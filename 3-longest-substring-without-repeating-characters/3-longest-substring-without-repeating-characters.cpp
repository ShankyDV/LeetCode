class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0, r = n-1;
        unordered_set<char> v;
        int maxStr = 0;

        for(int r=0;r<n;r++)
        {
            if(v.find(s[r])==v.end())
            {
                v.insert(s[r]);
                maxStr = max(maxStr,r-l+1);
                
            }
            else
            {
                while(l!=r && s[l]!=s[r])
                    v.erase(s[l++]);
                
                //Removing and adding the same element
                v.erase(s[l++]);
                v.insert(s[r]);
                
                maxStr = max(maxStr,r-l+1);
            }
        }
        
        return maxStr;
    }
};




// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         if(s.length() == 0) return 0;
//         if(s.length() == 1) return 1;
//         unordered_set<int> st;
//         int l =0;
//         int mx = INT_MIN;
//         for(int i =0; i< s.length();i++){
//             if(st.find(s[i])!=st.end()){
//                 mx = max(mx,l);
//                 l = 0;
//             }
//             else{
//                 st.insert(s[i]);
//                 l++;
//                 mx = max(mx,l);
//             }
//         }
//         return mx;
//     }
// };