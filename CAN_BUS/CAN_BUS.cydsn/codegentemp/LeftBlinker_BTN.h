/*******************************************************************************
* File Name: LeftBlinker_BTN.h  
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

#if !defined(CY_PINS_LeftBlinker_BTN_H) /* Pins LeftBlinker_BTN_H */
#define CY_PINS_LeftBlinker_BTN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LeftBlinker_BTN_aliases.h"


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
} LeftBlinker_BTN_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   LeftBlinker_BTN_Read(void);
void    LeftBlinker_BTN_Write(uint8 value);
uint8   LeftBlinker_BTN_ReadDataReg(void);
#if defined(LeftBlinker_BTN__PC) || (CY_PSOC4_4200L) 
    void    LeftBlinker_BTN_SetDriveMode(uint8 mode);
#endif
void    LeftBlinker_BTN_SetInterruptMode(uint16 position, uint16 mode);
uint8   LeftBlinker_BTN_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void LeftBlinker_BTN_Sleep(void); 
void LeftBlinker_BTN_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(LeftBlinker_BTN__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define LeftBlinker_BTN_DRIVE_MODE_BITS        (3)
    #define LeftBlinker_BTN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LeftBlinker_BTN_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the LeftBlinker_BTN_SetDriveMode() function.
         *  @{
         */
        #define LeftBlinker_BTN_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define LeftBlinker_BTN_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define LeftBlinker_BTN_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define LeftBlinker_BTN_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define LeftBlinker_BTN_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define LeftBlinker_BTN_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define LeftBlinker_BTN_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define LeftBlinker_BTN_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define LeftBlinker_BTN_MASK               LeftBlinker_BTN__MASK
#define LeftBlinker_BTN_SHIFT              LeftBlinker_BTN__SHIFT
#define LeftBlinker_BTN_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LeftBlinker_BTN_SetInterruptMode() function.
     *  @{
     */
        #define LeftBlinker_BTN_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define LeftBlinker_BTN_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define LeftBlinker_BTN_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define LeftBlinker_BTN_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(LeftBlinker_BTN__SIO)
    #define LeftBlinker_BTN_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(LeftBlinker_BTN__PC) && (CY_PSOC4_4200L)
    #define LeftBlinker_BTN_USBIO_ENABLE               ((uint32)0x80000000u)
    #define LeftBlinker_BTN_USBIO_DISABLE              ((uint32)(~LeftBlinker_BTN_USBIO_ENABLE))
    #define LeftBlinker_BTN_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define LeftBlinker_BTN_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define LeftBlinker_BTN_USBIO_ENTER_SLEEP          ((uint32)((1u << LeftBlinker_BTN_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << LeftBlinker_BTN_USBIO_SUSPEND_DEL_SHIFT)))
    #define LeftBlinker_BTN_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << LeftBlinker_BTN_USBIO_SUSPEND_SHIFT)))
    #define LeftBlinker_BTN_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << LeftBlinker_BTN_USBIO_SUSPEND_DEL_SHIFT)))
    #define LeftBlinker_BTN_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(LeftBlinker_BTN__PC)
    /* Port Configuration */
    #define LeftBlinker_BTN_PC                 (* (reg32 *) LeftBlinker_BTN__PC)
#endif
/* Pin State */
#define LeftBlinker_BTN_PS                     (* (reg32 *) LeftBlinker_BTN__PS)
/* Data Register */
#define LeftBlinker_BTN_DR                     (* (reg32 *) LeftBlinker_BTN__DR)
/* Input Buffer Disable Override */
#define LeftBlinker_BTN_INP_DIS                (* (reg32 *) LeftBlinker_BTN__PC2)

/* Interrupt configuration Registers */
#define LeftBlinker_BTN_INTCFG                 (* (reg32 *) LeftBlinker_BTN__INTCFG)
#define LeftBlinker_BTN_INTSTAT                (* (reg32 *) LeftBlinker_BTN__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define LeftBlinker_BTN_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(LeftBlinker_BTN__SIO)
    #define LeftBlinker_BTN_SIO_REG            (* (reg32 *) LeftBlinker_BTN__SIO)
#endif /* (LeftBlinker_BTN__SIO_CFG) */

/* USBIO registers */
#if !defined(LeftBlinker_BTN__PC) && (CY_PSOC4_4200L)
    #define LeftBlinker_BTN_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define LeftBlinker_BTN_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define LeftBlinker_BTN_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define LeftBlinker_BTN_DRIVE_MODE_SHIFT       (0x00u)
#define LeftBlinker_BTN_DRIVE_MODE_MASK        (0x07u << LeftBlinker_BTN_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins LeftBlinker_BTN_H */


/* [] END OF FILE */
