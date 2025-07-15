#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    bool search = false;
    void getData(Node *&root);
    Node *insertNode(Node *&root, int d);
    void display(Node *&root);
    void minNode(Node *&root);
    void searchNode(Node *&root, int key);
    int longestPath(Node *&root);
    void swapPtr(Node *&root);  // Update this function to void as it modifies the tree in place
};

Node *BST ::insertNode(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    else
    {
        if (d < root->data)
        {
            root->left = insertNode(root->left, d);
        }
        if (d > root->data)
        {
            root->right = insertNode(root->right, d);
        }
        return root;
    }
}

void BST ::getData(Node *&root)
{
    int ip;
    cout << "Enter Data to insert in BST " << endl;
    cin >> ip;
    insertNode(root, ip);
}

void BST ::display(Node *&root)
{
    if (root == NULL)
    {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp != NULL)
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        else
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
    }
}

void BST::minNode(Node *&root)
{
    if (root == NULL)
    {
        cout << "Tree is empty!" << endl;
        return;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    cout << "Minimum Element of BST is " << root->data << endl;
}

void BST::searchNode(Node *&root, int key)
{
    search = false;
    if (root == NULL)
    {
        return;
    }
    if (root->data == key)
    {
        search = true;
        cout << "Key Found in BST" << endl;
        return;
    }

    if (root->data < key)
    {
        searchNode(root->right, key);
    }
    else
    {
        searchNode(root->left, key);
    }
}

int BST ::longestPath(Node *&root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftPath = longestPath(root->left);
    int rightPath = longestPath(root->right);

    return max(leftPath, rightPath) + 1;
}

// Corrected swapPtr function
void BST::swapPtr(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    // Swap left and right children
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recurse for the left and right subtrees
    swapPtr(root->left);
    swapPtr(root->right);
}

int main()
{
    BST b;
    Node *root = NULL;
    int ch, key;
    cout << "*** DSAL PRACTICAL - 04 (B-6) ***" << endl;
    cout << "*** Prepared By - Anshul Singh ***\n"
         << endl;

    while (1)
    {
        cout << "\nMENU : \n1.Insert Node\n2.Number of nodes in longest path\n3.Minimum Data\n4.Swap Left to Right and Vice Versa\n5.Search Value\n6.Display\n7.Exit" << endl;
        cout << "\nEnter Your Choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            b.getData(root);
            break;
        case 2:
            cout << "Longest path is : " << b.longestPath(root) << endl;
            break;
        case 3:
            b.minNode(root);
            break;
        case 4:
            b.swapPtr(root);  // Perform the swap
            cout << "Swapped Left <-> Right" << endl;
            cout << "Tree after swapping left and right subtrees:" << endl;
            b.display(root);  // Display the tree after the swap
            break;
        case 5:
            cout << "Enter Value to Search " << endl;
            cin >> key;
            b.searchNode(root, key);
            if (!b.search)
                cout << "Key Not Found in BST" << endl;
            break;
        case 6:
            b.display(root);
            break;

        default:
            cout << "\n\t***Terminated Successfully***" << endl;
            exit(0);
        }
    }
    return 0;
}

