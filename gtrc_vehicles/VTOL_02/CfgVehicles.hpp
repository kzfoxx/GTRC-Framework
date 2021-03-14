
class CfgVehicles {
	class VTOL_02_infantry_base_F;
	class VTOL_02_infantry_dynamicLoadout_base_F: VTOL_02_infantry_base_F {
		class TextureSources;
		class Turrets;
	};
	class O_T_VTOL_02_infantry_dynamicLoadout_F: VTOL_02_infantry_dynamicLoadout_base_F {
		class Components;
		class TextureSources: TextureSources {
			class GreenHex;
			class Grey;
			class Hex;
		};
		class Turrets: Turrets {
			class GunnerTurret;
		};
	};
	class B_GTRC_VTOL_02_infantry_dynamicLoadout_F: O_T_VTOL_02_infantry_dynamicLoadout_F {
		_generalMacro = B_GTRC_VTOL_02_infantry_dynamicLoadout_F;
		author = "Phil0rd";
		crew = "B_Pilot_F";
		displayName = $STR_GTRC_Vehicles_VTOL_02_Name;
		side = 1;
		faction = "GTRC";
		hiddenSelectionsTextures[] = {"gtrc_vehicles\VTOL_02\data\VTOL_02_EXT01_green_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT02_green_CO.paa","gtrc_vehicles\VTOL_02\data\VTOL_02_EXT03_L_green_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT03_R_green_CO.paa"};
		textureList[] = {"Green",1};
		typicalCargo[] = {"B_Soldier_F"};
		
		class Components: Components {
			class TransportPylonsComponent {
				uiPicture = "\A3\Air_F_Exp\VTOL_02\Data\UI\VTOL_02_3DEN_CA.paa";
				class Pylons {
					class PylonRight1 {
						attachment = "PylonRack_4Rnd_ACE_Hellfire_AGM114K";
						hardpoints[] = {"B_BOMB_PYLON", "UNI_SCALPEL", "O_SKYFIRE", "20MM_TWIN_CANNON", "B_BIM9X_RAIL", "B_BIM9X_DUAL_RAIL"};
						priority = 5;
						UIposition[] = {0.35,0.16};
					};
					class PylonRight2: PylonRight1 {
						attachment = "PylonRack_20Rnd_Rocket_03_HE_F";
						priority = 4;
						UIposition[] = {0.33,0.21};
					};
					class PylonLeft1: PylonRight2 {
						mirroredMissilePos = 2;
						UIposition[] = {0.33,0.34};
					};
					class PylonLeft2: PylonRight1 {
						mirroredMissilePos = 1;
						UIposition[] = {0.35,0.39};
					};
				};
			};
		};
		class Turrets: Turrets {
			class GunnerTurret: GunnerTurret {
				magazines[] = {"250Rnd_30mm_HE_shells_Tracer_Red","250Rnd_30mm_APDS_shells_Tracer_Red","Laserbatteries"};
				turretInfoType = "Rsc_ACE_Helo_UI_Turret";
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
		class TextureSources: TextureSources {
			class GreenHex: GreenHex {
				factions[] = {"OPF_F","OPF_T_F","GTRC"};
			};
			class Grey: Grey {
				factions[] = {"OPF_F","OPF_T_F","GTRC"};
			};
			class Hex: Hex {
				factions[] = {"OPF_F","OPF_T_F","GTRC"};
			};
			class Standard {
				displayName = "Standard";
				author = "JustUnfriendly";
				factions[] = {"OPF_F","OPF_T_F","GTRC"};
				textures[] = {"gtrc_vehicles\VTOL_02\data\VTOL_02_EXT01_grey_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT02_grey_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT03_L_grey_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT03_R_grey_CO.paa"};
			};

			class Black {
				displayName = "Black";
				author = "JustUnfriendly";
				factions[] = {"OPF_F","OPF_T_F","GTRC"};
				textures[] = {"gtrc_vehicles\VTOL_02\data\VTOL_02_EXT01_black_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT02_black_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT03_L_black_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT03_R_black_CO.paa"};
			};

			class Green {
				displayName = "Green";
				author = "JustUnfriendly";
				factions[] = {"OPF_F","OPF_T_F","GTRC"};
				textures[] = {"gtrc_vehicles\VTOL_02\data\VTOL_02_EXT01_green_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT02_green_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT03_L_green_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT03_R_green_CO.paa"};
			};

			class Brown {
				displayName = "Brown";
				author = "JustUnfriendly";
				factions[] = {"OPF_F","OPF_T_F","GTRC"};
				textures[] = {"gtrc_vehicles\VTOL_02\data\VTOL_02_EXT01_brown_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT02_brown_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT03_L_brown_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT03_R_brown_CO.paa"};
			};

			class Tan {
				displayName = "Tan";
				author = "JustUnfriendly";
				factions[] = {"OPF_F","OPF_T_F","GTRC"};
				textures[] = {"gtrc_vehicles\VTOL_02\data\VTOL_02_EXT01_tan_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT02_tan_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT03_L_tan_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT03_R_tan_CO.paa"};
			};

			class Red {
				displayName = "Red";
				author = "JustUnfriendly";
				factions[] = {"OPF_F","OPF_T_F","GTRC"};
				textures[] = {"gtrc_vehicles\VTOL_02\data\VTOL_02_EXT01_red_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT02_red_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT03_L_red_CO.paa", "gtrc_vehicles\VTOL_02\data\VTOL_02_EXT03_R_red_CO.paa"};
			};
		};
	};
};