import math
def add_binary_nums(x, y): 
        max_len = max(len(x), len(y)) 
  
        x = x.zfill(max_len) 
        y = y.zfill(max_len) 
          
        # initialize the result 
        result = '' 
          
        # initialize the carry 
        carry = 0
  
        # Traverse the string 
        for i in range(max_len - 1, -1, -1): 
            r = carry 
            r += 1 if x[i] == '1' else 0
            r += 1 if y[i] == '1' else 0
            result = ('1' if r % 2 == 1 else '0') + result 
            carry = 0 if r < 2 else 1     # Compute the carry. 
          
        if carry !=0 : result = '1' + result 

        return result.zfill(max_len)

def complement(sum_bin):   
    s1=""
    for i in range(len(sum_bin)):
        s=""
        
        for j in range(len(sum_bin[i])):
            if sum_bin[i][j]=="0":
                s=s+"1"
            else:
                s=s+"0"
               
        s1=s1+s
    return add_binary_nums(s1,"1")


def n2b(num):
    return "{0:b}".format(num)

def dTb(num):
    x=num
    num=str(bin(num))
    num=num[2:len(num)]
    if x<16:
            num=(4-len(num))*'0'+num
    else:
            num=(8-len(num))*'0'+num
    return num

def asl(a,q):
    a1=""
    q1=""
    for i in range(1,len(a)):
        a1=a1+a[i]
    a1=a1+q[0]
    for i in range(1,len(q)):
        q1=q1+q[i]
    
    return a1,q1

def bTd(binary): 
      
    binary1 = binary 
    decimal, i, n = 0, 0, 0
    while(binary != 0): 
        dec = binary % 10
        decimal = decimal + dec * pow(2, i) 
        binary = binary//10
        i += 1
    return decimal        
        

print("Enter the divisor:")
b=int(input())
print("Enter the dividend:")
q=int(input())
b=dTb(b)
print("Divisor in binary:",b)
if q>=16:
    b="0000"+b
q=dTb(q)
print("Dividend in binary:",q)
b1="1"+complement(b)
print("2's complement of divisor:",b1)
n=len(q)
a="0"*n+"0"
x=len(a)
print("n", "A"," "*(n-1),"Q"," "*(n-1),"    Action")
print(n,a,q,"  initial")
p=n
while n!=0:
    if a[0]=='1':
        a,q=asl(a,q)
        print(n,a,q,"   leftshift")
        a=add_binary_nums(a,b)
        if len(a)>x:
            a=a[1:len(a)]
        print(n,a,q,"   A+M")
        
    else:
        a,q=asl(a,q)
        print(n,a,q,"   leftshift")
        a=add_binary_nums(a,b1)
        if len(a)>x:
            a=a[1:len(a)]
        print(n,a,q,"   A-M")

    if a[0]=='1':
        q=q+"0"
        print(n,a,q,"  Q0=0")
    else:
        q=q+"1"
        print(n,a,q,"  Q0=1")
    n=n-1

if a[0]=='1':
    a=add_binary_nums(a,b)
    if len(a)>x:
            a=a[1:len(a)]
    print("Final A+M")
    print(a,q)
print("Remainder= ",a," In decimal:",bTd(int(a)))

print("Quotient= ",q," In decimal:",bTd(int(q)))  