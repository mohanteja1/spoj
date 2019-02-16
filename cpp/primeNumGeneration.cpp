#include <iostream>
using namespace std;
#include<math.h>

int isPrimeOptimized(int number){	
	int k = sqrt(number*1.0);
	if (number % 2 == 0)
		return 0;

		for (int i = 3; i <=k;i+=2)
		{
			if (!(number%i))
				return 0;
		}
return 1;
}


int main() {
	
	// your code here
	int testcases;
	int startNum,endNum;
	
	cin >> testcases;
	
	while(testcases>0)
	{
	//prime num generation
	
	cin >> startNum;
	cin >> endNum;
	if(startNum>5){
	if(startNum%2==0)
	    startNum++;
	}
	else{
		cout << 2 << "\n" << 3 <<"\n" ;
		startNum=5;
	}
	
	for(int i=startNum;i<=endNum;i=i+2)
	{
		if(isPrimeOptimized(i)) cout << i << endl;
	}
	 testcases--;
	 cout<<"\n" ;
	}

   
	return 0;
}