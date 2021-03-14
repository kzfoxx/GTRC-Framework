params [["_minTime", 5], ["_maxTime", 180]];

PMF_respawnTimeMin = _minTime;
if (isNil "PMF_respawnTimeMax") then {
	PMF_respawnTimeMax = _maxTime;
};


player addEventHandler ["Killed", {
	params ["_unit"];
	
	if (typeOf _unit in ["B_RangeMaster_F", "B_Pilot_F"]) exitWith {};
	setPlayerRespawnTime PMF_respawnTimeMax;
	[] spawn {
		sleep 5;
		["Initialize", [player, [playerSide], true, false, true, true, true, true, false, true]] call BIS_fnc_EGSpectator;
		while {!alive player} do {
			if (count (units group player select {alive _x && _x distance getMarkerPos PMF_baseMarker > 800}) < 1) then {
				if (playerRespawnTime > 5) then {
					setPlayerRespawnTime PMF_respawnTimeMin;
				};
			};	
			sleep 5;
		};
	};
}];

player addEventHandler ["Respawn", {
	params ["_unit", "_old"];
	//deleteVehicle _old;
	
	["Terminate"] call BIS_fnc_EGSpectator;	
	if (typeOf _unit in ["B_RangeMaster_F", "B_Pilot_F"]) exitWith {};

	
	private _grp = group _unit;	
	private _leader = leader _grp;
	private _respawnOn = objNull;
	
	if ((_leader != _unit) && !(_leader getVariable ["ACE_isUnconscious", false]) && (alive _leader)) then {
		_respawnOn = _leader;
	} else {
		private _minDist = 1000000;
		{
			private _newDist = _x distance _leader;
			if ((_newDist < _minDist) && !(_x getVariable ["ACE_isUnconscious", false]) && (alive _x)) then {
				_minDist = _newDist;
				_respawnOn = _x;
			};
		} forEach ((units _grp) - [_unit, _leader]);
	};
	
	if !(isNull _respawnOn) then {
		if (vehicle _respawnOn != _respawnOn) then {
			_unit moveInAny vehicle _respawnOn
		} else {
			if (_respawnOn distance getMarkerPos PMF_baseMarker < 800) then {
				_unit setPos getPos _respawnOn;
			} else {
				[_unit, getPos _respawnOn, getDir _respawnOn] call PMF_fnc_odst;
				playSound3D ["a3\missions_f_beta\data\sounds\firing_drills\checkpoint_not_clear.wss", _respawnOn, false, getPos _respawnOn, 3, 1, 50];
				[_unit, "正在空降"] remoteExecCall ["groupChat", units group _unit select {(_x distance _pos) < 50 and isPlayer _x;}];
			};
		};
	} else {
		if !(isNil "PMF_baseHeight") then {
			_unit setPosASL [getPosASL _unit select 0, getPosASL _unit select 1, (getPosASL PMF_baseHeight select 2) + 0.5];
		};
	};
}];

["ace_unconscious", {
	params ["_unit", "_uncon"];
	
	if (!_uncon) exitWith {};

	if (_unit in units group player) then {
		_unit spawn {
			group player setVariable ["PMF_lastUnitDownedTime", time];
			sleep 30;
			if ((time - (group player getVariable ["PMF_lastUnitDownedTime", 0])) < 29.5) exitWith {};
			
			private _allDown = true;
			{
				if ((!(_x getVariable ["ACE_isUnconscious", false])) && (alive _x)) exitWith {
					_allDown = false;
				};
			} forEach units group player;
			
			if (_allDown) then {
				sleep random 10;
				if (alive player && (player getVariable ["ACE_isUnconscious", false])) then {
					player setDamage 1;
				};
			};
		};
	};
}] call CBA_fnc_addEventHandler;

private _podAction = ["GrpRespawnPod", "小队重生", "", {remoteExecCall ["PMF_fnc_instantRespawn", group player]}, {true}] call ace_interact_menu_fnc_createAction;
private _beaconAction = ["GrpRespawnPod", "小队重生", "", {
	remoteExecCall ["PMF_fnc_instantRespawn", group _player];
	_player playAction "PutDown";
	deleteVehicle _target;
}, {true}] call ace_interact_menu_fnc_createAction;
["Box_B_UAV_06_medical_F", 0, ["ACE_MainActions"], _beaconAction, false] call ace_interact_menu_fnc_addActionToClass;