#pragma once

#include "com/mojang/minecraftpe/world/level/levelgen/feature/Feature.h"

class SaoHouseFeature : public Feature {
public:
	SaoHouseFeature();
	
	virtual bool place(BlockSource&, const BlockPos&, Random&) const;
};