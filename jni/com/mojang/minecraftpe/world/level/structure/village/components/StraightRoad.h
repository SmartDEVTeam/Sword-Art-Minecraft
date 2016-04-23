#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BlockSource;
class BoundingBox;
class Random;

class StraightRoad : public VillagePiece {
public:
	StraightRoad();
	StraightRoad(StartPiece*, int, Random&, BoundingBox const&, int);
	~Smithy();

	void postProcess(BlockSource*, Random&, BoundingBox const&);

	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
