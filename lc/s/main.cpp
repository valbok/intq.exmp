Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        int i = m - 1, j = n - 1, k = nums1.size() - 1;
        while (k>=0) {
            if (i>=0 && j>=0 && nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            } else if (j>=0)  {
                nums1[k--] = nums2[j--];
            } else break;
        }

    }
****

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

int firstBadVersion(int n) {
        int b = 0;
        int e = n;
        while (b < e) {
            int m = b + (e - b) / 2;
            if (isBadVersion(m)) {
                e = m;
            } else {
                b = m + 1;
            }
        }

        return e;
    }
