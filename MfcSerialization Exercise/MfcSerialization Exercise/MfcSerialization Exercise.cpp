// MfcSerialization Exercise.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <tchar.h>  
#include <afx.h>
#include "People.h"


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	CPeople peo("张三", 25, '1');

	CFile myFile(_T("d:/person.ser"), CFile::modeCreate | CFile::modeReadWrite);
	// Create a storing archive.  
	CArchive arStore(&myFile, CArchive::store);

	// Write the object to the archive  
	arStore.WriteObject(&peo);

	arStore.Flush();
	// Close the storing archive  
	arStore.Close();

	// Create a loading archive.  
	myFile.SeekToBegin();
	CArchive arLoad(&myFile, CArchive::load);

	// Verify the object is in the archive.  
	CPeople* p = (CPeople*)arLoad.ReadObject(peo.GetRuntimeClass());
	arLoad.Close();

	//wcout << "姓名:" << name.GetBuffer(name.GetLength()) << endl;  

	CString name = p->getName();
	wchar_t* pch = name.GetBuffer(0);
	wcout << "姓名:" << pch << endl;
	name.ReleaseBuffer(); //注意释放  

	cout << "性别:" << p->getSex() << endl;
	cout << "年龄:" << p->getAge() << endl;

	getchar();

	delete p;
	return 0;
}

