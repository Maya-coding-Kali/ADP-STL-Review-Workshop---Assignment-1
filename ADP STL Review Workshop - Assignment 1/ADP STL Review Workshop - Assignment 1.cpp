// ADP STL Review Workshop - Assignment 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Vector.h"
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;
void MainMenu();
void ListMenu();
void DequeMenu();
void MapsMenu();
void SetMenu();
void MultiSetMenu();
void MultiMapsMenu();
void StackMenu();
void QueueMenu();
void PriorityQueueMenu();
void printStack(stack<int> s);
void printQueue(queue<int> q);
int MenuChoice(string& Menu);
//int DataToStore();
int main()
{
	/*map<int, int> MyMap;
	MyMap.insert(pair<int, int>(1, 2));
	for (auto x : MyMap)
	{
		cout << x.first << ", " << x.second;
	}
	cout << MyMap[1];*/
	while (true)
	{
		MainMenu();
	}
	return 0; 
}
void MainMenu()
{
	string menu = "1) Vector\n2) List\n3) Deque\n4) Maps\n5) MultiMaps\n6) Sets\n7) Multisets\n8) Stack\n9) Queue\n10) Priority Queue\n"; 
	int choice = MenuChoice(menu);	
	// if vector, go to option 1
	if (choice == 1)
	{		
		cout << "Vector\n";
		MyVector<int> vect;
		vect.VectorMenu();
	}
	if (choice == 2)
	{
		cout << "List\n";
		ListMenu();
	}
	if (choice == 3)
	{
		cout << "Deque\n";
		DequeMenu();
	}
	if (choice == 4)
	{
		cout << "Map\n";
		MapsMenu();
	}
	if (choice == 5)
	{
		cout << "MultiMap\n";
		MultiMapsMenu();
	}
	if (choice == 6)
	{
		cout << "Set\n";
		SetMenu();
	}
	if (choice == 7)
	{
		cout << "MultiSet\n";
		MultiSetMenu();
	}
	if (choice == 8)
	{
		cout << "Stack\n";
		StackMenu();
	}
	if (choice == 9)
	{
		cout << "Queue\n";
		QueueMenu();
	}
	if (choice == 10)
	{
		cout << "Priority Queue\n";
		PriorityQueueMenu();
	}
}
int MenuChoice(string &Menu )
{
	int choice = 0;
	std::cout << "What function would you like to select?\n";
	cout << Menu;
	std::cin >> choice;
	return choice;
}
int DataToStore()
{
	int UserInput;
	std::cout << "\n--What data would you like to store?--\n";
	std::cin >> UserInput;
	return UserInput;
}
void ListMenu()
{
	std::list<int> MynewList;
	int choice;
	do {
		string menu = "1) Add Back\n2) Add front\n3) print\n4) Add an element to a specific location\n5)Show MyList size\n6) Access a particular Element in the MyList by using Iterator\n";
		choice = MenuChoice(menu);
		//Add an Element to the end of list - Done
		if (choice == 1)
		{
			std::cout << "You have chosen: \n Add an element to Back of List\n";
			int UserInput = DataToStore();
			MynewList.push_back(UserInput);
		}	
		//Add an element to the beginning of the list - done
		if (choice == 2)
		{
			std::cout << "You have chosen: \n Add an element to Front of List\n";
			int UserInput = DataToStore();
			MynewList.insert(MynewList.begin(), UserInput);
		}
		//Print the list using list iterator-Done
		if (choice == 3)
		{
			std::cout << "You have chosen: \nPrint\n";
			for (std::list<int>::iterator i = MynewList.begin(); i != MynewList.end(); ++i)
				cout << *i << " ";
			cout << "\n";
		}
		// Add an element to a specific location in the list - done//
		if (choice == 4)
		{
			std::cout << "You have chosen: \n Add an element to a specific location\n";
			int UserInput = DataToStore();
			std::cout << "Where would you like to store it?";
			int WhichIndex;
			cin >> WhichIndex;
			if (WhichIndex > MynewList.size() || WhichIndex < 0)
			{

				std::cout << "Slow down there champ we only have " << MynewList.size() << " Elements\n";
			}
			else
			{
				auto it = MynewList.begin();				
				it = MynewList.begin();
				std::advance(it, WhichIndex);
				MynewList.insert(it, UserInput);
			}
		}
		//Show Mylist’s size - done
		if (choice == 5)
		{
			std::cout << "We have " << MynewList.size() << " Elements\n";

		}
		// Access a particular Element in the MyList by using Iterator - Done
		if (choice == 6)
		{
			//using Iter = std::List<int>::const_iterator;
			int Value = 0;
			bool Found;
			cout << "what data would you like to find\n";
			cin >> Value;
			auto it = MynewList.begin();
			while( it != MynewList.end())
			{
				if (Value == *it)
				{
					Found = true;
					break;
				}
				++it;
			}
			if (Found)
			{
				cout << "You found the value " << *it << endl;
			}
			else
			{
				cout << "We cound not find the value" << endl;
			}
		}
		if (choice == 7)//Print the list using Copy Algorithm and otream iterator -Done
		{
			std::ostream_iterator<int> out_it(std::cout, ", ");
			std::copy(MynewList.begin(), MynewList.end(), out_it);
		}
	} while (choice != 12);

}
void DequeMenu()
{
	/*
		
		
		Access a Particular Element in the Deque by using[] operator*/

	std::deque<int> MynewDeque;
	int choice;
	do {
		string menu = "1) Add Back\n2) Add front\n3) print\n4)Show MyList size\n5) Access a particular Element in the MyList by using Iterator\n 6) Access a particular Element in the MyList by using []\n";
		choice = MenuChoice(menu);
		//Add an Element to the end of list - Done
		if (choice == 1)
		{
			std::cout << "You have chosen: \n Add an element to Back of Deque:\n";
			int UserInput = DataToStore();
			MynewDeque.push_back(UserInput);
		}
		//Add an element to the beginning of the list - done
		if (choice == 2)
		{
			std::cout << "You have chosen: \n Add an element to Front of Deque\n";
			int UserInput = DataToStore();
			MynewDeque.insert(MynewDeque.begin(), UserInput);
		}
		//Print the deque using deque iterator-Done
		if (choice == 3)
		{
			std::cout << "You have chosen: \n Print\n";
			for (std::deque<int>::iterator i = MynewDeque.begin(); i != MynewDeque.end(); ++i)
				cout << *i << " ";
			cout << "\n";
		}
		
		//Show Deques’s size - done
		if (choice == 4 )
		{
			std::cout << "We have " << MynewDeque.size() << " Elements\n";

		}
		// Access a particular Element in the Deque by using Iterator - Done
		if (choice == 5)
		{
			//using Iter = std::List<int>::const_iterator;
			int Value = 0;
			bool Found;
			cout << "what data would you like to find\n";
			cin >> Value;
			auto it = MynewDeque.begin();
			while (it != MynewDeque.end())
			{
				if (Value == *it)
				{
					Found = true;
					break;
				}
				++it;
			}
			if (Found)
			{
				cout << "You found the value " << *it << endl;
			}
			else
			{
				cout << "We cound not find the value" << endl;
			}
		}
		if (choice == 6)//Find specific item in deque sing [] -Done
		{
			bool Found = false;
			int valueIndex = 0;
			int Value;
			cout << "what data would you like to find\n";
			cin >> Value;
			for (int i = 0; i < MynewDeque.size(); i++)
			{
				if (MynewDeque[i] == Value)
				{
					valueIndex = i;
					Found = true;
				}
				 
			}
			if (Found)
			{
				cout << "You found the value " << MynewDeque[valueIndex] << " at " << valueIndex <<" index" << endl;
			}
			else
			{
				cout << "We cound not find the value" << endl;
			}
		}
	} while (choice != 12);
}
void MapsMenu()
{
	int choice = 0;
	map<int, string> MyMap;
	do
	{
		//Add an Element to the Map
		string menu = "1) Add Back\n2)Show You can not have the same value \n3) Print\n";
		choice = MenuChoice(menu);
		if (choice == 1)
		{
			cout << "\n--What data would you like to input?--\n";
			string UserString;
			int userNumber;
			cout << "String to input: ";
			cin >> UserString;
			cout << "Int to input: ";
			cin >> userNumber;
			MyMap.insert(pair<int, string>(userNumber, UserString));
		}
		if(choice == 2)
		{
			//Show that Multiple similar Mapped values are ignored ( By adding and printing) 
			cout << "\n--Watch how we input two of the same data and it doesnt add the second one?--\n";
			cout << "\n--What data would you like to input?--\n";
			string UserString;
			int userNumber;
			cout << "String to input: ";
			cin >> UserString;
			cout << "Int to input: ";
			cin >> userNumber;
			MyMap.insert(pair<int, string>(userNumber, UserString));
			MyMap.insert(pair<int, string>(userNumber, UserString));
			for (auto it : MyMap)
			{
				std::cout << it.first << " - " << it.second << '\n';
			}
		}
		if (choice == 3)
		{
			for (auto it : MyMap)
			{
				std::cout << it.first << " - " << it.second << '\n';

			}
		}
	} while (choice != 12);	
}
void MultiMapsMenu()
{
	int choice = 0;
	multimap<int, string> MyMap;
	do
	{
		//Add an Element to the Map
		string menu = "1) Add Back\n2)Show You can have the same value \n3) Print\n";
		choice = MenuChoice(menu);
		if (choice == 1)
		{
			cout << "\n--What data would you like to input?--\n";
			string UserString;
			int userNumber;
			cout << "String to input: ";
			cin >> UserString;
			cout << "Int to input: ";
			cin >> userNumber;
			MyMap.insert(pair<int, string>(userNumber, UserString));
		}
		if (choice == 2)
		{
			//Show that Multiple similar Mapped values are ignored ( By adding and printing) 
			cout << "\n--Watch how we input two of the same data and it doesnt add the second one?--\n";
			cout << "\n--What data would you like to input?--\n";
			string UserString;
			int userNumber;
			cout << "String to input: ";
			cin >> UserString;
			cout << "Int to input: ";
			cin >> userNumber;
			MyMap.insert(pair<int, string>(userNumber, UserString));
			MyMap.insert(pair<int, string>(userNumber, UserString));
			for (auto it : MyMap)
			{
				std::cout << it.first << " - " << it.second << '\n';
			}
		}
		if (choice == 3)
		{
			for (auto it : MyMap)
			{
				std::cout << it.first << " - " << it.second << '\n';

			}
		}
	} while (choice != 12);

}
void SetMenu()
{
	/*
		Add an Element to the Set 
		Show that Multiple similar Set values are ignored ( By adding and printing) 
		Printing the Set
	*/
	int choice = 0;
	set<int> MySet;
	do
	{
		//Add an Element to the Map
		string menu = "1) Add Back\n2)Show You can not have the same value \n3) Print\n";
		choice = MenuChoice(menu);
		if (choice == 1)
		{
			cout << "\n--What data would you like to input?--\n";			
			int userNumber;			
			cout << "Int to input: ";
			cin >> userNumber;
			MySet.insert(userNumber);
		}
		if (choice == 2)
		{
			//Show that Multiple similar Mapped values are ignored ( By adding and printing) 
			cout << "\n--Watch how we input two of the same data and it doesnt add the second one?--\n";
			cout << "\n--What data would you like to input?--\n";
			int userNumber;
			cout << "Int to input: ";
			cin >> userNumber;
			MySet.insert(userNumber);
			MySet.insert(userNumber);
			cout << userNumber << " has been input twice \n";
			for (auto it : MySet)
			{
				cout << it << ", ";
			}
			cout << "\n";
		}
		if (choice == 3)
		{
			for (auto it : MySet)
			{
				cout << it << ", ";
			}
			cout << "\n";
		}
	} while (choice != 12);
}
void MultiSetMenu()
{
	/*
		Add an Element to the Set
		Show that Multiple similar Set values are ignored ( By adding and printing)
		Printing the Set
	*/
	int choice = 0;
	multiset<int> MySet;
	do
	{
		//Add an Element to the Map
		string menu = "1) Add Back\n2)Show You can not have the same value \n3) Print\n";
		choice = MenuChoice(menu);
		if (choice == 1)
		{
			cout << "\n--What data would you like to input?--\n";
			int userNumber;
			cout << "Int to input: ";
			cin >> userNumber;
			MySet.insert(userNumber);
		}
		if (choice == 2)
		{
			//Show that Multiple similar Mapped values are ignored ( By adding and printing) 
			cout << "\n--Watch how we input two of the same data and it doesnt add the second one?--\n";
			cout << "\n--What data would you like to input?--\n";
			int userNumber;
			cout << "Int to input: ";
			cin >> userNumber;
			MySet.insert(userNumber);
			MySet.insert(userNumber);
			cout << userNumber << " has been input twice \n";
			for (auto it : MySet)
			{
				cout << it << ", ";
			}
			cout << "\n";
		}
		if (choice == 3)
		{
			for (auto it : MySet)
			{
				cout << it << ", ";
			}
			cout << "\n";
		}
	} while (choice != 12);
}
void StackMenu()
{
/*
Push into the Stack  
Pop from the Stack  
Print The Stack 
*/
	int choice = 0;
	stack<int> MyStack;
	do
	{
		//Add an Element to the Map
		string menu = "1) Push\n2)Pop \n3) Print\n";
		choice = MenuChoice(menu);
		if (choice == 1)
		{
			cout << "\n--What data would you like to input?--\n";
			int userNumber;
			cout << "Int to input: ";
			cin >> userNumber;
			MyStack.push(userNumber);
		}
		if (choice == 2)
		{
			//pop
			cout << "\n--You are about to remove data?--\n";
			MyStack.pop();	
		}
		if (choice == 3)
		{
			printStack(MyStack);
		}
	} while (choice != 12);
}
void printStack(stack<int> s) {
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";
}
void printQueue(queue<int> s) {
	while (!s.empty()) {
		cout << s.front() << " ";
		s.pop();
	}
	cout << "\n";
}
void printPQueue(priority_queue<int> s) {
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";
}
void QueueMenu()
{
	int choice = 0;
	queue<int> MyQueue;
	do
	{
		//Add an Element to the Map
		string menu = "1) Push\n2)Pop \n3) Print\n";
		choice = MenuChoice(menu);
		if (choice == 1)
		{
			cout << "\n--What data would you like to input?--\n";
			int userNumber;
			cout << "Int to input: ";
			cin >> userNumber;
			MyQueue.push(userNumber);
		}
		if (choice == 2)
		{
			//pop
			cout << "\n--You are about to remove data?--\n";
			MyQueue.pop();
		}
		if (choice == 3)
		{
			printQueue(MyQueue);
		}
	} while (choice != 12);
}
void PriorityQueueMenu()
{
	int choice = 0;
	priority_queue<int> MyPsAndQueues;
	do
	{
		//Add an Element to the Map
		string menu = "1) Push\n2)Pop \n3) Print\n";
		choice = MenuChoice(menu);
		if (choice == 1)
		{
			cout << "\n--What data would you like to input?--\n";
			int userNumber;
			cout << "Int to input: ";
			cin >> userNumber;
			MyPsAndQueues.push(userNumber);
		}
		if (choice == 2)
		{
			//pop
			cout << "\n--You are about to remove data?--\n";
			MyPsAndQueues.pop();
		}
		if (choice == 3)
		{
			printPQueue(MyPsAndQueues);
		}
	} while (choice != 12);
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
