#include "CardinalItems.h"
#include <string>

#include "swords/Elucidator.h"
#include "swords/DarkRepulser.h"
#include "swords/Kagemitsu.h"
#include "swords/LambentLight.h"

#include "valuables/CardinalFragment.h"
#include "valuables/CardinalStick.h"

#include "CreativeTab.h"

#include "com/mojang/minecraftpe/world/item/Item.h"

Item* CardinalItems::elucidator;
Item* CardinalItems::darkRepulser;
Item* CardinalItems::kagemitsu;
Item* CardinalItems::lambentLight;
Item* CardinalItems::fragment;
Item* CardinalItems::stick;

void CardinalItems::initItems() {
	
	//Swords
	elucidator = new Elucidator("elucidator", 1000);
	darkRepulser = new DarkRepulser("darkRepulser", 1001);
	kagemitsu = new Kagemitsu("kagemitsu", 1002);
	lambentLight = new LambentLight("lambentLight", 1003);

	//Valuables
	fragment = new CardinalFragment(900);
	stick = new CardinalStick(901);
	
    initTabs();

}

void CardinalItems::initTabs() {

    CreativeTab* swordTab = new CreativeTab(elucidator, 0);
	//Swords
	swordTab->addItem(elucidator, 0);
	swordTab->addItem(darkRepulser, 0);
	swordTab->addItem(kagemitsu, 0);
	swordTab->addItem(lambentLight, 0);
	swordTab->addToTabsList();
 
	CreativeTab* materialTab = new CreativeTab(fragment, 0);
	//Valuables 
	materialTab->addItem(fragment, 0);
	materialTab->addItem(stick, 0);
	materialTab->addItem(fragment, 1);
	materialTab->addItem(stick, 1); 
	materialTab->addToTabsList();
}

std::string CardinalItems::getItemTypeByData(int data) {
	switch(data) {
		case 0:
			return "crystallite";
		case 1:
			return "elucidador";
	}
}
