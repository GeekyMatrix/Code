class Solution {
public:
//BRUTE FORCE   
int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long  res = 0;
        for(int i = 0; i < n; i++){
              int minVal = arr[i];

            for(int j = i; j < n; j++){
               minVal = min(minVal , arr[j]);
               res = (res + minVal) % mod;
            }
        }
        return res;
    }

//OPTIMAL
vector<int>getNSL(vector<int>& arr , int n){
    vector<int>res(n);
    stack<int>st;

    for(int i = 0; i < n; i++){
        if(st.empty()) res[i] = -1;

        else {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            res[i] = st.empty() ? -1 : st.top();
        }
        st.push(i);
    }
    return res;
}

vector<int>getNSR(vector<int>& arr , int n){
    vector<int>res(n);
    stack<int>st;

    for(int i = n - 1; i >= 0; i--){
        if(st.empty()) res[i] = n;

        else {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            res[i] = st.empty() ? n : st.top();
        }
        st.push(i);
    }
    return res;
}

int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int>NSL = getNSL(arr,n);
        vector<int>NSR = getNSR(arr,n);

        long long Sum = 0;
         int mod = 1e9+7;

    for(int i = 0; i < n; i++){
        long long ls = i - NSL[i]; //Left me kitne element honge
        long long rs = NSR[i] - i; //Right me kitne element honge

        long long Totalways = ls * rs;

        //Totalways subarrays honge jiska minimum arr[i]

        long long TotalSum =  Totalways * arr[i];

        Sum = (Sum + TotalSum) % mod;
    }
    return Sum;
    }
};
