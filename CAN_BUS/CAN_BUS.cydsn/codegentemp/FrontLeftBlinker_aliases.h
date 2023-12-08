/*******************************************************************************
* File Name: FrontLeftBlinker.h  
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

#if !defined(CY_PINS_FrontLeftBlinker_ALIASES_H) /* Pins FrontLeftBlinker_ALIASES_H */
#define CY_PINS_FrontLeftBlinker_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define FrontLeftBlinker_0			(FrontLeftBlinker__0__PC)
#define FrontLeftBlinker_0_PS		(FrontLeftBlinker__0__PS)
#define FrontLeftBlinker_0_PC		(FrontLeftBlinker__0__PC)
#define FrontLeftBlinker_0_DR		(FrontLeftBlinker__0__DR)
#define FrontLeftBlinker_0_SHIFT	(FrontLeftBlinker__0__SHIFT)
#define FrontLeftBlinker_0_INTR	((uint16)((uint16)0x0003u << (FrontLeftBlinker__0__SHIFT*2u)))

#define FrontLeftBlinker_INTR_ALL	 ((uint16)(FrontLeftBlinker_0_INTR))


#endif /* End Pins FrontLeftBlinker_ALIASES_H */


/* [] END OF FILE */
