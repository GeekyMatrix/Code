//Approach 2
//Sliding window
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        
        int result = 0;
        
        int l = 0;

        long currSum = 0;

        for(int r = 0; r < n; r++){

        long target = nums[r];

        currSum+= nums[r];

 while((r - l + 1) * target - currSum > k){ //window shrink ,,,, while ke jagah if se bhi kaam hojaega
        currSum-= nums[l];
        l++;
        } 
         
         result = max(result , (r - l + 1)); //shi window hai
        }
        return result;
    } 
