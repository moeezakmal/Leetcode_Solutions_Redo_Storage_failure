// Time: O(V+E) = O(n)
// Space: O(n) -> hashmap

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> umap;

        if (node == NULL)
            return NULL;
        
        else
            return dfs(node, umap);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& hmap)
    {
        if(hmap.find(node) != hmap.end())
        {
            return hmap[node];
        }

        Node* copy = new Node(node->val);
        hmap[node] = copy;

        for(const auto& nei : node->neighbors)
        {
            copy->neighbors.push_back(dfs(nei, hmap));
        }

        return copy;
    }

};