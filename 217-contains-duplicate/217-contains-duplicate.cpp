class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mp;
        bool flag = false;
        for(auto &it: nums){
            mp[it]++;
            if(mp[it]>1){
                return true;
            }
        }
        return flag;
    }
};