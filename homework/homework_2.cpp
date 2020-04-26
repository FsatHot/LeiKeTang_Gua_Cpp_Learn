#include <vector>
#include <iostream>
/*
��ҵ 2

���γ�˵����ַ
https://www.zhihu.com/question/389457315/answer/1170354190

���γ���Ƶҳ��
https://www.bilibili.com/video/BV1rt4y127ak/
*/

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

// ��ҵ��ʽ��ʼ
//
// ������ҵ�õ��� string, ��Ҫ��...
// 0, ���±������ַ���
// 2, ѭ��
// 3, ѡ�� (Ҳ���� if)

// ======
//
// �����������ڲ��Եĺ���
// �ϸ���ҵ�Ѿ����͹�����÷��������ﲻ�ظ�����

void ensure(bool condition, const string &message)
{
    if (condition)
    {
        log("||| ���Գɹ�");
    }
    else
    {
        log("*** ����ʧ��: ", message);
    }
}

// ��ҵ 1
// ʵ�ֲ���
//     1. ͨ�������ַ��� s1��ȡ��ѭ����Ԫ���� s2 �жϣ����ĳ��ѭ����Ԫ���� s2 ��ȣ����� index ���� i�����ҽ���ѭ����
//     2. ���ѭ��������û���ҵ��� s2 ��ȵ�Ԫ�أ����� index ��ֵΪ -1��
//     ע�⣬��� s2 �� s1 �г����˶�Σ�ֻ�����һ�γ��ֵ�λ�á�

int find(const string &s1, char s2)
{
    // ���� s2 �� s1 �е��±�, �� 0 ��ʼ, ����������򷵻� -1
    size_t i = 0;
    int index = -1;
    while (i < s1.size())
    {
        if (s2 == s1[i])
        {
            index = i;
            break;
        }
        i = i + 1;
    }
    return index;
}

// ���Ժ���
void testFind()
{
    ensure(find("hello", 'a') == -1, "find 1");
    ensure(find("hello", 'e') == 1, "find 2");
    ensure(find("hello", 'l') == 2, "find 3");
}

// �������һ��������Ϊ������ҵ�Ĳο�
// �����ַ�����Сд��ʽ�ĺ���
// ע��, ��������� s �ַ���ȫ�Ǵ�д��ĸ
string
lowercase(const string &s)
{
    // �����������ַ���, �����˴�д��ĸ��Сд��ĸ
    // �� const ��������Ϊ���ǲ����ᱻ�޸�
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // ��ʼ��һ�����ַ���
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        // ע��, ��� find �Ѿ�����ʵ����
        int index = find(upper, s[i]);
        // �ַ��������üӺ�ƴ��, �����׿��� log һ��
        result += lower[index];
        i += 1;
    }
    return result;
}

// ���Ժ���
void testLowercase()
{
    ensure(lowercase("HELLO") == "hello", "lowercase 1");
    ensure(lowercase("GUA") == "gua", "lowercase 2");
}

// ��ҵ 2
//
// ����һ������
// ������һ���ַ��� s
// ���ش�д����ַ���
// ע��, ���� s �ַ�����ȫ��Сд��ĸ
//
// ʵ�ֲ���
//     1. �����ַ��� s��ʹ����ҵ 1 �� find �����ҵ� s �е�ÿһλԪ���� lower �е� index��
//     2. �õ� index ֮�󣬾�֪�����Ԫ�ض�Ӧ�Ĵ�д��ĸ��ʲô����Сд��ĸ�� index ����ͬ��
//     3. �ۼ���Щ��д�ַ�֮��Ľ������ s ��Ӧ�Ĵ�д����ַ���
string
uppercase(const string &s)
{
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // ��ʼ��һ�����ַ���
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        // ע��, ��� find �Ѿ�����ʵ����
        int index = find(lower, s[i]);
        // �ַ��������üӺ�ƴ��, �����׿��� log һ��
        result += upper[index];
        i += 1;
    }
    return result;
}

void testUppercase()
{
    ensure(uppercase("hello") == "HELLO", "uppercase 1");
    ensure(uppercase("gua") == "GUA", "uppercase 2");
}

// ��ҵ 3
//
// ʵ�� lowercase1
// ������ȷ����� Сд��ĸ ���ַ���
//
// ʵ�ֲ���
//     1. �����ַ��� s����� s �е�Ԫ���Ǵ�д��ĸ�������Ԫ�ر� upper �ַ���������
//     2. ��� s �е�Ԫ����Сд��ĸ��ֱ��ƴ�Ӽ���

string
lowercase1(const string &s)
{
    // �����������ַ���, �����˴�д��ĸ��Сд��ĸ
    // �� const ��������Ϊ���ǲ����ᱻ�޸�
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // ��ʼ��һ�����ַ���
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        int index = find(upper, s[i]);
        if (index != -1)
        {
            result += lower[index];
        }
        else{
            result +=s[i];
        }
        i += 1;
    }
    return result;
}

