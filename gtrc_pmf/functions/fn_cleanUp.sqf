private _allHolders = (
	allMissionObjects "WeaponHolder" +
	allMissionObjects "GroundWeaponHolder" +
	allMissionObjects "WeaponHolderSimulated"
);
{
	private _thisHolder = _x;
	private _nearPlayer = false;
	{
		if ((_thisHolder distance _x) < 1000 && (_thisHolder distance getMarkerPos PMF_baseMarker) > 1000) exitWith {_nearPlayer = true};
	} forEach allPlayers;
	if ((!_nearPlayer) && !(_thisHolder getVariable ["PMF_dontDelete", false])) then {deleteVehicle _thisHolder};
} forEach _allHolders;