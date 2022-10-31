class Solution {
public:
    int trap(vector<int>& h) {
               ios_base::sync_with_stdio(false);
        cin.tie(NULL); //work fast

        int res=0;
        int n=h.size();
        int left[n]; // store max to right
        int right[n]; // store max to left 
        left[0]=h[0];
        right[n-1]=h[n-1];
        
        for(int i=1;i<n;i++)
            left[i]=max(left[i-1],h[i]);
        
        for(int i=n-2;i>=0;i--)
            right[i]=max(right[i+1],h[i]);
        
        int w[n];
        
        for(int i=0;i<n;i++)
            w[i]=min(left[i],right[i])-h[i];
        
        res=accumulate(w,w+n,0);
        return res;
    }
};
