#include <iostream>
#include <string>
#include "ListStack.hpp"

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
    void pretrav()
        {
            BinTree* root = this;
            ListStack<BinTree*> st;
            while (root != 0 || !st.isEmpty())
            {
                while (root != 0)
                {
                    cout << root -> data << " ";
                    st.push(root);
                    root = root -> ls;
                }
                if (!st.isEmpty())
                {
                    root = st.pop();
                    root = root -> rs;
                }
            }
        }
    void intrav()
        {
            BinTree* root = this;
            ListStack<BinTree*> st;
            while (root != 0 || !st.isEmpty())
            {
                while (root != 0)
                {
                    st.push(root);
                    root = root -> ls;
                }
                if (!st.isEmpty())
                {
                    root = st.pop();
                    cout << root -> data << " ";
                    root = root -> rs;
                }
            }
        }
    void posttrav()
        {
            BinTree* root = this;
            ListStack<BinTree*> st;
            ListStack<int> stf;
            bool first = true;
            while ((root != this || first) || !st.isEmpty())
            {
                first = false; //if it's not the first time to run the circle;
                while (root != 0)
                {
                    st.push(root);
                    stf.push(1);
                    root = root -> ls;
                }
                while (!st.isEmpty() && stf.getTop() == 2)
                {
                    root = st.pop();
                    stf.pop();
                    cout << root -> data << " ";
                }
                if (!st.isEmpty())
                {
                    stf.pop();
                    stf.push(2);
                    root = st.getTop() -> rs;
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
    mB -> pretrav();
    cout << endl;
    mB -> intrav();
    cout << endl;
    mB -> posttrav();
    cout << endl;
    return 0;
}
