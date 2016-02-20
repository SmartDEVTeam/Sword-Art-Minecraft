#pragma once
class Block;

class CardinalBlocks {
public:
	static Block* testBlock;
	
	static void initBlocks();
	static void registerBlock(Block*);
	static int getNextBlockID();
};