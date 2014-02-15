#include <iostream>
#include <map>
#include <assert.h>

using namespace std;

bool allCharsUniqueByMap( const string& s )
{
    map<char, bool> m;
    for ( unsigned i = 0; i < s.length(); i++ )
    {
        char c = s[i];
        if ( m[c] )
        {
            return false;
        }

        m[c] = true;
    }

    return true;
}

bool allCharsUniqueByTypeLess( const string& s )
{
    for ( unsigned int i = 0; i < s.length(); i++ )
    {
        for ( unsigned int j = i + 1; j < s.length(); j++ )
        {
            if ( s[i] == s[j] )
            {
                return false;
            }
        }
    }

    return true;
}

int main( int argc, char *argv[] )
{
    assert( allCharsUniqueByMap( "123" ) == true );
    assert( allCharsUniqueByMap( "1123" ) != true );
    assert( allCharsUniqueByMap( "abcde" ) == true );
    assert( allCharsUniqueByMap( "abcdeda" ) != true );
    assert( allCharsUniqueByMap( "aBb" ) == true );
    assert( allCharsUniqueByMap( "aBbBbB" ) != true );
    assert( allCharsUniqueByMap( " %123 4" ) != true );

    assert( allCharsUniqueByTypeLess( "123" ) == true );
    assert( allCharsUniqueByTypeLess( "1123" ) != true );
    assert( allCharsUniqueByTypeLess( "abcde" ) == true );
    assert( allCharsUniqueByTypeLess( "abcdeda" ) != true );
    assert( allCharsUniqueByTypeLess( "aBb" ) == true );
    assert( allCharsUniqueByTypeLess( "aBbBbB" ) != true );
    assert( allCharsUniqueByTypeLess( " %123 4" ) != true );

    return 0;
}
