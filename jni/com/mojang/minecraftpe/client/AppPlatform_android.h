#pragma once

#include "AppPlatform.h"

class ImageData;
class Vec2;
class ImagePickingCallback;

class AppPlatform_android : public AppPlatform {
public:
	AppPlatform_android();
	
	virtual ~AppPlatform_android();
	virtual void getDataUrl() const;
	virtual std::string getImagePath(const std::string&, bool);
	virtual void loadPNG(ImageData&, const std::string&, bool);
	virtual void loadTGA(ImageData&, const std::string&, bool);
	virtual void getKeyFromKeyCode(int, int, int);
	virtual void showKeyboard(const std::string&, int, bool, bool, const Vec2&);
	virtual void hideKeyboard();
	virtual float getKeyboardHeight() const;
	virtual void swapBuffers();
	virtual void discardBackbuffer();
	virtual void getSystemRegion() const;
	virtual void getGraphicsVendor();
	virtual void getGraphicsRenderer();
	virtual void getGraphicsVersion();
	virtual void getGraphicsExtensions();
	virtual void pickImage(ImagePickingCallback&);
	virtual std::string getExternalStoragePath();
	virtual std::string getInternalStoragePath();
	virtual std::string getUserDataPath();
	virtual void showDialog(int);
	virtual void createUserInput();
	virtual void getUserInputStatus();
	virtual void getUserInput();
	virtual int getScreenWidth();
	virtual int getScreenHeight();
   	int getScreenType() const;
};
