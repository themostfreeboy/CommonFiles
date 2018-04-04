#pragma once

#ifndef __MY7Z_LZMA_LIB_H
#define __MY7Z_LZMA_LIB_H

#pragma comment(lib,"My7z_LZMA.lib")

int My7z_LZMA_CodeFile(const char *in_file_name, const char* out_file_name);//通过LZMA算法压缩
int My7z_LZMA_DecodeFile(const char *in_file_name, const char* out_file_name);//通过LZMA算法解压缩，解压一个非My7z_LZMA_CodeFile函数压缩的任意文件会导致缓冲区溢出，程序崩溃，此bug尚未解决

#endif