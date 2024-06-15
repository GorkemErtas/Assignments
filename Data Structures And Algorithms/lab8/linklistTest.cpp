#include "linklist.h"

#define prettyPrint(value) (value?"Yes":"No")

int main() {
    LinkListNode<int> *node_1 = new LinkListNode<int>(1);
    LinkListNode<int> *node_2 = new LinkListNode<int>(2);
    LinkListNode<int> *node_3 = new LinkListNode<int>(3);
    LinkListNode<int> *node_4 = new LinkListNode<int>(4);
    LinkList<int> linklist = LinkList<int>();
    linklist.insertFirst(node_1); // Linklist : 1->
    cout << "Is test case 1 correct ? : " << prettyPrint(linklist.isEmpty() == false) << endl;
    cout << "Is test case 2 correct ? : " << prettyPrint(linklist.topElement()->data == 1) << endl;
    linklist.insertLast(node_2); // Linklist : 1->2
    linklist.insertLast(node_3); // Linklist : 1->2->3
    cout << "Is test case 3 correct ? : " << prettyPrint(linklist.topElement()->data == 3) << endl;
    cout << "Is test case 4 correct ? : " << prettyPrint(linklist.removeElement(2)->data == 2)
         << endl; // Linklist : 1->3
    linklist.insert(node_4, 1); // Linklist : 1->4->3
    cout << "Is test case 5 correct ? : " << prettyPrint(linklist.topElement()->data == 3) << endl;
    cout << "Is test case 6 correct ? : " << prettyPrint(linklist.getHead()->next->data == 4) << endl;
    linklist.clear();
    return 0;
}