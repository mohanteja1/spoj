# cpp quicks
## inputs
1. iostream
     * cout <<
     * cin >>
     * cerr <<
     * clog <<
     * while (t--) 
       { 
        getline(cin, str); 
  
        // Keep reading a new line while there is 
        // a blank line 
        while (str.length()==0 ) 
            getline(cin, str); 
  
        cout << str << " : newline" << endl; 
       } 

2. stdio.h
    * scanf("%d", &x); 
    *  char str[100];  
        fgets(str, 100, stdin);   

## [preprocessors](https://www.geeksforgeeks.org/cc-preprocessors/)    
1. Macros
     * #define LIMIT 5                       // macro definition 
     * #define AREA(l, b) (l * b)            // macro with parameter 
     *
2. File Inclusion
     * #include< file_name > //Header File or Standard files
     * #include "file_name" //user defined files

3. Conditional Compilation
     * #ifdef macro_name    //executed
          statement1;
          .
          statementN;
       #endif

4. Other directives
    
    * #undef LIMIT         //undefines an existing macro  

    * #pragma 

                   vc++                                     |         gcc version
      #pragma startup func1 /*called before startup */      |         void __attribute__((constructor)) func1(); 
      
      #pragma exit func2    /*called after main returned */ |        void __attribute__((destructor)) func2(); 
    
    * #pragma warn -rvl: hides those warning which are raised when a function which is supposed to  
      return a value does not returns a value.
      #pragma warn -par:  hides those warning which are raised when a function does not uses the parameters passed to it.
      #pragma warn -rch:  hides those warning which are raised when a code is unreachable. For example: any code written after the return statement in a function is unreachable.


5. [Arrays](http://www.geeksforgeeks.org/arrays-in-c-language-set-1-introduction/)
    
    * [opaque pointer](https://www.geeksforgeeks.org/opaque-pointer/)
    
    * arr[i]     ==  *(arr + i)           //similar
    * arr[i][j]  ==  *(*(arr + i) + j)
    *

6. [strings](https://www.geeksforgeeks.org/c-string-class-and-its-applications/S)
   
    *   
         ```cpp      

            //take input
            string str="";
            getline(cin,str);

            char string1[100];
            cin.get(string1,100,'\n');


            //initialization by raw string
            string str1("first string");
            
            //initialization by another string
            string str2(str1);
            
            // initialization by character with number of occurence
            string str3(5, '#');
            
            // initialization by part of another string
            string str4(str1, 6, 6); //    from 6th index (second parameter)
            
            // 6 characters (third parameter)
            // initialization by part of another string : iteartor version
            string str5(str2.begin(), str2.begin() + 5);
         ```
         ```c
            cout << str1 << endl;
            cout << str2 << endl;
            cout << str3 << endl;
            cout << str4 << endl;
            cout << str5 << endl;

            //  assignment operator
            string str6 = str4;

            // clear function deletes all character from string
            str4.clear();

            //  both size() and length() return length of string and
            //  they work as synonyms
            int len = str6.length(); // Same as "len = str6.size();"

            cout << "Length of string is : " << len << endl;

            // a particular character can be accessed using at /
            // [] operator
            char ch = str6.at(2); //  Same as "ch = str6[2];"
         ```
         ```c   
            cout << "third character of string is : " << ch << endl;

            //  front return first character and back returns last charcter
            //  of string

            char ch_f = str6.front(); // Same as "ch_f = str6[0];"
            char ch_b = str6.back();  // Same as below
                                    // "ch_b = str6[str6.length() - 1];"

            cout << "First char is : " << ch_f << ", Last char is : "
                << ch_b << endl;

            // c_str returns null terminated char array version of string
            const char *charstr = str6.c_str();
            printf("%s\n", charstr);
         ```
         ```c 
             // append add the argument string at the end
             str6.append(" extension");
             //  same as str6 += " extension"
        
            // another version of append, which appends part of other
            // string
            str4.append(str6, 0, 6); // at 0th position 6 character

            cout << str6 << endl;
            cout << str4 << endl;

            //  find returns index where pattern is found.
            //  If pattern is not there it returns predefined
            //  constant npos whose value is -1

            if (str6.find(str4) != string::npos)
                cout << "str4 found in str6 at " << str6.find(str4)
                    << " pos" << endl;
            else
                cout << "str4 not found in str6" << endl;

            //  substr(a, b) function returns a substring of b length
            //  starting from index a
            cout << str6.substr(7, 3) << endl;

            //  if second argument is not passed, string till end is
            // taken as substring
            cout << str6.substr(7) << endl;

            //  erase(a, b) deletes b characters at index a
            str6.erase(7, 4);
            cout << str6 << endl;

            //  iterator version of erase
            str6.erase(str6.begin() + 5, str6.end() - 3);
            cout << str6 << endl;

            str6 = "This is a examples";

            //  replace(a, b, str)  replaces b characters from a index by str
            str6.replace(2, 7, "ese are test");

            cout << str6 << endl;

            string returnFloatingPart(string str)
            {
                int pos = str.find(".");
                if (pos == string::npos)
                    return "";
                else
                    return str.substr(pos + 1);
            }

            // this function checks whether string contains all digit or not
            bool containsOnlyDigit(string str)
            {
                int l = str.length();
                for (int i = 0; i < l; i++)
                {
                    if (str.at(i) < '0' || str.at(i) > '9')
                        return false;
                }
                //  if we reach here all character are digits
                return true;
            }

            // this function replaces all single space by %20
            // Used in URLS
            string replaceBlankWith20(string str)
            {
                string replaceby = "%20";
                int n = 0;

                // loop till all space are replaced
                while ((n = str.find(" ", n)) != string::npos)
                {
                    str.replace(n, 1, replaceby);
                    n += replaceby.length();
                }
                return str;
            }

            // driver function to check above methods
            int main()
            {
                string fnum = "23.342";
                cout << "Floating part is : " << returnFloatingPart(fnum)
                    << endl;

                string num = "3452";
                if (containsOnlyDigit(num))
                    cout << "string contains only digit" << endl;

                string urlex = "google com in";
                cout << replaceBlankWith20(urlex) << endl;

                return 0;
            }
        ```  
    * reading strings with spaces
       ```c
       printf("Enter whole sentece (yeah, bring spaces too, I can handle it):\n");
       scanf ("%[^\n]%*c", string);
       printf ("You entered: %s", string);
       ```

7. VECTORS:
    
    * functions:
       1. myvector.erase (myvector.begin()+2,myvector.begin()+3);
       2.
       3. 

	   

## [ASCI](https://ascii.cl/)    
## [GNU GMP LIBRARY](https://gmplib.org/)

https://users.cs.cf.ac.uk/Dave.Marshall/C/node18.html

# visualcode 
   * beautify or format code : shft + alt + F

# competative shorts
  * cnt = p = 0;  //double declaration
  * 