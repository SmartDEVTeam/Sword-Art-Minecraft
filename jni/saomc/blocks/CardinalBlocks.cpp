#include "CardinalBlocks.h"

#include "minecraftpe/world/item/AuxDataBlockItem.h"
#include "minecraftpe/client/renderer/block/BlockGraphics.h"

#include "CardinalOre.h"

Block* CardinalBlocks::cardinalOre;

void CardinalBlocks::initBlocks()
{
	cardinalOre = new CardinalOre(220);
}

void CardinalBlocks::initBlockItems()
{
	Item::mItems[220] = new AuxDataBlockItem(cardinalOre->getDescriptionId(), 220 - 256, cardinalOre);
}

void CardinalBlocks::initCreativeBlocks()
{	
	Item::addCreativeItem(220, 0);
	Item::addCreativeItem(220, 1);
}

void CardinalBlocks::initBlockGraphics()
{
	BlockGraphics::mBlocks[220] = new BlockGraphics("dirt");
	BlockGraphics::mBlocks[220]->setTextureItem("cardinal_ore");
}

