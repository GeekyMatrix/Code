class RecentCounter {
public:
queue<int>q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
    if(q.size() == 0) {
        q.push(t);
        return 1;
    } 
    else{
        if(t <= 3000) q.push(t);
        else{
        int margin = t - 3000;

        while(q.size()!=0 && q.front() < margin) q.pop();
        q.push(t);
        }
    }
    return q.size();
    }
};
