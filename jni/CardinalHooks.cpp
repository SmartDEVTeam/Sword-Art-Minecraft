#include <Headers.h>

std::string MOD_VERSION = "1.0.0 Alpha";
bool DEV_MODE = true;

static std::string (*_Common$getGameDevVersionString)();
static std::string Common$getGameDevVersionString() {
	if(DEV_MODE) {
		return "DEV Version";
	}
}

static std::string (*_Common$getGameVersionString)();
static std::string Common$getGameVersionString() {
	return "§a§lSA: M " + MOD_VERSION;
}

static std::string (*_AppPlatform$getEdition)();
static std::string AppPlatform$getEdition() {
	return "edu";
}

static int (*_AppPlatform_android$getScreenType)();
static int AppPlatform_android$getScreenType() {
	return 1;
}

static void (*_Item$initCreativeItems)();
static void Item$initCreativeItems() {
	_Item$initCreativeItems();
	
	CardinalItems::initItems();
}

static void (*_Mob$causeFallDamage)(Mob*, float);
static void Mob$causeFallDamage(Mob* self, float blocksFallen) {
	return;
}


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &Common::getGameDevVersionString, (void*) &Common$getGameDevVersionString, (void**) &_Common$getGameDevVersionString);
	MSHookFunction((void*) &Common::getGameVersionString, (void*) &Common$getGameVersionString, (void**) &_Common$getGameVersionString);
	MSHookFunction((void*) &AppPlatform::getEdition, (void*) &AppPlatform$getEdition, (void**) &_AppPlatform$getEdition);
	MSHookFunction((void*) &AppPlatform_android::getScreenType, (void*) &AppPlatform_android$getScreenType, (void**) &_AppPlatform_android$getScreenType);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &Mob::causeFallDamage, (void*) &Mob$causeFallDamage, (void**) &_Mob$causeFallDamage);

	return JNI_VERSION_1_2;
}
