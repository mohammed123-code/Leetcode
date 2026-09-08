class Solution {
public:

    bool canFinish(vector<int>& piles, int h, int k){
        long long hours=0;  //should not exceed the h
        for(int i=0;i<piles.size();i++){
            hours+=piles[i]/k;
            if(piles[i]%k!=0){
                hours++;
            }
            if(hours>h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(), piles.end());
        int res;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(canFinish(piles, h, mid)){
                res=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return res;
    }
};