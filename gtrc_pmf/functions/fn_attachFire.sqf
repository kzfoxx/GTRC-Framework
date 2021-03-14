params ["_veh"];
private _fire = "#particlesource" createVehiclelocal getpos _veh;
_fire setParticleClass "AirObjectDestructionFire";
_fire setDropInterval 0.01;
_fire attachTo [_veh, [0,0,-1]];

private _smoke = "#particlesource" createVehiclelocal getpos _veh;
_smoke setParticleClass "AirObjectDestructionSmoke";
_smoke setDropInterval 0.05;
_smoke attachTo [_veh, [0,0,-1]];

[
	{isNull (_this select 0)},
	{
		detach (_this select 1);
		detach (_this select 2);
		private _pos = getPos (_this select 1);
		_pos = [_pos select 0, _pos select 1, 0];
		deleteVehicle (_this select 1);
		_this select 2 setPos _pos;
		_this select 2 setDropInterval 0.5;
		[
		{
			deleteVehicle (_this select 2);
		}, _this, 1] call CBA_fnc_waitAndExecute;
	},
	[_veh, _fire, _smoke],
	60,
	{
		deleteVehicle (_this select 1);
		deleteVehicle (_this select 2);
	}
] call CBA_fnc_waitUntilAndExecute;