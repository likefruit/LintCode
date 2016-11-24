//我的答案
class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        int i=0;
        int j=0;
        int k=0;
       
        if(n==0) return;
        if(m==0)
        {
            for(;j<n;++j)
                A[j]=B[j];
            return;
        }
        while(j<n)
        {
            if(A[m+j-1]<=B[j])
            {
                A[m+j]=B[j];
                j++;
            }
            else
            {
                while(A[i]<=B[j])
                    i++;
                for(k=m+j-1;k>=i;--k)
                {
                    A[k+1]=A[k];
                }
                A[i]=B[j];
                
                j++;
            }
        }
    }
};

// Time:  O(m + n)
// Space: O(1)

class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements,
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        int i = m + n;
        while (m > 0 && n > 0) {
            if (A[m - 1] > B[n - 1]) {
                A[i - 1] = A[m - 1];
                --m;
            } else {
                A[i - 1] = B[n - 1];
                --n;
            }
            --i;
        }

        while (n > 0) {
            A[i - 1] = B[n - 1];
            --n;
            --i;
        }
    }
};
