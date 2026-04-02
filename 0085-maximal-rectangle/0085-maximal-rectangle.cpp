class Solution {
public:

    //-----------HELPER FUNCTION----------------------

    //this function is from Lettcode 84.Largest Rectangle ina  Histogram
    int largestRectangleArea(vector<int> heights) {
        int n=heights.size();
        stack<int>st;
        int maxi=0;
        for(int i=0;i<=n;i++){
            int currh;

            if(i==n){ 
                currh=0;
            }
            else{
                currh=heights[i];
            }

            while(!st.empty() && heights[st.top()] > currh ){
                int height=heights[st.top()];       
                st.pop();

                int right = i;
                int left;
                if(st.empty()){
                    left = -1;
                }
                else{
                    left = st.top();
                }

                int width=right-left-1;
                maxi=max(maxi,width*height);
            }
            st.push(i);
        }
        return maxi;
    }



//passing each rows to the helper function and finding the max area

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }

        int r=matrix.size();
        int c=matrix[0].size();
        int res=0;
        int maxi=0;
        vector<int>EachRow(c,0);  //column size vector

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='1'){
                    EachRow[j]+=1;
                }
                else{
                    EachRow[j]=0;
                }
            }
            res=largestRectangleArea(EachRow);
            maxi=max(res,maxi);
        }
        return maxi;
        
    }
};