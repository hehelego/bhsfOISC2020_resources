from subprocess import *
from os import system as runcmd
import random


def getout(idx): runcmd(f'cat {idx}.in | ./a.out > {idx}.ans')

def genonce(idx,args):
    (a,q)=args

    fin=open(f'{idx}.in','w')
    fin.write(f'{len(a)} {len(q)}\n')

    for x in a: fin.write(f'{x} ')
    fin.write('\n')
    for x in q: fin.write(f'{x[0]} {x[1]}\n')

    fin.close()
    getout(idx)
    print("end %d"%(idx))


# count(0) = np
# count(1) = nq
# count(2) = n(1-p-q)
def gen_list(n,p=0.3,q=0.3):
    def get():
        x=random.random()
        if x<p: return 0
        elif x<q: return 1
        else: return 2
    return [get() for _ in range(n)]
def gen_qry(n,m):
    def gen_range():
        l=random.randint(1,n)
        r=random.randint(1,n)
        return (min(l,r),max(l,r))
    return [gen_range() for _ in range(m)]

def gen(i,n,m): genonce(i,(gen_list(n),gen_qry(n,m)))


if __name__=="__main__":
    from os import system as run
    run('g++ std.cpp -O2 -o a.out')

    gen(0,1000,1000)
    gen(1,1500,1500)
    gen(2,2000,2000)

    gen(3,10000,2000)
    gen(4,100000,2000)
    gen(5,2000,10000)

    gen(6,100000,100000)
    gen(7,200000,100000)
    gen(8,100000,200000)
    gen(9,200000,200000)

    run('rm a.out')
