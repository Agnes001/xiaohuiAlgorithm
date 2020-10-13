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
    /// �������Ԫ��
    /// </summary>
    /// <param name="data"></param>
    /// <param name="index"></param>
    void insert(int data, int index)
    {
        Node* insertNode = new Node(data);
        if (size == 0)
        {
            //������
            head = insertNode;
            last = insertNode;
        }
        else if (index == 0)
        {
            //����ͷ��
            insertNode->next = head;
            head = insertNode;
        }
        else if (size == index)
        {
            //����β��
            last->next = insertNode;
            last = insertNode;
        }
        else
        {
            //�����м�
            Node* prevNode = get(index - 1);
            insertNode->next = prevNode->next;
            prevNode->next = insertNode;
        }
        size++;
    }
    /// <summary>
    /// �������Ԫ��
    /// </summary>
    /// <param name="index">���ҵ�λ��</param>
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
    /// ����ɾ��Ԫ��
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
            //ɾ��ͷ�ڵ�
            removeNode = head;
            head = removeNode->next;
        }
        else if (index == size - 1)
        {
            //ɾ��β�ڵ� 
            Node* prevNode = get(index - 1);
            removeNode = prevNode->next;
            prevNode->next = NULL;
            last = prevNode;
        }
        else
        {
            //ɾ���м�ڵ�
            Node* prevNode = get(index - 1);
            Node* nextNode = prevNode->next->next;
            removeNode = prevNode->next;
            prevNode->next = nextNode;
        }
        size--;
        return removeNode;
    }
    /// <summary>
    /// �������
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
    //ͷ�ڵ�ָ��
    Node* head;
    //β�ڵ�ָ��
    Node* last;
    //����ʵ�ʳ���
    int size;
};