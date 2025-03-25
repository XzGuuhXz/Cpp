#include <iostream>

//procurar a biblioteca n8n
//criar uma biblioteca:colocar onder, e altura da arvore

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
    int heigthTreePosOrder(TreeNode* node, int H1Left, int H2Hight);
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

//onder esquerda-raiz-direira
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
    posOrder(node->getRight());
    std::cout << node->getData(); 
  }
  std::cout << "  ";
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

//Altura posOrder
int BinaryTree::heigthTreePosOrder(TreeNode* node, int H1Left, int H2Right)
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

int main()
{
  BinaryTree tree;

  tree.insertVal(5);
  tree.insertVal(4);
  tree.insertVal(3);
  tree.insertVal(2);
  tree.insertVal(8);
  tree.insertVal(45);
  tree.insertVal(78);
  tree.insertVal(23);
  tree.insertVal(1);
  
  tree.inOrder(tree.root);
  std::cout <<"\n\n";
  tree.posOrder(tree.root);
  std::cout <<"\n\n";
  tree.preOrder(tree.root);
  std::cout <<"\n\n";
  std::cout << "InOrder " << tree.heigthTree(tree.root, 0, 0) << "\n\n";
  std::cout << "PosOrder " << tree.heigthTreePosOrder(tree.root, 0, 0);
}
