#include <iostream>
#include <ctime>
#include <string>
#include <winsock2.h>
#include <windows.h>

std::string StringFormat(const char* fmt, ...);
std::string Time2String(struct tm* tInfo = NULL);

bool InitWinsock();
void CleanWinsock();
