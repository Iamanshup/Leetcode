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
    Node* dfs(Node* node, map<Node*, Node*> &oldToNewNodeMap) {
        if (node == NULL) {
            return NULL;
        }

        Node* newNode = new Node(node -> val);
        oldToNewNodeMap[node] = newNode;

        for (Node* neighbor : node -> neighbors) {
            if (oldToNewNodeMap.find(neighbor) != oldToNewNodeMap.end()) {
                newNode -> neighbors.push_back(oldToNewNodeMap[neighbor]);
            } else {
                newNode -> neighbors.push_back(dfs(neighbor, oldToNewNodeMap));
            }
        }

        return newNode;
    }

    Node* cloneGraph(Node* node) {
        map<Node*, Node*> oldToNewNodeMap;
        return dfs(node, oldToNewNodeMap);
    }
};