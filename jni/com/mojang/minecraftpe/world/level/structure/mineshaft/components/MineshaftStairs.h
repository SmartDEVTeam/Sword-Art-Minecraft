#pragma once

#include "../MineshaftPiece.h"
class MineshaftData;
class CompoundTag;
class BlockSource;
class BoundingBox;
class Random;

class MineshaftStairs : public MineshaftPiece {
public:
	MineshaftStairs(MineshaftData&);
	MineshaftStairs(MineshaftData&, int, Random&, BoundingBox const&, int);

	virtual ~MineshaftStairs();
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
	virtual void postProcess(BlockSource*, Random&, BoundingBox const&);
	void findCorridorSize(std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&, int, int, int, int);
	void addChildren(StructurePiece*, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&);
	void findStairs(std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&, int, int, int, int);
};
