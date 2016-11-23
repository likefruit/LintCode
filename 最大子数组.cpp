//我的答案
class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int max=nums[0];
        int nowmax=0;
        for(int i=0;i<nums.size();++i)
        {
            nowmax+=nums[i];
            if(nowmax<0)
                nowmax=0;
            if(nowmax>max&&nowmax!=0)
                max=nowmax;
        }
        
        return max;
    }
};

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        int max_sum = INT_MIN, sum = 0;
        for (const auto& i : nums) {
            sum += i;
            max_sum = max(max_sum, sum);
            sum = max(sum, 0);
        }
        return max_sum;
    }
};
