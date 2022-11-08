
#include <iostream>
#include <fstream>
#include <algorithm>
#include "BST.h"
using namespace std;




        BSTNode* BST::CreateNode(int data){
        BSTNode* newNode = new BSTNode;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    
	
        BSTNode* BST::Insert(BSTNode* node, int data){
        
        if(node==NULL){
            node = CreateNode(data);
        } else if(data <= node->data){
            node->left = Insert(node->left,data);
        } else {
            node->right = Insert(node->right,data);
        }
            return node;

    }


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

	
	int BST::CountNodes(BSTNode* root){
        if(root == nullptr){
            return 0;
        } else
        return 1 + CountNodes(root->right) + CountNodes(root->left);
    }

	
        void BST::CreateTree(string file){
        ifstream filename;
        int x;
        filename.open(file);
        if(!filename){
            cout<<"Error! Unable to open file!"<<endl;
        } else{
                int count = 0;
                 while(filename>>x){
                        count++;
                        if(count==1){
                                root = CreateNode(x);
                        } else  {
                                Insert(root,x);
                        }
        }
        filename.close();
        }
    }




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
       }else{
        if(abs(left-right)>1)
        return false;

        }
        return true;



