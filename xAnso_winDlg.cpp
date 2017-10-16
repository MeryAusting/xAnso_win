
// xAnso_winDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "xAnso_win.h"
#include "xAnso_winDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CxAnso_winDlg �Ի���



CxAnso_winDlg::CxAnso_winDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CxAnso_winDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CxAnso_winDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CxAnso_winDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_FileOpenPath, &CxAnso_winDlg::OnBnClickedBtnFileopenpath)
	ON_BN_CLICKED(IDC_BTN_FileSavaPath, &CxAnso_winDlg::OnBnClickedBtnFilesavapath)
	ON_BN_CLICKED(IDC_BTN_Rebuildso, &CxAnso_winDlg::OnBnClickedBtnRebuildso)
	ON_BN_CLICKED(IDC_BTN_RepiareSo, &CxAnso_winDlg::OnBnClickedBtnRepiareso)
END_MESSAGE_MAP()


// CxAnso_winDlg ��Ϣ�������

BOOL CxAnso_winDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CxAnso_winDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CxAnso_winDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CxAnso_winDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//�õ�so�ļ�·��
void CxAnso_winDlg::OnBnClickedBtnFileopenpath()
{
	CFileDialog dlg(TRUE, L".so", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"��ִ���ļ�(*.so)|*.so|�����ļ� (*.*)|*.*||");
	if (dlg.DoModal() == IDOK)
	{
		CString m_FilePath = dlg.GetPathName();
		SetDlgItemText(IDC_EDIT1, m_FilePath);
		UpdateData(FALSE);
	}
}

// �ؽ�so�󱣴�·��
void CxAnso_winDlg::OnBnClickedBtnFilesavapath()
{
	WCHAR szDir[MAX_PATH];
	BROWSEINFO bi;
	ITEMIDLIST *pidl;

	bi.hwndOwner = this->m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szDir;
	bi.lpszTitle = L"��ѡ��Ŀ¼";
	bi.ulFlags = BIF_RETURNONLYFSDIRS;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;

	pidl = SHBrowseForFolder(&bi);
	if (pidl == NULL){
		return;
	}

	if (SHGetPathFromIDList(pidl, szDir))
	{
		CString m_strSavePath;
		m_strSavePath.Format(L"%s", szDir);
		SetDlgItemText(IDC_EDIT2, m_strSavePath);
	}
}


void CxAnso_winDlg::OnBnClickedBtnRebuildso()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

}


void CxAnso_winDlg::OnBnClickedBtnRepiareso()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
