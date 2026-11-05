/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr){
            return nullptr;
        }
       unordered_set<int> seen;
       Node* head = new Node(node->val, node->neighbors);  
       queue<Node*> q;
       queue<Node*> qhead;
       q.push(node);
       qhead.push(head);
       while (!q.empty()){
            if (seen.contains(q.front()->val)){
                qhead.pop();
                q.pop();
                continue;
            }
            seen.insert(qhead.front()->val);
            Node* nexthead = qhead.front();
            qhead.pop();
            Node* nextnode = q.front();
            q.pop();
            vector<Node *> ns;
            for (Node * neighbor: nextnode->neighbors){
                if (neighbor && !seen.contains(neighbor->val)){
                    ns.push_back(neighbor);
                    q.push(neighbor);
                    qhead.push(neighbor);
                }
            }
            nexthead->neighbors = ns;
       }
       return head;
    }
};
