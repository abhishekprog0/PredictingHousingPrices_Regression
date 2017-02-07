#include<iostream>
using namespace std;
float abs(float x, float y)
{
	if( x > y)
		return (x - y);
	return (y - x);
}
int main()
{
	 /* The following code implements Linear Regression with one Feature Variable */
	//Iput for total number of training data
	int m;
	cin >> m;
	// Used array to store the number of training data for feature_1.
	float feature_1[m];
	float target_output[m], predicted_output, pred;
	//input feature 1
	for(int i = 0; i < m; i++) 
		cin  >> feature_1[i];
	//target output	
	for(int i = 0; i < m; i++) 
		cin >> target_output[i];
	//y = k1 * feature_1 + k2;
	//k1 and k2 represents the parameters of line y
	float k1 = -1, k2 = 2; //Initial Guess
	float s1 = 0, s2 = 0;
	float p1 = 1, p2 = 1;
	float alpha = 0.01; //alpha = learning rate		
	//linear regression using gradient descent
	cout<< "Iterations for parameters: "<<endl;
	//cout<<"m         c"<<endl;		
	while(abs(p2 - k2) >= 0.000001)
	{
		p1 = k1;
		p2 = k2;
		for(int i = 0; i < m; i++) 
		{
			s1 = s1 + (k1 + k2 * a1[i] - b[i]);
			s2 = s2 + (k1 + k2 * a1[i] - b[i]) * a1[i];		
		}
		s1 = s1 / m;
		s2 = s2 / m;
		k2 = k2 - ( alpha * s2 );
		k1 = k1 - ( alpha * s1 );
		cout << k1 << " " << k2 << endl;
	}
	cout << "m = " << k1 << ", c = " << k2 << endl;
	cout << "Enter your prediction input variable: ";
	cin >> pred;
	float final = k2 * pred + k1;
	cout << "Predicted output: " << final;			
}

