#pragma once
#include "Menu.h"
#include "ListFile.h"

namespace ListManager
{
	using Menu::Option;

	class ListEditor
	{
	public:
		ListEditor();

		void AddTask(void);
		void MarkTask(bool complete);
		void DeleteTask(void);
		void ClearList(void);
		void ShowList(void);
		void Exit(void);
	};

	class ListCreator
	{	
	public:
		ListCreator();

		void CreateTodoList(void);
		void OpenTodoList(void);
		void Exit(void);
	};
}