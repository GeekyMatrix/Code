class Solution {
public:
//Recursive method
   vector<TreeNode*>solve(int start,int end){
    
    if(start>end) return {NULL};

    if(start==end){
         TreeNode *root=new TreeNode(start);
         return {root};
    }
  vector<TreeNode*>result;
     for(int i=start;i<=end;i++){
//Haar ek index ke left bst& right bst check krlo
         vector<TreeNode*> left_bsts=solve(start,i-1);
         vector<TreeNode*> right_bsts=solve(i+1,end);

    //pair bnao ki uss particular root ke liye kitne bsts ho skte hai
         for(TreeNode* leftRoot:left_bsts){
             for(TreeNode* rightRoot:right_bsts){

               TreeNode* root=new TreeNode(i);
                root->left=leftRoot;
                root->right=rightRoot;
            //answer mai save krte jao kitne bsts bn rhe hai
                result.push_back(root);
             }
         }
     }
        return result;
   }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }

//Memoization method
map<pair<int,int>,vector<TreeNode*>>mp; // {start,end}->TreeNode

   vector<TreeNode*>solve(int start,int end){
    
    if(start>end) return {NULL};

    if(start==end){
         TreeNode *root=new TreeNode(start);
         return mp[{start,end}]={root};
    }

    if(mp.find({start,end})!=mp.end()){
        return mp[{start,end}];
    }
  vector<TreeNode*>result;
     for(int i=start;i<=end;i++){
//Haar ek index ke left bst& right bst check krlo
         vector<TreeNode*> left_bsts=solve(start,i-1);
         vector<TreeNode*> right_bsts=solve(i+1,end);

    //pair bnao ki uss particular root ke liye kitne bsts ho skte hai
         for(TreeNode* leftRoot:left_bsts){
             for(TreeNode* rightRoot:right_bsts){

               TreeNode* root=new TreeNode(i);
                root->left=leftRoot;
                root->right=rightRoot;
            //answer mai save krte jao kitne bsts bn rhe hai
                result.push_back(root);
             }
         }
     }
        return mp[{start,end}]=result;
   }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};
