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
	//�ؼ�����  
	if (ar.IsStoring()) {
		//���л�  
		ar << this->age << this->sex << this->name;
	}
	else {
		//�����л�  
		ar >> this->age >> this->sex >> this->name;
	}
}
