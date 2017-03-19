#pragma once

#include "minecraftpe/world/level/block/Block.h"

class CardinalOre : public Block
{
public:
	CardinalOre(short id);

	virtual int getExperienceDrop(Random&) const;
	virtual short getResource(Random&, int, int);
	virtual int getSpawnResourcesAuxValue(unsigned char);
	virtual int getResourceCount(Random&, int, int);
	virtual std::string buildDescriptionName(unsigned char) const;
};

