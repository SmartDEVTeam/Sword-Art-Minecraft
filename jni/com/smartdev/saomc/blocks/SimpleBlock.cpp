#include "SimpleBlock.h"

#include "com/mojang/minecraftpe/leveledit.h"

#include "CardinalBlocks.h"

SimpleBlock::SimpleBlock(std::string asset, int id) : 
	Block("simpleBlock", id, asset, Material::getMaterial(MaterialType::DECORATION)) {
		
	//creativeCategory = 3;
	setDestroyTime(0.5F);
	setSoundType(SOUND_GRASS);
	
	CardinalBlocks::registerBlock(this);
}

int SimpleBlock::getResourceCount(Random& rand, int i1, int i2) {
	return 3;
}

bool SimpleBlock::isCraftingBlock() const{
return true;
}