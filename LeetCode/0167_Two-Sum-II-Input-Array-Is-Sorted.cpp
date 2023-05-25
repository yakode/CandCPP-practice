// two pointers
class Solution{
public:
    vector<int> twoSum(vector<int> &numbers, int target){
        int left = 0, right = numbers.size() - 1;

        while(left < right){
            int sum = numbers[left] + numbers[right];
            
            if(sum < target) left++;
            else if(sum > target) right--;
            else return vector<int> {left+1, right+1};
        }

        return vector<int> {-1, -1};
    }
};

// binary search
class Solution{
public:
    vector<int> twoSum(vector<int> &numbers, int target){
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
