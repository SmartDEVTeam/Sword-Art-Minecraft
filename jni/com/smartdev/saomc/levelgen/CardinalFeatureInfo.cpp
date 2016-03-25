#include "CardinalFeatureInfo.h"

CardinalFeatureInfo::CardinalFeatureInfo(CardinalFeatureInfo::GenType gentype, std::unique_ptr<Feature> feature, int amountPerChunk, int minY, int maxY) :
	gentype(gentype),
	feature(std::move(feature)),
	amountPerChunk(amountPerChunk),
	minY(minY),
	maxY(maxY) {
}

