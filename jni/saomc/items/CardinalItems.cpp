#include "CardinalItems.h"

#include "swords/Elucidator.h"
#include "swords/DarkRepulser.h"
#include "swords/Kagemitsu.h"
#include "swords/LambentLight.h"

#include "valuables/CardinalFragment.h"
#include "valuables/CardinalStick.h"

Item* CardinalItems::elucidator;
Item* CardinalItems::darkRepulser;
Item* CardinalItems::kagemitsu;
Item* CardinalItems::lambentLight;
Item* CardinalItems::fragment;
Item* CardinalItems::stick;

void CardinalItems::initItems()
{
	//Swords
	elucidator = new Elucidator("elucidator", 1000);
	darkRepulser = new DarkRepulser("darkRepulser", 1001);
	kagemitsu = new Kagemitsu("kagemitsu", 1002);
	lambentLight = new LambentLight("lambentLight", 1003);

	//Valuables
	fragment = new CardinalFragment(900);
	stick = new CardinalStick(901);
}

void CardinalItems::initCreativeItems()
{
	Item::addCreativeItem(900, 0);
	Item::addCreativeItem(901, 0);
	
	Item::addCreativeItem(1000, 0);
	Item::addCreativeItem(1001, 0);
	Item::addCreativeItem(1002, 0);
	Item::addCreativeItem(1003, 0);
}

std::string CardinalItems::getTypeByData(unsigned char aux)
{
	switch (aux) {
		case 0:
			return "crystallite";
		case 1:
			return "elucidador";
	}
}