void testLowercase1()
{
    ensure(lowercase1("heLLo") == "hello", "lowercase1 1");
    ensure(lowercase1("gua") == "gua", "lowercase1 2");
    ensure(lowercase1("GW") == "gw", "lowercase1 3");
}

// ��ҵ 4
//
// ʵ�� uppercase1
// ������ȷ����� ��д��ĸ ���ַ���
//
// ʵ�ֲ���
//     1. �ο���ҵ 3
string
uppercase1(const string &s)
{
    // �����������ַ���, �����˴�д��ĸ��Сд��ĸ
    // �� const ��������Ϊ���ǲ����ᱻ�޸�
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // ��ʼ��һ�����ַ���
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        int index = find(lower, s[i]);
        if (index != -1)
        {
            result += upper[index];
        }
        else
        {
            result += s[i];
        }
        i += 1;
    }
    return result;
}

void testUppercase1()
{
    ensure(uppercase1("helLo") == "HELLO", "uppercase1 1");
    ensure(uppercase1("gUA") == "GUA", "uppercase1 2");
}

// ��ҵ 5
// ʵ��һ���� �������� �ļ����㷨, ��������
// ����һ���ַ���, ������λ, ���Ǽ���
// ������ 1 λΪ��
// ԭʼ��Ϣ 'afz' �ᱻ����Ϊ 'bga'
// ʵ�� encode1 ����, �����ļ��ܳ����벢����
// ���� 1 λ
//
// ע��:
//     s ��һ��ֻ����Сд��ĸ���ַ���
//
// ʵ�ֲ���
//     1. �����ַ��� s���ҳ�ÿһλԪ���� lower �е� index��Ȼ���ҳ� lower �� index + 1 ��Ԫ�أ�ƴ����һ��
//     2. ע�⿼�Ǳ߽���������������� index 25(Ҳ�����ַ� 'z')����ȡ����һλԪ�أ�Ҳ���� 'a'��
string
encode1(const string &s)
{
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // ��ʼ��һ�����ַ���
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        int index = find(lower, s[i]);
        if (index < lower.size() - 1)
        {
            result += lower[index + 1];
        }
        else
        {
            result += lower[0];
        }
        i += 1;
    }
    return result;
}

void testEncode1()
{
    ensure(encode1("afz") == "bga", "encode1 1");
    ensure(encode1("gw") == "hx", "encode1 2");
}

// ��ҵ 6
// ʵ�� decode1 ����, ����ҵ 5 ���ܵ��������Ϊ���Ĳ�����
//
// ע��:
//     s ��һ��ֻ����Сд��ĸ���ַ���
//
// ʵ�ֲ���
//     1. ��ҵ 5 ��������һλ�����ܣ����ܵĲ����������������ƶ�һλ������ 'bga' ����ܳ� 'afz'
//     2. �����ַ��� s���ҳ�ÿһλԪ���� lower �е� index��Ȼ���ҳ� lower �� index - 1 ��Ԫ�أ�ƴ����һ��
//     3. ע�⿼�Ǳ߽������������������Ԫ���� 'a'����ȡ�� 'z'
string
decode1(const string &s)
{
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // ��ʼ��һ�����ַ���
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        int index = find(lower, s[i]);
        if (index > 0)
        {
            result += lower[index - 1];
        }
        else
        {
            result += lower[lower.size() - 1];
        }
        i += 1;
    }
    return result;
}

void testDecode1()
{
    ensure(decode1("bga") == "afz", "decode1 1");
    ensure(decode1("hx") == "gw", "decode1 2");
}

// ��ҵ 7
// ʵ�� encode2
// ����һ������ shift ��ʾ�Ƶ�λ��
//
// ע��:
//     s ��һ��ֻ����Сд��ĸ���ַ���
//
// ʵ�ֲ���
//     1. ����ҵ 5 ���ƣ���һ���ĵط����������Ǽ���� index ֮���ҳ� lower �� index + shift ��Ԫ�أ�Ȼ��ƴ����һ��
//     2. ע�⿼�Ǳ߽�������� index + shift �����˱߽�����

string
encode2(const string &s, int shift)
{
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // ��ʼ��һ�����ַ���
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        int index = find(lower, s[i]);
        if (index < lower.size() - shift)
        {
            result += lower[index + shift];
        }
        else
        {
            result += lower[index + shift - lower.size()];
        }
        i += 1;
    }
    return result;
}

void testEncode2()
{
    ensure(encode2("afz", 2) == "chb", "encode2 1");
    ensure(encode2("gw", 3) == "jz", "encode2 2");
}

// ��ҵ 8
// ʵ�� decode2
// ����һ������ shift ��ʾ�Ƶ�λ��
//
// ע��:
//     s ��һ��ֻ����Сд��ĸ���ַ���
//
// ʵ�ֲ���
//     1. ����ҵ 6 ���ƣ���һ���ĵط����������Ǽ���� index ֮���ҳ� lower �� index - shift ��Ԫ�أ�Ȼ��ƴ����һ��
//     2. ע�⿼�Ǳ߽����

