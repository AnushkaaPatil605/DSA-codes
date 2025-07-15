#include <iostream>
#include <string>

using namespace std;

class dictionary;

class node {
    string word, meaning;
    node *left, *right;

public:
    friend class dictionary;
    node() {
        left = NULL;
        right = NULL;
    }
    node(string word, string meaning) {
        this->word = word;
        this->meaning = meaning;
        left = NULL;
        right = NULL;
    }
};

class dictionary {
    node *root;

    node* findMin(node *rnode);
    node* deleteWord(node* root, string key);

public:
    dictionary() {
        root = NULL;
    }
    void create();
    void inorder_rec(node *rnode);
    void postorder_rec(node *rnode);
    void inorder();
    void postorder();
    bool insert(string word, string meaning);
    int search(string key);
    void deleteWord(string key);
};

int dictionary::search(string key) {
    node *tmp = root;
    int count = 0;

    while (tmp != NULL) {
        count++;
        if (key < tmp->word) {
            tmp = tmp->left;
        } else if (key > tmp->word) {
            tmp = tmp->right;
        } else {
            cout << "\nWord: " << key << "\nMeaning: " << tmp->meaning << "\n";
            return count;
        }
    }
    return -1;
}

// Function to find the minimum node in the right subtree
node* dictionary::findMin(node *root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Recursive function to delete a word
node* dictionary::deleteWord(node* root, string key) {
    if (root == NULL) return NULL;

    if (key < root->word) {
        root->left = deleteWord(root->left, key);
    } else if (key > root->word) {
        root->right = deleteWord(root->right, key);
    } else {
        // Node with one or no child
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        node* temp = findMin(root->right);
        root->word = temp->word;
        root->meaning = temp->meaning;
        root->right = deleteWord(root->right, temp->word);
    }
    return root;
}

// Public function to delete a word
void dictionary::deleteWord(string key) {
    if (search(key) == -1) {
        cout << "\nWord not found!";
    } else {
        root = deleteWord(root, key);
        cout << "\nWord '" << key << "' deleted successfully!";
    }
}

void dictionary::postorder() {
    postorder_rec(root);
}

void dictionary::postorder_rec(node *rnode) {
    if (rnode) {
        postorder_rec(rnode->right);
        cout << " " << rnode->word << " : " << rnode->meaning << endl;
        postorder_rec(rnode->left);
    }
}

void dictionary::create() {
    int n;
    string wordI, meaningI;
    cout << "\nEnter number of words you want to insert: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\nWord: ";
        cin >> wordI;
        cout << "\nMeaning: ";
        cin.ignore();
        getline(cin, meaningI);
        insert(wordI, meaningI);
    }
}

void dictionary::inorder_rec(node *rnode) {
    if (rnode) {
        inorder_rec(rnode->left);
        cout << " " << rnode->word << " : " << rnode->meaning << endl;
        inorder_rec(rnode->right);
    }
}

void dictionary::inorder() {
    inorder_rec(root);
}

bool dictionary::insert(string word, string meaning) {
    node *p = new node(word, meaning);
    if (root == NULL) {
        root = p;
        return true;
    }
    node *cur = root;
    node *par = NULL;
    
    while (cur != NULL) {
        par = cur;
        if (word > cur->word) {
            cur = cur->right;
        } else if (word < cur->word) {
            cur = cur->left;
        } else {
            cout << "\nWord is already in the dictionary.";
            return false;
        }
    }
    
    if (word > par->word) {
        par->right = p;
    } else {
        par->left = p;
    }
    return true;
}

int main() {
    dictionary dict;
    int choice;
    string word, meaning;

    do {
        cout << "\n************** PRACTICAL NO: 09 (D-19) ***************";
        cout << "\nPrepared By: Anushka Patil";
        cout << "\n===== Dictionary Menu =====";
        cout << "\n1. Insert a word";
        cout << "\n2. Search for a word";
        cout << "\n3. Display words in ascending order (Inorder)";
        cout << "\n4. Display words in descending order (Postorder)";
        cout << "\n5. Delete a word";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nEnter word: ";
            cin >> word;
            cout << "Enter meaning: ";
            cin.ignore();
            getline(cin, meaning);
            dict.insert(word, meaning);
            break;

        case 2:
            cout << "\nEnter word to search: ";
            cin >> word;
            int comparisons;
            comparisons = dict.search(word);
            if (comparisons == -1)
                cout << "\nWord not found!\n";
            else
                cout << "\n " << word << " found in " << comparisons << " comparisons\n";
            break;

        case 3:
            cout << "\nDictionary in Ascending Order:\n";
            dict.inorder();
            break;

        case 4:
            cout << "\nDictionary in Descending Order:\n";
            dict.postorder();
            break;

        case 5:
            cout << "\nEnter word to delete: ";
            cin >> word;
            dict.deleteWord(word);
            break;

        case 6:
            cout << "\nExiting program...\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

