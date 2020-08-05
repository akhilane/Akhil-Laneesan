#include "pch.h"
#include "CPoints.h"

CPointDamp::CPointDamp()
{
	m_dRadius = 1;
	m_dXs = 10;
	m_dYs = 10;
	m_damplitude = 100;
	m_dTime = 7;
	m_dTimePeriod = m_dTime / 2;
	m_dXd = 10;
	m_dYd = 200;
}


CPointDamp::~CPointDamp()
{
}


