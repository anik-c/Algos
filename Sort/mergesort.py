def merge(arr,l,mid,r):
    s1=(mid-l)+1
    s2=r-mid
    a1=[0]*s1
    a2=[0]*s2
    for i in range(0,s1):
        a1[i]=arr[l+i]
    for i in range(0,s2):
        a2[i]=arr[mid+1+i]
    i=0
    j=0
    k=l
    while i<s1 and j<s2:
        if a1[i]<a2[j]:
            arr[k]=a1[i]
            k+=1
            i+=1
        else:
            arr[k]=a2[j]
            k+=1
            j+=1
    
    while i<s1:
        arr[k]=a1[i]
        k+=1
        i+=1
    while j<s2:
        arr[k]=a2[j]
        k+=1
        j+=1
            

def mergeSort(arr,l,r):
    if l>=r:
        return
    mid=l+(r-l)//2
    mergeSort(arr,l,mid)
    mergeSort(arr,mid+1,r)
    merge(arr,l,mid,r)

arr=[7,2,1,5,3,6,7]
mergeSort(arr,0,len(arr)-1)

print(arr)