/*
��ҵ 3

���γ�˵����ַ
https://www.zhihu.com/question/389457315/answer/1170354190

���γ���Ƶҳ��
https://www.bilibili.com/video/BV1rt4y127ak/
*/
#include <vector>
#include <iostream>
#include <string>

using namespace std;

template <class T>
void _print(T arg)
{
    cout << arg << " ";
}

template <class... Args>
void log(Args... args)
{
    int arr[] = {(_print(args), 0)...};
    cout << endl;
}

void ensure(bool condition, const string &message)
{
    // ��������������ʱ��, ��� message
    if (not condition)
    {
        log("*** ����ʧ��: ", message);
    }
    else
    {
        log("||| ���Գɹ�");
    }
}

// ������ҵ��Ҫ�� string
// string ��Ŀ�õ���֪ʶ��Ȼ��
// 0, ���±������ַ���
// 2, ѭ��
// 3, ѡ�� (Ҳ���� if)
//

// ��ҵ 1
//
string nChar(int n, char fillchar = ' ')
{
    string r = "";
    int i = 0;
    while (i < n)
    {
        r += fillchar;
        i += 1;
    }
    return r;
}

string
zfill(int n, int width)
{
    // �� n ��λ����� width ��ô���������Ҷ��룬���㲿���� 0 ���㲢����
    // �����뿴����
    // ��ʾ:
    // ���� n �ĳ���, �������һ��ָ�����ȵ� 0, ʹ������Ϻ󳤶�Ϊ width

    // ʵ�ֲ���
    // 1. �� n ת��Ϊ�ַ��������㳤��
    //    ����ת�ַ������� string n_str = to_string(n);
    // 2. �� zfill ����ǰ, ����һ���������� nChar, ����һ������Ϊ n �� 0 �ַ���
    // 3. �����Ҫ���� 0 �ĸ�����ʹ�� nChar ����
    // 4. ƴ��

    string n_str = to_string(n);
    string result = nChar(width - (n_str.length()), '0') + n_str;
    return result;
}

// ���Ժ���
void testZfill()
{
    ensure(zfill(1, 4) == "0001", "zfill ���� 1");
    ensure(zfill(23, 4) == "0023", "zfill ���� 2");
    ensure(zfill(12345, 4) == "12345", "zfill ���� 3");
    ensure(zfill(169, 5) == "00169", "zfill ���� 4");
}

// ��ҵ 2
//
string
rjust(const string &s, int width, char fillchar = ' ')
{
    // ��� s ����С�� width, ���ڿ�ͷ�� fillchar ��䲢����

    // ���� string ����

    // ��ʾ:
    // ��������ҵ 1, ���м�������
    // һ�ǲ���Ҫ���� string() ת������
    // ���������ַ����� 0 ���ǿ������ж���

    // �ֲ���ʾ��
    // 1. ������Ҫ�� fillchar ���ɵ��ַ�������
    // 2. ʹ����ҵ 1 �еĸ������� nChar, �޸����Ա���ϱ����ʹ��
    // 3. �����޸ĺ�� nChar ��������õ��ַ���
    // 4. ƴ�Ӳ����ؽ��
    string result;
    if (s.length() <= width)
    {
        result = nChar(width - (s.length()), fillchar) + s;
    }
    else
    {
        result = s;
    }
    return result;
}

// ���Ժ���
void testRjust()
{
    ensure(rjust("gua", 5) == "  gua", "rjust ���� 1");
    ensure(rjust("guagua", 5) == "guagua", "rjust ���� 2");
    ensure(rjust("gua", 5, '*') == "**gua", "rjust ���� 3");
}

// ��ҵ 3
//
string ljust(string s, int width, char fillchar = ' ')
{
    // s �� string
    // width �� ����
    // fillchar �� ����Ϊ 1 ���ַ���, Ĭ��Ϊ�ո� ' '

    // ��� s ����С�� width, ����ĩβ�� fillchar ��䲢����
    // ����, ԭ������, �������⴦��

    // ���� string ����

    // ��ʾ:
    // ��������ҵ 2, ���������λ�������������Ҳ�

    // ʵ�ֲ���
    // 1. ������ҵ 2 �еĴ���, �ǵðѺ������ĳ� ljust
    // 2. ����ҵ 2 ���һ�����ַ���ƴ�ӵ�����Ԫ�ص���λ��
    string result;
    if (s.length() <= width)
    {
        result = s + nChar(width - (s.length()), fillchar);
    }
    else
    {
        result = s;
    }
    return result;
}

