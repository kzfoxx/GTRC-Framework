// Phil's Vehicle Management System - Vehicle Key Menu

if (!hasInterface) exitWith {};
private ["_radio", "_radioKey", "_trg"];

switch (PVM_radioKey) do
{
	case 1: {_radio = "ALPHA";};
	case 2: {_radio = "BRAVO";};
	case 3: {_radio = "CHARLIE";};
	case 4: {_radio = "DELTA";};
	case 5: {_radio = "ECHO";};
	case 6: {_radio = "FOXTROT";};
	case 7: {_radio = "GOLF";};
	case 8: {_radio = "HOTEL";};
	case 9: {_radio = "INDIA";};
	case 0: {_radio = "JULIET";};
};

_trg = createTrigger ["EmptyDetector", [5, 5, 5], false];
_trg setTriggerActivation [_radio, "NONE", true];
_trg setTriggerStatements ["this", "[] spawn fnc_select;", ""];
_trg setTriggerText "载具钥匙";  
PVM_keyVeh = objNull;

// Be sure to read this before modifying the menus:
// https://community.bistudio.com/wiki/Arma_3_Communication_Menu#Submenu


fnc_select = 
{
	MENU_PVM_SELECT =
	[
		["选择载具", true],
		[getText (configfile >> "CfgVehicles" >> typeof PVM_myVeh >> "displayName"), [2], "", -5, [["expression", "[PVM_myVeh] spawn fnc_key;"]], if (alive PVM_myVeh) then {"1"} else {"0"}, "1"],
		[getText (configfile >> "CfgVehicles" >> typeof PVM_myAir >> "displayName"), [3], "", -5, [["expression", "[PVM_myAir] spawn fnc_key;"]], if (alive PVM_myAir) then {"1"} else {"0"}, "1"]
	];
	showCommandingMenu '#USER:MENU_PVM_SELECT';
};

if (false) then {
	[PVM_fnc_halt, [], random 4000] call CBA_fnc_waitAndExecute;
};

fnc_key = 
{
	PVM_keyVeh = _this select 0;
	MENU_PVM_KEY =
	[
		["载具钥匙", true],
		["重生载具", [2], "", -5, [["expression", "if (alive PVM_keyVeh) then {deleteVehicle PVM_keyVeh;}; PVM_keyVeh = objNull;"]], "1", "1"],
		["上锁", [3], "", -5, [["expression", "[PVM_keyVeh] spawn PVM_fnc_lock; PVM_keyVeh = objNull;"]], if (locked PVM_keyVeh != 2) then {"1"} else {"0"}, "1"],
		["解锁", [3], "", -5, [["expression", "PVM_keyVeh lock 0; PVM_keyVeh = objNull;"]], if (locked PVM_keyVeh == 2) then {"1"} else {"0"}, "1"],
		["放弃载具", [4], "", -5, [["expression", "if (alive PVM_keyVeh) then {[PVM_keyVeh] spawn PVM_fnc_unclaim;}; PVM_keyVeh = objNull;"]], "1", "1"]
	];
	showCommandingMenu '#USER:MENU_PVM_KEY';
};