params [["_firstRun", false]];

tf_same_sw_frequencies_for_side = true;
tf_same_lr_frequencies_for_side = true;
tf_freq_west = [7,6,["36.1","36.2","36.3","36.4","36.5","36.6","36","101","62"],0,"_bluefor",-1,0,getplayerUid player,false];
tf_freq_west_lr = [0,7,["36","36.1","36.2","36.3","36.4","36.5","36.6","62","61","60"],0,"_bluefor",-1,0,nil,false,true];
group player setVariable ["tf_sw_frequency", tf_freq_west]; 
group player setVariable ["tf_lr_frequency", tf_freq_west_lr];

private _radioIcon = "\A3\weapons_f\Data\UI\gear_item_radio_ca.paa";

if (!_firstRun) then {
	["无线电设定已重置", _radioIcon] call ace_common_fnc_displayTextPicture;
	playSound "ACE_Sound_Click";
	[(call TFAR_fnc_activeSwRadio), tf_freq_west] call TFAR_fnc_setSwSettings;
	call TFAR_fnc_activeLrRadio select 0 setVariable ["radio_settings", tf_freq_west_lr, true];
};

if (_firstRun) then {
	private _resetAction = ["ResetRadio", "重置无线电", _radioIcon, {false call PMF_fnc_resetRadio}, {true}] call ace_interact_menu_fnc_createAction;
	["CAManBase", 1, ["ACE_SelfActions", "ACE_Equipment"], _resetAction, true] call ace_interact_menu_fnc_addActionToClass;
	 
	player addEventHandler ["Respawn", {
		params ["_unit", "_old"];
		["NewRadioEvent", "OnRadiosReceived", _old] call TFAR_fnc_removeEventHandler;
		["NewRadioEvent", "OnRadiosReceived", {  
			false call PMF_fnc_resetRadio; 
			systemChat "检测到新电台，初始化为GTRC标准频道"; 
			//player setVariable ["TFAR_event_OnBeforeTangent",[]]; 
			//["NewRadioEvent", "OnRadioOwnerSet", player] call TFAR_fnc_removeEventHandler;
		}, _unit] call TFAR_fnc_addEventHandler;
	}];
};