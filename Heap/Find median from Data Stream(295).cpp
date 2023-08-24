class MedianFinder {
public:
//Approach-1 (O(n^2) - TLE

 vector<int> vec;
    int i = 0;
    MedianFinder() {
        vec.resize(5*10000+1);
    }
    
    void addNum(int num) {
        if(i == 0) {
            vec[i++] = num;
            return;
        }
        int j = i-1;
        while(j >= 0 && vec[j] > num) {
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = num;
        i++;
    }
    
    double findMedian() {
        int n = i;
        if(n%2 == 0) {
            int l = n/2-1;
            int r = n/2;
            return (float)(vec[l]+vec[r])/2;
        }
        
        return vec[n/2];
    }

//Approach-2 (O(logn) insertion using priority_queue)
priority_queue<int>left_max_heap; //Max heap
priority_queue<int,vector<int>,greater<int>>right_min_heap; //Min heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max_heap.empty() || num < left_max_heap.top()) left_max_heap.push(num);
        else right_min_heap.push(num);

 //Always maintain left_max_heap size one greater than right_min_heap size 
 //ya phir ,dono ka size equal ho

 if(abs ((int) left_max_heap.size() - (int) right_min_heap.size() )>1) {
  right_min_heap.push(left_max_heap.top());
  left_max_heap.pop();
 }

 else if(left_max_heap.size()<right_min_heap.size()){
  left_max_heap.push(right_min_heap.top());
  right_min_heap.pop();
 }
    }
    
    double findMedian() {
       if(left_max_heap.size()==right_min_heap.size()) {
           //Matlab even no.of hue honge
          return (double)(left_max_heap.top()+right_min_heap.top())/2;
       }
        //else hamare pass odd no. of hue honge
        return left_max_heap.top();
    }
}; 
