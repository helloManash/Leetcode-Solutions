class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>pq;
        string a = "";
        map<int,int>mp;
        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
        }
        for(auto &[e, i] : mp){
            pq.push({i,e});
        }
        while(pq.size() > 1){
            auto el1 = pq.top();
            char t = el1.second;
            int num1 = el1.first;
            num1--;
            pq.pop();
            auto el2 = pq.top();
            char k = el2.second;
            int num2 = el2.first;
            num2--;
            pq.pop();
            a += t;
            a += k;

            if(num1 > 0){
                pq.push({num1, t});
            }
            if(num2 > 0){
                pq.push({num2, k});
            }
        }

        if(pq.size() == 1){
            if(pq.top().first > 1){
                return "";
            }
            else{
                if(a.empty()){
                    return s;
                }
                if(pq.top().second == a.back()){
                    return "";
                }
                a += pq.top().second;
                pq.pop();
            }
            
        }
        return a;
    }
};