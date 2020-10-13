#include <iostream>

class MyQueue {

public:
    MyQueue(int capacity)
    {
        this->arr = new int[capacity];
        this->size = capacity;
    }
    /// <summary>
    /// 入队
    /// </summary>
    /// <param name="element">入队的元素</param>
    void enQueue(int element)
    {
        if ((rear + 1) % size == front)
        {
            return;//队列已满
        }
        arr[rear] = element;
        rear = (rear + 1) % size;
    }
    /// <summary>
    /// 出队
    /// </summary>
    /// <returns></returns>
    int deQueue()
    {
        if (rear == front)
        {
            return -1;//队列为空
        }
        int deQueueElement = arr[front];
        front = (front + 1) % size;
        return deQueueElement;
    }
    /// <summary>
    /// 输出队列
    /// </summary>
    void output()
    {
        for (int i = front; i != rear; i = (i + 1) % size)
        {
            std::cout << arr[i] << std::endl;
        }
    }
private:
    int* arr;//arr指向数组
    int front; //队头下标
    int rear;
    int size;
};