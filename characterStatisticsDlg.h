
// characterStatisticsDlg.h : ͷ�ļ�
//
#include "BSTreeOfWord.h"
#include "BSTree.h"
#include "C.h"
#define NUMBER 1000
#pragma once


// CcharacterStatisticsDlg �Ի���
class CcharacterStatisticsDlg : public CDialogEx
{
// ����
public:
	CcharacterStatisticsDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHARACTERSTATISTICS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
