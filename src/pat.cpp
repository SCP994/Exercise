#include "pat.h"

int pat_b_1001(int n)
{
    int cnt = 0;

    while (n != 1)
    {
        ++cnt;
        if (n % 2)
            n = (3 * n + 1) / 2;
        else
            n /= 2;
    }

    return cnt;
}

int pat_b_1011(long long A, long long B, long long C)
{
    if (A + B > C)
        return 1;
    return 0;
}

int pat_b_1016(int A, int DA, int B, int DB)
{
    int PA = 0;
    int PB = 0;
    while (A)
    {
        if (A % 10 == DA)
            PA = PA * 10 + DA;
        A /= 10;
    }
    while (B)
    {
        if (B % 10 == DB)
            PB = PB * 10 + DB;
        B /= 10;
    }
    return PA + PB;
}

void pat_b_1026(int C1, int C2)
{
    int duration = C2 - C1;
    int h = 0, m = 0, s = 0;
    const int BASE = 60;
    const int clk_tck = 100;

    s = duration % (BASE * clk_tck );
    duration /= (BASE * clk_tck );
    m = duration % BASE;
    duration /= BASE;
    h = duration % BASE;

    printf("%02d:%02d:%02d\n", h, m, (s + (clk_tck / 2))/ clk_tck);
}

int pat_b_1046(int a, int b, int c, int d)
{
    int total = a + c;
    if (b == total && d != total)
        return 2;
    if (b != total && d == total)
        return 1;
    return 0;
}

namespace
{
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
}

void pat_b_1008(int arr[], int n, int m)
{
    int g = gcd(n, m);
    for (int i = 0; i < g; ++i)
    {
        int b = i;
        int e = (b + m) % n;
        int t = arr[b];
        while (e != b)
        {
            std::swap(arr[e], t);
            e = (e + m) % n;
        }
        arr[e] = t;
    }
}

void pat_b_1032(int arr[])
{
    int n, index, score;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &index, &score);
        arr[index] += score;
    }
    int* p = std::max_element(arr + 1, arr + n + 1);
    printf("%d %d\n", static_cast<int>(p - arr), *p);
}

void pat_b_1012(int arr[])
{
    int cnt[5] = {0};
    int a[5] = {0};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", arr + i);

        int num = arr[i];
        int remainder = num % 5;
        if (remainder == 0)
        {
            if (num % 2 == 0)
            {
                ++cnt[0];
                a[0] += num;
            }
        }
        else if (remainder == 1)
        {
            if (cnt[1] % 2 == 0)
                a[1] += num;
            else
                a[1] -= num;
            ++cnt[1];
        }
        else if (remainder == 2)
        {
            ++cnt[2];
            ++a[2];
        }
        else if (remainder == 3)
        {
            ++cnt[3];
            a[3] += num;
        }
        else // remainder == 4
        {
            cnt[4] = 1;
            if (num > a[4])
                a[4] = num;
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (i)
            printf(" ");
        if (cnt[i])
        {
            if (i == 3)
                printf("%.1f", static_cast<double>(a[i]) / cnt[i]);
            else
                printf("%d", a[i]);
        }
        else
            printf("N");
    }
}

namespace
{
    int win_1018(char a, char b)
    {
        if (a == b)
            return 0;
        if (a == 'C' && b == 'J' || a == 'J' && b == 'B' || a == 'B' && b == 'C')
            return 1;
        return -1;
    }
}

void pat_b_1018()
{
    const char arr[] = {'B', 'C', 'J'};

    int n;
    scanf("%d", &n);

    char a, b;
    int resultA[3] = {0};
    std::unordered_map<char, int> numA = {{'C', 0}, {'J', 0}, {'B', 0}};
    std::unordered_map<char, int> numB = {{'C', 0}, {'J', 0}, {'B', 0}};

    for (int i = 0; i < n; ++i)
    {
        getchar();
        scanf("%c %c", &a, &b);
        int result = win_1018(a, b);
        if (result == 1)
        {
            ++resultA[0];
            ++numA[a];
        }
        else if (result == 0)
            ++resultA[1];
        else
        {
            ++resultA[2];
            ++numB[b];
        }
    }

    printf("%d %d %d\n", resultA[0], resultA[1], resultA[2]);
    printf("%d %d %d\n", resultA[2], resultA[1], resultA[0]);

    int cA = 0, cB = 0;
    for (int i = 1; i < 3; ++i)
    {
        if (numA[arr[i]] > numA[arr[cA]])
            cA = i;
        if (numB[arr[i]] > numB[arr[cB]])
            cB = i;
    }

    printf("%c %c\n", arr[cA], arr[cB]);
}

