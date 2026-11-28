class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();

        vector<int> factor(n),price(n);

        for(int i=0;i<n;i++){
            factor[i]=items[i][0];
            price[i]=items[i][1];
        }


        vector<int>arr(n,0);


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && factor[j]%factor[i] ==0 ){
                    arr[i]++;
                }
            }
        }



        vector<int>dp(budget+1,0);
        for(int i=0;i<n;i++){
            vector<int>ndp=dp;


            for(int b=budget-price[i];b>=0;b--){
                ndp[b+price[i]]=max(ndp[b+price[i]], dp[b]+1+arr[i]);
            
            }


            for(int b=price[i];b<=budget;b++){
                ndp[b]=max(ndp[b],ndp[b-price[i]]+1);
            }


            dp=move(ndp);

            
        }

        return *max_element(dp.begin(),dp.end());
    }
};