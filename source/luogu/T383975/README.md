# 恋心

## 题目描述

小 R 有一个长度为 $n$ 的序列 $a$，她计划给她的好朋友小 M 送礼。

无论是小 R 还是小 M，她们都特别喜欢区间。她们会使用形如 $[l,r]$ 这样的记号来描述一个区间。一个区间 $[l,r]$ 指的是满足 $l\leq x\leq r$ 的所有的 $x$。一个区间的长度即为 **正整数** $x$ 的个数，例如区间 $[3,5]$ 的长度为 $3$。她们称两个区间 $[l_1,r_1]$，$[l_2,r_2]$ 不同，当且仅当 $l_1 \neq l_2$，$r_1\neq r_2$ 中有至少一个不等号成立。

因此，小 R 希望在 $[1,n]$ 的子区间中，选取 $k$ 个 **两两不同且长度大于等于 $2$** 的区间 $[l,r]$ 当做送给小 M 的礼物。一个区间 $[l,r]$ 对小 M 的珍贵程度为 $\min(\sum \limits_{i=l}^{r-1}a_i, \sum \limits_{i=l+1}^{r}a_i)$。（其中 $\sum\limits_{i=x}^y a_i=a_x+a_{x+1}+a_{x+2}+\dots+a_y$）

请告诉小 R 她选出的礼物中对小 M 珍贵程度最低的礼物的珍贵程度最大可以是多少。

## 输入格式

第一行输入两个正整数 $n,k$，分别表示序列 $a$ 的长度，以及小 R 选取的区间个数。

第二行输入 $n$ 个正整数，表示序列 $a$。

## 输出格式

输出一行，一个正整数，表示小 R 选出的礼物中，对小 M 珍贵程度最低的礼物的珍贵程度最大可以是多少。

## 样例 #1

### 样例输入 #1

```
7 3
2 7 1 8 1 8 2
```

### 样例输出 #1

```
19
```

## 提示

**【样例解释】**

对于第一组样例，一种可能的选择方案为：小 R 选取了区间 $[1,7]$，$[2,7]$，$[1,6]$，三个区间分别带来了 $27,20,19$ 的珍贵程度，因此珍贵程度最低的礼物，其珍贵程度是 $19$。可以证明，$19$ 是所有选择方案中，珍贵程度最低的礼物的珍贵程度的最大值。

对于第二组样例，符合第 $12$ 组数据的数据范围。

**【数据范围】**

| 测试点编号 | $n\leq$ | $k\leq$ | $a_i\leq$ |
| :----------: | :----------: | :----------: | :----------: |
| $1\sim 2$ | $10$ | $3$ | $10^3$ |
| $3\sim 4$ | $10^3$ | $2$ | $10^3$ |
| $5\sim 6$ | $2\times 10^5$ | $3$ | $10^3$ |
| $7\sim 8$ | $10^3$ | $10$ | $10^6$ |
| $9\sim 11$ | $10^3$ | $10^3$ | $10^6$ |
| $12\sim 14$ | $10^3$ | $5\times 10^5$ | $10^6$ |
| $15\sim 17$ | $2\times 10^5$ | $5\times 10^5$ | $10^6$ |
| $18\sim 20$ | $2\times 10^5$ | $10^9$ | $10^9$ |

对于所有数据，数据保证 $1\le n\le 2\times 10^5$，$1\le a_i\le 10^9$，$1\le k\le 10^9$。保证 $k\le \frac{n(n-1)}{2}$。
