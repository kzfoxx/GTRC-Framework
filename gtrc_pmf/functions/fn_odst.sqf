params ["_unit", "_pos", ["_dir", random 360], ["_altitude", 2000], ["_maxTime", 15], ["_exactPos", false]];
if (_exactPos) then {
	_pos = [_pos select 0, _pos select 1, _altitude];
} else {
	_pos = [(_pos select 0) + (random 20) - 10, (_pos select 1) + (random 20) - 10, _altitude];
};

private _veh = "B_Ejection_Seat_Plane_CAS_01_F" createVehicle _pos;
_veh setPos _pos;
_veh allowDamage false;
_veh setDir _dir;
_veh setVelocity [0,0,-2000];
_veh lock true;
_unit allowDamage false;
_unit moveInAny _veh;
[_veh, "PMF_fnc_attachFire", allPlayers, false, true] call BIS_fnc_MP;

if (_unit == player) then {
	[] spawn {
		playSound "vtolAlarm";
		playSound "WindBig";
		sleep 0.5;
		playSound "wind1";
		sleep 0.5;
		playSound "wind2";
		sleep 0.5;
		playSound "wind3";
		sleep 0.5;
		playSound "wind4";
		sleep 0.5;
		playSound "wind5";
	};
};
[
	{getPos (_this select 1) select 2 < 10},
	{
		
		moveOut (_this select 0);
		unassignVehicle (_this select 0);
		deleteVehicle (_this select 1);
		_this select 0 switchMove "AinvPknlMstpSlayWrflDnon_AmovPercMstpSnonWnonDnon";
		playSound3D ["A3\Sounds_F\sfx\explosion1.wss", _this select 0, false, AGLToASL [getPos (_this select 0) select 0, getPos (_this select 0) select 1, 5], 5, 1, 200];
		[
		{
			_this select 0 allowDamage true;
		}, _this, 5] call CBA_fnc_waitAndExecute;
	},
	[_unit, _veh, _fire, _smoke],
	_maxTime,
	{
		moveOut (_this select 0);
		unassignVehicle (_this select 0);
		deleteVehicle (_this select 1);
		_this select 0 allowDamage true;
	}
] call CBA_fnc_waitUntilAndExecute;