#include "main.h"


int main(){

  printf("CURRENT TIME: %s\n",Time2String().c_str());

  if (!InitWinsock()) return -1;

  printf("**** WELCOME VSCODE - SOCKET\n");
  for (int i = 0; i < 5; ++ i) printf("[%d] ---\n",i);

  printf("Enter to exit:");
  getchar();

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
