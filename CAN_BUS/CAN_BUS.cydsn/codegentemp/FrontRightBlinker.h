/*******************************************************************************
* File Name: FrontRightBlinker.h  
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

#if !defined(CY_PINS_FrontRightBlinker_H) /* Pins FrontRightBlinker_H */
#define CY_PINS_FrontRightBlinker_H

#include "cytypes.h"
#include "cyfitter.h"
#include "FrontRightBlinker_aliases.h"


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
} FrontRightBlinker_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   FrontRightBlinker_Read(void);
void    FrontRightBlinker_Write(uint8 value);
uint8   FrontRightBlinker_ReadDataReg(void);
#if defined(FrontRightBlinker__PC) || (CY_PSOC4_4200L) 
    void    FrontRightBlinker_SetDriveMode(uint8 mode);
#endif
void    FrontRightBlinker_SetInterruptMode(uint16 position, uint16 mode);
uint8   FrontRightBlinker_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void FrontRightBlinker_Sleep(void); 
void FrontRightBlinker_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(FrontRightBlinker__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define FrontRightBlinker_DRIVE_MODE_BITS        (3)
    #define FrontRightBlinker_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - FrontRightBlinker_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the FrontRightBlinker_SetDriveMode() function.
         *  @{
         */
        #define FrontRightBlinker_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define FrontRightBlinker_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define FrontRightBlinker_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define FrontRightBlinker_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define FrontRightBlinker_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define FrontRightBlinker_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define FrontRightBlinker_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define FrontRightBlinker_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define FrontRightBlinker_MASK               FrontRightBlinker__MASK
#define FrontRightBlinker_SHIFT              FrontRightBlinker__SHIFT
#define FrontRightBlinker_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in FrontRightBlinker_SetInterruptMode() function.
     *  @{
     */
        #define FrontRightBlinker_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define FrontRightBlinker_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define FrontRightBlinker_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define FrontRightBlinker_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(FrontRightBlinker__SIO)
    #define FrontRightBlinker_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(FrontRightBlinker__PC) && (CY_PSOC4_4200L)
    #define FrontRightBlinker_USBIO_ENABLE               ((uint32)0x80000000u)
    #define FrontRightBlinker_USBIO_DISABLE              ((uint32)(~FrontRightBlinker_USBIO_ENABLE))
    #define FrontRightBlinker_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define FrontRightBlinker_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define FrontRightBlinker_USBIO_ENTER_SLEEP          ((uint32)((1u << FrontRightBlinker_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << FrontRightBlinker_USBIO_SUSPEND_DEL_SHIFT)))
    #define FrontRightBlinker_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << FrontRightBlinker_USBIO_SUSPEND_SHIFT)))
    #define FrontRightBlinker_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << FrontRightBlinker_USBIO_SUSPEND_DEL_SHIFT)))
    #define FrontRightBlinker_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(FrontRightBlinker__PC)
    /* Port Configuration */
    #define FrontRightBlinker_PC                 (* (reg32 *) FrontRightBlinker__PC)
#endif
/* Pin State */
#define FrontRightBlinker_PS                     (* (reg32 *) FrontRightBlinker__PS)
/* Data Register */
#define FrontRightBlinker_DR                     (* (reg32 *) FrontRightBlinker__DR)
/* Input Buffer Disable Override */
#define FrontRightBlinker_INP_DIS                (* (reg32 *) FrontRightBlinker__PC2)

/* Interrupt configuration Registers */
#define FrontRightBlinker_INTCFG                 (* (reg32 *) FrontRightBlinker__INTCFG)
#define FrontRightBlinker_INTSTAT                (* (reg32 *) FrontRightBlinker__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define FrontRightBlinker_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(FrontRightBlinker__SIO)
    #define FrontRightBlinker_SIO_REG            (* (reg32 *) FrontRightBlinker__SIO)
#endif /* (FrontRightBlinker__SIO_CFG) */

/* USBIO registers */
#if !defined(FrontRightBlinker__PC) && (CY_PSOC4_4200L)
    #define FrontRightBlinker_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define FrontRightBlinker_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define FrontRightBlinker_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define FrontRightBlinker_DRIVE_MODE_SHIFT       (0x00u)
#define FrontRightBlinker_DRIVE_MODE_MASK        (0x07u << FrontRightBlinker_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins FrontRightBlinker_H */


/* [] END OF FILE */
