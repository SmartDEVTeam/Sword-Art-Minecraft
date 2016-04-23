#pragma once
#include <string>

class AppPlatform {
public:
	static AppPlatform* mSingleton;
   std::string getEdition() const;
};

