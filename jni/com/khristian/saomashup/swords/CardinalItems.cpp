#include "CardinalItems.h"

#include "Elucidator.h"

#include "com/mojang/minecraftpe/world/item/Item.h"

Item* CardinalItems::elucidator;

void CardinalItems::initItems() {
	elucidator = new Elucidator("elucidator", getNextItemId());
	
	initCreativeItems();
}

void CardinalItems::initCreativeItems() {
	Item::addCreativeItem(elucidator, 0);
}

int CardinalItems::getNextItemId() {
	for(int testId = 1000; testId < 4096; testId++) {
		if(Item::mItems[testId] == NULL)
			return testId;
	}
	return 4096;
}