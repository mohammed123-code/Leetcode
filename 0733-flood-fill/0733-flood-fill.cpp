class Solution {
public:
    void func(vector<vector<int>>&image, int r, int c, int oldy, int newy){
        //base case

        int n=image.size();
        int m=image[0].size();

        if(r<0 || r>=n || c<0 || c>=m){
            return;
        }

        if(image[r][c]!=oldy){
            return;
        }

        //change the color
        image[r][c]=newy;

        func(image, r-1, c, oldy, newy);
        func(image, r+1, c, oldy, newy);
        func(image, r, c-1, oldy, newy);
        func(image, r, c+1, oldy, newy);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldy=image[sr][sc];

        if(oldy==color){
            return image;
        }

        func(image, sr, sc, oldy, color);

        return image;
    }
};