#pragma once

#include "FillingContainer.h"

class Inventory : public FillingContainer {
public:
	int getSelectedSlot() const;
	void selectSlot(int);
};
