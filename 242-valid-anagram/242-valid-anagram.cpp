class Solution {
public:
    bool isAnagram(string s, string t) {
        //unordered_map<string,int> mp(26,0);
        sort(s.begin(),s.end());
        int ss = s.size();
        int ts = t.size();
        if(ts!=ss) return false;
        sort(t.begin(),t.end());
        int i =0;
        while(i<ss){
            if(s[i] != t[i]){
                return false;
            }
            i++;
        }
        return true;
        
    }
};