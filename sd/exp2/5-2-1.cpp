#include <iostream>
#include <string>

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
    BinTree(char mEle, BinTree* lt, BinTree* rt)
        {
            data = mEle;
            ls = lt;
            rs = rt;
        }
    void pretrav()
        {
            cout << data << " "; //father first;
            if (ls)
            {
                ls -> pretrav();
            }
            if (rs)
            {
                rs -> pretrav();
            }
        }
    void intrav()
        {
            if (ls)
            {
                ls -> intrav();
            }
            cout << data << " "; //father in the middle;
            if (rs)
            {
                rs -> intrav();
            }
        }
    void posttrav()
        {
            if (ls)
            {
                ls -> posttrav();
            }
            if (rs)
            {
                rs -> posttrav();
            }
            cout << data << " "; //father last;
        }

    /*string getList()
        {
            string tmp = "(" + data + " ";
            if (ls)
            {
                tmp += ls -> getList();
            }
            tmp += " ";
            if (rs)
            {
                tmp += rs -> getList();
            }
            tmp += ")";
            return tmp;
        }*/
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
    mB -> pretrav();
    cout << endl;
    mB -> intrav();
    cout << endl;
    mB -> posttrav();
    cout << endl;
    return 0;
}
