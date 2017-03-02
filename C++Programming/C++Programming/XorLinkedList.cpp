/*
* C++ Program To Implement XOR Linked List
*/
#include <iostream>
#include <cstdlib>
using namespace std;
/*
* Node Declaration
*/
struct node
{
	int data;
	struct node* npx;
}*headNd;

/*
* Class Declaration
*/
class xor_list
{
public:
	node* XOR(struct node *a, struct node *b);
	void insert(struct node **headNd_ref, int data);
	void display(struct node *headNd);
	xor_list()
	{
		headNd = NULL;
	}
};

/*
* Main Contains Menu
*/
int main21()
{
	xor_list xl;
	int choice, item;
	while (1)
	{
		cout << "\n-------------" << endl;
		cout << "Operations on XOR Linked List" << endl;
		cout << "\n-------------" << endl;
		cout << "1.Insert Element at First" << endl;
		cout << "2.Display List" << endl;
		cout << "3.Quit" << endl;
		cout << "Enter your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter value to be inserted: ";
			cin >> item;
			xl.insert(&headNd, item);
			break;
		case 2:
			xl.display(headNd);
			break;
		case 3:
			exit(1);
			break;
		default:
			cout << "Wrong Choice" << endl;
		}
	}
	return 0;
}

/*
* Returns XORed value of the node addressed
*/
node *xor_list::XOR(struct node *a, struct node *b)
{
	return (node*)((unsigned int)(a) ^ (unsigned int)(b));
}

/*
* Insert Node at Beginning
*/
void xor_list::insert(struct node **headNd_ref, int data)
{
	node *new_node = new (struct node);
	new_node->data = data;
	new_node->npx = XOR(*headNd_ref, NULL);
	if (*headNd_ref != NULL)
	{
		node* next = XOR((*headNd_ref)->npx, NULL);
		(*headNd_ref)->npx = XOR(new_node, next);
	}
	*headNd_ref = new_node;
}

// Display List
void xor_list::display(struct node *headNd)
{
	node *curr = headNd;
	node *prev = NULL;
	node *next;
	cout << "Elements of XOR Linked List: " << endl;
	while (curr != NULL)
	{
		cout << curr->data << " ";
		next = XOR(prev, curr->npx);
		prev = curr;
		curr = next;
	}
	cout << endl;
}