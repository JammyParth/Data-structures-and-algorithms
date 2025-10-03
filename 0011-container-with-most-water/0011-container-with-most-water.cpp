class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int i = 0;
        int j = n - 1;
        int maxwater = INT_MIN;
        while(i < j){
            int dist = j - i;
            int water = dist * min(height[i] , height[j]);

            maxwater = max(water , maxwater);

            if(height[i] == height[j]){
                i++;
                j--;
            }

            else if(height[i] < height[j]){
                i++;
            }

            else{
                j--;
            }
        }

        return maxwater;
    }
};