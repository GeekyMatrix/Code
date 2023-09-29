class Solution {
public:
//Ist Approach  
int paths = 0;
void solve(TreeNode* root, int targetSum,long long int currSum){
  if(root == NULL) return;

  currSum+=root->val;
  if(currSum == targetSum) paths++;
  
  solve(root->left, targetSum, currSum);
  solve(root->right, targetSum, currSum);
}
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;

        solve(root, targetSum, 0);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return paths;
    }

//2nd Approach 
 int paths = 0;
void solve(TreeNode* currRoot, int targetSum, long long int currSum,  unordered_map<long long int,long long int>mp){

  if(currRoot == NULL) return;
  currSum+=currRoot->val;

if(currSum == targetSum) paths++;

if(mp.find(currSum - targetSum)!= mp.end()) paths+= mp[currSum - targetSum]; //agar diff map mai present hai

  if(mp.find(currSum)!=mp.end()) mp[currSum]++; //pehle wale Entry ko bda do

  else mp[currSum] = 1; //New Entry krdo

  solve(currRoot->left, targetSum ,currSum, mp);
  solve(currRoot->right, targetSum ,currSum, mp);
  
  mp[currSum]--;//wapas hote time map se Entry hata do
  return;
 }

    int pathSum(TreeNode* root, int targetSum) {

        if(root == NULL) return 0;
        unordered_map<long long int,long long int>mp;  // node -> frequency
        solve(root, targetSum, 0, mp);
        return paths;
    }
};
