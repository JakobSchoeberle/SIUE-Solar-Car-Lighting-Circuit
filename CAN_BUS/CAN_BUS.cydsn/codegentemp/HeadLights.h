/*******************************************************************************
* File Name: HeadLights.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_HeadLights_H) /* Pins HeadLights_H */
#define CY_PINS_HeadLights_H

#include "cytypes.h"
#include "cyfitter.h"
#include "HeadLights_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} HeadLights_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   HeadLights_Read(void);
void    HeadLights_Write(uint8 value);
uint8   HeadLights_ReadDataReg(void);
#if defined(HeadLights__PC) || (CY_PSOC4_4200L) 
    void    HeadLights_SetDriveMode(uint8 mode);
#endif
void    HeadLights_SetInterruptMode(uint16 position, uint16 mode);
uint8   HeadLights_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void HeadLights_Sleep(void); 
void HeadLights_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(HeadLights__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define HeadLights_DRIVE_MODE_BITS        (3)
    #define HeadLights_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - HeadLights_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the HeadLights_SetDriveMode() function.
         *  @{
         */
        #define HeadLights_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define HeadLights_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define HeadLights_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define HeadLights_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define HeadLights_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define HeadLights_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define HeadLights_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define HeadLights_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define HeadLights_MASK               HeadLights__MASK
#define HeadLights_SHIFT              HeadLights__SHIFT
#define HeadLights_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in HeadLights_SetInterruptMode() function.
     *  @{
     */
        #define HeadLights_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define HeadLights_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define HeadLights_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define HeadLights_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(HeadLights__SIO)
    #define HeadLights_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(HeadLights__PC) && (CY_PSOC4_4200L)
    #define HeadLights_USBIO_ENABLE               ((uint32)0x80000000u)
    #define HeadLights_USBIO_DISABLE              ((uint32)(~HeadLights_USBIO_ENABLE))
    #define HeadLights_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define HeadLights_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define HeadLights_USBIO_ENTER_SLEEP          ((uint32)((1u << HeadLights_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << HeadLights_USBIO_SUSPEND_DEL_SHIFT)))
    #define HeadLights_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << HeadLights_USBIO_SUSPEND_SHIFT)))
    #define HeadLights_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << HeadLights_USBIO_SUSPEND_DEL_SHIFT)))
    #define HeadLights_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(HeadLights__PC)
    /* Port Configuration */
    #define HeadLights_PC                 (* (reg32 *) HeadLights__PC)
#endif
/* Pin State */
#define HeadLights_PS                     (* (reg32 *) HeadLights__PS)
/* Data Register */
#define HeadLights_DR                     (* (reg32 *) HeadLights__DR)
/* Input Buffer Disable Override */
#define HeadLights_INP_DIS                (* (reg32 *) HeadLights__PC2)

/* Interrupt configuration Registers */
#define HeadLights_INTCFG                 (* (reg32 *) HeadLights__INTCFG)
#define HeadLights_INTSTAT                (* (reg32 *) HeadLights__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define HeadLights_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(HeadLights__SIO)
    #define HeadLights_SIO_REG            (* (reg32 *) HeadLights__SIO)
#endif /* (HeadLights__SIO_CFG) */

/* USBIO registers */
#if !defined(HeadLights__PC) && (CY_PSOC4_4200L)
    #define HeadLights_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define HeadLights_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define HeadLights_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define HeadLights_DRIVE_MODE_SHIFT       (0x00u)
#define HeadLights_DRIVE_MODE_MASK        (0x07u << HeadLights_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins HeadLights_H */


/* [] END OF FILE */
