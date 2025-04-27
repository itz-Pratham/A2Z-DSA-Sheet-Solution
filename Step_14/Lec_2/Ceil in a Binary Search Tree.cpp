// GFG same ques

// User function Template for C++

// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    int ans = -1;
    while (root != NULL) {
        if (root->data == input) {
            return root->data;
        }
        if (root->data > input) {
            ans = root->data;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ans;
}