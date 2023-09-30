class Solution {
public:
//TC = O(N^3)  (TLE) 
//SC = O(1)
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){

           if(nums[j] > nums[i]){

               for(int k = j+1; k < n; k++){

               if(nums[k] < nums[j] && nums[k] > nums[i]) return true;
               }
           }
        }
        }
         return false;
    }

//TC = O(N^2)
//SC = O(1)
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
         int mini_i = INT_MAX;

        for(int j = 0; j < n-1; j++){

           mini_i = min(mini_i , nums[j]);

               for(int k = j+1; k < n; k++){

               if(nums[k] < nums[j] && nums[k] > mini_i) return true;
               }
           }
         return false;
    }

//TC = O(N)
//SC = O(N)
bool find132pattern(vector<int>& nums) {
 int n = nums.size();
 stack<int>st;

 int num3 = INT_MIN; 

 for(int i = n-1; i>=0; i--){
  if(nums[i] < num3) return true;

  while(!st.empty() && st.top() < nums[i]){
  num3 = st.top();
  st.pop();
  }

  st.push(nums[i]);
 }
 
 return false;
}
};
