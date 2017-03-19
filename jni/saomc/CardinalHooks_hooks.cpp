#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include "Substrate.h"

//#include "minecraftpe/client/MinecraftClient.h"
#include "minecraftpe/world/item/Item.h"
#include "minecraftpe/world/level/block/Block.h"
#include "minecraftpe/client/locale/Localization.h"
#include "minecraftpe/world/level/block/BlockGraphics.h"

#include "items/CardinalItems.h"
#include "blocks/CardinalBlocks.h"
#include "recipes/CardinalRecipes.h"

void (*_Item$initClientData)();
void Item$initClientData()
{
	_Item$initClientData();
	
	CardinalItems::initItems();
	CardinalBlocks::initBlockItems();
}

void (*_Block$initBlocks)();
void Block$initBlocks()
{
	_Block$initBlocks();
	
	CardinalBlocks::initBlocks();
}

void (*_Item$initCreativeItems)();
void Item$initCreativeItems()
{
	_Item$initCreativeItems();
	
	CardinalItems::initCreativeItems();
	CardinalBlocks::initCreativeBlocks();
}

void (*_BlockGraphics$initBlocks)();
void BlockGraphics$initBlocks()
{
	_BlockGraphics$initBlocks();
	
	CardinalBlocks::initBlockGraphics();
}

void (*_Recipes$init)(Recipes*);
void Recipes$init(Recipes *self)
{	
	_Recipes$init(self);	
	
	CardinalRecipes::initRecipes(self);
}

FurnaceRecipes* (*_FurnaceRecipes$FurnaceRecipes)(FurnaceRecipes*);
FurnaceRecipes* FurnaceRecipes$FurnaceRecipes(FurnaceRecipes *self)
{
	_FurnaceRecipes$FurnaceRecipes(self);
	
	CardinalRecipes::initFurnaceRecipes(self);
}

//Remove this until we uodate MinecraftClient and we figure out a new way to play sounds trough entities
/*void (*_MinecraftClient$onPlayerLoaded)(MinecraftClient*, Player&);
void MinecraftClient$onPlayerLoaded(MinecraftClient *client, Player &player){
	_MinecraftClient$onPlayerLoaded(client, player);

	client->sendLocalMessage("SA: M", "Welcome to Sword Art: Minecraft!");
	client->sendLocalMessage("SA: M", "Enjoy with the new SAO features in Minecraft: Pocket Edition");
	client->playUI("saomc.player.welcome", 1.0F, 1.0F);
}*/

/*static void (*_Mob$die)( Mob*, EntityDamageSource const&);
static void Mob$die(Mob* dead, EntityDamageSource const& damage) {
	static MinecraftClient* mcinstance;
    static LocalPlayer* player;
		dead->playSound("saomc.entity.death", 1.0F, 1.0F);
			if(dead == (Mob*)player){
			    mcinstance->playUI("saomc.player.death", 1.0F, 1.0F);
			}
	_Mob$die(dead, damage);
}*/

void (*_Localization$_load)(Localization*, const std::string&);
void Localization$_load(Localization* self, const std::string& langCode)
{
	_Localization$_load(self, langCode);
	
	if(langCode == "en_US" || langCode == "es_ES")
		_Localization$_load(self, "cardinal/" + langCode);
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
	MSHookFunction((void*) &Item::initClientData, (void*) &Item$initClientData, (void**) &_Item$initClientData);
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &BlockGraphics::initBlocks, (void*) &BlockGraphics$initBlocks, (void**) &_BlockGraphics$initBlocks);
	//MSHookFunction((void*) &Recipes::init, (void*) &Recipes$init, (void**) &_Recipes$init);
	//MSHookFunction((void*) &MinecraftClient::onPlayerLoaded, (void*) &MinecraftClient$onPlayerLoaded, (void**) &_MinecraftClient$onPlayerLoaded);
   	//MSHookFunction((void*) &Mob::die, (void*) &Mob$die, (void**) &_Mob$die);
	///MSHookFunction((void*) &Localization::_load, (void*) &Localization$_load, (void**) &_Localization$_load);
	
	return JNI_VERSION_1_6;
}

