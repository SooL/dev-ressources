#ifndef __SOOL_OPAMP_H
#define __SOOL_OPAMP_H

#include "peripheral_include.h"
//SOOL-OPAMP-INCLUDES
#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F398xx ) ||\
    defined(STM32H7     ) || defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) ||\
    defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) ||\
    defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
//region defines

#define OPAMP_CSR
#define OPAMP_Common_CSR

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F398xx ) ||\
    defined(STM32H7     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define OPAMP_CSR_0_OPAMPxEN OPAMPxEN             // 1 bits @ 0
#define OPAMP2_CSR_2_OPAMPxEN OPAMPxEN             // 1 bits @ 0
#define OPAMP1_CSR_2_OPAMPxEN OPAMPxEN             // 1 bits @ 0
#define OPAMP3_CSR_1_OPAMPxEN OPAMPxEN             // 1 bits @ 0
#define OPAMP4_CSR_1_OPAMPxEN OPAMPxEN             // 1 bits @ 0
#else
#define OPAMP_CSR_0_OPAMPxEN
#define OPAMP2_CSR_2_OPAMPxEN
#define OPAMP1_CSR_2_OPAMPxEN
#define OPAMP3_CSR_1_OPAMPxEN
#define OPAMP4_CSR_1_OPAMPxEN
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F398xx ) ||\
    defined(STM32H7     ) 
#define OPAMP_CSR_0_FORCEVP  FORCEVP              // 1 bits @ 1
#define OPAMP_CSR_0_VPSEL    VPSEL                // 2 bits @ 2
#define OPAMP_CSR_0_VMSEL    VMSEL                // 2 bits @ 5
#define OPAMP_CSR_0_CALON    CALON                // 1 bits @ 11
#define OPAMP_CSR_0_CALSEL   CALSEL               // 2 bits @ 12
#define OPAMP_CSR_0_PGGAIN   PGGAIN               // 4 bits @ 14
#define OPAMP_CSR_0_USERTRIM USERTRIM             // 1 bits @ 18
#define OPAMP_CSR_0_TSTREF   TSTREF               // 1 bits @ 29
#define OPAMP2_CSR_0_FORCEVP FORCEVP              // 1 bits @ 1
#define OPAMP2_CSR_0_VPSEL   VPSEL                // 2 bits @ 2
#define OPAMP2_CSR_0_VMSEL   VMSEL                // 2 bits @ 5
#define OPAMP2_CSR_0_CALON   CALON                // 1 bits @ 11
#define OPAMP2_CSR_0_CALSEL  CALSEL               // 2 bits @ 12
#define OPAMP2_CSR_0_PGGAIN  PGGAIN               // 4 bits @ 14
#define OPAMP2_CSR_0_USERTRIM USERTRIM             // 1 bits @ 18
#define OPAMP2_CSR_0_TSTREF  TSTREF               // 1 bits @ 29
#define OPAMP1_CSR_0_FORCEVP FORCEVP              // 1 bits @ 1
#define OPAMP1_CSR_0_VPSEL   VPSEL                // 2 bits @ 2
#define OPAMP1_CSR_0_VMSEL   VMSEL                // 2 bits @ 5
#define OPAMP1_CSR_0_CALON   CALON                // 1 bits @ 11
#define OPAMP1_CSR_0_CALSEL  CALSEL               // 2 bits @ 12
#define OPAMP1_CSR_0_PGGAIN  PGGAIN               // 4 bits @ 14
#define OPAMP1_CSR_0_USERTRIM USERTRIM             // 1 bits @ 18
#define OPAMP1_CSR_0_TSTREF  TSTREF               // 1 bits @ 29
#define OPAMP3_CSR_0_FORCEVP FORCEVP              // 1 bits @ 1
#define OPAMP3_CSR_0_VPSEL   VPSEL                // 2 bits @ 2
#define OPAMP3_CSR_0_VMSEL   VMSEL                // 2 bits @ 5
#define OPAMP3_CSR_0_CALON   CALON                // 1 bits @ 11
#define OPAMP3_CSR_0_CALSEL  CALSEL               // 2 bits @ 12
#define OPAMP3_CSR_0_PGGAIN  PGGAIN               // 4 bits @ 14
#define OPAMP3_CSR_0_USERTRIM USERTRIM             // 1 bits @ 18
#define OPAMP3_CSR_0_TSTREF  TSTREF               // 1 bits @ 29
#define OPAMP4_CSR_0_FORCEVP FORCEVP              // 1 bits @ 1
#define OPAMP4_CSR_0_VPSEL   VPSEL                // 2 bits @ 2
#define OPAMP4_CSR_0_VMSEL   VMSEL                // 2 bits @ 5
#define OPAMP4_CSR_0_CALON   CALON                // 1 bits @ 11
#define OPAMP4_CSR_0_CALSEL  CALSEL               // 2 bits @ 12
#define OPAMP4_CSR_0_PGGAIN  PGGAIN               // 4 bits @ 14
#define OPAMP4_CSR_0_USERTRIM USERTRIM             // 1 bits @ 18
#define OPAMP4_CSR_0_TSTREF  TSTREF               // 1 bits @ 29
#else
#define OPAMP_CSR_0_FORCEVP
#define OPAMP_CSR_0_VPSEL
#define OPAMP_CSR_0_VMSEL
#define OPAMP_CSR_0_CALON
#define OPAMP_CSR_0_CALSEL
#define OPAMP_CSR_0_PGGAIN
#define OPAMP_CSR_0_USERTRIM
#define OPAMP_CSR_0_TSTREF
#define OPAMP2_CSR_0_FORCEVP
#define OPAMP2_CSR_0_VPSEL
#define OPAMP2_CSR_0_VMSEL
#define OPAMP2_CSR_0_CALON
#define OPAMP2_CSR_0_CALSEL
#define OPAMP2_CSR_0_PGGAIN
#define OPAMP2_CSR_0_USERTRIM
#define OPAMP2_CSR_0_TSTREF
#define OPAMP1_CSR_0_FORCEVP
#define OPAMP1_CSR_0_VPSEL
#define OPAMP1_CSR_0_VMSEL
#define OPAMP1_CSR_0_CALON
#define OPAMP1_CSR_0_CALSEL
#define OPAMP1_CSR_0_PGGAIN
#define OPAMP1_CSR_0_USERTRIM
#define OPAMP1_CSR_0_TSTREF
#define OPAMP3_CSR_0_FORCEVP
#define OPAMP3_CSR_0_VPSEL
#define OPAMP3_CSR_0_VMSEL
#define OPAMP3_CSR_0_CALON
#define OPAMP3_CSR_0_CALSEL
#define OPAMP3_CSR_0_PGGAIN
#define OPAMP3_CSR_0_USERTRIM
#define OPAMP3_CSR_0_TSTREF
#define OPAMP4_CSR_0_FORCEVP
#define OPAMP4_CSR_0_VPSEL
#define OPAMP4_CSR_0_VMSEL
#define OPAMP4_CSR_0_CALON
#define OPAMP4_CSR_0_CALSEL
#define OPAMP4_CSR_0_PGGAIN
#define OPAMP4_CSR_0_USERTRIM
#define OPAMP4_CSR_0_TSTREF
#endif

#if defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) || defined(STM32L151xDx) ||\
    defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) || defined(STM32L152xD ) ||\
    defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) || defined(STM32L162xCA) ||\
    defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define OPAMP_CSR_0_S6SEL1   S6SEL1               // 1 bits @ 4
