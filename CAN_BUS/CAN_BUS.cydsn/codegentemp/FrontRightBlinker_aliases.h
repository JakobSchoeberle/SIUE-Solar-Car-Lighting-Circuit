/*******************************************************************************
* File Name: FrontRightBlinker.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_FrontRightBlinker_ALIASES_H) /* Pins FrontRightBlinker_ALIASES_H */
#define CY_PINS_FrontRightBlinker_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define FrontRightBlinker_0			(FrontRightBlinker__0__PC)
#define FrontRightBlinker_0_PS		(FrontRightBlinker__0__PS)
#define FrontRightBlinker_0_PC		(FrontRightBlinker__0__PC)
#define FrontRightBlinker_0_DR		(FrontRightBlinker__0__DR)
#define FrontRightBlinker_0_SHIFT	(FrontRightBlinker__0__SHIFT)
#define FrontRightBlinker_0_INTR	((uint16)((uint16)0x0003u << (FrontRightBlinker__0__SHIFT*2u)))

#define FrontRightBlinker_INTR_ALL	 ((uint16)(FrontRightBlinker_0_INTR))


#endif /* End Pins FrontRightBlinker_ALIASES_H */


/* [] END OF FILE */
