class Solution {
public:
int res = 0;
 void Solve(TreeNode* root , vector<int>&cnt){
  if(!root) return;

  cnt[root->val]++;

  if(root->left == NULL && root->right == NULL) { //Leaf Node
      int oddfreq = 0;

      for(int i = 0; i <= 9; i++){
          if(cnt[i] % 2 != 0) oddfreq++;
      }
      if(oddfreq <= 1) res++;
  }

  Solve(root->left , cnt);
  Solve(root->right , cnt);

  cnt[root->val]--; //Backtrack
 }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>cnt(10,0);
        Solve(root, cnt);
        return res;
    }
};
