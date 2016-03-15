#include "stdafx.h"
#include "People.h"
#include <afx.h>  
#include <string>


IMPLEMENT_SERIAL(CPeople, CObject, VERSIONABLE_SCHEMA | 2)


CPeople::CPeople()
{};

CPeople::CPeople(CString name, int age, char sex) :name(name), age(age), sex(sex)
{
}


CPeople::~CPeople()
{
}

void CPeople::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	//关键代码  
	if (ar.IsStoring()) {
		//序列化  
		ar << this->age << this->sex << this->name;
	}
	else {
		//反序列化  
		ar >> this->age >> this->sex >> this->name;
	}
}
