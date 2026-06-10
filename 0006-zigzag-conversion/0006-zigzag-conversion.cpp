class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;

        string res="";

        for(int i=0;i<numRows;i++){   //no rows times..
            int j=i;  //for traversing string
            int flag=1;  //for odd or even row check

            while(j<s.size()){
                res+=s[j];  //1)add
                if(i==0 || i==numRows-1){ // if last or first row
                    j+=(numRows-1)*2;
                }
                else if(flag%2!=0){//odd row
                    j+=(numRows-1)*2-(2*i);
                } 
                else{   //even row
                    j+=(2*i);
                }
                flag++;
            }
        }
        return res;
    }
};