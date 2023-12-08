/*******************************************************************************
* File Name: RearLeftBrake.h  
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

#if !defined(CY_PINS_RearLeftBrake_H) /* Pins RearLeftBrake_H */
#define CY_PINS_RearLeftBrake_H

#include "cytypes.h"
#include "cyfitter.h"
#include "RearLeftBrake_aliases.h"


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
} RearLeftBrake_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   RearLeftBrake_Read(void);
void    RearLeftBrake_Write(uint8 value);
uint8   RearLeftBrake_ReadDataReg(void);
#if defined(RearLeftBrake__PC) || (CY_PSOC4_4200L) 
    void    RearLeftBrake_SetDriveMode(uint8 mode);
#endif
void    RearLeftBrake_SetInterruptMode(uint16 position, uint16 mode);
uint8   RearLeftBrake_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void RearLeftBrake_Sleep(void); 
void RearLeftBrake_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(RearLeftBrake__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define RearLeftBrake_DRIVE_MODE_BITS        (3)
    #define RearLeftBrake_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - RearLeftBrake_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the RearLeftBrake_SetDriveMode() function.
         *  @{
         */
        #define RearLeftBrake_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define RearLeftBrake_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define RearLeftBrake_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define RearLeftBrake_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define RearLeftBrake_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define RearLeftBrake_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define RearLeftBrake_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define RearLeftBrake_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define RearLeftBrake_MASK               RearLeftBrake__MASK
#define RearLeftBrake_SHIFT              RearLeftBrake__SHIFT
#define RearLeftBrake_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RearLeftBrake_SetInterruptMode() function.
     *  @{
     */
        #define RearLeftBrake_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define RearLeftBrake_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define RearLeftBrake_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define RearLeftBrake_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(RearLeftBrake__SIO)
    #define RearLeftBrake_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(RearLeftBrake__PC) && (CY_PSOC4_4200L)
    #define RearLeftBrake_USBIO_ENABLE               ((uint32)0x80000000u)
    #define RearLeftBrake_USBIO_DISABLE              ((uint32)(~RearLeftBrake_USBIO_ENABLE))
    #define RearLeftBrake_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define RearLeftBrake_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define RearLeftBrake_USBIO_ENTER_SLEEP          ((uint32)((1u << RearLeftBrake_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << RearLeftBrake_USBIO_SUSPEND_DEL_SHIFT)))
    #define RearLeftBrake_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << RearLeftBrake_USBIO_SUSPEND_SHIFT)))
    #define RearLeftBrake_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << RearLeftBrake_USBIO_SUSPEND_DEL_SHIFT)))
    #define RearLeftBrake_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(RearLeftBrake__PC)
    /* Port Configuration */
    #define RearLeftBrake_PC                 (* (reg32 *) RearLeftBrake__PC)
#endif
/* Pin State */
#define RearLeftBrake_PS                     (* (reg32 *) RearLeftBrake__PS)
/* Data Register */
#define RearLeftBrake_DR                     (* (reg32 *) RearLeftBrake__DR)
/* Input Buffer Disable Override */
#define RearLeftBrake_INP_DIS                (* (reg32 *) RearLeftBrake__PC2)

/* Interrupt configuration Registers */
#define RearLeftBrake_INTCFG                 (* (reg32 *) RearLeftBrake__INTCFG)
#define RearLeftBrake_INTSTAT                (* (reg32 *) RearLeftBrake__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define RearLeftBrake_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(RearLeftBrake__SIO)
    #define RearLeftBrake_SIO_REG            (* (reg32 *) RearLeftBrake__SIO)
#endif /* (RearLeftBrake__SIO_CFG) */

/* USBIO registers */
#if !defined(RearLeftBrake__PC) && (CY_PSOC4_4200L)
    #define RearLeftBrake_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define RearLeftBrake_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define RearLeftBrake_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define RearLeftBrake_DRIVE_MODE_SHIFT       (0x00u)
#define RearLeftBrake_DRIVE_MODE_MASK        (0x07u << RearLeftBrake_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins RearLeftBrake_H */


/* [] END OF FILE */
