class CfgPatches {
	class gtrc_pmf {
		requiredAddons[] = {"cba_events"};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] = {};
	};
};

class CfgDebriefing {  
	class SlotWL {
		title = "角色未经授权";
		subtitle = "此角色仅限通过相关考核的战队成员使用";
		description = "";
	};
};

#include "CfgFunctions.hpp"
#include "CfgUnitInsignia.hpp"
#include "ACE_ZeusActions.hpp"