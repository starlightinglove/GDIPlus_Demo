// GDIPlus_DemoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include <atlimage.h>
#include "richstatic.h"
#include "afxcmn.h"

#define TIMER_UPDATE_MEMORY 1

typedef struct _tagTransColor{
	_tagTransColor()
	{
		nAlpha = 255;
		color = RGB(255,255,255);
	}
	int nAlpha;//͸���ȣ�0-255
	COLORREF color;//��ɫֵ
}_tagTransColor;

// CGDIPlus_DemoDlg �Ի���
class CGDIPlus_DemoDlg : public CDialog
{
// ����
public:
	CGDIPlus_DemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GDIPLUS_DEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	//CDC����
	CDC             m_BGMemDC;
	BOOL m_bRedrawBkDC;
	COLORREF m_bgColor;
	Gdiplus::REAL     m_startAngle;
	int      m_nPos;
	CImage   m_imgBG;

	//���岿��
	_tagTransColor   m_FillColor;//�������ɫ
	_tagTransColor   m_BorderColor;//Ĭ�ϱ߿�
	_tagTransColor   m_BorderHiColor;//�����߿�
	_tagTransColor   m_TextColor;
	_tagTransColor   m_BackColor;
	int              m_nEllipseAlpha;//����͸����

	int m_nLeftMargin;
	int m_nTopMargin;
	int m_nEllipseWidth;
	int m_nEllipseHeight;

	int m_nRightPaddingClient;

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	//������ƺ���
	void ReDraw(CDC *pDC);
	void PaintBG(CDC *pDC);
	void RedrawEllipse(CDC *pDC,CRect rectDraw);
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCheckBorder();
	CButton m_btnCheckBorder;
	afx_msg void OnBnClickedButtonChangebgimg();
	afx_msg void OnBnClickedButton3();
	void UpdateMemory();
	void UpdateEllipse(int nPos);
	void SetPosToEllipse(int nOffset);
	afx_msg void OnBnClickedCheck1();
	CButton m_btnCheckMemory;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CRichStatic m_staticTips;

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTRBNThumbPosChangingSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl m_wndFillAlpha;
	CSliderCtrl m_wndBorder;
	CSliderCtrl m_wndBorderHight;
	afx_msg void OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTRBNThumbPosChangingSlider3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTRBNThumbPosChangingSlider2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonBody();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton6();
	void UpdateEllipseThemes();
	CSliderCtrl m_wndTransAlpha;
	afx_msg void OnTRBNThumbPosChangingSlider4(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl m_wndPos;
	afx_msg void OnTRBNThumbPosChangingSlider5(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl m_wndTextTrans;
	afx_msg void OnTRBNThumbPosChangingSlider6(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton8();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CSliderCtrl m_wndSliderBack;
	afx_msg void OnTRBNThumbPosChangingSlider7(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonBody2();
	afx_msg void OnEnChangeEditLeft();
	afx_msg void OnEnChangeEditTop();
	afx_msg void OnEnChangeEditWidth();
	afx_msg void OnEnChangeEditHeight();
	CSpinButtonCtrl m_wndSpinLeft;
	CSpinButtonCtrl m_wndSpinTop;
	CSpinButtonCtrl m_wndSpinWidth;
	CSpinButtonCtrl m_wndSpinHeight;
	afx_msg void OnNMClickSyslink1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslink2(NMHDR *pNMHDR, LRESULT *pResult);
};
