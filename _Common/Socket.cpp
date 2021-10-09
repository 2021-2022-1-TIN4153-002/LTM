#include "Socket.h"
#include "stdio.h"

/* *** CÁC HÀM VỀ WINSOCK*** */

//Hàm khởi tạo Winsock - sử dụng đầu tiên trong hàm main() hoặc khi khởi tạo Thread mới có sử dụng Network
bool CSocket::InitWinsock(){
  WSADATA wsaData;
  int  iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
  if (iResult != 0) {
      printf("WSAStartup failed with error: %d\n", iResult);
      return false;
  }
  return true;
}

//Hàm hủy winsock - sử dụng cuối cùng trong hàm main()
void CSocket::CleanWinsock(){
    WSACleanup();
}