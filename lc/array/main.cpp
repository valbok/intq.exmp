Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

int removeDuplicates(vector<int>& nums) {
        int len = nums.empty() ? 0 : 1;
        //nums = [[0],[0],1,1,1,2,2,3,3,4],
        //nums = [[0],1,[1],1,1,2,2,3,3,4],
        //nums = [0,[1],1,[1],1,2,2,3,3,4],
        //nums = [0,[1],1,1,[1],2,2,3,3,4],
        //nums = [0,[1],2,1,1,[2],2,3,3,4],
        //nums = [0,1,[2],2,1,2,[2],3,3,4],
        //nums = [0,1,[2],3,1,2,2,[3],3,4],
        //nums = [0,1,2,[3],3,2,2,3,[3],4],
        //nums = [0,1,2,[3],4,2,2,3,3,[4]],
        
        //nums = [[1],[1],2],
        //nums = [[1],1,[2]],
        for (int i = 1;i<nums.size();++i) {            
            if (nums[i] != nums[len-1]) {
                ++len;
                nums[len-1] = nums[i];
            }
        
        }
        return len;
    }
***
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

    int rec(vector<int> &prices, int i, int d, int max, int s = 1)
    {
        //cout <<"i:"<<i<<" d:"<<d<<" max:"<<max<<endl;
        if (d > max)
            max = d;
        for (int j = i + 1; j<prices.size(); ++j) {
            int dd = d + (prices[j]*s);
            //cout <<"  j:"<<j<<" "<<d<<(s>0?"+":"-")<<prices[j]<<"="<<dd<<endl;
            if (s > 0 && dd > 0 ||s < 0)  
                max = rec(prices, j, dd, max, 0-s);
        }
        return max;
    }
    int maxProfit(vector<int>& prices) {
        int max = 0;
        for (int i = 0; i < prices.size(); ++i) {
            //cout <<":"<<prices[i]<<endl;            
            int d = 0 - prices[i];
            int r = rec(prices, i, d, max, 1);
            if (r>max)
                max = r;
        }
        return max;
    }
***
Given an array, rotate the array to the right by k steps, where k is non-negative.


***
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

***
Given a non-empty array of integers, every element appears twice except for one. Find that single one.
***
Given two arrays, write a function to compute their intersection.

***
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

    vector<int> plusOne(vector<int>& digits) {
        bool b = false;
        for (int i = digits.size()-1; i>=0;--i) {
            ++digits[i];
            if (digits[i]<10) {
                b = true;
                break;
            }
            
            digits[i] %= 10;
        }
        if (!b)
            digits.insert(digits.begin(), 1);
        
        return digits;
        
    }

***
Given an array nums, write a function to move all 0s to the end of it while maintaining the relative order of the non-zero elements.
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        // 1 2 *4 0 0
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                if (j != i) {
                    nums[j] = nums[i];
                    nums[i] = 0;
                }
                
                ++j;
            }
        }
        
        
    }

***
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,vector<int>>m;
        // 3 2 4:  6
        // 3 3: 6
        for (int i = 0; i<nums.size();++i) {
            m[nums[i]].push_back(i);
            int v = target - nums[i];
            auto itv = m.find(v);
            if (itv != m.end())
                for (int a: itv->second) {
                    if (a!=i)
                        return {a, i};
                }
            
        }
        return {};
    }
***
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

bool isValidSudoku(vector<vector<char>>& board) {
        int width[9][10] = {0};
        int height[9][10] = {0};

        for (int h = 0; h < 9; h += 3) {
            for (int w = 0; w < 9; w += 3) {
                int vv[10] = {0};
                for (int i = h; i < h + 3; ++i) {
                    for (int j = w; j < w + 3; ++j) {
                        if (board[i][j] == '.')continue;
                        int v = board[i][j] - '0';
                        if (vv[v] != 0) {
                            return false;
                        }
                        ++vv[v];
                        if (width[i][v] != 0){
                            return false;
                        }
                        width[i][v] += 1;
                        if (height[j][v] != 0){
                            return false;
                        }
                        height[j][v] += 1;

                    }
                }
            }
        }

        return true;
    }
***
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0;i<n-1;++i) {
            for (int j=i;j<n-i-1;++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = tmp;
            }
        }
    }