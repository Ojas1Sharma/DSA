# we have array of strings in python
def getMinWildcard(patterns):

    maxstringlength=max([len(i) for i in patterns])
    k=maxstringlength


    for i in range(maxstringlength):
             
        flag=1
        temp=patterns[0][i]
        for j in patterns:
            if j[i]!=temp and j[i]!="?":
                flag=0
        if flag==1:
            k=k-1
 
    return k






def main():
    patterns=["abcd","a?cd","am?d","????"]
    l=getMinWildcard(patterns)
    print(l)

main()