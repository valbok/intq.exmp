#include <assert.h>
#include <iostream>

class ListIntItem
{
    int value;
    ListIntItem* next;
    ListIntItem(): value( 0 ), next( 0 ) {}
    friend class ListInt;
};

class ListInt
{
    ListIntItem* head;
    ListIntItem* tail;

public:
    ListInt(): head( 0 ), tail( 0 ) {}

    ListInt( const ListInt& list ): head( 0 ), tail( 0 )
    {
        for ( ListIntItem* i = list.tail; i; i = i->next )
        {
            push( i->value );
        }
    }

    void push( const int v )
    {
        ListIntItem *i = new ListIntItem();
        i->value = v;
        if ( empty() )
        {
            head = tail = i;
            return;
        }

        head->next = i;
        head = i;
    }

    bool empty() const
    {
        return tail == 0;
    }

    int pop()
    {
        int v = tail->value;
        auto next = tail->next;

        delete tail;
        tail = next;

        return v;
    }

    ~ListInt()
    {
        while( !empty() )
        {
            pop();
        }
    }

};

template<class T>
class List;

template <class T>
class ListItem
{
    ListItem( const T &t ): value( t ), next( 0 ) {}
    T value;
    ListItem *next;
    friend class List<T>;
};

template <class T>
class List
{
    ListItem<T> *head;
    ListItem<T> *tail;

public:
    List(): head( 0 ), tail( 0 ) {}

    List( const List<T>& list ): head( 0 ), tail( 0 )
    {
        for ( ListItem<T> *i = list.tail; i; i = i->next )
        {
            push( i->value );
        }
    }

    bool empty() const
    {
        return tail == 0;
    }

    void push( const T &v )
    {
        ListItem<T> *i = new ListItem<T>( v );
        if ( empty() )
        {
            head = tail = i;
            return;
        }

        head->next = i;
        head = i;
    }

    T pop()
    {
        T v = tail->value;
        auto next = tail->next;

        delete tail;
        tail = next;

        return v;
    }

    ~List()
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
        ListInt list;
        list.push( 1 );
        list.push( 2 );
        list.push( 3 );

        ListInt list2( list );
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
        List<int> list;
        list.push( 1 );
        list.push( 2 );
        list.push( 3 );

        List<int> list2( list );
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
        List<TMP> list;
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
