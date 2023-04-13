class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int area_max = min(height[left], height[right]) * (right-left);
        int area_cur;

        while(left != right){
            if(height[left] <= height[right]) left++;
            else right--;
            area_cur = min(height[left], height[right]) * (right-left);
            if(area_cur > area_max) area_max = area_cur;
        }

        return area_max;
    }
};
