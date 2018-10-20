#include <iostream>

using namespace std;

template<typename T>
struct Node
{
    T data;
    Node<T>* next;
    Node(const T& _data,Node<T>* _next = nullptr)
    {
        this->data = _data;
        this->next = _next;
    }
};

template<typename T>
class Queue
{
public:
    Queue()
    {
        this->first = nullptr;
        this->last = nullptr;
        this->size = 0;
    }
    Queue(const Queue& other)
    {
        this->copy(other);
    }
    Queue& operator=(const Queue& other)
    {
        if(this != &other)
        {
            this->erase();
            this->copy(other);
        }
        return *this;
    }
    void pop()
    {
        if(!this->empty())
        {
            Node<T>* temp = this->first;
            this->first = this->first->next;
            delete temp;
            this->size--;
        }
    }
    void push(const T& _data)
    {
        if(this->first == nullptr)
        {
            this->first = new Node<T>(_data);
            this->last = this->first;
        }
        else
        {
            //Node<T>* toAdd = new Node<T>(_data);
            this->last->next = new Node<T>(_data);
            this->last = this->last->next;
        }
        this->size ++;
    }
    const T& front() const
    {
        if(this->first != nullptr)
        {
            return this->first->data;
        }
        throw "Empty Queue";
    }
    const T& back() const
    {
        if(this->last != nullptr)
        {
            return this->last->data;
        }
        throw "Empty Queue";
    }
    size_t getSize() const
    {
        return this->size;
    }
    ~Queue()
    {
        this->erase();
    }
private:
    Node<T>* first;
    Node<T>* last;
    size_t size;
    void copy(const Queue& other)
    {
        if(other.empty())
        {
            this->first = nullptr;
            this->last = nullptr;
            this->size = 0;
        }
        else
        {
            Node<T>* temp = other.first;
            for(size_t i=0; i<other.getSize(); i++)
            {
                this->push(temp->data);
                temp = temp->next;

            }
        }
        this->size = other.getSize();
    }
    void erase()
    {
        while(!this->empty())
        {
            this->pop();
        }
    }
    bool empty() const
    {
        return this->size == 0;
    }
};
int main()
{
    return 0;
}
