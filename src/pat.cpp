#include "pat.h"

int pat_b_1001(int n) {
    int cnt = 0;

    while (n != 1) {
        ++cnt;
        if (n % 2)
            n = (3 * n + 1) / 2;
        else
            n /= 2;
    }

    return cnt;
}

int pat_b_1011(long long A, long long B, long long C) {
    if (A + B > C)
        return 1;
    return 0;
}

int pat_b_1016(int A, int DA, int B, int DB) {
    int PA = 0;
    int PB = 0;
    while (A) {
        if (A % 10 == DA)
            PA = PA * 10 + DA;
        A /= 10;
    }
    while (B) {
        if (B % 10 == DB)
            PB = PB * 10 + DB;
        B /= 10;
    }
    return PA + PB;
}

void pat_b_1026(int C1, int C2) {
    int duration = C2 - C1;
    int h = 0, m = 0, s = 0;
    const int BASE = 60;
    const int clk_tck = 100;

    s = duration % (BASE * clk_tck);
    duration /= (BASE * clk_tck);
    m = duration % BASE;
    duration /= BASE;
    h = duration % BASE;

    printf("%02d:%02d:%02d\n", h, m, (s + (clk_tck / 2)) / clk_tck);
}

int pat_b_1046(int a, int b, int c, int d) {
    int total = a + c;
    if (b == total && d != total)
        return 2;
    if (b != total && d == total)
        return 1;
    return 0;
}

namespace {
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
} // namespace

void pat_b_1008(int arr[], int n, int m) {
    int g = gcd(n, m);
    for (int i = 0; i < g; ++i) {
        int b = i;
        int e = (b + m) % n;
        int t = arr[b];
        while (e != b) {
            std::swap(arr[e], t);
            e = (e + m) % n;
        }
        arr[e] = t;
    }
}

void pat_b_1032(int arr[]) {
    int n, index, score;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &index, &score);
        arr[index] += score;
    }
    int *p = std::max_element(arr + 1, arr + n + 1);
    printf("%d %d\n", static_cast<int>(p - arr), *p);
}

void pat_b_1012(int arr[]) {
    int cnt[5] = {0};
    int a[5] = {0};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);

        int num = arr[i];
        int remainder = num % 5;
        if (remainder == 0) {
            if (num % 2 == 0) {
                ++cnt[0];
                a[0] += num;
            }
        } else if (remainder == 1) {
            if (cnt[1] % 2 == 0)
                a[1] += num;
            else
                a[1] -= num;
            ++cnt[1];
        } else if (remainder == 2) {
            ++cnt[2];
            ++a[2];
        } else if (remainder == 3) {
            ++cnt[3];
            a[3] += num;
        } else // remainder == 4
        {
            cnt[4] = 1;
            if (num > a[4])
                a[4] = num;
        }
    }

    for (int i = 0; i < 5; ++i) {
        if (i)
            printf(" ");
        if (cnt[i]) {
            if (i == 3)
                printf("%.1f", static_cast<double>(a[i]) / cnt[i]);
            else
                printf("%d", a[i]);
        } else
            printf("N");
    }
}

namespace {
int win_1018(char a, char b) {
    if (a == b)
        return 0;
    if (a == 'C' && b == 'J' || a == 'J' && b == 'B' || a == 'B' && b == 'C')
        return 1;
    return -1;
}
} // namespace

void pat_b_1018() {
    const char arr[] = {'B', 'C', 'J'};

    int n;
    scanf("%d", &n);

    char a, b;
    int resultA[3] = {0};
    std::unordered_map<char, int> numA = {{'C', 0}, {'J', 0}, {'B', 0}};
    std::unordered_map<char, int> numB = {{'C', 0}, {'J', 0}, {'B', 0}};

    for (int i = 0; i < n; ++i) {
        getchar();
        scanf("%c %c", &a, &b);
        int result = win_1018(a, b);
        if (result == 1) {
            ++resultA[0];
            ++numA[a];
        } else if (result == 0)
            ++resultA[1];
        else {
            ++resultA[2];
            ++numB[b];
        }
    }

    printf("%d %d %d\n", resultA[0], resultA[1], resultA[2]);
    printf("%d %d %d\n", resultA[2], resultA[1], resultA[0]);

    int cA = 0, cB = 0;
    for (int i = 1; i < 3; ++i) {
        if (numA[arr[i]] > numA[arr[cA]])
            cA = i;
        if (numB[arr[i]] > numB[arr[cB]])
            cB = i;
    }

    printf("%c %c\n", arr[cA], arr[cB]);
}

void pat_a_1042() {
    const char strs[][5] = {
        "",    "S1",  "S2",  "S3",  "S4",  "S5",  "S6",  "S7",  "S8",  "S9",
        "S10", "S11", "S12", "S13", "H1",  "H2",  "H3",  "H4",  "H5",  "H6",
        "H7",  "H8",  "H9",  "H10", "H11", "H12", "H13", "C1",  "C2",  "C3",
        "C4",  "C5",  "C6",  "C7",  "C8",  "C9",  "C10", "C11", "C12", "C13",
        "D1",  "D2",  "D3",  "D4",  "D5",  "D6",  "D7",  "D8",  "D9",  "D10",
        "D11", "D12", "D13", "J1",  "J2",
    };
    int order[55];
    for (int i = 1; i < 55; ++i)
        order[i] = i;

    int k;
    scanf("%d", &k);

    int shuffleOrder[55];
    for (int i = 1; i < 55; ++i)
        scanf("%d", shuffleOrder + i);

    int tmpOrder[55];
    while (k--) {
        for (int i = 1; i < 55; ++i)
            tmpOrder[shuffleOrder[i]] = order[i];
        std::swap(order, tmpOrder);
    }

    for (int i = 1; i < 55; ++i) {
        if (i > 1)
            printf(" ");
        printf("%s", strs[order[i]]);
    }
}

namespace {
int shortest_1046(int arr[], int n, int totalDistance, int s, int e) {
    int dis = arr[e] - arr[s];
    return dis < totalDistance - dis ? dis : totalDistance - dis;
}
} // namespace

void pat_a_1046(int arr[]) {
    int n;
    scanf("%d", &n);
    int totalDistance = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", arr + i);
        totalDistance += arr[i];
        arr[i] += arr[i - 1];
    }

    int m, s, e;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &s, &e);
        --s;
        --e;
        if (s > e)
            std::swap(s, e);
        printf("%d\n", shortest_1046(arr, n, totalDistance, s, e));
    }
}

namespace {
bool judge_1065(long long a, long long b, long long c) {
    if (a >= 0 && b < 0 || a < 0 && b >= 0)
        return a + b > c;
    if (a >= 0 && c < 0 || a < 0 && c >= 0)
        return a >= 0;
    return a > c - b;
}
} // namespace

void pat_a_1065() {
    int n;
    scanf("%d", &n);
    long long a, b, c;
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld%lld", &a, &b, &c);
        if (judge_1065(a, b, c))
            printf("Case #%d: true\n", i + 1);
        else
            printf("Case #%d: false\n", i + 1);
    }
}

void pat_b_1010() {
    int a, b;
    int i = 0;

    while (scanf("%d%d", &a, &b) != EOF) // 或者读入一行
    {
        if (b == 0)
            continue;
        if (i)
            printf(" ");
        ++i;
        printf("%d %d", a * b, b - 1);
    }

    if (i == 0) // 零多项式：系数全为零的多项式
        printf("0 0");
}

void pat_a_1002() {
    const float eps = 1e-5;

    float arr[1001] = {0};
    int k, a;
    float b;

    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d%f", &a, &b);
        arr[a] = b;
    }

    int total = k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d%f", &a, &b);
        if (abs(arr[a]) < eps)
            ++total;
        arr[a] += b;
        if (abs(arr[a]) < eps)
            --total;
    }

    printf("%d", total);
    for (int i = 1000; i >= 0; --i)
        if (abs(arr[i]) > eps)
            printf(" %d %.1f", i, arr[i]);
}

void pat_a_1009() {
    const float eps = 1e-5;
    const int maxn = 2001;

    float arr1[maxn] = {0};
    float arr2[maxn] = {0};
    int k, a;
    float b;

    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d%f", &a, &b);
        arr1[a] = b;
    }

    int total = 0;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d%f", &a, &b);
        for (int j = 0; j < maxn; ++j)
            if (abs(arr1[j]) > eps) {
                int t = a + j;
                if (abs(arr2[t]) < eps)
                    ++total;
                arr2[t] += arr1[j] * b;
                if (abs(arr2[t]) < eps)
                    --total;
            }
    }

    printf("%d", total);
    for (int i = maxn - 1; i >= 0; --i)
        if (abs(arr2[i]) > eps)
            printf(" %d %.1f", i, arr2[i]);
}

void pat_b_1041() {
    std::unordered_map<int, std::pair<std::string, int>>
        map; // 数据量不大，可以直接用数组映射

    char license[20];
    int trial, real;

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%d", license, &trial, &real);
        map[trial] = {std::string(license), real};
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &trial);
        printf("%s %d\n", map[trial].first.c_str(), map[trial].second);
    }
}

void pat_b_1004() {
    char maxName[11], maxID[11], minName[11], minID[11];
    int maxScore = -1, minScore = 101;

    int n, score;
    scanf("%d", &n);

    char name[11], ID[11];
    for (int i = 0; i < n; ++i) {
        scanf("%s%s%d", name, ID, &score);
        if (score > maxScore) {
            maxScore = score;
            strcpy(maxName, name);
            strcpy(maxID, ID);
        }
        if (score < minScore) {
            minScore = score;
            strcpy(minName, name);
            strcpy(minID, ID);
        }
    }

    printf("%s %s\n", maxName, maxID);
    printf("%s %s\n", minName, minID);
}

void pat_b_1028() {
    const int limitYear = 2014 - 200;
    const int limitMonth = 9;
    const int limitDay = 6;
    const int nowYear = 2014;
    const int nowMonth = 9;
    const int nowDay = 6;

    char maxName[6], minName[6], name[6];
    int maxYear = -1, minYear = 2015;
    int maxMonth = -1, minMonth = 13;
    int maxDay = -1, minDay = 32;
    int year, month, day;
    int total = 0;

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d/%d/%d", name, &year, &month, &day);

        if ((year > limitYear || year == limitYear && month > limitMonth ||
             year == limitYear && month == limitMonth && day >= limitDay) &&
            (year < nowYear || year == nowYear && month < nowMonth ||
             year == nowYear && month == nowMonth && day <= nowDay))
            ++total;
        else
            continue;

        if (year > maxYear || year == maxYear && month > maxMonth ||
            year == maxYear && month == maxMonth && day > maxDay) {
            strcpy(maxName, name);
            maxYear = year;
            maxMonth = month;
            maxDay = day;
        }

        if (year < minYear || year == minYear && month < minMonth ||
            year == minYear && month == minMonth && day < minDay) {
            strcpy(minName, name);
            minYear = year;
            minMonth = month;
            minDay = day;
        }
    }

    if (total == 0) // 可能输入的日期都是不合理的
        printf("%d\n", total);
    else
        printf("%d %s %s\n", total, minName, maxName);
}

void pat_a_1011() {
    const char arr[] = {'W', 'T', 'L'};

    float wtl[3][3];
    char results[3];
    float profit = 1.0;
    for (int i = 0; i < 3; ++i) {
        scanf("%f%f%f", wtl[i], wtl[i] + 1, wtl[i] + 2);
        float *p = std::max_element(wtl[i], wtl[i] + 3);
        results[i] = arr[p - wtl[i]];
        profit *= *p;
    }

    printf("%c %c %c %.2f\n", results[0], results[1], results[2],
           ((profit * 0.65) - 1.0) * 2.0);
}

void pat_a_1006() {
    int n;
    scanf("%d", &n);

    int maxTime = -1, minTime = 24 * 60 * 60 + 1;
    int time, h, m, s;
    char maxName[16], minName[16], name[16];

    for (int i = 0; i < n; ++i) {
        scanf("%s", name);

        scanf("%d:%d:%d", &h, &m, &s);
        time = h * 60 * 60 + m * 60 + s;

        if (time < minTime) {
            minTime = time;
            strcpy(minName, name);
        }

        scanf("%d:%d:%d", &h, &m, &s);
        time = h * 60 * 60 + m * 60 + s;

        if (time > maxTime) {
            maxTime = time;
            strcpy(maxName, name);
        }
    }

    printf("%s %s\n", minName, maxName);
}

namespace {
struct Student_1036 {
    char name[11];
    char ID[11];
    char gender;
    int grade;
    Student_1036() : grade(-1) {}
    Student_1036(int grade) : grade(grade) {}
};
} // namespace

void pat_a_1036() {
    Student_1036 maxStudent(-1), minStudent(101), student;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%s %c%s%d", student.name, &student.gender, student.ID,
              &student.grade); // 接收字符之前加个空格
        if (student.gender == 'M') {
            if (student.grade < minStudent.grade)
                minStudent = student;
        } else {
            if (student.grade > maxStudent.grade)
                maxStudent = student;
        }
    }

    bool sign = true;

    if (maxStudent.grade == -1) {
        sign = false;
        printf("Absent\n");
    } else
        printf("%s %s\n", maxStudent.name, maxStudent.ID);

    if (minStudent.grade == 101) {
        sign = false;
        printf("Absent\n");
    } else
        printf("%s %s\n", minStudent.name, minStudent.ID);

    if (sign)
        printf("%d\n", maxStudent.grade - minStudent.grade);
    else
        printf("NA\n");
}

void pat_b_1036() {
    int n;
    char c;
    scanf("%d %c", &n, &c);

    int m = (n + 1) / 2;
    for (int i = 0; i < m; ++i) {
        if (i == 0 || i == m - 1) {
            for (int j = 0; j < n; ++j)
                printf("%c", c);
            printf("\n");
        } else {
            printf("%c", c);
            for (int j = 1; j < n - 1; ++j)
                printf(" ");
            printf("%c\n", c);
        }
    }
}

void pat_b_1027() {
    int n;
    char c;
    scanf("%d %c", &n, &c);

    int bottom = static_cast<int>(sqrt((n + 1) * 2)) - 1;
    if (bottom % 2 == 0) // 注意可能是偶数
        --bottom;
    int used = (bottom + 1) * (bottom + 1) / 2 - 1;

    for (int i = bottom; i > 0; i -= 2) {
        for (int j = 0; j < (bottom - i) / 2; ++j)
            printf(" ");
        for (int j = 0; j < i; ++j)
            printf("%c", c);
        printf("\n");
    }
    for (int i = 3; i <= bottom; i += 2) {
        for (int j = 0; j < (bottom - i) / 2; ++j)
            printf(" ");
        for (int j = 0; j < i; ++j)
            printf("%c", c);
        printf("\n");
    }

    printf("%d\n", n - used);
}

void pat_a_1031() {
    char str[100];
    scanf("%s", str);

    int n = strlen(str);
    int n1 = (n + 2) / 3;
    int n2 = n + 2 - n1 * 2;

    for (int i = 0; i < n1 - 1; ++i) {
        printf("%c", str[i]);
        for (int j = 0; j < n2 - 2; ++j)
            printf(" ");
        printf("%c", str[n - i - 1]);
        printf("\n");
    }

    for (int i = n1 - 1; i < n1 - 1 + n2; ++i)
        printf("%c", str[i]);

    printf("\n");
}

void pat_b_1022() {
    int a, b, base;
    scanf("%d%d%d", &a, &b, &base);

    int c = a + b;
    int i = 0;
    int arr[100];

    do // 用 while 语句则要特判 c = 0
    {
        arr[i++] = c % base;
        c /= base;
    } while (c);

    for (int j = i - 1; j >= 0; --j)
        printf("%d", arr[j]);
    printf("\n");
}

void pat_b_1037() {
    int g[3], s[3], k[3];
    int total[2];
    for (int i = 0; i < 2; ++i) {
        scanf("%d.%d.%d", g + i, s + i, k + i);
        total[i] = g[i] * 17 * 29 + s[i] * 29 + k[i];
    }

    int left = total[1] - total[0];
    bool minus = left < 0;
    left = left < 0 ? -left : left;

    g[2] = left / (17 * 29);
    left %= 17 * 29;
    s[2] = left / 29;
    left %= 29;
    k[2] = left;

    if (minus)
        printf("-");
    printf("%d.%d.%d\n", g[2], s[2], k[2]);
}

namespace {
struct Bit_a_1019 {
    int num;
    int exp;
    Bit_a_1019(int num = 0, int exp = 0) : num(num), exp(exp) {}
};
} // namespace

void pat_a_1019() {
    int n, b;
    scanf("%d%d", &n, &b);

    Bit_a_1019 bits[32];

    int index = 0;
    do {
        bits[index].num = n % b;
        bits[index].exp = index;
        n /= b;
        ++index;
    } while (n);

    bool result = true;
    for (int i = 0; i < index / 2; ++i)
        if (bits[i].num != bits[index - i - 1].num) {
            result = false;
            break;
        }

    printf(result ? "Yes\n" : "No\n");
    for (int i = index - 1; i >= 0; --i) {
        if (i < index - 1)
            printf(" ");
        printf("%d", bits[i].num);
    }
}

void pat_a_1027() {
    char bits[] = {'0', '1', '2', '3', '4', '5', '6',
                   '7', '8', '9', 'A', 'B', 'C'};
    int base = 13;
    int r, g, b;
    char resultR[2], resultG[2], resultB[2];
    scanf("%d%d%d", &r, &g, &b);

    resultR[1] = bits[r % base];
    resultR[0] = bits[r / base];
    resultG[1] = bits[g % base];
    resultG[0] = bits[g / base];
    resultB[1] = bits[b % base];
    resultB[0] = bits[b / base];

    printf("#%c%c%c%c%c%c\n", resultR[0], resultR[1], resultG[0], resultG[1],
           resultB[0], resultB[1]);
}

void pat_a_1058() {
    int a[3], b[3], c[3];
    scanf("%d.%d.%d", a, a + 1, a + 2);
    scanf("%d.%d.%d", b, b + 1, b + 2);
    int carry = 0;
    c[2] = (a[2] + b[2]) % 29;
    carry = (a[2] + b[2]) / 29;
    c[1] = (a[1] + b[1] + carry) % 17;
    carry = (a[1] + b[1] + carry) / 17;
    c[0] = a[0] + b[0] + carry;
    printf("%d.%d.%d", c[0], c[1], c[2]);
}

