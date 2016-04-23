#pragma once
#include "com/mojang/minecraftpe/world/level/structure/StructurePiece.h"
#include "com/mojang/minecraftpe/world/level/block/Block.h"

class CompoundTag;
class Random;
class BlockSource;
class BoundingBox;

class CardinalHouseStructure : public StructurePiece {
public:

    void postProcess(BlockSource*, Random&, BoundingBox const&);
    void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
    void addAdditionalSaveData(CompoundTag&);
    void readAdditionalSaveData(CompoundTag&);
};

