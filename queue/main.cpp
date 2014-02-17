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

    Queue( const Queue<T>& q ): head( 0 ), tail( 0 )
    {
        for ( Item<T> *i = q.head; i; i = i->next )
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

// Stack by one Queue
template <class T>
class Stack
{
    Queue<T> q1;
    unsigned c;
public:
    Stack(): c( 0 ){}

    void push( const T &v )
    {
        q1.push( v );
        c++;
    }

    bool empty()
    {
        return c == 0;
    }

    T pop()
    {
        if ( empty() )
        {
            throw "error";
        }

        for ( int i = 0; i < c - 1; i++ )
        {
            q1.push( q1.pop() );
        }

        c--;

        return q1.pop();
    }
};

int main()
{
    {
        Queue<int> q;
        q.push( 1 );
        q.push( 2 );
        q.push( 3 );

        Queue<int> q2( q );
        assert( q2.empty() == false );
        assert( q2.pop() == 1 );
        assert( q2.empty() == false );
        assert( q2.pop() == 2 );
        assert( q2.empty() == false );
        assert( q2.pop() == 3 );
        assert( q2.empty() == true );

        assert( q.empty() == false );
        assert( q.pop() == 1 );
        assert( q.empty() == false );
        assert( q.pop() == 2 );
        assert( q.empty() == false );
        assert( q.pop() == 3 );
        assert( q.empty() == true );

    }

    {
        Queue<TMP> q;
        q.push( TMP(1) );
        q.push( TMP(2) );
        q.push( TMP(3) );

        assert( q.empty() == false );
        assert( q.pop().v == 1 );
        assert( q.empty() == false );
        assert( q.pop().v == 2 );
        assert( q.empty() == false );
        assert( q.pop().v == 3 );
        assert( q.empty() == true );
    }
    {
        Queue<int> q1;
        Queue<int> q2;
        q1.push( 1 );
        q1.push( 2 );
        q1.push( 3 );
        q1.push( 4 );
        q1.push( 5 );
        q1.push( 6 );
        int c = 6;
        while ( !q1.empty() )
        {
            for ( int j = 0; j < c - 1; j++ )
            {
                q1.push( q1.pop() );
            }

            q2.push( q1.pop() );
            c--;
        }

        assert( q2.pop() == 6 );
        assert( q2.pop() == 5 );
        assert( q2.pop() == 4 );
        assert( q2.pop() == 3 );
        assert( q2.pop() == 2 );
        assert( q2.pop() == 1 );


    }
    {
        Stack<int> s;
        s.push( 1 );
        s.push( 2 );
        s.push( 3 );
        s.push( 4 );
        s.push( 5 );
        s.push( 6 );

        assert( s.empty() == false );
        assert( s.pop() == 6 );
        assert( s.pop() == 5 );
        assert( s.pop() == 4 );
        assert( s.pop() == 3 );
        assert( s.pop() == 2 );
        assert( s.pop() == 1 );
        assert( s.empty() == true );

        s.push( 1 );
        s.push( 2 );
        assert( s.pop() == 2 );
        s.push( 3 );
        s.push( 4 );
        assert( s.pop() == 4 );
        assert( s.pop() == 3 );
        s.push( 5 );
        assert( s.pop() == 5 );
        assert( s.pop() == 1 );
        assert( s.empty() == true );


    }

}
