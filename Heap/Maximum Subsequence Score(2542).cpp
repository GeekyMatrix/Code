class Solution {
public:
 //RECURSIVE METHOD
//Approach 1 (TLE)
   int K;
   int n;
    priority_queue<int,vector<int>,greater<int>>pq;
  
  void removefrompq(int num){
     vector<int>temp;

     while(!pq.empty()){
         int x = pq.top();
         pq.pop();
         if(x == num) break;
         temp.push_back(x);

         for(auto &x:temp) pq.push(x);
     }
  }
   int solve(vector<int>& nums1, vector<int>& nums2, int sum,int min,int i,int count){
   //BASE CASE
   if(count == K) return sum * min;

   if(i >= n) return 0;

   pq.push(nums2[i]);

   int take_i = solve(nums1, nums2, sum + nums1[i], pq.top(), i + 1,count + 1);

   removefrompq(nums2[i]);

   int not_take_i = solve(nums1, nums2, sum, min, i + 1, count);

  return max(take_i, not_take_i);
   }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
      K=k;
      n = nums1.size();
      return solve(nums1,nums2,0,0,0,0);
    }
//Approach 2
bool static comp(pair<int, int>& a, pair<int, int>& b){
   return a.second > b.second;    
}

 long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
 int n =nums1.size();

 vector<pair<int,int>>vec(n);

for(int i = 0;i < n; i++) vec[i] = {nums1[i] , nums2[i]};

sort(vec.begin(), vec.end(),comp);  //Decreasing order mai sort krdia nums2 ko

priority_queue<int,vector<int>,greater<int>>pq; //min heap
   long long ksum = 0; 

for(int i = 0;i <=k-1; i++){
  ksum+= vec[i].first;
  pq.push(vec[i].first);
}
 long long res = ksum * vec[k-1].second;

 for(int i = k; i < n; i++){
 ksum+= vec[i].first - pq.top();
 pq.pop();

 pq.push(vec[i].first);

 res = max(res , ksum * vec[i].second);
 }

 return res;
 }
};
