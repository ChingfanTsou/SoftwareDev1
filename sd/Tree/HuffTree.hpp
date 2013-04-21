#ifndef HUFFTREE_H
#define HUFFTREE_H

#include <string>
#include <fstream>
#include <map>
#include "Heap.h"
#include "SeqList.hpp"
#include "ListStack.hpp"

using std::string;
using std::ofstream;
using std::ios;
using std::endl;
using std::map;
using std::ifstream;
using std::getline;

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
        bool operator>(const Node& other)
            {
                return t<other.t;
            }
    };
    void outHuf();
    string find(char);
    void conCode();
    void outHuff();
    void deCode();
    
private:
    SeqList<Node>* cnt;
    map<char, string> code;
    Heap<Node>* minHeap;
    Node* root;
    string text;
    int n;
    ofstream outFile;
    Node findMin();
    void crtHuff();
    void trav(const Node*, string&);
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
    
    minHeap = new Heap<HuffTree::Node>;
    for (SeqList<HuffTree::Node>::Node* p = cnt -> first(); p != cnt -> last(); p = cnt -> nextPos(p))
    {
        minHeap->insert(p->data);
    }
    
    delete cnt;
    crtHuff();
}

HuffTree::~HuffTree()
{
    delete cnt;
    delete minHeap;
    delete root;
}

HuffTree::Node HuffTree::findMin()
{
    return minHeap->getTop();
}

void HuffTree::crtHuff()
{
    HuffTree::Node* ptx;
    HuffTree::Node* pty;
    int s = 0;
    
    for (int i = 1; i < n; ++i)
    {
        int s = 0;
        ptx = new HuffTree::Node(findMin());
        pty = new HuffTree::Node(findMin());
        HuffTree::Node* nd = new HuffTree::Node('#', ptx->t + pty->t);
        nd -> ls = ptx;
        nd -> rs = pty;
        minHeap->insert(*nd);
    }
    root = new HuffTree::Node(minHeap->getTop());
}

void HuffTree::outHuff()
{
    string tot;
    trav(root, tot);
}

void HuffTree::trav(const HuffTree::Node* root, string& tot)
{
    if (root -> x != '#')
    {
        outFile << root -> x << " " << tot << endl;
        code.insert(map<char, string>::value_type(root->x, tot));

        return;
    }
    tot.push_back('0');
    trav(root -> ls, tot);
    tot.pop_back();

    tot.push_back('1');
    trav(root -> rs, tot);
    tot.pop_back();

    return;
}

string HuffTree::find(char f)
{
    return code.find(f)->second;
}

void HuffTree::conCode()
{
    ofstream out("concode.dat", ios::out);
    for (string::const_iterator p = text.begin(); p != text.end(); p++)
    {
        out << find(*p) << endl;
    }
}

void HuffTree::deCode()
{
    ofstream out("decode.dat", ios::out);
    ifstream in("concode.dat", ios::in);
    string num;
    HuffTree::Node* r = root;
    
    while (!in.eof())
    {
        getline(in, num);
        for (string::iterator p = num.begin(); p != num.end(); ++p)
        {
            if (*p == '0')
                r = r->ls;
            else
                r = r->rs;            
        }
        if (r->x != '#')
        {
            out << r->x;
            r = root;
        }
    }
}

#endif /* HUFFTREE_H */
