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

class BTree
{
public:
    Node *head;

    void printTree() const
    {
        printSubtree( head );
        std::cout << "--" << std::endl;
        printSubtreeN( head );
    }

    static void printSubtree( const Node *n )
    {
        if ( n == 0 )
        {
            return;
        }

        std::cout << n->value << std::endl;
        printSubtree( n->left );
        printSubtree( n->right );
    }

    static void printSubtreeN( const Node *n )
    {
        std::stack<const Node*> s;
        const Node *current = n;
        while ( 1 )
        {
            std::cout << n->value << std::endl;
            if ( n->right )
                s.push( n->right );
            if ( n->left )
                s.push( n->left );

            n = !s.empty() ? s.top() : 0;
            if ( !n )
            {
                break;
            }

            s.pop();
        }
    }

    const Node *search( const int v ) const
    {
        return searchNode( head, v );
    }

    const Node *searchNode( const Node *n, const int v ) const
    {
        if ( !n )
        {
            return 0;
        }

        if ( n->value == v )
        {
            return n;
        }

        const Node *l = searchNode( n->left, v );
        if ( l )
        {
            return l;
        }

        const Node *r = searchNode( n->right, v );

        return r;
    }

    static void insertNode( Node *n, Node *v )
    {
        if ( n->p->left == n )
        {
            n->p->left = v;
            v->left = n;
            return;
        }

        n->p->right = v;
        v->right = n;
    }

};

int main()
{
    Node root;
    BTree t;
    t.head = &root;

    Node l1(1);
    l1.p = &root;
    Node r1(2);
    r1.p = &root;

    root.left = &l1;
    root.right = &r1;

    Node l2(3);
    l2.p = &l1;
    Node r2(4);
    r2.p = &l1;

    l1.left = &l2;
    l1.right = &r2;

    Node l3(5);
    l3.p = &r1;
    Node r3(6);
    r3.p = &r1;

    r1.left = &l3;
    r1.right = &r3;

    t.printTree();
    const Node *r = 0;

    r = t.search( 4 );
    assert( r->value == 4 );
    r = t.search( 10 );
    assert( r == 0 );

    r = t.search( 0 );
    assert( r->value == 0 );


    Node l12( 10 );
    Node r12( 20 );
    BTree::insertNode( &l1, &l12 );
    std::cout <<"insert"<<std::endl;
    t.printTree();
    BTree::insertNode( &r1, &r12 );
    std::cout <<"insert"<<std::endl;
    t.printTree();

    Node l12r(11);
    l12.right = &l12r;

    Node r12l(22);
    r12.left = &r12l;
    std::cout <<"insert"<<std::endl;
    t.printTree();

    return 0;
}
