#include "ListFile.h"
#include <string>
#include <algorithm>

namespace ListFile
{
	// Надо брать за привычку работать с файлами в бинарном режиме
	// Постоянная проблема с форматированием строки с таском
	TaskList::Task TaskFromFile(std::ifstream& in)
	{
		std::string line;
		std::getline(in, line);

		if (line == "")
		{
			TaskList::Task task("", 0);
			return task;
		}
			

		TaskFileData str_task;
		str_task.id = line.substr(0, line.find(" "));
		str_task.text = std::string(line.begin() + str_task.id.length() + 1, line.end() - 2);
		str_task.is_completed = *(line.end() - 1);

		TaskList::Task task(str_task.text, std::stoi(str_task.id), std::stoi(str_task.is_completed));
		return task;
	}

	void ListFile::ReadList(void)
	{
		// Не очень хорошо наверное
		// Лучше бы было чтение при создании класса
		// А вообще лучше было бы унаследовать list, и тогда не нужно было бы трогать tasks_structure
		in.open(folder_path + list.GetName() + ".txt");
		TaskList::tasks_structure tmp_tasks;

		// Read task
		while (in.good())
		{
			TaskList::Task tmp_task = TaskFromFile(in);
			tmp_tasks.push_back(tmp_task);
		}

		// Костыль
		tmp_tasks.pop_back(); // Because last string empty

		list = tmp_tasks;

		in.clear();
		in.close();
	}

	void ListFile::WriteList(void)
	{
		out.open(folder_path + list.GetName() + ".txt");
		auto tasks = list.GetTasks();
		
		// Тоже костыль, скорость крадёт
		for (auto it = tasks.begin(); it != tasks.end(); ++it)
			if (it->GetTask() != "")
				out << it->GetFullTask() << std::endl;

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
	void ListFile::CreateList(void)
	{
		WriteList();
	}
}