#include "CardinalBlocks.h"

#include "com/mojang/minecraftpe/world/level/block/Block.h"

#include "SimpleBlock.h"

Block* CardinalBlocks::testBlock;

void CardinalBlocks::initBlocks() {
	testBlock = new SimpleBlock("stone", getNextBlockID());
}

void CardinalBlocks::registerBlock(Block* block) {
	block->init();
	Block::mBlocks[block->blockId] = block;
	Block::mOwnedBlocks.emplace_back(std::unique_ptr<Block>(block));
}

int CardinalBlocks::getNextBlockID() {
	for(int blockId = 0; blockId < 256; blockId++) {
		if(Block::mBlocks[blockId] == NULL) {
			return blockId;
		}
	}
	return 255;
}