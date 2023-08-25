class Solution {
public:
//Approach 1
    int largestRectangleArea(vector<int>& heights) {
        int res=INT_MIN;
        int n=heights.size();
        
        for(int i=0;i<n;i++){
          int curr=heights[i];

          //Usse left wale dekh lo
          for(int j=i-1;j>=0;j--){
              if(heights[j]>=heights[i]) curr+=heights[i];
              else break;
          }

         //Usse right wale dekh lo
          for(int j=i+1;j<n;j++){
          if(heights[j]>=heights[i]) curr+=heights[i];
          else break;
          }

         res=max(res,curr);
        }
        return res;
    }

//Approach 2
vector<int> previous_smaller(vector<int>& heights){ //Next smaller element
    int n=heights.size();
    vector<int>ans;
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() &&  heights[st.top()]>=heights[i]) st.pop();

        int ele=(st.empty())?-1:st.top();
        ans.push_back(ele);
        st.push(i);
    }
    return ans;
}

vector<int> next_smaller(vector<int>& heights){  //next greater element
    int n=heights.size();
    vector<int>ans;
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() &&  heights[st.top()]>=heights[i]) st.pop();

        int ele=(st.empty())? n:(st.top());
        ans.push_back(ele);
        st.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

 int largestRectangleArea(vector<int>& heights) {
     int res=0;
  
  vector<int>ps=previous_smaller(heights);
  vector<int>ns=next_smaller(heights);
 
 for(int i=0;i<heights.size();i++){
  int curr_area=(ns[i]-ps[i]-1)*heights[i];
  
  res=max(res,curr_area);
 }
 return res;
 }
};
