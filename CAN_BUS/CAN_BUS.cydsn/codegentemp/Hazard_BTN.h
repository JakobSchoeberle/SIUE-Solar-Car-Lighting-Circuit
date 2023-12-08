/*******************************************************************************
* File Name: Hazard_BTN.h  
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

#if !defined(CY_PINS_Hazard_BTN_H) /* Pins Hazard_BTN_H */
#define CY_PINS_Hazard_BTN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Hazard_BTN_aliases.h"


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
} Hazard_BTN_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Hazard_BTN_Read(void);
void    Hazard_BTN_Write(uint8 value);
uint8   Hazard_BTN_ReadDataReg(void);
#if defined(Hazard_BTN__PC) || (CY_PSOC4_4200L) 
    void    Hazard_BTN_SetDriveMode(uint8 mode);
#endif
void    Hazard_BTN_SetInterruptMode(uint16 position, uint16 mode);
uint8   Hazard_BTN_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Hazard_BTN_Sleep(void); 
void Hazard_BTN_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Hazard_BTN__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Hazard_BTN_DRIVE_MODE_BITS        (3)
    #define Hazard_BTN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Hazard_BTN_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Hazard_BTN_SetDriveMode() function.
         *  @{
         */
        #define Hazard_BTN_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Hazard_BTN_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Hazard_BTN_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Hazard_BTN_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Hazard_BTN_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Hazard_BTN_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Hazard_BTN_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Hazard_BTN_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Hazard_BTN_MASK               Hazard_BTN__MASK
#define Hazard_BTN_SHIFT              Hazard_BTN__SHIFT
#define Hazard_BTN_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Hazard_BTN_SetInterruptMode() function.
     *  @{
     */
        #define Hazard_BTN_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Hazard_BTN_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Hazard_BTN_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Hazard_BTN_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Hazard_BTN__SIO)
    #define Hazard_BTN_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Hazard_BTN__PC) && (CY_PSOC4_4200L)
    #define Hazard_BTN_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Hazard_BTN_USBIO_DISABLE              ((uint32)(~Hazard_BTN_USBIO_ENABLE))
    #define Hazard_BTN_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Hazard_BTN_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Hazard_BTN_USBIO_ENTER_SLEEP          ((uint32)((1u << Hazard_BTN_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Hazard_BTN_USBIO_SUSPEND_DEL_SHIFT)))
    #define Hazard_BTN_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Hazard_BTN_USBIO_SUSPEND_SHIFT)))
    #define Hazard_BTN_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Hazard_BTN_USBIO_SUSPEND_DEL_SHIFT)))
    #define Hazard_BTN_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Hazard_BTN__PC)
    /* Port Configuration */
    #define Hazard_BTN_PC                 (* (reg32 *) Hazard_BTN__PC)
#endif
/* Pin State */
#define Hazard_BTN_PS                     (* (reg32 *) Hazard_BTN__PS)
/* Data Register */
#define Hazard_BTN_DR                     (* (reg32 *) Hazard_BTN__DR)
/* Input Buffer Disable Override */
#define Hazard_BTN_INP_DIS                (* (reg32 *) Hazard_BTN__PC2)

/* Interrupt configuration Registers */
#define Hazard_BTN_INTCFG                 (* (reg32 *) Hazard_BTN__INTCFG)
#define Hazard_BTN_INTSTAT                (* (reg32 *) Hazard_BTN__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Hazard_BTN_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Hazard_BTN__SIO)
    #define Hazard_BTN_SIO_REG            (* (reg32 *) Hazard_BTN__SIO)
#endif /* (Hazard_BTN__SIO_CFG) */

/* USBIO registers */
#if !defined(Hazard_BTN__PC) && (CY_PSOC4_4200L)
    #define Hazard_BTN_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Hazard_BTN_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Hazard_BTN_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Hazard_BTN_DRIVE_MODE_SHIFT       (0x00u)
#define Hazard_BTN_DRIVE_MODE_MASK        (0x07u << Hazard_BTN_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Hazard_BTN_H */


/* [] END OF FILE */
