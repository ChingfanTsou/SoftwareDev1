#ifndef QUEUELIST_H
#define QUEUELIST_H

template <typename EleType>
class QueueList
{
public:
    QueueList<EleType>();
    ~QueueList<EleType>();
    EleType deQueue();
    void enQueue(const EleType&);
    bool isEmpty();
private:
    class Node
    {
    public:
        EleType data;
        Node* next;
    };
    Node* tail;
};

template <typename EleType>
QueueList<EleType>::QueueList()
    :tail(0)
{
}

template <typename EleType>
QueueList<EleType>::~QueueList()
{
    while (!isEmpty())
    {
        deQueue();
    }
}

template <typename EleType>
void QueueList<EleType>::enQueue(const EleType& nwEle)
{
    Node* p = new Node;
    p -> data = nwEle;
    if (tail)
    {
        p -> next = tail -> next;
        tail -> next = p;
        tail = p;
    }
    else
    {
        tail = p;
        tail -> next = tail;
    }
}

template <typename EleType>
EleType QueueList<EleType>::deQueue()
{
    Node* p = tail -> next;
    if (tail -> next == tail)
    {
        tail = 0;
    }
    else
    {
        tail -> next = tail -> next -> next;
    }
    
    EleType tmp = p -> data;
    delete p;
    return tmp;
}

template <typename EleType>
bool QueueList<EleType>::isEmpty()
{
    return (!tail);
}

#endif /* QUEUELIST_H */
