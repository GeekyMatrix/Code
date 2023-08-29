/*
Story points
1.When new element comes num[i],make space for it (Window size can't be greater than k)

2.Now,when nums[i] comes there is no need to keep small elements in that window,pop them

3.Now push i in deque->for nums[i]

4.If (i>=k-1),then deque of front is our answer for that window
*/

//TC:-O(N)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
     
        deque<int> deq;

        vector<int> result;
        
        for(int i = 0; i<n; i++) {
            // step:1 remove the max elements from front which are out of window size
            while(!deq.empty() && deq.front() <= i-k)
                deq.pop_front();
            
            //step:2 we maintain the deque in descending order
            while(!deq.empty() && nums[i] > nums[deq.back()])
                deq.pop_back();
            
        step:3 Insert that Element in the deque
            deq.push_back(i);

            if(i >= k-1) //Only when the window size first gets equal or greater than k
                result.push_back(nums[deq.front()]); //front will have the max element (dequeue is maintained in descending order)
        }
        return result;
    }
};

//Approach-2 (Using max-heap (priority_queue)) (worst case :O(n*log(n)) when elements are in ascending order)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> result;

        int n = nums.size();

        for(int i = 0; i<n; i++) {
            
            //remove the max elements which are out of window size
            while(!pq.empty() && pq.top().second <= i-k)
                pq.pop();
            
            pq.push({nums[i], i}); //we will always find the max element at top

            if(i >= k-1)
                result.push_back(pq.top().first);
        }
        return result;
    }
};
