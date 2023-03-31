#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdexcept>

using namespace std;

const uint32_t
    QUEUE_SIZE = 16;
  
template <typename QueueType>
class Queue {
public:
    Queue(void) {
  
        data = new QueueType[QUEUE_SIZE];
        capacity = QUEUE_SIZE;
    
        count = tail = 0;
        head = QUEUE_SIZE - 1;
    }
  
    ~Queue(void) { delete[] data; }
  
    void clear() { count = tail = 0; head = capacity - 1; }
  
    uint32_t size() { return count; }
    bool isEmpty() { return !count; }

    void enqueue(const QueueType &d) {

        if(count == capacity) {
            int tmpCap = 2 * capacity;
            QueueType *tmpData = new QueueType[tmpCap];

            if (tmpData == nullptr) {
                throw std::overflow_error("Queue is full");
            }

            for (int i = 0; i < capacity; i++) {
                tmpData[i] = data[(head+1+i)%capacity];
            }

            head = tmpCap - 1;
            tail = capacity;

            delete[] data;

            data = tmpData;
            capacity = tmpCap;
        }

        data[tail] = d;

        tail = ++tail%capacity;

        count++;
    }
  
    QueueType dequeue() {
  
        if (count == 0)
            throw underflow_error("Queue is empty");

        head = ++head % capacity;

        count--;

        return data[head];
    }

private:
    QueueType
        *data;
    
    int
        head,tail,
        count,
        capacity;
};

#endif
