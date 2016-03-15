// MfcSerialization Exercise.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
#include <tchar.h>  
#include <afx.h>
#include "People.h"


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	CPeople peo("����", 25, '1');

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

	//wcout << "����:" << name.GetBuffer(name.GetLength()) << endl;  

	CString name = p->getName();
	wchar_t* pch = name.GetBuffer(0);
	wcout << "����:" << pch << endl;
	name.ReleaseBuffer(); //ע���ͷ�  

	cout << "�Ա�:" << p->getSex() << endl;
	cout << "����:" << p->getAge() << endl;

	getchar();

	delete p;
	return 0;
}

