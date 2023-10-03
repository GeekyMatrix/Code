class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt = 0;
        unordered_map<int,int>m;

        for(auto &i : nums){
          cnt+=m[i];
          m[i]++;
        } 
        return cnt;
    }
};
