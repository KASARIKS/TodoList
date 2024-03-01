//#include <iostream>
//#include "Menu.h"
//#include "ListFile.h"
//#include "ListManager.h"
#include "AppAlgorithm.h"

int main()
{
    /*using Menu::MenuOptions;
    using Menu::Option;
    MenuOptions menu_options1 = { 
        Option("Create todo-list", 'a', []() {std::cout << "Action: creating a todo-list" << std::endl; }), 
        Option("Open todo-list", 'b', []() {std::cout << "Action: opening a todo-list" << std::endl; }),
        Option("Exit", 'q', []() {std::cout << "Action: exit" << std::endl; })
    };

    Menu::Menu menu_1(menu_options1);
    menu_1.Show();
    menu_1.SelectOption();*/

    /*ListFile::ListFile list_file("test_list");
    list_file.CreateList();
    TaskList::List list(list_file.GetList());
    
    auto tasks = list.GetTasks();

    for (auto it = tasks.begin(); it != tasks.end(); ++it)
        std::cout << *it << std::endl;
    
    list.AddTask("Do my homework").AddTask("Clean my room");

    list_file.SaveList(list);*/
    AppAlgorithm::AppAlgorithm();
}