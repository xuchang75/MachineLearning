// Example program
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int x[10] = {1,3,2,4,5,3,6,8,6,9};
	int y[10] = {3,4,5,6,3,6,1,8,6,7};
	int z[10] = {1,1,1,1,0,1,0,0,0,0};

	//h = m + nx + py
	double m = 1;
	double n = 1;
	double p = 1;
	
	//learning rate
	double rate = 0.2;
	

	int c = 1;

    double lastcost = 0;
	while (true)
	{
		double err = 0;
		double err2 = 0;
		double err3 = 0;
		
		double cost = 0;
		
		for (int i = 0; i < 10; i++)
		{   
		    double h = m + n*x[i] + p*y[i];
		    double f = 1/(1+pow(exp(1) , -h));
			err += f - z[i];
			err2 += (f - z[i])*x[i];
			err3 += (f - z[i])*y[i];
			
			if(z[i] == 1)
			    cost += -log(f);
			else
			    cost += -log(1-f);
		}


		cout << c << " " << cost << endl;

		m = m - rate*err/10;
		n = n - rate*err2/10;
		p = p - rate*err3/10;
		
        
		if ((cost - lastcost < 0.0001 && cost - lastcost > -0.0001) || c > 2000)
			break;

		lastcost = cost;
		c++;
	}

	cout << m << "  " << n <<" "<<p << endl;
	
	return 0;
}