void pat_b_1009() {
    int num = 0;
    char strs[90][90];
    while (scanf("%s", strs[num]) != EOF) {
        num++;
    }
    for (int i = num - 1; i >= 0; --i) {
        printf("%s", strs[i]);
        if (i)
            printf(" ");
    }
}

void pat_b_1009_1() {
    char str[100];
    std::cin.getline(str, 100);

    int len = strlen(str);
    for (int i = 0; i < len; ++i)
        if (str[i] == ' ')
            str[i] = '\0';

    int i = len; // 不是 len - 1，带入 0、1 验证
    while (i--) {
        if (str[i] != '\0' && i)
            continue;
        printf(i ? "%s " : "%s", i ? str + i + 1 : str);
    }
    printf("\n");
}

void pat_b_1006() {
    int n;
    scanf("%d", &n);

    int numB = n / 100;
    n %= 100;
    int numS = n / 10;
    int numG = n %= 10;

    for (int i = 0; i < numB; ++i)
        printf("B");
    for (int i = 0; i < numS; ++i)
        printf("S");
    for (int i = 0; i < numG; ++i)
        printf("%d", i + 1);
}

void pat_b_1021(char str[]) {
    scanf("%s", str);

    int len = strlen(str);
    int arr[10] = {0};

    for (int i = 0; i < len; ++i)
        ++arr[str[i] - '0'];

    for (int i = 0; i < 10; ++i)
        if (arr[i])
            printf("%d:%d\n", i, arr[i]);
}

void pat_b_1031() {
    const int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    const char rear[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

    char str[100][19];
    int n;
    bool allPassed = true;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%s", *(str + i));
        int total = 0;
        bool sign = true;
        for (int j = 0; j < 17; ++j) {
            if (str[i][j] < '0' || str[i][j] > '9') {
                sign = false;
                break;
            }
            total += (str[i][j] - '0') * weight[j];
        }
        if (sign) {
            total %= 11;
            if (str[i][17] != rear[total])
                sign = false;
        }
        if (!sign) {
            allPassed = false;
            printf("%s\n", str[i]);
        }
    }

    if (allPassed)
        printf("All passed\n");
}

void pat_b_1002() {
    const char num[][5] = {"ling", "yi",  "er", "san", "si",
                           "wu",   "liu", "qi", "ba",  "jiu"};

    char str[101];
    scanf("%s", str);

    int len = strlen(str);
    int total = 0;
    while (len--)
        total += str[len] - '0';

    int idx = 0;
    int result[5];
    while (total) {
        result[idx++] = total % 10;
        total /= 10;
    }

    for (int i = idx - 1; i >= 0; --i) {
        printf("%s", num[result[i] - 0]);
        if (i)
            printf(" ");
    }
}

void pat_b_1014() { pat_a_1061(); }

void pat_a_1061() {
    const char day[][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    char str[4][61];
    int len[4];

    for (int i = 0; i < 4; ++i) {
        scanf("%s", *(str + i));
        len[i] = strlen(str[i]);
    }

    char same[3] = {0};
    for (int i = 0; i < len[0]; ++i) {
        if (!same[0] && (str[0][i] < 'A' || str[0][i] > 'G') ||
            same[0] && (str[0][i] < '0' || str[0][i] > '9') &&
                (str[0][i] < 'A' || str[0][i] > 'N'))
            continue;
        if (str[0][i] == str[1][i]) {
            if (!same[0])
                same[0] = str[0][i];
            else {
                same[1] = str[0][i];
                break;
            }
        }
    }

    for (int i = 0; i < len[2]; ++i) {
        if ((str[2][i] < 'a' || str[2][i] > 'z') &&
            (str[2][i] < 'A' || str[2][i] > 'Z'))
            continue;
        if (str[2][i] == str[3][i]) {
            same[2] = i;
            break;
        }
    }

    int h = same[1] - '0';
    if (same[1] >= 'A' && same[1] <= 'N')
        h = 10 + same[1] - 'A';

    printf("%s %02d:%02d", day[same[0] - 'A'], h, same[2]);
}

void pat_a_1073() {
    char str[10000];
    scanf("%s", str);

    int len = strlen(str);

    bool firstSign, secondSign;
    int index = 0;
    int num[10000];
    int exp = 0;

    for (int i = 0, sign = 0; i < len; ++i)
        if (sign == 0) {
            firstSign = str[i] == '+';
            ++sign;
        } else if (sign == 1) {
            if (str[i] < '0' || str[i] > '9') {
                if (str[i] == '+' || str[i] == '-') {
                    secondSign = str[i] == '+';
                    ++sign;
                }
                continue;
            }
            num[index++] = str[i] - '0';
        } else {
            exp *= 10;
            exp += str[i] - '0';
        }

    int dotIndex = 1;

    if (!firstSign)
        printf("-");
    if (secondSign)
        dotIndex += exp;
    else
        dotIndex -= exp;

    if (dotIndex <= 0) {
        printf("0.");
        for (int i = 0; i < -dotIndex; ++i)
            printf("0");
    }
    for (int i = 0; i < index; ++i) {
        if (i == dotIndex)
            printf(".");
        printf("%d", num[i]);
    }
    if (dotIndex >= index) {
        for (int i = 0; i < dotIndex - index; ++i)
            printf("0");
    }
}

void pat_b_1024() { pat_a_1073(); }

void pat_b_1048() {
    const char jqk[] = {'J', 'Q', 'K'};

    char a[101], b[101];
    scanf("%s%s", a, b);

    int lenA = strlen(a);
    int lenB = strlen(b);

    if (lenB < lenA) // b 比 a 短，高位要补 0
    {
        std::reverse(b, b + lenB); // 不 reverse 会补到低位！
        for (int i = lenB; i < lenA; ++i)
            b[i] = '0';
        lenB = lenA;
        std::reverse(b, b + lenB);
    }

    for (int i = lenB - 1, j = lenA - 1; i >= 0 && j >= 0; --i, --j) {
        int numA = a[j] - '0';
        int numB = b[i] - '0';

        if ((lenB - i) % 2) {
            int t = (numB + numA) % 13;
            if (t < 10)
                b[i] = '0' + t;
            else
                b[i] = jqk[t - 10];
        } else {
            int t = numB - numA;
            if (t < 0)
                t += 10;
            b[i] = '0' + t;
        }
    }

    for (int i = 0; i < lenB; ++i)
        printf("%c", b[i]);
}

void pat_a_1001() {
    int a, b, c;
    scanf("%d%d", &a, &b);
    c = a + b;
    if (c < 0) {
        printf("-");
        c = -c;
    }

    int i = 0, j = 0;
    char num[15];
    do {
        if (i && i % 3 == 0)
            num[j++] = ',';
        num[j++] = '0' + c % 10;
        ++i;
        c /= 10;
    } while (c);

    for (int i = j - 1; i >= 0; --i)
        printf("%c", num[i]);
    printf("\n");
}

void pat_a_1005() {
    const char numStrArr[][6] = {"zero", "one", "two",   "three", "four",
                                 "five", "six", "seven", "eight", "nine"};
    char str[101];
    scanf("%s", str);

    int len = strlen(str);
    int total = 0;
    for (int i = 0; i < len; ++i)
        total += str[i] - '0';

    int idx = 0;
    int numArr[3];
    do {
        numArr[idx++] = total % 10;
        total /= 10;
    } while (total);

    for (int i = idx - 1; i >= 0; --i) {
        printf("%s", numStrArr[numArr[i]]);
        if (i)
            printf(" ");
    }
    printf("\n");
}

void pat_a_1035() {
    const int maxn = 1000;

    int n;
    scanf("%d", &n);

    char name[maxn][11];
    char pwd[maxn][11];

    int changed[maxn] = {0};
    int changedNum = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%s%s", *(name + i), *(pwd + i));
        int len = strlen(pwd[i]);
        bool sign = false;
        for (int j = 0; j < len; ++j) {
            char &c = pwd[i][j];
            if (c != '1' && c != '0' && c != 'l' && c != 'O')
                continue;
            sign = true;
            if (c == '1')
                c = '@';
            else if (c == '0')
                c = '%';
            else if (c == 'l')
                c = 'L';
            else
                c = 'o';
        }
        if (sign) {
            changed[i] = 1;
            ++changedNum;
        }
    }

    if (!changedNum)
        printf("There %s %d %s and no account is modified\n",
               n > 1 ? "are" : "is", n, n > 1 ? "accounts" : "account");
    else {
        printf("%d\n", changedNum);
        for (int i = 0; i < n; ++i)
            if (changed[i])
                printf("%s %s\n", name[i], pwd[i]);
    }
}

void pat_a_1077() {
    const int maxn = 100;
    const int maxStrLen = 300;

    char strs[maxn][maxStrLen];
    int len[maxn];
    int n;
    scanf("%d", &n);

    getchar();
    for (int i = 0; i < n; ++i) {
        std::cin.getline(strs[i], maxStrLen);
        len[i] = strlen(strs[i]);
    }

    int idx = 0;
    char common[maxStrLen] = "";

    for (int i = 1;; ++i) {
        int sign = 0;
        char c = 0;
        for (int j = 0; j < n; ++j) {
            int k = len[j] - i;
            if (k < 0 || c != 0 && strs[j][k] != c) {
                sign = 1;
                break;
            }
            if (!c)
                c = strs[j][k];
        }
        if (!sign)
            common[idx++] = c;
        else
            break;
    }

    if (idx == 0)
        printf("nai");
    else {
        // while (common[idx - 1] == ' ')
        // --idx;
        for (int i = idx - 1; i >= 0; --i)
            printf("%c", common[i]);
    }
    printf("\n");
}

namespace {
void printNum_1082(int n, const char num[][5]) {
    if (n / 1000)
        printf("%s Qian", num[n / 1000]);
    if (n / 1000 && (n % 1000) && (n % 1000) < 100)
        printf(" %s", num[0]);
    if (n % 1000 / 100) {
        if (n / 1000)
            printf(" ");
        printf("%s Bai", num[n % 1000 / 100]);
    }
    if (n % 1000 / 100 && n % 100 && n % 100 < 10)
        printf(" %s", num[0]);
    if (n % 100 / 10) {
        if (n > 100)
            printf(" ");
        printf("%s Shi", num[n % 100 / 10]);
    }
    if (n % 10) {
        if (n > 10)
            printf(" ");
        printf("%s", num[n % 10]);
    }
};
} // namespace

void pat_a_1082() {
    const char num[][5] = {"ling", "yi",  "er", "san", "si",
                           "wu",   "liu", "qi", "ba",  "jiu"};

    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("%s\n", num[0]);
        return;
    }
    if (n < 0) {
        printf("Fu ");
        n = -n;
    }

    int yiNum = n / 100000000;
    int wanNum = n / 10000 % 10000;
    int geNum = n % 10000;

    if (yiNum)
        printf("%s Yi", num[yiNum]);
    if (yiNum && wanNum && wanNum < 1000)
        printf(" %s", num[0]);
    if (yiNum && wanNum)
        printf(" ");
    if (wanNum) {
        printNum_1082(wanNum, num);
        printf(" Wan");
    }
    if (wanNum && wanNum % 10 == 0 && geNum ||
        geNum && geNum < 1000) // 100008000 读作 一亿八千
        printf(" %s", num[0]);
    if (yiNum || wanNum)
        printf(" ");
    printNum_1082(geNum, num);
}

void pat_a_1082_1() {
    const char num[][5] = {"ling", "yi",  "er", "san", "si",
                           "wu",   "liu", "qi", "ba",  "jiu"};
    const char wei[][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};

    char str[15];
    scanf("%s", str);

    int len = strlen(str);
    int left = 0, right = len - 1;

    if (str[0] == '-') {
        printf("Fu");
        ++left;
    }

    while (left + 4 <= right)
        right -= 4;

    while (left < len) {
        bool flag = false;
        bool isPrinted = false;
        while (left <= right) {
            int n = str[left] - '0';
            if (left && n == 0) // left 条件是为了应对 str 为 "0" 的情况
                flag = true;
            else {
                if (flag) {
                    printf(" %s", num[0]);
                    flag = false;
                }
                if (left)
                    printf(" ");
                printf("%s", num[n]);
                isPrinted = true;
                if (left < right)
                    printf(" %s", wei[right - left - 1]);
            }
            ++left;
        }
        if (isPrinted && right != len - 1) // 不是个位
            printf(" %s", wei[(len - left) / 4 + 2]);
        right += 4;
    }
}

namespace {
struct Testee {
    char name[14];
    int score;
    int rank;
    int localRank;
    int room;
};
} // namespace

void pat_a_1025() {
    Testee testees[30000];

    int n, k;
    scanf("%d", &n);

    int idx = 0;
    int room = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            scanf("%s%d", testees[idx].name, &testees[idx].score);
            testees[idx].room = room;
            ++idx;
        }
        ++room;

        std::sort(testees + idx - k, testees + idx,
                  [](const auto &a, const auto &b) {
                      if (a.score == b.score)
                          return strcmp(a.name, b.name) < 0;
                      return a.score > b.score;
                  });

        int num = 0;
        for (auto it = testees + idx - k; it < testees + idx; ++it) {
            ++num;
            if (it == testees + idx - k)
                it->localRank = 1;
            else {
                if (it->score == (it - 1)->score)
                    it->localRank = (it - 1)->localRank;
                else
                    it->localRank = num;
            }
        }
    }

    std::sort(testees, testees + idx, [](const auto &a, const auto &b) {
        if (a.score == b.score)
            return strcmp(a.name, b.name) < 0;
        return a.score > b.score;
    });

    int num = 0;
    for (auto it = testees; it < testees + idx; ++it) {
        ++num;
        if (it == testees)
            it->rank = 1;
        else {
            if (it->score == (it - 1)->score)
                it->rank = (it - 1)->rank;
            else
                it->rank = num;
        }
    }

    printf("%d\n", idx);
    for (auto it = testees; it < testees + idx; ++it)
        printf("%s %d %d %d\n", it->name, it->rank, it->room, it->localRank);
}

namespace {
struct Person_1062 {
    int id;
    int virtue;
    int talent;
    int sort;
};
} // namespace

void pat_a_1062() {
    Person_1062 people[100000];

    int n, l, h;
    scanf("%d%d%d", &n, &l, &h);

    int total = 0;
    int id, virtue, talent;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &id, &virtue, &talent);
        if (talent < l || virtue < l)
            continue;
        people[total].id = id;
        people[total].virtue = virtue;
        people[total].talent = talent;

        if (virtue >= h && talent >= h)
            people[total].sort = virtue + talent + 900;
        else if (virtue >= h && talent < h)
            people[total].sort = virtue + talent + 600;
        else if (virtue < h && talent < h && virtue >= talent)
            people[total].sort = virtue + talent + 300;
        else
            people[total].sort = virtue + talent;

        ++total;
    }

    std::sort(people, people + total, [](const auto &a, const auto &b) {
        if (a.sort == b.sort) {
            if (a.virtue == b.virtue)
                return a.id < b.id;
            return a.virtue > b.virtue;
        }
        return a.sort > b.sort;
    });

    printf("%d\n", total);
    for (int i = 0; i < total; ++i)
        printf("%d %d %d\n", people[i].id, people[i].virtue, people[i].talent);
}

void pat_b_1015() { pat_a_1062(); }

namespace {
struct Student_1012 {
    int id;
    int C, M, E, A;
    int rankC, rankM, rankE, rankA;
};
} // namespace

void pat_a_1012() {
    Student_1012 students[2000];
    std::unordered_map<int, int> map;

    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        auto &it = students[i];
        scanf("%d%d%d%d", &it.id, &it.C, &it.M, &it.E);
        it.A = it.C + it.M + it.E;
    }

    std::sort(students, students + n,
              [](const auto &a, const auto &b) { return a.C > b.C; });
    students[0].rankC = 1;
    for (int i = 1; i < n; ++i) {
        if (students[i].C == students[i - 1].C)
            students[i].rankC = students[i - 1].rankC;
        else
            students[i].rankC = i + 1;
    }
    std::sort(students, students + n,
              [](const auto &a, const auto &b) { return a.M > b.M; });
    students[0].rankM = 1;
    for (int i = 1; i < n; ++i) {
        if (students[i].M == students[i - 1].M)
            students[i].rankM = students[i - 1].rankM;
        else
            students[i].rankM = i + 1;
    }
    std::sort(students, students + n,
              [](const auto &a, const auto &b) { return a.E > b.E; });
    students[0].rankE = 1;
    for (int i = 0; i < n; ++i) {
        if (students[i].E == students[i - 1].E)
            students[i].rankE = students[i - 1].rankE;
        else
            students[i].rankE = i + 1;
    }
    std::sort(students, students + n,
              [](const auto &a, const auto &b) { return a.A > b.A; });
    students[0].rankA = 1;
    for (int i = 0; i < n; ++i) {
        if (students[i].A == students[i - 1].A)
            students[i].rankA = students[i - 1].rankA;
        else
            students[i].rankA = i + 1;
    }

    for (int i = 0; i < n; ++i)
        map[students[i].id] = i;

    int id;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &id);
        if (map.find(id) == map.end())
            printf("N/A\n");
        else {
            Student_1012 &s = students[map[id]];
            if (s.rankA <= s.rankC && s.rankA <= s.rankM && s.rankA <= s.rankE)
                printf("%d A\n", s.rankA);
            else if (s.rankC <= s.rankA && s.rankC <= s.rankM &&
                     s.rankC <= s.rankE)
                printf("%d C\n", s.rankC);
            else if (s.rankM <= s.rankA && s.rankM <= s.rankC &&
                     s.rankM <= s.rankE)
                printf("%d M\n", s.rankM);
            else
                printf("%d E\n", s.rankE);
        }
    }
}

namespace {
struct Date_1016 {
    int M, d, h, m;
    Date_1016(int M = 0, int d = 0, int h = 0, int m = 0)
        : M(M), d(d), h(h), m(m) {}
};

struct Customer_1016 {
    char name[21];
    std::vector<std::pair<Date_1016, Date_1016>> records;
    Customer_1016() {}
    Customer_1016(const char str[]) { strcpy(name, str); }
};

struct Item_1016 {
    char name[21];
    char state[9];
    Date_1016 date;
};
} // namespace

