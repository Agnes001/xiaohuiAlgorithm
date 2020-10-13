#include <iostream>

class MyQueue {

public:
    MyQueue(int capacity)
    {
        this->arr = new int[capacity];
        this->size = capacity;
    }
    /// <summary>
    /// ���
    /// </summary>
    /// <param name="element">��ӵ�Ԫ��</param>
    void enQueue(int element)
    {
        if ((rear + 1) % size == front)
        {
            return;//��������
        }
        arr[rear] = element;
        rear = (rear + 1) % size;
    }
    /// <summary>
    /// ����
    /// </summary>
    /// <returns></returns>
    int deQueue()
    {
        if (rear == front)
        {
            return -1;//����Ϊ��
        }
        int deQueueElement = arr[front];
        front = (front + 1) % size;
        return deQueueElement;
    }
    /// <summary>
    /// �������
    /// </summary>
    void output()
    {
        for (int i = front; i != rear; i = (i + 1) % size)
        {
            std::cout << arr[i] << std::endl;
        }
    }
private:
    int* arr;//arrָ������
    int front; //��ͷ�±�
    int rear;
    int size;
};