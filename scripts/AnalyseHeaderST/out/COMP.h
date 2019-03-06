#ifndef __SOOL_COMP_H
#define __SOOL_COMP_H

#include "peripheral_include.h"
//SOOL-COMP-INCLUDES
#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F3     ) ||\
    defined(STM32H7     ) || defined(STM32L0     ) || defined(STM32L1     ) || defined(STM32L4     ) ||\
    defined(STM32L4P    ) 
//region defines

#if defined(STM32H7     ) 
#define COMP_CFGR
#define COMP_MAP1_CFGR       CFGR_TypeDef CFGR
#else
#define COMP_MAP1_CFGR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F3     ) ||\
    defined(STM32L0     ) || defined(STM32L1     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define COMP_CSR
#define COMP_MAP0_CSR        typename plugin::CSR_TypeDef CSR
#else
#define COMP_MAP0_CSR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F302xC ) ||\
    defined(STM32F303xC ) || defined(STM32F358xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) ||\
    defined(STM32L0     ) || defined(STM32L1     ) 
#define COMP_CSR_0
#endif

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F373xC ) ||\
    defined(STM32F378xx ) || defined(STM32L0     ) 
#define COMP_CSR_0_COMP1EN   COMP1EN              // 1 bits @ 0
#define COMP_CSR_0_COMP2LOCK COMP2LOCK            // 1 bits @ 31
#define COMP2_CSR_1_COMP1EN  COMP1EN              // 1 bits @ 0
#define COMP4_CSR_1_COMP1EN  COMP1EN              // 1 bits @ 0
#define COMP4_CSR_1_COMP2LOCK COMP2LOCK            // 1 bits @ 31
#define COMP6_CSR_1_COMP1EN  COMP1EN              // 1 bits @ 0
#define COMP6_CSR_1_COMP2LOCK COMP2LOCK            // 1 bits @ 31
#define COMP1_CSR_1_COMP2LOCK COMP2LOCK            // 1 bits @ 31
#define COMP3_CSR_1_COMP1EN  COMP1EN              // 1 bits @ 0
#define COMP3_CSR_1_COMP2LOCK COMP2LOCK            // 1 bits @ 31
#define COMP5_CSR_1_COMP1EN  COMP1EN              // 1 bits @ 0
#define COMP5_CSR_1_COMP2LOCK COMP2LOCK            // 1 bits @ 31
#define COMP7_CSR_1_COMP1EN  COMP1EN              // 1 bits @ 0
#define COMP7_CSR_1_COMP2LOCK COMP2LOCK            // 1 bits @ 31
#else
#define COMP_CSR_0_COMP1EN
#define COMP_CSR_0_COMP2LOCK
#define COMP2_CSR_1_COMP1EN
#define COMP4_CSR_1_COMP1EN
#define COMP4_CSR_1_COMP2LOCK
#define COMP6_CSR_1_COMP1EN
#define COMP6_CSR_1_COMP2LOCK
#define COMP1_CSR_1_COMP2LOCK
#define COMP3_CSR_1_COMP1EN
#define COMP3_CSR_1_COMP2LOCK
#define COMP5_CSR_1_COMP1EN
#define COMP5_CSR_1_COMP2LOCK
#define COMP7_CSR_1_COMP1EN
#define COMP7_CSR_1_COMP2LOCK
#endif

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F373xC ) ||\
    defined(STM32F378xx ) 
#define COMP_CSR_0_COMP1SW1  COMP1SW1             // 1 bits @ 1
#define COMP_CSR_0_COMP1MODE COMP1MODE            // 2 bits @ 2
#define COMP_CSR_0_COMP1INSEL COMP1INSEL           // 3 bits @ 4
#define COMP_CSR_0_COMP1OUTSEL COMP1OUTSEL          // 3 bits @ 8
#define COMP_CSR_0_COMP1POL  COMP1POL             // 1 bits @ 11
#define COMP_CSR_0_COMP1HYST COMP1HYST            // 2 bits @ 12
#define COMP_CSR_0_COMP1OUT  COMP1OUT             // 1 bits @ 14
#define COMP_CSR_0_COMP1LOCK COMP1LOCK            // 1 bits @ 15
#define COMP_CSR_0_COMP2EN   COMP2EN              // 1 bits @ 16
#define COMP_CSR_0_COMP2MODE COMP2MODE            // 2 bits @ 18
#define COMP_CSR_0_COMP2INSEL COMP2INSEL           // 3 bits @ 20
#define COMP_CSR_0_WNDWEN    WNDWEN               // 1 bits @ 23
#define COMP_CSR_0_COMP2OUTSEL COMP2OUTSEL          // 3 bits @ 24
#define COMP_CSR_0_COMP2POL  COMP2POL             // 1 bits @ 27
#define COMP_CSR_0_COMP2HYST COMP2HYST            // 2 bits @ 28
#define COMP_CSR_0_COMP2OUT  COMP2OUT             // 1 bits @ 30
#define COMP_CSR_1_COMPxOUTSEL COMPxOUTSEL          // 3 bits @ 8
#define COMP_CSR_1_COMPxPOL  COMPxPOL             // 1 bits @ 11
#define COMP_CSR_1_COMPxHYST COMPxHYST            // 2 bits @ 12
#define COMP_CSR_1_COMPxOUT  COMPxOUT             // 1 bits @ 14
#define COMP_CSR_1_COMPxLOCK COMPxLOCK            // 1 bits @ 15
#define COMP2_CSR_0_COMP1OUT COMP1OUT             // 1 bits @ 14
#define COMP2_CSR_0_WNDWEN   WNDWEN               // 1 bits @ 23
#define COMP2_CSR_1_COMP1MODE COMP1MODE            // 2 bits @ 2
#define COMP2_CSR_1_COMP1INSEL COMP1INSEL           // 3 bits @ 4
#define COMP2_CSR_1_COMP1OUTSEL COMP1OUTSEL          // 3 bits @ 8
#define COMP2_CSR_1_COMP1POL COMP1POL             // 1 bits @ 11
#define COMP2_CSR_1_COMP1HYST COMP1HYST            // 2 bits @ 12
#define COMP2_CSR_1_COMPxOUT COMPxOUT             // 1 bits @ 14
#define COMP2_CSR_1_COMP1LOCK COMP1LOCK            // 1 bits @ 15
#define COMP2_CSR_1_COMP2EN  COMP2EN              // 1 bits @ 16
#define COMP2_CSR_1_COMP2MODE COMP2MODE            // 2 bits @ 18
#define COMP2_CSR_1_COMP2INSEL COMP2INSEL           // 3 bits @ 20
#define COMP2_CSR_1_COMP2OUTSEL COMP2OUTSEL          // 3 bits @ 24
#define COMP2_CSR_1_COMP2POL COMP2POL             // 1 bits @ 27
#define COMP2_CSR_1_COMP2HYST COMP2HYST            // 2 bits @ 28
#define COMP2_CSR_2_COMP1SW1 COMP1SW1             // 1 bits @ 1
#define COMP2_CSR_2_COMPxOUTSEL COMPxOUTSEL          // 3 bits @ 8
#define COMP2_CSR_2_COMPxPOL COMPxPOL             // 1 bits @ 11
#define COMP2_CSR_2_COMPxHYST COMPxHYST            // 2 bits @ 12
#define COMP2_CSR_2_COMPxLOCK COMPxLOCK            // 1 bits @ 15
#define COMP4_CSR_0_COMP1SW1 COMP1SW1             // 1 bits @ 1
#define COMP4_CSR_0_COMP1OUT COMP1OUT             // 1 bits @ 14
#define COMP4_CSR_0_COMP2INSEL COMP2INSEL           // 3 bits @ 20
#define COMP4_CSR_0_WNDWEN   WNDWEN               // 1 bits @ 23
#define COMP4_CSR_0_COMP2OUTSEL COMP2OUTSEL          // 3 bits @ 24
#define COMP4_CSR_0_COMP2POL COMP2POL             // 1 bits @ 27
#define COMP4_CSR_0_COMP2HYST COMP2HYST            // 2 bits @ 28
#define COMP4_CSR_1_COMP1MODE COMP1MODE            // 2 bits @ 2
#define COMP4_CSR_1_COMP1INSEL COMP1INSEL           // 3 bits @ 4
#define COMP4_CSR_1_COMP1OUTSEL COMP1OUTSEL          // 3 bits @ 8
#define COMP4_CSR_1_COMP1POL COMP1POL             // 1 bits @ 11
#define COMP4_CSR_1_COMP1HYST COMP1HYST            // 2 bits @ 12
#define COMP4_CSR_1_COMPxOUT COMPxOUT             // 1 bits @ 14
#define COMP4_CSR_1_COMP1LOCK COMP1LOCK            // 1 bits @ 15
#define COMP4_CSR_1_COMP2EN  COMP2EN              // 1 bits @ 16
#define COMP4_CSR_1_COMP2MODE COMP2MODE            // 2 bits @ 18
#define COMP4_CSR_1_COMP2OUT COMP2OUT             // 1 bits @ 30
#define COMP4_CSR_2_COMPxOUTSEL COMPxOUTSEL          // 3 bits @ 8
#define COMP4_CSR_2_COMPxPOL COMPxPOL             // 1 bits @ 11
#define COMP4_CSR_2_COMPxHYST COMPxHYST            // 2 bits @ 12
#define COMP4_CSR_2_COMPxLOCK COMPxLOCK            // 1 bits @ 15
#define COMP6_CSR_0_COMP1SW1 COMP1SW1             // 1 bits @ 1
#define COMP6_CSR_0_COMP1OUT COMP1OUT             // 1 bits @ 14
#define COMP6_CSR_0_COMP2INSEL COMP2INSEL           // 3 bits @ 20
#define COMP6_CSR_0_WNDWEN   WNDWEN               // 1 bits @ 23
#define COMP6_CSR_0_COMP2OUTSEL COMP2OUTSEL          // 3 bits @ 24
#define COMP6_CSR_0_COMP2POL COMP2POL             // 1 bits @ 27
#define COMP6_CSR_0_COMP2HYST COMP2HYST            // 2 bits @ 28
#define COMP6_CSR_1_COMP1MODE COMP1MODE            // 2 bits @ 2
#define COMP6_CSR_1_COMP1INSEL COMP1INSEL           // 3 bits @ 4
#define COMP6_CSR_1_COMP1OUTSEL COMP1OUTSEL          // 3 bits @ 8
#define COMP6_CSR_1_COMP1POL COMP1POL             // 1 bits @ 11
#define COMP6_CSR_1_COMP1HYST COMP1HYST            // 2 bits @ 12
#define COMP6_CSR_1_COMPxOUT COMPxOUT             // 1 bits @ 14
#define COMP6_CSR_1_COMP1LOCK COMP1LOCK            // 1 bits @ 15
#define COMP6_CSR_1_COMP2EN  COMP2EN              // 1 bits @ 16
#define COMP6_CSR_1_COMP2MODE COMP2MODE            // 2 bits @ 18
#define COMP6_CSR_1_COMP2OUT COMP2OUT             // 1 bits @ 30
#define COMP6_CSR_2_COMPxOUTSEL COMPxOUTSEL          // 3 bits @ 8
#define COMP6_CSR_2_COMPxPOL COMPxPOL             // 1 bits @ 11
#define COMP6_CSR_2_COMPxHYST COMPxHYST            // 2 bits @ 12
#define COMP6_CSR_2_COMPxLOCK COMPxLOCK            // 1 bits @ 15
#define COMP1_CSR_0_COMPxOUT COMPxOUT             // 1 bits @ 14
#define COMP1_CSR_0_COMP2INSEL COMP2INSEL           // 3 bits @ 20
#define COMP1_CSR_0_WNDWEN   WNDWEN               // 1 bits @ 23
#define COMP1_CSR_0_COMP2OUTSEL COMP2OUTSEL          // 3 bits @ 24
#define COMP1_CSR_0_COMP2POL COMP2POL             // 1 bits @ 27
#define COMP1_CSR_0_COMP2HYST COMP2HYST            // 2 bits @ 28
#define COMP1_CSR_1_COMP1OUTSEL COMP1OUTSEL          // 3 bits @ 8
#define COMP1_CSR_1_COMP1POL COMP1POL             // 1 bits @ 11
#define COMP1_CSR_1_COMP1HYST COMP1HYST            // 2 bits @ 12
#define COMP1_CSR_1_COMP1OUT COMP1OUT             // 1 bits @ 14
#define COMP1_CSR_1_COMP1LOCK COMP1LOCK            // 1 bits @ 15
#define COMP1_CSR_1_COMP2EN  COMP2EN              // 1 bits @ 16
#define COMP1_CSR_1_COMP2MODE COMP2MODE            // 2 bits @ 18
#define COMP1_CSR_1_COMP2OUT COMP2OUT             // 1 bits @ 30
#define COMP1_CSR_2_COMPxOUTSEL COMPxOUTSEL          // 3 bits @ 8
#define COMP1_CSR_2_COMPxPOL COMPxPOL             // 1 bits @ 11
#define COMP1_CSR_2_COMPxHYST COMPxHYST            // 2 bits @ 12
#define COMP1_CSR_2_COMPxLOCK COMPxLOCK            // 1 bits @ 15
#define COMP3_CSR_0_COMP1SW1 COMP1SW1             // 1 bits @ 1
#define COMP3_CSR_0_COMP1OUT COMP1OUT             // 1 bits @ 14
#define COMP3_CSR_0_COMP2INSEL COMP2INSEL           // 3 bits @ 20
#define COMP3_CSR_0_WNDWEN   WNDWEN               // 1 bits @ 23
#define COMP3_CSR_0_COMP2OUTSEL COMP2OUTSEL          // 3 bits @ 24
#define COMP3_CSR_0_COMP2POL COMP2POL             // 1 bits @ 27
#define COMP3_CSR_0_COMP2HYST COMP2HYST            // 2 bits @ 28
#define COMP3_CSR_1_COMP1MODE COMP1MODE            // 2 bits @ 2
#define COMP3_CSR_1_COMP1INSEL COMP1INSEL           // 3 bits @ 4
#define COMP3_CSR_1_COMP1OUTSEL COMP1OUTSEL          // 3 bits @ 8
#define COMP3_CSR_1_COMP1POL COMP1POL             // 1 bits @ 11
#define COMP3_CSR_1_COMP1HYST COMP1HYST            // 2 bits @ 12
#define COMP3_CSR_1_COMPxOUT COMPxOUT             // 1 bits @ 14
#define COMP3_CSR_1_COMP1LOCK COMP1LOCK            // 1 bits @ 15
#define COMP3_CSR_1_COMP2EN  COMP2EN              // 1 bits @ 16
#define COMP3_CSR_1_COMP2MODE COMP2MODE            // 2 bits @ 18
#define COMP3_CSR_1_COMP2OUT COMP2OUT             // 1 bits @ 30
#define COMP3_CSR_2_COMPxOUTSEL COMPxOUTSEL          // 3 bits @ 8
#define COMP3_CSR_2_COMPxPOL COMPxPOL             // 1 bits @ 11
#define COMP3_CSR_2_COMPxHYST COMPxHYST            // 2 bits @ 12
#define COMP3_CSR_2_COMPxLOCK COMPxLOCK            // 1 bits @ 15
#define COMP5_CSR_0_COMP1SW1 COMP1SW1             // 1 bits @ 1
#define COMP5_CSR_0_COMP1OUT COMP1OUT             // 1 bits @ 14
#define COMP5_CSR_0_COMP2INSEL COMP2INSEL           // 3 bits @ 20
#define COMP5_CSR_0_WNDWEN   WNDWEN               // 1 bits @ 23
#define COMP5_CSR_0_COMP2OUTSEL COMP2OUTSEL          // 3 bits @ 24
#define COMP5_CSR_0_COMP2POL COMP2POL             // 1 bits @ 27
#define COMP5_CSR_0_COMP2HYST COMP2HYST            // 2 bits @ 28
#define COMP5_CSR_1_COMP1MODE COMP1MODE            // 2 bits @ 2
#define COMP5_CSR_1_COMP1INSEL COMP1INSEL           // 3 bits @ 4
#define COMP5_CSR_1_COMP1OUTSEL COMP1OUTSEL          // 3 bits @ 8
#define COMP5_CSR_1_COMP1POL COMP1POL             // 1 bits @ 11
#define COMP5_CSR_1_COMP1HYST COMP1HYST            // 2 bits @ 12
#define COMP5_CSR_1_COMPxOUT COMPxOUT             // 1 bits @ 14
#define COMP5_CSR_1_COMP1LOCK COMP1LOCK            // 1 bits @ 15
#define COMP5_CSR_1_COMP2EN  COMP2EN              // 1 bits @ 16
#define COMP5_CSR_1_COMP2MODE COMP2MODE            // 2 bits @ 18
#define COMP5_CSR_1_COMP2OUT COMP2OUT             // 1 bits @ 30
#define COMP5_CSR_2_COMPxOUTSEL COMPxOUTSEL          // 3 bits @ 8
#define COMP5_CSR_2_COMPxPOL COMPxPOL             // 1 bits @ 11
#define COMP5_CSR_2_COMPxHYST COMPxHYST            // 2 bits @ 12
#define COMP5_CSR_2_COMPxLOCK COMPxLOCK            // 1 bits @ 15
#define COMP7_CSR_0_COMP1SW1 COMP1SW1             // 1 bits @ 1
#define COMP7_CSR_0_COMP1OUT COMP1OUT             // 1 bits @ 14
#define COMP7_CSR_0_COMP2INSEL COMP2INSEL           // 3 bits @ 20
#define COMP7_CSR_0_WNDWEN   WNDWEN               // 1 bits @ 23
#define COMP7_CSR_0_COMP2OUTSEL COMP2OUTSEL          // 3 bits @ 24
#define COMP7_CSR_0_COMP2POL COMP2POL             // 1 bits @ 27
#define COMP7_CSR_0_COMP2HYST COMP2HYST            // 2 bits @ 28
#define COMP7_CSR_1_COMP1MODE COMP1MODE            // 2 bits @ 2
#define COMP7_CSR_1_COMP1INSEL COMP1INSEL           // 3 bits @ 4
#define COMP7_CSR_1_COMP1OUTSEL COMP1OUTSEL          // 3 bits @ 8
#define COMP7_CSR_1_COMP1POL COMP1POL             // 1 bits @ 11
#define COMP7_CSR_1_COMP1HYST COMP1HYST            // 2 bits @ 12
#define COMP7_CSR_1_COMPxOUT COMPxOUT             // 1 bits @ 14
#define COMP7_CSR_1_COMP1LOCK COMP1LOCK            // 1 bits @ 15
#define COMP7_CSR_1_COMP2EN  COMP2EN              // 1 bits @ 16
#define COMP7_CSR_1_COMP2MODE COMP2MODE            // 2 bits @ 18
#define COMP7_CSR_1_COMP2OUT COMP2OUT             // 1 bits @ 30
#define COMP7_CSR_2_COMPxOUTSEL COMPxOUTSEL          // 3 bits @ 8
#define COMP7_CSR_2_COMPxPOL COMPxPOL             // 1 bits @ 11
#define COMP7_CSR_2_COMPxHYST COMPxHYST            // 2 bits @ 12
#define COMP7_CSR_2_COMPxLOCK COMPxLOCK            // 1 bits @ 15
#else
#define COMP_CSR_0_COMP1SW1
#define COMP_CSR_0_COMP1MODE
#define COMP_CSR_0_COMP1INSEL
#define COMP_CSR_0_COMP1OUTSEL
#define COMP_CSR_0_COMP1POL
#define COMP_CSR_0_COMP1HYST
#define COMP_CSR_0_COMP1OUT
#define COMP_CSR_0_COMP1LOCK
#define COMP_CSR_0_COMP2EN
#define COMP_CSR_0_COMP2MODE
#define COMP_CSR_0_COMP2INSEL
#define COMP_CSR_0_WNDWEN
#define COMP_CSR_0_COMP2OUTSEL
#define COMP_CSR_0_COMP2POL
#define COMP_CSR_0_COMP2HYST
#define COMP_CSR_0_COMP2OUT
#define COMP_CSR_1_COMPxOUTSEL
#define COMP_CSR_1_COMPxPOL
#define COMP_CSR_1_COMPxHYST
#define COMP_CSR_1_COMPxOUT
#define COMP_CSR_1_COMPxLOCK
#define COMP2_CSR_0_COMP1OUT
#define COMP2_CSR_0_WNDWEN
#define COMP2_CSR_1_COMP1MODE
#define COMP2_CSR_1_COMP1INSEL
#define COMP2_CSR_1_COMP1OUTSEL
#define COMP2_CSR_1_COMP1POL
#define COMP2_CSR_1_COMP1HYST
#define COMP2_CSR_1_COMPxOUT
#define COMP2_CSR_1_COMP1LOCK
#define COMP2_CSR_1_COMP2EN
#define COMP2_CSR_1_COMP2MODE
#define COMP2_CSR_1_COMP2INSEL
#define COMP2_CSR_1_COMP2OUTSEL
#define COMP2_CSR_1_COMP2POL
#define COMP2_CSR_1_COMP2HYST
#define COMP2_CSR_2_COMP1SW1
#define COMP2_CSR_2_COMPxOUTSEL
#define COMP2_CSR_2_COMPxPOL
#define COMP2_CSR_2_COMPxHYST
#define COMP2_CSR_2_COMPxLOCK
#define COMP4_CSR_0_COMP1SW1
#define COMP4_CSR_0_COMP1OUT
#define COMP4_CSR_0_COMP2INSEL
#define COMP4_CSR_0_WNDWEN
#define COMP4_CSR_0_COMP2OUTSEL
#define COMP4_CSR_0_COMP2POL
#define COMP4_CSR_0_COMP2HYST
#define COMP4_CSR_1_COMP1MODE
#define COMP4_CSR_1_COMP1INSEL
#define COMP4_CSR_1_COMP1OUTSEL
#define COMP4_CSR_1_COMP1POL
#define COMP4_CSR_1_COMP1HYST
#define COMP4_CSR_1_COMPxOUT
#define COMP4_CSR_1_COMP1LOCK
#define COMP4_CSR_1_COMP2EN
#define COMP4_CSR_1_COMP2MODE
#define COMP4_CSR_1_COMP2OUT
#define COMP4_CSR_2_COMPxOUTSEL
#define COMP4_CSR_2_COMPxPOL
#define COMP4_CSR_2_COMPxHYST
#define COMP4_CSR_2_COMPxLOCK
#define COMP6_CSR_0_COMP1SW1
#define COMP6_CSR_0_COMP1OUT
#define COMP6_CSR_0_COMP2INSEL
#define COMP6_CSR_0_WNDWEN
#define COMP6_CSR_0_COMP2OUTSEL
#define COMP6_CSR_0_COMP2POL
#define COMP6_CSR_0_COMP2HYST
#define COMP6_CSR_1_COMP1MODE
#define COMP6_CSR_1_COMP1INSEL
#define COMP6_CSR_1_COMP1OUTSEL
#define COMP6_CSR_1_COMP1POL
#define COMP6_CSR_1_COMP1HYST
#define COMP6_CSR_1_COMPxOUT
#define COMP6_CSR_1_COMP1LOCK
#define COMP6_CSR_1_COMP2EN
#define COMP6_CSR_1_COMP2MODE
#define COMP6_CSR_1_COMP2OUT
#define COMP6_CSR_2_COMPxOUTSEL
#define COMP6_CSR_2_COMPxPOL
#define COMP6_CSR_2_COMPxHYST
#define COMP6_CSR_2_COMPxLOCK
#define COMP1_CSR_0_COMPxOUT
#define COMP1_CSR_0_COMP2INSEL
#define COMP1_CSR_0_WNDWEN
#define COMP1_CSR_0_COMP2OUTSEL
#define COMP1_CSR_0_COMP2POL
#define COMP1_CSR_0_COMP2HYST
#define COMP1_CSR_1_COMP1OUTSEL
#define COMP1_CSR_1_COMP1POL
#define COMP1_CSR_1_COMP1HYST
#define COMP1_CSR_1_COMP1OUT
#define COMP1_CSR_1_COMP1LOCK
#define COMP1_CSR_1_COMP2EN
#define COMP1_CSR_1_COMP2MODE
#define COMP1_CSR_1_COMP2OUT
#define COMP1_CSR_2_COMPxOUTSEL
#define COMP1_CSR_2_COMPxPOL
#define COMP1_CSR_2_COMPxHYST
#define COMP1_CSR_2_COMPxLOCK
#define COMP3_CSR_0_COMP1SW1
#define COMP3_CSR_0_COMP1OUT
#define COMP3_CSR_0_COMP2INSEL
#define COMP3_CSR_0_WNDWEN
#define COMP3_CSR_0_COMP2OUTSEL
#define COMP3_CSR_0_COMP2POL
#define COMP3_CSR_0_COMP2HYST
#define COMP3_CSR_1_COMP1MODE
#define COMP3_CSR_1_COMP1INSEL
#define COMP3_CSR_1_COMP1OUTSEL
#define COMP3_CSR_1_COMP1POL
#define COMP3_CSR_1_COMP1HYST
#define COMP3_CSR_1_COMPxOUT
#define COMP3_CSR_1_COMP1LOCK
#define COMP3_CSR_1_COMP2EN
#define COMP3_CSR_1_COMP2MODE
#define COMP3_CSR_1_COMP2OUT
#define COMP3_CSR_2_COMPxOUTSEL
#define COMP3_CSR_2_COMPxPOL
#define COMP3_CSR_2_COMPxHYST
#define COMP3_CSR_2_COMPxLOCK
#define COMP5_CSR_0_COMP1SW1
#define COMP5_CSR_0_COMP1OUT
#define COMP5_CSR_0_COMP2INSEL
#define COMP5_CSR_0_WNDWEN
#define COMP5_CSR_0_COMP2OUTSEL
#define COMP5_CSR_0_COMP2POL
#define COMP5_CSR_0_COMP2HYST
#define COMP5_CSR_1_COMP1MODE
#define COMP5_CSR_1_COMP1INSEL
#define COMP5_CSR_1_COMP1OUTSEL
#define COMP5_CSR_1_COMP1POL
#define COMP5_CSR_1_COMP1HYST
#define COMP5_CSR_1_COMPxOUT
#define COMP5_CSR_1_COMP1LOCK
#define COMP5_CSR_1_COMP2EN
#define COMP5_CSR_1_COMP2MODE
#define COMP5_CSR_1_COMP2OUT
#define COMP5_CSR_2_COMPxOUTSEL
#define COMP5_CSR_2_COMPxPOL
#define COMP5_CSR_2_COMPxHYST
#define COMP5_CSR_2_COMPxLOCK
#define COMP7_CSR_0_COMP1SW1
#define COMP7_CSR_0_COMP1OUT
#define COMP7_CSR_0_COMP2INSEL
#define COMP7_CSR_0_WNDWEN
#define COMP7_CSR_0_COMP2OUTSEL
#define COMP7_CSR_0_COMP2POL
#define COMP7_CSR_0_COMP2HYST
#define COMP7_CSR_1_COMP1MODE
#define COMP7_CSR_1_COMP1INSEL
#define COMP7_CSR_1_COMP1OUTSEL
#define COMP7_CSR_1_COMP1POL
#define COMP7_CSR_1_COMP1HYST
#define COMP7_CSR_1_COMPxOUT
#define COMP7_CSR_1_COMP1LOCK
#define COMP7_CSR_1_COMP2EN
#define COMP7_CSR_1_COMP2MODE
#define COMP7_CSR_1_COMP2OUT
#define COMP7_CSR_2_COMPxOUTSEL
#define COMP7_CSR_2_COMPxPOL
#define COMP7_CSR_2_COMPxHYST
#define COMP7_CSR_2_COMPxLOCK
#endif

