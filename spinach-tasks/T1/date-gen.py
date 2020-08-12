from subprocess import *


def getout(idx):
    fin = open(f'{idx}.in','r')
    fout = open(f'{idx}.ans','w')
    data = fin.readlines()[0]
    
    p = Popen("./a.out",stdin=PIPE,stdout=PIPE)
    p.stdin.write((str(data)+'\n').encode('utf-8'))
    p.stdin.flush()
    output=p.stdout.readline().decode('utf-8')
    fout.write(output)

    fin.close();fout.close()


def genonce(idx,args):
    (n,k,p)=args

    fin=open(f'{idx}.in','w')
    fin.write(f'{n} {k} {p}')
    fin.close()
    getout(idx)
    print("end %d"%(idx))

if __name__=="__main__":
    from os import system as run
    run('g++ std.cpp -O2 -o a.out')

    genonce(0,(3,2,2))
    genonce(1,(1,10,998244353))
    genonce(2,(10000,100,998244353))
    genonce(3,(10000,200,998244353))
    genonce(4,(100000,200,998244353))
    genonce(5,(int(1e10),500,998244353))
    genonce(6,(int(1e10),1000,998244353))
    genonce(7,((2**36)-1,2000,998244353))
    genonce(8,((2**36)-1,2000,37))
    genonce(9,((2**36)-1,2000,2*3*5*7*11*13*17+1))

    genonce(10,(3,2,1))
    genonce(11,(1,10,10))
    genonce(12,(10000,100,999))
    genonce(13,(10000,200,int(1e10)))
    genonce(14,(100000,200,int(1e10)))
    genonce(15,(int(1e10),500,3*5717))
    genonce(16,(int(1e10),1000,2*3*5*7*11*13*17))
    genonce(17,((2**36)-1,2000,998244353-1))
    genonce(18,((2**36)-1,2000,36))
    genonce(19,((2**36)-1,2000,2*3*5*7*11*13*17-1))

    run('rm a.out')
