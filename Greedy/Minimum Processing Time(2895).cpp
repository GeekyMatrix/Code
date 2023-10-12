class Solution {
public:
static bool comp(int a,int b){
    return a > b;
}
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(),tasks.end(),comp); //sort krdia descending order mai
        sort(processorTime.begin(),processorTime.end()); //sort krdia ascending order mai

        int n = tasks.size();
        int res = INT_MIN;
        
        int i = 0, j = 0;

        while(i < n){
         res = max(res , processorTime[j] + tasks[i]);

         i+=4; // jump to next 4
         j++;
        }
        return res;
    }
};
