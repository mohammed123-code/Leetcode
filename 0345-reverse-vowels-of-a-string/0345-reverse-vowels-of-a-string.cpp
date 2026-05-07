class Solution {
public:
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ||
                (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    string reverseVowels(string s) {
        vector<int>Index;
        vector<int>Vowels;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                Index.push_back(i);
                Vowels.push_back(s[i]);
            }
        }
        reverse(Vowels.begin(), Vowels.end());
        for(int i=0;i<Index.size();i++){
            s[Index[i]]=Vowels[i];
        }
        return s;

    }
};