void pat_a_1016() {
    int hourFee[24] = {0};

    for (int i = 0; i < 24; ++i)
        scanf("%d", hourFee + i);

    std::unordered_map<std::string, Customer_1016> map;
    std::unordered_map<std::string, Date_1016> mapOnLine;

    int n;
    scanf("%d", &n);

    std::vector<Item_1016> items;
    char name[21];
    char state[9];
    int M, d, h, m; // 所有输入中 M 月份相同

    for (int i = 0; i < n; ++i) {
        scanf("%s %d:%d:%d:%d %s", name, &M, &d, &h, &m, state);
        Item_1016 item;
        strcpy(item.name, name);
        strcpy(item.state, state);
        item.date = Date_1016(M, d, h, m);
        items.push_back(item);
    }

    std::sort(items.begin(), items.end(), [](const auto &a, const auto &b) {
        if (a.date.M != b.date.M)
            return a.date.M < b.date.M;
        else if (a.date.d != b.date.d)
            return a.date.d < b.date.d;
        else if (a.date.h != b.date.h)
            return a.date.h < b.date.h;
        else
            return a.date.m < b.date.m;
    });

    for (int i = 0; i < n; ++i) {
        strcpy(name, items[i].name);
        strcpy(state, items[i].state);
        M = items[i].date.M;
        d = items[i].date.d;
        h = items[i].date.h;
        m = items[i].date.m;

        std::string key = name;

        if (map.find(key) == map.end())
            map[key] = Customer_1016(key.c_str());

        if (strcmp(state, "on-line") == 0)
            mapOnLine[key] = Date_1016(M, d, h, m);
        else // off-line
        {
            if (mapOnLine.find(key) != mapOnLine.end()) {
                map[key].records.push_back(
                    {mapOnLine[key], Date_1016(M, d, h, m)});
                mapOnLine.erase(mapOnLine.find(key));
            }
        }
    }

    std::vector<std::string> vec;
    for (auto it = map.begin(); it != map.end(); ++it)
        vec.push_back(it->first);

    std::sort(vec.begin(), vec.end(),
              [](const auto &a, const auto &b) { return a < b; });

    for (const auto &it : vec) {
        Customer_1016 &c = map[it];

        float totalAmount = 0.0;

        if (c.records.empty()) // 不存在有效通话记录的用户不输出！
            continue;
        printf("%s %02d\n", c.name, M);

        for (const auto &[first, second] : c.records) {
            int beginD = first.d, beginH = first.h, beginM = first.m;
            int endD = second.d, endH = second.h, endM = second.m;

            int minutes = 0;
            float amount = 0.0;

            while (beginD < endD ||
                   beginD == endD &&
                       (beginH < endH || beginH == endH && beginM < endM)) {
                ++minutes;
                amount += hourFee[beginH];

                ++beginM;
                if (beginM == 60) {
                    beginM = 0;
                    ++beginH;
                    if (beginH == 24) {
                        beginH = 0;
                        ++beginD;
                    }
                }
            }

            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", first.d, first.h,
                   first.m, second.d, second.h, second.m, minutes,
                   amount / 100.0);
            totalAmount += amount / 100.0;
        }

        printf("Total amount: $%.2f\n", totalAmount);
    }
}

namespace {
struct Student_1028 {
    int ID;
    char name[9];
    int grade;
};
} // namespace

void pat_a_1028() {
    Student_1028 students[100000];

    int n, c;
    scanf("%d%d", &n, &c);

    for (int i = 0; i < n; ++i) {
        auto &stu = students[i];
        scanf("%d%s%d", &stu.ID, stu.name, &stu.grade);
    }

    if (c == 1) {
        std::sort(students, students + n,
                  [](const auto &a, const auto &b) { return a.ID < b.ID; });
    } else if (c == 2) {
        std::sort(students, students + n, [](const auto &a, const auto &b) {
            int result = strcmp(a.name, b.name);
            if (result == 0)
                return a.ID < b.ID;
            return result < 0;
        });
    } else // c == 3
    {
        std::sort(students, students + n, [](const auto &a, const auto &b) {
            if (a.grade == b.grade)
                return a.ID < b.ID;
            return a.grade < b.grade;
        });
    }

    for (int i = 0; i < n; ++i) {
        auto &stu = students[i];
        printf("%06d %s %d\n", stu.ID, stu.name, stu.grade);
    }
}

namespace {
struct Person_1055 {
    char name[9];
    int age;
    int worth;
};
} // namespace

void pat_a_1055() {
    Person_1055 people[100000];

    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i) {
        auto &p = people[i];
        scanf("%s%d%d", p.name, &p.age, &p.worth);
    }

    std::sort(people, people + n, [](const auto &a, const auto &b) {
        if (a.worth == b.worth) {
            if (a.age == b.age)
                return strcmp(a.name, b.name) < 0;
            return a.age < b.age;
        }
        return a.worth > b.worth;
    });

    int m, mi, ma;
    for (int i = 0; i < k; ++i) {
        scanf("%d%d%d", &m, &mi, &ma);

        printf("Case #%d:\n", i + 1);
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (cnt >= m)
                break;
            auto &p = people[j];
            if (p.age >= mi && p.age <= ma) {
                ++cnt;
                printf("%s %d %d\n", p.name, p.age, p.worth);
            }
        }
        if (!cnt)
            printf("None\n");
    }
}

namespace {
struct User_1075 {
    int ID;
    int sort;
    int rank;
    int sum;
    int score[5];

    // 可统一为一个是否有通过编译的提交的标记
    bool subFlag[5];  // 提交标记
    bool passFlag[5]; // 通过编译标记

    User_1075() : ID(0), sort(0), rank(0), sum(0) {
        memset(score, 0, sizeof(score));
        memset(subFlag, 0, sizeof(subFlag));
        memset(passFlag, 0, sizeof(passFlag));
    }
};
} // namespace

void pat_a_1075() {
    User_1075 users[10000];
    int score[5];

    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);

    for (int i = 0; i < k; ++i)
        scanf("%d", score + i);

    int ID, p, s;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &ID, &p, &s);
        auto &u = users[ID - 1];

        u.ID = ID;
        if (!u.subFlag[p - 1]) {
            u.subFlag[p - 1] = true;
            if (s == -1) {
                u.passFlag[p - 1] = false;
                u.score[p - 1] = 0;
            } else {
                u.passFlag[p - 1] = true;
                u.score[p - 1] = s;
            }
        } else {
            if (s >= u.score[p - 1]) // 编译通过的 0 分和没通过编译的 0 分相等
            {
                u.passFlag[p - 1] = true;
                u.score[p - 1] = s;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        auto &u = users[i];
        int sign = false;
        for (int j = 0; j < k; ++j)
            if (u.subFlag[j] && u.passFlag[j]) {
                sign = true;
                break;
            }
        if (!sign)
            u.sort = -1;
        else {
            u.sum = std::accumulate(u.score, u.score + k, 0);
            u.sort = std::accumulate(u.score, u.score + k, 0);
            u.sort *= 10;
            for (int j = 0; j < k; ++j)
                if (u.score[j] == score[j])
                    u.sort += 1;
            ++cnt;
        }
    }

    std::sort(users, users + n, [](const auto &a, const auto &b) {
        if (a.sort == b.sort)
            return a.ID < b.ID;
        return a.sort > b.sort;
    });

    users[0].rank = 1;
    for (int i = 1; i < cnt; ++i) {
        if (users[i].sum == users[i - 1].sum)
            users[i].rank = users[i - 1].rank;
        else
            users[i].rank = i + 1;
    }

    for (int i = 0; i < cnt; ++i) {
        auto &u = users[i];
        printf("%d %05d", u.rank, u.ID);
        printf(" %d", u.sum);
        for (int j = 0; j < k; ++j) {
            if (u.subFlag[j])
                printf(" %d", u.score[j]);
            else
                printf(" -");
        }
        printf("\n");
    }
}

namespace {
struct Student_1083 {
    char name[11], ID[11];
    int grade;
};
} // namespace

void pat_a_1083() {
    Student_1083 students[1000];

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        auto &stu = students[i];
        scanf("%s%s%d", stu.name, stu.ID, &stu.grade);
    }

    std::sort(students, students + n,
              [](const auto &a, const auto &b) { return a.grade > b.grade; });

    int mi, ma;
    scanf("%d%d", &mi, &ma);

    int flag = false;
    for (int i = 0; i < n; ++i) {
        auto &stu = students[i];
        if (stu.grade >= mi && stu.grade <= ma) {
            flag = true;
            printf("%s %s\n", stu.name, stu.ID);
        }
    }
    if (!flag)
        printf("NONE\n");
}

namespace {
struct Student_1080 {
    int ID;
    int ge, gi, sum;
    int choices[5];
    int rank;
};
} // namespace

void pat_a_1080() {
    Student_1080 students[40000];
    int quota[100];

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; ++i)
        scanf("%d", quota + i);

    for (int i = 0; i < n; ++i) {
        auto &stu = students[i];
        scanf("%d%d", &stu.ge, &stu.gi);
        stu.sum = stu.ge + stu.gi;
        stu.ID = i;

        for (int j = 0; j < k; ++j)
            scanf("%d", &stu.choices[j]);
    }

    std::sort(students, students + n, [](const auto &a, const auto &b) {
        if (a.sum == b.sum)
            return a.ge > b.ge;
        return a.sum > b.sum;
    });

    students[0].rank = 1;
    for (int i = 1; i < n; ++i) {
        auto &stu = students[i];
        auto &preStu = students[i - 1];
        if (stu.sum == preStu.sum && stu.ge == preStu.ge)
            stu.rank = preStu.rank;
        else
            stu.rank = i + 1;
    }

    std::vector<int> vec[100];
    for (int i = 0; i < n; ++i) {
        auto &stu = students[i];
        for (int j = 0; j < k; ++j) {
            int choice = stu.choices[j];
            if (vec[choice].size() < quota[choice] ||
                students[vec[choice].back()].rank == stu.rank) {
                vec[choice].push_back(i);
                break;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        std::sort(vec[i].begin(), vec[i].end(),
                  [&](const auto &a, const auto &b) {
                      return students[a].ID < students[b].ID;
                  });
        for (int j = 0; j < vec[i].size(); ++j) {
            if (j)
                printf(" ");
            printf("%d", students[vec[i][j]].ID);
        }
        printf("\n");
    }
}

namespace {
struct Car_1095 {
    char plate[8];
    int time;
    bool flag; // false: in, true: out
    bool valid;
    Car_1095() {}
    Car_1095(const char str[], int time, bool flag, bool valid)
        : time(time), flag(flag), valid(valid) {
        strcpy(plate, str);
    }
};
} // namespace

void pat_a_1095() {
    Car_1095 cars[10000];

    int n, k;
    scanf("%d%d", &n, &k);

    int h, m, s;
    bool flag;
    char status[4];
    for (int i = 0; i < n; ++i) {
        scanf("%s%d:%d:%d%s", cars[i].plate, &h, &m, &s, status);

        cars[i].time = h * 60 * 60 + m * 60 + s;
        cars[i].flag = strcmp(status, "out") == 0;
        cars[i].valid = true;
    }

    std::sort(cars, cars + n,
              [](const auto &a, const auto &b) { return a.time < b.time; });

    std::map<std::string, Car_1095 *> map;
    std::map<std::string, int> mapDuration;
    std::vector<std::string> result;
    int maxDuration = -1;

    for (int i = 0; i < n; ++i) {
        auto &car = cars[i];
        if (!car.flag) // in
        {
            if (map.find(car.plate) != map.end())
                map[car.plate]->valid = false;
            map[car.plate] = &car;
        } else // out
        {
            if (map.find(car.plate) != map.end()) {
                int duration = car.time - map[car.plate]->time;

                if (mapDuration.find(car.plate) == mapDuration.end())
                    mapDuration[car.plate] = duration;
                else
                    mapDuration[car.plate] += duration;

                if (mapDuration[car.plate] > maxDuration) {
                    maxDuration = mapDuration[car.plate];
                    result.clear();
                    result.push_back(car.plate);
                } else if (mapDuration[car.plate] == maxDuration)
                    result.push_back(car.plate);

                map.erase(map.find(car.plate));
            } else
                car.valid = false;
        }
    }
    for (const auto &[s, p] : map)
        p->valid = false;

    int queries[80000];
    for (
        int i = 0; i < k;
        ++i) // 可以在输入的同时遍历所有车辆，每次遍历从上次遍历结束的位置继续，参考答案见辅导书
    {
        scanf("%d:%d:%d", &h, &m, &s);
        queries[i] = h * 60 * 60 + m * 60 + s;
    }

    int num = 0;
    int queryIdx = 0;

    for (int i = 0; i < n; ++i) {
        auto &car = cars[i];

        if (!car.valid)
            continue;

        int queryTime = queries[queryIdx];

        if (car.time > queryTime) {
            printf("%d\n", num);
            if (++queryIdx == k)
                break;
            --i;
            continue;
        }

        if (!car.flag) // in
            ++num;
        else // out
            --num;
    }
    for (int i = queryIdx; i < k; ++i) // 别漏了这里！
        printf("%d\n", num);

    std::sort(result.begin(), result.end());
    for (const auto &plate : result)
        printf("%s ", plate.c_str());
    printf("%02d:%02d:%02d\n", maxDuration / (60 * 60),
           maxDuration % (60 * 60) / 60, maxDuration % 60);
}

void pat_a_1084() {
    char str1[80], str2[80];
    scanf("%s%s", str1, str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    std::vector<char> result;

    int map[256] = {0};

    for (int i = 0; i < len2; ++i) {
        str2[i] = std::toupper(str2[i]);
        map[str2[i]] = 1;
    }
    for (int i = 0; i < len1; ++i) {
        str1[i] = std::toupper(str1[i]);
        if (!map[str1[i]]) {
            map[str1[i]] = 1; // 避免重复加入
            result.push_back(str1[i]);
        }
    }

    for (int i = 0; i < result.size(); ++i)
        printf("%c", result[i]);
    printf("\n");
}

void pat_b_1029() { pat_a_1084(); }

void pat_b_1033() {
    char str1[100001], str2[100001];

    std::cin.getline(str1, 100001); // 第一行可能为空，所以要 getline！
    std::cin.getline(str2, 100001);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int arr[256] = {0};
    for (int i = 0; i < len1; ++i)
        arr[str1[i]] = 1;

    for (int i = 0; i < len2; ++i) {
        if (arr[std::toupper(str2[i])] ||
            arr['+'] && str2[i] >= 'A' && str2[i] <= 'Z')
            continue;
        printf("%c", str2[i]);
    }
    printf("\n");
}

void pat_b_1038() {
    int n, t;
    int score[100] = {0};

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        ++score[t];
    }

    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &t);
        if (i)
            printf(" ");
        printf("%d", score[t]);
    }
}

void pat_a_1092() {
    char str1[1001], str2[1001];

    std::cin.getline(str1, 1001);
    std::cin.getline(str2, 1001);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int arr[256] = {0};
    for (int i = 0; i < len1; ++i)
        ++arr[str1[i]];

    bool sign = true;
    int left = 0;
    for (int i = 0; i < len2; ++i) {
        if (arr[str2[i]] == 0) {
            sign = false;
            ++left;
        } else
            --arr[str2[i]];
    }

    if (sign)
        printf("Yes %d\n", len1 - len2);
    else
        printf("No %d\n", left);
}

void pat_b_1039() { pat_a_1092(); }

void pat_b_1042() {
    char str[1001];
    std::cin.getline(str, 1001);

    int len = strlen(str);
    int freq[256] = {0};
    for (int i = 0; i < len; ++i)
        ++freq[std::tolower(str[i])];

    int maxFreq = -1;
    char c;
    for (int i = 0; i < 256; ++i)
        if (i >= 'a' && i <= 'z' && freq[i] > maxFreq) {
            maxFreq = freq[i];
            c = i;
        }
    printf("%c %d\n", c, maxFreq);
}

void pat_b_1043() {
    char str[10001];
    std::cin.getline(str, 10001);

    int len = strlen(str);
    std::map<char, int> map;
    map['P'] = 0;
    map['A'] = 0;
    map['T'] = 0;
    map['e'] = 0;
    map['s'] = 0;
    map['t'] = 0;
    for (int i = 0; i < len; ++i)
        if (map.find(str[i]) != map.end())
            ++map[str[i]];

    while (map['P'] + map['A'] + map['T'] + map['e'] + map['s'] + map['t']) {
        if (map['P']) {
            printf("P");
            --map['P'];
        }
        if (map['A']) {
            printf("A");
            --map['A'];
        }
        if (map['T']) {
            printf("T");
            --map['T'];
        }
        if (map['e']) {
            printf("e");
            --map['e'];
        }
        if (map['s']) {
            printf("s");
            --map['s'];
        }
        if (map['t']) {
            printf("t");
            --map['t'];
        }
    }
    printf("\n");
}

void pat_b_1047() {
    int n;
    scanf("%d", &n);

    int totalScore[1001] = {0};
    int team, crew, score;
    for (int i = 0; i < n; ++i) {
        scanf("%d-%d%d", &team, &crew, &score);
        totalScore[team] += score;
    }

    int *p = std::max_element(totalScore, totalScore + 1001);
    printf("%d %d\n", static_cast<int>(p - totalScore), *p);
}

void pat_a_1041() {
    int arr[100000];
    int map[10001] = {0};

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        ++map[arr[i]];
    }

    bool sign = false;
    for (int i = 0; i < n; ++i)
        if (map[arr[i]] == 1) {
            printf("%d\n", arr[i]);
            sign = true;
            break;
        }
    if (!sign)
        printf("None\n");
}

void pat_a_1050() {
    const int maxn = 10001;
    char str1[maxn], str2[maxn];

    char map[256] = {0};

    std::cin.getline(str1, maxn);
    std::cin.getline(str2, maxn);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (int i = 0; i < len2; ++i)
        map[str2[i]] = 1;

    for (int i = 0; i < len1; ++i)
        if (!map[str1[i]])
            printf("%c", str1[i]);
    printf("\n");
}

