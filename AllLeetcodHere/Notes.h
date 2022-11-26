#pragma once
#include <vector>
#include <iostream>
#include <chrono>
using namespace std;

#define mins(a,b,c) min(min(a,b),c)

/* notes
	vector<int> a(2, 8); // 这样生成含有两个元素且值为8的向量
	3 >> 1 右移（左移）操作只适用于整数，比除法快，优先级比除法低，答案与整数除法相同：3 >> 1 为 1
	非静态变量不能在类外定义
	int i; 变量类型：typeid(i).name();
	string s; 长度：s.size(); 或者 s.length(); char* s; 长度：strlen(s);
	string 类型，s += a; 比 s = s + a; 快
	malloc free 成对 https://blog.csdn.net/qq_46515446/article/details/124746533
	malloc 传入字节数，返回值需强转成指定类型的地址
	不需要考虑 new 失败的情况
	int const* i; const int* i;	// const 在 * 左边，可以修改地址，不能通过 *i 修改值
	int* const i;	// const 在 * 右边，不可以修改地址，可以通过 *i 修改值
	const int* const i;	// 不能修改地址，也不能通过 *i 修改值
	const 能用尽用
	顺序结构：vector、list、deque
	容器适配器：stack、queue、priority-queue
	结构体：将不同类型的数据组合成一个整体，是自定义类型;  共同体：不同类型的几个变量共同占用一段内存
		1）结构体中的每个成员都有自己独立的地址，它们是同时存在的； 共同体中的所有成员占用同一段内存，它们不能同时存在
		2）sizeof(struct)是内存对齐后所有成员长度的总和，sizeof(union)是内存对齐后最长数据成员的长度
	void pointer in C / C++:
		A void pointer is a pointer that has no associated data type with it.
		A void pointer can hold address of any type and can be typecasted to any type.

	貌似 resize 第二次分配有点问题，直接 = vector<int>(m, vector<int>(n)); 重新赋值好了

*/

/* emplace_back()
	功能：和 push_back() 相同，都是在 vector 容器的尾部添加一个元素
	push_back()方法要调用构造函数和复制构造函数，这也就代表着要先构造一个临时对象，然后把临时的copy构造函数拷贝或者移动到容器最后面。
	而emplace_back()在实现时，则是直接在容器的尾部创建这个元素，省去了拷贝或移动元素的过程

	vector<pair<int, int> > ret;
	//ret.push_back(1, 1);	//会报错，因为没有构造一个临时对象
	ret.push_back(pair<int, int>(1, 1));	//不会报错，因为构成了一个pair对象
	ret.emplace_back(1, 1);	//不会报错，因为直接在容器的尾部创建对象

	push_back()：向容器中加入一个右值元素(临时对象)时，首先会调用构造函数构造这个临时对象，
	然后需要调用拷贝构造函数（或转移构造函数）将这个临时对象放入容器中。原来的临时变量释放。这样造成的问题就是临时变量申请资源的浪费。
	emplace_back()：在插入元素的时候直接构造（原地构造），只调用一次构造函数，不需要触发拷贝构造和转移构造。而且调用形式更加简洁，直接根据参数初始化临时对象的成员。
	内存优化方面和运行效率方面更优。

	elections.emplace_back("Nelson Mandela", "South Africa", 1994); // 传入的是 创建这个对象 需要的 构造参数

	elections.push_back(President("Franklin Delano Roosevelt", "the USA", 1936));  // 传入的是一个对象

	elections.emplace_back(President("Franklin Delano Roosevelt", "the USA", 1936));  // 同上一样
*/

class Notes
{
public:
	pair<int, int> minMax(vector<int>& nums);   // min and max in 3n / 2 times' comparison

	void check();	// 判断系统大小端存储

	void check_();

	float testTime();	// 测试代码运行时间

	void malloc_free();

	int& test(int& a)	// 返回的是左值
	{
		++a;
		return a;
	}

	void t(int* p)
	{
		cout << p << endl;
		p = nullptr;
		cout << p << endl;  // 在外面访问指针，不会是空指针
	}

private:

};

/*
	char* 是变量，值可以改变，char[] 是常量，值不能改变。
	比如：
	char* a = "string1";
	char b[] = "string2";
	char* 本身是一个字符指针变量，但是它既可以指向字符串常量，又可以指向字符串变量，指向的类型决定了对应的字符串能不能改变。
	注意：上面的 a, b 都会在末尾加上 '\0'，所以使用 strcpy_s 等函数时，注意要复制的长度是 strlen(a) + 1！！！
*/

// https ://blog.csdn.net/whahu1989/article/details/118880075
/*
1. 编译器产生的这些特殊成员函数都是public和inline的
2. 拷贝构造函数的默认操作是对所有非静态成员变量进行逐个拷贝构造；
3. 拷贝赋值构造函数的默认操作是对所有非静态成员变量进行逐个拷贝赋值构造；
4. 移动构造函数的默认操作是对所有非静态成员变量进行逐个移动构造；
5. 移动赋值构造函数的默认操作是对所有非静态成员变量进行逐个移动赋值构造；
6. 对于析构函数，如果这个类有个父类且父类的析构函数是virtual的，那么自动生成的析构函数也是virtual的；
7. 需要的时候才有可能自动生成
*/

