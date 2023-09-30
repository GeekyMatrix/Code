class Solution {
public:
//BFS
    int maxLevelSum(TreeNode* root) {
        int resultlevel = 0;
        queue<TreeNode*>q;
        q.push(root);
        int currlevel = 1;
        int maxSum = INT_MIN;

        while(!q.empty()){
            int sum = 0;

            int size = q.size();

            while(size--){  //Travese for all the childs
             TreeNode* front = q.front();
             q.pop();

             sum+=front->val;

             if(front->left) q.push(front->left);
             if(front->right) q.push(front->right);
            }

             if(sum > maxSum){ //if greatersum found then update the level
              maxSum = sum;
              resultlevel = currlevel;
             }

            currlevel++; //next level pr chle gae
        }
        return resultlevel;
    }

//DFS
map<int, int>mp;  // level-> value

void dfs(TreeNode* root, int level){
    if(root == NULL) return;
    mp[level]+=root->val;

    if(root->left) dfs(root->left, level+1);
    if(root->right) dfs(root->right, level+1);
}

int maxLevelSum(TreeNode* root) {
dfs(root , 1);

int resultlevel;
int maxSum = INT_MIN;

for(auto &it : mp){
 int currlevel = it.first;
 int currSum = it.second;

 if( currSum > maxSum){ // if maxSum found then update the  resultlevel
 maxSum = currSum;
 resultlevel = currlevel;
  }
}
 return resultlevel;
}
};
