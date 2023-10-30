class Solution {
public://Approach 1
static int countOnebits(int num){
        int count = 0;
        while (num) {
            
            count += num & 1;
            
            num >>= 1;
        }
        
        return count;
        
}
static bool comp(int &a , int & b){
 
 if(countOnebits(a) == countOnebits(b)) return  a < b ; // jo chota value hoga usko ascending mai rkh do
 return countOnebits(a) < countOnebits(b); // jo chota 1 bits hoga usko ascending mai rkh do

}
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }

//Approach 2

static bool comp(int &a , int & b){
 
if(__builtin_popcount(a) == __builtin_popcount(b)) return  a < b ; // jo chota value hoga usko ascending mai rkh do
 return __builtin_popcount(a) < __builtin_popcount(b); // jo chota 1 bits hoga usko ascending mai rkh do

}
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }

};
