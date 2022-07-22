// 1114. 按序打印 tag 多线程
// 给你一个类：

// public class Foo {
//   public void first() { print("first"); }
//   public void second() { print("second"); }
//   public void third() { print("third"); }
// }
// 三个不同的线程 A、B、C 将会共用一个 Foo 实例。

// 线程 A 将会调用 first() 方法
// 线程 B 将会调用 second() 方法
// 线程 C 将会调用 third() 方法
// 请设计修改程序，以确保 second() 方法在 first() 方法之后被执行，third() 方法在 second() 方法之后被执行。

// 提示：

// 尽管输入中的数字似乎暗示了顺序，但是我们并不保证线程在操作系统中的调度顺序。
// 你看到的输入格式主要是为了确保测试的全面性。
 

// 示例 1：

// 输入：nums = [1,2,3]
// 输出："firstsecondthird"
// 解释：
// 有三个线程会被异步启动。输入 [1,2,3] 表示线程 A 将会调用 first() 方法，线程 B 将会调用 second() 方法，线程 C 将会调用 third() 方法。正确的输出是 "firstsecondthird"。
// 示例 2：

// 输入：nums = [1,3,2]
// 输出："firstsecondthird"
// 解释：
// 输入 [1,3,2] 表示线程 A 将会调用 first() 方法，线程 B 将会调用 third() 方法，线程 C 将会调用 second() 方法。正确的输出是 "firstsecondthird"。

class Foo {
    condition_variable cv;
    mutex mtx;
    int k = 0;

public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        k = 1;
        cv.notify_all();    // 通知其他所有在等待唤醒队列中的线程
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);   // lock mtx
         // unlock mtx，并阻塞等待唤醒通知，需要满足 k == 1 才能继续运行
        // 捕获 this，lambda可以使用所在类的成员变量
        cv.wait(lock, [this](){return k == 1;});
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        k = 2;
        // 随机通知一个（unspecified）在等待唤醒队列中的线程
        cv.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);   // lock mtx
        // unlock mtx，并阻塞等待唤醒通知，需要满足 k == 2 才能继续运行
        cv.wait(lock, [this](){return k == 2;});
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};