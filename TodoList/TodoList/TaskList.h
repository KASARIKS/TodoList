#pragma once
#include "StartLibraryPack.h"

namespace TaskList
{
	class Task
	{
		std::string text;
		bool is_completed;
	public:
		Task(const std::string& text);

		std::string GetTask(void);
		friend std::ostream& operator<<(std::ostream& out, const Task& task);
		bool IsCompleted(void);
		void Complete(void);
	};

	// List with tasks
	typedef std::vector<Task> tasks_structure;

	class List
	{
		std::string name;
		tasks_structure tasks;
	public:
		List(const std::string& name);

		tasks_structure& GetTasks(void);
		std::string GetName(void);
		List& AddTask(Task& task);
		List& AddTask(std::string task_name);
	};
}