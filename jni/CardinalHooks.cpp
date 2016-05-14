#include <Headers.h>

std::string MOD_VERSION = "1.0.0 Alpha";
bool DEV_MODE = true;
bool BEATER_MODE = false;
std::string BUILD_VERSION = "1";

//static MinecraftClient* mcinstance;
//static LocalPlayer* localplayer;

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

static void (*_Item$initCreativeItems)();
static void Item$initCreativeItems() {
	_Item$initCreativeItems();
	
	//CardinalItems::initItems();
	//CardinalBlocks::initCreativeBlocks();
}

static void (*_Block$initBlocks)();
static void Block$initBlocks() {
	_Block$initBlocks();
	
	//CardinalBlocks::initBlocks();
}

static void (*_Recipes$init)(Recipes*);
static void Recipes$init(Recipes *self) {	
	_Recipes$init(self);	
	
	//CardinalRecipes::initRecipes(self);
}

static FurnaceRecipes* (*_FurnaceRecipes$FurnaceRecipes)(FurnaceRecipes*);
static FurnaceRecipes* FurnaceRecipes$FurnaceRecipes(FurnaceRecipes *self) {
	_FurnaceRecipes$FurnaceRecipes(self);
	
	//CardinalRecipes::initFurnaceRecipes(self);
}

void (*_MinecraftClient$onPlayerLoaded)(MinecraftClient*, Player&);
void MinecraftClient$onPlayerLoaded(MinecraftClient *client, Player &player){
	_MinecraftClient$onPlayerLoaded(client, player);
	
	client->sendLocalMessage("SA: M", "Welcome to Sword Art: Minecraft!");
	client->sendLocalMessage("SA: M", "Enjoy with the new SAO features in Minecraft: Pocket Edition");
	client->playUI("saomc.player.welcome", 1.0F, 1.0F);
	//Mob* playerPtr = (Mob*) client->getLocalPlayer();
	//playerPtr->playSound("saomc.player.welcome", 1.0F, 1.0F);
}

static void (*_Mob$causeFallDamage)(Mob*, float);
static void Mob$causeFallDamage(Mob *self, float blocksFallen) {
	return;
}

static void (*_Mob$die)(Mob*, const EntityDamageSource&);
static void Mob$die(Mob *self, const EntityDamageSource &damage) {
	MinecraftClient* mcinstance;
	self->playSound("saomc.entity.death", 1.0F, 1.0F);
	if(self == ((Mob*) mcinstance->getLocalPlayer())){
	    mcinstance->playUI("saomc.player.death", 1.0F, 1.0F);
	}
	
	_Mob$die(self, damage);
}

static BiomeDecorator* (*_BiomeDecorator$BiomeDecorator)(BiomeDecorator*);
static BiomeDecorator* BiomeDecorator$BiomeDecorator(BiomeDecorator* self) {
	BiomeDecorator* retval = _BiomeDecorator$BiomeDecorator(self);
	
	//CardinalDecorator::registerFeatures();
	
	return retval;
}

static void (*_BiomeDecorator$decorateOres)(BiomeDecorator*, BlockSource*, Random&, const BlockPos&);
static void BiomeDecorator$decorateOres(BiomeDecorator* decorator, BlockSource* region, Random& random, const BlockPos& blockPos) {
	_BiomeDecorator$decorateOres(decorator, region, random, blockPos);
	
	//CardinalDecorator::decorateOres(decorator, region, random, blockPos);
}

static void (*_BiomeDecorator$decorate)(BiomeDecorator*, BlockSource*, Random&, Biome*, const BlockPos&, bool, float);
static void BiomeDecorator$decorate(BiomeDecorator* decorator, BlockSource* region, Random& random, Biome* biome, const BlockPos& pos, bool b1, float f1) {
	_BiomeDecorator$decorate(decorator, region, random, biome, pos, b1, f1);
	
	//CardinalDecorator::decorate(decorator, region, random, biome, pos, b1, f1);
}

static void (*_Localization$_load)(Localization*, const std::string&);
static void Localization$_load(Localization* self, const std::string& langCode) {
	_Localization$_load(self, langCode);
	if(langCode == "en_US" || langCode == "es_ES")
		self->_appendTranslations("loc/cardinal/" + langCode + "-pocket.lang");
}

