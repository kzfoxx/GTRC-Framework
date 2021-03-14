class MuzzleSlot;
class SlotInfo;
class CowsSlot;
class PointerSlot;
class UnderBarrelSlot;
class Mode_SemiAuto;
class Mode_FullAuto;

class CfgWeapons {
	class Rifle;
	class UGL_F;
	class Rifle_Base_F: Rifle {
		class Single;
		class FullAuto;
		class WeaponSlotsInfo;
	};
	class arifle_MX_Base_F: Rifle_Base_F {};
	class arifle_Mk16_base_F: arifle_MX_Base_F {
		author = "Phil0rd";
		_generalMacro = "arifle_Mk16_base_F";
		scope = 0;
		displayName = "SCAR-L";
		descriptionShort = "Mk16 SCAR-L";
		model = "gtrc_scar\Mk16\Mk16_F.p3d";
		hiddenSelections[] = {"camo1", "camo2"};
		handAnim[] = {"OFP2_ManSkeleton", "gtrc_scar\Mk16\Data\Anim\Mk16.rtm"};
		reloadAction = "GestureReloadSPAR_01";
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag_Tracer_Red","30Rnd_556x45_Stanag_Tracer_Green","30Rnd_556x45_Stanag_Tracer_Yellow","30Rnd_556x45_Stanag_red","30Rnd_556x45_Stanag_green","ACE_30Rnd_556x45_Stanag_M995_AP_mag","ACE_30Rnd_556x45_Stanag_Mk262_mag","ACE_30Rnd_556x45_Stanag_Mk318_mag","ACE_30Rnd_556x45_Stanag_Tracer_Dim","rhs_mag_30Rnd_556x45_Mk318_Stanag","rhs_mag_30Rnd_556x45_Mk262_Stanag","rhs_mag_30Rnd_556x45_M855A1_Stanag","rhs_mag_30Rnd_556x45_M855A1_Stanag_No_Tracer","rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Red","rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Green","rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Yellow","rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Orange","rhs_mag_30Rnd_556x45_M200_Stanag"};
		htMin = 8;
		htMax = 920;
		inertia = 0.600000;
		dexterity = 1.600000;
		initSpeed = 870;
		recoil = "recoil_spar";
		maxZeroing = 800;
		bullet1[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_01", 0.501187, 1, 15};
		bullet2[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_02", 0.501187, 1, 15};
		bullet3[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_03", 0.501187, 1, 15};
		bullet4[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_04", 0.501187, 1, 15};
		bullet5[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_01", 0.398107, 1, 15};
		bullet6[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_02", 0.398107, 1, 15};
		bullet7[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_03", 0.398107, 1, 15};
		bullet8[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_04", 0.398107, 1, 15};
		bullet9[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_01", 0.251189, 1, 15};
		bullet10[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_02", 0.251189, 1, 15};
		bullet11[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_03", 0.251189, 1, 15};
		bullet12[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_04", 0.251189, 1, 15};
		soundBullet[] = {"bullet1", 0.083000, "bullet2", 0.083000, "bullet3", 0.083000, "bullet4", 0.083000, "bullet5", 0.083000, "bullet6", 0.083000, "bullet7", 0.083000, "bullet8", 0.083000, "bullet9", 0.083000, "bullet10", 0.083000, "bullet11", 0.083000, "bullet12", 0.083000};

		class Library {
			libTextDesc = "Mk16 SCAR-L";
		};

		class WeaponSlotsInfo {

			class MuzzleSlot: MuzzleSlot {
				linkProxy = "\A3\Data_F\Proxies\weapon_slots\MUZZLE";
				iconPosition[] = {0, 0.450000};
				iconScale = 0.200000;
			};

			class CowsSlot: CowsSlot {
				iconPosition[] = {0.450000, 0.280000};
				iconScale = 0.200000;
			};

			class PointerSlot: PointerSlot {
				iconPosition[] = {0.350000, 0.450000};
				iconScale = 0.200000;
			};

			class UnderBarrelSlot: UnderBarrelSlot {
				iconPosition[] = {0.200000, 0.800000};
				iconScale = 0.300000;
			};
			mass = 73;
		};
		distanceZoomMin = 300;
		distanceZoomMax = 300;
		modes[] = {"Single", "FullAuto", "single_medium_optics1", "single_medium_optics2", "fullauto_medium"};

		class Single: Mode_SemiAuto {
			reloadTime = 0.096000;
			dispersion = 0.000580;
			minRange = 2;
			minRangeProbab = 0.300000;
			midRange = 150;
			midRangeProbab = 0.700000;
			maxRange = 300;
			maxRangeProbab = 0.050000;
		};

		class FullAuto: Mode_FullAuto {
			reloadTime = 0.096000;
			dispersion = 0.000580;
			minRange = 2;
			minRangeProbab = 0.900000;
			midRange = 20;
			midRangeProbab = 0.700000;
			maxRange = 40;
			maxRangeProbab = 0.050000;
			aiRateOfFire = 0.000001;
		};

		class fullauto_medium: FullAuto {
			showToPlayer = 0;
			burst = 3;
			minRange = 2;
			minRangeProbab = 0.500000;
			midRange = 75;
			midRangeProbab = 0.700000;
			maxRange = 100;
			maxRangeProbab = 0.050000;
			aiRateOfFire = 2;
		};

		class single_medium_optics1: Single {
			requiredOpticType = 1;
			showToPlayer = 0;
			minRange = 5;
			minRangeProbab = 0.200000;
			midRange = 300;
			midRangeProbab = 0.700000;
			maxRange = 450;
			maxRangeProbab = 0.300000;
			aiRateOfFire = 5;
			aiRateOfFireDistance = 500;
		};

		class single_medium_optics2: single_medium_optics1 {
			requiredOpticType = 2;
			minRange = 100;
			minRangeProbab = 0.100000;
			midRange = 400;
			midRangeProbab = 0.700000;
			maxRange = 600;
			maxRangeProbab = 0.050000;
			aiRateOfFire = 6;
			aiRateOfFireDistance = 600;
		};
	};

	class arifle_Mk16_F: arifle_Mk16_base_F {
		author = "Phil0rd";
		_generalMacro = "arifle_Mk16_F";
		baseWeapon = "arifle_Mk16_F";
		scope = 2;
		displayName = "SCAR-L";
		picture = "gtrc_scar\Mk16\Data\UI\gear_Mk16_X_CA.paa";
		hiddenSelectionsTextures[] = {"gtrc_scar\Mk16\Data\SCAR_L_CO.paa", "gtrc_scar\Mk16\Data\SCAR_acc_CO.paa"};
	};

	class arifle_Mk16_blk_F: arifle_Mk16_base_F {
		author = "Phil0rd";
		_generalMacro = "arifle_Mk16_blk_F";
		baseWeapon = "arifle_Mk16_blk_F";
		scope = 2;
		displayName = "SCAR-L (Black)";
		picture = "gtrc_scar\Mk16\Data\UI\gear_Mk16_blk_X_CA.paa";
		hiddenSelectionsTextures[] = {"gtrc_scar\Mk16\Data\SCAR_L_blk_CO.paa", "gtrc_scar\Mk16\Data\SCAR_acc_blk_CO.paa"};
	};

	class arifle_Mk16_khk_F: arifle_Mk16_base_F {
		author = "Phil0rd";
		_generalMacro = "arifle_Mk16_khk_F";
		baseWeapon = "arifle_Mk16_khk_F";
		scope = 2;
		displayName = "SCAR-L (Khaki)";
		picture = "gtrc_scar\Mk16\Data\UI\gear_Mk16_khk_X_CA.paa";
		hiddenSelectionsTextures[] = {"gtrc_scar\Mk16\Data\SCAR_L_khk_CO.paa", "gtrc_scar\Mk16\Data\SCAR_acc_khk_CO.paa"};
	};

	class arifle_Mk16_CQC_base_F: arifle_Mk16_base_F {
		author = "Phil0rd";
		_generalMacro = "arifle_Mk16_CQC_base_F";
		scope = 0;
		model = "gtrc_scar\Mk16\Mk16_CQC_F.p3d";
		reloadAction = "GestureReloadSPAR_01";
		inertia = 0.500000;
		aimTransitionSpeed = 1.100000;
		initSpeed = 815;
		maxZeroing = 600;

		class WeaponSlotsInfo: WeaponSlotsInfo {
			mass = 67;
		};

		class Single: Single {
			dispersion = 0.000880;
		};

		class FullAuto: FullAuto {
			dispersion = 0.000880;
		};
		aiDispersionCoefY = 6;
		aiDispersionCoefX = 4;
	};

	class arifle_Mk16_CQC_F: arifle_Mk16_CQC_base_F {
		author = "Phil0rd";
		_generalMacro = "arifle_Mk16_CQC_F";
		baseWeapon = "arifle_Mk16_CQC_F";
		scope = 2;
		displayName = "SCAR-L CQC";
		picture = "gtrc_scar\Mk16\Data\UI\gear_Mk16_CQC_X_CA.paa";
		hiddenSelectionsTextures[] = {"gtrc_scar\Mk16\Data\SCAR_L_CO.paa", "gtrc_scar\Mk16\Data\SCAR_acc_CO.paa"};
	};

	class arifle_Mk16_CQC_blk_F: arifle_Mk16_CQC_base_F {
		author = "Phil0rd";
		_generalMacro = "arifle_Mk16_CQC_blk_F";
		baseWeapon = "arifle_Mk16_CQC_blk_F";
		scope = 2;
		displayName = "SCAR-L CQC (Black)";
		picture = "gtrc_scar\Mk16\Data\UI\gear_Mk16_CQC_blk_X_CA.paa";
		hiddenSelectionsTextures[] = {"gtrc_scar\Mk16\Data\SCAR_L_blk_CO.paa", "gtrc_scar\Mk16\Data\SCAR_acc_blk_CO.paa"};
	};

	class arifle_Mk16_CQC_khk_F: arifle_Mk16_CQC_base_F {
		author = "Phil0rd";
		_generalMacro = "arifle_Mk16_CQC_khk_F";
		baseWeapon = "arifle_Mk16_CQC_khk_F";
		scope = 2;
		displayName = "SCAR-L CQC (Khaki)";
		picture = "gtrc_scar\Mk16\Data\UI\gear_Mk16_CQC_khk_X_CA.paa";
		hiddenSelectionsTextures[] = {"gtrc_scar\Mk16\Data\SCAR_L_khk_CO.paa", "gtrc_scar\Mk16\Data\SCAR_acc_khk_CO.paa"};
	};

	class arifle_Mk16_GL_base_F: arifle_Mk16_base_F {
		author = "Phil0rd";
		_generalMacro = "arifle_Mk16_GL_base_F";
		scope = 0;
		model = "gtrc_scar\Mk16\Mk16_GL_F.p3d";
		UiPicture = "\A3\Weapons_F\Data\UI\icon_gl_CA.paa";
		hiddenSelections[] = {"camo1", "camo2", "camo3"};
		handAnim[] = {"OFP2_ManSkeleton", "gtrc_scar\Mk16\Data\Anim\Mk16_gl.rtm"};
		reloadAction = "GestureReloadSPAR_01";
		inertia = 0.700000;
		aimTransitionSpeed = 0.900000;

		class WeaponSlotsInfo: WeaponSlotsInfo {
			class UnderBarrelSlot {};
			mass = 103;
		};

		class EGLM: UGL_F {
			useModelOptics = 0;
			useExternalOptic = 0;
			cameraDir = "OP_look";
			discreteDistance[] = {50, 75, 100, 150, 200, 250, 300, 350, 400};
			discreteDistanceCameraPoint[] = {"OP_eye_50", "OP_eye_75", "OP_eye_100", "OP_eye_150", "OP_eye_200", "OP_eye_250", "OP_eye_300", "OP_eye_350", "OP_eye_400"};
			discreteDistanceInitIndex = 1;
			reloadAction = "GestureReloadTrgUGL";
		};
		aiDispersionCoefY = 6;
		aiDispersionCoefX = 4;
		muzzles[] = {"this", "EGLM"};
	};

	class arifle_Mk16_GL_F: arifle_Mk16_GL_base_F {
		author = "Phil0rd";
		_generalMacro = "arifle_Mk16_GL_F";
		baseWeapon = "arifle_Mk16_GL_F";
		scope = 2;
		displayName = "SCAR-L GL";
		picture = "gtrc_scar\Mk16\Data\UI\gear_Mk16_GL_X_CA.paa";
		hiddenSelectionsTextures[] = {"gtrc_scar\Mk16\Data\SCAR_L_CO.paa", "gtrc_scar\Mk16\Data\SCAR_acc_CO.paa", "gtrc_scar\Mk16\Data\EGLM_CO.paa"};
	};

	class arifle_Mk16_GL_blk_F: arifle_Mk16_GL_base_F {
		author = "Phil0rd";
		_generalMacro = "arifle_Mk16_GL_blk_F";
		baseWeapon = "arifle_Mk16_GL_blk_F";
		scope = 2;
		displayName = "SCAR-L GL (Black)";
		picture = "gtrc_scar\Mk16\Data\UI\gear_Mk16_GL_blk_X_CA.paa";
		hiddenSelectionsTextures[] = {"gtrc_scar\Mk16\Data\SCAR_L_blk_CO.paa", "gtrc_scar\Mk16\Data\SCAR_acc_blk_CO.paa", "gtrc_scar\Mk16\Data\EGLM_blk_CO.paa"};
	};

	class arifle_Mk16_GL_khk_F: arifle_Mk16_GL_base_F {
		author = "Phil0rd";
		_generalMacro = "arifle_Mk16_GL_khk_F";
		baseWeapon = "arifle_Mk16_GL_khk_F";
		scope = 2;
		displayName = "SCAR-L GL (Khaki)";
		picture = "gtrc_scar\Mk16\Data\UI\gear_Mk16_GL_khk_X_CA.paa";
		hiddenSelectionsTextures[] = {"gtrc_scar\Mk16\Data\SCAR_L_khk_CO.paa", "gtrc_scar\Mk16\Data\SCAR_acc_khk_CO.paa", "gtrc_scar\Mk16\Data\EGLM_khk_CO.paa"};
	};
};