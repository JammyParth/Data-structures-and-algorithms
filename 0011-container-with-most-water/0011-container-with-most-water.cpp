class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n - 1;

        int maxarea = INT_MIN;
        while(i < j){
            maxarea = max(min(height[i] , height[j]) * (j - i) , maxarea);

            if(height[i] <= height[j]){
                i++;
            }

            else{
                j--;
            }
        }

    return maxarea;
    }
};