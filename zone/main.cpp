#include <iostream>
#include <cassert>
#include <climits>
#include <algorithm>
#include <cstdlib>
#include <sys/resource.h>

using namespace std;

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int q = 1;
    int r = 2;
    for (int p = 0; p < A.size() - 2; ++p) {
        q = p + 1;
        r = q + 1;
        if (A[r] < A[p] + A[q]) {
            break;
        }
    }

    for (int p = 0; p < q; ++p) {
        int s = A[p] + A[q];
        int l = abs(A[p] - A[q]);
        if (A[r] < s && A[r] > l) {
            return s + A[r];
        }
    }

    return -1;
}

int slow_solution(vector<int> &A) {
    int min = INT_MAX;
    for (int p = 0; p < A.size() - 2; ++p) {
        for (int q = p + 1; q < A.size() - 1; ++q) {
            int s = A[p] + A[q];
            int l = abs(A[p] - A[q]);
            for (int r = q + 1; r < A.size(); ++r) {
                if (A[r] < s && A[r] > l) {
                    int sum = A[p] + A[q] + A[r];
                    if (sum < min) {
                        min = sum;
                    }
                }
            }
        }
    }

    return min == INT_MAX ? -1 : min;
}

int main() {
    {
        vector<int> v = {10, 2, 5, 1, 8, 20};
        int s = solution(v);
        int ss = slow_solution(v);  
        assert(s == 23);
        assert(s == ss);
    }

    {
        vector<int> v = {10, 2, 5, 1, 8, 20, 2, 12};
        int s = solution(v);
        int ss = slow_solution(v);  
        assert(s == 5);
        assert(s == ss);
    }

    {
        vector<int> v = {1, 2, 3, 5, 5, 6, 8};
        int s = solution(v);
        int ss = slow_solution(v);  
        assert(s == 11);
        assert(s == ss);
    }

    {
        vector<int> v = {100, 2, 5, 9, 50, 1, 80, 20, 100, 59, 50, 23, 21, 150};
        int s = solution(v);
        int ss = slow_solution(v);  
        assert(s == 43);
        assert(s == ss);
    }

    {
        vector<int> v = {2, 10, 5, 1, 10, 8, 25, 100, 3, 59, 50, 21, 150};
        int s = solution(v);
        int ss = slow_solution(v);  
        assert(s == 21);
        assert(s == ss);
    }
    {
        vector<int> v;
        for (int i = 0; i < 1000; ++i) {
            v.push_back(rand() % 1000000);
        }
        int s = solution(v);
        int ss = slow_solution(v); 
        assert(s == ss);
    }

    {
        vector<int> v;
        int n = 100000;
        for (int i = 0; i < n; ++i) {
            v.push_back(rand() % 1000000);
        }
        float userTime;
        struct rusage startTime, stopTime;

        getrusage(RUSAGE_SELF, &startTime);

        (void)solution(v);
        
        getrusage(RUSAGE_SELF, &stopTime);
        userTime =
            ((float)(stopTime.ru_utime.tv_sec - startTime.ru_utime.tv_sec)) +
            ((float)(stopTime.ru_utime.tv_usec - startTime.ru_utime.tv_usec)) * 1e-6;

        cout << "Time on " << n << " items is " << userTime << " seconds" << endl;

    }
}
