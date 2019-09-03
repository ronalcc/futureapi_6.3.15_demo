#include "stdafx.h"
#include "main.h"

int main()
{
	system("COLOR 0A");
	logfile = fopen("syslog.txt", "w");

	string g_chFrontaddr = getConfig("config", "FrontAddr");
	cout << "g_chFrontaddr = " << g_chFrontaddr << "\n" << endl;
	CTraderApi *pUserApi = new CTraderApi;//--------------------------
	pUserApi->CreateFtdcTraderApi(".\\flow\\");
	LOG(pUserApi->GetApiVersion());
	cout << endl;
	CSimpleHandler sh(pUserApi);
cir:pUserApi->RegisterSpi(&sh);
	pUserApi->SubscribePrivateTopic(THOST_TERT_QUICK);
	pUserApi->SubscribePublicTopic(THOST_TERT_QUICK);
	pUserApi->RegisterFront(const_cast<char *>(g_chFrontaddr.c_str()));
	pUserApi->Init();
	WaitForSingleObject(g_hEvent, INFINITE);

	sh.ReqAuthenticate();
	WaitForSingleObject(g_hEvent, INFINITE);
	sh.ReqUserLogin();
	WaitForSingleObject(g_hEvent, INFINITE);
		

	

	//string g_chFrontMdaddr = getConfig("config", "FrontMdAddr");
	//cout << "g_chFrontMdaddr = " << g_chFrontMdaddr << "\n" << endl;
	//CThostFtdcMdApi  *pUserMdApi = 
	//	CThostFtdcMdApi::CreateFtdcMdApi(".\\flow\\md");
	//CSimpleMdHandler ash(pUserMdApi);
	//pUserMdApi->RegisterSpi(&ash);
	//pUserMdApi->RegisterFront(const_cast<char *>(g_chFrontMdaddr.c_str()));
	//pUserMdApi->Init();
	WaitForSingleObject(xinhao, INFINITE);
	sh.ReqQryInstrument();//查询合约
	WaitForSingleObject(xinhao, INFINITE);
	//ash.SubscribeMarketData();//订阅行情
	//pUserMdApi->Release();

}

