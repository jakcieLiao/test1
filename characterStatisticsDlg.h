
// characterStatisticsDlg.h : 头文件
//
#include "BSTreeOfWord.h"
#include "BSTree.h"
#include "C.h"
#define NUMBER 1000
#pragma once


// CcharacterStatisticsDlg 对话框
class CcharacterStatisticsDlg : public CDialogEx
{
// 构造
public:
	CcharacterStatisticsDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHARACTERSTATISTICS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnEnChangeEdit1();
	CString m_edit;
	afx_msg void OnBnClickedButton1();
private:
	BSTRee Tree;
	BSTRee1 tree;
	char str[NUMBER];
	//char *str;
public:
	afx_msg void OnBnClickedButton2();
};
