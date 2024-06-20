## Assignment One

|Name|Student Number|
|:----:|:----------:|
|胡锦晖|2053300|

##### 1. Please write the pseudocode of *Quick Sort*

解答：
```
quicksort(Array, p, r)  
{  
    if p < r;
    then q <- partition(Array, p, r)
    quicksort(Array, p, q - 1)
    quicksort(Array, p + 1, r)
}
其中
partition(Array, p, r)
{
    x <- Array[r]
    i <- p-1
    for j <- p to r - 1
    do if Array[j] <= x
    then i++;
    exchange Array[i]<->Array[j]
    exchange Array[i + 1]<->Array[r]
    return i + 1
}
```

##### 2. Which of the following statements is/are valid?(more than one answer is possible)

解答：BCD

* A. Time complexity of Quick Sort is $\Theta (n^2)$

* B. Time complexity of Quick Sort is $O(n^2)$

* C. For any two functions $f(n)$ and $g(n)$, we have $f(n) = \Theta(g(n))$ if and only if $f(n) = O(g(n))$ and $f(n) = \Omega(g(n))$

* D. Time complexity of all computer algorithms can be written as $\Omega(1)$

##### **(a)** The 1-D Discrete Fourier Transform (DFT) of $N$ samples of a signal $f(x)$ sampled at $x =  0, 1, 2, ···, N - 1$ is:$$ F(u) = \frac{1}{n} \sum^{N - 1}_{x = 0}(x) e^{\frac{-j2\pi ux}{N}}$$for $u = 0, 1, ···, N - 1$, and $j = \sqrt{-1}$. If $f(x)$ is generally complex, how many complex multiplications are needed to compute the Fourier Transform of the given sample?
解答：
对于每一个$u = 0, 1, ···, N - 1$，都需要进行$x = 0, 1, ···, N - 1$共$N$次求和，使用$N$个复数乘法(即$4N$个实数乘法)。所以共需要进行$N^2$次复数乘法。

##### **(b)** A significantly more efficient algorithm for computing the DFT is called the Fast Fourier Transform (FFT). The FFT algorithm has the following recurrence relation:$$ T(n) = 2T(\frac{n}{2}) + n$$for $n > 1$ with $T(1) = 1$, n is a power of $2$. Find the complexity of the FFT.

解答：
根据递推关系对于每一个$u = 0, 1, ···, N - 1$, 由于$N$为$2$的幂，所以需要进行$log_2(N)$次复数乘法，共计$Nlog_2(N)$次，所以时间复杂度为$O(NlogN)$