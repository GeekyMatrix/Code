class Solution {
public:
//IST APPROACH O(n^2)
 int path=0;
 void solve(TreeNode* root,int targetSum,int CurrentSum){
 if(root==NULL) return;

 CurrentSum+=root->val;

 if(targetSum == CurrentSum) path++;
 solve(root->left,targetSum,CurrentSum);
 solve(root->right,targetSum,CurrentSum);
 }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;

        solve(root,targetSum,0);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return path;
    }

//2nd Approach O(n)
int output=0;
  void solve(TreeNode* CurrRoot,long long int Currsum,int targetSum,unordered_map<long long int,long long int>m){
   if(CurrRoot == NULL) return;
     Currsum+=CurrRoot->val;

           if(Currsum == targetSum) output++; 
       
            if(m.find(Currsum-targetSum)!=m.end()) output+=m[Currsum-targetSum];
            
            if(m.find(Currsum)!=m.end()) m[Currsum]++;

          else m[Currsum]=1;

         solve(CurrRoot->left, Currsum,targetSum,m);
         solve(CurrRoot->right, Currsum,targetSum,m);
            m[Currsum]--;
            return;
  }

 int pathSum(TreeNode* root, int targetSum) {
  if(root == NULL) return 0;
  unordered_map<long long int,long long int>m;  
  solve(root,0,targetSum,m);
  return output;
 }
};
