class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int diff=target-nums[i];
          //MIL GAYA TOH ANSWER MAI PUSH KARO
            if(m.find(diff)!=m.end()){
             ans.push_back(i);
             ans.push_back(m[diff]);
            }
            //INSER KARO MAP MAI
            else m[nums[i]]=i;
        }
     return ans;
    }
};
