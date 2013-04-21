#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::abs;

class BinTree
{
    class Node;
public:
    BinTree()
        {
            ls = 0;
            rs = 0;
        }
    BinTree(char mEle, BinTree* lt, BinTree* rt)
        {
            data = mEle;
            ls = lt;
            rs = rt;
        }
    ~BinTree()
        {
            delete ls;
            delete rs;
        }

    char data;
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

int trav1(BinTree* r)
{
    if (!r)
    {
        return 0;
    }
    int hl = trav1(r -> ls);
    if (hl == -1)
    {
        return -1;
    }
    int hr = trav1(r -> rs);
    if (hr == -1)
    {
        return -1;
    }
    if (abs(hl - hr) > 1)
    {
        cout << "This is not a BST" << endl;
        return -1;
    }
    
    if (hl > hr)
    {
        return hl + 1;
    }
    else
    {
        return hr + 1;
    }
}

bool trav2(BinTree* r)
{
    if (!r)
    {
        return true;
    }
    if (r -> ls && r -> ls -> data > r -> data)
    {
        return false;
    }
    if (r -> rs && r -> rs -> data < r -> data)
    {
        return false;
    }
    if (!trav2(r -> ls))
    {
        return false;
    }
    if (!trav2(r -> rs))
    {
        return false;
    }
    
    return true;
}

int main()
{
    
    BinTree* root = createBT();
    
    trav1(root);
    if (!trav2(root))
    {
        cout << "This is not a sorted binary tree." << endl;
    }
    else
    {
        cout << "This is a sorted binary tree." << endl;
    }
    
    return 0;
}