#if defined(STM32F302xC ) || defined(STM32F303xC ) || defined(STM32F358xx ) 
#define COMP_CSR_0_COMPxNONINSEL COMPxNONINSEL        // 1 bits @ 7
#define COMP_CSR_2_COMPxWNDWEN COMPxWNDWEN          // 1 bits @ 9
#define COMP_CSR_2_COMPxHYST COMPxHYST            // 2 bits @ 16
#define COMP2_CSR_0_COMP2MODE COMP2MODE            // 2 bits @ 2
#define COMP2_CSR_0_COMP2NONINSEL COMP2NONINSEL        // 1 bits @ 7
#define COMP2_CSR_0_COMP2WNDWEN COMP2WNDWEN          // 1 bits @ 9
#define COMP2_CSR_0_COMP2HYST COMP2HYST            // 2 bits @ 16
#define COMP2_CSR_1_COMPxNONINSEL COMPxNONINSEL        // 1 bits @ 7
#define COMP2_CSR_3_COMPxWNDWEN COMPxWNDWEN          // 1 bits @ 9
#define COMP2_CSR_3_COMPxHYST COMPxHYST            // 2 bits @ 16
#define COMP4_CSR_0_COMP4MODE COMP4MODE            // 2 bits @ 2
#define COMP4_CSR_0_COMP4NONINSEL COMP4NONINSEL        // 1 bits @ 7
#define COMP4_CSR_0_COMP4HYST COMP4HYST            // 2 bits @ 16
#define COMP4_CSR_1_COMPxNONINSEL COMPxNONINSEL        // 1 bits @ 7
#define COMP4_CSR_3_COMPxWNDWEN COMPxWNDWEN          // 1 bits @ 9
#define COMP4_CSR_3_COMPxHYST COMPxHYST            // 2 bits @ 16
#define COMP6_CSR_0_COMP6MODE COMP6MODE            // 2 bits @ 2
#define COMP6_CSR_0_COMP6NONINSEL COMP6NONINSEL        // 1 bits @ 7
#define COMP6_CSR_0_COMP6HYST COMP6HYST            // 2 bits @ 16
#define COMP6_CSR_1_COMPxNONINSEL COMPxNONINSEL        // 1 bits @ 7
#define COMP6_CSR_3_COMPxWNDWEN COMPxWNDWEN          // 1 bits @ 9
#define COMP6_CSR_3_COMPxHYST COMPxHYST            // 2 bits @ 16
#define COMP1_CSR_0_COMPxNONINSEL COMPxNONINSEL        // 1 bits @ 7
#define COMP1_CSR_0_COMPxWNDWEN COMPxWNDWEN          // 1 bits @ 9
#define COMP1_CSR_0_COMP1HYST COMP1HYST            // 2 bits @ 16
#define COMP1_CSR_3_COMPxHYST COMPxHYST            // 2 bits @ 16
#define COMP3_CSR_0_COMPxWNDWEN COMPxWNDWEN          // 1 bits @ 9
#define COMP3_CSR_1_COMPxNONINSEL COMPxNONINSEL        // 1 bits @ 7
#define COMP3_CSR_3_COMPxHYST COMPxHYST            // 2 bits @ 16
#define COMP5_CSR_0_COMPxWNDWEN COMPxWNDWEN          // 1 bits @ 9
#define COMP5_CSR_1_COMPxNONINSEL COMPxNONINSEL        // 1 bits @ 7
#define COMP5_CSR_3_COMPxHYST COMPxHYST            // 2 bits @ 16
#define COMP7_CSR_0_COMPxWNDWEN COMPxWNDWEN          // 1 bits @ 9
#define COMP7_CSR_1_COMPxNONINSEL COMPxNONINSEL        // 1 bits @ 7
#define COMP7_CSR_3_COMPxHYST COMPxHYST            // 2 bits @ 16
#else
#define COMP_CSR_0_COMPxNONINSEL
#define COMP_CSR_2_COMPxWNDWEN
#define COMP_CSR_2_COMPxHYST
#define COMP2_CSR_0_COMP2MODE
#define COMP2_CSR_0_COMP2NONINSEL
#define COMP2_CSR_0_COMP2WNDWEN
#define COMP2_CSR_0_COMP2HYST
#define COMP2_CSR_1_COMPxNONINSEL
#define COMP2_CSR_3_COMPxWNDWEN
#define COMP2_CSR_3_COMPxHYST
#define COMP4_CSR_0_COMP4MODE
#define COMP4_CSR_0_COMP4NONINSEL
#define COMP4_CSR_0_COMP4HYST
#define COMP4_CSR_1_COMPxNONINSEL
#define COMP4_CSR_3_COMPxWNDWEN
#define COMP4_CSR_3_COMPxHYST
#define COMP6_CSR_0_COMP6MODE
#define COMP6_CSR_0_COMP6NONINSEL
#define COMP6_CSR_0_COMP6HYST
#define COMP6_CSR_1_COMPxNONINSEL
#define COMP6_CSR_3_COMPxWNDWEN
#define COMP6_CSR_3_COMPxHYST
#define COMP1_CSR_0_COMPxNONINSEL
#define COMP1_CSR_0_COMPxWNDWEN
#define COMP1_CSR_0_COMP1HYST
#define COMP1_CSR_3_COMPxHYST
#define COMP3_CSR_0_COMPxWNDWEN
#define COMP3_CSR_1_COMPxNONINSEL
#define COMP3_CSR_3_COMPxHYST
#define COMP5_CSR_0_COMPxWNDWEN
#define COMP5_CSR_1_COMPxNONINSEL
#define COMP5_CSR_3_COMPxHYST
#define COMP7_CSR_0_COMPxWNDWEN
#define COMP7_CSR_1_COMPxNONINSEL
#define COMP7_CSR_3_COMPxHYST
#endif

#if defined(STM32L1     ) 
#define COMP_CSR_0_WNDWE     WNDWE                // 1 bits @ 17
#define COMP_CSR_1_VREFOUTEN VREFOUTEN            // 1 bits @ 16
#define COMP_CSR_1_OUTSEL    OUTSEL               // 3 bits @ 21
#define COMP_CSR_2_CS400KPU  CS400KPU             // 1 bits @ 1
#define COMP_CSR_2_CS10KPD   CS10KPD              // 1 bits @ 2
#define COMP_CSR_2_CMP1OUT   CMP1OUT              // 1 bits @ 7
#define COMP_CSR_2_INSEL     INSEL                // 3 bits @ 18
#define COMP_CSR_3_CS10KPU   CS10KPU              // 1 bits @ 0
#define COMP_CSR_3_CS400KPD  CS400KPD             // 1 bits @ 3
#define COMP_CSR_4_CMP1EN    CMP1EN               // 1 bits @ 4
#define COMP_CSR_4_CMP2OUT   CMP2OUT              // 1 bits @ 13
#define COMP_CSR_5_SPEED     SPEED                // 1 bits @ 12
#define COMP2_CSR_1_WNDWE    WNDWE                // 1 bits @ 17
#define COMP2_CSR_2_VREFOUTEN VREFOUTEN            // 1 bits @ 16
#define COMP2_CSR_2_OUTSEL   OUTSEL               // 3 bits @ 21
#define COMP2_CSR_3_CS10KPU  CS10KPU              // 1 bits @ 0
#define COMP2_CSR_3_CS10KPD  CS10KPD              // 1 bits @ 2
#define COMP2_CSR_3_CMP1OUT  CMP1OUT              // 1 bits @ 7
#define COMP2_CSR_3_INSEL    INSEL                // 3 bits @ 18
#define COMP2_CSR_4_CS400KPU CS400KPU             // 1 bits @ 1
#define COMP2_CSR_4_CS400KPD CS400KPD             // 1 bits @ 3
#define COMP2_CSR_5_CMP1EN   CMP1EN               // 1 bits @ 4
#define COMP2_CSR_5_CMP2OUT  CMP2OUT              // 1 bits @ 13
#define COMP2_CSR_6_SPEED    SPEED                // 1 bits @ 12
#define COMP4_CSR_1_WNDWE    WNDWE                // 1 bits @ 17
#define COMP4_CSR_1_OUTSEL   OUTSEL               // 3 bits @ 21
#define COMP4_CSR_2_CS400KPU CS400KPU             // 1 bits @ 1
#define COMP4_CSR_2_VREFOUTEN VREFOUTEN            // 1 bits @ 16
#define COMP4_CSR_3_CS10KPD  CS10KPD              // 1 bits @ 2
#define COMP4_CSR_3_CMP1OUT  CMP1OUT              // 1 bits @ 7
#define COMP4_CSR_3_INSEL    INSEL                // 3 bits @ 18
#define COMP4_CSR_4_CS10KPU  CS10KPU              // 1 bits @ 0
#define COMP4_CSR_4_CS400KPD CS400KPD             // 1 bits @ 3
#define COMP4_CSR_5_CMP1EN   CMP1EN               // 1 bits @ 4
#define COMP4_CSR_5_CMP2OUT  CMP2OUT              // 1 bits @ 13
#define COMP4_CSR_6_SPEED    SPEED                // 1 bits @ 12
#define COMP6_CSR_1_WNDWE    WNDWE                // 1 bits @ 17
#define COMP6_CSR_1_OUTSEL   OUTSEL               // 3 bits @ 21
#define COMP6_CSR_2_CS400KPU CS400KPU             // 1 bits @ 1
#define COMP6_CSR_2_VREFOUTEN VREFOUTEN            // 1 bits @ 16
#define COMP6_CSR_3_CS10KPD  CS10KPD              // 1 bits @ 2
#define COMP6_CSR_3_CMP1OUT  CMP1OUT              // 1 bits @ 7
#define COMP6_CSR_3_INSEL    INSEL                // 3 bits @ 18
#define COMP6_CSR_4_CS10KPU  CS10KPU              // 1 bits @ 0
#define COMP6_CSR_4_CS400KPD CS400KPD             // 1 bits @ 3
#define COMP6_CSR_5_CMP1EN   CMP1EN               // 1 bits @ 4
#define COMP6_CSR_5_CMP2OUT  CMP2OUT              // 1 bits @ 13
#define COMP6_CSR_6_SPEED    SPEED                // 1 bits @ 12
#define COMP1_CSR_1_WNDWE    WNDWE                // 1 bits @ 17
#define COMP1_CSR_1_OUTSEL   OUTSEL               // 3 bits @ 21
#define COMP1_CSR_2_CS400KPU CS400KPU             // 1 bits @ 1
#define COMP1_CSR_2_CS10KPD  CS10KPD              // 1 bits @ 2
#define COMP1_CSR_2_CMP1OUT  CMP1OUT              // 1 bits @ 7
#define COMP1_CSR_2_VREFOUTEN VREFOUTEN            // 1 bits @ 16
#define COMP1_CSR_3_CS10KPU  CS10KPU              // 1 bits @ 0
#define COMP1_CSR_3_CS400KPD CS400KPD             // 1 bits @ 3
#define COMP1_CSR_3_INSEL    INSEL                // 3 bits @ 18
#define COMP1_CSR_4_CMP1EN   CMP1EN               // 1 bits @ 4
#define COMP1_CSR_5_CMP2OUT  CMP2OUT              // 1 bits @ 13
#define COMP1_CSR_6_SPEED    SPEED                // 1 bits @ 12
#define COMP3_CSR_1_WNDWE    WNDWE                // 1 bits @ 17
#define COMP3_CSR_1_OUTSEL   OUTSEL               // 3 bits @ 21
#define COMP3_CSR_2_CS400KPU CS400KPU             // 1 bits @ 1
#define COMP3_CSR_2_VREFOUTEN VREFOUTEN            // 1 bits @ 16
#define COMP3_CSR_3_CS10KPD  CS10KPD              // 1 bits @ 2
#define COMP3_CSR_3_CMP1OUT  CMP1OUT              // 1 bits @ 7
#define COMP3_CSR_3_INSEL    INSEL                // 3 bits @ 18
#define COMP3_CSR_4_CS10KPU  CS10KPU              // 1 bits @ 0
#define COMP3_CSR_4_CS400KPD CS400KPD             // 1 bits @ 3
#define COMP3_CSR_5_CMP1EN   CMP1EN               // 1 bits @ 4
#define COMP3_CSR_5_CMP2OUT  CMP2OUT              // 1 bits @ 13
#define COMP3_CSR_6_SPEED    SPEED                // 1 bits @ 12
#define COMP5_CSR_1_WNDWE    WNDWE                // 1 bits @ 17
#define COMP5_CSR_1_OUTSEL   OUTSEL               // 3 bits @ 21
#define COMP5_CSR_2_CS400KPU CS400KPU             // 1 bits @ 1
#define COMP5_CSR_2_VREFOUTEN VREFOUTEN            // 1 bits @ 16
#define COMP5_CSR_3_CS10KPD  CS10KPD              // 1 bits @ 2
#define COMP5_CSR_3_CMP1OUT  CMP1OUT              // 1 bits @ 7
#define COMP5_CSR_3_INSEL    INSEL                // 3 bits @ 18
#define COMP5_CSR_4_CS10KPU  CS10KPU              // 1 bits @ 0
#define COMP5_CSR_4_CS400KPD CS400KPD             // 1 bits @ 3
#define COMP5_CSR_5_CMP1EN   CMP1EN               // 1 bits @ 4
#define COMP5_CSR_5_CMP2OUT  CMP2OUT              // 1 bits @ 13
#define COMP5_CSR_6_SPEED    SPEED                // 1 bits @ 12
#define COMP7_CSR_1_WNDWE    WNDWE                // 1 bits @ 17
#define COMP7_CSR_1_OUTSEL   OUTSEL               // 3 bits @ 21
#define COMP7_CSR_2_CS400KPU CS400KPU             // 1 bits @ 1
#define COMP7_CSR_2_VREFOUTEN VREFOUTEN            // 1 bits @ 16
#define COMP7_CSR_3_CS10KPD  CS10KPD              // 1 bits @ 2
#define COMP7_CSR_3_CMP1OUT  CMP1OUT              // 1 bits @ 7
#define COMP7_CSR_3_INSEL    INSEL                // 3 bits @ 18
#define COMP7_CSR_4_CS10KPU  CS10KPU              // 1 bits @ 0
#define COMP7_CSR_4_CS400KPD CS400KPD             // 1 bits @ 3
#define COMP7_CSR_5_CMP1EN   CMP1EN               // 1 bits @ 4
#define COMP7_CSR_5_CMP2OUT  CMP2OUT              // 1 bits @ 13
#define COMP7_CSR_6_SPEED    SPEED                // 1 bits @ 12
#else
#define COMP_CSR_0_WNDWE
#define COMP_CSR_1_VREFOUTEN
#define COMP_CSR_1_OUTSEL
#define COMP_CSR_2_CS400KPU
#define COMP_CSR_2_CS10KPD
#define COMP_CSR_2_CMP1OUT
#define COMP_CSR_2_INSEL
#define COMP_CSR_3_CS10KPU
#define COMP_CSR_3_CS400KPD
#define COMP_CSR_4_CMP1EN
#define COMP_CSR_4_CMP2OUT
#define COMP_CSR_5_SPEED
#define COMP2_CSR_1_WNDWE
#define COMP2_CSR_2_VREFOUTEN
#define COMP2_CSR_2_OUTSEL
#define COMP2_CSR_3_CS10KPU
#define COMP2_CSR_3_CS10KPD
#define COMP2_CSR_3_CMP1OUT
#define COMP2_CSR_3_INSEL
#define COMP2_CSR_4_CS400KPU
#define COMP2_CSR_4_CS400KPD
#define COMP2_CSR_5_CMP1EN
#define COMP2_CSR_5_CMP2OUT
#define COMP2_CSR_6_SPEED
#define COMP4_CSR_1_WNDWE
#define COMP4_CSR_1_OUTSEL
#define COMP4_CSR_2_CS400KPU
#define COMP4_CSR_2_VREFOUTEN
#define COMP4_CSR_3_CS10KPD
#define COMP4_CSR_3_CMP1OUT
#define COMP4_CSR_3_INSEL
#define COMP4_CSR_4_CS10KPU
#define COMP4_CSR_4_CS400KPD
#define COMP4_CSR_5_CMP1EN
#define COMP4_CSR_5_CMP2OUT
#define COMP4_CSR_6_SPEED
#define COMP6_CSR_1_WNDWE
#define COMP6_CSR_1_OUTSEL
#define COMP6_CSR_2_CS400KPU
#define COMP6_CSR_2_VREFOUTEN
#define COMP6_CSR_3_CS10KPD
#define COMP6_CSR_3_CMP1OUT
#define COMP6_CSR_3_INSEL
#define COMP6_CSR_4_CS10KPU
#define COMP6_CSR_4_CS400KPD
#define COMP6_CSR_5_CMP1EN
#define COMP6_CSR_5_CMP2OUT
#define COMP6_CSR_6_SPEED
#define COMP1_CSR_1_WNDWE
#define COMP1_CSR_1_OUTSEL
#define COMP1_CSR_2_CS400KPU
#define COMP1_CSR_2_CS10KPD
#define COMP1_CSR_2_CMP1OUT
#define COMP1_CSR_2_VREFOUTEN
#define COMP1_CSR_3_CS10KPU
#define COMP1_CSR_3_CS400KPD
#define COMP1_CSR_3_INSEL
#define COMP1_CSR_4_CMP1EN
#define COMP1_CSR_5_CMP2OUT
#define COMP1_CSR_6_SPEED
#define COMP3_CSR_1_WNDWE
#define COMP3_CSR_1_OUTSEL
#define COMP3_CSR_2_CS400KPU
#define COMP3_CSR_2_VREFOUTEN
#define COMP3_CSR_3_CS10KPD
#define COMP3_CSR_3_CMP1OUT
#define COMP3_CSR_3_INSEL
#define COMP3_CSR_4_CS10KPU
#define COMP3_CSR_4_CS400KPD
#define COMP3_CSR_5_CMP1EN
#define COMP3_CSR_5_CMP2OUT
#define COMP3_CSR_6_SPEED
#define COMP5_CSR_1_WNDWE
#define COMP5_CSR_1_OUTSEL
#define COMP5_CSR_2_CS400KPU
#define COMP5_CSR_2_VREFOUTEN
#define COMP5_CSR_3_CS10KPD
#define COMP5_CSR_3_CMP1OUT
#define COMP5_CSR_3_INSEL
#define COMP5_CSR_4_CS10KPU
#define COMP5_CSR_4_CS400KPD
#define COMP5_CSR_5_CMP1EN
#define COMP5_CSR_5_CMP2OUT
#define COMP5_CSR_6_SPEED
#define COMP7_CSR_1_WNDWE
#define COMP7_CSR_1_OUTSEL
#define COMP7_CSR_2_CS400KPU
#define COMP7_CSR_2_VREFOUTEN
#define COMP7_CSR_3_CS10KPD
#define COMP7_CSR_3_CMP1OUT
#define COMP7_CSR_3_INSEL
#define COMP7_CSR_4_CS10KPU
#define COMP7_CSR_4_CS400KPD
#define COMP7_CSR_5_CMP1EN
#define COMP7_CSR_5_CMP2OUT
#define COMP7_CSR_6_SPEED
#endif

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F3     ) ||\
    defined(STM32L0     ) || defined(STM32L1     ) 
#define COMP_CSR_1
#define COMP1_CSR_1
#endif

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F3     ) ||\
    defined(STM32L0     ) 
#define COMP_CSR_1_COMPxEN   COMPxEN              // 1 bits @ 0
#define COMP2_CSR_0_COMP2LOCK COMP2LOCK            // 1 bits @ 31
#define COMP2_CSR_2_COMPxEN  COMPxEN              // 1 bits @ 0
#define COMP4_CSR_0
#define COMP4_CSR_2_COMPxEN  COMPxEN              // 1 bits @ 0
#define COMP6_CSR_0
#define COMP6_CSR_2_COMPxEN  COMPxEN              // 1 bits @ 0
#define COMP1_CSR_1_COMPxEN  COMPxEN              // 1 bits @ 0
#define COMP3_CSR_2_COMPxEN  COMPxEN              // 1 bits @ 0
#define COMP5_CSR_2_COMPxEN  COMPxEN              // 1 bits @ 0
#define COMP7_CSR_2_COMPxEN  COMPxEN              // 1 bits @ 0
#else
#define COMP_CSR_1_COMPxEN
#define COMP2_CSR_0_COMP2LOCK
#define COMP2_CSR_2_COMPxEN
#define COMP4_CSR_2_COMPxEN
#define COMP6_CSR_2_COMPxEN
#define COMP1_CSR_1_COMPxEN
#define COMP3_CSR_2_COMPxEN
#define COMP5_CSR_2_COMPxEN
#define COMP7_CSR_2_COMPxEN
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) || defined(STM32F358xx ) ||\
    defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F398xx ) 
#define COMP_CSR_1_COMPxSW1  COMPxSW1             // 1 bits @ 1
#define COMP2_CSR_3_COMPxSW1 COMPxSW1             // 1 bits @ 1
#define COMP4_CSR_1_COMPxSW1 COMPxSW1             // 1 bits @ 1
#define COMP6_CSR_1_COMPxSW1 COMPxSW1             // 1 bits @ 1
#define COMP1_CSR_1_COMPxSW1 COMPxSW1             // 1 bits @ 1
#define COMP3_CSR_1_COMPxSW1 COMPxSW1             // 1 bits @ 1
#define COMP5_CSR_1_COMPxSW1 COMPxSW1             // 1 bits @ 1
#define COMP7_CSR_1_COMPxSW1 COMPxSW1             // 1 bits @ 1
#else
#define COMP_CSR_1_COMPxSW1
#define COMP2_CSR_3_COMPxSW1
#define COMP4_CSR_1_COMPxSW1
#define COMP6_CSR_1_COMPxSW1
#define COMP1_CSR_1_COMPxSW1
#define COMP3_CSR_1_COMPxSW1
#define COMP5_CSR_1_COMPxSW1
#define COMP7_CSR_1_COMPxSW1
#endif

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F302xC ) ||\
    defined(STM32F303xC ) || defined(STM32F358xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) 
#define COMP_CSR_1_COMPxMODE COMPxMODE            // 2 bits @ 2
#define COMP2_CSR_2_COMPxMODE COMPxMODE            // 2 bits @ 2
#define COMP4_CSR_2_COMPxMODE COMPxMODE            // 2 bits @ 2
#define COMP6_CSR_2_COMPxMODE COMPxMODE            // 2 bits @ 2
#define COMP1_CSR_0_COMP1MODE COMP1MODE            // 2 bits @ 2
#define COMP1_CSR_1_COMPxMODE COMPxMODE            // 2 bits @ 2
#define COMP3_CSR_2_COMPxMODE COMPxMODE            // 2 bits @ 2
#define COMP5_CSR_2_COMPxMODE COMPxMODE            // 2 bits @ 2
#define COMP7_CSR_2_COMPxMODE COMPxMODE            // 2 bits @ 2
#else
#define COMP_CSR_1_COMPxMODE
#define COMP2_CSR_2_COMPxMODE
#define COMP4_CSR_2_COMPxMODE
#define COMP6_CSR_2_COMPxMODE
#define COMP1_CSR_0_COMP1MODE
#define COMP1_CSR_1_COMPxMODE
#define COMP3_CSR_2_COMPxMODE
#define COMP5_CSR_2_COMPxMODE
#define COMP7_CSR_2_COMPxMODE
#endif

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F301x8 ) ||\
    defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F318xx ) || defined(STM32F358xx ) || defined(STM32F373xC ) ||\
    defined(STM32F378xx ) || defined(STM32F398xx ) 
#define COMP_CSR_1_COMPxINSEL COMPxINSEL           // 3 bits @ 4
#define COMP2_CSR_2_COMPxINSEL COMPxINSEL           // 3 bits @ 4
#define COMP4_CSR_2_COMPxINSEL COMPxINSEL           // 3 bits @ 4
#define COMP6_CSR_2_COMPxINSEL COMPxINSEL           // 3 bits @ 4
#define COMP1_CSR_1_COMPxINSEL COMPxINSEL           // 3 bits @ 4
#define COMP3_CSR_2_COMPxINSEL COMPxINSEL           // 3 bits @ 4
#define COMP5_CSR_2_COMPxINSEL COMPxINSEL           // 3 bits @ 4
#define COMP7_CSR_2_COMPxINSEL COMPxINSEL           // 3 bits @ 4
#else
#define COMP_CSR_1_COMPxINSEL
#define COMP2_CSR_2_COMPxINSEL
#define COMP4_CSR_2_COMPxINSEL
#define COMP6_CSR_2_COMPxINSEL
#define COMP1_CSR_1_COMPxINSEL
#define COMP3_CSR_2_COMPxINSEL
#define COMP5_CSR_2_COMPxINSEL
#define COMP7_CSR_2_COMPxINSEL
#endif

