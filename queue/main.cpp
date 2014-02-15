#include <assert.h>
#include <iostream>

template<class T>
class Queue;

template <class T>
class Item
{
    Item( const T &t ): value( t ), next( 0 ) {}
    T value;
    Item *next;
    friend class Queue<T>;
};

template <class T>
class Queue
{
    Item<T> *head;
    Item<T> *tail;

public:
    Queue(): head( 0 ), tail( 0 ) {}

    Queue( const Queue<T>& list ): head( 0 ), tail( 0 )
    {
        for ( Item<T> *i = list.head; i; i = i->next )
        {
            push( i->value );
        }
    }

    bool empty() const
    {
        return head == 0;
    }

    void push( const T &v )
    {
        Item<T> *i = new Item<T>( v );
        if ( empty() )
        {
            head = tail = i;
            return;
        }

        tail->next = i;
        tail = i;
    }

    T pop()
    {
        auto p = head;
        head = head->next;
        auto v = p->value;
        delete p;
        return v;
    }

    ~Queue()
    {
        while( !empty() )
        {
            pop();
        }
    }
};

class TMP
{

public:
    int v;
    TMP( int i ): v( i ) {}
};

int main()
{
    {
        Queue<int> list;
        list.push( 1 );
        list.push( 2 );
        list.push( 3 );

        Queue<int> list2( list );
        assert( list2.empty() == false );
        assert( list2.pop() == 1 );
        assert( list2.empty() == false );
        assert( list2.pop() == 2 );
        assert( list2.empty() == false );
        assert( list2.pop() == 3 );
        assert( list2.empty() == true );

        assert( list.empty() == false );
        assert( list.pop() == 1 );
        assert( list.empty() == false );
        assert( list.pop() == 2 );
        assert( list.empty() == false );
        assert( list.pop() == 3 );
        assert( list.empty() == true );

    }

    {
        Queue<TMP> list;
        list.push( TMP(1) );
        list.push( TMP(2) );
        list.push( TMP(3) );

        assert( list.empty() == false );
        assert( list.pop().v == 1 );
        assert( list.empty() == false );
        assert( list.pop().v == 2 );
        assert( list.empty() == false );
        assert( list.pop().v == 3 );
        assert( list.empty() == true );
    }


}
