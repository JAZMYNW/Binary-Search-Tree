
#include <iostream>
#include <fstream>
#include <algorithm>
#include "BST.h"
using namespace std;



	BSTNode* BST::CreateNode(int data){
        BSTnode* newNode = new BSTnode;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
	/*
	  Receives as input the root of a binary search tree or subtree, creates
	  and inserts a new node with the given value 'data'.
	  Returns pointer to the new node.
	*/
	BSTNode* BST::Insert(BSTNode* node, int data){
        
        if(node==NULL){
            node = CreateNode(data);
        }if(data <= node->data){
            node->left = Insert(node->left,data);
        } else{
            node->right = Insert(node->right,data);
        }
            return node;
        
    }


	/*
	  Searches for the provided 'data' in the subtrees of 'node'.
	  if 'node' is the root of a tree, it will search the entire tree
	  and return true if the key is found, false if not. 
	*/
	bool BST::Search(BSTNode* node, int data){
        if(node==NULL){
            return false;
        } if(node->data == data){
            return true;
        } else if(data <= node->data){
            return Search(node->left,data);
        } else 
            return Search(node->right,data);
    }

	/*
	  Returns the number of nodes in the tree/subtree with the provided root
	*/
	int BST::CountNodes(BSTNode* root){
        if(root == nullptr){
            return 0;
        } else
        return 1 + CountNodes(root->right) + CountNodes(root->left);
    }

	/*
	  Receives a text file containing one integer per line,
	  and inserts them into a binary search tree one at a time.
	*/
	void BST::CreateTree(string file){
        ifstream input;
        int x;
        input.open(file);
        if(!input){
            cout<<"Error! Unable to open file!"<<endl;
        }
        while(input>>x){
            Insert(root,x);
        }
        input.close();
    }

	/*
	  Returns true if the binary tree/subtree with the provided root is balanced.
	  That is, that for any given node in the tree, the difference in heights
	  of its left and right subtree differ by one at most.
	*/
	int BST::TreeHeight(BSTNode* node){
       int left;
       int right;
        if(node==NULL){
            return 0;
        } else
        left = TreeHeight(node->left);
        right = TreeHeight(node->right);
        return max(left,right)+1;
    }

    bool BST::isBalanced(BSTNode* node){
       int left = TreeHeight(node->left);
       int right = TreeHeight(node->right);
       if(node == NULL){
       return true;
       }
       if(abs(left-right)<=1){
        if(isBalanced(node->right)&& isBalanced(node->left)){
            return true;
        }
       }
       return false;     

    }


