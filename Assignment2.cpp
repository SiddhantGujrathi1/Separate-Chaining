/*
	Problem Statement:
	Implement all the functions of a dictionary (ADT) using Seperate Chaining.
	Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable.
	Keys must be unique. Standard Operations: Insert(key, value), Find(key), Delete(key).
============================================================================
Name : Assignment_2.cpp
Author : Gujrathi Siddhant
============================================================================*/
#include <iostream>
#include <vector>
using namespace std;
class SeperateHash
{
public:
	int n;
	vector<vector<int>> v;
	SeperateHash(int n)
	{
		v = vector <vector<int>> (n);
		this->n = n;
	}
	int getHashIndex(int x);
	void add(int x);
	void del(int x);
	void displayHash();
	int NPresent(int x);
};
/*-----------------------------------------------------
				To get the index of key
-------------------------------------------------------*/
int SeperateHash::getHashIndex(int x)
{
	return x % n;
}
/*-----------------------------------------------------
			To insert element in hash table
-------------------------------------------------------*/
void SeperateHash::add(int x)
{
		// Adding the element according to hash index
		v[getHashIndex(x)].push_back(x);
}
/*-----------------------------------------------------
To delete element in hash table
-------------------------------------------------------*/
void SeperateHash::del(int x)
{
	int i = getHashIndex(x);
	for (int j = 0; j < (int)v[i].size(); j++)
	{
		if (v[i][j] == x)
		{
			v[i].erase(v[i].begin() + j);
			cout << x << " deleted!" << endl;
			return;
		}
	}
	cout << "No Element Found!" << endl;
}
/*-----------------------------------------------------
			To display the hash table
-------------------------------------------------------*/
void SeperateHash::displayHash()
{
	// Display the contents
	for (int i = 0; i < n; i++)
	{
		cout << i;
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << " -> " << v[i][j];
		}
		cout << endl;
	}
}
int main()
{
char ch;
	int arr[10];
	SeperateHash obj(10);
do
{
int choice;
cout<<"\n1.Insert Element\n2.Find Key\n3.Display Element.\n4.Delete Element\nEnter your choice: ";
cin>>choice;
// Sending the size for separate chaining
switch(choice)
{
case 1:
int num;
	 cout<<"Enter the total number of elements to be added\n";
	 cin>>num;
	 for(int i=0;i<num;i++)
	 {
	 cout<<"Enter Element: ";
	 cin>>arr[i];
	 for(int j=0;j<i;j++)
	 {
	 	if(arr[i]==arr[j])
	 	{
	 		cout<<"\nDuplicate entries are not allowed";
	 		i--;
	 		continue;
	 	}
	 }
	 }
	 for (int i = 0; i < num; i++)
		 obj.add(arr[i]); // Inserting elements in the container accordingly
		 break;
		 case 2:
		 int key1;
		 cout<<"\nEnter the key to find: ";
		 cin>>key1;
		 cout<<"\nIndex of key is "<<obj.getHashIndex(key1);
		 break;
		 case 3:
		 obj.displayHash();
		 break;
		 case 4:
		 int key2;
		 cout<<"\nEnter the key to delete: ";
		 cin>>key2;
		 obj.del(key2);
	 cout <<endl;
	 break;
	 default:
	 cout<<"\nPlease Enter the valid choice..";
}
cout<<"\nDo you want to continue??(y/n)";
cin>>ch;
}while(ch=='y' or ch=='Y');
	return 0;
}

