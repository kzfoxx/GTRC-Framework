params ["_source", "_copy"];
private ["_list", "_i"];

_list = getObjectTextures _source;
if (count _list == 0 or typeOf _source != typeOf _copy) exitWith {};

_i = 0;
{
	if (_x isEqualTo "") exitWith {};
	_copy setObjectTextureGlobal [_i, _x];
	//systemChat str [_i, _x];
	_i = _i + 1;
} forEach _list;