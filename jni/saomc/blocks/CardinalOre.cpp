#include "CardinalOre.h"
#include "minecraftpe/world/item/Item.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/util/Random.h"

#include "CardinalBlocks.h"
#include "../items/CardinalItems.h"

CardinalOre::CardinalOre(short id) : Block("cardinalOre", id, Material::getMaterial(MaterialType::STONE))
{
	Block::mBlocks[id] = this;
	init();
	setCategory(CreativeItemCategory::Blocks);
	setDestroyTime(0.5f);
}

int CardinalOre::getExperienceDrop(Random &random) const
{
	return random.genrand_int32() % 4; // drops from 0 to 4 experience orbs
}

short CardinalOre::getResource(Random&, int, int)
{
	return CardinalItems::fragment->itemId;
}

int CardinalOre::getSpawnResourcesAuxValue(unsigned char aux)
{
	return aux;
}

int CardinalOre::getResourceCount(Random &random, int, int fortune)
{
	return fortune * (random.genrand_int32() % 3) + 1; // drops between 1 and 4 fortune
}

std::string CardinalOre::buildDescriptionName(unsigned char aux) const
{
	return "tile.cardinalOre." + CardinalItems::getTypeByData(aux) + ".name";
}

