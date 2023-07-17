### Multiplicity

You are given an integer array $a_1, a_2, ..., a_n$.

The array $b$ is called to be a subsequence of $a$ if it is possible to remove some elements from $a$ to get $b$.

Array $b_1, b_2, ..., b_k$ is called to be good if it is not empty and for every $i (1 \leq i \leq k)$ is divisible by $i$.

Find the number of good subsequences in $a$ modulo $10^9 + 7$.

Two subsequences are considered different if index sets of numbers included in them are different. That is, the values ​of the elements ​do not matter in the comparison of subsequences. In particular, the array $a$ has exactly $2^n - 1$ different subsequences (excluding an empty subsequence).

### Input

The first line contains an integer $n (1 \leq n \leq 100 000)$ — the length of the array $a$.

The next line contains integers $a_1, a_2, ..., a_n (1 \leq a_i \leq 10^6)$.

### Output

Print exactly one integer — the number of good subsequences taken modulo $10^9 + 7$.

### Sample 1

Input:

```
2
1 2
```

Output:

```
3
```

### Sample 2

Input:

```
5
2 2 1 22 14
```

Output:

```
13
```

### Note

In the first example, all three non-empty possible subsequences are good: ${1}, {1, 2}, {2}$.

In the second example, the possible good subsequences are:

$$ \lbrace 2 \rbrace, \lbrace 2, 2\rbrace, \lbrace 2, 22\rbrace, \lbrace 2, 14\rbrace, \lbrace 2\rbrace, \lbrace 2, 22\rbrace, \lbrace 2, 14\rbrace, \lbrace 1\rbrace, \lbrace 1, 22\rbrace, \lbrace 1, 14\rbrace, \lbrace 22\rbrace, \lbrace 22, 14\rbrace, \lbrace 14\rbrace $$

Note, that some subsequences are listed more than once, since they occur in the original array multiple times.
