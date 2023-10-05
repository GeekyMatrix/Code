class Solution {
public:
//BRUTE FORCE (TLE)
    vector<int> majorityElement(vector<int>& arr) {
        set<int>s;
        vector<int>res;
 int n = arr.size();

 for(int i=0;i<n;i++){
     //Take one Element from Array (say,Element)
     int ele = arr[i];
     int cnt = 0;

     for(int j = 0; j < n; j++){
         if(arr[j] == ele) cnt++;
     }
     if(cnt > n/3)   s.insert(arr[i]);
 }
  for(auto &i : s)    res.push_back(i);
  
  return res;
    }

//Optimise method (moore's Voting algorithm)
 //TC=O(N)
 //SC=O(1)
     vector<int> majorityElement(vector<int>& nums) {
          int n = nums.size();
        
        int maj1 = NULL;
        int count1 = 0;

        int maj2  = NULL;
        int count2 = 0;
        
        for(int i = 0; i<n; i++) {
            if(nums[i] == maj1) count1++;
            else if(nums[i] == maj2)  count2++;
            else if(count1 == 0) {
                 maj1 = nums[i];
                 count1 = 1;
            } else if(count2 == 0) {
                maj2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
      vector<int> result; //because atmost two elements can occur more than ⌊ n/3 ⌋ in an array of length n
        count1 = 0;
        count2 = 0;
        for(int num:nums) {
            if(num == maj1) count1++;
            else if(num == maj2) count2++;
        }

        if(count1 > (n/3)) result.push_back(maj1);
        if(count2 > (n/3)) result.push_back(maj2);
        return result;
    }
};
