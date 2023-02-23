class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > p;
        for(int i = 0;i < capital.size() ; i++){
            p.push(make_pair(capital[i], i));
        }
        priority_queue<int>pq;
        
        
        
        while(k>0){
            while(!p.empty()){
                pair<int, int> indexCap = p.top();
                if(indexCap.first <= w){
                    pq.push(profits[indexCap.second]);
                    p.pop();
                }else{
                    break;
                }
                
            }
            if(!pq.empty()){
                int profit = pq.top();
                pq.pop();
                w += profit;
            }
            k--;
        }
        return w;
        
    }
};

