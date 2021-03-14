
class SensorTemplateLaser;
class SensorTemplatePassiveRadar;

class CfgVehicles {
	class Heli_light_03_dynamicLoadout_base_F;
	class I_Heli_light_03_dynamicLoadout_F: Heli_light_03_dynamicLoadout_base_F {
		class Components;
	};
	
	class B_GTRC_Heli_light_03_dynamicLoadout_F: I_Heli_light_03_dynamicLoadout_F {
		_generalMacro = "B_GTRC_Heli_light_03_dynamicLoadout_F";
		ace_hellfire_addLaserDesignator = 0;
		displayName = $STR_GTRC_Vehicles_Heli_light_03_Name;
		crew = "B_helipilot_F";
		magazines[] = {"5000Rnd_762x51_Belt","168Rnd_CMFlare_Chaff_Magazine"};
		side = 1;
		faction = "GTRC";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"gtrc_vehicles\Heli_Light_03\data\Heli_Light_03_base_GTRC_CO.paa"};
		typicalCargo[] = {"B_Soldier_F"};
		
		class TextureSources {
			class Blufor {
				displayName = "GTRC";
				author = "Phil0rd";
				textures[] = {"gtrc_vehicles\Heli_Light_03\data\Heli_Light_03_base_GTRC_CO.paa"};
				factions[] = {"GTRC"};
			};
		};
		
		class Components: Components {
			class SensorsManagerComponent {
				class Components {
					class PassiveRadarSensorComponent: SensorTemplatePassiveRadar {
					};
					class LaserSensorComponent: SensorTemplateLaser {
					};
				};
			};
			class TransportPylonsComponent {
				uiPicture = "\A3\Air_F_EPB\Heli_Light_03\data\UI\Heli_Light_03_3DEN_CA.paa";
				class Pylons {
					class PylonLeft1 {
						attachment = "PylonRack_4Rnd_ACE_Hellfire_AGM114K";
						hardpoints[] = {"B_BOMB_PYLON", "UNI_SCALPEL", "O_SKYFIRE", "20MM_TWIN_CANNON", "B_BIM9X_RAIL", "B_BIM9X_DUAL_RAIL"};
						priority = 5;
						UIposition[] = {0.06,0.4};
					};
					class PylonRight1: PylonLeft1 {
						attachment = "PylonRack_4Rnd_ACE_Hellfire_AGM114N";
						mirroredMissilePos = 1;
						UIposition[] = {0.59,0.4};
					};
				};
			};
		};
	};
};