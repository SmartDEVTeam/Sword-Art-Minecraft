#pragma once

#include <memory>
#include <vector>

#include "com/mojang/minecraftpe/client/gui/TButton.h"

class Screen;
class ExtendedInventoryScreen;

class CardinalDeathScreen
{
public:
static std::shared_ptr<NinePatchLayer> image;

	static void init(Screen*);
	static void setupPositions(Screen*);
	static void render(Screen*, int, int, float);
	static void _buttonClicked(Screen*, Button&);
};