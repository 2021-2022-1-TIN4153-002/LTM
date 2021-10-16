#pragma once

#include <windows.h>

class CThread;
typedef struct _ThreadData{
    CThread* pThis;
    void* pData;
}THREAD_DATA;

class CThread{
public:
    DWORD   WaitCompleted();
    void ExitThread();
protected:
    //dwDelay: tính bằng miliseconds, pData: dữ liệu khởi tạo cho Thread
    CThread(UINT dwDelay = 100, void* pData = NULL);
    ~CThread();
    virtual void OnInit();      //Khởi tạo Thread
    virtual void OnExit();      //Thoát khỏi Thread
    virtual void OnLoop() = 0;  //Xử lý vòng lặp Thread mỗi dwDelay miliseconds

    //Hàm đầu vào của CreateThread
    static UINT _EntryThread(LPVOID lParam);
    void OnEntryThread();

    //Các biến thuộc Thread
    HANDLE  m_hThread;
    DWORD   m_dwTID;
    void*   m_pData;
    HANDLE  m_hEvent;
    UINT    m_dwDelay;
    BOOL    m_bRunning;
};