#pragma once
#include <string>
#include "SDL2/SDL.h"

namespace GUI
{
	// Structs responsible for displaying warning and error windows
	//
	struct ErrorBox
	{
	private:
		static const std::string TITLE;
	public:
		ErrorBox(const std::string &message);
	};

	struct WarningBox
	{
	private:
		static const std::string TITLE;
	public:
		WarningBox(const std::string &message);
	};
	//
}