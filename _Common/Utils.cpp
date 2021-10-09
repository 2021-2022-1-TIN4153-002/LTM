#include "utils.h"

/* *** CÁC HÀM TIỆN ÍCH *** */
//Hàm định dạng chuỗi
std::string CUtils::StringFormat(const char* fmt, ...){
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
std::string CUtils::Time2String(struct tm* tInfo){
  if (!tInfo){
    time_t t = time(NULL);
    tInfo = localtime (&t);
  }
  char buffer [80];
  strftime (buffer,80,"%d-%m-%Y %H:%M:%S",tInfo);
  return std::string(buffer);
}
