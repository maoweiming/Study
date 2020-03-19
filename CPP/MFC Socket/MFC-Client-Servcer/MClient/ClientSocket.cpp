#include "pch.h"
#include "framework.h"
#include "ClientSocket.h"
#include "MClient.h"
#include "MClientDlg.h"

CClientSocket::CClientSocket()
{

}

CClientSocket::~CClientSocket()
{

}

void CClientSocket::OnRecevie(int nErrorCode)
{
    //*
    if (nErrorCode > 0)
    {
        char* pData = NULL;
        pData = new char[1024];
        memset(pData, 0, sizeof(char) * 1024);
        UCHAR leng = 0;
        CString str;
        leng = Receive(pData, 1024, 0);
        str = pData;
        // 在编辑框中显示接收到的数据
        ((CMClientDlg*)theApp.GetMainWnd())->SetDlgItemTextW(IDC_EDIT_RECIVE, str);
        delete pData;
        pData = NULL;
        CSocket::OnReceive(nErrorCode);
    }
  // */
}

int CClientSocket::SendMSG(LPSTR lpBuffer, int nLen)
{
    //生成协议头
    int nErrorCode = Send(lpBuffer, nLen);
    if (nErrorCode == SOCKET_ERROR)
    {
        AfxMessageBox(_T("发送错误！"));
        return FALSE;
    }
    CString e;
    e.Format(_T("%d"), nErrorCode);
    return  nErrorCode;
}
