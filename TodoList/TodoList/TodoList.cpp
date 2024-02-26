#include <iostream>
#include "Menu.h"

int main()
{
    using Menu::MenuOptions;
    using Menu::Option;
    const std::string first("create todo-list");
    MenuOptions menu_options1 = { 
        Option("Create todo-list", 'a', []() {std::cout << "Action: creating a todo-list" << std::endl; }), 
        Option("Open todo-list", 'b', []() {std::cout << "Action: opening a todo-list" << std::endl; }),
        Option("Exit", 'q', []() {std::cout << "Action: exit" << std::endl; })
    };

    Menu::Menu menu_1(menu_options1);
    menu_1.Show();
    menu_1.SelectOption();
}