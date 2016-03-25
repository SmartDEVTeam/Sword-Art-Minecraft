#pragma once
#include "Feature.h"

class OreFeature : public Feature {
public:
	OreFeature(BlockID, int);
	OreFeature(BlockID, unsigned char, int);
	
	virtual ~OreFeature();
	virtual bool place(BlockSource&, const BlockPos&, Random&) const;
	
	static bool _isDiggable(BlockID);
};

