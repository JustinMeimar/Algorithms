# A Dynamic Programming based Python
# program for LPS problem Returns the length
#  of the longest palindromic subsequence in seq
def printLSP(D, str_, n, i, j):
    
    if j < len(str_)/2:
        return 0

    if D[i][j] == D[i][j-1] + 2:
        
        print(str_[j]) 
        printLSP(D, str_, n, i, j-1)
        print(str_[j])
    
    else:
        printLSP(D, str_, n, i, j-1)
    
def lps(str_):
    n = len(str_)
 
    # Create a table to store results of subproblems
    L = [[0 for x in range(n)] for x in range(n)]
 
    # Strings of length 1 are palindrome of length 1
    for i in range(n):
        L[i][i] = 0
 

    # cl is length of substring
    for cl in range(2, n+1):
        for i in range(n-cl+1):
            j = i+cl-1
            #if str[i] == str[j] and cl == 2:
            #    L[i][j] = 2
            if str_[i] == str_[j]:
                L[i][j] = L[i+1][j-1] + 2
            else:
                L[i][j] = max(L[i][j-1], L[i+1][j]);
    
    for l in L:
        print(l)
    
    printLSP(L, str_, n, 0, len(str_)-1)

    return L[0][n-1]
 
# Driver program to test above functions
seq = "peqqde"
n = len(seq)
print("The length of the LPS is " + str(lps(seq)))
 
# This code is contributed by Bhavya Jain
