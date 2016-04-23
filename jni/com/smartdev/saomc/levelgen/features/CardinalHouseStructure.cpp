#include "CardinalHouseStructure.h"


void CardinalHouseStructure::postProcess(BlockSource* region, Random& random, BoundingBox const& bounds) {
generateBox(region, bounds, 0, 0, 0, 10, 10, 10, {Block::mCobblestone->blockId, 0}, {Block::mCobblestone->blockId, 0}, false);
}

void CardinalHouseStructure ::postProcessMobsAt(BlockSource* region, Random& random, BoundingBox const& bounds) {

//Spawn the structures mobs here

}

void CardinalHouseStructure::addAdditionalSaveData(CompoundTag&) {
//add data
}


void CardinalHouseStructure::readAdditionalSaveData(CompoundTag&) {
//add data
}