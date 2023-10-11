class Solution {
public:
//BRUTE FORCE
//TC = o(n * m)
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = people.size();
        int m = flowers.size();
        vector<int>res(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int start = flowers[j][0];
                int end = flowers[j][1];

                if(people[i] >= start && people[i] <= end)  res[i]++;
            }
        }
        return res;
    }

//Approach-2 (Using Binary Search)
//T.C : O((m+n) * log(n))
//S.C : O(m)
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n = people.size();
        
        vector<int> result(n);
        
        vector<int> start_time(m);
        vector<int> end_time(m);
        
        for(int i = 0; i<m; i++) {
            start_time[i] = flowers[i][0];
            end_time[i]   = flowers[i][1];
        }
        
        sort(begin(start_time), end(start_time));
        sort(begin(end_time), end(end_time));
        
        for(int i = 0; i<n; i++) {
     int bloomed_already = upper_bound(begin(start_time), end(start_time), people[i]) - begin(start_time);
            
    int died_already  = lower_bound(begin(end_time), end(end_time), people[i]) - begin(end_time);

         result[i] = bloomed_already - died_already;
            
        }
        
        return result;
    }
};
