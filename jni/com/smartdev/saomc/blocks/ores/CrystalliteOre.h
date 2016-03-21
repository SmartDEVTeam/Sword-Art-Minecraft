#pragma once

#include "com/mojang/minecraftpe/world/level/block/Block.h"

class CrystalliteOre : public Block {
public:
	 CrystalliteOre(std::string, int);

    virtual int getExperienceDrop(Random&) const;
	 virtual int getResource(Random&, int, int);
	virtual int getSpawnResourcesAuxValue(unsigned char);
	virtual int getResourceCount(Random&, int, int);
	const TextureUVCoordinateSet& getTexture(signed char, int);
};
