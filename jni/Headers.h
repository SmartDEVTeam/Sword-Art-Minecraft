#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include "Substrate.h"
#include "com/mojang/minecraftpe/Common.h"
#include "com/mojang/minecraftpe/locale/I18n.h"
#include "com/mojang/minecraftpe/world/item/Item.h"
#include "com/mojang/minecraftpe/world/entity/Mob.h"
#include "com/smartdev/saomc/items/CardinalItems.h"
#include "com/smartdev/saomc/items/recipes/CardinalItemRecipes.h"
#include "com/mojang/minecraftpe/world/level/Level.h"
#include "com/mojang/minecraftpe/world/level/LevelListener.h"
