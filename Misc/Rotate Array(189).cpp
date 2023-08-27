//Approach 1
//T.C=O(N),S.C(N)
   void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int>temp(n,0);
    
   if(k>=n) k=k%n;        //JUST TO AVOID THE SAME K REPETITION

int a=0;

for(int i=n-k;i<n;i++) temp[a++]=nums[i];

for(int i=0;i<n-k;i++) temp[a++]=nums[i];

for(int i=0;i<n;i++)   nums[i]=temp[i];
   }

//Approach 2
//T.C=O(N),S.C(1)
  void reverse(vector<int>& nums,int low,int high){
     while(low<high){
         swap(nums[low++],nums[high--]);
     }
  }

  void rotate(vector<int>& nums, int k) {
  int n=nums.size();

  k=k%n;    //IF N<K (toh same chiz repeat hokr wahi aaega usko avoid krne ke liye)

  reverse(nums,0,n-k-1);
  reverse(nums,n-k,n-1);
  reverse(nums,0,n-1);
  }
