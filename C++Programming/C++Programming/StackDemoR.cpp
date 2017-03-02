#include <iostream>
using namespace std;

struct node {
	int data;
	struct node *next;
};

class stackDemo {

	struct node *top;
public:
	stackDemo() {
		top = NULL;
	}

	void push();
	void pop();
	void display();

};

void stackDemo::push()
{
	int data;
	struct node *ptr;
	
	cout << "enter any data to insert into stack"<<endl;
	cin >> data;
	ptr = new node;
	ptr->data = data;
	ptr->next = NULL;

	if (top != NULL) {
		ptr->next = top;
	}
	top = ptr;
	cout << "New item is inserted to the stack!!!" << endl;
}

void stackDemo::pop()
{
	struct node *temp;

	if (top == NULL) {
		cout << "the stack is already underflow"<<endl;
	}
	temp = top;
	top = temp->next;
	cout << "the object " << temp->data << " is poped from stack";
	delete temp;

}

void stackDemo::display()
{
	struct node *ptr;
	ptr = top;
	cout << "The stack data is : ";
	while(ptr != NULL) {
		cout << ptr->data<<" ->";
		ptr = ptr->next;
	}
	cout << "NULL" << endl;
}

int mainr1() {

	int choice;
	stackDemo stack;

	while (true)
	{
		cout << "\n-----------------------------------------------------------" << endl;
		cout << "\t\tSTACK USING LINKED LIST\n" << endl;
		cout << "1:PUSH\n2:POP\n3:DISPLAY STACK\n4:EXIT" << endl;
		cout << "\nEnter your choice(1-4): " << endl;
		cin >> choice;

			switch (choice) {
				case 1:
					stack.push();
					break;
				case 2:
					stack.pop();
					break;
				case 3:
					stack.display();
					break;
				case 4:
					return 0;
					break;
				default:
					cout << "please enter correct value from (1-4)";
		
			}
	}

	getchar();
	return 0;
}