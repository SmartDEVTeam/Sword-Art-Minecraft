#include "CardinalItems.h"

#include "Elucidator.h"
#include "DarkRepulser.h"
#include "Kagemitsu.h"

#include "com/mojang/minecraftpe/world/item/Item.h"

Item* CardinalItems::elucidator;
Item* CardinalItems::darkRepulser;
Item* CardinalItems::kagemitsu;


void CardinalItems::initItems() {
	elucidator = new Elucidator("elucidator", 1000);
   darkRepulser = new DarkRepulser("darkRepulser", 1001);
   kagemitsu = new Kagemitsu("kagemitsu", 1002);
	
	initCreativeItems();
}

void CardinalItems::initCreativeItems() {
	Item::addCreativeItem(elucidator, 0);
   Item::addCreativeItem(darkRepulser, 0);
   Item::addCreativeItem(kagemitsu, 0);
}

int CardinalItems::getNextItemId() {
	for(int testId = 1000; testId < 4096; testId++) {
		if(Item::mItems[testId] == NULL)
			return testId;
	}
	return 4096;
}