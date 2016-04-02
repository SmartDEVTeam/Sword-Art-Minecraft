#include <Headers.h>

std::string MOD_VERSION = "1.0.0 Alpha";
bool DEV_MODE = false;
bool BEATER_MODE = true;
std::string BUILD_VERSION = "1";

class GameStore;
class Textures;
class GeometryGroup;
class TextureGroup;

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

<<<<<<< HEAD
static BiomeDecorator* (*_BiomeDecorator$BiomeDecorator)(BiomeDecorator*);
static BiomeDecorator* BiomeDecorator$BiomeDecorator(BiomeDecorator* self) {
	BiomeDecorator* retval = _BiomeDecorator$BiomeDecorator(self);
	
	CardinalDecorator::registerOres();
	
	return retval;
=======
void (*skinRepoOrg)(SkinRepository*, Options&, GeometryGroup&, GameStore&, TextureGroup&, std::string const&, unsigned long long);
void skinRepoHook(SkinRepository* repo, Options& op, GeometryGroup& ge, GameStore& st, TextureGroup& tex, std::string const& text, unsigned long long HELP) {
    skinRepoOrg(repo, op, ge, st, tex, text, HELP);

	 Skin Kirito ("Kirito: Coat of Midnight", "Kirito: Coat of midnight", "geometry.humanoid.normal", "mob/skins/SAO/Kirito.png", Skin::SkinType::FREE);
    
    Skin Kirito2 ("Kirito: Knights of the Blood", "Kirito: Knights of the Blood", "geometry.humanoid.normal", "mob/skins/SAO/Kirito2.png", Skin::SkinType::FREE);
   
    Skin Kirito3 ("Kirito: Alternative", "Kirito: Alternative", "geometry.humanoid.normal", "mob/skins/SAO/Kirito3.png", Skin::SkinType::FREE);

    Skin Klein ("Klein", "Klein", "geometry.humanoid.normal", "mob/skins/SAO/Klein.png", Skin::SkinType::FREE);

    Skin Agil ("Agil the Merchant", "Agil the Merchant", "geometry.humanoid.normal", "mob/skins/SAO/Agil.png", Skin::SkinType::FREE);

   Skin Asuna ("Asuna the FlashLight", "Asuna the FlashLight", "geometry.humanoid.normal", "mob/skins/SAO/Asuna.png", Skin::SkinType::FREE);

   Skin Lizbeth ("Lizbeth the Blacksmith", "Lizbeth the Blacksmith", "geometry.humanoid.normal", "mob/skins/SAO/Lizbeth.png", Skin::SkinType::FREE);

    Skin Silica ("Silica the Dragon Tamer", "Silica the Dragon Tamer", "geometry.humanoid.normal", "mob/skins/SAO/Silica.png", Skin::SkinType::FREE);

    Skin Strea ("Strea-MHCP002", "Strea-MHCP002", "geometry.humanoid.normal", "mob/skins/SAO/Strea.png", Skin::SkinType::FREE);

    Skin Philia ("Philia the Treasure Hunter", "Philia the Treasure Hunter", "geometry.humanoid.normal", "mob/skins/SAO/Philia.png", Skin::SkinType::FREE);

	SkinPack* SAOSkinPack = new SkinPack(SkinPack::SkinPackType::PACK, "Sword Art Online: World of Aincrad", "SAO: WoA" , true, {Kirito, Kirito2, Kirito3, Klein, Agil, Asuna, Lizbeth, Silica, Strea, Philia});
    repo->skinPacks.push_back(SAOSkinPack);
    SAOSkinPack->unlocked = true;

>>>>>>> origin/master
}

static void (*_BiomeDecorator$decorateOres)(BiomeDecorator*, BlockSource*, Random&, const BlockPos&);
static void BiomeDecorator$decorateOres(BiomeDecorator* decorator, BlockSource* region, Random& random, const BlockPos& blockPos) {
	_BiomeDecorator$decorateOres(decorator, region, random, blockPos);
	
	CardinalDecorator::decorateOres(decorator, region, random, blockPos);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {

	MSHookFunction((void*) &Common::getGameDevVersionString, (void*) &Common$getGameDevVersionString, (void**) &_Common$getGameDevVersionString);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	MSHookFunction((void*) &Recipes::init, (void*) &Recipes$init, (void**) &_Recipes$init);
<<<<<<< HEAD
=======

	 void* furnaceRecipes = dlsym(RTLD_DEFAULT, "_ZN14FurnaceRecipesC1Ev");
    void* SkinRepository = dlsym(RTLD_DEFAULT, "_ZN14SkinRepositoryC2ER7OptionsR13GeometryGroupR9GameStoreR12TextureGroupRKSsy");

	MSHookFunction(furnaceRecipes, (void*) &FurnaceRecipes$FurnaceRecipes, (void**) &_FurnaceRecipes$FurnaceRecipes);

	//MSHookFunction((void*) &I18n::get, (void*) &I18n$get, (void**) &_I18n$get);

>>>>>>> origin/master
	MSHookFunction((void*) &Mob::causeFallDamage, (void*) &Mob$causeFallDamage, (void**) &_Mob$causeFallDamage);
	MSHookFunction((void*) &Mob::die, (void*) &Mob$die, (void**) &_Mob$die);
<<<<<<< HEAD
=======

   MSHookFunction(SkinRepository, (void *) &skinRepoHook, (void **) &skinRepoOrg);
	
>>>>>>> origin/master
	MSHookFunction((void*) &BiomeDecorator::decorateOres, (void*) &BiomeDecorator$decorateOres, (void**) &_BiomeDecorator$decorateOres);
	//MSHookFunction((void*) &I18n::get, (void*) &I18n$get, (void**) &_I18n$get);

	void* furnaceRecipes = dlsym(RTLD_DEFAULT, "_ZN14FurnaceRecipesC1Ev");
	MSHookFunction(furnaceRecipes, (void*) &FurnaceRecipes$FurnaceRecipes, (void**) &_FurnaceRecipes$FurnaceRecipes);

	void* biomeDecorator = dlsym(RTLD_DEFAULT, "_ZN14BiomeDecoratorC2Ev");
	MSHookFunction(biomeDecorator, (void*) &BiomeDecorator$BiomeDecorator, (void**) &_BiomeDecorator$BiomeDecorator);

	return JNI_VERSION_1_2;
}
