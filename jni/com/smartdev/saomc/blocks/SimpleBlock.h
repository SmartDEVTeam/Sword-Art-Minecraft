#pragma once

#include "com/mojang/minecraftpe/world/level/block/Block.h"

class SimpleBlock : public Block {
public:
	SimpleBlock(std::string, int);

	virtual int getResourceCount(Random&, int, int);
    virtual bool isCraftingBlock() const;
};