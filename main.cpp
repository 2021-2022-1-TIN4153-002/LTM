#include "main.h"

DWORD MainThread(LPVOID lParam){
  bool* pIsRunning = (bool*)lParam;
  DWORD tid = GetCurrentThreadId();
  printf("\n[MAIN THREAD] - TID %d - START\n",tid);
  
  while (*pIsRunning){
    printf("TID [%d] RUNNING %d\n",tid,GetTickCount());
    Sleep(1000);//1000ms -> 1s
  }

  printf("\n[MAIN THREAD] - TID %d - END\n",tid);
  return 1;
}

int main(){

  printf("CURRENT TIME: %s\n",Time2String().c_str());
  printf("MAIN THREAD ID: %d\n",GetCurrentThreadId());

  bool isMainRuning = true;

  if (!InitWinsock()) return -1;

  printf("**** WELCOME VSCODE - MULTITHREAD\n");

  HANDLE hMainThread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)MainThread,&isMainRuning,0,NULL);
  
  printf("Enter to exit:");
  getchar();
  isMainRuning = false;
  WaitForSingleObject(hMainThread,INFINITE);

  CleanWinsock();
  printf("\n*** EXIT APP ***\n");
  
  return 1;
}

/* *** CÁC HÀM VỀ WINSOCK*** */
//Hàm khởi tạo Winsock - sử dụng đầu tiên trong hàm main()
bool InitWinsock(){
  WSADATA wsaData;
  int  iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
  if (iResult != 0) {
      printf("WSAStartup failed with error: %d\n", iResult);
      return false;
  }
  return true;
}
//Hàm hủy winsock - sử dụng cuối cùng trong hàm main()
void CleanWinsock(){
  WSACleanup();
}

/* *** CÁC HÀM TIỆN ÍCH *** */
//Hàm định dạng chuỗi
std::string StringFormat(const char* fmt, ...){
  va_list vaArgs;
  va_start(vaArgs, fmt);
  va_list vaArgsCopy;
  va_copy(vaArgsCopy, vaArgs);
  const int iLen = vsnprintf(NULL, 0, fmt, vaArgsCopy);
  va_end(vaArgsCopy);
  int iSize = iLen + 1;
  char* buff = (char*)malloc(iSize);
  vsnprintf(buff, iSize, fmt, vaArgs);
  va_end(vaArgs);
  std::string s = buff;
  free(buff);
  return std::string(s);
}
//Hàm chuyển ngày giờ sang chuỗi
std::string Time2String(struct tm* tInfo){
  if (!tInfo){
    time_t t = time(NULL);
    tInfo = localtime (&t);
  }
  char buffer [80];
  strftime (buffer,80,"%d-%m-%Y %H:%M:%S",tInfo);
  return std::string(buffer);
}
