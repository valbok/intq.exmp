You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

int climb_Stairs(int i, int n, vector<int> &v) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        if (i+1>v.size() - 1){

            v.push_back(-1);
        }
        if (i+2>v.size() - 1) {

            v.push_back(-1);
        }
        int ii = v[i+1];
        if (ii == -1) {
            ii = climb_Stairs(i + 1, n, v);
            v[i+1] = ii;


        } else {

        }
        int jj = v[i+2];
        if (jj == -1) {
            jj = climb_Stairs(i + 2, n, v);
            v[i+2] = jj;
        }
        return ii + jj;
    }
  int climbStairs(int n) {
        vector<int> v = {-1};
        return climb_Stairs(0, n, v);
    }


     dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];

****
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.



 int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int max = nums[0];
        // -2,1,-3,4,-1,2,1,-5,4
        //    1,-2,4, 3,5,6,1 ,5
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i - 1] > 0 ? nums[i - 1] : 0;
            if (nums[i] > max)
                max = nums[i];
        }
        //
        return max;


    }

***
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

    int maxProfit(vector<int>& prices) {
        int min = prices.empty() ? 0 : prices[0];
        int r = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < min) {
                min = prices[i];
                continue;
            }
            int d = prices[i] - min;
            if (d > r)
                r = d;
        }

        return r;
    }


*****
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.


int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        // 2,7, 9, 3, 1
        // 2 7 11  11 12
        int max = nums[0];
        if (nums[1] < max)
            nums[1] = max;
        else
            max = nums[1];
        for (int i = 2; i < nums.size(); ++i) {
            int m = nums[i] + (nums[i-2] > 0 ? nums[i-2] : 0);
            if (m > max)
                max = m;
            nums[i] = max;
        }
        return max;
    }