#if defined(STM32F373xC ) || defined(STM32F378xx ) 
#define COMP_CSR_1_COMPxWNDWEN COMPxWNDWEN          // 1 bits @ 7
#define COMP2_CSR_2_COMPxWNDWEN COMPxWNDWEN          // 1 bits @ 7
#define COMP4_CSR_2_COMPxWNDWEN COMPxWNDWEN          // 1 bits @ 7
#define COMP6_CSR_2_COMPxWNDWEN COMPxWNDWEN          // 1 bits @ 7
#define COMP1_CSR_1_COMPxWNDWEN COMPxWNDWEN          // 1 bits @ 7
#define COMP3_CSR_2_COMPxWNDWEN COMPxWNDWEN          // 1 bits @ 7
#define COMP5_CSR_2_COMPxWNDWEN COMPxWNDWEN          // 1 bits @ 7
#define COMP7_CSR_2_COMPxWNDWEN COMPxWNDWEN          // 1 bits @ 7
#else
#define COMP_CSR_1_COMPxWNDWEN
#define COMP2_CSR_2_COMPxWNDWEN
#define COMP4_CSR_2_COMPxWNDWEN
#define COMP6_CSR_2_COMPxWNDWEN
#define COMP1_CSR_1_COMPxWNDWEN
#define COMP3_CSR_2_COMPxWNDWEN
#define COMP5_CSR_2_COMPxWNDWEN
#define COMP7_CSR_2_COMPxWNDWEN
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F398xx ) 
#define COMP_CSR_1_COMPxBLANKING COMPxBLANKING        // 2 bits @ 18
#define COMP_CSR_2_COMPxOUTSEL COMPxOUTSEL          // 4 bits @ 10
#define COMP_CSR_2_COMPxPOL  COMPxPOL             // 1 bits @ 15
#define COMP_CSR_2_COMPxOUT  COMPxOUT             // 1 bits @ 30
#define COMP2_CSR_0_COMP2OUTSEL COMP2OUTSEL          // 4 bits @ 10
#define COMP2_CSR_0_COMP2POL COMP2POL             // 1 bits @ 15
#define COMP2_CSR_0_COMP2BLANKING COMP2BLANKING        // 2 bits @ 18
#define COMP2_CSR_2_COMPxBLANKING COMPxBLANKING        // 2 bits @ 18
#define COMP2_CSR_2_COMPxOUT COMPxOUT             // 1 bits @ 30
#define COMP2_CSR_3_COMPxOUTSEL COMPxOUTSEL          // 4 bits @ 10
#define COMP2_CSR_3_COMPxPOL COMPxPOL             // 1 bits @ 15
#define COMP4_CSR_0_COMP4EN  COMP4EN              // 1 bits @ 0
#define COMP4_CSR_0_COMP4OUTSEL COMP4OUTSEL          // 4 bits @ 10
#define COMP4_CSR_0_COMP4POL COMP4POL             // 1 bits @ 15
#define COMP4_CSR_0_COMP4BLANKING COMP4BLANKING        // 2 bits @ 18
#define COMP4_CSR_0_COMP4OUT COMP4OUT             // 1 bits @ 30
#define COMP4_CSR_0_COMP4LOCK COMP4LOCK            // 1 bits @ 31
#define COMP4_CSR_2_COMPxBLANKING COMPxBLANKING        // 2 bits @ 18
#define COMP4_CSR_3_COMPxOUTSEL COMPxOUTSEL          // 4 bits @ 10
#define COMP4_CSR_3_COMPxPOL COMPxPOL             // 1 bits @ 15
#define COMP4_CSR_3_COMPxOUT COMPxOUT             // 1 bits @ 30
#define COMP6_CSR_0_COMP6EN  COMP6EN              // 1 bits @ 0
#define COMP6_CSR_0_COMP6OUTSEL COMP6OUTSEL          // 4 bits @ 10
#define COMP6_CSR_0_COMP6POL COMP6POL             // 1 bits @ 15
#define COMP6_CSR_0_COMP6BLANKING COMP6BLANKING        // 2 bits @ 18
#define COMP6_CSR_0_COMP6OUT COMP6OUT             // 1 bits @ 30
#define COMP6_CSR_0_COMP6LOCK COMP6LOCK            // 1 bits @ 31
#define COMP6_CSR_2_COMPxBLANKING COMPxBLANKING        // 2 bits @ 18
#define COMP6_CSR_3_COMPxOUTSEL COMPxOUTSEL          // 4 bits @ 10
#define COMP6_CSR_3_COMPxPOL COMPxPOL             // 1 bits @ 15
#define COMP6_CSR_3_COMPxOUT COMPxOUT             // 1 bits @ 30
#define COMP1_CSR_2_COMPxBLANKING COMPxBLANKING        // 2 bits @ 18
#define COMP1_CSR_3_COMPxOUTSEL COMPxOUTSEL          // 4 bits @ 10
#define COMP1_CSR_3_COMPxPOL COMPxPOL             // 1 bits @ 15
#define COMP1_CSR_3_COMPxOUT COMPxOUT             // 1 bits @ 30
#define COMP3_CSR_2_COMPxBLANKING COMPxBLANKING        // 2 bits @ 18
#define COMP3_CSR_3_COMPxOUTSEL COMPxOUTSEL          // 4 bits @ 10
#define COMP3_CSR_3_COMPxPOL COMPxPOL             // 1 bits @ 15
#define COMP3_CSR_3_COMPxOUT COMPxOUT             // 1 bits @ 30
#define COMP5_CSR_2_COMPxBLANKING COMPxBLANKING        // 2 bits @ 18
#define COMP5_CSR_3_COMPxOUTSEL COMPxOUTSEL          // 4 bits @ 10
#define COMP5_CSR_3_COMPxPOL COMPxPOL             // 1 bits @ 15
#define COMP5_CSR_3_COMPxOUT COMPxOUT             // 1 bits @ 30
#define COMP7_CSR_2_COMPxBLANKING COMPxBLANKING        // 2 bits @ 18
#define COMP7_CSR_3_COMPxOUTSEL COMPxOUTSEL          // 4 bits @ 10
#define COMP7_CSR_3_COMPxPOL COMPxPOL             // 1 bits @ 15
#define COMP7_CSR_3_COMPxOUT COMPxOUT             // 1 bits @ 30
#else
#define COMP_CSR_1_COMPxBLANKING
#define COMP_CSR_2_COMPxOUTSEL
#define COMP_CSR_2_COMPxPOL
#define COMP_CSR_2_COMPxOUT
#define COMP2_CSR_0_COMP2OUTSEL
#define COMP2_CSR_0_COMP2POL
#define COMP2_CSR_0_COMP2BLANKING
#define COMP2_CSR_2_COMPxBLANKING
#define COMP2_CSR_2_COMPxOUT
#define COMP2_CSR_3_COMPxOUTSEL
#define COMP2_CSR_3_COMPxPOL
#define COMP4_CSR_0_COMP4EN
#define COMP4_CSR_0_COMP4OUTSEL
#define COMP4_CSR_0_COMP4POL
#define COMP4_CSR_0_COMP4BLANKING
#define COMP4_CSR_0_COMP4OUT
#define COMP4_CSR_0_COMP4LOCK
#define COMP4_CSR_2_COMPxBLANKING
#define COMP4_CSR_3_COMPxOUTSEL
#define COMP4_CSR_3_COMPxPOL
#define COMP4_CSR_3_COMPxOUT
#define COMP6_CSR_0_COMP6EN
#define COMP6_CSR_0_COMP6OUTSEL
#define COMP6_CSR_0_COMP6POL
#define COMP6_CSR_0_COMP6BLANKING
#define COMP6_CSR_0_COMP6OUT
#define COMP6_CSR_0_COMP6LOCK
#define COMP6_CSR_2_COMPxBLANKING
#define COMP6_CSR_3_COMPxOUTSEL
#define COMP6_CSR_3_COMPxPOL
#define COMP6_CSR_3_COMPxOUT
#define COMP1_CSR_2_COMPxBLANKING
#define COMP1_CSR_3_COMPxOUTSEL
#define COMP1_CSR_3_COMPxPOL
#define COMP1_CSR_3_COMPxOUT
#define COMP3_CSR_2_COMPxBLANKING
#define COMP3_CSR_3_COMPxOUTSEL
#define COMP3_CSR_3_COMPxPOL
#define COMP3_CSR_3_COMPxOUT
#define COMP5_CSR_2_COMPxBLANKING
#define COMP5_CSR_3_COMPxOUTSEL
#define COMP5_CSR_3_COMPxPOL
#define COMP5_CSR_3_COMPxOUT
#define COMP7_CSR_2_COMPxBLANKING
#define COMP7_CSR_3_COMPxOUTSEL
#define COMP7_CSR_3_COMPxPOL
#define COMP7_CSR_3_COMPxOUT
#endif

#if defined(STM32L100xC ) || defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) ||\
    defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) ||\
    defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define COMP_CSR_1_FCH3      FCH3                 // 1 bits @ 26
#define COMP_CSR_1_FCH8      FCH8                 // 1 bits @ 27
#define COMP_CSR_1_RCH13     RCH13                // 1 bits @ 28
#define COMP_CSR_1_CAIE      CAIE                 // 1 bits @ 29
#define COMP_CSR_3_TSUSP     TSUSP                // 1 bits @ 31
#define COMP_CSR_5_CAIF      CAIF                 // 1 bits @ 30
#define COMP2_CSR_0_FCH3     FCH3                 // 1 bits @ 26
#define COMP2_CSR_0_FCH8     FCH8                 // 1 bits @ 27
#define COMP2_CSR_0_RCH13    RCH13                // 1 bits @ 28
#define COMP2_CSR_0_CAIE     CAIE                 // 1 bits @ 29
#define COMP2_CSR_3_TSUSP    TSUSP                // 1 bits @ 31
#define COMP2_CSR_5_CAIF     CAIF                 // 1 bits @ 30
#define COMP4_CSR_1_FCH3     FCH3                 // 1 bits @ 26
#define COMP4_CSR_1_FCH8     FCH8                 // 1 bits @ 27
#define COMP4_CSR_1_RCH13    RCH13                // 1 bits @ 28
#define COMP4_CSR_1_CAIE     CAIE                 // 1 bits @ 29
#define COMP4_CSR_4_TSUSP    TSUSP                // 1 bits @ 31
#define COMP4_CSR_6_CAIF     CAIF                 // 1 bits @ 30
#define COMP6_CSR_1_FCH3     FCH3                 // 1 bits @ 26
#define COMP6_CSR_1_FCH8     FCH8                 // 1 bits @ 27
#define COMP6_CSR_1_RCH13    RCH13                // 1 bits @ 28
#define COMP6_CSR_1_CAIE     CAIE                 // 1 bits @ 29
#define COMP6_CSR_4_TSUSP    TSUSP                // 1 bits @ 31
#define COMP6_CSR_6_CAIF     CAIF                 // 1 bits @ 30
#define COMP1_CSR_1_FCH3     FCH3                 // 1 bits @ 26
#define COMP1_CSR_1_FCH8     FCH8                 // 1 bits @ 27
#define COMP1_CSR_1_RCH13    RCH13                // 1 bits @ 28
#define COMP1_CSR_1_CAIE     CAIE                 // 1 bits @ 29
#define COMP1_CSR_2_TSUSP    TSUSP                // 1 bits @ 31
#define COMP1_CSR_6_CAIF     CAIF                 // 1 bits @ 30
#define COMP3_CSR_1_FCH3     FCH3                 // 1 bits @ 26
#define COMP3_CSR_1_FCH8     FCH8                 // 1 bits @ 27
#define COMP3_CSR_1_RCH13    RCH13                // 1 bits @ 28
#define COMP3_CSR_1_CAIE     CAIE                 // 1 bits @ 29
#define COMP3_CSR_4_TSUSP    TSUSP                // 1 bits @ 31
#define COMP3_CSR_6_CAIF     CAIF                 // 1 bits @ 30
#define COMP5_CSR_1_FCH3     FCH3                 // 1 bits @ 26
#define COMP5_CSR_1_FCH8     FCH8                 // 1 bits @ 27
#define COMP5_CSR_1_RCH13    RCH13                // 1 bits @ 28
#define COMP5_CSR_1_CAIE     CAIE                 // 1 bits @ 29
#define COMP5_CSR_4_TSUSP    TSUSP                // 1 bits @ 31
#define COMP5_CSR_6_CAIF     CAIF                 // 1 bits @ 30
#define COMP7_CSR_1_FCH3     FCH3                 // 1 bits @ 26
#define COMP7_CSR_1_FCH8     FCH8                 // 1 bits @ 27
#define COMP7_CSR_1_RCH13    RCH13                // 1 bits @ 28
#define COMP7_CSR_1_CAIE     CAIE                 // 1 bits @ 29
#define COMP7_CSR_4_TSUSP    TSUSP                // 1 bits @ 31
#define COMP7_CSR_6_CAIF     CAIF                 // 1 bits @ 30
#else
#define COMP_CSR_1_FCH3
#define COMP_CSR_1_FCH8
#define COMP_CSR_1_RCH13
#define COMP_CSR_1_CAIE
#define COMP_CSR_3_TSUSP
#define COMP_CSR_5_CAIF
#define COMP2_CSR_0_FCH3
#define COMP2_CSR_0_FCH8
#define COMP2_CSR_0_RCH13
#define COMP2_CSR_0_CAIE
#define COMP2_CSR_3_TSUSP
#define COMP2_CSR_5_CAIF
#define COMP4_CSR_1_FCH3
#define COMP4_CSR_1_FCH8
#define COMP4_CSR_1_RCH13
#define COMP4_CSR_1_CAIE
#define COMP4_CSR_4_TSUSP
#define COMP4_CSR_6_CAIF
#define COMP6_CSR_1_FCH3
#define COMP6_CSR_1_FCH8
#define COMP6_CSR_1_RCH13
#define COMP6_CSR_1_CAIE
#define COMP6_CSR_4_TSUSP
#define COMP6_CSR_6_CAIF
#define COMP1_CSR_1_FCH3
#define COMP1_CSR_1_FCH8
#define COMP1_CSR_1_RCH13
#define COMP1_CSR_1_CAIE
#define COMP1_CSR_2_TSUSP
#define COMP1_CSR_6_CAIF
#define COMP3_CSR_1_FCH3
#define COMP3_CSR_1_FCH8
#define COMP3_CSR_1_RCH13
#define COMP3_CSR_1_CAIE
#define COMP3_CSR_4_TSUSP
#define COMP3_CSR_6_CAIF
#define COMP5_CSR_1_FCH3
#define COMP5_CSR_1_FCH8
#define COMP5_CSR_1_RCH13
#define COMP5_CSR_1_CAIE
#define COMP5_CSR_4_TSUSP
#define COMP5_CSR_6_CAIF
#define COMP7_CSR_1_FCH3
#define COMP7_CSR_1_FCH8
#define COMP7_CSR_1_RCH13
#define COMP7_CSR_1_CAIE
#define COMP7_CSR_4_TSUSP
#define COMP7_CSR_6_CAIF
#endif

#if defined(STM32L0     ) 
#define COMP_CSR_1_COMP1VALUE COMP1VALUE           // 1 bits @ 30
#define COMP_CSR_1_COMP1LOCK COMP1LOCK            // 1 bits @ 31
#define COMP_CSR_2_COMP2EN   COMP2EN              // 1 bits @ 0
#define COMP_CSR_2_COMP2SPEED COMP2SPEED           // 1 bits @ 3
#define COMP_CSR_2_COMP1INNSEL COMP1INNSEL          // 2 bits @ 4
#define COMP_CSR_2_COMP1WM   COMP1WM              // 1 bits @ 8
#define COMP_CSR_3_COMP2INNSEL COMP2INNSEL          // 3 bits @ 4
#define COMP_CSR_3_COMP2INPSEL COMP2INPSEL          // 3 bits @ 8
#define COMP_CSR_3_COMP1LPTIM1IN1 COMP1LPTIM1IN1       // 1 bits @ 12
#define COMP_CSR_3_COMP2LPTIM1IN1 COMP2LPTIM1IN1       // 1 bits @ 13
#define COMP_CSR_3_COMP1POLARITY COMP1POLARITY        // 1 bits @ 15
#define COMP_CSR_3_COMP2VALUE COMP2VALUE           // 1 bits @ 30
#define COMP_CSR_4_WINMODE   WINMODE              // 1 bits @ 8
#define COMP_CSR_4_COMP2LPTIM1IN2 COMP2LPTIM1IN2       // 1 bits @ 12
#define COMP_CSR_4_COMP2POLARITY COMP2POLARITY        // 1 bits @ 15
#define COMP_CSR_4_COMPxOUTVALUE COMPxOUTVALUE        // 1 bits @ 30
#define COMP_CSR_5_COMPxPOLARITY COMPxPOLARITY        // 1 bits @ 15
#define COMP2_CSR_0_COMP1WM  COMP1WM              // 1 bits @ 8
#define COMP2_CSR_1_COMP1VALUE COMP1VALUE           // 1 bits @ 30
#define COMP2_CSR_2_COMP1LOCK COMP1LOCK            // 1 bits @ 31
#define COMP2_CSR_3_COMP2SPEED COMP2SPEED           // 1 bits @ 3
#define COMP2_CSR_3_COMP1INNSEL COMP1INNSEL          // 2 bits @ 4
#define COMP2_CSR_3_WINMODE  WINMODE              // 1 bits @ 8
#define COMP2_CSR_3_COMP2VALUE COMP2VALUE           // 1 bits @ 30
#define COMP2_CSR_4_COMP2INNSEL COMP2INNSEL          // 3 bits @ 4
#define COMP2_CSR_4_COMP2INPSEL COMP2INPSEL          // 3 bits @ 8
#define COMP2_CSR_4_COMP1LPTIM1IN1 COMP1LPTIM1IN1       // 1 bits @ 12
#define COMP2_CSR_4_COMP2LPTIM1IN1 COMP2LPTIM1IN1       // 1 bits @ 13
#define COMP2_CSR_4_COMP1POLARITY COMP1POLARITY        // 1 bits @ 15
#define COMP2_CSR_4_COMPxOUTVALUE COMPxOUTVALUE        // 1 bits @ 30
#define COMP2_CSR_5_COMP2LPTIM1IN2 COMP2LPTIM1IN2       // 1 bits @ 12
#define COMP2_CSR_5_COMP2POLARITY COMP2POLARITY        // 1 bits @ 15
#define COMP2_CSR_6_COMPxPOLARITY COMPxPOLARITY        // 1 bits @ 15
#define COMP4_CSR_0_COMP1WM  COMP1WM              // 1 bits @ 8
#define COMP4_CSR_2_COMP1VALUE COMP1VALUE           // 1 bits @ 30
#define COMP4_CSR_2_COMP1LOCK COMP1LOCK            // 1 bits @ 31
#define COMP4_CSR_3_COMP2EN  COMP2EN              // 1 bits @ 0
#define COMP4_CSR_3_COMP2SPEED COMP2SPEED           // 1 bits @ 3
#define COMP4_CSR_3_COMP1INNSEL COMP1INNSEL          // 2 bits @ 4
#define COMP4_CSR_3_WINMODE  WINMODE              // 1 bits @ 8
#define COMP4_CSR_4_COMP2INNSEL COMP2INNSEL          // 3 bits @ 4
#define COMP4_CSR_4_COMP2INPSEL COMP2INPSEL          // 3 bits @ 8
#define COMP4_CSR_4_COMP1LPTIM1IN1 COMP1LPTIM1IN1       // 1 bits @ 12
#define COMP4_CSR_4_COMP2LPTIM1IN1 COMP2LPTIM1IN1       // 1 bits @ 13
#define COMP4_CSR_4_COMP1POLARITY COMP1POLARITY        // 1 bits @ 15
#define COMP4_CSR_4_COMP2VALUE COMP2VALUE           // 1 bits @ 30
#define COMP4_CSR_5_COMP2LPTIM1IN2 COMP2LPTIM1IN2       // 1 bits @ 12
#define COMP4_CSR_5_COMP2POLARITY COMP2POLARITY        // 1 bits @ 15
#define COMP4_CSR_5_COMPxOUTVALUE COMPxOUTVALUE        // 1 bits @ 30
#define COMP4_CSR_6_COMPxPOLARITY COMPxPOLARITY        // 1 bits @ 15
#define COMP6_CSR_0_COMP1WM  COMP1WM              // 1 bits @ 8
#define COMP6_CSR_2_COMP1VALUE COMP1VALUE           // 1 bits @ 30
#define COMP6_CSR_2_COMP1LOCK COMP1LOCK            // 1 bits @ 31
#define COMP6_CSR_3_COMP2EN  COMP2EN              // 1 bits @ 0
#define COMP6_CSR_3_COMP2SPEED COMP2SPEED           // 1 bits @ 3
#define COMP6_CSR_3_COMP1INNSEL COMP1INNSEL          // 2 bits @ 4
#define COMP6_CSR_3_WINMODE  WINMODE              // 1 bits @ 8
#define COMP6_CSR_4_COMP2INNSEL COMP2INNSEL          // 3 bits @ 4
#define COMP6_CSR_4_COMP2INPSEL COMP2INPSEL          // 3 bits @ 8
#define COMP6_CSR_4_COMP1LPTIM1IN1 COMP1LPTIM1IN1       // 1 bits @ 12
#define COMP6_CSR_4_COMP2LPTIM1IN1 COMP2LPTIM1IN1       // 1 bits @ 13
#define COMP6_CSR_4_COMP1POLARITY COMP1POLARITY        // 1 bits @ 15
#define COMP6_CSR_4_COMP2VALUE COMP2VALUE           // 1 bits @ 30
#define COMP6_CSR_5_COMP2LPTIM1IN2 COMP2LPTIM1IN2       // 1 bits @ 12
#define COMP6_CSR_5_COMP2POLARITY COMP2POLARITY        // 1 bits @ 15
#define COMP6_CSR_5_COMPxOUTVALUE COMPxOUTVALUE        // 1 bits @ 30
#define COMP6_CSR_6_COMPxPOLARITY COMPxPOLARITY        // 1 bits @ 15
#define COMP1_CSR_0_COMP1WM  COMP1WM              // 1 bits @ 8
#define COMP1_CSR_2_COMP2EN  COMP2EN              // 1 bits @ 0
#define COMP1_CSR_2_COMP2SPEED COMP2SPEED           // 1 bits @ 3
#define COMP1_CSR_2_COMP1INNSEL COMP1INNSEL          // 2 bits @ 4
#define COMP1_CSR_2_COMP1VALUE COMP1VALUE           // 1 bits @ 30
#define COMP1_CSR_3_COMP2INNSEL COMP2INNSEL          // 3 bits @ 4
#define COMP1_CSR_3_WINMODE  WINMODE              // 1 bits @ 8
#define COMP1_CSR_4_COMP2INPSEL COMP2INPSEL          // 3 bits @ 8
#define COMP1_CSR_4_COMP1LPTIM1IN1 COMP1LPTIM1IN1       // 1 bits @ 12
#define COMP1_CSR_4_COMP2LPTIM1IN1 COMP2LPTIM1IN1       // 1 bits @ 13
#define COMP1_CSR_4_COMP1POLARITY COMP1POLARITY        // 1 bits @ 15
#define COMP1_CSR_4_COMP2VALUE COMP2VALUE           // 1 bits @ 30
#define COMP1_CSR_5_COMP2LPTIM1IN2 COMP2LPTIM1IN2       // 1 bits @ 12
#define COMP1_CSR_5_COMP2POLARITY COMP2POLARITY        // 1 bits @ 15
#define COMP1_CSR_5_COMPxOUTVALUE COMPxOUTVALUE        // 1 bits @ 30
#define COMP1_CSR_6_COMPxPOLARITY COMPxPOLARITY        // 1 bits @ 15
#define COMP3_CSR_0_COMP1WM  COMP1WM              // 1 bits @ 8
#define COMP3_CSR_2_COMP1VALUE COMP1VALUE           // 1 bits @ 30
#define COMP3_CSR_2_COMP1LOCK COMP1LOCK            // 1 bits @ 31
#define COMP3_CSR_3_COMP2EN  COMP2EN              // 1 bits @ 0
#define COMP3_CSR_3_COMP2SPEED COMP2SPEED           // 1 bits @ 3
#define COMP3_CSR_3_COMP1INNSEL COMP1INNSEL          // 2 bits @ 4
#define COMP3_CSR_3_WINMODE  WINMODE              // 1 bits @ 8
#define COMP3_CSR_4_COMP2INNSEL COMP2INNSEL          // 3 bits @ 4
#define COMP3_CSR_4_COMP2INPSEL COMP2INPSEL          // 3 bits @ 8
#define COMP3_CSR_4_COMP1LPTIM1IN1 COMP1LPTIM1IN1       // 1 bits @ 12
#define COMP3_CSR_4_COMP2LPTIM1IN1 COMP2LPTIM1IN1       // 1 bits @ 13
#define COMP3_CSR_4_COMP1POLARITY COMP1POLARITY        // 1 bits @ 15
#define COMP3_CSR_4_COMP2VALUE COMP2VALUE           // 1 bits @ 30
#define COMP3_CSR_5_COMP2LPTIM1IN2 COMP2LPTIM1IN2       // 1 bits @ 12
#define COMP3_CSR_5_COMP2POLARITY COMP2POLARITY        // 1 bits @ 15
#define COMP3_CSR_5_COMPxOUTVALUE COMPxOUTVALUE        // 1 bits @ 30
#define COMP3_CSR_6_COMPxPOLARITY COMPxPOLARITY        // 1 bits @ 15
#define COMP5_CSR_0_COMP1WM  COMP1WM              // 1 bits @ 8
#define COMP5_CSR_2_COMP1VALUE COMP1VALUE           // 1 bits @ 30
#define COMP5_CSR_2_COMP1LOCK COMP1LOCK            // 1 bits @ 31
#define COMP5_CSR_3_COMP2EN  COMP2EN              // 1 bits @ 0
#define COMP5_CSR_3_COMP2SPEED COMP2SPEED           // 1 bits @ 3
#define COMP5_CSR_3_COMP1INNSEL COMP1INNSEL          // 2 bits @ 4
#define COMP5_CSR_3_WINMODE  WINMODE              // 1 bits @ 8
#define COMP5_CSR_4_COMP2INNSEL COMP2INNSEL          // 3 bits @ 4
#define COMP5_CSR_4_COMP2INPSEL COMP2INPSEL          // 3 bits @ 8
#define COMP5_CSR_4_COMP1LPTIM1IN1 COMP1LPTIM1IN1       // 1 bits @ 12
#define COMP5_CSR_4_COMP2LPTIM1IN1 COMP2LPTIM1IN1       // 1 bits @ 13
#define COMP5_CSR_4_COMP1POLARITY COMP1POLARITY        // 1 bits @ 15
#define COMP5_CSR_4_COMP2VALUE COMP2VALUE           // 1 bits @ 30
#define COMP5_CSR_5_COMP2LPTIM1IN2 COMP2LPTIM1IN2       // 1 bits @ 12
#define COMP5_CSR_5_COMP2POLARITY COMP2POLARITY        // 1 bits @ 15
#define COMP5_CSR_5_COMPxOUTVALUE COMPxOUTVALUE        // 1 bits @ 30
#define COMP5_CSR_6_COMPxPOLARITY COMPxPOLARITY        // 1 bits @ 15
#define COMP7_CSR_0_COMP1WM  COMP1WM              // 1 bits @ 8
#define COMP7_CSR_2_COMP1VALUE COMP1VALUE           // 1 bits @ 30
#define COMP7_CSR_2_COMP1LOCK COMP1LOCK            // 1 bits @ 31
#define COMP7_CSR_3_COMP2EN  COMP2EN              // 1 bits @ 0
#define COMP7_CSR_3_COMP2SPEED COMP2SPEED           // 1 bits @ 3
#define COMP7_CSR_3_COMP1INNSEL COMP1INNSEL          // 2 bits @ 4
#define COMP7_CSR_3_WINMODE  WINMODE              // 1 bits @ 8
#define COMP7_CSR_4_COMP2INNSEL COMP2INNSEL          // 3 bits @ 4
#define COMP7_CSR_4_COMP2INPSEL COMP2INPSEL          // 3 bits @ 8
#define COMP7_CSR_4_COMP1LPTIM1IN1 COMP1LPTIM1IN1       // 1 bits @ 12
#define COMP7_CSR_4_COMP2LPTIM1IN1 COMP2LPTIM1IN1       // 1 bits @ 13
#define COMP7_CSR_4_COMP1POLARITY COMP1POLARITY        // 1 bits @ 15
#define COMP7_CSR_4_COMP2VALUE COMP2VALUE           // 1 bits @ 30
#define COMP7_CSR_5_COMP2LPTIM1IN2 COMP2LPTIM1IN2       // 1 bits @ 12
#define COMP7_CSR_5_COMP2POLARITY COMP2POLARITY        // 1 bits @ 15
#define COMP7_CSR_5_COMPxOUTVALUE COMPxOUTVALUE        // 1 bits @ 30
#define COMP7_CSR_6_COMPxPOLARITY COMPxPOLARITY        // 1 bits @ 15
#else
#define COMP_CSR_1_COMP1VALUE
#define COMP_CSR_1_COMP1LOCK
#define COMP_CSR_2_COMP2EN
#define COMP_CSR_2_COMP2SPEED
#define COMP_CSR_2_COMP1INNSEL
#define COMP_CSR_2_COMP1WM
#define COMP_CSR_3_COMP2INNSEL
#define COMP_CSR_3_COMP2INPSEL
#define COMP_CSR_3_COMP1LPTIM1IN1
#define COMP_CSR_3_COMP2LPTIM1IN1
#define COMP_CSR_3_COMP1POLARITY
#define COMP_CSR_3_COMP2VALUE
#define COMP_CSR_4_WINMODE
#define COMP_CSR_4_COMP2LPTIM1IN2
#define COMP_CSR_4_COMP2POLARITY
#define COMP_CSR_4_COMPxOUTVALUE
#define COMP_CSR_5_COMPxPOLARITY
#define COMP2_CSR_0_COMP1WM
#define COMP2_CSR_1_COMP1VALUE
#define COMP2_CSR_2_COMP1LOCK
#define COMP2_CSR_3_COMP2SPEED
#define COMP2_CSR_3_COMP1INNSEL
#define COMP2_CSR_3_WINMODE
#define COMP2_CSR_3_COMP2VALUE
#define COMP2_CSR_4_COMP2INNSEL
#define COMP2_CSR_4_COMP2INPSEL
#define COMP2_CSR_4_COMP1LPTIM1IN1
#define COMP2_CSR_4_COMP2LPTIM1IN1
#define COMP2_CSR_4_COMP1POLARITY
#define COMP2_CSR_4_COMPxOUTVALUE
#define COMP2_CSR_5_COMP2LPTIM1IN2
#define COMP2_CSR_5_COMP2POLARITY
#define COMP2_CSR_6_COMPxPOLARITY
#define COMP4_CSR_0_COMP1WM
#define COMP4_CSR_2_COMP1VALUE
#define COMP4_CSR_2_COMP1LOCK
#define COMP4_CSR_3_COMP2EN
#define COMP4_CSR_3_COMP2SPEED
#define COMP4_CSR_3_COMP1INNSEL
#define COMP4_CSR_3_WINMODE
#define COMP4_CSR_4_COMP2INNSEL
#define COMP4_CSR_4_COMP2INPSEL
#define COMP4_CSR_4_COMP1LPTIM1IN1
#define COMP4_CSR_4_COMP2LPTIM1IN1
#define COMP4_CSR_4_COMP1POLARITY
#define COMP4_CSR_4_COMP2VALUE
#define COMP4_CSR_5_COMP2LPTIM1IN2
#define COMP4_CSR_5_COMP2POLARITY
#define COMP4_CSR_5_COMPxOUTVALUE
#define COMP4_CSR_6_COMPxPOLARITY
#define COMP6_CSR_0_COMP1WM
#define COMP6_CSR_2_COMP1VALUE
#define COMP6_CSR_2_COMP1LOCK
#define COMP6_CSR_3_COMP2EN
#define COMP6_CSR_3_COMP2SPEED
#define COMP6_CSR_3_COMP1INNSEL
#define COMP6_CSR_3_WINMODE
#define COMP6_CSR_4_COMP2INNSEL
#define COMP6_CSR_4_COMP2INPSEL
#define COMP6_CSR_4_COMP1LPTIM1IN1
#define COMP6_CSR_4_COMP2LPTIM1IN1
#define COMP6_CSR_4_COMP1POLARITY
#define COMP6_CSR_4_COMP2VALUE
#define COMP6_CSR_5_COMP2LPTIM1IN2
#define COMP6_CSR_5_COMP2POLARITY
#define COMP6_CSR_5_COMPxOUTVALUE
#define COMP6_CSR_6_COMPxPOLARITY
#define COMP1_CSR_0_COMP1WM
#define COMP1_CSR_2_COMP2EN
#define COMP1_CSR_2_COMP2SPEED
#define COMP1_CSR_2_COMP1INNSEL
#define COMP1_CSR_2_COMP1VALUE
#define COMP1_CSR_3_COMP2INNSEL
#define COMP1_CSR_3_WINMODE
#define COMP1_CSR_4_COMP2INPSEL
#define COMP1_CSR_4_COMP1LPTIM1IN1
#define COMP1_CSR_4_COMP2LPTIM1IN1
#define COMP1_CSR_4_COMP1POLARITY
#define COMP1_CSR_4_COMP2VALUE
#define COMP1_CSR_5_COMP2LPTIM1IN2
#define COMP1_CSR_5_COMP2POLARITY
#define COMP1_CSR_5_COMPxOUTVALUE
#define COMP1_CSR_6_COMPxPOLARITY
#define COMP3_CSR_0_COMP1WM
#define COMP3_CSR_2_COMP1VALUE
#define COMP3_CSR_2_COMP1LOCK
#define COMP3_CSR_3_COMP2EN
#define COMP3_CSR_3_COMP2SPEED
#define COMP3_CSR_3_COMP1INNSEL
#define COMP3_CSR_3_WINMODE
#define COMP3_CSR_4_COMP2INNSEL
#define COMP3_CSR_4_COMP2INPSEL
#define COMP3_CSR_4_COMP1LPTIM1IN1
#define COMP3_CSR_4_COMP2LPTIM1IN1
#define COMP3_CSR_4_COMP1POLARITY
#define COMP3_CSR_4_COMP2VALUE
#define COMP3_CSR_5_COMP2LPTIM1IN2
#define COMP3_CSR_5_COMP2POLARITY
#define COMP3_CSR_5_COMPxOUTVALUE
#define COMP3_CSR_6_COMPxPOLARITY
#define COMP5_CSR_0_COMP1WM
#define COMP5_CSR_2_COMP1VALUE
#define COMP5_CSR_2_COMP1LOCK
#define COMP5_CSR_3_COMP2EN
#define COMP5_CSR_3_COMP2SPEED
#define COMP5_CSR_3_COMP1INNSEL
#define COMP5_CSR_3_WINMODE
#define COMP5_CSR_4_COMP2INNSEL
#define COMP5_CSR_4_COMP2INPSEL
#define COMP5_CSR_4_COMP1LPTIM1IN1
#define COMP5_CSR_4_COMP2LPTIM1IN1
#define COMP5_CSR_4_COMP1POLARITY
#define COMP5_CSR_4_COMP2VALUE
#define COMP5_CSR_5_COMP2LPTIM1IN2
#define COMP5_CSR_5_COMP2POLARITY
#define COMP5_CSR_5_COMPxOUTVALUE
#define COMP5_CSR_6_COMPxPOLARITY
#define COMP7_CSR_0_COMP1WM
#define COMP7_CSR_2_COMP1VALUE
#define COMP7_CSR_2_COMP1LOCK
#define COMP7_CSR_3_COMP2EN
#define COMP7_CSR_3_COMP2SPEED
#define COMP7_CSR_3_COMP1INNSEL
#define COMP7_CSR_3_WINMODE
#define COMP7_CSR_4_COMP2INNSEL
#define COMP7_CSR_4_COMP2INPSEL
#define COMP7_CSR_4_COMP1LPTIM1IN1
#define COMP7_CSR_4_COMP2LPTIM1IN1
#define COMP7_CSR_4_COMP1POLARITY
#define COMP7_CSR_4_COMP2VALUE
#define COMP7_CSR_5_COMP2LPTIM1IN2
#define COMP7_CSR_5_COMP2POLARITY
#define COMP7_CSR_5_COMPxOUTVALUE
#define COMP7_CSR_6_COMPxPOLARITY
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F398xx ) ||\
    defined(STM32L0     ) || defined(STM32L1     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define COMP_CSR_2
#endif

#if defined(STM32L4     ) || defined(STM32L4P    ) 
#define COMP_CSR_2_BRGEN     BRGEN                // 1 bits @ 22
#define COMP_CSR_2_SCALEN    SCALEN               // 1 bits @ 23
#define COMP_CSR_3_HYST      HYST                 // 2 bits @ 16
#define COMP_CSR_3_BLANKING  BLANKING             // 3 bits @ 18
#define COMP_CSR_4_EN        EN                   // 1 bits @ 0
#define COMP_CSR_4_PWRMODE   PWRMODE              // 2 bits @ 2
#define COMP_CSR_4_LOCK      LOCK                 // 1 bits @ 31
#define COMP_CSR_5_INMSEL    INMSEL               // 3 bits @ 4
#define COMP_CSR_5_WINMODE   WINMODE              // 1 bits @ 9
#define COMP_CSR_6
#define COMP2_CSR_0_BRGEN    BRGEN                // 1 bits @ 22
#define COMP2_CSR_1_SCALEN   SCALEN               // 1 bits @ 23
#define COMP2_CSR_4_EN       EN                   // 1 bits @ 0
#define COMP2_CSR_4_HYST     HYST                 // 2 bits @ 16
#define COMP2_CSR_4_BLANKING BLANKING             // 3 bits @ 18
#define COMP2_CSR_4_LOCK     LOCK                 // 1 bits @ 31
#define COMP2_CSR_5_PWRMODE  PWRMODE              // 2 bits @ 2
#define COMP2_CSR_5_WINMODE  WINMODE              // 1 bits @ 9
#define COMP2_CSR_6_INMSEL   INMSEL               // 3 bits @ 4
#define COMP2_CSR_6_VALUE    VALUE                // 1 bits @ 30
#define COMP2_CSR_7
#define COMP4_CSR_2_BRGEN    BRGEN                // 1 bits @ 22
#define COMP4_CSR_2_SCALEN   SCALEN               // 1 bits @ 23
#define COMP4_CSR_4_HYST     HYST                 // 2 bits @ 16
#define COMP4_CSR_4_BLANKING BLANKING             // 3 bits @ 18
#define COMP4_CSR_5_EN       EN                   // 1 bits @ 0
#define COMP4_CSR_5_PWRMODE  PWRMODE              // 2 bits @ 2
#define COMP4_CSR_5_WINMODE  WINMODE              // 1 bits @ 9
#define COMP4_CSR_5_LOCK     LOCK                 // 1 bits @ 31
#define COMP4_CSR_6_INMSEL   INMSEL               // 3 bits @ 4
#define COMP4_CSR_7
#define COMP6_CSR_2_BRGEN    BRGEN                // 1 bits @ 22
#define COMP6_CSR_2_SCALEN   SCALEN               // 1 bits @ 23
#define COMP6_CSR_4_HYST     HYST                 // 2 bits @ 16
#define COMP6_CSR_4_BLANKING BLANKING             // 3 bits @ 18
#define COMP6_CSR_5_EN       EN                   // 1 bits @ 0
#define COMP6_CSR_5_PWRMODE  PWRMODE              // 2 bits @ 2
#define COMP6_CSR_5_WINMODE  WINMODE              // 1 bits @ 9
#define COMP6_CSR_5_LOCK     LOCK                 // 1 bits @ 31
#define COMP6_CSR_6_INMSEL   INMSEL               // 3 bits @ 4
#define COMP6_CSR_7
#define COMP1_CSR_2_BRGEN    BRGEN                // 1 bits @ 22
#define COMP1_CSR_2_SCALEN   SCALEN               // 1 bits @ 23
#define COMP1_CSR_4_EN       EN                   // 1 bits @ 0
#define COMP1_CSR_4_PWRMODE  PWRMODE              // 2 bits @ 2
#define COMP1_CSR_4_HYST     HYST                 // 2 bits @ 16
#define COMP1_CSR_4_BLANKING BLANKING             // 3 bits @ 18
#define COMP1_CSR_4_LOCK     LOCK                 // 1 bits @ 31
#define COMP1_CSR_5_INMSEL   INMSEL               // 3 bits @ 4
#define COMP1_CSR_5_WINMODE  WINMODE              // 1 bits @ 9
#define COMP1_CSR_7
#define COMP3_CSR_2_BRGEN    BRGEN                // 1 bits @ 22
#define COMP3_CSR_2_SCALEN   SCALEN               // 1 bits @ 23
#define COMP3_CSR_4_HYST     HYST                 // 2 bits @ 16
#define COMP3_CSR_4_BLANKING BLANKING             // 3 bits @ 18
#define COMP3_CSR_5_EN       EN                   // 1 bits @ 0
#define COMP3_CSR_5_PWRMODE  PWRMODE              // 2 bits @ 2
#define COMP3_CSR_5_WINMODE  WINMODE              // 1 bits @ 9
#define COMP3_CSR_5_LOCK     LOCK                 // 1 bits @ 31
#define COMP3_CSR_6_INMSEL   INMSEL               // 3 bits @ 4
#define COMP3_CSR_7
#define COMP5_CSR_2_BRGEN    BRGEN                // 1 bits @ 22
#define COMP5_CSR_2_SCALEN   SCALEN               // 1 bits @ 23
#define COMP5_CSR_4_HYST     HYST                 // 2 bits @ 16
#define COMP5_CSR_4_BLANKING BLANKING             // 3 bits @ 18
#define COMP5_CSR_5_EN       EN                   // 1 bits @ 0
#define COMP5_CSR_5_PWRMODE  PWRMODE              // 2 bits @ 2
#define COMP5_CSR_5_WINMODE  WINMODE              // 1 bits @ 9
#define COMP5_CSR_5_LOCK     LOCK                 // 1 bits @ 31
#define COMP5_CSR_6_INMSEL   INMSEL               // 3 bits @ 4
#define COMP5_CSR_7
#define COMP7_CSR_2_BRGEN    BRGEN                // 1 bits @ 22
#define COMP7_CSR_2_SCALEN   SCALEN               // 1 bits @ 23
#define COMP7_CSR_4_HYST     HYST                 // 2 bits @ 16
#define COMP7_CSR_4_BLANKING BLANKING             // 3 bits @ 18
#define COMP7_CSR_5_EN       EN                   // 1 bits @ 0
#define COMP7_CSR_5_PWRMODE  PWRMODE              // 2 bits @ 2
#define COMP7_CSR_5_WINMODE  WINMODE              // 1 bits @ 9
#define COMP7_CSR_5_LOCK     LOCK                 // 1 bits @ 31
#define COMP7_CSR_6_INMSEL   INMSEL               // 3 bits @ 4
#define COMP7_CSR_7
#else
#define COMP_CSR_2_BRGEN
#define COMP_CSR_2_SCALEN
#define COMP_CSR_3_HYST
#define COMP_CSR_3_BLANKING
#define COMP_CSR_4_EN
#define COMP_CSR_4_PWRMODE
#define COMP_CSR_4_LOCK
#define COMP_CSR_5_INMSEL
#define COMP_CSR_5_WINMODE
#define COMP2_CSR_0_BRGEN
#define COMP2_CSR_1_SCALEN
#define COMP2_CSR_4_EN
#define COMP2_CSR_4_HYST
#define COMP2_CSR_4_BLANKING
#define COMP2_CSR_4_LOCK
#define COMP2_CSR_5_PWRMODE
#define COMP2_CSR_5_WINMODE
#define COMP2_CSR_6_INMSEL
#define COMP2_CSR_6_VALUE
#define COMP4_CSR_2_BRGEN
#define COMP4_CSR_2_SCALEN
#define COMP4_CSR_4_HYST
#define COMP4_CSR_4_BLANKING
#define COMP4_CSR_5_EN
#define COMP4_CSR_5_PWRMODE
#define COMP4_CSR_5_WINMODE
#define COMP4_CSR_5_LOCK
#define COMP4_CSR_6_INMSEL
#define COMP6_CSR_2_BRGEN
#define COMP6_CSR_2_SCALEN
#define COMP6_CSR_4_HYST
#define COMP6_CSR_4_BLANKING
#define COMP6_CSR_5_EN
#define COMP6_CSR_5_PWRMODE
#define COMP6_CSR_5_WINMODE
#define COMP6_CSR_5_LOCK
#define COMP6_CSR_6_INMSEL
#define COMP1_CSR_2_BRGEN
#define COMP1_CSR_2_SCALEN
#define COMP1_CSR_4_EN
#define COMP1_CSR_4_PWRMODE
#define COMP1_CSR_4_HYST
#define COMP1_CSR_4_BLANKING
#define COMP1_CSR_4_LOCK
#define COMP1_CSR_5_INMSEL
#define COMP1_CSR_5_WINMODE
#define COMP3_CSR_2_BRGEN
#define COMP3_CSR_2_SCALEN
#define COMP3_CSR_4_HYST
#define COMP3_CSR_4_BLANKING
#define COMP3_CSR_5_EN
#define COMP3_CSR_5_PWRMODE
#define COMP3_CSR_5_WINMODE
#define COMP3_CSR_5_LOCK
#define COMP3_CSR_6_INMSEL
#define COMP5_CSR_2_BRGEN
#define COMP5_CSR_2_SCALEN
#define COMP5_CSR_4_HYST
#define COMP5_CSR_4_BLANKING
#define COMP5_CSR_5_EN
#define COMP5_CSR_5_PWRMODE
#define COMP5_CSR_5_WINMODE
#define COMP5_CSR_5_LOCK
#define COMP5_CSR_6_INMSEL
#define COMP7_CSR_2_BRGEN
#define COMP7_CSR_2_SCALEN
#define COMP7_CSR_4_HYST
#define COMP7_CSR_4_BLANKING
#define COMP7_CSR_5_EN
#define COMP7_CSR_5_PWRMODE
#define COMP7_CSR_5_WINMODE
#define COMP7_CSR_5_LOCK
#define COMP7_CSR_6_INMSEL
#endif

#if defined(STM32L431xx ) || defined(STM32L432xx ) || defined(STM32L433xx ) || defined(STM32L442xx ) ||\
    defined(STM32L443xx ) || defined(STM32L451xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) 
#define COMP_CSR_2_INMESEL   INMESEL              // 2 bits @ 25
#define COMP_CSR_5_INPSEL    INPSEL               // 2 bits @ 7
#define COMP2_CSR_2_INMESEL  INMESEL              // 2 bits @ 25
#define COMP2_CSR_5_INPSEL   INPSEL               // 2 bits @ 7
#define COMP4_CSR_2_INMESEL  INMESEL              // 2 bits @ 25
#define COMP4_CSR_5_INPSEL   INPSEL               // 2 bits @ 7
#define COMP6_CSR_2_INMESEL  INMESEL              // 2 bits @ 25
#define COMP6_CSR_5_INPSEL   INPSEL               // 2 bits @ 7
#define COMP1_CSR_2_INMESEL  INMESEL              // 2 bits @ 25
#define COMP1_CSR_5_INPSEL   INPSEL               // 2 bits @ 7
#define COMP3_CSR_2_INMESEL  INMESEL              // 2 bits @ 25
#define COMP3_CSR_5_INPSEL   INPSEL               // 2 bits @ 7
#define COMP5_CSR_2_INMESEL  INMESEL              // 2 bits @ 25
#define COMP5_CSR_5_INPSEL   INPSEL               // 2 bits @ 7
#define COMP7_CSR_2_INMESEL  INMESEL              // 2 bits @ 25
#define COMP7_CSR_5_INPSEL   INPSEL               // 2 bits @ 7
#else
#define COMP_CSR_2_INMESEL
#define COMP_CSR_5_INPSEL
#define COMP2_CSR_2_INMESEL
#define COMP2_CSR_5_INPSEL
#define COMP4_CSR_2_INMESEL
#define COMP4_CSR_5_INPSEL
#define COMP6_CSR_2_INMESEL
#define COMP6_CSR_5_INPSEL
#define COMP1_CSR_2_INMESEL
#define COMP1_CSR_5_INPSEL
#define COMP3_CSR_2_INMESEL
#define COMP3_CSR_5_INPSEL
#define COMP5_CSR_2_INMESEL
#define COMP5_CSR_5_INPSEL
#define COMP7_CSR_2_INMESEL
#define COMP7_CSR_5_INPSEL
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F398xx ) ||\
    defined(STM32L0     ) 
