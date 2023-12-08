/*******************************************************************************
* File Name: LeftBlinker_BTN.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "LeftBlinker_BTN.h"

static LeftBlinker_BTN_BACKUP_STRUCT  LeftBlinker_BTN_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: LeftBlinker_BTN_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet LeftBlinker_BTN_SUT.c usage_LeftBlinker_BTN_Sleep_Wakeup
*******************************************************************************/
void LeftBlinker_BTN_Sleep(void)
{
    #if defined(LeftBlinker_BTN__PC)
        LeftBlinker_BTN_backup.pcState = LeftBlinker_BTN_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            LeftBlinker_BTN_backup.usbState = LeftBlinker_BTN_CR1_REG;
            LeftBlinker_BTN_USB_POWER_REG |= LeftBlinker_BTN_USBIO_ENTER_SLEEP;
            LeftBlinker_BTN_CR1_REG &= LeftBlinker_BTN_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(LeftBlinker_BTN__SIO)
        LeftBlinker_BTN_backup.sioState = LeftBlinker_BTN_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        LeftBlinker_BTN_SIO_REG &= (uint32)(~LeftBlinker_BTN_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: LeftBlinker_BTN_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to LeftBlinker_BTN_Sleep() for an example usage.
*******************************************************************************/
void LeftBlinker_BTN_Wakeup(void)
{
    #if defined(LeftBlinker_BTN__PC)
        LeftBlinker_BTN_PC = LeftBlinker_BTN_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            LeftBlinker_BTN_USB_POWER_REG &= LeftBlinker_BTN_USBIO_EXIT_SLEEP_PH1;
            LeftBlinker_BTN_CR1_REG = LeftBlinker_BTN_backup.usbState;
            LeftBlinker_BTN_USB_POWER_REG &= LeftBlinker_BTN_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(LeftBlinker_BTN__SIO)
        LeftBlinker_BTN_SIO_REG = LeftBlinker_BTN_backup.sioState;
    #endif
}


/* [] END OF FILE */
