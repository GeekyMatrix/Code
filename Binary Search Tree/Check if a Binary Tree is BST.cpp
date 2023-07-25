//Approach 1
int maximum(BinaryTreeNode <int>*root){
if(root==NULL) return INT_MIN;

  return max(root->data,max(maximum(root->left),maximum(root->right));
}

int minimum(BinaryTreeNode <int>*root){
if(root==NULL) return INT_MAX;

return min(root->data,min(minimum(root->left),minimum(root->right));
}


bool isBST(BinaryTreeNode <int>*root){
if(root==NULL) return true;

  int leftMax=maximum(root->left);
  int rightMin=minimum(root->right);

  bool Output= (root->data>leftMax) && (root->data<=rightMin) && isBST(root->left) && isBST(root->right);

  return Output;
}

int main(){
cout<<isBST(root)<<endl;
}
//Approach 2
bool isBST3(BinaryTreeNode<int>*root,int min,int max){
if(root==NULL) return true;

if(root->data<min || root->data>max) return false;

bool isLeftOK=isBST3(root->left,min,root->data-1);
bool isRightOK=isBST3(root->right,root->data,max);

return isLeftOK && isRightOK;
}

int main(){
 cout<<isBST3(root,INT_MIN,INT_MAX)<<endl;
}
