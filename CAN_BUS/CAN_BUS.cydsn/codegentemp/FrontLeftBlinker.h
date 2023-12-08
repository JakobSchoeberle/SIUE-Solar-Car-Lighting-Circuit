/*******************************************************************************
* File Name: FrontLeftBlinker.h  
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

#if !defined(CY_PINS_FrontLeftBlinker_H) /* Pins FrontLeftBlinker_H */
#define CY_PINS_FrontLeftBlinker_H

#include "cytypes.h"
#include "cyfitter.h"
#include "FrontLeftBlinker_aliases.h"


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
} FrontLeftBlinker_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   FrontLeftBlinker_Read(void);
void    FrontLeftBlinker_Write(uint8 value);
uint8   FrontLeftBlinker_ReadDataReg(void);
#if defined(FrontLeftBlinker__PC) || (CY_PSOC4_4200L) 
    void    FrontLeftBlinker_SetDriveMode(uint8 mode);
#endif
void    FrontLeftBlinker_SetInterruptMode(uint16 position, uint16 mode);
uint8   FrontLeftBlinker_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void FrontLeftBlinker_Sleep(void); 
void FrontLeftBlinker_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(FrontLeftBlinker__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define FrontLeftBlinker_DRIVE_MODE_BITS        (3)
    #define FrontLeftBlinker_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - FrontLeftBlinker_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the FrontLeftBlinker_SetDriveMode() function.
         *  @{
         */
        #define FrontLeftBlinker_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define FrontLeftBlinker_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define FrontLeftBlinker_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define FrontLeftBlinker_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define FrontLeftBlinker_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define FrontLeftBlinker_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define FrontLeftBlinker_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define FrontLeftBlinker_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define FrontLeftBlinker_MASK               FrontLeftBlinker__MASK
#define FrontLeftBlinker_SHIFT              FrontLeftBlinker__SHIFT
#define FrontLeftBlinker_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in FrontLeftBlinker_SetInterruptMode() function.
     *  @{
     */
        #define FrontLeftBlinker_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define FrontLeftBlinker_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define FrontLeftBlinker_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define FrontLeftBlinker_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(FrontLeftBlinker__SIO)
    #define FrontLeftBlinker_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(FrontLeftBlinker__PC) && (CY_PSOC4_4200L)
    #define FrontLeftBlinker_USBIO_ENABLE               ((uint32)0x80000000u)
    #define FrontLeftBlinker_USBIO_DISABLE              ((uint32)(~FrontLeftBlinker_USBIO_ENABLE))
    #define FrontLeftBlinker_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define FrontLeftBlinker_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define FrontLeftBlinker_USBIO_ENTER_SLEEP          ((uint32)((1u << FrontLeftBlinker_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << FrontLeftBlinker_USBIO_SUSPEND_DEL_SHIFT)))
    #define FrontLeftBlinker_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << FrontLeftBlinker_USBIO_SUSPEND_SHIFT)))
    #define FrontLeftBlinker_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << FrontLeftBlinker_USBIO_SUSPEND_DEL_SHIFT)))
    #define FrontLeftBlinker_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(FrontLeftBlinker__PC)
    /* Port Configuration */
    #define FrontLeftBlinker_PC                 (* (reg32 *) FrontLeftBlinker__PC)
#endif
/* Pin State */
#define FrontLeftBlinker_PS                     (* (reg32 *) FrontLeftBlinker__PS)
/* Data Register */
#define FrontLeftBlinker_DR                     (* (reg32 *) FrontLeftBlinker__DR)
/* Input Buffer Disable Override */
#define FrontLeftBlinker_INP_DIS                (* (reg32 *) FrontLeftBlinker__PC2)

/* Interrupt configuration Registers */
#define FrontLeftBlinker_INTCFG                 (* (reg32 *) FrontLeftBlinker__INTCFG)
#define FrontLeftBlinker_INTSTAT                (* (reg32 *) FrontLeftBlinker__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define FrontLeftBlinker_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(FrontLeftBlinker__SIO)
    #define FrontLeftBlinker_SIO_REG            (* (reg32 *) FrontLeftBlinker__SIO)
#endif /* (FrontLeftBlinker__SIO_CFG) */

/* USBIO registers */
#if !defined(FrontLeftBlinker__PC) && (CY_PSOC4_4200L)
    #define FrontLeftBlinker_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define FrontLeftBlinker_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define FrontLeftBlinker_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define FrontLeftBlinker_DRIVE_MODE_SHIFT       (0x00u)
#define FrontLeftBlinker_DRIVE_MODE_MASK        (0x07u << FrontLeftBlinker_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins FrontLeftBlinker_H */


/* [] END OF FILE */
