#pragma once


// CColorStatic
// 用于自动调整静态文本框字体背景、颜色等的类
class CColorStatic : public CStatic
{
	DECLARE_DYNAMIC(CColorStatic)

public:
	CColorStatic();
	virtual ~CColorStatic();

protected:
	DECLARE_MESSAGE_MAP()

private:
	COLORREF    m_ForeColor;        //文本颜色
	COLORREF    m_BackColor;        //背景色
	CBrush      m_BkBrush;          //背景刷
	CFont*      p_Font;             //字体

public:
	void SetForeColor(COLORREF color);      //设置文本颜色
	void SetBkColor(COLORREF color);        //设置背景颜色
	void SetTextFont(int FontHight,LPCTSTR FontName);   //设置字体 

	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
};


