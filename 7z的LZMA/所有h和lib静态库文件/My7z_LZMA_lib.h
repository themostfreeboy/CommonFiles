#pragma once

#ifndef __MY7Z_LZMA_LIB_H
#define __MY7Z_LZMA_LIB_H

#pragma comment(lib,"My7z_LZMA.lib")

int My7z_LZMA_CodeFile(const char *in_file_name, const char* out_file_name);//ͨ��LZMA�㷨ѹ��
int My7z_LZMA_DecodeFile(const char *in_file_name, const char* out_file_name);//ͨ��LZMA�㷨��ѹ������ѹһ����My7z_LZMA_CodeFile����ѹ���������ļ��ᵼ�»���������������������bug��δ���

#endif