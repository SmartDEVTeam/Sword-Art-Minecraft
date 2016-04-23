#pragma once

#include "ItemInstance.h";

class FillingContainer {
public:
	ItemInstance* getLinked(int) const; // from Inventory::getSelected
};
