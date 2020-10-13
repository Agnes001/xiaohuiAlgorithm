#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
    }
};

class MyLinkedList {

public:
    /// <summary>
    /// 链表插入元素
    /// </summary>
    /// <param name="data"></param>
    /// <param name="index"></param>
    void insert(int data, int index)
    {
        Node* insertNode = new Node(data);
        if (size == 0)
        {
            //空链表
            head = insertNode;
            last = insertNode;
        }
        else if (index == 0)
        {
            //插入头部
            insertNode->next = head;
            head = insertNode;
        }
        else if (size == index)
        {
            //插入尾部
            last->next = insertNode;
            last = insertNode;
        }
        else
        {
            //插入中间
            Node* prevNode = get(index - 1);
            insertNode->next = prevNode->next;
            prevNode->next = insertNode;
        }
        size++;
    }
    /// <summary>
    /// 链表查找元素
    /// </summary>
    /// <param name="index">查找的位置</param>
    /// <returns></returns>
    Node* get(int index)
    {
        Node* tmp = head;
        for (int i = 0; i < index; i++)
        {
            tmp = tmp->next;
        }
        return tmp;
    }
    /// <summary>
    /// 链表删除元素
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    Node* remove(int index)
    {
        if (index < 0 || index >= size)
        {
            return nullptr;
        }
        Node* removeNode = NULL;
        if (index == 0)
        {
            //删除头节点
            removeNode = head;
            head = removeNode->next;
        }
        else if (index == size - 1)
        {
            //删除尾节点 
            Node* prevNode = get(index - 1);
            removeNode = prevNode->next;
            prevNode->next = NULL;
            last = prevNode;
        }
        else
        {
            //删除中间节点
            Node* prevNode = get(index - 1);
            Node* nextNode = prevNode->next->next;
            removeNode = prevNode->next;
            prevNode->next = nextNode;
        }
        size--;
        return removeNode;
    }
    /// <summary>
    /// 输出链表
    /// </summary>
    void output()
    {
        Node* tmp = head;
        while (tmp != NULL)
        {
            std::cout << tmp->data << std::endl;
            tmp = tmp->next;
        }
    }
private:
    //头节点指针
    Node* head;
    //尾节点指针
    Node* last;
    //链表实际长度
    int size;
};