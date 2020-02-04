
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
