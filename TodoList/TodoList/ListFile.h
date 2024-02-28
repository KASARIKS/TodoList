#pragma once
#include "TaskList.h"
#include <fstream>
#include <string>

// Save and read txt file
namespace ListFile
{
	const std::string folder_path("Lists\\");
	struct TaskFileData
	{
		std::string id, text, is_completed;
	};

	TaskList::Task TaskFromFile(std::ifstream& in);

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
		void CreateList(void);
	};
}