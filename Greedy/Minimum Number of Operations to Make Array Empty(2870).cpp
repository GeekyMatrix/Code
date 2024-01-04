class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;
        unordered_map<int,int>mp; //frequency ->count
        
        for(int i = 0; i < nums.size(); i++) mp[nums[i]]++; //store krwa li values ko
        
        for(auto &i : mp){
          int count = i.second;
            
            if(count < 2) return -1;
            
            operations+= ((count+2) / 3); // pehle 3 ke multiply mai divide krke dekhenge
        }
        return operations;
    }
};