#define OPAMP_CSR_1_OPA1PD   OPA1PD               // 1 bits @ 0
#define OPAMP_CSR_1_S3SEL1   S3SEL1               // 1 bits @ 1
#define OPAMP_CSR_1_S4SEL1   S4SEL1               // 1 bits @ 2
#define OPAMP_CSR_1_S5SEL1   S5SEL1               // 1 bits @ 3
#define OPAMP_CSR_1_OPA1CAL_L OPA1CAL_L            // 1 bits @ 5
#define OPAMP_CSR_1_OPA1CAL_H OPA1CAL_H            // 1 bits @ 6
#define OPAMP_CSR_1_OPA1LPM  OPA1LPM              // 1 bits @ 7
#define OPAMP_CSR_1_S3SEL2   S3SEL2               // 1 bits @ 9
#define OPAMP_CSR_1_S4SEL2   S4SEL2               // 1 bits @ 10
#define OPAMP_CSR_1_S5SEL2   S5SEL2               // 1 bits @ 11
#define OPAMP_CSR_1_S6SEL2   S6SEL2               // 1 bits @ 12
#define OPAMP_CSR_1_OPA2CAL_L OPA2CAL_L            // 1 bits @ 13
#define OPAMP_CSR_1_OPA2CAL_H OPA2CAL_H            // 1 bits @ 14
#define OPAMP_CSR_1_OPA2LPM  OPA2LPM              // 1 bits @ 15
#define OPAMP_CSR_1_ANAWSEL1 ANAWSEL1             // 1 bits @ 24
#define OPAMP_CSR_1_ANAWSEL2 ANAWSEL2             // 1 bits @ 25
#define OPAMP_CSR_1_S7SEL2   S7SEL2               // 1 bits @ 27
#define OPAMP_CSR_1_AOP_RANGE AOP_RANGE            // 1 bits @ 28
#define OPAMP_CSR_1_OPA1CALOUT OPA1CALOUT           // 1 bits @ 29
#define OPAMP_CSR_2_OPA2PD   OPA2PD               // 1 bits @ 8
#define OPAMP_CSR_2_OPA2CALOUT OPA2CALOUT           // 1 bits @ 30
#define OPAMP_OTR_0_AO2_OPT_OFFSET_TRIM_HIGH AO2_OPT_OFFSET_TRIM_HIGH // 5 bits @ 15
#define OPAMP_OTR_0_OT_USER  OT_USER              // 1 bits @ 31
#define OPAMP_OTR_1
#define OPAMP_OTR_2
#define OPAMP_Common_OTR
#define OPAMP_Common_MAP0_OTR uint32_t OTR
#define OPAMP2_CSR_0_S6SEL1  S6SEL1               // 1 bits @ 4
#define OPAMP2_CSR_1_OPA1CAL_H OPA1CAL_H            // 1 bits @ 6
#define OPAMP2_CSR_1_OPA1LPM OPA1LPM              // 1 bits @ 7
#define OPAMP2_CSR_1_S3SEL2  S3SEL2               // 1 bits @ 9
#define OPAMP2_CSR_1_S5SEL2  S5SEL2               // 1 bits @ 11
#define OPAMP2_CSR_1_OPA2LPM OPA2LPM              // 1 bits @ 15
#define OPAMP2_CSR_1_ANAWSEL1 ANAWSEL1             // 1 bits @ 24
#define OPAMP2_CSR_1_ANAWSEL2 ANAWSEL2             // 1 bits @ 25
#define OPAMP2_CSR_1_S7SEL2  S7SEL2               // 1 bits @ 27
#define OPAMP2_CSR_1_AOP_RANGE AOP_RANGE            // 1 bits @ 28
#define OPAMP2_CSR_1_OPA1CALOUT OPA1CALOUT           // 1 bits @ 29
#define OPAMP2_CSR_2_S3SEL1  S3SEL1               // 1 bits @ 1
#define OPAMP2_CSR_2_S4SEL1  S4SEL1               // 1 bits @ 2
#define OPAMP2_CSR_2_S5SEL1  S5SEL1               // 1 bits @ 3
#define OPAMP2_CSR_2_OPA1CAL_L OPA1CAL_L            // 1 bits @ 5
#define OPAMP2_CSR_2_S4SEL2  S4SEL2               // 1 bits @ 10
#define OPAMP2_CSR_2_S6SEL2  S6SEL2               // 1 bits @ 12
#define OPAMP2_CSR_2_OPA2CAL_L OPA2CAL_L            // 1 bits @ 13
#define OPAMP2_CSR_2_OPA2CAL_H OPA2CAL_H            // 1 bits @ 14
#define OPAMP2_CSR_2_OPA2CALOUT OPA2CALOUT           // 1 bits @ 30
#define OPAMP2_CSR_3_OPA1PD  OPA1PD               // 1 bits @ 0
#define OPAMP2_CSR_3_OPA2PD  OPA2PD               // 1 bits @ 8
#define OPAMP2_OTR_0_AO2_OPT_OFFSET_TRIM_HIGH AO2_OPT_OFFSET_TRIM_HIGH // 5 bits @ 15
#define OPAMP2_OTR_0_OT_USER OT_USER              // 1 bits @ 31
#define OPAMP2_OTR_1
#define OPAMP2_OTR_2
#define OPAMP1_CSR_0_S6SEL1  S6SEL1               // 1 bits @ 4
#define OPAMP1_CSR_1_OPA1CAL_H OPA1CAL_H            // 1 bits @ 6
#define OPAMP1_CSR_1_OPA1LPM OPA1LPM              // 1 bits @ 7
#define OPAMP1_CSR_1_S3SEL2  S3SEL2               // 1 bits @ 9
#define OPAMP1_CSR_1_S5SEL2  S5SEL2               // 1 bits @ 11
#define OPAMP1_CSR_1_OPA2LPM OPA2LPM              // 1 bits @ 15
#define OPAMP1_CSR_1_ANAWSEL1 ANAWSEL1             // 1 bits @ 24
#define OPAMP1_CSR_1_ANAWSEL2 ANAWSEL2             // 1 bits @ 25
#define OPAMP1_CSR_1_S7SEL2  S7SEL2               // 1 bits @ 27
#define OPAMP1_CSR_1_AOP_RANGE AOP_RANGE            // 1 bits @ 28
#define OPAMP1_CSR_1_OPA1CALOUT OPA1CALOUT           // 1 bits @ 29
#define OPAMP1_CSR_2_S3SEL1  S3SEL1               // 1 bits @ 1
#define OPAMP1_CSR_2_S4SEL1  S4SEL1               // 1 bits @ 2
#define OPAMP1_CSR_2_S5SEL1  S5SEL1               // 1 bits @ 3
#define OPAMP1_CSR_2_OPA1CAL_L OPA1CAL_L            // 1 bits @ 5
#define OPAMP1_CSR_2_S4SEL2  S4SEL2               // 1 bits @ 10
#define OPAMP1_CSR_2_S6SEL2  S6SEL2               // 1 bits @ 12
#define OPAMP1_CSR_2_OPA2CAL_L OPA2CAL_L            // 1 bits @ 13
#define OPAMP1_CSR_2_OPA2CAL_H OPA2CAL_H            // 1 bits @ 14
#define OPAMP1_CSR_2_OPA2CALOUT OPA2CALOUT           // 1 bits @ 30
#define OPAMP1_CSR_3_OPA1PD  OPA1PD               // 1 bits @ 0
#define OPAMP1_CSR_3_OPA2PD  OPA2PD               // 1 bits @ 8
#define OPAMP1_OTR_0_AO2_OPT_OFFSET_TRIM_HIGH AO2_OPT_OFFSET_TRIM_HIGH // 5 bits @ 15
#define OPAMP1_OTR_0_OT_USER OT_USER              // 1 bits @ 31
#define OPAMP1_OTR_1
#define OPAMP1_OTR_2
#define OPAMP3_CSR_0_S6SEL1  S6SEL1               // 1 bits @ 4
#define OPAMP3_CSR_1_S3SEL1  S3SEL1               // 1 bits @ 1
#define OPAMP3_CSR_1_S4SEL1  S4SEL1               // 1 bits @ 2
#define OPAMP3_CSR_1_S5SEL1  S5SEL1               // 1 bits @ 3
#define OPAMP3_CSR_1_OPA1CAL_L OPA1CAL_L            // 1 bits @ 5
#define OPAMP3_CSR_1_OPA1CAL_H OPA1CAL_H            // 1 bits @ 6
#define OPAMP3_CSR_1_OPA1LPM OPA1LPM              // 1 bits @ 7
#define OPAMP3_CSR_1_S3SEL2  S3SEL2               // 1 bits @ 9
#define OPAMP3_CSR_1_S4SEL2  S4SEL2               // 1 bits @ 10
#define OPAMP3_CSR_1_S5SEL2  S5SEL2               // 1 bits @ 11
#define OPAMP3_CSR_1_S6SEL2  S6SEL2               // 1 bits @ 12
#define OPAMP3_CSR_1_OPA2CAL_L OPA2CAL_L            // 1 bits @ 13
#define OPAMP3_CSR_1_OPA2CAL_H OPA2CAL_H            // 1 bits @ 14
#define OPAMP3_CSR_1_OPA2LPM OPA2LPM              // 1 bits @ 15
#define OPAMP3_CSR_1_ANAWSEL1 ANAWSEL1             // 1 bits @ 24
#define OPAMP3_CSR_1_ANAWSEL2 ANAWSEL2             // 1 bits @ 25
#define OPAMP3_CSR_1_S7SEL2  S7SEL2               // 1 bits @ 27
#define OPAMP3_CSR_1_AOP_RANGE AOP_RANGE            // 1 bits @ 28
#define OPAMP3_CSR_1_OPA1CALOUT OPA1CALOUT           // 1 bits @ 29
#define OPAMP3_CSR_2_OPA1PD  OPA1PD               // 1 bits @ 0
#define OPAMP3_CSR_2_OPA2PD  OPA2PD               // 1 bits @ 8
#define OPAMP3_CSR_2_OPA2CALOUT OPA2CALOUT           // 1 bits @ 30
#define OPAMP4_CSR_0_S6SEL1  S6SEL1               // 1 bits @ 4
#define OPAMP4_CSR_1_S3SEL1  S3SEL1               // 1 bits @ 1
#define OPAMP4_CSR_1_S4SEL1  S4SEL1               // 1 bits @ 2
#define OPAMP4_CSR_1_S5SEL1  S5SEL1               // 1 bits @ 3
#define OPAMP4_CSR_1_OPA1CAL_L OPA1CAL_L            // 1 bits @ 5
#define OPAMP4_CSR_1_OPA1CAL_H OPA1CAL_H            // 1 bits @ 6
#define OPAMP4_CSR_1_OPA1LPM OPA1LPM              // 1 bits @ 7
#define OPAMP4_CSR_1_S3SEL2  S3SEL2               // 1 bits @ 9
#define OPAMP4_CSR_1_S4SEL2  S4SEL2               // 1 bits @ 10
#define OPAMP4_CSR_1_S5SEL2  S5SEL2               // 1 bits @ 11
#define OPAMP4_CSR_1_S6SEL2  S6SEL2               // 1 bits @ 12
#define OPAMP4_CSR_1_OPA2CAL_L OPA2CAL_L            // 1 bits @ 13
#define OPAMP4_CSR_1_OPA2CAL_H OPA2CAL_H            // 1 bits @ 14
#define OPAMP4_CSR_1_OPA2LPM OPA2LPM              // 1 bits @ 15
#define OPAMP4_CSR_1_ANAWSEL1 ANAWSEL1             // 1 bits @ 24
#define OPAMP4_CSR_1_ANAWSEL2 ANAWSEL2             // 1 bits @ 25
#define OPAMP4_CSR_1_S7SEL2  S7SEL2               // 1 bits @ 27
#define OPAMP4_CSR_1_AOP_RANGE AOP_RANGE            // 1 bits @ 28
#define OPAMP4_CSR_1_OPA1CALOUT OPA1CALOUT           // 1 bits @ 29
#define OPAMP4_CSR_2_OPA1PD  OPA1PD               // 1 bits @ 0
#define OPAMP4_CSR_2_OPA2PD  OPA2PD               // 1 bits @ 8
#define OPAMP4_CSR_2_OPA2CALOUT OPA2CALOUT           // 1 bits @ 30
#else
#define OPAMP_CSR_0_S6SEL1
#define OPAMP_CSR_1_OPA1PD
#define OPAMP_CSR_1_S3SEL1
#define OPAMP_CSR_1_S4SEL1
#define OPAMP_CSR_1_S5SEL1
#define OPAMP_CSR_1_OPA1CAL_L
#define OPAMP_CSR_1_OPA1CAL_H
#define OPAMP_CSR_1_OPA1LPM
#define OPAMP_CSR_1_S3SEL2
#define OPAMP_CSR_1_S4SEL2
#define OPAMP_CSR_1_S5SEL2
#define OPAMP_CSR_1_S6SEL2
#define OPAMP_CSR_1_OPA2CAL_L
#define OPAMP_CSR_1_OPA2CAL_H
#define OPAMP_CSR_1_OPA2LPM
#define OPAMP_CSR_1_ANAWSEL1
#define OPAMP_CSR_1_ANAWSEL2
#define OPAMP_CSR_1_S7SEL2
#define OPAMP_CSR_1_AOP_RANGE
#define OPAMP_CSR_1_OPA1CALOUT
#define OPAMP_CSR_2_OPA2PD
#define OPAMP_CSR_2_OPA2CALOUT
#define OPAMP_OTR_0_AO2_OPT_OFFSET_TRIM_HIGH
#define OPAMP_OTR_0_OT_USER
#define OPAMP_Common_MAP0_OTR __SOOL_PERIPH_PADDING_4
#define OPAMP2_CSR_0_S6SEL1
#define OPAMP2_CSR_1_OPA1CAL_H
#define OPAMP2_CSR_1_OPA1LPM
#define OPAMP2_CSR_1_S3SEL2
#define OPAMP2_CSR_1_S5SEL2
#define OPAMP2_CSR_1_OPA2LPM
#define OPAMP2_CSR_1_ANAWSEL1
#define OPAMP2_CSR_1_ANAWSEL2
#define OPAMP2_CSR_1_S7SEL2
#define OPAMP2_CSR_1_AOP_RANGE
#define OPAMP2_CSR_1_OPA1CALOUT
#define OPAMP2_CSR_2_S3SEL1
#define OPAMP2_CSR_2_S4SEL1
#define OPAMP2_CSR_2_S5SEL1
#define OPAMP2_CSR_2_OPA1CAL_L
#define OPAMP2_CSR_2_S4SEL2
#define OPAMP2_CSR_2_S6SEL2
#define OPAMP2_CSR_2_OPA2CAL_L
#define OPAMP2_CSR_2_OPA2CAL_H
#define OPAMP2_CSR_2_OPA2CALOUT
#define OPAMP2_CSR_3_OPA1PD
#define OPAMP2_CSR_3_OPA2PD
#define OPAMP2_OTR_0_AO2_OPT_OFFSET_TRIM_HIGH
#define OPAMP2_OTR_0_OT_USER
#define OPAMP1_CSR_0_S6SEL1
#define OPAMP1_CSR_1_OPA1CAL_H
#define OPAMP1_CSR_1_OPA1LPM
#define OPAMP1_CSR_1_S3SEL2
#define OPAMP1_CSR_1_S5SEL2
#define OPAMP1_CSR_1_OPA2LPM
#define OPAMP1_CSR_1_ANAWSEL1
#define OPAMP1_CSR_1_ANAWSEL2
#define OPAMP1_CSR_1_S7SEL2
#define OPAMP1_CSR_1_AOP_RANGE
#define OPAMP1_CSR_1_OPA1CALOUT
#define OPAMP1_CSR_2_S3SEL1
#define OPAMP1_CSR_2_S4SEL1
#define OPAMP1_CSR_2_S5SEL1
#define OPAMP1_CSR_2_OPA1CAL_L
#define OPAMP1_CSR_2_S4SEL2
#define OPAMP1_CSR_2_S6SEL2
#define OPAMP1_CSR_2_OPA2CAL_L
#define OPAMP1_CSR_2_OPA2CAL_H
#define OPAMP1_CSR_2_OPA2CALOUT
#define OPAMP1_CSR_3_OPA1PD
#define OPAMP1_CSR_3_OPA2PD
#define OPAMP1_OTR_0_AO2_OPT_OFFSET_TRIM_HIGH
#define OPAMP1_OTR_0_OT_USER
#define OPAMP3_CSR_0_S6SEL1
#define OPAMP3_CSR_1_S3SEL1
#define OPAMP3_CSR_1_S4SEL1
#define OPAMP3_CSR_1_S5SEL1
#define OPAMP3_CSR_1_OPA1CAL_L
#define OPAMP3_CSR_1_OPA1CAL_H
#define OPAMP3_CSR_1_OPA1LPM
#define OPAMP3_CSR_1_S3SEL2
#define OPAMP3_CSR_1_S4SEL2
#define OPAMP3_CSR_1_S5SEL2
#define OPAMP3_CSR_1_S6SEL2
#define OPAMP3_CSR_1_OPA2CAL_L
#define OPAMP3_CSR_1_OPA2CAL_H
#define OPAMP3_CSR_1_OPA2LPM
#define OPAMP3_CSR_1_ANAWSEL1
#define OPAMP3_CSR_1_ANAWSEL2
#define OPAMP3_CSR_1_S7SEL2
#define OPAMP3_CSR_1_AOP_RANGE
#define OPAMP3_CSR_1_OPA1CALOUT
#define OPAMP3_CSR_2_OPA1PD
#define OPAMP3_CSR_2_OPA2PD
#define OPAMP3_CSR_2_OPA2CALOUT
#define OPAMP4_CSR_0_S6SEL1
#define OPAMP4_CSR_1_S3SEL1
#define OPAMP4_CSR_1_S4SEL1
#define OPAMP4_CSR_1_S5SEL1
#define OPAMP4_CSR_1_OPA1CAL_L
#define OPAMP4_CSR_1_OPA1CAL_H
#define OPAMP4_CSR_1_OPA1LPM
#define OPAMP4_CSR_1_S3SEL2
#define OPAMP4_CSR_1_S4SEL2
#define OPAMP4_CSR_1_S5SEL2
#define OPAMP4_CSR_1_S6SEL2
#define OPAMP4_CSR_1_OPA2CAL_L
#define OPAMP4_CSR_1_OPA2CAL_H
#define OPAMP4_CSR_1_OPA2LPM
#define OPAMP4_CSR_1_ANAWSEL1
#define OPAMP4_CSR_1_ANAWSEL2
#define OPAMP4_CSR_1_S7SEL2
#define OPAMP4_CSR_1_AOP_RANGE
#define OPAMP4_CSR_1_OPA1CALOUT
#define OPAMP4_CSR_2_OPA1PD
#define OPAMP4_CSR_2_OPA2PD
#define OPAMP4_CSR_2_OPA2CALOUT
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F398xx ) 
#define OPAMP_CSR_0_TCMEN    TCMEN                // 1 bits @ 7
#define OPAMP_CSR_0_VMSSEL   VMSSEL               // 1 bits @ 8
#define OPAMP_CSR_0_VPSSEL   VPSSEL               // 2 bits @ 9
#define OPAMP_CSR_0_TRIMOFFSETP TRIMOFFSETP          // 5 bits @ 19
#define OPAMP_CSR_0_TRIMOFFSETN TRIMOFFSETN          // 5 bits @ 24
#define OPAMP_CSR_0_OUTCAL   OUTCAL               // 1 bits @ 30
#define OPAMP_CSR_0_LOCK     LOCK                 // 1 bits @ 31
#define OPAMP2_CSR_0_OPAMP2EN OPAMP2EN             // 1 bits @ 0
#define OPAMP2_CSR_0_TCMEN   TCMEN                // 1 bits @ 7
#define OPAMP2_CSR_0_VMSSEL  VMSSEL               // 1 bits @ 8
#define OPAMP2_CSR_0_VPSSEL  VPSSEL               // 2 bits @ 9
#define OPAMP2_CSR_0_TRIMOFFSETP TRIMOFFSETP          // 5 bits @ 19
#define OPAMP2_CSR_0_TRIMOFFSETN TRIMOFFSETN          // 5 bits @ 24
#define OPAMP2_CSR_0_OUTCAL  OUTCAL               // 1 bits @ 30
#define OPAMP2_CSR_0_LOCK    LOCK                 // 1 bits @ 31
#define OPAMP1_CSR_0_TCMEN   TCMEN                // 1 bits @ 7
#define OPAMP1_CSR_0_VMSSEL  VMSSEL               // 1 bits @ 8
#define OPAMP1_CSR_0_VPSSEL  VPSSEL               // 2 bits @ 9
#define OPAMP1_CSR_0_TRIMOFFSETP TRIMOFFSETP          // 5 bits @ 19
#define OPAMP1_CSR_0_TRIMOFFSETN TRIMOFFSETN          // 5 bits @ 24
#define OPAMP1_CSR_0_OUTCAL  OUTCAL               // 1 bits @ 30
#define OPAMP1_CSR_0_LOCK    LOCK                 // 1 bits @ 31
#define OPAMP3_CSR_0_TCMEN   TCMEN                // 1 bits @ 7
#define OPAMP3_CSR_0_VMSSEL  VMSSEL               // 1 bits @ 8
#define OPAMP3_CSR_0_VPSSEL  VPSSEL               // 2 bits @ 9
#define OPAMP3_CSR_0_TRIMOFFSETP TRIMOFFSETP          // 5 bits @ 19
#define OPAMP3_CSR_0_TRIMOFFSETN TRIMOFFSETN          // 5 bits @ 24
#define OPAMP3_CSR_0_OUTCAL  OUTCAL               // 1 bits @ 30
#define OPAMP3_CSR_0_LOCK    LOCK                 // 1 bits @ 31
#define OPAMP4_CSR_0_TCMEN   TCMEN                // 1 bits @ 7
#define OPAMP4_CSR_0_VMSSEL  VMSSEL               // 1 bits @ 8
#define OPAMP4_CSR_0_VPSSEL  VPSSEL               // 2 bits @ 9
#define OPAMP4_CSR_0_TRIMOFFSETP TRIMOFFSETP          // 5 bits @ 19
#define OPAMP4_CSR_0_TRIMOFFSETN TRIMOFFSETN          // 5 bits @ 24
#define OPAMP4_CSR_0_OUTCAL  OUTCAL               // 1 bits @ 30
#define OPAMP4_CSR_0_LOCK    LOCK                 // 1 bits @ 31
#else
#define OPAMP_CSR_0_TCMEN
#define OPAMP_CSR_0_VMSSEL
#define OPAMP_CSR_0_VPSSEL
#define OPAMP_CSR_0_TRIMOFFSETP
#define OPAMP_CSR_0_TRIMOFFSETN
#define OPAMP_CSR_0_OUTCAL
#define OPAMP_CSR_0_LOCK
#define OPAMP2_CSR_0_OPAMP2EN
#define OPAMP2_CSR_0_TCMEN
#define OPAMP2_CSR_0_VMSSEL
#define OPAMP2_CSR_0_VPSSEL
#define OPAMP2_CSR_0_TRIMOFFSETP
#define OPAMP2_CSR_0_TRIMOFFSETN
#define OPAMP2_CSR_0_OUTCAL
#define OPAMP2_CSR_0_LOCK
#define OPAMP1_CSR_0_TCMEN
#define OPAMP1_CSR_0_VMSSEL
#define OPAMP1_CSR_0_VPSSEL
#define OPAMP1_CSR_0_TRIMOFFSETP
#define OPAMP1_CSR_0_TRIMOFFSETN
#define OPAMP1_CSR_0_OUTCAL
#define OPAMP1_CSR_0_LOCK
#define OPAMP3_CSR_0_TCMEN
#define OPAMP3_CSR_0_VMSSEL
#define OPAMP3_CSR_0_VPSSEL
#define OPAMP3_CSR_0_TRIMOFFSETP
#define OPAMP3_CSR_0_TRIMOFFSETN
#define OPAMP3_CSR_0_OUTCAL
#define OPAMP3_CSR_0_LOCK
#define OPAMP4_CSR_0_TCMEN
#define OPAMP4_CSR_0_VMSSEL
#define OPAMP4_CSR_0_VPSSEL
#define OPAMP4_CSR_0_TRIMOFFSETP
#define OPAMP4_CSR_0_TRIMOFFSETN
#define OPAMP4_CSR_0_OUTCAL
#define OPAMP4_CSR_0_LOCK
#endif

