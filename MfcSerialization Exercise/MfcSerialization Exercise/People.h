#pragma once

#include <afx.h>
#include <string.h>
#include <atlstr.h>

class CPeople:public CObject
{
public:
	CPeople(void);
	CPeople(CString name, int age, char sex);
	virtual ~CPeople();

	virtual void Serialize(CArchive& ar);
private:
	CString name;
	int age;
	char sex;

public:
	DECLARE_SERIAL(CPeople);

	CString getName()
	{
		return this->name;
	}

	int getAge()
	{
		return this->age;
	}
	char getSex()
	{
		return this->sex;
	}



};

