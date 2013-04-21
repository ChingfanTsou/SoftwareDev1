#include <iostream>

using std::cout;
using std::endl;

class AVLTree
{
public:
    AVLTree()
        {
        }
    ~AVLTree()
        {
        }
    void insert(int n)
        {
            bool t;
            insert(root, n, t);
        }
    void deleteByKey(int key)
        {
            del(root, key);
        }
    bool find(int x)
        {
            return search(root, x);
        }
private:
    class Node
    {
    public:
        int bf;
        int data;
        Node* ls;
        Node* rs;
    } *root;

    bool search(Node* r, int key)
        {
            if (!r)
            {
                return false;
            }
            if (r->data == key)
            {
                return true;
            }
            if (search(r->rs, key))
            {
                return true;
            }
            if (search(r->ls, key))
            {
                return true;
            }
            return false;
        }
    void rightRotate(Node* &p)
        {
            Node* lc = p -> ls;
            p -> ls = lc -> rs;
            lc -> rs = p;
            p = lc;
        }
    void leftRotate(Node* &p)
        {
            Node* rc = p -> rs;
            p -> rs = rc -> ls;
            rc -> ls = p;
            p = rc;
        }
    void leftBalance(Node* &r)
        {
            Node* lc;
            Node* rd;
            lc = r -> ls;
            switch (lc -> bf)
            {
            case 1:
                r -> bf = lc -> bf = 0;
                rightRotate(r);
                break;
            case -1:
                rd = lc -> rs;
                switch (rd -> bf)
                {
                case 1:
                    r -> bf = -1;
                    lc -> bf = 0;
                    break;
                case 0:
                    r -> bf = lc -> bf = 0;
                    break;
                case -1:
                    r -> bf = 0;
                    lc -> bf = 1;
                }
                rd -> bf = 0;
                leftRotate(r -> ls);
                rightRotate(r);
            }
        }
    void rightBalance(Node* &r)
        {
            Node* rc;
            Node* rd;
            rc = r -> rs;
            switch (rc -> bf)
            {
            case -1:
                r -> bf = rc -> bf = 0;
                leftRotate(r);
                break;
            case 1:
                rd = rc -> ls;
                switch (rd -> bf)
                {
                case -1:
                    r -> bf = 1;
                    rc -> bf = 0;
                    break;
                case 0:
                    r -> bf = rc -> bf = 0;
                    break;
                case 1:
                    r -> bf = 0;
                    rc -> bf = -1;
                }
                rd -> bf = 0;
                rightRotate(r -> rs);
                leftRotate(r);
            }
        }
    int insert(Node* &t, int newD, bool &taller)
        {
            if(!t)
            {
                t = new Node();
                t -> data = newD;
                t -> ls = t -> rs = 0;
                t -> bf = 0;
                taller = true;
            }
            else
            {
                if(newD == t -> data)
                {
                    taller = false;
                    return 0;
                }
                if(newD < t -> data)
                {
                    if(!insert(t -> ls, newD, taller))
                    {
                        return 0;
                    }
                    if(taller)
                    {
                        switch (t->bf)
                        {
                        case 1:
                            leftBalance(t);
                            taller = false;
                            break;
                        case 0:
                            t -> bf = 1;
                            taller = true;
                            break;
                        case -1:
                            t -> bf = 0;
                            taller = false;
                            break;
                        }
                    }
                }
                else
                {
                    if(insert(t -> rs, newD, taller))
                    {
                        return 0;
                    }
                    if (taller)
                    {
                        switch(t -> bf)
                        {
                        case -1:
                            rightBalance(t);
                            taller = false;
                            break;
                        case 0:
                            t -> bf = -1;
                            taller = true;
                            break;
                        case 1:
                            t -> bf = 0;
                            taller = 0;
                            break;
                        }
                    }
                }
            }
            return 1;
        }
    
    Node* del(Node* &ptr, int key)
        {
            Node* re_ptr;

            if (ptr->data == key)
            {
                re_ptr = ptr;
                if (!ptr -> ls || !ptr -> rs)
                {
                    Node* tmp = ptr;
                    if (ptr -> rs)
                    {
                        ptr = ptr -> rs;
                    }
                    else
                    {
                        ptr = ptr -> ls;
                    }
                    delete tmp;
                }
                else
                {
                    ptr = del(ptr -> ls, key);
                }
                return re_ptr;
            }
            if (ptr -> data > key && !ptr -> ls || ptr -> data < key && !ptr -> rs)
            {
                re_ptr = ptr;
                if (!ptr -> ls || !ptr -> rs)
                {
                    if (ptr -> rs)
                    {
                        ptr = ptr -> rs;
                    }
                    else
                    {
                        ptr = ptr -> ls;
                    }
                }
                else
                {
                    ptr = del(ptr -> ls, key);
                }
            }
            else
            {
                if (ptr -> data > key)
                {
                    re_ptr = del(ptr -> ls, key);
                }
                else
                {
                    re_ptr = del(ptr -> rs, key);
                }
            }

            return re_ptr;
        }
};

int main()
{
    AVLTree mTree;
    for (int i = 0; i < 10; ++i)
    {
        mTree.insert(i);
    }
    cout << mTree.find(0) << endl;
    cout << mTree.find(9) << endl;
    cout << mTree.find(10) << endl;
    for (int i = 0; i < 10; ++i)
    {
        mTree.deleteByKey(i);
    }
    cout << mTree.find(0) << endl;
    return 0;
}
