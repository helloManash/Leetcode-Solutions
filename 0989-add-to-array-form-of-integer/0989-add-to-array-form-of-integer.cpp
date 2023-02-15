class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        int cnt = 0, i = 0;
        while(k > 0 && i < num.size()){
            int sum = cnt + num[i] + k % 10;
            k /= 10;
            if(sum < 10){
                cnt = 0;
            }
            else{
                cnt = 1;
            }
            num[i] = sum % 10;
            i++;
        }
        while(i < num.size()){
            int sum = cnt + num[i];
            if(sum < 10){
                cnt = 0;
            }
            else{
                cnt = 1;
            }
            num[i] = sum % 10;
            i++;
        }
        
        while(k > 0){
            int sum = cnt + (k % 10);
            // cout<<sum<<" ";
            k /= 10;
            if(sum < 10){
                cnt = 0;
            }
            else{
                cnt = 1;
            }
            
            num.push_back(sum % 10);
        }
        if(cnt == 1){
            num.push_back(cnt);
        }
        reverse(num.begin(), num.end());
        return num;
    }
};