题目

给定一个整数数组A。

定义B[i] = A[0] * … * A[i-1] * A[i+1] * … * A[n-1]， 计算B的时候请不要使用除法。

样例

给出A=[1, 2, 3]，返回 B为[6, 3, 2]

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */

    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        vector<long long> res;

        long long mul=1;

        int i=0;
        int j=0;

        for(;i<nums.size();++i)
        {
            while(j<nums.size())
            {
                if(i==j)
                {
                    j++;
                    continue;
                }
                else
                {
                    mul*=nums[j];
                    j++;
                }
            }
            res.push_back(mul);
            mul=1;
            j=0;
        }

        return res;
    }
};
