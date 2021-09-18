#include <iostream>
#include <ctime>
#include <winsock2.h>
#include <windows.h>

#pragma comment (lib, "libws2_32.a")

int main(){

  time_t t = time(NULL);
  WSADATA wsaData;
  int  iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
  printf("WSAStartup(): %d\n",iResult);
  if (iResult != 0) {
       printf("WSAStartup failed with error: %d\n", iResult);
      return 1;
  }

  printf("**** WELCOME VSCODE! Toi la NVT\n");
  for (int i = 0; i < 5; ++ i) printf("---\n");
  
  // cleanup
  WSACleanup();
  printf("\n*** EXIT APP ***\n");
  
  return 1;
}