namespace {
void judge_1005(int num, int map[]) {
    while (num != 1) {
        if (num % 2)
            num = (3 * num + 1) / 2;
        else
            num /= 2;
        ++map[num];
    }
}
} // namespace

void pat_b_1005() {
    int arr[100];
    int map[10000] = {0}; // 101、1000 不通过

    int k;
    scanf("%d", &k);

    for (int i = 0; i < k; ++i) {
        scanf("%d", &arr[i]);
        judge_1005(arr[i], map);
    }

    std::vector<int> result;
    for (int i = 0; i < k; ++i)
        if (!map[arr[i]])
            result.push_back(arr[i]);

    std::sort(result.begin(), result.end(), std::greater<int>());
    for (int i = 0; i < result.size(); ++i) {
        if (i)
            printf(" ");
        printf("%d", result[i]);
    }
}

void pat_a_1048() // 散列表
{
    int n, m;
    scanf("%d%d", &n, &m);

    int arr[100000];
    int map[1000] = {0}; // 不能只开 500，否则会段错误
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        ++map[arr[i]];
    }

    std::sort(arr, arr + n);

    int v1 = 0;
    int v2 = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] < m && map[m - arr[i]] &&
            (arr[i] != m - arr[i] || map[arr[i]] > 1)) {
            v1 = arr[i];
            v2 = m - arr[i];
            break;
        }

    if (v1 && v2)
        printf("%d %d\n", v1, v2);
    else
        printf("No Solution\n");
}

void pat_a_1048_1() // 双指针
{
    int n, m;
    scanf("%d%d", &n, &m);

    int arr[100000];
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    std::sort(arr, arr + n);

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int total = arr[left] + arr[right];
        if (total == m)
            break;
        else {
            if (total > m)
                --right;
            else
                ++left;
        }
    }

    if (left < right)
        printf("%d %d\n", arr[left], arr[right]);
    else
        printf("No Solution\n");
}

void pat_a_1048_2() // 二分
{
    int n, m;
    scanf("%d%d", &n, &m);

    int arr[100000];
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    std::sort(arr, arr + n);

    int v1, v2;
    bool sign;
    for (int i = 0; i < n; ++i) {
        v1 = arr[i];

        int left = i + 1;
        int right = n;

        sign = false;
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] == m - v1) {
                v2 = m - v1;
                sign = true;
                break;
            } else if (arr[mid] > m - v1)
                right = mid;
            else
                left = mid + 1;
        }
        if (sign)
            break;
    }

    if (sign)
        printf("%d %d\n", v1, v2);
    else
        printf("No Solution\n");
}

void pat_b_1023() {
    const int maxn = 10;

    int totalNum = 0;
    int map[maxn];
    for (int i = 0; i < maxn; ++i) {
        scanf("%d", &map[i]);
        totalNum += map[i];
    }

    std::string str;
    for (int i = 1; i < maxn; ++i)
        if (map[i]) {
            str += char(i + '0');
            --map[i];
            break;
        }
    --totalNum;

    while (totalNum--) {
        for (int i = 0; i < maxn; ++i)
            if (map[i]) {
                str += char(i + '0');
                --map[i];
                break;
            }
    }

    printf("%s\n", str.c_str());
}

namespace {
struct Cake_1070 {
    float inventory, price, averagePrice; // inventory could be decimals
};
} // namespace

void pat_a_1070() {
    const int maxn = 1000;
    const float eps = std::numeric_limits<float>::epsilon();

    Cake_1070 cakes[maxn];

    int n;
    float d;
    scanf("%d%f", &n, &d);

    for (int i = 0; i < n; ++i)
        scanf("%f", &cakes[i].inventory);
    for (int i = 0; i < n; ++i) {
        scanf("%f", &cakes[i].price);
        cakes[i].averagePrice = cakes[i].price / cakes[i].inventory;
    }

    std::sort(cakes, cakes + n, [](const auto &a, const auto &b) {
        return a.averagePrice > b.averagePrice;
    });

    float profit = 0.0f;

    for (int i = 0; i < n; ++i)
        if (d < cakes[i].inventory) {
            profit += cakes[i].averagePrice * d;
            break;
        } else {
            profit += cakes[i].price;
            d -= cakes[i].inventory;
            if (d < eps)
                break;
        }

    printf("%.2f\n", profit);
}

void pat_b_1020() { pat_a_1070(); }

namespace {
struct GasStation_1033 {
    double price, distance;
};
} // namespace

void pat_a_1033() {
    const int maxn = 500;
    const float eps = std::numeric_limits<double>::epsilon();

    GasStation_1033
        gasStations[maxn]; // 如果在终点 gasStations[n]
                           // 设置一个终点加油站，其油价设为 0，会方便一些

    double c, d, dAvg;
    int n;
    scanf("%lf%lf%lf%d", &c, &d, &dAvg, &n);

    for (int i = 0; i < n; ++i)
        scanf("%lf%lf", &gasStations[i].price, &gasStations[i].distance);

    std::sort(gasStations, gasStations + n, [&](const auto &a, const auto &b) {
        return b.distance > a.distance;
    });

    double container = 0.0;
    double price = 0.0;
    double distance = 0.0;
    double onceDistance = c * dAvg;
    for (int i = 0; i < n; ++i) {
        auto &thisGS = gasStations[i];

        if (thisGS.distance > distance)
            break;

        if (thisGS.distance < distance)
            continue;

        if (fabs(distance - d) < eps)
            break;

        int minIdx = -1;
        for (int j = i + 1; j < n; ++j) {
            auto &nextGS = gasStations[j];
            if (nextGS.distance - distance > onceDistance)
                break;
            if (minIdx == -1 || gasStations[minIdx].price > nextGS.price ||
                fabs(gasStations[minIdx].price - nextGS.price) < eps) {
                minIdx = j;
                if (gasStations[minIdx].price <
                    thisGS.price) // break when meets first cheaper gas station!
                                  // if none then find the cheapest
                    break;
            }
        }

        if (minIdx == -1) {
            if (onceDistance > d - distance ||
                fabs(onceDistance - (d - distance)) < eps) {
                price +=
                    (d - distance - container * dAvg) / dAvg * thisGS.price;
                container = 0.0;
                distance = d;
            } else {
                distance += onceDistance;
                break;
            }
        } else {
            auto &nextGS = gasStations[minIdx];

            if (thisGS.price > nextGS.price ||
                fabs(thisGS.price - nextGS.price) < eps) {
                price += (nextGS.distance - distance - container * dAvg) /
                         dAvg * thisGS.price;
                container = 0.0;
                distance = nextGS.distance;
            } else {
                if (onceDistance > d - distance ||
                    fabs(onceDistance - (d - distance)) < eps) {
                    price +=
                        (d - distance - container * dAvg) / dAvg * thisGS.price;
                    container = 0.0;
                    distance = d;
                } else {
                    price += (c - container) * thisGS.price;
                    container = c - (nextGS.distance - distance) / dAvg;
                    distance = nextGS.distance;
                }
            }
        }
    }

    if (fabs(distance - d) < eps)
        printf("%.2lf\n", price);
    else
        printf("The maximum travel distance = %.2f\n", distance);
}

void pat_a_1037() {
    const int maxn = 100000;
    int coupons[maxn];
    int values[maxn];

    int nc, np;

    scanf("%d", &nc);
    for (int i = 0; i < nc; ++i)
        scanf("%d", coupons + i);

    scanf("%d", &np);
    for (int i = 0; i < np; ++i)
        scanf("%d", values + i);

    int profit = 0;

    std::sort(coupons, coupons + nc);
    std::sort(values, values + np);

    for (int i = 0; i < nc && i < np; ++i) // forward i = j
    {
        if (coupons[i] > 0 || values[i] > 0)
            break;
        profit += coupons[i] * values[i];
    }

    for (int i = nc - 1, j = np - 1; i >= 0 && j >= 0;
         --i, --j) // backward i != j if nc != np
    {
        if (coupons[i] < 0 || values[j] < 0)
            break;
        profit += coupons[i] * values[j];
    }

    printf("%d\n", profit);
}

void pat_a_1067() {
    const int maxn = 100000;

    int n, t;
    int arr[maxn];
    int vis[maxn] = {0};
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        arr[t] = i;
    }

    int step = 0;

    for (int i = 0; i < n; ++i) // a greedy algorithm should be used instead
    {
        if (vis[i] || arr[i] == i)
            continue;

        int next = i;
        bool zero = false;
        while (!vis[next]) {
            vis[next] = 1;
            if (next == 0)
                zero = true;
            next = arr[next];
            ++step;
        }
        if (zero)
            --step;
        else
            ++step;
    }

    printf("%d\n", step);
}

void pat_a_1038() {
    int n;
    std::string strs[10000];

    std::cin >> n;

    for (int i = 0; i < n; ++i)
        std::cin >> strs[i];

    std::sort(strs, strs + n,
              [](const auto &a, const auto &b) { return a + b < b + a; });

    for (int i = 0; i < strs[0].size(); ++i)
        if (strs[0][i] != '0') {
            strs[0] = strs[0].substr(i);
            break;
        }

    bool allZero = true;
    for (int i = 0; i < n; ++i) // can simply strcat all strs[]
    {
        if (std::stoi(strs[i]) == 0) {
            if (allZero) {
                if (i == n - 1)
                    std::cout << "0";
                continue;
            } else
                std::cout << strs[i];
        } else {
            if (allZero)
                std::cout << std::stoi(strs[i]);
            else
                std::cout << strs[i];
            allZero = false;
        }
    }

    std::cout << std::endl;
}

void pat_a_1085() {
    const int maxn = 100000;

    int arr[maxn];
    int n;
    long long p; // do not use int
    scanf("%d%lld", &n, &p);

    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    std::sort(arr, arr + n);

    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        int mi = arr[i];

        int left = i;
        int right = n;
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] <= mi * p)
                left = mid + 1;
            else
                right = mid;
        }
        if (left - i > cnt)
            cnt = left - i;
    }

    printf("%d\n", cnt);
}

void pat_b_1030() { pat_a_1085(); }

void pat_a_1010() {
    using ll =
        long long; // cannot be unsigned long long for the judge of overflow

    char n1[11], n2[11];
    int tag;
    ll radix;

    scanf("%s%s", n1, n2);
    scanf("%d%lld", &tag, &radix);

    char *p1 = n1;
    char *p2 = n2;

    if (tag == 2)
        std::swap(p1, p2);

    int len1 = strlen(p1);
    int len2 = strlen(p2);

    ll intN1 = 0;
    ll intN2 = 0;

    auto getNum = [](char *p, int len, ll radix) {
        ll res = 0;
        for (int i = 0; i < len; ++i) {
            ll t = p[i] - '0';
            if (p[i] >= 'a' && p[i] <= 'z')
                t = p[i] - 'a' + 10;
            res = res * radix + t;
            if (res < 0) // overflow!
                return static_cast<ll>(0);
        }
        return res;
    };

    intN1 = getNum(p1, len1, radix);

    ll left = 1;
    for (int i = 0; i < len2; ++i) {
        int t = p2[i] - '0';
        if (p2[i] >= 'a' && p2[i] <= 'z')
            t = p2[i] - 'a' + 10;
        if (t + 1 > left)
            left = t + 1;
    }

    ll right =
        std::numeric_limits<int>::max(); // the answer could be 2^31 - 1, mid is
                                         // up to 2^31 - 2, but left (left = mid
                                         // + 1) is up to 2^31 - 1
    while (left < right) {
        ll mid = (left + right) / 2;

        intN2 = getNum(p2, len2, mid);

        if (intN2 >= intN1 || intN2 == 0)
            right = mid;
        else
            left = mid + 1;
    }

    if (getNum(p2, len2, left) != intN1)
        printf("Impossible\n");
    else
        printf("%lld\n", left);
}

void pat_a_1044() {
    const int maxn = 100001;

    int arr[maxn] = {0};

    int n, m, t;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        arr[i + 1] = arr[i] + t;
    }

    std::vector<std::pair<int, int>> vec;

    int mi = 0x3F3F3F3F;
    for (int i = 0; i < n + 1; ++i) {
        int start = i;
        int end = n + 1;

        while (start < end) {
            int mid = (start + end) / 2;
            int total = arr[mid] - arr[i];
            if (total >= m)
                end = mid;
            else
                start = mid + 1;
        }
        int total = arr[start] - arr[i];
        if (total >= m && total <= mi) {
            if (total < mi) {
                vec.clear();
                mi = arr[start] - arr[i];
            }
            vec.push_back({i + 1, start});
        }
    }

    for (const auto &[s, e] : vec)
        printf("%d-%d\n", s, e);
}

void pat_a_1085_1() {
    const int maxn = 100000;

    int arr[maxn];

    int n;
    long long p;
    scanf("%d%lld", &n, &p);

    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    std::sort(arr, arr + n);

    int left = 0;
    int right = 0;
    int cnt = 0;
    while (right < n) {
        if (arr[right] <= arr[left] * p) {
            if (right - left + 1 > cnt)
                cnt = right - left + 1;
            ++right;
        } else {
            ++left;
        }
    }
    printf("%d\n", cnt);
}

void pat_a_1089() {
    const int maxn = 100;

    int arrOriginal[maxn];
    int arrSort[maxn];

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", &arrOriginal[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arrSort[i]);

    bool isInsert = true;
    int right = n - 1;

    // array can be accessed even if index is negative! right could be less then
    // -1 without the first condition
    while (right >= 0 && arrOriginal[right] == arrSort[right])
        --right;

    for (int i = 1; i <= right; ++i)
        if (arrSort[i] < arrSort[i - 1]) {
            isInsert = false;
            break;
        }

    if (isInsert) {
        printf("Insertion Sort\n");

        /*
            4
            3 4 2 1
            3 4 2 1
        */
        if (right == -1)
            right = 0;
        while (arrSort[right] < arrSort[right + 1])
            ++right;

        ++right;
        while (right > 0 && arrSort[right] < arrSort[right - 1]) {
            std::swap(arrSort[right], arrSort[right - 1]);
            --right;
        }

        for (int i = 0; i < n; ++i) {
            if (i)
                printf(" ");
            printf("%d", arrSort[i]);
        }
    } else {
        printf("Merge Sort\n");

        int t = 1;
        bool breakSign = false;
        while (true) {
            t *= 2;
            for (int i = 0; i < n; i += t) {
                for (int j = i + 1; j < i + t && j < n; ++j) {
                    if (arrSort[j] < arrSort[j - 1]) {
                        breakSign = true;
                        break;
                    }
                }
                if (breakSign)
                    break;
            }
            if (breakSign)
                break;
        }

        for (int i = 0; i < n; i += t) {
            int left = i;
            int right = i + t;
            if (right > n)
                right = n;
            std::sort(arrSort + left, arrSort + right);
        }

        for (int i = 0; i < n; ++i) {
            if (i)
                printf(" ");
            printf("%d", arrSort[i]);
        }
    }
}

void pat_b_1035() { pat_a_1089(); }

void pat_a_1029() {
    const int maxn = 2 * 100000;

    int n[2];
    int arr[2][maxn]; // would be more convenient to set a sentinel at the end
                      // of each array

    scanf("%d", &n[0]);
    for (int i = 0; i < n[0]; ++i)
        scanf("%d", &arr[0][i]);
    scanf("%d", &n[1]);
    for (int i = 0; i < n[1]; ++i)
        scanf("%d", &arr[1][i]);

    int mid = (n[0] + n[1] + 1) / 2;

    int idx[2] = {0};
    int nowArr = arr[0][0] > arr[1][0] ? 1 : 0;
    int anotherArr = nowArr == 1 ? 0 : 1;

    idx[anotherArr] = -1;

    int cnt = 1;
    while (cnt < mid) {
        if (idx[nowArr] < n[nowArr] - 1 &&
            idx[anotherArr] < n[anotherArr] - 1) {
            if (arr[nowArr][idx[nowArr] + 1] >
                arr[anotherArr][idx[anotherArr] + 1])
                std::swap(nowArr, anotherArr);
            ++idx[nowArr];
            ++cnt;
        } else {
            if (idx[nowArr] == n[nowArr] - 1)
                std::swap(nowArr, anotherArr);
            ++idx[nowArr];
            ++cnt;
        }
    }

    printf("%d\n", arr[nowArr][idx[nowArr]]);
}

void pat_a_1093() {
    const int maxn = 100001;
    const int mod = 1000000007;

    char str[maxn];
    scanf("%s", str);

    int pNum[maxn] = {0};
    int tNum[maxn] = {0};

    int len = strlen(str);

    for (int i = 0; i < len; ++i) {
        if (str[i] == 'P') {
            if (i == 0)
                pNum[i] = 1;
            else
                pNum[i] = pNum[i - 1] + 1;
        } else if (i > 0) {
            pNum[i] = pNum[i - 1];
        }
    }

    for (int i = len - 1; i >= 0; --i) {
        if (str[i] == 'T') {
            if (i == len - 1)
                tNum[i] = 1;
            else
                tNum[i] = tNum[i + 1] + 1;
        } else if (i < len - 1) {
            tNum[i] = tNum[i + 1];
        }
    }

    int cnt = 0;

    for (int i = 1; i < len - 1; ++i) {
        if (str[i] != 'A')
            continue;
        cnt += pNum[i - 1] * tNum[i + 1];
        cnt %= mod;
    }

    printf("%d\n", cnt);
}

void pat_b_1040() { pat_a_1093(); }

void pat_a_1101() {
    const int maxn = 100000;

    int arr[maxn];
    int mi[maxn] = {0};
    int ma[maxn] = {0};

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    for (int i = 1; i < n; ++i)
        ma[i] = std::max(arr[i - 1], ma[i - 1]);

    mi[n - 1] = 0x3F3F3F3F;
    for (int i = n - 2; i >= 0; --i)
        mi[i] = std::min(arr[i + 1], mi[i + 1]);

    int cnt = 0;
    int result[maxn];

    for (int i = 0; i < n; ++i)
        if (arr[i] <= mi[i] && arr[i] >= ma[i])
            result[cnt++] = arr[i];

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; ++i) {
        if (i)
            printf(" ");
        printf("%d", result[i]);
    }
    if (cnt == 0) // e.g. 2 1, there's no result
        printf("\n");
}

