# PYTHON COMPETITIVE PROGRAMMING

1. Counter Package:

 '''python
   
        #Code to find top 3 elements and their counts 
        #using most_common 
        from collections import Counter 

        arr = [1, 3, 4, 1, 2, 1, 1, 3, 4, 3, 5, 1, 2, 5, 3, 4, 5] 
        counter = Counter(arr) 
        top_three = counter.most_common(3) 
        print(top_three) 

'''
  output:  [(1, 5), (3, 4), (4, 3)]

2. The n-largest/n-smallest function of the heapq Package

'''python
       
        # Python code to find 3 largest and 4 smallest 
        # elements of a list. 
        import heapq 

        grades = [110, 25, 38, 49, 20, 95, 33, 87, 80, 90] 
        print(heapq.nlargest(3, grades)) 
        print(heapq.nsmallest(4, grades)) 


'''
output: [110, 95, 90]
        [20, 25, 33, 38] 

3. Dictionary and concept of zipping Dictionaries

'''python
        # Python code to demonstrate use of zip. 
        import heapq 
        
        stocks = { 
            'Goog' : 520.54, 
            'FB' : 76.45, 
            'yhoo' : 39.28, 
            'AMZN' : 306.21, 
            'APPL' : 99.76
            } 
        
        zipped_1 = zip(stocks.values(), stocks.keys()) 
        
        # sorting according to values 
        print(sorted(zipped_1)) 
        
        zipped_2 = zip(stocks.keys(), stocks.values()) 
        print(sorted(zipped_2)) 
        #sorting according to keys 


'''
output: 
        [(39.28, 'yhoo'), (76.45, 'FB'), (99.76, 'APPL'), (306.21, 'AMZN'), (520.54, 'Goog')]
    [('AMZN', 306.21), ('APPL', 99.76), ('FB', 76.45), ('Goog', 520.54), ('yhoo', 39.28)]

   4. The Map function:

'''python
   
        # Python code to apply a function on a list 
        income = [10, 30, 75] 
        
        def double_money(dollars): 
            return dollars * 2
        
        new_income = list(map(double_money, income)) 
        print(new_income) 

'''
output: [20, 60, 150

'''python
   


'''
output: 


'''python
   


'''
output: 
