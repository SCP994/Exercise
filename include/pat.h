#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// 3.1 简单模拟

int pat_b_1001(int n);

int pat_b_1011(long A, long B, long C);

int pat_b_1016(int A, int DA, int B, int DB);

void pat_b_1026(int C1, int C2);

int pat_b_1046(int a, int b, int c, int d);

void pat_b_1008(int arr[], int n, int m);

void pat_b_1032(int arr[]);

void pat_b_1012(int arr[]);

void pat_b_1018();

void pat_a_1042();

void pat_a_1046(int arr[]);

void pat_a_1065();

void pat_b_1010();

void pat_a_1002();

void pat_a_1009();

// 3.2 查找元素

void pat_b_1041();

void pat_b_1004();

void pat_b_1028();

void pat_a_1011();

void pat_a_1006();

void pat_a_1036();

// 3.3 图形输出

void pat_b_1036();

void pat_b_1027();

void pat_a_1031();

// 3.5 进制转换

void pat_b_1022();

void pat_b_1037();

void pat_a_1019();

void pat_a_1027();

void pat_a_1058();

// 3.6 字符串处理

void pat_b_1009();

void pat_b_1009_1();

void pat_b_1006();

void pat_b_1021(char str[]);

void pat_b_1031();

void pat_b_1002();

void pat_a_1061();

void pat_b_1014();

void pat_a_1073();

void pat_b_1024();

void pat_b_1048(); // *

void pat_a_1001();

void pat_a_1005();

void pat_a_1035();

void pat_a_1077();

void pat_a_1082();

void pat_a_1082_1(); // *

// 4.1 排序

void pat_a_1025();

void pat_a_1062();

void pat_b_1015();

void pat_a_1012();

void pat_a_1016(); // *

void pat_a_1028();

void pat_a_1055();

void pat_a_1075(); // *

void pat_a_1083();

void pat_a_1080();

void pat_a_1095(); // *

// 4.2 散列

void pat_a_1084();

void pat_b_1029();

void pat_b_1033();

void pat_b_1038();

void pat_a_1092();

void pat_b_1039();

void pat_b_1042();

void pat_b_1043();

void pat_b_1047();

void pat_a_1041();

void pat_a_1050();

void pat_b_1005();

void pat_a_1048();

void pat_a_1048_1();

void pat_a_1048_2();

// 4.4 贪心

void pat_b_1023();

void pat_a_1070();

void pat_b_1020();

void pat_a_1033(); // *

void pat_a_1037();

void pat_a_1067(); // *

void pat_a_1038();

// 4.5 二分

void pat_a_1085();

void pat_b_1030();

void pat_a_1010(); // *

void pat_a_1044();

// 4.6 two pointers

void pat_a_1085_1();

void pat_a_1089(); // *

void pat_b_1035();

void pat_a_1029(); // *

// 4.7 其他高效技巧与算法

void pat_a_1093();

void pat_b_1040();

void pat_a_1101();

void pat_b_1045();

// 5.1 简单数学

void pat_b_1003();

void pat_a_1069();

void pat_b_1019();

void pat_a_1104(); // *

void pat_b_1049();

void pat_a_1008();

void pat_a_1049(); // *

void pat_a_1049_(); // redo

// 5.3 分数的四则运算

void pat_a_1081();

void pat_a_1088();

void pat_b_1034();

// 5.4 素数

void pat_a_1007();

void pat_b_1013();

void pat_a_1015();

void pat_a_1078(); // *

// 5.5 质因子分解

void pat_a_1096(); // *

void pat_a_1059(); // *

// 5.6 大整数运算

void pat_b_1017();

void pat_a_1023();

void pat_a_1024(); // *

// 6.1 vector 的常见用法详解

void pat_a_1039(); // *

void pat_a_1047(); // *

// 6.2 set 的常见用法详解

void pat_a_1063();

// 6.3 string 的常见用法详解

void pat_a_1060(); // *

// 6.4 map 的常见用法详解

void pat_a_1100(); // *

void pat_b_1044();

void pat_a_1054();

void pat_a_1071();

void pat_a_1022(); // *

// 7.1 栈的应用

void pat_a_1051();

// 7.2 队列的应用

void pat_a_1056(); // *

// 7.3 链表处理

void pat_a_1074(); // *

void pat_b_1025();

void pat_a_1032();

void pat_a_1052(); // *

void pat_a_1097(); // *

// 8.1 深度优先搜索

void pat_a_1103(); // *

// 8.2 广度优先搜索

void pat_a_1091(); // *

// 9.2 二叉树的遍历 *

void pat_a_1020();

void pat_a_1086();

void pat_a_1102();

// 9.3 树的遍历

void pat_a_1079(); // *

void pat_a_1090();

void pat_a_1094();

void pat_a_1106();

void pat_a_1004();

void pat_a_1053(); // *

// 9.4 二叉查找树

void pat_a_1043(); // * ?

void pat_a_1064(); // **

void pat_a_1099();

// 9.5 平衡二叉树（AVL 树）

void pat_a_1066(); // *

// 9.6 并查集

void pat_a_1107(); // **

// 9.7 堆

void pat_a_1098(); // *

// 10.3 图的遍历

void pat_a_1013(); // *

void pat_a_1021();

void pat_a_1034(); // **

void pat_a_1076();

// 10.4 最短路径

void pat_a_1003();

void pat_a_1018(); // *

void pat_a_1030();
