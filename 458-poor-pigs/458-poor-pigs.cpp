class Solution {
public:
    bool func(int pigs,int t,int buckets){
         long long val = pow(t,pigs);
         if(val>=buckets) return 1;
         return 0;
    }
    int poorPigs(int buckets, int md, int mt) {
        int i = 0;
        int j = 12;
        int t = mt/md;
        t++;
        int ans=j;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(func(mid,t,buckets)){
                j=mid-1;
                ans=mid;
            }
            else i = mid+1; 
        }
        return ans;
    }
};
