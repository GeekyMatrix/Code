class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();

         vector<int>ans(n);
         stack<int>st;

         for(int i=n-1;i>=0;i--){
             while(!st.empty() && temperatures[i]>=temperatures[st.top()]) st.pop();

             if(st.empty()) ans[i]=0; // aage koi bada temperature nhi hai
             else ans[i]=st.top()-i;  // days

             st.push(i);  // haar ek temp. day ka entry kardo  
         }
         return ans;
    }
};
