/*ARITH - Simple Arithmetics
no tags  

One part of the new WAP portal is also a calculator computing expressions with very long numbers. 
To make the output look better, the result is formated the same way as is it usually used with manual calculations. 
Your task is to write the core part of this calculator.
 Given two numbers and the requested operation, you are to compute the result and print it in the form specified 
 below. With addition and subtraction, the numbers are written below each other. Multiplication is a little 
 bit more complex: first of all, we make a partial result for every digit of one of the numbers, 
 and then sum the results together. 

Input
There is a single positive integer T on the first line of input (equal to about 1000). 
It stands for the number of expressions to follow. 
Each expression consists of a single line containing a positive integer number, 
an operator (one of +, - and *) and the second positive integer number. Every number has at most 500 digits. 
There are no spaces on the line. If the operation is subtraction, the second number is always
 lower than the first one. No number will begin with zero. 

Output
For each expression, print two lines with two given numbers, the second number below the first one, 
last digits (representing unities) must be aligned in the same column. Put the operator right in front of
 the first digit of the second number. After the second number, there must be a horizontal line made of dashes (-). 
For each addition or subtraction, put the result right below the horizontal line, with last digit aligned 
to the last digit of both operands. 
For each multiplication, multiply the first number by each digit of the second number. 
Put the partial results one below the other, starting with the product of the last digit of the second number. 
Each partial result should be aligned with the corresponding digit. 
That means the last digit of the partial product must be in the same column as the digit of the second number.
No product may begin with any additional zeros. If a particular digit is zero, the product has exactly one 
digit -- zero.
If the second number has more than one digit, print another horizontal line under the partial results, and then print 
the sum of them. 
There must be minimal number of spaces on the beginning of lines, with respect to other constraints. 
The horizontal line is always as long as necessary to reach the left and right end of both numbers 
(and operators) directly below and above it. 
That means it begins in the same column where the leftmost digit or operator of that two lines 
(one below and one above) is. It ends in the column where is the rightmost digit of that two numbers. 
The line can be neither longer nor shorter than specified. 
Print one blank line after each test case, including the last one. 
Example
Sample Input:
4
12345+67890
324-111
325*4405
1234*4

Sample Output:
 12345
+67890
------
 80235

 324
-111
----
 213

    325
  *4405
  -----
   1625
     0
 1300
1300
-------
1431625

1234
  *4
----
4936*/

// PROBLEM:
// AIM : given something find something.
// CONSTRAINTS:
/* TEST CASES:  INPUT   SOLUTION
        1            -->
        2           -->
 */

/* ALGORITHM1:
              1.READ INPUT AS STRING TO REDUCE THE MEMORY
              2.
              3.
              4.
   */
//COMPLEXITY: O(n^2) multiplication       time 0.04 sec -1200 testcases     MEMORY: 16MB
// rank 1's complexity: 0.00 sec memory

//BY MOHANTEJA


#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <queue>
#include<algorithm>

template <class T>
T max(T &a, T &b) { return (!(a < b) ? a : b); }

using namespace std;

void printChar(int frontSpace, int noOfRepitions, char value)
{
	while (frontSpace--)
		printf(" ");
	while (noOfRepitions--)
		printf("%c", value);
	return;
}

void printString(int frontSpace, string num, char symbool, int shouldPrintChar)
{
	while (frontSpace--)
		printf(" ");
	if (shouldPrintChar)
		printf("%c", symbool);
	cout<< num;
	return;
}

int getDigit(char digit)
{
	return digit - '0';
}

int operation(char digit1, char digit2, char operatr)
{

	switch (operatr)
	{
	case '*':
	 // cout << "recieved ="<< digit1 << " " << digit2<< " " <<getDigit(digit1) * getDigit(digit2) << endl;
		return getDigit(digit1) * getDigit(digit2);
	case '-':
		return (digit1<digit2)? (getDigit(digit1) + 10 - getDigit(digit2)) : (getDigit(digit1) - getDigit(digit2));
	case '+':
	 // cout << "recieved ="<< digit1 << " " << digit2<< endl;
		return getDigit(digit1) + getDigit(digit2);
	default:
		return 0;
	}
}

string getZeros(int numberOfZeros){

	string str(numberOfZeros,'0');
	return str;
}

