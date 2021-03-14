// AutoPilotInit.sqf   SCRIPT VERSION
// © v.2.0 June 2017 - Devastator_cm
// Different by mod and script version

DEVAS_AutoPilotMain 		= Compile preprocessFileLineNumbers "gtrc_pvm\scripts\AutoPilot\AutoPilotMain.sqf";
DEVAS_AutoPilot				= Compile preprocessFileLineNumbers "gtrc_pvm\scripts\AutoPilot\AutoPilot.sqf";
DEVAS_DCM2RPY				= Compile preprocessFileLineNumbers "gtrc_pvm\scripts\AutoPilot\Math\AutoPilotDCM2RPY.sqf";				
DEVAS_VectorDirAndUp2DCM	= Compile preprocessFileLineNumbers "gtrc_pvm\scripts\AutoPilot\Math\AutoPilotVectorDirAndUp2DCM.sqf";	
DEVAS_MatrixMultiply		= Compile preprocessFileLineNumbers "gtrc_pvm\scripts\AutoPilot\Math\AutoPilotMatrixMultiply.sqf";
DEVAS_AutoPilotHeli			= Compile preprocessFileLineNumbers "gtrc_pvm\scripts\AutoPilot\AutoPilotHeli.sqf";
DEVAS_AutoPilotFWing		= Compile preprocessFileLineNumbers "gtrc_pvm\scripts\AutoPilot\AutoPilotFWing.sqf";
DEVAS_Loiter				= Compile preprocessFileLineNumbers "gtrc_pvm\scripts\AutoPilot\Loiter.sqf";
DEVAS_LoiterMain			= Compile preprocessFileLineNumbers "gtrc_pvm\scripts\AutoPilot\LoiterMain.sqf";
DEVAS_LoiterStart			= Compile preprocessFileLineNumbers "gtrc_pvm\scripts\AutoPilot\LoiterStart.sqf";
DEVAS_LoiterAdjust			= Compile preprocessFileLineNumbers "gtrc_pvm\scripts\AutoPilot\LoiterAdjust.sqf";

//{[_x] spawn DEVAS_AutoPilot;} foreach (entities [["Air"],   [], false, true]);
//{[_x] spawn DEVAS_Loiter;}    foreach (entities [["Plane"], [], false, true]);

PVM_fnc_loadAutoPilot = {
	params ["_veh"];
	
	if (_veh isKindOf "Plane") then {
		[_veh] spawn DEVAS_Loiter;
	};
	[_veh] spawn DEVAS_AutoPilot;
	_veh setVariable ["PVM_autoPilotLoaded", true];
};