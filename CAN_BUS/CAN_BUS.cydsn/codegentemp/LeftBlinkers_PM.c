/*******************************************************************************
* File Name: LeftBlinkers_PM.c
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

#include "LeftBlinkers.h"

/* Check for removal by optimization */
#if !defined(LeftBlinkers_Sync_ctrl_reg__REMOVED)

static LeftBlinkers_BACKUP_STRUCT  LeftBlinkers_backup = {0u};

    
/*******************************************************************************
* Function Name: LeftBlinkers_SaveConfig
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
void LeftBlinkers_SaveConfig(void) 
{
    LeftBlinkers_backup.controlState = LeftBlinkers_Control;
}


/*******************************************************************************
* Function Name: LeftBlinkers_RestoreConfig
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
void LeftBlinkers_RestoreConfig(void) 
{
     LeftBlinkers_Control = LeftBlinkers_backup.controlState;
}


/*******************************************************************************
* Function Name: LeftBlinkers_Sleep
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
void LeftBlinkers_Sleep(void) 
{
    LeftBlinkers_SaveConfig();
}


/*******************************************************************************
* Function Name: LeftBlinkers_Wakeup
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
void LeftBlinkers_Wakeup(void)  
{
    LeftBlinkers_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
