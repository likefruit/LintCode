//题目应该作以下修改
//不能连续三个柱子有相同的颜色

//此题是经典的DP问题
//思考动态规划的第一点----最优子结构：
//思考动态规划的第二点----子问题重叠：
//思考动态规划的第三点----边界：
//思考动态规划的第四点----子问题独立：
class Solution {  
public:  
    /** 
     * @param n non-negative integer, n posts 
     * @param k non-negative integer, k colors 
     * @return an integer, the total number of ways 
     */  
    int numWays(int n, int k) {  
        // Write your code here  
        if (n==0 || k==0) return 0;  
        if (n==1) return k;  
        if (n==2) return k*k;  
        if (k == 1) return 0;  
        int num[3];  
        num[1] = k;  
        num[2] = k*k;  
        int temp=num[2];  
        for(int i=3; i<=n; i++) {  
            temp = num[1] * (k-1) + num[2] * (k-1);  
            num[1] = num[2];  
            num[2] = temp;  
        }  
        return temp;  
    }  
};  
