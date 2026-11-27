class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<long long> s;

        for(int i = 0; i < nums.size(); i++) {
            if(i > indexDiff) {
                s.erase(s.find(nums[i - indexDiff - 1]));
            }

            auto it = s.lower_bound((long long)nums[i] - valueDiff);

            if(it != s.end() && *it <= (long long)nums[i] + valueDiff) {
                return true;
            }

            s.insert(nums[i]);
        }

        return false;
    }
};