/*
Located on a line are N segments, numbered from 0 to N − 1, whose positions are given in arrays A and B. For each I (0 ≤ I < N) the position of segment I is from A[I] to B[I] (inclusive). The segments are sorted by their ends, which means that B[K] ≤ B[K + 1] for K such that 0 ≤ K < N − 1.
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
    int solution(vector<int> &A, vector<int> &B) {
        if (A.empty())return 0;
        int prev = B[0];
        int c = 1;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] > prev) {
                ++c;
                prev = B[i];
            }
        }
        return c;
    }
int main() {
    vector<int>A={1,3,7,9,9};    vector<int>B={5,6,8,9,10};
    //vector<int>A={1,3,7,2,9};    vector<int>B={5,6,8,4,11};
cout <<solution(A,B)<<endl;
//cout <<cc(7 )<<endl;

}