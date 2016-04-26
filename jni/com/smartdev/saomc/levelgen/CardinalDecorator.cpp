#include "CardinalDecorator.h"
#include "com/mojang/minecraftpe/world/level/biome/BiomeDecorator.h"
#include "com/mojang/minecraftpe/world/level/levelgen/feature/OreFeature.h"
#include "com/mojang/minecraftpe/world/level/block/Block.h"
#include "com/mojang/minecraftpe/world/level/BlockSource.h"
#include "com/mojang/minecraftpe/world/level/BlockPos.h"
#include "com/mojang/minecraftpe/world/util/Random.h"
#include "OreFeatureInfo.h"

#include "../blocks/CardinalBlocks.h"

bool CardinalDecorator::initialized = false;
std::vector<OreFeatureInfo> CardinalDecorator::oreFeatures;

void CardinalDecorator::registerFeatures() {
	if(initialized)
		return;
	initialized = true;
	
	oreFeatures.emplace_back(OreFeatureInfo::GenType::SPAN, std::unique_ptr<Feature>(new OreFeature(CardinalBlocks::cardinalOre->blockId, 0, 10)), 1, 1, 16);
	oreFeatures.emplace_back(OreFeatureInfo::GenType::SPAN, std::unique_ptr<Feature>(new OreFeature(CardinalBlocks::cardinalOre->blockId, 1, 10)), 1, 1, 16);
}

void CardinalDecorator::decorateOres(BiomeDecorator* decorator, BlockSource* region, Random& random, const BlockPos& pos) {	
	for(OreFeatureInfo& fe : oreFeatures) {
		if(fe.gentype == OreFeatureInfo::GenType::SPAN)
			decorator->decorateDepthSpan(region, random, pos, fe.amountPerChunk, fe.feature, fe.minY, fe.maxY);
		else if(fe.gentype == OreFeatureInfo::GenType::AVERAGE)
			decorator->decorateDepthAverage(region, random, pos, fe.amountPerChunk, fe.feature, fe.minY, fe.maxY);
	}
}

void CardinalDecorator::decorate(BiomeDecorator* decorator, BlockSource* region, Random& random, Biome* biome, const BlockPos& pos, bool b1, float f1) {
	int randX = pos.x + (random.genrand_int32() % 15);
	int randZ = pos.z + (random.genrand_int32() % 15);
	int topY = region->getTopSolidBlock(randX, randZ, false);
	//decorator->_placeFeature(region, CardinalHouseFeature, {randX, topY, randZ}, random);
}