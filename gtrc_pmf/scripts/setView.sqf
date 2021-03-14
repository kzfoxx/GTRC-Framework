// Phil's Quick View Distance Menu

if (!hasInterface) exitWith {};
private ["_radio", "_radioKey", "_allowNoGrass", "_volumeMenu", "_trg"];


/* --------------------- Settings --------------------- */

_radioKey = 0; 			// 0 for press key 0-0-0, 1 for 0-0-1, 2 for 0-0-2, etc
_allowNoGrass = "0";	// "1" - allowed, "0" - not allowed
_volumeMenu = "0";		// "0" to disable this if you use other earplugs script.

/* ---------------------------------------------------- */

switch (_radioKey) do
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

_trg = createTrigger ["EmptyDetector", [7, 7, 7], false];
_trg setTriggerActivation [_radio, "NONE", true];
_trg setTriggerStatements ["this", "['', 0] spawn fnc_setView", ""];
_trg setTriggerText "视距设置";  

// Be sure to read this before modifying the menus:
// https://community.bistudio.com/wiki/Arma_3_Communication_Menu#Submenu

MENU_VIEW =
[
	["视距设置", true],
	["环境视距", [2], "#USER:MENU_VIEW_ENV", -5, [], "1", "1"], 
	["物体视距", [3], "#USER:MENU_VIEW_OBJ", -5, [], "1", "1"],
	["阴影距离", [4], "#USER:MENU_VIEW_SDW", -5, [], "1", "1"],
	["地形细节", [5], "#USER:MENU_VIEW_TRN", -5, [], "1", "1"],
	["音量调节", [6], "#USER:MENU_VIEW_VOL", -5, [], "1", _volumeMenu],
	["右键关闭", [0], "", -5, [], "1", "1"]
];

MENU_VIEW_ENV =
[
	["环境视距", true],
	["瞄准距离", [2], "", -5, [["expression", "['ENV', -10] spawn fnc_setView;"]], "1", "1", "\A3\ui_f\data\IGUI\Cfg\Cursors\iconcursorsupport_ca.paa"],
	["500", [3], "", -5, [["expression", "['ENV', 500] spawn fnc_setView;"]], "1", "1"],
	["750", [4], "", -5, [["expression", "['ENV', 750] spawn fnc_setView;"]], "1", "1"],
	["1000", [5], "", -5, [["expression", "['ENV', 1000] spawn fnc_setView;"]], "1", "1"],
	["1500", [6], "", -5, [["expression", "['ENV', 1500] spawn fnc_setView;"]], "1", "1"],
	["2000", [7], "", -5, [["expression", "['ENV', 2000] spawn fnc_setView;"]], "1", "1"],
	["3000", [8], "", -5, [["expression", "['ENV', 3000] spawn fnc_setView;"]], "1", "1"],
	["5000", [9], "", -5, [["expression", "['ENV', 5000] spawn fnc_setView;"]], "1", "1"],
	["7500", [10], "", -5, [["expression", "['ENV', 7500] spawn fnc_setView;"]], "1", "1"],
	["10000", [11], "", -5, [["expression", "['ENV', 10000] spawn fnc_setView;"]], "1", "1"],
	["Reset", [0], "", -5, [["expression", "['ENV', -1] spawn fnc_setView;"]], "1", "1"]
];

MENU_VIEW_OBJ =
[
	["物体视距", true],
	["瞄准距离", [2], "", -5, [["expression", "['OBJ', -10] spawn fnc_setView;"]], "1", "1", "\A3\ui_f\data\IGUI\Cfg\Cursors\iconcursorsupport_ca.paa"],
	["500", [3], "", -5, [["expression", "['OBJ', 500] spawn fnc_setView;"]], "1", "1"],
	["750", [4], "", -5, [["expression", "['OBJ', 750] spawn fnc_setView;"]], "1", "1"],
	["1000", [5], "", -5, [["expression", "['OBJ', 1000] spawn fnc_setView;"]], "1", "1"],
	["1500", [6], "", -5, [["expression", "['OBJ', 1500] spawn fnc_setView;"]], "1", "1"],
	["2000", [7], "", -5, [["expression", "['OBJ', 2000] spawn fnc_setView;"]], "1", "1"],
	["3000", [8], "", -5, [["expression", "['OBJ', 3000] spawn fnc_setView;"]], "1", "1"],
	["5000", [9], "", -5, [["expression", "['OBJ', 5000] spawn fnc_setView;"]], "1", "1"],
	["7500", [10], "", -5, [["expression", "['OBJ', 7500] spawn fnc_setView;"]], "1", "1"],
	["10000", [11], "", -5, [["expression", "['OBJ', 10000] spawn fnc_setView;"]], "1", "1"],
	["Reset", [0], "", -5, [["expression", "['OBJ', -1] spawn fnc_setView;"]], "1", "1"]
];

