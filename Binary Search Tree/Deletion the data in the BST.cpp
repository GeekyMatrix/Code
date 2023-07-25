BinaryTreeNode<int>*deleteData(int data,BinaryTreeNode<int>*node){
if(node==NULL) return NULL;

  if(data>node->data) {
  node->right=deleteData(data,node->right);
    return node;
  }

  else if(data<node->data){
     node->left=deleteData(data,node->left);
    return node;
  }
  else {
      if(node->left==NULL && node->right==NULL){
      delete node;
       return NULL;
      }

    else if(node->left==NULL){
    BinaryTreeNode<int>*temp=node->right;
      node->right==NULL;
      delete node;
      return temp;
    }
  else if(node->right==NULL){
    BinaryTreeNode<int>*temp=node->left;
      node->left==NULL;
      delete node;
      return temp;
    }
   else{ 
      BinaryTreeNode<int>*minNode=node->right;
      while(minNode->left!=NULL){
       minNode=minNode->left;
      }
     int rightMin=minNode->data;
     node->data=rightMin;
     node->right=deleteData(rightMin,node->right);
     return node;
   }
  }
}

//Print Function
void printTree(BinaryTreeNode<int>*root){
if(root==NULL) return;

cout<<root->data<<":";

  if(root->left!=NULL){
  cout<<"L"<<root->left->data;
  }

if(root->right!=NULL){
cout<<"R"<<root->right->data;
}
cout<<endl;
printTree(root->left);
printTree(root->right);
}

void deleteData(int data){
root=deleteData(data,root);
}

void printTree(){
printTree(root);
}

int main(){
BST b;
  b.deleteData(10);
  b.deleteData(100);
  b.printTree();
}
