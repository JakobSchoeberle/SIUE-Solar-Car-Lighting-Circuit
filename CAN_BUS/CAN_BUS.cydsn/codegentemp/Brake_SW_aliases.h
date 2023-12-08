/*******************************************************************************
* File Name: Brake_SW.h  
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

#if !defined(CY_PINS_Brake_SW_ALIASES_H) /* Pins Brake_SW_ALIASES_H */
#define CY_PINS_Brake_SW_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Brake_SW_0			(Brake_SW__0__PC)
#define Brake_SW_0_PS		(Brake_SW__0__PS)
#define Brake_SW_0_PC		(Brake_SW__0__PC)
#define Brake_SW_0_DR		(Brake_SW__0__DR)
#define Brake_SW_0_SHIFT	(Brake_SW__0__SHIFT)
#define Brake_SW_0_INTR	((uint16)((uint16)0x0003u << (Brake_SW__0__SHIFT*2u)))

#define Brake_SW_INTR_ALL	 ((uint16)(Brake_SW_0_INTR))


#endif /* End Pins Brake_SW_ALIASES_H */


/* [] END OF FILE */
