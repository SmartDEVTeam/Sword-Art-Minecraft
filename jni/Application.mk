APP_PLATFORM := android-15
APP_ABI := armeabi-v7a #x86
APP_CFLAGS := -O2 -std=gnu99 # optimization level 2, use C99 (for decleations in for loops, etc)

APP_CPPFLAGS += -std=c++14

APP_STL := gnustl_shared