string
decode2(const string &s, int shift)
{
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // ��ʼ��һ�����ַ���
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        int index = find(lower, s[i]);
        if (index < shift)
        {
            result += lower[index - shift + lower.size()];
        }
        else
        {
            result += lower[index - shift];
        }
        i += 1;
    }
    return result;
}

void testDecode2()
{
    ensure(decode2("chb", 2) == "afz", "decode2 1");
    ensure(decode2("jz", 3) == "gw", "decode2 2");
}

// ��ҵ 9
// ʵ�� encode3
// ����һ������ shift ��ʾ�Ƶ�λ��
// ��� s �а����˲�����ĸ���ַ�, ����ո������������, �������ַ�����������ԭ��
//
// ע��:
//     s ��һ��ֻ����Сд��ĸ�Ͳ�����ĸ���ַ����ַ���
//
// ʵ�ֲ���
//     1. ��ҵ 9 ����ҵ 7 ���������� s ��ͬ��
//         ��ҵ 7 �е� s ֻ����Сд��ĸ����ҵ 9 ����һЩ����Ҫ������ַ��������Ա�����ʱ����Ҫ�����ж�
//     2. ������������Ĳ�����ĸ����ʲô��������ֱ��ƴ�����ַ�����
//     3. ���������������Сд��ĸ���Ͱ�����ҵ 7 �еķ�ʽ����
string
encode3(const string &s, int shift)
{
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // ��ʼ��һ�����ַ���
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        int index = find(lower, s[i]);
        if (index == -1)
        {
            result += s[i];
        }
        else
        {
            if (index < lower.size() - shift)
            {
                result += lower[index + shift];
            }
            else
            {
                result += lower[index + shift - lower.size()];
            }
        }
        i += 1;
    }
    return result;
}

void testEncode3()
{
    ensure(encode3("a fz", 2) == "c hb", "encode3 1");
    ensure(encode3("g#w", 3) == "j#z", "encode3 2");
}

// ��ҵ 10
// ʵ�� decode3
// ����һ������ shift ��ʾ�Ƶ�λ��
// ��� s �а����˲�����ĸ���ַ�, ����ո������������, �������ַ�����������ԭ��
//
// ע��:
//     s ��һ��ֻ����Сд��ĸ�Ͳ�����ĸ���ַ����ַ���
//
// ʵ�ֲ���
//     1. ��ҵ 10 ����ҵ 8 ���ƣ������ڱ�����ʱ���� s �Ƿ�ΪСд��ĸ�������Сд��ĸ�Ͱ�����ҵ 8 �ķ�ʽ����
//     2. ����ֱ��ƴ�ӽ��

string
decode3(const string &s, int shift)
{
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // ��ʼ��һ�����ַ���
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        int index = find(lower, s[i]);
        if (index == -1)
        {
            result += s[i];
        }
        else
        {
            if (index < shift)
            {
                result += lower[index - shift + lower.size()];
            }
            else
            {
                result += lower[index - shift];
            }
        }

        i += 1;
    }
    return result;
}

void testDecode3()
{
    ensure(decode3("ch#b", 2) == "af#z", "decode3 1");
    ensure(decode3("j z", 3) == "g w", "decode3 2");
}

// ��ҵ 11
// ֪����һ��������, ���������
// �����ڴ�
// https://www.zhihu.com/question/28324597
// ��һ�����ǿ�������...
// �����¥�����ԭ��
//
// ʵ�ֲ���
//     1. ��ҵ 11 ����ҵ 10 ���������ڣ���ҵ 11 �� shift �ǲ�ȷ���ģ�������Ҫ�� shift ������һ��
//     2. �ڳ��Ե�ʱ��Ҫ�Ȱ� code ת��Сд����д��ĸת��Сд���ո�ͱ�㲻Ҫת��
//     3. shift �Ŀ���ȡֵΪ 1 - 25������Щ���������һ�飬�۲���ܳ����Ľ��
//
// ������Ҫ���۹۲����ȷ������
// �ڵ���ڿ��У���̴������Զ�ʶ�����ȷ������
// ������ĵ���ڿΣ���ָ�������̡�����ѱ�����ſΡ�����ڣ�
void decode4()
{
    const string code = "VRPHWLPHV L ZDQW WR FKDW ZLWK BRX,EXW L KDYH QR UHDVRQ WR FKDW ZLWK BRX";
}

void test()
{
    testFind();
    testLowercase();
    testUppercase();
    testLowercase1();
    testUppercase1();
    testEncode1();
    testDecode1();
    testEncode2();
    testDecode2();
    testEncode3();
    testDecode3();
}

int main(int argc, const char *argv[])
{
    test();

    return 0;
}