void pat_b_1045() { pat_a_1101(); }

void pat_b_1003() {
    int n;
    scanf("%d", &n);

    auto judge = [](const char str[]) {
        int len = strlen(str);

        int pIdx = -1;
        int tIdx = -1;
        for (int i = 0; i < len; ++i) {
            char c = str[i];
            if (c - 'P' && c - 'A' && c - 'T')
                return false;
            if (c == 'P') {
                if (pIdx != -1)
                    return false;
                pIdx = i;
            }
            if (c == 'T') {
                if (tIdx != -1)
                    return false;
                tIdx = i;
            }
        }

        if (pIdx == -1 || tIdx == -1 || pIdx >= tIdx - 1)
            return false;

        for (int i = pIdx + 1; i < tIdx; ++i)
            if (str[i] != 'A')
                return false;

        int left = pIdx;
        int right = len - 1 - tIdx;

        if (right != left * (tIdx - pIdx - 1))
            return false;

        for (int i = 0; i < pIdx; ++i)
            if (str[i] != 'A')
                return false;

        for (int i = tIdx + 1; i < len; ++i)
            if (str[i] != 'A')
                return false;

        return true;
    };

    char str[101];
    getchar();
    for (int i = 0; i < n; ++i) {
        std::cin.getline(str, 101);
        printf(judge(str) ? "YES\n" : "NO\n");
    }
}

void pat_a_1069() {
    const int end = 6174;
    const int len = 4;

    int num;
    scanf("%d", &num);

    char str[len + 1];
    std::string nextStr = std::to_string(num);
    int size =
        nextStr
            .size(); // do not use size() inside for statement! it's changing!
    for (int i = 0; i < len - size; ++i)
        nextStr = "0" + nextStr;
    strcpy(str, nextStr.c_str());

    for (int i = 1; i < len; ++i)
        if (str[i] == str[i - 1]) {
            if (i == len - 1) {
                printf("%s - %s = 0000\n", str, str);
                return;
            }
        } else {
            break;
        }

    int ma, mi;
    do {
        std::sort(str, str + len);
        mi = std::stoi(str);
        std::sort(str, str + len, std::greater<char>());
        ma = std::stoi(str);

        printf("%04d - %04d = %04d\n", ma, mi, ma - mi);

        std::string nextStr = std::to_string(ma - mi);
        int size = nextStr.size();
        for (int i = 0; i < len - size; ++i)
            nextStr = '0' + nextStr;

        strcpy(str, nextStr.c_str());
    } while (ma - mi != end);
}

void pat_b_1019() { pat_a_1069(); }

void pat_a_1104() {
    using ull = unsigned long long;
    using ld = long double;

    ull n; // can not be int
    scanf("%lld", &n);

    ld t;
    ld sum = 0.0; // can not be double or float
    for (ull i = 0; i < n; ++i) {
        scanf("%Lf", &t);
        sum += static_cast<ld>((n - i) * (i + 1)) * t;
    }

    printf("%.2Lf\n", sum);
}

void pat_b_1049() { pat_a_1104(); }

void pat_a_1008() {
    const int maxn = 100;

    int arr[maxn];

    int n, t;
    scanf("%d", &n);

    int floor = 0;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        if (t > floor)
            total += (t - floor) * 6 + 5;
        else
            total += (floor - t) * 4 + 5;
        floor = t;
    }

    printf("%d\n", total);
}

void pat_a_1049() {
    int n;
    scanf("%d", &n);

    int cnt = 0;
    int idx = 1;

    int pre, post, now;
    while (n / idx) {
        pre = n / (idx * 10);
        post = n % idx;
        now = n / idx % 10;

        if (now == 0)
            cnt += pre * idx;
        else if (now == 1)
            cnt += pre * idx + post + 1;
        else // now >= 2
            cnt += (pre + 1) * idx;

        idx *= 10;
    }

    printf("%d\n", cnt);
}

void pat_a_1049_() {
    int n;
    scanf("%d", &n);

    int cnt = 0;
    int now = 0;
    int pre = 0;
    int post = 0;
    int post_ = 0;
    int index = 1;

    while (n / index) {
        now = n / index % 10;
        pre = n / (index * 10);
        post = n % index; // 1. right

        // if (post != post_) // test
        //     return;

        if (now > 1)
            cnt += (pre + 1) * index;
        else if (now == 1)
            cnt += pre * index + (post + 1);
        else
            cnt += pre * index;

        // post_ = post_ * 10 + now; // 2. wrong!

        // post += now * index; // 3. also right

        index *= 10;
    }

    printf("%d\n", cnt);
}

namespace {
long long gcd_1081(long a, long b) {
    if (b == 0)
        return a;
    return gcd_1081(b, a % b);
}

struct Fraction_1081 {
    long long up, down;
    Fraction_1081(long long up_, long long down_) {
        up = up_;
        down = down_;
        if (up == 0)
            down = 1;
    }

    void reduce() {
        long long g = gcd_1081(std::llabs(up), std::llabs(down));
        up /= g;
        down /= g;
        if (up > 0 && down < 0) {
            down *= -1;
            up *= -1;
        }
    }
};

void print_1081(Fraction_1081 &fraction) {
    long long front = 0;

    long long u = std::llabs(fraction.up);
    long long d = std::llabs(fraction.down);

    if (u >= d) {
        front = u / d;
        printf("%lld", front);
        fraction.up = u % d * (fraction.up > 0 ? 1 : -1);
    }

    if (fraction.up == 0) {
        if (front == 0)
            printf("0\n");
    } else {
        if (front != 0)
            printf(" ");
        printf("%lld/%lld\n", fraction.up, fraction.down);
    }
}
} // namespace

void pat_a_1081() {
    int n;
    scanf("%d", &n);

    long long u, d;
    Fraction_1081 sum(0, 1);

    for (int i = 0; i < n; ++i) {
        scanf("%lld/%lld", &u, &d);
        sum.up = sum.up * d + u * sum.down;
        sum.down *= d;
        sum.reduce();
    }

    print_1081(sum);
}

namespace {
long long gcd_1088(long a, long b) {
    if (b == 0)
        return a;
    return gcd_1088(b, a % b);
}

struct Fraction_1088 {
    long long up, down;
    Fraction_1088(long long up_, long long down_) {
        up = up_;
        down = down_;
        if (up == 0)
            down = 1;
    }

    void reduce() {
        long long g = gcd_1088(std::llabs(up), std::llabs(down));
        up /= g;
        down /= g;
        if (up > 0 && down < 0) {
            down *= -1;
            up *= -1;
        }
    }
};

void print_1088(Fraction_1088 fraction) {
    long long front = 0;

    long long u = std::llabs(fraction.up);
    long long d = std::llabs(fraction.down);

    bool sign = true;
    if (fraction.up > 0 && fraction.down < 0 ||
        fraction.up < 0 && fraction.down > 0)
        sign = false;

    fraction.up = u;
    fraction.down = d;

    if (d == 0) {
        printf("Inf");
        return;
    }

    if (u >= d) {
        front = u / d;
        fraction.up = u % d;
    }

    if (!sign)
        printf("(-");

    if (front)
        printf("%lld", front);

    if (fraction.up == 0) {
        if (front == 0)
            printf("0");
    } else {
        if (front != 0)
            printf(" ");
        printf("%lld/%lld", fraction.up, fraction.down);
    }

    if (!sign)
        printf(")");
}
} // namespace

void pat_a_1088() {
    Fraction_1088 frac1(0, 1), frac2(0, 1);

    scanf("%lld/%lld%lld/%lld", &frac1.up, &frac1.down, &frac2.up, &frac2.down);

    frac1.reduce();
    frac2.reduce();

    Fraction_1088 ans(0, 1);

    ans.down = frac1.down * frac2.down;
    ans.up = frac1.up * frac2.down + frac2.up * frac1.down;
    ans.reduce();

    print_1088(frac1);
    printf(" + ");
    print_1088(frac2);
    printf(" = ");
    print_1088(ans);
    printf("\n");

    ans.down = frac1.down * frac2.down;
    ans.up = frac1.up * frac2.down - frac2.up * frac1.down;
    ans.reduce();

    print_1088(frac1);
    printf(" - ");
    print_1088(frac2);
    printf(" = ");
    print_1088(ans);
    printf("\n");

    ans.down = frac1.down * frac2.down;
    ans.up = frac1.up * frac2.up;
    ans.reduce();

    print_1088(frac1);
    printf(" * ");
    print_1088(frac2);
    printf(" = ");
    print_1088(ans);
    printf("\n");

    ans.down = frac1.down * frac2.up;
    ans.up = frac1.up * frac2.down;
    ans.reduce();

    print_1088(frac1);
    printf(" / ");
    print_1088(frac2);
    printf(" = ");
    print_1088(ans);
    printf("\n");
}

void pat_b_1034() { pat_a_1088(); }

void pat_a_1007() {
    const int maxn = 100000;

    int idx = 0;
    int prime[maxn] = {0};
    bool isNotPrime[maxn] = {0};

    for (int i = 2; i < maxn; ++i) {
        if (!isNotPrime[i]) {
            prime[idx++] = i;
            for (int j = i + i; j < maxn; j += i)
                isNotPrime[j] = true;
        }
    }

    int n;
    scanf("%d", &n);

    int cnt = 0;

    for (int i = 1; i < idx; ++i) {
        if (prime[i] > n)
            break;
        if (prime[i] - prime[i - 1] == 2)
            ++cnt;
    }

    printf("%d\n", cnt);
}

void pat_b_1013() {
    const int maxn = 200000; // careful, it's not the range of n

    int m, n;
    scanf("%d%d", &m, &n);

    int idx = 0;
    int prime[maxn] = {0};
    bool isNotPrime[maxn] = {0};

    for (int i = 2; i < maxn; ++i)
        if (!isNotPrime[i]) {
            prime[idx++] = i;
            if (idx >= n)
                break;
            for (int j = i + i; j < maxn; j += i)
                isNotPrime[j] = true;
        }

    for (int i = m; i <= n; ++i) {
        if ((i - m) % 10)
            printf(" ");
        else if (i > m)
            printf("\n");
        printf("%d", prime[i - 1]);
    }
}

void pat_a_1015() {
    const int maxn = 100000;
    int idx = 0;
    int prime[maxn] = {0};
    bool isNotPrime[maxn] = {0};

    isNotPrime[1] = true; // one is not prime!
    for (int i = 2; i < maxn; ++i)
        if (!isNotPrime[i]) {
            prime[idx++] = i;
            for (int j = i + i; j < maxn; j += i)
                isNotPrime[j] = true;
        }

    int n, d;

    auto f = [](int num, int d) {
        std::string tmp; // can user array instead
        while (num) {
            int remainder = num % d;
            num = num / d;
            tmp = tmp + std::to_string(remainder);
        }

        int ret = 0;
        int len = tmp.size();
        for (int i = 0; i < len; ++i)
            ret += (tmp[i] - '0') * static_cast<int>(pow(d, len - 1 - i));
        return ret;
    };

    while (true) {
        scanf("%d", &n);
        if (n < 0)
            break;
        scanf("%d", &d);

        int rN = f(n, d);

        if (!isNotPrime[n] && !isNotPrime[rN])
            printf("Yes\n");
        else
            printf("No\n");
    }
}

void pat_a_1078() {
    const int maxn = 10100; // should be greater than maximun of n 10000 !

    auto isPrime = [](int num) {
        if (num < 2)
            return false;
        for (int i = 2; i * i <= num; ++i)
            if (num % i == 0)
                return false;
        return true;
    };

    int hash[maxn] = {0};

    int size, n, t;
    scanf("%d%d", &size, &n);

    while (!isPrime(size))
        ++size;

    std::vector<int> result;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);

        bool sign = false;

        int j = 0;
        do {
            int k = (t + j * j) % size;

            if (hash[k] == 0) {
                hash[k] = t;
                result.push_back(k);
                sign = true;
                break;
            }
            ++j;
        } while (j <= size); // can be proven

        if (!sign)
            result.push_back(-1);
    }

    for (int i = 0; i < result.size(); ++i) {
        if (i)
            printf(" ");
        if (result[i] == -1)
            printf("-");
        else
            printf("%d", result[i]);
    }
    printf("\n");
}

void pat_a_1096() {
    int n;
    scanf("%d", &n);

    int maxLen = 0;
    int begin = 0;

    // for (int i = 2; i * i <= n; ++i) // TLE!

    int sqr = static_cast<int>(sqrt(1.0 * n));
    for (int i = 2; i <= sqr; ++i)
        if (n % i == 0) {
            int j = i;
            int t = n;
            while (t % j == 0) {
                t /= j;
                ++j;
            }
            if (j - i > maxLen) {
                maxLen = j - i;
                begin = i;
            }
        }

    if (maxLen == 0) //  n is a prime
    {
        printf("1\n%d\n", n);
        return;
    }

    printf("%d\n", maxLen);
    for (int i = begin; i < begin + maxLen; ++i) {
        if (i > begin)
            printf("*");
        printf("%d", i);
    }
    printf("\n");
}

namespace {
struct Factor_a_1059 {
    int x, cnt;
    Factor_a_1059() : x(0), cnt(0) {}
};
} // namespace

void pat_a_1059() {
    /*
        another method: open the prime number table up to 10^5,
        because 10^10 is larger than the integer range
    */
    auto isPrime = [](int num) {
        int sqr = static_cast<int>(sqrt(1.0 * num));
        for (int i = 2; i <= sqr; ++i)
            if (num % i == 0)
                return false;
        return true;
    };

    int n;
    scanf("%d", &n);

    if (n == 1 || isPrime(n)) {
        printf("%d=%d\n", n, n);
        return;
    }

    int fIdx = 0;
    Factor_a_1059 fac[10];

    int tN = n;
    int sqr = static_cast<int>(sqrt(1.0 * tN));
    for (int i = 2; i <= sqr; ++i)
        if (isPrime(i) && tN % i == 0) {
            while (tN % i == 0) {
                ++fac[fIdx].cnt;
                tN /= i;
            }
            fac[fIdx].x = i;
            ++fIdx;
            if (tN == 0)
                break;
        }

    printf("%d=", n);
    for (int i = 0; i < fIdx; ++i) {
        if (i)
            printf("*");
        printf("%d", fac[i].x);
        if (fac[i].cnt > 1)
            printf("^%d", fac[i].cnt);
    }
    printf("\n");
}

void pat_b_1017() {
    const int maxn = 1001;

    char strA[maxn], strQ[maxn];
    int b, r;

    scanf("%s%d", strA, &b);

    int lenA = strlen(strA);
    int qIdx = 0;

    int now = 0;
    for (int i = 0; i < lenA; ++i) {
        now = now * 10 + (strA[i] - '0');
        if (now < b) {
            strQ[qIdx++] = '0';
        } else {
            strQ[qIdx++] = '0' + now / b;
            now = now % b;
        }
    }
    strQ[qIdx] = '\0';

    char *p = strQ;
    while (*p == '0')
        ++p;
    if (*p == '\0')
        --p;

    printf("%s %d\n", p, now);
}

void pat_a_1023() {
    const int maxn = 21;

    char original[maxn], result[maxn];
    scanf("%s", original);

    int lenO = strlen(original);
    int hash[256] = {0};
    for (int i = 0; i < lenO; ++i)
        ++hash[original[i]];

    int idx = 0;
    int c = 0;
    for (int i = lenO - 1; i >= 0; --i) {
        int now = 2 * (original[i] - '0') + c;
        result[idx++] = '0' + now % 10;
        c = now / 10;
    }
    if (c > 0)
        result[idx++] = '0' + c;
    result[idx++] = '\0';

    std::reverse(result, result + idx - 1);

    int lenR = strlen(result);
    for (int i = 0; i < lenR; ++i)
        --hash[result[i]];

    bool sign = true;
    for (int i = 0; i < 256; ++i)
        if (hash[i] != 0) {
            sign = false;
            break;
        }

    printf(sign ? "Yes\n" : "No\n");
    printf("%s\n", result);
}

void pat_a_1024() {
    const int maxn = 1000;

    auto isPalindromic = [](const char *str, int len) {
        for (int i = 0; i < len / 2; ++i)
            if (str[i] != str[len - 1 - i])
                return false;
        return true;
    };

    char numA[maxn], numB[maxn], numC[maxn];
    int k;
    scanf("%s%d", numA, &k);

    int lenA = strlen(numA);
    int step = 0;

    while (step < k && !isPalindromic(numA, lenA)) {
        strcpy(numB, numA);
        std::reverse(numB, numB + lenA);

        int idx = 0;
        int c = 0;
        for (int i = lenA - 1; i >= 0; --i) {
            int now = (numA[i] - '0') + (numB[i] - '0') + c;
            numC[idx++] = '0' + now % 10;
            c = now / 10;
        }
        if (c > 0)
            numC[idx++] = '0' + c;
        numC[idx] = '\0';

        std::reverse(numC, numC + idx);

        strcpy(numA, numC);
        lenA = strlen(numA);
        ++step;
    }

    printf("%s\n%d\n", numA, step);
}

void pat_a_1039() {
    int N, K;
    scanf("%d%d", &N, &K);

    // should use string hash, like pat_a_1047, save more space than std::string
    std::unordered_map<std::string, std::vector<int>> m;

    int n, k;
    char name[5];
    for (int i = 0; i < K; ++i) {
        scanf("%d%d", &k, &n);
        for (int j = 0; j < n; ++j) {
            scanf("%s", name);
            if (m.find(name) == m.end())
                m[name] = std::vector<int>();
            m[name].push_back(k);
        }
    }

    for (int i = 0; i < N; ++i) {
        scanf("%s", name);

        printf("%s ", name);

        if (m.find(name) == m.end()) {
            printf("0\n");
        } else {
            std::sort(m[name].begin(), m[name].end());
            printf("%d ", static_cast<int>(m[name].size()));
            for (int j = 0; j < m[name].size(); ++j) {
                if (j)
                    printf(" ");
                printf("%d", m[name][j]);
            }
            printf("\n");
        }
    }
}

