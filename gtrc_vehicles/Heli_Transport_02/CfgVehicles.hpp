
class CfgVehicles {
	class I_Heli_Transport_02_F;
	
	class B_GTRC_Heli_Transport_02_F: I_Heli_Transport_02_F {
		_generalMacro = "B_GTRC_Heli_Transport_02_F";
		displayName = $STR_GTRC_Vehicles_Heli_Transport_02_Name;
		crew = "B_helipilot_F";
		side = 1;
		faction = "GTRC";
		hiddenSelections[] = {"camo1", "camo2", "camo3"};
		hiddenSelectionsTextures[] = {
			"gtrc_vehicles\Heli_Transport_02\data\blu_mohawk_co.paa",
			"gtrc_vehicles\Heli_Transport_02\data\blu_mohawk2_co.paa",
			"gtrc_vehicles\Heli_Transport_02\data\blu_mohawk3_co.paa"
		};
		typicalCargo[] = {"B_Soldier_F"};
	};
};