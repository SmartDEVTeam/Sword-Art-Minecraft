#pragma once

#include <memory>

class BlockSource;
class Random;
class BlockPos;
class Feature;
class Biome;

class BiomeDecorator {
public:	
	BiomeDecorator();
	virtual void decorateOres(BlockSource*, Random&, const BlockPos&);
	virtual ~BiomeDecorator();
	
	void _getRandomHeight(int, int, BlockSource*, Random&, const BlockPos&);
	void _getRandomSolidPosition(BlockSource*, const BlockPos&, Random&);
	void _getRandomSurfacePosition(BlockSource*, const BlockPos&, Random&);
	void _getRandomTreePosition(BlockSource*, const BlockPos&, Random&);
	void _placeFeature(BlockSource*, const std::unique_ptr<Feature>&, const BlockPos&, Random&);
	void decorate(BlockSource*, Random&, Biome*, const BlockPos&, bool, float);
	void decorateDepthAverage(BlockSource*, Random&, const BlockPos&, int, std::unique_ptr<Feature>&, int, int);
	void decorateDepthSpan(BlockSource*, Random&, const BlockPos&, int, std::unique_ptr<Feature>&, int, int);
};