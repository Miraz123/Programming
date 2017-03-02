#include <iostream>

using namespace std;

void swapcallbyvalue(int a, int b);
void swapcallbyreference(int &a, int &b);
void swapcallbypointer(int *a, int *b);
int main1() {

	//------------------------------------------------------------------------------------
	int var1 = 10;
	int& var2 = var1;

	// var2 is just reference variable , and it work as alias
	//it only reference the var1 , it never allocate new memory for var2

	cout << "first variable " << var1 << endl;
	cout << "second variable " << var2 << endl;
	var2 = 29;
	cout << "first variable " << var1 << endl;
	// output : var1 : 29

	//------------------------------------------------------------------------------------

	int *varadd = &var1;

	cout << "var1 value ::" << *varadd << endl;
	cout << "var1 address ::" << varadd << endl;
	cout << "address  of pointer::" << &varadd << endl;

	//------------------------------------------------------------------------------------

	int arr[] = { 10, 11, 34 };
	cout << "arr::" << arr << endl;
	cout << "arr[0]::" << &arr[0] << endl;
	cout << "*(arr)::" << *(arr) << endl;
	cout << "*(arr+0)::" << *(arr + 0) << endl;
	cout << "*(arr+1)::" << *(arr + 1) << endl;
	cout << "*(arr+2)::" << *(arr + 2) << endl;

	cout << "arr[0] + arr[1]::" << *(arr + 0) + *(arr + 1) << endl;
	//------------------------------------------------------------------------------------

	int **vartwp = &varadd;

	cout << "var1 value ::" << **vartwp << endl;
	cout << "address  of pointer::" << &vartwp << endl;

	//------------------------------------------------------------------------------------
	int a = 2;
	int b = 3;
	swapcallbyvalue(a, b);
	cout << "call by value a :: b" << a << " ::" << b << endl;
	swapcallbyreference(a, b);
	cout << "call by reference a :: b" << a << " ::" << b << endl;
	swapcallbypointer(&a, &b);
	cout << "call by pointer a :: b" << a << " ::" << b << endl;

	//------------------------------------------------------------------------------------

	int *add[3] = { &arr[0],&arr[1],&arr[2] };
	// add is array of three integer pointer

	char *names[] = { "Miller","Jones","Anderson" };
	cout << "the value is *(*(names + 1) + 2)  %c : " << *(*(names + 1) + 2) << endl;
	cout << "the value is names[1][2]  %c : " << names[1][2] << endl;



	getchar();
	return 0;
}

void swapcallbyvalue(int a, int b) {

	int temp;
	temp = a;
	a = b;
	b = temp;

}

void swapcallbyreference(int &a, int &b) {

	int temp;
	temp = a;
	a = b;
	b = temp;
}


void swapcallbypointer(int *a, int *b) {

	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}
