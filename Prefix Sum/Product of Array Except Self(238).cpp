class Solution {
public:
// Time Complexity : O(N), Space complexity : O(N)
    vector<int> productExceptSelf(vector<int>& nums) {
         int n=nums.size();
          vector<int>Pref_prod_start(n);
           vector<int>Pref_prod_end(n);
        vector<int>ans(n);
      
      Pref_prod_start[0]=nums[0];
        for(int i=1;i<n;i++)  Pref_prod_start[i]= Pref_prod_start[i-1]*nums[i];

       Pref_prod_end[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)  Pref_prod_end[i]= Pref_prod_end[i+1]*nums[i];
       
       ans[0]= Pref_prod_end[1];
       ans[n-1]=Pref_prod_start[n-2];

       for(int i=1;i<n-1;i++) ans[i]=Pref_prod_start[i-1]* Pref_prod_end[i+1];

        return ans;
    }

//  Time Complexity : O(N), Space complexity : O(1)
  vector<int> productExceptSelf(vector<int>& nums) {
           int n=nums.size();
        vector<int>ans(n,1);

         int productOfAllbeforeCurrent=1;
        for(int i=0;i<n;i++){
        ans[i]= productOfAllbeforeCurrent;
        productOfAllbeforeCurrent*=nums[i];
        }

       int productofAllAfterCurr=1;
        for(int i=n-1;i>=0;i--){
        ans[i]*=productofAllAfterCurr;
       productofAllAfterCurr*=nums[i];
        }
        
        return ans;
  }
};
