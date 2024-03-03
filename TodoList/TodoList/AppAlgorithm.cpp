#include "AppAlgorithm.h"
#include "ListManager.h"
#include "Menu.h"
#include <filesystem>
#include <regex>

namespace AppAlgorithm
{
	void FirstMenu(void)
	{
		std::cout << "a. Create todo-list" << std::endl;
		std::cout << "b. Open todo-list" << std::endl;
		std::cout << "c. Show list of todo-lists" << std::endl;
		std::cout << "d. Delete todo-list" << std::endl;
		std::cout << "q. Exit" << std::endl;
	}

	void SecondMenu(void)
	{
		std::cout << "a. Add Task" << std::endl;
		std::cout << "b. Mark task as completed" << std::endl;
		std::cout << "c. Mark task as not completed" << std::endl;
		std::cout << "d. Delete task" << std::endl;
		std::cout << "f. Show list" << std::endl;
		std::cout << "q. Exit" << std::endl;
	}

	void ShowTodoLists(void)
	{
		std::cout << "All todo-lists: " << std::endl;
		for (const auto& it : std::filesystem::directory_iterator(ListFile::folder_path))
		{
			std::string list_path = it.path().string();
			std::string new_list_path;
			list_path.replace(list_path.find(ListFile::folder_path), ListFile::folder_path.length(), new_list_path);
			list_path.replace(list_path.find(".txt"), 4, new_list_path);
			
			std::cout << list_path << std::endl;
		}
			
	}

	void DeleteTodoList(void)
	{
		std::string name;
		std::cout << "Input todo-list name: ";
		std::cin >> name;
		std::filesystem::remove(ListFile::folder_path + name + ".txt");
	}

	void AppAlgorithm(void)
	{
		std::cout << "Test" << std::endl;
		ListManager::ListCreator list_creator;
		while (true)
		{
			FirstMenu();
			std::string tmp;
			std::cout << "Select option: ";
			std::cin >> tmp;
			char ch = *(tmp.begin());

			switch (ch)
			{
			case 'a':
				list_creator.CreateTodoList();
				break;
			case 'b':
				list_creator.OpenTodoList();
				break;
			case 'c':
				ShowTodoLists();
				continue;
			case 'd':
				DeleteTodoList();
				continue;
			case 'q':
				std::cout << "All the best." << std::endl;
				exit(1);
				break;
			default:
				std::cout << "There is no such option!" << std::endl;
				fflush(stdin);
				continue;
			}

			ListManager::ListEditor list_editor(list_creator.GetListFile());
			list_editor.ShowList();

			while (ch != 'q')
			{
				std::cout << "Select option('h' for help): ";
				std::cin >> tmp;
				ch = *(tmp.begin());

				switch (ch)
				{
				case 'h':
					SecondMenu();
					break;
				case 'a':
					list_editor.AddTask();
					break;
				case 'b':
					list_editor.MarkTask(true);
					break;
				case 'c':
					list_editor.MarkTask(false);
					break;
				case 'd':
					list_editor.DeleteTask();
					break;
				case 'f':
					list_editor.ShowList();
					break;
				case 'q':
					std::cout << "List saved." << std::endl;
					break;
				default:
					std::cout << "Wrong choice! Input 'h' for help." << std::endl;
					break;
				}
			}
		}
	}
}