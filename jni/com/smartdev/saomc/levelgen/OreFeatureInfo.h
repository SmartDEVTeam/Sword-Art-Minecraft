#pragma once
#include <memory>
#include "com/mojang/minecraftpe/world/level/levelgen/feature/Feature.h"

struct OreFeatureInfo {
	enum class GenType : int {
		SPAN,
		AVERAGE
	};
	
	OreFeatureInfo(OreFeatureInfo::GenType, std::unique_ptr<Feature>, int, int, int);
	
	OreFeatureInfo::GenType gentype;
	std::unique_ptr<Feature> feature;
	int amountPerChunk;
	int minY;
	int maxY;
};

