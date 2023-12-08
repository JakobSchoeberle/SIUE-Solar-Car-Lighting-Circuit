/*******************************************************************************
* File Name: RearRightBrake.h  
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

#if !defined(CY_PINS_RearRightBrake_H) /* Pins RearRightBrake_H */
#define CY_PINS_RearRightBrake_H

#include "cytypes.h"
#include "cyfitter.h"
#include "RearRightBrake_aliases.h"


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
} RearRightBrake_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   RearRightBrake_Read(void);
void    RearRightBrake_Write(uint8 value);
uint8   RearRightBrake_ReadDataReg(void);
#if defined(RearRightBrake__PC) || (CY_PSOC4_4200L) 
    void    RearRightBrake_SetDriveMode(uint8 mode);
#endif
void    RearRightBrake_SetInterruptMode(uint16 position, uint16 mode);
uint8   RearRightBrake_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void RearRightBrake_Sleep(void); 
void RearRightBrake_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(RearRightBrake__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define RearRightBrake_DRIVE_MODE_BITS        (3)
    #define RearRightBrake_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - RearRightBrake_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the RearRightBrake_SetDriveMode() function.
         *  @{
         */
        #define RearRightBrake_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define RearRightBrake_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define RearRightBrake_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define RearRightBrake_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define RearRightBrake_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define RearRightBrake_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define RearRightBrake_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define RearRightBrake_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define RearRightBrake_MASK               RearRightBrake__MASK
#define RearRightBrake_SHIFT              RearRightBrake__SHIFT
#define RearRightBrake_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RearRightBrake_SetInterruptMode() function.
     *  @{
     */
        #define RearRightBrake_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define RearRightBrake_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define RearRightBrake_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define RearRightBrake_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(RearRightBrake__SIO)
    #define RearRightBrake_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(RearRightBrake__PC) && (CY_PSOC4_4200L)
    #define RearRightBrake_USBIO_ENABLE               ((uint32)0x80000000u)
    #define RearRightBrake_USBIO_DISABLE              ((uint32)(~RearRightBrake_USBIO_ENABLE))
    #define RearRightBrake_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define RearRightBrake_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define RearRightBrake_USBIO_ENTER_SLEEP          ((uint32)((1u << RearRightBrake_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << RearRightBrake_USBIO_SUSPEND_DEL_SHIFT)))
    #define RearRightBrake_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << RearRightBrake_USBIO_SUSPEND_SHIFT)))
    #define RearRightBrake_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << RearRightBrake_USBIO_SUSPEND_DEL_SHIFT)))
    #define RearRightBrake_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(RearRightBrake__PC)
    /* Port Configuration */
    #define RearRightBrake_PC                 (* (reg32 *) RearRightBrake__PC)
#endif
/* Pin State */
#define RearRightBrake_PS                     (* (reg32 *) RearRightBrake__PS)
/* Data Register */
#define RearRightBrake_DR                     (* (reg32 *) RearRightBrake__DR)
/* Input Buffer Disable Override */
#define RearRightBrake_INP_DIS                (* (reg32 *) RearRightBrake__PC2)

/* Interrupt configuration Registers */
#define RearRightBrake_INTCFG                 (* (reg32 *) RearRightBrake__INTCFG)
#define RearRightBrake_INTSTAT                (* (reg32 *) RearRightBrake__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define RearRightBrake_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(RearRightBrake__SIO)
    #define RearRightBrake_SIO_REG            (* (reg32 *) RearRightBrake__SIO)
#endif /* (RearRightBrake__SIO_CFG) */

/* USBIO registers */
#if !defined(RearRightBrake__PC) && (CY_PSOC4_4200L)
    #define RearRightBrake_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define RearRightBrake_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define RearRightBrake_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define RearRightBrake_DRIVE_MODE_SHIFT       (0x00u)
#define RearRightBrake_DRIVE_MODE_MASK        (0x07u << RearRightBrake_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins RearRightBrake_H */


/* [] END OF FILE */
