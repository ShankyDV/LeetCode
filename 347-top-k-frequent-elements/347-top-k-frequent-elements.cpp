class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k == nums.size()) return nums;
        vector<int> ans;
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        for(auto it : nums){
            mp[it]++;
        }
        for(auto it= mp.begin(); it!=mp.end();it++){
            pq.push(make_pair(it->second,it->first));
        }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};