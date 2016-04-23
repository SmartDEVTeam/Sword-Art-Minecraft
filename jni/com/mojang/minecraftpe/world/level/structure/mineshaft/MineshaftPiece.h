#pragma once

#include "mcpe/level/structure/StructurePiece.h"
class MineshaftData;
class BlockSource;
class BoundingBox;
class PieceWeight;

class MineshaftPiece : public StructurePiece {
public:
	virtual ~MineshaftPiece();
	void _isSupportingBox(int, int, BlockSource*, int, int);
	void createRandomShaftPiece(MineshaftData&, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&, int, int, int, int, int);
	void generateAndAddPiece(StructurePiece*, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&, int, int, int, int, int);
	void createChest(BlockSource*, BoundingBox const&, Random &, int, int, int, int, std::vector<WeighedTreasureItem, std::allocator<WeighedTreasureItem>> const&, int);
};
