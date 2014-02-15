#include <iostream>
#include <assert.h>

using namespace std;

template < unsigned n >
void print( int (&img)[n][n] )
{
    for ( unsigned i = 0; i < n; i++ )
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
    int n = 3;
    int img[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    int nimg[3][3];

    print<3>( img );
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < n; j++ )
        {
            nimg[j][n-i-1] = img[i][j];
        }
    }

    cout << endl;
    print<3>( nimg );
}

void img4()
{
    int n = 4;
    int img[4][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
    int nimg[4][4];


    print<4>( img );
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < n; j++ )
        {
            nimg[j][n-i-1] = img[i][j];
        }
    }
    cout << endl;
    print<4>( nimg );
}

int main( int argc, char *argv[] )
{
    img3();
    cout << endl;
    img4();
    return 0;
}
