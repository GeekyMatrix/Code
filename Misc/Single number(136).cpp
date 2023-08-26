class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto it:nums){ 
            //A^0=A
            //A^A=0
            
          ans^=it;
        }
        return ans;
    }
};
