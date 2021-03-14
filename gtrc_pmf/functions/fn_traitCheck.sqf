params ["_unit", "_trait"];

if (_trait isEqualTo "none") exitWith {true};

private ["_info", "_remark"];

_info = squadParams _unit;
if !(_info select 0 select 0 in ["GTRC"]) exitWith {false};
_remark = (_info select 1 select 5) splitString ", ";
if (_trait in _remark) exitWith {true};
false