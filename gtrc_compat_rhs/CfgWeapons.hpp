#define compat_556 {"rhs_mag_30Rnd_556x45_M855A1_Stanag","rhs_mag_30Rnd_556x45_M855A1_Stanag_No_Tracer","rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Red","rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Green","rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Yellow","rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Orange","rhs_mag_30Rnd_556x45_Mk318_Stanag","rhs_mag_30Rnd_556x45_Mk262_Stanag","rhs_mag_30Rnd_556x45_M200_Stanag","ACE_30Rnd_556x45_Stanag_M995_AP_mag","ACE_30Rnd_556x45_Stanag_Mk318_mag","ACE_30Rnd_556x45_Stanag_Mk262_mag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag_red","30Rnd_556x45_Stanag_green","30Rnd_556x45_Stanag_Tracer_Red","30Rnd_556x45_Stanag_Tracer_Green","30Rnd_556x45_Stanag_Tracer_Yellow","ACE_30Rnd_556x45_Stanag_Tracer_Dim","rhs_mag_30Rnd_556x45_M855_Stanag","rhs_mag_30Rnd_556x45_M855_Stanag_Tracer_Red","rhs_mag_30Rnd_556x45_M855_Stanag_Tracer_Green","rhs_mag_30Rnd_556x45_M855_Stanag_Tracer_Yellow","rhs_mag_30Rnd_556x45_M855_Stanag_Tracer_Orange"}

#define compat_762 {"ACE_20Rnd_762x51_Mk316_Mod_0_Mag","ACE_20Rnd_762x51_Mk319_Mod_0_Mag","ACE_20Rnd_762x51_M118LR_Mag","ACE_20Rnd_762x51_M993_AP_Mag","ACE_20Rnd_762x51_Mag_SD","20Rnd_762x51_Mag","ACE_20Rnd_762x51_Mag_Tracer","ACE_20Rnd_762x51_Mag_Tracer_Dim","rhsusf_20Rnd_762x51_m118_special_Mag","rhsusf_20Rnd_762x51_m993_Mag","rhsusf_20Rnd_762x51_m62_Mag"}

#define compat_UGL {"1Rnd_HE_Grenade_shell","UGL_FlareWhite_F","UGL_FlareGreen_F","UGL_FlareRed_F","UGL_FlareYellow_F","UGL_FlareCIR_F","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","1Rnd_SmokeYellow_Grenade_shell","1Rnd_SmokePurple_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell","1Rnd_SmokeOrange_Grenade_shell","ACE_HuntIR_M203","rhs_mag_M441_HE","rhs_mag_M433_HEDP","rhs_mag_M781_Practice","rhs_mag_M397_HET","rhs_mag_M4009","rhs_mag_m576"}

class CfgWeapons {
	class Rifle_Base_F;
	class srifle_EBR_F;
	class UGL_F;
	class mk20_base_F;
	class Tavor_base_F;
	class DMR_03_base_F;
	class DMR_06_base_F;
	
	class arifle_Mk20_F: mk20_base_F {
		magazineWell[] = {"STANAG_556x45"};
	};
	class arifle_Mk20_GL_F: mk20_base_F {
		magazineWell[] = {"STANAG_556x45"};
	};
	class arifle_Mk20C_F: mk20_base_F {
		magazineWell[] = {"STANAG_556x45"};
	};
	class arifle_TRG20_F: Tavor_base_F {
		magazineWell[] = {"STANAG_556x45"};
	};
	class arifle_TRG21_F: Tavor_base_F {
		magazineWell[] = {"STANAG_556x45"};
	};
	class arifle_TRG21_GL_F: arifle_TRG21_F {
		magazineWell[] = {"STANAG_556x45"};
	};
	class arifle_SPAR_01_base_F: Rifle_Base_F {
		magazineWell[] = {"STANAG_556x45"};
	};
	
	class srifle_DMR_03_F: DMR_03_base_F {
		magazineWell[] = {"CBA_762x51_M14"};
	};
	
