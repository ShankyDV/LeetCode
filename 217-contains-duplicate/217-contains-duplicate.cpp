class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        bool flag = false;
        for(auto &it: nums){
            if(s.find(it)!=s.end()){
                flag = true;
            }
            s.insert(it);
        }
        return flag;
    }
};