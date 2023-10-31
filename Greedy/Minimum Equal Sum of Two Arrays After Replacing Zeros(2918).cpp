class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long countZeros1 = 0 , countZeros2 = 0;

        for(auto i : nums1){
            sum1 += i;
            if(i == 0) countZeros1++;
        }

            for(auto i : nums2){
            sum2 += i;
            if(i == 0) countZeros2++;
        }
    
if(countZeros1 == 0 && sum1 < countZeros2 + sum2 || countZeros2 == 0 && sum2 < countZeros1 + sum1) return -1;

    return max(sum1 + countZeros1 ,  sum2 + countZeros2);

    }
};
