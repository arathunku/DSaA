#include <iostream>
#include <string.h>

// BST

using namespace std;


struct Element{
  int key;
  int value;
};

struct Node{
  Element elem;
  Node *p, *left,*right;
};

// Binary search tree
struct BST{
  Node *root;
};

void init(BST & tree){
  tree.root = NULL;
}

bool insertElem(BST & tree, Element elem){
  Node *z = new Node();
  z -> left = z -> right = z -> p = NULL;
  z -> elem = elem;
  Node *y = NULL;
  Node *x = tree.root;
  while(x != NULL){
    y = x;
    if(y -> elem.key == z->elem.key) {
      return false;
    }
    if(z->elem.key < x->elem.key){
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z -> p = y;
  if(y==NULL){
    tree.root = z;
    return true;
  } else if(z -> elem.key < y->elem.key) {
    y->left = z;
    return true;
  } else {
    y->right = z;
    return true;
  }
  return false;
}

void showInorder(BST & tree){
  if(tree.root == NULL) {
    cout << endl;
    return;
  }
  if( tree.root!=NULL){
    BST left;
    left.root = tree.root -> left;
    BST right;
    right.root = tree.root -> right;
    if(left.root != NULL) 
      showInorder(left);
    cout<< tree.root->elem.key << "(" << tree.root->elem.value << "),";
    if(right.root != NULL) 
      showInorder(right);
    if(tree.root ->p == NULL) {
      cout << endl;
    }
  }
}

void showPreorder(BST & tree){
  if(tree.root == NULL) {
    cout << endl;
    return;
  }
  if( tree.root!=NULL){
    BST left;
    left.root = tree.root -> left;
    BST right;
    right.root = tree.root -> right;
    cout<< tree.root->elem.key << "(" << tree.root->elem.value << "),";
    if(left.root != NULL) 
      showInorder(left);
    if(right.root != NULL) 
      showInorder(right);
    if(tree.root ->p == NULL) {
      cout << endl;
    }
  }
}
void showPostorder(BST & tree){
  if(tree.root == NULL) {
    cout << endl;
    return;
  }
  if( tree.root!=NULL){
    BST left;
    left.root = tree.root -> left;
    BST right;
    right.root = tree.root -> right;
    if(left.root != NULL) 
      showInorder(left);
    if(right.root != NULL) 
      showInorder(right);
    cout<< tree.root->elem.key << "(" << tree.root->elem.value << "),";
    if(tree.root ->p == NULL) {
      cout << endl;
    }
  }
}
Node *treeminimum(Node *root) {
  while(root->left != NULL) {
    root = root->left;
  }
  return root;
}

Node *treesuccessor(Node *root, int key){
  Node *x = new Node();
  x -> left = x -> right = x -> p = NULL;
  x -> elem.key = key;
  if(root->right != NULL){
    return(treeminimum(root));
  }
  Node *y = x->p;
  while(y!= NULL && x==y->right){
    x = y;
    y = y->p;
  }
  return y;
}

Node *findKeyRecursion(Node *root,int key) {
  if(root == NULL){
    return NULL;
  } else if(root->elem.key == key) {
    return root;
  }else if( key < root->elem.key) {
    return findKeyRecursion(root->left, key);
  } else {
    return findKeyRecursion(root->right, key);
  }
}
bool findKey(BST & tree,int key, Element &elem) {
  Node *r;
  r = findKeyRecursion(tree.root, key);
  if(r != NULL){
    elem = r -> elem;
    return true;
  }
  return false;
}

bool removeKey(BST & tree, int key, Element &elem){
  if(tree.root == NULL){
    return false;
  }
  cout << "root na start: " << tree.root->elem.key << endl;
  Node *z = findKeyRecursion(tree.root, key);
  if(z == NULL){
    return false;
  }
  Node *y, *x;
  if(z->right == NULL || z->left == NULL) {
    y = tree.root;
  } else {
    y = treesuccessor(tree.root, key);
    if(y == NULL){
      return false;
    }
  }

  if(y->left != NULL){
    x = y->left;
  } else {
    x = y->right;
  }

  if(x != NULL)
    x->p = y->p;

  cout << "xxxxxxxxx: " << tree.root->elem.key << endl;
  if(y->p == NULL){
    tree.root = x;
  } else if(y == y->p->left){
    y->p->left = x;
  } else {
    y->p->right = x;
  }
  elem = z->elem;

  if(y != z){
    z->elem.key = y->elem.key;
  } else {
    if(z->right == NULL) {cout << z->elem.key << endl;}
    while(y->left != NULL && y->right != NULL){
      if(y->left)
        insertElem(tree, y->left->elem);
      if(y->right)
        insertElem(tree, y->right->elem);
    }
  }
  delete z;
  return true;
}

void clearNodesBelow(Node *tree){
  if( tree != NULL){
    clearNodesBelow(tree -> left);
    clearNodesBelow(tree -> right);
    delete tree;
  }
}

void clear(BST & tree){
  if( tree.root != NULL){
    clearNodesBelow(tree.root -> left);
    clearNodesBelow(tree.root -> right);
    delete tree.root;
    tree.root = NULL;
    return;
  }
}

int CalculateNodes(Node *tree){
  if( tree == NULL) {
    return 0;
  } else {
    return(CalculateNodes(tree->left)+CalculateNodes(tree->right)+1);
  }
}
int numberOfNodes(BST & tree){
  if(tree.root == NULL) {
    return -1;
  } else {
    return CalculateNodes(tree.root);
  }
}

void CalculateHeight(Node *tree,int *height){
  int left_height, right_height;
  if( tree == NULL)
      *height = 0;
  else {
    CalculateHeight(tree->left, &left_height);
    CalculateHeight(tree->right, &right_height);
    if( left_height > right_height)
      *height = left_height + 1;
    else
      *height = right_height + 1;
  }
}
int height(BST & tree){
  int height = 0;
  if(tree.root == NULL){
    return -1;
  }
  CalculateHeight(tree.root, &height);
  return height;
}

int functionA(BST & tree){
  return -1;
}

int functionB(BST & tree, int key){
  return -1;
}

bool functionC(BST & tree, int key, Element &elem){
  return false;
}


void showBool(bool val){
  if(val)
    cout << "true" << endl;
  else
    cout << "false" << endl;
}


int main(){
  const int commandSize=2;
  const int MAXLINE=100;
  char line[MAXLINE]; 
  char command[commandSize+1]; // for '\0'
  BST *tree;
  int currentT=0;
  int value;
  command[commandSize]='\0';
  while(true){
    cin >> command[0];
    if(command[0]=='#')
    {
      cin.getline(line, MAXLINE);
      continue;
    }
    cin >> command[1];

    if(strcmp(command,"HA")==0){
      cout << tree[0].root -> elem.key << "\t";
      cout << "END OF EXECUTION" << endl;
      break;
    }
    // zero-argument command
    if(strcmp(command,"SI")==0)
    {
      showInorder(tree[currentT]);
      continue;
    }

    if(strcmp(command,"SP")==0)
    {
      showPreorder(tree[currentT]);
      continue;
    }

    if(strcmp(command,"SQ")==0)
    {
      showPostorder(tree[currentT]);
      continue;
    }

    if(strcmp(command,"CL")==0)
    {
      clear(tree[currentT]);
      continue;
    }

    if(strcmp(command,"IN")==0)
    {
      init(tree[currentT]);
      continue;
    }

    if(strcmp(command,"NN")==0)
    {
      cout << numberOfNodes(tree[currentT]) << endl;
      continue;
    }

    if(strcmp(command,"HE")==0)
    {
      cout << height(tree[currentT]) << endl;
      continue;
    }

    if(strcmp(command,"FA")==0)
    {
      cout << functionA(tree[currentT]) << endl;
      continue;
    }

    // read next argument, one int value
    cin >> value;
    

    if(strcmp(command,"IE")==0)
    {
      int variable2;
      cin >> variable2;
      Element elem;
      elem.key=value;
      elem.value=variable2;
      showBool(insertElem(tree[currentT],elem));
      continue;
    }

    if(strcmp(command,"FK")==0)
    {
      Element elem;
      bool ret=findKey(tree[currentT], value, elem);
      if(ret)
        cout << elem.key << '(' << elem.value << ')' << endl;
      else
        cout << "false" << endl;
      continue;
    }

    if(strcmp(command,"RK")==0)
    {
      Element elem;
      bool ret=removeKey(tree[currentT], value, elem);
      if(ret)
        cout << elem.key << '(' << elem.value << ')' << endl;
      else
        cout << "false" << endl;
      continue;
    }


    if(strcmp(command,"CH")==0)
    {
      currentT=value;
      continue;
    }

    if(strcmp(command,"GO")==0)
    {
      tree=new BST[value];
      continue;
    }

    if(strcmp(command,"FB")==0)
    {
      cout << functionB(tree[currentT],value) << endl;
      continue;
    }

    if(strcmp(command,"FC")==0)
    {
      Element elem;
      bool ret=functionC(tree[currentT], value, elem);
      if(ret)
        cout << elem.key << '(' << elem.value << ')' << endl;
      else
        cout << "false" << endl;
      continue;
    }

    cout << "wrong argument in test: " << command << endl;
    return 1;
  }
}
