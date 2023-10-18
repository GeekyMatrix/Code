class Solution {
public:
//BRUTE FORCE(TLE)
    vector<int> findIndices(vector<int>& nums, int iD, int vD) {
        
     int n = nums.size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(abs(i - j) >= iD && abs(nums[i] - nums[j]) >= vD) return {i,j};
            }
        }
        return {-1, -1};
    }

//OPTIMISED 
    vector<int> findIndices(vector<int>& nums, int iD, int vD) {
        
     int n = nums.size();
     map<int,vector<int>>mp;

        for(int i = iD; i < n; i++) mp[nums[i]].push_back(i); 

        for(int i = 0; i < (n - iD); i++){ 

        int  minm = mp.begin()->first; 
        int idx_minm = mp.begin()->second[0];

        int maxm = prev(mp.end())->first;
        int idx_maxm = prev(mp.end())->second[0];

        if(abs(nums[i] - minm) >= vD) return {i , idx_minm};

        if(abs(nums[i] - maxm) >= vD) return {i , idx_maxm};
     
     //MAP SE ENTRY DELETE KRO
        if(mp[nums[i + iD]].size() > 1)    mp[nums[i + iD]].erase(mp[nums[i + iD]].begin()); //Ek delete krdo

        else   mp.erase(nums[i + iD]); //pura delete krdo

        }
        return {-1, -1};
    }
};
