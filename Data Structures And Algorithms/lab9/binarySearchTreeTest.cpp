#include "binarySearchTree.h"

#define prettyPrint(value) (value?"Yes":"No")

int main() {
    TreeNode<int> *node_1 = new TreeNode<int>(24);
    TreeNode<int> *node_2 = new TreeNode<int>(13);
    TreeNode<int> *node_3 = new TreeNode<int>(45);
    TreeNode<int> *node_4 = new TreeNode<int>(10);
    TreeNode<int> *node_5 = new TreeNode<int>(32);
    TreeNode<int> *node_6 = new TreeNode<int>(54);
    TreeNode<int> *node_7 = new TreeNode<int>(12);
    TreeNode<int> *node_8 = new TreeNode<int>(15);
    BST<int> bst = BST<int>();
    bst.iterativeInsert(node_1);
    bst.recursiveInsert(bst.getRoot(), node_2);
    bst.iterativeInsert(node_3);
    bst.recursiveInsert(bst.getRoot(), node_4);
    bst.iterativeInsert(node_5);
    bst.recursiveInsert(bst.getRoot(), node_6);
    bst.iterativeInsert(node_7);

    cout << "Is test case 1 correct ? :" << prettyPrint(bst.getRoot()->data == 24) << endl;
    cout << "Is test case 2 correct ? :" << prettyPrint(bst.getRoot()->left->left->data == 10) << endl;
    cout << "Is test case 3 correct ? :" << prettyPrint(bst.getRoot()->right->right->data == 54) << endl;
    cout << "Is test case 4 correct ? :" << prettyPrint(bst.getRoot()->right->left->data == 32) << endl;
    bst.print(bst.getRoot());
    bst.deleteNode(32);
    cout << "Is test case 5 correct ? :" << prettyPrint(bst.getRoot()->right->left == NULL) << endl;
    bst.deleteNode(45);
    cout << "Is test case 6 correct ? :" << prettyPrint(bst.getRoot()->right->data == 54) << endl;
    bst.iterativeInsert(node_8);
    cout << "Is test case 7 correct ? :" << prettyPrint(bst.getRoot()->left->data == 12) << endl;
    cout << "Is test case 8 correct ? :" << prettyPrint(bst.getRoot()->left->left->data == 10) << endl;
    cout << "Is test case 9 correct ? :" << prettyPrint(bst.getRoot()->left->right->data == 15) << endl;
    bst.deleteNode(100);
    // Test case 10 is printing the "Node is not exist !" error.

    bst.clear(bst.getRoot());
    return 0;
}