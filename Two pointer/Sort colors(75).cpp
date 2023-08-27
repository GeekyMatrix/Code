class Solution {
public:
// Approach 1
void sortColors(vector<int>& nums) {
 sort(nums.begin(),nums.end());
}

//Approach 2
//TC=O(2N)
  void sortColors(vector<int>& nums) {
     int n=nums.size();

    int f=0,s=0,t=0;

    for(int i=0;i<n;i++){  //sbka count kr lia
        if(nums[i]==0) f++;
        else if(nums[i]==1) s++;
        else t++;
    }

   for(int i=0;i<f;i++) nums[i]=0;

   for(int i=f;i<f+s;i++) nums[i]=1;

   for(int i=f+s;i<f+s+t;i++) nums[i]=2;
  }

//Approach 3
// TC=O(N)
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0,m=0,h=n-1;
        while(m<=h){
         int X=nums[m];
         if(X==0){
             swap(nums[l],nums[m]);
             l++;
             m++;
         }
         else if(X==1) m++;
         else{
             swap(nums[h],nums[m]);
             h--;
         }
        }
    }
};
