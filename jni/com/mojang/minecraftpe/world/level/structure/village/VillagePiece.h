#pragma once

#include "../StartPiece.h"
class CompoundTag;
class BlockSource;
class BoundingBox;
class FullBlock;
class PieceWeight;

class VillagePiece : public StructurePiece {
public:
	StartPiece* start;

	VillagePiece();
	VillagePiece(StartPiece*, int);

	~VillagePiece();
	void spawnVillagers(BlockSource*, BoundingBox const&, int, int, int, int);
	bool biomeBlock(FullBlock);
	void fillColumnDown(BlockSource*, FullBlock, int, int, int, BoundingBox const&);
	void generateBox(BlockSource*, BoundingBox const&, int, int, int, int, int, int, FullBlock, FullBlock, bool);
	int getAverageGroundHeight(BlockSource*, BoundingBox const&);
	int getVillagerProfession(int);
	bool isOkBox(BoundingBox const&);
	void placeBlock(BlockSource*, FullBlock, int, int, int, BoundingBox const&);

	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
