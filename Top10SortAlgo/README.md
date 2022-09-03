# 十大经典排序算法

![](./img/top10.png)



**不稳定：** 快些选堆，快排、希尔、选择、归并



## 1.快速排序（Quick Sort）（不稳定）

**时间复杂度:** $O(nlog_2n)$ 

**空间复杂度：** $O(log_2n)$

**基本思路：** 快速排序每一次都排定一个元素（这个元素呆在了它最终应该呆的位置），然后递归地去排它左边的部分和右边的部分，依次进行下去，直到数组有序；

**算法思想：** 分而治之（分治思想），与「归并排序」不同，「快速排序」在「分」这件事情上不像「归并排序」无脑地一分为二，而是采用了 partition 的方法，因此就没有「合」的过程。

随机选取一个数（x = rand() % len + startIndex）作为基准；
把比基准小的数交换到前面，比基准大的数交换到后面；
对左右区间递归重复。

```cpp
vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    quickSort(nums, 0, n - 1);
    return nums;
}

void quickSort(vector<int>&nums, int startIndex, int endIndex) {
    if (startIndex >= endIndex) return;


    int x = rand() % (endIndex - startIndex + 1) + startIndex; // 基于随机的原则
    swap(nums[startIndex], nums[x]);
    int firstNum = nums[startIndex];

    int l = startIndex, r = endIndex;
    while (l < r) {
        // 从后往前走，将比第一个小的移到前面
        while (l < r && nums[r] >= firstNum) --r;
        if (l < r) {
            nums[l] = nums[r];
        }
        // 从前往后走，将比第一个大的移到后面
        while (l < r && nums[l] <= firstNum) ++l;
        if (l < r) {
            nums[r] = nums[l];
        }
    }
    nums[l] = firstNum;
    // 自顶向下
    quickSort(nums, startIndex, l - 1);
    quickSort(nums, l + 1, endIndex);
}
```



## 2.堆排序（Heap Sort）（不稳定）

**时间复杂度:** $O(nlog_2n)$ 

**空间复杂度：** $O(1)$

先在原先数组的基础上构造大根堆（时间复杂度 $O(nlog_2n)$ ）；
再依次弹出最大元素（每次弹出的时间复杂度为 $O(log_2k)$ ，k为当前大根堆中元素数目）。

```cpp
vector<int> sortArray(vector<int>& nums) {
    // heapSort 堆排序
    int n = nums.size();
    // 将数组整理成大根堆
    buildMaxHeap(nums);
    for (int i = n - 1; i >= 1; --i) {
        // 依次弹出最大元素，放到数组最后，当前排序对应数组大小 - 1
        swap(nums[0], nums[i]);
        --n;
        maxHeapify(nums, 0, n);
    }
    return nums;
}

void buildMaxHeap(vector<int>& nums) {
    int n = nums.size();
    for (int i = (n - 1) / 2; i >= 0; --i) {
        maxHeapify(nums, i, n);
    }
}

void maxHeapify(vector<int>& nums, int i, int n) {
    while (i * 2 + 1 < n) {
        // 代表当前 i 节点的左右儿子；
        // 超出数组大小则代表当前 i 节点为叶子节点，不需要移位
        int j = 2 * i + 1;
        if (j + 1 < n && nums[j + 1] > nums[j]) ++j;

        if (nums[j] > nums[i]) {
            swap(nums[i], nums[j]);
            // 迭代判断对应子节点及其儿子节点的大小关系
            i = j;
        } else {
            break;
        }
    }
}
```



## 3.归并排序（Merge Sort）（稳定）

**时间复杂度:** $O(nlog_2n)$ 

**空间复杂度：** $O(n)$

**基本思路：** 借助额外空间，合并两个有序数组，得到更长的有序数组。例如：「力扣」第 88 题：合并两个有序数组。
**算法思想： **分而治之（分治思想）。「分而治之」思想的形象理解是「曹冲称象」、MapReduce，在一定情况下可以并行化。

[更好的讲解](https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/solution/jian-zhi-offer-51-shu-zu-zhong-de-ni-xu-pvn2h/)

算法流程：

1. 终止条件： 当 l≥r 时，代表子数组长度为 1 ，此时终止划分；
2. 递归划分： 计算数组中点 m ，递归划分左子数组 merge_sort(l, m) 和右子数组 merge_sort(m + 1, r) ；
3. 合并：
   1. 暂存数组 nums 闭区间 [i, r] 内的元素至辅助数组 tmp；
   2. 循环合并： 设置双指针 i, j 分别指向 左/右 子数组的首元素；
      - 当 i = m + 1 时： 代表左子数组已合并完，因此添加右子数组当前元素 tmp[j]，并执行 j = j + 1；
      - 否则，当 j = r + 1 时： 代表右子数组已合并完，因此添加左子数组当前元素 tmp[i]，并执行 i = i + 1；
      - 否则，当 tmp[i] ≤ tmp[j] 时： 添加左子数组当前元素 tmp[i]，并执行 i = i + 1；
      - 否则（即 tmp[i] > tmp[j]）时： 添加右子数组当前元素 tmp[j]，并执行 j = j + 1

