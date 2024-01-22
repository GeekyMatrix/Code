class Solution {
public:
//Approach1
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>res(2);
        int n = nums.size();

        vector<int>store(n+1,0);

        for(int i = 0; i < n; i++) store[nums[i]]++;

        for(int i = 1; i < store.size(); i++){
            if(store[i] == 2) res[0] = i;
            if(store[i] == 0) res[1] = i;
        }
        return res;
    }

//Approach2
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>res(2);
        unordered_map<int,int>mp;
        
        for(int i = 1; i <= nums.size(); i++) mp[i]++;

        for(auto &num : nums) mp[num]--;

        for(auto it : mp){
            if(it.second == -1) res[0] = it.first;  //Duplicate
             if(it.second == 1) res[1] = it.first;  //missing
        }
        return res;
    }
};
