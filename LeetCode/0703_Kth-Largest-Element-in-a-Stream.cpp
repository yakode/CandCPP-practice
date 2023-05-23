// implement min heap
class KthLargest{
public:
    vector<int> min_heap;
    int n; // size of heap
    int k;

    void heap_push(int val){
        min_heap[n++] = val;
        
        int i = n-1;
        while(i > 0){
            if(min_heap[i] < min_heap[i/2]){
                swap(min_heap[i], min_heap[i/2]);
            }else{
                break;
            }

            i /= 2;
        }
    }

    void heap_pop(){
        if(n == 0) return;

        min_heap[0] = min_heap[--n];

        int i = 0;
        while(i < n){
            if(i * 2 + 1 < n){
                if(min_heap[i * 2 + 1] < min_heap[i * 2]){
                    if(min_heap[i * 2 + 1] < min_heap[i]){
                        swap(min_heap[i * 2 + 1], min_heap[i]);
                        i = i * 2 + 1;
                    }else{
                        break;
                    }
                }else{
                    if(min_heap[i * 2] < min_heap[i]){
                        swap(min_heap[i * 2], min_heap[i]);
                        i = i * 2;
                    }else{
                        break;
                    }
                }
            }else if(i * 2 < n){
                if(min_heap[i * 2] < min_heap[i]){
                    swap(min_heap[i * 2], min_heap[i]);
                    i = i * 2;
                }else{
                    break;
                }
            }else{
                break;
            }
        }
    }

    KthLargest(int k, vector<int> &nums){
        this->min_heap.resize(10001);
        this->n = 0;
        this->k = k;

        for(int i = 0; i < nums.size(); ++i){
            heap_push(nums[i]);
        }

        while(n > k){
            heap_pop();
        }
    }
    
    int add(int val){
        if(n < k){
            heap_push(val);
        }else if(val > min_heap[0]){
            heap_pop();
            heap_push(val);
        }

        return min_heap[0];
    }
};


// priority_queue
class KthLargest{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

    KthLargest(int k, vector<int> &nums){
        this->k = k;

        for(int i = 0; i < nums.size(); ++i){
            pq.push(nums[i]);
        }

        while(pq.size() > k){
            pq.pop();
        }
    }

    int add(int val){
        if(pq.size() < k){
            pq.push(val);
        }else if(val > pq.top()){
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }
};