#if defined(STM32H7     ) || defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) ||\
    defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) ||\
    defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define OPAMP_CSR_1
#endif

#if defined(STM32H7     ) 
#define OPAMP_CSR_1_OPAHSM   OPAHSM               // 1 bits @ 8
#define OPAMP_CSR_1_CALOUT   CALOUT               // 1 bits @ 30
#define OPAMP_HSOTR
#define OPAMP_MAP0_HSOTR     typename plugin::HSOTR_TypeDef HSOTR
#define OPAMP2_CSR_1_OPAHSM  OPAHSM               // 1 bits @ 8
#define OPAMP2_CSR_1_CALOUT  CALOUT               // 1 bits @ 30
#define OPAMP1_CSR_1_OPAHSM  OPAHSM               // 1 bits @ 8
#define OPAMP1_CSR_1_CALOUT  CALOUT               // 1 bits @ 30
#define OPAMP3_CSR_1_OPAHSM  OPAHSM               // 1 bits @ 8
#define OPAMP3_CSR_1_CALOUT  CALOUT               // 1 bits @ 30
#define OPAMP4_CSR_1_OPAHSM  OPAHSM               // 1 bits @ 8
#define OPAMP4_CSR_1_CALOUT  CALOUT               // 1 bits @ 30
#else
#define OPAMP_CSR_1_OPAHSM
#define OPAMP_CSR_1_CALOUT
#define OPAMP_MAP0_HSOTR __SOOL_PERIPH_PADDING_4
#define OPAMP2_CSR_1_OPAHSM
#define OPAMP2_CSR_1_CALOUT
#define OPAMP1_CSR_1_OPAHSM
#define OPAMP1_CSR_1_CALOUT
#define OPAMP3_CSR_1_OPAHSM
#define OPAMP3_CSR_1_CALOUT
#define OPAMP4_CSR_1_OPAHSM
#define OPAMP4_CSR_1_CALOUT
#endif

#if defined(STM32L151xD ) || defined(STM32L152xD ) || defined(STM32L162xD ) 
#define OPAMP_CSR_1_OPA3PD   OPA3PD               // 1 bits @ 16
#define OPAMP_CSR_1_S3SEL3   S3SEL3               // 1 bits @ 17
#define OPAMP_CSR_1_S4SEL3   S4SEL3               // 1 bits @ 18
#define OPAMP_CSR_1_S5SEL3   S5SEL3               // 1 bits @ 19
#define OPAMP_CSR_1_S6SEL3   S6SEL3               // 1 bits @ 20
#define OPAMP_CSR_1_OPA3CAL_L OPA3CAL_L            // 1 bits @ 21
#define OPAMP_CSR_1_OPA3CAL_H OPA3CAL_H            // 1 bits @ 22
#define OPAMP_CSR_1_OPA3LPM  OPA3LPM              // 1 bits @ 23
#define OPAMP_CSR_1_ANAWSEL3 ANAWSEL3             // 1 bits @ 26
#define OPAMP_CSR_1_OPA3CALOUT OPA3CALOUT           // 1 bits @ 31
#define OPAMP_OTR_0_AO3_OPT_OFFSET_TRIM_LOW AO3_OPT_OFFSET_TRIM_LOW // 5 bits @ 20
#define OPAMP_OTR_0_AO3_OPT_OFFSET_TRIM_HIGH AO3_OPT_OFFSET_TRIM_HIGH // 5 bits @ 25
#define OPAMP_OTR_1_AO3_OPT_OFFSET_TRIM_LP_LOW AO3_OPT_OFFSET_TRIM_LP_LOW // 5 bits @ 20
#define OPAMP_OTR_1_AO3_OPT_OFFSET_TRIM_LP_HIGH AO3_OPT_OFFSET_TRIM_LP_HIGH // 5 bits @ 25
#define OPAMP2_CSR_1_OPA3PD  OPA3PD               // 1 bits @ 16
#define OPAMP2_CSR_1_S3SEL3  S3SEL3               // 1 bits @ 17
#define OPAMP2_CSR_1_S4SEL3  S4SEL3               // 1 bits @ 18
#define OPAMP2_CSR_1_S5SEL3  S5SEL3               // 1 bits @ 19
#define OPAMP2_CSR_1_S6SEL3  S6SEL3               // 1 bits @ 20
#define OPAMP2_CSR_1_OPA3CAL_L OPA3CAL_L            // 1 bits @ 21
#define OPAMP2_CSR_1_OPA3CAL_H OPA3CAL_H            // 1 bits @ 22
#define OPAMP2_CSR_1_OPA3LPM OPA3LPM              // 1 bits @ 23
#define OPAMP2_CSR_1_ANAWSEL3 ANAWSEL3             // 1 bits @ 26
#define OPAMP2_CSR_1_OPA3CALOUT OPA3CALOUT           // 1 bits @ 31
#define OPAMP2_OTR_0_AO3_OPT_OFFSET_TRIM_LOW AO3_OPT_OFFSET_TRIM_LOW // 5 bits @ 20
#define OPAMP2_OTR_0_AO3_OPT_OFFSET_TRIM_HIGH AO3_OPT_OFFSET_TRIM_HIGH // 5 bits @ 25
#define OPAMP2_OTR_1_AO3_OPT_OFFSET_TRIM_LP_LOW AO3_OPT_OFFSET_TRIM_LP_LOW // 5 bits @ 20
#define OPAMP2_OTR_1_AO3_OPT_OFFSET_TRIM_LP_HIGH AO3_OPT_OFFSET_TRIM_LP_HIGH // 5 bits @ 25
#define OPAMP1_CSR_1_OPA3PD  OPA3PD               // 1 bits @ 16
#define OPAMP1_CSR_1_S3SEL3  S3SEL3               // 1 bits @ 17
#define OPAMP1_CSR_1_S4SEL3  S4SEL3               // 1 bits @ 18
#define OPAMP1_CSR_1_S5SEL3  S5SEL3               // 1 bits @ 19
#define OPAMP1_CSR_1_S6SEL3  S6SEL3               // 1 bits @ 20
#define OPAMP1_CSR_1_OPA3CAL_L OPA3CAL_L            // 1 bits @ 21
#define OPAMP1_CSR_1_OPA3CAL_H OPA3CAL_H            // 1 bits @ 22
#define OPAMP1_CSR_1_OPA3LPM OPA3LPM              // 1 bits @ 23
#define OPAMP1_CSR_1_ANAWSEL3 ANAWSEL3             // 1 bits @ 26
#define OPAMP1_CSR_2_OPA3CALOUT OPA3CALOUT           // 1 bits @ 31
#define OPAMP1_OTR_0_AO3_OPT_OFFSET_TRIM_LOW AO3_OPT_OFFSET_TRIM_LOW // 5 bits @ 20
#define OPAMP1_OTR_0_AO3_OPT_OFFSET_TRIM_HIGH AO3_OPT_OFFSET_TRIM_HIGH // 5 bits @ 25
#define OPAMP1_OTR_1_AO3_OPT_OFFSET_TRIM_LP_LOW AO3_OPT_OFFSET_TRIM_LP_LOW // 5 bits @ 20
#define OPAMP1_OTR_1_AO3_OPT_OFFSET_TRIM_LP_HIGH AO3_OPT_OFFSET_TRIM_LP_HIGH // 5 bits @ 25
#define OPAMP3_CSR_1_OPA3PD  OPA3PD               // 1 bits @ 16
#define OPAMP3_CSR_1_S3SEL3  S3SEL3               // 1 bits @ 17
#define OPAMP3_CSR_1_S4SEL3  S4SEL3               // 1 bits @ 18
#define OPAMP3_CSR_1_S5SEL3  S5SEL3               // 1 bits @ 19
#define OPAMP3_CSR_1_S6SEL3  S6SEL3               // 1 bits @ 20
#define OPAMP3_CSR_1_OPA3CAL_L OPA3CAL_L            // 1 bits @ 21
#define OPAMP3_CSR_1_OPA3CAL_H OPA3CAL_H            // 1 bits @ 22
#define OPAMP3_CSR_1_OPA3LPM OPA3LPM              // 1 bits @ 23
#define OPAMP3_CSR_1_ANAWSEL3 ANAWSEL3             // 1 bits @ 26
#define OPAMP3_CSR_1_OPA3CALOUT OPA3CALOUT           // 1 bits @ 31
#define OPAMP4_CSR_1_OPA3PD  OPA3PD               // 1 bits @ 16
#define OPAMP4_CSR_1_S3SEL3  S3SEL3               // 1 bits @ 17
#define OPAMP4_CSR_1_S4SEL3  S4SEL3               // 1 bits @ 18
#define OPAMP4_CSR_1_S5SEL3  S5SEL3               // 1 bits @ 19
#define OPAMP4_CSR_1_S6SEL3  S6SEL3               // 1 bits @ 20
#define OPAMP4_CSR_1_OPA3CAL_L OPA3CAL_L            // 1 bits @ 21
#define OPAMP4_CSR_1_OPA3CAL_H OPA3CAL_H            // 1 bits @ 22
#define OPAMP4_CSR_1_OPA3LPM OPA3LPM              // 1 bits @ 23
#define OPAMP4_CSR_1_ANAWSEL3 ANAWSEL3             // 1 bits @ 26
#define OPAMP4_CSR_1_OPA3CALOUT OPA3CALOUT           // 1 bits @ 31
#else
#define OPAMP_CSR_1_OPA3PD
#define OPAMP_CSR_1_S3SEL3
#define OPAMP_CSR_1_S4SEL3
#define OPAMP_CSR_1_S5SEL3
#define OPAMP_CSR_1_S6SEL3
#define OPAMP_CSR_1_OPA3CAL_L
#define OPAMP_CSR_1_OPA3CAL_H
#define OPAMP_CSR_1_OPA3LPM
#define OPAMP_CSR_1_ANAWSEL3
#define OPAMP_CSR_1_OPA3CALOUT
#define OPAMP_OTR_0_AO3_OPT_OFFSET_TRIM_LOW
#define OPAMP_OTR_0_AO3_OPT_OFFSET_TRIM_HIGH
#define OPAMP_OTR_1_AO3_OPT_OFFSET_TRIM_LP_LOW
#define OPAMP_OTR_1_AO3_OPT_OFFSET_TRIM_LP_HIGH
#define OPAMP2_CSR_1_OPA3PD
#define OPAMP2_CSR_1_S3SEL3
#define OPAMP2_CSR_1_S4SEL3
#define OPAMP2_CSR_1_S5SEL3
#define OPAMP2_CSR_1_S6SEL3
#define OPAMP2_CSR_1_OPA3CAL_L
#define OPAMP2_CSR_1_OPA3CAL_H
#define OPAMP2_CSR_1_OPA3LPM
#define OPAMP2_CSR_1_ANAWSEL3
#define OPAMP2_CSR_1_OPA3CALOUT
#define OPAMP2_OTR_0_AO3_OPT_OFFSET_TRIM_LOW
#define OPAMP2_OTR_0_AO3_OPT_OFFSET_TRIM_HIGH
#define OPAMP2_OTR_1_AO3_OPT_OFFSET_TRIM_LP_LOW
#define OPAMP2_OTR_1_AO3_OPT_OFFSET_TRIM_LP_HIGH
#define OPAMP1_CSR_1_OPA3PD
#define OPAMP1_CSR_1_S3SEL3
#define OPAMP1_CSR_1_S4SEL3
#define OPAMP1_CSR_1_S5SEL3
#define OPAMP1_CSR_1_S6SEL3
#define OPAMP1_CSR_1_OPA3CAL_L
#define OPAMP1_CSR_1_OPA3CAL_H
#define OPAMP1_CSR_1_OPA3LPM
#define OPAMP1_CSR_1_ANAWSEL3
#define OPAMP1_CSR_2_OPA3CALOUT
#define OPAMP1_OTR_0_AO3_OPT_OFFSET_TRIM_LOW
#define OPAMP1_OTR_0_AO3_OPT_OFFSET_TRIM_HIGH
#define OPAMP1_OTR_1_AO3_OPT_OFFSET_TRIM_LP_LOW
#define OPAMP1_OTR_1_AO3_OPT_OFFSET_TRIM_LP_HIGH
#define OPAMP3_CSR_1_OPA3PD
#define OPAMP3_CSR_1_S3SEL3
#define OPAMP3_CSR_1_S4SEL3
#define OPAMP3_CSR_1_S5SEL3
#define OPAMP3_CSR_1_S6SEL3
#define OPAMP3_CSR_1_OPA3CAL_L
#define OPAMP3_CSR_1_OPA3CAL_H
#define OPAMP3_CSR_1_OPA3LPM
#define OPAMP3_CSR_1_ANAWSEL3
#define OPAMP3_CSR_1_OPA3CALOUT
#define OPAMP4_CSR_1_OPA3PD
#define OPAMP4_CSR_1_S3SEL3
#define OPAMP4_CSR_1_S4SEL3
#define OPAMP4_CSR_1_S5SEL3
#define OPAMP4_CSR_1_S6SEL3
#define OPAMP4_CSR_1_OPA3CAL_L
#define OPAMP4_CSR_1_OPA3CAL_H
#define OPAMP4_CSR_1_OPA3LPM
#define OPAMP4_CSR_1_ANAWSEL3
#define OPAMP4_CSR_1_OPA3CALOUT
#endif