#define COMP_CSR_2_COMPxLOCK COMPxLOCK            // 1 bits @ 31
#define COMP2_CSR_0_COMP2EN  COMP2EN              // 1 bits @ 0
#define COMP2_CSR_1_COMPxLOCK COMPxLOCK            // 1 bits @ 31
#define COMP4_CSR_3_COMPxLOCK COMPxLOCK            // 1 bits @ 31
#define COMP6_CSR_3_COMPxLOCK COMPxLOCK            // 1 bits @ 31
#define COMP1_CSR_3_COMPxLOCK COMPxLOCK            // 1 bits @ 31
#define COMP3_CSR_3_COMPxLOCK COMPxLOCK            // 1 bits @ 31
#define COMP5_CSR_3_COMPxLOCK COMPxLOCK            // 1 bits @ 31
#define COMP7_CSR_3_COMPxLOCK COMPxLOCK            // 1 bits @ 31
#else
#define COMP_CSR_2_COMPxLOCK
#define COMP2_CSR_0_COMP2EN
#define COMP2_CSR_1_COMPxLOCK
#define COMP4_CSR_3_COMPxLOCK
#define COMP6_CSR_3_COMPxLOCK
#define COMP1_CSR_3_COMPxLOCK
#define COMP3_CSR_3_COMPxLOCK
#define COMP5_CSR_3_COMPxLOCK
#define COMP7_CSR_3_COMPxLOCK
#endif

#if defined(STM32L0     ) || defined(STM32L1     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define COMP_CSR_3
#define COMP_CSR_4
#define COMP_CSR_5
#define COMP2_CSR_4
#define COMP2_CSR_5
#define COMP2_CSR_6
#define COMP4_CSR_4
#define COMP4_CSR_5
#define COMP4_CSR_6
#define COMP6_CSR_4
#define COMP6_CSR_5
#define COMP6_CSR_6
#define COMP1_CSR_4
#define COMP1_CSR_5
#define COMP3_CSR_4
#define COMP3_CSR_5
#define COMP3_CSR_6
#define COMP5_CSR_4
#define COMP5_CSR_5
#define COMP5_CSR_6
#define COMP7_CSR_4
#define COMP7_CSR_5
#define COMP7_CSR_6
#endif

#if defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define COMP_CSR_3_INPSEL    INPSEL               // 1 bits @ 7
#define COMP2_CSR_4_INPSEL   INPSEL               // 1 bits @ 7
#define COMP4_CSR_4_INPSEL   INPSEL               // 1 bits @ 7
#define COMP6_CSR_4_INPSEL   INPSEL               // 1 bits @ 7
#define COMP1_CSR_3_INPSEL   INPSEL               // 1 bits @ 7
#define COMP3_CSR_4_INPSEL   INPSEL               // 1 bits @ 7
#define COMP5_CSR_4_INPSEL   INPSEL               // 1 bits @ 7
#define COMP7_CSR_4_INPSEL   INPSEL               // 1 bits @ 7
#else
#define COMP_CSR_3_INPSEL
#define COMP2_CSR_4_INPSEL
#define COMP4_CSR_4_INPSEL
#define COMP6_CSR_4_INPSEL
#define COMP1_CSR_3_INPSEL
#define COMP3_CSR_4_INPSEL
#define COMP5_CSR_4_INPSEL
#define COMP7_CSR_4_INPSEL
#endif

#if defined(STM32L151xCA) || defined(STM32L151xD ) || defined(STM32L151xDx) || defined(STM32L151xE ) ||\
    defined(STM32L152xCA) || defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define COMP_CSR_4_SW1       SW1                  // 1 bits @ 5
#define COMP2_CSR_5_SW1      SW1                  // 1 bits @ 5
#define COMP4_CSR_5_SW1      SW1                  // 1 bits @ 5
#define COMP6_CSR_5_SW1      SW1                  // 1 bits @ 5
#define COMP1_CSR_4_SW1      SW1                  // 1 bits @ 5
#define COMP3_CSR_5_SW1      SW1                  // 1 bits @ 5
#define COMP5_CSR_5_SW1      SW1                  // 1 bits @ 5
#define COMP7_CSR_5_SW1      SW1                  // 1 bits @ 5
#else
#define COMP_CSR_4_SW1
#define COMP2_CSR_5_SW1
#define COMP4_CSR_5_SW1
#define COMP6_CSR_5_SW1
#define COMP1_CSR_4_SW1
#define COMP3_CSR_5_SW1
#define COMP5_CSR_5_SW1
#define COMP7_CSR_5_SW1
#endif

#define COMPOPT_ICFR
#define COMPOPT_OR
#define COMPOPT_SR

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F3     ) ||\
    defined(STM32L0     ) || defined(STM32L100xC ) || defined(STM32L151xC ) || defined(STM32L151xCA) ||\
    defined(STM32L151xD ) || defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xC ) ||\
    defined(STM32L152xCA) || defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) ||\
    defined(STM32L162xC ) || defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) ||\
    defined(STM32L162xE ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define COMP2_CSR_0
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F318xx ) 
#define COMP2_CSR_0_COMP2SW1 COMP2SW1             // 1 bits @ 1
#define COMP2_CSR_1_COMP2INPDAC COMP2INPDAC          // 1 bits @ 1
#else
#define COMP2_CSR_0_COMP2SW1
#define COMP2_CSR_1_COMP2INPDAC
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) || defined(STM32F358xx ) ||\
    defined(STM32F398xx ) 
#define COMP2_CSR_0_COMP2INSEL COMP2INSEL           // 3 bits @ 4
#define COMP4_CSR_0_COMP4INSEL COMP4INSEL           // 3 bits @ 4
#define COMP6_CSR_0_COMP6INSEL COMP6INSEL           // 3 bits @ 4
#else
#define COMP2_CSR_0_COMP2INSEL
#define COMP4_CSR_0_COMP4INSEL
#define COMP6_CSR_0_COMP6INSEL
#endif

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F3     ) 
#define COMP2_CSR_0_COMP2OUT COMP2OUT             // 1 bits @ 30
#else
#define COMP2_CSR_0_COMP2OUT
#endif

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F3     ) ||\
    defined(STM32L0     ) || defined(STM32L1     ) || defined(STM32L431xx ) || defined(STM32L432xx ) ||\
    defined(STM32L433xx ) || defined(STM32L442xx ) || defined(STM32L443xx ) || defined(STM32L451xx ) ||\
    defined(STM32L452xx ) || defined(STM32L462xx ) 
#define COMP2_CSR_2
#endif

#if defined(STM32F3     ) || defined(STM32L0     ) || defined(STM32L1     ) 
#define COMP2_CSR_3
#endif

#if defined(STM32F303xC ) || defined(STM32F358xx ) 
#define COMP4_CSR_0_COMP4WNDWEN COMP4WNDWEN          // 1 bits @ 9
#define COMP6_CSR_0_COMP6WNDWEN COMP6WNDWEN          // 1 bits @ 9
#define COMP3_CSR_0_COMP3MODE COMP3MODE            // 2 bits @ 2
#define COMP3_CSR_0_COMP3NONINSEL COMP3NONINSEL        // 1 bits @ 7
#define COMP3_CSR_0_COMP3HYST COMP3HYST            // 2 bits @ 16
#define COMP5_CSR_0_COMP5MODE COMP5MODE            // 2 bits @ 2
#define COMP5_CSR_0_COMP5NONINSEL COMP5NONINSEL        // 1 bits @ 7
#define COMP5_CSR_0_COMP5HYST COMP5HYST            // 2 bits @ 16
#define COMP7_CSR_0_COMP7MODE COMP7MODE            // 2 bits @ 2
#define COMP7_CSR_0_COMP7NONINSEL COMP7NONINSEL        // 1 bits @ 7
#define COMP7_CSR_0_COMP7HYST COMP7HYST            // 2 bits @ 16
#else
#define COMP4_CSR_0_COMP4WNDWEN
#define COMP6_CSR_0_COMP6WNDWEN
#define COMP3_CSR_0_COMP3MODE
#define COMP3_CSR_0_COMP3NONINSEL
#define COMP3_CSR_0_COMP3HYST
#define COMP5_CSR_0_COMP5MODE
#define COMP5_CSR_0_COMP5NONINSEL
#define COMP5_CSR_0_COMP5HYST
#define COMP7_CSR_0_COMP7MODE
#define COMP7_CSR_0_COMP7NONINSEL
#define COMP7_CSR_0_COMP7HYST
#endif

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F301x8 ) ||\
    defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F318xx ) || defined(STM32F358xx ) || defined(STM32F373xC ) ||\
    defined(STM32F378xx ) || defined(STM32F398xx ) || defined(STM32L0     ) || defined(STM32L1     ) 
#define COMP4_CSR_1
#define COMP6_CSR_1
#define COMP3_CSR_1
#define COMP5_CSR_1
#define COMP7_CSR_1
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F398xx ) ||\
    defined(STM32L0     ) || defined(STM32L1     ) 
#define COMP4_CSR_3
#define COMP6_CSR_3
#define COMP3_CSR_3
#define COMP5_CSR_3
#define COMP7_CSR_3
#endif

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F302xC ) ||\
    defined(STM32F302xE ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F358xx ) ||\
    defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F398xx ) || defined(STM32L0     ) 
#define COMP1_CSR_0
#endif

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F302xC ) ||\
    defined(STM32F302xE ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F358xx ) ||\
    defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F398xx ) 
#define COMP1_CSR_0_COMP1SW1 COMP1SW1             // 1 bits @ 1
#define COMP1_CSR_0_COMP1INSEL COMP1INSEL           // 3 bits @ 4
#else
#define COMP1_CSR_0_COMP1SW1
#define COMP1_CSR_0_COMP1INSEL
#endif

#if defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) || defined(STM32F303xE ) ||\
    defined(STM32F358xx ) || defined(STM32F398xx ) 
#define COMP1_CSR_0_COMP1OUTSEL COMP1OUTSEL          // 4 bits @ 10
#define COMP1_CSR_0_COMP1POL COMP1POL             // 1 bits @ 15
#define COMP1_CSR_0_COMP1BLANKING COMP1BLANKING        // 2 bits @ 18
#define COMP1_CSR_0_COMP1OUT COMP1OUT             // 1 bits @ 30
#else
#define COMP1_CSR_0_COMP1OUTSEL
#define COMP1_CSR_0_COMP1POL
#define COMP1_CSR_0_COMP1BLANKING
#define COMP1_CSR_0_COMP1OUT
#endif

#if defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) || defined(STM32F303xE ) ||\
    defined(STM32F358xx ) || defined(STM32F398xx ) || defined(STM32L0     ) 
#define COMP1_CSR_0_COMP1LOCK COMP1LOCK            // 1 bits @ 31
#else
#define COMP1_CSR_0_COMP1LOCK
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F398xx ) ||\
    defined(STM32L0     ) || defined(STM32L1     ) || defined(STM32L471xx ) || defined(STM32L475xx ) ||\
    defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define COMP1_CSR_3
#endif

#if defined(STM32L0     ) || defined(STM32L1     ) 
#define COMP1_CSR_6
#endif

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F302xC ) ||\
    defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F358xx ) || defined(STM32F373xC ) ||\
    defined(STM32F378xx ) || defined(STM32F398xx ) || defined(STM32L0     ) 
#define COMP3_CSR_0
#define COMP5_CSR_0
#define COMP7_CSR_0
#endif

