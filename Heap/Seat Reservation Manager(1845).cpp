// class SeatManager {
// public:
//Approach-1 - Reducing the time taken by reserve (Accepted)
//T.C : O((m+n) * logn)
//S.C : O(n)

 priority_queue<int,vector<int>,greater<int>>pq; //Min heap
    SeatManager(int n) {
        for(int i = 1; i <= n; i++) pq.push(i);
    }
    
    int reserve() {
        int x = pq.top();
        pq.pop();
        return x;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
        return;
    }
// };

//Approach-2 (Improving Approach-2) - Avoiding pre-initialising of heap
//T.C : O(m* log(n)) , where m = number of reserve calls
//S.C : O(n)
class SeatManager {
public:
 priority_queue<int,vector<int>,greater<int>>pq; //Min heap
 int seat_marker;
    SeatManager(int n) {
       seat_marker = 1;
    }
    
    int reserve() {
        if(!pq.empty()){
        int x = pq.top();
        pq.pop();
        return x;
    }
    
    int seat = seat_marker;
    seat_marker++;
    return seat;

    }
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
        return;
    }
};
