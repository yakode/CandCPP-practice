class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int len = pushed.size();
        /*
	 * check the element of "popped" one by one
	 * push the element of "pushed" into stack until meet the current element of "popped"
	 * then pop it from stack
	 * if I can pop all the element of stack
	 * "popped" is  valid
	 */
	for(int i = 0, j = 0; i < len; ++i){
            // i for popped
            // j for pushed
            while(j < len && (s.empty() || s.top() != popped[i])) s.push(pushed[j++]);
            if(!s.empty() && s.top() == popped[i]) s.pop();
        }
        if(!s.empty()) return false;
        return true;
    }
};
