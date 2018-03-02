#pragma once
#include <vector>
#include <iostream>

namespace N2B_Data
{

	class AVL_Tree
	{
	public:
		AVL_Tree()
			:
			sentinel(0, sentinel)
		{}

		void insert(int key)
		{
			Node* node = new Node(key, sentinel);
			//find position
			//if tree is empty make the node the new root
			if (root == nullptr)
			{
				root = node;
				return;
			}
			//else find the new position
			Node* new_parent = root;
			while (true)
			{
				if (node->key < new_parent->key)
				{
					if (new_parent->l_child == &sentinel)
					{
						make_l_child(node, new_parent);
						break;
					}
					new_parent = new_parent->l_child;
				}
				else
				{
					if (new_parent->r_child == &sentinel)
					{
						make_r_child(node, new_parent);
						break;
					}
					new_parent = new_parent->r_child;
				}
			}
			AVL_fixup(node);
		}


		void print_in_order()
		{
			print_in_order(root);
		}
		class Node;
		void print_in_order(Node* node)
		{
			if (node == &sentinel)
				return;
			print_in_order(node->l_child);
			std::cout << " (" << node->key << ", p: " << node->parent->key << " lh: " << node->l_height << " rh: " << node->r_height << ") ";
			print_in_order(node->r_child);
		}

	private:
		class Node
		{
		public:
			Node(int key, Node& sentinel) 
				: 
				key(key), 
				l_child(&sentinel), 
				r_child(&sentinel),
				parent(&sentinel)
			{}

			Node* l_child;
			Node* r_child;
			Node* parent;

			int l_height = 0;
			int r_height = 0;
			int key;
		};

		Node sentinel;
		Node* root;

		void AVL_fixup(Node* node)
		{
			Node* parent = node->parent;
			while (parent != &sentinel)
			{
				//update height
				if (is_l_child(node, parent))
					parent->l_height = std::max(parent->l_child->l_height + 1, parent->l_child->r_height + 1);
				else
					parent->r_height = std::max(parent->r_child->l_height + 1, parent->r_child->r_height + 1);
				//check height
				if (parent->l_height - parent->r_height < -1)
				{
					parent->r_height -= 2;
					l_rotate(parent);
				}
				else if (parent->l_height - parent->r_height > 1)
				{
					parent->l_height -= 2;
					r_rotate(parent);
				}
				node = parent;
				parent = node->parent;
			}
		}

		void l_rotate(Node* x)
		{
			Node* y = x->r_child;
			if (is_l_child(x, x->parent))
				make_l_child(y, x->parent);
			else
				make_r_child(y, x->parent);
			if (x == root)
				root = y;
			Node* b = y->l_child;
			make_r_child(b, x);
			make_l_child(x, y);
		}
		void r_rotate(Node* y)
		{
			Node* x = y->l_child;
			if (is_l_child(y, y->parent))
				make_l_child(x, y->parent);
			else
				make_r_child(x, y->parent);
			if (root = y)
				root = x;
			Node* b = x->r_child;
			make_l_child(b, y);
			make_r_child(y, x);
		}

		void make_l_child(Node* child, Node* parent)
		{
			parent->l_child = child;
			child->parent = parent;
		}
		void make_r_child(Node* child, Node* parent)
		{
			parent->r_child = child;
			child->parent = parent;
		}
		bool is_l_child(Node* child, Node* parent)
		{
			return parent->l_child == child;
		}
		bool is_r_child(Node* child, Node* parent)
		{
			return parent->r_child == child;
		}

	};


	static void AVL_tree_test()
	{
		AVL_Tree tree;

		tree.insert(1);
		tree.print_in_order();
		std::cout << std::endl;
		tree.insert(2);
		tree.print_in_order();
		std::cout << std::endl;
		tree.insert(5);
		tree.print_in_order();
		std::cout << std::endl;
		tree.insert(7);
		tree.print_in_order();
		std::cout << std::endl;
		tree.insert(8);
		tree.print_in_order();
		std::cout << std::endl;
		tree.insert(11);
		tree.print_in_order();
		std::cout << std::endl;
		tree.insert(14);
		tree.print_in_order();
		std::cout << std::endl;
		tree.insert(15);

		
		tree.print_in_order();
	}
}