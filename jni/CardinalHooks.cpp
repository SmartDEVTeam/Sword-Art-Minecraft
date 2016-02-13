#include <Headers.h>

std::string MOD_VERSION = "1.0.0 Alpha";
bool DEV_MODE = true;

static std::string (*Common_getGameDevVersionString_real)();
static std::string Common_getGameDevVersionString_hook() {
if(DEV_MODE) {
	return "DEV Version";
}
}

static std::string (*Common_getGameVersionString_real)();
static std::string Common_getGameVersionString_hook() {
	return "§a§lSA: M " + MOD_VERSION;
}

static std::string (*AppPlatform_getEdition_real)();
static std::string AppPlatform_getEdition_hook() {
	return "edu";
}

static int (*AppPlatform_android_getScreenType_real)();
static int AppPlatform_android_getScreenType_hook() {
	return 0;
}

void (*_Item$initItems)();
void Item$initItems(){ 
CardinalItems::initItems();
_Item$initItems();
}

void (*_Item$initCreativeItems)();
void Item$initCreativeItems()
{
	_Item$initCreativeItems();
CardinalItems::initCreativeItems();
}


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
MSHookFunction((void*) &Common::getGameDevVersionString, (void*) &Common_getGameDevVersionString_hook, (void**) &Common_getGameDevVersionString_real);
MSHookFunction((void*) &Common::getGameVersionString, (void*) &Common_getGameVersionString_hook, (void**) &Common_getGameVersionString_real);
MSHookFunction((void*) &AppPlatform::getEdition, (void*) &AppPlatform_getEdition_hook, (void**) &AppPlatform_getEdition_real);
MSHookFunction((void*) &AppPlatform_android::getScreenType, (void*) &AppPlatform_android_getScreenType_hook, (void**) &AppPlatform_android_getScreenType_real);
MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);

	return JNI_VERSION_1_2;
}
