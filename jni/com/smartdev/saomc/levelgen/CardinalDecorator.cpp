#include "CardinalDecorator.h"
#include "com/mojang/minecraftpe/world/level/biome/BiomeDecorator.h"
#include "com/mojang/minecraftpe/world/level/levelgen/feature/OreFeature.h"
#include "com/mojang/minecraftpe/world/level/block/Block.h"
#include "CardinalFeatureInfo.h"

#include "../blocks/CardinalBlocks.h"

bool CardinalDecorator::initialized = false;
std::vector<CardinalFeatureInfo> CardinalDecorator::features;

void CardinalDecorator::registerOres() {
	if(initialized)
		return;
	initialized = true;
	
	features.emplace_back(CardinalFeatureInfo::GenType::SPAN, std::unique_ptr<Feature>(new OreFeature(CardinalBlocks::cardinalOre->blockId, 0, 17)), 20, 0, 128);
}

void CardinalDecorator::decorateOres(BiomeDecorator* decorator, BlockSource* region, Random& random, const BlockPos& pos) {	
	for(CardinalFeatureInfo& fe : features) {
		if(fe.gentype == CardinalFeatureInfo::GenType::SPAN)
			decorator->decorateDepthSpan(region, random, pos, fe.amountPerChunk, fe.feature, fe.minY, fe.maxY);
		else if(fe.gentype == CardinalFeatureInfo::GenType::AVERAGE)
			decorator->decorateDepthAverage(region, random, pos, fe.amountPerChunk, fe.feature, fe.minY, fe.maxY);
	}
}
