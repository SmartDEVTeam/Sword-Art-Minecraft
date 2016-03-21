#pragma once

#include "com/mojang/minecraftpe/world/level/block/Block.h"

class CrystalliteOre : public Block {
public:
	CrystalliteOre(std::string, int);

	virtual int getExperienceDrop(Random&) const;
	virtual int getResource(Random&, int, int);
	virtual int getResourceCount(Random&, int, int);
};
