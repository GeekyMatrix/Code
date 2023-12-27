class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        int n = colors.size();

        for(int i = 0; i < n - 1; i++) {
            if(colors[i] == colors[i+1]) {

                int j = i, maxi = neededTime[i] , sum = 0;

                while(j < n && colors[i] == colors[j]){
                    sum += neededTime[j];
                    maxi = max(maxi , neededTime[j]);
                    j++;
                }
                  res += (sum - maxi);
                  i = j - 1;
            }
        }

        return res;;
    }
};
