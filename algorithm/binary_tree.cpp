/*
* 作者：刘时明
* 时间：2020/6/17-22:55
* 作用：
*/
template<typename K, typename V>
class BinTreeNode
{
private:
    BinTreeNode<K, V> *left;
    BinTreeNode<K, V> *right;
    BinTreeNode<K, V> *parent;
    K key;
    V value;

public:
    BinTreeNode() = default;

    BinTreeNode(K key, V value)
    {
        BinTreeNode(nullptr, nullptr, nullptr, key, value);
    }

    BinTreeNode(BinTreeNode<K, V> *left, BinTreeNode<K, V> *right, BinTreeNode<K, V> *parent, K key, V value)
    {
        this->key = key;
        this->value = value;
        this->left = left;
        this->right = right;
        this->parent = parent;
    }

    template<typename K1, typename V1>
    friend
    class BinaryTree;
};

template<typename K, typename V>
class BinaryTree
{
private:
    BinTreeNode<K, V> *root;
    int c_size;

public:
    BinaryTree()
    {
        this->root = nullptr;
        this->c_size = 0;
    }

    int size() const
    {
        return this->c_size;
    }

    bool isEmpty() const
    {
        return this->c_size == 0;
    }

    bool insert(K key, V value)
    {
        if (this->root == nullptr)
        {
            root = new BinTreeNode<K, V>(key, value);
        } else
        {
            // auto *newNode = new BinTreeNode<K, V>(key, value);
            BinTreeNode<K, V> *temp = root;
            while (temp != nullptr)
            {
                if (temp->key > key)
                {
                    if (temp->right != nullptr)
                    {
                        temp = temp->right;
                    } else
                    {
                        temp->right = new BinTreeNode<K, V>(nullptr, nullptr, temp, key, value);
                    }
                } else if (temp->key < key)
                {
                    temp = temp->left;
                    if (temp->left != nullptr)
                    {
                        temp = temp->left;
                    } else
                    {
                        temp->left = new BinTreeNode<K, V>(nullptr, nullptr, temp, key, value);
                    }
                } else
                {
                    c_size--;
                    temp->value = value;
                    return false;
                }
            }
        }
        c_size++;
        return true;
    }
};
//void BinaryTreeDemo()
//{
//    auto *tree = new BinaryTree<int, int>();
//    tree->insert(1, 4);
//    tree->insert(2, 8);
//    cout << tree->size() << endl;
//}