class Solution {
public:
    
    static bool comp(vector<int>& a, vector<int>& b) {
        return (a[1] - a[0]) > (b[1] - b[0]);
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        
        sort(tasks.begin(), tasks.end(), comp);

        int energy = 0;
        int current = 0;

        for (auto &t : tasks) {

            int actual = t[0];
            int minimum = t[1];

            if (current < minimum) {
                energy += (minimum - current);
                current = minimum;
            }

            current -= actual;
        }

        return energy;
    }
};