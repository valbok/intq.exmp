#include <assert.h>
#include <iostream>

template<class T>
class Stack;

template <class T>
class Item
{
    Item( const T &t ): value( t ), next( 0 ) {}
    T value;
    Item *next;
    friend class Stack<T>;
};

template <class T>
class Stack
{
    Item<T> *head;
    Item<T> *tail;

    void append( const T &v )
    {
        Item<T> *i = new Item<T>( v );
        if ( empty() )
        {
            head = tail = i;
            return;
        }

        head->next = i;
        head = i;
    }

public:
    Stack(): head( 0 ), tail( 0 ) {}

    Stack( const Stack<T>& stack ): head( 0 ), tail( 0 )
    {
        for ( Item<T> *i = stack.tail; i; i = i->next )
        {
            append( i->value );
        }
    }

    bool empty() const
    {
        return tail == 0;
    }

    void push( const T &v )
    {
        Item<T> *i = new Item<T>( v );
        if ( empty() )
        {
            head = tail = i;
            return;
        }

        i->next = tail;
        tail = i;
    }

    T pop()
    {
        auto p = tail;
        tail = tail->next;
        auto v = p->value;
        delete p;
        return v;
    }

    ~Stack()
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

template <class T>
class Queue
{
    Stack<T> s1;
    Stack<T> s2;
    unsigned c;
public:
    Queue(): c( 0 ){}

    void push( const T &v )
    {
        s1.push( v );
        c++;
    }

    bool empty()
    {
        return c == 0;
    }

    T pop()
    {
        while ( !s1.empty() )
        {
            s2.push( s1.pop() );
        }

        auto v = s2.pop();
        while ( !s2.empty() )
        {
            s1.push( s2.pop() );
        }

        c--;
        std::cout << "pop " << v << std::endl;
        return v;
    }


};
int main()
{
    {
        Stack<int> stack;
        stack.push( 1 );
        stack.push( 2 );
        stack.push( 3 );

        Stack<int> stack2( stack );
        assert( stack2.empty() == false );
        assert( stack2.pop() == 3 );
        assert( stack2.empty() == false );
        assert( stack2.pop() == 2 );
        assert( stack2.empty() == false );
        assert( stack2.pop() == 1 );
        assert( stack2.empty() == true );

        assert( stack.empty() == false );
        assert( stack.pop() == 3 );
        assert( stack.empty() == false );
        assert( stack.pop() == 2 );
        assert( stack.empty() == false );
        assert( stack.pop() == 1 );
        assert( stack.empty() == true );

    }

    {
        Stack<TMP> stack;
        stack.push( TMP(1) );
        stack.push( TMP(2) );
        stack.push( TMP(3) );

        assert( stack.empty() == false );
        assert( stack.pop().v == 3 );
        assert( stack.empty() == false );
        assert( stack.pop().v == 2 );
        assert( stack.empty() == false );
        assert( stack.pop().v == 1 );
        assert( stack.empty() == true );
    }

    {
        Stack<int> stack;
        stack.push( 1 );
        stack.push( 2 );
        stack.push( 3 );

        Stack<int> stack2;

        while ( !stack.empty() )
        {
            stack2.push( stack.pop() );
        }

        assert( stack2.empty() == false );
        assert( stack2.pop() == 1 );
        assert( stack2.pop() == 2 );
        assert( stack2.pop() == 3 );

    }

    {
        Queue<int> q;
        q.push( 1 );
        q.push( 2 );
        q.push( 3 );
        q.push( 4 );

        assert( q.empty() == false );
        assert( q.pop() == 1 );
        assert( q.pop() == 2 );
        assert( q.pop() == 3 );
        assert( q.pop() == 4 );
        assert( q.empty() == true );

        q.push( 1 );
        q.push( 2 );
        assert( q.pop() == 1 );
        q.push( 3 );
        assert( q.pop() == 2 );
        q.push( 4 );
        assert( q.pop() == 3 );
        assert( q.pop() == 4 );
        assert( q.empty() == true );




    }
}
