private _weight = (round ((loadAbs player)*0.1*0.4536*100))/100;

private _arsenalText = "<t color='#00ff00' size='1.5'>当前负重: %1kg</t>";

if (_weight > PMF_noSprintWeight) then {
	player allowSprint false;
	_arsenalText = "<t color='#ffff00' size='1.5'>当前负重: %1kg</t>";
} else {
	player allowSprint true;
};

if (_weight > PMF_forceWalkWeight) then {
	player forceWalk true;
	_arsenalText = "<t color='#ff0000' size='1.5'>当前负重: %1kg</t>";
} else {
	player forceWalk false;
};

if (!isNull (uinamespace getvariable "RSCDisplayArsenal")) then {
	cutText [format [_arsenalText, _weight], "PLAIN DOWN", 0.5, true, true];
};