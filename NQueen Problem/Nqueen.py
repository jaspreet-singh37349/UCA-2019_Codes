# -*- coding: utf-8 -*-
"""
Created on Sat Jul 20 09:42:43 2019

@author: Jaspreet
"""

def valid_move(chess,col,row):
    c = 1
    for i in range(col-1,-1,-1):
        if chess[i] == row:
            # Rooks move
            return False
        
        # Above knights move
        if chess[i] == row - c:
            return False
        
        #Below Knights move
        if chess[i] == row + c:
            return False
        c += 1
    return True
            


"""
Logic!! :
1.  We check column-wise.
2.  To check we can place queen in particular row of the column we use 
    valid move fnc
3.  if there is no place to fit queen in that column then set that column
    valid move func will not rum and that column in chess will be none and
    false will return.
4.  As recurrsion is used so solve of previous column will return false and
    due to which next row of that column will be selected to check.
5.  if there is no space in all the next rows then steps 3 and 4 are repeated.
"""
            
def solve(chess, col, size):
    if col == size:
        return True
    for i in range(size):
        if valid_move(chess, col, i):
            chess[col] = i
            if solve(chess, col+1, size):
                return True
    chess[col] = None
    return False


def solve_nqueen(size):
    chess = [None]*size
    # solve is used to check whole logic
    if solve(chess,0,size):
        print("solved")
        print(chess)
        a = [["." for i in range(size)] for j in range(size)]
        for i in range(size):
            a[chess[i]][i] = "Q"
        for i in range(size):
            print(a[i])
        return True
    else:
        print("No Solution")
        return False




if __name__ == '__main__':
    
    chess = [None]*4
    solve(chess,0,4)
    assert chess == [1,3,0,2]
    size = int(input("please input size of chess : "))
    solve_nqueen(size)
    
