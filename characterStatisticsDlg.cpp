﻿
// characterStatisticsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "characterStatistics.h"
#include "characterStatisticsDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcharacterStatisticsDlg 对话框



CcharacterStatisticsDlg::CcharacterStatisticsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHARACTERSTATISTICS_DIALOG, pParent)
	, m_edit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcharacterStatisticsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_edit);
}

BEGIN_MESSAGE_MAP(CcharacterStatisticsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CcharacterStatisticsDlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT1, &CcharacterStatisticsDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CcharacterStatisticsDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CcharacterStatisticsDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CcharacterStatisticsDlg 消息处理程序

BOOL CcharacterStatisticsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码**********************************************
	Tree = NULL;
	tree = NULL;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcharacterStatisticsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcharacterStatisticsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcharacterStatisticsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcharacterStatisticsDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CcharacterStatisticsDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

//字符统计
void CcharacterStatisticsDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);	//将控件中的内容同步到CString中
	//将CString转换为char数组
	string key = CT2A(m_edit.GetBuffer());
	strcpy_s(str, key.c_str());
	
	//memcpy(str, m_edit, m_edit.GetLength());
	/*
	方法一: 
         char *p; 
         CString str="hello"; 
         p=str.GetBuffer(str.GetLength()); 
         str.ReleaseBuffer(); 
       方法二: 
       CString str="hello"; 
       char ch[20]; 
       memcpy(ch,str,str.GetLength()); 
      方法三: 
        char *ch; 
        CString str="hello"; 
        ch=(LPSTR)(LPCTSTR)str;
	*/
	//生成二叉排序树
	for (int i = 0; str[i]; i++)
		insertBSTree(Tree, str[i]);
	//展示字符二叉树(用文件方式)
	preTraversal(Tree);
	AfxMessageBox(_T("字符统计成功！"));
}

//单词统计
void CcharacterStatisticsDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	string key = CT2A(m_edit.GetBuffer());
	//init_BST(tree);
	cToString(tree, key);
	preTraversalBSTR(tree);
	AfxMessageBox(_T("单词统计成功！"));
}
