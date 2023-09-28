class Solution {
public:
//Approach 1(Iteration)

vector<int> sortArrayByParity(vector<int>& nums) {
int j = 0;

for(int i = 0; i < nums.size(); i++){
    if(nums[i] % 2 == 0) {//even
     swap(nums[i] , nums[j]);
     j++;
    }
}
 return nums;
}

//Approach 2(Sorting)
static bool comp(int &a, int &b){
    return a % 2 < b % 2; // if a % 2 will be even then it return a else it return b
}
vector<int> sortArrayByParity(vector<int>& nums) {
sort(nums.begin() , nums.end(), comp);

return nums;
}

//Approach 3(Two pointer)
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0,j = nums.size()-1;

        while(i < j){
            if(nums[i] % 2 != 0 && nums[j] % 2 ==0) {
                swap(nums[i++], nums[j--]);
            }
            if(nums[i] % 2 == 0) i++;
            if(nums[j] % 2 !=0) j--;
        }
    return nums;
    }
};