#if defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) || defined(STM32L151xDx) ||\
    defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) || defined(STM32L152xD ) ||\
    defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) || defined(STM32L162xCA) ||\
    defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) || defined(STM32L4     ) ||\
    defined(STM32L4P    ) 
#define OPAMP_CSR_2
#define OPAMP_LPOTR
#define OPAMP_MAP1_LPOTR     typename plugin::LPOTR_TypeDef LPOTR
#define OPAMP2_CSR_3
#define OPAMP1_CSR_3
#define OPAMP3_CSR_2
#define OPAMP4_CSR_2
#else
#define OPAMP_MAP1_LPOTR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32L4     ) || defined(STM32L4P    ) 
#define OPAMP_CSR_2_OPALPM   OPALPM               // 1 bits @ 1
#define OPAMP_CSR_2_OPAMODE  OPAMODE              // 2 bits @ 2
#define OPAMP_CSR_2_PGGAIN   PGGAIN               // 2 bits @ 4
#define OPAMP_CSR_2_VPSEL    VPSEL                // 1 bits @ 10
#define OPAMP_CSR_2_CALON    CALON                // 1 bits @ 12
#define OPAMP_CSR_2_CALSEL   CALSEL               // 1 bits @ 13
#define OPAMP_CSR_2_USERTRIM USERTRIM             // 1 bits @ 14
#define OPAMP_CSR_2_CALOUT   CALOUT               // 1 bits @ 15
#define OPAMP_CSR_3
#define OPAMP2_CSR_1_OPALPM  OPALPM               // 1 bits @ 1
#define OPAMP2_CSR_1_OPAMODE OPAMODE              // 2 bits @ 2
#define OPAMP2_CSR_1_VPSEL   VPSEL                // 1 bits @ 10
#define OPAMP2_CSR_1_CALON   CALON                // 1 bits @ 12
#define OPAMP2_CSR_1_CALSEL  CALSEL               // 1 bits @ 13
#define OPAMP2_CSR_1_USERTRIM USERTRIM             // 1 bits @ 14
#define OPAMP2_CSR_2_VMSEL   VMSEL                // 2 bits @ 8
#define OPAMP2_CSR_2_CALOUT  CALOUT               // 1 bits @ 15
#define OPAMP2_CSR_3_PGGAIN  PGGAIN               // 2 bits @ 4
#define OPAMP1_CSR_1_OPALPM  OPALPM               // 1 bits @ 1
#define OPAMP1_CSR_1_OPAMODE OPAMODE              // 2 bits @ 2
#define OPAMP1_CSR_1_PGAGAIN PGAGAIN              // 2 bits @ 4
#define OPAMP1_CSR_1_VPSEL   VPSEL                // 1 bits @ 10
#define OPAMP1_CSR_1_CALON   CALON                // 1 bits @ 12
#define OPAMP1_CSR_1_CALSEL  CALSEL               // 1 bits @ 13
#define OPAMP1_CSR_1_USERTRIM USERTRIM             // 1 bits @ 14
#define OPAMP1_CSR_1_OPARANGE OPARANGE             // 1 bits @ 31
#define OPAMP1_CSR_2_VMSEL   VMSEL                // 2 bits @ 8
#define OPAMP1_CSR_2_CALOUT  CALOUT               // 1 bits @ 15
#define OPAMP1_CSR_3_PGGAIN  PGGAIN               // 2 bits @ 4
#define OPAMP3_CSR_2_OPALPM  OPALPM               // 1 bits @ 1
#define OPAMP3_CSR_2_OPAMODE OPAMODE              // 2 bits @ 2
#define OPAMP3_CSR_2_PGGAIN  PGGAIN               // 2 bits @ 4
#define OPAMP3_CSR_2_VPSEL   VPSEL                // 1 bits @ 10
#define OPAMP3_CSR_2_CALON   CALON                // 1 bits @ 12
#define OPAMP3_CSR_2_CALSEL  CALSEL               // 1 bits @ 13
#define OPAMP3_CSR_2_USERTRIM USERTRIM             // 1 bits @ 14
#define OPAMP3_CSR_2_CALOUT  CALOUT               // 1 bits @ 15
#define OPAMP3_CSR_3
#define OPAMP4_CSR_2_OPALPM  OPALPM               // 1 bits @ 1
#define OPAMP4_CSR_2_OPAMODE OPAMODE              // 2 bits @ 2
#define OPAMP4_CSR_2_PGGAIN  PGGAIN               // 2 bits @ 4
#define OPAMP4_CSR_2_VPSEL   VPSEL                // 1 bits @ 10
#define OPAMP4_CSR_2_CALON   CALON                // 1 bits @ 12
#define OPAMP4_CSR_2_CALSEL  CALSEL               // 1 bits @ 13
#define OPAMP4_CSR_2_USERTRIM USERTRIM             // 1 bits @ 14
#define OPAMP4_CSR_2_CALOUT  CALOUT               // 1 bits @ 15
#define OPAMP4_CSR_3
#else
#define OPAMP_CSR_2_OPALPM
#define OPAMP_CSR_2_OPAMODE
#define OPAMP_CSR_2_PGGAIN
#define OPAMP_CSR_2_VPSEL
#define OPAMP_CSR_2_CALON
#define OPAMP_CSR_2_CALSEL
#define OPAMP_CSR_2_USERTRIM
#define OPAMP_CSR_2_CALOUT
#define OPAMP2_CSR_1_OPALPM
#define OPAMP2_CSR_1_OPAMODE
#define OPAMP2_CSR_1_VPSEL
#define OPAMP2_CSR_1_CALON
#define OPAMP2_CSR_1_CALSEL
#define OPAMP2_CSR_1_USERTRIM
#define OPAMP2_CSR_2_VMSEL
#define OPAMP2_CSR_2_CALOUT
#define OPAMP2_CSR_3_PGGAIN
#define OPAMP1_CSR_1_OPALPM
#define OPAMP1_CSR_1_OPAMODE
#define OPAMP1_CSR_1_PGAGAIN
#define OPAMP1_CSR_1_VPSEL
#define OPAMP1_CSR_1_CALON
#define OPAMP1_CSR_1_CALSEL
#define OPAMP1_CSR_1_USERTRIM
#define OPAMP1_CSR_1_OPARANGE
#define OPAMP1_CSR_2_VMSEL
#define OPAMP1_CSR_2_CALOUT
#define OPAMP1_CSR_3_PGGAIN
#define OPAMP3_CSR_2_OPALPM
#define OPAMP3_CSR_2_OPAMODE
#define OPAMP3_CSR_2_PGGAIN
#define OPAMP3_CSR_2_VPSEL
#define OPAMP3_CSR_2_CALON
#define OPAMP3_CSR_2_CALSEL
#define OPAMP3_CSR_2_USERTRIM
#define OPAMP3_CSR_2_CALOUT
#define OPAMP4_CSR_2_OPALPM
#define OPAMP4_CSR_2_OPAMODE
#define OPAMP4_CSR_2_PGGAIN
#define OPAMP4_CSR_2_VPSEL
#define OPAMP4_CSR_2_CALON
#define OPAMP4_CSR_2_CALSEL
#define OPAMP4_CSR_2_USERTRIM
#define OPAMP4_CSR_2_CALOUT
#endif

#if defined(STM32H7     ) || defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) ||\
    defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) ||\
    defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
#define OPAMP_OTR
#define OPAMP_MAP0_OTR       typename plugin::OTR_TypeDef OTR
#define OPAMP2_CSR_1
#define OPAMP1_CSR_1
#else
#define OPAMP_MAP0_OTR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32H7     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define OPAMP_OTR_0_TRIMOFFSETN TRIMOFFSETN          // 5 bits @ 0
#define OPAMP_OTR_0_TRIMOFFSETP TRIMOFFSETP          // 5 bits @ 8
#define OPAMP2_OTR_0_TRIMOFFSETN TRIMOFFSETN          // 5 bits @ 0
#define OPAMP2_OTR_0_TRIMOFFSETP TRIMOFFSETP          // 5 bits @ 8
#define OPAMP1_CSR_1_OPAEN   OPAEN                // 1 bits @ 0
#define OPAMP1_OTR_0_TRIMOFFSETN TRIMOFFSETN          // 5 bits @ 0
#define OPAMP1_OTR_0_TRIMOFFSETP TRIMOFFSETP          // 5 bits @ 8
#else
#define OPAMP_OTR_0_TRIMOFFSETN
#define OPAMP_OTR_0_TRIMOFFSETP
#define OPAMP2_OTR_0_TRIMOFFSETN
#define OPAMP2_OTR_0_TRIMOFFSETP
#define OPAMP1_CSR_1_OPAEN
#define OPAMP1_OTR_0_TRIMOFFSETN
#define OPAMP1_OTR_0_TRIMOFFSETP
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F398xx ) ||\
    defined(STM32H7     ) || defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) ||\
    defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) ||\
    defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 

#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F398xx ) ||\
    defined(STM32H7     ) || defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) ||\
    defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) ||\
    defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define OPAMP2_CSR_0
#define OPAMP1_CSR_0
#define OPAMP3_CSR_0
#define OPAMP4_CSR_0
#endif

#if defined(STM32H7     ) || defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) ||\
    defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) ||\
    defined(STM32L4P    ) 
#define OPAMP2_CSR_1_OPAEN   OPAEN                // 1 bits @ 0
#else
#define OPAMP2_CSR_1_OPAEN
#endif

#if defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define OPAMP2_CSR_1_PGAGAIN PGAGAIN              // 2 bits @ 4
#else
#define OPAMP2_CSR_1_PGAGAIN
#endif

#if defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) || defined(STM32F303xE ) ||\
    defined(STM32F358xx ) || defined(STM32F398xx ) 
#define OPAMP1_CSR_0_OPAMP1EN OPAMP1EN             // 1 bits @ 0
#else
#define OPAMP1_CSR_0_OPAMP1EN
#endif

#if defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F358xx ) || defined(STM32F398xx ) 
#define OPAMP3_CSR_0_OPAMP3EN OPAMP3EN             // 1 bits @ 0
#define OPAMP4_CSR_0_OPAMP4EN OPAMP4EN             // 1 bits @ 0
#else
#define OPAMP3_CSR_0_OPAMP3EN
#define OPAMP4_CSR_0_OPAMP4EN
#endif

//endregion

