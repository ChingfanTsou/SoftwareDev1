#ifndef SEQLIST_H
#define SEQLIST_H

template <typename EleType>
class SeqList
{
public:
    class Node
    {
        friend class SeqList<EleType>;
    public:
        Node();
        ~Node();
        Node(const EleType&);
        /**
           此处若将data置为private则
           SeqList<SeqList<> >会有操作不便，
           详见《C++沉思录》
        */
        EleType data;
    private:
        Node* next;
    };
    SeqList();
    virtual ~SeqList();
    Node* insert(const EleType&, Node*);
    Node* findByVal(const EleType&) const;
    EleType findByPos(const Node*) const;
    void delByPos(Node*);
    void rmByPos(Node*);
    Node* prePos(const Node*) const;
    Node* nextPos(const Node*) const;
    void clear();
    Node* first() const;
    Node* last() const;
    Node* pushBack(const EleType&);
private:
    Node* head;
    Node* tail;
};

template <typename EleType>
SeqList<EleType>::Node::Node()
    :next(0)
{
}

template <typename EleType>
SeqList<EleType>::Node::~Node()
{
}

template <typename EleType>
SeqList<EleType>::Node::Node(const EleType& nwEle)
    :data(nwEle), next(0)
{
}

template <typename EleType>
SeqList<EleType>::SeqList()
    :head(0), tail(0)
{
}

template <typename EleType>
SeqList<EleType>::~SeqList()
{
    while (head)
    {
        delByPos(head);
    }
}

template <typename EleType>
typename SeqList<EleType>::Node* SeqList<EleType>::insert(const EleType& nwEle, Node* pos)
{
    Node* q = new Node(nwEle);
    if (pos == head)
    {
        q -> next = head;
        head = q;
        if (!tail)
        {
            tail = q;
        }
        return head;
    }
    else if (pos == 0)
    {
        tail -> next = q;
        tail = q;
        return tail;
    }
    q -> next = pos -> next;
    pos -> next = q;
    return q;
}

template <typename EleType>
typename SeqList<EleType>::Node* SeqList<EleType>::findByVal(const EleType& mEle) const
{
    for (SeqList<EleType>::Node* p = head; p; p = p -> next)
    {
        if (p -> data == mEle)
        {
            return p;
        }
    }
    return 0;
}

template <typename EleType>
EleType SeqList<EleType>::findByPos(const Node* pos) const
{
    if (pos == 0)
    {
        return head -> data;
    }
    return pos -> next -> data;
}

template <typename EleType>
void SeqList<EleType>::delByPos(Node* pos)
{
    if (head == tail)
    {
        delete pos;
        head = 0;
        tail = 0;
    }
    if (pos == tail)
    {
        for (Node* p = head; p; p = p -> next)
        {
            if (p -> next == tail)
            {
                tail = p;
                p -> next = 0;
                break;
            }
        }
        delete pos;
        return;
    }
    else if (head == pos)
    {
        head = head -> next;
        delete pos;
        return;
    }
    for (Node* p = head; p; p = p -> next)
    {
        if (p -> next == pos)
        {
            p -> next = pos -> next;
            delete pos;
            return;
        }
    }
}

template <typename EleType>
void SeqList<EleType>::rmByPos(Node* pos)
{
    if (head == tail)
    {
        head = 0;
        tail = 0;
    }
    if (pos == tail)
    {
        for (Node* p = head; p; p = p -> next)
        {
            if (p -> next == tail)
            {
                tail = p;
                p -> next = 0;
                break;
            }
        }
        return;
    }
    else if (head == pos)
    {
        head = head -> next;
        return;
    }
    for (Node* p = head; p; p = p -> next)
    {
        if (p -> next == pos)
        {
            p -> next = pos -> next;
            return;
        }
    }
}

template <typename EleType>
typename SeqList<EleType>::Node* SeqList<EleType>::prePos(const Node* pos) const
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
typename SeqList<EleType>::Node* SeqList<EleType>::nextPos(const Node* pos) const
{
    return pos -> next;
}

template <typename EleType>
void SeqList<EleType>::clear()
{
    while (head)
    {
        delByPos(head);
    }
}

template <typename EleType>
typename SeqList<EleType>::Node* SeqList<EleType>::first() const
{
    return head;
}

template <typename EleType>
typename SeqList<EleType>::Node* SeqList<EleType>::last() const
{
    return 0;
}

template <typename EleType>
typename SeqList<EleType>::Node* SeqList<EleType>::pushBack(const EleType& nwEle)
{
    insert(nwEle, tail);
}
#endif /* SEQLIST_H */
