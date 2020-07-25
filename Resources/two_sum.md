# Two Sum:
----------

1. Sorting and Two Pointers

Algorithm:

1.    hasArrayTwoCandidates (A[], ar_size, sum)
2.    Sort the array in non-decreasing order.
3.    Initialize two index variables to find the candidate
      elements in the sorted array.
	       a. Initialize first to the leftmost index: l = 0
	       b. Initialize second the rightmost index: r = ar_size-1
4.    Loop while l<r.
			a. If (A[l] + A[r] == sum) then return 1
			b. Else if( A[l] + A[r] < sum ) then l++
			c. Else r--
>
5.    No candidates in whole array – return 0


==============================================================================


2. Hashing

Algorithm:

1.    Initialize an empty hash table s.
2.    Do following for each element A[i] in A[]
        If s[x – A[i]] is set then print the pair (A[i], x – A[i])
        Insert A[i] into s.

Pseudo Code :

		unordered_set s
		for(i=0 to end)
			if(s.find(target_sum - arr[i]) == s.end)
				insert(arr[i] into s)
			else 
				print arr[i], target-arr[i]



