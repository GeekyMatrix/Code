//Recursive Method
 vector<TreeNode*>solve(int n){
       if(n%2==0){ //Even
        return {};
       }
       if(n==1){
            TreeNode *root= new TreeNode(0);
            return {root};
       }
         vector<TreeNode*>result;
      for(int i=1;i<n;i+=2){
     vector<TreeNode*> leftAllFBT=solve(i);
     vector<TreeNode*> rightAllFBT=solve(n-i-1);

      for(auto &l:leftAllFBT){
          for(auto &r:rightAllFBT){
               TreeNode *root= new TreeNode(0);
               root->left=l;
               root->right=r;
               result.push_back(root);
          }
      }

      }
      return result;
   }
    vector<TreeNode*> allPossibleFBT(int n) {
         return solve(n);
    }

//Memoization method
unordered_map<int,vector<TreeNode*>>mp;

 vector<TreeNode*>solve(int n){
       if(n%2==0){ //Even
        return {};
       }
       if(n==1){
            TreeNode *root= new TreeNode(0);
            return {root};
       }
       if(mp.find(n)!=mp.end()) return mp[n];

         vector<TreeNode*>result;
      for(int i=1;i<n;i+=2){
     vector<TreeNode*> leftAllFBT=solve(i);
     vector<TreeNode*> rightAllFBT=solve(n-i-1);

      for(auto &l:leftAllFBT){
          for(auto &r:rightAllFBT){
               TreeNode *root= new TreeNode(0);
               root->left=l;
               root->right=r;
               result.push_back(root);
          }
      }

      }
      return mp[n]=result;
   }
    vector<TreeNode*> allPossibleFBT(int n) {
         return solve(n);
    }
};
