#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BlockSource;
class BoundingBox;
class Random;

class SimpleHouse : public VillagePiece {
public:
	SimpleHouse();
	SimpleHouse(StartPiece*, int, Random&, BoundingBox const&, int);
	~SimpleHouse();

	void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
	void postProcess(BlockSource*, Random&, BoundingBox const&);

	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
	
	//Custom functions
	void genSimpleHouse(BlockSource*, Random&, BoundingBox const&);
};
