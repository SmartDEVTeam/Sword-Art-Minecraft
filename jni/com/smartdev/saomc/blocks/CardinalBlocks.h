#pragma once
class Block;

class CardinalBlocks {
public:
	static Block* cardinalOre;
	
	static void initBlocks();
	static void registerBlock(Block*);
	
	static void initCreativeBlocks();
};