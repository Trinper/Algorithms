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
    tree.removeNode(key_delete);
    tree.ALR();
    fclose (stdin);
    //fclose (stdout);
    return 0;
}
