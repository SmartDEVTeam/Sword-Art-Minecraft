#pragma once
#include <memory>
#include "com/mojang/minecraftpe/world/level/levelgen/feature/Feature.h"

struct CardinalFeatureInfo {
	enum class GenType : int {
		SPAN,
		AVERAGE
	};
	
	CardinalFeatureInfo(CardinalFeatureInfo::GenType, std::unique_ptr<Feature>, int, int, int);
	
	CardinalFeatureInfo::GenType gentype;
	std::unique_ptr<Feature> feature;
	int amountPerChunk;
	int minY;
	int maxY;
};

