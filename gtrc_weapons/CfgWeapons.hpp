
class CfgWeapons {

	class Rifle_Long_Base_F;
	class LMG_03_base_F: Rifle_Long_Base_F {
		class WeaponSlotsInfo;
	};
	class LMG_03_F: LMG_03_base_F {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			mass = 150;
		};
	};
	
	class Rifle;
	class Rifle_Base_F: Rifle {
		class WeaponSlotsInfo;
	};
	class arifle_AK12_base_F: Rifle_Base_F {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			mass = 80;
		};
	};
	class arifle_AK12_GL_base_F: arifle_AK12_base_F {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			mass = 100;
		}; 
	};
	class arifle_AKM_base_F: Rifle_Base_F {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			mass = 75;
		};
	};
	class arifle_AKS_base_F: Rifle_Base_F {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			mass = 65;
		};
	};
	class arifle_AK12U_base_F: arifle_AK12_base_F {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			mass = 70;
		};
	};
	class arifle_RPK12_base_F: arifle_AK12_base_F {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			mass = 106;
		};
	};
	class arifle_ARX_base_F: Rifle_Base_F {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			mass = 100;
		};
	};
	
	class Launcher;
	class Launcher_Base_F: Launcher {
		class WeaponSlotsInfo;
	};
	class rhs_weap_maaws: Launcher_Base_F {
		displayName = "M3E1 MAAWS";
		class WeaponSlotsInfo: WeaponSlotsInfo {
			mass = 127;
		};
	};
};