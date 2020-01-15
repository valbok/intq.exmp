Given an array of integers, find the subset of non-adjacent elements with the maximum sum. Calculate the sum of that subset.

For example, given an array  we have the following possible subsets:


Subset      Sum
[-2, 3, 5]   6
[-2, 3]      1
[-2, -4]    -6
[-2, 5]      3
[1, -4]     -3
[1, 5]       6
[3, 5]       8

int maxSubsetSum(vector<int> arr) {
    if (arr.size() < 3) return 0;

    int max = arr[0];
    if (arr[0] > arr[1])
        arr[1] = arr[0];
    else
        max = arr[1];
    for (int i = 2; i < arr.size(); ++i) {
        int m = arr[i] + (arr[i-2] > 0 ? arr[i-2] : 0);
        arr[i] = m > max ? m : max;
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}