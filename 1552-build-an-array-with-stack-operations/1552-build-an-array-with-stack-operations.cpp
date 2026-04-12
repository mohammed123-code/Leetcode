class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int index = 0;
        int m = target.size();

        for (int i = 1; i <= n && index < m; i++) {
            res.push_back("Push");

            if (target[index] != i) {
                res.push_back("Pop");
            } else {
                index++;
            }
        }

        return res;
    }
};