class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        unordered_map<int,int> mp;
        vector<pair<int,int>> v;
        Node* cur = head;
        
        while(cur != NULL){
            if(mp.find(target - cur->data) != mp.end()){
                v.push_back(make_pair(target - cur->data,cur->data));
            }
            mp[cur->data]++;
            cur = cur->next;
        }
        
        sort(v.begin(),v.end());
        return v;
    }
};