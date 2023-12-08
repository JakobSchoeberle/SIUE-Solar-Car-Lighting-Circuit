/*******************************************************************************
* File Name: LeftBlinker_BTN.h  
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

#if !defined(CY_PINS_LeftBlinker_BTN_ALIASES_H) /* Pins LeftBlinker_BTN_ALIASES_H */
#define CY_PINS_LeftBlinker_BTN_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LeftBlinker_BTN_0			(LeftBlinker_BTN__0__PC)
#define LeftBlinker_BTN_0_PS		(LeftBlinker_BTN__0__PS)
#define LeftBlinker_BTN_0_PC		(LeftBlinker_BTN__0__PC)
#define LeftBlinker_BTN_0_DR		(LeftBlinker_BTN__0__DR)
#define LeftBlinker_BTN_0_SHIFT	(LeftBlinker_BTN__0__SHIFT)
#define LeftBlinker_BTN_0_INTR	((uint16)((uint16)0x0003u << (LeftBlinker_BTN__0__SHIFT*2u)))

#define LeftBlinker_BTN_INTR_ALL	 ((uint16)(LeftBlinker_BTN_0_INTR))


#endif /* End Pins LeftBlinker_BTN_ALIASES_H */


/* [] END OF FILE */
