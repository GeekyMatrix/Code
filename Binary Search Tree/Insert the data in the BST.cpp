BinaryTreeNode<int>*insert(int data,BinaryTreeNode<int>*node){
if(node==NULL) {
BinaryTreeNode<int>*newNode=new BinaryTreeNode<int>(data);
  return newNode;
}
if(data<node->data) node->left=insert(data,node->left);

else  node->right=insert(data,node->right);

return node;
}

void Insert(int data){
 this->root=insert(data,this->data);
}
