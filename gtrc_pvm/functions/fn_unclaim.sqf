params ["_veh"];
[_veh] call PVM_fnc_lock;
{_veh removeAction _x;} forEach (_veh getVariable ["PVM_actions", []]);
if (PVM_separateAir && _veh isKindOf "Air") then {
	PVM_myAir = objNull;
}
else{
	PVM_myVeh = objNull;
};
PVM_list_unclaimed pushBack _veh;
publicVariable "PVM_list_unclaimed";
[name player, _veh] remoteExec ["PVM_fnc_unclaimOther"];