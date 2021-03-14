params ["_veh"];

if (PVM_separateAir && _veh isKindOf "Air") then {
	PVM_myAir = _veh;
}
else{
	PVM_myVeh = _veh;
};

_veh setVehicleReceiveRemoteTargets true;
_veh setVehicleReportOwnPosition true;
_veh setVehicleReceiveRemoteTargets true;

if !(_veh getVariable ["monitor", false]) then {[_veh] spawn PVM_fnc_monitor;};