#include "TaskList.h"
#include <string>

namespace TaskList
{
	// Task methods
	Task::Task(const std::string& text, int id) : text(text)
	{
		is_completed = 0;
		this->id = id;
	}

	Task::Task(const std::string& text, int id, int is_completed) : text(text)
	{
		this->is_completed = is_completed;
		this->id = id;
	}

	std::string Task::GetTask(void)
	{
		return text;
	}

	std::string Task::GetFullTask(void)
	{
		return std::to_string(id) + " " + text + " " + std::to_string(is_completed);
	}

	bool Task::IsCompleted(void)
	{
		return is_completed;
	}

	void Task::Complete(void)
	{
		is_completed = true;
	}

	void Task::UnComplete(void)
	{
		is_completed = false;
	}

	std::ostream& operator<<(std::ostream& out, const Task& task)
	{
		out << task.id << " " << task.text << " " << (task.is_completed == 1 ? "<Completed>" : "<Not completed>");
		return out;
	}

	int Task::GetId(void)
	{
		return id;
	}

	// List methods
	List::List(const std::string& name) : name(name), tasks() 
	{
		this->task_counter = 1;
	}

	List::List(tasks_structure& tasks)
	{
		this->tasks = tasks;
		task_counter = std::max_element(tasks.begin(), tasks.end(), [](TaskList::Task t1, TaskList::Task t2) {
			return t1.GetId() > t2.GetId();
			})->GetId();
	}

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
		++task_counter;
		return *this;
	}

	List& List::AddTask(std::string task_text)
	{
		tasks.push_back(Task(task_text, task_counter));
		++task_counter;
		return *this;
	}
	List& List::DeleteTask(int id)
	{
		// find element
		auto el = tasks.begin();
		for (; el != tasks.end(); ++el)
			if (el->GetId() == id)
			{
				tasks.erase(el);
				break;
			}

		// Maybe not need
		/*if (el == tasks.end() && el->GetId() == id)
			tasks.erase(el);*/

		return *this;
	}

	List& List::CompleteTask(int id)
	{
		for (auto it = tasks.begin(); it != tasks.end(); ++it)
			if (id == it->GetId())
				it->Complete();
		return *this;
	}

	List& List::UnCompleteTask(int id)
	{
		for (auto it = tasks.begin(); it != tasks.end(); ++it)
			if (id == it->GetId())
				it->UnComplete();
		return *this;
	}
	
	void List::operator=(tasks_structure& tasks)
	{
		this->tasks = tasks;
		if (tasks.size() > 1)
			task_counter = std::max_element(tasks.begin(), tasks.end(), [](TaskList::Task t1, TaskList::Task t2) {
			return t1.GetId() < t2.GetId();
				})->GetId() + 1;
		else if (tasks.size() > 0)
			task_counter = tasks.begin()->GetId() + 1;
		else
			task_counter = 1;
	}
	void List::SetName(std::string name)
	{
		this->name = name;
	}
	void List::Clear(void)
	{
		tasks.clear();
		task_counter = 1;
	}
}