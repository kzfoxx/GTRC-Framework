// Phil's Vehicle Management System - Initialization Script

if (isNil "PVM") exitWith {}; 

/* --------------------- Settings --------------------- */

PVM_emptyTime = 3600;				// Max time a claimed vehicle can be left empty before respawn, in seconds and must be mutiplies of 20 (0, 20, 40, 60...)
PVM_desertedDistance = 2000;		// Claimed vehicles will respawn if no player is within this distance.
PVM_deleteWreck = false;				// Delete vehicle wrecks when they respawn. With either setting, you can still use the in-game garbage collection or other clean-up scripts without conflicts.
PVM_respawnDelay = 15;				// Respawn delay after the vehicle is destoryed, does not apply to manual respawn or respawn due to left empty/deserted.
PVM_separateAir = true;				// Allow players to have an air vehicle in addtion to ground/water vehicle, so that pilots can transport vehicles on their own.
PVM_radioKey = 9; 					// Key to open the vehicle key menu. 0 for press 0-0-0, 1 for 0-0-1, 2 for 0-0-2, etc

PVM_pilot = ["飞行员", "B_Fighter_Pilot_F", "B_Pilot_F", "B_T_Pilot_F", "B_Helipilot_F", "B_T_Helipilot_F", "B_officer_F", "B_T_officer_F"];
PVM_UAV = ["UAV Operators", "B_soldier_UAV_F", "B_T_soldier_UAV_F", "B_officer_F", "B_T_officer_F"];

PVM_guide = [						// Make necessary changes to this guide so that it matches your settings.
parseText "Generall Guidlines <br />
<br />
<t size='0.8'>If you wish to use one of the vehicles at base, claim it first.<br /> 
Each player can only claim one vehicle at a time.<br />
Some vehicles have rank or qualificaton requirement.<br />
Pilots can claim an air vehicle plus a car or boat.<br /> 
After claiming a vehicle, you are given its key. <br />
Press 0-0-9 to open your vehicle key menu.<br />
<br />
Your claimed vehicle will respawn back to base when:<br /> 
  - It is destoryed (after a 15 sec delay).<br /> 
  - You manually force respawn it.<br /> 
  - You claim another vehicle.<br /> 
  - You disconnect from the server.<br /> 
  - It is left empty for more then 60 minutes.<br /> 
  - No player is within 1 KM of it.<br />
<br />
You may use an unlocked vehicle claimed by another player.
However, it may get respawned or locked anytime depending on the original owner.<br />
If you release your vehicle ownership, it will stay where you left it for 10 minutes. 
Other players can claim it, but before so, it is still under your name. 
Thus if you claim a new vehicle or disconnect at this time, the unclaimed one will get reset.</t>" 
];

/* ---------------------------------------------------- */


if (isServer) then {
	PVM_list_unclaimed = [];
	publicVariable "PVM_list_unclaimed";
	{
		_x allowDamage false;
		_x lock 2;
		_x action ["lightOff", _x];
		_x setVariable ["initPos", getPosWorld _x];
	} forEach synchronizedObjects PVM;
	
	addMissionEventHandler ["HandleDisconnect", {
		private _uid = _this select 2;
		deleteVehicle (missionNamespace getVariable [format ["PVM_%1_air", _uid], objNull]);
		deleteVehicle (missionNamespace getVariable [format ["PVM_%1_veh", _uid], objNull]);
		missionNamespace setVariable [format ["PVM_%1_air", _uid], nil];
		missionNamespace setVariable [format ["PVM_%1_veh", _uid], nil];
	}];
};

if (hasInterface) then {
	waitUntil {!isNull player};
	
	PVM_myVeh = objNull;
	PVM_myAir = objNull;
	
	private _actionUseTrue = ["PVM_useVehicleTrue", "使用此载具", "", {
		[_target] call PVM_fnc_tryClaim;
	}, {
		([player, _target getVariable ["PMF_minRank", "none"]] call PMF_fnc_rankCheck) && (vehicle _player == _player)
	}] call ace_interact_menu_fnc_createAction;
	
	private _actionUseFlase = ["PVM_useVehicleFalse", "载具无法使用", "", {
		hint "载具无法使用";
	}, {
		(!([player, _target getVariable ["PMF_minRank", "none"]] call PMF_fnc_rankCheck)) && (vehicle _player == _player)
	}] call ace_interact_menu_fnc_createAction;
	
	{
		[_x, 0, ["ACE_MainActions"], _actionUseTrue] call ace_interact_menu_fnc_addActionToObject;
		[_x, 0, ["ACE_MainActions"], _actionUseFlase] call ace_interact_menu_fnc_addActionToObject;
	} forEach synchronizedObjects PVM;
	
	/*
	{
		_x addAction ["载具使用说明", {
			"Phil's Vehicle Management System" hintC PVM_guide;
			hintC_EH = findDisplay 72 displayAddEventHandler ["unload", {
				0 = _this spawn {
					_this select 0 displayRemoveEventHandler ["unload", hintC_EH];
					hintSilent "";
				};
			}];
		}, nil, 100, true, true, "", "vehicle player == player", 10];
		_x addAction ["使用此载具", {[_this select 0] call PVM_fnc_tryClaim;}, nil, 101, true, true, "", "vehicle player == player", 10];
	} forEach synchronizedObjects PVM;
	*/
	
	if (didJIP) then {
		private _list = PVM_list_unclaimed;
		{
			if (isNull _x) then {
				_list = _list - [_x];
			}
			else {
				["Someone", _x] call PVM_fnc_unclaimOther;
			};
		} forEach PVM_list_unclaimed;
		if !(_list isEqualTo PVM_list_unclaimed) then {
			PVM_list_unclaimed = _list;
			publicVariable "PVM_list_unclaimed";
		};
	};
	
	execVM "gtrc_pvm\scripts\PVM_key.sqf";
	execVM "gtrc_pvm\scripts\AutoPilot\AutoPilotInit.sqf";
};