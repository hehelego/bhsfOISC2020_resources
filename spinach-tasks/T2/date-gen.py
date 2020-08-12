from subprocess import *
from random import randint as rand


def getout(idx):
    fin = open(f'{idx}.in','r')
    fout = open(f'{idx}.ans','w')
    data = fin.readlines()
    
    p = Popen("./a.out",stdin=PIPE,stdout=PIPE)
    for x in data:
        p.stdin.write((str(x)+'\n').encode('utf-8'))

    p.stdin.flush()
    output=p.stdout.readline().decode('utf-8')
    fout.write(output)

    fin.close();fout.close()


def genonce(idx,args):
    (n,es,ws)=args

    fin=open(f'{idx}.in','w')
    fin.write(f'{n} {len(es)}\n')
    for (u,v) in es:
        fin.write(f'{u} {v}\n')
    for i in range(1,n+1):
        for j in range(1,n+1):
            f=lambda d,k:d.get(k) if d.get(k) else 0
            fin.write(f'{f(ws,(i,j))} ')
        fin.write('\n')
    fin.close()
    getout(idx)
    print("end %d"%(idx))


def rand_weight(): return rand(0,int(1e5))

def get_w(n):
    w=dict()
    for i in range(1,n+1):
        for j in range(1,n+1):
            w[(i,j)]=rand_weight()
    return w

def get_tree(n):
    es=[]
    for i in range(2,n+1):
        es.append((i,rand(1,i-1)))
    return es

def gen_graph(n):
    m=rand(n//2,n*(n-1)//4)
    es=[]
    for _ in range(m):
        x=rand(2,n)
        y=rand(1,x-1)
        es.append((x,y))
    return es


if __name__=="__main__":
    from os import system as run
    run('g++ std.cpp -o a.out')

    genonce(0,(3,[(1,2),(2,3),(1,3)],dict()))
    genonce(1,(18,[(1,2),(1,18)],dict()))

    genonce(2,(1,[],{(1,1):13}))
    genonce(3,(18,[],get_w(18)))

    genonce(4,(14,get_tree(14),get_w(14)))
    genonce(5,(16,get_tree(16),get_w(16)))
    genonce(6,(18,get_tree(18),get_w(18)))
    
    genonce(7,(8,gen_graph(8),get_w(8)))
    genonce(8,(15,gen_graph(15),get_w(15)))
    genonce(9,(18,gen_graph(18),get_w(18)))

    run('rm a.out')
