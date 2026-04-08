class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int>res=nums;
        int i=0;
        for(int i=0;i<n;i++){
            res.push_back(nums[i]);
        }
        return res;

    }
};