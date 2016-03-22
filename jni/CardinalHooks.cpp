#include <Headers.h>

std::string MOD_VERSION = "1.0.0 Alpha";
bool DEV_MODE = true;
bool BEATER_MODE = false;
std::string BUILD_VERSION = "2";

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

void (*_Block$initBlocks)();
void Block$initBlocks() {
	_Block$initBlocks();
	
	CardinalBlocks::initBlocks();
}

void (*_Recipes$init)(Recipes*);
void Recipes$init(Recipes* self) {	
	_Recipes$init(self);	
	
	CardinalRecipes::initRecipes(self);
}

static FurnaceRecipes* (*_FurnaceRecipes$FurnaceRecipes)(FurnaceRecipes*);
static FurnaceRecipes* FurnaceRecipes$FurnaceRecipes(FurnaceRecipes* self) 
{
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

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {

	MSHookFunction((void*) &Common::getGameDevVersionString, (void*) &Common$getGameDevVersionString, (void**) &_Common$getGameDevVersionString);

	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);

	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);

	MSHookFunction((void*) &Recipes::init, (void*) &Recipes$init, (void**) &_Recipes$init);

	 void* furnaceRecipes = dlsym(RTLD_DEFAULT, "_ZN14FurnaceRecipesC1Ev");
	MSHookFunction(furnaceRecipes, (void*) &FurnaceRecipes$FurnaceRecipes, (void**) &_FurnaceRecipes$FurnaceRecipes);

	//MSHookFunction((void*) &I18n::get, (void*) &I18n$get, (void**) &_I18n$get);

	MSHookFunction((void*) &Mob::causeFallDamage, (void*) &Mob$causeFallDamage, (void**) &_Mob$causeFallDamage);

	MSHookFunction((void*) &Mob::die, (void*) &Mob$die, (void**) &_Mob$die);

	return JNI_VERSION_1_2;
}
