#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BlockSource;
class BoundingBox;
class Random;

class SmallTemple : public VillagePiece {
public:
	SmallTemple();
	SmallTemple(StartPiece*, int, Random&, BoundingBox const&, int);
	~SmallTemple();

	int getVillagerProfession(int);
	void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
	void postProcess(BlockSource*, Random&, BoundingBox const&);
	
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
