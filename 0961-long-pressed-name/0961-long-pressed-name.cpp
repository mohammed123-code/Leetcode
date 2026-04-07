class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name[0] != typed[0]){
            return false;
        }

        int n = name.size();
        int m = typed.size();
        
        if(n > m){
            return false;
        }

        int index = 0;

        for(int i = 0; i < m; ){
            if(index < n && typed[i] == name[index]){
                index++;
                i++;
            }
            else if(i > 0 && typed[i] == typed[i-1]){
                i++;
            }
            else{
                return false;
            }
        }

        return index == n;  
    }
};