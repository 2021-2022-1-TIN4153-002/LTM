#pragma once

#include <iostream>
#include <ctime>
#include <string>
#include <winsock2.h>
#include <windows.h>


class CUtils{
public:
    static std::string StringFormat(const char* fmt, ...);
    static std::string Time2String(struct tm* tInfo = NULL);
protected:
    CUtils(){};
    ~CUtils(){};    
};

