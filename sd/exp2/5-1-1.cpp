#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

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
    string getList()
        {
            string tmp = "(";
            tmp.push_back(data);
            tmp += " ";
            if (ls) //if has left son
            {
                tmp += ls -> getList();
            }
            tmp += " ";
            if (rs) //if has right son
            {
                tmp += rs -> getList();
            }
            tmp += ")";
            return tmp;
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
    if ( ch == '#' ) //if this is an empty node;
    {
        T = 0;
        return T;
    }
    else
    {
        T = new BinTree();
        T -> data = ch ; //create the node;
        T -> ls = createBT () ;
        T -> rs = createBT() ;
        return T;
    }
}
int main()
{
    
    BinTree* root = createBT();
    cout << root -> getList() << endl;

    return 0;
}
