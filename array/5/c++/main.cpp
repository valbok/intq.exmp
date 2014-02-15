#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

template < unsigned m, unsigned n >
void print( int (&img)[m][n] )
{
    for ( unsigned i = 0; i < m; i++ )
    {
        for ( unsigned j = 0; j < n; j++ )
        {
            int v = img[i][j];
            if ( v < 10 )
            {
                cout << "0";
            }
            cout << v << " ";
        }

        cout << endl;
    }
}

void img3()
{
    int m = 5;
    int n = 3;
    int img[5][3] = { {1,2,3}, {4,0,6}, {7,8,9}, {0,11,12}, {13,14,15} };

    print<5, 3>( img );
    int li = 110; int lj = 110;
    for ( int i = 0; i < m; i++ )
    {
        for ( int j = 0; j < n; j++ )
        {
            if ( img[i][j] == 0 && i != li && j != lj )
            {
                li = i;
                lj = j;
                for ( int ii = 0; ii < m; ii++ )
                {
                    std::cout << "clear [" << ii << "][" <<j <<"]"<<std::endl;
                    img[ii][j] = 0;
                }

                for ( int jj = 0; jj < n; jj++ )
                {
                    std::cout << "clear [" << i << "][" <<jj <<"]"<<std::endl;
                    img[i][jj] = 0;
                }
            }
        }
    }

    cout << endl;
    print<5,3>( img );
}

int main( int argc, char *argv[] )
{
    int ii[199];
    cout << ii[1] << endl;
    vector<int> iv = {1,2};
    cout << iv[0];
    //img3();
    cout << endl;
    return 0;
}
