class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<int>res;
         vector<vector<int>>store;

         for(int i = 0; i <= rowIndex; i++){
             vector<int>temp(i + 1 , 1);

             for(int j = 1; j < i; j++)  temp[j] = store[i - 1][j -1] + store[i - 1][j]; //Fill the choice dig.
             
             if( i == rowIndex){
              res = temp;
              break;
             }

              store.push_back(temp);
         }
         return res;
    }
};
