/*
Phil's Mission Framework v0.5

Special variable names that can be used in Eden Editor:

	PMF_tele				Player can teleport to miniFOB from this object. The miniFOB system will not be initialized if PMF_tele is not present.
	PMF_ctrlPanel			Mission control panel (become zeus, reset VM vehicles, etc)
	PMF_range				Marker area that covers the shooting range. All terrain objects within are removed.
	PMF_respawn				Marker area
	
*/

// Settings:

call compile preprocessFileLineNumbers "gtrc_pmf\init\default_settings.sqf";

// ===========================================================

call compile preprocessFileLineNumbers "gtrc_pmf\scripts\airborne.sqf";

if (isServer) then {
	
	//private _zeus1 = (createGroup sideLogic) createUnit ["ModuleCurator_F", [0, 0, 0], [], 0, ""];
	//private _zeus2 = (createGroup sideLogic) createUnit ["ModuleCurator_F", [0, 0, 0], [], 0, ""];
	PMF_list_zeus = allCurators;
	publicVariable "PMF_list_zeus";
	
	PMF_serverLoop = [] spawn {
	
		while {true} do {
			sleep 600;
			call PMF_fnc_cleanUp;
		};
	};
	
	if (isNil "hcOwner") then {
		hcOwner = 2;
	};
};

