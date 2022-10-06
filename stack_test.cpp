#include "stack.h"
#include <iostream>
using namespace std;

int main() {
	Stack<int> stack;
	stack.push(1);
	stack.push(3);
	stack.push(5);
	cout << "Size: ";
	cout << stack.size() <<endl;
	cout << "Top: " << stack.top() << endl;
	stack.pop();
	cout << "Top: " << stack.top() << endl;
	stack.pop();
	cout << "Top: " << stack.top() << endl;
	stack.pop();
	cout << "Top: " << stack.top() << endl;
	return 0;
}
	
