#include<bits/stdc++.h>
#include<limits.h>
#define r(i,beg,end) for(long long int i=beg;i<end;i++)
using namespace std;
int main()
{
	//input for training data
	int m, h, n,l=0;
	cin>>n>>m;
	float in[m][n+2];
	float p[n+1]; //parameter vector
	r(i,0,m)
		r(j,1,n+2)
			cin>>in[i][j];
	r(i,0,m)
		in[i][0]=1;		
	r(i,0,n+1)
		p[i]=-1.1;	
	float s1=0,s2=0;
	float alpha = 0.01; //alpha = learning rate		
	//linear regression using gradient descent
	cout<< "Iterations for parameters: "<<endl;
	//cout<<"m         c"<<endl;		
	while(l<100)
	{
		r(k,0,n+1)
		{
			s2=0;
			r(i,0,m)
			{
				s1=0;
				r(j,0,n+1)
					s1 += p[j] * in[i][j];		
				s2 += (s1 - in[i][n+1])*in[i][k];
			}
			p[k]=p[k] - ((alpha/m)*s2);
		}
		l++;
	}
	cin>>h;
	float pred[h][n+1];
	r(i,0,h)
		r(j,1,n+1)
			cin>>pred[i][j];
	r(i,0,h)
		pred[i][0]=1;
	r(i,0,h){
		s1=0;
		r(j,0,n+1)
			s1 = s1 + p[j]*pred[i][j]; 
		cout<<s1<<endl;
	}
}

