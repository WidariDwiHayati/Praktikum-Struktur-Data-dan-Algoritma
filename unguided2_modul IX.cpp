#include <iostream>
#include <iomanip>

using namespace std;

struct Pohon
{
    char data_2311102060;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

void init()
{
    root = NULL;
}

bool isEmpty()
{
    return root == NULL;
}

void buatNode(char data_2311102060)
{
    if (isEmpty())
    {
        root = new Pohon();
        root->data_2311102060 = data_2311102060;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data_2311102060 << " berhasil dibuat sebagai root."
             << endl;
    }
    else
    {
        cout << "\n Tree sudah ada!" << endl;
    }
}

Pohon *insertLeft(char data_2311102060, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\n Node " << node->data_2311102060 << " sudah ada child kiri !" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data_2311102060 = data_2311102060;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data_2311102060 << " berhasil ditambahkan ke child kiri " << baru->parent->data_2311102060 << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data_2311102060, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\n Node " << node->data_2311102060 << " sudah ada child kanan !" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data_2311102060 = data_2311102060;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data_2311102060 << " berhasil ditambahkan ke child kanan " << baru->parent->data_2311102060 << endl;
            return baru;
        }
    }
}

void update(char data_2311102060, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        }
        else
        {
            char temp = node->data_2311102060;
            node->data_2311102060 = data_2311102060;
            cout << "\n Node " << temp << " berhasil diubah menjadi "
                 << data_2311102060 << endl;
        }
    }
}

void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data node : " << node->data_2311102060 << endl;
        }
    }
}

void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data Node : " << node->data_2311102060 << endl;
            cout << " Root : " << root->data_2311102060 << endl;
            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->data_2311102060 << endl;
            if (node->parent != NULL && node->parent->left != node &&
                node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data_2311102060 << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data_2311102060 << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << " Child Kiri : (tidakpunya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data_2311102060 << endl;
            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data_2311102060 << endl;
        }
    }
}

void displayChild(Pohon *node)
{
    if (node->left)
        cout << "Child kiri: " << node->left->data_2311102060 << endl;
    if (node->right)
        cout << "Child kanan: " << node->right->data_2311102060 << endl;
}

void displayDescendant(Pohon *node)
{
    if (node->left)
    {
        cout << "Descendant kiri: ";
        displayDescendant(node->left);
        cout << endl;
    }
    if (node->right)
    {
        cout << "Descendant kanan: ";
        displayDescendant(node->right);
        cout << endl;
    }
    if (!node->left && !node->right)
        cout << node->data_2311102060 << " ";
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data_2311102060 << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data_2311102060 << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data_2311102060 << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->data_2311102060 << " berhasil dihapus." << endl;
    }
}

void clear()
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    }
    else
    {
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic()
{
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}

int main()
{
    init();
    char data_2311102060;
    cout << "Masukkan data root: ";
    cin >> data_2311102060;
    buatNode(data_2311102060);
    Pohon *node;
    int pilihan;
    while (true)
    {
        cout << "\n Menu:" << endl;
        cout << "1. Tambah node kiri" << endl;
        cout << "2. Tambah node kanan" << endl;
        cout << "3. Update node" << endl;
        cout << "4. Retrieve node" << endl;
        cout << "5. Find node" << endl;
        cout << "6. Display child" << endl;
        cout << "7. Display descendant" << endl;
        cout << "8. PreOrder" << endl;
        cout << "9. InOrder" << endl;
        cout << "10. PostOrder" << endl;
        cout << "11. Delete subtree" << endl;
        cout << "12. Clear tree" << endl;
        cout << "13. Characteristic" << endl;
        cout << "14. Exit" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
        {
            char dataKiri;
            cout << "Masukkan data kiri: ";
            cin >> dataKiri;
            node = insertLeft(dataKiri, root);
            break;
        }
        case 2:
        {
            char dataKanan;
            cout << "Masukkan data kanan: ";
            cin >> dataKanan;
            node = insertRight(dataKanan, root);
            break;
        }
        case 3:
        {
            char dataUpdate;
            cout << "Masukkan data update: ";
            cin >> dataUpdate;
            update(dataUpdate, root);
            break;
        }
        case 4:
        {
            retrieve(root);
            break;
        }
        case 5:
        {
            find(root);
            break;
        }
        case 6:
        {
            displayChild(root);
            break;
        }
        case 7:
        {
            displayDescendant(root);
            break;
        }
        case 8:
        {
            preOrder();
            break;
        }
        case 9:
        {
            inOrder();
            break;
        }
        case 10:
        {
            postOrder();
            break;
        }
        case 11:
        {
            deleteSub(root);
            break;
        }
        case 12:
        {
            clear();
            break;
        }
        case 13:
        {
            characteristic();
            break;
        }
        case 14:
        {
            return 0;
        }
        default:
        {
            cout << "Pilihan tidak tersedia!" << endl;
            break;
        }
        }
    }
    return 0;
}