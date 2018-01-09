// Example program
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int x[10] = {1,3,2,4,5,3,6,8,6,9};
	int y[10] = {3,4,5,6,3,6,1,8,6,7};

	//y = mx + n
	double m = 0;
	double n = 0;

	double err = 0;
	double err2 = 0;
	
	double rate = 0.05;

	int c = 1;
	
	for (int i = 0; i < 10; i++)
	{
	    cout<<y[i] <<endl;
	}   

	while (true)
	{
		err = 0;
		for (int i = 0; i < 10; i++)
		{   
			err += (m*x[i] + n - y[i]);
			err2 += (m*x[i] + n - y[i])*x[i];
		}

		err2 /= 10;
		err /= 10;

		cout << c << " " << err << endl;

		m = m - rate*err2;
		n = n - rate*err;

		if (err*err < 0.001 || c > 500)
			break;

		c++;
	}

	cout << m << "  " << n << endl;
	
	return 0;
}
