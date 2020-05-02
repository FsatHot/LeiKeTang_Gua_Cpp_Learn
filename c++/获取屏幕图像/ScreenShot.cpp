
// ͨ�� HDC��� ��ȡ��Ļ ���Ƶ����а�

#include <iostream>
#include <windows.h>

using namespace std;

void screenshot(POINT a, POINT b)
{
    // ��ȡ��Ļ��λͼ
    // �ú�������һָ�����ڵĿͻ������������Ļ����ʾ�豸�����Ļ����ľ�����Ժ������GDI������ʹ�øþ�������豸�����Ļ����л�ͼ��
    HDC screenImage = GetDC(NULL);
    // �ú�������һ����ָ���豸���ݵ��ڴ��豸�����Ļ�����DC����ͨ��GetDc()��ȡ��HDCֱ��������豸��ͨ����������������DC���������ڴ��е�һ�������������
    HDC hDC = CreateCompatibleDC(screenImage);
    // �ú���������ָ�����豸������ص��豸���ݵ�λͼ
    HBITMAP hBitmap = CreateCompatibleBitmap(screenImage, abs(b.x - a.x), abs(b.y - a.y));
    // �ú���ѡ��һ����ָ�����豸�����Ļ����У����¶����滻��ǰ����ͬ���͵Ķ���
    HGDIOBJ old_obj = SelectObject(hDC, hBitmap);
    // BitBlt��һ��������������ú�����ָ����Դ�豸���������е����ؽ���λ�飨bit_block��ת�����Դ��͵�Ŀ���豸������
    BOOL bRet = BitBlt(hDC, 0, 0, abs(b.x - a.x), abs(b.y - a.y), screenImage, a.x, a.y, SRCCOPY);

    // ��λͼ���浽������
    // �򿪼��а�
    OpenClipboard(NULL);
    // ��ռ��а�
    EmptyClipboard();
    // ���ü��а�����
    SetClipboardData(CF_BITMAP, hBitmap);
    
    // �رռ��а�
    CloseClipboard();

    // ���������ڴ�
    SelectObject(hDC, old_obj);
    // �ú���ɾ��ָ�����豸�����Ļ���
    DeleteDC(hDC);
    // ReleaseDC�����ͷ��豸�����Ļ�����DC��������Ӧ�ó���ʹ��
    ReleaseDC(NULL, screenImage);
    // ɾ��λͼ����
    DeleteObject(hBitmap);
}

int main()
{
    POINT a, b;
    a.x = 0;
    a.y = 0;

    b.x = 1920;
    b.y = 1080;

    screenshot(a, b);
    
}