MENU_VIEW_SDW =
[
	["阴影距离", true],
	["0", [2], "", -5, [["expression", "['SDW', 0] spawn fnc_setView;"]], "1", "1"],
	["20", [3], "", -5, [["expression", "['SDW', 20] spawn fnc_setView;"]], "1", "1"],
	["50", [4], "", -5, [["expression", "['SDW', 50] spawn fnc_setView;"]], "1", "1"],
	["75", [5], "", -5, [["expression", "['SDW', 75] spawn fnc_setView;"]], "1", "1"],
	["100", [6], "", -5, [["expression", "['SDW', 100] spawn fnc_setView;"]], "1", "1"],
	["150", [7], "", -5, [["expression", "['SDW', 150] spawn fnc_setView;"]], "1", "1"],
	["200", [8], "", -5, [["expression", "['SDW', 200] spawn fnc_setView;"]], "1", "1"]
];

MENU_VIEW_TRN =
[
	["地形细节", true],
	["Low", [2], "", -5, [["expression", "['TRN', 50] spawn fnc_setView;"]], "1", _allowNoGrass],
	["Standard", [3], "", -5, [["expression", "['TRN', 25] spawn fnc_setView;"]], "1", "1"],
	["High", [4], "", -5, [["expression", "['TRN', 12.5] spawn fnc_setView;"]], "1", "1"],
	["Very High", [5], "", -5, [["expression", "['TRN', 6.25] spawn fnc_setView;"]], "1", "1"],
	["Ultra", [6], "", -5, [["expression", "['TRN', 3.125] spawn fnc_setView;"]], "1", "1"]
];

MENU_VIEW_VOL =
[
	["音量调节", true],
	["Mute", [2], "", -5, [["expression", "['VOL', 0] spawn fnc_setView;"]], "1", "1"],
	["25%", [3], "", -5, [["expression", "['VOL', 0.25] spawn fnc_setView;"]], "1", "1"],
	["50%", [4], "", -5, [["expression", "['VOL', 0.5] spawn fnc_setView;"]], "1", "1"],
	["75%", [5], "", -5, [["expression", "['VOL', 0.75] spawn fnc_setView;"]], "1", "1"],
	["Full", [6], "", -5, [["expression", "['VOL', 1] spawn fnc_setView;"]], "1", "1"]
];

fnc_setView =
{
	params ["_mode", "_value"];
	private _currentViewDist = viewDistance;
	
	if (_value == -10) then
	{
		setViewDistance 12000; // Temporarily set view distance to maximum, as screenToWorld does not work properly for positions beyound view distance.
		if ((UAVControl getConnectedUAV player select 1) != "") then	// Use the UAV's position as reference if player is currently controlling it.
		{
			_value = ((getConnectedUAV player) distance screenToWorld [0.5,0.5]) + 200;		// Add another 200 so that objects don't disappear immediately if distance increases. 
		}
		else 
		{
			_value = (player distance screenToWorld [0.5,0.5]) + 200;
		};
		
		if (_mode == "ENV") then
		{
			_value = _value + 800;	// Add addtional 800 so that player can ACUTALLY see the aiming position clearly.
		}
		else
		{
			setViewDistance _currentViewDist;
		};
	};
	
	if 	(_mode == "OBJ" && _value > _currentViewDist) then
	{
		setViewDistance (_value + 200);		// Making sure object distance does not exceed overall distance.
	};

	switch (_mode) do
	{
		case "ENV": {setViewDistance _value};
		case "OBJ": {setObjectViewDistance _value};
		case "SDW": {setShadowDistance _value};
		case "TRN": {setTerrainGrid _value};
		case "VOL": {1 fadeSound _value};
	};
	
	showCommandingMenu "#USER:MENU_VIEW";
};