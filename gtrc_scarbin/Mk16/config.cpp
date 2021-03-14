class CfgPatches {
	class gtrc_scar_L {
		addonRootClass = "gtrc_scar";
		requiredAddons[] = {"A3_Weapons_F"};
		requiredVersion = 0.100000;
		units[] = {"Weapon_arifle_Mk16_blk_F", "Weapon_arifle_Mk16_CQC_blk_F", "Weapon_arifle_Mk16_CQC_F", "Weapon_arifle_Mk16_CQC_khk_F", "Weapon_arifle_Mk16_F", "Weapon_arifle_Mk16_GL_blk_F", "Weapon_arifle_Mk16_GL_F", "Weapon_arifle_Mk16_GL_khk_F", "Weapon_arifle_Mk16_khk_F"};
		weapons[] = {"arifle_Mk16_blk_F", "arifle_Mk16_CQC_blk_F", "arifle_Mk16_CQC_F", "arifle_Mk16_CQC_khk_F", "arifle_Mk16_F", "arifle_Mk16_GL_blk_F", "arifle_Mk16_GL_F", "arifle_Mk16_GL_khk_F", "arifle_Mk16_khk_F"};
	};
};

#include "CfgWeapons.hpp"

class CfgVehicles {
	class Weapon_Base_F;

	class Weapon_arifle_Mk16_F: Weapon_Base_F {
		scope = 2;
		scopeCurator = 2;
		displayName = "SCAR-L";
		author = "Phil0rd";
		editorCategory = "EdCat_Weapons";
		editorSubcategory = "EdSubcat_AssaultRifles";
		vehicleClass = "WeaponsPrimary";

		class TransportWeapons {

			class arifle_Mk16_F {
				weapon = "arifle_Mk16_F";
				count = 1;
			};
		};

		class TransportMagazines {

			class 30Rnd_556x45_Stanag {
				magazine = "30Rnd_556x45_Stanag";
				count = 1;
			};
		};
	};

	class Weapon_arifle_Mk16_blk_F: Weapon_Base_F {
		scope = 2;
		scopeCurator = 2;
		displayName = "SCAR-L (Black)";
		author = "Phil0rd";
		editorCategory = "EdCat_Weapons";
		editorSubcategory = "EdSubcat_AssaultRifles";
		vehicleClass = "WeaponsPrimary";

		class TransportWeapons {

			class arifle_Mk16_blk_F {
				weapon = "arifle_Mk16_blk_F";
				count = 1;
			};
		};

		class TransportMagazines {

			class 30Rnd_556x45_Stanag {
				magazine = "30Rnd_556x45_Stanag";
				count = 1;
			};
		};
	};

	class Weapon_arifle_Mk16_khk_F: Weapon_Base_F {
		scope = 2;
		scopeCurator = 2;
		displayName = "SCAR-L (Khaki)";
		author = "Phil0rd";
		editorCategory = "EdCat_Weapons";
		editorSubcategory = "EdSubcat_AssaultRifles";
		vehicleClass = "WeaponsPrimary";

		class TransportWeapons {

			class arifle_Mk16_khk_F {
				weapon = "arifle_Mk16_khk_F";
				count = 1;
			};
		};

		class TransportMagazines {

			class 30Rnd_556x45_Stanag {
				magazine = "30Rnd_556x45_Stanag";
				count = 1;
			};
		};
	};

	class Weapon_arifle_Mk16_CQC_F: Weapon_Base_F {
		scope = 2;
		scopeCurator = 2;
		displayName = "SCAR-L CQC";
		author = "Phil0rd";
		editorCategory = "EdCat_Weapons";
		editorSubcategory = "EdSubcat_AssaultRifles";
		vehicleClass = "WeaponsPrimary";

		class TransportWeapons {

			class arifle_Mk16_CQC_F {
				weapon = "arifle_Mk16_CQC_F";
				count = 1;
			};
		};

		class TransportMagazines {

			class 30Rnd_556x45_Stanag {
				magazine = "30Rnd_556x45_Stanag";
				count = 1;
			};
		};
	};

	class Weapon_arifle_Mk16_CQC_blk_F: Weapon_Base_F {
		scope = 2;
		scopeCurator = 2;
		displayName = "SCAR-L CQC (Black)";
		author = "Phil0rd";
		editorCategory = "EdCat_Weapons";
		editorSubcategory = "EdSubcat_AssaultRifles";
		vehicleClass = "WeaponsPrimary";

		class TransportWeapons {

			class arifle_Mk16_CQC_blk_F {
				weapon = "arifle_Mk16_CQC_blk_F";
				count = 1;
			};
		};

		class TransportMagazines {

			class 30Rnd_556x45_Stanag {
				magazine = "30Rnd_556x45_Stanag";
				count = 1;
			};
		};
	};

	class Weapon_arifle_Mk16_CQC_khk_F: Weapon_Base_F {
		scope = 2;
		scopeCurator = 2;
		displayName = "SCAR-L CQC (Khaki)";
		author = "Phil0rd";
		editorCategory = "EdCat_Weapons";
		editorSubcategory = "EdSubcat_AssaultRifles";
		vehicleClass = "WeaponsPrimary";

		class TransportWeapons {

			class arifle_Mk16_CQC_khk_F {
				weapon = "arifle_Mk16_CQC_khk_F";
				count = 1;
			};
		};

		class TransportMagazines {

			class 30Rnd_556x45_Stanag {
				magazine = "30Rnd_556x45_Stanag";
				count = 1;
			};
		};
	};

	class Weapon_arifle_Mk16_GL_F: Weapon_Base_F {
		scope = 2;
		scopeCurator = 2;
		displayName = "SCAR-L GL";
		author = "Phil0rd";
		editorCategory = "EdCat_Weapons";
		editorSubcategory = "EdSubcat_AssaultRifles";
		vehicleClass = "WeaponsPrimary";

		class TransportWeapons {

			class arifle_Mk16_GL_F {
				weapon = "arifle_Mk16_GL_F";
				count = 1;
			};
		};

		class TransportMagazines {

			class 30Rnd_556x45_Stanag {
				magazine = "30Rnd_556x45_Stanag";
				count = 1;
			};
		};
	};

	class Weapon_arifle_Mk16_GL_blk_F: Weapon_Base_F {
		scope = 2;
		scopeCurator = 2;
		displayName = "SCAR-L GL (Black)";
		author = "Phil0rd";
		editorCategory = "EdCat_Weapons";
		editorSubcategory = "EdSubcat_AssaultRifles";
		vehicleClass = "WeaponsPrimary";

		class TransportWeapons {

			class arifle_Mk16_GL_blk_F {
				weapon = "arifle_Mk16_GL_blk_F";
				count = 1;
			};
		};

		class TransportMagazines {

			class 30Rnd_556x45_Stanag {
				magazine = "30Rnd_556x45_Stanag";
				count = 1;
			};
		};
	};

	class Weapon_arifle_Mk16_GL_khk_F: Weapon_Base_F {
		scope = 2;
		scopeCurator = 2;
		displayName = "SCAR-L GL (Khaki)";
		author = "Phil0rd";
		editorCategory = "EdCat_Weapons";
		editorSubcategory = "EdSubcat_AssaultRifles";
		vehicleClass = "WeaponsPrimary";

		class TransportWeapons {

			class arifle_Mk16_GL_khk_F {
				weapon = "arifle_Mk16_GL_khk_F";
				count = 1;
			};
		};

		class TransportMagazines {

			class 30Rnd_556x45_Stanag {
				magazine = "30Rnd_556x45_Stanag";
				count = 1;
			};
		};
	};
};