namespace sool
{
	namespace core
	{struct OPAMP_base_plugin
		{
		
			#ifdef OPAMP_CSR
			struct CSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t OPAMP_CSR_0_OPAMPxEN :1;
						uint32_t OPAMP_CSR_0_FORCEVP  :1;
						uint32_t OPAMP_CSR_0_VPSEL    :2;
						uint32_t OPAMP_CSR_0_S6SEL1   :1;
						uint32_t OPAMP_CSR_0_VMSEL    :2;
						uint32_t OPAMP_CSR_0_TCMEN    :1;
						uint32_t OPAMP_CSR_0_VMSSEL   :1;
						uint32_t OPAMP_CSR_0_VPSSEL   :2;
						uint32_t OPAMP_CSR_0_CALON    :1;
						uint32_t OPAMP_CSR_0_CALSEL   :2;
						uint32_t OPAMP_CSR_0_PGGAIN   :4;
						uint32_t OPAMP_CSR_0_USERTRIM :1;
						uint32_t OPAMP_CSR_0_TRIMOFFSETP :5;
						uint32_t OPAMP_CSR_0_TRIMOFFSETN :5;
						uint32_t OPAMP_CSR_0_TSTREF   :1;
						uint32_t OPAMP_CSR_0_OUTCAL   :1;
						uint32_t OPAMP_CSR_0_LOCK     :1;
					};
					#ifdef OPAMP_CSR_1
					struct
					{
						uint32_t OPAMP_CSR_1_OPA1PD   :1;
						uint32_t OPAMP_CSR_1_S3SEL1   :1;
						uint32_t OPAMP_CSR_1_S4SEL1   :1;
						uint32_t OPAMP_CSR_1_S5SEL1   :1;
						uint32_t                      :1;
						uint32_t OPAMP_CSR_1_OPA1CAL_L :1;
						uint32_t OPAMP_CSR_1_OPA1CAL_H :1;
						uint32_t OPAMP_CSR_1_OPA1LPM  :1;
						uint32_t OPAMP_CSR_1_OPAHSM   :1;
						uint32_t OPAMP_CSR_1_S3SEL2   :1;
						uint32_t OPAMP_CSR_1_S4SEL2   :1;
						uint32_t OPAMP_CSR_1_S5SEL2   :1;
						uint32_t OPAMP_CSR_1_S6SEL2   :1;
						uint32_t OPAMP_CSR_1_OPA2CAL_L :1;
						uint32_t OPAMP_CSR_1_OPA2CAL_H :1;
						uint32_t OPAMP_CSR_1_OPA2LPM  :1;
						uint32_t OPAMP_CSR_1_OPA3PD   :1;
						uint32_t OPAMP_CSR_1_S3SEL3   :1;
						uint32_t OPAMP_CSR_1_S4SEL3   :1;
						uint32_t OPAMP_CSR_1_S5SEL3   :1;
						uint32_t OPAMP_CSR_1_S6SEL3   :1;
						uint32_t OPAMP_CSR_1_OPA3CAL_L :1;
						uint32_t OPAMP_CSR_1_OPA3CAL_H :1;
						uint32_t OPAMP_CSR_1_OPA3LPM  :1;
						uint32_t OPAMP_CSR_1_ANAWSEL1 :1;
						uint32_t OPAMP_CSR_1_ANAWSEL2 :1;
						uint32_t OPAMP_CSR_1_ANAWSEL3 :1;
						uint32_t OPAMP_CSR_1_S7SEL2   :1;
						uint32_t OPAMP_CSR_1_AOP_RANGE :1;
						uint32_t OPAMP_CSR_1_OPA1CALOUT :1;
						uint32_t OPAMP_CSR_1_CALOUT   :1;
						uint32_t OPAMP_CSR_1_OPA3CALOUT :1;
					};
					#endif
					#ifdef OPAMP_CSR_2
					struct
					{
						uint32_t                      :1;
						uint32_t OPAMP_CSR_2_OPALPM   :1;
						uint32_t OPAMP_CSR_2_OPAMODE  :2;
						uint32_t OPAMP_CSR_2_PGGAIN   :2;
						uint32_t                      :2;
						uint32_t OPAMP_CSR_2_OPA2PD   :1;
						uint32_t                      :1;
						uint32_t OPAMP_CSR_2_VPSEL    :1;
						uint32_t                      :1;
						uint32_t OPAMP_CSR_2_CALON    :1;
						uint32_t OPAMP_CSR_2_CALSEL   :1;
						uint32_t OPAMP_CSR_2_USERTRIM :1;
						uint32_t OPAMP_CSR_2_CALOUT   :1;
						uint32_t                      :14;
						uint32_t OPAMP_CSR_2_OPA2CALOUT :1;
						uint32_t                      :1;
					};
					#endif
					#ifdef OPAMP_CSR_3
					struct
					{
						uint32_t                      :8;
						uint32_t VMSEL                :2;
						uint32_t                      :22;
					};
					#endif
				};
				//SOOL-OPAMP_CSR-DECLARATION
			};
			#endif
			
			#ifdef OPAMP_HSOTR
			struct HSOTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TRIMHSOFFSETN        :5;
					uint32_t                      :3;
					uint32_t TRIMHSOFFSETP        :5;
					uint32_t                      :19;
			
				//SOOL-OPAMP_HSOTR-DECLARATION
			};
			#endif
			
			#ifdef OPAMP_LPOTR
			struct LPOTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TRIMLPOFFSETN        :5;
					uint32_t                      :3;
					uint32_t TRIMLPOFFSETP        :5;
					uint32_t                      :19;
			
				//SOOL-OPAMP_LPOTR-DECLARATION
			};
			#endif
			
			#ifdef OPAMP_OTR
			struct OTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t OPAMP_OTR_0_TRIMOFFSETN :5;
						uint32_t                      :3;
						uint32_t OPAMP_OTR_0_TRIMOFFSETP :5;
						uint32_t                      :2;
						uint32_t OPAMP_OTR_0_AO2_OPT_OFFSET_TRIM_HIGH :5;
						uint32_t OPAMP_OTR_0_AO3_OPT_OFFSET_TRIM_LOW :5;
						uint32_t OPAMP_OTR_0_AO3_OPT_OFFSET_TRIM_HIGH :5;
						uint32_t                      :1;
						uint32_t OPAMP_OTR_0_OT_USER  :1;
					};
					#ifdef OPAMP_OTR_1
					struct
					{
						uint32_t AO1_OPT_OFFSET_TRIM_LOW :5;
						uint32_t AO1_OPT_OFFSET_TRIM_HIGH :5;
						uint32_t AO2_OPT_OFFSET_TRIM_LOW :5;
						uint32_t AO2_OPT_OFFSET_TRIM_LP_HIGH :5;
						uint32_t OPAMP_OTR_1_AO3_OPT_OFFSET_TRIM_LP_LOW :5;
						uint32_t OPAMP_OTR_1_AO3_OPT_OFFSET_TRIM_LP_HIGH :5;
						uint32_t                      :2;
					};
					#endif
					#ifdef OPAMP_OTR_2
					struct
					{
						uint32_t AO1_OPT_OFFSET_TRIM_LP_LOW :5;
						uint32_t AO1_OPT_OFFSET_TRIM_LP_HIGH :5;
						uint32_t AO2_OPT_OFFSET_TRIM_LP_LOW :5;
						uint32_t                      :17;
					};
					#endif
				};
				//SOOL-OPAMP_OTR-DECLARATION
			};
			#endif
			};
		template<typename plugin=OPAMP_base_plugin>
		class OPAMP
		{
			//SOOL-OPAMP-ENUMS
			
			public :
			
			union
			{
				
				struct
				{
					typename plugin::CSR_TypeDef CSR; // @0x000
					OPAMP_MAP0_OTR;      // @0x004
					OPAMP_MAP0_HSOTR;    // @0x008
				};
				struct
				{
					__SOOL_PERIPH_PADDING_8;
					OPAMP_MAP1_LPOTR;    // @0x008
				};
			};
			private:
			OPAMP() = delete;
			//SOOL-OPAMP-DECLARATION
		};
		
		
		class OPAMP_Common
		{
			//SOOL-OPAMP_Common-ENUMS
			
			public :
			
			union
			{
				
				struct
				{
					uint32_t CSR;        // @0x000
					OPAMP_Common_MAP0_OTR; // @0x004
				};
			};
			private:
			OPAMP_Common() = delete;
			//SOOL-OPAMP_Common-DECLARATION
		};
		
		//region instances
#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F303x8 ) || defined(STM32F318xx ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) 
#define OPAMP_BASE_ADDR ((uint32_t)0x4001003CU)
#endif

#if defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) || defined(STM32F303xE ) ||\
    defined(STM32F358xx ) || defined(STM32F398xx ) 
#define OPAMP_BASE_ADDR ((uint32_t)0x40010038U)
#define OPAMP1_BASE_ADDR ((uint32_t)0x40010038U)
#endif

#if defined(STM32H7     ) 
#define OPAMP_BASE_ADDR ((uint32_t)0x40009000U)
#define OPAMP2_BASE_ADDR ((uint32_t)0x40009010U)
#define OPAMP1_BASE_ADDR ((uint32_t)0x40009000U)
#endif

#if defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) || defined(STM32L151xDx) ||\
    defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) || defined(STM32L152xD ) ||\
    defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) || defined(STM32L162xCA) ||\
    defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define OPAMP_BASE_ADDR ((uint32_t)0x40007C5CU)
#define OPAMP1_BASE_ADDR ((uint32_t)0x40007C5CU)
#endif

#if defined(STM32L4     ) || defined(STM32L4P    ) 
#define OPAMP_BASE_ADDR ((uint32_t)0x40007800U)
#define OPAMP1_BASE_ADDR ((uint32_t)0x40007800U)
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F398xx ) 
#define OPAMP2_BASE_ADDR ((uint32_t)0x4001003CU)
#endif

#if defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define OPAMP2_BASE_ADDR ((uint32_t)0x40007810U)
#define OPAMP12_COMMON_BASE_ADDR ((uint32_t)0x40007800U)
#endif

#if defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F358xx ) || defined(STM32F398xx ) 
#define OPAMP3_BASE_ADDR ((uint32_t)0x40010040U)
#define OPAMP4_BASE_ADDR ((uint32_t)0x40010044U)
#endif

#if defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xDx) || defined(STM32L151xE ) ||\
    defined(STM32L152xC ) || defined(STM32L152xCA) || defined(STM32L152xDx) || defined(STM32L152xE ) ||\
    defined(STM32L162xC ) || defined(STM32L162xCA) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define OPAMP12_COMMON_BASE_ADDR ((uint32_t)0x40007C5CU)
#endif

#if defined(STM32L151xD ) || defined(STM32L152xD ) || defined(STM32L162xD ) 
#define OPAMP123_COMMON_BASE_ADDR ((uint32_t)0x40007C5CU)
#endif

#if defined(STM32L431xx ) || defined(STM32L432xx ) || defined(STM32L433xx ) || defined(STM32L442xx ) ||\
    defined(STM32L443xx ) || defined(STM32L451xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) 
#define OPAMP1_COMMON_BASE_ADDR ((uint32_t)0x40007800U)
#endif

#ifdef OPAMP_BASE_ADDR
volatile class OPAMP<>* const OPAMP =reinterpret_cast<class OPAMP<>* const>(OPAMP_BASE_ADDR);
#endif
#ifdef OPAMP1_BASE_ADDR
struct OPAMP1_plugin: OPAMP_base_plugin {
	
	#ifdef OPAMP_CSR
	struct CSR_TypeDef : public Reg32_t
	{
		using Reg32_t::operator=;
	
		union
		{
			#ifdef OPAMP1_CSR_0
			struct
			{
				uint32_t OPAMP1_CSR_0_OPAMP1EN :1;
				uint32_t OPAMP1_CSR_0_FORCEVP :1;
				uint32_t OPAMP1_CSR_0_VPSEL   :2;
				uint32_t OPAMP1_CSR_0_S6SEL1  :1;
				uint32_t OPAMP1_CSR_0_VMSEL   :2;
				uint32_t OPAMP1_CSR_0_TCMEN   :1;
				uint32_t OPAMP1_CSR_0_VMSSEL  :1;
				uint32_t OPAMP1_CSR_0_VPSSEL  :2;
				uint32_t OPAMP1_CSR_0_CALON   :1;
				uint32_t OPAMP1_CSR_0_CALSEL  :2;
				uint32_t OPAMP1_CSR_0_PGGAIN  :4;
				uint32_t OPAMP1_CSR_0_USERTRIM :1;
				uint32_t OPAMP1_CSR_0_TRIMOFFSETP :5;
				uint32_t OPAMP1_CSR_0_TRIMOFFSETN :5;
				uint32_t OPAMP1_CSR_0_TSTREF  :1;
				uint32_t OPAMP1_CSR_0_OUTCAL  :1;
				uint32_t OPAMP1_CSR_0_LOCK    :1;
			};
			#endif
			#ifdef OPAMP1_CSR_1
			struct
			{
				uint32_t OPAMP1_CSR_1_OPAEN   :1;
				uint32_t OPAMP1_CSR_1_OPALPM  :1;
				uint32_t OPAMP1_CSR_1_OPAMODE :2;
				uint32_t OPAMP1_CSR_1_PGAGAIN :2;
				uint32_t OPAMP1_CSR_1_OPA1CAL_H :1;
				uint32_t OPAMP1_CSR_1_OPA1LPM :1;
				uint32_t OPAMP1_CSR_1_OPAHSM  :1;
				uint32_t OPAMP1_CSR_1_S3SEL2  :1;
				uint32_t OPAMP1_CSR_1_VPSEL   :1;
				uint32_t OPAMP1_CSR_1_S5SEL2  :1;
				uint32_t OPAMP1_CSR_1_CALON   :1;
				uint32_t OPAMP1_CSR_1_CALSEL  :1;
				uint32_t OPAMP1_CSR_1_USERTRIM :1;
				uint32_t OPAMP1_CSR_1_OPA2LPM :1;
				uint32_t OPAMP1_CSR_1_OPA3PD  :1;
				uint32_t OPAMP1_CSR_1_S3SEL3  :1;
				uint32_t OPAMP1_CSR_1_S4SEL3  :1;
				uint32_t OPAMP1_CSR_1_S5SEL3  :1;
				uint32_t OPAMP1_CSR_1_S6SEL3  :1;
				uint32_t OPAMP1_CSR_1_OPA3CAL_L :1;
				uint32_t OPAMP1_CSR_1_OPA3CAL_H :1;
				uint32_t OPAMP1_CSR_1_OPA3LPM :1;
				uint32_t OPAMP1_CSR_1_ANAWSEL1 :1;
				uint32_t OPAMP1_CSR_1_ANAWSEL2 :1;
				uint32_t OPAMP1_CSR_1_ANAWSEL3 :1;
				uint32_t OPAMP1_CSR_1_S7SEL2  :1;
				uint32_t OPAMP1_CSR_1_AOP_RANGE :1;
				uint32_t OPAMP1_CSR_1_OPA1CALOUT :1;
				uint32_t OPAMP1_CSR_1_CALOUT  :1;
				uint32_t OPAMP1_CSR_1_OPARANGE :1;
			};
			#endif
			struct
			{
				uint32_t OPAMP1_CSR_2_OPAMPxEN :1;
				uint32_t OPAMP1_CSR_2_S3SEL1  :1;
				uint32_t OPAMP1_CSR_2_S4SEL1  :1;
				uint32_t OPAMP1_CSR_2_S5SEL1  :1;
				uint32_t                      :1;
				uint32_t OPAMP1_CSR_2_OPA1CAL_L :1;
				uint32_t                      :2;
				uint32_t OPAMP1_CSR_2_VMSEL   :2;
				uint32_t OPAMP1_CSR_2_S4SEL2  :1;
				uint32_t                      :1;
				uint32_t OPAMP1_CSR_2_S6SEL2  :1;
				uint32_t OPAMP1_CSR_2_OPA2CAL_L :1;
				uint32_t OPAMP1_CSR_2_OPA2CAL_H :1;
				uint32_t OPAMP1_CSR_2_CALOUT  :1;
				uint32_t                      :14;
				uint32_t OPAMP1_CSR_2_OPA2CALOUT :1;
				uint32_t OPAMP1_CSR_2_OPA3CALOUT :1;
			};
			#ifdef OPAMP1_CSR_3
			struct
			{
				uint32_t OPAMP1_CSR_3_OPA1PD  :1;
				uint32_t                      :3;
				uint32_t OPAMP1_CSR_3_PGGAIN  :2;
				uint32_t                      :2;
				uint32_t OPAMP1_CSR_3_OPA2PD  :1;
				uint32_t                      :23;
			};
			#endif
		};
		//SOOL-OPAMP_CSR-DECLARATION
	};
	#endif
	
