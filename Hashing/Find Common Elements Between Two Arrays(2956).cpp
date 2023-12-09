class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res(2);
        unordered_map<int,int>m1;
         unordered_map<int,int>m2;
        
        for(auto it : nums1) m1[it]++;
        for(auto it : nums2) m2[it]++;
        
        int cnt1 = 0;
        for( auto i : nums1){
            if(m2.find(i)!= m2.end())  cnt1++;
        }
         res[0] = cnt1;
        
        int cnt2 = 0;
        for( auto i : nums2){
            if(m1.find(i)!= m1.end()) cnt2++;
        }
        
     res[1] = cnt2;
    
    return res;
    }
};
