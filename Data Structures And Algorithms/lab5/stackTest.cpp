#include "stack.h"

#define prettyPrint(value) (value?"Yes":"No")

/*
Görkem Ertaþ
20070006004
*/

// Example input   -> "a+b*c+(d*e+f)*g"
// Expected output -> "abc*+de*f+g*+"
string inFixToPostFix(string word) {
    Stack<char> stack = Stack<char>(word.length());
    string result;
    return result;
// Some operations
}


int main() {
    Stack<int> numbers = Stack<int>(3);
    cout << "Is stack empty ? " << prettyPrint(numbers.isEmpty()) << endl;
    cout << "Is stack full ? " << prettyPrint(numbers.isFull()) << endl;
    numbers.push(1);
    cout << "Is test case 1 correct ? : " << prettyPrint(numbers.isEmpty() == false) << endl;
    int value = numbers.pop();
    cout << "Is test case 2 correct ? : " << prettyPrint(numbers.isEmpty() == true) << endl;
    cout << "Is test case 3 correct ? :" << prettyPrint(value == 1) << endl;
    numbers.push(1);
    numbers.push(2);
    numbers.push(3);
    cout << "Is test case 4 correct ? :" << prettyPrint(numbers.isFull()) << endl;
    numbers.push(4);
    cout << "Is test case 5 correct ? :" << prettyPrint(numbers.getTopIndex() == 2) << endl;
	cout << "Is test case 7 correct ? :" << prettyPrint(inFixToPostFix("a+b*c+(d*e+f)*g") == "abc*+de*f+g*+") << endl;
    return 0;
}
