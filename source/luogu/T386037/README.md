# 迭代更新

## 题目描述

已知一个数字,它的初始值为您,按如下规则对其进行n次操作:

- 如果当前它的值不超过m,则给它加上a
- 否则,给它减去b

请求出它经过n次操作后的值。

## 输入格式

**输入由多组数据构成**。

第一行一个正整数T,表示共有T组数据。

对于每组数据,有一行五个空格分隔的整数n,m,x,a,b。

## 输出格式

对于每组数据,输出一行一个整数表示答案。

## 样例 #1

### 样例输入 #1

```
1 5
2 1 2 7 9 9
3 4 9 2 9 6
4 3 2 6 9 10
5 5 10 5 5 9
6 5 3 5 7 5
```

### 样例输出 #1

```
1 ‐2
2 8
3 ‐5
4 2
5 4
```

## 提示

**【样例 $1$ 解释】**

对于第一组数据：$x$ 的变化为 $7 \rightarrow -2$。

对于第二组数据：$x$ 的变化为 $2 \rightarrow 11 \rightarrow 5 \rightarrow 14 \rightarrow 8$。

对于第三组数据：$x$ 的变化为 $6 \rightarrow -4 \rightarrow 5 \rightarrow -5$。

对于第四组数据：$x$ 的变化为 $5 \rightarrow 10 \rightarrow 15 \rightarrow 6 \rightarrow 11 \rightarrow 2$。

对于第五组数据：$x$ 的变化为 $5 \rightarrow 0 \rightarrow 7 \rightarrow 2 \rightarrow 9 \rightarrow 4$。

**【子任务】**

对于 $30\%$ 的测试数据，有 $1\leq T\leq 2,000$，$1\leq n\leq 2,000$。

对于另外 $20\%$ 的测试数据，保证所有的 $b = 0$。

对于另外 $20\%$ 的测试数据，保证 $b\neq 0$ 且 $a$ 一定可以被 $b$ 整除。

对于 $100\%$ 的测试数据，保证 $1\leq T\leq 10^5$，$1\leq n\leq 10^9$，$0\leq m,x,a,b\leq 10^9$。
