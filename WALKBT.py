t=int(input())
for i in range(0,t):
	x1=0
	x=set()
	N=input().split()
	n=int(N[0])
	y=int(2**n)
	q=int(N[1])
	for j in range(0,q):
		s=input().split()
		a=[]
		c=0
		if s[0]=='!':
			x1=int((x1+int(2**(int(s[1]))))%y)
			a=bin(x1)[2:]
			r=1;
			a=a[::-1]
			for i in range(len(a),n):
				a=a+'0'
			a=a[::-1]
			for k in range(0,n):
				if a[k]=='0':
					r=2*r
				else:
					r=2*r+1
				if r not in x:
					x.add(r)	
		else:
			print(len(x)+1)