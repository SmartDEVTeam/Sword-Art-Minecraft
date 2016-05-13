#pragma once

#include "Screen.h"

class HudScreen : public Screen {
public:
	HudScreen(MinecraftClient&);

	virtual ~HudScreen();
	virtual bool renderGameBehind() const;
	virtual bool isShowingMenu() const;
	virtual bool isModal() const;
	virtual bool shouldStealMouse() const;
	virtual void handleDirection(DirectionId, float, float);
	virtual void render(int, int, float);
};

