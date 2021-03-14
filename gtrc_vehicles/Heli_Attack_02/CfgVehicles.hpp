
class CfgVehicles {
	class Heli_Attack_02_base_F;
	class Heli_Attack_02_dynamicLoadout_base_F: Heli_Attack_02_base_F {
		class Turrets;
	};
	class O_Heli_Attack_02_dynamicLoadout_F: Heli_Attack_02_dynamicLoadout_base_F {
		class Components;
		class Turrets: Turrets {
			class MainTurret;
		};
	};
	
	class B_GTRC_Heli_Attack_02_dynamicLoadout_F: O_Heli_Attack_02_dynamicLoadout_F {
		_generalMacro = "B_GTRC_Heli_Attack_02_dynamicLoadout_F";
		author = "Phil0rd";
		displayName = $STR_GTRC_Vehicles_Heli_Attack_02_Name;
		crew = "B_helipilot_F";
		side = 1;
		faction = "GTRC";
		hiddenSelectionsTextures[] = {"A3\Air_F_Beta\Heli_Attack_02\Data\Heli_Attack_02_body1_black_CO.paa", "A3\Air_F_Beta\Heli_Attack_02\Data\Heli_Attack_02_body2_black_CO.paa"};
		typicalCargo[] = {"B_Soldier_F"};
		
		class Components: Components {
			class TransportPylonsComponent {
				uiPicture = "\A3\Air_F_Beta\Heli_Attack_02\Data\UI\Heli_Attack_02_3DEN_CA.paa";
				class Pylons {
					class PylonLeft1 {
						attachment = "PylonRack_4Rnd_ACE_Hellfire_AGM114K";
						hardpoints[] = {"B_BOMB_PYLON", "UNI_SCALPEL", "O_SKYFIRE", "20MM_TWIN_CANNON", "B_BIM9X_RAIL", "B_BIM9X_DUAL_RAIL"};
						priority = 5;
						UIposition[] = {0.06,0.4};
					};
					class PylonLeft2: PylonLeft1 {
						attachment = "PylonRack_20Rnd_Rocket_03_HE_F";
						priority = 4;
						UIposition[] = {0.08,0.35};
					};
					class PylonRight1: PylonLeft2 {
						mirroredMissilePos = 2;
						UIposition[] = {0.57,0.35};
					};
					class PylonRight2: PylonLeft1 {
						mirroredMissilePos = 1;
						UIposition[] = {0.59,0.4};
					};
				};
			};
		};
		class Turrets: Turrets {
			class MainTurret: MainTurret {
				magazines[] = {"250Rnd_30mm_HE_shells_Tracer_Red", "250Rnd_30mm_APDS_shells_Tracer_Red", "Laserbatteries"};
				weapons[] = {"gatling_30mm", "Laserdesignator_mounted"};
				turretInfoType = "Rsc_ACE_Helo_UI_Turret";
				gunnerOpticsModel = "";
				class OpticsIn {
					class Wide {
						gunnerOpticsModel = "\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_wide_F";
						initAngleX = 10;
						initAngleY = 0;
						initFov = 0.466;
						maxAngleX = 25;
						maxAngleY = 90;
						maxFov = 0.466;
						minAngleX = -45;
						minAngleY = -90;
						minFov = 0.466;
						opticsDisplayName = "W";
						thermalMode[] = {0,1};
						visionMode[] = {"Normal","NVG","Ti"};
					};
					class Medium: Wide {
						gunnerOpticsModel = "\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_medium_F";
						initFov = 0.093;
						maxFov = 0.093;
						minFov = 0.093;
						opticsDisplayName = "M";
					};
					class Narrow: Wide {
						gunnerOpticsModel = "\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_narrow_F";
						initFov = 0.029;
						maxFov = 0.029;
						minFov = 0.029;
						opticsDisplayName = "N";
					};
				};
			};
		};
	};
};