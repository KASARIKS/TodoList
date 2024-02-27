#pragma once
#include "StartLibraryPack.h"

namespace Menu
{
	// Has pointer to function, and call it
	class Option
	{
		std::string name;
		char indicator;
		void (*action)(void);
	public:
		Option(const std::string& name, char indicator, void(*action)(void));
		std::string GetOptionLine(void);
		char GetIndicator(void);
		void DoAction(void);
		friend std::ostream& operator<<(std::ostream& out, const Option& option);
	};

	typedef std::vector<Option> MenuOptions;
	
	class Menu
	{
		MenuOptions options;
	public:
		Menu(const MenuOptions& menu_options);
		void Show(void);
		void SelectOption(void);
	};
}