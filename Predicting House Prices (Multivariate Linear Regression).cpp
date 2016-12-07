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
	float s0=0, s1=0, s2=0, min , max, mean, range,cf=0.0,v=100.0 ;
	float p[n+1]; //parameter vector
	r(i,0,m)
		r(j,1,n+2)
			cin>>in[i][j];
	//mean normalization under construction
	/*r(i,1,n+1)
	{
		s0=0;
		min = max = in[0][i];
		r(j,0,m)
		{
			s0 +=in[j][i];
			if(in[j][i] < min ) 
				min = in[j][i];
			if(in[j][i]>max)
				max=in[j][i];		
		}
		mean = s0/m;
		range = max - min;
		r(j,0,m)
			in[j][i] = (in[j][i] - mean)/range;
	}*/		
	r(i,0,m)
		in[i][0]=1;		
	r(i,0,n+1)
		p[i]=-1.1;	
	float alpha = 0.01; //alpha = learning rate		
	//linear regression using gradient descent learning algorithm
	while(abs(cf - v)>0.0001)
	{
		v=cf;
		r(k,0,n+1)
		{
			s2=0,cf=0;
			r(i,0,m)
			{
				s1=0;
				r(j,0,n+1)
					s1 += p[j] * in[i][j];		
				s2 += (s1 - in[i][n+1])*in[i][k];
				cf += (s1 - in[i][n+1])*(s1 - in[i][n+1]); //cost function
			}
			cf = cf / (2 * m);
			p[k]=p[k] - ((alpha/m)*s2);
		}
	}
	//input for prediction data
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
