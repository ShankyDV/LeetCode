class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(auto it: magazine){
            mp[it]++;
        }
        for(auto ti: ransomNote)
        {
            mp[ti]--;
        }
        
        for(auto i : mp){
            if(i.second < 0){
                return false;
            }
        }
        return true;
    }
};