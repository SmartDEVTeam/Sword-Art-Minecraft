#include "CrystalliteOre.h"

#include "com/mojang/minecraftpe/leveledit.h"
#include "com/mojang/minecraftpe/world/item/Item.h"
#include "com/mojang/minecraftpe/world/util/Random.h"
#include "com/mojang/minecraftpe/CreativeItemCategory.h"

#include "../CardinalBlocks.h"
#include "../../items/CardinalItems.h"

CrystalliteOre::CrystalliteOre(std::string asset, int id) : 
	Block("crystalliteOre", id, asset, Material::getMaterial(MaterialType::STONE)) {
	
	creativeCategory = CreativeItemCategory::BLOCKS;
	setDestroyTime(0.5F);
	setSoundType(SOUND_STONE);
	
	CardinalBlocks::registerBlock(this);
}

int CrystalliteOre::getExperienceDrop(Random& rand) const{
	return (rand.genrand_int32() % 3); // drops from 0 to 4 experience orbs
};

int CrystalliteOre::getResource(Random& random, int data, int fortune) {
	return CardinalItems::crystalliteFragment->itemId;
}

int CrystalliteOre::getResourceCount(Random& rand, int data, int fortune) {
	return fortune * (rand.genrand_int32() % 3) + 1; // drops between 1 and 4 * fortune
}
