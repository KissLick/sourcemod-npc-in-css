
#include "CAI_Link.h"


//-----------------------------------------------------------------------------
// Purpose:	Given the source node ID, returns the destination ID
// Input  :
// Output :
//-----------------------------------------------------------------------------	
int	CAI_Link::DestNodeID(int srcID)
{
	if (srcID == m_iSrcID)
	{
		return m_iDestID;
	}
	else
	{
		return m_iSrcID;
	}
}

//-----------------------------------------------------------------------------
// Purpose: Constructor
// Input  :
// Output :
//-----------------------------------------------------------------------------
CAI_Link::CAI_Link(void)
{
	m_iSrcID			= -1;
	m_iDestID			= -1;
	m_LinkInfo			= 0;
	m_timeStaleExpires = 0;
	m_pDynamicLink = NULL;

	for (int hull=0;hull<NUM_HULLS;hull++)
	{
		m_iAcceptedMoveTypes[hull] = 0;
	}

};

