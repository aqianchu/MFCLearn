// ScreenCapDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ScreenCapDialog.h"
#include "afxdialogex.h"


// CScreenCapDialog �Ի���

IMPLEMENT_DYNAMIC(CScreenCapDialog, CDialogEx)

CScreenCapDialog::CScreenCapDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CScreenCapDialog::IDD, pParent)
{

}

CScreenCapDialog::~CScreenCapDialog()
{
}

void CScreenCapDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CScreenCapDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CScreenCapDialog::OnBnClickedButton1)
END_MESSAGE_MAP()

void CScreenCapDialog::Screen(char filename[])
{
	CDC *pDC = GetDC();// ��ĻDC
	//CDC *c = GetDC();
	//pDC = CDC::FromHandle(c->m_hDC);//��ȡ������ĻDC
	int BitPerpiexl = pDC->GetDeviceCaps(BITSPIXEL);//��ȡ��ɫģʽ
	int Width = pDC->GetDeviceCaps(HORZRES);//��ȡ��Ļ���
	int Height = pDC->GetDeviceCaps(VERTRES);//��ȡ��Ļ�߶�


	CDC memDC;//�ڴ�CD
	memDC.CreateCompatibleDC(pDC);//����

	CBitmap memBitmap, *oldmemBitmap;
	memBitmap.CreateCompatibleBitmap(pDC, Width, Height);//����λͼ

	oldmemBitmap = memDC.SelectObject(&memBitmap);//��memBitmapѡ���ڴ�DC
	memDC.BitBlt(0, 0, Width, Height, pDC, 0, 0, SRCCOPY);//������Ļͼ���ڴ�DC


	BITMAP bmp;
	memBitmap.GetBitmap(&bmp);
	FILE *fp;
	fopen_s(&fp, filename, "w+b");

	BITMAPINFOHEADER bih = { 0 }; // λͼ��Ϣͷ
	bih.biBitCount = bmp.bmBitsPixel;//ÿ�������ֽڴ�С
	bih.biCompression = BI_RGB;
	bih.biHeight = bmp.bmHeight;//�߶�
	bih.biPlanes = 1;
	bih.biSize = sizeof(BITMAPINFOHEADER);
	bih.biSizeImage = bmp.bmWidthBytes*bmp.bmHeight;//ͼ�����ݴ�С
	bih.biWidth = bmp.bmWidth;//���


	BITMAPFILEHEADER bfh = { 0 };//λͼ�ļ�ͷ
	bfh.bfOffBits = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);//��λͼ���ݵ�ƫ����
	bfh.bfSize = bfh.bfOffBits + bmp.bmWidthBytes * bmp.bmHeight;//�ļ��ܵĴ�С
	bfh.bfType = (WORD)0x4d42;

	fwrite(&bfh, 1, sizeof(BITMAPFILEHEADER), fp);//д��λͼ�ļ�ͷ

	fwrite(&bih, 1, sizeof(BITMAPINFOHEADER), fp);//д��λͼ��Ϣͷ

	byte * p = new byte[bmp.bmWidthBytes * bmp.bmHeight];//�����ڴ汣��λͼ����

	GetDIBits(memDC.m_hDC, (HBITMAP)memBitmap.m_hObject, 0, Height, p,
		(LPBITMAPINFO)&bih, DIB_RGB_COLORS);//��ȡλͼ����

	fwrite(p, 1, bmp.bmWidthBytes * bmp.bmHeight, fp);//д��λͼ����

	delete[] p;

	fclose(fp);

	memDC.SelectObject(oldmemBitmap);


}
// CScreenCapDialog ��Ϣ�������


void CScreenCapDialog::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	Screen("D:/s.jpg");
}
