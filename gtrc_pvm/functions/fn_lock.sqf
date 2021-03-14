params ["_veh"];
{
	moveOut _x;
} forEach crew _veh;
waitUntil {count crew _veh == 0};
_veh lock 2;