#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

string reverse( const string& s )
{
    string r;
    for ( int i = s.length() - 1; i >= 0; --i )
    {
        r += s[i];
    }

    return r;
}

char* reverseC( const char* s )
{
    unsigned len = strlen( s );
    char* r = new char[len];
    for ( int i = len - 1; i >= 0; --i )
    {
        r[len - i - 1] = s[i];
    }

    return r;
}

int main( int argc, char *argv[] )
{
    assert( reverse( "123" ) == "321" );
    assert( reverse( "1234" ) == "4321" );
    assert( reverse( "12345678" ) == "87654321" );
    assert( reverse( "123456789" ) == "987654321" );

    assert( string( reverseC( "123" ) ) == string( "321" ) );
    assert( string( reverseC( "1234" ) ) == string( "4321" ) );
    assert( string( reverseC( "12345678" ) ) == string( "87654321" ) );
    assert( string( reverseC( "123456789" ) ) == string( "987654321" ) );

    return 0;
}
