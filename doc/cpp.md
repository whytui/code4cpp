# CPP

## 内存模型

#### 1.5块内存区域
* 堆 heap ：
由new分配的内存块，其释放编译器不去管，由我们程序自己控制（一个new对应一个delete）。如果程序员没有释放掉，在程序结束时OS会自动回收。涉及的问题：“缓冲区溢出”、“内存泄露”
* 栈 stack ：
是那些编译器在需要时分配，在不需要时自动清除的存储区。存放局部变量、函数参数。
存放在栈中的数据只在当前函数及下一层函数中有效，一旦函数返回了，这些数据也就自动释放了。
* 全局/静态存储区 （.bss段和.data段） ：
全局和静态变量被分配到同一块内存中。在C语言中，未初始化的放在.bss段中，初始化的放在.data段中；在C++里则不区分了。
* 常量存储区 （.rodata段） ：
存放常量，不允许修改（通过非正当手段也可以修改）
* 代码区 （.text段） ：
存放代码（如函数），不允许修改（类似常量存储区），但可以执行（不同于常量存储区）
根据C++对象生命周期不同，C++的内存模型有三种不同的内存区域:
1.自由存储区，动态区、静态区局部非静态变量的存储区域(栈)
2.动态区:用operator new,malloc分配的内存(堆)
3.静态区:全局变量、静态变量、字符串常量存在位置

#### 2.class内存模型

class由成员变量、成员函数、静态成员变量、静态成员函数、虚函数与纯虚函数组成