#include <iostream>
#include <fstream>
#include "QueueList.hpp"
#include "SeqList.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::ifstream;

class ListTree
{
public:
    class Node
    {
        friend class ListTree;
    public:
        Node(char k)
            :data(k)
            {
            }
        char data;
    private:
        SeqList<Node*> child;
    };
    
    ListTree()
        :root(0)
        {   
        }
    ~ListTree()
        {
        }
    void insert(char f, char k)
        {
            Node* fa = find(f);
            if (!fa)
            {
                root = new Node(f);
                fa = root;
            }
            fa->child.pushBack(new Node(k));
        }
    void prevTrav()
        {
            for (SeqList<ListTree::Node*>::Node* p = root->child.first(); p; p = root->child.nextPos(p))
            {
                pretrav(p->data);
                cout << endl;
            }
        }

private:
    void pretrav(Node* r)
        {
            cout << r->data << " ";
            for (SeqList<ListTree::Node*>::Node* p = r->child.first(); p; p = r->child.nextPos(p))
            {
                pretrav(p->data);
            }
        }

    Node* find(char k)
        {
            if (!root)
            {
                return 0;
            }
            else
            {
                return search(root, k);
            }
        }
    Node* search(const Node* t, char k)
        {
            if (t -> data == k)
            {
                return const_cast<Node*>(t);
            }

            Node* it;
            for (SeqList<ListTree::Node*>::Node* p = t->child.first(); p; p = t->child.nextPos(p))
            {
                it = search(p->data, k);
                if (it)
                {
                    return it;
                }
            }
            return 0;
        }

    Node* root;
};

void build(ListTree& T, ifstream& in)
{
    char t;
    int n;
    in >> n;
    for (int i = 0; i < n; i++)
    {
        in >> t;
        char s;
        s = in.get();
        while (s != '\n')
        {
            if (s == ' ')
            {
                s = in.get();
                continue;
            }
            T.insert(t, s);
            s = in.get();
        }
    }
}
int main()
{
    ListTree T;
    ListTree T2;
    ifstream in("tree3.in", ios::in);

    build(T, in);
    T.prevTrav();

    T2.insert('Z', 'A');
    T2.insert('Z', 'J');
    build(T2, in);
    T2.prevTrav();

    return 0;
}
