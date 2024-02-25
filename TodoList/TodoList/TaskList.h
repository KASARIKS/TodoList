#pragma once
#include <iostream>
#include <vector>
namespace TaskList
{
	class Task
	{
		std::string text;
		bool is_completed;
	public:
		Task(std::string text);

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
		List(std::string name);

		tasks_structure& GetTasks(void);
		std::string GetName(void);
		List& AddTask(Task& task);
		List& AddTask(std::string task_name);
	};
}