	#ifdef OPAMP_OTR
	struct OTR_TypeDef : public Reg32_t
	{
		using Reg32_t::operator=;
	
		union
		{
			struct
			{
				uint32_t OPAMP1_OTR_0_TRIMOFFSETN :5;
				uint32_t                      :3;
				uint32_t OPAMP1_OTR_0_TRIMOFFSETP :5;
				uint32_t                      :2;
				uint32_t OPAMP1_OTR_0_AO2_OPT_OFFSET_TRIM_HIGH :5;
				uint32_t OPAMP1_OTR_0_AO3_OPT_OFFSET_TRIM_LOW :5;
				uint32_t OPAMP1_OTR_0_AO3_OPT_OFFSET_TRIM_HIGH :5;
				uint32_t                      :1;
				uint32_t OPAMP1_OTR_0_OT_USER :1;
			};
			#ifdef OPAMP1_OTR_1
			struct
			{
				uint32_t AO1_OPT_OFFSET_TRIM_LOW :5;
				uint32_t AO1_OPT_OFFSET_TRIM_HIGH :5;
				uint32_t AO2_OPT_OFFSET_TRIM_LOW :5;
				uint32_t AO2_OPT_OFFSET_TRIM_LP_HIGH :5;
				uint32_t OPAMP1_OTR_1_AO3_OPT_OFFSET_TRIM_LP_LOW :5;
				uint32_t OPAMP1_OTR_1_AO3_OPT_OFFSET_TRIM_LP_HIGH :5;
				uint32_t                      :2;
			};
			#endif
			#ifdef OPAMP1_OTR_2
			struct
			{
				uint32_t AO1_OPT_OFFSET_TRIM_LP_LOW :5;
				uint32_t AO1_OPT_OFFSET_TRIM_LP_HIGH :5;
				uint32_t AO2_OPT_OFFSET_TRIM_LP_LOW :5;
				uint32_t                      :17;
			};
			#endif
		};
		//SOOL-OPAMP_OTR-DECLARATION
	};
	#endif
	
	#ifdef OPAMP_HSOTR
	struct HSOTR_TypeDef : public Reg32_t
	{
		using Reg32_t::operator=;
		
			uint32_t TRIMHSOFFSETN        :5;
			uint32_t                      :3;
			uint32_t TRIMHSOFFSETP        :5;
			uint32_t                      :19;
	
		//SOOL-OPAMP_HSOTR-DECLARATION
	};
	#endif
	
	#ifdef OPAMP_LPOTR
	struct LPOTR_TypeDef : public Reg32_t
	{
		using Reg32_t::operator=;
		
			uint32_t TRIMLPOFFSETN        :5;
			uint32_t                      :3;
			uint32_t TRIMLPOFFSETP        :5;
			uint32_t                      :19;
	
		//SOOL-OPAMP_LPOTR-DECLARATION
	};
	#endif
	
};
volatile class OPAMP<OPAMP1_plugin>* const OPAMP1 =reinterpret_cast<class OPAMP<OPAMP1_plugin>* const>(OPAMP1_BASE_ADDR);
#endif
#ifdef OPAMP2_BASE_ADDR
struct OPAMP2_plugin: OPAMP_base_plugin {
	
	#ifdef OPAMP_CSR
	struct CSR_TypeDef : public Reg32_t
	{
		using Reg32_t::operator=;
	
		union
		{
			#ifdef OPAMP2_CSR_0
			struct
			{
				uint32_t OPAMP2_CSR_0_OPAMP2EN :1;
				uint32_t OPAMP2_CSR_0_FORCEVP :1;
				uint32_t OPAMP2_CSR_0_VPSEL   :2;
				uint32_t OPAMP2_CSR_0_S6SEL1  :1;
				uint32_t OPAMP2_CSR_0_VMSEL   :2;
				uint32_t OPAMP2_CSR_0_TCMEN   :1;
				uint32_t OPAMP2_CSR_0_VMSSEL  :1;
				uint32_t OPAMP2_CSR_0_VPSSEL  :2;
				uint32_t OPAMP2_CSR_0_CALON   :1;
				uint32_t OPAMP2_CSR_0_CALSEL  :2;
				uint32_t OPAMP2_CSR_0_PGGAIN  :4;
				uint32_t OPAMP2_CSR_0_USERTRIM :1;
				uint32_t OPAMP2_CSR_0_TRIMOFFSETP :5;
				uint32_t OPAMP2_CSR_0_TRIMOFFSETN :5;
				uint32_t OPAMP2_CSR_0_TSTREF  :1;
				uint32_t OPAMP2_CSR_0_OUTCAL  :1;
				uint32_t OPAMP2_CSR_0_LOCK    :1;
			};
			#endif
			#ifdef OPAMP2_CSR_1
			struct
			{
				uint32_t OPAMP2_CSR_1_OPAEN   :1;
				uint32_t OPAMP2_CSR_1_OPALPM  :1;
				uint32_t OPAMP2_CSR_1_OPAMODE :2;
				uint32_t OPAMP2_CSR_1_PGAGAIN :2;
				uint32_t OPAMP2_CSR_1_OPA1CAL_H :1;
				uint32_t OPAMP2_CSR_1_OPA1LPM :1;
				uint32_t OPAMP2_CSR_1_OPAHSM  :1;
				uint32_t OPAMP2_CSR_1_S3SEL2  :1;
				uint32_t OPAMP2_CSR_1_VPSEL   :1;
				uint32_t OPAMP2_CSR_1_S5SEL2  :1;
				uint32_t OPAMP2_CSR_1_CALON   :1;
				uint32_t OPAMP2_CSR_1_CALSEL  :1;
				uint32_t OPAMP2_CSR_1_USERTRIM :1;
				uint32_t OPAMP2_CSR_1_OPA2LPM :1;
				uint32_t OPAMP2_CSR_1_OPA3PD  :1;
				uint32_t OPAMP2_CSR_1_S3SEL3  :1;
				uint32_t OPAMP2_CSR_1_S4SEL3  :1;
				uint32_t OPAMP2_CSR_1_S5SEL3  :1;
				uint32_t OPAMP2_CSR_1_S6SEL3  :1;
				uint32_t OPAMP2_CSR_1_OPA3CAL_L :1;
				uint32_t OPAMP2_CSR_1_OPA3CAL_H :1;
				uint32_t OPAMP2_CSR_1_OPA3LPM :1;
				uint32_t OPAMP2_CSR_1_ANAWSEL1 :1;
				uint32_t OPAMP2_CSR_1_ANAWSEL2 :1;
				uint32_t OPAMP2_CSR_1_ANAWSEL3 :1;
				uint32_t OPAMP2_CSR_1_S7SEL2  :1;
				uint32_t OPAMP2_CSR_1_AOP_RANGE :1;
				uint32_t OPAMP2_CSR_1_OPA1CALOUT :1;
				uint32_t OPAMP2_CSR_1_CALOUT  :1;
				uint32_t OPAMP2_CSR_1_OPA3CALOUT :1;
			};
			#endif
			struct
			{
				uint32_t OPAMP2_CSR_2_OPAMPxEN :1;
				uint32_t OPAMP2_CSR_2_S3SEL1  :1;
				uint32_t OPAMP2_CSR_2_S4SEL1  :1;
				uint32_t OPAMP2_CSR_2_S5SEL1  :1;
				uint32_t                      :1;
				uint32_t OPAMP2_CSR_2_OPA1CAL_L :1;
				uint32_t                      :2;
				uint32_t OPAMP2_CSR_2_VMSEL   :2;
				uint32_t OPAMP2_CSR_2_S4SEL2  :1;
				uint32_t                      :1;
				uint32_t OPAMP2_CSR_2_S6SEL2  :1;
				uint32_t OPAMP2_CSR_2_OPA2CAL_L :1;
				uint32_t OPAMP2_CSR_2_OPA2CAL_H :1;
				uint32_t OPAMP2_CSR_2_CALOUT  :1;
				uint32_t                      :14;
				uint32_t OPAMP2_CSR_2_OPA2CALOUT :1;
				uint32_t                      :1;
			};
			#ifdef OPAMP2_CSR_3
			struct
			{
				uint32_t OPAMP2_CSR_3_OPA1PD  :1;
				uint32_t                      :3;
				uint32_t OPAMP2_CSR_3_PGGAIN  :2;
				uint32_t                      :2;
				uint32_t OPAMP2_CSR_3_OPA2PD  :1;
				uint32_t                      :23;
			};
			#endif
		};
		//SOOL-OPAMP_CSR-DECLARATION
	};
	#endif
	
	#ifdef OPAMP_OTR
	struct OTR_TypeDef : public Reg32_t
	{
		using Reg32_t::operator=;
	
		union
		{
			struct
			{
				uint32_t OPAMP2_OTR_0_TRIMOFFSETN :5;
				uint32_t                      :3;
				uint32_t OPAMP2_OTR_0_TRIMOFFSETP :5;
				uint32_t                      :2;
				uint32_t OPAMP2_OTR_0_AO2_OPT_OFFSET_TRIM_HIGH :5;
				uint32_t OPAMP2_OTR_0_AO3_OPT_OFFSET_TRIM_LOW :5;
				uint32_t OPAMP2_OTR_0_AO3_OPT_OFFSET_TRIM_HIGH :5;
				uint32_t                      :1;
				uint32_t OPAMP2_OTR_0_OT_USER :1;
			};
			#ifdef OPAMP2_OTR_1
			struct
			{
				uint32_t AO1_OPT_OFFSET_TRIM_LOW :5;
				uint32_t AO1_OPT_OFFSET_TRIM_HIGH :5;
				uint32_t AO2_OPT_OFFSET_TRIM_LOW :5;
				uint32_t AO2_OPT_OFFSET_TRIM_LP_HIGH :5;
				uint32_t OPAMP2_OTR_1_AO3_OPT_OFFSET_TRIM_LP_LOW :5;
				uint32_t OPAMP2_OTR_1_AO3_OPT_OFFSET_TRIM_LP_HIGH :5;
				uint32_t                      :2;
			};
			#endif
			#ifdef OPAMP2_OTR_2
			struct
			{
				uint32_t AO1_OPT_OFFSET_TRIM_LP_LOW :5;
				uint32_t AO1_OPT_OFFSET_TRIM_LP_HIGH :5;
				uint32_t AO2_OPT_OFFSET_TRIM_LP_LOW :5;
				uint32_t                      :17;
			};
			#endif
		};
		//SOOL-OPAMP_OTR-DECLARATION
	};
	#endif
	
	#ifdef OPAMP_HSOTR
	struct HSOTR_TypeDef : public Reg32_t
	{
		using Reg32_t::operator=;
		
			uint32_t TRIMHSOFFSETN        :5;
			uint32_t                      :3;
			uint32_t TRIMHSOFFSETP        :5;
			uint32_t                      :19;
	
		//SOOL-OPAMP_HSOTR-DECLARATION
	};
	#endif
	
	#ifdef OPAMP_LPOTR
	struct LPOTR_TypeDef : public Reg32_t
	{
		using Reg32_t::operator=;
		
			uint32_t TRIMLPOFFSETN        :5;
			uint32_t                      :3;
			uint32_t TRIMLPOFFSETP        :5;
			uint32_t                      :19;
	
		//SOOL-OPAMP_LPOTR-DECLARATION
	};
	#endif
	
};
volatile class OPAMP<OPAMP2_plugin>* const OPAMP2 =reinterpret_cast<class OPAMP<OPAMP2_plugin>* const>(OPAMP2_BASE_ADDR);
#endif
#ifdef OPAMP12_COMMON_BASE_ADDR
volatile class OPAMP_Common * const OPAMP12_COMMON = reinterpret_cast<class OPAMP_Common* const>(OPAMP12_COMMON_BASE_ADDR);
#endif
#ifdef OPAMP3_BASE_ADDR
struct OPAMP3_plugin: OPAMP_base_plugin {
	
	#ifdef OPAMP_CSR
	struct CSR_TypeDef : public Reg32_t
	{
		using Reg32_t::operator=;
	
