#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::ifstream;

class ChilBro
{
public:
    class Node
    {
        friend class ChilBro;
    public:
        Node(char k)
            :data(k),child(0),bro(0)
            {
            }
        char data;
    private:
        Node* child;
        Node* bro;
    };
    
    ChilBro()
        :root(0)
        {   
        }
    ~ChilBro()
        {
        }
    void insert(char f, char k)
        {
            Node* fa = find(f);
            if (!fa)
            {
                root = new Node(f);
                fa = root;
            }
            Node* sn = new Node(k);
            sn -> bro = fa -> child;
            fa -> child = sn;
        }
    Node* find(char k)
        {
            if (!root)
            {
                return 0;
            }
            else
            {
                return search(root, k);
            }
        }
    char getChild(char k, int x)
        {
            Node* it = search(root, k);
            int i = 0;
            for (Node* p = it -> child; p; p = p -> bro)
            {
                ++i;
                if (i == x)
                {
                    return p -> data;
                }
            }
        }
    int getHeight()
        {
            return height(root);
        }
    
private:
    Node* search(const Node* t, char k)
        {
            if (t -> data == k)
            {
                return const_cast<Node*>(t);
            }

            Node* it;
            for (Node* p = t -> child; p; p = p -> bro)
            {
                it = search(p, k);
                if (it)
                {
                    return it;
                }
            }
            return 0;
        }
    int height(const Node* t)
        {
            int mH = 1;
            for (Node* p = t -> child; p; p = p -> bro)
            {
                int h = height(p) + 1;
                if (mH < h)
                {
                    mH = h;
                }
            }
            return mH;
        }
    Node* root;
};

int main()
{
    ifstream in("tree.in", ios::in);
    ChilBro T;
    char t;
    while (in >> t)
    {
        char s;
        s = in.get();
        while (s != '\n')
        {
            if (s == ' ')
            {
                s = in.get();
                continue;
            }
            T.insert(t, s);
            s = in.get();
        }
    }

    cout << T.getChild('C', 2) << endl;
    cout << T.getHeight() << endl;
    return 0;
}
