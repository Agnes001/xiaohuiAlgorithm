//#include <iostream>

class MyArray {

public:
    MyArray(int capacity)
    {
        _parr = new int[capacity];
        _calpacity = capacity;
        _size = 0;
    }
    ~MyArray()
    {
        delete[] _parr;
    }
    /// <summary>
    /// �������Ԫ��
    /// </summary>
    /// <param name="element">�����Ԫ��</param>
    /// <param name="index">�����λ��</param>
    void insert(int element, int index)
    {
        //�жϷ����±��Ƿ񳬳���Χ
        if (index<0 || index>_size)
        {
            return;
        }
        //���ʵ��Ԫ�شﵽ�����������ߣ���������
        if (_size>=_calpacity)
        {
            resize();
        }
        //��������ѭ�����������Ųһλ
        for (int i = _size - 1; i >= index; i--)
        {
            _parr[i + 1] = _parr[i];
        }
        _parr[index] = element;
        _size++;
    }
    /// <summary>
    /// ��������
    /// </summary>
    void resize()
    {
        int *tmparr = new int[_calpacity * 2];
        for (int i = 0; i < _calpacity; i++)
        {
            tmparr[i] = _parr[i];
        }
        _parr = tmparr;
    }
    /// <summary>
    /// ����ɾ��Ԫ��
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    int deleteArr(int index)
    {
        //�жϷ����±��Ƿ񳬳���Χ
        if (index < 0 || index >= _size) {
            return -1;
        }
        int deletedElement = _parr[index];
        //��������ѭ�������Ԫ������Ųһλ��
        for (int i = index; i < _size - 1; i++) {
            _parr[i] = _parr[i + 1];
        }
        _size--;
        return deletedElement;
    }

private:
    int* _parr;
    int _calpacity;//������ܳ���
    int _size;//ʵ�ʴ洢���ݳ���

};