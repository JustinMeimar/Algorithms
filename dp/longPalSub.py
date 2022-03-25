def LPS(s, n):
    
    D = [[0 for x in range(n)] for x in range(n)]

    for i in range(n):
        D[i][i] = 1

    for k in range(2, n+1):
        for i in range(n-k+1):
            j = i + k -1
            if s[i] == s[j] and k == 2:
                D[i][j] = 2
            elif s[i] == s[j]:
                D[i][j] = D[i+1][j-1] + 2
            else:
                D[i][j] = max(D[i][j-1], D[i+1][j])
    
    for i in D:
        print(i)

def main():
    
    string = "peqqde" 
    LPS(string, len(string))

    return 0

if __name__ == "__main__":

    main()
