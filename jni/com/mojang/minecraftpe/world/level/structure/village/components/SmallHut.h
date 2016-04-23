#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BlockSource;
class BoundingBox;
class Random;

class SmallHut : public VillagePiece {
public:
	SmallHut();
	SmallHut(StartPiece*, int, Random&, BoundingBox const&, int);
	~SmallHut();

	void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
	void postProcess(BlockSource*, Random&, BoundingBox const&);

	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
