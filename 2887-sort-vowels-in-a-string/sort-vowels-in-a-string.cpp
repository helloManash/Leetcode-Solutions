class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        if((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u')){
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        string t = "";
        for(auto i: s){
            if(isVowel(i)){
                t += i;
            }
        }
        sort(t.begin(), t.end());
        int j = 0;
        for(int i = 0;i < s.length(); i++){
            if(isVowel(s[i])){
                s[i] = t[j];
                j++;
            }
        }
        return s;
    }
};