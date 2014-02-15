#include <assert.h>
#include <iostream>

class TMP
{

public:
    int v;
    TMP( int i ): v( i ) {}
};


template <class T>
struct Node
{
    T data;
    Node *next;
    Node *rand;
    Node( const T &v ): data( v ), next( 0 ), rand( 0 ) {}
};

template <class T>
struct List
{
    Node<T> *head;
    Node<T> *tail;
    unsigned size;

    List(): head( 0 ), tail( 0 ), size( 0 ){}
    List( const List<T> &list ): head( 0 ), tail( 0 ), size( 0 )
    {
        copy( list );
    }

    ~List()
    {
        removeAll();
    }

    void copy( const List<T> &list )
    {
        for ( auto i = list.head; i; i = i->next )
        {
            append( i->data );
        }
    }

    bool empty()
    {
        return head == 0;
    }

    Node<T> *append( const T &v )
    {
        auto n = new Node<T>( v );
        if ( empty() )
        {
            head = tail = n;
            size = 1;
            return n;
        }

        tail->next = n;
        tail = n;
        size++;

        return n;
    }

    const Node<T> *find( const T &v ) const
    {
        for ( auto i = head; i; i = i->next )
        {
            if ( i->data == v )
            {
                return i;
            }
        }

        return 0;
    }

    bool remove( const T &v )
    {
        auto prev = head;
        for ( auto i = head; i; i = i->next )
        {
            if ( i->data == v )
            {
                prev->next = i->next;
                if ( i == head )
                {
                    head = i->next;
                }
                if ( i == tail )
                {
                    tail = prev;
                }

                delete i;
                size--;

                return true;
            }
            prev = i;
        }

        return false;
    }

    bool removeAll()
    {
        auto i = head;
        while ( i )
        {
            auto next = i->next;
            delete i;
            size--;

            i = next;
        }

        head = tail = 0;
        return size == 0;
    }

    unsigned removeAllDuplicates()
    {
        unsigned c = 0;
        for ( auto i = head; i; i = i->next )
        {
            auto prev = i;
            for ( auto j = i->next; j; j = j->next )
            {
                if ( i->data != j->data )
                {
                    prev = j;
                    continue;
                }

                if ( j == tail )
                {
                    tail = prev;
                }

                prev->next = j->next;
                delete j;

                size--;
                c++;
                prev = j;
            }
        }

        return c;
    }

    void copyTo( List<T> &list )
    {
        auto current = head;
        while ( current )
        {
            Node<T> *n = new Node<T>( current->data );

            n->next = current->next;
            current->next = n;

            current = n->next;
        }

        current = head;
        while ( current )
        {
            current->next->rand = current->rand->next;
            current = current->next->next;
        }

        current = head;
        while ( current )
        {
            if ( current == head )
            {
                list.head = current->next;
            }

            auto next = current->next;
            current->next = current->next ? current->next->next : 0;
            current = next;
        }

        for ( auto i = list.head; i; i = i->next )
        {
            list.size++;
        }
    }

};

int main()
{
   {
        List<int> list;
        list.append( 1 );
        list.append( 2 );
        list.append( 3 );
        assert( list.size == 3 );

        auto f = list.find( 2 );
        assert( f != 0 );
        assert( f->data == 2 );

        List<int> list2( list );
        assert( list2.empty() == false );
        assert( list2.size == 3 );
        assert( list2.find( 1 ) != 0 );
        assert( list2.find( 2 ) != 0 );
        assert( list2.find( 3 ) != 0 );

        assert( list.remove( 2 ) );
        assert( list.size == 2 );
        assert( list.find( 2 ) == 0 );
        assert( list.find( 3 ) != 0 );

        list.removeAll();
        assert( list.size == 0 );
        assert( list.find( 1 ) == 0 );

        assert( list2.size == 3 );

    }

    {
        List<TMP> list;
        list.append( TMP(1) );
        list.append( TMP(2) );
        list.append( TMP(3) );

        assert( list.empty() == false );
        assert( list.size == 3 );
        assert( list.removeAll() );
        assert( list.size == 0 );
    }

    {
        List<int> list;
        list.append( 1 );
        list.append( 2 );
        list.append( 3 );

        assert( list.removeAllDuplicates() == 0 );
        assert( list.size == 3 );
        assert( list.find( 1 ) != 0 );
        assert( list.find( 2 ) != 0 );
        assert( list.find( 3 ) != 0 );

        list.append( 2 );

        assert( list.size == 4 );
        assert( list.removeAllDuplicates() == 1 );

        assert( list.size == 3 );
        assert( list.find( 1 ) != 0 );
        assert( list.find( 2 ) != 0 );
        assert( list.find( 3 ) != 0 );

        list.append( 1 );
        list.append( 2 );
        list.append( 3 );

        assert( list.size == 6 );
        assert( list.removeAllDuplicates() == 3 );
    }

    {
        List<int> list1;
        auto n1 = list1.append( 1 );
        auto n2 = list1.append( 2 );
        auto n3 = list1.append( 3 );
        auto n4 = list1.append( 4 );
        n1->rand = n4;
        n2->rand = n1;
        n3->rand = n4;
        n4->rand = n2;

        List<int> list2;
        list1.copyTo( list2 );
        assert( list1.size == 4 );
        assert( list2.size == 4 );
        auto b1 = list2.find( 1 );
        auto b2 = list2.find( 2 );
        auto b3 = list2.find( 3 );
        auto b4 = list2.find( 4 );

        assert( b1->rand == b4 );
        assert( b2->rand == b1 );
        assert( b3->rand == b4 );
        assert( b4->rand == b2 );


    }

}
