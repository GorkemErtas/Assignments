#include <iostream>

using namespace std;

template<class T>
class Stack {
private:
    int top;
    int size;
    T *elements;
public:
    Stack(int size) {
        this->size = size;
        elements = new T[size];
        top = -1;
        for (int i = 0; i < size; i++) {
            elements[i] = NULL;
        }
    }

    int getTopIndex() {
        return top;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == (size - 1);
    }

    void printStack() {
        cout << "Stack = {" << endl;
        for (int i = 0; i <= top; i++) {
            cout << elements[i] << ",";
        }
        cout << "} " << endl;
    }

    void clear() {
        delete[] elements;
    }

    // Fill the function and add necessary control statements to prevent program crash
    void push(T element) {
		if(top==size-1){
			cout<<"The stack is full"<<endl;
			return;
		}
		if(top<size){
			top++;
			elements[top]=element;
		}
    }

    // Fill the function and add necessary control statements to prevent program crash
    T pop() {
    	if(top=0){
    		cout<<"The stack is empty."<<endl;
    		return NULL;
		}
		else{
			T element=elements[top];
			elements[top]=NULL;
			top=top-1;
			return element;
		}
    }
};
