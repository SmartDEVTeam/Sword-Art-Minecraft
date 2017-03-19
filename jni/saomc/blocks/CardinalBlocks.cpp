#include "CardinalBlocks.h"

#include "minecraftpe/world/item/AuxDataBlockItem.h"
#include "minecraftpe/world/level/block/BlockGraphics.h"

#include "CardinalOre.h"

Block* CardinalBlocks::mCardinalOre;

void CardinalBlocks::initBlocks()
{
	mCardinalOre = new CardinalOre(220);
}

void CardinalBlocks::initBlockItems()
{
	Item::mItems[mCardinalOre->blockId] = new AuxDataBlockItem(mCardinalOre->getDescriptionId(), mCardinalOre->blockId - 256, mCardinalOre);
}

void CardinalBlocks::initCreativeBlocks()
{	
	Item::addCreativeItem(mCardinalOre, 0);
	Item::addCreativeItem(mCardinalOre, 1);
}

void CardinalBlocks::initBlockGraphics()
{
	BlockGraphics::mBlocks[220] = new BlockGraphics("dirt");
	BlockGraphics::mBlocks[220]->setTextureItem("cardinal_ore");
}

