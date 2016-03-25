#pragma once

#include <vector>

class BiomeDecorator;
class BlockSource;
class Random;
class BlockPos;
class CardinalFeatureInfo;

class CardinalDecorator {
public:
	static bool initialized;
	static std::vector<CardinalFeatureInfo> features;

	static void registerOres();
	
	static void decorateOres(BiomeDecorator*, BlockSource*, Random&, const BlockPos&);
};