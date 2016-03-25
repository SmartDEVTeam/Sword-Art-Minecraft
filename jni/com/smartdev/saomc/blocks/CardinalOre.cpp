#include "CardinalOre.h"

#include "com/mojang/minecraftpe/leveledit.h"
#include "com/mojang/minecraftpe/world/item/Item.h"
#include "com/mojang/minecraftpe/world/item/ItemInstance.h"
#include "com/mojang/minecraftpe/world/util/Random.h"
#include "com/mojang/minecraftpe/CreativeItemCategory.h"

#include "CardinalBlocks.h"
#include "../items/CardinalItems.h"

CardinalOre::CardinalOre(int id) : 
	Block("cardinalore", id, "stone", Material::getMaterial(MaterialType::STONE)) {
	
	creativeCategory = CreativeItemCategory::BLOCKS;
	setDestroyTime(0.5F);
	setSoundType(SOUND_STONE);
	
	initTextures();
	
	CardinalBlocks::registerAuxDataBlock(this);
}

int CardinalOre::getExperienceDrop(Random& rand) const{
	return (rand.genrand_int32() % 4); // drops from 0 to 4 experience orbs
};

int CardinalOre::getResource(Random& random, int data, int fortune) {
	return CardinalItems::fragment->itemId;
}

int CardinalOre::getSpawnResourcesAuxValue(unsigned char blockData) {
	return (int) blockData;
}

int CardinalOre::getResourceCount(Random& rand, int data, int fortune) {
	return fortune * (rand.genrand_int32() % 3) + 1; // drops between 1 and 4 fortune
}

const TextureUVCoordinateSet& CardinalOre::getTexture(signed char side, int data) {
	return textures[data];
}

std::string CardinalOre::buildDescriptionName(const ItemInstance& item) const {
	return "tile.cardinalOre." + CardinalItems::getItemTypeByData(item.aux) + ".name";
}

void CardinalOre::initTextures() {
	textures[0] = getTextureUVCoordinateSet("crystalliteore", 0);
	textures[1] = getTextureUVCoordinateSet("elucidadorore", 0);
}