#if defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F358xx ) || defined(STM32F398xx ) 
#define COMP3_CSR_0_COMP3EN  COMP3EN              // 1 bits @ 0
#define COMP3_CSR_0_COMP3INSEL COMP3INSEL           // 3 bits @ 4
#define COMP3_CSR_0_COMP3OUTSEL COMP3OUTSEL          // 4 bits @ 10
#define COMP3_CSR_0_COMP3POL COMP3POL             // 1 bits @ 15
#define COMP3_CSR_0_COMP3BLANKING COMP3BLANKING        // 2 bits @ 18
#define COMP3_CSR_0_COMP3OUT COMP3OUT             // 1 bits @ 30
#define COMP3_CSR_0_COMP3LOCK COMP3LOCK            // 1 bits @ 31
#define COMP5_CSR_0_COMP5EN  COMP5EN              // 1 bits @ 0
#define COMP5_CSR_0_COMP5INSEL COMP5INSEL           // 3 bits @ 4
#define COMP5_CSR_0_COMP5OUTSEL COMP5OUTSEL          // 4 bits @ 10
#define COMP5_CSR_0_COMP5POL COMP5POL             // 1 bits @ 15
#define COMP5_CSR_0_COMP5BLANKING COMP5BLANKING        // 2 bits @ 18
#define COMP5_CSR_0_COMP5OUT COMP5OUT             // 1 bits @ 30
#define COMP5_CSR_0_COMP5LOCK COMP5LOCK            // 1 bits @ 31
#define COMP7_CSR_0_COMP7EN  COMP7EN              // 1 bits @ 0
#define COMP7_CSR_0_COMP7INSEL COMP7INSEL           // 3 bits @ 4
#define COMP7_CSR_0_COMP7OUTSEL COMP7OUTSEL          // 4 bits @ 10
#define COMP7_CSR_0_COMP7POL COMP7POL             // 1 bits @ 15
#define COMP7_CSR_0_COMP7BLANKING COMP7BLANKING        // 2 bits @ 18
#define COMP7_CSR_0_COMP7OUT COMP7OUT             // 1 bits @ 30
#define COMP7_CSR_0_COMP7LOCK COMP7LOCK            // 1 bits @ 31
#else
#define COMP3_CSR_0_COMP3EN
#define COMP3_CSR_0_COMP3INSEL
#define COMP3_CSR_0_COMP3OUTSEL
#define COMP3_CSR_0_COMP3POL
#define COMP3_CSR_0_COMP3BLANKING
#define COMP3_CSR_0_COMP3OUT
#define COMP3_CSR_0_COMP3LOCK
#define COMP5_CSR_0_COMP5EN
#define COMP5_CSR_0_COMP5INSEL
#define COMP5_CSR_0_COMP5OUTSEL
#define COMP5_CSR_0_COMP5POL
#define COMP5_CSR_0_COMP5BLANKING
#define COMP5_CSR_0_COMP5OUT
#define COMP5_CSR_0_COMP5LOCK
#define COMP7_CSR_0_COMP7EN
#define COMP7_CSR_0_COMP7INSEL
#define COMP7_CSR_0_COMP7OUTSEL
#define COMP7_CSR_0_COMP7POL
#define COMP7_CSR_0_COMP7BLANKING
#define COMP7_CSR_0_COMP7OUT
#define COMP7_CSR_0_COMP7LOCK
#endif

//endregion

namespace sool
{
	namespace core
	{struct COMP_base_plugin
		{
		
			#ifdef COMP_CSR
			struct CSR_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
			
				union
				{
					#ifdef COMP_CSR_0
					struct
					{
						uint32_t COMP_CSR_0_COMP1EN   :1;
						uint32_t COMP_CSR_0_COMP1SW1  :1;
						uint32_t COMP_CSR_0_COMP1MODE :2;
						uint32_t COMP_CSR_0_COMP1INSEL :3;
						uint32_t COMP_CSR_0_COMPxNONINSEL :1;
						uint32_t COMP_CSR_0_COMP1OUTSEL :3;
						uint32_t COMP_CSR_0_COMP1POL  :1;
						uint32_t COMP_CSR_0_COMP1HYST :2;
						uint32_t COMP_CSR_0_COMP1OUT  :1;
						uint32_t COMP_CSR_0_COMP1LOCK :1;
						uint32_t COMP_CSR_0_COMP2EN   :1;
						uint32_t COMP_CSR_0_WNDWE     :1;
						uint32_t COMP_CSR_0_COMP2MODE :2;
						uint32_t COMP_CSR_0_COMP2INSEL :3;
						uint32_t COMP_CSR_0_WNDWEN    :1;
						uint32_t COMP_CSR_0_COMP2OUTSEL :3;
						uint32_t COMP_CSR_0_COMP2POL  :1;
						uint32_t COMP_CSR_0_COMP2HYST :2;
						uint32_t COMP_CSR_0_COMP2OUT  :1;
						uint32_t COMP_CSR_0_COMP2LOCK :1;
					};
					#endif
					#ifdef COMP_CSR_1
					struct
					{
						uint32_t COMP_CSR_1_COMPxEN   :1;
						uint32_t COMP_CSR_1_COMPxSW1  :1;
						uint32_t COMP_CSR_1_COMPxMODE :2;
						uint32_t COMP_CSR_1_COMPxINSEL :3;
						uint32_t COMP_CSR_1_COMPxWNDWEN :1;
						uint32_t COMP_CSR_1_COMPxOUTSEL :3;
						uint32_t COMP_CSR_1_COMPxPOL  :1;
						uint32_t COMP_CSR_1_COMPxHYST :2;
						uint32_t COMP_CSR_1_COMPxOUT  :1;
						uint32_t COMP_CSR_1_COMPxLOCK :1;
						uint32_t COMP_CSR_1_VREFOUTEN :1;
						uint32_t                      :1;
						uint32_t COMP_CSR_1_COMPxBLANKING :2;
						uint32_t                      :1;
						uint32_t COMP_CSR_1_OUTSEL    :3;
						uint32_t                      :2;
						uint32_t COMP_CSR_1_FCH3      :1;
						uint32_t COMP_CSR_1_FCH8      :1;
						uint32_t COMP_CSR_1_RCH13     :1;
						uint32_t COMP_CSR_1_CAIE      :1;
						uint32_t COMP_CSR_1_COMP1VALUE :1;
						uint32_t COMP_CSR_1_COMP1LOCK :1;
					};
					#endif
					#ifdef COMP_CSR_2
					struct
					{
						uint32_t COMP_CSR_2_COMP2EN   :1;
						uint32_t COMP_CSR_2_CS400KPU  :1;
						uint32_t COMP_CSR_2_CS10KPD   :1;
						uint32_t COMP_CSR_2_COMP2SPEED :1;
						uint32_t COMP_CSR_2_COMP1INNSEL :2;
						uint32_t                      :1;
						uint32_t COMP_CSR_2_CMP1OUT   :1;
						uint32_t COMP_CSR_2_COMP1WM   :1;
						uint32_t COMP_CSR_2_COMPxWNDWEN :1;
						uint32_t COMP_CSR_2_COMPxOUTSEL :4;
						uint32_t                      :1;
						uint32_t COMP_CSR_2_COMPxPOL  :1;
						uint32_t COMP_CSR_2_COMPxHYST :2;
						uint32_t COMP_CSR_2_INSEL     :3;
						uint32_t                      :1;
						uint32_t COMP_CSR_2_BRGEN     :1;
						uint32_t COMP_CSR_2_SCALEN    :1;
						uint32_t                      :1;
						uint32_t COMP_CSR_2_INMESEL   :2;
						uint32_t                      :3;
						uint32_t COMP_CSR_2_COMPxOUT  :1;
						uint32_t COMP_CSR_2_COMPxLOCK :1;
					};
					#endif
					#ifdef COMP_CSR_3
					struct
					{
						uint32_t COMP_CSR_3_CS10KPU   :1;
						uint32_t                      :2;
						uint32_t COMP_CSR_3_CS400KPD  :1;
						uint32_t COMP_CSR_3_COMP2INNSEL :3;
						uint32_t COMP_CSR_3_INPSEL    :1;
						uint32_t COMP_CSR_3_COMP2INPSEL :3;
						uint32_t                      :1;
						uint32_t COMP_CSR_3_COMP1LPTIM1IN1 :1;
						uint32_t COMP_CSR_3_COMP2LPTIM1IN1 :1;
						uint32_t                      :1;
						uint32_t COMP_CSR_3_COMP1POLARITY :1;
						uint32_t COMP_CSR_3_HYST      :2;
						uint32_t COMP_CSR_3_BLANKING  :3;
						uint32_t                      :9;
						uint32_t COMP_CSR_3_COMP2VALUE :1;
						uint32_t COMP_CSR_3_TSUSP     :1;
					};
					#endif
					#ifdef COMP_CSR_4
					struct
					{
						uint32_t COMP_CSR_4_EN        :1;
						uint32_t                      :1;
						uint32_t COMP_CSR_4_PWRMODE   :2;
						uint32_t COMP_CSR_4_CMP1EN    :1;
						uint32_t COMP_CSR_4_SW1       :1;
						uint32_t                      :2;
						uint32_t COMP_CSR_4_WINMODE   :1;
						uint32_t                      :3;
						uint32_t COMP_CSR_4_COMP2LPTIM1IN2 :1;
						uint32_t COMP_CSR_4_CMP2OUT   :1;
						uint32_t                      :1;
						uint32_t COMP_CSR_4_COMP2POLARITY :1;
						uint32_t                      :14;
						uint32_t COMP_CSR_4_COMPxOUTVALUE :1;
						uint32_t COMP_CSR_4_LOCK      :1;
					};
					#endif
					#ifdef COMP_CSR_5
					struct
					{
						uint32_t                      :4;
						uint32_t COMP_CSR_5_INMSEL    :3;
						uint32_t COMP_CSR_5_INPSEL    :2;
						uint32_t COMP_CSR_5_WINMODE   :1;
						uint32_t                      :2;
						uint32_t COMP_CSR_5_SPEED     :1;
						uint32_t                      :2;
						uint32_t COMP_CSR_5_COMPxPOLARITY :1;
						uint32_t                      :14;
						uint32_t COMP_CSR_5_CAIF      :1;
						uint32_t                      :1;
					};
					#endif
					#ifdef COMP_CSR_6
					struct
					{
						uint32_t                      :15;
						uint32_t POLARITY             :1;
						uint32_t                      :14;
						uint32_t VALUE                :1;
						uint32_t                      :1;
					};
					#endif
				};
				//SOOL-COMP_CSR-DECLARATION
			};
			#endif
			};
		template<typename plugin=COMP_base_plugin>
		class COMP
		{
			//SOOL-COMP-ENUMS
			
			public :
			
			#ifdef COMP_CFGR
			struct CFGR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EN                   :1;
					uint32_t BRGEN                :1;
					uint32_t SCALEN               :1;
					uint32_t POLARITY             :1;
					uint32_t WINMODE              :1;
					uint32_t                      :1;
					uint32_t ITEN                 :1;
					uint32_t                      :1;
					uint32_t HYST                 :2;
					uint32_t                      :2;
					uint32_t PWRMODE              :2;
					uint32_t                      :2;
					uint32_t INMSEL               :3;
					uint32_t                      :1;
					uint32_t INPSEL               :1;
					uint32_t                      :3;
					uint32_t BLANKING             :4;
					uint32_t                      :3;
					uint32_t LOCK                 :1;
			
				//SOOL-COMP_CFGR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					COMP_MAP0_CSR;       // @0x000
				};
				struct
				{
					COMP_MAP1_CFGR;      // @0x000
				};
			};
			private:
			COMP() = delete;
			//SOOL-COMP-DECLARATION
		};
		
		
		class COMPOPT
		{
			//SOOL-COMPOPT-ENUMS
			
			public :
			
			#ifdef COMPOPT_ICFR
			struct ICFR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :16;
					uint32_t C1IF                 :1;
					uint32_t C2IF                 :1;
					uint32_t                      :14;
			
				//SOOL-COMPOPT_ICFR-DECLARATION
			};
			#endif
			
			#ifdef COMPOPT_OR
			struct OR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t AFOPA6               :1;
					uint32_t AFOPA8               :1;
					uint32_t AFOPB12              :1;
					uint32_t AFOPE6               :1;
					uint32_t AFOPE15              :1;
					uint32_t AFOPG2               :1;
					uint32_t AFOPG3               :1;
					uint32_t AFOPG4               :1;
					uint32_t AFOPI1               :1;
					uint32_t AFOPI4               :1;
					uint32_t AFOPK2               :1;
					uint32_t                      :21;
			
				//SOOL-COMPOPT_OR-DECLARATION
			};
			#endif
			
			#ifdef COMPOPT_SR
			struct SR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t C1VAL                :1;
					uint32_t C2VAL                :1;
					uint32_t                      :14;
					uint32_t C1IF                 :1;
					uint32_t C2IF                 :1;
					uint32_t                      :14;
			
				//SOOL-COMPOPT_SR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					SR_TypeDef SR;       // @0x000
					ICFR_TypeDef ICFR;   // @0x004
					OR_TypeDef OR;       // @0x008
				};
			};
			private:
			COMPOPT() = delete;
			//SOOL-COMPOPT-DECLARATION
		};
		
		//region instances
#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F302xC ) ||\
    defined(STM32F302xE ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F358xx ) ||\
    defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F398xx ) 
#define COMP1_BASE_ADDR ((uint32_t)0x4001001CU)
#endif

#if defined(STM32H7     ) 
#define COMP1_BASE_ADDR ((uint32_t)0x5800380CU)
#define COMP2_BASE_ADDR ((uint32_t)0x58003810U)
#define COMP12_BASE_ADDR ((uint32_t)0x58003800U)
#endif

#if defined(STM32L0     ) 
#define COMP1_BASE_ADDR ((uint32_t)0x40010018U)
#define COMP2_BASE_ADDR ((uint32_t)0x4001001CU)
#endif

#if defined(STM32L1     ) 
#define COMP1_BASE_ADDR ((uint32_t)0x40007C00U)
#define COMP_BASE_ADDR ((uint32_t)0x40007C00U)
#endif

#if defined(STM32L4     ) || defined(STM32L4P    ) 
#define COMP1_BASE_ADDR ((uint32_t)0x40010200U)
#define COMP2_BASE_ADDR ((uint32_t)0x40010204U)
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F303x8 ) || defined(STM32F318xx ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) 
#define COMP_BASE_ADDR ((uint32_t)0x40010020U)
#endif

#if defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) || defined(STM32F303xE ) ||\
    defined(STM32F358xx ) || defined(STM32F398xx ) 
#define COMP_BASE_ADDR ((uint32_t)0x4001001CU)
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F398xx ) 
#define COMP2_BASE_ADDR ((uint32_t)0x40010020U)
#define COMP4_BASE_ADDR ((uint32_t)0x40010028U)
#define COMP6_BASE_ADDR ((uint32_t)0x40010030U)
#endif

#if defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F358xx ) || defined(STM32F398xx ) 
#define COMP3_BASE_ADDR ((uint32_t)0x40010024U)
#define COMP5_BASE_ADDR ((uint32_t)0x4001002CU)
#define COMP7_BASE_ADDR ((uint32_t)0x40010034U)
#endif

#ifdef COMP1_BASE_ADDR
struct COMP1_plugin: COMP_base_plugin {
	
	#ifdef COMP_CSR
	struct CSR_TypeDef : public Reg16_t
	{
		using Reg16_t::operator=;
	
		union
		{
			#ifdef COMP1_CSR_0
			struct
			{
				uint32_t COMP1EN              :1;
				uint32_t COMP1_CSR_0_COMP1SW1 :1;
				uint32_t COMP1_CSR_0_COMP1MODE :2;
				uint32_t COMP1_CSR_0_COMP1INSEL :3;
				uint32_t COMP1_CSR_0_COMPxNONINSEL :1;
				uint32_t COMP1_CSR_0_COMP1WM  :1;
				uint32_t COMP1_CSR_0_COMPxWNDWEN :1;
				uint32_t COMP1_CSR_0_COMP1OUTSEL :4;
				uint32_t COMP1_CSR_0_COMPxOUT :1;
				uint32_t COMP1_CSR_0_COMP1POL :1;
				uint32_t COMP1_CSR_0_COMP1HYST :2;
				uint32_t COMP1_CSR_0_COMP1BLANKING :2;
				uint32_t COMP1_CSR_0_COMP2INSEL :3;
				uint32_t COMP1_CSR_0_WNDWEN   :1;
				uint32_t COMP1_CSR_0_COMP2OUTSEL :3;
				uint32_t COMP1_CSR_0_COMP2POL :1;
				uint32_t COMP1_CSR_0_COMP2HYST :2;
				uint32_t COMP1_CSR_0_COMP1OUT :1;
				uint32_t COMP1_CSR_0_COMP1LOCK :1;
			};
			#endif
			#ifdef COMP1_CSR_1
			struct
			{
				uint32_t COMP1_CSR_1_COMPxEN  :1;
				uint32_t COMP1_CSR_1_COMPxSW1 :1;
				uint32_t COMP1_CSR_1_COMPxMODE :2;
				uint32_t COMP1_CSR_1_COMPxINSEL :3;
				uint32_t COMP1_CSR_1_COMPxWNDWEN :1;
				uint32_t COMP1_CSR_1_COMP1OUTSEL :3;
				uint32_t COMP1_CSR_1_COMP1POL :1;
				uint32_t COMP1_CSR_1_COMP1HYST :2;
				uint32_t COMP1_CSR_1_COMP1OUT :1;
				uint32_t COMP1_CSR_1_COMP1LOCK :1;
				uint32_t COMP1_CSR_1_COMP2EN  :1;
				uint32_t COMP1_CSR_1_WNDWE    :1;
				uint32_t COMP1_CSR_1_COMP2MODE :2;
				uint32_t                      :1;
				uint32_t COMP1_CSR_1_OUTSEL   :3;
				uint32_t                      :2;
				uint32_t COMP1_CSR_1_FCH3     :1;
				uint32_t COMP1_CSR_1_FCH8     :1;
				uint32_t COMP1_CSR_1_RCH13    :1;
				uint32_t COMP1_CSR_1_CAIE     :1;
				uint32_t COMP1_CSR_1_COMP2OUT :1;
				uint32_t COMP1_CSR_1_COMP2LOCK :1;
			};
			#endif
			struct
			{
				uint32_t COMP1_CSR_2_COMP2EN  :1;
				uint32_t COMP1_CSR_2_CS400KPU :1;
				uint32_t COMP1_CSR_2_CS10KPD  :1;
				uint32_t COMP1_CSR_2_COMP2SPEED :1;
				uint32_t COMP1_CSR_2_COMP1INNSEL :2;
				uint32_t                      :1;
				uint32_t COMP1_CSR_2_CMP1OUT  :1;
				uint32_t COMP1_CSR_2_COMPxOUTSEL :3;
				uint32_t COMP1_CSR_2_COMPxPOL :1;
				uint32_t COMP1_CSR_2_COMPxHYST :2;
				uint32_t                      :1;
				uint32_t COMP1_CSR_2_COMPxLOCK :1;
				uint32_t COMP1_CSR_2_VREFOUTEN :1;
				uint32_t                      :1;
				uint32_t COMP1_CSR_2_COMPxBLANKING :2;
				uint32_t                      :2;
				uint32_t COMP1_CSR_2_BRGEN    :1;
				uint32_t COMP1_CSR_2_SCALEN   :1;
				uint32_t                      :1;
				uint32_t COMP1_CSR_2_INMESEL  :2;
				uint32_t                      :3;
				uint32_t COMP1_CSR_2_COMP1VALUE :1;
				uint32_t COMP1_CSR_2_TSUSP    :1;
			};
			#ifdef COMP1_CSR_3
			struct
			{
				uint32_t COMP1_CSR_3_CS10KPU  :1;
				uint32_t                      :2;
				uint32_t COMP1_CSR_3_CS400KPD :1;
				uint32_t COMP1_CSR_3_COMP2INNSEL :3;
				uint32_t COMP1_CSR_3_INPSEL   :1;
				uint32_t COMP1_CSR_3_WINMODE  :1;
				uint32_t                      :1;
				uint32_t COMP1_CSR_3_COMPxOUTSEL :4;
				uint32_t                      :1;
				uint32_t COMP1_CSR_3_COMPxPOL :1;
				uint32_t COMP1_CSR_3_COMPxHYST :2;
				uint32_t COMP1_CSR_3_INSEL    :3;
				uint32_t                      :9;
				uint32_t COMP1_CSR_3_COMPxOUT :1;
				uint32_t COMP1_CSR_3_COMPxLOCK :1;
			};
			#endif
			#ifdef COMP1_CSR_4
			struct
			{
				uint32_t COMP1_CSR_4_EN       :1;
				uint32_t                      :1;
				uint32_t COMP1_CSR_4_PWRMODE  :2;
				uint32_t COMP1_CSR_4_CMP1EN   :1;
				uint32_t COMP1_CSR_4_SW1      :1;
				uint32_t                      :2;
				uint32_t COMP1_CSR_4_COMP2INPSEL :3;
				uint32_t                      :1;
				uint32_t COMP1_CSR_4_COMP1LPTIM1IN1 :1;
				uint32_t COMP1_CSR_4_COMP2LPTIM1IN1 :1;
				uint32_t                      :1;
				uint32_t COMP1_CSR_4_COMP1POLARITY :1;
				uint32_t COMP1_CSR_4_HYST     :2;
				uint32_t COMP1_CSR_4_BLANKING :3;
				uint32_t                      :9;
				uint32_t COMP1_CSR_4_COMP2VALUE :1;
				uint32_t COMP1_CSR_4_LOCK     :1;
			};
			#endif
			#ifdef COMP1_CSR_5
			struct
			{
				uint32_t                      :4;
				uint32_t COMP1_CSR_5_INMSEL   :3;
				uint32_t COMP1_CSR_5_INPSEL   :2;
				uint32_t COMP1_CSR_5_WINMODE  :1;
				uint32_t                      :2;
				uint32_t COMP1_CSR_5_COMP2LPTIM1IN2 :1;
				uint32_t COMP1_CSR_5_CMP2OUT  :1;
				uint32_t                      :1;
				uint32_t COMP1_CSR_5_COMP2POLARITY :1;
				uint32_t                      :14;
				uint32_t COMP1_CSR_5_COMPxOUTVALUE :1;
				uint32_t                      :1;
			};
			#endif
			#ifdef COMP1_CSR_6
			struct
			{
				uint32_t                      :12;
				uint32_t COMP1_CSR_6_SPEED    :1;
				uint32_t                      :2;
				uint32_t COMP1_CSR_6_COMPxPOLARITY :1;
				uint32_t                      :14;
				uint32_t COMP1_CSR_6_CAIF     :1;
				uint32_t                      :1;
			};
			#endif
			#ifdef COMP1_CSR_7
			struct
			{
				uint32_t                      :15;
				uint32_t POLARITY             :1;
				uint32_t                      :14;
				uint32_t VALUE                :1;
				uint32_t                      :1;
			};
			#endif
		};
		//SOOL-COMP_CSR-DECLARATION
	};
	#endif
	
};
volatile class COMP<COMP1_plugin>* const COMP1 =reinterpret_cast<class COMP<COMP1_plugin>* const>(COMP1_BASE_ADDR);
#endif
#ifdef COMP2_BASE_ADDR
struct COMP2_plugin: COMP_base_plugin {
	
	#ifdef COMP_CSR
	struct CSR_TypeDef : public Reg16_t
	{
		using Reg16_t::operator=;
	
		union
		{
			#ifdef COMP2_CSR_0
			struct
			{
				uint32_t COMP2_CSR_0_COMP2EN  :1;
				uint32_t COMP2_CSR_0_COMP2SW1 :1;
				uint32_t COMP2_CSR_0_COMP2MODE :2;
				uint32_t COMP2_CSR_0_COMP2INSEL :3;
				uint32_t COMP2_CSR_0_COMP2NONINSEL :1;
				uint32_t COMP2_CSR_0_COMP1WM  :1;
				uint32_t COMP2_CSR_0_COMP2WNDWEN :1;
				uint32_t COMP2_CSR_0_COMP2OUTSEL :4;
				uint32_t COMP2_CSR_0_COMP1OUT :1;
				uint32_t COMP2_CSR_0_COMP2POL :1;
				uint32_t COMP2_CSR_0_COMP2HYST :2;
				uint32_t COMP2_CSR_0_COMP2BLANKING :2;
				uint32_t                      :2;
				uint32_t COMP2_CSR_0_BRGEN    :1;
				uint32_t COMP2_CSR_0_WNDWEN   :1;
				uint32_t                      :2;
				uint32_t COMP2_CSR_0_FCH3     :1;
				uint32_t COMP2_CSR_0_FCH8     :1;
				uint32_t COMP2_CSR_0_RCH13    :1;
				uint32_t COMP2_CSR_0_CAIE     :1;
				uint32_t COMP2_CSR_0_COMP2OUT :1;
				uint32_t COMP2_CSR_0_COMP2LOCK :1;
			};
			#endif
			struct
			{
				uint32_t COMP2_CSR_1_COMP1EN  :1;
				uint32_t COMP2_CSR_1_COMP2INPDAC :1;
				uint32_t COMP2_CSR_1_COMP1MODE :2;
				uint32_t COMP2_CSR_1_COMP1INSEL :3;
				uint32_t COMP2_CSR_1_COMPxNONINSEL :1;
				uint32_t COMP2_CSR_1_COMP1OUTSEL :3;
				uint32_t COMP2_CSR_1_COMP1POL :1;
				uint32_t COMP2_CSR_1_COMP1HYST :2;
				uint32_t COMP2_CSR_1_COMPxOUT :1;
				uint32_t COMP2_CSR_1_COMP1LOCK :1;
				uint32_t COMP2_CSR_1_COMP2EN  :1;
				uint32_t COMP2_CSR_1_WNDWE    :1;
				uint32_t COMP2_CSR_1_COMP2MODE :2;
				uint32_t COMP2_CSR_1_COMP2INSEL :3;
				uint32_t COMP2_CSR_1_SCALEN   :1;
				uint32_t COMP2_CSR_1_COMP2OUTSEL :3;
				uint32_t COMP2_CSR_1_COMP2POL :1;
				uint32_t COMP2_CSR_1_COMP2HYST :2;
				uint32_t COMP2_CSR_1_COMP1VALUE :1;
				uint32_t COMP2_CSR_1_COMPxLOCK :1;
			};
			#ifdef COMP2_CSR_2
			struct
			{
				uint32_t COMP2_CSR_2_COMPxEN  :1;
				uint32_t COMP2_CSR_2_COMP1SW1 :1;
				uint32_t COMP2_CSR_2_COMPxMODE :2;
				uint32_t COMP2_CSR_2_COMPxINSEL :3;
				uint32_t COMP2_CSR_2_COMPxWNDWEN :1;
				uint32_t COMP2_CSR_2_COMPxOUTSEL :3;
				uint32_t COMP2_CSR_2_COMPxPOL :1;
				uint32_t COMP2_CSR_2_COMPxHYST :2;
				uint32_t                      :1;
				uint32_t COMP2_CSR_2_COMPxLOCK :1;
				uint32_t COMP2_CSR_2_VREFOUTEN :1;
				uint32_t                      :1;
				uint32_t COMP2_CSR_2_COMPxBLANKING :2;
				uint32_t                      :1;
				uint32_t COMP2_CSR_2_OUTSEL   :3;
				uint32_t                      :1;
				uint32_t COMP2_CSR_2_INMESEL  :2;
				uint32_t                      :3;
				uint32_t COMP2_CSR_2_COMPxOUT :1;
				uint32_t COMP2_CSR_2_COMP1LOCK :1;
			};
			#endif
			#ifdef COMP2_CSR_3
			struct
			{
				uint32_t COMP2_CSR_3_CS10KPU  :1;
				uint32_t COMP2_CSR_3_COMPxSW1 :1;
				uint32_t COMP2_CSR_3_CS10KPD  :1;
				uint32_t COMP2_CSR_3_COMP2SPEED :1;
				uint32_t COMP2_CSR_3_COMP1INNSEL :2;
				uint32_t                      :1;
				uint32_t COMP2_CSR_3_CMP1OUT  :1;
				uint32_t COMP2_CSR_3_WINMODE  :1;
				uint32_t COMP2_CSR_3_COMPxWNDWEN :1;
				uint32_t COMP2_CSR_3_COMPxOUTSEL :4;
				uint32_t                      :1;
				uint32_t COMP2_CSR_3_COMPxPOL :1;
				uint32_t COMP2_CSR_3_COMPxHYST :2;
				uint32_t COMP2_CSR_3_INSEL    :3;
				uint32_t                      :9;
				uint32_t COMP2_CSR_3_COMP2VALUE :1;
				uint32_t COMP2_CSR_3_TSUSP    :1;
			};
			#endif
			#ifdef COMP2_CSR_4
			struct
			{
				uint32_t COMP2_CSR_4_EN       :1;
				uint32_t COMP2_CSR_4_CS400KPU :1;
				uint32_t                      :1;
				uint32_t COMP2_CSR_4_CS400KPD :1;
				uint32_t COMP2_CSR_4_COMP2INNSEL :3;
				uint32_t COMP2_CSR_4_INPSEL   :1;
				uint32_t COMP2_CSR_4_COMP2INPSEL :3;
				uint32_t                      :1;
				uint32_t COMP2_CSR_4_COMP1LPTIM1IN1 :1;
				uint32_t COMP2_CSR_4_COMP2LPTIM1IN1 :1;
				uint32_t                      :1;
				uint32_t COMP2_CSR_4_COMP1POLARITY :1;
				uint32_t COMP2_CSR_4_HYST     :2;
				uint32_t COMP2_CSR_4_BLANKING :3;
				uint32_t                      :9;
				uint32_t COMP2_CSR_4_COMPxOUTVALUE :1;
				uint32_t COMP2_CSR_4_LOCK     :1;
			};
			#endif
			#ifdef COMP2_CSR_5
			struct
			{
				uint32_t                      :2;
				uint32_t COMP2_CSR_5_PWRMODE  :2;
				uint32_t COMP2_CSR_5_CMP1EN   :1;
				uint32_t COMP2_CSR_5_SW1      :1;
				uint32_t                      :1;
				uint32_t COMP2_CSR_5_INPSEL   :2;
				uint32_t COMP2_CSR_5_WINMODE  :1;
				uint32_t                      :2;
				uint32_t COMP2_CSR_5_COMP2LPTIM1IN2 :1;
				uint32_t COMP2_CSR_5_CMP2OUT  :1;
				uint32_t                      :1;
				uint32_t COMP2_CSR_5_COMP2POLARITY :1;
				uint32_t                      :14;
				uint32_t COMP2_CSR_5_CAIF     :1;
				uint32_t                      :1;
			};
			#endif
			#ifdef COMP2_CSR_6
			struct
			{
				uint32_t                      :4;
				uint32_t COMP2_CSR_6_INMSEL   :3;
				uint32_t                      :5;
				uint32_t COMP2_CSR_6_SPEED    :1;
				uint32_t                      :2;
				uint32_t COMP2_CSR_6_COMPxPOLARITY :1;
				uint32_t                      :14;
				uint32_t COMP2_CSR_6_VALUE    :1;
				uint32_t                      :1;
			};
			#endif
			#ifdef COMP2_CSR_7
			struct
			{
				uint32_t                      :15;
				uint32_t POLARITY             :1;
				uint32_t                      :16;
			};
			#endif
		};
		//SOOL-COMP_CSR-DECLARATION
	};
	#endif
	
};
volatile class COMP<COMP2_plugin>* const COMP2 =reinterpret_cast<class COMP<COMP2_plugin>* const>(COMP2_BASE_ADDR);
#endif
#ifdef COMP12_BASE_ADDR
volatile class COMPOPT * const COMP12 = reinterpret_cast<class COMPOPT* const>(COMP12_BASE_ADDR);
#endif
#ifdef COMP_BASE_ADDR
volatile class COMP<>* const COMP =reinterpret_cast<class COMP<>* const>(COMP_BASE_ADDR);
#endif
#ifdef COMP4_BASE_ADDR
struct COMP4_plugin: COMP_base_plugin {
	
