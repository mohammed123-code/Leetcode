class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        
        vector<int>minArr(n);
        minArr[n-1]=nums[n-1];
        
        int mini=INT_MAX;
        
        for(int i=n-2;i>=0;i--){
            minArr[i]=min(nums[i],minArr[i+1]);
        }
        


        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            int score=maxi-minArr[i];
            if(score<=k){
                return i;
            }
        }
        return -1;
    }
};