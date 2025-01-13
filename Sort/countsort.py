#countsort.py
def countSort(arr):
    mini=min(arr)
    for i in range(0,len(arr)):
        arr[i]=arr[i]-mini
    maxi=max(arr)
    freq=[0]*(maxi+1)
    for i in range(0,len(arr)):
        freq[arr[i]]+=1
    
    for i in range(1,len(freq)):
        freq[i]=freq[i]+freq[i-1]
        
    ans=[0]*(len(arr))
    
    for i in range(len(arr) - 1, -1, -1):
        freq[arr[i]] -= 1
        ans[freq[arr[i]]] = arr[i] + mini
    
    return ans
arr=[-10,0,1,10,-4,7]

ans=countSort(arr)

for ele in ans:
    print(ele)