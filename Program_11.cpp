//
//  Program_11.cpp
//  Data Structure
//
//  Created by Hansika Saxena on 20/11/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

// C program to demonstrate Binary Search Trees
#include <iostream>
using namespace std;

// tree node, including left and right pointers, data
class Node{
public:
    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
    int data;
        Node *left, *right;
};

// BST class
class BST{
public:

        Node *root;
    BST(){
        root=NULL;
    }
        void insert(Node *treeNode, int data);
        Node* deleteData(Node *treeNode, int data);
        void searchReplace(Node* treeNode, int data);
        Node* minValueNode(Node* node);
        void printLevelOrder(Node* treeNode);
        void printGivenLevel(Node* treeNode, int level);
        int  getHeight(Node *treeNode);
        void inOrder(Node * treeNode);
        void preOrder(Node * treeNode);
        void postOrder(Node * treeNode);
        void insert(int data){ insert(root, data);}
   
        int getHeight(){return getHeight(root);}
    
        void inOrder() {inOrder(root);}
        void preOrder(){preOrder(root);}
        void postOrder(){postOrder(root);}
};

//part i
void BST::insert(Node *treeNode, int data)
{
        if (treeNode==NULL)
        {
             treeNode = new Node(data);
            root = treeNode;
        }
        else
        {
                if (data < treeNode->data)
                {
                        if (!treeNode->left)
                        {
                                Node *treeTemp = new Node(data);
                                treeNode->left = treeTemp;
                        }
                        else
                                insert(treeNode->left, data);
                }
                else
                {
                        if (!treeNode->right)
                        {
                                Node *treeTemp = new Node(data);
                                treeNode->right = treeTemp;
                        }
                        else
                                insert(treeNode->right, data);
                }
        }
}

//part ii
Node* BST::deleteData(Node *treeNode, int data){
    if (data < treeNode->data){
           treeNode->left = deleteData(treeNode->left, data);
    }
    else if (data > treeNode->data){
           treeNode->right = deleteData(treeNode->right, data);
    }
    else{
        if (treeNode->left == NULL) {
                   Node* temp = treeNode->right;
                   free(treeNode);
                   return temp;
               }
               else if (root->right == NULL) {
                     Node* temp = treeNode->left;
                     free(treeNode);
                     return temp;
               }
        
               // node with two children: Get the inorder successor (smallest in the right subtree)
               Node* temp = minValueNode(root->right);
        
               // Copy the inorder successor's content to this node
               treeNode->data = temp->data;
        
               // Delete the inorder successor
               treeNode->right = deleteData(treeNode->right, temp->data);
    }
    return treeNode;
}

Node* BST::minValueNode(Node* node)
{
    Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

//part iii
void BST::searchReplace(Node* treeNode, int data)
{
    int d;
    deleteData(treeNode,data);
    std::cout<<"Enter element y \n";
    std::cin>>d;
    insert(treeNode, d);
    std::cout<<"Element replaced \n";
}

//part iv

void BST::inOrder(Node * treeNode)
{
        if (!treeNode)
                return;
        inOrder(treeNode->left);
        std::cout << treeNode->data << " " ;
        inOrder(treeNode->right);
}


void BST::preOrder(Node * treeNode)
{
        if (!treeNode)
                return;
        std::cout << treeNode->data << " ";
        preOrder(treeNode->left);
        preOrder(treeNode->right);
}

void BST::postOrder(Node * treeNode)
{
        if (!treeNode)
                return;
        postOrder(treeNode->left);
        postOrder(treeNode->right);
        std::cout << treeNode->data << " ";
}

//part v
void BST::printLevelOrder(Node* treeNode)
{
    int h = getHeight(treeNode);
    int i;
    for (i = 1; i <= h; i++)
        printGivenLevel(treeNode, i);
}
 
//Print nodes at a given level
void BST::printGivenLevel(Node* treeNode, int level)
{
    if (treeNode == NULL)
        return;
    if (level == 1)
        std::cout << treeNode->data << " ";
    else if (level > 1)
    {
        printGivenLevel(treeNode->left, level-1);
        printGivenLevel(treeNode->right, level-1);
    }
}

//part vi
int BST::getHeight(Node *treeNode)
{
        if (!treeNode)
                return 0;
        return 1 + max(getHeight(treeNode->left) , getHeight(treeNode->right));
}


int main()
{
        BST myBST;
    int val,ch;
       std::cout<<"1) Insert Element in BST"<<endl;
        std::cout<<"2) Delete Element from BST"<<endl;
        std::cout<<"3) Search x and replace with y"<<endl;
        std::cout<<"4) Display BST in preorder, inorder, and postorder"<<endl;
        std::cout<<"5) Display BST in level-by-level"<<endl;
        std::cout<<"6) Display the height of BST"<<endl;
        std::cout<<"7) EXIT"<<endl;

        do {
           std::cout<<"Enter choice: "<<endl;
           std::cin>>ch;
           switch(ch) {
              case 1: {
                 std::cout<<"Enter value to insert:"<<endl;
                 std::cin>>val;
                  myBST.insert(val);
                 break;
              }
              case 2: {
                  std::cout<<"Enter value to delete:"<<endl;
                  std::cin>>val;
                  myBST.deleteData(myBST.root,val);
                  break;
              }
              case 3: {
                  std::cout<<"Enter value x to be searched:"<<endl;
                std::cin>>val;
                myBST.searchReplace(myBST.root,val);
                break;
              }
              case 4: {
                 std::cout<<"BST in Preorder:"<<endl;
                  myBST.preOrder(myBST.root);
                std::cout<<endl<<"BST in Inorder:"<<endl;
                  myBST.inOrder(myBST.root);
                std::cout<<endl<<"BST in Postorder:"<<endl;
                  myBST.postOrder(myBST.root);
                 break;
              }
               case 5: {
                   std::cout<<"BST in level - by - level:"<<endl;
                   myBST.printLevelOrder(myBST.root);
                   break;
               }
               case 6: {
                   std::cout<<"Heigth of BST = "<<myBST.getHeight(myBST.root)<<endl;
                    break;
               }
              default: {
                 std::cout<<"Invalid Choice"<<endl;
              }
           }
        }while(ch!=7);
}
