
#include <iostream>
#include "bintree.h"
#include "bstree.h"
using namespace std;
using namespace DS;

int main() {

    bstree<int> bst;

    bst.insert(5);
    bst.insert(15);
    bst.insert(25);
    bst.insert(22);
    bst.insert(-29);
    bst.insert(29);
    bst.insert(2);
    bst.insert(19);
    bst.insert(30);
    bst.insert(40);
    bst.insert(4);
    bst.insert(-34);

    bst.prettyprint();

    cout << "Height:" << bst.height() << endl;
    cout << "Preorder:" << endl;
    bst.preorderprint();
    cout << "Inorder:" << endl;
    bst.inorderprint();
    cout << "Postorder:" << endl;
    bst.postorderprint();

    cout << bst.in_bst(15) << endl;
    cout << bst.in_bst(30) << endl;

//    bst.prettyprint();
//    cout << "==================" << endl;
//    bst.bst_remove(40);
    bst.prettyprint();
    cout << "==================" << endl;
    bst.bst_remove(30);
    bst.prettyprint();
    cout << "==================" << endl;
    bst.prettyprint();
    cout << "==================" << endl;
    bst.bst_remove(25);
    bst.prettyprint();
    cout << "==================" << endl;
    bst.bst_remove(29);
    bst.prettyprint();
    cout << "==================" << endl;
    bst.bst_remove(5);
    bst.prettyprint();
    cout << "==================" << endl;


    return 0;
}