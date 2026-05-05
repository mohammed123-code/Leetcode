class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if (n != goal.size()) return false;

        vector<int> index;
        for (int i = 0; i < n; i++) {
            if (s[0] == goal[i]) {
                index.push_back(i);
            }
        }

        for (int k = 0; k < index.size(); k++) {
            int start = index[k];
            bool match = true;

            for (int j = 0; j < n; j++) {
                if (s[j] != goal[(start + j) % n]) {
                    match = false;
                    break;
                }
            }

            if (match) return true;
        }

        return false;
    }
};