class SmallestInfiniteSet {
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    SmallestInfiniteSet() {
        n = 1;
    }
    
    int popSmallest() {
        int tmp;
        
        if(!pq.empty()){
            tmp = pq.top();
            while(!pq.empty() && pq.top() == tmp) pq.pop();
        }else{
            tmp = n;
            n++;
        }

        return tmp;
    }
    
    void addBack(int num) {
        if(n > num){
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
