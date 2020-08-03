# 组合与数论常识

> a lecture on   
> combinatorics and number theory   
>
> 主要讲解知识,会有一些例题.   

## table of content

- 分步,分类计数原理
- 排列,组合
- 递推关系
- 容斥原理
- 生成函数运算
- 整除关系,同余关系
- 二元一次不定方程与模线性方程组(CRT)
- 素数判定与质因子分解
- 数论函数及其求和方法



## 组合常识

~~基本上就是简单高中数学题,我们跳过~~

### 递推关系

- 等差数列与等比数列是基础
- 几个常见模型(形式变换,不动点,特征根,卷积,微分方程) [参考这里](https://zhuanlan.zhihu.com/p/104544760)
  - $a_{n+1}=pa_n+q$
  - $a_{n+2}=Aa_{n+1}+Ba_{n}+C$
  - $S_{n}-S_{n-1}=n2^n$
  - $a_{n+1}+pa_{n}=qa_{n+1}a_n$
  - $a_{n+1}a_{n}=a_{n+1}+a_{n}$
  - $c_n=\sum_{0\leq i\leq n} c_ic_{n-i-1}$

### 容斥原理,生成函数

> 参考这些资料进行学习
>
> - [git-repo:whynotmarkdown](https://github.com/hehelego/WhyNotMarkdown)





## 数论常识

### 整除关系

$$
\begin{aligned}
&a=bq+r\quad(0\leq r<b)\\
\implies & \lfloor\frac{a}{b}\rfloor=q,a\bmod b=r\\
\end{aligned}
$$



如果有$r=0$即$\exists k,bk=a$则称$b\mid a$($b$整除$a$或者$b$为$a$的因子)



### 同余关系

$$
\begin{aligned}
&a=bq+r\\
\implies& a\equiv r\pmod b
\end{aligned}
$$

- 威尔逊定理$p\in primes \iff (p-1)!\equiv -1\pmod p$
- 欧拉定理的扩展(指数循环节)$(b\geq m)\implies a^b\equiv a^{b\bmod m+\varphi(m)}\pmod m$

### 模线性方程组与二元一次方程

> 见现场推到与参考资料



### 素数判定与质因数分解

- $O(\sqrt n)$暴力
- 素数定理$|[1..n]\cap primes|=O(\frac{n}{\log n})$
- 神秘定理$\sum_{primes\leq n}\frac{1}{p}=O(\log \log n)$
- `pollard-rho,miller-rabin`

### 数论函数与求和问题

> 见参考资料与现场讲解