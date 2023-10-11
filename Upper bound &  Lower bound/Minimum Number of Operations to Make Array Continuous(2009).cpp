class Solution {
public:
//BRUTE FORCE
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int res = INT_MAX;

        for(int i = 0; i < n; i++){
         int L = nums[i];  //L -> minm
         int R = L + n - 1;//R ->maxm
         
         int operations = 0;
         unordered_set<int>used;

         for(int j = 0; j < n; j++){

           if(nums[j] >= L && nums[j] <= R && used.find(nums[j]) == used.end()){ 
            used.insert(nums[j]);
            continue;
           } 

           else operations++;

         }
         res = min(res,operations);
        }
     return res;
    }

//OPTIMISE 
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int res = INT_MAX;
        
        set<int>st(nums.begin(), nums.end()); //sort karega sath hi unique element bhi rkhega
        vector<int>temp(st.begin() , st.end());

        for(int i = 0; i < temp.size(); i++){
         int L = temp[i];  //L -> max
         int R = L + n - 1; //R->maxm

         int j = upper_bound(temp.begin(),temp.end(),R) - temp.begin();

         int within_Range = j - i;
         int out_of_range = n - within_Range; // operations 

         res = min(res,out_of_range);
        }
     return res;
    }
};
