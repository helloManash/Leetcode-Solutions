class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int size = code.size();
        if(k == 0){
            vector<int>v(code.size(), 0);
            return v;
        }
        vector<int>v;
        if(k > 0){
            for(int i = 0; i < size; i++){
                int sum = 0;
                int t = k;
                for(int j = i + 1; t > 0; j++){
                    j %= size;
                    sum += code[j];
                    t--;
                }
                v.push_back(sum);
            }
        }
        else{
            for(int i = 0; i < size; i++){
                int sum = 0, t = k;
                for(int j = (i + size + t) ;abs(t) > 0; j++){
                    j %= size;
                    sum += code[j];
                    t++;
                }
                v.push_back(sum);
            }
        }
        return v;
    }
};