void pat_a_1042()
{
    const char strs[][5] = {
        "",
        "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
        "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
        "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
        "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
        "J1", "J2",
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
    while (k--)
    {
        for (int i = 1; i < 55; ++i)
            tmpOrder[shuffleOrder[i]] = order[i];
        std::swap(order, tmpOrder);
    }

    for (int i = 1; i < 55; ++i)
    {
        if (i > 1)
            printf(" ");
        printf("%s", strs[order[i]]);
    }
}

namespace
{
    int shortest_1046(int arr[], int n, int totalDistance, int s, int e)
    {
        int dis = arr[e] - arr[s];
        return dis < totalDistance - dis ? dis : totalDistance - dis;
    }
}

void pat_a_1046(int arr[])
{
    int n;
    scanf("%d", &n);
    int totalDistance = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", arr + i);
        totalDistance += arr[i];
        arr[i] += arr[i - 1];
    }

    int m, s, e;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &s, &e);
        --s;
        --e;
        if (s > e)
            std::swap(s, e);
        printf("%d\n", shortest_1046(arr, n, totalDistance, s, e));
    }
}

namespace
{
    bool judge_1065(long long a, long long b, long long c)
    {
        if (a >= 0 && b < 0 || a < 0 && b >= 0)
            return a + b > c;
        if (a >= 0 && c < 0 || a < 0 && c >= 0)
            return a >= 0;
        return a > c - b;
    }
}

void pat_a_1065()
{
    int n;
    scanf("%d", &n);
    long long a, b, c;
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        if (judge_1065(a, b, c))
            printf("Case #%d: true\n", i + 1);
        else
            printf("Case #%d: false\n", i + 1);
    }
}

void pat_b_1010()
{
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

void pat_a_1002()
{
    const float eps = 1e-5;

    float arr[1001] = {0};
    int k, a;
    float b;

    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d%f", &a, &b);
        arr[a] = b;
    }

    int total = k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
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

void pat_a_1009()
{
    const float eps = 1e-5;
    const int maxn = 2001;

    float arr1[maxn] = {0};
    float arr2[maxn] = {0};
    int k, a;
    float b;

    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d%f", &a, &b);
        arr1[a] = b;
    }

    int total = 0;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d%f", &a, &b);
        for (int j = 0; j < maxn; ++j)
            if (abs(arr1[j]) > eps)
            {
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

void pat_b_1041()
{
    std::unordered_map<int, std::pair<std::string, int>> map; // 数据量不大，可以直接用数组映射

    char license[20];
    int trial, real;

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s%d%d", license, &trial, &real);
        map[trial] = {std::string(license), real};
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &trial);
        printf("%s %d\n", map[trial].first.c_str(), map[trial].second);
    }
}

void pat_b_1004()
{
    char maxName[11], maxID[11], minName[11], minID[11];
    int maxScore = -1, minScore = 101;

    int n, score;
    scanf("%d", &n);

    char name[11], ID[11];
    for (int i = 0; i < n; ++i)
    {
        scanf("%s%s%d", name, ID, &score);
        if (score > maxScore)
        {
            maxScore = score;
            strcpy(maxName, name);
            strcpy(maxID, ID);
        }
        if (score < minScore)
        {
            minScore = score;
            strcpy(minName, name);
            strcpy(minID, ID);
        }
    }

    printf("%s %s\n", maxName, maxID);
    printf("%s %s\n", minName, minID);
}

