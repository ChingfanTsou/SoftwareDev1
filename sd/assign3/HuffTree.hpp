#ifndef HUFFTREE_H
#define HUFFTREE_H

#include <string>
#include <fstream>
#include <bitset>
#include "SeqList.hpp"
#include "ListStack.hpp"

using std::string;
using std::ofstream;
using std::ios;
using std::endl;
using std::bitset;
using std::ifstream;

class HuffTree
{
public:
    HuffTree();
    HuffTree(const string&);
    virtual ~HuffTree();
    class Node
    {
    public:
        Node();
        Node(char, int);
        virtual ~Node();
        bool operator==(const Node&);
        char x;
        int t;
        Node* ls;
        Node* rs;
    };
    void outHuf();
    int find(char);
    void conCode();
    void outHuff();
    void deCode();
    
private:
    SeqList<Node>* cnt;
    SeqList<Node>* code;
    string text;
    int n;
    ofstream outFile;
    Node* findMin();
    void crtHuff();
    void trav(const Node*, ListStack<int>);
};

HuffTree::Node::Node()
{
}

HuffTree::Node::~Node()
{
}

HuffTree::Node::Node(char k, int tm)
    :t(tm), x(k)
{
}

bool HuffTree::Node::operator==(const Node& ot)
{
    return (x == ot.x);
}

HuffTree::HuffTree()
{
}

HuffTree::HuffTree(const string& txt)
    :text(txt), n(0), outFile("code.dat", ios::out)
{
    cnt = new SeqList<HuffTree::Node>();
    for (string::const_iterator p = text.begin(); p != text.end(); p++)
    {
        HuffTree::Node nd(*p, 1);
        SeqList<HuffTree::Node>::Node* pnd = cnt -> findByVal(nd);
        if (pnd)
        {
            ++(pnd -> data.t);
        }
        else
        {
            cnt -> pushBack(nd);
            ++n;
        }
    }
    crtHuff();
}

HuffTree::~HuffTree()
{
}

HuffTree::Node* HuffTree::findMin()
{
    int m = text.length() + 1;
    SeqList<HuffTree::Node>::Node* mp;

    for (SeqList<HuffTree::Node>::Node* p = cnt -> first(); p != cnt -> last(); p = cnt -> nextPos(p))
    {
        if (m > p -> data.t)
        {
            m = p -> data.t;
            mp = p;
        }
    }
    cnt -> rmByPos(mp);
    return &(mp -> data);
}

void HuffTree::crtHuff()
{
    HuffTree::Node* ptx;
    HuffTree::Node* pty;
    int s = 0;
    
    for (int i = 1; i < n; ++i)
    {
        int s = 0;
        ptx = findMin();
        pty = findMin();
        HuffTree::Node* nd = new HuffTree::Node('#', ptx -> t + pty -> t);
        nd -> ls = ptx;
        nd -> rs = pty;
        cnt -> pushBack(*nd);
    }
}

void HuffTree::outHuff()
{
    ListStack<int> st;
    code = new SeqList<HuffTree::Node>();
    trav(&(cnt -> first() -> data), st);
}

void HuffTree::trav(const HuffTree::Node* root, ListStack<int> st)
{
    if (root -> x != '#')
    {
        outFile << root -> x << " ";
        int tot = 0;
        while (!st.isEmpty())
        {
            tot <<= 1;
            tot += st.getTop();
            outFile << st. pop();
        }
        code -> pushBack(HuffTree::Node(root -> x, tot));
        outFile << endl;
        return;
    }
    st.push(0);
    trav(root -> ls, st);
    st.pop();
    st.push(1);
    trav(root -> rs, st);
    return;
}

int HuffTree::find(char f)
{
    SeqList<HuffTree::Node>::Node* p = code -> findByVal(HuffTree::Node(f, 0));
    return p -> data.t;
}

void HuffTree::conCode()
{
    ofstream out("concode.dat", ios::out);
    for (string::const_iterator p = text.begin(); p != text.end(); p++)
    {
        out << bitset<sizeof(int)*8>(find(*p)) << endl;
    }
}

void HuffTree::deCode()
{
    ofstream out("decode.dat", ios::out);
    ifstream in("concode.dat", ios::in);
    int num;
    HuffTree::Node* root = &(cnt -> first() -> data);
    
    while (!in.eof())
    {
        in >> num;
        if (!num)
        {
            root = root -> ls;
        }
        else
        {
            root = root -> rs;
        }
        if (root -> x != '#')
        {
            out << root -> x;
            root = &(cnt -> first() -> data);
        }
    }
}

#endif /* HUFFTREE_H */
