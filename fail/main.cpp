#include <iostream>
#include <vector>
using namespace std;
     int climb_Stairs(int i, int n, vector<int> &v) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        if (i+1>v.size() - 1){
            cout <<"1 "<<v.size()<<endl;
            v.push_back(-1);
        }
        if (i+2>v.size() - 1) {
            cout <<"2 "<<v.size()<<endl;
            v.push_back(-1);
        }
        int ii = v[i+1];
        if (ii == -1) {
            ii = climb_Stairs(i + 1, n, v);
            v[i+1] = ii;
            cout <<ii<<":"<<v[i+1];
            for (auto a:v)cout<<a<<" ";cout<<endl;
        } else {
            cout << i+1<<":"<<ii<<endl;
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
int main() {
cout <<climbStairs(6)<<endl;
//cout <<cc(7 )<<endl;

}