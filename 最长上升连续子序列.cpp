//我的答案
class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        int upMax=1;
        int downMax=1;
        
        int res=1;
        int Now=1;
        
        int i=0;
        
        if(A.size()==0) return 0;
        while(i<A.size()-1)
        {
            while(A[i]<=A[i+1]&&i<A.size()-1)
            {
                upMax++;
                i++;
            }
            if(i<A.size()-1)
            {
                while(A[i]>=A[i+1]&&i<A.size()-1)
                {
                    downMax++;
                    i++;
                }
            }
            Now=max(upMax,downMax);
            if(res<Now)
                res=Now;
            upMax=1;
            downMax=1;
        }
        return res;
    }
};

// Time:  O(m * n)
// Space: O(m * n)

class Solution {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        if (A.empty()) {
            return 0;
        }

        // max_inc_len[i][j] stores the length of longest increasing continuous 
        // subsequence which starts with A[i][j]
        vector<vector<int>> max_inc_len(A.size(), vector<int>(A[0].size(), 0));
        int ans = 0;

        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[0].size(); ++j) {
                // Not yet visited.
                if (max_inc_len[i][j] == 0) {
                    ans = max(ans, fill(A, i, j, INT_MIN, max_inc_len));
                }
            }
        }

        return ans;
    }

    int fill(const vector<vector<int>>& A, const int i, const int j,
             const int prev_val,
             vector<vector<int>>& max_inc_len) {
        // Invalid cases.
        if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size() ||
            A[i][j] <= prev_val) {
            return 0;
        }

        // Return max_inc_len if visited.
        if (max_inc_len[i][j] > 0) {
            return max_inc_len[i][j];
        }

        // Try each direction to find the max of max_inc_len[i][j].
        const vector<pair<int, int>> directions = {{0, 1}, {0, -1},
                                                   {1, 0}, {-1, 0}};
        for (const auto& d : directions) {
            max_inc_len[i][j] = max(max_inc_len[i][j],
                                    1 + fill(A, i + d.first, j + d.second,
                                             A[i][j], max_inc_len));
        }

        return max_inc_len[i][j];
    }
};


// Time:  O(m * n)
// Space: O(m * n)
class Solution2 {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        if (A.empty()) {
            return 0;
        }

        // max_inc_len[i][j] stores the length of longest decreasing continuous 
        // subsequence which starts with A[i][j]
        vector<vector<int>> max_inc_len(A.size(), vector<int>(A[0].size(), 0));
        int ans = 0;

        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[0].size(); ++j) {
                // Not yet visited.
                if (max_inc_len[i][j] == 0) {
                    ans = max(ans, fill(A, i, j, INT_MAX, max_inc_len));
                }
            }
        }

        return ans;
    }

    int fill(const vector<vector<int>>& A, const int i, const int j,
             const int prev_val,
             vector<vector<int>>& max_inc_len) {
        // Invalid cases.
        if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size() ||
            A[i][j] >= prev_val) {
            return 0;
        }

        // Return max_inc_len if visited.
        if (max_inc_len[i][j] > 0) {
            return max_inc_len[i][j];
        }

        // Try each direction to find the max of max_inc_len[i][j].
        const vector<pair<int, int>> directions = {{0, 1}, {0, -1},
                                                   {1, 0}, {-1, 0}};
        for (const auto& d : directions) {
            max_inc_len[i][j] = max(max_inc_len[i][j],
                                    1 + fill(A, i + d.first, j + d.second,
                                             A[i][j], max_inc_len));
        }

        return max_inc_len[i][j];
    }
};
