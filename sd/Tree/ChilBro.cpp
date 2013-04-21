#include <iostream>
#include <fstream>
#include "QueueList.hpp"


using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::ifstream;

class ChilBro
{
public:
    class Node
    {
        friend class ChilBro;
    public:
        Node(char k)
            :data(k),child(0),bro(0)
            {
            }
        char data;
    private:
        Node* child;
        Node* bro;
    };
    
    ChilBro()
        :root(0)
        {   
        }
    ~ChilBro()
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
            Node* sn = new Node(k);
            sn -> bro = fa -> child;
            fa -> child = sn;
        }
    void prevTrav()
        {
            pretrav(root);
            cout << endl;
        }
    void postTrav()
        {
            posttrav(root);
            cout << endl;
        }
    void bfs()
        {
            QueueList<Node*> mQ;
            mQ.enQueue(root);

            Node* r;
            while (!mQ.isEmpty()) //breadth-first traversal,while the queue is not empty,travel the queue's head node;
            {
                r = mQ.deQueue();
                cout << r->data << " ";
                for (Node* p = r -> child; p; p = p -> bro)
                {
                    mQ.enQueue(p);
                }
            }
            cout << endl;
        }

private:
    void pretrav(Node* r)
        {
            cout << r->data << " ";
            for (Node* p = r -> child; p; p = p -> bro)
            {
                pretrav(p);
            }
        }
    void posttrav(Node* r)
        {
            for (Node* p = r -> child; p; p = p -> bro)
            {
                pretrav(p);
            }
            cout << r->data << " ";
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
            for (Node* p = t -> child; p; p = p -> bro)
            {
                it = search(p, k);
                if (it)
                {
                    return it;
                }
            }
            return 0;
        }

    Node* root;
};

int main()
{
    ifstream in("tree2.in", ios::in);
    ChilBro T;
    char t;

    while (in >> t)
    {
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

    T.prevTrav();
    T.postTrav();
    T.bfs();

    return 0;
}
