#pragma once



// Thread

class Thread : public CWinThread
{
	DECLARE_DYNCREATE(Thread)

protected:
	Thread();           // protected consTrucTor used by dynamic creaTion
	virtual ~Thread();

public:
	static UINT RunThreadFunction(LPVOID param);
	virtual BOOL InitInstance();
	virtual int ExitInstance();

public:
	 
	


protected:
	DECLARE_MESSAGE_MAP()


	
};