static void (*_DeathScreen$init)(DeathScreen*);
static void DeathScreen$init(DeathScreen* self)
{
	/*if(self->mcClient->getLocalPlayer()->IsCreative() && self->craftingType != CraftingType::FULLCRAFTING)*/
		 CardinalDeathScreen::init(self);
}

static void (*_DeathScreen$setupPositions)(DeathScreen*);
static void DeathScreen$setupPositions(DeathScreen* self)
{
	/*if(self->mcClient->getLocalPlayer()->IsCreative() && self->craftingType != CraftingType::FULLCRAFTING)*/
		 CardinalDeathScreen::setupPositions(self);
}

static void (*_DeathScreen$render)(DeathScreen*, int, int, float);
static void DeathScreen$render(DeathScreen* self, int i1, int i2, float f1)
{
	/*if(self->mcClient->getLocalPlayer()->IsCreative() && self->craftingType != CraftingType::FULLCRAFTING)*/
		 CardinalDeathScreen::render(self, i1, i2, f1);
}

static void (*_DeathScreen$_buttonClicked)(DeathScreen*, Button&);
static void DeathScreen$_buttonClicked(DeathScreen* self, Button& button)
{
	/*if(self->mcClient->getLocalPlayer()->IsCreative() && self->craftingType != CraftingType::FULLCRAFTING)*/
		 CardinalDeathScreen::_buttonClicked(self, button);
}

static std::string (*_I18n$get)(const std::string&, const std::vector<std::string,std::allocator<std::string>>&);
static std::string I18n$get(const std::string &key, const std::vector<std::string,std::allocator<std::string>> &a) {
	if(key == "deathScreen.title") return "";
	if(key == "deathScreen.message") return "";
	
	return _I18n$get(key, a);
};

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &Common::getGameDevVersionString, (void*) &Common$getGameDevVersionString, (void**) &_Common$getGameDevVersionString);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	MSHookFunction((void*) &Recipes::init, (void*) &Recipes$init, (void**) &_Recipes$init);
	MSHookFunction((void*) &MinecraftClient::onPlayerLoaded, (void*) &MinecraftClient$onPlayerLoaded, (void**) &_MinecraftClient$onPlayerLoaded);
	MSHookFunction((void*) &Mob::causeFallDamage, (void*) &Mob$causeFallDamage, (void**) &_Mob$causeFallDamage);
	MSHookFunction((void*) &Mob::die, (void*) &Mob$die, (void**) &_Mob$die);
	MSHookFunction((void*) &BiomeDecorator::decorateOres, (void*) &BiomeDecorator$decorateOres, (void**) &_BiomeDecorator$decorateOres);
	MSHookFunction((void*) &BiomeDecorator::decorate, (void*) &BiomeDecorator$decorate, (void**) &_BiomeDecorator$decorate);
	MSHookFunction((void*) &Localization::_load, (void*) &Localization$_load, (void**) &_Localization$_load);
    
	void* furnaceRecipes = dlsym(RTLD_DEFAULT, "_ZN14FurnaceRecipesC1Ev");
	MSHookFunction(furnaceRecipes, (void*) &FurnaceRecipes$FurnaceRecipes, (void**) &_FurnaceRecipes$FurnaceRecipes);
	
	void* biomeDecorator = dlsym(RTLD_DEFAULT, "_ZN14BiomeDecoratorC2Ev");
	MSHookFunction(biomeDecorator, (void*) &BiomeDecorator$BiomeDecorator, (void**) &_BiomeDecorator$BiomeDecorator);

	MSHookFunction((void*) &DeathScreen::init, (void*) &DeathScreen$init, (void**) &_DeathScreen$init);
	MSHookFunction((void*) &DeathScreen::setupPositions, (void*) &DeathScreen$setupPositions, (void**) &_DeathScreen$setupPositions);
	MSHookFunction((void*) &DeathScreen::render, (void*) &DeathScreen$render, (void**) &_DeathScreen$render);
	MSHookFunction((void*) &DeathScreen::_buttonClicked, (void*) &DeathScreen$_buttonClicked, (void**) &_DeathScreen$_buttonClicked);
	MSHookFunction((void*) &I18n::get, (void*) &I18n$get, (void**) &_I18n$get);
	
	return JNI_VERSION_1_2;
}
