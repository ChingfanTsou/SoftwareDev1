#ifndef SEQLISTSTA_H
#define SEQLISTSTA_H

template <typename EleType>
class SeqListSta
{
public:
    class Node
    {
    public:
        Node();
        ~Node();
        Node(const EleType&);
    private:
        EleType data;
        int index;
        Node* next;
    };
    SeqListSta();
    virtual ~SeqListSta();
    SeqListSta(int);
    void insert(const EleType&, int);
    int findByVal(const EleType&) const;
    EleType findByPos(int) const;
    void delByPos(int);
    int prePos(int) const;
    int nextPos(int) const;
    void clear();
    int first() const;
    int last() const;
private:
    void init();
    Node* getNode(const EleType&);
    void freeNode(Node*);
    int length;
    Node* head;
    Node* sphead;
    Node space[];
};

template <typename EleType>
SeqListSta<EleType>::Node::Node()
{
}

template <typename EleType>
SeqListSta<EleType>::Node::~Node()
{
}

template <typename EleType>
SeqListSta<EleType>::Node::Node(const EleType& nwEle)
    :data(nwEle)
{
}

template <typename EleType>
SeqListSta<EleType>::SeqListSta()
{
}

template <typename EleType>
SeqListSta<EleType>::SeqListSta(int cap)
    :length(cap)
{
    init();
}

template <typename EleType>
void SeqListSta<EleType>::init()
{
    space = new Node[length];

    for (int i = 0; i < length - 1; ++i)
    {
        space[i].next = space + i + 1;
        space[i].index = i;
    }
    space[length - 1].next = 0;
    space[length - 1].index = length - 1;
    sphead = space;
    head = 0;
}

template <typename EleType>
SeqListSta<EleType>::~SeqListSta()
{
    delete [] space;
}

template <typename EleType>
typename SeqListSta<EleType>::Node* SeqListSta<EleType>::getNode(const EleType& nwEle)
{
    Node* p = sphead;
    sphead = sphead -> next;
    p -> data = nwEle;
    return p;
}

template <typename EleType>
void SeqListSta<EleType>::insert(const EleType& nwEle, int pos)
{
    if (pos == 0)
    {
        head = getNode(nwEle);
        return;
    }
    Node* q = getNode(nwEle);
    q -> next = space[pos].next;
    space[pos].next = q;
}

template <typename EleType>
int SeqListSta<EleType>::findByVal(const EleType& mEle) const
{
    for (const SeqListSta<EleType>::Node* p = head; p; p = p -> next)
    {
        if (p -> data == mEle)
        {
            return p -> index;
        }
    }
    return 0;
}

template <typename EleType>
EleType SeqListSta<EleType>::findByPos(int pos) const
{
    return space[pos];
}

template <typename EleType>
void SeqListSta<EleType>::delByPos(int pos)
{
    Node* p;
    if (space[pos].next)
    {
        p =space[pos].next;
        space[pos].next = p -> next;
        freeNode(p);
    }
}

template <typename EleType>
void SeqListSta<EleType>::freeNode(Node* p)
{
    p -> next = sphead -> next;
    sphead -> next = p;
}

template <typename EleType>
int SeqListSta<EleType>::prePos(int pos) const
{
    for (Node* p = head; p; p = p -> next)
    {
        if (p -> next == space + pos)
        {
            return p -> index;
        }
    }
    return head -> index;
}

template <typename EleType>
int SeqListSta<EleType>::nextPos(int pos) const
{
    return space[pos].next -> index;
}

template <typename EleType>
void SeqListSta<EleType>::clear()
{
    delete [] space;
    init();
}

template <typename EleType>
int SeqListSta<EleType>::first() const
{
    return head;
}

template <typename EleType>
int SeqListSta<EleType>::last() const
{
    for (Node* p = head; p; p = p -> next)
    {
        if (p -> next == 0)
        {
            return p -> index;
        }
    }
    return head -> index;
}
#endif /* SEQLISTSTA_H */
