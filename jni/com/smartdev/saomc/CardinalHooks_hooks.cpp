#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "Headers.h"

//Settings 
std::string MOD_VERSION = "1.0.0 Alpha";
bool DEV_MODE = true;
bool BEATER_MODE = false;
std::string BUILD_VERSION = "1";
//End settings 

static std::string (*_Common$getGameDevVersionString)();
static std::string Common$getGameDevVersionString() {
	if(DEV_MODE) {
		return "§a§lSA: M " + MOD_VERSION + "\n§r§fDevelopment Build " + BUILD_VERSION;
	} else if(BEATER_MODE){
		return "§a§lSA: M " + MOD_VERSION +"\n§r§fBeater Build " + BUILD_VERSION;
	} else {
		return "§a§lSA: M " + MOD_VERSION;
   }
}

static void (*_Item$initItems)();
static void Item$initItems() {
	_Item$initItems();
	
	CardinalItems::initItems();
	//CardinalBlocks::initCreativeBlocks();
}

static void (*_Block$initBlocks)();
static void Block$initBlocks() {
	_Block$initBlocks();
	
	CardinalBlocks::initBlocks();
}

static void (*_Recipes$init)(Recipes*);
static void Recipes$init(Recipes* self) {	
	_Recipes$init(self);	
	
	CardinalRecipes::initRecipes(self);
}

static FurnaceRecipes* (*_FurnaceRecipes$FurnaceRecipes)(FurnaceRecipes*);
static FurnaceRecipes* FurnaceRecipes$FurnaceRecipes(FurnaceRecipes* self) {
	_FurnaceRecipes$FurnaceRecipes(self);
	CardinalRecipes::initFurnaceRecipes(self);
}

void (*_MinecraftClient$onPlayerLoaded)(MinecraftClient*, Player&);
void MinecraftClient$onPlayerLoaded(MinecraftClient *client, Player &player){
	_MinecraftClient$onPlayerLoaded(client, player);

	client->sendLocalMessage("SA: M", "Welcome to Sword Art: Minecraft!");
	client->sendLocalMessage("SA: M", "Enjoy with the new SAO features in Minecraft: Pocket Edition");
	client->playUI("saomc.player.welcome", 1.0F, 1.0F);
}

static void (*_Mob$die)( Mob*, EntityDamageSource const&);
static void Mob$die(Mob* dead, EntityDamageSource const& damage) {
	static MinecraftClient* mcinstance;
    static LocalPlayer* player;
		dead->playSound("saomc.entity.death", 1.0F, 1.0F);
			if(dead == (Mob*)player){
			    mcinstance->playUI("saomc.player.death", 1.0F, 1.0F);
			}
	_Mob$die(dead, damage);
}

static void (*_Localization$_load)(Localization*, const std::string&);
static void Localization$_load(Localization* self, const std::string& langCode) {
	_Localization$_load(self, langCode);
	if(langCode == "en_US" || langCode == "es_ES")
		self->_appendTranslations("loc/cardinal/" + langCode + "-pocket.lang");
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	
    MSHookFunction((void*) &Common::getGameDevVersionString, (void*) &Common$getGameDevVersionString, (void**) &_Common$getGameDevVersionString);
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	MSHookFunction((void*) &Recipes::init, (void*) &Recipes$init, (void**) &_Recipes$init);
	MSHookFunction((void*) &MinecraftClient::onPlayerLoaded, (void*) &MinecraftClient$onPlayerLoaded, (void**) &_MinecraftClient$onPlayerLoaded);
   	MSHookFunction((void*) &Mob::die, (void*) &Mob$die, (void**) &_Mob$die);
	MSHookFunction((void*) &Localization::_load, (void*) &Localization$_load, (void**) &_Localization$_load);
	
	return JNI_VERSION_1_2;
}
