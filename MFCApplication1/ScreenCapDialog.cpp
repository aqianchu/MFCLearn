// ScreenCapDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ScreenCapDialog.h"
#include "afxdialogex.h"


// CScreenCapDialog 对话框

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
	CDC *pDC = GetDC();// 屏幕DC
	//CDC *c = GetDC();
	//pDC = CDC::FromHandle(c->m_hDC);//获取整个屏幕DC
	int BitPerpiexl = pDC->GetDeviceCaps(BITSPIXEL);//获取颜色模式
	int Width = pDC->GetDeviceCaps(HORZRES);//获取屏幕宽度
	int Height = pDC->GetDeviceCaps(VERTRES);//获取屏幕高度


	CDC memDC;//内存CD
	memDC.CreateCompatibleDC(pDC);//创建

	CBitmap memBitmap, *oldmemBitmap;
	memBitmap.CreateCompatibleBitmap(pDC, Width, Height);//创建位图

	oldmemBitmap = memDC.SelectObject(&memBitmap);//将memBitmap选入内存DC
	memDC.BitBlt(0, 0, Width, Height, pDC, 0, 0, SRCCOPY);//复制屏幕图像到内存DC


	BITMAP bmp;
	memBitmap.GetBitmap(&bmp);
	FILE *fp;
	fopen_s(&fp, filename, "w+b");

	BITMAPINFOHEADER bih = { 0 }; // 位图信息头
	bih.biBitCount = bmp.bmBitsPixel;//每个像素字节大小
	bih.biCompression = BI_RGB;
	bih.biHeight = bmp.bmHeight;//高度
	bih.biPlanes = 1;
	bih.biSize = sizeof(BITMAPINFOHEADER);
	bih.biSizeImage = bmp.bmWidthBytes*bmp.bmHeight;//图像数据大小
	bih.biWidth = bmp.bmWidth;//宽度


	BITMAPFILEHEADER bfh = { 0 };//位图文件头
	bfh.bfOffBits = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);//到位图数据的偏移量
	bfh.bfSize = bfh.bfOffBits + bmp.bmWidthBytes * bmp.bmHeight;//文件总的大小
	bfh.bfType = (WORD)0x4d42;

	fwrite(&bfh, 1, sizeof(BITMAPFILEHEADER), fp);//写入位图文件头

	fwrite(&bih, 1, sizeof(BITMAPINFOHEADER), fp);//写入位图信息头

	byte * p = new byte[bmp.bmWidthBytes * bmp.bmHeight];//申请内存保存位图数据

	GetDIBits(memDC.m_hDC, (HBITMAP)memBitmap.m_hObject, 0, Height, p,
		(LPBITMAPINFO)&bih, DIB_RGB_COLORS);//获取位图数据

	fwrite(p, 1, bmp.bmWidthBytes * bmp.bmHeight, fp);//写入位图数据

	delete[] p;

	fclose(fp);

	memDC.SelectObject(oldmemBitmap);


}
// CScreenCapDialog 消息处理程序


void CScreenCapDialog::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	Screen("D:/s.jpg");
}
