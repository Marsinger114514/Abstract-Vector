//
// Created by 18101 on 24-10-4.
//
#include "Vector.h"
#include <iostream>
#include "String.h"
void testVectorString() {
    Vector<String> test_String;
    // 测试文件输入
    test_String.input();
    cout << "文件读取成功: " << test_String << endl;

    // 尾部添加元素
    test_String.push_back("Hello");
    test_String.push_back("World");
    cout << "添加元素 'Hello', 'World' 后: " << test_String << endl;

    // 头部添加元素
    test_String.push_front("Greetings");
    cout << "添加元素 'Greetings' 到头部后: " << test_String << endl;

    // 在特定位置插入元素
    test_String.insert("C++", 1);
    cout << "在索引 1 插入 'C++' 后: " << test_String << endl;

    // 删除最后一个元素
    test_String.pop_back();
    cout << "删除最后一个元素后: " << test_String << endl;

    // 删除第一个元素
    test_String.pop_front();
    cout << "删除第一个元素后: " << test_String << endl;

    // 删除特定位置的元素
    test_String.erase(1);
    cout << "删除索引 1 的元素后: " << test_String << endl;

    // 删除一段范围内的元素
    test_String.push_back("One");
    test_String.push_back("Two");
    test_String.push_back("Three");
    test_String.erase(1, 2); // 删除索引 1 到 2 的元素
    cout << "删除索引 1 到 2 的元素后: " << test_String << endl;

    // 反转向量
    test_String.reverse();
    cout << "反转后: " << test_String << endl;

    // 显示头部和尾部元素
    cout << "头部元素: " << test_String.front() << endl;
    cout << "尾部元素: " << test_String.back() << endl;

    // 检查大小和容量
    cout << "大小: " << test_String.getsize() << ", 容量: " << test_String.space() << endl;

    // 检查向量是否为空
    cout << "是否为空: " << (test_String.isempty() ? "是" : "否") << endl;

    // 合并测试
    Vector<String> another_vector;
    another_vector.push_back("Goodbye");
    another_vector.push_back("Everyone");
    try {
        Vector<String> merged_vector = test_String + another_vector;
        cout << "合并后: " << merged_vector << endl;
    }catch (int) {
        cout << "维数不同，无法合并 " << endl;
    }

    Vector<String> other_vector;
    other_vector.push_back("Goodbye");
    other_vector.push_back("Goodbye");
    other_vector.push_back("Goodbye");
    other_vector.push_back("Goodbye");
    other_vector.push_back("Goodbye");
    other_vector.push_back("Goodbye");
    other_vector.push_back("Goodbye");
    try {
        Vector<String> merged_vector1 = test_String + other_vector;
        cout << "合并后: " << merged_vector1 << endl;
    }catch (int) {
        cout << "维数不同，无法合并 " << endl;
    }

    // 输出到文件
    test_String.output("Output.txt");
    cout << "内容已输出到文件 Output.txt" << endl;

}
void testVectorint() {
    // 创建一个整型 Vector
    Vector<int> test_vector;

    // 尾部添加元素
    test_vector.push_back(1);
    test_vector.push_back(2);
    test_vector.push_back(3);
    cout << "添加元素 1, 2, 3 后: " << test_vector << endl;

    // 头部添加元素
    test_vector.push_front(0);
    cout << "添加元素 0 到头部后: " << test_vector << endl;

    // 在特定位置插入元素
    test_vector.insert(1, 2);  // 在索引 2 插入元素 1
    cout << "在索引 2 插入 1 后: " << test_vector << endl;

    // 删除最后一个元素
    test_vector.pop_back();
    cout << "删除最后一个元素后: " << test_vector << endl;

    // 删除第一个元素
    test_vector.pop_front();
    cout << "删除第一个元素后: " << test_vector << endl;

    // 删除特定位置的元素
    test_vector.erase(2); // 删除索引 2 的元素
    cout << "删除索引 2 的元素后: " << test_vector << endl;

    // 删除一段范围内的元素
    test_vector.erase(1, 2); // 删除索引 1 到 2 的元素
    cout << "删除索引 1 到 2 的元素后: " << test_vector << endl;

    // 反转向量
    test_vector.push_back(4);
    test_vector.push_back(5);
    test_vector.reverse();
    cout << "添加元素4，5反转后: " << test_vector <<endl;

    // 显示头部和尾部元素
    cout << "头部元素: " << test_vector.front() << endl;
    cout << "尾部元素: " << test_vector.back() << endl;

    // 检查大小和容量
    cout << "大小: " << test_vector.getsize() << ", 容量: " << test_vector.space() << endl;

    // 检查向量是否为空
    cout << "是否为空: " << (test_vector.isempty() ? "是" : "否") << endl;

    // 测试异常情况
    try {
        test_vector.erase(100); // 尝试删除一个不存在的索引
    } catch (int ) {
        cout << "捕获到异常: 删除索引越界" << endl;
    }

    cout << "访问索引为0的元素后: " << test_vector[0] << endl;

    try {
        cout << test_vector[2]; // 尝试访问一个不存在的元素
    } catch (int) {
        cout << "捕获到异常: 下标越界" << endl;
    }

    // 合并数组
    Vector<int> another_vector;
    another_vector.push_back(6);
    another_vector.push_back(7);

    // 使用+运算符合并
    Vector<int> merged_vector = test_vector + another_vector;
    cout << "合并后: " << merged_vector << endl;

    Vector<int> other_vector;
    other_vector.push_back(3);
    other_vector.push_back(4);
    other_vector.push_back(5);

    try {
        Vector<int> merged_vector1 = test_vector + other_vector;
    }catch (int) {
        cout<< "维数不同无法合并" << endl;
    }


    // 清空向量
    while (!test_vector.isempty()) {
        test_vector.pop_back();
    }
    cout << "清空后是否为空: " << (test_vector.isempty() ? "是" : "否") << endl;

    // 重新添加元素
    test_vector.push_back(10);
    test_vector.push_back(20);
    cout << "重新添加元素 10 和 20 后: " << test_vector << endl;
}