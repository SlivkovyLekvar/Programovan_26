#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int size;

public:
    Queue();
    ~Queue();

};

#endif // QUEUE_H