// ���Ժ���
void testLjust()
{
    ensure(ljust("gua", 5) == "gua  ", "ljust ���� 1");
    ensure(ljust("guagua", 5) == "guagua", "ljust ���� 2");
    ensure(ljust("gua", 5, '*') == "gua**", "ljust ���� 3");
}

// ��ҵ 4
//
string
center(const string &s, int width, char fillchar = ' ')
{
    // ��� s ����С�� width, ���������� fillchar ��䲢����
    // ��� s ���Ⱥ� width ��Ϊ��ż, ���޷�ƽ���������ߵ� fillchar
    //     ���������, ����ߵ� fillchar ����С���ұ�

    // ���� string ����

    // ��ʾ:
    // ��Ҫ���� s ���������ַ����ĳ��Ⱥ�, �ֱ�������������ַ���, �����հ����߰�˳��ƴ��

    // ʵ�ֲ���
    // 1. ������������ַ������ܳ���
    // 2. ������������ַ����ĳ��ȣ�ע��Ҫ������
    //      C++ �� 5/2 ����� 2
    // 3. ����������������ַ���
    // 4. ƴ���ַ���, �����ؽ��
    string result;
    if (s.length() <= width)
    {
        result = s + nChar((width - (s.length())) / 2, fillchar);
        result = nChar((width - (s.length())) / 2, fillchar) + result;
        if (result.length() <= width)
        {
            result = result + nChar((width - (result.length())), fillchar);
        }
    }
    else
    {
        result = s;
    }
    return result;
}

// ���Ժ���
void testCenter()
{
    ensure(center("gua", 5) == " gua ", "center ���� 1");
    ensure(center("gua", 5, '*') == "*gua*", "center ���� 2");
    ensure(center("gw", 5) == " gw  ", "center ���� 3");
    ensure(center("gua", 6) == " gua  ", "center ���� 4");
}

// ��ҵ 5
//
bool isSpace(const string &s)
{
    // ��� s ���Ƿ�ֻ�����ո�

    // ���� ����ֵ
    // ��� s �а�����ֻ�пո��򷵻� true
    // ���򷵻� false

    // ��ʾ:
    // ���� s �е������ַ�, ������������ǿո��ַ�, ���� false, ���򷵻� true

    // ʵ�ֲ���
    // 1. �����һ�����ַ������� false
    // 2. ���� s �е�ÿ���ַ�
    // 3. ����ַ����ǿո�, ���� false
    // 4. ��ѭ��������, ���� true
    bool result = true;
    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] != ' ' || s == "")
        {
            result = false;
        }
    }
    return result;
}

// ���Ժ���
void testIsSpace()
{
    ensure(isSpace(" "), "isSpace ���� 1");
    ensure(isSpace("   "), "isSpace ���� 2");
    // C++ �� not ������� !
    // ͬ���� and ��� && �� or ��� ||
    // ensure(not isSpace(""), "isSpace ���� 3");
    ensure(not isSpace("gua"), "isSpace ���� 4");
    ensure(not isSpace("  gua"), "isSpace ���� 5");
}

int find(const string &s1, char s2)
{
    // ���� s2 �� s1 �е��±�, �� 0 ��ʼ, ����������򷵻� -1
    size_t i = 0;
    int result = -1;
    while (i < s1.size())
    {
        if (s2 == s1[i])
        {

            result = 1;
        }
        i = i + 1;
    }
    return result;
}
// ��ҵ 6
//
bool isDigit(const string &s)
{
    // ��� s ���Ƿ�ֻ��������
    // ����: ����ֵ

    // ��ʾ:
    // ��������ҵ 5, �жϵ������ӿո��Ϊ������

    // ʵ�ֲ���
    // 1. ���� isSpace �����еĴ���
    // 2. ���ж��ַ��Ƿ�Ϊ�ո�Ĳ��ָ�Ϊ�ж��Ƿ�Ϊ����
    //     ͨ���ж��ַ��Ƿ����ַ��� "0123456789" ��, ���ж����Ƿ�Ϊ����
    bool result = true;
    string number = "0123456789";
    for (int i = 0; i < s.length(); i++)
    {

        if (find(number, s[i]) == -1 || s.size() == 0)
        {
            result = false;
            break;
        }
    }
    return result;
}

