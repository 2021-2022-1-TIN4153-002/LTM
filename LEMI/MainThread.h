#pragma once

#include "../_Common/Thread.h"

class CMainThread: public CThread {
public:
    CMainThread(UINT dwDelay = 100, void* pData = NULL);
    ~CMainThread();
protected:
    void OnInit();
    void OnExit();
    void OnLoop();
};