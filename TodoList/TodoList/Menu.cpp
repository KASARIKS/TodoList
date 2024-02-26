#include "Menu.h"

namespace Menu
{
	// Option methods
	Option::Option(const std::string& name, char indicator, void(*action)(void)) : name(name)
	{
		this->indicator = indicator;
		this->action = action;
	}

	std::string Option::GetOptionLine(void)
	{
		return name + " " + indicator;
	}
	char Option::GetIndicator(void)
	{
		return indicator;
	}

	void Option::DoAction(void)
	{
		action();
	}

	std::ostream& operator<<(std::ostream& out, const Option& option)
	{
		out << option.name + " " + option.indicator;
		return out;
	}

	// Menu methods
	Menu::Menu(const MenuOptions& menu_options) : options(menu_options)
	{

	}

	void Menu::Show(void)
	{
		for (auto option = options.begin(); option != options.end(); ++option)
			std::cout << *option << std::endl;
	}

	void Menu::SelectOption(void)
	{
		char indicator;
		std::cout << "Select option: ";
		std::cin >> indicator;
		for (auto option = options.begin(); option != options.end(); ++option)
			if (option->GetIndicator() == indicator)
			{
				option->DoAction();
				return;
			}

		throw std::invalid_argument("Wrong indicator");
	}

}