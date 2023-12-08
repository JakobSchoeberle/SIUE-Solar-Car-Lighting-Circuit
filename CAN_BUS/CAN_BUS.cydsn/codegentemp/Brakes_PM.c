/*******************************************************************************
* File Name: Brakes_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Brakes.h"

/* Check for removal by optimization */
#if !defined(Brakes_Sync_ctrl_reg__REMOVED)

static Brakes_BACKUP_STRUCT  Brakes_backup = {0u};

    
/*******************************************************************************
* Function Name: Brakes_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Brakes_SaveConfig(void) 
{
    Brakes_backup.controlState = Brakes_Control;
}


/*******************************************************************************
* Function Name: Brakes_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void Brakes_RestoreConfig(void) 
{
     Brakes_Control = Brakes_backup.controlState;
}


/*******************************************************************************
* Function Name: Brakes_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Brakes_Sleep(void) 
{
    Brakes_SaveConfig();
}


/*******************************************************************************
* Function Name: Brakes_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Brakes_Wakeup(void)  
{
    Brakes_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
