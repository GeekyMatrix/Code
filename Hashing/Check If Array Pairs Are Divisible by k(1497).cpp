class Solution {
public:
    bool canArrange(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

         int n = nums.size();
        
        if(n % 2) return false;
        
        for(auto x : nums){
         
         x = ((x % k) + k) % k; 

         mp[x]++; 
        }
        
         if(mp[0]%2==1)    return false;
    
        for(int i = 1; i < k; i++){
            if(mp[i] != mp[k-i]) return false; // ladka + ladki == 0 for making the pair
        }
        return true;
    }
};
