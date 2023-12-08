/*******************************************************************************
* File Name: HeadLights.h  
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

#if !defined(CY_PINS_HeadLights_ALIASES_H) /* Pins HeadLights_ALIASES_H */
#define CY_PINS_HeadLights_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define HeadLights_0			(HeadLights__0__PC)
#define HeadLights_0_PS		(HeadLights__0__PS)
#define HeadLights_0_PC		(HeadLights__0__PC)
#define HeadLights_0_DR		(HeadLights__0__DR)
#define HeadLights_0_SHIFT	(HeadLights__0__SHIFT)
#define HeadLights_0_INTR	((uint16)((uint16)0x0003u << (HeadLights__0__SHIFT*2u)))

#define HeadLights_INTR_ALL	 ((uint16)(HeadLights_0_INTR))


#endif /* End Pins HeadLights_ALIASES_H */


/* [] END OF FILE */
