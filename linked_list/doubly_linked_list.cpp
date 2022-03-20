#include <iostream>

template <typename T>
class DList
{
public:
    DList() : head(nullptr), tail(nullptr), size(0) {}

    size_t getSize() const { return size; }
    bool is_empty() const { return head == nullptr; }
    void clear();

    void push_front(T data);
    void pop_front();

    void push_back(T data);    
    void pop_back();

    void insert(T data, size_t i);
    void removeAt(size_t i);

    // [] definition can be only inside class!
    T & operator[](const size_t i)
    {
        return find(i)->data;
    }

    ~DList() { clear(); }

private:
    template <typename Type>
    class Node
    {
        public:
            Node(Type data = Type(),
                 Node <Type> * next = nullptr,
                 Node <Type> * prev = nullptr) : 
                 data(data), next(next), prev(prev) {}

            Type data;
            Node <Type> * next;
            Node <Type> * prev;
    };

    Node <T> * head;
    Node <T> * tail;
    size_t size;

    // search node from head or from tail depends on
    // to which of them it closer
    Node <T> * find(size_t i)
    {
        Node <T> * tmp = nullptr;

        if (i < size / 2)
        {
            tmp = head;
            for (size_t j = 0; j != i; ++j) tmp = tmp->next;
        }
        else
        {
            tmp = tail;
            for (size_t j = size - 1; j != i; --j) tmp = tmp->prev;
        }

        return tmp;
    }
};

template <typename T>
void DList<T>::clear()
{
    while (size)
    {
        pop_front();
    }
}

template <typename T>
void DList<T>::push_front(T data)
{
    if (is_empty())
    {
        head = new Node <T> (data);
        tail = head;
    }
    else
    {
        head = new Node <T> (data, head);
        head->next->prev = head;
    }

    ++size;
}

template <typename T>
void DList<T>::pop_front()
{
    if (is_empty()) return;
    if (size == 1)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }

    --size;
}

template <typename T>
void DList<T>::push_back(T data)
{
    if (is_empty())
    {
        push_front(data);
    }
    else
    {
        tail = new Node <T> (data, nullptr, tail);
        tail->prev->next = tail;
        ++size;
    }
}

template <typename T>
void DList<T>::pop_back()
{
    if (is_empty()) return;
    if (size == 1)
    {
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }

    --size;
}

template <typename T>
void DList<T>::insert(T data, size_t i)
{
    if (i == 0)
    {
        push_front(data);
        return;
    }

    Node <T> * tmp = find(i - 1);
    tmp->next = new Node <T> (data, tmp->next, tmp);
    tmp->next->next->prev = tmp->next;

    ++size;
}

template <typename T>
void DList<T>::removeAt(size_t i)
{
    if (i == 0)
    {
        pop_front();
        return;
    }

    Node <T> * tmp = find(i-1);
    Node <T> * new_next = tmp->next->next;
    delete tmp->next;
    tmp->next = new_next;
    tmp->next->prev = tmp;

    --size;
}
