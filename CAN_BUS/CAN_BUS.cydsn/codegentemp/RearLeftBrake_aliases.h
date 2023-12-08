/*******************************************************************************
* File Name: RearLeftBrake.h  
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

#if !defined(CY_PINS_RearLeftBrake_ALIASES_H) /* Pins RearLeftBrake_ALIASES_H */
#define CY_PINS_RearLeftBrake_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define RearLeftBrake_0			(RearLeftBrake__0__PC)
#define RearLeftBrake_0_PS		(RearLeftBrake__0__PS)
#define RearLeftBrake_0_PC		(RearLeftBrake__0__PC)
#define RearLeftBrake_0_DR		(RearLeftBrake__0__DR)
#define RearLeftBrake_0_SHIFT	(RearLeftBrake__0__SHIFT)
#define RearLeftBrake_0_INTR	((uint16)((uint16)0x0003u << (RearLeftBrake__0__SHIFT*2u)))

#define RearLeftBrake_INTR_ALL	 ((uint16)(RearLeftBrake_0_INTR))


#endif /* End Pins RearLeftBrake_ALIASES_H */


/* [] END OF FILE */
