class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>m;
        for(string path: paths){
            string pt;
            int i;
            for(i = 0; i < path.size() && path[i] != ' '; i++){
                pt += path[i];
            }
            pt +='/';
            i++;
            while( i < path.size()){
                string file, data;
                while(i < path.size() && path[i] != '('){
                    file += path[i++];
                }
                while(i < path.size() && path[i] != ' '){
                    data += path[i++];
                }
                m[data].push_back(pt + file);
                ++i;
                
            }
        }
        for(auto &x: m){
            if(x.second.size() > 1){
                ans.push_back(x.second);
            }
        }
        return ans;
    }
};