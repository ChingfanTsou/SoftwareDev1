#ifndef BINTREE_H
#define BINTREE_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class BinTree
{
public:
    class Node {
        friend class BinTree;
    public:
        char data;
        Node* ls;
        Node* rs;
    };

    BinTree();
    BinTree(const string&);
    ~BinTree();
    string getPreorder();
    string getPostorder();
    char getFather(char);
    void delByVal(char);
private:
    Node* root;
    void pretrav(string&, const Node*);
    void posttrav(string&, const Node*);
    bool del(Node*, char);
    char findFa(const Node*, char);
    Node* createNode(const string&, string::const_iterator);
};

BinTree::BinTree()
    :root(0)
{
}

BinTree::BinTree(const string& nwT)
{
    root = createNode(nwT, nwT.begin());
}

BinTree::Node* BinTree::createNode(const string& nwT, string::const_iterator p)
{
    if (p == nwT.end())
    {
        return 0;
    }
    
    if (*p == '#')
    {
        return 0;
    }
    else
    {
        Node* pN = new Node();
        pN -> data = *p;
        pN -> ls = createNode(nwT, ++p);
        pN -> rs = createNode(nwT, ++p);
        return pN;
    }

}

string BinTree::getPreorder()
{
    string preorder;
    pretrav(preorder, root);
    return preorder;
}

void BinTree::pretrav(string& preorder, const Node* root)
{
    if (root -> ls == 0 && root -> rs == 0)
    {
        preorder.push_back(root -> data);
    }
    else
    {
        pretrav(preorder, root -> ls);
        pretrav(preorder, root -> rs);
    }
}

string BinTree::getPostorder()
{
    string postorder;
    posttrav(postorder, root);
    return postorder;
}

void BinTree::posttrav(string& postorder, const Node* root)
{
    posttrav(postorder, root -> ls);
    posttrav(postorder, root -> rs);
    postorder.push_back(root -> data);
}

char BinTree::getFather(char x)
{
    return findFa(root, x);
}

char findFa(const BinTree::Node* root, char x)
{
    if (!root)
    {
        return '#';
    }
    
    if (root -> ls -> data == x ||
        root -> rs -> data == x)
    {
        return root -> data;
    }
    else
    {
        char ch = findFa(root -> ls, x);
        if (ch == '#')
        {
            return findFa(root -> rs, x);
        }
    }
}

void BinTree::delByVal(char x)
{
    if (del(root, x))
    {
        cout << "success!" << endl;
    }
    else
    {
        cout << "no such node" << endl;
    }
}

bool del(BinTree::Node* root, char x)
{
    if (root -> ls -> data == x)
    {
        delete root -> ls;
        root -> ls = 0;
        return true;
    }
    else if (root -> rs -> data == x)
    {
        delete root -> rs;
        root -> rs = 0;
        return true;
    }

    if (del(root -> ls, x) || del (root -> rs, x))
    {
        return true;
    }

    return false;
}

BinTree::~BinTree()
{
    delete root -> ls;
    delete root -> rs;
}

#endif /* BINTREE_H */
