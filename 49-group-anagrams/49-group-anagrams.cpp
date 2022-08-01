class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>>  mp;  // <[]( , , ,)>
        for(int i =0;i<strs.size();i++){
            string x = strs[i]; //Copy
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(x);
        }
        for(auto j = mp.begin(); j!=mp.end();j++){
            ans.push_back(j->second);
        }
        return ans;
    }
};