string multiply(string number,int numLen,char digit){
	//multiplies number with single digit
   string result="";
	 int tempResult=0,tempCarry=0;
	 for(int i=numLen-1;i>=0;i--)
	 {
      tempResult = operation(number.at(i),digit,'*');
			tempResult +=tempCarry;
		//	cout<<"tempresult= " << tempResult<<endl;
      tempCarry=tempResult/10;
			tempResult=tempResult%10;
			result.push_back('0'+ tempResult);
	 }
  
	if(tempCarry)
	   result.push_back('0'+ tempCarry);
	
	while(result.back() =='0')
	 result.pop_back();
	if(result.empty()) result.push_back('0');	

	reverse(result.begin(),result.end()); 
//  cout<<"result in multyply = " << result<<endl;
  return result;

}

string addition(string firstVar, string secondVar,int printflag)
{
	int v1len = firstVar.length();
	int v2len = secondVar.length();
	//find result of addition

	string result = "";
	int tempRes = 0, tempCarry = 0;
	int i = 0, j = 0;
	for (i = v1len - 1, j = v2len - 1; i >= 0 && j >= 0; i--, j--)
	{
		tempRes = operation(firstVar.at(i), secondVar.at(j), '+') + tempCarry;
		if (tempRes > 9)
		{
			tempCarry = 1;
			tempRes = tempRes % 10;
		}
		else
		{
			tempCarry = 0;
		}
		result.push_back('0' + tempRes);
	}

	if (i < 0 && j >= 0)
	{
		if (tempCarry)
		{
			while (j >= 0)
			{
				tempRes = getDigit(secondVar.at(j)) + tempCarry;
				if (tempRes > 9)
				{
					tempCarry = 1;
					tempRes = tempRes - 10;
				}
				else
				{
					tempCarry = 0;
				}

				result.push_back('0' + tempRes);
				
				j--;
			}
		}
		else
		{
			while (j >= 0)
			{
				result.push_back(secondVar.at(j));
				j--;
			}
		}
	}
	else if (j < 0 && i >= 0)
	{
		if (tempCarry)
		{
			while (i >= 0)
			{
				tempRes = getDigit(firstVar.at(i)) + tempCarry;
				if (tempRes > 9)
				{
					tempCarry = 1;
					tempRes = tempRes - 10;
				}
				else
				{
					tempCarry = 0;
				}
				result.push_back('0' + tempRes);
				i--;
			}
		}
		else
		{
			while (i >= 0)
			{
				result.push_back(firstVar.at(i));
				i--;
			}
		}
	}

	if (tempCarry)
		result.push_back('1');
	

	while(result.back() =='0')
	 result.pop_back();
	if(result.empty()) result.push_back('0');	

reverse(result.begin(), result.end());
	//printing part
  if(printflag){
	   int ansDigits = result.length();
	   int dashlineLength = max(v2len + 1, ansDigits); 
	   printString(dashlineLength - v1len, firstVar, char(32), 0);
	   printf("\n");
	   printString(dashlineLength-v2len-1, secondVar, '+', 1);
	   printf("\n");
	   printChar(0, dashlineLength, '-');
	   printf("\n");
	   printString(dashlineLength - ansDigits, result, char(32), 0);
		 printf("\n");
		 return result;
	}
	else
	{
		return result;
	}
	
}