void pat_a_1047() {
    const int maxK = 2501;
    const int nameLen = 4;
    const int base = 26;

    // should use name array instead, vector save the index of the name

    auto getKey = [base](const char str[]) {
        int key = 0;
        for (int i = 0; i < nameLen - 1; ++i)
            key = key * base + str[i] - 'A';
        key = key * base + str[nameLen - 1] - '0';
        return key;
    };

    auto getValue = [base](int key, char str[]) {
        str[nameLen] = '\0';

        int t = key % base;
        str[nameLen - 1] = '0' + t;
        key /= base;

        // while (key) { ... } wrong!
        for (int i = nameLen - 2; i >= 0; --i) {
            t = key % base;
            str[i] = 'A' + t;
            key /= base;
        }
    };

    int N, K;
    scanf("%d%d", &N, &K);

    std::vector<int> m[maxK];

    char name[nameLen + 1];
    int n, t;
    for (int i = 0; i < N; ++i) {
        scanf("%s%d", name, &n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &t);
            m[t].push_back(getKey(name));
        }
    }

    for (int i = 1; i <= K; ++i) {
        printf("%d %d\n", i, static_cast<int>(m[i].size()));
        std::sort(m[i].begin(), m[i].end());
        for (const auto &it : m[i]) {
            getValue(it, name);
            printf("%s\n", name);
        }
    }
}

void pat_a_1063() {
    const int maxn = 50;

    std::unordered_set<int> s[maxn];

    int n, m, t;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &m);
        for (int j = 0; j < m; ++j) {
            scanf("%d", &t);
            s[i].insert(t);
        }
    }

    auto getSimilarity = [&s](int a, int b) {
        auto &sA = s[a];
        auto &sB = s[b];
        int sizeA = sA.size();
        int sizeB = sB.size();

        int cnt = 0;
        for (const auto &it : sA)
            if (sB.find(it) != sB.end())
                ++cnt;

        return (1.0 * cnt) / (sizeA + sizeB - cnt);
    };

    int k;
    scanf("%d", &k);

    int a, b;
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &a, &b);
        printf("%.1f%%\n", 100 * getSimilarity(a - 1, b - 1));
    }
}

void pat_a_1060() {
    int n;
    std::string a, b;

    std::cin >> n >> a >> b;

    // could be 000, 000.001
    auto deal = [](std::string &str) {
        bool noOther = true;
        for (int i = 0; i < str.size(); ++i)
            if (str[i] > '0' && str[i] <= '9') {
                noOther = false;
                break;
            }
        if (noOther) {
            str = "0";
            return;
        }
    };

    auto getValidity = [n](const std::string &str) {
        std::string ret = "0.";

        if (str == "0") {
            for (int i = 0; i < n; ++i)
                ret += "0";
            ret += "*10^0";
            return ret;
        }

        int len = str.size();

        int first = -1;
        int dot = -1;
        for (int i = 0; i < len; ++i) {
            if (first == -1 && str[i] != '0' && str[i] != '.') // != 0 && != .
                first = i;
            if (str[i] == '.')
                dot = i;
            if (first != -1 && dot != -1)
                break;
        }
        if (dot == -1)
            dot = len;

        for (int i = first, valid = 0; valid < n; ++i) {
            if (i < len && str[i] == '.')
                continue;

            if (i >= len)
                ret += '0';
            else
                ret += str[i];
            ++valid;
        }

        ret += "*10^";

        if (str[first] == '0') // 0 !
            ret += '0';
        else
            ret += std::to_string(dot < first ? dot - first + 1
                                              : dot - first); // !

        return ret;
    };

    deal(a);
    deal(b);
    std::string vA = getValidity(a);
    std::string vB = getValidity(b);

    if (vA == vB)
        printf("YES %s\n", vA.c_str());
    else
        printf("NO %s %s\n", vA.c_str(), vB.c_str());
}

void pat_a_1100() {
    const int maxLen = 20;
    const int base = 13;

    std::string lDigit[base] = {"tret", "jan", "feb", "mar", "apr",
                                "may",  "jun", "jly", "aug", "sep",
                                "oct",  "nov", "dec"};
    std::string hDigit[base] = {"_",   "tam", "hel", "maa", "huh", "tou", "kes",
                                "hei", "elo", "syy", "lok", "mer", "jou"};

    // could directly obtain all mapped strings of [0, 169)
    std::unordered_map<std::string, int> digitToNum, hDigitToNum;
    for (int i = 0; i < base; ++i) {
        digitToNum[lDigit[i]] = i;
        hDigitToNum[hDigit[i]] = i * base;
    }

    auto isDecimal = [](const char num[]) {
        int len = strlen(num);
        for (int i = 0; i < len; ++i)
            if (num[i] >= 'a' && num[i] <= 'z')
                return false;
        return true;
    };

    auto getDecimalFromString = [](const char num[]) {
        int len = strlen(num);
        int ret = 0;
        for (int i = 0; i < len; ++i)
            ret = ret * 10 + (num[i] - '0');
        return ret;
    };

    auto getMarsFromDecimal = [&](int value, char result[]) {
        if (value == 0) {
            strcpy(result, lDigit[0].c_str());
            return;
        }
        if (value < base) {
            strcpy(result, lDigit[value].c_str());
            return;
        }
        int now = value % base;
        value /= base;
        strcpy(result, hDigit[value].c_str());
        if (now > 0) {
            int len = strlen(result);
            result[len] = ' ';
            strcpy(result + len + 1, lDigit[now].c_str());
        }
    };

    auto getDecimalFromMars = [&](char num[], char result[]) {
        int len = strlen(num);
        int space = 0;
        for (int i = 0; i < len; ++i)
            if (num[i] == ' ') {
                space = i;
                break;
            }

        int value = 0;
        if (space == 0) {
            if (digitToNum.find(num) != digitToNum.end())
                value = digitToNum[num];
            else
                value = hDigitToNum[num];
        } else {
            num[space] = '\0';
            value = hDigitToNum[num];
            value += digitToNum[num + space + 1];
        }
        strcpy(result, std::to_string(value).c_str());
    };

    int n;
    scanf("%d%*c", &n);

    char num[maxLen];
    char result[maxLen];
    for (int i = 0; i < n; ++i) {
        std::cin.getline(num, 20);
        if (isDecimal(num)) {
            int value = getDecimalFromString(num);
            getMarsFromDecimal(value, result);
        } else
            getDecimalFromMars(num, result);
        printf("%s\n", result);
    }
}

void pat_b_1044() { pat_a_1100(); }

void pat_a_1054() {
    int m, n, t;
    scanf("%d%d", &m, &n);

    std::unordered_map<int, int> map;

    int total = m * n;

    // for (int i = 0; i < total; ++i) // cost too much space!
    //     map[i] = 0;

    for (int i = 0; i < total; ++i) {
        scanf("%d", &t);
        if (map.find(t) == map.end())
            map[t] = 1;
        else
            ++map[t];
    }

    auto p = std::max_element(
        map.begin(), map.end(),
        [](const auto &a, const auto &b) { return a.second < b.second; });
    printf("%d\n", p->first);
}

void pat_a_1071() {
    const int maxn = 1048576 + 1;

    char str[maxn];
    std::cin.getline(str, maxn);

    int len = strlen(str);

    for (int i = 0; i < len; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = std::tolower(str[i]);
        if (!(str[i] >= 'a' && str[i] <= 'z' || str[i] >= '0' && str[i] <= '9'))
            str[i] = '\0';
    }

    std::unordered_map<std::string, int> map;
    for (int i = 0; i < len; ++i) {
        if (str[i] == '\0')
            continue;

        if (map.find(str + i) == map.end())
            map[str + i] = 1;
        else
            ++map[str + i];

        int j = i;
        while (str[j] != '\0')
            ++j;
        i = j;
    }

    int ma = -1;
    std::string ret;
    for (const auto &[a, b] : map) {
        if (b > ma) {
            ma = b;
            ret = a;
        } else if (b == ma && a < ret) {
            ret = a;
        }
    }
    printf("%s %d\n", ret.c_str(), ma);
}

void pat_a_1022() {
    const int maxLen = 81;
    const int maxLenQuery =
        1000; // different from maxLen, could be much greater than maxLen
    const int maxM = 1000;

    std::unordered_map<std::string, std::vector<int>> titleM, authorM, keywordM,
        publisherM, yearM;
    std::unordered_map<int, std::unordered_map<std::string, std::vector<int>> *>
        mM = {{1, &titleM},
              {2, &authorM},
              {3, &keywordM},
              {4, &publisherM},
              {5, &yearM}};

    int n;
    scanf("%d", &n);

    int ID;
    char tmp[maxLen];
    for (int i = 0; i < n; ++i) {
        scanf("%d%*c", &ID);

        std::cin.getline(tmp, maxLen);
        if (titleM.find(tmp) == titleM.end())
            titleM[tmp] = std::vector<int>();
        titleM[tmp].push_back(ID);

        std::cin.getline(tmp, maxLen);
        if (authorM.find(tmp) == authorM.end())
            authorM[tmp] = std::vector<int>();
        authorM[tmp].push_back(ID);

        std::cin.getline(tmp, maxLen);
        int len = strlen(tmp);
        for (int i = 0; i < len; ++i)
            if (tmp[i] == ' ')
                tmp[i] = '\0';
        for (int i = 0; i < len; ++i)
            if (tmp[i] != '\0') {
                if (keywordM.find(tmp + i) == keywordM.end())
                    keywordM[tmp + i] = std::vector<int>();
                keywordM[tmp + i].push_back(ID);

                int j = i;
                while (tmp[j] != '\0')
                    ++j;
                i = j;
            }

        std::cin.getline(tmp, maxLen);
        if (publisherM.find(tmp) == publisherM.end())
            publisherM[tmp] = std::vector<int>();
        publisherM[tmp].push_back(ID);

        std::cin.getline(tmp, maxLen);
        if (yearM.find(tmp) == yearM.end())
            yearM[tmp] = std::vector<int>();
        yearM[tmp].push_back(ID);
    }

    auto print = [](std::unordered_map<std::string, std::vector<int>> &map,
                    const char str[]) {
        // Priority queue cannot be traversed, so set can be used, then no need
        // to sort.
        std::sort(map[str].begin(), map[str].end());
        for (const auto &it : map[str])
            printf("%07d\n", it);
    };

    int m;
    scanf("%d%*c", &m);

    char queries[maxLenQuery][maxM];
    for (int i = 0; i < m; ++i) {
        std::cin.getline(queries[i], maxLenQuery);
        printf("%s\n", queries[i]);

        int type = queries[i][0] - '0';
        auto &map = *mM[type];
        if (map.find(queries[i] + 3) != map.end())
            print(map, queries[i] + 3);
        else
            printf("Not Found\n");
    }
}

void pat_a_1051() {
    const int maxn = 1000;

    int m, n, k;
    int arr[maxn];
    scanf("%d%d%d", &m, &n, &k);

    std::stack<int> s;
    auto judge = [&s, m, n](int arr[]) {
        s = std::stack<int>();

        int last = 0;
        for (int i = 0; i < n; ++i) {
            if (!s.empty() && s.top() == arr[i]) {
                if (s.top() > last)
                    last = s.top();
                s.pop();
            } else if (s.empty() || s.top() < arr[i]) {
                for (int j = last + 1; j <= arr[i]; ++j)
                    s.push(j);
                if (s.size() > m)
                    return false;
                if (s.top() > last)
                    last = s.top();
                s.pop();
            } else
                return false;
        }

        return true;
    };

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j)
            scanf("%d", &arr[j]);
        if (judge(arr))
            printf("YES\n");
        else
            printf("NO\n");
    }
}

void pat_a_1056() {
    const int maxn = 1000;

    int np, ng;
    scanf("%d%d", &np, &ng);

    int weight[maxn];
    int rank[maxn];

    std::queue<int> q;
    for (int i = 0; i < np; ++i)
        scanf("%d", &weight[i]);

    int t;
    for (int i = 0; i < np; ++i) {
        scanf("%d", &t);
        q.push(t);
    }

    while (q.size() > 1) {
        int size = q.size();
        // int nowRank = (size + 1) / ng + 1; // wrong !!!
        int nowRank = size / ng;
        if (size % ng)
            nowRank += 1;
        while (size) {
            int max = -1;
            for (int i = 0; i < ng && size > 0; ++i) {
                if (max == -1 || weight[q.front()] > weight[max])
                    max = q.front();
                rank[q.front()] = nowRank + 1;
                q.pop();
                --size;
            }
            q.push(max);
        }
    }
    rank[q.front()] = 1;

    for (int i = 0; i < np; ++i) {
        if (i)
            printf(" ");
        printf("%d", rank[i]);
    }
    printf("\n");
}

namespace {
struct Node_a_1074 {
    int value, next;
};

int reverseK(Node_a_1074 nodes[], int head, int k) // another method: sort nodes
{
    int begin = nodes[head].next;
    int next = begin;
    while (k-- > 0) {
        int t = nodes[next].next;
        nodes[next].next = nodes[head].next;
        nodes[head].next = next;
        next = t;
    }
    nodes[begin].next = next;
    return begin;
}
} // namespace

void pat_a_1074() {
    const int maxn = 100000 + 1;

    Node_a_1074 nodes[maxn];

    int root, n, k;
    scanf("%d%d%d", &root, &n, &k);

    for (int i = 0; i < n; ++i) {
        int idx;
        scanf("%d", &idx);
        Node_a_1074 &node = nodes[idx];
        scanf("%d%d", &node.value, &node.next);
    }

    int cnt = 0;
    int next = root;
    while (next != -1) {
        next = nodes[next].next;
        ++cnt;
    }

    int head = maxn;
    nodes[head].next = root;
    while (head != -1 && cnt >= k) {
        head = reverseK(nodes, head, k);
        cnt -= k;
    }

    head = maxn;
    next = nodes[head].next;
    while (next != -1) {
        Node_a_1074 &node = nodes[next];
        if (node.next == -1)
            printf("%05d %d %d\n", next, node.value, node.next);
        else
            printf("%05d %d %05d\n", next, node.value, node.next);
        next = node.next;
    }
}

void pat_b_1025() { pat_a_1074(); }

namespace {
struct Node_a_1032 {
    char c;
    int next;
    bool vis = false;
};

} // namespace

void pat_a_1032() {
    const int maxn = 100000;

    Node_a_1032 nodes[maxn];

    int root1, root2, n;
    scanf("%d%d%d", &root1, &root2, &n);

    for (int i = 0; i < n; ++i) {
        int idx;
        scanf("%d%*c", &idx);
        Node_a_1032 &node = nodes[idx];
        scanf("%c%d", &node.c, &node.next);
    }

    int next = root1;
    while (next != -1) {
        nodes[next].vis = true;
        next = nodes[next].next;
    }

    next = root2;
    while (next != -1) {
        if (nodes[next].vis) {
            printf("%05d\n", next);
            return;
        }
        next = nodes[next].next;
    }
    printf("-1\n");
}

namespace {
struct Node_a_1052 {
    int address, value, next;
    bool vis;
    Node_a_1052() : address(0), value(0x3F3F3F3F), next(0), vis(false) {}
};
} // namespace

void pat_a_1052() {
    const int maxn = 100000;

    Node_a_1052 nodes[maxn];

    int n, root;
    scanf("%d%d", &n, &root);

    for (int i = 0, idx; i < n; ++i) {
        scanf("%d", &idx);
        Node_a_1052 &node = nodes[idx];
        node.address = idx;
        scanf("%d%d", &node.value, &node.next);
    }

    int cnt = 0;
    int next = root;
    while (next != -1) {
        ++cnt;
        nodes[next].vis = true;
        next = nodes[next].next;
    }

    for (int i = 0; i < maxn; ++i)
        if (!nodes[i].vis)
            nodes[i].value = 0x3F3F3F3F;

    std::sort(nodes, nodes + maxn,
              [](const auto &a, const auto &b) { return a.value < b.value; });

    root = nodes[0].address;
    if (cnt == 0) // special!
        printf("%d %d\n", cnt, -1);
    else
        printf("%d %05d\n", cnt, root);

    for (int i = 0; i < cnt; ++i) {
        if (i < cnt - 1)
            printf("%05d %d %05d\n", nodes[i].address, nodes[i].value,
                   nodes[i + 1].address);
        else
            printf("%05d %d %d\n", nodes[i].address, nodes[i].value, -1);
    }
}

namespace {
struct Node_a_1097 {
    int address, value, next;
    Node_a_1097() : address(0), value(0), next(0) {}
};
} // namespace

void pat_a_1097() {
    const int maxn = 100000;

    Node_a_1097 nodes[maxn];
    std::unordered_set<int> s;

    int root, n;
    scanf("%d%d", &root, &n);

    for (int i = 0, idx; i < n; ++i) {
        scanf("%d", &idx);
        Node_a_1097 &node = nodes[idx];
        node.address = idx;
        scanf("%d%d", &node.value, &node.next);
    }

    int root1 = -1, p1 = -1;
    int root2 = -1, p2 = -1;
    int p = root;
    while (p != -1) {
        Node_a_1097 &node = nodes[p];
        if (s.find(static_cast<int>(abs(node.value))) != s.end()) {
            if (root2 == -1)
                root2 = node.address;
            else
                nodes[p2].next = node.address;
            p2 = node.address;
        } else {
            s.insert(static_cast<int>(abs(node.value)));
            if (root1 == -1)
                root1 = node.address;
            else
                nodes[p1].next = node.address;
            p1 = node.address;
        }
        p = node.next;
    }
    nodes[p1].next = -1;
    if (p2 != -1)
        nodes[p2].next = -1;

    p1 = root1;
    while (p1 != -1) {
        Node_a_1097 &node = nodes[p1];
        if (node.next == -1)
            printf("%05d %d %d\n", p1, node.value, node.next);
        else
            printf("%05d %d %05d\n", p1, node.value, node.next);
        p1 = node.next;
    }
    p2 = root2;
    while (p2 != -1) {
        Node_a_1097 &node = nodes[p2];
        if (node.next == -1)
            printf("%05d %d %d\n", p2, node.value, node.next);
        else
            printf("%05d %d %05d\n", p2, node.value, node.next);
        p2 = node.next;
    }
}

