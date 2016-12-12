**题目：**

给出一个不含重复数字的排列，求这些数字的所有排列按字典序排序后该排列的编号。其中，编号从1开始。

**样例：**

例如，排列 [1,2,4] 是第 1 个排列。


----------


**分析：**
这个题目的意思就是，给定一组数字（不重复），给出某一个排列，求这个排列在全排列中按照字典序的位置。

**思路一：**

首先可以想到使用C++中的STL：next_permutation函数生成全排列，然后一个个遍历这个全排列，找到目标排列。

```
//代码超时（TLE）
class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        
        vector<int> B(A);
        long long res=2;
        
        sort(B.begin(),B.end());
        
        if(B==A)
            return 1;
        while (next_permutation(B.begin(), B.end()))
	    {   
            if(B==A)
                break;
            else
                res++;
	    }
	    return res;

    }
};
```

[关于C++的next_permutation函数](http://leonard1853.iteye.com/blog/1450085)

**关于全排列的拓展**
递归实现全排列
```
void perm(char a[], int n, int k) {

	if (k == n - 1) {//这是终止条件因为是交换所以到n-1步的时候就等于排好了全部了。  

		for (int i = 0; i < n; i++)

			cout << a[i] << " "; cout << endl;

	}

	else {

		for (int i = k; i < n; ++i)

		{

			int temp = a[i];//交换步骤  

			a[i] = a[k];

			a[k] = temp;

			perm(a, n, k + 1);//确定排完第一个之后排接下去的（n-1）个。

			temp = a[i];//排完后要复原状态  

			a[i] = a[k];  a[k] = temp;

		}

	}

}

int main() {

	char a[] = { 'a','b','c','d','e' };

	perm(a, 5, 0);

	return 0;
}
```

----------


**思路二：**

第一种方法可能能找出答案，但是做了大量的重复工作，具有较大的时间和空间复杂度。
找出给定排列的第一位数字在字典序的位置，在根据它的位置，推算出前面已经有多少个排列。

例如：
给定21345，那么根据字典序12345，2排在第二位，此时只要计算前面1的所有排列再加上1，即可得到21345在全排列中的位置，即4*3*2*1+1=24+1=25。

后面的位置类似。

此时可以写出如下代码。


```
class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
     //计算阶乘的函数
     long long fac(int a)
     {
         long long res=1;
         while(a!=1)
            res*=a--;
         return res;
     }
     
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        if(A.empty()) return 0;
        if(A.size()==1) return 1;
        
        long long res=1;
        vector<int> B(A);
        
        sort(B.begin(),B.end());
        
        //记录位数
        int dig=A.size()-1;
        
        int j=0;
        
        for(int i=0;i<A.size()-1;++i)
        {
            //找出A中每一位数字在B中的位置
            while(A[i]!=B[j])
                j++;
            //重点：如何判断这个数字前面有多少个排列了呢？
            //注意当前面一位已经插入进排列，那么必须在此时的有序数组中删除已经插入进排列中的数字，这时候使用迭代器删除。
            res+=j*fac(dig--);
            B.erase(B.begin()+j);
            j=0;
        } 
	    return res;
    }
};
```



