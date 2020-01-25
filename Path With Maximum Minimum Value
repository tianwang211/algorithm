class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        
        vector<vector<int>> maxScore(A.size(), vector<int>(A[0].size(), INT_MIN));
        set<pair<int, int>> s;
        s.insert(make_pair(0, 0));
        
        while(!s.empty()) {
            pair<int, int> curIndex = *s.begin();
            s.erase(curIndex);

            int maxNeigh = INT_MIN;
            vector<pair<int, int>> validNeigh;
            for (int i = 0; i < 4; i++) {
                int row = curIndex.first + rows[i], col = curIndex.second + cols[i];
                if (row < 0 || row >= A.size() || col < 0 || col >= A[0].size()) continue;
                if (maxScore[row][col] != INT_MIN) maxNeigh = max(maxNeigh, maxScore[row][col]);
                validNeigh.push_back(make_pair(row, col));
            }
            
            int temp;
            if (maxNeigh != INT_MIN) temp = min(maxNeigh, A[curIndex.first][curIndex.second]);
            else temp = A[curIndex.first][curIndex.second];

            if (maxScore[curIndex.first][curIndex.second] < temp) {
                maxScore[curIndex.first][curIndex.second] = temp;
                for (int i = 0; i < validNeigh.size(); i++)
                    if (maxScore[validNeigh[i].first][validNeigh[i].second] == INT_MIN || min(temp, A[validNeigh[i].first][validNeigh[i].second]) > maxScore[validNeigh[i].first][validNeigh[i].second]) {
                        s.insert(validNeigh[i]);
                    }
            }
        }
        
        return maxScore.back().back();
    }

private:
    vector<int> rows = {1, -1, 0, 0};
    vector<int> cols = {0, 0, 1, -1};
};
