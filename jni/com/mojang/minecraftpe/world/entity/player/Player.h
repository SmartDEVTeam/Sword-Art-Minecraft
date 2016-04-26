#pragma once
#include "../Entity.h"
#include "../../item/ItemInstance.h"

class Tick;

class Player : public Entity {
public:
	char filler2[2971];
	bool creativeMode;

   void tickWorld(Tick const&);
	void drop(const ItemInstance*);
	ItemInstance* getSelectedItem() const;
	bool IsCreative() const;
};
