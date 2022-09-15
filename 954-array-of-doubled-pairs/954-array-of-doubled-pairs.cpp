class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        if(n & 1) return false;
        map<int,int>mp;
        
        for(auto x: arr) mp[x]++;
        for(auto i: mp){
            int x =  i.first;
            if( mp[x] == 0){
                continue;
            }
            while(mp[x] > 0){
                mp[x]--;
                if(x < 0){
                    if(abs(x)&1){
                        return false;
                    }
                    if(mp[x/2] > 0){
                        mp[x/2]--;
                    }
                    else{
                        return false;
                    }
                }
                else if(x > 0){
                    if(mp[x*2] >0){
                        mp[x*2]--;
                    }
                    else{
                        return false;
                    }
                }
            }if(mp[x]<0){
                return false;
            }
        }
        return true;
    }
};