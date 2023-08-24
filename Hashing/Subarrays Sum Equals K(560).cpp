class Solution {
public:
//Approach 1(Subarrays method)
//TC=O(N^2)
//SC=O(0)
int subarraySum(vector<int>& arr, int k) {
  int n=arr.size();
  int Subarrays_cnt=0;

for(int i=0;i<n;i++){
  int sum=0;
  for(int j=i;j<n;j++){
    sum+=arr[j];
    if(sum==k) Subarrays_cnt++;
  }
}
  return Subarrays_cnt++;
}

////Approach 2(Prefix Sum method)
//TC=O(N)
//SC=O(N)
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int,int>m; // {prefixSum,cnt}
      m[0]=1;  //for prefixSum 0 the cnt is 1 we should have be takecare of it..
  
      int Prefixsum=0,cnt=0;
      
        for(int i=0;i<arr.size();i++){
           Prefixsum+=arr[i];
          int remove=Prefixsum-k;

          cnt+=m[remove]; // if remove will be present in the map it will a subarrays
       
          m[Prefixsum]++; // mark the increment for the paricular Prefixsum value in the map
        }
      return  cnt;
    }
};
