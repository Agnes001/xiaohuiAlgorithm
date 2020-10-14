#include <iostream>
/// <summary>
/// 二叉树节点
/// </summary>
template <typename T>
struct TreeNode {
    T data;
    TreeNode<T>* leftChild;
    TreeNode<T>* rightChild;

    TreeNode(const T& data) :data(data), leftChild(nullptr), rightChild(nullptr) { }
};

template <typename T>
class BinaryTreeTraversal {
    typedef TreeNode<T> node;
public:
    BinaryTreeTraversal(T* arr, size_t n, const T& invalid)
    {
        size_t index = 0;
        _root = createBinaryTree(arr, n, invalid, index);
    }

    node* createBinaryTree(T* arr, size_t n, const T& invalid, size_t& index)
    {
        node* root = nullptr;
        if (arr[index] != invalid)
        {
            root = new node(arr[index]);
            root->leftChild = nullptr;
            root->rightChild = nullptr;

            size_t lnode = 2 * index + 1;
            size_t rnode = 2 * index + 2;

            if (lnode > n - 1) root->leftChild = nullptr;
            else root->leftChild = createBinaryTree(arr, n, invalid, lnode);

            if (rnode > n - 1) root->rightChild = nullptr;
            else root->rightChild = createBinaryTree(arr, n, invalid, rnode);
        }
        return root;
    }
    /// <summary>
    /// 前序遍历
    /// </summary>
    /// <param name="node"></param>
    void preOrderTraveral()
    {
        preOrder(_root);      
        std::cout<<std::endl;
    }
    void preOrder(node *root)
    {
        if (root)
        {
            std::cout << root->data << " ";
            preOrder(root->leftChild);
            preOrder(root->rightChild);
        }
    }
    /// <summary>
    /// 中序遍历
    /// </summary>
    /// <param name="node"></param>
    void inOrderTraveral()
    {
        inOrder(_root);
        std::cout << std::endl;
    }
    void inOrder(node *root)
    {
        if (root)
        {
            inOrder(root->leftChild);
            std::cout << root->data << " ";
            inOrder(root->rightChild);
        }
    }
    /// <summary>
    /// 后序遍历
    /// </summary>
    /// <param name="node"></param>
    void postOrderTraveral()
    {
        postOrder(_root);
        std::cout << std::endl;
    }
    void postOrder(node *root)
    {
        if (root)
        {
            postOrder(root->leftChild);
            postOrder(root->rightChild);
            std::cout << root->data << " ";
        }
    }
private:
    node* _root;
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5, '#', 6, '#', '#', 7, 8};
    BinaryTreeTraversal<int> biTree = { arr,sizeof(arr) / sizeof(arr[0]),'#' };
    std::cout << "前序排序" << std::endl;
    biTree.preOrderTraveral();
    std::cout << "中序排序" << std::endl;
    biTree.inOrderTraveral();
    std::cout << "后序排序" << std::endl;
    biTree.postOrderTraveral();

    system("pause");
    return 0;
}