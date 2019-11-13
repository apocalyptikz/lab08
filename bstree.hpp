#include <algorithm>
#include "bstree.h"
#include "bintree.h"

namespace DS {

	//Precondition: root_ptr points to a binary tree with at least one node
	//Postcondition: Height of the tree is returned recursively, recall that a tree 
	//  with one node is height of 0 and an empty tree has a height of -1
	template<typename Item>
	long bstree<Item>::bst_height(const  binary_tree_node<Item>* root_ptr) const
	{
		if (root_ptr == nullptr)
			return -1;
		if (root_ptr->left() == nullptr && root_ptr->right() == nullptr)
			return 0;

		return 1 + std::max(bst_height(root_ptr->left()), bst_height(root_ptr->right()));
	}

	//Precondition: Tree has at least one node, ie height >= 0
	//Precondition: Inserts newDataItem into the binary search tree in the correct spot.
	template<typename Item>
	void bstree<Item>::bst_insert(const Item& in, binary_tree_node<Item>* root_ptr)
	{
		if (root_ptr == nullptr)
		{
			root_ptr = new binary_tree_node<Item>(in);
			return;
		}
		if (root_ptr->data() <= in)
		{
			if (root_ptr->right() == nullptr)
			{
				root_ptr->set_right(new binary_tree_node<Item>(in));
				return;
			}
			bst_insert(in, root_ptr->right());
		}
		if (root_ptr->data() > in)
		{
			if (root_ptr->left() == nullptr)
			{
				root_ptr->set_left(new binary_tree_node<Item>(in));
				return;
			}
			bst_insert(in, root_ptr->left());
		}

	}

	//Precondition: root_ptr is a root pointer of a binary search tree
	//Postcondition: Returns true if target is in the BST, false otherwise
	template<typename Item>
	bool bstree<Item>::in_bst(const Item& target, binary_tree_node<Item>* root_ptr)
	{
		if (root_ptr == nullptr)
			return false;
		if (root_ptr->data() == target)
			return true;
		if (root_ptr->data() <= target)
			return in_bst(target, root_ptr->right());
		return in_bst(target, root_ptr->left());
	}

	//Precondition: root_ptr is a root pointer of a binary search tree or may be
	//  NULL for an empty tree).
	//Postcondition: If target was in the tree, then one copy of target has been 
	//  removed, and root_ptr now points to the root of the new 
	//  (smaller) binary search tree. In this case the function returns true.
	//  If target was not in the tree, then the tree is unchanged (and the
	//  function returns false).
	template<typename Item>
	binary_tree_node<Item>* minNode(binary_tree_node<Item>*& node_ptr);
	template<typename Item>
	binary_tree_node<Item>* minNode(binary_tree_node<Item>*& node_ptr)
	{
		if (node_ptr->left() == nullptr)
			return node_ptr;
		return minNode(node_ptr->left());
	}

	template<typename Item>
	binary_tree_node<Item>* maxNode(binary_tree_node<Item>* &node_ptr);
	template<typename Item>
	binary_tree_node<Item>* maxNode(binary_tree_node<Item>*& node_ptr)
	{
		if (node_ptr->right() == nullptr)
			return node_ptr;
		return maxNode(node_ptr->right());
	}
	template<typename Item>
	bool bstree<Item>::bst_remove(const Item& target, binary_tree_node<Item>*& root_ptr)
	{
		if (root_ptr == nullptr)
			return false;
		if (root_ptr->data() == target)
		{
			if (root_ptr->is_leaf())
				root_ptr = nullptr;
			
			if (root_ptr->left() == nullptr && root_ptr->right() != nullptr)
			{
				binary_tree_node<Item>* temp = root_ptr->right();
				root_ptr->set_data(root_ptr->right()->data());
				delete temp;
			}

			if (root_ptr->left() != nullptr && root_ptr->right() == nullptr)
			{
				binary_tree_node<Item>* temp = root_ptr->right();
				root_ptr->set_data(root_ptr->left()->data());
				delete temp;
			}
			
			if (root_ptr->left() != nullptr && root_ptr->right() != nullptr)
			{
				binary_tree_node<Item>* newValue = maxNode(root_ptr->left());
				root_ptr = newValue;
				delete newValue;
				//binary_tree_node<Item>* extraVal = minNode(root_ptr->left());
				//bst_remove(newValue->left()->data(), root_ptr->left());	
			}
				

			return true;
		}
		if (root_ptr->data() <= target)
			return bst_remove(target, root_ptr->right());
		return bst_remove(target, root_ptr->left());
	}
	//1 : tree is emtpy
	//2 : Tree not empty, target < than root
	//3 : tree not empty, target > than root
	//4 target == root node, do not need to check, if not < or >, than it is ==
	//4a The root node has no left child
	//4bThe root does have a left child

	//Precondtion: root_ptr is a root pointer of a non-empty binary search tree
	//Postcondition: The largest item in the BST bas been removed, and the root_ptr
	//  now points to the root of the new (smaller) BST. The reference parameter,
	//  removed, has been set to a copy of the removed item.
	template<typename Item>
	void bstree<Item>::bst_remove_max(binary_tree_node<Item>*& root_ptr, Item& removed)
	{
		if (root_ptr == nullptr)
			return;
	}


}