#ifndef SEQLISTH_H
#define SEQLISTH_H

template <typename EleType>
class SeqListH
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
        Node* next;
    };
    SeqListH();
    virtual ~SeqListH();
    void insert(const EleType&, const Node*);
    const Node* findByVal(const EleType&) const;
    EleType findByPos(const Node*) const;
    void delByPos(const Node*);
    const Node* prePos(const Node*) const;
    const Node* nextPos(const Node*) const;
    void clear();
    const Node* first() const;
    const Node* last() const;
private:
    Node* head;
};

template <typename EleType>
SeqListH<EleType>::Node::Node()
{
}

template <typename EleType>
SeqListH<EleType>::Node::~Node()
{
}

template <typename EleType>
SeqListH<EleType>::Node::Node(const EleType& nwEle)
    :data(nwEle)
{
}

template <typename EleType>
SeqListH<EleType>::SeqListH()
{
    head = new Node();
    head -> next = 0;
}

template <typename EleType>
SeqListH<EleType>::~SeqListH()
{
    while (head -> next)
    {
        delByPos(head -> next);
    }
    delete head;
}

template <typename EleType>
void SeqListH<EleType>::insert(const EleType& nwEle, const Node* pos)
{
    Node* q = new Node(nwEle);
    q -> next = pos -> next;
    pos -> next = q;
}

template <typename EleType>
const typename SeqListH<EleType>::Node* SeqListH<EleType>::findByVal(const EleType& mEle) const
{
    for (const SeqListH<EleType>::Node* p = head -> next; p; p = p -> next)
    {
        if (p -> data == mEle)
        {
            return p;
        }
    }
    return 0;
}

template <typename EleType>
EleType SeqListH<EleType>::findByPos(const Node* pos) const
{
    return pos -> next -> data;
}

template <typename EleType>
void SeqListH<EleType>::delByPos(const Node* pos)
{
    Node* p;
    if (pos -> next)
    {
        p = pos -> next;
        pos -> next = p -> next;
        delete p;
    }
}

template <typename EleType>
const typename SeqListH<EleType>::Node* SeqListH<EleType>::prePos(const Node* pos) const
{
    for (Node* p = head; p; p = p -> next)
    {
        if (p -> next == pos)
        {
            return p;
        }
    }
    return head;
}

template <typename EleType>
const typename SeqListH<EleType>::Node* SeqListH<EleType>::nextPos(const Node* pos) const
{
    return pos -> next;
}

template <typename EleType>
void SeqListH<EleType>::clear()
{
    while (head -> next)
    {
        delByPos(head -> next);
    }
}

template <typename EleType>
const typename SeqListH<EleType>::Node* SeqListH<EleType>::first() const
{
    return head -> next;
}

template <typename EleType>
const typename SeqListH<EleType>::Node* SeqListH<EleType>::last() const
{
    for (Node* p = head -> next; p; p = p -> next)
    {
        if (p -> next == 0)
        {
            return p;
        }
    }
    return head;
}
#endif /* SEQLISTH_H */
