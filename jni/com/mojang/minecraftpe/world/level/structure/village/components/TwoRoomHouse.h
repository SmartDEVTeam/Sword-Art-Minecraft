#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BlockSource;
class BoundingBox;
class Random;

class TwoRoomHouse : public VillagePiece {
public:
	TwoRoomHouse();
	TwoRoomHouse(StartPiece*, int, Random&, BoundingBox const&, int);
	~TwoRoomHouse();
	
	void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
	void postProcess(BlockSource*, Random&, BoundingBox const&);

	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