namespace {
void dfs_a_1103(int idx, int n, int k, int p, int sum, int facSum,
                int &maxFacSum, std::vector<int> &tmp, std::vector<int> &ret) {
    int add = static_cast<int>(pow(1.0 * idx, p));
    sum += add;

    if (tmp.size() < k && sum <= n) {
        tmp.push_back(idx);
        facSum += idx;
        if (sum == n) {
            if (tmp.size() == k && facSum > maxFacSum) {
                maxFacSum = facSum;
                ret = tmp;
            }
        } else {
            dfs_a_1103(idx, n, k, p, sum, facSum, maxFacSum, tmp, ret);
        }
        facSum -= idx;
        tmp.pop_back();
    }

    if (idx > 1) {
        sum -= add;
        dfs_a_1103(idx - 1, n, k, p, sum, facSum, maxFacSum, tmp,
                   ret); // from large to small, then no need to sort
    }
}
} // namespace

void pat_a_1103() {
    int n, k, p;
    scanf("%d%d%d", &n, &k, &p);

    int right = static_cast<int>(sqrt(1.0 * n));
    std::vector<int> tmp, ret;
    int maxFacSum = 0;
    dfs_a_1103(right, n, k, p, 0, 0, maxFacSum, tmp, ret);

    if (ret.size() == 0)
        printf("Impossible\n");
    else {
        printf("%d = ", n);
        for (int i = 0; i < ret.size(); ++i) {
            if (i)
                printf(" + ");
            printf("%d^%d", ret[i], p);
        }
        printf("\n");
    }
}

namespace {
// whether (i, j, k) needs to be visited
bool judge_a_1091(std::vector<std::vector<std::vector<bool>>> &pixels,
                  std::vector<std::vector<std::vector<bool>>> &inq, const int i,
                  const int j, const int k, const int l, const int m,
                  const int n) {
    if (i < 0 || i >= l || j < 0 || j >= m || k < 0 || k >= n ||
        !pixels[i][j][k] || inq[i][j][k])
        return false;
    return true;
}

int bfs_a_1091(std::vector<std::vector<std::vector<bool>>> &pixels,
               std::vector<std::vector<std::vector<bool>>> &inq, const int i,
               const int j, const int k, const int l, const int m,
               const int n) {
    int X[6] = {1, -1, 0, 0, 0, 0};
    int Y[6] = {0, 0, 1, -1, 0, 0};
    int Z[6] = {0, 0, 0, 0, 1, -1};

    std::queue<std::tuple<int, int, int>> q;
    q.push({i, j, k});
    inq[i][j][k] = true;

    int volume = 1;

    while (!q.empty()) {
        auto [a, b, c] = q.front();
        q.pop();

        for (int i = 0; i < 6; ++i) {
            int tA = a + X[i];
            int tB = b + Y[i];
            int tC = c + Z[i];
            if (judge_a_1091(pixels, inq, tA, tB, tC, l, m, n)) {
                ++volume;
                inq[tA][tB][tC] = true;
                q.push({tA, tB, tC});
            }
        }
    }

    return volume;
}
} // namespace

void pat_a_1091() // using dfs will cause stack overflow
{
    using std::vector;

    const int maxm = 1286; // 1286
    const int maxn = 129;  // 128
    const int maxl = 61;   // 60

    /*
        should simply use a larger number than the limit: 128 -> 130, 60 -> 80
        do not use the limit directly, maybe the question itself has problems
    */

    int m, n, l, t, b;
    scanf("%d%d%d%d", &m, &n, &l, &t);

    if (l >= maxl || m >= maxm || n >= maxn)
        return; // wrong if set maxn = 128, maxl = 60

    vector<vector<vector<bool>>> pixels(
        maxl, vector<vector<bool>>(maxm, vector<bool>(maxn, false)));
    // pixels[maxl][maxm][maxn] is too large to declare on stack,
    // std::vector<bool> only store one bit for bool, std::vector<bool> cannot
    // be assinged like scanf("%d", &vec[0]);
    vector<vector<vector<bool>>> inq(
        maxl, vector<vector<bool>>(maxm, vector<bool>(maxn, false)));

    for (int i = 0; i < l; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < n; ++k) {
                scanf("%d", &b);
                if (b)
                    pixels[i][j][k] = true;
            }

    int ret = 0;
    for (int i = 0; i < l; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < n; ++k)
                if (judge_a_1091(pixels, inq, i, j, k, l, m, n)) {
                    int volume = bfs_a_1091(pixels, inq, i, j, k, l, m, n);
                    if (volume >= t)
                        ret += volume;
                }

    printf("%d\n", ret);
}

namespace {
void getLevelFromPostAndIn_a_1020(int postSeq[], int inSeq[],
                                  std::vector<std::vector<int>> &levelSeq,
                                  int pl, int pr, int il, int ir,
                                  int layer = 0) {
    if (pl == pr || il == ir)
        return;

    int root = postSeq[pr - 1];
    levelSeq[layer].push_back(root);

    int lLen = 0;
    for (int i = il; i < ir; ++i)
        if (inSeq[i] == root) {
            lLen = i - il;
            break;
        }

    getLevelFromPostAndIn_a_1020(postSeq, inSeq, levelSeq, pl, pl + lLen, il,
                                 il + lLen, layer + 1);
    getLevelFromPostAndIn_a_1020(postSeq, inSeq, levelSeq, pl + lLen, pr - 1,
                                 il + lLen + 1, ir, layer + 1);
}
} // namespace

void pat_a_1020() {
    const int maxn = 30;

    int inSeq[maxn], postSeq[maxn];

    int n;
    scanf("%d", &n);

    std::vector<std::vector<int>> levelSeq(n, std::vector<int>());

    for (int i = 0; i < n; ++i)
        scanf("%d", &postSeq[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &inSeq[i]);

    getLevelFromPostAndIn_a_1020(postSeq, inSeq, levelSeq, 0, n, 0, n);

    for (int i = 0; i < levelSeq.size(); ++i)
        for (int j = 0; j < levelSeq[i].size(); ++j) {
            if (i || j)
                printf(" ");
            printf("%d", levelSeq[i][j]);
        }
    printf("\n");
}

namespace {
void getPostFromPreAndIn_a_1086(int preSeq[], int inSeq[], int postSeq[],
                                int pl, int pr, int il, int ir, int idx) {
    if (pl == pr || il == ir)
        return;

    int root = preSeq[pl];
    postSeq[idx - 1] = root;

    int len = ir - il;
    int lLen = 0;
    for (int i = il; i < ir; ++i)
        if (inSeq[i] == root) {
            lLen = i - il;
            break;
        }
    int rLen = len - lLen - 1;

    getPostFromPreAndIn_a_1086(preSeq, inSeq, postSeq, pl + 1, pl + 1 + lLen,
                               il, il + lLen, idx - 1 - rLen);
    getPostFromPreAndIn_a_1086(preSeq, inSeq, postSeq, pl + 1 + lLen, pr,
                               il + lLen + 1, ir, idx - 1);
}
} // namespace

void pat_a_1086() {
    const int maxn = 30;

    int preSeq[maxn], inSeq[maxn], postSeq[maxn];
    int preIdx = 0, inIdx = 0;

    std::stack<int> s;

    int n;
    char op[5];
    scanf("%d", &n);

    for (int i = 0; i < 2 * n; ++i) {
        scanf("%s", op);
        if (strcmp(op, "Push") == 0) {
            scanf("%d", &preSeq[preIdx]);
            s.push(preSeq[preIdx++]);
        } else // "Pop"
        {
            inSeq[inIdx++] = s.top();
            s.pop();
        }
    }

    getPostFromPreAndIn_a_1086(preSeq, inSeq, postSeq, 0, n, 0, n, n);

    for (int i = 0; i < n; ++i) {
        if (i)
            printf(" ");
        printf("%d", postSeq[i]);
    }
}

namespace {
struct Node_a_1102 {
    int left;
    int right;
};

void invert_a_1102(Node_a_1102 nodes[], int root) {
    if (root == -1)
        return;

    Node_a_1102 &node = nodes[root];
    invert_a_1102(nodes, node.left);
    invert_a_1102(nodes, node.right);
    std::swap(node.left, node.right);
}

int getRoot_a_1102(Node_a_1102 nodes[], const int n) {
    const int maxn = 10;
    int isChild[maxn] = {0};

    for (int i = 0; i < n; ++i) {
        if (nodes[i].left != -1)
            isChild[nodes[i].left] = 1;
        if (nodes[i].right != -1)
            isChild[nodes[i].right] = 1;
    }

    for (int i = 0; i < n; ++i)
        if (!isChild[i])
            return i;
    return -1;
}

void getLevelSeq_a_1102(Node_a_1102 nodes[], int root, int levelSeq[]) {
    int idx = 0;
    std::queue<int> q;
    q.push(root);

    while (!q.empty()) {
        Node_a_1102 &node = nodes[q.front()];
        levelSeq[idx++] = q.front();
        q.pop();

        if (node.left != -1)
            q.push(node.left);
        if (node.right != -1)
            q.push(node.right);
    }
}

void getInSeq_a_1102(Node_a_1102 nodes[], int root, int inSeq[]) {
    int idx = 0;
    std::stack<int> s;

    while (root != -1) {
        s.push(root);
        root = nodes[root].left;
    }

    while (!s.empty()) {
        root = s.top();
        inSeq[idx++] = s.top();
        s.pop();

        if (nodes[root].right != -1) {
            root = nodes[root].right;
            while (root != -1) {
                s.push(root);
                root = nodes[root].left;
            }
        }
    }
}
} // namespace

void pat_a_1102() {
    const int maxn = 10;

    int levelSeq[maxn], inSeq[maxn];

    Node_a_1102 nodes[maxn];

    int n;
    scanf("%d%*c", &n);

    char l, r;
    for (int i = 0; i < n; ++i) {
        scanf("%c %c%*c", &l, &r);
        nodes[i].left = (l == '-') ? -1 : (l - '0');
        nodes[i].right = (r == '-') ? -1 : (r - '0');
    }

    int root = getRoot_a_1102(nodes, n);

    invert_a_1102(nodes, root);

    getLevelSeq_a_1102(nodes, root, levelSeq);
    getInSeq_a_1102(nodes, root, inSeq);

    for (int i = 0; i < n; ++i) {
        if (i)
            printf(" ");
        printf("%d", levelSeq[i]);
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        if (i)
            printf(" ");
        printf("%d", inSeq[i]);
    }
    printf("\n");
}

namespace {
struct Node_a_1079 {
    int value;
    bool isRetailer = false;
    std::vector<int> children;
};

double traverse_a_1079(Node_a_1079 nodes[], int root, double p, double r) {
    double ret = 0.0;

    std::queue<int> q;
    q.push(root);

    int layer = 0;
    while (!q.empty()) {
        ++layer;
        int size = q.size();
        while (size--) {
            Node_a_1079 &node = nodes[q.front()];
            q.pop();

            // price from root supplier is p not p * (1 + 4 / 100) !
            if (node.isRetailer)
                ret += node.value * p * pow(1 + r / 100, layer - 1);
            else {
                for (const auto &child : node.children)
                    q.push(child);
            }
        }
    }
    return ret;
}
} // namespace

void pat_a_1079() {
    const int maxn = 100000;

    Node_a_1079 nodes[maxn];

    int n;
    double p, r;
    scanf("%d%lf%lf", &n, &p, &r);

    for (int i = 0, k; i < n; ++i) {
        scanf("%d", &k);
        Node_a_1079 &node = nodes[i];
        if (k == 0) {
            scanf("%d", &node.value);
            node.isRetailer = true;
        } else { // k > 0
            for (int j = 0, t; j < k; ++j) {
                scanf("%d", &t);
                node.children.push_back(t);
            }
        }
    }

    double ret = traverse_a_1079(nodes, 0, p, r);
    printf("%.1lf\n", ret);
}

namespace {
struct Node_a_1090 {
    std::vector<int> children;
};

std::pair<double, int> traverse_a_1090(Node_a_1090 nodes[], int root, double p,
                                       double r) {
    std::queue<int> q;
    q.push(root);

    int layer = 0;
    double max = 0.0;
    int cnt = 0;
    while (!q.empty()) {
        ++layer;
        int size = q.size();
        while (size--) {
            Node_a_1090 &node = nodes[q.front()];
            q.pop();
            if (node.children.size() == 0) {
                double t = p * pow(1 + r / 100, layer - 1);
                if (t > max) {
                    max = t;
                    cnt = 1;
                } else if (fabs(t - max) <
                           std::numeric_limits<double>::epsilon())
                    ++cnt;

            } else {
                for (const auto &child : node.children)
                    q.push(child);
            }
        }
    }

    return {max, cnt};
}
} // namespace

void pat_a_1090() {
    const int maxn = 100000;

    Node_a_1090 nodes[maxn];

    int n;
    double p, r;
    scanf("%d%lf%lf", &n, &p, &r);

    int root;
    for (int i = 0, t; i < n; ++i) {
        scanf("%d", &t);
        if (t == -1)
            root = i;
        else
            nodes[t].children.push_back(i);
    }

    auto [max, cnt] = traverse_a_1090(nodes, root, p, r);
    printf("%.2lf %d\n", max, cnt);
}

namespace {
struct Node_a_1094 {
    std::vector<int> children;
};

std::pair<int, int> bfs_a_1094(Node_a_1094 nodes[], int root) {
    std::queue<int> q;
    q.push(root);

    int level = 0;
    int maxN = 0, maxL = 0;
    while (!q.empty()) {
        ++level;
        int size = q.size();
        if (size > maxN) {
            maxN = size;
            maxL = level;
        }
        while (size--) {
            Node_a_1094 &node = nodes[q.front()];
            q.pop();
            for (const auto &child : node.children)
                q.push(child);
        }
    }

    return {maxN, maxL};
}
} // namespace

void pat_a_1094() {
    const int maxn = 100;

    Node_a_1094 nodes[maxn];

    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0, id, k, t; i < m; ++i) {
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &t);
            nodes[id].children.push_back(t);
        }
    }

    int root = 1;
    auto [maxN, maxL] = bfs_a_1094(nodes, root);
    printf("%d %d\n", maxN, maxL);
}

namespace {
struct Node_a_1106 {
    bool isRetailer = false;
    std::vector<int> children;
};

std::pair<double, int> bfs_a_1106(Node_a_1106 nodes[], int root, double p,
                                  double r) {
    std::queue<int> q;
    q.push(root);

    int level = 0;
    double minPrice = std::numeric_limits<double>::max();
    int cnt = 0;
    while (!q.empty()) {
        ++level;
        int size = q.size();
        while (size--) {
            Node_a_1106 &node = nodes[q.front()];
            q.pop();

            if (node.isRetailer) {
                double t = p * pow(1 + r / 100, level - 1);
                if (t < minPrice) {
                    minPrice = t;
                    cnt = 1;
                } else if (fabs(t - minPrice) <
                           std::numeric_limits<double>::epsilon())
                    ++cnt;
            } else {
                for (const auto &child : node.children)
                    q.push(child);
            }
        }
    }

    return {minPrice, cnt};
}
} // namespace

void pat_a_1106() {
    const int maxn = 100000;

    Node_a_1106 nodes[maxn];

    int n;
    double p, r;
    scanf("%d%lf%lf", &n, &p, &r);

    for (int i = 0, k, t; i < n; ++i) {
        scanf("%d", &k);
        if (k == 0)
            nodes[i].isRetailer = true;
        else {
            for (int j = 0; j < k; ++j) {
                scanf("%d", &t);
                nodes[i].children.push_back(t);
            }
        }
    }

    auto [minPrice, cnt] = bfs_a_1106(nodes, 0, p, r);
    printf("%.4lf %d\n", minPrice, cnt);
}

namespace {
struct Node_a_1004 {
    std::vector<int> children;
};

void bfs_a_1004(Node_a_1004 nodes[], int root, std::vector<int> &result) {
    std::queue<int> q;
    q.push(root);

    int cnt = 0;
    while (!q.empty()) {
        int size = q.size();
        int cnt = 0;
        while (size--) {
            Node_a_1004 &node = nodes[q.front()];
            q.pop();

            if (node.children.size() == 0)
                ++cnt;
            else {
                for (const auto &child : node.children)
                    q.push(child);
            }
        }
        result.push_back(cnt);
    }
}
} // namespace

void pat_a_1004() {
    const int maxn = 100;

    Node_a_1004 nodes[maxn];

    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0, id, k; i < m; ++i) {
        scanf("%d%d", &id, &k);
        for (int j = 0, t; j < k; ++j) {
            scanf("%d", &t);
            nodes[id].children.push_back(t);
        }
    }

    int root = 1;
    std::vector<int> result;
    bfs_a_1004(nodes, 1, result);

    for (int i = 0; i < result.size(); ++i) {
        if (i)
            printf(" ");
        printf("%d", result[i]);
    }
    printf("\n");
}

namespace {
struct Node_a_1053 {
    int weight;
    std::vector<int> children;
};

void dfs_a_1053(const Node_a_1053 nodes[], int root, const int s,
                std::vector<std::vector<int>> &result, std::vector<int> &tmp,
                int sum = 0) {
    sum += nodes[root].weight;
    tmp.push_back(nodes[root].weight);

    if (sum > s) {
        tmp.pop_back();
        return;
    }
    if (sum == s) // the reason to judge here not inside the for loop is that
                  // nodes[root].weight could equal s
    {
        if (nodes[root].children.size() == 0)
            result.push_back(tmp);
        tmp.pop_back();
        return;
    }

    for (const auto &child : nodes[root].children)
        dfs_a_1053(nodes, child, s, result, tmp, sum);

    tmp.pop_back();
    sum -= nodes[root].weight;
}
} // namespace

void pat_a_1053() {
    const int maxn = 100;

    Node_a_1053 nodes[maxn];

    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);

    for (int i = 0; i < n; ++i)
        scanf("%d", &nodes[i].weight);

    for (int i = 0, id, k; i < m; ++i) {
        scanf("%d%d", &id, &k);
        for (int j = 0, t; j < k; ++j) {
            scanf("%d", &t);
            nodes[id].children.push_back(t);
        }

        // only sort here is wrong because of such situation: 5 3 2; 5 3 4,
        // althouth the weight 3 is the same, do not know their children's
        // weights

        // std::sort(nodes[id].children.begin(), nodes[id].children.end(),
        //           [&nodes](const auto &a, const auto &b) {
        //               return nodes[a].weight > nodes[b].weight;
        //           });
    }

    int root = 0;
    std::vector<std::vector<int>> result;
    std::vector<int> tmp;
    dfs_a_1053(nodes, root, s, result, tmp);

    // simply sort, no need to consider such situation: 1 2 and 1 2 3
    // the question also does not give a comparison of such situation
    std::sort(result.rbegin(), result.rend());

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            if (j)
                printf(" ");
            printf("%d", result[i][j]);
        }
        printf("\n");
    }
}