// ���Ժ���
void testIsDigit()
{
    ensure(isDigit("123"), "is_digit ���� 1");
    ensure(isDigit("0"), "is_digit ���� 2");
    ensure(not isDigit("  "), "is_digit ���� 3");
    ensure(not isDigit("1.1"), "is_digit ���� 4");
    ensure(not isDigit("gua"), "is_digit ���� 5");
    // ensure(not isDigit(""), "is_digit ���� 6");
}

// ��ҵ 7
//
string
stripLeft(const string &s)
{
    // ����һ����ɾ�����ַ�����ʼ�����пո񡹵��ַ���

    // ���� string

    // ʵ�ֲ���
    // ���������ַ���, ��¼��һ���ǿո��ַ���λ��, ���ɴ��и��ַ���
    // 1. ʹ����ҵ 5 �� isSpace �������ж� s �Ƿ�ֻ�����ո�
    //    ��� s ֻ�����ո񣬷��ؿ��ַ���
    // 2. �����ַ����ҵ����ǿո���ַ����±�
    // 3. ��Ƭ������
    //      string ����Ƭ��������
    //             0123456789
    // string s = "kuaibiancheng";
    // string s1 = s.substr(2, 5);
    // ����� aibia
    // ��һ��������ʾ��ʼ���±꣬�ڶ���������ʾ��Ƭ�ĸ���

    
}

// ���Ժ���
void testStripLeft()
{
    ensure(stripLeft("  gua") == "gua", "stripLeft ���� 1");
    ensure(stripLeft(" gua  ") == "gua  ", "stripLeft ���� 2");
    ensure(stripLeft("") == "", "stripLeft ���� 3");
    ensure(stripLeft("    ") == "", "stripLeft ���� 4");
}

// ��ҵ 8
//
string
stripRight(const string &s)
{
    // ����һ����ɾ�����ַ���ĩβ�����пո񡹵��ַ���

    // ��ʾ:
    // ��������ҵ 7
    // �������������Ҫ������������ַ���

    // ʵ�ֲ���
    // 1. ����һ��ѭ��, ���ҵ�������ַ���
    //     ���ҵ�������ķ�ʽ�������ִ� n �� 0
    // 2. �����ַ����ҵ����ǿո���ַ����±�
    // 3. ��Ƭ������


}

// ���Ժ���
void testStripRight()
{
    ensure(stripRight("gua") == "gua", "stripRight ���� 1");
    ensure(stripRight(" gua  ") == " gua", "stripRight ���� 2");
    ensure(stripRight("") == "", "stripRight ���� 3");
    ensure(stripRight("    ") == "", "stripRight ���� 4");
}

// ��ҵ 9
//
string
strip(const string &s)
{
    // ����һ����ɾ�����ַ�����β�����пո񡹵��ַ���

    // ���� string

    // ��ʾ:
    // ���ε�����ҵ 7 ����ҵ 8 �еĺ�������

    // �ֲ���ʾ:
    // 1. ���� stripLeft
    // 2. ����һ���Ľ���������� stripRight
    // 3. ���ؽ��

    return 0;
}

// ���Ժ���
void testStrip()
{
    ensure(strip("  gua") == "gua", "strip ���� 1");
    ensure(strip(" gua  ") == "gua", "strip ���� 2");
    ensure(strip("") == "", "strip ���� 3");
    ensure(strip("    ") == "", "strip ���� 4");
}

// ��ҵ 10
//
string
replace(const string &s, const string &old_str, const string &new_str)
{
    // ����һ������ s �е� old_str �ַ����滻Ϊ new_str �ַ��������ַ���
    // ���� old ���ڲ���ֻ����һ��

    // ���� string

    // ��ʾ:
    // �ҵ�ָ�����ַ�������ʼ�±�, ����ǰ���ַ��������ַ�������ƴ��

    // ʵ�ֲ���
    // 1. �ҵ� old_str ���±�
    // 2. �� s �г� 2 �������� old_str ���ַ���
    // 3. ƴ�Ӳ����ؽ��

    return 0;
}

// ���Ժ���
void testReplace()
{
    ensure(replace("guagua", "ag", "l") == "gulua", "replace ���� 1");
    ensure(replace("g  ", "  ", "a") == "ga", "replace ���� 2");
    ensure(replace("l", "l", "") == "", "replace ���� 3");
}

void test()
{
    testZfill();
    testRjust();
    testLjust();
    testCenter();
    testIsSpace();
    testIsDigit();
    testStripLeft();
    testStripRight();
    testStrip();
    testReplace();
}

int main(int argc, const char *argv[])
{
    test();

    return 0;
}
