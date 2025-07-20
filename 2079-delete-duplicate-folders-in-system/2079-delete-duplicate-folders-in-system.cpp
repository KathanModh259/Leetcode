class Solution {
public:
    struct Node {
        unordered_map<string, Node*> children;
        string key;
        bool deleted = false;
    };

    Node* root = new Node();

    void insert(Node* node, vector<string>& path, int index) {
        if (index == path.size()) return;
        string& folder = path[index];
        if (!node->children.count(folder)) {
            node->children[folder] = new Node();
        }
        insert(node->children[folder], path, index + 1);
    }

    string mark(Node* node, unordered_map<string, vector<Node*>>& seen) {
        if (node->children.empty()) return "()";
        vector<pair<string, string>> sigs;
        for (auto& [name, child] : node->children) {
            sigs.push_back({name, mark(child, seen)});
        }
        sort(sigs.begin(), sigs.end());
        string signature;
        for (auto& [name, sig] : sigs) {
            signature += "(" + name + sig + ")";
        }
        node->key = signature;
        seen[signature].push_back(node);
        return signature;
    }

    void deleteDuplicates(unordered_map<string, vector<Node*>>& seen) {
        for (auto& [sig, nodes] : seen) {
            if (nodes.size() > 1) {
                for (auto* node : nodes) {
                    node->deleted = true;
                }
            }
        }
    }

    void collect(Node* node, vector<string>& path, vector<vector<string>>& result) {
        for (auto& [name, child] : node->children) {
            if (!child->deleted) {
                path.push_back(name);
                result.push_back(path);
                collect(child, path, result);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        for (auto& path : paths) {
            insert(root, path, 0);
        }
        unordered_map<string, vector<Node*>> seen;
        mark(root, seen);
        deleteDuplicates(seen);
        vector<vector<string>> result;
        vector<string> path;
        collect(root, path, result);

        return result;
    }
};