		union
		{
			#ifdef OPAMP3_CSR_0
			struct
			{
				uint32_t OPAMP3_CSR_0_OPAMP3EN :1;
				uint32_t OPAMP3_CSR_0_FORCEVP :1;
				uint32_t OPAMP3_CSR_0_VPSEL   :2;
				uint32_t OPAMP3_CSR_0_S6SEL1  :1;
				uint32_t OPAMP3_CSR_0_VMSEL   :2;
				uint32_t OPAMP3_CSR_0_TCMEN   :1;
				uint32_t OPAMP3_CSR_0_VMSSEL  :1;
				uint32_t OPAMP3_CSR_0_VPSSEL  :2;
				uint32_t OPAMP3_CSR_0_CALON   :1;
				uint32_t OPAMP3_CSR_0_CALSEL  :2;
				uint32_t OPAMP3_CSR_0_PGGAIN  :4;
				uint32_t OPAMP3_CSR_0_USERTRIM :1;
				uint32_t OPAMP3_CSR_0_TRIMOFFSETP :5;
				uint32_t OPAMP3_CSR_0_TRIMOFFSETN :5;
				uint32_t OPAMP3_CSR_0_TSTREF  :1;
				uint32_t OPAMP3_CSR_0_OUTCAL  :1;
				uint32_t OPAMP3_CSR_0_LOCK    :1;
			};
			#endif
			struct
			{
				uint32_t OPAMP3_CSR_1_OPAMPxEN :1;
				uint32_t OPAMP3_CSR_1_S3SEL1  :1;
				uint32_t OPAMP3_CSR_1_S4SEL1  :1;
				uint32_t OPAMP3_CSR_1_S5SEL1  :1;
				uint32_t                      :1;
				uint32_t OPAMP3_CSR_1_OPA1CAL_L :1;
				uint32_t OPAMP3_CSR_1_OPA1CAL_H :1;
				uint32_t OPAMP3_CSR_1_OPA1LPM :1;
				uint32_t OPAMP3_CSR_1_OPAHSM  :1;
				uint32_t OPAMP3_CSR_1_S3SEL2  :1;
				uint32_t OPAMP3_CSR_1_S4SEL2  :1;
				uint32_t OPAMP3_CSR_1_S5SEL2  :1;
				uint32_t OPAMP3_CSR_1_S6SEL2  :1;
				uint32_t OPAMP3_CSR_1_OPA2CAL_L :1;
				uint32_t OPAMP3_CSR_1_OPA2CAL_H :1;
				uint32_t OPAMP3_CSR_1_OPA2LPM :1;
				uint32_t OPAMP3_CSR_1_OPA3PD  :1;
				uint32_t OPAMP3_CSR_1_S3SEL3  :1;
				uint32_t OPAMP3_CSR_1_S4SEL3  :1;
				uint32_t OPAMP3_CSR_1_S5SEL3  :1;
				uint32_t OPAMP3_CSR_1_S6SEL3  :1;
				uint32_t OPAMP3_CSR_1_OPA3CAL_L :1;
				uint32_t OPAMP3_CSR_1_OPA3CAL_H :1;
				uint32_t OPAMP3_CSR_1_OPA3LPM :1;
				uint32_t OPAMP3_CSR_1_ANAWSEL1 :1;
				uint32_t OPAMP3_CSR_1_ANAWSEL2 :1;
				uint32_t OPAMP3_CSR_1_ANAWSEL3 :1;
				uint32_t OPAMP3_CSR_1_S7SEL2  :1;
				uint32_t OPAMP3_CSR_1_AOP_RANGE :1;
				uint32_t OPAMP3_CSR_1_OPA1CALOUT :1;
				uint32_t OPAMP3_CSR_1_CALOUT  :1;
				uint32_t OPAMP3_CSR_1_OPA3CALOUT :1;
			};
			#ifdef OPAMP3_CSR_2
			struct
			{
				uint32_t OPAMP3_CSR_2_OPA1PD  :1;
				uint32_t OPAMP3_CSR_2_OPALPM  :1;
				uint32_t OPAMP3_CSR_2_OPAMODE :2;
				uint32_t OPAMP3_CSR_2_PGGAIN  :2;
				uint32_t                      :2;
				uint32_t OPAMP3_CSR_2_OPA2PD  :1;
				uint32_t                      :1;
				uint32_t OPAMP3_CSR_2_VPSEL   :1;
				uint32_t                      :1;
				uint32_t OPAMP3_CSR_2_CALON   :1;
				uint32_t OPAMP3_CSR_2_CALSEL  :1;
				uint32_t OPAMP3_CSR_2_USERTRIM :1;
				uint32_t OPAMP3_CSR_2_CALOUT  :1;
				uint32_t                      :14;
				uint32_t OPAMP3_CSR_2_OPA2CALOUT :1;
				uint32_t                      :1;
			};
			#endif
			#ifdef OPAMP3_CSR_3
			struct
			{
				uint32_t                      :8;
				uint32_t VMSEL                :2;
				uint32_t                      :22;
			};
			#endif
		};
		//SOOL-OPAMP_CSR-DECLARATION
	};
	#endif
	
};
volatile class OPAMP<OPAMP3_plugin>* const OPAMP3 =reinterpret_cast<class OPAMP<OPAMP3_plugin>* const>(OPAMP3_BASE_ADDR);
#endif
#ifdef OPAMP4_BASE_ADDR
struct OPAMP4_plugin: OPAMP_base_plugin {
	
	#ifdef OPAMP_CSR
	struct CSR_TypeDef : public Reg32_t
	{
		using Reg32_t::operator=;
	
		union
		{
			#ifdef OPAMP4_CSR_0
			struct
			{
				uint32_t OPAMP4_CSR_0_OPAMP4EN :1;
				uint32_t OPAMP4_CSR_0_FORCEVP :1;
				uint32_t OPAMP4_CSR_0_VPSEL   :2;
				uint32_t OPAMP4_CSR_0_S6SEL1  :1;
				uint32_t OPAMP4_CSR_0_VMSEL   :2;
				uint32_t OPAMP4_CSR_0_TCMEN   :1;
				uint32_t OPAMP4_CSR_0_VMSSEL  :1;
				uint32_t OPAMP4_CSR_0_VPSSEL  :2;
				uint32_t OPAMP4_CSR_0_CALON   :1;
				uint32_t OPAMP4_CSR_0_CALSEL  :2;
				uint32_t OPAMP4_CSR_0_PGGAIN  :4;
				uint32_t OPAMP4_CSR_0_USERTRIM :1;
				uint32_t OPAMP4_CSR_0_TRIMOFFSETP :5;
				uint32_t OPAMP4_CSR_0_TRIMOFFSETN :5;
				uint32_t OPAMP4_CSR_0_TSTREF  :1;
				uint32_t OPAMP4_CSR_0_OUTCAL  :1;
				uint32_t OPAMP4_CSR_0_LOCK    :1;
			};
			#endif
			struct
			{
				uint32_t OPAMP4_CSR_1_OPAMPxEN :1;
				uint32_t OPAMP4_CSR_1_S3SEL1  :1;
				uint32_t OPAMP4_CSR_1_S4SEL1  :1;
				uint32_t OPAMP4_CSR_1_S5SEL1  :1;
				uint32_t                      :1;
				uint32_t OPAMP4_CSR_1_OPA1CAL_L :1;
				uint32_t OPAMP4_CSR_1_OPA1CAL_H :1;
				uint32_t OPAMP4_CSR_1_OPA1LPM :1;
				uint32_t OPAMP4_CSR_1_OPAHSM  :1;
				uint32_t OPAMP4_CSR_1_S3SEL2  :1;
				uint32_t OPAMP4_CSR_1_S4SEL2  :1;
				uint32_t OPAMP4_CSR_1_S5SEL2  :1;
				uint32_t OPAMP4_CSR_1_S6SEL2  :1;
				uint32_t OPAMP4_CSR_1_OPA2CAL_L :1;
				uint32_t OPAMP4_CSR_1_OPA2CAL_H :1;
				uint32_t OPAMP4_CSR_1_OPA2LPM :1;
				uint32_t OPAMP4_CSR_1_OPA3PD  :1;
				uint32_t OPAMP4_CSR_1_S3SEL3  :1;
				uint32_t OPAMP4_CSR_1_S4SEL3  :1;
				uint32_t OPAMP4_CSR_1_S5SEL3  :1;
				uint32_t OPAMP4_CSR_1_S6SEL3  :1;
				uint32_t OPAMP4_CSR_1_OPA3CAL_L :1;
				uint32_t OPAMP4_CSR_1_OPA3CAL_H :1;
				uint32_t OPAMP4_CSR_1_OPA3LPM :1;
				uint32_t OPAMP4_CSR_1_ANAWSEL1 :1;
				uint32_t OPAMP4_CSR_1_ANAWSEL2 :1;
				uint32_t OPAMP4_CSR_1_ANAWSEL3 :1;
				uint32_t OPAMP4_CSR_1_S7SEL2  :1;
				uint32_t OPAMP4_CSR_1_AOP_RANGE :1;
				uint32_t OPAMP4_CSR_1_OPA1CALOUT :1;
				uint32_t OPAMP4_CSR_1_CALOUT  :1;
				uint32_t OPAMP4_CSR_1_OPA3CALOUT :1;
			};
			#ifdef OPAMP4_CSR_2
			struct
			{
				uint32_t OPAMP4_CSR_2_OPA1PD  :1;
				uint32_t OPAMP4_CSR_2_OPALPM  :1;
				uint32_t OPAMP4_CSR_2_OPAMODE :2;
				uint32_t OPAMP4_CSR_2_PGGAIN  :2;
				uint32_t                      :2;
				uint32_t OPAMP4_CSR_2_OPA2PD  :1;
				uint32_t                      :1;
				uint32_t OPAMP4_CSR_2_VPSEL   :1;
				uint32_t                      :1;
				uint32_t OPAMP4_CSR_2_CALON   :1;
				uint32_t OPAMP4_CSR_2_CALSEL  :1;
				uint32_t OPAMP4_CSR_2_USERTRIM :1;
				uint32_t OPAMP4_CSR_2_CALOUT  :1;
				uint32_t                      :14;
				uint32_t OPAMP4_CSR_2_OPA2CALOUT :1;
				uint32_t                      :1;
			};
			#endif
			#ifdef OPAMP4_CSR_3
			struct
			{
				uint32_t                      :8;
				uint32_t VMSEL                :2;
				uint32_t                      :22;
			};
			#endif
		};
		//SOOL-OPAMP_CSR-DECLARATION
	};
	#endif
	
};
volatile class OPAMP<OPAMP4_plugin>* const OPAMP4 =reinterpret_cast<class OPAMP<OPAMP4_plugin>* const>(OPAMP4_BASE_ADDR);
#endif
#ifdef OPAMP123_COMMON_BASE_ADDR
volatile class OPAMP_Common * const OPAMP123_COMMON = reinterpret_cast<class OPAMP_Common* const>(OPAMP123_COMMON_BASE_ADDR);
#endif
#ifdef OPAMP1_COMMON_BASE_ADDR
volatile class OPAMP_Common * const OPAMP1_COMMON = reinterpret_cast<class OPAMP_Common* const>(OPAMP1_COMMON_BASE_ADDR);
#endif
//endregion

