#pragma once

#include <memory>
#include <vector>

#include "com/mojang/minecraftpe/client/gui/ImageButton.h"
class Screen;

class CardinalDeathScreen
{
public:
	static std::shared_ptr<ImageButton> respawnButton;

	static void init(Screen*);
	static void setupPositions(Screen*);
	static void render(Screen*, int, int, float);
	static void _buttonClicked(Screen*, Button&);
};
