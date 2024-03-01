#include "ListManager.h"
#include <iostream>

namespace ListManager
{
	// ListCreator Mehtods
	
	ListCreator::ListCreator() : current("")
	{

	}

	void ListCreator::Input(void)
	{
		std::cout << "Input name of todo-list: ";
		std::cin >> name;
	}

	void ListCreator::CreateTodoList(void)
	{
		Input();
		current.SetName(name);
		current.CreateList();
	}

	void ListCreator::OpenTodoList(void)
	{
		Input();
		current.SetName(name);
	}

	void ListCreator::Exit(void)
	{
		std::cout << "All the best." << std::endl;
	}

	ListFile::ListFile& ListCreator::GetListFile(void)
	{
		return current;
	}

	// ListEditor Methods
	ListEditor::ListEditor(ListFile::ListFile& current) : current(current)
	{
	}

	void ListEditor::AddTask(void)
	{
		std::string task_text;
		std::cout << "Input task: ";
		std::getline(std::cin >> std::ws, task_text);
		
		auto tmp = current.GetList();

		tmp.AddTask(task_text);
		current.SaveList(tmp);
	}

	void ListEditor::MarkTask(bool complete)
	{
		int id = InputId();

		auto tmp = current.GetList();
		
		if (complete)
			tmp.CompleteTask(id);
		else
			tmp.UnCompleteTask(id);

		current.SaveList(tmp);
	}

	void ListEditor::DeleteTask(void)
	{
		int id = InputId();
		auto tmp = current.GetList();
		tmp.DeleteTask(id);
		current.SaveList(tmp);
	}

	void ListEditor::ShowList(void)
	{
		auto output_current = current.GetList().GetTasks();
		std::cout << current.GetList().GetName() << std::endl;
		for (auto it = output_current.begin(); it != output_current.end(); ++it)
			std::cout << *it << std::endl;
	}

	// Functions-helpers

	int InputId(void)
	{
		int id;
		std::cout << "Input id: ";
		std::cin >> id;
		return id;
	}

}