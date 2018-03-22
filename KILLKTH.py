s=input()
sub=[]
l=len(s)
for i in range(l):
	for j in range(i,l):
		sub.append((s[i:j+1]))
sub.sort()
b="".join(sub)
q=int(input())
g=0
for i in range(q):
	p,m=map(int,input().split())
	k=(p*g)%m+1
	print (b[k-1])
	g=g+ord(b[k-1]) 