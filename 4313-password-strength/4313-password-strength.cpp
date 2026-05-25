class Solution {
public:
    int passwordStrength(string password) {
        int points=0;

        unordered_map<char,int>mp;

        for(char ch : password){
            mp[ch]++;
        }


        
        for(auto it : mp){
            char ch = it.first;
            if(isalpha(ch)){
                if(islower(ch)){
                    points+=1;
                }
                else{
                    points+=2;
                }
            }
            else if(ch-'0'>=0 && ch-'0'<=9){
                points+=3;
            }
            else{
                points+=5;
            }
        }
        return points;
    }
};