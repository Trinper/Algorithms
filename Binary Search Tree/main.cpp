#include <bits/stdc++.h>

struct Node{
    int key;
    Node* Left = nullptr;
    Node* Right = nullptr;
};

class BST {
    Node* root;

    static void DestroyNode(Node* node){
        if (node){
            DestroyNode(node->Left);
            DestroyNode(node->Right);
            delete node;
        }
    }

    public:

    BST(): root(nullptr){}

    ~BST(){
        DestroyNode(root);
    }

    Node* minNode(Node* node){
        if (!node){
            return nullptr;
        } else if (node -> Left){
            return minNode(node -> Left);
        } else {
            return node;
        }
    }

    Node* minNode(){
        return minNode(root);
    }

    Node* maxNode(Node* node){
        if (node -> Right){
            return maxNode(node -> Right);
        } else {
            return node;
        }
    }

    Node* maxNode(){
        return maxNode(root);
    }

    void insertNode(int key){
        Node** cur = &root;
        while (*cur){
            Node& node = **cur;
            if (key < node.key){
                cur = &node.Left;
            } else if (key > node.key){
                cur = &node.Right;
            } else {
                return;
            }
        }
        *cur = new Node {key, nullptr, nullptr};
    }

    Node* deleteNode(int key, Node* node){
        Node* temp;
        if (!node){
            return nullptr;
        }
        if (key < node -> key){
            node -> Left = deleteNode(key, node -> Left);
        } else if (key > node -> key){
            node -> Right = deleteNode(key, node -> Right);
        } else if (node -> Left && node -> Right){
            temp = minNode(node -> Right);
            node -> key = temp -> key;
            node -> Right = deleteNode(node -> key, node -> Right);
        } else {
            temp = node;
            if (!node -> Left){
                node = node -> Right;
            } else if (!node -> Right){
                node = node -> Left;
            }
            delete temp;
        }

        return node;
    }

    Node* deleteNode(int key){
        return deleteNode(key, root);
    }

    void removeNode(int key, Node* node){
        root = deleteNode(key, node);
    }

    void removeNode(int key){
        root = deleteNode(key);
    }

    static int getHeight(Node* node){
        int height  = -1;
        if (node){
            return std::max(getHeight(node -> Left), getHeight(node -> Right)) + 1;
        } else {
            return -1;
        }
    }

    int getHeight(){
        return getHeight(root);
    }

    Node* find(Node* node, int key){
        if (!node || node -> key == key){
            return node;
        }

        if (node -> key < key){
            return find(node -> Right, key);
        }

        return find(node -> Left, key);
    }

    bool search(int key){
        return find(root, key);
    }

    void ALR(Node* node){
        if (node){
            std::cout << node->key << '\n';
            ALR(node->Left);
            ALR(node->Right);
        }
    }

    void ALR(){
        ALR(root);
    }

    void LRA(Node* node){
        if (node){
            LRA(node->Left);
            LRA(node->Right);
            std::cout << node->key << '\n';
        }
    }

    void LRA(){
        LRA(root);
    }

    void LAR(Node* node){
        if (node){
            LAR(node->Left);
            std::cout << node->key << '\n';
            LAR(node->Right);
        }
    }

    void LAR(){
        LAR(root);
    }

    void ARL(Node* node){
        if (node){
            std::cout << node->key << '\n';
            ARL(node->Right);
            ARL(node->Left);
        }
    }

    void ARL(){
        ARL(root);
    }

    void RLA(Node* node){
        if (node){
            RLA(node->Right);
            RLA(node->Left);
            std::cout << node->key << '\n';
        }
    }

    void RLA() {
        RLA(root);
    }

    void RAL(Node* node){
        if (node){
            RAL(node->Right);
            std::cout << node->key << '\n';
            RAL(node->Left);
        }
    }

    void RAL(){
        RAL(root);
    }
};
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    BST tree;
    int key_delete;
    std::cin >> key_delete >> std::ws;
    int key;
    while (std::cin >> key){
        tree.insertNode(key);
    }

    std::cout << "Height of BST: " << tree.getHeight() << '\n';
    std::cout << "Tree before removal: " << '\n';
    tree.ALR();
    std::cout << '\n' << "The result of searching for a Node with a key equal to key_delete: " << (tree.search(key_delete) ? "true" : "false") << '\n';
    tree.removeNode(key_delete); //delete key_delete
    std::cout << "Height of BST after removal: " << tree.getHeight() << '\n';
    std::cout << "New tree after removal: " << '\n';
    tree.ALR();
    fclose (stdin);
    return 0;
}
