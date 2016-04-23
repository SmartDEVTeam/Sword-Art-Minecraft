#pragma once

#include "ItemInstance.h"

class PlayerRenderer;
class MinecraftClient;

class ItemInHandRenderer {
public:
	char filler[52];
	ItemInstance itemToRender;
   MinecraftClient* minecraft;
	
	void render(float);
   void _renderLeftHand(PlayerRenderer&, float);
};