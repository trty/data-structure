// #include <iostream>
// #include <string.h>
// const int Maxsize = 100;
// typedef int DataType;
// using namespace std;

// class HString
// {
//     char *str;
//     int size;

// public:
//     HString();
//     bool Assign(char *s);
//     int Index_BF(HString T, int pos);
// };

// HString::HString()
// {
//     str = new char[Maxsize + 1];
//     size = 0;
// }

// bool HString::Assign(char *s)
// {
//     str = new char[strlen(s) + 1];
//     if (str == NULL)
//     {
//         cout << "out of memory!" << endl;
//         return 0;
//     }
//     else
//     {
//         size = strlen(s);
//         for (int i = 0; i < size; i++)
//             str[i] = s[i];
//     }
//     return 1;
// }

// int HString::Index_BF(HString T, int pos)
// {
//     int i = pos - 1;
//     int j = 0;
//     while (i <= size - 1 && j <= T.size - 1)
//     {
//         if (str[i] == T.str[j])
//         {
//             i++;
//             j++;
//         }
//         else
//         {
//             i = i - j + 1;
//             j = 0;
//         }
//     }
//     if (j > T.size - 1)
//         return i - T.size + 1;
//     else
//         return -1;
// }

// int main()
// {
//     char str[Maxsize];
//     char substr[Maxsize];
//     HString S, T;
//     cout << "请输入主串：";
//     cin >> str;
//     cout << "请输入模式串：";
//     cin >> substr;
//     int pos = 1;
//     S.Assign(str);
//     T.Assign(substr);
//     if (S.Index_BF(T, pos) != -1)
//     {
//         cout << "匹配成功！" << endl;
//         cout << "从主串第" << S.Index_BF(T, pos) << "个位置开始匹配！" << endl;
//     }
//     else
//         cout << "匹配不成功！" << endl;
//     return 0;
// }
//KMP算法样例
#include <iostream> //KMP算法
#include <string.h>
const int Maxsize = 100;
typedef int DataType;
using namespace std;
int length;
class HString
{
    char *str;
    int size;

public:
    HString();
    bool Assign(char *s);
    int Index_KMP(HString T, int pos, int next[]);
    void get_next(int next[]);
};

HString::HString()
{
    str = new char[Maxsize + 1];
    size = 0;
}

bool HString::Assign(char *s)
{
    str = new char[strlen(s) + 1];
    if (str == NULL)
    {
        cout << "out of memory!" << endl;
        return 0;
    }
    else
    {
        size = strlen(s);
        for (int i = 0; i < size; i++)
            str[i] = s[i];
    }
    return 1;
}

void HString::get_next(int next[])
{
    int i = 0;
    next[0] = -1;
    int j = -1;
    while (i < size - 1)
    {
        if (j == -1 || str[i] == str[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
    length = size;
}

int HString::Index_KMP(HString T, int pos, int next[])
{
    int i = pos - 1;
    int j = 0;
    while (i <= size - 1 && j <= T.size - 1)
    {
        if (str[i] == T.str[j])
        {
            i++;
            j++;
        }
        else if (j == 0)
            i++;
        else
            j = next[j];
    }
    if (j >= T.size)
        return i - T.size + 1;
    else
        return -1;
}

int main()
{
    char str[Maxsize];
    char substr[Maxsize];
    int next[Maxsize];
    HString S, T;
    cout << "请输入主串：";
    cin >> str;
    cout << "请输入模式串：";
    cin >> substr;

    int pos = 1;
    if (S.Assign(str) == 1)
        cout << "主串赋值成功！" << endl;
    else
        cout << "主串赋值不成功！" << endl;
    if (T.Assign(substr) == 1)
        cout << "子串赋值成功！" << endl;
    else
        cout << "子串赋值不成功！" << endl;
    T.get_next(next);
    for (int i = 0; i < length; i++)
        cout << next[i] << " ";
    cout << endl;
    cout << S.Index_KMP(T, pos, next) << endl;
    return 0;
}
