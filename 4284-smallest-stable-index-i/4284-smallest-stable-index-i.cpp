class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        
        vector<int>minArr(n);
        int mini=INT_MAX;
        
        for(int i=n-1;i>=0;i--){
            if(nums[i]<mini){
                mini=nums[i];
            }
            minArr[i]=mini;
        }


        int maxi=0;
        int score=0;
        for(int i=0;i<n;i++){
            if(maxi<nums[i]){
                maxi=nums[i];
            }
            score=maxi-minArr[i];
            if(score<=k){
                return i;
            }
        }
        return -1;
    }
};