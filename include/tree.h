#ifndef tree.h
#define tree.h
#include <iostream>

class TreeNode
{
  private:

    int data;
    TreeNode* left;
    TreeNode* right;

  public:
    // costrutor
    TreeNode(int val) : data(val), left(nullptr), right(nullptr){}

    //Métodos de acesso
    int getData() const { return data; }
    TreeNode* getLeft() const { return left; }
    TreeNode* getRight() const { return right; }    

    void setLeft(TreeNode* node) {left = node;}
    void setRight(TreeNode* node) {right = node;}

    ~TreeNode() {}
};

class BinaryTree
{
  private:
    TreeNode* insert(TreeNode* node, int val);
    void deleteTree(TreeNode* node);    

  public:
    TreeNode* root;
    BinaryTree() : root(nullptr) {}
    void insertVal(int val);
    void inOrder(TreeNode* node);
    void posOrder(TreeNode* node);
    void preOrder(TreeNode* node);
    int heigthTree(TreeNode* node, int H1Left, int H2Hight);
    ~BinaryTree();
};

TreeNode* BinaryTree::insert(TreeNode* node, int val)
{
  if(node == nullptr)
  {
    return new TreeNode(val);
  }
  if(val < node->getData())
  {
    node->setLeft(insert(node->getLeft(), val));
  }
  else if(val > node->getData())
  {
    node->setRight(insert(node->getRight(), val));
  }
  return node;
}

#endif