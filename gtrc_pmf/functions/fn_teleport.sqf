params [["_mode", 0]];
private ["_units"];

_units = [];

switch (_mode) do {
	case 0: {_units = [player]};
	case 1: {_units = allPlayers};
	case 2: {
		{
			if (_x inArea "PMF_respawn") then {
				_units pushBack _x;
			};
		} forEach allPlayers;
	};
};

if (count (curatorSelected select 0) > 0) then {
	private _target = curatorSelected select 0 select 0;
	{
		_x setVehiclePosition [_target, [], 0];
		_x moveInAny _target;
	} forEach _units;
} else {
	{
		_x setVehiclePosition [screenToWorld [0.5,0.5], [], 0];
	} forEach _units;
};