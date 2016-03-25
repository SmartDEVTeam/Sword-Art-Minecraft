#pragma once
class BlockSource;
class BlockPos;
class Random;

#include "../../../../CommonTypes.h"

class Feature {
public:
	Feature(bool);
	
	virtual ~Feature();
	virtual bool place(BlockSource&, const BlockPos&, Random&) const = 0;
	
	bool _getManuallyPlaced() const;
	void _placeBlock(BlockSource&, const BlockPos&, const FullBlock&) const;
	void _setBlockAndData(BlockSource&, const BlockPos&, const FullBlock&) const;
};

