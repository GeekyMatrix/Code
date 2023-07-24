/*o/p----->>>>>
  1:L2 R3
  2:
  3:
*/
void printTree(Binary TreeNode<int>*root){
//BASE CASE
  if(root==NULL) return;

  cout<<root->data<<":";
  if(root->left!=NULL) cout<<"L"<<root->left->data;

  if(root->right!=NULL) cout<<"R"<<root->right->data;

 cout<<endl;
  printTree(root->left);
  printTree(root->right);
}

int main(){
printTree(root);
delete root;
}
