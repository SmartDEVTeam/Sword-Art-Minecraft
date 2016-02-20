#include "CardinalItems.h"

#include "Elucidator.h"
#include "DarkRepulser.h"
#include "Kagemitsu.h"
#include "LambentLight.h"

#include "../blocks/CardinalBlocks.h"

#include "com/mojang/minecraftpe/world/item/Item.h"

Item* CardinalItems::elucidator;
Item* CardinalItems::darkRepulser;
Item* CardinalItems::kagemitsu;
Item* CardinalItems::lambentLight;


void CardinalItems::initItems() {
   elucidator = new Elucidator("elucidator", getNextItemId());
   darkRepulser = new DarkRepulser("darkRepulser", getNextItemId());
   kagemitsu = new Kagemitsu("kagemitsu", getNextItemId());
   lambentLight = new LambentLight("lambentLight", getNextItemId());
	
	initCreativeItems();
}

void CardinalItems::initCreativeItems() {
	Item::addCreativeItem(elucidator, 0);
   Item::addCreativeItem(darkRepulser, 0);
   Item::addCreativeItem(kagemitsu, 0);
   Item::addCreativeItem(lambentLight, 0);
   Item::addCreativeItem(CardinalBlocks::testBlock, 0);
}

int CardinalItems::getNextItemId() {
	for(int testId = 1000; testId < 4096; testId++) {
		if(Item::mItems[testId] == NULL)
			return testId;
	}
	return 4096;
}