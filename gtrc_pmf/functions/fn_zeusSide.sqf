params [["_mode", -1]];

private _curator = getAssignedCuratorLogic player;

_curator removeEventHandler ["CuratorObjectPlaced", _curator getVariable ["placeUnitEH", 10000]];

if !(_mode in [0, 1, 2, 3, 4]) exitWith {};


private ["_id"];
switch (_mode) do {
	
	case 0: {
		_id = _curator addEventHandler ["CuratorObjectPlaced", {
			params ["", "_unit"];
			if (driver _unit != leader _unit OR !(side _unit in [west, east])) exitWith {};
			
			private ["_grpNew", "_grpOld"];
			_grpOld = group _unit;
			if (side _unit == west) then {
				_grpNew = createGroup [east, true];
			} else {
				_grpNew = createGroup [west, true];
			};
			
			units _grpOld joinSilent _grpNew;
			deleteGroup _grpOld;			
		}];
	};
	
	case 1: {
		_id = _curator addEventHandler ["CuratorObjectPlaced", {
			params ["", "_unit"];
			if (driver _unit != leader _unit) exitWith {};
			
			private ["_grpNew", "_grpOld"];
			_grpOld = group _unit;
			_grpNew = createGroup [west, true];
			units _grpOld joinSilent _grpNew;
			deleteGroup _grpOld;			
		}];
	};
	
	case 2: {
		_id = _curator addEventHandler ["CuratorObjectPlaced", {
			params ["", "_unit"];
			if (driver _unit != leader _unit) exitWith {};
			
			private ["_grpNew", "_grpOld"];
			_grpOld = group _unit;
			_grpNew = createGroup [east, true];
			units _grpOld joinSilent _grpNew;
			deleteGroup _grpOld;			
		}];
	};
	
	case 3: {
		_id = _curator addEventHandler ["CuratorObjectPlaced", {
			params ["", "_unit"];
			if (driver _unit != leader _unit) exitWith {};
			
			private ["_grpNew", "_grpOld"];
			_grpOld = group _unit;
			_grpNew = createGroup [independent, true];
			units _grpOld joinSilent _grpNew;
			deleteGroup _grpOld;			
		}];
	};
	
	case 4: {
		_id = _curator addEventHandler ["CuratorObjectPlaced", {
			params ["", "_unit"];
			if (driver _unit != leader _unit) exitWith {};
			
			private ["_grpNew", "_grpOld"];
			_grpOld = group _unit;
			_grpNew = createGroup [civilian, true];
			units _grpOld joinSilent _grpNew;
			deleteGroup _grpOld;			
		}];
	};
};

_curator setVariable ["placeUnitEH", _id];