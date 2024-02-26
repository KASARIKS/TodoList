#include "TaskList.h"

namespace TaskList
{
	// Task methods
	Task::Task(const std::string& text) : text(text), is_completed(0) {}

	std::string Task::GetTask(void)
	{
		return text;
	}

	bool Task::IsCompleted(void)
	{
		return is_completed;
	}

	void Task::Complete(void)
	{
		is_completed = true;
	}

	std::ostream& operator<<(std::ostream& out, const Task& task)
	{
		out << task.text;
		return out;
	}

	// List methods
	List::List(const std::string& name) : name(name), tasks() {}

	tasks_structure& List::GetTasks(void)
	{
		return tasks;
	}

	std::string List::GetName(void)
	{
		return name;
	}

	List& List::AddTask(Task& task)
	{
		tasks.push_back(task);
		return *this;
	}

	List& List::AddTask(std::string task_name)
	{
		tasks.push_back(Task(task_name));
		return *this;
	}
}