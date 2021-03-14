if (!isServer) exitWith {};

params ["_selected", ["_mode", 0]];
_selected params ["_objects", "_groups"];

private ["_owner"];

switch (_mode) do {
	case 0: {_owner = remoteExecutedOwner};
	case 1: {_owner = hcOwner};
	case 2: {_owner = 2};
};

{
	if (groupOwner _x != _owner) then {
		_x setGroupOwner _owner;
	};
	_objects = _objects - (units _x);
} forEach _groups;

{
	if (!(_x isKindOf "man") && owner _x != _owner) then {
		_x setOwner _owner;
	};
} forEach _objects;