if (hasInterface) then {
	waitUntil {alive player};
	
	
	//=============================================
	//		Slot qualification check
	//=============================================
	
	private _trait = player getVariable ["PMF_trait", "none"];
	private _minRank = player getVariable ["PMF_minRank", "none"];
	if !(([player, _trait] call PMF_fnc_traitCheck) && ([player, _minRank] call PMF_fnc_rankCheck)) then {
		//hintC "不满足使用此角色的最低要求";
		["loser", false, 1, false, false] call BIS_fnc_endMission;
	};
	[player, "none", true, true] call pmf_fnc_rankCheck;

	
	//=============================================
	//		Mission enhancing scripts
	//=============================================
	
	execVM "gtrc_pmf\scripts\setView.sqf";
	
	
	//=============================================
	//		Setup zeus control panel
	//=============================================
	
	if (!isNil "PMF_ctrlPanel") then {
	
		PMF_ctrlPanel addAction ["查看当前宙斯", {
			private _zeus1 = name getAssignedCuratorUnit (PMF_list_zeus select 0);
			private _zeus2 = name getAssignedCuratorUnit (PMF_list_zeus select 1);
			hintC format ["宙斯1: %1\n宙斯2: %2", _zeus1, _zeus2];
		}, nil, 102, true, true, "", "true", 5];
		
		PMF_ctrlPanel addAction ["成为宙斯1", {
		
			private _trait = PMF_list_zeus select 0 getVariable ["PMF_trait", "zeus"];
			if ([player, _trait] call PMF_fnc_traitCheck) then {
				[player, 0] remoteExec ["PMF_fnc_zeus", 2]
			} else {
				hintC "你没有宙斯权限";
			};
		/*
			private _rank = PMF_list_zeus select 0 getVariable ["PMF_minRank", "SPC"];
			if ([player, _rank] call PMF_fnc_rankCheck) then {
				[player, 0] remoteExec ["PMF_fnc_zeus", 2]
			} else {
				hintC "你没有宙斯权限";
			};
		*/
		}, nil, 101, true, true, "", "true", 5];
		
		PMF_ctrlPanel addAction ["成为宙斯2", {
		
			private _trait = PMF_list_zeus select 1 getVariable ["PMF_trait", "zeus"];
			if ([player, _trait] call PMF_fnc_traitCheck) then {
				[player, 1] remoteExec ["PMF_fnc_zeus", 2]
			} else {
				hintC "你没有宙斯权限";
			};
		/*
			private _rank = PMF_list_zeus select 1 getVariable ["PMF_minRank", "SPC"];
			if ([player, _rank] call PMF_fnc_rankCheck) then {
				[player, 1] remoteExec ["PMF_fnc_zeus", 2]
			} else {
				hintC "你没有宙斯权限";
			};
		*/
		}, nil, 100, true, true, "", "true", 5];
	};
	
	
	//=============================================
	//		Clear obstructions in shooting range 
	//=============================================
	
	if !(getMarkerPos "PMF_range" isEqualTo [0, 0, 0]) then {
		private _length = selectMax getMarkerSize "PMF_range";
		{
			if (_x inArea "PMF_range") then {
				hideObject _x;
			};
		} forEach nearestTerrainObjects [getMarkerPos "PMF_range", [], _length];
		"PMF_range" setMarkerAlpha 0;
	};
	
	
	//=============================================
	//		Event Handlers
	//=============================================
	
	// Release UAV control from dead player
	player addEventHandler ["Killed", {
		params ["_unit"];
		_unit connectTerminalToUAV objNull;
	}];
	
	// Add player to Zeus editables after respawn
	player addEventHandler ["Respawn", {
		params ["_new", "_old"];
		[_new] remoteExec ["PMF_fnc_addEditable", 2];
		//[PMF_fnc_bleedingHint, [_new], 3] call CBA_fnc_waitAndExecute;
		//if (_new distance _old < 500) then {
			deleteVehicle _old;
		//};
	}];
	[player] remoteExec ["PMF_fnc_addEditable", 2];

	
	// Loadout weight limit
	["loadout", {call PMF_fnc_XEH_loadout}] call CBA_fnc_addPlayerEventHandler; 
	
	// Complex camera restriction
	["cameraView", {
		[_this select 1, cameraOn] call PMF_fnc_XEH_cameraView;
	}] call CBA_fnc_addPlayerEventHandler;
	["vehicle", {
            [cameraView, _this select 1] call PMF_fnc_XEH_cameraView;
	}] call CBA_fnc_addPlayerEventHandler;
	
	// Reset TFAR radio to GTRC frequencies and add reset action
	true call PMF_fnc_resetRadio;
	
	// Fix paradrop cargo attach position
	paradropEH = ["ace_cargoUnloaded", {
		private _item = _this select 0;
		if (!local _item) exitWith {};
		[{ 
			params ["_item"];
			private _para = attachedTo _item; 
			if (typeOf _para != "B_Parachute_02_F") exitWith {};
			_item attachTo [_para, [0,0,1]];
		}, [_item], 2] call CBA_fnc_waitAndExecute;
	}] call CBA_fnc_addEventHandler;
	
	// Make sure correct rank is always on the uniform
	["loadout", {
		if (isNil "PMF_playerRankIndex") exitWith {};
		private _currentInsignia = [player] call BIS_fnc_getUnitInsignia;
		private _correctInsignia = if (PMF_playerRankIndex == 0) then {""} else {format ["Rank_%1", (PMF_playerRankIndex min 14)]};
		if (_currentInsignia != _correctInsignia) then {
			[player, format ["Rank_%1", (PMF_playerRankIndex min 14)]] call BIS_fnc_setUnitInsignia;
		};
	}] call CBA_fnc_addPlayerEventHandler; 
	
	// Really prevent instant death for player and kill badly wounded AIs
	/*
	["ace_unconscious", {
		params ["_unit", "_uncon"];
		
		if (!_uncon) exitWith {};
		
		if (local _unit) then {
			if (_unit == player) then {
				[{
					params ["_args", "_idPFH"];
					_args params ["_unit", "_frameno"];
					if (diag_frameno >= _frameno + 3) then {
						_unit allowDamage false;
						for "_i" from -1 to 11 do {
							_unit setVariable [format ["hitInd_%1", _i], (_unit getHitIndex _i) min 0.95];
						};
						[_idPFH] call CBA_fnc_removePerFrameHandler;
					};
				}, 0, [_unit, diag_frameno]] call CBA_fnc_addPerFrameHandler;
				
				[{
					params ["_unit"];
					_unit allowDamage true;
					for "_i" from -1 to 11 do {
						_unit setHitIndex [_i, _unit getVariable [format ["hitInd_%1", _i], 0]];
					};
					if ((_unit getHitPointDamage "hitBody") > 0.9) then {
						if (0.6 > random 1) then {
							[_unit] call ace_medical_fnc_setCardiacArrest;
						};
					};
				}, [_unit], 2] call CBA_fnc_waitAndExecute;

			} else {
				if ((_unit getHitIndex 2 >= 0.9) or (_unit getHitIndex 7 >= 0.9)) then {
					_unit setDamage 1;
				};
			};
		};
	}] call CBA_fnc_addEventHandler;
	*/
	[] spawn {
		waitUntil {sleep 1; alive player};
		private _txt = parseText "当前版本无线电插件有BUG会导致接收到其他频道玩家说话<br/>   每次进入服务器后重启插件可以解决这一问题<br/><img size='11' image='gtrc_pmf\data\reload.paa'/>";
		"请重启TS无线电插件" hintC _txt;
		sleep 1;
	};
};
/*
if (!hasInterface && !isServer) then {
    hcOwner = clientOwner;
	publicVariable "hcOwner";
	format ["Headless Client online. hcOwner = %1", hcOwner] remoteExecCall ["systemChat", 0];
};
*/