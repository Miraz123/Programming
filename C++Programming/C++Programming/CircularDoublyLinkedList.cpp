/*
* C++ Program to Implement Circular Doubly Linked List
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

/*
* Node Declaration
*/
struct node
{
	int info;
	struct node *next;
	struct node *prev;
}*startNode, *lastNode;
int counter = 0;
/*
* Class Declaration
*/
class double_clist
{
public:
	node *create_node(int);
	void insert_begin();
	void insert_lastNode();
	void insert_pos();
	void delete_pos();
	void search();
	void update();
	void display();
	void reverse();
	void sort();
	double_clist()
	{
		startNode = NULL;
		lastNode = NULL;
	}
};

/*
* Main: Contains Menu
*/
int main18()
{
	int choice;
	double_clist cdl;
	while (1)
	{
		cout << "\n-------------------------------" << endl;
		cout << "Operations on Doubly Circular linked list" << endl;
		cout << "\n-------------------------------" << endl;
		cout << "1.Insert at Beginning" << endl;
		cout << "2.Insert at lastNode" << endl;
		cout << "3.Insert at Position" << endl;
		cout << "4.Delete at Position" << endl;
		cout << "5.Update Node" << endl;
		cout << "6.Search Element" << endl;
		cout << "7.Sort" << endl;
		cout << "8.Display List" << endl;
		cout << "9.Reverse List" << endl;
		cout << "10.Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cdl.insert_begin();
			break;
		case 2:
			cdl.insert_lastNode();
			break;
		case 3:
			cdl.insert_pos();
			break;
		case 4:
			cdl.delete_pos();
			break;
		case 5:
			cdl.update();
			break;
		case 6:
			cdl.search();
			break;
		case 7:
			cdl.sort();
			break;
		case 8:
			cdl.display();
			break;
		case 9:
			cdl.reverse();
			break;
		case 10:
			exit(1);
		default:
			cout << "Wrong choice" << endl;
		}
	}
	return 0;
}

