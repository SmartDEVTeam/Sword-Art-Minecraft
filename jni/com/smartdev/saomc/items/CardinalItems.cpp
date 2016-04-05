#include "CardinalItems.h"
#include <string>

#include "swords/Elucidator.h"
#include "swords/DarkRepulser.h"
#include "swords/Kagemitsu.h"
#include "swords/LambentLight.h"

#include "valuables/CardinalFragment.h"
#include "valuables/CardinalStick.h"

#include "armor/CardinalArmor.h"

#include "com/mojang/minecraftpe/world/item/Item.h"

Item* CardinalItems::elucidator;
Item* CardinalItems::darkRepulser;
Item* CardinalItems::kagemitsu;
Item* CardinalItems::lambentLight;
Item* CardinalItems::fragment;
Item* CardinalItems::stick;
Item* CardinalItems::boots;
Item* CardinalItems::pants;
Item* CardinalItems::chestPlate;
Item* CardinalItems::helmet;

void CardinalItems::initItems() {
	
	//Swords
	elucidator = new Elucidator("elucidator", 1000);
	darkRepulser = new DarkRepulser("darkRepulser", 1001);
	kagemitsu = new Kagemitsu("kagemitsu", 1002);
	lambentLight = new LambentLight("lambentLight", 1003);

	//Valuables
	fragment = new CardinalFragment(900);
	stick = new CardinalStick(901);
	
	boots = new CardinalArmor("cardinalBoots", 1100, ArmorSlot::BOOTS, 4);
	pants = new CardinalArmor("cardinalPants", 1101, ArmorSlot::LEGGINGS, 4);
	chestPlate = new CardinalArmor("cardinalChestPlate", 1102, ArmorSlot::CHESTPLATE, 4);
	helmet = new CardinalArmor("cardinalHelmet", 1103, ArmorSlot::HELMET, 4);

	initCreativeItems();
}

void CardinalItems::initCreativeItems() {
	//Swords
	Item::addCreativeItem(elucidator, 0);
	Item::addCreativeItem(darkRepulser, 0);
	Item::addCreativeItem(kagemitsu, 0);
	Item::addCreativeItem(lambentLight, 0);
 
	//Valuables 
	Item::addCreativeItem(fragment, 0);
	Item::addCreativeItem(stick, 0);
	Item::addCreativeItem(fragment, 1);
	Item::addCreativeItem(stick, 1); 
	
	//Armor
	Item::addCreativeItem(boots, 0);
	Item::addCreativeItem(pants, 0);
	Item::addCreativeItem(chestPlate, 0);
	Item::addCreativeItem(helmet, 0);
}

std::string CardinalItems::getItemTypeByData(int data) {
	switch(data) {
		case 0:
			return "crystallite";
		case 1:
			return "elucidador";
	}
}