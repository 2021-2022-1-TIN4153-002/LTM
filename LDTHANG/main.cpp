#include "main.h"

CMainThread* _mainThread;

int main(){
  printf("CURRENT TIME: %s\n",CUtils::Time2String().c_str());
  printf("MAIN THREAD ID: %d\n",GetCurrentThreadId());
  
  if (!CSocket::InitWinsock()) return -1;

  printf("**** WELCOME VSCODE - MULTITHREAD\n");
  _mainThread = new CMainThread(1000);
  _mainThread->WaitCompleted();

  CSocket::CleanWinsock();
  printf("\n*** EXIT APP ***\n");

  return 1;
}