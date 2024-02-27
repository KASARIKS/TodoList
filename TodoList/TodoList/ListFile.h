#pragma once
#include "TaskList.h"
#include <fstream>

// Save and read txt file
namespace ListFile
{
	const std::string folder_path("Lists\\");
	class ListFile
	{
		TaskList::List list;
		std::ifstream in;
		std::ofstream out;

		// This methods add .txt to the end of file path
		void ReadList(void);
		void WriteList(void);
	public:
		ListFile(std::string list_name);
		TaskList::List& GetList(void);
		void SaveList(const TaskList::List& list);
	};
}