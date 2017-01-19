#pragma once

#include "minecraftpe/world/level/block/Block.h"

class CardinalOre : public Block
{
public:
	CardinalOre(int);

	virtual int getExperienceDrop(Random&) const;
	virtual int getResource(Random&, int, int);
	virtual int getSpawnResourcesAuxValue(unsigned char);
	virtual int getResourceCount(Random&, int, int);
	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual std::string buildDescriptionName(unsigned char) const;
	std::string getTypeByData(int);
};

