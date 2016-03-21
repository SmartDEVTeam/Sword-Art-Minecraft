#include "CardinalItems.h"
#include <string>

#include "swords/Elucidator.h"
#include "swords/DarkRepulser.h"
#include "swords/Kagemitsu.h"
#include "swords/LambentLight.h"

#include "valuables/crystallite/CrystalliteFragment.h"
#include "valuables/crystallite/CrystalliteStick.h"

#include "valuables/elucidador/ElucidadorFragment.h"
#include "valuables/elucidador/ElucidadorStick.h"

#include "com/mojang/minecraftpe/world/item/Item.h"
#include "../blocks/CardinalBlocks.h"

Item* CardinalItems::elucidator;
Item* CardinalItems::darkRepulser;
Item* CardinalItems::kagemitsu;
Item* CardinalItems::lambentLight;
Item* CardinalItems::crystalliteFragment;
Item* CardinalItems::crystalliteStick;
Item* CardinalItems::elucidadorFragment;
Item* CardinalItems::elucidadorStick;

void CardinalItems::initItems() {
	
	//Swords
	elucidator = new Elucidator("elucidator", 1000);
	darkRepulser = new DarkRepulser("darkRepulser", 1001);
	kagemitsu = new Kagemitsu("kagemitsu", 1002);
	lambentLight = new LambentLight("lambentLight", 1003);

	//Valuables
	crystalliteFragment = new CrystalliteFragment("crystalliteFragment", 900);
	crystalliteStick = new CrystalliteStick("crystalliteStick", 901);

	elucidadorFragment = new ElucidadorFragment("elucidadorFragment", 902);
	elucidadorStick = new ElucidadorStick("elucidadorStick", 903);

	initCreativeItems();
}

void CardinalItems::initCreativeItems() {
	//Swords
	Item::addCreativeItem(elucidator, 0);
	Item::addCreativeItem(darkRepulser, 0);
	Item::addCreativeItem(kagemitsu, 0);
	Item::addCreativeItem(lambentLight, 0);
 
	//Valuables 
	Item::addCreativeItem(crystalliteFragment, 0);
	Item::addCreativeItem(crystalliteStick, 0);
	Item::addCreativeItem(elucidadorFragment, 0);
	Item::addCreativeItem(elucidadorStick, 0); 
}