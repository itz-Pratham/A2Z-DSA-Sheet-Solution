class Solution {
    public:
        void deleteNode(ListNode* node) {
            *node = *node->next; // this means that the pointer of the given node should now point towards the next node
        }
    };