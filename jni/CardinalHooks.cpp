#include <Headers.h>

std::string MOD_VERSION = "1.0.0 Alpha";
bool DEV_MODE = true;
bool BEATER_MODE = false;
std::string BUILD_VERSION = "1";

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
	
	CardinalItems::initItems();
	CardinalBlocks::initCreativeBlocks();
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

static void (*_Mob$causeFallDamage)(Mob*, float);
static void Mob$causeFallDamage(Mob* self, float blocksFallen) {
	return;
}

static void (*_Mob$die)( Mob*, EntityDamageSource const&);
static void Mob$die(Mob* dead, EntityDamageSource const& damage) {
	_Mob$die(dead, damage);
	
	dead->playSound("saomc.entity.death", 1.0F, 1.0F);//sao.mob.death
}

static BiomeDecorator* (*_BiomeDecorator$BiomeDecorator)(BiomeDecorator*);
static BiomeDecorator* BiomeDecorator$BiomeDecorator(BiomeDecorator* self) {
	BiomeDecorator* retval = _BiomeDecorator$BiomeDecorator(self);
	
	CardinalDecorator::registerFeatures();
	
	return retval;
}

static void (*_BiomeDecorator$decorateOres)(BiomeDecorator*, BlockSource*, Random&, const BlockPos&);
static void BiomeDecorator$decorateOres(BiomeDecorator* decorator, BlockSource* region, Random& random, const BlockPos& blockPos) {
	_BiomeDecorator$decorateOres(decorator, region, random, blockPos);
	
	CardinalDecorator::decorateOres(decorator, region, random, blockPos);
}

static void (*_BiomeDecorator$decorate)(BiomeDecorator*, BlockSource*, Random&, Biome*, const BlockPos&, bool, float);
static void BiomeDecorator$decorate(BiomeDecorator* decorator, BlockSource* region, Random& random, Biome* biome, const BlockPos& pos, bool b1, float f1) {
	_BiomeDecorator$decorate(decorator, region, random, biome, pos, b1, f1);
	
	CardinalDecorator::decorate(decorator, region, random, biome, pos, b1, f1);
}

static void (*_Localization$_load)(Localization*, const std::string&);
static void Localization$_load(Localization* self, const std::string& langCode) {
	_Localization$_load(self, langCode);
	if(langCode == "en_US" || langCode == "es_ES")
		self->_appendTranslations("loc/cardinal/" + langCode + "-pocket.lang");
}

void (*_Gui$renderHearts)(Gui*);
void Gui$renderHearts(Gui* self) {
}

static void (*_InventoryScreen$init)(DeathScreen*);
static void InventoryScreen$init(DeathScreen* self)
{
	/*if(self->mcClient->getLocalPlayer()->IsCreative() && self->craftingType != CraftingType::FULLCRAFTING)*/
		 CardinalDeathScreen::init(self);

	_InventoryScreen$init(self);
}

static void (*_InventoryScreen$setupPositions)(DeathScreen*);
static void InventoryScreen$setupPositions(DeathScreen* self)
{
	_InventoryScreen$setupPositions(self);
	
	/*if(self->mcClient->getLocalPlayer()->IsCreative() && self->craftingType != CraftingType::FULLCRAFTING)*/
		 CardinalDeathScreen::setupPositions(self);
}

static void (*_InventoryScreen$render)(DeathScreen*, int, int, float);
static void InventoryScreen$render(DeathScreen* self, int i1, int i2, float f1)
{
	_InventoryScreen$render(self, i1, i2, f1);
	
/*	if(self->mcClient->getLocalPlayer()->IsCreative() && self->craftingType != CraftingType::FULLCRAFTING)*/
		 CardinalDeathScreen::render(self, i1, i2, f1);
}

static void (*_InventoryScreen$_buttonClicked)(DeathScreen*, Button&);
static void InventoryScreen$_buttonClicked(DeathScreen* self, Button& button)
{
	_InventoryScreen$_buttonClicked(self, button);
	
	/*if(self->mcClient->getLocalPlayer()->IsCreative() && self->craftingType != CraftingType::FULLCRAFTING)*/
		 //CardinalDeathScreen::_buttonClicked(self, button);
}

static std::string (*_I18n$get)(const std::string&);
static std::string I18n$get(const std::string& key) {	
if(key == "deathScreen.title") return "";
return _I18n$get(key);
};

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {

	MSHookFunction((void*) &Common::getGameDevVersionString, (void*) &Common$getGameDevVersionString, (void**) &_Common$getGameDevVersionString);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	MSHookFunction((void*) &Recipes::init, (void*) &Recipes$init, (void**) &_Recipes$init);
	MSHookFunction((void*) &Mob::causeFallDamage, (void*) &Mob$causeFallDamage, (void**) &_Mob$causeFallDamage);
	MSHookFunction((void*) &Mob::die, (void*) &Mob$die, (void**) &_Mob$die);
	MSHookFunction((void*) &BiomeDecorator::decorateOres, (void*) &BiomeDecorator$decorateOres, (void**) &_BiomeDecorator$decorateOres);
	MSHookFunction((void*) &BiomeDecorator::decorate, (void*) &BiomeDecorator$decorate, (void**) &_BiomeDecorator$decorate);
	MSHookFunction((void*) &Localization::_load, (void*) &Localization$_load, (void**) &_Localization$_load);

	void* furnaceRecipes = dlsym(RTLD_DEFAULT, "_ZN14FurnaceRecipesC1Ev");
	MSHookFunction(furnaceRecipes, (void*) &FurnaceRecipes$FurnaceRecipes, (void**) &_FurnaceRecipes$FurnaceRecipes);
	
	void* biomeDecorator = dlsym(RTLD_DEFAULT, "_ZN14BiomeDecoratorC2Ev");
	MSHookFunction(biomeDecorator, (void*) &BiomeDecorator$BiomeDecorator, (void**) &_BiomeDecorator$BiomeDecorator);

MSHookFunction((void*) &Gui::renderHearts, (void*) &Gui$renderHearts, (void**) &_Gui$renderHearts);

MSHookFunction((void*) &DeathScreen::init, (void*) &InventoryScreen$init, (void**) &_InventoryScreen$init);
	MSHookFunction((void*) &DeathScreen::setupPositions, (void*) &InventoryScreen$setupPositions, (void**) &_InventoryScreen$setupPositions);
	MSHookFunction((void*) &DeathScreen::render, (void*) &InventoryScreen$render, (void**) &_InventoryScreen$render);
	MSHookFunction((void*) &DeathScreen::_buttonClicked, (void*) &InventoryScreen$_buttonClicked, (void**) &_InventoryScreen$_buttonClicked);

   void* I18n_get = dlsym(RTLD_DEFAULT, "_ZN4I18n3getE");	

MSHookFunction(I18n_get, (void*) &I18n$get, (void**) &_I18n$get);	

	return JNI_VERSION_1_2;
}
