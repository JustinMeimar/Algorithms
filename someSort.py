def call_counter(func):
    def helper(*args, **kwargs):
        helper.calls += 1
        return func(*args, **kwargs)
    helper.calls = 0 
    return helper

@call_counter
def SomeSort(A, b, e):

    if e == b + 1:
        if A[b] > A[e]:
            A[b], A[e] = A[e], A[b]

    elif e > b + 1:
        p = (e - b+1)//3
        SomeSort(A, b, e - p)
        SomeSort(A, b + p, e)
        SomeSort(A, b, e - p)

    return A 

inorder = [1,2,3,4,5,6,7,8,9]
rorder = [10,8,7,6,5,4,3,2,1]
mix_order = [1,10,9,2,4,6,4,3,7]

b1, e1 = 0, len(inorder)-1
b2, e2 = 0, len(rorder)-1
b3, e3 = 0, len(mix_order)-1

print(SomeSort(inorder, b1, e1))
print(SomeSort.calls)
SomeSort.calls = 0

print(SomeSort(rorder, b2, e2))
print(SomeSort.calls)
SomeSort.calls = 0

print(SomeSort(mix_order, b3, e3))
print(SomeSort.calls)


