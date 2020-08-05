// Thread.cpp : implemenTaTion file
//

#include "pch.h"
#include "Pattern Generator.h"
#include "Thread.h"
#include "Pattern GeneratorView.h"
#include "CPoints.h"


// Thread

IMPLEMENT_DYNCREATE(Thread, CWinThread)

Thread::Thread()
{
}

Thread::~Thread()
{
}

BOOL Thread::InitInstance()
{
	// TODO:  perform and per-Thread initialization here
	return TRUE;
}

int Thread::ExitInstance()
{
	// TODO:  perform any per-Thread cleanup here
	return CWinThread::ExitInstance();
}


BEGIN_MESSAGE_MAP(Thread, CWinThread)
END_MESSAGE_MAP()


// Thread message handlers
UINT Thread::RunThreadFunction (LPVOID param)
{
CPatternGeneratorView* pCounterThreadView = (CPatternGeneratorView*)param;



while (1)
{
	if (pCounterThreadView->m_iCounter == 1)
	{
		CPoint MyPoint;
		MyPoint.x = rand() / 500 + 150;
		MyPoint.y = rand() / 500 + 150;

		pCounterThreadView->m_PointArray.Add(MyPoint);

		Sleep(100);
	}
	else if (pCounterThreadView->m_iCounter == 2)
	{
		CPoint SphiralPoint;


		double dRadius = 0;
		double dTheta = 0;


		while (dTheta <= (300))
		{
			
			dRadius = dTheta;

			SphiralPoint.x = (dRadius * cos(dTheta / 10 * 3.14)) + pCounterThreadView->m_iXpoint;
			SphiralPoint.y = (dRadius * sin(dTheta / 10 * 3.14)) + pCounterThreadView->m_iYpoint;

			pCounterThreadView->m_SphiralArray.Add(SphiralPoint);
			dTheta++;
			Sleep(50);
			pCounterThreadView->Invalidate();
		}
	}
	else if (pCounterThreadView->m_iCounter == 3)
	{
		CPointDamp DampedPoint;
		
		
		while (1)
		{

			int iTime = 0;
			

			iTime = DampedPoint.m_damplitude;
			for (int a = 1; a < DampedPoint.m_damplitude; a++)
			{
				DampedPoint.m_dXd += DampedPoint.m_dTimePeriod / iTime;
				iTime--;
				DampedPoint.m_dYd -= 1;
				pCounterThreadView->m_DampedArray.Add(DampedPoint);


			}
			iTime = 1;
			for (int b = DampedPoint.m_damplitude; b > 0; b--)
			{

				DampedPoint.m_dXd += DampedPoint.m_dTimePeriod / iTime;
				iTime++;
				DampedPoint.m_dYd += 1;
				pCounterThreadView->m_DampedArray.Add(DampedPoint);


			}

			iTime = DampedPoint.m_damplitude;
			for (int a = 1; a < DampedPoint.m_damplitude; a++)
			{
				DampedPoint.m_dXd += DampedPoint.m_dTimePeriod / iTime;
				iTime--;
				DampedPoint.m_dYd += 1;
				pCounterThreadView->m_DampedArray.Add(DampedPoint);

			}

			iTime = 1;
			for (int b = DampedPoint.m_damplitude; b > 0; b--)
			{
				DampedPoint.m_dXd += DampedPoint.m_dTimePeriod / iTime;
				iTime++;
				DampedPoint.m_dYd -= 1;
				pCounterThreadView->m_DampedArray.Add(DampedPoint);

			}
			pCounterThreadView->m_DampedArray.Add(DampedPoint);


			DampedPoint.m_damplitude -= 9;

			pCounterThreadView->Invalidate();
			Sleep(50);
		}

	}
	
	pCounterThreadView->Invalidate();
	}
return 1;
}