void pat_b_1028()
{
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
    for (int i = 0; i < n; ++i)
    {
        scanf("%s%d/%d/%d", name, &year, &month, &day);

        if ((year > limitYear
        || year == limitYear && month > limitMonth
        || year == limitYear && month == limitMonth && day >= limitDay)
        && (year < nowYear
        || year == nowYear && month < nowMonth
        || year == nowYear && month == nowMonth && day <= nowDay))
            ++total;
        else
            continue;

        if (year > maxYear
        || year == maxYear && month > maxMonth
        || year == maxYear && month == maxMonth && day > maxDay)
        {
            strcpy(maxName, name);
            maxYear = year;
            maxMonth = month;
            maxDay = day;
        }

        if (year < minYear
        || year == minYear && month < minMonth
        || year == minYear && month == minMonth && day < minDay)
        {
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

void pat_a_1011()
{
    const char arr[] = {'W', 'T', 'L'};

    float wtl[3][3];
    char results[3];
    float profit = 1.0;
    for (int i = 0; i < 3; ++i)
    {
        scanf("%f%f%f", wtl[i], wtl[i] + 1, wtl[i] + 2);
        float* p = std::max_element(wtl[i], wtl[i] + 3);
        results[i] = arr[p - wtl[i]];
        profit *= *p;
    }

    printf("%c %c %c %.2f\n", results[0], results[1], results[2], ((profit * 0.65) - 1.0) * 2.0);
}

void pat_a_1006()
{
    int n;
    scanf("%d", &n);

    int maxTime = -1, minTime = 24 * 60 * 60 + 1;
    int time, h, m, s;
    char maxName[16], minName[16], name[16];

    for (int i = 0; i < n; ++i)
    {
        scanf("%s", name);

        scanf("%d:%d:%d", &h, &m, &s);
        time = h * 60 * 60 + m * 60 + s;

        if (time < minTime)
        {
            minTime = time;
            strcpy(minName, name);
        }

        scanf("%d:%d:%d", &h, &m, &s);
        time = h * 60 * 60 + m * 60 + s;

        if (time > maxTime)
        {
            maxTime = time;
            strcpy(maxName, name);
        }
    }

    printf("%s %s\n", minName, maxName);
}

namespace
{
    struct Student_1036
    {
        char name[11];
        char ID[11];
        char gender;
        int grade;
        Student_1036() : grade(-1) {}
        Student_1036(int grade) : grade(grade) {}
    };
}

void pat_a_1036()
{
    Student_1036 maxStudent(-1), minStudent(101), student;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%s %c%s%d", student.name, &student.gender, student.ID, &student.grade); // 接收字符之前加个空格
        if (student.gender == 'M')
        {
            if (student.grade < minStudent.grade)
                minStudent = student;
        }
        else
        {
            if (student.grade > maxStudent.grade)
                maxStudent = student;
        }
    }

    bool sign = true;

    if (maxStudent.grade == -1)
    {
        sign = false;
        printf("Absent\n");
    }
    else
        printf("%s %s\n", maxStudent.name, maxStudent.ID);

    if (minStudent.grade == 101)
    {
        sign = false;
        printf("Absent\n");
    }
    else
        printf("%s %s\n", minStudent.name, minStudent.ID);

    if (sign)
        printf("%d\n", maxStudent.grade - minStudent.grade);
    else
        printf("NA\n");
}

void pat_b_1036()
{
    int n;
    char c;
    scanf("%d %c", &n, &c);

    int m = (n + 1) / 2;
    for (int i = 0; i < m; ++i)
    {
        if (i == 0 || i == m - 1)
        {
            for (int j = 0; j < n; ++j)
                printf("%c", c);
            printf("\n");
        }
        else
        {
            printf("%c", c);
            for (int j = 1; j < n - 1; ++j)
                printf(" ");
            printf("%c\n", c);
        }
    }
}

void pat_b_1027()
{
    int n;
    char c;
    scanf("%d %c", &n, &c);

    int bottom = static_cast<int>(sqrt((n + 1) * 2)) - 1;
    if (bottom % 2 == 0) // 注意可能是偶数
        --bottom;
    int used = (bottom + 1) * (bottom + 1) / 2 - 1;

    for (int i = bottom; i > 0; i -= 2)
    {
        for (int j = 0; j < (bottom - i) / 2; ++j)
            printf(" ");
        for (int j = 0; j < i; ++j)
            printf("%c", c);
        printf("\n");
    }
    for (int i = 3; i <= bottom; i += 2)
    {
        for (int j = 0; j < (bottom - i) / 2; ++j)
            printf(" ");
        for (int j = 0; j < i; ++j)
            printf("%c", c);
        printf("\n");
    }

    printf("%d\n", n - used);
}

void pat_a_1031()
{
    char str[100];
    scanf("%s", str);

    int n = strlen(str);
    int n1 = (n + 2) / 3;
    int n2 = n + 2 - n1 * 2;

    for (int i = 0; i < n1 - 1; ++i)
    {
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

void pat_b_1022()
{
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

void pat_b_1037()
{
    int g[3], s[3], k[3];
    int total[2];
    for (int i = 0; i < 2; ++i)
    {
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

namespace
{
    struct Bit_a_1019
    {
        int num;
        int exp;
        Bit_a_1019(int num = 0, int exp = 0) : num(num), exp(exp) {}
    };
}

void pat_a_1019()
{
    int n, b;
    scanf("%d%d", &n, &b);

    Bit_a_1019 bits[32];

    int index = 0;
    do
    {
        bits[index].num = n % b;
        bits[index].exp = index;
        n /= b;
        ++index;
    } while (n);

    bool result = true;
    for (int i = 0; i < index / 2; ++i)
        if (bits[i].num != bits[index - i - 1].num)
        {
            result = false;
            break;
        }

    printf(result ? "Yes\n" : "No\n");
    for (int i = index - 1; i >= 0; --i)
    {
        if (i < index - 1)
            printf(" ");
        printf("%d", bits[i].num);
    }
}

void pat_a_1027()
{
    char bits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
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

    printf("#%c%c%c%c%c%c\n",
        resultR[0], resultR[1], resultG[0], resultG[1], resultB[0], resultB[1]);
}

void pat_a_1058()
{
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

void pat_b_1009()
{
    int num = 0;
    char strs[90][90];
    while (scanf("%s", strs[num]) != EOF)
    {
        num++;
    }
    for (int i = num - 1; i >= 0; --i)
    {
        printf("%s", strs[i]);
        if (i)
            printf(" ");
    }
}

void pat_b_1009_1()
{
    char str[100];
    std::cin.getline(str, 100);

    int len = strlen(str);
    for (int i = 0; i < len; ++i)
        if (str[i] == ' ')
            str[i] = '\0';

    int i = len; // 不是 len - 1，带入 0、1 验证
    while (i--)
    {
        if (str[i] != '\0' && i)
            continue;
        printf(i ? "%s " : "%s", i ? str + i + 1 : str);
    }
    printf("\n");
}
