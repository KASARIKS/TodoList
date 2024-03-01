#include "AppAlgorithm.h"
#include "ListManager.h"
#include "Menu.h"

namespace AppAlgorithm
{
	void FirstMenu(void)
	{
		std::cout << "a. Create todo-list" << std::endl;
		std::cout << "b. Open todo-list" << std::endl;
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

	void AppAlgorithm(void)
	{
		std::cout << "Test" << std::endl;
		ListManager::ListCreator list_creator;
		while (true)
		{
			FirstMenu();
			char ch;
			std::cout << "Select option: ";
			std::cin >> ch;

			switch (ch)
			{
			case 'a':
				list_creator.CreateTodoList();
				break;
			case 'b':
				list_creator.OpenTodoList();
				break;
			case 'q':
				std::cout << "All the best." << std::endl;
				exit(1);
				break;
			default:
				std::cout << "There is no such option!" << std::endl;
				continue;
			}

			ListManager::ListEditor list_editor(list_creator.GetListFile());
			list_editor.ShowList();

			while (ch != 'q')
			{
				std::cout << "Select option('h' for help): ";
				std::cin >> ch;

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

//namespace AppAlgorithm
//{
	// Быстро написал меню, для правильного проекта не хватило знаний
	/*void FirstMenu(void)
	{
		std::cout << "a. Create todo-list" << std::endl;
		std::cout << "b. Open todo-list" << std::endl;
		std::cout << "q. Exit" << std::endl;
	}

	void SecondMenu(void)
	{
		std::cout << "a. Add Task" << std::endl;
		std::cout << "b. Mark task as completed" << std::endl;
		std::cout << "c. Mark task as not completed" << std::endl;
		std::cout << "d. Delete task" << std::endl;
		std::cout << "q. Exit" << std::endl;
	}*/

	//void AppAlgorithm(void)
	//{
		//std::cout << "Test" << std::endl;
		//ListManager::ListCreator list_creator;
		//while (true)
		//{
			/*FirstMenu();
			char ch;
			std::cout << "Select option: ";
			std::cin >> ch;*/

			/*switch (ch)
			{
			case 'a':
				list_creator.CreateTodoList();
				break;
			case 'b':
				list_creator.OpenTodoList();
				break;
			case 'q':
				std::cout << "All the best." << std::endl;
				exit(1);
				break;
			default:
				std::cout << "There is no such option!" << std::endl;
				continue;
			}*/

			/*ListManager::ListEditor list_editor(list_creator.GetListFile());
			list_editor.ShowList();

			std::cout << "Select option('h' for help): ";
			std::cin >> ch;*/

			/*while (ch != 'q')
			{
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
				case 'q':
					std::cout << "List saved." << std::endl;
					break;
				default:
					std::cout << "Wrong choice! Input 'h' for help." << std::endl;
					break;
				}
			}*/
			//}
		//}
	//}