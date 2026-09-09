class Solution {
public:

    bool canFinish(vector<int>& piles, int h, int n){
        long tot=0;
        for(int i=0;i<piles.size();i++){
            tot+=(piles[i]/n);
            if(piles[i]%n!=0){
                tot++;
            }
        }
        if(tot>h){
            return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(), piles.end());
        int res=high;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(canFinish(piles, h, mid)){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return res;
    }
};