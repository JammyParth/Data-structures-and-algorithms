class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> positions;
        int mincount = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            positions[nums[i]].push_back(i);

            // If this element appears at least 3 times
            if (positions[nums[i]].size() >= 3) {
                vector<int>& pos = positions[nums[i]];
                int first = pos.front();
                int last = pos.back();
                mincount = min(mincount, 2 * (last - first));
                pos.erase(pos.begin());
            }
        }

        return (mincount == INT_MAX ? -1 : mincount);
    }
};