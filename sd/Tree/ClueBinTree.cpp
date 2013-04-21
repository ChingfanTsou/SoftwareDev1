#include <iostream>
#include <string>
#include <cstdio>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class BinTree;
BinTree* root;

class BinTree
{
public:
    BinTree()
        {
            ls = 0;
            rs = 0;
            lt = false;
            rt = false;
        }
    BinTree(char mEle, BinTree* otl, BinTree* otr)
        {
            data = mEle;
            ls = otl;
            rs = otr;
        }
    ~BinTree()
        {
            delete ls;
            delete rs;
        }

    BinTree* prenext(BinTree* p)
        {
            BinTree* q;
            if (p->lt == true)
                q=p->ls;
            else
            {
                q = p;
                while (!q->rt && q!=root)
                    q = q->rs;
                if (q != root)
                {
                    q = q->rs;
                }
            }
            return q;
        }
    void pretrav()
        {   
            for (BinTree* p = this; p != root; p = prenext(p))
            {
                cout << p->data << " ";
            }
        }

    BinTree* innext(BinTree* p)
        {
            if (!p->rt)
                return p->rs;
            else
            {
                p = p->rs;
                while (p->lt)
                {
                    p = p->ls;
                }
                return p;
            }
        }
    void intrav()
        {
            for (BinTree* p = innext(root); p != root; p = innext(p))
            {
                cout << p->data << " ";
            }
        }

    void posttrav()
        {
            if (lt)
            {
                ls -> posttrav();
            }
            if (rt)
            {
                rs -> posttrav();
            }
            cout << data << " "; //father last;
        }


    char data;
    BinTree* ls;
    BinTree* rs;
    bool lt;
    bool rt;
};

BinTree* createBT(BinTree*& pre)
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
        T -> ls = createBT(pre);
        if (!T->ls)
        {
            T->ls=pre;
        }
        else
        {
            T->lt = true;
        }
        if (!pre->rs)
        {
            pre->rs=T;
        }
        pre=T;
        T -> rs = createBT(pre);
        if (T->rs)
        {
            T->rt = true;
        }
        return T;
    }
}

int main()
{    
    freopen("tree.in","r",stdin);
    root = new BinTree();
    BinTree* tmp = root;
    root->ls=root->rs=createBT(tmp);
    root->lt=root->rt=true;
    tmp -> rs = root;

    root->ls->pretrav();
    cout << endl;
    root->ls->intrav();
    cout << endl;
    root->ls->posttrav();
    cout << endl;

    return 0;
}
