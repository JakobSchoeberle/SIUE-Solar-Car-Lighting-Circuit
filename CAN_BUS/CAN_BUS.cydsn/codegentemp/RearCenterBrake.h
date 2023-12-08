/*******************************************************************************
* File Name: RearCenterBrake.h  
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

#if !defined(CY_PINS_RearCenterBrake_H) /* Pins RearCenterBrake_H */
#define CY_PINS_RearCenterBrake_H

#include "cytypes.h"
#include "cyfitter.h"
#include "RearCenterBrake_aliases.h"


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
} RearCenterBrake_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   RearCenterBrake_Read(void);
void    RearCenterBrake_Write(uint8 value);
uint8   RearCenterBrake_ReadDataReg(void);
#if defined(RearCenterBrake__PC) || (CY_PSOC4_4200L) 
    void    RearCenterBrake_SetDriveMode(uint8 mode);
#endif
void    RearCenterBrake_SetInterruptMode(uint16 position, uint16 mode);
uint8   RearCenterBrake_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void RearCenterBrake_Sleep(void); 
void RearCenterBrake_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(RearCenterBrake__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define RearCenterBrake_DRIVE_MODE_BITS        (3)
    #define RearCenterBrake_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - RearCenterBrake_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the RearCenterBrake_SetDriveMode() function.
         *  @{
         */
        #define RearCenterBrake_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define RearCenterBrake_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define RearCenterBrake_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define RearCenterBrake_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define RearCenterBrake_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define RearCenterBrake_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define RearCenterBrake_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define RearCenterBrake_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define RearCenterBrake_MASK               RearCenterBrake__MASK
#define RearCenterBrake_SHIFT              RearCenterBrake__SHIFT
#define RearCenterBrake_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RearCenterBrake_SetInterruptMode() function.
     *  @{
     */
        #define RearCenterBrake_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define RearCenterBrake_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define RearCenterBrake_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define RearCenterBrake_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(RearCenterBrake__SIO)
    #define RearCenterBrake_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(RearCenterBrake__PC) && (CY_PSOC4_4200L)
    #define RearCenterBrake_USBIO_ENABLE               ((uint32)0x80000000u)
    #define RearCenterBrake_USBIO_DISABLE              ((uint32)(~RearCenterBrake_USBIO_ENABLE))
    #define RearCenterBrake_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define RearCenterBrake_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define RearCenterBrake_USBIO_ENTER_SLEEP          ((uint32)((1u << RearCenterBrake_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << RearCenterBrake_USBIO_SUSPEND_DEL_SHIFT)))
    #define RearCenterBrake_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << RearCenterBrake_USBIO_SUSPEND_SHIFT)))
    #define RearCenterBrake_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << RearCenterBrake_USBIO_SUSPEND_DEL_SHIFT)))
    #define RearCenterBrake_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(RearCenterBrake__PC)
    /* Port Configuration */
    #define RearCenterBrake_PC                 (* (reg32 *) RearCenterBrake__PC)
#endif
/* Pin State */
#define RearCenterBrake_PS                     (* (reg32 *) RearCenterBrake__PS)
/* Data Register */
#define RearCenterBrake_DR                     (* (reg32 *) RearCenterBrake__DR)
/* Input Buffer Disable Override */
#define RearCenterBrake_INP_DIS                (* (reg32 *) RearCenterBrake__PC2)

/* Interrupt configuration Registers */
#define RearCenterBrake_INTCFG                 (* (reg32 *) RearCenterBrake__INTCFG)
#define RearCenterBrake_INTSTAT                (* (reg32 *) RearCenterBrake__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define RearCenterBrake_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(RearCenterBrake__SIO)
    #define RearCenterBrake_SIO_REG            (* (reg32 *) RearCenterBrake__SIO)
#endif /* (RearCenterBrake__SIO_CFG) */

/* USBIO registers */
#if !defined(RearCenterBrake__PC) && (CY_PSOC4_4200L)
    #define RearCenterBrake_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define RearCenterBrake_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define RearCenterBrake_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define RearCenterBrake_DRIVE_MODE_SHIFT       (0x00u)
#define RearCenterBrake_DRIVE_MODE_MASK        (0x07u << RearCenterBrake_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins RearCenterBrake_H */


/* [] END OF FILE */
