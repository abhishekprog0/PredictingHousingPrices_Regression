#include<bits/stdc++.h>
#include<limits.h>
#define r(i,n) for(long long int i=0;i<n;i++)
using namespace std;
int main()
{
	//input for training data
	int m;
	cin>>m;
	float a1[m],a2[m];
	float b[m],pred;
	//input feature 1
	r(i,m)
		cin>>a1[i];
	//	cin>>a2[i]
	//target output	
	r(i,m)
		cin>>b[i];
	float k1=-1,k2=2;
	float s1=0,s2=0;
	float p1=1,p2=1;
	float alpha = 0.01; //alpha = learning rate		
	//linear regression using gradient descent
	cout<< "Iterations for parameters: "<<endl;
	//cout<<"m         c"<<endl;		
	while(abs(p2-k2)>=0.000001)
	{
		p1=k1;
		p2=k2;
		r(i,m)
		{
			s1 = s1 + (k1 + k2*a1[i] - b[i]);
			s2 = s2 + (k1 + k2*a1[i] - b[i])*a1[i];		
		}
		s1 = s1/( m );
		s2 = s2/( m );
		k2 = k2 - ( alpha * s2 );
		k1 = k1 - ( alpha * s1 );
		cout<<k1<<" "<<k2<<endl;
	}
	cout<<"m = "<<k1<<", c = "<<k2<<endl;
	cout<<"Enter your prediction input variable: ";
	cin>>pred;
	float final = k2 * pred + k1;
	cout<<"Predicted output: "<<final;			
}

