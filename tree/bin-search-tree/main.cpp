#include <iostream>
#include <stack>
#include <assert.h>

using namespace std;

class Node
{
public:
    Node *p;
    Node *left;
    Node *right;
    int value;
    Node(int v = 0 ): p(0), left(0), right(0), value( v ){}

};

class Tree
{
public:
    Node *head;

    Tree(): head( 0 ){}
    void printTree() const
    {
        printSubtree( head );
    }

    static void printSubtree( const Node *n, std::string s = "" )
    {
        if ( n == 0 )
        {
            return;
        }

        std::cout << s << n->value << std::endl;
        printSubtree( n->left, "l " );
        printSubtree( n->right, "r " );
    }

    int height()
    {
        int i = 0;
        findHeight( head, i );

        return i;
    }

    static void findHeight( const Node *n, int &i, int d = 0 )
    {
        if ( n == 0 )
        {
            return;
        }

        if ( d > i )
        {
            i = d;
        }

        findHeight( n->left, i, d + 1 );
        findHeight( n->right, i, d + 1 );
    }

    void insert( const int v )
    {
        Node *n = new Node( v );
        if ( head == 0 )
        {
            head = n;
            return;
        }

        Node *leaf = head;
        Node *prev = 0;
        while ( leaf )
        {
            prev = leaf;
            leaf = v < leaf->value ? leaf->left : leaf->right;
        }

        n->p = prev;
        if ( v < prev->value )
        {
            prev->left = n;
        }
        else
        {
            prev->right = n;
        }
    }


};


int main()
{
    {
        Tree t;
        t.insert( 10 );
        t.insert( 4 );
        t.insert( 17 );
        t.insert( 1 );
        t.insert( 5 );
        t.insert( 16 );
        t.insert( 21 );
        t.printTree();
        assert( t.height() == 2 );
    }

    {
        Tree t;
        t.insert( 10 );
        t.insert( 5 );
        t.insert( 17 );
        t.insert( 4 );
        t.insert( 1 );
        t.insert( 16 );
        t.insert( 21 );
        t.printTree();
        assert( t.height() == 3 );

    }

    {
        Tree t;
        t.insert( 16 );
        t.insert( 10 );
        t.insert( 17 );
        t.insert( 5 );
        t.insert( 4 );
        t.insert( 1 );
        t.insert( 21 );
        t.printTree();
        assert( t.height() == 4 );
    }

    {
        Tree t;
        t.insert( 17 );
        t.insert( 16 );
        t.insert( 21 );
        t.insert( 10 );
        t.insert( 5 );
        t.insert( 4 );
        t.insert( 1 );
        t.printTree();
        assert( t.height() == 5 );
    }

    {
        Tree t;
        t.insert( 21 );
        t.insert( 17 );
        t.insert( 16 );
        t.insert( 10 );
        t.insert( 5 );
        t.insert( 4 );
        t.insert( 1 );
        t.printTree();
        assert( t.height() == 6 );
    }

    return 0;
}
