class SmallestInfiniteSet {
public:
priority_queue<int,vector<int>,greater<int>>pq;
set<int>s;

    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++){
            pq.push(i);
            s.insert(i);
        }
    }
    
    int popSmallest() {
        int smallest = pq.top();
        pq.pop();
        s.erase(smallest);
        return smallest;
    }
    
    void addBack(int num) {
        if(s.find(num) == s.end()){ // if nu, is not present in the set
        s.insert(num);
        pq.push(num);
        }
    }
};
