#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x): data(x), left(NULL), right(NULL) {}
};

// insert into BST
Node* insertBST(Node* r, int x){
    if(!r) return new Node(x);
    if(x < r->data) r->left  = insertBST(r->left, x);
    else if(x > r->data) r->right = insertBST(r->right, x);
    return r;
}

// number of nodes in longest path from root (height in nodes)
int heightNodes(Node* r){
    if(!r) return 0;
    int lh = heightNodes(r->left);
    int rh = heightNodes(r->right);
    return (lh>rh?lh:rh) + 1;
}

// minimum value in BST (leftmost)
bool findMin(Node* r, int &ans){
    if(!r) return false;
    while(r->left) r = r->left;
    ans = r->data; return true;
}

// mirror tree (swap left/right at every node)
void mirror(Node* r){
    if(!r) return;
    Node* t = r->left; r->left = r->right; r->right = t;
    mirror(r->left); mirror(r->right);
}

// search key
bool searchBST(Node* r, int key){
    if(!r) return false;
    if(key == r->data) return true;
    if(key < r->data) return searchBST(r->left, key);
    return searchBST(r->right, key);
}

// inorder display (sorted for normal BST)
void inorder(Node* r){
    if(!r) return;
    inorder(r->left); cout << r->data << " "; inorder(r->right);
}

int main(){
    Node* root = NULL;
    int n,x,ch;

    // construct initial BST
    cout << "Enter number of values: ";
    cin >> n;
    cout << "Enter values: ";
    for(int i=0;i<n;i++){ cin >> x; root = insertBST(root, x); }

    do{
        cout << "\n1.Insert  2.Longest path nodes  3.Minimum  4.Mirror  5.Search  6.Display(Inorder)  7.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch){
            case 1:
                cout << "Value: "; cin >> x; root = insertBST(root, x); break;
            case 2:
                cout << "Longest path length (nodes): " << heightNodes(root) << "\n"; break;
            case 3:{
                int m; if(findMin(root,m)) cout << "Minimum: " << m << "\n"; else cout << "Tree empty\n";
                break; }
            case 4:
                mirror(root); cout << "Tree mirrored.\n"; break;
            case 5:
                cout << "Search key: "; cin >> x;
                cout << (searchBST(root,x) ? "Found\n" : "Not found\n"); break;
            case 6:
                cout << "Inorder: "; inorder(root); cout << "\n"; break;
            case 7: cout << "Exit\n"; break;
            default: cout << "Invalid\n";
        }
    }while(ch!=7);

    return 0;
}
