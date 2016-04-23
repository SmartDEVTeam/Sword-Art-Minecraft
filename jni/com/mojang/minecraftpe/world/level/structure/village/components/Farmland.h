#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BlockSource;
class BoundingBox;
class Random;

class Farmland : public VillagePiece {
public:
	Farmland();
	Farmland(StartPiece*, int, Random&, BoundingBox const&, int);
	~Farmland();

	void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
	void postProcess(BlockSource*, Random&, BoundingBox const&);

	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
