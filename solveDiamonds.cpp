#include<iostream>
using namespace std;

unsigned long int calc(unsigned long int num)
{

	unsigned long int sum_even=0,sum_odd=0,temp;
	while(num)
	{
		temp=num%10;
		if(temp%2==0) sum_even=sum_even+temp;
		else sum_odd=sum_odd+temp;
		num=num/10;
	}

	if(sum_even>sum_odd) return sum_even-sum_odd;

	return sum_odd-sum_even;
}

int main()
{
	unsigned long int t,sum,first,i,n;
	cin>>t;


		sum=0;
		i=1;
		first=2;

		if(n>1000)
		{
			sum=4168595;
			i=1001;
			first=1002;
		}

		while(i<n+1)
		{
			sum=sum+i*calc(first);
			i=i+1;
			first=first+1;
		}

		i=i-2;

		while(i>0)
		{
			sum=sum+i*calc(first);
			i=i-1;
			first=first+1;
		}

		cout<<sum<<endl;
	}
}
