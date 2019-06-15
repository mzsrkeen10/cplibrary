class Trie {
  private:
    struct TrieNode {
        vector<int> next;
        vector<int> accept;
        int num_string;
        TrieNode(int num_edge) : num_string(0), next(num_edge, -1) {}
    };

    int num_edge;
    int margin;
    vector<TrieNode> nodes;

  public:
    Trie(int num_edge, int margin) : num_edge(num_edge), margin(margin) {
        nodes.push_back(TrieNode(num_edge));
    }

    void add(const string &str, int str_id = nodes[0].num_string,
             int str_index = 0, int node_index = 0) {
        if (str_index == str.size()) {
            nodes[node_index].accept.push_back(str_id);
        } else {
            const int n = str[str_index] - margin;
            if (nodes[node_index].next[n] == -1) {
                nodes[node_index].next[n] = (int)nodes.size();
                nodes.push_back(TrieNode(num_edge));
            }
            nodes[node_index].num_string++;
            add(str, str_id, str_index + 1, nodes[node_index].next[n]);
        }
    }

    void query(const string &str, const function<void(int)> &f,
               int str_index = 0, int node_index = 0) {
        for (auto &index : nodes[node_index].accept)
            f(idx);
        if (str_index == str.size())
            return;

        const int n = str[str_index] - margin;
        if (nodes[node_index].next[n] == -1)
            return;
        query(str, f, str_index + 1, nodes[node_index].next[n]);
    }

    int count(const string &str, int str_index = 0, int node_index = 0) {
        if (str_index == str.size())
            return nodes[node_index].accept.size();

        const int n = str[str_index] - margin;
        if (nodes[node_index].next[n] == -1)
            return 0;
        return count(str, str_index + 1, nodes[node_index].next[n]);
    }

    int size() { return nodes[0].num_string; }
};
