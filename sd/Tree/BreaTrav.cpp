#include <iostream>
#include <string>
#include "ListStack.hpp"
#include "QueueList.hpp"

using std::string;
using std::cout;
using std::endl;
using std::cin;

class BinTree
{
public:
    BinTree()
        {
            ls = 0;
            rs = 0;
        }
    BinTree(const string& mEle, BinTree* lt, BinTree* rt)
        {
            data = mEle;
            ls = lt;
            rs = rt;
        }

    void bfs()
        {
            QueueList<BinTree*> mQ;

            BinTree* root = this;
            mQ.enQueue(root);

            while (!mQ.isEmpty()) //breadth-first traversal,while the queue is not empty,travel the queue's head node;
            {
                root = mQ.deQueue();
                cout << root -> data << " ";
                if (root -> ls)
                {
                    mQ.enQueue(root -> ls);
                }
                if (root -> rs)
                {
                    mQ.enQueue(root -> rs);
                }
            }
        }

    ~BinTree()
        {
            delete ls;
            delete rs;
        }

    string data;
    BinTree* ls;
    BinTree* rs;
};

BinTree* createBT()
{
    char ch;
    cin >> ch;
    BinTree* T;
    if ( ch == '#' )
    {
        T = 0;
        return T;
    }
    else
    {
        T = new BinTree();
        T -> data = ch ;
        T -> ls = createBT () ;
        T -> rs = createBT() ;
        return T;
    }
}

int main()
{
    //BinTree* mB = new BinTree(string("root"), new BinTree(string("a"), new BinTree(string("c"), 0, 0), new BinTree(string("d"), 0, 0)), new BinTree(string("e"), new BinTree(string("f"), 0, 0), new BinTree(string("g"), 0, 0)));
    BinTree* mB = createBT();
    //cout << mB -> getList() << endl;
    mB -> bfs();
    cout << endl;
    return 0;
}