	class SMA_AssaultBase;
	class SMA_556_RIFLEBASE: SMA_AssaultBase {
		ACE_barrelLength = 355;
		ACE_barrelTwist = 177.8;
		ACE_clearJamAction = "GestureReloadMX";
		ace_overheating_dispersion = 1;
		ace_overheating_mrbs = 3000;
		ace_overheating_slowdownFactor = 1;
		ACE_RailHeightAboveBore = 3.56139;
		initSpeed = -0.94;
		magazines[] = compat_556;
		magazineWell[] = {"STANAG_556x45"};
		scope = 1;
	};
	class SMA_MK16: SMA_556_RIFLEBASE {};
	class SMA_Mk16QCB: SMA_MK16 {
		ACE_barrelLength = 254;
		initSpeed = -0.8979;
	};
	class SMA_Mk16_blackQCB: SMA_MK16 {
		ACE_barrelLength = 254;
		initSpeed = -0.8979;
	};
	class SMA_Mk16_GreenQCB: SMA_MK16 {
		ACE_barrelLength = 254;
		initSpeed = -0.8979;
	};

	class SMA_Steyr_AUG_BASE_F: SMA_556_RIFLEBASE {
		ACE_barrelLength = 406.4;
		initSpeed = -0.974297;
	};
	class SMA_A3_BASE_F: SMA_556_RIFLEBASE {
		ACE_barrelLength = 441.96;
		initSpeed = -0.992849;
	};

	class SMA_762_RIFLEBASE: SMA_AssaultBase {
		ACE_barrelLength = 330;
		ACE_barrelTwist = 279.4;
		ACE_clearJamAction = "GestureReloadMX";
		ace_overheating_dispersion = 1;
		ace_overheating_mrbs = 3000;
		ace_overheating_slowdownFactor = 1;
		ACE_RailHeightAboveBore = 3.56139;
		initSpeed = -0.8979;
		magazines[] = compat_762;
		magazineWell[] = {"CBA_762x51_M14"};
		scope = 1;
	};
	class SMA_Mk17: SMA_762_RIFLEBASE {};
	class SMA_Mk17_16: SMA_Mk17 {
		ACE_barrelLength = 400;
		initSpeed = -0.94;
	};
	class SMA_Mk17_16_black: SMA_Mk17 {
		ACE_barrelLength = 400;
		initSpeed = -0.94;
	};
	class SMA_Mk17_16_Green: SMA_Mk17 {
		ACE_barrelLength = 400;
		initSpeed = -0.94;
	};
	class rhs_weap_M590_5RD: Rifle_Base_F {
		magazines[] = {"rhsusf_5Rnd_00Buck","rhsusf_5rnd_doomsday_buck","rhsusf_5Rnd_Slug","rhsusf_5Rnd_HE","rhsusf_5Rnd_FRAG","rhsusf_5Rnd_dragon_breath","rhsusf_5Rnd_shrapnel"};
	};
	class rhs_weap_M590_8RD: rhs_weap_M590_5RD {
		magazines[] = {"rhsusf_8Rnd_00Buck","rhsusf_8rnd_doomsday_buck","rhsusf_8Rnd_Slug","rhsusf_8Rnd_HE","rhsusf_8Rnd_FRAG","rhsusf_8Rnd_dragon_breath","rhsusf_8Rnd_shrapnel"};
	};
	class rhs_weap_vhs2_base: Rifle_Base_F {
		ACE_barrelLength = 500;
		ACE_barrelTwist = 177.8;
		ACE_clearJamAction = "GestureReloadMX";
		ace_overheating_dispersion = 1;
		ace_overheating_mrbs = 3000;
		ace_overheating_slowdownFactor = 1;
		ACE_RailHeightAboveBore = 3.56139;
		magazineWell[] = {"CBA_556x45_G36","STANAG_556x45"};
	};
	class rhs_weap_vhsd2;
	class rhs_weap_vhsk2: rhs_weap_vhsd2 {
		ACE_barrelLength = 410;
	};
};