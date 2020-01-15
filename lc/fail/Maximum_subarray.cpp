
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.


    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int max = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i-1] > 0 ? nums[i-1] : 0;
            if (max < nums[i])
                max = nums[i];
        }
        return max;
    }