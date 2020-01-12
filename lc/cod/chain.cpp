#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool pos(const vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            if (abs(a[i] - b[j]) > 1)
                return true;
        }
    }

    return false;
}

int solution(vector<int> &A) {
    map<int, vector<int>> m;
    for (int i = 1; i < A.size()-1; ++i)
        m[A[i]].push_back(i);

    for (auto i = m.begin(); i != m.end(); ++i) {
        for (auto j = m.begin(); j != i; ++j) {
            if (pos(i->second,j->second))
                return i->first + j->first;
        }
        if (pos(i->second, i->second))
            return i->first + i->first;
    }

    return 0;
}
int main() {
    vector<int>A={1,1,2,1,2,1};
    cout <<solution(A)<<endl;

}