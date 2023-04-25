class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); ++i){
            int left = i+1, right = numbers.size(), mid;
            int target2 = target - numbers[i];

            while(left < right){
                mid = left + (right - left) / 2;
                
                if(numbers[mid] < target2) left = mid + 1;
                else if(numbers[mid] > target2) right = mid;
                else{
                    vector<int> ans{i+1, mid+1};
                    return ans;
                }
            }
        }

        vector<int> ans{-1, -1};
        return ans;
    }
};
