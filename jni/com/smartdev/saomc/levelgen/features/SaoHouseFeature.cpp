#include "SaoHouseFeature.h"

#include "com/mojang/minecraftpe/world/level/BlockPos.h"
#include "com/mojang/minecraftpe/world/level/block/Block.h"
#include "com/mojang/minecraftpe/CommonTypes.h"

#include "../../blocks/CardinalBlocks.h"

SaoHouseFeature::SaoHouseFeature() : Feature(false) { 

}

bool SaoHouseFeature::place(BlockSource& region, const BlockPos& pos, Random& rand) const {
	for(int x = -8; x < 8; x++) {
		for(int z = -8; z < 8; z++) {
			_setBlockAndData(region, {pos.x + x, pos.y, pos.z + z}, {CardinalBlocks::cardinalOre->blockId, 0});
		}
	}
	return true;
}