//SOOL-OPAMP-DEFINES
//SOOL-OPAMP-DEFINITION
	};
};//region undef
#undef OPAMP_CSR_0_OPAMPxEN
#undef OPAMP2_CSR_2_OPAMPxEN
#undef OPAMP1_CSR_2_OPAMPxEN
#undef OPAMP3_CSR_1_OPAMPxEN
#undef OPAMP4_CSR_1_OPAMPxEN
#undef OPAMP_CSR_0_FORCEVP
#undef OPAMP_CSR_0_VPSEL
#undef OPAMP_CSR_0_VMSEL
#undef OPAMP_CSR_0_CALON
#undef OPAMP_CSR_0_CALSEL
#undef OPAMP_CSR_0_PGGAIN
#undef OPAMP_CSR_0_USERTRIM
#undef OPAMP_CSR_0_TSTREF
#undef OPAMP2_CSR_0_FORCEVP
#undef OPAMP2_CSR_0_VPSEL
#undef OPAMP2_CSR_0_VMSEL
#undef OPAMP2_CSR_0_CALON
#undef OPAMP2_CSR_0_CALSEL
#undef OPAMP2_CSR_0_PGGAIN
#undef OPAMP2_CSR_0_USERTRIM
#undef OPAMP2_CSR_0_TSTREF
#undef OPAMP1_CSR_0_FORCEVP
#undef OPAMP1_CSR_0_VPSEL
#undef OPAMP1_CSR_0_VMSEL
#undef OPAMP1_CSR_0_CALON
#undef OPAMP1_CSR_0_CALSEL
#undef OPAMP1_CSR_0_PGGAIN
#undef OPAMP1_CSR_0_USERTRIM
#undef OPAMP1_CSR_0_TSTREF
#undef OPAMP3_CSR_0_FORCEVP
#undef OPAMP3_CSR_0_VPSEL
#undef OPAMP3_CSR_0_VMSEL
#undef OPAMP3_CSR_0_CALON
#undef OPAMP3_CSR_0_CALSEL
#undef OPAMP3_CSR_0_PGGAIN
#undef OPAMP3_CSR_0_USERTRIM
#undef OPAMP3_CSR_0_TSTREF
#undef OPAMP4_CSR_0_FORCEVP
#undef OPAMP4_CSR_0_VPSEL
#undef OPAMP4_CSR_0_VMSEL
#undef OPAMP4_CSR_0_CALON
#undef OPAMP4_CSR_0_CALSEL
#undef OPAMP4_CSR_0_PGGAIN
#undef OPAMP4_CSR_0_USERTRIM
#undef OPAMP4_CSR_0_TSTREF
#undef OPAMP_CSR_0_S6SEL1
#undef OPAMP_CSR_1_OPA1PD
#undef OPAMP_CSR_1_S3SEL1
#undef OPAMP_CSR_1_S4SEL1
#undef OPAMP_CSR_1_S5SEL1
#undef OPAMP_CSR_1_OPA1CAL_L
#undef OPAMP_CSR_1_OPA1CAL_H
#undef OPAMP_CSR_1_OPA1LPM
#undef OPAMP_CSR_1_S3SEL2
#undef OPAMP_CSR_1_S4SEL2
#undef OPAMP_CSR_1_S5SEL2
#undef OPAMP_CSR_1_S6SEL2
#undef OPAMP_CSR_1_OPA2CAL_L
#undef OPAMP_CSR_1_OPA2CAL_H
#undef OPAMP_CSR_1_OPA2LPM
#undef OPAMP_CSR_1_ANAWSEL1
#undef OPAMP_CSR_1_ANAWSEL2
#undef OPAMP_CSR_1_S7SEL2
#undef OPAMP_CSR_1_AOP_RANGE
#undef OPAMP_CSR_1_OPA1CALOUT
#undef OPAMP_CSR_2_OPA2PD
#undef OPAMP_CSR_2_OPA2CALOUT
#undef OPAMP_OTR_0_AO2_OPT_OFFSET_TRIM_HIGH
#undef OPAMP_OTR_0_OT_USER
#undef OPAMP_Common_MAP0_OTR
#undef OPAMP2_CSR_0_S6SEL1
#undef OPAMP2_CSR_1_OPA1CAL_H
#undef OPAMP2_CSR_1_OPA1LPM
#undef OPAMP2_CSR_1_S3SEL2
#undef OPAMP2_CSR_1_S5SEL2
#undef OPAMP2_CSR_1_OPA2LPM
#undef OPAMP2_CSR_1_ANAWSEL1
#undef OPAMP2_CSR_1_ANAWSEL2
#undef OPAMP2_CSR_1_S7SEL2
#undef OPAMP2_CSR_1_AOP_RANGE
#undef OPAMP2_CSR_1_OPA1CALOUT
#undef OPAMP2_CSR_2_S3SEL1
#undef OPAMP2_CSR_2_S4SEL1
#undef OPAMP2_CSR_2_S5SEL1
#undef OPAMP2_CSR_2_OPA1CAL_L
#undef OPAMP2_CSR_2_S4SEL2
#undef OPAMP2_CSR_2_S6SEL2
#undef OPAMP2_CSR_2_OPA2CAL_L
#undef OPAMP2_CSR_2_OPA2CAL_H
#undef OPAMP2_CSR_2_OPA2CALOUT
#undef OPAMP2_CSR_3_OPA1PD
#undef OPAMP2_CSR_3_OPA2PD
#undef OPAMP2_OTR_0_AO2_OPT_OFFSET_TRIM_HIGH
#undef OPAMP2_OTR_0_OT_USER
#undef OPAMP1_CSR_0_S6SEL1
#undef OPAMP1_CSR_1_OPA1CAL_H
#undef OPAMP1_CSR_1_OPA1LPM
#undef OPAMP1_CSR_1_S3SEL2
#undef OPAMP1_CSR_1_S5SEL2
#undef OPAMP1_CSR_1_OPA2LPM
#undef OPAMP1_CSR_1_ANAWSEL1
#undef OPAMP1_CSR_1_ANAWSEL2
#undef OPAMP1_CSR_1_S7SEL2
#undef OPAMP1_CSR_1_AOP_RANGE
#undef OPAMP1_CSR_1_OPA1CALOUT
#undef OPAMP1_CSR_2_S3SEL1
#undef OPAMP1_CSR_2_S4SEL1
#undef OPAMP1_CSR_2_S5SEL1
#undef OPAMP1_CSR_2_OPA1CAL_L
#undef OPAMP1_CSR_2_S4SEL2
#undef OPAMP1_CSR_2_S6SEL2
#undef OPAMP1_CSR_2_OPA2CAL_L
#undef OPAMP1_CSR_2_OPA2CAL_H
#undef OPAMP1_CSR_2_OPA2CALOUT
#undef OPAMP1_CSR_3_OPA1PD
#undef OPAMP1_CSR_3_OPA2PD
#undef OPAMP1_OTR_0_AO2_OPT_OFFSET_TRIM_HIGH
#undef OPAMP1_OTR_0_OT_USER
#undef OPAMP3_CSR_0_S6SEL1
#undef OPAMP3_CSR_1_S3SEL1
#undef OPAMP3_CSR_1_S4SEL1
#undef OPAMP3_CSR_1_S5SEL1
#undef OPAMP3_CSR_1_OPA1CAL_L
#undef OPAMP3_CSR_1_OPA1CAL_H
#undef OPAMP3_CSR_1_OPA1LPM
#undef OPAMP3_CSR_1_S3SEL2
#undef OPAMP3_CSR_1_S4SEL2
#undef OPAMP3_CSR_1_S5SEL2
#undef OPAMP3_CSR_1_S6SEL2
#undef OPAMP3_CSR_1_OPA2CAL_L
#undef OPAMP3_CSR_1_OPA2CAL_H
#undef OPAMP3_CSR_1_OPA2LPM
#undef OPAMP3_CSR_1_ANAWSEL1
#undef OPAMP3_CSR_1_ANAWSEL2
#undef OPAMP3_CSR_1_S7SEL2
#undef OPAMP3_CSR_1_AOP_RANGE
#undef OPAMP3_CSR_1_OPA1CALOUT
#undef OPAMP3_CSR_2_OPA1PD
#undef OPAMP3_CSR_2_OPA2PD
#undef OPAMP3_CSR_2_OPA2CALOUT
#undef OPAMP4_CSR_0_S6SEL1
#undef OPAMP4_CSR_1_S3SEL1
#undef OPAMP4_CSR_1_S4SEL1
#undef OPAMP4_CSR_1_S5SEL1
#undef OPAMP4_CSR_1_OPA1CAL_L
#undef OPAMP4_CSR_1_OPA1CAL_H
#undef OPAMP4_CSR_1_OPA1LPM
#undef OPAMP4_CSR_1_S3SEL2
#undef OPAMP4_CSR_1_S4SEL2
#undef OPAMP4_CSR_1_S5SEL2
#undef OPAMP4_CSR_1_S6SEL2
#undef OPAMP4_CSR_1_OPA2CAL_L
#undef OPAMP4_CSR_1_OPA2CAL_H
#undef OPAMP4_CSR_1_OPA2LPM
#undef OPAMP4_CSR_1_ANAWSEL1
#undef OPAMP4_CSR_1_ANAWSEL2
#undef OPAMP4_CSR_1_S7SEL2
#undef OPAMP4_CSR_1_AOP_RANGE
#undef OPAMP4_CSR_1_OPA1CALOUT
#undef OPAMP4_CSR_2_OPA1PD
#undef OPAMP4_CSR_2_OPA2PD
#undef OPAMP4_CSR_2_OPA2CALOUT
#undef OPAMP_CSR_0_TCMEN
#undef OPAMP_CSR_0_VMSSEL
#undef OPAMP_CSR_0_VPSSEL
#undef OPAMP_CSR_0_TRIMOFFSETP
#undef OPAMP_CSR_0_TRIMOFFSETN
#undef OPAMP_CSR_0_OUTCAL
#undef OPAMP_CSR_0_LOCK
#undef OPAMP2_CSR_0_OPAMP2EN
#undef OPAMP2_CSR_0_TCMEN
#undef OPAMP2_CSR_0_VMSSEL
#undef OPAMP2_CSR_0_VPSSEL
#undef OPAMP2_CSR_0_TRIMOFFSETP
#undef OPAMP2_CSR_0_TRIMOFFSETN
#undef OPAMP2_CSR_0_OUTCAL
#undef OPAMP2_CSR_0_LOCK
#undef OPAMP1_CSR_0_TCMEN
#undef OPAMP1_CSR_0_VMSSEL
#undef OPAMP1_CSR_0_VPSSEL
#undef OPAMP1_CSR_0_TRIMOFFSETP
#undef OPAMP1_CSR_0_TRIMOFFSETN
#undef OPAMP1_CSR_0_OUTCAL
#undef OPAMP1_CSR_0_LOCK
#undef OPAMP3_CSR_0_TCMEN
#undef OPAMP3_CSR_0_VMSSEL
#undef OPAMP3_CSR_0_VPSSEL
#undef OPAMP3_CSR_0_TRIMOFFSETP
#undef OPAMP3_CSR_0_TRIMOFFSETN
#undef OPAMP3_CSR_0_OUTCAL
#undef OPAMP3_CSR_0_LOCK
#undef OPAMP4_CSR_0_TCMEN
#undef OPAMP4_CSR_0_VMSSEL
#undef OPAMP4_CSR_0_VPSSEL
#undef OPAMP4_CSR_0_TRIMOFFSETP
#undef OPAMP4_CSR_0_TRIMOFFSETN
#undef OPAMP4_CSR_0_OUTCAL
#undef OPAMP4_CSR_0_LOCK
#undef OPAMP_CSR_1_OPAHSM
#undef OPAMP_CSR_1_CALOUT
#undef OPAMP_MAP0_HSOTR
#undef OPAMP2_CSR_1_OPAHSM
#undef OPAMP2_CSR_1_CALOUT
#undef OPAMP1_CSR_1_OPAHSM
#undef OPAMP1_CSR_1_CALOUT
#undef OPAMP3_CSR_1_OPAHSM
#undef OPAMP3_CSR_1_CALOUT
#undef OPAMP4_CSR_1_OPAHSM
#undef OPAMP4_CSR_1_CALOUT
#undef OPAMP_CSR_1_OPA3PD
#undef OPAMP_CSR_1_S3SEL3
#undef OPAMP_CSR_1_S4SEL3
#undef OPAMP_CSR_1_S5SEL3
#undef OPAMP_CSR_1_S6SEL3
#undef OPAMP_CSR_1_OPA3CAL_L
#undef OPAMP_CSR_1_OPA3CAL_H
#undef OPAMP_CSR_1_OPA3LPM
#undef OPAMP_CSR_1_ANAWSEL3
#undef OPAMP_CSR_1_OPA3CALOUT
#undef OPAMP_OTR_0_AO3_OPT_OFFSET_TRIM_LOW
#undef OPAMP_OTR_0_AO3_OPT_OFFSET_TRIM_HIGH
#undef OPAMP_OTR_1_AO3_OPT_OFFSET_TRIM_LP_LOW
#undef OPAMP_OTR_1_AO3_OPT_OFFSET_TRIM_LP_HIGH
#undef OPAMP2_CSR_1_OPA3PD
#undef OPAMP2_CSR_1_S3SEL3
#undef OPAMP2_CSR_1_S4SEL3
#undef OPAMP2_CSR_1_S5SEL3
#undef OPAMP2_CSR_1_S6SEL3
#undef OPAMP2_CSR_1_OPA3CAL_L
#undef OPAMP2_CSR_1_OPA3CAL_H
#undef OPAMP2_CSR_1_OPA3LPM
#undef OPAMP2_CSR_1_ANAWSEL3
#undef OPAMP2_CSR_1_OPA3CALOUT
#undef OPAMP2_OTR_0_AO3_OPT_OFFSET_TRIM_LOW
#undef OPAMP2_OTR_0_AO3_OPT_OFFSET_TRIM_HIGH
#undef OPAMP2_OTR_1_AO3_OPT_OFFSET_TRIM_LP_LOW
#undef OPAMP2_OTR_1_AO3_OPT_OFFSET_TRIM_LP_HIGH
#undef OPAMP1_CSR_1_OPA3PD
#undef OPAMP1_CSR_1_S3SEL3
#undef OPAMP1_CSR_1_S4SEL3
#undef OPAMP1_CSR_1_S5SEL3
#undef OPAMP1_CSR_1_S6SEL3
#undef OPAMP1_CSR_1_OPA3CAL_L
#undef OPAMP1_CSR_1_OPA3CAL_H
#undef OPAMP1_CSR_1_OPA3LPM
#undef OPAMP1_CSR_1_ANAWSEL3
#undef OPAMP1_CSR_2_OPA3CALOUT
#undef OPAMP1_OTR_0_AO3_OPT_OFFSET_TRIM_LOW
#undef OPAMP1_OTR_0_AO3_OPT_OFFSET_TRIM_HIGH
#undef OPAMP1_OTR_1_AO3_OPT_OFFSET_TRIM_LP_LOW
#undef OPAMP1_OTR_1_AO3_OPT_OFFSET_TRIM_LP_HIGH
#undef OPAMP3_CSR_1_OPA3PD
#undef OPAMP3_CSR_1_S3SEL3
#undef OPAMP3_CSR_1_S4SEL3
#undef OPAMP3_CSR_1_S5SEL3
#undef OPAMP3_CSR_1_S6SEL3
#undef OPAMP3_CSR_1_OPA3CAL_L
#undef OPAMP3_CSR_1_OPA3CAL_H
#undef OPAMP3_CSR_1_OPA3LPM
#undef OPAMP3_CSR_1_ANAWSEL3
#undef OPAMP3_CSR_1_OPA3CALOUT
#undef OPAMP4_CSR_1_OPA3PD
#undef OPAMP4_CSR_1_S3SEL3
#undef OPAMP4_CSR_1_S4SEL3
#undef OPAMP4_CSR_1_S5SEL3
#undef OPAMP4_CSR_1_S6SEL3
#undef OPAMP4_CSR_1_OPA3CAL_L
#undef OPAMP4_CSR_1_OPA3CAL_H
#undef OPAMP4_CSR_1_OPA3LPM
#undef OPAMP4_CSR_1_ANAWSEL3
#undef OPAMP4_CSR_1_OPA3CALOUT
#undef OPAMP_MAP1_LPOTR
#undef OPAMP_CSR_2_OPALPM
#undef OPAMP_CSR_2_OPAMODE
#undef OPAMP_CSR_2_PGGAIN
#undef OPAMP_CSR_2_VPSEL
#undef OPAMP_CSR_2_CALON
#undef OPAMP_CSR_2_CALSEL
#undef OPAMP_CSR_2_USERTRIM
#undef OPAMP_CSR_2_CALOUT
#undef OPAMP2_CSR_1_OPALPM
#undef OPAMP2_CSR_1_OPAMODE
#undef OPAMP2_CSR_1_VPSEL
#undef OPAMP2_CSR_1_CALON
#undef OPAMP2_CSR_1_CALSEL
#undef OPAMP2_CSR_1_USERTRIM
#undef OPAMP2_CSR_2_VMSEL
#undef OPAMP2_CSR_2_CALOUT
#undef OPAMP2_CSR_3_PGGAIN
#undef OPAMP1_CSR_1_OPALPM
#undef OPAMP1_CSR_1_OPAMODE
#undef OPAMP1_CSR_1_PGAGAIN
#undef OPAMP1_CSR_1_VPSEL
#undef OPAMP1_CSR_1_CALON
#undef OPAMP1_CSR_1_CALSEL
#undef OPAMP1_CSR_1_USERTRIM
#undef OPAMP1_CSR_1_OPARANGE
#undef OPAMP1_CSR_2_VMSEL
#undef OPAMP1_CSR_2_CALOUT
#undef OPAMP1_CSR_3_PGGAIN
#undef OPAMP3_CSR_2_OPALPM
#undef OPAMP3_CSR_2_OPAMODE
#undef OPAMP3_CSR_2_PGGAIN
#undef OPAMP3_CSR_2_VPSEL
#undef OPAMP3_CSR_2_CALON
#undef OPAMP3_CSR_2_CALSEL
#undef OPAMP3_CSR_2_USERTRIM
#undef OPAMP3_CSR_2_CALOUT
#undef OPAMP4_CSR_2_OPALPM
#undef OPAMP4_CSR_2_OPAMODE
#undef OPAMP4_CSR_2_PGGAIN
#undef OPAMP4_CSR_2_VPSEL
#undef OPAMP4_CSR_2_CALON
#undef OPAMP4_CSR_2_CALSEL
#undef OPAMP4_CSR_2_USERTRIM
#undef OPAMP4_CSR_2_CALOUT
#undef OPAMP_MAP0_OTR
#undef OPAMP_OTR_0_TRIMOFFSETN
#undef OPAMP_OTR_0_TRIMOFFSETP
#undef OPAMP2_OTR_0_TRIMOFFSETN
#undef OPAMP2_OTR_0_TRIMOFFSETP
#undef OPAMP1_CSR_1_OPAEN
#undef OPAMP1_OTR_0_TRIMOFFSETN
#undef OPAMP1_OTR_0_TRIMOFFSETP
#undef OPAMP2_CSR_1_OPAEN
#undef OPAMP2_CSR_1_PGAGAIN
#undef OPAMP1_CSR_0_OPAMP1EN
#undef OPAMP3_CSR_0_OPAMP3EN
#undef OPAMP4_CSR_0_OPAMP4EN
//endregion
#endif
#endif
