#lsp contiguous characters, easier than subsequence

def lsp(string, n):
    
    print(string)
    if n == 1: 
        return 0

    if n == 2:
        if string[0] == string[1]:
            return 2

    a1 = lsp(string[0:n-1], n-1)
    a2 = lsp(string[1:n],n-1)
    a3 = -1
    if string[0] == string[n-1]:
        a3 = lsp(string[1:n-1], n-2)

    return max(a1, a2, a3)

def main():

    string = "abagg"

    x = lsp(string, len(string)) 
    
    print(x)

if __name__ == "__main__":

    main()
