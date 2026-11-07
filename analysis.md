#  GCD Algorithm Analysis:
## Divisor-Based GCD (Brute-Force):
**Time Complexity Analysis**: 
1. **Phase 1**: Finding Divisors of $a$
```cpp
for (int i = 1; i <= a; i++) {
    if (a % i == 0) {
        r.push_back(i);
    }
}
```
The loop iterates exactly $a$ times. In each iteration, modulo arithmetic and conditional checks take $O(1)$ time.Inserting into std::vector takes amortized $O(1)$ time.Time Complexity: $T_1(a) = \Theta(a)$

2. **Phase 2**: Finding Divisors of $b$
```cpp
for (int i = 1; i <= b; i++) {
    if (b % i == 0) {
        m.push_back(i);
    }
}
```
The loop iterates exactly $b$ times under identical conditions.Time Complexity: $T_2(b) = \Theta(b)$

3. **Phase 3:** Finding the Maximum Common Divisor (Nested Loops)
Let $d(n)$ denote the divisor function (the total number of divisors of $n$).The size of vector r is $\vert{}r\vert{} = d(a)$, and the size of vector m is $\vert{}m\vert{} = d(b)$.The nested loop executes exactly $d(a) \times d(b)$ comparisons:$$T_3(a, b) = \Theta(d(a) \cdot d(b))$$Because $d(n) \le 2\sqrt{n}$ for any positive integer $n$:$$T_3(a, b) = O(\sqrt{a} \cdot \sqrt{b}) = O(\sqrt{ab})$$Since the geometric mean $\sqrt{ab}$ is bounded by the arithmetic mean $\frac{a + b}{2}$, this step is strictly dominated by Phase 1 and Phase 2 ($O(\sqrt{ab}) \le O(a + b)$).

**Overall Time ComplexitySumming the cost of all phases**:$$T_{\text{total}}(a, b) = T_1(a) + T_2(b) + T_3(a, b) = \Theta(a) + \Theta(b) + O(\sqrt{ab}) = \Theta(a + b)$$If we assume $a \approx b \approx N$:$$T(N) = \Theta(N)$$The algorithm runs in linear time relative to the numerical magnitude of the inputs.

---
## Subtraction:
 if $a > b$ then: $\gcd(a, b) = \gcd(a - b, b)$
 **Analysis:**
 let us assume the **worst_case Scenario**: $a = N$ and $b = 1$
1. **step 1**: $a > b \implies a = N - 1$ ، $b = 1$
2. **Step 2**: $a > b \implies a = N - 2$ ، $b = 1$
:
.
3. **Step $N-1$**: $a = 2 - 1 = 1$ ، $b = 1$
**since the condition in while-loop is no longer correct 
($a \neq b$), the algorithm will stop at this point after $N-1$ sequences.
The T-function will be:
**$$T(N) = c \cdot (N - 1) = \Theta(N)$$**
**So the t-function is linear**
------
## Division/Modulo: 
#### Prove:
let us assume that a & b are 2 integer numbers and $a>b$
According to **Divison Theorem** the following relation holds:
**$$a = q \cdot b + r \implies r = a - q \cdot b \quad (0 \le r < b)$$**
Now lets assume that $d$ is the $gcd$ of both $a$ & $b$.

- since $d$ divides $a$ & $b$, so it divides the subtraction of them: 
**$r = a - qb$**
- On the other hand if a number divides both $b$ and $r$, it will divide their sum:
**$a = qb + r$**
**Therefore**, $gcd(a,b)$ is the same as the *$gcd(b,r)$*.
**$$\gcd(a, b) = \gcd(b, a \pmod b)$$**
We continue this algorith 'till the remainder is $0$:
**$$\gcd(x, 0) = x$$**
----
####  Time Complexity Analysis:
**Theorem**:
In each step of the **division algorithm** the following relationship is valid:
**$$r = a \pmod b < \frac{a}{2}$$**
**Prove:**
We have 2 cases:
1. ($b \le \frac{a}{2}$): **$$r < b \le \frac{a}{2} \implies r < \frac{a}{2}$$**

2. $b > \frac{a}{2}$:
since $b > \frac{a}{2}$, q can only be $1$. Otherwise $b$ will be greater than $a$, which leads to a contradiction.
 **$$a = 1 \cdot b + r \implies r = a - b$$**
 Hence:
 **$$
 b > \frac{a}{2} \implies -b < -\frac{a}{2} \implies a - b < a - \frac{a}{2}
  \implies
 r < \frac{a}{2}
  $$**

Since in each step the variables are replaced by $r$, so after 2 steps the value of numbers is reduced by 50%.
**$$a_{k+2} < \frac{a_k}{2}$$**
This leads to a **Exponential Behavior**. Therefore, the T_function will be:     **$O(\log a)$**
Now let us see which inputs detemine the upper_bound and cause the worst scenario.
The following relation is valid in every step:
**$$r_{i+1} = r_{i-1} - q_i \cdot r_i$$**
For the algorithm, in order to take longer to finish, $r_{i+1}$ should stay as big as possible.Thus $q_i \cdot r_i$ must be as small as possible, which means $q_i$ must be equal to $1$. Therefore, the equation will take the following form:
**$$r_{i+1} = r_{i-1} - 1 \cdot r_i \implies r_{i-1} = r_i + r_{i+1}$$**
which is the very **Recurrence Relation Of Fibonacci**.
It means that Fibonacci numbers are the worst inputs of this algorithm which determine the *upper bound*.

  