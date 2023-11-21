class Solution {
public:
//BRUTE FORCE
int MOD = 1e9 + 7; 
int cnt = 0;

int rev(int n){
    int reversed_number = 0, remainder;
  while(n != 0) {
    remainder = n % 10;
    reversed_number = reversed_number * 10 + remainder;
    n /= 10;
  }
   return reversed_number;
}
    int countNicePairs(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])) cnt++;
            }
        }
        return cnt % MOD;
    }

//OPTIMAL CODE

int MOD = 1e9 + 7; 
int cnt = 0;

int rev(int n){
    int reversed_number = 0, remainder;
  while(n != 0) {
    remainder = n % 10;
    reversed_number = reversed_number * 10 + remainder;
    n /= 10;
  }
   return reversed_number;
}

    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(int i = 0; i < nums.size(); i++){
                int diff = nums[i] - rev(nums[i]);

                if(mp.find(diff) != mp.end()) cnt = (cnt + mp[diff]) % MOD; // already exist

                mp[diff]++; //for new entry
            
        }
        return cnt % MOD;
    }
};
