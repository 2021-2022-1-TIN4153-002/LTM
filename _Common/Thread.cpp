#include "Thread.h"
#include "stdio.h"

CThread::CThread(UINT dwDelay, void* pData){
    m_dwDelay = dwDelay;
    m_pData = pData;
    //printf("CThread::CThread\n");
    m_hThread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)_EntryThread,(LPVOID)this,0,&m_dwTID);
}
CThread::~CThread(){

}

void CThread::OnInit(){

}
void CThread::OnExit(){

}

UINT CThread::_EntryThread(LPVOID lParam){
    CThread* pThis = (CThread*)lParam;
    //printf("CThread::_EntryThread(%p)\n",pThis);
    pThis->OnEntryThread();
    return 0xDEAD;
}
void CThread::OnEntryThread(){
    //printf("CThread::OnEntryThread()\n");
    m_bRunning = TRUE;
    m_hEvent = CreateEvent(NULL,FALSE,FALSE,NULL);

    OnInit();

    while (m_bRunning){
        UINT r = WaitForSingleObject(m_hEvent,m_dwDelay);
        if (r != WAIT_TIMEOUT) break;
        OnLoop();
    }

    OnExit();
}
DWORD CThread::WaitCompleted(){
    return WaitForSingleObject(m_hThread,INFINITE);
}

void CThread::ExitThread(){
    m_bRunning = FALSE;
    SetEvent(m_hEvent);
    if (m_dwTID != GetCurrentThreadId()) WaitForSingleObject(m_hThread,INFINITE);
}