class Solution{
public:
    string repeatLimitedString(string s, int repeatLimit){
        string ans;
        int nr = 0;
        char cur = '0';
        priority_queue<char> pq;

        for(char &c: s){
            pq.push(c);
        }

        while(!pq.empty()){
            if(cur != pq.top()){
                ans += pq.top();
                cur = pq.top();
                pq.pop();
                nr = 1;
            }else{
                if(nr == repeatLimit){
                    pq.pop();
                    if(pq.empty()){
                        break;
                    }else if(cur == pq.top()){
                        int tmp = 1;
                        while(!pq.empty() && cur == pq.top()){
                            ++tmp;
                            pq.pop();
                        }
                        if(pq.empty())
                            break;
                        ans += pq.top();
                        pq.pop();
                        while(tmp > repeatLimit){
                            for(int i = 0; i < repeatLimit; ++i){
                                ans += cur;
                            }
                            tmp -= repeatLimit;
                            if(!pq.empty()){
                                ans += pq.top();
                                if(tmp == 0){
                                    cur = pq.top();
                                    nr = 1;
                                }
                                pq.pop();
                            }else{
                                break;
                                // double loop! only break inner loop :(
                            }
                        }
                        if(pq.empty())
                            break;
                        nr = tmp;
                        while(tmp--){
                            ans += cur;
                        }
                    }else{
                        ans += pq.top();
                        ans += cur;
                        pq.pop();
                        nr = 1;
                    }
                }else{
                    ans += pq.top();
                    pq.pop();
                    ++nr;
                }
            }
            
        }

        return ans;
    }
};