	#ifdef COMP_CSR
	struct CSR_TypeDef : public Reg16_t
	{
		using Reg16_t::operator=;
	
		union
		{
			#ifdef COMP4_CSR_0
			struct
			{
				uint32_t COMP4_CSR_0_COMP4EN  :1;
				uint32_t COMP4_CSR_0_COMP1SW1 :1;
				uint32_t COMP4_CSR_0_COMP4MODE :2;
				uint32_t COMP4_CSR_0_COMP4INSEL :3;
				uint32_t COMP4_CSR_0_COMP4NONINSEL :1;
				uint32_t COMP4_CSR_0_COMP1WM  :1;
				uint32_t COMP4_CSR_0_COMP4WNDWEN :1;
				uint32_t COMP4_CSR_0_COMP4OUTSEL :4;
				uint32_t COMP4_CSR_0_COMP1OUT :1;
				uint32_t COMP4_CSR_0_COMP4POL :1;
				uint32_t COMP4_CSR_0_COMP4HYST :2;
				uint32_t COMP4_CSR_0_COMP4BLANKING :2;
				uint32_t COMP4_CSR_0_COMP2INSEL :3;
				uint32_t COMP4_CSR_0_WNDWEN   :1;
				uint32_t COMP4_CSR_0_COMP2OUTSEL :3;
				uint32_t COMP4_CSR_0_COMP2POL :1;
				uint32_t COMP4_CSR_0_COMP2HYST :2;
				uint32_t COMP4_CSR_0_COMP4OUT :1;
				uint32_t COMP4_CSR_0_COMP4LOCK :1;
			};
			#endif
			#ifdef COMP4_CSR_1
			struct
			{
				uint32_t COMP4_CSR_1_COMP1EN  :1;
				uint32_t COMP4_CSR_1_COMPxSW1 :1;
				uint32_t COMP4_CSR_1_COMP1MODE :2;
				uint32_t COMP4_CSR_1_COMP1INSEL :3;
				uint32_t COMP4_CSR_1_COMPxNONINSEL :1;
				uint32_t COMP4_CSR_1_COMP1OUTSEL :3;
				uint32_t COMP4_CSR_1_COMP1POL :1;
				uint32_t COMP4_CSR_1_COMP1HYST :2;
				uint32_t COMP4_CSR_1_COMPxOUT :1;
				uint32_t COMP4_CSR_1_COMP1LOCK :1;
				uint32_t COMP4_CSR_1_COMP2EN  :1;
				uint32_t COMP4_CSR_1_WNDWE    :1;
				uint32_t COMP4_CSR_1_COMP2MODE :2;
				uint32_t                      :1;
				uint32_t COMP4_CSR_1_OUTSEL   :3;
				uint32_t                      :2;
				uint32_t COMP4_CSR_1_FCH3     :1;
				uint32_t COMP4_CSR_1_FCH8     :1;
				uint32_t COMP4_CSR_1_RCH13    :1;
				uint32_t COMP4_CSR_1_CAIE     :1;
				uint32_t COMP4_CSR_1_COMP2OUT :1;
				uint32_t COMP4_CSR_1_COMP2LOCK :1;
			};
			#endif
			struct
			{
				uint32_t COMP4_CSR_2_COMPxEN  :1;
				uint32_t COMP4_CSR_2_CS400KPU :1;
				uint32_t COMP4_CSR_2_COMPxMODE :2;
				uint32_t COMP4_CSR_2_COMPxINSEL :3;
				uint32_t COMP4_CSR_2_COMPxWNDWEN :1;
				uint32_t COMP4_CSR_2_COMPxOUTSEL :3;
				uint32_t COMP4_CSR_2_COMPxPOL :1;
				uint32_t COMP4_CSR_2_COMPxHYST :2;
				uint32_t                      :1;
				uint32_t COMP4_CSR_2_COMPxLOCK :1;
				uint32_t COMP4_CSR_2_VREFOUTEN :1;
				uint32_t                      :1;
				uint32_t COMP4_CSR_2_COMPxBLANKING :2;
				uint32_t                      :2;
				uint32_t COMP4_CSR_2_BRGEN    :1;
				uint32_t COMP4_CSR_2_SCALEN   :1;
				uint32_t                      :1;
				uint32_t COMP4_CSR_2_INMESEL  :2;
				uint32_t                      :3;
				uint32_t COMP4_CSR_2_COMP1VALUE :1;
				uint32_t COMP4_CSR_2_COMP1LOCK :1;
			};
			#ifdef COMP4_CSR_3
			struct
			{
				uint32_t COMP4_CSR_3_COMP2EN  :1;
				uint32_t                      :1;
				uint32_t COMP4_CSR_3_CS10KPD  :1;
				uint32_t COMP4_CSR_3_COMP2SPEED :1;
				uint32_t COMP4_CSR_3_COMP1INNSEL :2;
				uint32_t                      :1;
				uint32_t COMP4_CSR_3_CMP1OUT  :1;
				uint32_t COMP4_CSR_3_WINMODE  :1;
				uint32_t COMP4_CSR_3_COMPxWNDWEN :1;
				uint32_t COMP4_CSR_3_COMPxOUTSEL :4;
				uint32_t                      :1;
				uint32_t COMP4_CSR_3_COMPxPOL :1;
				uint32_t COMP4_CSR_3_COMPxHYST :2;
				uint32_t COMP4_CSR_3_INSEL    :3;
				uint32_t                      :9;
				uint32_t COMP4_CSR_3_COMPxOUT :1;
				uint32_t COMP4_CSR_3_COMPxLOCK :1;
			};
			#endif
			#ifdef COMP4_CSR_4
			struct
			{
				uint32_t COMP4_CSR_4_CS10KPU  :1;
				uint32_t                      :2;
				uint32_t COMP4_CSR_4_CS400KPD :1;
				uint32_t COMP4_CSR_4_COMP2INNSEL :3;
				uint32_t COMP4_CSR_4_INPSEL   :1;
				uint32_t COMP4_CSR_4_COMP2INPSEL :3;
				uint32_t                      :1;
				uint32_t COMP4_CSR_4_COMP1LPTIM1IN1 :1;
				uint32_t COMP4_CSR_4_COMP2LPTIM1IN1 :1;
				uint32_t                      :1;
				uint32_t COMP4_CSR_4_COMP1POLARITY :1;
				uint32_t COMP4_CSR_4_HYST     :2;
				uint32_t COMP4_CSR_4_BLANKING :3;
				uint32_t                      :9;
				uint32_t COMP4_CSR_4_COMP2VALUE :1;
				uint32_t COMP4_CSR_4_TSUSP    :1;
			};
			#endif
			#ifdef COMP4_CSR_5
			struct
			{
				uint32_t COMP4_CSR_5_EN       :1;
				uint32_t                      :1;
				uint32_t COMP4_CSR_5_PWRMODE  :2;
				uint32_t COMP4_CSR_5_CMP1EN   :1;
				uint32_t COMP4_CSR_5_SW1      :1;
				uint32_t                      :1;
				uint32_t COMP4_CSR_5_INPSEL   :2;
				uint32_t COMP4_CSR_5_WINMODE  :1;
				uint32_t                      :2;
				uint32_t COMP4_CSR_5_COMP2LPTIM1IN2 :1;
				uint32_t COMP4_CSR_5_CMP2OUT  :1;
				uint32_t                      :1;
				uint32_t COMP4_CSR_5_COMP2POLARITY :1;
				uint32_t                      :14;
				uint32_t COMP4_CSR_5_COMPxOUTVALUE :1;
				uint32_t COMP4_CSR_5_LOCK     :1;
			};
			#endif
			#ifdef COMP4_CSR_6
			struct
			{
				uint32_t                      :4;
				uint32_t COMP4_CSR_6_INMSEL   :3;
				uint32_t                      :5;
				uint32_t COMP4_CSR_6_SPEED    :1;
				uint32_t                      :2;
				uint32_t COMP4_CSR_6_COMPxPOLARITY :1;
				uint32_t                      :14;
				uint32_t COMP4_CSR_6_CAIF     :1;
				uint32_t                      :1;
			};
			#endif
			#ifdef COMP4_CSR_7
			struct
			{
				uint32_t                      :15;
				uint32_t POLARITY             :1;
				uint32_t                      :14;
				uint32_t VALUE                :1;
				uint32_t                      :1;
			};
			#endif
		};
		//SOOL-COMP_CSR-DECLARATION
	};
	#endif
	
};
volatile class COMP<COMP4_plugin>* const COMP4 =reinterpret_cast<class COMP<COMP4_plugin>* const>(COMP4_BASE_ADDR);
#endif
#ifdef COMP6_BASE_ADDR
struct COMP6_plugin: COMP_base_plugin {
	
	#ifdef COMP_CSR
	struct CSR_TypeDef : public Reg16_t
	{
		using Reg16_t::operator=;
	
		union
		{
			#ifdef COMP6_CSR_0
			struct
			{
				uint32_t COMP6_CSR_0_COMP6EN  :1;
				uint32_t COMP6_CSR_0_COMP1SW1 :1;
				uint32_t COMP6_CSR_0_COMP6MODE :2;
				uint32_t COMP6_CSR_0_COMP6INSEL :3;
				uint32_t COMP6_CSR_0_COMP6NONINSEL :1;
				uint32_t COMP6_CSR_0_COMP1WM  :1;
				uint32_t COMP6_CSR_0_COMP6WNDWEN :1;
				uint32_t COMP6_CSR_0_COMP6OUTSEL :4;
				uint32_t COMP6_CSR_0_COMP1OUT :1;
				uint32_t COMP6_CSR_0_COMP6POL :1;
				uint32_t COMP6_CSR_0_COMP6HYST :2;
				uint32_t COMP6_CSR_0_COMP6BLANKING :2;
				uint32_t COMP6_CSR_0_COMP2INSEL :3;
				uint32_t COMP6_CSR_0_WNDWEN   :1;
				uint32_t COMP6_CSR_0_COMP2OUTSEL :3;
				uint32_t COMP6_CSR_0_COMP2POL :1;
				uint32_t COMP6_CSR_0_COMP2HYST :2;
				uint32_t COMP6_CSR_0_COMP6OUT :1;
				uint32_t COMP6_CSR_0_COMP6LOCK :1;
			};
			#endif
			#ifdef COMP6_CSR_1
			struct
			{
				uint32_t COMP6_CSR_1_COMP1EN  :1;
				uint32_t COMP6_CSR_1_COMPxSW1 :1;
				uint32_t COMP6_CSR_1_COMP1MODE :2;
				uint32_t COMP6_CSR_1_COMP1INSEL :3;
				uint32_t COMP6_CSR_1_COMPxNONINSEL :1;
				uint32_t COMP6_CSR_1_COMP1OUTSEL :3;
				uint32_t COMP6_CSR_1_COMP1POL :1;
				uint32_t COMP6_CSR_1_COMP1HYST :2;
				uint32_t COMP6_CSR_1_COMPxOUT :1;
				uint32_t COMP6_CSR_1_COMP1LOCK :1;
				uint32_t COMP6_CSR_1_COMP2EN  :1;
				uint32_t COMP6_CSR_1_WNDWE    :1;
				uint32_t COMP6_CSR_1_COMP2MODE :2;
				uint32_t                      :1;
				uint32_t COMP6_CSR_1_OUTSEL   :3;
				uint32_t                      :2;
				uint32_t COMP6_CSR_1_FCH3     :1;
				uint32_t COMP6_CSR_1_FCH8     :1;
				uint32_t COMP6_CSR_1_RCH13    :1;
				uint32_t COMP6_CSR_1_CAIE     :1;
				uint32_t COMP6_CSR_1_COMP2OUT :1;
				uint32_t COMP6_CSR_1_COMP2LOCK :1;
			};
			#endif
			struct
			{
				uint32_t COMP6_CSR_2_COMPxEN  :1;
				uint32_t COMP6_CSR_2_CS400KPU :1;
				uint32_t COMP6_CSR_2_COMPxMODE :2;
				uint32_t COMP6_CSR_2_COMPxINSEL :3;
				uint32_t COMP6_CSR_2_COMPxWNDWEN :1;
				uint32_t COMP6_CSR_2_COMPxOUTSEL :3;
				uint32_t COMP6_CSR_2_COMPxPOL :1;
				uint32_t COMP6_CSR_2_COMPxHYST :2;
				uint32_t                      :1;
				uint32_t COMP6_CSR_2_COMPxLOCK :1;
				uint32_t COMP6_CSR_2_VREFOUTEN :1;
				uint32_t                      :1;
				uint32_t COMP6_CSR_2_COMPxBLANKING :2;
				uint32_t                      :2;
				uint32_t COMP6_CSR_2_BRGEN    :1;
				uint32_t COMP6_CSR_2_SCALEN   :1;
				uint32_t                      :1;
				uint32_t COMP6_CSR_2_INMESEL  :2;
				uint32_t                      :3;
				uint32_t COMP6_CSR_2_COMP1VALUE :1;
				uint32_t COMP6_CSR_2_COMP1LOCK :1;
			};
			#ifdef COMP6_CSR_3
			struct
			{
				uint32_t COMP6_CSR_3_COMP2EN  :1;
				uint32_t                      :1;
				uint32_t COMP6_CSR_3_CS10KPD  :1;
				uint32_t COMP6_CSR_3_COMP2SPEED :1;
				uint32_t COMP6_CSR_3_COMP1INNSEL :2;
				uint32_t                      :1;
				uint32_t COMP6_CSR_3_CMP1OUT  :1;
				uint32_t COMP6_CSR_3_WINMODE  :1;
				uint32_t COMP6_CSR_3_COMPxWNDWEN :1;
				uint32_t COMP6_CSR_3_COMPxOUTSEL :4;
				uint32_t                      :1;
				uint32_t COMP6_CSR_3_COMPxPOL :1;
				uint32_t COMP6_CSR_3_COMPxHYST :2;
				uint32_t COMP6_CSR_3_INSEL    :3;
				uint32_t                      :9;
				uint32_t COMP6_CSR_3_COMPxOUT :1;
				uint32_t COMP6_CSR_3_COMPxLOCK :1;
			};
			#endif
			#ifdef COMP6_CSR_4
			struct
			{
				uint32_t COMP6_CSR_4_CS10KPU  :1;
				uint32_t                      :2;
				uint32_t COMP6_CSR_4_CS400KPD :1;
				uint32_t COMP6_CSR_4_COMP2INNSEL :3;
				uint32_t COMP6_CSR_4_INPSEL   :1;
				uint32_t COMP6_CSR_4_COMP2INPSEL :3;
				uint32_t                      :1;
				uint32_t COMP6_CSR_4_COMP1LPTIM1IN1 :1;
				uint32_t COMP6_CSR_4_COMP2LPTIM1IN1 :1;
				uint32_t                      :1;
				uint32_t COMP6_CSR_4_COMP1POLARITY :1;
				uint32_t COMP6_CSR_4_HYST     :2;
				uint32_t COMP6_CSR_4_BLANKING :3;
				uint32_t                      :9;
				uint32_t COMP6_CSR_4_COMP2VALUE :1;
				uint32_t COMP6_CSR_4_TSUSP    :1;
			};
			#endif
			#ifdef COMP6_CSR_5
			struct
			{
				uint32_t COMP6_CSR_5_EN       :1;
				uint32_t                      :1;
				uint32_t COMP6_CSR_5_PWRMODE  :2;
				uint32_t COMP6_CSR_5_CMP1EN   :1;
				uint32_t COMP6_CSR_5_SW1      :1;
				uint32_t                      :1;
				uint32_t COMP6_CSR_5_INPSEL   :2;
				uint32_t COMP6_CSR_5_WINMODE  :1;
				uint32_t                      :2;
				uint32_t COMP6_CSR_5_COMP2LPTIM1IN2 :1;
				uint32_t COMP6_CSR_5_CMP2OUT  :1;
				uint32_t                      :1;
				uint32_t COMP6_CSR_5_COMP2POLARITY :1;
				uint32_t                      :14;
				uint32_t COMP6_CSR_5_COMPxOUTVALUE :1;
				uint32_t COMP6_CSR_5_LOCK     :1;
			};
			#endif
			#ifdef COMP6_CSR_6
			struct
			{
				uint32_t                      :4;
				uint32_t COMP6_CSR_6_INMSEL   :3;
				uint32_t                      :5;
				uint32_t COMP6_CSR_6_SPEED    :1;
				uint32_t                      :2;
				uint32_t COMP6_CSR_6_COMPxPOLARITY :1;
				uint32_t                      :14;
				uint32_t COMP6_CSR_6_CAIF     :1;
				uint32_t                      :1;
			};
			#endif
			#ifdef COMP6_CSR_7
			struct
			{
				uint32_t                      :15;
				uint32_t POLARITY             :1;
				uint32_t                      :14;
				uint32_t VALUE                :1;
				uint32_t                      :1;
			};
			#endif
		};
		//SOOL-COMP_CSR-DECLARATION
	};
	#endif
	
};
volatile class COMP<COMP6_plugin>* const COMP6 =reinterpret_cast<class COMP<COMP6_plugin>* const>(COMP6_BASE_ADDR);
#endif
#ifdef COMP3_BASE_ADDR
struct COMP3_plugin: COMP_base_plugin {
	
	#ifdef COMP_CSR
	struct CSR_TypeDef : public Reg16_t
	{
		using Reg16_t::operator=;
	
		union
		{
			#ifdef COMP3_CSR_0
			struct
			{
				uint32_t COMP3_CSR_0_COMP3EN  :1;
				uint32_t COMP3_CSR_0_COMP1SW1 :1;
				uint32_t COMP3_CSR_0_COMP3MODE :2;
				uint32_t COMP3_CSR_0_COMP3INSEL :3;
				uint32_t COMP3_CSR_0_COMP3NONINSEL :1;
				uint32_t COMP3_CSR_0_COMP1WM  :1;
				uint32_t COMP3_CSR_0_COMPxWNDWEN :1;
				uint32_t COMP3_CSR_0_COMP3OUTSEL :4;
				uint32_t COMP3_CSR_0_COMP1OUT :1;
				uint32_t COMP3_CSR_0_COMP3POL :1;
				uint32_t COMP3_CSR_0_COMP3HYST :2;
				uint32_t COMP3_CSR_0_COMP3BLANKING :2;
				uint32_t COMP3_CSR_0_COMP2INSEL :3;
				uint32_t COMP3_CSR_0_WNDWEN   :1;
				uint32_t COMP3_CSR_0_COMP2OUTSEL :3;
				uint32_t COMP3_CSR_0_COMP2POL :1;
				uint32_t COMP3_CSR_0_COMP2HYST :2;
				uint32_t COMP3_CSR_0_COMP3OUT :1;
				uint32_t COMP3_CSR_0_COMP3LOCK :1;
			};
			#endif
			#ifdef COMP3_CSR_1
			struct
			{
				uint32_t COMP3_CSR_1_COMP1EN  :1;
				uint32_t COMP3_CSR_1_COMPxSW1 :1;
				uint32_t COMP3_CSR_1_COMP1MODE :2;
				uint32_t COMP3_CSR_1_COMP1INSEL :3;
				uint32_t COMP3_CSR_1_COMPxNONINSEL :1;
				uint32_t COMP3_CSR_1_COMP1OUTSEL :3;
				uint32_t COMP3_CSR_1_COMP1POL :1;
				uint32_t COMP3_CSR_1_COMP1HYST :2;
				uint32_t COMP3_CSR_1_COMPxOUT :1;
				uint32_t COMP3_CSR_1_COMP1LOCK :1;
				uint32_t COMP3_CSR_1_COMP2EN  :1;
				uint32_t COMP3_CSR_1_WNDWE    :1;
				uint32_t COMP3_CSR_1_COMP2MODE :2;
				uint32_t                      :1;
				uint32_t COMP3_CSR_1_OUTSEL   :3;
				uint32_t                      :2;
				uint32_t COMP3_CSR_1_FCH3     :1;
				uint32_t COMP3_CSR_1_FCH8     :1;
				uint32_t COMP3_CSR_1_RCH13    :1;
				uint32_t COMP3_CSR_1_CAIE     :1;
				uint32_t COMP3_CSR_1_COMP2OUT :1;
				uint32_t COMP3_CSR_1_COMP2LOCK :1;
			};
			#endif
			struct
			{
				uint32_t COMP3_CSR_2_COMPxEN  :1;
				uint32_t COMP3_CSR_2_CS400KPU :1;
				uint32_t COMP3_CSR_2_COMPxMODE :2;
				uint32_t COMP3_CSR_2_COMPxINSEL :3;
				uint32_t COMP3_CSR_2_COMPxWNDWEN :1;
				uint32_t COMP3_CSR_2_COMPxOUTSEL :3;
				uint32_t COMP3_CSR_2_COMPxPOL :1;
				uint32_t COMP3_CSR_2_COMPxHYST :2;
				uint32_t                      :1;
				uint32_t COMP3_CSR_2_COMPxLOCK :1;
				uint32_t COMP3_CSR_2_VREFOUTEN :1;
				uint32_t                      :1;
				uint32_t COMP3_CSR_2_COMPxBLANKING :2;
				uint32_t                      :2;
				uint32_t COMP3_CSR_2_BRGEN    :1;
				uint32_t COMP3_CSR_2_SCALEN   :1;
				uint32_t                      :1;
				uint32_t COMP3_CSR_2_INMESEL  :2;
				uint32_t                      :3;
				uint32_t COMP3_CSR_2_COMP1VALUE :1;
				uint32_t COMP3_CSR_2_COMP1LOCK :1;
			};
			#ifdef COMP3_CSR_3
			struct
			{
				uint32_t COMP3_CSR_3_COMP2EN  :1;
				uint32_t                      :1;
				uint32_t COMP3_CSR_3_CS10KPD  :1;
				uint32_t COMP3_CSR_3_COMP2SPEED :1;
				uint32_t COMP3_CSR_3_COMP1INNSEL :2;
				uint32_t                      :1;
				uint32_t COMP3_CSR_3_CMP1OUT  :1;
				uint32_t COMP3_CSR_3_WINMODE  :1;
				uint32_t                      :1;
				uint32_t COMP3_CSR_3_COMPxOUTSEL :4;
				uint32_t                      :1;
				uint32_t COMP3_CSR_3_COMPxPOL :1;
				uint32_t COMP3_CSR_3_COMPxHYST :2;
				uint32_t COMP3_CSR_3_INSEL    :3;
				uint32_t                      :9;
				uint32_t COMP3_CSR_3_COMPxOUT :1;
				uint32_t COMP3_CSR_3_COMPxLOCK :1;
			};
			#endif
			#ifdef COMP3_CSR_4
			struct
			{
				uint32_t COMP3_CSR_4_CS10KPU  :1;
				uint32_t                      :2;
				uint32_t COMP3_CSR_4_CS400KPD :1;
				uint32_t COMP3_CSR_4_COMP2INNSEL :3;
				uint32_t COMP3_CSR_4_INPSEL   :1;
				uint32_t COMP3_CSR_4_COMP2INPSEL :3;
				uint32_t                      :1;
				uint32_t COMP3_CSR_4_COMP1LPTIM1IN1 :1;
				uint32_t COMP3_CSR_4_COMP2LPTIM1IN1 :1;
				uint32_t                      :1;
				uint32_t COMP3_CSR_4_COMP1POLARITY :1;
				uint32_t COMP3_CSR_4_HYST     :2;
				uint32_t COMP3_CSR_4_BLANKING :3;
				uint32_t                      :9;
				uint32_t COMP3_CSR_4_COMP2VALUE :1;
				uint32_t COMP3_CSR_4_TSUSP    :1;
			};
			#endif
			#ifdef COMP3_CSR_5
			struct
			{
				uint32_t COMP3_CSR_5_EN       :1;
				uint32_t                      :1;
				uint32_t COMP3_CSR_5_PWRMODE  :2;
				uint32_t COMP3_CSR_5_CMP1EN   :1;
				uint32_t COMP3_CSR_5_SW1      :1;
				uint32_t                      :1;
				uint32_t COMP3_CSR_5_INPSEL   :2;
				uint32_t COMP3_CSR_5_WINMODE  :1;
				uint32_t                      :2;
				uint32_t COMP3_CSR_5_COMP2LPTIM1IN2 :1;
				uint32_t COMP3_CSR_5_CMP2OUT  :1;
				uint32_t                      :1;
				uint32_t COMP3_CSR_5_COMP2POLARITY :1;
				uint32_t                      :14;
				uint32_t COMP3_CSR_5_COMPxOUTVALUE :1;
				uint32_t COMP3_CSR_5_LOCK     :1;
			};
			#endif
			#ifdef COMP3_CSR_6
			struct
			{
				uint32_t                      :4;
				uint32_t COMP3_CSR_6_INMSEL   :3;
				uint32_t                      :5;
				uint32_t COMP3_CSR_6_SPEED    :1;
				uint32_t                      :2;
				uint32_t COMP3_CSR_6_COMPxPOLARITY :1;
				uint32_t                      :14;
				uint32_t COMP3_CSR_6_CAIF     :1;
				uint32_t                      :1;
			};
			#endif
			#ifdef COMP3_CSR_7
			struct
			{
				uint32_t                      :15;
				uint32_t POLARITY             :1;
				uint32_t                      :14;
				uint32_t VALUE                :1;
				uint32_t                      :1;
			};
			#endif
		};
		//SOOL-COMP_CSR-DECLARATION
	};
	#endif
	
};
volatile class COMP<COMP3_plugin>* const COMP3 =reinterpret_cast<class COMP<COMP3_plugin>* const>(COMP3_BASE_ADDR);
#endif
#ifdef COMP5_BASE_ADDR
struct COMP5_plugin: COMP_base_plugin {
	
