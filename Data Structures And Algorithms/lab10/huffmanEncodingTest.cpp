#include "huffmanTree.h"

#define prettyPrint(value) (value?"Yes":"No")

int main() {
    string word = "aswdesdsxqwsddaxaweqewasdx";
    // Necessary tree nodes and sorted list based on frequency are given in below.
    TreeNode<char> *q = new TreeNode<char>('q', 2);
    TreeNode<char> *e = new TreeNode<char>('e', 3);
    TreeNode<char> *x = new TreeNode<char>('x', 3);
    TreeNode<char> *a = new TreeNode<char>('a', 4);
    TreeNode<char> *w = new TreeNode<char>('w', 4);
    TreeNode<char> *s = new TreeNode<char>('s', 5);
    TreeNode<char> *d = new TreeNode<char>('d', 5);
    TreeNode<char> *list[] = {q, e, x, a, w, s, d};
    HuffmanTree<char> huffmanTree = HuffmanTree<char>(list, 9);

    TreeNode<char> *root = huffmanTree.buildTree();
    TreeNode<char> *tempRoot = root;
    huffmanTree.assignPaths(tempRoot, "");
    cout << "Is test case 1 correct ? : " << prettyPrint(root != NULL) << endl;
    cout << "Is test case 2 correct ? : " << prettyPrint(s->frequency == 5) << endl;
    cout << "Is test case 3 correct ? : " << prettyPrint(root->left->left->frequency == 5) << endl;
    cout << "Is test case 4 correct ? : " << prettyPrint(root->right->right->right->left->data == 'q') << endl;
    cout << "Is test case 4 correct ? : " << prettyPrint(root->right->frequency == 16) << endl;
    cout << "Is test case 5 correct ? : " << prettyPrint(root->left->frequency == 10) << endl;
    cout << "Is test case 6 correct ? : " << prettyPrint(s->path == "00") << endl;
    cout << "Is test case 7 correct ? : " << prettyPrint(a->path == "101") << endl;
    cout << "Is test case 8 correct ? : " << prettyPrint(root->right->left->right->path == "101") << endl;
    cout << "Is test case 9 correct ? : " << prettyPrint(root->right->right->path == "11") << endl;
    string encodedPath = "1010011001111100010010011101100001011011001011101111111011111101010001100";
    string encoded = a->path + s->path + w->path + d->path + e->path + s->path + d->path + s->path + x->path +
                     q->path + w->path + s->path + d->path + d->path + a->path + x->path + a->path + w->path +
                     e->path + q->path + e->path + w->path + a->path + s->path + d->path + x->path;
    cout << "Is test case 10 correct ? : " << prettyPrint(encoded == encodedPath) << endl;
    huffmanTree.clear(root);
    return 0;
}