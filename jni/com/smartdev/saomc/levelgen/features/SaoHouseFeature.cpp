#include "SaoHouseFeature.h"

#include "com/mojang/minecraftpe/world/level/BlockPos.h"
#include "com/mojang/minecraftpe/world/level/block/Block.h"
#include "com/mojang/minecraftpe/CommonTypes.h"
#include "com/mojang/minecraftpe/world/util/Random.h"

#include "../../blocks/CardinalBlocks.h"

SaoHouseFeature::SaoHouseFeature() : Feature(false) { 

}

bool SaoHouseFeature::place(BlockSource& region, const BlockPos& pos, Random& rand) const {
	if(rand.genrand_int32() % 30 == 1) {
		for(int x = -3; x <= 3; x++) {
			for(int z = -3; z <= 3; z++) {
				for(int y = 0; y <= 6; y++) {	
					if(y == 0 || y == 6 || x == -3 || x == 3 || z == -3 || z == 3)
						_setBlockAndData(region, {pos.x + x, pos.y + y, pos.z + z}, {CardinalBlocks::cardinalOre->blockId, 0});
					else
						_setBlockAndData(region, {pos.x + x, pos.y + y, pos.z + z}, {0, 0});
				}
			}
		}
	}	
	return true;
}