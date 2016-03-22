#include "CardinalItems.h"
#include <string>

#include "swords/Elucidator.h"
#include "swords/DarkRepulser.h"
#include "swords/Kagemitsu.h"
#include "swords/LambentLight.h"

#include "valuables/CardinalFragment.h"
#include "valuables/CardinalStick.h"

#include "com/mojang/minecraftpe/world/item/Item.h"

Item* CardinalItems::elucidator;
Item* CardinalItems::darkRepulser;
Item* CardinalItems::kagemitsu;
Item* CardinalItems::lambentLight;
Item* CardinalItems::cardinalFragment;
Item* CardinalItems::cardinalStick;

void CardinalItems::initItems() {
	
	//Swords
	elucidator = new Elucidator("elucidator", 1000);
	darkRepulser = new DarkRepulser("darkRepulser", 1001);
	kagemitsu = new Kagemitsu("kagemitsu", 1002);
	lambentLight = new LambentLight("lambentLight", 1003);

	//Valuables
	cardinalFragment = new CrystalliteFragment(900);
	cardinalStick = new CrystalliteStick(901);

	initCreativeItems();
}

void CardinalItems::initCreativeItems() {
	//Swords
	Item::addCreativeItem(elucidator, 0);
	Item::addCreativeItem(darkRepulser, 0);
	Item::addCreativeItem(kagemitsu, 0);
	Item::addCreativeItem(lambentLight, 0);
 
	//Valuables 
	Item::addCreativeItem(cardinalFragment, 0);
	Item::addCreativeItem(cardinalStick, 0);
	Item::addCreativeItem(cardinalFragment, 1);
	Item::addCreativeItem(cardinalStick, 1); 
}

std::string CardinalItems::getItemTypeByData(int data) {
	switch(data) {
		case 0:
			return "crystallite";
		case 1:
			return "elucidator";
	}
}