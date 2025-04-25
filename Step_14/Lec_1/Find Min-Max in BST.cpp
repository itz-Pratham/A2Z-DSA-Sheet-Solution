// This is a GFG problem find minimum element in BST .. very similar to the original one .. same approaches

// Function to find the minimum element in the given BST.

/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
*/

class Solution {
  public:
    pair<int,int> min_max_Value(Node* root) {
        // Code here
        if (!root) return {INT_MAX, INT_MIN}; // as per the question
        
        Node* temp1 = root;
        Node* temp2 = root;

        //for min
        while(temp1->left != NULL){
            temp1 = temp1->left;
        }

        // for max
        while(temp2->right != NULL){
            temp2 = temp2->right;
        }
        
        return {temp1->data, temp2->data};
    }
};