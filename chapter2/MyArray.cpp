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
    /// 数组插入元素
    /// </summary>
    /// <param name="element">插入的元素</param>
    /// <param name="index">插入的位置</param>
    void insert(int element, int index)
    {
        //判断访问下标是否超出范围
        if (index<0 || index>_size)
        {
            return;
        }
        //如果实际元素达到数组容量上线，数组扩容
        if (_size>=_calpacity)
        {
            resize();
        }
        //从右向左循环，逐个向右挪一位
        for (int i = _size - 1; i >= index; i--)
        {
            _parr[i + 1] = _parr[i];
        }
        _parr[index] = element;
        _size++;
    }
    /// <summary>
    /// 数组扩容
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
    /// 数组删除元素
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    int deleteArr(int index)
    {
        //判断访问下标是否超出范围
        if (index < 0 || index >= _size) {
            return -1;
        }
        int deletedElement = _parr[index];
        //从左向右循环，逐个元素向左挪一位。
        for (int i = index; i < _size - 1; i++) {
            _parr[i] = _parr[i + 1];
        }
        _size--;
        return deletedElement;
    }

private:
    int* _parr;
    int _calpacity;//数组的总长度
    int _size;//实际存储数据长度

};