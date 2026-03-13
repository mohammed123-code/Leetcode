class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini=INT_MAX;
        int sum=0;

        int left=0;
        int right=0;

        while(right<nums.size()){
            sum+=nums[right];
            right++;
            //---this is fo reduing window size
            while(sum>=target){
                int currwindow=right-left;
                mini=min(mini,currwindow);
                sum-=nums[left];
                left++;
            }
        }
        if(mini!=INT_MAX){
            return mini;
        }
        return 0;
    }
};