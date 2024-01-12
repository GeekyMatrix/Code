class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        set<int> store1 , store2 , common;
        
        for(auto &it: nums1){
            store1.insert(it);
            common.insert(it);
        }
        
            for(auto &it: nums2){
            store2.insert(it);
            common.insert(it);
        }
        
        int res = min(min(n/2 , (int)store1.size()) + min(n/2 , (int)store2.size()) , (int)common.size());
        
        return res;
    }
};
