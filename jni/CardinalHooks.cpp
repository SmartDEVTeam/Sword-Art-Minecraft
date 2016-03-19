#include <Headers.h>

std::string MOD_VERSION = "1.0.0 Alpha";
bool DEV_MODE = true;

static std::string (*_Common$getGameDevVersionString)();
static std::string Common$getGameDevVersionString() {
	if(DEV_MODE) {
		return "DEV Version §a§l" + MOD_VERSION;
	} else {
      return "§a§lSA: M " + MOD_VERSION;
   }
}

static void (*_Item$initCreativeItems)();
static void Item$initCreativeItems() {
	_Item$initCreativeItems();
	
	CardinalItems::initItems();
}

void (*_Recipes$init)(Recipes*);void Recipes$init(Recipes* self) {	_Recipes$init(self);		 CardinalItemRecipes::initRecipes(self);
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
    MSHookFunction((void*) &Recipes::init, (void*) &Recipes$init, (void**) &_Recipes$init);
    //MSHookFunction((void*) &I18n::get, (void*) &I18n$get, (void**) &_I18n$get);
	MSHookFunction((void*) &Mob::causeFallDamage, (void*) &Mob$causeFallDamage, (void**) &_Mob$causeFallDamage);
    MSHookFunction((void*) &Mob::die, (void*) &Mob$die, (void**) &_Mob$die);

	return JNI_VERSION_1_2;
}
