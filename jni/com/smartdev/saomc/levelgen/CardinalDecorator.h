#pragma once

#include <vector>
#include <memory>

class BiomeDecorator;
class BlockSource;
class Random;
class BlockPos;
class OreFeatureInfo;
class Feature;
class Biome;

class CardinalDecorator {
public:
	static bool initialized;
	static std::vector<OreFeatureInfo> oreFeatures;
	static std::unique_ptr<Feature> saoHouseFeature;

	static void registerFeatures();
	
	static void decorateOres(BiomeDecorator*, BlockSource*, Random&, const BlockPos&);
	static void decorate(BiomeDecorator*, BlockSource*, Random&, Biome*, const BlockPos&, bool, float);
};