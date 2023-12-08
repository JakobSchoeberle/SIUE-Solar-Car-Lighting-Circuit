/*******************************************************************************
* File Name: RearCenterBrake.h  
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

#if !defined(CY_PINS_RearCenterBrake_ALIASES_H) /* Pins RearCenterBrake_ALIASES_H */
#define CY_PINS_RearCenterBrake_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define RearCenterBrake_0			(RearCenterBrake__0__PC)
#define RearCenterBrake_0_PS		(RearCenterBrake__0__PS)
#define RearCenterBrake_0_PC		(RearCenterBrake__0__PC)
#define RearCenterBrake_0_DR		(RearCenterBrake__0__DR)
#define RearCenterBrake_0_SHIFT	(RearCenterBrake__0__SHIFT)
#define RearCenterBrake_0_INTR	((uint16)((uint16)0x0003u << (RearCenterBrake__0__SHIFT*2u)))

#define RearCenterBrake_INTR_ALL	 ((uint16)(RearCenterBrake_0_INTR))


#endif /* End Pins RearCenterBrake_ALIASES_H */


/* [] END OF FILE */
