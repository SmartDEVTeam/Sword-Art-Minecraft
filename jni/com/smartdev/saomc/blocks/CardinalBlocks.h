#pragma once
class Block;

class CardinalBlocks {
public:
	static Block* crystalliteOre;
	
	static void initBlocks();
	static void registerBlock(Block*);
	
	static void initCreativeItems();
};