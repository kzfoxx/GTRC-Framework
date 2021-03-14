params ["_newCameraView", "_cameraOn"];

// Display laser target if inside air vehicles

if (_cameraOn isKindOf "Air" && _newCameraView != "EXTERNAL" && isNil "PMF_laserDraw3D") then {

	PMF_laserDraw3D = addMissionEventHandler ["Draw3D", {

		private _eyePos = eyePos cameraOn;
		{
			private _targetPos = getPosASL _x;
			//_targetPos = _targetPos vectorAdd ((_targetPos vectorFromTo _eyePos) vectorMultiply 0.5);
			//_targetPos = _targetPos set [2, (_targetPos select 2) + 0.1];
			drawIcon3D [
				"\A3\Ui_f\data\IGUI\RscCustomInfo\Sensors\Targets\LaserTarget_ca.paa", 
				[1, 0, 0, 0.5 max ([objNull, "VIEW"] checkVisibility [_eyePos, _targetPos])],
				getPos _x, 0.7, 0.7, 0, format ["%1 m", round (cameraOn distance _x)],
				2, 0.033, "RobotoCondensed", "center", false
			]; 
		} forEach entities "LaserTargetW";
	}];

} else {

	if (!isNil "PMF_laserDraw3D") then {
		removeMissionEventHandler ["Draw3D", PMF_laserDraw3D];
		PMF_laserDraw3D = nil;
	};

};


// Check if 3rd person is allowed

if (_newCameraView != "EXTERNAL") exitWith {};
if (_cameraOn != player && PMF_allowVehicle3rdPerson) exitWith {};
if ((player distance getMarkerPos PMF_baseMarker) < PMF_inBase3rdPersonRange) exitWith {};

_cameraOn switchCamera "INTERNAL";