	#ifdef COMP_CSR
	struct CSR_TypeDef : public Reg16_t
	{
		using Reg16_t::operator=;
	
		union
		{
			#ifdef COMP5_CSR_0
			struct
			{
				uint32_t COMP5_CSR_0_COMP5EN  :1;
				uint32_t COMP5_CSR_0_COMP1SW1 :1;
				uint32_t COMP5_CSR_0_COMP5MODE :2;
				uint32_t COMP5_CSR_0_COMP5INSEL :3;
				uint32_t COMP5_CSR_0_COMP5NONINSEL :1;
				uint32_t COMP5_CSR_0_COMP1WM  :1;
				uint32_t COMP5_CSR_0_COMPxWNDWEN :1;
				uint32_t COMP5_CSR_0_COMP5OUTSEL :4;
				uint32_t COMP5_CSR_0_COMP1OUT :1;
				uint32_t COMP5_CSR_0_COMP5POL :1;
				uint32_t COMP5_CSR_0_COMP5HYST :2;
				uint32_t COMP5_CSR_0_COMP5BLANKING :2;
				uint32_t COMP5_CSR_0_COMP2INSEL :3;
				uint32_t COMP5_CSR_0_WNDWEN   :1;
				uint32_t COMP5_CSR_0_COMP2OUTSEL :3;
				uint32_t COMP5_CSR_0_COMP2POL :1;
				uint32_t COMP5_CSR_0_COMP2HYST :2;
				uint32_t COMP5_CSR_0_COMP5OUT :1;
				uint32_t COMP5_CSR_0_COMP5LOCK :1;
			};
			#endif
			#ifdef COMP5_CSR_1
			struct
			{
				uint32_t COMP5_CSR_1_COMP1EN  :1;
				uint32_t COMP5_CSR_1_COMPxSW1 :1;
				uint32_t COMP5_CSR_1_COMP1MODE :2;
				uint32_t COMP5_CSR_1_COMP1INSEL :3;
				uint32_t COMP5_CSR_1_COMPxNONINSEL :1;
				uint32_t COMP5_CSR_1_COMP1OUTSEL :3;
				uint32_t COMP5_CSR_1_COMP1POL :1;
				uint32_t COMP5_CSR_1_COMP1HYST :2;
				uint32_t COMP5_CSR_1_COMPxOUT :1;
				uint32_t COMP5_CSR_1_COMP1LOCK :1;
				uint32_t COMP5_CSR_1_COMP2EN  :1;
				uint32_t COMP5_CSR_1_WNDWE    :1;
				uint32_t COMP5_CSR_1_COMP2MODE :2;
				uint32_t                      :1;
				uint32_t COMP5_CSR_1_OUTSEL   :3;
				uint32_t                      :2;
				uint32_t COMP5_CSR_1_FCH3     :1;
				uint32_t COMP5_CSR_1_FCH8     :1;
				uint32_t COMP5_CSR_1_RCH13    :1;
				uint32_t COMP5_CSR_1_CAIE     :1;
				uint32_t COMP5_CSR_1_COMP2OUT :1;
				uint32_t COMP5_CSR_1_COMP2LOCK :1;
			};
			#endif
			struct
			{
				uint32_t COMP5_CSR_2_COMPxEN  :1;
				uint32_t COMP5_CSR_2_CS400KPU :1;
				uint32_t COMP5_CSR_2_COMPxMODE :2;
				uint32_t COMP5_CSR_2_COMPxINSEL :3;
				uint32_t COMP5_CSR_2_COMPxWNDWEN :1;
				uint32_t COMP5_CSR_2_COMPxOUTSEL :3;
				uint32_t COMP5_CSR_2_COMPxPOL :1;
				uint32_t COMP5_CSR_2_COMPxHYST :2;
				uint32_t                      :1;
				uint32_t COMP5_CSR_2_COMPxLOCK :1;
				uint32_t COMP5_CSR_2_VREFOUTEN :1;
				uint32_t                      :1;
				uint32_t COMP5_CSR_2_COMPxBLANKING :2;
				uint32_t                      :2;
				uint32_t COMP5_CSR_2_BRGEN    :1;
				uint32_t COMP5_CSR_2_SCALEN   :1;
				uint32_t                      :1;
				uint32_t COMP5_CSR_2_INMESEL  :2;
				uint32_t                      :3;
				uint32_t COMP5_CSR_2_COMP1VALUE :1;
				uint32_t COMP5_CSR_2_COMP1LOCK :1;
			};
			#ifdef COMP5_CSR_3
			struct
			{
				uint32_t COMP5_CSR_3_COMP2EN  :1;
				uint32_t                      :1;
				uint32_t COMP5_CSR_3_CS10KPD  :1;
				uint32_t COMP5_CSR_3_COMP2SPEED :1;
				uint32_t COMP5_CSR_3_COMP1INNSEL :2;
				uint32_t                      :1;
				uint32_t COMP5_CSR_3_CMP1OUT  :1;
				uint32_t COMP5_CSR_3_WINMODE  :1;
				uint32_t                      :1;
				uint32_t COMP5_CSR_3_COMPxOUTSEL :4;
				uint32_t                      :1;
				uint32_t COMP5_CSR_3_COMPxPOL :1;
				uint32_t COMP5_CSR_3_COMPxHYST :2;
				uint32_t COMP5_CSR_3_INSEL    :3;
				uint32_t                      :9;
				uint32_t COMP5_CSR_3_COMPxOUT :1;
				uint32_t COMP5_CSR_3_COMPxLOCK :1;
			};
			#endif
			#ifdef COMP5_CSR_4
			struct
			{
				uint32_t COMP5_CSR_4_CS10KPU  :1;
				uint32_t                      :2;
				uint32_t COMP5_CSR_4_CS400KPD :1;
				uint32_t COMP5_CSR_4_COMP2INNSEL :3;
				uint32_t COMP5_CSR_4_INPSEL   :1;
				uint32_t COMP5_CSR_4_COMP2INPSEL :3;
				uint32_t                      :1;
				uint32_t COMP5_CSR_4_COMP1LPTIM1IN1 :1;
				uint32_t COMP5_CSR_4_COMP2LPTIM1IN1 :1;
				uint32_t                      :1;
				uint32_t COMP5_CSR_4_COMP1POLARITY :1;
				uint32_t COMP5_CSR_4_HYST     :2;
				uint32_t COMP5_CSR_4_BLANKING :3;
				uint32_t                      :9;
				uint32_t COMP5_CSR_4_COMP2VALUE :1;
				uint32_t COMP5_CSR_4_TSUSP    :1;
			};
			#endif
			#ifdef COMP5_CSR_5
			struct
			{
				uint32_t COMP5_CSR_5_EN       :1;
				uint32_t                      :1;
				uint32_t COMP5_CSR_5_PWRMODE  :2;
				uint32_t COMP5_CSR_5_CMP1EN   :1;
				uint32_t COMP5_CSR_5_SW1      :1;
				uint32_t                      :1;
				uint32_t COMP5_CSR_5_INPSEL   :2;
				uint32_t COMP5_CSR_5_WINMODE  :1;
				uint32_t                      :2;
				uint32_t COMP5_CSR_5_COMP2LPTIM1IN2 :1;
				uint32_t COMP5_CSR_5_CMP2OUT  :1;
				uint32_t                      :1;
				uint32_t COMP5_CSR_5_COMP2POLARITY :1;
				uint32_t                      :14;
				uint32_t COMP5_CSR_5_COMPxOUTVALUE :1;
				uint32_t COMP5_CSR_5_LOCK     :1;
			};
			#endif
			#ifdef COMP5_CSR_6
			struct
			{
				uint32_t                      :4;
				uint32_t COMP5_CSR_6_INMSEL   :3;
				uint32_t                      :5;
				uint32_t COMP5_CSR_6_SPEED    :1;
				uint32_t                      :2;
				uint32_t COMP5_CSR_6_COMPxPOLARITY :1;
				uint32_t                      :14;
				uint32_t COMP5_CSR_6_CAIF     :1;
				uint32_t                      :1;
			};
			#endif
			#ifdef COMP5_CSR_7
			struct
			{
				uint32_t                      :15;
				uint32_t POLARITY             :1;
				uint32_t                      :14;
				uint32_t VALUE                :1;
				uint32_t                      :1;
			};
			#endif
		};
		//SOOL-COMP_CSR-DECLARATION
	};
	#endif
	
};
volatile class COMP<COMP5_plugin>* const COMP5 =reinterpret_cast<class COMP<COMP5_plugin>* const>(COMP5_BASE_ADDR);
#endif
#ifdef COMP7_BASE_ADDR
struct COMP7_plugin: COMP_base_plugin {
	
	#ifdef COMP_CSR
	struct CSR_TypeDef : public Reg16_t
	{
		using Reg16_t::operator=;
	
		union
		{
			#ifdef COMP7_CSR_0
			struct
			{
				uint32_t COMP7_CSR_0_COMP7EN  :1;
				uint32_t COMP7_CSR_0_COMP1SW1 :1;
				uint32_t COMP7_CSR_0_COMP7MODE :2;
				uint32_t COMP7_CSR_0_COMP7INSEL :3;
				uint32_t COMP7_CSR_0_COMP7NONINSEL :1;
				uint32_t COMP7_CSR_0_COMP1WM  :1;
				uint32_t COMP7_CSR_0_COMPxWNDWEN :1;
				uint32_t COMP7_CSR_0_COMP7OUTSEL :4;
				uint32_t COMP7_CSR_0_COMP1OUT :1;
				uint32_t COMP7_CSR_0_COMP7POL :1;
				uint32_t COMP7_CSR_0_COMP7HYST :2;
				uint32_t COMP7_CSR_0_COMP7BLANKING :2;
				uint32_t COMP7_CSR_0_COMP2INSEL :3;
				uint32_t COMP7_CSR_0_WNDWEN   :1;
				uint32_t COMP7_CSR_0_COMP2OUTSEL :3;
				uint32_t COMP7_CSR_0_COMP2POL :1;
				uint32_t COMP7_CSR_0_COMP2HYST :2;
				uint32_t COMP7_CSR_0_COMP7OUT :1;
				uint32_t COMP7_CSR_0_COMP7LOCK :1;
			};
			#endif
			#ifdef COMP7_CSR_1
			struct
			{
				uint32_t COMP7_CSR_1_COMP1EN  :1;
				uint32_t COMP7_CSR_1_COMPxSW1 :1;
				uint32_t COMP7_CSR_1_COMP1MODE :2;
				uint32_t COMP7_CSR_1_COMP1INSEL :3;
				uint32_t COMP7_CSR_1_COMPxNONINSEL :1;
				uint32_t COMP7_CSR_1_COMP1OUTSEL :3;
				uint32_t COMP7_CSR_1_COMP1POL :1;
				uint32_t COMP7_CSR_1_COMP1HYST :2;
				uint32_t COMP7_CSR_1_COMPxOUT :1;
				uint32_t COMP7_CSR_1_COMP1LOCK :1;
				uint32_t COMP7_CSR_1_COMP2EN  :1;
				uint32_t COMP7_CSR_1_WNDWE    :1;
				uint32_t COMP7_CSR_1_COMP2MODE :2;
				uint32_t                      :1;
				uint32_t COMP7_CSR_1_OUTSEL   :3;
				uint32_t                      :2;
				uint32_t COMP7_CSR_1_FCH3     :1;
				uint32_t COMP7_CSR_1_FCH8     :1;
				uint32_t COMP7_CSR_1_RCH13    :1;
				uint32_t COMP7_CSR_1_CAIE     :1;
				uint32_t COMP7_CSR_1_COMP2OUT :1;
				uint32_t COMP7_CSR_1_COMP2LOCK :1;
			};
			#endif
			struct
			{
				uint32_t COMP7_CSR_2_COMPxEN  :1;
				uint32_t COMP7_CSR_2_CS400KPU :1;
				uint32_t COMP7_CSR_2_COMPxMODE :2;
				uint32_t COMP7_CSR_2_COMPxINSEL :3;
				uint32_t COMP7_CSR_2_COMPxWNDWEN :1;
				uint32_t COMP7_CSR_2_COMPxOUTSEL :3;
				uint32_t COMP7_CSR_2_COMPxPOL :1;
				uint32_t COMP7_CSR_2_COMPxHYST :2;
				uint32_t                      :1;
				uint32_t COMP7_CSR_2_COMPxLOCK :1;
				uint32_t COMP7_CSR_2_VREFOUTEN :1;
				uint32_t                      :1;
				uint32_t COMP7_CSR_2_COMPxBLANKING :2;
				uint32_t                      :2;
				uint32_t COMP7_CSR_2_BRGEN    :1;
				uint32_t COMP7_CSR_2_SCALEN   :1;
				uint32_t                      :1;
				uint32_t COMP7_CSR_2_INMESEL  :2;
				uint32_t                      :3;
				uint32_t COMP7_CSR_2_COMP1VALUE :1;
				uint32_t COMP7_CSR_2_COMP1LOCK :1;
			};
			#ifdef COMP7_CSR_3
			struct
			{
				uint32_t COMP7_CSR_3_COMP2EN  :1;
				uint32_t                      :1;
				uint32_t COMP7_CSR_3_CS10KPD  :1;
				uint32_t COMP7_CSR_3_COMP2SPEED :1;
				uint32_t COMP7_CSR_3_COMP1INNSEL :2;
				uint32_t                      :1;
				uint32_t COMP7_CSR_3_CMP1OUT  :1;
				uint32_t COMP7_CSR_3_WINMODE  :1;
				uint32_t                      :1;
				uint32_t COMP7_CSR_3_COMPxOUTSEL :4;
				uint32_t                      :1;
				uint32_t COMP7_CSR_3_COMPxPOL :1;
				uint32_t COMP7_CSR_3_COMPxHYST :2;
				uint32_t COMP7_CSR_3_INSEL    :3;
				uint32_t                      :9;
				uint32_t COMP7_CSR_3_COMPxOUT :1;
				uint32_t COMP7_CSR_3_COMPxLOCK :1;
			};
			#endif
			#ifdef COMP7_CSR_4
			struct
			{
				uint32_t COMP7_CSR_4_CS10KPU  :1;
				uint32_t                      :2;
				uint32_t COMP7_CSR_4_CS400KPD :1;
				uint32_t COMP7_CSR_4_COMP2INNSEL :3;
				uint32_t COMP7_CSR_4_INPSEL   :1;
				uint32_t COMP7_CSR_4_COMP2INPSEL :3;
				uint32_t                      :1;
				uint32_t COMP7_CSR_4_COMP1LPTIM1IN1 :1;
				uint32_t COMP7_CSR_4_COMP2LPTIM1IN1 :1;
				uint32_t                      :1;
				uint32_t COMP7_CSR_4_COMP1POLARITY :1;
				uint32_t COMP7_CSR_4_HYST     :2;
				uint32_t COMP7_CSR_4_BLANKING :3;
				uint32_t                      :9;
				uint32_t COMP7_CSR_4_COMP2VALUE :1;
				uint32_t COMP7_CSR_4_TSUSP    :1;
			};
			#endif
			#ifdef COMP7_CSR_5
			struct
			{
				uint32_t COMP7_CSR_5_EN       :1;
				uint32_t                      :1;
				uint32_t COMP7_CSR_5_PWRMODE  :2;
				uint32_t COMP7_CSR_5_CMP1EN   :1;
				uint32_t COMP7_CSR_5_SW1      :1;
				uint32_t                      :1;
				uint32_t COMP7_CSR_5_INPSEL   :2;
				uint32_t COMP7_CSR_5_WINMODE  :1;
				uint32_t                      :2;
				uint32_t COMP7_CSR_5_COMP2LPTIM1IN2 :1;
				uint32_t COMP7_CSR_5_CMP2OUT  :1;
				uint32_t                      :1;
				uint32_t COMP7_CSR_5_COMP2POLARITY :1;
				uint32_t                      :14;
				uint32_t COMP7_CSR_5_COMPxOUTVALUE :1;
				uint32_t COMP7_CSR_5_LOCK     :1;
			};
			#endif
			#ifdef COMP7_CSR_6
			struct
			{
				uint32_t                      :4;
				uint32_t COMP7_CSR_6_INMSEL   :3;
				uint32_t                      :5;
				uint32_t COMP7_CSR_6_SPEED    :1;
				uint32_t                      :2;
				uint32_t COMP7_CSR_6_COMPxPOLARITY :1;
				uint32_t                      :14;
				uint32_t COMP7_CSR_6_CAIF     :1;
				uint32_t                      :1;
			};
			#endif
			#ifdef COMP7_CSR_7
			struct
			{
				uint32_t                      :15;
				uint32_t POLARITY             :1;
				uint32_t                      :14;
				uint32_t VALUE                :1;
				uint32_t                      :1;
			};
			#endif
		};
		//SOOL-COMP_CSR-DECLARATION
	};
	#endif
	
};
volatile class COMP<COMP7_plugin>* const COMP7 =reinterpret_cast<class COMP<COMP7_plugin>* const>(COMP7_BASE_ADDR);
#endif
//endregion