/*
*MEMORY ALLOCATED FOR NODE DYNAMICALLY
*/
node* double_clist::create_node(int value)
{
	counter++;
	struct node *temp;
	temp = new(struct node);
	temp->info = value;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
/*
*INSERTS ELEMENT AT BEGINNING
*/
void double_clist::insert_begin()
{
	int value;
	cout << endl << "Enter the element to be inserted: ";
	cin >> value;
	struct node *temp;
	temp = create_node(value);
	if (startNode == lastNode && startNode == NULL)
	{
		cout << "Element inserted in empty list" << endl;
		startNode = lastNode = temp;
		startNode->next = lastNode->next = NULL;
		startNode->prev = lastNode->prev = NULL;
	}
	else
	{
		temp->next = startNode;
		startNode->prev = temp;
		startNode = temp;
		startNode->prev = lastNode;
		lastNode->next = startNode;
		cout << "Element inserted" << endl;
	}
}

/*
*INSERTS ELEMNET AT lastNode
*/
void double_clist::insert_lastNode()
{
	int value;
	cout << endl << "Enter the element to be inserted: ";
	cin >> value;
	struct node *temp;
	temp = create_node(value);
	if (startNode == lastNode && startNode == NULL)
	{
		cout << "Element inserted in empty list" << endl;
		startNode = lastNode = temp;
		startNode->next = lastNode->next = NULL;
		startNode->prev = lastNode->prev = NULL;
	}
	else
	{
		lastNode->next = temp;
		temp->prev = lastNode;
		lastNode = temp;
		startNode->prev = lastNode;
		lastNode->next = startNode;
	}
}
/*
*INSERTS ELEMENT AT POSITION
*/
void double_clist::insert_pos()
{
	int value, pos, i;
	cout << endl << "Enter the element to be inserted: ";
	cin >> value;
	cout << endl << "Enter the postion of element inserted: ";
	cin >> pos;
	struct node *temp, *s, *ptr;
	temp = create_node(value);
	if (startNode == lastNode && startNode == NULL)
	{
		if (pos == 1)
		{
			startNode = lastNode = temp;
			startNode->next = lastNode->next = NULL;
			startNode->prev = lastNode->prev = NULL;
		}
		else
		{
			cout << "Position out of range" << endl;
			counter--;
			return;
		}
	}
	else
	{
		if (counter < pos)
		{
			cout << "Position out of range" << endl;
			counter--;
			return;
		}
		s = startNode;
		for (i = 1; i <= counter; i++)
		{
			ptr = s;
			s = s->next;
			if (i == pos - 1)
			{
				ptr->next = temp;
				temp->prev = ptr;
				temp->next = s;
				s->prev = temp;
				cout << "Element inserted" << endl;
				break;
			}
		}
	}
}
/*
* Delete Node at Particular Position
*/
void double_clist::delete_pos()
{
	int pos, i;
	node *ptr= NULL, *s;
	if (startNode == lastNode && startNode == NULL)
	{
		cout << "List is empty, nothing to delete" << endl;
		return;
	}
	cout << endl << "Enter the postion of element to be deleted: ";
	cin >> pos;
	if (counter < pos)
	{
		cout << "Position out of range" << endl;
		return;
	}
	s = startNode;
	if (pos == 1)
	{
		counter--;
		lastNode->next = s->next;
		s->next->prev = lastNode;
		startNode = s->next;
		free(s);
		cout << "Element Deleted" << endl;
		return;
	}
	for (i = 0; i < pos - 1; i++)
	{
		s = s->next;
		ptr = s->prev;
	}
	ptr->next = s->next;
	s->next->prev = ptr;
	if (pos == counter)
	{
		lastNode = ptr;
	}
	counter--;
	free(s);
	cout << "Element Deleted" << endl;
}
/*
* Update value of a particular node
*/
void double_clist::update()
{
	int value, i, pos;
	if (startNode == lastNode && startNode == NULL)
	{
		cout << "The List is empty, nothing to update" << endl;
		return;
	}
	cout << endl << "Enter the postion of node to be updated: ";
	cin >> pos;
	cout << "Enter the new value: ";
	cin >> value;
	struct node *s;
	if (counter < pos)
	{
		cout << "Position out of range" << endl;
		return;
	}
	s = startNode;
	if (pos == 1)
	{
		s->info = value;
		cout << "Node Updated" << endl;
		return;
	}
	for (i = 0; i < pos - 1; i++)
	{
		s = s->next;
	}
	s->info = value;
	cout << "Node Updated" << endl;
}
/*
* Search Element in the list
*/
void double_clist::search()
{
	int pos = 0, value, i;
	bool flag = false;
	struct node *s;
	if (startNode == lastNode && startNode == NULL)
	{
		cout << "The List is empty, nothing to search" << endl;
		return;
	}
	cout << endl << "Enter the value to be searched: ";
	cin >> value;
	s = startNode;
	for (i = 0; i < counter; i++)
	{
		pos++;
		if (s->info == value)
		{
			cout << "Element " << value << " found at position: " << pos << endl;
			flag = true;
		}
		s = s->next;
	}
	if (!flag)
		cout << "Element not found in the list" << endl;
}
/*
* Sorting Doubly Circular Link List
*/
void double_clist::sort()
{
	struct node *temp, *s;
	int value, i;
	if (startNode == lastNode && startNode == NULL)
	{
		cout << "The List is empty, nothing to sort" << endl;
		return;
	}
	s = startNode;
	for (i = 0; i < counter; i++)
	{
		temp = s->next;
		while (temp != startNode)
		{
			if (s->info > temp->info)
			{
				value = s->info;
				s->info = temp->info;
				temp->info = value;
			}
			temp = temp->next;
		}
		s = s->next;
	}
}
/*
* Display Elements of the List
*/
void double_clist::display()
{
	int i;
	struct node *s;
	if (startNode == lastNode && startNode == NULL)
	{
		cout << "The List is empty, nothing to display" << endl;
		return;
	}
	s = startNode;
	for (i = 0; i < counter - 1; i++)
	{
		cout << s->info << "<->";
		s = s->next;
	}
	cout << s->info << endl;
}
/*
* Reverse Doubly Circular Linked List
*/
void double_clist::reverse()
{
	if (startNode == lastNode && startNode == NULL)
	{
		cout << "The List is empty, nothing to reverse" << endl;
		return;
	}
	struct node *p1, *p2;
	p1 = startNode;
	p2 = p1->next;
	p1->next = NULL;
	p1->prev = p2;
	while (p2 != startNode)
	{
		p2->prev = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p2->prev;
	}
	lastNode = startNode;
	startNode = p1;
	cout << "List Reversed" << endl;
}