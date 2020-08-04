import os
import random
os.system('make clean')
os.system('make for sol')


def gen_input():
    n=1000
    with open('in','w') as f:
        f.writelines( "%d"%n )
        for i in range(2,n+1):
            f.writelines( "%d %d"%(i,random.randint(1,i-1)) )
    

def read_out(name):
    f=open(name,'r')
    c=f.read().split('\n')
    f.close()
    return c

def diff(a,b):
    def proc(xs):
        xs=map(lambda x:x.strip(),xs)
        xs=filter(lambda x:x!="",xs)
        return list(xs)
    a,b=proc(a),proc(b)
    return  a!=b

for _ in range(10):
    gen_input()
    os.system("cat in | ./sol.exe > sol.out ")
    os.system("cat in | ./for.exe > for.out ")
    sol_out=read_out('sol.out')
    for_out=read_out('for.out')
    if diff(sol_out,for_out): 
        print("\a------------ERROR----------")
        break
