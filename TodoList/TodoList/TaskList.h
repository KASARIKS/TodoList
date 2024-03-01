#pragma once
#include "StartLibraryPack.h"

namespace TaskList
{
	class Task
	{
		std::string text;
		int is_completed;
		int id;
	public:
		Task(const std::string& text, int id);
		Task(const std::string& text, int id, int is_completed);

		std::string GetTask(void);
		friend std::ostream& operator<<(std::ostream& out, const Task& task);
		bool IsCompleted(void);
		void Complete(void);
		void UnComplete(void);
		int GetId(void);
		std::string GetFullTask(void);
	};

	// List with tasks
	typedef std::vector<Task> tasks_structure;

	class List
	{
		std::string name;
		tasks_structure tasks;
		int task_counter;
	public:
		List(const std::string& name);
		List(tasks_structure& tasks);

		tasks_structure& GetTasks(void);
		std::string GetName(void);
		List& AddTask(Task& task);
		List& AddTask(std::string task_text);
		List& DeleteTask(int id);
		List& CompleteTask(int id);
		List& UnCompleteTask(int id);
		void operator=(tasks_structure& tasks);
		void SetName(std::string name);
	};
}