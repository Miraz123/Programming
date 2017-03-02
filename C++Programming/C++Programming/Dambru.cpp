//* * * * *
//	* * *						* * *
//	  *			user = 2 ,        *		user = 1 ,  * user = 0
//	* * *						* * *
//* * * * *

#include <iostream>

using namespace std;

void main() {
	int data;
	cout << "please enter the data : ";
	cin >> data;

	for (int i = data; i >= -data; i--) {
		cout << endl;
		for (int space = abs(i) * 2 + 1; space <=(data * 2 + 1); space++) {
			cout << " ";
		}
		for (int inner = abs(i) * 2 + 1; inner > 0 ; inner --) {
			cout << "* ";
		}
		
	}

	cin >> data;
}