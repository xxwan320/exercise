class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int number = nums[0] ;
        for(int fast = 0;fast < nums.size();fast ++ ){
            if(nums[fast] == number && fast == 0){
                nums[slow] = nums[fast];
                slow++;
            }
            if(nums[fast] != number && fast != 0){
                nums[slow] = nums[fast];
                slow++;
                number = nums[fast];
            }

        }
        return slow;
    }
};