```cpp
vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> tmp(n);
    mergeSort(nums, 0, n - 1, tmp);
    return nums;
}

void mergeSort (vector<int>& nums, int l, int r, vector<int>& tmp) {
    if (l >= r) return; // 终止条件，不需进行排列
    int m = l + (r - l) / 2;
    // 自底向上
    mergeSort(nums, l, m, tmp);
    mergeSort(nums, m + 1, r, tmp);
    // 排序当前数组
    int i = l, j = m + 1, pos = l;

    // [l, r] 区间拷贝下来进行排序
    for (int k = i; k <= m; ++k) {
        tmp[k] = nums[k];
    }
    for(int k = l, k <= r; ++k) {
        // 1.当 i = m + 1时：代表左子数组已合并完
        // 因此添加右子数组当前元素 tmp[j] ，并执行 j = j + 1
        if(i == m + 1) {
            nums[k] = tmp[j++];
        }
        // 2.否则，当 j = r + 1 时： 代表右子数组已合并完，因此添加左子数组当前元素 tmp[i]，并执行 i = i + 1；
        // 3.否则，当 tmp[i] <= tmp[j] 时： 添加左子数组当前元素 tmp[i] ，并执行 i = i + 1；
        else if (j == r + 1 || tmp[i] <= tmp[j]) {
            nums[k] = tmp[i++];
        }
        // 4.否则（即 tmp[i] > tmp[j]）时：添加右子数组当前元素 tmp[j] ，并执行 j = j + 1；
        else {
            nums[k] = tmp[j++];
        }
    }
}
```



## 4.冒泡排序（Bubble Sort）（稳定排序）

**时间复杂度:** $O(n^2)$ 

**空间复杂度：** $O(1)$

比较相邻元素，如果第一个比第二个大，则交换

```cpp
vector<int> sortArray(vector<int>& nums) {
    // bubbleSort
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
        bool flag = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
        if (flag == false) break; //无交换，代表当前序列已经最优
    }
    return nums;
}
```



## 5.选择排序（Select Sort）（不稳定）

依次给每个位置选择当前位置及以后最小的元素（交换当前元素与之后最小元素的位置）。

不稳定举例：
排序前：5, 5, 1, 7
排序后：1, 5, 5, 7

**时间复杂度:** $O(n^2)$ 

**空间复杂度：** $O(1)$

```cpp
vector<int> sortArray(vector<int>& nums) {
    // selectSort 选择排序
    int minIndex;
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
        minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        swap(nums[i], nums[minIndex]);
    }
    return nums;
}
```



## 6.插入排序（Insect Sort）（稳定）

**时间复杂度:** $O(n^2)$ 

**空间复杂度：** $O(1)$

在前 0 ~ i - 1 元素有序的情况下，（依次）将第 i 个元素插入前面已经有序的小序列，使其有序。

```cpp
vector<int> sortArray(vector<int>& nums) {
    // insertSort 插入排序
    int n = nums.size();
    // 第一个元素被认为已经被排序
    for (int i = 1; i < n; ++i) {
        // 先暂存这个元素，然后之前元素逐个后移，留出空位
        int tmp = nums[i];
        int j = i;
        // 注意边界 j > 0
        while (j > 0 && nums[j - 1] > temp) {
            nums[j] = nums[j - 1];
            j--;
        }
        nums[j] = temp;
    }
    return nums;
}
```



## 7.桶排序（Bucket Sort）（稳定）

**时间复杂度:** $O(n + k)$ 

**空间复杂度：** $O(n + k)$

将原数组的元素分到有限数量的桶里（大编号桶里的所有元素均大于小编号桶里的任意元素）；
分别对每个桶进行排序；
依次合并。

```cpp
vector<int> sortArray(vector<int>& nums) {
    // BucketSort 桶排序
    int n = nums.size();
    // 获取数组的最小值和最大值
    int maxNum = nums[0], minNum = nums[0];
    for (int i = 1; i < n; ++i) {
        if (nums[i] > maxNum) maxNum = nums[i];
        if (nums[i] < minNum) minNum = nums[i];
    }
    // 初始化桶
    int bucketNum = 5, bucketSize = (maxNum - minNum) / bucketNum + 1;
    vector<vector<int>> buckets(bucketNum, vector<int>(0));
    // 小至大分桶
    for (int num : nums) {
        int bucketIndex = (num - minNum) / bucketSize;
        buckets[bucketIndex].emplace_back(num);
    }
    // 桶内排序
    for (int i = 0; i < buckets.size(); ++i) {
        sort(buckets[i].begin(), buckets[i].end());
    }
    // 从桶中依次取数
    int index = 0;
    for (auto& bucket : buckets) {
        for (int num : bucket) {
            nums[index++] = num;
        }
    }

    return nums;
}
```



