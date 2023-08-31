class Solution {
public:
//BRUTE FORCE
 int maxProduct(vector<int>& nums) {
  int n=nums.size();
  int max_prod=INT_MIN;

  for(int i=0;i<n;i++){
      int prod=1;
      for(int j=i;j<n;j++){
          prod*=nums[j];
          if(prod > max_prod ) max_prod=prod;
      }
  }
   return max_prod;
 }

//OPTIMAL APRROACH
 int maxProduct(vector<int>& nums) {
  int n=nums.size();
  int max_prod=INT_MIN;

   int prefix=1,suffix=1;

   for(int i=0; i<n; i++){

       if(prefix==0) prefix=1;
       if(suffix==0) suffix=1;

     prefix*=nums[i];
     suffix*=nums[n-i-1];

     max_prod=max(max_prod,max(prefix,suffix));
   }
   return max_prod;
 }
};
