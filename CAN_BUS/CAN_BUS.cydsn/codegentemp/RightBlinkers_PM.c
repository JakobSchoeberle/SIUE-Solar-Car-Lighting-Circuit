/*******************************************************************************
* File Name: RightBlinkers_PM.c
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

#include "RightBlinkers.h"

/* Check for removal by optimization */
#if !defined(RightBlinkers_Sync_ctrl_reg__REMOVED)

static RightBlinkers_BACKUP_STRUCT  RightBlinkers_backup = {0u};

    
/*******************************************************************************
* Function Name: RightBlinkers_SaveConfig
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
void RightBlinkers_SaveConfig(void) 
{
    RightBlinkers_backup.controlState = RightBlinkers_Control;
}


/*******************************************************************************
* Function Name: RightBlinkers_RestoreConfig
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
void RightBlinkers_RestoreConfig(void) 
{
     RightBlinkers_Control = RightBlinkers_backup.controlState;
}


/*******************************************************************************
* Function Name: RightBlinkers_Sleep
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
void RightBlinkers_Sleep(void) 
{
    RightBlinkers_SaveConfig();
}


/*******************************************************************************
* Function Name: RightBlinkers_Wakeup
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
void RightBlinkers_Wakeup(void)  
{
    RightBlinkers_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
