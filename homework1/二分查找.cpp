class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
    while(left <= right){ //等号保证查找到右边界
        int middle = left + (right - left) / 2;  // 防止溢出
        if(nums[middle] < target){
            left = middle +1;
        }
        if(nums[middle] > target){
            right = middle - 1;
        }
        if(nums[middle] == target){
        return middle;
        }
         
    }
    return -1;
    }
};