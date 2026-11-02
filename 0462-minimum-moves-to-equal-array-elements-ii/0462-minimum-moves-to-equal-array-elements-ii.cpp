class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size()-1;
        int total = 0;

        while(left < right) {
            total += nums[right] - nums[left];
            left++;
            right--;
        }
        return total;
    }
};