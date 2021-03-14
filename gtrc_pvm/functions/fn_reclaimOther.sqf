params ["_vehNew", "_claimer"];
if (hasInterface) then {
	if (_vehNew getVariable ["monitor", false]) then {
		_vehNew setVariable ["monitor", (_claimer == player)];
	};
	_vehNew removeAction (_vehNew getVariable "claimID");
	[playerSide, "Base"] sideChat format ["%1 took the unclaimed %2", name _claimer, getText (configfile >> "CfgVehicles" >> typeof _vehNew >> "displayName")];
};

if (isServer) then {
	private ["_vehOld"];
	
	PVM_list_unclaimed = PVM_list_unclaimed - [_vehNew];
	publicVariable "PVM_list_unclaimed";
	if (PVM_separateAir && _vehNew isKindOf "Air") then {
		_vehOld = missionNamespace getVariable [format ["PVM_%1_air", getPlayerUID _claimer], objNull];
		missionNamespace setVariable [format ["PVM_%1_air", _vehNew getVariable ["claimer", ""]], nil];
		missionNamespace setVariable [format ["PVM_%1_air", getPlayerUID _claimer], _vehNew];
	}
	else{
		_vehOld = missionNamespace getVariable [format ["PVM_%1_veh", getPlayerUID _claimer], objNull];
		missionNamespace setVariable [format ["PVM_%1_veh", _vehNew getVariable ["claimer", ""]], nil];
		missionNamespace setVariable [format ["PVM_%1_veh", getPlayerUID _claimer], _vehNew];
	};
	if (_vehNew != _vehOld) then {deleteVehicle _vehOld};
	_vehNew setVariable ["claimer", getPlayerUID _claimer, true];
	_vehNew lock 0;
	_vehNew setOwner owner _claimer;
	[_vehNew] remoteExec ["PVM_fnc_claimVeh", _claimer];
};