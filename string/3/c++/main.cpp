#include <iostream>
#include <assert.h>
#include <string.h>
#include <map>

using namespace std;

string removeChar( string s, unsigned i )
{
    string r;
    for ( unsigned ii = 0; ii < s.length(); ++ii )
    {
        if ( ii == i )
        {
            continue;
        }

        r += s[ii];
    }

    return r;
}

string removeDuplicates( string s )
{
    unsigned len = s.length();
    for ( unsigned i = 0; i < len; ++i )
    {
        for ( unsigned j = i + 1; j < len; ++j )
        {
            if ( s[i] == s[j] )
            {
                return removeDuplicates( removeChar( s, j ) );
            }
        }
    }

    return s;
}

int main( int argc, char *argv[] )
{
    assert( removeDuplicates( "1123" ) == "123" );
    assert( removeDuplicates( "11223" ) == "123" );
    assert( removeDuplicates( "112233" ) == "123" );
    assert( removeDuplicates( "1232" ) == "123" );
    assert( removeDuplicates( "112233333333333" ) == "123" );
    assert( removeDuplicates( "112233333333333222233331111" ) == "123" );
    assert( removeDuplicates( "abacd" ) == "abcd" );

    return 0;
}
