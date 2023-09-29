//ist Approach

int maxpath = 0;

void solve(TreeNode* root, int steps, bool goleft){

if(root == NULL) return;
maxpath = max(maxpath,steps); //update karo

    if(goleft == true) {
        solve(root->left, steps + 1, false); //false->right jaio aab se for zigzag
        solve(root->right, 1, true);   //true->left jaio aab se for zigzag
    }
    else{ //go right
        solve(root->right, steps + 1, true); //true->left jaio aab se for zigzag
        solve(root->left, 1, false);    //false->right jaio aab se for zigzag
    }
}
    int longestZigZag(TreeNode* root) {
        solve(root, 0 ,true); //left ke liye
        solve(root, 0 , false);// Right ke liye
        return maxpath;
    }

//2nd Approach
int maxpath = 0;
void solve(TreeNode* root, int left, int right){
  if(root == NULL) return;
  maxpath = max({maxpath, left, right});

  solve(root->left, right + 1, 0);
  solve(root->right, 0, left + 1);
}
    int longestZigZag(TreeNode* root) {
        solve(root, 0 ,0); 
        return maxpath;
    }
};
