#include "CardinalItems.h"

#include "Elucidator.h"
#include "darkRepulser.h"

#include "com/mojang/minecraftpe/world/item/Item.h"

Item* CardinalItems::elucidator;
Item* CardinalItems::DarkRepulser;


void CardinalItems::initItems() {
	elucidator = new Elucidator("elucidator", 1000);
   //DarkRepulser = new darkRepulser("darkRepulser", 1001);
	
	initCreativeItems();
}

void CardinalItems::initCreativeItems() {
	Item::addCreativeItem(elucidator, 0);
    //Item::addCreativeItem(DarkRepulser, 0);
}

int CardinalItems::getNextItemId() {
	for(int testId = 1000; testId < 4096; testId++) {
		if(Item::mItems[testId] == NULL)
			return testId;
	}
	return 4096;
}