//SOOL-COMP-DEFINES
//SOOL-COMP-DEFINITION
	};
};//region undef
#undef COMP_MAP1_CFGR
#undef COMP_MAP0_CSR
#undef COMP_CSR_0_COMP1EN
#undef COMP_CSR_0_COMP2LOCK
#undef COMP2_CSR_1_COMP1EN
#undef COMP4_CSR_1_COMP1EN
#undef COMP4_CSR_1_COMP2LOCK
#undef COMP6_CSR_1_COMP1EN
#undef COMP6_CSR_1_COMP2LOCK
#undef COMP1_CSR_1_COMP2LOCK
#undef COMP3_CSR_1_COMP1EN
#undef COMP3_CSR_1_COMP2LOCK
#undef COMP5_CSR_1_COMP1EN
#undef COMP5_CSR_1_COMP2LOCK
#undef COMP7_CSR_1_COMP1EN
#undef COMP7_CSR_1_COMP2LOCK
#undef COMP_CSR_0_COMP1SW1
#undef COMP_CSR_0_COMP1MODE
#undef COMP_CSR_0_COMP1INSEL
#undef COMP_CSR_0_COMP1OUTSEL
#undef COMP_CSR_0_COMP1POL
#undef COMP_CSR_0_COMP1HYST
#undef COMP_CSR_0_COMP1OUT
#undef COMP_CSR_0_COMP1LOCK
#undef COMP_CSR_0_COMP2EN
#undef COMP_CSR_0_COMP2MODE
#undef COMP_CSR_0_COMP2INSEL
#undef COMP_CSR_0_WNDWEN
#undef COMP_CSR_0_COMP2OUTSEL
#undef COMP_CSR_0_COMP2POL
#undef COMP_CSR_0_COMP2HYST
#undef COMP_CSR_0_COMP2OUT
#undef COMP_CSR_1_COMPxOUTSEL
#undef COMP_CSR_1_COMPxPOL
#undef COMP_CSR_1_COMPxHYST
#undef COMP_CSR_1_COMPxOUT
#undef COMP_CSR_1_COMPxLOCK
#undef COMP2_CSR_0_COMP1OUT
#undef COMP2_CSR_0_WNDWEN
#undef COMP2_CSR_1_COMP1MODE
#undef COMP2_CSR_1_COMP1INSEL
#undef COMP2_CSR_1_COMP1OUTSEL
#undef COMP2_CSR_1_COMP1POL
#undef COMP2_CSR_1_COMP1HYST
#undef COMP2_CSR_1_COMPxOUT
#undef COMP2_CSR_1_COMP1LOCK
#undef COMP2_CSR_1_COMP2EN
#undef COMP2_CSR_1_COMP2MODE
#undef COMP2_CSR_1_COMP2INSEL
#undef COMP2_CSR_1_COMP2OUTSEL
#undef COMP2_CSR_1_COMP2POL
#undef COMP2_CSR_1_COMP2HYST
#undef COMP2_CSR_2_COMP1SW1
#undef COMP2_CSR_2_COMPxOUTSEL
#undef COMP2_CSR_2_COMPxPOL
#undef COMP2_CSR_2_COMPxHYST
#undef COMP2_CSR_2_COMPxLOCK
#undef COMP4_CSR_0_COMP1SW1
#undef COMP4_CSR_0_COMP1OUT
#undef COMP4_CSR_0_COMP2INSEL
#undef COMP4_CSR_0_WNDWEN
#undef COMP4_CSR_0_COMP2OUTSEL
#undef COMP4_CSR_0_COMP2POL
#undef COMP4_CSR_0_COMP2HYST
#undef COMP4_CSR_1_COMP1MODE
#undef COMP4_CSR_1_COMP1INSEL
#undef COMP4_CSR_1_COMP1OUTSEL
#undef COMP4_CSR_1_COMP1POL
#undef COMP4_CSR_1_COMP1HYST
#undef COMP4_CSR_1_COMPxOUT
#undef COMP4_CSR_1_COMP1LOCK
#undef COMP4_CSR_1_COMP2EN
#undef COMP4_CSR_1_COMP2MODE
#undef COMP4_CSR_1_COMP2OUT
#undef COMP4_CSR_2_COMPxOUTSEL
#undef COMP4_CSR_2_COMPxPOL
#undef COMP4_CSR_2_COMPxHYST
#undef COMP4_CSR_2_COMPxLOCK
#undef COMP6_CSR_0_COMP1SW1
#undef COMP6_CSR_0_COMP1OUT
#undef COMP6_CSR_0_COMP2INSEL
#undef COMP6_CSR_0_WNDWEN
#undef COMP6_CSR_0_COMP2OUTSEL
#undef COMP6_CSR_0_COMP2POL
#undef COMP6_CSR_0_COMP2HYST
#undef COMP6_CSR_1_COMP1MODE
#undef COMP6_CSR_1_COMP1INSEL
#undef COMP6_CSR_1_COMP1OUTSEL
#undef COMP6_CSR_1_COMP1POL
#undef COMP6_CSR_1_COMP1HYST
#undef COMP6_CSR_1_COMPxOUT
#undef COMP6_CSR_1_COMP1LOCK
#undef COMP6_CSR_1_COMP2EN
#undef COMP6_CSR_1_COMP2MODE
#undef COMP6_CSR_1_COMP2OUT
#undef COMP6_CSR_2_COMPxOUTSEL
#undef COMP6_CSR_2_COMPxPOL
#undef COMP6_CSR_2_COMPxHYST
#undef COMP6_CSR_2_COMPxLOCK
#undef COMP1_CSR_0_COMPxOUT
#undef COMP1_CSR_0_COMP2INSEL
#undef COMP1_CSR_0_WNDWEN
#undef COMP1_CSR_0_COMP2OUTSEL
#undef COMP1_CSR_0_COMP2POL
#undef COMP1_CSR_0_COMP2HYST
#undef COMP1_CSR_1_COMP1OUTSEL
#undef COMP1_CSR_1_COMP1POL
#undef COMP1_CSR_1_COMP1HYST
#undef COMP1_CSR_1_COMP1OUT
#undef COMP1_CSR_1_COMP1LOCK
#undef COMP1_CSR_1_COMP2EN
#undef COMP1_CSR_1_COMP2MODE
#undef COMP1_CSR_1_COMP2OUT
#undef COMP1_CSR_2_COMPxOUTSEL
#undef COMP1_CSR_2_COMPxPOL
#undef COMP1_CSR_2_COMPxHYST
#undef COMP1_CSR_2_COMPxLOCK
#undef COMP3_CSR_0_COMP1SW1
#undef COMP3_CSR_0_COMP1OUT
#undef COMP3_CSR_0_COMP2INSEL
#undef COMP3_CSR_0_WNDWEN
#undef COMP3_CSR_0_COMP2OUTSEL
#undef COMP3_CSR_0_COMP2POL
#undef COMP3_CSR_0_COMP2HYST
#undef COMP3_CSR_1_COMP1MODE
#undef COMP3_CSR_1_COMP1INSEL
#undef COMP3_CSR_1_COMP1OUTSEL
#undef COMP3_CSR_1_COMP1POL
#undef COMP3_CSR_1_COMP1HYST
#undef COMP3_CSR_1_COMPxOUT
#undef COMP3_CSR_1_COMP1LOCK
#undef COMP3_CSR_1_COMP2EN
#undef COMP3_CSR_1_COMP2MODE
#undef COMP3_CSR_1_COMP2OUT
#undef COMP3_CSR_2_COMPxOUTSEL
#undef COMP3_CSR_2_COMPxPOL
#undef COMP3_CSR_2_COMPxHYST
#undef COMP3_CSR_2_COMPxLOCK
#undef COMP5_CSR_0_COMP1SW1
#undef COMP5_CSR_0_COMP1OUT
#undef COMP5_CSR_0_COMP2INSEL
#undef COMP5_CSR_0_WNDWEN
#undef COMP5_CSR_0_COMP2OUTSEL
#undef COMP5_CSR_0_COMP2POL
#undef COMP5_CSR_0_COMP2HYST
#undef COMP5_CSR_1_COMP1MODE
#undef COMP5_CSR_1_COMP1INSEL
#undef COMP5_CSR_1_COMP1OUTSEL
#undef COMP5_CSR_1_COMP1POL
#undef COMP5_CSR_1_COMP1HYST
#undef COMP5_CSR_1_COMPxOUT
#undef COMP5_CSR_1_COMP1LOCK
#undef COMP5_CSR_1_COMP2EN
#undef COMP5_CSR_1_COMP2MODE
#undef COMP5_CSR_1_COMP2OUT
#undef COMP5_CSR_2_COMPxOUTSEL
#undef COMP5_CSR_2_COMPxPOL
#undef COMP5_CSR_2_COMPxHYST
#undef COMP5_CSR_2_COMPxLOCK
#undef COMP7_CSR_0_COMP1SW1
#undef COMP7_CSR_0_COMP1OUT
#undef COMP7_CSR_0_COMP2INSEL
#undef COMP7_CSR_0_WNDWEN
#undef COMP7_CSR_0_COMP2OUTSEL
#undef COMP7_CSR_0_COMP2POL
#undef COMP7_CSR_0_COMP2HYST
#undef COMP7_CSR_1_COMP1MODE
#undef COMP7_CSR_1_COMP1INSEL
#undef COMP7_CSR_1_COMP1OUTSEL
#undef COMP7_CSR_1_COMP1POL
#undef COMP7_CSR_1_COMP1HYST
#undef COMP7_CSR_1_COMPxOUT
#undef COMP7_CSR_1_COMP1LOCK
#undef COMP7_CSR_1_COMP2EN
#undef COMP7_CSR_1_COMP2MODE
#undef COMP7_CSR_1_COMP2OUT
#undef COMP7_CSR_2_COMPxOUTSEL
#undef COMP7_CSR_2_COMPxPOL
#undef COMP7_CSR_2_COMPxHYST
#undef COMP7_CSR_2_COMPxLOCK
#undef COMP_CSR_0_COMPxNONINSEL
#undef COMP_CSR_2_COMPxWNDWEN
#undef COMP_CSR_2_COMPxHYST
#undef COMP2_CSR_0_COMP2MODE
#undef COMP2_CSR_0_COMP2NONINSEL
#undef COMP2_CSR_0_COMP2WNDWEN
#undef COMP2_CSR_0_COMP2HYST
#undef COMP2_CSR_1_COMPxNONINSEL
#undef COMP2_CSR_3_COMPxWNDWEN
#undef COMP2_CSR_3_COMPxHYST
#undef COMP4_CSR_0_COMP4MODE
#undef COMP4_CSR_0_COMP4NONINSEL
#undef COMP4_CSR_0_COMP4HYST
#undef COMP4_CSR_1_COMPxNONINSEL
#undef COMP4_CSR_3_COMPxWNDWEN
#undef COMP4_CSR_3_COMPxHYST
#undef COMP6_CSR_0_COMP6MODE
#undef COMP6_CSR_0_COMP6NONINSEL
#undef COMP6_CSR_0_COMP6HYST
#undef COMP6_CSR_1_COMPxNONINSEL
#undef COMP6_CSR_3_COMPxWNDWEN
#undef COMP6_CSR_3_COMPxHYST
#undef COMP1_CSR_0_COMPxNONINSEL
#undef COMP1_CSR_0_COMPxWNDWEN
#undef COMP1_CSR_0_COMP1HYST
#undef COMP1_CSR_3_COMPxHYST
#undef COMP3_CSR_0_COMPxWNDWEN
#undef COMP3_CSR_1_COMPxNONINSEL
#undef COMP3_CSR_3_COMPxHYST
#undef COMP5_CSR_0_COMPxWNDWEN
#undef COMP5_CSR_1_COMPxNONINSEL
#undef COMP5_CSR_3_COMPxHYST
#undef COMP7_CSR_0_COMPxWNDWEN
#undef COMP7_CSR_1_COMPxNONINSEL
#undef COMP7_CSR_3_COMPxHYST
#undef COMP_CSR_0_WNDWE
#undef COMP_CSR_1_VREFOUTEN
#undef COMP_CSR_1_OUTSEL
#undef COMP_CSR_2_CS400KPU
#undef COMP_CSR_2_CS10KPD
#undef COMP_CSR_2_CMP1OUT
#undef COMP_CSR_2_INSEL
#undef COMP_CSR_3_CS10KPU
#undef COMP_CSR_3_CS400KPD
#undef COMP_CSR_4_CMP1EN
#undef COMP_CSR_4_CMP2OUT
#undef COMP_CSR_5_SPEED
#undef COMP2_CSR_1_WNDWE
#undef COMP2_CSR_2_VREFOUTEN
#undef COMP2_CSR_2_OUTSEL
#undef COMP2_CSR_3_CS10KPU
#undef COMP2_CSR_3_CS10KPD
#undef COMP2_CSR_3_CMP1OUT
#undef COMP2_CSR_3_INSEL
#undef COMP2_CSR_4_CS400KPU
#undef COMP2_CSR_4_CS400KPD
#undef COMP2_CSR_5_CMP1EN
#undef COMP2_CSR_5_CMP2OUT
#undef COMP2_CSR_6_SPEED
#undef COMP4_CSR_1_WNDWE
#undef COMP4_CSR_1_OUTSEL
#undef COMP4_CSR_2_CS400KPU
#undef COMP4_CSR_2_VREFOUTEN
#undef COMP4_CSR_3_CS10KPD
#undef COMP4_CSR_3_CMP1OUT
#undef COMP4_CSR_3_INSEL
#undef COMP4_CSR_4_CS10KPU
#undef COMP4_CSR_4_CS400KPD
#undef COMP4_CSR_5_CMP1EN
#undef COMP4_CSR_5_CMP2OUT
#undef COMP4_CSR_6_SPEED
#undef COMP6_CSR_1_WNDWE
#undef COMP6_CSR_1_OUTSEL
#undef COMP6_CSR_2_CS400KPU
#undef COMP6_CSR_2_VREFOUTEN
#undef COMP6_CSR_3_CS10KPD
#undef COMP6_CSR_3_CMP1OUT
#undef COMP6_CSR_3_INSEL
#undef COMP6_CSR_4_CS10KPU
#undef COMP6_CSR_4_CS400KPD
#undef COMP6_CSR_5_CMP1EN
#undef COMP6_CSR_5_CMP2OUT
#undef COMP6_CSR_6_SPEED
#undef COMP1_CSR_1_WNDWE
#undef COMP1_CSR_1_OUTSEL
#undef COMP1_CSR_2_CS400KPU
#undef COMP1_CSR_2_CS10KPD
#undef COMP1_CSR_2_CMP1OUT
#undef COMP1_CSR_2_VREFOUTEN
#undef COMP1_CSR_3_CS10KPU
#undef COMP1_CSR_3_CS400KPD
#undef COMP1_CSR_3_INSEL
#undef COMP1_CSR_4_CMP1EN
#undef COMP1_CSR_5_CMP2OUT
#undef COMP1_CSR_6_SPEED
#undef COMP3_CSR_1_WNDWE
#undef COMP3_CSR_1_OUTSEL
#undef COMP3_CSR_2_CS400KPU
#undef COMP3_CSR_2_VREFOUTEN
#undef COMP3_CSR_3_CS10KPD
#undef COMP3_CSR_3_CMP1OUT
#undef COMP3_CSR_3_INSEL
#undef COMP3_CSR_4_CS10KPU
#undef COMP3_CSR_4_CS400KPD
#undef COMP3_CSR_5_CMP1EN
#undef COMP3_CSR_5_CMP2OUT
#undef COMP3_CSR_6_SPEED
#undef COMP5_CSR_1_WNDWE
#undef COMP5_CSR_1_OUTSEL
#undef COMP5_CSR_2_CS400KPU
#undef COMP5_CSR_2_VREFOUTEN
#undef COMP5_CSR_3_CS10KPD
#undef COMP5_CSR_3_CMP1OUT
#undef COMP5_CSR_3_INSEL
#undef COMP5_CSR_4_CS10KPU
#undef COMP5_CSR_4_CS400KPD
#undef COMP5_CSR_5_CMP1EN
#undef COMP5_CSR_5_CMP2OUT
#undef COMP5_CSR_6_SPEED
#undef COMP7_CSR_1_WNDWE
#undef COMP7_CSR_1_OUTSEL
#undef COMP7_CSR_2_CS400KPU
#undef COMP7_CSR_2_VREFOUTEN
#undef COMP7_CSR_3_CS10KPD
#undef COMP7_CSR_3_CMP1OUT
#undef COMP7_CSR_3_INSEL
#undef COMP7_CSR_4_CS10KPU
#undef COMP7_CSR_4_CS400KPD
#undef COMP7_CSR_5_CMP1EN
#undef COMP7_CSR_5_CMP2OUT
#undef COMP7_CSR_6_SPEED
#undef COMP_CSR_1_COMPxEN
#undef COMP2_CSR_0_COMP2LOCK
#undef COMP2_CSR_2_COMPxEN
#undef COMP4_CSR_2_COMPxEN
#undef COMP6_CSR_2_COMPxEN
#undef COMP1_CSR_1_COMPxEN
#undef COMP3_CSR_2_COMPxEN
#undef COMP5_CSR_2_COMPxEN
#undef COMP7_CSR_2_COMPxEN
#undef COMP_CSR_1_COMPxSW1
#undef COMP2_CSR_3_COMPxSW1
#undef COMP4_CSR_1_COMPxSW1
#undef COMP6_CSR_1_COMPxSW1
#undef COMP1_CSR_1_COMPxSW1
#undef COMP3_CSR_1_COMPxSW1
#undef COMP5_CSR_1_COMPxSW1
#undef COMP7_CSR_1_COMPxSW1
#undef COMP_CSR_1_COMPxMODE
#undef COMP2_CSR_2_COMPxMODE
#undef COMP4_CSR_2_COMPxMODE
#undef COMP6_CSR_2_COMPxMODE
#undef COMP1_CSR_0_COMP1MODE
#undef COMP1_CSR_1_COMPxMODE
#undef COMP3_CSR_2_COMPxMODE
#undef COMP5_CSR_2_COMPxMODE
#undef COMP7_CSR_2_COMPxMODE
#undef COMP_CSR_1_COMPxINSEL
#undef COMP2_CSR_2_COMPxINSEL
#undef COMP4_CSR_2_COMPxINSEL
#undef COMP6_CSR_2_COMPxINSEL
#undef COMP1_CSR_1_COMPxINSEL
#undef COMP3_CSR_2_COMPxINSEL
#undef COMP5_CSR_2_COMPxINSEL
#undef COMP7_CSR_2_COMPxINSEL
#undef COMP_CSR_1_COMPxWNDWEN
#undef COMP2_CSR_2_COMPxWNDWEN
#undef COMP4_CSR_2_COMPxWNDWEN
#undef COMP6_CSR_2_COMPxWNDWEN
#undef COMP1_CSR_1_COMPxWNDWEN
#undef COMP3_CSR_2_COMPxWNDWEN
#undef COMP5_CSR_2_COMPxWNDWEN
#undef COMP7_CSR_2_COMPxWNDWEN
#undef COMP_CSR_1_COMPxBLANKING
#undef COMP_CSR_2_COMPxOUTSEL
#undef COMP_CSR_2_COMPxPOL
#undef COMP_CSR_2_COMPxOUT
#undef COMP2_CSR_0_COMP2OUTSEL
#undef COMP2_CSR_0_COMP2POL
#undef COMP2_CSR_0_COMP2BLANKING
#undef COMP2_CSR_2_COMPxBLANKING
#undef COMP2_CSR_2_COMPxOUT
#undef COMP2_CSR_3_COMPxOUTSEL
#undef COMP2_CSR_3_COMPxPOL
#undef COMP4_CSR_0_COMP4EN
#undef COMP4_CSR_0_COMP4OUTSEL
#undef COMP4_CSR_0_COMP4POL
#undef COMP4_CSR_0_COMP4BLANKING
#undef COMP4_CSR_0_COMP4OUT
#undef COMP4_CSR_0_COMP4LOCK
#undef COMP4_CSR_2_COMPxBLANKING
#undef COMP4_CSR_3_COMPxOUTSEL
#undef COMP4_CSR_3_COMPxPOL
#undef COMP4_CSR_3_COMPxOUT
#undef COMP6_CSR_0_COMP6EN
#undef COMP6_CSR_0_COMP6OUTSEL
#undef COMP6_CSR_0_COMP6POL
#undef COMP6_CSR_0_COMP6BLANKING
#undef COMP6_CSR_0_COMP6OUT
#undef COMP6_CSR_0_COMP6LOCK
#undef COMP6_CSR_2_COMPxBLANKING
#undef COMP6_CSR_3_COMPxOUTSEL
#undef COMP6_CSR_3_COMPxPOL
#undef COMP6_CSR_3_COMPxOUT
#undef COMP1_CSR_2_COMPxBLANKING
#undef COMP1_CSR_3_COMPxOUTSEL
#undef COMP1_CSR_3_COMPxPOL
#undef COMP1_CSR_3_COMPxOUT
#undef COMP3_CSR_2_COMPxBLANKING
#undef COMP3_CSR_3_COMPxOUTSEL
#undef COMP3_CSR_3_COMPxPOL
#undef COMP3_CSR_3_COMPxOUT
#undef COMP5_CSR_2_COMPxBLANKING
#undef COMP5_CSR_3_COMPxOUTSEL
#undef COMP5_CSR_3_COMPxPOL
#undef COMP5_CSR_3_COMPxOUT
#undef COMP7_CSR_2_COMPxBLANKING
#undef COMP7_CSR_3_COMPxOUTSEL
#undef COMP7_CSR_3_COMPxPOL
#undef COMP7_CSR_3_COMPxOUT
#undef COMP_CSR_1_FCH3
#undef COMP_CSR_1_FCH8
#undef COMP_CSR_1_RCH13
#undef COMP_CSR_1_CAIE
#undef COMP_CSR_3_TSUSP
#undef COMP_CSR_5_CAIF
#undef COMP2_CSR_0_FCH3
#undef COMP2_CSR_0_FCH8
#undef COMP2_CSR_0_RCH13
#undef COMP2_CSR_0_CAIE
#undef COMP2_CSR_3_TSUSP
#undef COMP2_CSR_5_CAIF
#undef COMP4_CSR_1_FCH3
#undef COMP4_CSR_1_FCH8
#undef COMP4_CSR_1_RCH13
#undef COMP4_CSR_1_CAIE
#undef COMP4_CSR_4_TSUSP
#undef COMP4_CSR_6_CAIF
#undef COMP6_CSR_1_FCH3
#undef COMP6_CSR_1_FCH8
#undef COMP6_CSR_1_RCH13
#undef COMP6_CSR_1_CAIE
#undef COMP6_CSR_4_TSUSP
#undef COMP6_CSR_6_CAIF
#undef COMP1_CSR_1_FCH3
#undef COMP1_CSR_1_FCH8
#undef COMP1_CSR_1_RCH13
#undef COMP1_CSR_1_CAIE
#undef COMP1_CSR_2_TSUSP
#undef COMP1_CSR_6_CAIF
#undef COMP3_CSR_1_FCH3
#undef COMP3_CSR_1_FCH8
#undef COMP3_CSR_1_RCH13
#undef COMP3_CSR_1_CAIE
#undef COMP3_CSR_4_TSUSP
#undef COMP3_CSR_6_CAIF
#undef COMP5_CSR_1_FCH3
#undef COMP5_CSR_1_FCH8
#undef COMP5_CSR_1_RCH13
#undef COMP5_CSR_1_CAIE
#undef COMP5_CSR_4_TSUSP
#undef COMP5_CSR_6_CAIF
#undef COMP7_CSR_1_FCH3
#undef COMP7_CSR_1_FCH8
#undef COMP7_CSR_1_RCH13
#undef COMP7_CSR_1_CAIE
#undef COMP7_CSR_4_TSUSP
#undef COMP7_CSR_6_CAIF
#undef COMP_CSR_1_COMP1VALUE
#undef COMP_CSR_1_COMP1LOCK
#undef COMP_CSR_2_COMP2EN
#undef COMP_CSR_2_COMP2SPEED
#undef COMP_CSR_2_COMP1INNSEL
#undef COMP_CSR_2_COMP1WM
#undef COMP_CSR_3_COMP2INNSEL
#undef COMP_CSR_3_COMP2INPSEL
#undef COMP_CSR_3_COMP1LPTIM1IN1
#undef COMP_CSR_3_COMP2LPTIM1IN1
#undef COMP_CSR_3_COMP1POLARITY
#undef COMP_CSR_3_COMP2VALUE
#undef COMP_CSR_4_WINMODE
#undef COMP_CSR_4_COMP2LPTIM1IN2
#undef COMP_CSR_4_COMP2POLARITY
#undef COMP_CSR_4_COMPxOUTVALUE
#undef COMP_CSR_5_COMPxPOLARITY
#undef COMP2_CSR_0_COMP1WM
#undef COMP2_CSR_1_COMP1VALUE
#undef COMP2_CSR_2_COMP1LOCK
#undef COMP2_CSR_3_COMP2SPEED
#undef COMP2_CSR_3_COMP1INNSEL
#undef COMP2_CSR_3_WINMODE
#undef COMP2_CSR_3_COMP2VALUE
#undef COMP2_CSR_4_COMP2INNSEL
#undef COMP2_CSR_4_COMP2INPSEL
#undef COMP2_CSR_4_COMP1LPTIM1IN1
#undef COMP2_CSR_4_COMP2LPTIM1IN1
#undef COMP2_CSR_4_COMP1POLARITY
#undef COMP2_CSR_4_COMPxOUTVALUE
#undef COMP2_CSR_5_COMP2LPTIM1IN2
#undef COMP2_CSR_5_COMP2POLARITY
#undef COMP2_CSR_6_COMPxPOLARITY
#undef COMP4_CSR_0_COMP1WM
#undef COMP4_CSR_2_COMP1VALUE
#undef COMP4_CSR_2_COMP1LOCK
#undef COMP4_CSR_3_COMP2EN
#undef COMP4_CSR_3_COMP2SPEED
#undef COMP4_CSR_3_COMP1INNSEL
#undef COMP4_CSR_3_WINMODE
#undef COMP4_CSR_4_COMP2INNSEL
#undef COMP4_CSR_4_COMP2INPSEL
#undef COMP4_CSR_4_COMP1LPTIM1IN1
#undef COMP4_CSR_4_COMP2LPTIM1IN1
#undef COMP4_CSR_4_COMP1POLARITY
#undef COMP4_CSR_4_COMP2VALUE
#undef COMP4_CSR_5_COMP2LPTIM1IN2
#undef COMP4_CSR_5_COMP2POLARITY
#undef COMP4_CSR_5_COMPxOUTVALUE
#undef COMP4_CSR_6_COMPxPOLARITY
#undef COMP6_CSR_0_COMP1WM
#undef COMP6_CSR_2_COMP1VALUE
#undef COMP6_CSR_2_COMP1LOCK
#undef COMP6_CSR_3_COMP2EN
#undef COMP6_CSR_3_COMP2SPEED
#undef COMP6_CSR_3_COMP1INNSEL
#undef COMP6_CSR_3_WINMODE
#undef COMP6_CSR_4_COMP2INNSEL
#undef COMP6_CSR_4_COMP2INPSEL
#undef COMP6_CSR_4_COMP1LPTIM1IN1
#undef COMP6_CSR_4_COMP2LPTIM1IN1
#undef COMP6_CSR_4_COMP1POLARITY
#undef COMP6_CSR_4_COMP2VALUE
#undef COMP6_CSR_5_COMP2LPTIM1IN2
#undef COMP6_CSR_5_COMP2POLARITY
#undef COMP6_CSR_5_COMPxOUTVALUE
#undef COMP6_CSR_6_COMPxPOLARITY
#undef COMP1_CSR_0_COMP1WM
#undef COMP1_CSR_2_COMP2EN
#undef COMP1_CSR_2_COMP2SPEED
#undef COMP1_CSR_2_COMP1INNSEL
#undef COMP1_CSR_2_COMP1VALUE
#undef COMP1_CSR_3_COMP2INNSEL
#undef COMP1_CSR_3_WINMODE
#undef COMP1_CSR_4_COMP2INPSEL
#undef COMP1_CSR_4_COMP1LPTIM1IN1
#undef COMP1_CSR_4_COMP2LPTIM1IN1
#undef COMP1_CSR_4_COMP1POLARITY
#undef COMP1_CSR_4_COMP2VALUE
#undef COMP1_CSR_5_COMP2LPTIM1IN2
#undef COMP1_CSR_5_COMP2POLARITY
#undef COMP1_CSR_5_COMPxOUTVALUE
#undef COMP1_CSR_6_COMPxPOLARITY
#undef COMP3_CSR_0_COMP1WM
#undef COMP3_CSR_2_COMP1VALUE
#undef COMP3_CSR_2_COMP1LOCK
#undef COMP3_CSR_3_COMP2EN
#undef COMP3_CSR_3_COMP2SPEED
#undef COMP3_CSR_3_COMP1INNSEL
#undef COMP3_CSR_3_WINMODE
#undef COMP3_CSR_4_COMP2INNSEL
#undef COMP3_CSR_4_COMP2INPSEL
#undef COMP3_CSR_4_COMP1LPTIM1IN1
#undef COMP3_CSR_4_COMP2LPTIM1IN1
#undef COMP3_CSR_4_COMP1POLARITY
#undef COMP3_CSR_4_COMP2VALUE
#undef COMP3_CSR_5_COMP2LPTIM1IN2
#undef COMP3_CSR_5_COMP2POLARITY
#undef COMP3_CSR_5_COMPxOUTVALUE
#undef COMP3_CSR_6_COMPxPOLARITY
#undef COMP5_CSR_0_COMP1WM
#undef COMP5_CSR_2_COMP1VALUE
#undef COMP5_CSR_2_COMP1LOCK
#undef COMP5_CSR_3_COMP2EN
#undef COMP5_CSR_3_COMP2SPEED
#undef COMP5_CSR_3_COMP1INNSEL
#undef COMP5_CSR_3_WINMODE
#undef COMP5_CSR_4_COMP2INNSEL
#undef COMP5_CSR_4_COMP2INPSEL
#undef COMP5_CSR_4_COMP1LPTIM1IN1
#undef COMP5_CSR_4_COMP2LPTIM1IN1
#undef COMP5_CSR_4_COMP1POLARITY
#undef COMP5_CSR_4_COMP2VALUE
#undef COMP5_CSR_5_COMP2LPTIM1IN2
#undef COMP5_CSR_5_COMP2POLARITY
#undef COMP5_CSR_5_COMPxOUTVALUE
#undef COMP5_CSR_6_COMPxPOLARITY
#undef COMP7_CSR_0_COMP1WM
#undef COMP7_CSR_2_COMP1VALUE
#undef COMP7_CSR_2_COMP1LOCK
#undef COMP7_CSR_3_COMP2EN
#undef COMP7_CSR_3_COMP2SPEED
#undef COMP7_CSR_3_COMP1INNSEL
#undef COMP7_CSR_3_WINMODE
#undef COMP7_CSR_4_COMP2INNSEL
#undef COMP7_CSR_4_COMP2INPSEL
#undef COMP7_CSR_4_COMP1LPTIM1IN1
#undef COMP7_CSR_4_COMP2LPTIM1IN1
#undef COMP7_CSR_4_COMP1POLARITY
#undef COMP7_CSR_4_COMP2VALUE
#undef COMP7_CSR_5_COMP2LPTIM1IN2
#undef COMP7_CSR_5_COMP2POLARITY
#undef COMP7_CSR_5_COMPxOUTVALUE
#undef COMP7_CSR_6_COMPxPOLARITY
#undef COMP_CSR_2_BRGEN
#undef COMP_CSR_2_SCALEN
#undef COMP_CSR_3_HYST
#undef COMP_CSR_3_BLANKING
#undef COMP_CSR_4_EN
#undef COMP_CSR_4_PWRMODE
#undef COMP_CSR_4_LOCK
#undef COMP_CSR_5_INMSEL
#undef COMP_CSR_5_WINMODE
#undef COMP2_CSR_0_BRGEN
#undef COMP2_CSR_1_SCALEN
#undef COMP2_CSR_4_EN
#undef COMP2_CSR_4_HYST
#undef COMP2_CSR_4_BLANKING
#undef COMP2_CSR_4_LOCK
#undef COMP2_CSR_5_PWRMODE
#undef COMP2_CSR_5_WINMODE
#undef COMP2_CSR_6_INMSEL
#undef COMP2_CSR_6_VALUE
#undef COMP4_CSR_2_BRGEN
#undef COMP4_CSR_2_SCALEN
#undef COMP4_CSR_4_HYST
#undef COMP4_CSR_4_BLANKING
#undef COMP4_CSR_5_EN
#undef COMP4_CSR_5_PWRMODE
#undef COMP4_CSR_5_WINMODE
#undef COMP4_CSR_5_LOCK
#undef COMP4_CSR_6_INMSEL
#undef COMP6_CSR_2_BRGEN
#undef COMP6_CSR_2_SCALEN
#undef COMP6_CSR_4_HYST
#undef COMP6_CSR_4_BLANKING
#undef COMP6_CSR_5_EN
#undef COMP6_CSR_5_PWRMODE
#undef COMP6_CSR_5_WINMODE
#undef COMP6_CSR_5_LOCK
#undef COMP6_CSR_6_INMSEL
#undef COMP1_CSR_2_BRGEN
#undef COMP1_CSR_2_SCALEN
#undef COMP1_CSR_4_EN
#undef COMP1_CSR_4_PWRMODE
#undef COMP1_CSR_4_HYST
#undef COMP1_CSR_4_BLANKING
#undef COMP1_CSR_4_LOCK
#undef COMP1_CSR_5_INMSEL
#undef COMP1_CSR_5_WINMODE
#undef COMP3_CSR_2_BRGEN
#undef COMP3_CSR_2_SCALEN
#undef COMP3_CSR_4_HYST
#undef COMP3_CSR_4_BLANKING
#undef COMP3_CSR_5_EN
#undef COMP3_CSR_5_PWRMODE
#undef COMP3_CSR_5_WINMODE
#undef COMP3_CSR_5_LOCK
#undef COMP3_CSR_6_INMSEL
#undef COMP5_CSR_2_BRGEN
#undef COMP5_CSR_2_SCALEN
#undef COMP5_CSR_4_HYST
#undef COMP5_CSR_4_BLANKING
#undef COMP5_CSR_5_EN
#undef COMP5_CSR_5_PWRMODE
#undef COMP5_CSR_5_WINMODE
#undef COMP5_CSR_5_LOCK
#undef COMP5_CSR_6_INMSEL
#undef COMP7_CSR_2_BRGEN
#undef COMP7_CSR_2_SCALEN
#undef COMP7_CSR_4_HYST
#undef COMP7_CSR_4_BLANKING
#undef COMP7_CSR_5_EN
#undef COMP7_CSR_5_PWRMODE
#undef COMP7_CSR_5_WINMODE
#undef COMP7_CSR_5_LOCK
#undef COMP7_CSR_6_INMSEL
#undef COMP_CSR_2_INMESEL
#undef COMP_CSR_5_INPSEL
#undef COMP2_CSR_2_INMESEL
#undef COMP2_CSR_5_INPSEL
#undef COMP4_CSR_2_INMESEL
#undef COMP4_CSR_5_INPSEL
#undef COMP6_CSR_2_INMESEL
#undef COMP6_CSR_5_INPSEL
#undef COMP1_CSR_2_INMESEL
#undef COMP1_CSR_5_INPSEL
#undef COMP3_CSR_2_INMESEL
#undef COMP3_CSR_5_INPSEL
#undef COMP5_CSR_2_INMESEL
#undef COMP5_CSR_5_INPSEL
#undef COMP7_CSR_2_INMESEL
#undef COMP7_CSR_5_INPSEL
#undef COMP_CSR_2_COMPxLOCK
#undef COMP2_CSR_0_COMP2EN
#undef COMP2_CSR_1_COMPxLOCK
#undef COMP4_CSR_3_COMPxLOCK
#undef COMP6_CSR_3_COMPxLOCK
#undef COMP1_CSR_3_COMPxLOCK
#undef COMP3_CSR_3_COMPxLOCK
#undef COMP5_CSR_3_COMPxLOCK
#undef COMP7_CSR_3_COMPxLOCK
#undef COMP_CSR_3_INPSEL
#undef COMP2_CSR_4_INPSEL
#undef COMP4_CSR_4_INPSEL
#undef COMP6_CSR_4_INPSEL
#undef COMP1_CSR_3_INPSEL
#undef COMP3_CSR_4_INPSEL
#undef COMP5_CSR_4_INPSEL
#undef COMP7_CSR_4_INPSEL
#undef COMP_CSR_4_SW1
#undef COMP2_CSR_5_SW1
#undef COMP4_CSR_5_SW1
#undef COMP6_CSR_5_SW1
#undef COMP1_CSR_4_SW1
#undef COMP3_CSR_5_SW1
#undef COMP5_CSR_5_SW1
#undef COMP7_CSR_5_SW1
#undef COMP2_CSR_0_COMP2SW1
#undef COMP2_CSR_1_COMP2INPDAC
#undef COMP2_CSR_0_COMP2INSEL
#undef COMP4_CSR_0_COMP4INSEL
#undef COMP6_CSR_0_COMP6INSEL
#undef COMP2_CSR_0_COMP2OUT
#undef COMP4_CSR_0_COMP4WNDWEN
#undef COMP6_CSR_0_COMP6WNDWEN
#undef COMP3_CSR_0_COMP3MODE
#undef COMP3_CSR_0_COMP3NONINSEL
#undef COMP3_CSR_0_COMP3HYST
#undef COMP5_CSR_0_COMP5MODE
#undef COMP5_CSR_0_COMP5NONINSEL
#undef COMP5_CSR_0_COMP5HYST
#undef COMP7_CSR_0_COMP7MODE
#undef COMP7_CSR_0_COMP7NONINSEL
#undef COMP7_CSR_0_COMP7HYST
#undef COMP1_CSR_0_COMP1SW1
#undef COMP1_CSR_0_COMP1INSEL
#undef COMP1_CSR_0_COMP1OUTSEL
#undef COMP1_CSR_0_COMP1POL
#undef COMP1_CSR_0_COMP1BLANKING
#undef COMP1_CSR_0_COMP1OUT
#undef COMP1_CSR_0_COMP1LOCK
#undef COMP3_CSR_0_COMP3EN
#undef COMP3_CSR_0_COMP3INSEL
#undef COMP3_CSR_0_COMP3OUTSEL
#undef COMP3_CSR_0_COMP3POL
#undef COMP3_CSR_0_COMP3BLANKING
#undef COMP3_CSR_0_COMP3OUT
#undef COMP3_CSR_0_COMP3LOCK
#undef COMP5_CSR_0_COMP5EN
#undef COMP5_CSR_0_COMP5INSEL
#undef COMP5_CSR_0_COMP5OUTSEL
#undef COMP5_CSR_0_COMP5POL
#undef COMP5_CSR_0_COMP5BLANKING
#undef COMP5_CSR_0_COMP5OUT
#undef COMP5_CSR_0_COMP5LOCK
#undef COMP7_CSR_0_COMP7EN
#undef COMP7_CSR_0_COMP7INSEL
#undef COMP7_CSR_0_COMP7OUTSEL
#undef COMP7_CSR_0_COMP7POL
#undef COMP7_CSR_0_COMP7BLANKING
#undef COMP7_CSR_0_COMP7OUT
#undef COMP7_CSR_0_COMP7LOCK
//endregion
#endif
#endif
