#pragma once

#include <winsock2.h>

class CSocket{
public:
    static bool InitWinsock();
    static void CleanWinsock();

protected:
};