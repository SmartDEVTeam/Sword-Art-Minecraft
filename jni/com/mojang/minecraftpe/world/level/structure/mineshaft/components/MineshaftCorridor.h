#pragma once

#include "../MineshaftPiece.h"
class MineshaftData;
class CompoundTag;
class BlockSource;
class BoundingBox;
class Random;

class MineshaftCorridor : public MineshaftPiece {
public:
	MineshaftCorridor(MineshaftData&);
	MineshaftCorridor(MineshaftData&, int, Random&, BoundingBox const&, int);

	virtual ~MineshaftCorridor();
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
     void postProcess(BlockSource*, Random&, BoundingBox const&);
	virtual void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
	void findCorridorSize(std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&, int, int, int, int);
	void addChildren(StructurePiece*, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&);
	void _placeCobWeb(BlockSource*, BoundingBox const&, Random&, float, int, int, int);
	void _placeSupport(BlockSource*, BoundingBox const&, int, int, int, int, int, Random&);

    void genCustomMineshaft(BlockSource*, Random&, BoundingBox const&);
};
