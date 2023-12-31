/*******************************************************************************
* File Name: Brake_SW.c  
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
#include "Brake_SW.h"

static Brake_SW_BACKUP_STRUCT  Brake_SW_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Brake_SW_Sleep
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
*  \snippet Brake_SW_SUT.c usage_Brake_SW_Sleep_Wakeup
*******************************************************************************/
void Brake_SW_Sleep(void)
{
    #if defined(Brake_SW__PC)
        Brake_SW_backup.pcState = Brake_SW_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Brake_SW_backup.usbState = Brake_SW_CR1_REG;
            Brake_SW_USB_POWER_REG |= Brake_SW_USBIO_ENTER_SLEEP;
            Brake_SW_CR1_REG &= Brake_SW_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Brake_SW__SIO)
        Brake_SW_backup.sioState = Brake_SW_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Brake_SW_SIO_REG &= (uint32)(~Brake_SW_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Brake_SW_Wakeup
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
*  Refer to Brake_SW_Sleep() for an example usage.
*******************************************************************************/
void Brake_SW_Wakeup(void)
{
    #if defined(Brake_SW__PC)
        Brake_SW_PC = Brake_SW_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Brake_SW_USB_POWER_REG &= Brake_SW_USBIO_EXIT_SLEEP_PH1;
            Brake_SW_CR1_REG = Brake_SW_backup.usbState;
            Brake_SW_USB_POWER_REG &= Brake_SW_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Brake_SW__SIO)
        Brake_SW_SIO_REG = Brake_SW_backup.sioState;
    #endif
}


/* [] END OF FILE */
