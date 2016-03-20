#include "CrystalliteOre.h"

#include "com/mojang/minecraftpe/leveledit.h"
#include "com/mojang/minecraftpe/world/item/Item.h"

#include "../CardinalBlocks.h"
#include "../../items/CardinalItems.h"

CrystalliteOre::CrystalliteOre(std::string asset, int id) : 
	Block("crystalliteOre", id, asset, Material::getMaterial(MaterialType::STONE)) {
	init();
   setSolid(true);
	creativeCategory = 3;
	setDestroyTime(0.5F);
	setSoundType(SOUND_STONE);
	
	CardinalBlocks::registerBlock(this);
}

int CrystalliteOre::getExperienceDrop(Random& rand) const{
return 2;
};

int CrystalliteOre::getResource(Random& random, int data, int fortune) {
	return CardinalItems::crystalliteFragment->itemId;
}

int CrystalliteOre::getSpawnResourcesAuxValue(unsigned char data) {
	return data;
}

int CrystalliteOre::getResourceCount(Random& random, int data, int fortune) {
	return 1 + (fortune * data);
}