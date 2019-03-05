#include <iostream>
using namespace std;

//O(n) solution //doesnt work if brackets are not strictly followed
//using recursion

void reversePolishNotation(char *arr, int currentPosition, int *returnPosition)
{

	//directOperand flags = 1  indicate whether the operands are directly available
	int directOperand1flag = 0, directOperand2flag = 0, operatorPosition;

	// a+b operand1=a operand2=b operator=+ and they are directly available
	// (a+b) + (d+e) this should be called recusively and directflags are set 0

	//see if operand1 is direct
	if (arr[currentPosition] == '(')
	{
		reversePolishNotation(arr, currentPosition + 1, returnPosition);
		//if operand position is not direct then it should be called recursively and its length parsed should be required
		// it is provided by returnPosition variable
		// (a+b)+b ---> (a+b')'+b returnPosition location after recursive call
		operatorPosition = *returnPosition + 1; // (a+b)'+'b
	}
	else
	{
		//if it is directly available 'a' + b print
		printf("%c", arr[currentPosition]);
		directOperand1flag = 1;
		//if direct operator position is next to operand1 ie currentposition+1
		operatorPosition = currentPosition + 1;
	}
	//see if operand2 is direct
	if (directOperand1flag) //just to know if operand1 is direct or indirect to adjust lengths
	{
		//if operand2 is indirect a+'('d+e)

		if (arr[currentPosition + 2] == '(')
		{
			operatorPosition = currentPosition + 1; //save the operator location bcause returnPosition changes
			reversePolishNotation(arr, currentPosition + 3, returnPosition);
		}
		else
		{
			//print direct operand2
			printf("%c", arr[currentPosition + 2]);
			directOperand2flag = 1;
		}
	}

	else
	{

		if (arr[*returnPosition + 2] == '(')
			reversePolishNotation(arr, *returnPosition + 3, returnPosition);
		else
		{
			printf("%c", arr[*returnPosition + 2]);
			directOperand2flag = 1;
		}
	}

	//print operator next
	printf("%c", arr[operatorPosition]);

	// adjust length parsed till now into returnPosition

	if (directOperand1flag && directOperand2flag)
	{
		//if both are direct ie 'a'+b')'  rp = cp+3;
		*returnPosition = currentPosition + 3;
	}
	else if ((!directOperand1flag) && directOperand2flag)
	{
		//if operator one is recursed and operator 2 is direct ..ie (a+b')' + d')'   +3
		*returnPosition += 3;
	}
	else
	{
		//if both are indirect or operand1 is direct and operand2 is indirect a+(b*m')')  +1 -->> a+(b*m)')'
		*returnPosition += 1;
	}
	return;
}

int main()
{

	// your code here
	int testcases;
	cin >> testcases;
	char *expression = (char *)malloc(sizeof(char) * 402);
	int returnPointer = 0;

	while (testcases > 0)
	{
		//reversepolishnotation
		cin >> expression;
		reversePolishNotation(expression, 1, &returnPointer);
		// printf("%d",returnPointer);
		testcases--;
		cout << "\n";
	}

	return 0;
}