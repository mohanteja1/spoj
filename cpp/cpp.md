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