void multiplication(string firstVar, string secondVar)
{


    int v1len = firstVar.length();
	  int v2len = secondVar.length();
	 
// this just finds the length of multiplication 
    string decimal1="0.";
		string decimal2="0." ;
		double value1=0,value2=0;
     if(v1len>3)
					value1=stod(decimal1.append(firstVar.substr(0,ceil(v1len/2))));
			else
			    value1=stod(decimal1.append(firstVar));
			 
		 if(v2len>3)
					value2=stod(decimal2.append(secondVar.substr(0,ceil(v2len/2))));
		 else
		     {
					   value2=stod(decimal2.append(secondVar)); 
				 }
	//	 cout << decimal1 << " " << decimal2 << endl;
      
    int anslength;
		if(value1 > 0 && value2 > 0 ){
			anslength= v1len + v2len + ((ceil(log10(value1) + log10(value2))>=0) ? 0:-1);
		}
    else
		 anslength = 1;

//now find the result and do the printing
  int dashlineLength = max(max(v1len, v2len + 1), anslength);
	// print operation and dashline

	printString(dashlineLength - v1len, firstVar, char(32), 0);
	printf("\n");
	printString(dashlineLength - v2len - 1, secondVar, '*', 1);
	printf("\n");
	// printChar(dashlineLength -((v1len!=1)? max(v2len + 1, v1len):dashlineLength),((v1len!=1)? max(v2len + 1, v1len):dashlineLength), '-');
	// printf("\n");



	// print individual operations
  
	string result = "0";
	string tempResult="";
	int tempResultLen = 0,i=0;

	for (i = 0; i < v2len; i++)
	{
		tempResult = multiply(firstVar,v1len,secondVar.at(v2len-1-i));
		tempResultLen =tempResult.length(); 
		if(i==0){
       printChar(dashlineLength-max(tempResultLen,v2len+1),max(tempResultLen,v2len+1), '-');
	   printf("\n");
		}
	  printString(dashlineLength - (tempResultLen + i), tempResult, char(32), 0);
		result=addition(result,tempResult.append(getZeros(i)),0);
		printf("\n");
	}
 
 if(v2len!=1)
 {
	 int resultLen=result.length();
	 printChar(dashlineLength-resultLen,result.length(),'-');
	 printf("\n");
	 printString(dashlineLength-resultLen,result,char(32),0);
	 printf("\n");
 }

}

string substraction(string firstVar, string secondVar,int printflag)
{

  int v1len = firstVar.length();
	int v2len = secondVar.length();
  
	int swapFlag=0;
	 if(v1len<v2len){
		   firstVar.swap(secondVar);
	     swapFlag=v2len;
			 v2len=v1len;
			 v1len=swapFlag;
			 swapFlag=1;
	 }
	//find result of substraction

	string result = "";
	int tempRes = 0, tempBorrow = 0;
	int i = 0, j = 0;
	for (i = v1len - 1, j = v2len - 1; i >= 0 || j >= 0; i--, j--)
	{
		tempRes = operation('0' + operation((i>=0)?firstVar.at(i):'0',(j>=0)? secondVar.at(j):'0', '-'),'0'+tempBorrow,'-');
		if (tempRes > getDigit(firstVar.at(i))-tempBorrow)
		{
			tempBorrow = 1;
		}
		else
		{
			tempBorrow = 0;
		}
		result.push_back('0' + tempRes);
	}


  while(result.back() =='0')
	  result.pop_back();

	if(result.empty()) result.push_back('0');	
	
	reverse(result.begin(), result.end());

  if(printflag){
     if(swapFlag){
			firstVar.swap(secondVar);
	     swapFlag=v2len;
			 v2len=v1len;
			 v1len=swapFlag;
			 swapFlag=1;
		}
	//printing part
	   int ansDigits = result.length();
	   int dashlineLength = max(max(v2len + 1,v1len), ansDigits+swapFlag);
	   printString(dashlineLength - v1len, firstVar, char(32), 0);
	   printf("\n");
	   printString(dashlineLength-v2len-1, secondVar, '-', 1);
	   printf("\n");
	   printChar(dashlineLength-max(v2len+1,ansDigits+swapFlag),max(v2len+1,ansDigits+swapFlag), '-');
	   printf("\n");
	   printString(dashlineLength - ansDigits-swapFlag, result,'-', swapFlag);
		 printf("\n");
     return result;
	}
	else
	{
		return result;
	}
	



}




int main()
{

  //  std::ifstream in; //Creating object for input stream 
	//  ofstream out; //Creating object for output stream
  //  in.open("file.txt");    //open a file to read input
  //  out.open("output.txt"); //open a file to write output



	// your code here
	int testcases;
	string expression = "";
	cin >> testcases;
	while (testcases > 0)
	{
		//cin.ignore();
		//getline(cin, expression);
		cin >> expression;
		//size_t position = expression.find('*');
		size_t position = expression.find_first_of("*-+");
		//cout <<"position = " << position <<" char= " << expression.at(position);
		if (position != string::npos)
		{

			switch (expression.at(position))
			{
			case '*':
				multiplication(expression.substr(0, position), expression.substr(position + 1));
				break;
			case '-':
				substraction(expression.substr(0, position), expression.substr(position + 1),1);
				break;
			case '+':
				addition(expression.substr(0, position), expression.substr(position + 1),1);
				break;
			}

		}
		printf("\n");
		expression.clear();
		testcases--;
		
	}

	// in.close();             //closing the input file
  // out.close();            //closing the output file


	return 0;
}
