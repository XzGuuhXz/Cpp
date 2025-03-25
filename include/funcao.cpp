#include "tree.h"

void BinaryTree::deleteTree(TreeNode* node)
{
  if(node != nullptr)
  {
    deleteTree(node->getLeft());
    deleteTree(node->getRight());
  }
  delete node;
}
void BinaryTree::insertVal(int val)
{
  root = insert(root, val);
}

//in oder esquerda-raiz-direira
void BinaryTree::inOrder(TreeNode * node)
{
  if(node != nullptr)
  {
    inOrder(node->getLeft());
    std::cout << node->getData();
    inOrder(node->getRight());
  }
}

//pos order esquerda-direira-raiz
void BinaryTree::posOrder(TreeNode * node)
{
  if(node != nullptr)
  {
    posOrder(node ->getLeft());
    std::cout << node->getData() << " "; 
    posOrder(node->getRight());
    
  }
  //std::cout<<"Arvore binaria Pos-Order:\n\n";
  std::cout << "\n";
}

//pre order raiz-esquerda-direita
void BinaryTree::preOrder(TreeNode * node)
{
  if(node != nullptr)
  {
    std::cout << node->getData();
    preOrder(node ->getLeft());
    preOrder(node->getRight());
  }
}

//altura inOrder
int BinaryTree::heigthTree(TreeNode* node, int H1Left, int H2Right)
{
  if(node != nullptr)
  { 
    H1Left = heigthTree(node->getLeft(), H1Left, 0);
    H2Right = heigthTree(node->getRight(), 0, H2Right);

    if(H1Left == H2Right)
    {
      return H1Left+1;
    }
    if(H1Left > H2Right)
    {
      return H1Left+1;
    }
    else
    {
      return H2Right+1;
    }
  }
  return 0;
}

BinaryTree::~BinaryTree()
{
  //msg ibj destruido
  //mesage delete TreeBinary
  deleteTree(root);  
}