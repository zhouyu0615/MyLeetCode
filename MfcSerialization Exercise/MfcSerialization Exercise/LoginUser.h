#pragma once

#include "stdafx.h" 
#include <afx.h>  
#include <atlstr.h>  
#include <string>  

class CLoginUser:public CObject
{
public:

	DECLARE_SERIAL(CLoginUser);

	CLoginUser(void); 
	 ~CLoginUser();

	//CLoginUser& operator = (const CLoginUser& otherUser);

	int m_Id;

	CString m_strLoginName;
	CString m_strLoginPassWd;
	CString m_strCreatedDateTime;
	CString m_strLastLoginInTime;
	int m_PermissionLevel;
	CString m_strLastUpdatedDateTime;
	int m_IsAutoLogin;
	int m_IsRememberPasswd;
	CTime   m_LastLoginInTime;			//记录登录时间///
	CTime	m_LastUpdatedDateTime;		//记住修改时间///

public:
	virtual void Serialize(CArchive& ar);	
};

