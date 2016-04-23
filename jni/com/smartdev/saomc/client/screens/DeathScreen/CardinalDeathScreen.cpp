#include "CardinalDeathScreen.h"

#include <sstream>

#include "com/mojang/minecraftpe/client/gui/screen/Screen.h"
#include "com/mojang/minecraftpe/client/gui/screen/InventoryScreen.h"
#include "com/mojang/minecraftpe/client/gui/screen/ScreenChooser.h"
#include "com/mojang/minecraftpe/client/gui/Gui.h"
#include "com/mojang/minecraftpe/client/MinecraftClient.h"
#include "com/mojang/minecraftpe/client/gui/NinePatchLayer.h"
#include "com/mojang/minecraftpe/client/gui/IntRectangle.h"
#include "com/mojang/minecraftpe/client/settings/Options.h"
#include "com/mojang/minecraftpe/client/renderer/Tessellator.h"

std::shared_ptr<NinePatchLayer>CardinalDeathScreen::image = NULL;


void CardinalDeathScreen::init(Screen* self)
{
NinePatchFactory sheet (self->mcClient->getTextures(), "gui/deathsheet.png");	
image = std::shared_ptr<NinePatchLayer>(sheet.createSymmetrical({0, 0, 605, 256}, 3, 3, 32.0F, 32.0F));
}

void CardinalDeathScreen::setupPositions(Screen* self)
{
image->xPosition = self->width/3.1;
	image->yPosition = self->height/5.5;
	image->setSize(((float) (605/4)), ((float) 256/4));
}

void CardinalDeathScreen::render(Screen* self, int i1, int i2, float f1)
{
  image->draw(Tessellator::instance, image->xPosition, image->yPosition);
}