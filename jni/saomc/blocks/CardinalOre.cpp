#include "CardinalOre.h"

#include "minecraftpe/leveledit.h"
#include "minecraftpe/world/item/Item.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/util/Random.h"

#include "CardinalBlocks.h"
#include "../items/CardinalItems.h"

CardinalOre::CardinalOre(int id) : Block("cardinalore", id, Material::getMaterial(MaterialType::STONE))
{
	init();
	setCategory(CreativeItemCategory::Blocks);
	setDestroyTime(0.5F);
}

int CardinalOre::getExperienceDrop(Random &rand) const
{
	return (rand.genrand_int32() % 4); // drops from 0 to 4 experience orbs
};

int CardinalOre::getResource(Random &random, int data, int fortune)
{
	return CardinalItems::fragment->itemId;
}

int CardinalOre::getSpawnResourcesAuxValue(unsigned char blockData)
{
	return (int) blockData;
}

int CardinalOre::getResourceCount(Random &rand, int data, int fortune)
{
	return fortune * (rand.genrand_int32() % 3) + 1; // drops between 1 and 4 fortune
}

std::string CardinalOre::buildDescriptionName(unsigned char aux) const
{
	return "tile.cardinalOre." + CardinalItems::getItemTypeByData(aux) + ".name";
}

