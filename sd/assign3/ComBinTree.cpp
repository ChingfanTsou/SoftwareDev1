#include <iostream>
#include <string>
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

    bool isCompBinTree()
        {
            QueueList<BinTree*> mQ;

            BinTree* root = this;
            mQ.enQueue(root);

            bool flag = false;

            while (!mQ.isEmpty()) //breadth-first traversal,while the queue is not empty,travel the queue's head node;
            {
                root = mQ.deQueue();
                if (!flag && !(root -> ls && root -> rs))
                {
                    if (!root -> ls && root -> rs)
                    {
                        return false;
                    }
                    flag = true;
                }
                if (flag && (root -> ls || root -> rs))
                {
                    return false;
                }
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
    BinTree* mB = createBT();
 
    if (mB -> isCompBinTree())
    {
        cout << "This is Complete Binary Tree." << endl;
    }
    else
    {
        cout << "This is not Complete Binary Tree." << endl;
    }
    return 0;
}
