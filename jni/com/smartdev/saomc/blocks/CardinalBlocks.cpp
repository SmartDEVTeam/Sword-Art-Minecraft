#include "CardinalBlocks.h"

#include "com/mojang/minecraftpe/world/level/block/Block.h"
#include "com/mojang/minecraftpe/world/item/Item.h"
#include "com/mojang/minecraftpe/world/item/BlockItem.h"

#include "CardinalOre.h"

Block* CardinalBlocks::cardinalOre;

void CardinalBlocks::initBlocks() {
	cardinalOre = new CardinalOre(210);
}

void CardinalBlocks::registerBlock(Block* block) {
	block->init();
	Block::mBlocks[block->blockId] = block;
	Block::mOwnedBlocks.emplace_back(std::unique_ptr<Block>(block));
	Item::mItems[block->blockId] = new BlockItem(block->getDescriptionId(), block->blockId - 0x100);
}

void CardinalBlocks::initCreativeBlocks() {	
	Item::addCreativeItem(cardinalOre, 0);
	Item::addCreativeItem(cardinalOre, 1);
}
