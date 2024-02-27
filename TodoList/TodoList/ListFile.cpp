#include "ListFile.h"
#include <string>

namespace ListFile
{
	void ListFile::ReadList(void)
	{
		in.open(folder_path + list.GetName() + ".txt");

		while (in.good())
		{
			std::string line;
			std::getline(in, line);
			list.AddTask(line);
		}

		in.clear();
		in.close();
	}

	void ListFile::WriteList(void)
	{
		out.open(folder_path + list.GetName() + ".txt");
		auto tasks = list.GetTasks();
		
		for (auto it = tasks.begin(); it != tasks.end(); ++it)
			if (it->GetTask() != "")
				out << it->GetTask() << std::endl;

		out.clear();
		out.close();
	}

	ListFile::ListFile(std::string list_name) : list(list_name)
	{	
	}

	TaskList::List& ListFile::GetList(void)
	{
		ReadList();
		return this->list;
	}

	void ListFile::SaveList(const TaskList::List& list)
	{
		this->list = list;
		WriteList();
	}
}