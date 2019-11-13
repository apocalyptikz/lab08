/*
 * bstree.h

Binary Tree


Precondition: None
Precondition: Inserts newDataItem into the binary search tree.  Calls bst_insert in all cases except for empty tree.
void insert( const Item&);

Precondition: bst_height is implemented and works
Precondition: Returns the height of the binary tree pointed to by root_ptr by calling the private recursive
	function called bst_height.  Recall that an empty tree is said to have height = -1.
long height( ) const { return (root_ptr == NULL) ? -1 : bst_height(root_ptr);  };

Precondition: None
Postcondition: Calls the book authors binary_tree_node print helper function to output the tree to stdout
void prettyprint() const;

Precondition: None
Postcondition: The book authors binary_tree_node inorder/preorder/postorder functions are called in order to output the ordered collapsed tree
void preorderprint() const;
void inorderprint() const;
void postorderprint() const;

Precondition: Tree has at least one node
Postcondition: Height of the tree is returned recursively, recall that a tree with one node is height of 0
long bst_height(const  binary_tree_node<Item>*) const;

Precondition: Tree has at least one node, ie height >= 0
Precondition: Inserts newDataItem into the binary search tree in the correct spot.
void bst_insert( const Item& newDataItem,binary_tree_node<Item>*);

 */

#ifndef BSTREE_H_
#define BSTREE_H_

#include <iostream>
#include "bintree.h"

namespace DS {

/*
Precondion: None
Postcondion:  Outputs data prepended by the -> string.  This function gets called by the (pre/in/post)print functions
*/
template <typename Item>
void print_node(const Item data) { std::cout <<  "->" << data; };

template <typename Item>
class bstree {
public:
	bstree() { root_ptr = nullptr;	}
	~bstree() { tree_clear(root_ptr); }

	void insert( const Item& newDataItem);
	long height( ) const { return (root_ptr == NULL) ? -1 : bst_height(root_ptr);  };

	void prettyprint() const;

	void preorderprint() const;
	void inorderprint() const;
	void postorderprint() const;

	bool in_bst(const Item& target) { return in_bst(target,root_ptr); }

	bool bst_remove(const Item& target) { return bst_remove(target,root_ptr); }

	void bst_remove_max(binary_tree_node<Item>*&, Item&);

private:
	void bst_insert( const Item&,binary_tree_node<Item>*);

	bool bst_remove(const Item&, binary_tree_node<Item>*&);
	bool in_bst(const Item&, binary_tree_node<Item>*);

	long bst_height(const binary_tree_node<Item>*) const;
	//void bst_pprint(const binary_tree_node<Item>*,size_t=0) const;

	binary_tree_node<Item>* root_ptr;
};


template <typename Item>
void bstree<Item>::insert( const Item& newDataItem) {
	if ( root_ptr == nullptr )
		root_ptr = new binary_tree_node<Item>(newDataItem);
	else bst_insert(newDataItem, root_ptr);
}

template <typename Item>
void bstree<Item>::prettyprint() const {
	if ( root_ptr == NULL )
		std::cout << "Empty tree" << std::endl;
	else
	{
		std:: cout << std::endl;
		print(root_ptr,0);
		std::cout << std::endl;
	}
}

template <typename Item>
void bstree<Item>::preorderprint() const {
	preorder(&print_node<Item>,root_ptr); std::cout << std::endl;
};

template <typename Item>
void bstree<Item>::inorderprint() const {
	inorder(&print_node<Item>,root_ptr);
	std::cout << std::endl;
};

template <typename Item>
void bstree<Item>::postorderprint() const {
	postorder(&print_node<Item>,root_ptr); std::cout << std::endl;
};


} //End Namespace LABBSTREE

#include "bstree.hpp"
#endif /* BSTREE_H_ */
