// PROBLEM: PALIN
// AIM : given a number find the NEXT nearest palindrome number .

/* CONSTRAINTS: number contains less than 1000000 digits,
                Numbers are always displayed without leading zeros.
 */               

/* TEST CASES:  INPUT     SOLUTION
                 808  -->818
                2133  -->2222
                9999  ---> 10001
                9      -->   11
                22922  --> 23032
                229922 -->230032
                99999  --->100001
                99901  ---->99999
                98999  --->99099
                1991----> 2002
                00001---> 2
                00000--->1
                00099--->101
 */ 
 
/* ALGORITHM1:
          1.initialize front iterator and rear iterator they move in opposite directions
          2.do:
                if     digit at front iterator equals digit at rear iterator 
                          then move iterators to next digit symmetrically
                elseif digit at front iterator is greater than digit at rear iterator
                          then make digit at rear index equal to digit at front index
                elseif digit at front iterator is less than digit at rear iterator
                          then a.make digit at rear index equal to digit at front index
                               b.forward add a carry to next digit infront of digit at rear index iteratively if carry again generated
            while front iterator is less than equals rear iterator

          3.if number is already a palindrome 
               if length of digit places of number is even
                    if digits at two middle places is 9
                        then a.recursive increament the first half of string till carry is forwarded
                             b.make second half symmetric to first half
                             c.return a flag indicating if carry taken place occupied extrabit
                     else 
                             a.increament middle two digits
                             b.return
               else if length is odd 
                    if  digit at middle is 9
                        then a.recursive increament the first half of string from middle digit till carry is forwarded
                             b.make second half symmetric to first half
                             c.return a flag inicating if carry taken place occupied extrabit
                    else 
                             a.increament middle digit 
                             b.return         
            else if not a palindrome number then 
                    return       
                       
   */
 //COMPLEXITY: O(n) 0.03               MEMORY: 17M 

//BY MOHANTEJA 

#include <iostream>
#include<cstring>

using namespace std;

//recursive increamenter , also returns length it increamented recursively example: 199'9' ---> '2'000 ,increamented length =3
  int increamentDigitChar(char *Digit)
  {
    if(Digit[0]=='9'){ 
      Digit[0]='0' ; 

      return 1 + increamentDigitChar(&Digit[-1]);
      }
    else {
      Digit[0]+=1;
    
      return 0;
    }

  }
 
 //makes second half of string equals first half 
 int makePalindrome(char *inputNum,int length){
       int frontIndex=0,rearIndex=length-1;
  

       while(frontIndex<=rearIndex)
       {
         inputNum[rearIndex]=inputNum[frontIndex];
         frontIndex++;
         rearIndex--;
       }

   return 0;

 }
  



  int nextPalindrome(char *inputNum,int length,int extraBitFlag){
/* manipulates string to next palindrome 
   returns 1 if no carry takes place else 0 */

      int frontIndex=0,rearIndex=length-1;
      int alreadyPalindromeFlag=1,even01OddLen=length%2;
  
    //checks whether the number is a palindrome already 
      while(frontIndex<=rearIndex){

                if(inputNum[frontIndex]==inputNum[rearIndex])
                    {
                      rearIndex--;
                      frontIndex++;
                      continue;
                    }
                else if(inputNum[frontIndex]>inputNum[rearIndex])
                    {
                       inputNum[rearIndex]=inputNum[frontIndex];
                       alreadyPalindromeFlag=0;
                    }
                else if(inputNum[frontIndex]<inputNum[rearIndex])
                {
                      alreadyPalindromeFlag=0;
                      increamentDigitChar(&inputNum[rearIndex-1]);
                      inputNum[rearIndex]=inputNum[frontIndex];
                }

                rearIndex--;
                frontIndex++;
                
      }
          

     if(alreadyPalindromeFlag){
          //odd
            if(even01OddLen)
               {
                  if(inputNum[length/2  ] !='9')
                      {
                        inputNum[length/2 ] +=1;
                        return extraBitFlag ;     //extrabitspace available =1 not available =0
                      }
                   else
                   {
                      if(increamentDigitChar(&inputNum[length/2])==(length/2 + 1 ))
                           return makePalindrome(&inputNum[-1],length+1);// extra bit space not available
                      else
                           return makePalindrome(inputNum,length)+1; //extra bit space available
                     
                   }
                      
               }
               else
               {
                 /* even length */
             
                 if(inputNum[length/2] !='9')
                      {
                        inputNum[length/2] += 1;
                        inputNum[length/2 -1 ] +=1;
                        return 1;
                      }
                   else
                   {
                      if(increamentDigitChar(&inputNum[length/2])==(length/2 + 1))
                           return makePalindrome(&inputNum[-1],length+1);
                      else
                           return makePalindrome(inputNum,length)+1;
                     
                   } 


               }
               

        }
        else  //not palindrome
        {
              return extraBitFlag;
        }
        
  

  

  }

  int main() {
	
	// your code here
	int testcases;
	char *inputNum =(char*)malloc(sizeof(char)*1000002);
    //memset(inputNum,'v',1000000);
	cin >> testcases;
	int i,length;
    
	while(testcases>0)
	{
	

	  i=1;
	  inputNum[0]='0';
     cin >> &inputNum[1]; 
     length=strlen(inputNum);

//remove trailling zeros 0001 ---->1 ,00000 ---->0
     for(;inputNum[i]=='0';i++);
     if(i==length) i--;

//call next Palindrome
     if(!nextPalindrome(&inputNum[i],length-i,1)) 
          cout << &inputNum[i-1]; //extra bit
     else 
          cout << &inputNum[i]; //no extra bit

	 testcases--;
	 cout<<"\n" ;
	}

   
	return 0;
  
}