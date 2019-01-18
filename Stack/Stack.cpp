#include <iostream>

using namespace std;

template<typename T>
struct Node
{
    T data;
    Node<T>* next;
    Node(const T& _data,Node<T>* _next=nullptr)
    {
        this->data = _data;
        this->next = _next;
    }
};

template<typename T>
class Stack
{
private:
    Node<T>* topElement;
    size_t size;
    void copy(const Stack<T>& other)
    {
        if(other.topElement == nullptr)
        {
            this->topElement = nullptr;
            this->size =0;
        }
        else
        {

            this->topElement = new Node<T>(other.topElement->data,other.topElement->next);
            Node<T>* temp1 = this->topElement;
            Node<T>* temp2 = other.topElement;
            while(temp2->next)
            {
                temp1->next = new Node<T>(temp2->next->data,temp2->next->next);
                temp2 = temp2->next;
                temp1 = temp1->next;
            }
            this->size = other.size;
        }
    }
    void erase()
    {
        while(!this->isEmpty())
        {
            this->pop();
        }
    }
public:
    Stack()
    {
        this->topElement = nullptr;
        this->size = 0;
    }
    Stack(const Stack& other)
    {
        this->copy(other);
    }
    Stack& operator=(const Stack& other)
    {
        if(this != &other)
        {
            this->erase();
            this->copy(other);
        }
        return *this;
    }
    ~Stack()
    {
        this->erase();
    }
    bool isEmpty()
    {
        return this->size == 0;
    }
    size_t getSize() const
    {
        return this->size;
    }
    void pop()
    {
        if(!this->isEmpty())
        {
            Node<T>* temp = this->topElement;
            this->topElement = this->topElement->next;
            delete temp;
            this->size--;
        }
        else throw "Empty stack";
    }
    void push(const T& element)
    {
        Node<T>* addElement = new Node<T>(element);
        if(this->isEmpty())
        {
            this->topElement = addElement;
        }
        else
        {
            addElement->next = this->topElement;
            this->topElement = addElement;
        }
        this->size++;
    }
    void print()
    {
        Node<T>* temp = this->topElement;
        while(temp)
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        }
        cout<<"Size : "<<this->getSize()<<endl;
    }
    const T& top() const
    {
        return this->topElement->data;
    }
};


int main()
{
    return 0;
}