## 8.计数排序（Count Sort）（稳定）

**时间复杂度:** $O(n + k)$ 

**空间复杂度：** $O(k), (k = maxNum - minNum + 1)$

创建数组 counts，用于统计原数组 nums 中各元素值的出现次数；
再依次将元素值赋值到 nums 中对应位置。

```cpp
vector<int> sortArray(vector<int>& nums) {
    // CountSort 计数排序
    int n = nums.size();
    int minNum = INT_MAX, maxNum = INT_MIN;
    // 找到数组中的最小和最大元素
    for (int i = 0; i < n; ++i) {
        if (nums[i] < minNum) minNum = nums[i];
        if (nums[i] > maxNum) maxNum = nums[i];
    }
    // 构造计数数组
    vector<int> counts(maxNum - minNum + 1, 0);
    for (int i = 0; i < n; ++i) {
        ++counts[nums[i] - minNum];
    }
    // 计数排序
    int index = 0;
    for (int i = 0; i < counts.size(); ++i) {
        while (counts[i] != 0) {
            nums[index++] = i + minNum;
            counts[i]--;
        }
    }
    return nums;
}
```



## 9.希尔排序（Shell Sort）（非稳定）

**时间复杂度:** 介于 $O(nlog_2n)$ 和 $O(n^2)$ 之间 

**空间复杂度：** $O(1)$

改进的插入排序（优化：原数组的一个元素距离正确位置很远的情况）
先让间隔 h 的元素有序，在使得间隔为 h / 2，一直缩小，一直到 h = 1（此时数组有序）。

```cpp
vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    // 分组，最开始时，间隔 gap 为数组的一半
    for (int gap = n / 2; gap >= 1 ; gap /= 2) {
        // 对各个分组进行插入分组
        for (int i = gap; i < n; ++i) {
            shellSort(nums, gap, i);
        }
    }
    return nums;
}

void shellSort(vector<int>&nums, int gap, int i) {
    int j, tmp = nums[i];
    for (j = i - gap; j >= 0 && tmp < nums[j]; j -= gap) {
        // 依次后移
        nums[j + gap] = nums[j];
    }
    nums[j + gap] = tmp;
}
```



## 10.基数排序（Radix Sort）（稳定）

对数组中所有数依次按由低到高的位数进行多次排序；
每次排序都基于上次排序的结果。
（相对位置顺序保持不变）

例：原始数组 1，23，21，11，32
第一次排序后 1，21，11，32，23
第二次排序后 1，11，21，23，32

```cpp
vector<int> counts;

vector<int> sortArray(vector<int>& nums) {
    // RadixSort 基数排序
    int n = nums.size();
    // 预处理，让所有的数都大于等于0
    for (int i = 0; i < n; ++i) {
        nums[i] += 50000; // 50000为最小可能的数组大小
    }
    // 找出最大的数字，并获得其最大位数
    int maxNum = nums[0];
    for (int i = 0; i < n; ++i) {
        if (nums[i] > maxNum) {
            maxNum = nums[i];
        }
    }
    int num = maxNum, maxLen = 0;
    while (num) {
        ++maxLen;
        num /= 10;
    }
    // 基数排序，低位优先
    int divisor = 1;
    vector<int> tmp(n, 0);
    for (int i = 0; i < maxLen; ++i) {
        radixSort(nums, tmp, divisor);
        swap(tmp, nums);
        divisor *= 10;
    }
    // 减去预处理量
    for (int i = 0; i < n; ++i) {
        nums[i] -= 50000;
    }
    return nums;
}

void radixSort(vector<int>& nums, vector<int>& tmp, int divisor) {
    int n = nums.size();
    counts = vector<int>(10, 0);
    // 统计个、十、百、千、万上对应 0 ~ 9 的出现次数
    for (int i = 0; i < n; ++i) {
        int x = (nums[i] / divisor) % 10;
        ++counts[x];
    }
    // 前缀和
    for (int i = 1; i <= 9; ++i) {
        counts[i] += counts[i - 1];
    }
    // 从后向前赋值
    for (int i = n - 1; i >= 0; --i) {
        int x = (nums[i] / divisor) % 10;
        int index = counts[x] - 1;
        tmp[index] = nums[i];
        --counts[x];
    }
}
```

