class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length(), z = 0;
        for (char c : s) if (c == '0') z++;
        if (z == 0) return 0;

        vector<int> dist(n + 1, -1);
        set<int> sets[2];
        for (int i = 0; i <= n; i++) sets[i % 2].insert(i);

        queue<int> q;
        q.push(z);
        dist[z] = 0;
        sets[z % 2].erase(z);

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            int x_min = max(0, k - (n - curr));
            int x_max = min(curr, k);
            int low = curr + k - 2 * x_max;
            int high = curr + k - 2 * x_min;

            auto& st = sets[low % 2];
            for (auto it = st.lower_bound(low); it != st.end() && *it <= high; ) {
                dist[*it] = dist[curr] + 1;
                if (*it == 0) return dist[*it];
                q.push(*it);
                it = st.erase(it);
            }
        }
        return -1;
    }
};