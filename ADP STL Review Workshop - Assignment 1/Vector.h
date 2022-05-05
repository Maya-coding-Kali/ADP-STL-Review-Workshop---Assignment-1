#pragma once
#include <iostream>
#include <vector>
using namespace std;
template<class T>
class MyVector
{
public:
	MyVector();
	MyVector(std::vector<T>& vect);
	~MyVector();
	void VectorMenu();
private:
	int MenuChoice(string& Menu);
	int DataToStore();
	void AddAnElementToTheEndOfVector();
	void AddAnElementToTheFrontOfVector();
	void AddAtSpecificLocation();
	void AccessElementUsingIterator();
	void AccessElementUsingSubscript();
	void Print();
	std::vector<T> MynewVector;
};
template<class T>
MyVector<T>::MyVector()
{
	MynewVector = {};
}
template<class T>
MyVector<T>::MyVector(std::vector<T>& vect)
{
	MynewVector = vect;
}
template<class T>
MyVector<T>::~MyVector()
{
	cout << "It was destroyed!! Victory Is Mine!";
}
template<class T>
int MyVector<T>::MenuChoice(string& Menu)
{
	int choice = 0;
	std::cout << "What would you like to select?\n";
	cout << Menu;
	std::cin >> choice;
	return choice;
}
template<class T>
void MyVector<T>::AddAnElementToTheEndOfVector()
{
	std::cout << "You have chosen: \n Add an element to Back of Vector\n";
	int UserInput = DataToStore();
	MynewVector.push_back(UserInput);
}
template<class T>
void MyVector<T>::AddAnElementToTheFrontOfVector()
{
	std::cout << "You have chosen: \n Add an element to Front of Vector\n";
	int UserInput = DataToStore();
	MynewVector.insert(MynewVector.begin(), UserInput);
}
template<class T>
void MyVector<T>::Print()
{
	std::cout << "You have chosen: \n Print\n";
	for (auto i = MynewVector.begin(); i != MynewVector.end(); ++i)
		cout << *i << " ";
}
template<class T>
void MyVector<T>::AddAtSpecificLocation()
{
	std::cout << "You have chosen: \n Add an element to a specific location\n";
	int UserInput = DataToStore();
	std::cout << "Where would you like to store it?";
	int WhichIndex;
	cin >> WhichIndex;
	if (WhichIndex > MynewVector.size() || WhichIndex < 0)
	{

		std::cout << "Slow down there champ we only have " << MynewVector.size() << " Elements\n";
	}
	else
	{
		MynewVector.insert(MynewVector.begin() + WhichIndex, UserInput);
	}
}
template<class T>
int MyVector<T>::DataToStore()
{
	int UserInput;
	std::cout << "What data would you like to store?";
	std::cin >> UserInput;
	return UserInput;
}
template<class T>
void MyVector<T>::AccessElementUsingIterator()
{
	using Iter = std::vector<int>::const_iterator;
	int index = 0;
	cout << "what index would you like to find\n";
	cin >> index;
	for (Iter it = MynewVector.begin(); it != MynewVector.end(); ++it) {
		if (index == *it)
		{
			cout << *it << endl;
		}
	}
}
template<class T>
void MyVector<T>::AccessElementUsingSubscript()
{
	int index = 0;
	cout << "what index would you like to find\n";
	cin >> index;
	cout << MynewVector[index] << endl;
}
template<class T>
void MyVector<T>::VectorMenu()
{
	int choice;
	do {
		string menu = "1) Add Back\n2) Add front\n3) print\n4) Add an element to a specific location\n5)Show MyVector size\n6) Access a particular Element in the MyVector by using Iterator\n7) Access using subscript[]";
		choice = MenuChoice(menu);

		if (choice == 1)
		{
			AddAnElementToTheEndOfVector();
		}
		if (choice == 2)
		{
			AddAnElementToTheFrontOfVector();
		}
		if (choice == 3)
		{
			Print();
		}
		if (choice == 4)//Add an element to a specific location in the MyVector
		{
			AddAtSpecificLocation();
		}
		if (choice == 5)//Show MyVector’s size
		{
			std::cout << "We have " << MynewVector.size() << " Elements\n";
		}
		if (choice == 6)// Access a particular Element in the MyVector by using Iterator
		{
			AccessElementUsingIterator();
		}
		if (choice == 7)//Access a Particular Element in the MyVector by using[] operator)
		{
			AccessElementUsingSubscript();
		}
	} while (choice != 12);
}
//void MyVector::AddAnElementToTheEndOfVector()
//{
//		
//}
