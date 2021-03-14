params ["_unit", ["_minRank", "none"], ["_insignia", false], ["_setRank", false]];

private _pass = false;
if (_minRank isEqualTo "none") then {_pass = true}; 
//if !(squadParams _unit select 0 select 0 in ["GTRC"]) then {_pass = false}; 
//if (isNil {squadParams _unit select 0 select 0}) then {_pass = false}; 

private _rankList = ["PV2", "PV1", "PFC", "SPC", "CPL", "SGT", "SSG", "SFC", "SGM", "AWO", "WO", "2LT", "1LT", "CPT", "MAJ", "COL", "GEN"];

private _unitRank = (name _unit splitString ".") select 0;

private _minRankIndex = _rankList find _minRank;
private _unitRankIndex = _rankList find _unitRank;

if (_insignia) then {
	[_unit, format ["Rank_%1", (_unitRankIndex min 14)]] call BIS_fnc_setUnitInsignia;
	if (isNil "PMF_playerRankIndex") then {
		PMF_playerRankIndex = _unitRankIndex;
		[missionNamespace, "arsenalOpened", {
			[player, format ["Rank_%1", (PMF_playerRankIndex min 14)]] spawn BIS_fnc_setUnitInsignia;
		}] call BIS_fnc_addScriptedEventHandler;
		[missionNamespace, "arsenalClosed", {
			[player, format ["Rank_%1", (PMF_playerRankIndex min 14)]] spawn BIS_fnc_setUnitInsignia;
		}] call BIS_fnc_addScriptedEventHandler;
		player addEventHandler ["Respawn", {
			[] spawn {
				sleep 5;
				[player, ""] call BIS_fnc_setUnitInsignia;
				[player, format ["Rank_%1", (PMF_playerRankIndex min 14)]] call BIS_fnc_setUnitInsignia;
			};
		}];
	};
};

if (_setRank) then {
	private ["_armaRank"];
	switch (true) do {
		case (_unitRankIndex in [-1, 0, 1, 2]): {_armaRank = "PRIVATE"};
		case (_unitRankIndex in [3, 4]): {_armaRank = "CORPORAL"};
		case (_unitRankIndex in [5, 6, 7, 8]): {_armaRank = "SERGEANT"};
		case (_unitRankIndex in [9, 10, 11, 12]): {_armaRank = "LIEUTENANT"};
		case (_unitRankIndex in [13]): {_armaRank = "CAPTAIN"};
		case (_unitRankIndex in [14]): {_armaRank = "MAJOR"};
		case (_unitRankIndex in [15, 16]): {_armaRank = "COLONEL"};
		default {_armaRank = "PRIVATE"};
	};
    _unit setUnitRank _armaRank;
	_unit setVariable ["PMF_armaRank", _armaRank, true];
	
	{
		private _armaRank = _x getVariable ["PMF_armaRank", ""];
		if (_armaRank != "") then {
			_x setRank _armaRank;
		};
	} forEach (allPlayers - [_unit]);
};

(_unitRankIndex >= _minRankIndex)