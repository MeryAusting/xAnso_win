
// xAnso_winDlg.h : ͷ�ļ�
//

#pragma once


// CxAnso_winDlg �Ի���
class CxAnso_winDlg : public CDialogEx
{
// ����
public:
	CxAnso_winDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_XANSO_WIN_DIALOG };

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
	afx_msg void OnBnClickedBtnFileopenpath();
	afx_msg void OnBnClickedBtnFilesavapath();
	afx_msg void OnBnClickedBtnRebuildso();
	afx_msg void OnBnClickedBtnRepiareso();
};
