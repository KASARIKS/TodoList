#pragma once
#include "Menu.h"
#include "ListFile.h"

namespace ListManager
{
	//using Menu::Option;

	int InputId(void);

	class ListEditor
	{
		ListFile::ListFile current;
	public:
		ListEditor(ListFile::ListFile& current);
		
		void AddTask(void);
		void MarkTask(bool complete);
		void DeleteTask(void);
		void ClearList(void);
		void ShowList(void);
	};

	typedef std::vector<TaskList::tasks_structure> lists;

	class ListCreator
	{	
		std::string name;
		ListFile::ListFile current;
	public:
		ListCreator();
		
		void Input(void);
		void CreateTodoList(void);
		void OpenTodoList(void);
		void Exit(void);
		ListFile::ListFile& GetListFile(void);
	};
}