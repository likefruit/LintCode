// Bubble sort
class Solution {
public:
	/**
	* @param A an integer array
	* @return void
	*/
	void  sortIntegers(vector<int> &A)
	{
		for (int i = A.size() - 1; i >= 0; i--)
		{

			for (int j = 0; j < i; j++)
			{
				if (A[j + 1] < A[j])
					swap(A[j + 1], A[j]);
			}

		}
	}
};
