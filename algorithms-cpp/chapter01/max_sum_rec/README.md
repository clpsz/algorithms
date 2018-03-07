#说明
本例实现了最大
使用./rand.py > data.txt来生成数据，这里我把我生成的数据也上传了

##算法1，暴力解法(O(N^3))
```
$make msr1
$time ./msr1 < data.txt
```
输出如下：
```
Max sum is: 2166
from: 18, end: 542

real    0m0.725s
user    0m0.722s
sys 0m0.001s
```
##算法2，去掉最内层循环(O(N^2))
```
$make msr2
$time ./msr2 < data.txt
```
输出如下：
```
Max sum is: 2166
from: 18, end: 542

real    0m0.006s
user    0m0.005s
sys 0m0.001s
```
##算法3，分治法(O(Nlog(N)))，好像拿不到最大子序列的位置
```
$make msr3
$time ./msr3 < data.txt
```
输出如下：
```
2166

real	0m0.002s
user	0m0.001s
sys	0m0.001s
```
##算法4，O(N)
```
$make msr4
$time ./msr4 < data.txt
```
输出如下：
```
Max sum is: 2166
from: 18, end: 542

real	0m0.002s
user	0m0.001s
sys	0m0.001s
```

#总结
可以看出来，Nlog(N)的算法性能已经很好了，但是N^2和N^3在数据增长时则无法接受。
