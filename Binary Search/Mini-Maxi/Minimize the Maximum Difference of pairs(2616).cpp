class Solution {
public:
int n;
bool is_valid(vector<int>& nums,int mid,int p){
  
  int i=0;
  int count_pairs=0;
  
  while(i<n-1){
      if(nums[i+1]-nums[i]<=mid) {
           count_pairs++;
           i+=2;   //ek pair le liya
      }
      else i++;   //pair nhi liya 
  }
    return count_pairs>=p;
}
    int minimizeMax(vector<int>& nums, int p) {
        n=nums.size();
        int result=INT_MAX;
        sort(nums.begin(),nums.end());
        int l=0,r=nums[n-1]-nums[0];

        while(l<=r){
            int mid=l+(r-l)/2;

            if(is_valid(nums,mid,p)){
                result=mid;
                r=mid-1;   //aur minimum ke side jaenge
            }
            else l=mid+1;  
        }
        return result;
    }
};
