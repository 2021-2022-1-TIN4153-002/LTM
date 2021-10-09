#include "main.h"
#include "MainThread.h"

CMainThread::CMainThread(UINT dwDelay, void* pData) : CThread(dwDelay,pData)
{

}
CMainThread::~CMainThread(){

}

void CMainThread::OnInit(){
    printf("CMainThread::OnInit() : %d\n",m_dwTID);
}
void CMainThread::OnExit(){
    printf("CMainThread::OnExit() : %d\n",m_dwTID);
};

void CMainThread::OnLoop(){
    static UINT i = 0;
    ++i;
    printf("CMainThread::OnLoop() : %d %u [%d]\n",m_dwTID,GetTickCount(), i);
    if (i > 10) ExitThread();
}
