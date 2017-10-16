
// xAnso_winDlg.h : 头文件
//

#pragma once


// CxAnso_winDlg 对话框
class CxAnso_winDlg : public CDialogEx
{
// 构造
public:
	CxAnso_winDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_XANSO_WIN_DIALOG };

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
	afx_msg void OnBnClickedBtnFileopenpath();
	afx_msg void OnBnClickedBtnFilesavapath();
	afx_msg void OnBnClickedBtnRebuildso();
	afx_msg void OnBnClickedBtnRepiareso();
};
