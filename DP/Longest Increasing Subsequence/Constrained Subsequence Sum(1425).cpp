class Solution {
public:
//Recursive Method
int n;
int K;

int Solve(int prev , int curr , vector<int>& nums){

    if(curr >= n) return 0; //BASE CASE
     
     int res = 0;

     if(prev == -1 || curr - prev <= K){
         
         int take = nums[curr] + Solve(curr , curr + 1, nums);
         
         int not_take = Solve(prev, curr + 1,nums);

         res = max(take , not_take);
     }
            return res;   
}
    int constrainedSubsetSum(vector<int>& nums, int k) {
        n = nums.size();
        K = k;
       
       int val = Solve(-1 , 0 , nums);

       if(val == 0) val = *max_element(nums.begin() , nums.end());

        return val;
    }

//Memoization 
int n;
int K;

unordered_map<string , int>mp;
int Solve(int prev , int curr , vector<int>& nums){

    if(curr >= n) return 0; //BASE CASE
    
    string key = to_string(prev) + "_" + to_string(curr);
     int res = 0;
    
    if(mp.find(key) != mp.end()) return mp[key];

     if(prev == -1 || curr - prev <= K){
         
         int take = nums[curr] + Solve(curr , curr + 1, nums);
         
         int not_take = Solve(prev, curr + 1,nums);

         res = max(take , not_take);
     }
            return mp[key] = res;   
}
    int constrainedSubsetSum(vector<int>& nums, int k) {
        n = nums.size();
        K = k;
       
       int val = Solve(-1 , 0 , nums);

       if(val == 0) val = *max_element(nums.begin() , nums.end());

        return val;
    }

//DP Method
    int constrainedSubsetSum(vector<int>& nums, int k) {
       int n = nums.size();
       vector<int>t(n);
       for(int i = 0; i< n; i++) t[i] = nums[i];
       
       int res = t[0];

       //LIS APPROACH
       for(int i = 1; i < n; i++){
           for(int j = i - 1; j >= 0 && i - j <= k; j--){

               t[i] = max(t[i] , nums[i] + t[j]);
               
               res = max(res , t[i]);
           }
       }
        return res;
    }

//DP + Pq(Optimised)
    int constrainedSubsetSum(vector<int>& nums, int k) {
       int n = nums.size();
       vector<int>t(n);
       for(int i = 0; i< n; i++) t[i] = nums[i];
       
       priority_queue<pair<int,int>>pq;
       pq.push({t[0] , 0});
       
       int res = t[0];

       //LIS APPROACH
       for(int i = 1; i < n; i++){

         while(!pq.empty() && i - pq.top().second > k) pq.pop();
         
               t[i] = max(t[i] , nums[i] + pq.top().first);
               pq.push({t[i] , i});
                
               res = max(res , t[i]);
           }
        return res;
    }
};
