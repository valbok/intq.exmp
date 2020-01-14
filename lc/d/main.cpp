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
