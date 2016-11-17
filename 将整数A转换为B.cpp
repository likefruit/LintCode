//自己的解法
class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        vector<string> str;
        unsigned int result=0;//无符号数
        int count=0;
        result=a^b;
        while(result)
        {
            count+=result%2;
            result/=2;
        }
        count+=result%2;
        return count;
    }
};

// Time:  O(logn) = O(32)
// Space: O(1)

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        int cnt = 0;
        for (int c = a ^ b; c != 0; c &= c - 1) {
            ++cnt;
        }
        return cnt;
    }
}; 
