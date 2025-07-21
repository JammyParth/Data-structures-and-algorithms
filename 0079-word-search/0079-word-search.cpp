class Solution {
public:

    string target = "";
    bool dfs(vector<vector<char>>& board,string word, unordered_map<char, int> &mp ,vector<vector<bool>>& vis , int row , int col){

        int n = board.size();
        int m = board[0].size();

        // Bounds and visited check
        if (row < 0 || col < 0 || row >= n || col >= m || vis[row][col])
            return false;

        // Check if character is part of the word and in correct order
        if (!mp.count(board[row][col]) || board[row][col] != word[target.size()])
            return false;

        target.push_back(board[row][col]);
        vis[row][col] = true;

        // Check if we matched the whole word
        if (target == word)
            return true;

        // Explore all four directions
        bool found = dfs(board, word, mp, vis, row + 1, col) ||
                     dfs(board, word, mp, vis, row - 1, col) ||
                     dfs(board, word, mp, vis, row, col + 1) ||
                     dfs(board, word, mp, vis, row, col - 1);

        // Backtrack
        vis[row][col] = false;
        target.pop_back();

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n , vector<bool>(m , false));
        unordered_map<char, int> mp;

        for(auto val : word){
            mp[val]++;
        }

        for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
        if (board[i][j] == word[0]) {
                target = ""; // reset target for new start
                if (dfs(board, word, mp, vis, i, j)) return true;
        }
        }
        }
        return false;
    }
};