/*
拷贝构造函数和拷贝赋值构造函数之间是互相独立的，用户定义了其中一个并不会阻止编译器生成另外一个
如果类里自定义了移动相关的构造函数，那么就会阻止编译器生成拷贝相关的构造函数
移动构造函数和移动赋值构造函数之间不是独立的，如果只定义了其中一个，那么就会阻止编译器去生成另外一个
移动相关的构造函数只有满足以下三个条件才会由编译器自动生成：
	1. 类里没有自定义拷贝构造函数和拷贝赋值构造函数
	2. 类里没有自定义移动构造函数和移动赋值构造函数
	3. 类里没有自定义析构函数
*/

// 当不需要拷贝相关的操作和移动相关的操作时，可以使用delete关键字显示的把这些函数删除掉

/*
	CClass a = CClass(10);	// 显示调用
	CClass a(10);	// 隐式调用

	CClass a;
	拷贝构造
	CClass b = a;	// 隐式调用拷贝构造，可能调用赋值（一般不会）
	CClass b(a);
	移动构造
	CClass b = move(a);	// 隐式调用移动构造
	CClass b(move(a));

	CClass a, b;
	拷贝赋值
	b = a;
	移动赋值
	b = move(a);

	CClass a = 10;	// 隐式类型转换，先调用有参构造，再调用拷贝赋值
	CClass a = move(10.1);	// 隐式类型转换，先调用有参构造，再调用移动赋值

	CClass a;	// 无参构造
	a = 10.9;	// 隐式类型转换，有参构造，再移动赋值

	CClass(double) = delete; 可避免所有 double 型构造的情况
	explicit 关键字可避免对应构造函数的隐式调用
*/

class CClass
{
public:
	CClass() : m_num(0), m_strLen(10), m_str((char*)malloc(10))	// (char*)malloc(10) 与 new char[10]() 异同
	{
		if (!m_str)
			throw bad_alloc();
		m_str[9] = '\0';
		cout << "default constructor" << endl;
	}

	//CClass(int m_num = 0) : m_num(m_num) { cout << "default constructor" << endl; }	// 带参数的默认构造函数，默认构造函数只能有一个

	explicit CClass(int num)	// 有参构造函数，此时编译器不会生成默认构造函数，可通过 default 来生成
		: m_num(num), m_strLen(10), m_str((char*)malloc(10))	// 编译器生成的拷贝函数只做浅拷贝，两个对象的 m_ptr 会指向同一个地址 
	{
		if (!m_str)
			throw bad_alloc();
		m_str[9] = '\0';
		cout << "constructor with params" << endl;	
	}

	CClass(double) = delete;

	~CClass() { if (m_str) free(m_str); }

	explicit CClass(const CClass& c)
		: m_num(c.m_num), m_strLen(c.m_strLen), m_str((char*)malloc(m_strLen))	// 拷贝构造
	{
		if (!m_str)
			throw bad_alloc();
		for (int i = 0; i < m_strLen; ++i)
			m_str[i] = c.m_str[i];
		cout << "copy constructor" << endl;
	}

	CClass& operator=(const CClass& c)	// 拷贝赋值
	{
		m_num = c.m_num;
		m_strLen = c.m_strLen;
		m_str = (char *)malloc(m_strLen);
		if (!m_str)
			throw bad_alloc();
		for (int i = 0; i < m_strLen; ++i)
			m_str[i] = c.m_str[i];
		cout << "copy assignment" << endl;
		return *this;
	}

	explicit CClass(CClass&& c) noexcept	// 声明和定义（包括类内和类外）都要加上 noexcept
		: m_num(c.m_num), m_strLen(c.m_strLen), m_str(c.m_str)	// 移动构造
	{
		c.m_str = nullptr;
		cout << "move constructor" << endl;
	}

	CClass& operator=(CClass&& c) noexcept	// 移动赋值
	{
		m_num = c.m_num;
		m_strLen = c.m_strLen;
		m_str = c.m_str;
		c.m_str = nullptr;
		cout << "move assignment" << endl;
		return *this;
	}

	int getA() const { return m_num; }

	char* getStr() const { return m_str; }

private:
	int m_num;
	int m_strLen;
	char* m_str;

};

/*
	不管是左值引用、右值引用，std::forward 都会按照原来的类型完美转发
	forward 主要解决引用函数参数为右值时，传进来之后有了变量名就变成了左值
*/
template <typename T>
class CLRValue
{
public:
	void printX(T& lValue) { cout << "lValue" << lValue << endl; }

	void printX(T&& rValue) { cout << "rValue" << rValue << endl; }

	void testRValue(T&& nValue)
	{
		printX(nValue);
		printX(forward<T>(nValue));
		printX(move(nValue));
	}

	void test()
	{
		int nValue = 100;
		testRValue(4);					// 左 右 右
		testRValue(nValue);						// 左 左 右
		testRValue(forward<int>(nValue));	// 左 右 右
	}

};
