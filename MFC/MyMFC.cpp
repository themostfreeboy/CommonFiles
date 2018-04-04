#include "MyMFC.h"
//#include "stdafx.h"

void MyCreatDirectory(std::string str)//�½��ļ���         e.g.:MyCreatDirectory("D:\\Boxing");
{
	CString strFolderPath(str.c_str());//stringתCString
	if (!PathIsDirectory(strFolderPath))//�ж�·���Ƿ����
	{

		//��������
		SECURITY_ATTRIBUTES attribute;
		attribute.nLength = sizeof(attribute);
		attribute.lpSecurityDescriptor = NULL;
		attribute.bInheritHandle = FALSE;

		CreateDirectory(strFolderPath, &attribute);
	}
}

void MyCreatDirectory(CString cstr)//�½��ļ���
{
	CString strFolderPath = cstr;
	if (!PathIsDirectory(strFolderPath))//�ж�·���Ƿ����
	{

		//��������
		SECURITY_ATTRIBUTES attribute;
		attribute.nLength = sizeof(attribute);
		attribute.lpSecurityDescriptor = NULL;
		attribute.bInheritHandle = FALSE;

		CreateDirectory(strFolderPath, &attribute);
	}
}

LPCTSTR MyCharToLPCTSTR(const char* szStrtemp)//char*תLPCTSTR
{
	char* szStr = new char[512];//Ϊ�˱���ֱ�ӶԴ���ĵ�ַ���иĶ���������һ���ڴ沢�Ѵ�������ݸ���
	strcpy_s(szStr, 512, szStrtemp);//���ƴ��������
	WCHAR wszClassName[512];
	memset(wszClassName, 0, sizeof(wszClassName));
	MultiByteToWideChar(CP_ACP, 0, szStr, strlen(szStr) + 1, wszClassName, sizeof(wszClassName) / sizeof(wszClassName[0]));
	delete[] szStr;//�ͷ��ڴ�
	WCHAR wszClassNameReturn[512];//Ϊ�˱���ֱ�ӶԴ����ĵ�ַ���иĶ���������һ���ڴ沢�Ѵ��������ݸ���
	wcscpy_s(wszClassNameReturn, 512, wszClassName);//���ƴ���������
	return wszClassNameReturn;
}

LPCWSTR MyCharToLPCWSTR(const char* szStrtemp)//char*תLPCWSTR
{
	LPCWSTR lpcwstr = CA2W(szStrtemp);
	return lpcwstr;
}

LPWSTR MyCharToLPWSTR(const char* szStrtemp)//char*תLPWSTR
{
	LPWSTR lpwstr = CA2W(szStrtemp);
	return lpwstr;
}

CString MyCharToCString(const char* szStrtemp)//char*תCString
{
	CString cstr(szStrtemp);
	return cstr;
}

const char* MyCStringToConstChar(CString cstr)//CStringתconst char*
{
	char *ptr;
    #ifdef _UNICODE
    LONG len;
    len = WideCharToMultiByte(CP_ACP, 0, cstr, -1, NULL, 0, NULL, NULL);
    ptr = new char [len+1];
    memset(ptr,0,len + 1);
    WideCharToMultiByte(CP_ACP, 0, cstr, -1, ptr, len + 1, NULL, NULL);
    #else
    ptr = new char [cstr.GetAllocLength()+1];
    sprintf(ptr,_T("%s"),cstr);
    #endif
    return ptr;
}

LPCTSTR MyCStringToLPCTSTR(CString cstr)//CStringתLPCTSTR
{

	LPCTSTR lpctstr = (LPCTSTR)cstr;
	return lpctstr;
}

std::string MyCStringToString(CString cstr)//CStringתstring
{
	CT2A xx(cstr);
	std::string str = xx;
	return str;
}

CString MyStringToCString(std::string str)//stringתCString
{
	CString cstr(str.c_str());
	return cstr;
}

double MyCStringToDouble(CString cstr)//CStringתdouble
{
	double dou;
	dou = _wtof(cstr);
	return dou;
}

const char* MyDoubleToChar(double dou)//doubleתchar*
{
	char buffer[512];
	sprintf_s(buffer, "%f", dou);
	return buffer;
}

CString MyGetTime(std::string str)//��ȡϵͳʱ��       e.g.:MyGetTime("D://Boxing//%Y%m%d%H%M%S.png");
{
	CString cstr_result;
	CTime tm;
	tm = CTime::GetCurrentTime();
	CString cstr_temp(str.c_str());
	cstr_result = tm.Format(cstr_temp);
	return cstr_result;
}

CString MyGetTime(CString cstr)//��ȡϵͳʱ��
{
	CString cstr_result;
	CTime tm;
	tm = CTime::GetCurrentTime();
	cstr_result = tm.Format(cstr);
	return cstr_result;
}

char* MyGetFileName(const char* path_name)//��·���л�ȡ�ļ���
{
	char file_name[100];
	int i=0;
	for(i=strlen(path_name);i>=0;i--)
	{
		if(path_name[i]=='\\')
		{
			strcpy(file_name,&(path_name[i+1]));
			break;
		}
	}
	return file_name;
}

char* MyAddFileName(const char* path_name, const char* add_name)//���ļ�����׺ǰ�������ַ���
{
	char new_path_name[100];
	int i=0,j=0;
	for(i=strlen(path_name);i>=0;i--)
	{
		if(path_name[i]=='.')
		{
			for(j=0;j<i;j++)
			{
				new_path_name[j]=path_name[j];
			}
			for(j=strlen(path_name);j>=i;j--)
			{
				new_path_name[j+strlen(add_name)]=path_name[j];
			}
			for(j=0;j<strlen(add_name);j++)
			{
				new_path_name[i+j]=add_name[j];
			}
			break;
		}
	}
	return new_path_name;
}

LPCWSTR MyWstringToLPCWSTR(std::wstring wstr)//wstringתLPCWSTR
{
	LPCWSTR lpcwstr(wstr.c_str());
	return lpcwstr;
}


long MyGetFileSize(const char* filename)//��ȡ�ļ���С�����ô˺���ʱ���ļ����봦��δ�򿪶�д״̬
{
	FILE *fp = NULL;
	errno_t err;
	err = fopen_s(&fp, filename, "rb");
	if (err != 0)
	{
		return -1;//�ļ���ʧ��
	}
    fseek(fp,0,SEEK_SET);
    fseek(fp,0,SEEK_END);
    long filesize=ftell(fp);
    rewind(fp);
	fclose(fp);
	return filesize;
}

