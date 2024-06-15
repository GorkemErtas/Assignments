#include <iostream>
/*
Görkem Ertaþ
20070006004
*/

using namespace std;


template<class T>
class TreeNode {
public:
    T data;
    int frequency;
    string path;
    TreeNode *left;
    TreeNode *right;

    TreeNode(T data, int frequency) {
        this->data = data;
        this->frequency = frequency;
        this->left = NULL;
        this->right = NULL;
        this->path = "";
    }
};

template<class T>
class HuffmanTree {
public :
    HuffmanTree(TreeNode<T> **sortedNodeList, int size) {
        this->sortedNodeList = sortedNodeList;
        this->size = size;
    }

    // Use the mergeNodes function and sortedNoteList to construct a huffman tree.
    // You can type function calls by yourself instead of using for/while loops.
    TreeNode<T> *buildTree() {
		TreeNode<T> *A = mergeNodes(sortedNodeList[0], sortedNodeList[1]);
		TreeNode<T> *B = mergeNodes(sortedNodeList[2], sortedNodeList[3]);
		TreeNode<T> *C = mergeNodes(sortedNodeList[4], A);
		TreeNode<T> *D = mergeNodes(sortedNodeList[5], sortedNodeList[6]);
		TreeNode<T> *E = mergeNodes(B, C);
		TreeNode<T> *F = mergeNodes(E, D);
		return F;
    }

    // Use one of the tree traversal methods to assign correct path value to the leaf nodes
    // As an example, the node with value 's' should have a path as "00" and
    // the node with value 'q' should have a path "1110"
    void assignPaths(TreeNode<T> *tempRoot, string path) {

    }

    void clear(TreeNode<T> *tempRoot) {
        if (tempRoot != NULL) {
            clear(tempRoot->left);
            clear(tempRoot->right);
            delete tempRoot;
        }
    }

private :
    TreeNode<T> **sortedNodeList;
    int size;

    // merge the given node values and return a new node connection
    // merged node data can be NULL
    TreeNode<T> *mergeNodes(TreeNode<T> *leftChild, TreeNode<T> *rightChild) {
    	TreeNode<T> *parent = new TreeNode<T> (NULL, leftChild->frequency + rightChild->frequency);
    	parent->left = leftChild;
    	parent->right = rightChild;
    	return parent;
    }


};
