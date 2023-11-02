lass Solution {
public:
// //Approach 1
// //TC = O(N^2)
// //SC = O(1)
int res = 0;

int findSum(TreeNode* root , int &cnt){
 if(!root) return 0;

 cnt++;
 int ls = findSum(root->left , cnt);
 int rs = findSum(root->right , cnt);

 return ls + rs + root->val;
}

void solve(TreeNode* root){
 if(!root) return;

 int cnt = 0;
 int totalsum = findSum(root , cnt); //sub tree Sum call kiya 

 if(root->val == totalsum / cnt) res++;

 solve(root->left);
 solve(root->right);
}
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return res;
    }

//Approach 1
//TC = O(N)
//SC = O(1)
int res = 0;

pair<int,int> solve(TreeNode* root){
 if(!root) return{0,0};

 auto p1 = solve(root->left);
 auto p2 = solve(root->right);

 int totalSum = p1.first + p2.first + root->val;
 int totalCnt =  p1.second + p2.second + 1;
 
 int avg = (totalSum / totalCnt);

 if(avg == root->val) res++;

 return {totalSum , totalCnt};
}
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return res;
    }
};
