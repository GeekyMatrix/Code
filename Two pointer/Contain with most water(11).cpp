class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int max_amount=0;
        int l=0;
        int r=n-1;
        while(l<r){
        int min_h=min(height[l],height[r]);
        
        max_amount=max(max_amount,(min_h)*(r-l));

        if(height[l]<height[r]) l++;
        else r--;
        }

        return max_amount;
    }
};
