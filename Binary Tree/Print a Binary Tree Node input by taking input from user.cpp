// Write print function

Binary Treenode<int>*takeInput(){
int rootData;
cout<<"Enter data"<<endl;
cin>>rootData;
if(rootData==-1) return NULL;
}

Binary TreeNode<int>*root=new Binary TreeNode<int>(rootData);

Binary TreeNode<int>*leftChild=takeInput();

Binary TreeNode<int>*rightChild=takeInput();

root->left=leftChild;
root->right=rightChild;

return root;
}

int main(){

Binary TreeNode<int>*root=takeInput();
print Tree(input);
}

/*
i/p :
  Enter data
1
    Enter data
2
  Enter data
-1
  Enter data
-1
  Enter data
3
  Enter data
-1
  Enter data
-1

  o/p
  1: L2 R3
  2:
  3:
  */
