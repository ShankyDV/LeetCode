class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int start = 0, end = (int)nums.size() - 1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(nums[mid] < target) start = mid+1;
            else {
                if(nums[mid] == target) ans[0] = mid;
                end = mid-1;
            }
        }
        start = 0, end = (int)nums.size() - 1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(nums[mid] > target) end = mid-1;
            else {
                if(nums[mid] == target) ans[1] = mid;
                start = mid+1;
            }
        }
        return ans;
    }
};















// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         vector<int> ans(1);
//         if(nums.size()==0){
//             ans.push_back(-1);
//             ans.push_back(-1);
//             return ans;
//         }
//         int start = 0;
//         int end = nums.size()-1;
//         int i ,j =0;
//          while(start<=end){
//              int mid = end-(start-end)/2;
//              if(nums[mid]==target){
//                  int i,j = mid;
//                  while(i>=start && j<=end){
//                      if(nums[i]!= target && nums[j]!=target){
//                          ans[0] = i;
//                          ans[1] = j;
//                          return ans;
//                      }
//                      i--;
//                      j++;
//                  }
//              }
//              else if(nums[mid] > target){
//                 end = mid -1;
                 
//              }
//              else{
//                  start = mid + 1;
//              }
             
//          }
//         return ans;
//     }
// };
