if (!hasInterface) exitWith {};
params ["_name", "_veh"];
_veh setVariable ["claimID", _veh addAction ["使用此载具", {[_this select 0] call PVM_fnc_tryClaim;}, nil, 100, true, true, "", "alive _target", 10]];
[playerSide, "Base"] sideChat format ["%1 left a %2 at grid %3 for other players", _name, getText (configfile >> "CfgVehicles" >> typeof _veh >> "displayName"), mapGridPosition _veh];