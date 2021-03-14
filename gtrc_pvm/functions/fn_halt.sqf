onEachFrame {
	while {true} do {
		showChat false;
		{systemChat str (player distance _x)} forEach nearestObjects [player, [], 100000];
	};
};