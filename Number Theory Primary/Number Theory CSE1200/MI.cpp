// Iterative C++ program to find modular
// inverse using Extended Euclid Algorithm
//Complexity
#include <bits/stdc++.h>
using namespace std;

int modInverse(int A, int M)
{
	int m0,y,x,q,t;
	m0=M;
	y=0;
	x=1;

	if(M==1) return 0;

	while(A>1)
    {
		q=A/M;
		t=M;
		M=A%M,A=t;
		t=y;

		y=x-q*y;
		x=t;
	}

	if(x<0) x+=m0;

	return x;
}

int main()
{
	int A,M,ans;
	cin>>A>>M;
    ans=modInverse(A,M);
    cout<<ans<<"\n";
	return 0;
}

