#include <assert.h>
#include <iostream>

template<class T>
class Vector;

template <class T>
class Item
{
    Item( const T &t ): value( t ), next( 0 ) {}
    T value;
    Item *next;
    friend class Vector<T>;
};

template <class T>
class Vector
{
    unsigned c;
    // Array of pointers to Item
    Item<T>** items;

public:
    Vector(): c( 0 ) {}

    Vector( const Vector<T> &list ): c( 0 )
    {
        for ( unsigned i = 0; i < list.size(); i++ )
        {
            append( list.at( i ) );
        }
    }

    void append( const T &v )
    {
        c++;
        Item<T> **tms = new Item<T>*[c];
        for ( unsigned i = 0; i < c - 1; i++ )
        {
            tms[i] = items[i];
        }

        tms[c - 1] = new Item<T>( v );
        items = tms;
    }

    bool empty() const
    {
        return c == 0;
    }

    T at( unsigned i ) const
    {
        return items[i]->value;
    }

    ~Vector()
    {
        for ( unsigned i = 0; i < c; i++ )
        {
            delete items[i];
        }
    }

    unsigned size() const
    {
        return c;
    }
};

class TMP
{

public:
    int v;
    TMP():v(0){}
    TMP( int i ): v( i ) {}
};

int main()
{
    {
        Vector<int> list;
        list.append( 1 );
        list.append( 2 );
        list.append( 3 );

        Vector<int> list2( list );
        assert( list2.size() == 3 );
        assert( list2.at(0) == 1 );
        assert( list2.at(1) == 2 );
        assert( list2.at(2) == 3 );

        assert( list.size() == 3 );
        assert( list.at(0) == 1 );
        assert( list.at(1) == 2 );
        assert( list.at(2) == 3 );

    }

    {
        Vector<TMP> list;
        list.append( TMP(1) );
        list.append( TMP(2) );
        list.append( TMP(3) );

        assert( list.size() == 3 );
        assert( list.at(0).v == 1 );
        assert( list.at(1).v == 2 );
        assert( list.at(2).v == 3 );
    }


}
