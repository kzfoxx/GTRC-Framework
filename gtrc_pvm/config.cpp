class CfgPatches {
	class gtrc_pvm {
		requiredAddons[] = {};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] = {};
	};
};

class CfgSounds {
	sounds[] = {Devas_click};
	class Devas_click {
		name = "Devas_click";
		sound[] = {"gtrc_pvm\scripts\AutoPilot\Sound\Devas_click.ogg", db+15, 1.0};
		titles[] = {};
	};
};

#include "CfgFunctions.hpp"
#include "CfgVehicles.hpp"