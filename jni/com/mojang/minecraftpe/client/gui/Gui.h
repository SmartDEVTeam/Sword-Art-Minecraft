#pragma once

#include "GuiComponent.h"
#include "../AppPlatformListener.h"

class MinecraftClient;
class Config;

class Gui : public GuiComponent, public AppPlatformListener {
public:
	Gui(MinecraftClient&);
	virtual ~Gui();
	virtual void onAppSuspended();
	virtual void onConfigChanged(const Config&);
    virtual void render(float, bool, int, int);
	void renderToolBar(float, float, bool);
   virtual void renderHearts();
	void renderProgressIndicator(int, int, float);
	void showPopupNotice(const std::string&, const std::string&);
	void renderOnSelectItemNameText(int, Font*, int);
};