namespace {
struct Node_a_1043 {
    int value;
    Node_a_1043 *left, *right;
    Node_a_1043(int v = 0) : value(v), left(nullptr), right(nullptr) {}
};

void insert_a_1043(Node_a_1043 *&root, int value) {
    if (!root) {
        root = new Node_a_1043(value);
        return;
    }
    if (value >= root->value)
        insert_a_1043(root->right, value);
    else
        insert_a_1043(root->left, value);
}

Node_a_1043 *create_a_1043(int arr[], int n) {
    Node_a_1043 *root = nullptr;
    for (int i = 0; i < n; ++i) {
        insert_a_1043(root, arr[i]);
    }
    return root;
}

void preTraverse_a_1043(Node_a_1043 *root, int arr[]) {
    if (!root)
        return;

    std::stack<Node_a_1043 *> s;
    s.push(root);

    int idx = 0;
    while (!s.empty()) {
        root = s.top();
        s.pop();

        arr[idx++] = root->value;

        if (root->right)
            s.push(root->right);
        if (root->left)
            s.push(root->left);
    }
}

void postTraverse_a_1043(Node_a_1043 *root, int arr[]) {
    if (!root)
        return;

    std::stack<Node_a_1043 *> s;

    while (root) {
        s.push(root);
        root = root->left;
    }

    int idx = 0;
    Node_a_1043 *last = nullptr;
    while (!s.empty()) {
        root = s.top();

        if (last == root->right || !root->right) {
            arr[idx++] = root->value;
            s.pop();
            last = root;
        } else {
            if (root->right) {
                root = root->right;
                while (root) {
                    s.push(root);
                    root = root->left;
                }
            }
        }
    }
}

void mirror_a_1043(Node_a_1043 *root) {
    if (!root)
        return;
    mirror_a_1043(root->left);
    mirror_a_1043(root->right);
    std::swap(root->left, root->right);
}

bool arrEqual_a_1043(int a[], int b[], int n) {
    for (int i = 0; i < n; ++i)
        if (a[i] != b[i])
            return false;
    return true;
}

void delete_a_1043(Node_a_1043 *root) {
    if (!root)
        return;

    delete_a_1043(root->left);
    root->left = nullptr;

    delete_a_1043(root->right);
    root->right = nullptr;

    delete root;
}
} // namespace

void pat_a_1043() {
    const int maxn = 1000;

    int arr[maxn];
    int preOrder[maxn], postOrder[maxn];

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    Node_a_1043 *root = create_a_1043(arr, n);

    preTraverse_a_1043(root, preOrder);
    if (!arrEqual_a_1043(arr, preOrder, n)) {
        mirror_a_1043(root);
        preTraverse_a_1043(root, preOrder);
    }

    if (arrEqual_a_1043(arr, preOrder, n)) {
        printf("YES\n");
        postTraverse_a_1043(root, postOrder);
        for (int i = 0; i < n; ++i) {
            if (i)
                printf(" ");
            printf("%d", postOrder[i]);
        }
        printf("\n");
    } else {
        printf("NO\n");
    }

    delete_a_1043(root);
    root = nullptr;
}

namespace {
void inOrder_a_1064(int arr[], int n, int result[]) {
    std::stack<int> s;

    int node = 1;
    while (node <= n) {
        s.push(node);
        node *= 2;
    }

    int idx = 0;
    while (!s.empty()) {
        node = s.top();
        s.pop();

        result[node] = arr[idx++]; // inOrder of CBT is an non-decreasing array

        if (node * 2 + 1 <= n) {
            node = node * 2 + 1;
            while (node <= n) {
                s.push(node);
                node *= 2;
            }
        }
    }
}
} // namespace

void pat_a_1064() {
    const int maxn = 1000 + 1;

    int arr[maxn], result[maxn];

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    std::sort(arr, arr + n);

    inOrder_a_1064(arr, n, result);

    for (int i = 1; i <= n; ++i) {
        if (i > 1)
            printf(" ");
        printf("%d", result[i]);
    }
    printf("\n");
}

namespace {
struct Node_a_1099 {
    int value;
    int left, right;
    Node_a_1099(int v = 0, int l = -1, int r = -1)
        : value(v), left(l), right(r) {}
};

void inOrder_a_1099(Node_a_1099 nodes[], int root, int arr[]) {
    std::stack<int> s;

    while (root != -1) {
        s.push(root);
        root = nodes[root].left;
    }

    int idx = 0;
    while (!s.empty()) {
        root = s.top();
        s.pop();

        nodes[root].value = arr[idx++];

        if (nodes[root].right != -1) {
            root = nodes[root].right;
            while (root != -1) {
                s.push(root);
                root = nodes[root].left;
            }
        }
    }
}

void levelOrder_a_1099(Node_a_1099 nodes[], int root, int result[]) {
    std::queue<int> q;

    q.push(root);

    int idx = 0;
    while (!q.empty()) {
        root = q.front();
        q.pop();

        result[idx++] = nodes[root].value;

        if (nodes[root].left != -1)
            q.push(nodes[root].left);
        if (nodes[root].right != -1)
            q.push(nodes[root].right);
    }
}
} // namespace

void pat_a_1099() {
    const int maxn = 100;

    int arr[maxn], result[maxn];
    Node_a_1099 nodes[maxn];

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &nodes[i].left, &nodes[i].right);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    std::sort(arr, arr + n);
    inOrder_a_1099(nodes, 0, arr);
    levelOrder_a_1099(nodes, 0, result);

    for (int i = 0; i < n; ++i) {
        if (i)
            printf(" ");
        printf("%d", result[i]);
    }
    printf("\n");
}

namespace {
struct Node_a_1066 {
    int value;
    int height;
    Node_a_1066 *left, *right;
    Node_a_1066(int v = 0, int h = 1)
        : value(v), height(h), left(nullptr), right(nullptr) {}
};

int getHeight_a_1066(Node_a_1066 *root) {
    if (!root)
        return 0;
    return root->height;
}

void updateHeight_a_1066(Node_a_1066 *root) {
    root->height =
        std::max(getHeight_a_1066(root->left), getHeight_a_1066(root->right)) +
        1;
}

int getBalanceFactor_a_1066(Node_a_1066 *root) {
    return getHeight_a_1066(root->left) - getHeight_a_1066(root->right);
}

void L(Node_a_1066 *&root) {
    Node_a_1066 *tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    updateHeight_a_1066(root);
    updateHeight_a_1066(tmp);
    root = tmp;
}

void R(Node_a_1066 *&root) {
    Node_a_1066 *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    updateHeight_a_1066(root);
    updateHeight_a_1066(tmp);
    root = tmp;
}

void insert_a_1066(Node_a_1066 *&root, int value) {
    if (!root) {
        root = new Node_a_1066(value);
        return;
    }

    if (value >= root->value)
        insert_a_1066(root->right, value);
    else
        insert_a_1066(root->left, value);

    int factor = getBalanceFactor_a_1066(root);
    if (factor == 2) {
        if (getBalanceFactor_a_1066(root->left) == 1) { // LL
            R(root);
        } else { // LR
            L(root->left);
            R(root);
        }
    } else if (factor == -2) {
        if (getBalanceFactor_a_1066(root->right) == -1) { // RR
            L(root);
        } else { // RL
            R(root->right);
            L(root);
        }
    }

    updateHeight_a_1066(root);
}

void delete_a_1066(Node_a_1066 *root) {
    if (!root)
        return;
    delete_a_1066(root->left);
    root->left = nullptr;
    delete_a_1066(root->right);
    root->right = nullptr;
    delete root;
}
} // namespace

void pat_a_1066() {
    Node_a_1066 *root = nullptr;

    int n;
    scanf("%d", &n);
    for (int i = 0, t; i < n; ++i) {
        scanf("%d", &t);
        insert_a_1066(root, t);
    }

    printf("%d\n", root->value);

    delete_a_1066(root);
}

namespace {
int findFather_a_1107(int arr[], int a) {
    int fa = a;
    while (fa != arr[fa])
        fa = arr[fa];
    while (a != fa) {
        int tmp = arr[a];
        arr[a] = fa;
        a = tmp;
    }
    return fa;
}

void Union_a_1107(int arr[], int a, int b) {
    int fa = findFather_a_1107(arr, a);
    int fb = findFather_a_1107(arr, b);
    if (fa != fb)
        arr[fa] = fb;
}
} // namespace

void pat_a_1107() {
    const int maxn = 1000 + 1;

    int people[maxn] = {0};
    int hobbies[maxn] = {0};
    int cnt[maxn] = {0};

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        people[i] = i;

    for (int i = 1, k; i <= n; ++i) {
        scanf("%d:", &k);
        for (int j = 0, t; j < k; ++j) {
            scanf("%d", &t);
            if (hobbies[t] == 0)
                hobbies[t] = i;
            Union_a_1107(people, i, findFather_a_1107(people, hobbies[t]));
        }
    }

    for (int i = 1; i <= n; ++i)
        ++cnt[findFather_a_1107(people, i)];

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (cnt[i])
            ++ans;

    std::sort(cnt + 1, cnt + n + 1, std::greater<int>());
    printf("%d\n", ans);
    for (int i = 1; i <= ans; ++i) {
        if (i > 1)
            printf(" ");
        printf("%d", cnt[i]);
    }
    printf("\n");
}

namespace {
namespace a_1098 {
void showArray(int arr[], int n) {
    for (int i = 1; i <= n; ++i) {
        if (i > 1)
            printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

bool isSame(int A[], int B[], int n) {
    for (int i = 1; i <= n; ++i)
        if (A[i] != B[i])
            return false;
    return true;
}

bool insertionSort(int arr[], int n, int tmp[]) {
    bool flag = false;

    for (int i = 2; i <= n; ++i) {
        int t = arr[i];
        int j = i - 1;
        while (j >= 1 && t < arr[j]) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = t;

        if (flag) {
            printf("Insertion Sort\n");
            showArray(arr, n);
            break;
        }
        if (isSame(arr, tmp, n))
            flag = true;
    }

    return flag;
}

void downAdjust(int arr[], int i, int n) {
    int j = i * 2;
    while (j <= n) {
        if (j + 1 <= n && arr[j] < arr[j + 1])
            j = j + 1;
        if (arr[i] < arr[j]) {
            std::swap(arr[i], arr[j]);
            i = j;
            j = i * 2;
        } else {
            break;
        }
    }
}

bool heapSort(int arr[], int n, int tmp[]) {
    for (int i = n / 2; i >= 1; --i)
        downAdjust(arr, i, n);

    bool flag = false;

    for (int i = n; i >= 2; --i) {
        std::swap(arr[1], arr[i]);
        downAdjust(arr, 1, i - 1);

        if (flag) {
            printf("Heap Sort\n");
            showArray(arr, n);
            break;
        }
        if (isSame(arr, tmp, n))
            flag = true;
    }

    return flag;
}
} // namespace a_1098
} // namespace

void pat_a_1098() {
    const int maxn = 101;

    int arr1[maxn], arr2[maxn];
    int tmp[maxn];

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &tmp[i]);

    if (!a_1098::insertionSort(arr1, n, tmp))
        a_1098::heapSort(arr2, n, tmp);
    // or
    // if (!a_1098::heapSort(arr1, n, tmp))
    //     a_1098::insertionSort(arr2, n, tmp);
}

namespace {
namespace a_1013 {
const int maxn = 1001;

int getSetNum(bool g[][maxn], int n, int k) {
    bool vis[maxn] = {0};
    int ret = 0;

    for (int i = 1; i <= n; ++i) {
        if (i == k || vis[i])
            continue;

        ++ret;

        std::queue<int> q;
        q.push(i);
        vis[i] = true;

        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int j = 1; j <= n; ++j) {
                if (j == k || vis[j] || !g[t][j])
                    continue;
                q.push(j);
                vis[j] = true;
            }
        }
    }

    return ret;
}
} // namespace a_1013
} // namespace

void pat_a_1013() {
    using a_1013::maxn;

    bool g[maxn][maxn] = {0};
    int key[maxn];

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0, a, b; i < m; ++i) {
        scanf("%d%d", &a, &b);
        g[a][b] = g[b][a] = true;
    }
    for (int i = 0; i < k; ++i)
        scanf("%d", &key[i]);

    for (int i = 0; i < k; ++i)
        printf("%d\n", a_1013::getSetNum(g, n, key[i]) - 1);
}

namespace {
namespace a_1021 {
const int maxn = 10001;
std::vector<int> adj[maxn];
int n;

int getComponentsNum() {
    std::vector<bool> vis(n + 1, false);

    int cnt = 0;

    for (int i = 1; i <= n; ++i) {
        if (vis[i])
            continue;

        ++cnt;
        std::queue<int> q;
        q.push(i);
        vis[i] = true;

        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (const auto &it : adj[t]) {
                if (vis[it])
                    continue;
                q.push(it);
                vis[it] = true;
            }
        }
    }

    return cnt;
}

void getDeepestDepth(std::vector<int> &result) {
    int maxDepth = -1;
    for (int i = 1; i <= n; ++i) {
        std::vector<bool> vis(n + 1, false);

        std::queue<int> q;
        q.push(i);
        vis[i] = true;

        int depth = 0;
        while (!q.empty()) {
            ++depth;
            int size = q.size();
            while (size--) {
                int t = q.front();
                q.pop();

                for (const auto &it : adj[t]) {
                    if (vis[it])
                        continue;
                    q.push(it);
                    vis[it] = true;
                }
            }
        }

        if (depth > maxDepth) {
            maxDepth = depth;
            result.clear();
            result.push_back(i);
        } else if (depth == maxDepth) {
            result.push_back(i);
        }
    }
}
} // namespace a_1021
} // namespace

void pat_a_1021() {
    using namespace a_1021;

    scanf("%d", &n);

    for (int i = 0, a, b; i < n - 1; ++i) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int k = getComponentsNum();
    if (k > 1) {
        printf("Error: %d components\n", k);
        return;
    }

    std::vector<int> result;
    getDeepestDepth(result);

    for (const auto &it : result)
        printf("%d\n", it);
}

namespace {
namespace a_1034 {
const int maxn = 2010; // 1000 phone calls could have 2000 people!
int w[maxn];
int g[maxn][maxn];

int n, k;

std::unordered_map<std::string, int> m1;
std::unordered_map<int, std::string> m2;
int mIdx = 0;
int map1(const char str[]) {
    if (m1.find(str) == m1.end()) {
        m1[str] = mIdx;
        m2[mIdx] = str;
        ++mIdx;
    }
    return m1[str];
}

std::string map2(int num) { return m2[num]; }

struct Node {
    int head, time, num;
    Node() : head(0), time(0), num(0) {}
};

void bfs(std::vector<Node> &result) {
    std::vector<bool> vis(mIdx, false);
    std::queue<int> q;

    for (int i = 0; i < mIdx; ++i) {
        if (vis[i])
            continue;

        Node node;
        int maxTime = -1;

        q.push(i);
        vis[i] = true;

        node.num += 1;
        if (w[i] > maxTime) {
            maxTime = w[i];
            node.head = i;
        }

        while (!q.empty()) {
            int t = q.front();
            q.pop();

            for (int j = 0; j < mIdx; ++j) {
                if (!g[t][j])
                    continue;

                node.time += g[t][j];
                // Delete this edge to prevent turning back!!!
                g[t][j] = g[j][t] = 0;

                if (vis[j])
                    continue;

                q.push(j);
                vis[j] = true;

                node.num += 1;
                if (w[j] > maxTime) {
                    maxTime = w[j];
                    node.head = j;
                }
            }
        }

        if (node.time > k && node.num > 2)
            result.push_back(node);
    }
}

void dfs(std::vector<Node> &result) {
    std::vector<bool> vis(mIdx, false);
    std::stack<int> s;

    for (int i = 0; i < mIdx; ++i) {
        if (vis[i])
            continue;

        Node node;
        int maxTime = -1;

        s.push(i);
        vis[i] = true;

        node.num += 1;
        if (w[i] > maxTime) {
            maxTime = w[i];
            node.head = i;
        }

        while (!s.empty()) {
            int t = s.top();

            int next = -1;
            for (int j = 0; j < mIdx; ++j) {
                if (!g[t][j])
                    continue;
                node.time += g[t][j];
                g[t][j] = g[j][t] = 0;
                if (vis[j])
                    continue;
                next = j;
                break;
            }

            if (next == -1) // different from bfs, pop here!!!
                s.pop();

            while (next != -1) {
                s.push(next);
                vis[next] = true;

                node.num += 1;
                if (w[next] > maxTime) {
                    maxTime = w[next];
                    node.head = next;
                }

                t = next;
                next = -1;
                for (int j = 0; j < mIdx; ++j) {
                    if (!g[t][j])
                        continue;
                    node.time += g[t][j];
                    g[t][j] = g[j][t] = 0;
                    if (vis[j])
                        continue;
                    next = j;
                    break;
                }
            }
        }

        if (node.time > k && node.num > 2)
            result.push_back(node);
    }
}
} // namespace a_1034
} // namespace

void pat_a_1034() {
    using namespace a_1034;

    scanf("%d%d", &n, &k);

    char name1[5], name2[5];
    int time;
    for (int i = 0; i < n; ++i) {
        scanf("%s%s%d", name1, name2, &time);
        int id1 = map1(name1);
        int id2 = map1(name2);
        w[id1] += time;
        w[id2] += time;
        g[id1][id2] += time;
        g[id2][id1] += time;
    }

    std::vector<Node> result;
    // bfs(result);
    // or
    dfs(result);
    std::sort(result.begin(), result.end(), [](const auto &a, const auto &b) {
        return map2(a.head) < map2(b.head);
    });

    printf("%zu\n", result.size());
    for (int i = 0; i < result.size(); ++i)
        printf("%s %d\n", map2(result[i].head).c_str(), result[i].num);
}
