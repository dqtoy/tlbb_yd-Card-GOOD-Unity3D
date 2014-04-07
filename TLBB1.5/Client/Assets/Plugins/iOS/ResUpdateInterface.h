#ifndef __RESUPDATEINTERFACE_H__
#define __RESUPDATEINTERFACE_H__

//#include "UpdateProcedure.h"

#ifdef WIN32
	#ifdef RESUPDATE_EXPORTS
		#define _ResupdateExport _declspec(dllexport)
		#pragma message("update lib export")
	#elif RESUPDATE_IMPORTS
		#define _ResupdateExport _declspec(dllimport)
		#pragma message("update lib import")
	#else
		#define _ResupdateExport
	#pragma message("update lib not in win32")
	#endif
#else
	#pragma message("update lib un import export")
	#define _ResupdateExport
#endif

extern "C"
{

	// ��ʼ�����³���
	_ResupdateExport void  InitUpdate();

	// ������Ŀ�ڱ��صĹ���Ŀ¼����update.ru��ͬ��Ŀ¼
	_ResupdateExport void SetAppWorkDir(const char *dir);

	// ������Դ���·�������url������http://127.0.0.1:8080,�������˼���,��Ҫ�ӷ�б�ߺ�url����,Ҳ����ʹ��http://����:�˿�
	_ResupdateExport void SetResourceUrl(const char *url);

	// ������Դ�������ĸ�Ŀ¼������rootΪmc/,���õ�ʱ��Ҫ���Ǽ�/
	_ResupdateExport void SetAppRoot(const char *root);

	// ������Դ��ʽ����Ҫ��֤����Դ������������Ӧ��Ŀ¼������ios����android
	_ResupdateExport  void SetResourceFormat(const char *format);

	// ���ð�װ�����еİ汾�ţ���ʽΪx.x.x.x
	_ResupdateExport void SetAppVersion(const char *version);

	// ��ȡ��װ�����еİ汾��
	_ResupdateExport const char* GetAppVersion();
	// tick
	_ResupdateExport void UpdateTick();

	// ��ǰ�¼�����������Ҫѭ���Ĳ�׽�¼�����Ҫ��ʱ��������Ӧ
	_ResupdateExport	 int GetPushEventType();
	
	/*
	enum MESSAGETYPE			//!< ���ع������õ�����ʾ��Ϣ����downloadDictionary.txt����һһ��Ӧ
	{
	MSG_INVALID = -1,     // Ŀǰû���¼�
	//		MSG_OK = 0,				//!< ȷ��
	//		MSG_CANCEL,				//!< ȡ��
	MSG_NETERROR = 10001 ,			//!< ���������쳣
	MSG_NEWAPP,				//!< ���������
	MSG_NOSDCARD,			//!< û��SD��
	MSG_SPACENOTENOUGH,		//!< �ڴ�����
	MSG_NOTDEFFINEERROR,	//!< δ�������
	MSG_TOTALNUM,			//!< ������Ϣ ��ʾ�ж�������ʾ
	MSG_UPDATE_APP,    // ��Ҫ���³���
	MSG_UPDATE_RES,      // ��Ҫ���±�Ҫ��Դ
	MSG_UPDATING,          //  ��Դ������
	MSG_UPDATE_FINNISH, // ��Դ�������
	MSG_VERSIONERROR,		//!< �汾�Ŵ���
	MSG_DOWN_MD5_ERR, // ����Md5.ru����
	MSG_READ_JSON_ERR, // �޷���ȡjson����
	MSG_JSON_FORMAT_ERR, // ��ȡjson��keyʧ��
	MSG_PARSE_HTTP_ERR, // ����httpͷ����
	MSG_CHECK_MD5_ERR, // check���ص�MD5����
	MSG_COPY_UPDATE_ERR, // ����update.ruʧ��
	MSG_NOT_UPDATE,  // ����Ҫ����
	MSG_CANNOT_CONNECT_SERVER, // �޷����ӵ����·�����,��������
	MSG_RECONNECT_SERVER, // ���ڳ����������·�����
	MSG_UPADTE_EXIST,     // �Ѿ���һ��update����������
	MSG_DOWN_LIST_ERR, // ����֮ǰ������Ҫ���ص��ļ���������
	MSG_UPDATE_UN_RES, // ��Ҫ���·Ǳ�Ҫ��Դ
	MSG_UPDATE_ALL_RES, // ��Ҫ���±�Ҫ��Դ�ͷǱ�Ҫ��Դ
	MSG_UPDATING_APP, // ���ڸ��³���(����)    
	MSG_INSTALLING_APP, // ���ڰ�װ����
	};

	*/

	// �����Ƿ���£�������֮ǰ��Ҫ��׽����Ҫ���µ��¼�
	_ResupdateExport void SetIsUpdate(bool isupdate);

	// ��ȡ��Ҫ���µ��ļ���С��Ӧ���ڲ�׽����Ҫ���µ��¼��Ժ����
	_ResupdateExport unsigned int GetDownSize();

	// ��ȡ��Ҫ���ؼ����ļ���Ӧ���ڲ�׽����Ҫ���µ��¼��Ժ����
	_ResupdateExport int GetTotalDownNumber();

	// ��ȡ��ǰ���ص��ǵڼ����ļ�
	_ResupdateExport int GetCurrentDownNumber();

	// ��ȡ��ǰ�ļ����½���,�ٷ���, 1Ϊ1%
	_ResupdateExport int GetPercent();


	// �˳���Դ���³����ڶ������ٶ���
	_ResupdateExport void ExitUpdate();

};



#endif