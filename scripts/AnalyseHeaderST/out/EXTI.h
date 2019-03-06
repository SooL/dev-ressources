#ifndef __SOOL_EXTI_H
#define __SOOL_EXTI_H

#include "peripheral_include.h"
//SOOL-EXTI-INCLUDES
#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F2     ) || defined(STM32F3     ) ||\
    defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L1     ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
//region defines

#if defined(STM32H7     ) 
#define EXTI_D3PCR1H
#define EXTI_D3PCR1L
#define EXTI_D3PCR2H
#define EXTI_D3PCR2L
#define EXTI_D3PCR3H
#define EXTI_D3PCR3L
#define EXTI_D3PMR1
#define EXTI_D3PMR2
#define EXTI_D3PMR3
#define EXTI_EMR2_0_EM41     EM41                 // 1 bits @ 9
#define EXTI_EMR2_0_EM42     EM42                 // 1 bits @ 10
#define EXTI_EMR2_0_EM43     EM43                 // 1 bits @ 11
#define EXTI_EMR2_0_EM44     EM44                 // 1 bits @ 12
#define EXTI_EMR2_0_EM45     EM45                 // 1 bits @ 13
#define EXTI_EMR2_0_EM46     EM46                 // 1 bits @ 14
#define EXTI_EMR2_0_EM47     EM47                 // 1 bits @ 15
#define EXTI_EMR2_0_EM48     EM48                 // 1 bits @ 16
#define EXTI_EMR2_0_EM49     EM49                 // 1 bits @ 17
#define EXTI_EMR2_0_EM50     EM50                 // 1 bits @ 18
#define EXTI_EMR2_0_EM51     EM51                 // 1 bits @ 19
#define EXTI_EMR2_0_EM52     EM52                 // 1 bits @ 20
#define EXTI_EMR2_0_EM53     EM53                 // 1 bits @ 21
#define EXTI_EMR2_0_EM54     EM54                 // 1 bits @ 22
#define EXTI_EMR2_0_EM55     EM55                 // 1 bits @ 23
#define EXTI_EMR2_0_EM56     EM56                 // 1 bits @ 24
#define EXTI_EMR2_0_EM57     EM57                 // 1 bits @ 25
#define EXTI_EMR2_0_EM58     EM58                 // 1 bits @ 26
#define EXTI_EMR2_0_EM59     EM59                 // 1 bits @ 27
#define EXTI_EMR2_0_EM60     EM60                 // 1 bits @ 28
#define EXTI_EMR2_0_EM61     EM61                 // 1 bits @ 29
#define EXTI_EMR2_0_EM62     EM62                 // 1 bits @ 30
#define EXTI_EMR2_0_EM63     EM63                 // 1 bits @ 31
#define EXTI_FTSR1_0_TR0     TR0                  // 1 bits @ 0
#define EXTI_FTSR1_0_TR1     TR1                  // 1 bits @ 1
#define EXTI_FTSR1_0_TR2     TR2                  // 1 bits @ 2
#define EXTI_FTSR1_0_TR3     TR3                  // 1 bits @ 3
#define EXTI_FTSR1_0_TR4     TR4                  // 1 bits @ 4
#define EXTI_FTSR1_0_TR5     TR5                  // 1 bits @ 5
#define EXTI_FTSR1_0_TR6     TR6                  // 1 bits @ 6
#define EXTI_FTSR1_0_TR7     TR7                  // 1 bits @ 7
#define EXTI_FTSR1_0_TR8     TR8                  // 1 bits @ 8
#define EXTI_FTSR1_0_TR9     TR9                  // 1 bits @ 9
#define EXTI_FTSR1_0_TR10    TR10                 // 1 bits @ 10
#define EXTI_FTSR1_0_TR11    TR11                 // 1 bits @ 11
#define EXTI_FTSR1_0_TR12    TR12                 // 1 bits @ 12
#define EXTI_FTSR1_0_TR13    TR13                 // 1 bits @ 13
#define EXTI_FTSR1_0_TR14    TR14                 // 1 bits @ 14
#define EXTI_FTSR1_0_TR15    TR15                 // 1 bits @ 15
#define EXTI_FTSR1_0_TR16    TR16                 // 1 bits @ 16
#define EXTI_FTSR1_0_TR17    TR17                 // 1 bits @ 17
#define EXTI_FTSR1_0_TR18    TR18                 // 1 bits @ 18
#define EXTI_FTSR1_0_TR19    TR19                 // 1 bits @ 19
#define EXTI_FTSR1_0_TR20    TR20                 // 1 bits @ 20
#define EXTI_FTSR1_0_TR21    TR21                 // 1 bits @ 21
#define EXTI_FTSR2_0_TR49    TR49                 // 1 bits @ 17
#define EXTI_FTSR2_0_TR51    TR51                 // 1 bits @ 19
#define EXTI_FTSR3
#define EXTI_IMR2_0_IM41     IM41                 // 1 bits @ 9
#define EXTI_IMR2_0_IM42     IM42                 // 1 bits @ 10
#define EXTI_IMR2_0_IM43     IM43                 // 1 bits @ 11
#define EXTI_IMR2_0_IM44     IM44                 // 1 bits @ 12
#define EXTI_IMR2_0_IM45     IM45                 // 1 bits @ 13
#define EXTI_IMR2_0_IM46     IM46                 // 1 bits @ 14
#define EXTI_IMR2_0_IM47     IM47                 // 1 bits @ 15
#define EXTI_IMR2_0_IM48     IM48                 // 1 bits @ 16
#define EXTI_IMR2_0_IM49     IM49                 // 1 bits @ 17
#define EXTI_IMR2_0_IM50     IM50                 // 1 bits @ 18
#define EXTI_IMR2_0_IM51     IM51                 // 1 bits @ 19
#define EXTI_IMR2_0_IM52     IM52                 // 1 bits @ 20
#define EXTI_IMR2_0_IM53     IM53                 // 1 bits @ 21
#define EXTI_IMR2_0_IM54     IM54                 // 1 bits @ 22
#define EXTI_IMR2_0_IM55     IM55                 // 1 bits @ 23
#define EXTI_IMR2_0_IM56     IM56                 // 1 bits @ 24
#define EXTI_IMR2_0_IM57     IM57                 // 1 bits @ 25
#define EXTI_IMR2_0_IM58     IM58                 // 1 bits @ 26
#define EXTI_IMR2_0_IM59     IM59                 // 1 bits @ 27
#define EXTI_IMR2_0_IM60     IM60                 // 1 bits @ 28
#define EXTI_IMR2_0_IM61     IM61                 // 1 bits @ 29
#define EXTI_IMR2_0_IM62     IM62                 // 1 bits @ 30
#define EXTI_IMR2_0_IM63     IM63                 // 1 bits @ 31
#define EXTI_PR1_0_PR0       PR0                  // 1 bits @ 0
#define EXTI_PR1_0_PR1       PR1                  // 1 bits @ 1
#define EXTI_PR1_0_PR2       PR2                  // 1 bits @ 2
#define EXTI_PR1_0_PR3       PR3                  // 1 bits @ 3
#define EXTI_PR1_0_PR4       PR4                  // 1 bits @ 4
#define EXTI_PR1_0_PR5       PR5                  // 1 bits @ 5
#define EXTI_PR1_0_PR6       PR6                  // 1 bits @ 6
#define EXTI_PR1_0_PR7       PR7                  // 1 bits @ 7
#define EXTI_PR1_0_PR8       PR8                  // 1 bits @ 8
#define EXTI_PR1_0_PR9       PR9                  // 1 bits @ 9
#define EXTI_PR1_0_PR10      PR10                 // 1 bits @ 10
#define EXTI_PR1_0_PR11      PR11                 // 1 bits @ 11
#define EXTI_PR1_0_PR12      PR12                 // 1 bits @ 12
#define EXTI_PR1_0_PR13      PR13                 // 1 bits @ 13
#define EXTI_PR1_0_PR14      PR14                 // 1 bits @ 14
#define EXTI_PR1_0_PR15      PR15                 // 1 bits @ 15
#define EXTI_PR1_0_PR16      PR16                 // 1 bits @ 16
#define EXTI_PR1_0_PR17      PR17                 // 1 bits @ 17
#define EXTI_PR1_0_PR18      PR18                 // 1 bits @ 18
#define EXTI_PR1_0_PR19      PR19                 // 1 bits @ 19
#define EXTI_PR1_0_PR20      PR20                 // 1 bits @ 20
#define EXTI_PR1_0_PR21      PR21                 // 1 bits @ 21
#define EXTI_PR2_0_PR49      PR49                 // 1 bits @ 17
#define EXTI_PR2_0_PR51      PR51                 // 1 bits @ 19
#define EXTI_RTSR1_0_TR0     TR0                  // 1 bits @ 0
#define EXTI_RTSR1_0_TR1     TR1                  // 1 bits @ 1
#define EXTI_RTSR1_0_TR2     TR2                  // 1 bits @ 2
#define EXTI_RTSR1_0_TR3     TR3                  // 1 bits @ 3
#define EXTI_RTSR1_0_TR4     TR4                  // 1 bits @ 4
#define EXTI_RTSR1_0_TR5     TR5                  // 1 bits @ 5
#define EXTI_RTSR1_0_TR6     TR6                  // 1 bits @ 6
#define EXTI_RTSR1_0_TR7     TR7                  // 1 bits @ 7
#define EXTI_RTSR1_0_TR8     TR8                  // 1 bits @ 8
#define EXTI_RTSR1_0_TR9     TR9                  // 1 bits @ 9
#define EXTI_RTSR1_0_TR10    TR10                 // 1 bits @ 10
#define EXTI_RTSR1_0_TR11    TR11                 // 1 bits @ 11
#define EXTI_RTSR1_0_TR12    TR12                 // 1 bits @ 12
#define EXTI_RTSR1_0_TR13    TR13                 // 1 bits @ 13
#define EXTI_RTSR1_0_TR14    TR14                 // 1 bits @ 14
#define EXTI_RTSR1_0_TR15    TR15                 // 1 bits @ 15
#define EXTI_RTSR1_0_TR16    TR16                 // 1 bits @ 16
#define EXTI_RTSR1_0_TR17    TR17                 // 1 bits @ 17
#define EXTI_RTSR1_0_TR18    TR18                 // 1 bits @ 18
#define EXTI_RTSR1_0_TR19    TR19                 // 1 bits @ 19
#define EXTI_RTSR1_0_TR20    TR20                 // 1 bits @ 20
#define EXTI_RTSR1_0_TR21    TR21                 // 1 bits @ 21
#define EXTI_RTSR2_0_TR49    TR49                 // 1 bits @ 17
#define EXTI_RTSR2_0_TR51    TR51                 // 1 bits @ 19
#define EXTI_RTSR3
#define EXTI_SWIER1_0_SWIER0 SWIER0               // 1 bits @ 0
#define EXTI_SWIER1_0_SWIER1 SWIER1               // 1 bits @ 1
#define EXTI_SWIER1_0_SWIER2 SWIER2               // 1 bits @ 2
#define EXTI_SWIER1_0_SWIER3 SWIER3               // 1 bits @ 3
#define EXTI_SWIER1_0_SWIER4 SWIER4               // 1 bits @ 4
#define EXTI_SWIER1_0_SWIER5 SWIER5               // 1 bits @ 5
#define EXTI_SWIER1_0_SWIER6 SWIER6               // 1 bits @ 6
#define EXTI_SWIER1_0_SWIER7 SWIER7               // 1 bits @ 7
#define EXTI_SWIER1_0_SWIER8 SWIER8               // 1 bits @ 8
#define EXTI_SWIER1_0_SWIER9 SWIER9               // 1 bits @ 9
#define EXTI_SWIER1_0_SWIER10 SWIER10              // 1 bits @ 10
#define EXTI_SWIER1_0_SWIER11 SWIER11              // 1 bits @ 11
#define EXTI_SWIER1_0_SWIER12 SWIER12              // 1 bits @ 12
#define EXTI_SWIER1_0_SWIER13 SWIER13              // 1 bits @ 13
#define EXTI_SWIER1_0_SWIER14 SWIER14              // 1 bits @ 14
#define EXTI_SWIER1_0_SWIER15 SWIER15              // 1 bits @ 15
#define EXTI_SWIER1_0_SWIER16 SWIER16              // 1 bits @ 16
#define EXTI_SWIER1_0_SWIER17 SWIER17              // 1 bits @ 17
#define EXTI_SWIER1_0_SWIER18 SWIER18              // 1 bits @ 18
#define EXTI_SWIER1_0_SWIER19 SWIER19              // 1 bits @ 19
#define EXTI_SWIER1_0_SWIER20 SWIER20              // 1 bits @ 20
#define EXTI_SWIER1_0_SWIER21 SWIER21              // 1 bits @ 21
#define EXTI_SWIER2_0_SWIER49 SWIER49              // 1 bits @ 17
#define EXTI_SWIER2_0_SWIER51 SWIER51              // 1 bits @ 19
#define EXTI_SWIER3
#define EXTI_MAP1_RTSR1      RTSR1_TypeDef RTSR1
#define EXTI_MAP1_FTSR1      FTSR1_TypeDef FTSR1
#define EXTI_MAP1_SWIER1     SWIER1_TypeDef SWIER1
#define EXTI_MAP1_D3PMR1     D3PMR1_TypeDef D3PMR1
#define EXTI_MAP1_D3PCR1L    uint32_t D3PCR1L
#define EXTI_MAP1_D3PCR1H    uint32_t D3PCR1H
#define EXTI_MAP1_RTSR2      RTSR2_TypeDef RTSR2
#define EXTI_MAP1_FTSR2      FTSR2_TypeDef FTSR2
#define EXTI_MAP1_SWIER2     SWIER2_TypeDef SWIER2
#define EXTI_MAP1_D3PMR2     D3PMR2_TypeDef D3PMR2
#define EXTI_MAP1_D3PCR2L    uint32_t D3PCR2L
#define EXTI_MAP1_D3PCR2H    uint32_t D3PCR2H
#define EXTI_MAP0_RTSR3      RTSR3_TypeDef RTSR3
#define EXTI_MAP0_FTSR3      FTSR3_TypeDef FTSR3
#define EXTI_MAP0_SWIER3     SWIER3_TypeDef SWIER3
#define EXTI_MAP0_D3PMR3     D3PMR3_TypeDef D3PMR3
#define EXTI_MAP0_D3PCR3L    uint32_t D3PCR3L
#define EXTI_MAP0_D3PCR3H    uint32_t D3PCR3H
#else
#define EXTI_EMR2_0_EM41
#define EXTI_EMR2_0_EM42
#define EXTI_EMR2_0_EM43
#define EXTI_EMR2_0_EM44
#define EXTI_EMR2_0_EM45
#define EXTI_EMR2_0_EM46
#define EXTI_EMR2_0_EM47
#define EXTI_EMR2_0_EM48
#define EXTI_EMR2_0_EM49
#define EXTI_EMR2_0_EM50
#define EXTI_EMR2_0_EM51
#define EXTI_EMR2_0_EM52
#define EXTI_EMR2_0_EM53
#define EXTI_EMR2_0_EM54
#define EXTI_EMR2_0_EM55
#define EXTI_EMR2_0_EM56
#define EXTI_EMR2_0_EM57
#define EXTI_EMR2_0_EM58
#define EXTI_EMR2_0_EM59
#define EXTI_EMR2_0_EM60
#define EXTI_EMR2_0_EM61
#define EXTI_EMR2_0_EM62
#define EXTI_EMR2_0_EM63
#define EXTI_FTSR1_0_TR0
#define EXTI_FTSR1_0_TR1
#define EXTI_FTSR1_0_TR2
#define EXTI_FTSR1_0_TR3
#define EXTI_FTSR1_0_TR4
#define EXTI_FTSR1_0_TR5
#define EXTI_FTSR1_0_TR6
#define EXTI_FTSR1_0_TR7
#define EXTI_FTSR1_0_TR8
#define EXTI_FTSR1_0_TR9
#define EXTI_FTSR1_0_TR10
#define EXTI_FTSR1_0_TR11
#define EXTI_FTSR1_0_TR12
#define EXTI_FTSR1_0_TR13
#define EXTI_FTSR1_0_TR14
#define EXTI_FTSR1_0_TR15
#define EXTI_FTSR1_0_TR16
#define EXTI_FTSR1_0_TR17
#define EXTI_FTSR1_0_TR18
#define EXTI_FTSR1_0_TR19
#define EXTI_FTSR1_0_TR20
#define EXTI_FTSR1_0_TR21
#define EXTI_FTSR2_0_TR49
#define EXTI_FTSR2_0_TR51
#define EXTI_IMR2_0_IM41
#define EXTI_IMR2_0_IM42
#define EXTI_IMR2_0_IM43
#define EXTI_IMR2_0_IM44
#define EXTI_IMR2_0_IM45
#define EXTI_IMR2_0_IM46
#define EXTI_IMR2_0_IM47
#define EXTI_IMR2_0_IM48
#define EXTI_IMR2_0_IM49
#define EXTI_IMR2_0_IM50
#define EXTI_IMR2_0_IM51
#define EXTI_IMR2_0_IM52
#define EXTI_IMR2_0_IM53
#define EXTI_IMR2_0_IM54
#define EXTI_IMR2_0_IM55
#define EXTI_IMR2_0_IM56
#define EXTI_IMR2_0_IM57
#define EXTI_IMR2_0_IM58
#define EXTI_IMR2_0_IM59
#define EXTI_IMR2_0_IM60
#define EXTI_IMR2_0_IM61
#define EXTI_IMR2_0_IM62
#define EXTI_IMR2_0_IM63
#define EXTI_PR1_0_PR0
#define EXTI_PR1_0_PR1
#define EXTI_PR1_0_PR2
#define EXTI_PR1_0_PR3
#define EXTI_PR1_0_PR4
#define EXTI_PR1_0_PR5
#define EXTI_PR1_0_PR6
#define EXTI_PR1_0_PR7
#define EXTI_PR1_0_PR8
#define EXTI_PR1_0_PR9
#define EXTI_PR1_0_PR10
#define EXTI_PR1_0_PR11
#define EXTI_PR1_0_PR12
#define EXTI_PR1_0_PR13
#define EXTI_PR1_0_PR14
#define EXTI_PR1_0_PR15
#define EXTI_PR1_0_PR16
#define EXTI_PR1_0_PR17
#define EXTI_PR1_0_PR18
#define EXTI_PR1_0_PR19
#define EXTI_PR1_0_PR20
#define EXTI_PR1_0_PR21
#define EXTI_PR2_0_PR49
#define EXTI_PR2_0_PR51
#define EXTI_RTSR1_0_TR0
#define EXTI_RTSR1_0_TR1
#define EXTI_RTSR1_0_TR2
#define EXTI_RTSR1_0_TR3
#define EXTI_RTSR1_0_TR4
#define EXTI_RTSR1_0_TR5
#define EXTI_RTSR1_0_TR6
#define EXTI_RTSR1_0_TR7
#define EXTI_RTSR1_0_TR8
#define EXTI_RTSR1_0_TR9
#define EXTI_RTSR1_0_TR10
#define EXTI_RTSR1_0_TR11
#define EXTI_RTSR1_0_TR12
#define EXTI_RTSR1_0_TR13
#define EXTI_RTSR1_0_TR14
#define EXTI_RTSR1_0_TR15
#define EXTI_RTSR1_0_TR16
#define EXTI_RTSR1_0_TR17
#define EXTI_RTSR1_0_TR18
#define EXTI_RTSR1_0_TR19
#define EXTI_RTSR1_0_TR20
#define EXTI_RTSR1_0_TR21
#define EXTI_RTSR2_0_TR49
#define EXTI_RTSR2_0_TR51
#define EXTI_SWIER1_0_SWIER0
#define EXTI_SWIER1_0_SWIER1
#define EXTI_SWIER1_0_SWIER2
#define EXTI_SWIER1_0_SWIER3
#define EXTI_SWIER1_0_SWIER4
#define EXTI_SWIER1_0_SWIER5
#define EXTI_SWIER1_0_SWIER6
#define EXTI_SWIER1_0_SWIER7
#define EXTI_SWIER1_0_SWIER8
#define EXTI_SWIER1_0_SWIER9
#define EXTI_SWIER1_0_SWIER10
#define EXTI_SWIER1_0_SWIER11
#define EXTI_SWIER1_0_SWIER12
#define EXTI_SWIER1_0_SWIER13
#define EXTI_SWIER1_0_SWIER14
#define EXTI_SWIER1_0_SWIER15
#define EXTI_SWIER1_0_SWIER16
#define EXTI_SWIER1_0_SWIER17
#define EXTI_SWIER1_0_SWIER18
#define EXTI_SWIER1_0_SWIER19
#define EXTI_SWIER1_0_SWIER20
#define EXTI_SWIER1_0_SWIER21
#define EXTI_SWIER2_0_SWIER49
#define EXTI_SWIER2_0_SWIER51
#define EXTI_MAP1_RTSR1 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP1_FTSR1 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP1_SWIER1 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP1_D3PMR1 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP1_D3PCR1L __SOOL_PERIPH_PADDING_4
#define EXTI_MAP1_D3PCR1H __SOOL_PERIPH_PADDING_4
#define EXTI_MAP1_RTSR2 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP1_FTSR2 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP1_SWIER2 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP1_D3PMR2 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP1_D3PCR2L __SOOL_PERIPH_PADDING_4
#define EXTI_MAP1_D3PCR2H __SOOL_PERIPH_PADDING_4
#define EXTI_MAP0_RTSR3 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP0_FTSR3 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP0_SWIER3 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP0_D3PMR3 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP0_D3PCR3L __SOOL_PERIPH_PADDING_4
#define EXTI_MAP0_D3PCR3H __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F2     ) || defined(STM32F3     ) ||\
    defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L1     ) 
#define EXTI_EMR
#define EXTI_FTSR
#define EXTI_IMR
#define EXTI_PR
#define EXTI_RTSR
#define EXTI_SWIER
#define EXTI_MAP0_IMR        IMR_TypeDef IMR
#define EXTI_MAP0_EMR        EMR_TypeDef EMR
#define EXTI_MAP0_RTSR       RTSR_TypeDef RTSR
#define EXTI_MAP0_FTSR       FTSR_TypeDef FTSR
#define EXTI_MAP0_SWIER      SWIER_TypeDef SWIER
#define EXTI_MAP0_PR         PR_TypeDef PR
#else
#define EXTI_MAP0_IMR __SOOL_PERIPH_PADDING_4
#define EXTI_MAP0_EMR __SOOL_PERIPH_PADDING_4
#define EXTI_MAP0_RTSR __SOOL_PERIPH_PADDING_4
#define EXTI_MAP0_FTSR __SOOL_PERIPH_PADDING_4
#define EXTI_MAP0_SWIER __SOOL_PERIPH_PADDING_4
#define EXTI_MAP0_PR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F031x6 ) || defined(STM32F038xx ) || defined(STM32F042x6 ) || defined(STM32F048xx ) ||\
    defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F1     ) ||\
    defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) || defined(STM32F7     ) ||\
    defined(STM32L1     ) 
#define EXTI_EMR_0_MR16      MR16                 // 1 bits @ 16
#define EXTI_IMR_0_MR16      MR16                 // 1 bits @ 16
#else
#define EXTI_EMR_0_MR16
#define EXTI_IMR_0_MR16
#endif

#if defined(STM32F0     ) || defined(STM32F101x6 ) || defined(STM32F101xB ) || defined(STM32F101xE ) ||\
    defined(STM32F101xG ) || defined(STM32F102x6 ) || defined(STM32F102xB ) || defined(STM32F103x6 ) ||\
    defined(STM32F103xB ) || defined(STM32F103xE ) || defined(STM32F103xG ) || defined(STM32F105xC ) ||\
    defined(STM32F107xC ) || defined(STM32F2     ) || defined(STM32F302x8 ) || defined(STM32F302xC ) ||\
    defined(STM32F302xE ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F373xC ) ||\
    defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L1     ) 
#define EXTI_EMR_0_MR18      MR18                 // 1 bits @ 18
#define EXTI_IMR_0_MR18      MR18                 // 1 bits @ 18
#else
#define EXTI_EMR_0_MR18
#define EXTI_IMR_0_MR18
#endif

#if defined(STM32F0     ) || defined(STM32F105xC ) || defined(STM32F107xC ) || defined(STM32F2     ) ||\
    defined(STM32F3     ) || defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L1     ) 
#define EXTI_EMR_0_MR19      MR19                 // 1 bits @ 19
#define EXTI_IMR_0_MR19      MR19                 // 1 bits @ 19
#else
#define EXTI_EMR_0_MR19
#define EXTI_IMR_0_MR19
#endif

#if defined(STM32F030xC ) || defined(STM32F070xB ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F2     ) ||\
    defined(STM32F3     ) || defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L1     ) 
#define EXTI_EMR_0_MR20      MR20                 // 1 bits @ 20
#define EXTI_IMR_0_MR20      MR20                 // 1 bits @ 20
#else
#define EXTI_EMR_0_MR20
#define EXTI_IMR_0_MR20
#endif

#if defined(STM32F031x6 ) || defined(STM32F038xx ) || defined(STM32F042x6 ) || defined(STM32F048xx ) ||\
    defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F2     ) ||\
    defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) || defined(STM32F303xE ) ||\
    defined(STM32F358xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F398xx ) ||\
    defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L1     ) 
#define EXTI_EMR_0_MR21      MR21                 // 1 bits @ 21
#define EXTI_IMR_0_MR21      MR21                 // 1 bits @ 21
#else
#define EXTI_EMR_0_MR21
#define EXTI_IMR_0_MR21
#endif

#if defined(STM32F031x6 ) || defined(STM32F038xx ) || defined(STM32F042x6 ) || defined(STM32F048xx ) ||\
    defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F2     ) ||\
    defined(STM32F3     ) || defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L1     ) 
#define EXTI_EMR_0_MR22      MR22                 // 1 bits @ 22
#define EXTI_IMR_0_MR22      MR22                 // 1 bits @ 22
#else
#define EXTI_EMR_0_MR22
#define EXTI_IMR_0_MR22
#endif

#if defined(STM32F0     ) || defined(STM32F3     ) || defined(STM32F410Cx ) || defined(STM32F410Rx ) ||\
    defined(STM32F410Tx ) || defined(STM32F413xx ) || defined(STM32F423xx ) || defined(STM32F7     ) ||\
    defined(STM32L100xC ) || defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) ||\
    defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) ||\
    defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define EXTI_EMR_0_MR23      MR23                 // 1 bits @ 23
#define EXTI_IMR_0_MR23      MR23                 // 1 bits @ 23
#else
#define EXTI_EMR_0_MR23
#define EXTI_IMR_0_MR23
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) || defined(STM32F358xx ) ||\
    defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F398xx ) || defined(STM32F765xx ) ||\
    defined(STM32F767xx ) || defined(STM32F769xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) 
#define EXTI_EMR_0_MR24      MR24                 // 1 bits @ 24
#define EXTI_IMR_0_MR24      MR24                 // 1 bits @ 24
#else
#define EXTI_EMR_0_MR24
#define EXTI_IMR_0_MR24
#endif

#if defined(STM32F031x6 ) || defined(STM32F038xx ) || defined(STM32F042x6 ) || defined(STM32F048xx ) ||\
    defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F3     ) 
#define EXTI_EMR_0_MR25      MR25                 // 1 bits @ 25
#define EXTI_EMR_1_EM27      EM27                 // 1 bits @ 27
#define EXTI_IMR_0_MR25      MR25                 // 1 bits @ 25
#define EXTI_IMR_1_IM27      IM27                 // 1 bits @ 27
#else
#define EXTI_EMR_0_MR25
#define EXTI_EMR_1_EM27
#define EXTI_IMR_0_MR25
#define EXTI_IMR_1_IM27
#endif

#if defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) ||\
    defined(STM32F098xx ) || defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F358xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) ||\
    defined(STM32F398xx ) 
#define EXTI_EMR_0_MR26      MR26                 // 1 bits @ 26
#define EXTI_IMR_0_MR26      MR26                 // 1 bits @ 26
#else
#define EXTI_EMR_0_MR26
#define EXTI_IMR_0_MR26
#endif

#if defined(STM32F031x6 ) || defined(STM32F038xx ) || defined(STM32F042x6 ) || defined(STM32F048xx ) ||\
    defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F301x8 ) ||\
    defined(STM32F302x8 ) || defined(STM32F302xE ) || defined(STM32F303xE ) || defined(STM32F318xx ) ||\
    defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F398xx ) 
#define EXTI_EMR_0_MR27      MR27                 // 1 bits @ 27
#define EXTI_IMR_0_MR27      MR27                 // 1 bits @ 27
#else
#define EXTI_EMR_0_MR27
#define EXTI_IMR_0_MR27
#endif

#if defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F358xx ) || defined(STM32F373xC ) ||\
    defined(STM32F378xx ) || defined(STM32F398xx ) 
#define EXTI_EMR_0_MR28      MR28                 // 1 bits @ 28
#define EXTI_IMR_0_MR28      MR28                 // 1 bits @ 28
#else
#define EXTI_EMR_0_MR28
#define EXTI_IMR_0_MR28
#endif

#if defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F358xx ) || defined(STM32F398xx ) 
#define EXTI_EMR_0_MR29      MR29                 // 1 bits @ 29
#define EXTI_EMR2_0_MR33     MR33                 // 1 bits @ 1
#define EXTI_FTSR_0_TR29     TR29                 // 1 bits @ 29
#define EXTI_FTSR2_0_TR33    TR33                 // 1 bits @ 1
#define EXTI_IMR_0_MR29      MR29                 // 1 bits @ 29
#define EXTI_IMR2_0_MR33     MR33                 // 1 bits @ 1
#define EXTI_PR_0_P29        P29                  // 1 bits @ 29
#define EXTI_PR2_0_PR33      PR33                 // 1 bits @ 1
#define EXTI_RTSR_0_TR29     TR29                 // 1 bits @ 29
#define EXTI_RTSR2_0_TR33    TR33                 // 1 bits @ 1
#define EXTI_SWIER_0_SWIE29  SWIE29               // 1 bits @ 29
#define EXTI_SWIER2_0_SWIER33 SWIER33              // 1 bits @ 1
#else
#define EXTI_EMR_0_MR29
#define EXTI_EMR2_0_MR33
#define EXTI_FTSR_0_TR29
#define EXTI_FTSR2_0_TR33
#define EXTI_IMR_0_MR29
#define EXTI_IMR2_0_MR33
#define EXTI_PR_0_P29
#define EXTI_PR2_0_PR33
#define EXTI_RTSR_0_TR29
#define EXTI_RTSR2_0_TR33
#define EXTI_SWIER_0_SWIE29
#define EXTI_SWIER2_0_SWIER33
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F398xx ) 
#define EXTI_EMR_0_MR30      MR30                 // 1 bits @ 30
#define EXTI_EMR2_0_MR32     MR32                 // 1 bits @ 0
#define EXTI_EMR2_2
#define EXTI_FTSR_0_TR30     TR30                 // 1 bits @ 30
#define EXTI_FTSR2_0_TR32    TR32                 // 1 bits @ 0
#define EXTI_FTSR2_1
#define EXTI_IMR_0_MR30      MR30                 // 1 bits @ 30
#define EXTI_IMR_6
#define EXTI_IMR2_0_MR32     MR32                 // 1 bits @ 0
#define EXTI_IMR2_2
#define EXTI_PR_0_P30        P30                  // 1 bits @ 30
#define EXTI_PR2_0_PR32      PR32                 // 1 bits @ 0
#define EXTI_PR2_1
#define EXTI_RTSR_0_TR30     TR30                 // 1 bits @ 30
#define EXTI_RTSR2_0_TR32    TR32                 // 1 bits @ 0
#define EXTI_RTSR2_1
#define EXTI_SWIER_0_SWIE30  SWIE30               // 1 bits @ 30
#define EXTI_SWIER2_0_SWIER32 SWIER32              // 1 bits @ 0
#define EXTI_SWIER2_1
#else
#define EXTI_EMR_0_MR30
#define EXTI_EMR2_0_MR32
#define EXTI_FTSR_0_TR30
#define EXTI_FTSR2_0_TR32
#define EXTI_IMR_0_MR30
#define EXTI_IMR2_0_MR32
#define EXTI_PR_0_P30
#define EXTI_PR2_0_PR32
#define EXTI_RTSR_0_TR30
#define EXTI_RTSR2_0_TR32
#define EXTI_SWIER_0_SWIE30
#define EXTI_SWIER2_0_SWIER32
#endif

#if defined(STM32F042x6 ) || defined(STM32F048xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F358xx ) || defined(STM32F398xx ) 
#define EXTI_EMR_0_MR31      MR31                 // 1 bits @ 31
#define EXTI_FTSR_0_TR31     TR31                 // 1 bits @ 31
#define EXTI_IMR_0_MR31      MR31                 // 1 bits @ 31
#define EXTI_PR_0_P31        P31                  // 1 bits @ 31
#define EXTI_RTSR_0_TR31     TR31                 // 1 bits @ 31
#define EXTI_SWIER_0_SWIE31  SWIE31               // 1 bits @ 31
#else
#define EXTI_EMR_0_MR31
#define EXTI_FTSR_0_TR31
#define EXTI_IMR_0_MR31
#define EXTI_PR_0_P31
#define EXTI_RTSR_0_TR31
#define EXTI_SWIER_0_SWIE31
#endif

#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F2     ) || defined(STM32F3     ) ||\
    defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L0     ) || defined(STM32L1     ) 
#define EXTI_EMR_1
#define EXTI_FTSR_0
#define EXTI_IMR_1
#define EXTI_PR_0
#define EXTI_RTSR_0
#define EXTI_SWIER_0
#endif

#if defined(STM32F031x6 ) || defined(STM32F038xx ) || defined(STM32F042x6 ) || defined(STM32F048xx ) ||\
    defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F1     ) ||\
    defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) || defined(STM32F7     ) ||\
    defined(STM32L0     ) || defined(STM32L1     ) 
#define EXTI_EMR_1_EM16      EM16                 // 1 bits @ 16
#define EXTI_IMR_1_IM16      IM16                 // 1 bits @ 16
#else
#define EXTI_EMR_1_EM16
#define EXTI_IMR_1_IM16
#endif

#if defined(STM32F0     ) || defined(STM32F101x6 ) || defined(STM32F101xB ) || defined(STM32F101xE ) ||\
    defined(STM32F101xG ) || defined(STM32F102x6 ) || defined(STM32F102xB ) || defined(STM32F103x6 ) ||\
    defined(STM32F103xB ) || defined(STM32F103xE ) || defined(STM32F103xG ) || defined(STM32F105xC ) ||\
    defined(STM32F107xC ) || defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) ||\
    defined(STM32F7     ) || defined(STM32L0     ) || defined(STM32L1     ) 
#define EXTI_EMR_1_EM18      EM18                 // 1 bits @ 18
#define EXTI_IMR_1_IM18      IM18                 // 1 bits @ 18
#else
#define EXTI_EMR_1_EM18
#define EXTI_IMR_1_IM18
#endif

#if defined(STM32F0     ) || defined(STM32F105xC ) || defined(STM32F107xC ) || defined(STM32F2     ) ||\
    defined(STM32F3     ) || defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L0     ) ||\
    defined(STM32L1     ) 
#define EXTI_EMR_1_EM19      EM19                 // 1 bits @ 19
#define EXTI_FTSR_0_TR19     TR19                 // 1 bits @ 19
#define EXTI_IMR_1_IM19      IM19                 // 1 bits @ 19
#define EXTI_PR_0_P19        P19                  // 1 bits @ 19
#define EXTI_RTSR_0_TR19     TR19                 // 1 bits @ 19
#define EXTI_SWIER_0_SWIE19  SWIE19               // 1 bits @ 19
#else
#define EXTI_EMR_1_EM19
#define EXTI_FTSR_0_TR19
#define EXTI_IMR_1_IM19
#define EXTI_PR_0_P19
#define EXTI_RTSR_0_TR19
#define EXTI_SWIER_0_SWIE19
#endif

#if defined(STM32F030xC ) || defined(STM32F070xB ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F2     ) ||\
    defined(STM32F3     ) || defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L0     ) ||\
    defined(STM32L1     ) 
#define EXTI_EMR_1_EM20      EM20                 // 1 bits @ 20
#define EXTI_FTSR_0_TR20     TR20                 // 1 bits @ 20
#define EXTI_IMR_1_IM20      IM20                 // 1 bits @ 20
#define EXTI_PR_0_P20        P20                  // 1 bits @ 20
#define EXTI_RTSR_0_TR20     TR20                 // 1 bits @ 20
#define EXTI_SWIER_0_SWIE20  SWIE20               // 1 bits @ 20
#else
#define EXTI_EMR_1_EM20
#define EXTI_FTSR_0_TR20
#define EXTI_IMR_1_IM20
#define EXTI_PR_0_P20
#define EXTI_RTSR_0_TR20
#define EXTI_SWIER_0_SWIE20
#endif

#if defined(STM32F031x6 ) || defined(STM32F038xx ) || defined(STM32F042x6 ) || defined(STM32F048xx ) ||\
    defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F2     ) ||\
    defined(STM32F3     ) || defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L0     ) ||\
    defined(STM32L1     ) 
#define EXTI_EMR_1_EM21      EM21                 // 1 bits @ 21
#define EXTI_EMR_1_EM22      EM22                 // 1 bits @ 22
#define EXTI_FTSR_0_TR22     TR22                 // 1 bits @ 22
#define EXTI_IMR_1_IM21      IM21                 // 1 bits @ 21
#define EXTI_IMR_1_IM22      IM22                 // 1 bits @ 22
#define EXTI_PR_0_P22        P22                  // 1 bits @ 22
#define EXTI_RTSR_0_TR22     TR22                 // 1 bits @ 22
#define EXTI_SWIER_0_SWIE22  SWIE22               // 1 bits @ 22
#else
#define EXTI_EMR_1_EM21
#define EXTI_EMR_1_EM22
#define EXTI_FTSR_0_TR22
#define EXTI_IMR_1_IM21
#define EXTI_IMR_1_IM22
#define EXTI_PR_0_P22
#define EXTI_RTSR_0_TR22
#define EXTI_SWIER_0_SWIE22
#endif

#if defined(STM32F0     ) || defined(STM32F3     ) || defined(STM32F410Cx ) || defined(STM32F410Rx ) ||\
    defined(STM32F410Tx ) || defined(STM32F413xx ) || defined(STM32F423xx ) || defined(STM32F7     ) ||\
    defined(STM32L0     ) || defined(STM32L100xC ) || defined(STM32L151xC ) || defined(STM32L151xCA) ||\
    defined(STM32L151xD ) || defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xC ) ||\
    defined(STM32L152xCA) || defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) ||\
    defined(STM32L162xC ) || defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) ||\
    defined(STM32L162xE ) 
#define EXTI_EMR_1_EM23      EM23                 // 1 bits @ 23
#define EXTI_IMR_1_IM23      IM23                 // 1 bits @ 23
#else
#define EXTI_EMR_1_EM23
#define EXTI_IMR_1_IM23
#endif

#if defined(STM32F3     ) || defined(STM32F765xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) ||\
    defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32L071xx ) || defined(STM32L072xx ) ||\
    defined(STM32L073xx ) || defined(STM32L081xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) 
#define EXTI_EMR_1_EM24      EM24                 // 1 bits @ 24
#define EXTI_IMR_1_IM24      IM24                 // 1 bits @ 24
#else
#define EXTI_EMR_1_EM24
#define EXTI_IMR_1_IM24
#endif

#if defined(STM32F031x6 ) || defined(STM32F038xx ) || defined(STM32F042x6 ) || defined(STM32F048xx ) ||\
    defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F3     ) ||\
    defined(STM32L0     ) 
#define EXTI_EMR_1_EM25      EM25                 // 1 bits @ 25
#define EXTI_IMR_1_IM25      IM25                 // 1 bits @ 25
#else
#define EXTI_EMR_1_EM25
#define EXTI_IMR_1_IM25
#endif

#if defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) ||\
    defined(STM32F098xx ) || defined(STM32F3     ) || defined(STM32L0     ) 
#define EXTI_EMR_1_EM26      EM26                 // 1 bits @ 26
#define EXTI_IMR_1_IM26      IM26                 // 1 bits @ 26
#else
#define EXTI_EMR_1_EM26
#define EXTI_IMR_1_IM26
#endif

#if defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F3     ) || defined(STM32L0     ) 
#define EXTI_EMR_1_EM28      EM28                 // 1 bits @ 28
#define EXTI_IMR_1_IM28      IM28                 // 1 bits @ 28
#else
#define EXTI_EMR_1_EM28
#define EXTI_IMR_1_IM28
#endif

#if defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) || defined(STM32F328xx ) ||\
    defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) ||\
    defined(STM32F398xx ) || defined(STM32L0     ) 
#define EXTI_EMR_1_EM29      EM29                 // 1 bits @ 29
#define EXTI_IMR_1_IM29      IM29                 // 1 bits @ 29
#else
#define EXTI_EMR_1_EM29
#define EXTI_IMR_1_IM29
#endif

#if defined(STM32F3     ) 
#define EXTI_EMR_1_EM30      EM30                 // 1 bits @ 30
#define EXTI_FTSR_1_FT30     FT30                 // 1 bits @ 30
#define EXTI_IMR_1_IM30      IM30                 // 1 bits @ 30
#define EXTI_PR_1_PIF30      PIF30                // 1 bits @ 30
#define EXTI_RTSR_1_RT30     RT30                 // 1 bits @ 30
#define EXTI_SWIER_1_SWI30   SWI30                // 1 bits @ 30
#else
#define EXTI_EMR_1_EM30
#define EXTI_FTSR_1_FT30
#define EXTI_IMR_1_IM30
#define EXTI_PR_1_PIF30
#define EXTI_RTSR_1_RT30
#define EXTI_SWIER_1_SWI30
#endif

#if defined(STM32F042x6 ) || defined(STM32F048xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F3     ) 
#define EXTI_EMR_1_EM31      EM31                 // 1 bits @ 31
#define EXTI_FTSR_1_FT31     FT31                 // 1 bits @ 31
#define EXTI_IMR_1_IM31      IM31                 // 1 bits @ 31
#define EXTI_PR_1_PIF31      PIF31                // 1 bits @ 31
#define EXTI_RTSR_1_RT31     RT31                 // 1 bits @ 31
#define EXTI_SWIER_1_SWI31   SWI31                // 1 bits @ 31
#else
#define EXTI_EMR_1_EM31
#define EXTI_FTSR_1_FT31
#define EXTI_IMR_1_IM31
#define EXTI_PR_1_PIF31
#define EXTI_RTSR_1_RT31
#define EXTI_SWIER_1_SWI31
#endif

#if defined(STM32L4     ) || defined(STM32L4P    ) 
#define EXTI_EMR1
#define EXTI_EMR1_EM19       EM19                 // 1 bits @ 19
#define EXTI_FTSR1_0_FT22    FT22                 // 1 bits @ 22
#define EXTI_FTSR1_1
#define EXTI_FTSR2_0_FT37    FT37                 // 1 bits @ 5
#define EXTI_FTSR2_0_FT38    FT38                 // 1 bits @ 6
#define EXTI_IMR1
#define EXTI_PR1
#define EXTI_PR1_0_PIF22     PIF22                // 1 bits @ 22
#define EXTI_PR2_0_PIF37     PIF37                // 1 bits @ 5
#define EXTI_PR2_0_PIF38     PIF38                // 1 bits @ 6
#define EXTI_RTSR1_0_RT22    RT22                 // 1 bits @ 22
#define EXTI_RTSR1_1
#define EXTI_RTSR2_0_RT37    RT37                 // 1 bits @ 5
#define EXTI_RTSR2_0_RT38    RT38                 // 1 bits @ 6
#define EXTI_SWIER1_0_SWI22  SWI22                // 1 bits @ 22
#define EXTI_SWIER1_1
#define EXTI_SWIER2_0_SWI37  SWI37                // 1 bits @ 5
#define EXTI_SWIER2_0_SWI38  SWI38                // 1 bits @ 6
#define EXTI_MAP2_IMR1       IMR1_TypeDef IMR1
#define EXTI_MAP2_EMR1       EMR1_TypeDef EMR1
#define EXTI_MAP2_RTSR1      RTSR1_TypeDef RTSR1
#define EXTI_MAP2_FTSR1      FTSR1_TypeDef FTSR1
#define EXTI_MAP2_SWIER1     SWIER1_TypeDef SWIER1
#define EXTI_MAP2_PR1        PR1_TypeDef PR1
#else
#define EXTI_EMR1_EM19
#define EXTI_FTSR1_0_FT22
#define EXTI_FTSR2_0_FT37
#define EXTI_FTSR2_0_FT38
#define EXTI_PR1_0_PIF22
#define EXTI_PR2_0_PIF37
#define EXTI_PR2_0_PIF38
#define EXTI_RTSR1_0_RT22
#define EXTI_RTSR2_0_RT37
#define EXTI_RTSR2_0_RT38
#define EXTI_SWIER1_0_SWI22
#define EXTI_SWIER2_0_SWI37
#define EXTI_SWIER2_0_SWI38
#define EXTI_MAP2_IMR1 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP2_EMR1 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP2_RTSR1 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP2_FTSR1 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP2_SWIER1 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP2_PR1 __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32H7     ) || defined(STM32L451xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) ||\
    defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define EXTI_EMR1_EM29       EM29                 // 1 bits @ 29
#define EXTI_IMR1_0_IM29     IM29                 // 1 bits @ 29
#else
#define EXTI_EMR1_EM29
#define EXTI_IMR1_0_IM29
#endif

#if defined(STM32H7     ) || defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) ||\
    defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) ||\
    defined(STM32L4P    ) 
#define EXTI_EMR1_EM30       EM30                 // 1 bits @ 30
#define EXTI_EMR2_0_EM36     EM36                 // 1 bits @ 4
#define EXTI_IMR1_0_IM30     IM30                 // 1 bits @ 30
#define EXTI_IMR2_0_IM36     IM36                 // 1 bits @ 4
#else
#define EXTI_EMR1_EM30
#define EXTI_EMR2_0_EM36
#define EXTI_IMR1_0_IM30
#define EXTI_IMR2_0_IM36
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F398xx ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
#define EXTI_EMR2
#define EXTI_IMR2
#define EXTI_PR2
#define EXTI_MAP0_IMR2       IMR2_TypeDef IMR2
#define EXTI_MAP0_EMR2       EMR2_TypeDef EMR2
#define EXTI_MAP0_RTSR2      RTSR2_TypeDef RTSR2
#define EXTI_MAP0_FTSR2      FTSR2_TypeDef FTSR2
#define EXTI_MAP0_SWIER2     SWIER2_TypeDef SWIER2
#define EXTI_MAP0_PR2        PR2_TypeDef PR2
#else
#define EXTI_MAP0_IMR2 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP0_EMR2 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP0_RTSR2 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP0_FTSR2 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP0_SWIER2 __SOOL_PERIPH_PADDING_4
#define EXTI_MAP0_PR2 __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F398xx ) ||\
    defined(STM32H7     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define EXTI_EMR2_0
#define EXTI_EMR2_1
#define EXTI_FTSR2
#define EXTI_IMR2_0
#define EXTI_IMR2_1
#define EXTI_PR2_0
#define EXTI_RTSR2
#define EXTI_SWIER2
#endif

#if defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) || defined(STM32F303xE ) ||\
    defined(STM32F358xx ) || defined(STM32F398xx ) 
#define EXTI_EMR2_0_MR34     MR34                 // 1 bits @ 2
#define EXTI_EMR2_0_MR35     MR35                 // 1 bits @ 3
#define EXTI_IMR2_0_MR34     MR34                 // 1 bits @ 2
#define EXTI_IMR2_0_MR35     MR35                 // 1 bits @ 3
#else
#define EXTI_EMR2_0_MR34
#define EXTI_EMR2_0_MR35
#define EXTI_IMR2_0_MR34
#define EXTI_IMR2_0_MR35
#endif

#if defined(STM32H7     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define EXTI_EMR2_0_EM37     EM37                 // 1 bits @ 5
#define EXTI_EMR2_0_EM38     EM38                 // 1 bits @ 6
#define EXTI_FTSR1
#define EXTI_IMR1_0
#define EXTI_IMR2_0_IM37     IM37                 // 1 bits @ 5
#define EXTI_IMR2_0_IM38     IM38                 // 1 bits @ 6
#define EXTI_PR1_0
#define EXTI_RTSR1
#define EXTI_SWIER1
#else
#define EXTI_EMR2_0_EM37
#define EXTI_EMR2_0_EM38
#define EXTI_IMR2_0_IM37
#define EXTI_IMR2_0_IM38
#endif

#if defined(STM32H7     ) || defined(STM32L433xx ) || defined(STM32L443xx ) || defined(STM32L476xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) 
#define EXTI_EMR2_0_EM39     EM39                 // 1 bits @ 7
#define EXTI_IMR2_0_IM39     IM39                 // 1 bits @ 7
#else
#define EXTI_EMR2_0_EM39
#define EXTI_IMR2_0_IM39
#endif

#if defined(STM32H7     ) || defined(STM32L451xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define EXTI_EMR2_0_EM40     EM40                 // 1 bits @ 8
#define EXTI_IMR2_0_IM40     IM40                 // 1 bits @ 8
#else
#define EXTI_EMR2_0_EM40
#define EXTI_IMR2_0_IM40
#endif

#if defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) || defined(STM32F328xx ) ||\
    defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F398xx ) || defined(STM32H7     ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
#define EXTI_EMR2_1_EM33     EM33                 // 1 bits @ 1
#define EXTI_IMR2_1_IM33     IM33                 // 1 bits @ 1
#else
#define EXTI_EMR2_1_EM33
#define EXTI_IMR2_1_IM33
#endif

#if defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303x8 ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F318xx ) || defined(STM32F328xx ) || defined(STM32F334x8 ) ||\
    defined(STM32F358xx ) || defined(STM32F398xx ) || defined(STM32H7     ) || defined(STM32L431xx ) ||\
    defined(STM32L432xx ) || defined(STM32L433xx ) || defined(STM32L442xx ) || defined(STM32L443xx ) ||\
    defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) 
#define EXTI_EMR2_1_EM34     EM34                 // 1 bits @ 2
#define EXTI_IMR2_1_IM34     IM34                 // 1 bits @ 2
#else
#define EXTI_EMR2_1_EM34
#define EXTI_IMR2_1_IM34
#endif

#if defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303x8 ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F318xx ) || defined(STM32F328xx ) || defined(STM32F334x8 ) ||\
    defined(STM32F358xx ) || defined(STM32F398xx ) || defined(STM32H7     ) || defined(STM32L432xx ) ||\
    defined(STM32L433xx ) || defined(STM32L442xx ) || defined(STM32L443xx ) || defined(STM32L452xx ) ||\
    defined(STM32L462xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define EXTI_EMR2_1_EM35     EM35                 // 1 bits @ 3
#define EXTI_IMR2_1_IM35     IM35                 // 1 bits @ 3
#else
#define EXTI_EMR2_1_EM35
#define EXTI_IMR2_1_IM35
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F303x8 ) || defined(STM32F318xx ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) 
#define EXTI_EMR2_3
#define EXTI_IMR2_3
#endif

#if defined(STM32L471xx ) 
#define EXTI_EMR2_4
#define EXTI_IMR2_4
#endif

#if defined(STM32L475xx ) || defined(STM32L485xx ) 
#define EXTI_EMR2_5
#define EXTI_IMR2_5
#endif

#if defined(STM32L476xx ) || defined(STM32L486xx ) 
#define EXTI_EMR2_6
#define EXTI_IMR2_6
#endif

#if defined(STM32L496xx ) || defined(STM32L4A6xx ) 
#define EXTI_EMR2_7
#define EXTI_IMR2_7
#endif

#if defined(STM32F101x6 ) || defined(STM32F101xB ) || defined(STM32F101xE ) || defined(STM32F101xG ) ||\
    defined(STM32F102x6 ) || defined(STM32F102xB ) || defined(STM32F103x6 ) || defined(STM32F103xB ) ||\
    defined(STM32F103xE ) || defined(STM32F103xG ) || defined(STM32F105xC ) || defined(STM32F107xC ) ||\
    defined(STM32F2     ) || defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F373xC ) || defined(STM32F4     ) ||\
    defined(STM32F7     ) || defined(STM32L1     ) 
#define EXTI_FTSR_0_TR18     TR18                 // 1 bits @ 18
#define EXTI_PR_0_P18        P18                  // 1 bits @ 18
#define EXTI_RTSR_0_TR18     TR18                 // 1 bits @ 18
#define EXTI_SWIER_0_SWIE18  SWIE18               // 1 bits @ 18
#else
#define EXTI_FTSR_0_TR18
#define EXTI_PR_0_P18
#define EXTI_RTSR_0_TR18
#define EXTI_SWIER_0_SWIE18
#endif

#if defined(STM32F031x6 ) || defined(STM32F038xx ) || defined(STM32F042x6 ) || defined(STM32F048xx ) ||\
    defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F2     ) ||\
    defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) || defined(STM32F303xE ) ||\
    defined(STM32F358xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F398xx ) ||\
    defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L0     ) || defined(STM32L1     ) 
#define EXTI_FTSR_0_TR21     TR21                 // 1 bits @ 21
#define EXTI_PR_0_P21        P21                  // 1 bits @ 21
#define EXTI_RTSR_0_TR21     TR21                 // 1 bits @ 21
#define EXTI_SWIER_0_SWIE21  SWIE21               // 1 bits @ 21
#else
#define EXTI_FTSR_0_TR21
#define EXTI_PR_0_P21
#define EXTI_RTSR_0_TR21
#define EXTI_SWIER_0_SWIE21
#endif

#if defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) || defined(STM32F413xx ) ||\
    defined(STM32F423xx ) || defined(STM32F7     ) || defined(STM32L100xC ) || defined(STM32L151xC ) ||\
    defined(STM32L151xCA) || defined(STM32L151xD ) || defined(STM32L151xDx) || defined(STM32L151xE ) ||\
    defined(STM32L152xC ) || defined(STM32L152xCA) || defined(STM32L152xD ) || defined(STM32L152xDx) ||\
    defined(STM32L152xE ) || defined(STM32L162xC ) || defined(STM32L162xCA) || defined(STM32L162xD ) ||\
    defined(STM32L162xDx) || defined(STM32L162xE ) 
#define EXTI_FTSR_0_TR23     TR23                 // 1 bits @ 23
#define EXTI_PR_0_P23        P23                  // 1 bits @ 23
#define EXTI_RTSR_0_TR23     TR23                 // 1 bits @ 23
#define EXTI_SWIER_0_SWIE23  SWIE23               // 1 bits @ 23
#else
#define EXTI_FTSR_0_TR23
#define EXTI_PR_0_P23
#define EXTI_RTSR_0_TR23
#define EXTI_SWIER_0_SWIE23
#endif

#if defined(STM32F765xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) || defined(STM32F777xx ) ||\
    defined(STM32F779xx ) 
#define EXTI_FTSR_0_TR24     TR24                 // 1 bits @ 24
#define EXTI_IMR_9
#define EXTI_PR_0_P24        P24                  // 1 bits @ 24
#define EXTI_RTSR_0_TR24     TR24                 // 1 bits @ 24
#define EXTI_SWIER_0_SWIE24  SWIE24               // 1 bits @ 24
#else
#define EXTI_FTSR_0_TR24
#define EXTI_PR_0_P24
#define EXTI_RTSR_0_TR24
#define EXTI_SWIER_0_SWIE24
#endif

#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F3     ) || defined(STM32L0     ) ||\
    defined(STM32L1     ) 
#define EXTI_FTSR_1
#define EXTI_PR_1
#define EXTI_RTSR_1
#define EXTI_SWIER_1
#endif

#if defined(STM32F101x6 ) || defined(STM32F101xB ) || defined(STM32F101xE ) || defined(STM32F101xG ) ||\
    defined(STM32F102x6 ) || defined(STM32F102xB ) || defined(STM32F103x6 ) || defined(STM32F103xB ) ||\
    defined(STM32F103xE ) || defined(STM32F103xG ) || defined(STM32F105xC ) || defined(STM32F107xC ) ||\
    defined(STM32F3     ) || defined(STM32L1     ) 
#define EXTI_FTSR_1_FT18     FT18                 // 1 bits @ 18
#define EXTI_PR_1_PIF18      PIF18                // 1 bits @ 18
#define EXTI_RTSR_1_RT18     RT18                 // 1 bits @ 18
#define EXTI_SWIER_1_SWI18   SWI18                // 1 bits @ 18
#else
#define EXTI_FTSR_1_FT18
#define EXTI_PR_1_PIF18
#define EXTI_RTSR_1_RT18
#define EXTI_SWIER_1_SWI18
#endif

#if defined(STM32F0     ) || defined(STM32F105xC ) || defined(STM32F107xC ) || defined(STM32F3     ) ||\
    defined(STM32L0     ) || defined(STM32L1     ) 
#define EXTI_FTSR_1_FT19     FT19                 // 1 bits @ 19
#define EXTI_PR_1_PIF19      PIF19                // 1 bits @ 19
#define EXTI_RTSR_1_RT19     RT19                 // 1 bits @ 19
#define EXTI_SWIER_1_SWI19   SWI19                // 1 bits @ 19
#else
#define EXTI_FTSR_1_FT19
#define EXTI_PR_1_PIF19
#define EXTI_RTSR_1_RT19
#define EXTI_SWIER_1_SWI19
#endif

#if defined(STM32F030xC ) || defined(STM32F070xB ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F3     ) ||\
    defined(STM32L0     ) || defined(STM32L1     ) 
#define EXTI_FTSR_1_FT20     FT20                 // 1 bits @ 20
#define EXTI_PR_1_PIF20      PIF20                // 1 bits @ 20
#define EXTI_RTSR_1_RT20     RT20                 // 1 bits @ 20
#define EXTI_SWIER_1_SWI20   SWI20                // 1 bits @ 20
#else
#define EXTI_FTSR_1_FT20
#define EXTI_PR_1_PIF20
#define EXTI_RTSR_1_RT20
#define EXTI_SWIER_1_SWI20
#endif

#if defined(STM32F031x6 ) || defined(STM32F038xx ) || defined(STM32F042x6 ) || defined(STM32F048xx ) ||\
    defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F3     ) ||\
    defined(STM32L0     ) || defined(STM32L1     ) 
#define EXTI_FTSR_1_FT21     FT21                 // 1 bits @ 21
#define EXTI_FTSR_1_FT22     FT22                 // 1 bits @ 22
#define EXTI_PR_1_PIF21      PIF21                // 1 bits @ 21
#define EXTI_PR_1_PIF22      PIF22                // 1 bits @ 22
#define EXTI_RTSR_1_RT21     RT21                 // 1 bits @ 21
#define EXTI_RTSR_1_RT22     RT22                 // 1 bits @ 22
#define EXTI_SWIER_1_SWI21   SWI21                // 1 bits @ 21
#define EXTI_SWIER_1_SWI22   SWI22                // 1 bits @ 22
#else
#define EXTI_FTSR_1_FT21
#define EXTI_FTSR_1_FT22
#define EXTI_PR_1_PIF21
#define EXTI_PR_1_PIF22
#define EXTI_RTSR_1_RT21
#define EXTI_RTSR_1_RT22
#define EXTI_SWIER_1_SWI21
#define EXTI_SWIER_1_SWI22
#endif

#if defined(STM32L100xC ) || defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) ||\
    defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) ||\
    defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define EXTI_FTSR_1_FT23     FT23                 // 1 bits @ 23
#define EXTI_PR_1_PIF23      PIF23                // 1 bits @ 23
#define EXTI_RTSR_1_RT23     RT23                 // 1 bits @ 23
#define EXTI_SWIER_1_SWI23   SWI23                // 1 bits @ 23
#else
#define EXTI_FTSR_1_FT23
#define EXTI_PR_1_PIF23
#define EXTI_RTSR_1_RT23
#define EXTI_SWIER_1_SWI23
#endif

#if defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) || defined(STM32F328xx ) ||\
    defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) ||\
    defined(STM32F398xx ) 
#define EXTI_FTSR_1_FT29     FT29                 // 1 bits @ 29
#define EXTI_PR_1_PIF29      PIF29                // 1 bits @ 29
#define EXTI_RTSR_1_RT29     RT29                 // 1 bits @ 29
#define EXTI_SWIER_1_SWI29   SWI29                // 1 bits @ 29
#else
#define EXTI_FTSR_1_FT29
#define EXTI_PR_1_PIF29
#define EXTI_RTSR_1_RT29
#define EXTI_SWIER_1_SWI29
#endif

#if defined(STM32L432xx ) || defined(STM32L433xx ) || defined(STM32L442xx ) || defined(STM32L443xx ) ||\
    defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) ||\
    defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) ||\
    defined(STM32L4P    ) 
#define EXTI_FTSR2_0_FT35    FT35                 // 1 bits @ 3
#define EXTI_PR2_0_PIF35     PIF35                // 1 bits @ 3
#define EXTI_RTSR2_0_RT35    RT35                 // 1 bits @ 3
#define EXTI_SWIER2_0_SWI35  SWI35                // 1 bits @ 3
#else
#define EXTI_FTSR2_0_FT35
#define EXTI_PR2_0_PIF35
#define EXTI_RTSR2_0_RT35
#define EXTI_SWIER2_0_SWI35
#endif

#if defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define EXTI_FTSR2_0_FT36    FT36                 // 1 bits @ 4
#define EXTI_PR2_0_PIF36     PIF36                // 1 bits @ 4
#define EXTI_RTSR2_0_RT36    RT36                 // 1 bits @ 4
#define EXTI_SWIER2_0_SWI36  SWI36                // 1 bits @ 4
#else
#define EXTI_FTSR2_0_FT36
#define EXTI_PR2_0_PIF36
#define EXTI_RTSR2_0_RT36
#define EXTI_SWIER2_0_SWI36
#endif

#if defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) || defined(STM32F328xx ) ||\
    defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F398xx ) 
#define EXTI_FTSR2_1_FT33    FT33                 // 1 bits @ 1
#define EXTI_PR2_1_PIF33     PIF33                // 1 bits @ 1
#define EXTI_RTSR2_1_RT33    RT33                 // 1 bits @ 1
#define EXTI_SWIER2_1_SWI33  SWI33                // 1 bits @ 1
#else
#define EXTI_FTSR2_1_FT33
#define EXTI_PR2_1_PIF33
#define EXTI_RTSR2_1_RT33
#define EXTI_SWIER2_1_SWI33
#endif

#if defined(STM32F100xB ) || defined(STM32F100xE ) 
#define EXTI_IMR_2
#endif

#if defined(STM32F101x6 ) || defined(STM32F101xB ) || defined(STM32F101xE ) || defined(STM32F101xG ) ||\
    defined(STM32F102x6 ) || defined(STM32F102xB ) || defined(STM32F103x6 ) || defined(STM32F103xB ) ||\
    defined(STM32F103xE ) || defined(STM32F103xG ) 
#define EXTI_IMR_3
#endif

#if defined(STM32F105xC ) || defined(STM32F107xC ) 
#define EXTI_IMR_4
#endif

#if defined(STM32F2     ) || defined(STM32F401xC ) || defined(STM32F401xE ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F411xE ) || defined(STM32F412Cx ) || defined(STM32F412Rx ) ||\
    defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F415xx ) || defined(STM32F417xx ) ||\
    defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32L100xB ) ||\
    defined(STM32L100xBA) || defined(STM32L151xB ) || defined(STM32L151xBA) || defined(STM32L152xB ) ||\
    defined(STM32L152xBA) 
#define EXTI_IMR_5
#endif

#if defined(STM32F373xC ) || defined(STM32F378xx ) 
#define EXTI_IMR_7
#endif

#if defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) || defined(STM32F413xx ) ||\
    defined(STM32F423xx ) || defined(STM32F722xx ) || defined(STM32F723xx ) || defined(STM32F732xx ) ||\
    defined(STM32F733xx ) || defined(STM32F745xx ) || defined(STM32F746xx ) || defined(STM32F756xx ) ||\
    defined(STM32L100xC ) || defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) ||\
    defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) ||\
    defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define EXTI_IMR_8
#endif

#if defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) 
#define EXTI_IMR1_1
#endif

#define EXTI_Core_EMR1
#define EXTI_Core_EMR2
#define EXTI_Core_EMR3
#define EXTI_Core_IMR1
#define EXTI_Core_IMR2
#define EXTI_Core_IMR3
#define EXTI_Core_PR1
#define EXTI_Core_PR2
#define EXTI_Core_PR3

//endregion

namespace sool
{
	namespace core
	{
		class EXTI
		{
			//SOOL-EXTI-ENUMS
			
			public :
			
			#ifdef EXTI_D3PMR1
			struct D3PMR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MR0                  :1;
					uint32_t MR1                  :1;
					uint32_t MR2                  :1;
					uint32_t MR3                  :1;
					uint32_t MR4                  :1;
					uint32_t MR5                  :1;
					uint32_t MR6                  :1;
					uint32_t MR7                  :1;
					uint32_t MR8                  :1;
					uint32_t MR9                  :1;
					uint32_t MR10                 :1;
					uint32_t MR11                 :1;
					uint32_t MR12                 :1;
					uint32_t MR13                 :1;
					uint32_t MR14                 :1;
					uint32_t MR15                 :1;
					uint32_t                      :3;
					uint32_t MR19                 :1;
					uint32_t MR20                 :1;
					uint32_t MR21                 :1;
					uint32_t                      :2;
					uint32_t MR25                 :1;
					uint32_t                      :7;
			
				//SOOL-EXTI_D3PMR1-DECLARATION
			};
			#endif
			
			#ifdef EXTI_D3PMR2
			struct D3PMR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :2;
					uint32_t MR34                 :1;
					uint32_t MR35                 :1;
					uint32_t                      :5;
					uint32_t MR41                 :1;
					uint32_t                      :6;
					uint32_t MR48                 :1;
					uint32_t MR49                 :1;
					uint32_t MR50                 :1;
					uint32_t MR51                 :1;
					uint32_t MR52                 :1;
					uint32_t MR53                 :1;
					uint32_t                      :10;
			
				//SOOL-EXTI_D3PMR2-DECLARATION
			};
			#endif
			
			#ifdef EXTI_D3PMR3
			struct D3PMR3_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :24;
					uint32_t MR88                 :1;
					uint32_t                      :7;
			
				//SOOL-EXTI_D3PMR3-DECLARATION
			};
			#endif
			
			#ifdef EXTI_EMR
			struct EMR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t MR0                  :1;
						uint32_t MR1                  :1;
						uint32_t MR2                  :1;
						uint32_t MR3                  :1;
						uint32_t MR4                  :1;
						uint32_t MR5                  :1;
						uint32_t MR6                  :1;
						uint32_t MR7                  :1;
						uint32_t MR8                  :1;
						uint32_t MR9                  :1;
						uint32_t MR10                 :1;
						uint32_t MR11                 :1;
						uint32_t MR12                 :1;
						uint32_t MR13                 :1;
						uint32_t MR14                 :1;
						uint32_t MR15                 :1;
						uint32_t EXTI_EMR_0_MR16      :1;
						uint32_t MR17                 :1;
						uint32_t EXTI_EMR_0_MR18      :1;
						uint32_t EXTI_EMR_0_MR19      :1;
						uint32_t EXTI_EMR_0_MR20      :1;
						uint32_t EXTI_EMR_0_MR21      :1;
						uint32_t EXTI_EMR_0_MR22      :1;
						uint32_t EXTI_EMR_0_MR23      :1;
						uint32_t EXTI_EMR_0_MR24      :1;
						uint32_t EXTI_EMR_0_MR25      :1;
						uint32_t EXTI_EMR_0_MR26      :1;
						uint32_t EXTI_EMR_0_MR27      :1;
						uint32_t EXTI_EMR_0_MR28      :1;
						uint32_t EXTI_EMR_0_MR29      :1;
						uint32_t EXTI_EMR_0_MR30      :1;
						uint32_t EXTI_EMR_0_MR31      :1;
					};
					#ifdef EXTI_EMR_1
					struct
					{
						uint32_t EM0                  :1;
						uint32_t EM1                  :1;
						uint32_t EM2                  :1;
						uint32_t EM3                  :1;
						uint32_t EM4                  :1;
						uint32_t EM5                  :1;
						uint32_t EM6                  :1;
						uint32_t EM7                  :1;
						uint32_t EM8                  :1;
						uint32_t EM9                  :1;
						uint32_t EM10                 :1;
						uint32_t EM11                 :1;
						uint32_t EM12                 :1;
						uint32_t EM13                 :1;
						uint32_t EM14                 :1;
						uint32_t EM15                 :1;
						uint32_t EXTI_EMR_1_EM16      :1;
						uint32_t EM17                 :1;
						uint32_t EXTI_EMR_1_EM18      :1;
						uint32_t EXTI_EMR_1_EM19      :1;
						uint32_t EXTI_EMR_1_EM20      :1;
						uint32_t EXTI_EMR_1_EM21      :1;
						uint32_t EXTI_EMR_1_EM22      :1;
						uint32_t EXTI_EMR_1_EM23      :1;
						uint32_t EXTI_EMR_1_EM24      :1;
						uint32_t EXTI_EMR_1_EM25      :1;
						uint32_t EXTI_EMR_1_EM26      :1;
						uint32_t EXTI_EMR_1_EM27      :1;
						uint32_t EXTI_EMR_1_EM28      :1;
						uint32_t EXTI_EMR_1_EM29      :1;
						uint32_t EXTI_EMR_1_EM30      :1;
						uint32_t EXTI_EMR_1_EM31      :1;
					};
					#endif
				};
				//SOOL-EXTI_EMR-DECLARATION
			};
			#endif
			
			#ifdef EXTI_EMR1
			struct EMR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EM0                  :1;
					uint32_t EM1                  :1;
					uint32_t EM2                  :1;
					uint32_t EM3                  :1;
					uint32_t EM4                  :1;
					uint32_t EM5                  :1;
					uint32_t EM6                  :1;
					uint32_t EM7                  :1;
					uint32_t EM8                  :1;
					uint32_t EM9                  :1;
					uint32_t EM10                 :1;
					uint32_t EM11                 :1;
					uint32_t EM12                 :1;
					uint32_t EM13                 :1;
					uint32_t EM14                 :1;
					uint32_t EM15                 :1;
					uint32_t EM16                 :1;
					uint32_t EM17                 :1;
					uint32_t EM18                 :1;
					uint32_t EXTI_EMR1_EM19       :1;
					uint32_t EM20                 :1;
					uint32_t EM21                 :1;
					uint32_t EM22                 :1;
					uint32_t EM23                 :1;
					uint32_t EM24                 :1;
					uint32_t EM25                 :1;
					uint32_t EM26                 :1;
					uint32_t EM27                 :1;
					uint32_t EM28                 :1;
					uint32_t EXTI_EMR1_EM29       :1;
					uint32_t EXTI_EMR1_EM30       :1;
					uint32_t EM31                 :1;
			
				//SOOL-EXTI_EMR1-DECLARATION
			};
			#endif
			
			#ifdef EXTI_EMR2
			struct EMR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef EXTI_EMR2_0
					struct
					{
						uint32_t EXTI_EMR2_0_MR32     :1;
						uint32_t EXTI_EMR2_0_MR33     :1;
						uint32_t EXTI_EMR2_0_MR34     :1;
						uint32_t EXTI_EMR2_0_MR35     :1;
						uint32_t EXTI_EMR2_0_EM36     :1;
						uint32_t EXTI_EMR2_0_EM37     :1;
						uint32_t EXTI_EMR2_0_EM38     :1;
						uint32_t EXTI_EMR2_0_EM39     :1;
						uint32_t EXTI_EMR2_0_EM40     :1;
						uint32_t EXTI_EMR2_0_EM41     :1;
						uint32_t EXTI_EMR2_0_EM42     :1;
						uint32_t EXTI_EMR2_0_EM43     :1;
						uint32_t EXTI_EMR2_0_EM44     :1;
						uint32_t EXTI_EMR2_0_EM45     :1;
						uint32_t EXTI_EMR2_0_EM46     :1;
						uint32_t EXTI_EMR2_0_EM47     :1;
						uint32_t EXTI_EMR2_0_EM48     :1;
						uint32_t EXTI_EMR2_0_EM49     :1;
						uint32_t EXTI_EMR2_0_EM50     :1;
						uint32_t EXTI_EMR2_0_EM51     :1;
						uint32_t EXTI_EMR2_0_EM52     :1;
						uint32_t EXTI_EMR2_0_EM53     :1;
						uint32_t EXTI_EMR2_0_EM54     :1;
						uint32_t EXTI_EMR2_0_EM55     :1;
						uint32_t EXTI_EMR2_0_EM56     :1;
						uint32_t EXTI_EMR2_0_EM57     :1;
						uint32_t EXTI_EMR2_0_EM58     :1;
						uint32_t EXTI_EMR2_0_EM59     :1;
						uint32_t EXTI_EMR2_0_EM60     :1;
						uint32_t EXTI_EMR2_0_EM61     :1;
						uint32_t EXTI_EMR2_0_EM62     :1;
						uint32_t EXTI_EMR2_0_EM63     :1;
					};
					#endif
					#ifdef EXTI_EMR2_1
					struct
					{
						uint32_t EM32                 :1;
						uint32_t EXTI_EMR2_1_EM33     :1;
						uint32_t EXTI_EMR2_1_EM34     :1;
						uint32_t EXTI_EMR2_1_EM35     :1;
						uint32_t                      :28;
					};
					#endif
					#ifdef EXTI_EMR2_2
					struct
					{
						uint32_t EM                   :4;
						uint32_t                      :28;
					};
					#endif
					#ifdef EXTI_EMR2_3
					struct
					{
						uint32_t EM                   :1;
						uint32_t                      :31;
					};
					#endif
					#ifdef EXTI_EMR2_4
					struct
					{
						uint32_t EM                   :6;
						uint32_t                      :26;
					};
					#endif
					#ifdef EXTI_EMR2_5
					struct
					{
						uint32_t EM                   :7;
						uint32_t                      :25;
					};
					#endif
					#ifdef EXTI_EMR2_6
					struct
					{
						uint32_t EM                   :8;
						uint32_t                      :24;
					};
					#endif
					#ifdef EXTI_EMR2_7
					struct
					{
						uint32_t EM                   :9;
						uint32_t                      :23;
					};
					#endif
				};
				//SOOL-EXTI_EMR2-DECLARATION
			};
			#endif
			
			#ifdef EXTI_FTSR
			struct FTSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef EXTI_FTSR_0
					struct
					{
						uint32_t TR0                  :1;
						uint32_t TR1                  :1;
						uint32_t TR2                  :1;
						uint32_t TR3                  :1;
						uint32_t TR4                  :1;
						uint32_t TR5                  :1;
						uint32_t TR6                  :1;
						uint32_t TR7                  :1;
						uint32_t TR8                  :1;
						uint32_t TR9                  :1;
						uint32_t TR10                 :1;
						uint32_t TR11                 :1;
						uint32_t TR12                 :1;
						uint32_t TR13                 :1;
						uint32_t TR14                 :1;
						uint32_t TR15                 :1;
						uint32_t TR16                 :1;
						uint32_t TR17                 :1;
						uint32_t EXTI_FTSR_0_TR18     :1;
						uint32_t EXTI_FTSR_0_TR19     :1;
						uint32_t EXTI_FTSR_0_TR20     :1;
						uint32_t EXTI_FTSR_0_TR21     :1;
						uint32_t EXTI_FTSR_0_TR22     :1;
						uint32_t EXTI_FTSR_0_TR23     :1;
						uint32_t EXTI_FTSR_0_TR24     :1;
						uint32_t                      :4;
						uint32_t EXTI_FTSR_0_TR29     :1;
						uint32_t EXTI_FTSR_0_TR30     :1;
						uint32_t EXTI_FTSR_0_TR31     :1;
					};
					#endif
					#ifdef EXTI_FTSR_1
					struct
					{
						uint32_t FT0                  :1;
						uint32_t FT1                  :1;
						uint32_t FT2                  :1;
						uint32_t FT3                  :1;
						uint32_t FT4                  :1;
						uint32_t FT5                  :1;
						uint32_t FT6                  :1;
						uint32_t FT7                  :1;
						uint32_t FT8                  :1;
						uint32_t FT9                  :1;
						uint32_t FT10                 :1;
						uint32_t FT11                 :1;
						uint32_t FT12                 :1;
						uint32_t FT13                 :1;
						uint32_t FT14                 :1;
						uint32_t FT15                 :1;
						uint32_t FT16                 :1;
						uint32_t FT17                 :1;
						uint32_t EXTI_FTSR_1_FT18     :1;
						uint32_t EXTI_FTSR_1_FT19     :1;
						uint32_t EXTI_FTSR_1_FT20     :1;
						uint32_t EXTI_FTSR_1_FT21     :1;
						uint32_t EXTI_FTSR_1_FT22     :1;
						uint32_t EXTI_FTSR_1_FT23     :1;
						uint32_t                      :5;
						uint32_t EXTI_FTSR_1_FT29     :1;
						uint32_t EXTI_FTSR_1_FT30     :1;
						uint32_t EXTI_FTSR_1_FT31     :1;
					};
					#endif
				};
				//SOOL-EXTI_FTSR-DECLARATION
			};
			#endif
			
			#ifdef EXTI_FTSR1
			struct FTSR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t EXTI_FTSR1_0_TR0     :1;
						uint32_t EXTI_FTSR1_0_TR1     :1;
						uint32_t EXTI_FTSR1_0_TR2     :1;
						uint32_t EXTI_FTSR1_0_TR3     :1;
						uint32_t EXTI_FTSR1_0_TR4     :1;
						uint32_t EXTI_FTSR1_0_TR5     :1;
						uint32_t EXTI_FTSR1_0_TR6     :1;
						uint32_t EXTI_FTSR1_0_TR7     :1;
						uint32_t EXTI_FTSR1_0_TR8     :1;
						uint32_t EXTI_FTSR1_0_TR9     :1;
						uint32_t EXTI_FTSR1_0_TR10    :1;
						uint32_t EXTI_FTSR1_0_TR11    :1;
						uint32_t EXTI_FTSR1_0_TR12    :1;
						uint32_t EXTI_FTSR1_0_TR13    :1;
						uint32_t EXTI_FTSR1_0_TR14    :1;
						uint32_t EXTI_FTSR1_0_TR15    :1;
						uint32_t EXTI_FTSR1_0_TR16    :1;
						uint32_t EXTI_FTSR1_0_TR17    :1;
						uint32_t EXTI_FTSR1_0_TR18    :1;
						uint32_t EXTI_FTSR1_0_TR19    :1;
						uint32_t EXTI_FTSR1_0_TR20    :1;
						uint32_t EXTI_FTSR1_0_TR21    :1;
						uint32_t EXTI_FTSR1_0_FT22    :1;
						uint32_t                      :9;
					};
					#ifdef EXTI_FTSR1_1
					struct
					{
						uint32_t FT0                  :1;
						uint32_t FT1                  :1;
						uint32_t FT2                  :1;
						uint32_t FT3                  :1;
						uint32_t FT4                  :1;
						uint32_t FT5                  :1;
						uint32_t FT6                  :1;
						uint32_t FT7                  :1;
						uint32_t FT8                  :1;
						uint32_t FT9                  :1;
						uint32_t FT10                 :1;
						uint32_t FT11                 :1;
						uint32_t FT12                 :1;
						uint32_t FT13                 :1;
						uint32_t FT14                 :1;
						uint32_t FT15                 :1;
						uint32_t FT16                 :1;
						uint32_t                      :1;
						uint32_t FT18                 :1;
						uint32_t FT19                 :1;
						uint32_t FT20                 :1;
						uint32_t FT21                 :1;
						uint32_t                      :10;
					};
					#endif
				};
				//SOOL-EXTI_FTSR1-DECLARATION
			};
			#endif
			
			#ifdef EXTI_FTSR2
			struct FTSR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t EXTI_FTSR2_0_TR32    :1;
						uint32_t EXTI_FTSR2_0_TR33    :1;
						uint32_t                      :1;
						uint32_t EXTI_FTSR2_0_FT35    :1;
						uint32_t EXTI_FTSR2_0_FT36    :1;
						uint32_t EXTI_FTSR2_0_FT37    :1;
						uint32_t EXTI_FTSR2_0_FT38    :1;
						uint32_t                      :10;
						uint32_t EXTI_FTSR2_0_TR49    :1;
						uint32_t                      :1;
						uint32_t EXTI_FTSR2_0_TR51    :1;
						uint32_t                      :12;
					};
					#ifdef EXTI_FTSR2_1
					struct
					{
						uint32_t FT32                 :1;
						uint32_t EXTI_FTSR2_1_FT33    :1;
						uint32_t                      :30;
					};
					#endif
				};
				//SOOL-EXTI_FTSR2-DECLARATION
			};
			#endif
			
			#ifdef EXTI_FTSR3
			struct FTSR3_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :18;
					uint32_t TR82                 :1;
					uint32_t                      :1;
					uint32_t TR84                 :1;
					uint32_t TR85                 :1;
					uint32_t TR86                 :1;
					uint32_t                      :9;
			
				//SOOL-EXTI_FTSR3-DECLARATION
			};
			#endif
			
			#ifdef EXTI_IMR
			struct IMR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t MR0                  :1;
						uint32_t MR1                  :1;
						uint32_t MR2                  :1;
						uint32_t MR3                  :1;
						uint32_t MR4                  :1;
						uint32_t MR5                  :1;
						uint32_t MR6                  :1;
						uint32_t MR7                  :1;
						uint32_t MR8                  :1;
						uint32_t MR9                  :1;
						uint32_t MR10                 :1;
						uint32_t MR11                 :1;
						uint32_t MR12                 :1;
						uint32_t MR13                 :1;
						uint32_t MR14                 :1;
						uint32_t MR15                 :1;
						uint32_t EXTI_IMR_0_MR16      :1;
						uint32_t MR17                 :1;
						uint32_t EXTI_IMR_0_MR18      :1;
						uint32_t EXTI_IMR_0_MR19      :1;
						uint32_t EXTI_IMR_0_MR20      :1;
						uint32_t EXTI_IMR_0_MR21      :1;
						uint32_t EXTI_IMR_0_MR22      :1;
						uint32_t EXTI_IMR_0_MR23      :1;
						uint32_t EXTI_IMR_0_MR24      :1;
						uint32_t EXTI_IMR_0_MR25      :1;
						uint32_t EXTI_IMR_0_MR26      :1;
						uint32_t EXTI_IMR_0_MR27      :1;
						uint32_t EXTI_IMR_0_MR28      :1;
						uint32_t EXTI_IMR_0_MR29      :1;
						uint32_t EXTI_IMR_0_MR30      :1;
						uint32_t EXTI_IMR_0_MR31      :1;
					};
					#ifdef EXTI_IMR_1
					struct
					{
						uint32_t IM0                  :1;
						uint32_t IM1                  :1;
						uint32_t IM2                  :1;
						uint32_t IM3                  :1;
						uint32_t IM4                  :1;
						uint32_t IM5                  :1;
						uint32_t IM6                  :1;
						uint32_t IM7                  :1;
						uint32_t IM8                  :1;
						uint32_t IM9                  :1;
						uint32_t IM10                 :1;
						uint32_t IM11                 :1;
						uint32_t IM12                 :1;
						uint32_t IM13                 :1;
						uint32_t IM14                 :1;
						uint32_t IM15                 :1;
						uint32_t EXTI_IMR_1_IM16      :1;
						uint32_t IM17                 :1;
						uint32_t EXTI_IMR_1_IM18      :1;
						uint32_t EXTI_IMR_1_IM19      :1;
						uint32_t EXTI_IMR_1_IM20      :1;
						uint32_t EXTI_IMR_1_IM21      :1;
						uint32_t EXTI_IMR_1_IM22      :1;
						uint32_t EXTI_IMR_1_IM23      :1;
						uint32_t EXTI_IMR_1_IM24      :1;
						uint32_t EXTI_IMR_1_IM25      :1;
						uint32_t EXTI_IMR_1_IM26      :1;
						uint32_t EXTI_IMR_1_IM27      :1;
						uint32_t EXTI_IMR_1_IM28      :1;
						uint32_t EXTI_IMR_1_IM29      :1;
						uint32_t EXTI_IMR_1_IM30      :1;
						uint32_t EXTI_IMR_1_IM31      :1;
					};
					#endif
					#ifdef EXTI_IMR_2
					struct
					{
						uint32_t IM                   :18;
						uint32_t                      :14;
					};
					#endif
					#ifdef EXTI_IMR_3
					struct
					{
						uint32_t IM                   :19;
						uint32_t                      :13;
					};
					#endif
					#ifdef EXTI_IMR_4
					struct
					{
						uint32_t IM                   :20;
						uint32_t                      :12;
					};
					#endif
					#ifdef EXTI_IMR_5
					struct
					{
						uint32_t IM                   :23;
						uint32_t                      :9;
					};
					#endif
					#ifdef EXTI_IMR_6
					struct
					{
						uint32_t IM                   :32;
					};
					#endif
					#ifdef EXTI_IMR_7
					struct
					{
						uint32_t IM                   :29;
						uint32_t                      :3;
					};
					#endif
					#ifdef EXTI_IMR_8
					struct
					{
						uint32_t IM                   :24;
						uint32_t                      :8;
					};
					#endif
					#ifdef EXTI_IMR_9
					struct
					{
						uint32_t IM                   :25;
						uint32_t                      :7;
					};
					#endif
				};
				//SOOL-EXTI_IMR-DECLARATION
			};
			#endif
			
			#ifdef EXTI_IMR1
			struct IMR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef EXTI_IMR1_0
					struct
					{
						uint32_t IM0                  :1;
						uint32_t IM1                  :1;
						uint32_t IM2                  :1;
						uint32_t IM3                  :1;
						uint32_t IM4                  :1;
						uint32_t IM5                  :1;
						uint32_t IM6                  :1;
						uint32_t IM7                  :1;
						uint32_t IM8                  :1;
						uint32_t IM9                  :1;
						uint32_t IM10                 :1;
						uint32_t IM11                 :1;
						uint32_t IM12                 :1;
						uint32_t IM13                 :1;
						uint32_t IM14                 :1;
						uint32_t IM15                 :1;
						uint32_t IM16                 :1;
						uint32_t IM17                 :1;
						uint32_t IM18                 :1;
						uint32_t IM19                 :1;
						uint32_t IM20                 :1;
						uint32_t IM21                 :1;
						uint32_t IM22                 :1;
						uint32_t IM23                 :1;
						uint32_t IM24                 :1;
						uint32_t IM25                 :1;
						uint32_t IM26                 :1;
						uint32_t IM27                 :1;
						uint32_t IM28                 :1;
						uint32_t EXTI_IMR1_0_IM29     :1;
						uint32_t EXTI_IMR1_0_IM30     :1;
						uint32_t IM31                 :1;
					};
					#endif
					#ifdef EXTI_IMR1_1
					struct
					{
						uint32_t IM                   :32;
					};
					#endif
				};
				//SOOL-EXTI_IMR1-DECLARATION
			};
			#endif
			
			#ifdef EXTI_IMR2
			struct IMR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef EXTI_IMR2_0
					struct
					{
						uint32_t EXTI_IMR2_0_MR32     :1;
						uint32_t EXTI_IMR2_0_MR33     :1;
						uint32_t EXTI_IMR2_0_MR34     :1;
						uint32_t EXTI_IMR2_0_MR35     :1;
						uint32_t EXTI_IMR2_0_IM36     :1;
						uint32_t EXTI_IMR2_0_IM37     :1;
						uint32_t EXTI_IMR2_0_IM38     :1;
						uint32_t EXTI_IMR2_0_IM39     :1;
						uint32_t EXTI_IMR2_0_IM40     :1;
						uint32_t EXTI_IMR2_0_IM41     :1;
						uint32_t EXTI_IMR2_0_IM42     :1;
						uint32_t EXTI_IMR2_0_IM43     :1;
						uint32_t EXTI_IMR2_0_IM44     :1;
						uint32_t EXTI_IMR2_0_IM45     :1;
						uint32_t EXTI_IMR2_0_IM46     :1;
						uint32_t EXTI_IMR2_0_IM47     :1;
						uint32_t EXTI_IMR2_0_IM48     :1;
						uint32_t EXTI_IMR2_0_IM49     :1;
						uint32_t EXTI_IMR2_0_IM50     :1;
						uint32_t EXTI_IMR2_0_IM51     :1;
						uint32_t EXTI_IMR2_0_IM52     :1;
						uint32_t EXTI_IMR2_0_IM53     :1;
						uint32_t EXTI_IMR2_0_IM54     :1;
						uint32_t EXTI_IMR2_0_IM55     :1;
						uint32_t EXTI_IMR2_0_IM56     :1;
						uint32_t EXTI_IMR2_0_IM57     :1;
						uint32_t EXTI_IMR2_0_IM58     :1;
						uint32_t EXTI_IMR2_0_IM59     :1;
						uint32_t EXTI_IMR2_0_IM60     :1;
						uint32_t EXTI_IMR2_0_IM61     :1;
						uint32_t EXTI_IMR2_0_IM62     :1;
						uint32_t EXTI_IMR2_0_IM63     :1;
					};
					#endif
					#ifdef EXTI_IMR2_1
					struct
					{
						uint32_t IM32                 :1;
						uint32_t EXTI_IMR2_1_IM33     :1;
						uint32_t EXTI_IMR2_1_IM34     :1;
						uint32_t EXTI_IMR2_1_IM35     :1;
						uint32_t                      :28;
					};
					#endif
					#ifdef EXTI_IMR2_2
					struct
					{
						uint32_t IM                   :4;
						uint32_t                      :28;
					};
					#endif
					#ifdef EXTI_IMR2_3
					struct
					{
						uint32_t IM                   :1;
						uint32_t                      :31;
					};
					#endif
					#ifdef EXTI_IMR2_4
					struct
					{
						uint32_t IM                   :6;
						uint32_t                      :26;
					};
					#endif
					#ifdef EXTI_IMR2_5
					struct
					{
						uint32_t IM                   :7;
						uint32_t                      :25;
					};
					#endif
					#ifdef EXTI_IMR2_6
					struct
					{
						uint32_t IM                   :8;
						uint32_t                      :24;
					};
					#endif
					#ifdef EXTI_IMR2_7
					struct
					{
						uint32_t IM                   :9;
						uint32_t                      :23;
					};
					#endif
				};
				//SOOL-EXTI_IMR2-DECLARATION
			};
			#endif
			
			#ifdef EXTI_PR
			struct PR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef EXTI_PR_0
					struct
					{
						uint32_t P0                   :1;
						uint32_t P1                   :1;
						uint32_t P2                   :1;
						uint32_t P3                   :1;
						uint32_t P4                   :1;
						uint32_t P5                   :1;
						uint32_t P6                   :1;
						uint32_t P7                   :1;
						uint32_t P8                   :1;
						uint32_t P9                   :1;
						uint32_t P10                  :1;
						uint32_t P11                  :1;
						uint32_t P12                  :1;
						uint32_t P13                  :1;
						uint32_t P14                  :1;
						uint32_t P15                  :1;
						uint32_t P16                  :1;
						uint32_t P17                  :1;
						uint32_t EXTI_PR_0_P18        :1;
						uint32_t EXTI_PR_0_P19        :1;
						uint32_t EXTI_PR_0_P20        :1;
						uint32_t EXTI_PR_0_P21        :1;
						uint32_t EXTI_PR_0_P22        :1;
						uint32_t EXTI_PR_0_P23        :1;
						uint32_t EXTI_PR_0_P24        :1;
						uint32_t                      :4;
						uint32_t EXTI_PR_0_P29        :1;
						uint32_t EXTI_PR_0_P30        :1;
						uint32_t EXTI_PR_0_P31        :1;
					};
					#endif
					#ifdef EXTI_PR_1
					struct
					{
						uint32_t PIF0                 :1;
						uint32_t PIF1                 :1;
						uint32_t PIF2                 :1;
						uint32_t PIF3                 :1;
						uint32_t PIF4                 :1;
						uint32_t PIF5                 :1;
						uint32_t PIF6                 :1;
						uint32_t PIF7                 :1;
						uint32_t PIF8                 :1;
						uint32_t PIF9                 :1;
						uint32_t PIF10                :1;
						uint32_t PIF11                :1;
						uint32_t PIF12                :1;
						uint32_t PIF13                :1;
						uint32_t PIF14                :1;
						uint32_t PIF15                :1;
						uint32_t PIF16                :1;
						uint32_t PIF17                :1;
						uint32_t EXTI_PR_1_PIF18      :1;
						uint32_t EXTI_PR_1_PIF19      :1;
						uint32_t EXTI_PR_1_PIF20      :1;
						uint32_t EXTI_PR_1_PIF21      :1;
						uint32_t EXTI_PR_1_PIF22      :1;
						uint32_t EXTI_PR_1_PIF23      :1;
						uint32_t                      :5;
						uint32_t EXTI_PR_1_PIF29      :1;
						uint32_t EXTI_PR_1_PIF30      :1;
						uint32_t EXTI_PR_1_PIF31      :1;
					};
					#endif
				};
				//SOOL-EXTI_PR-DECLARATION
			};
			#endif
			
			#ifdef EXTI_PR1
			struct PR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef EXTI_PR1_0
					struct
					{
						uint32_t EXTI_PR1_0_PR0       :1;
						uint32_t EXTI_PR1_0_PR1       :1;
						uint32_t EXTI_PR1_0_PR2       :1;
						uint32_t EXTI_PR1_0_PR3       :1;
						uint32_t EXTI_PR1_0_PR4       :1;
						uint32_t EXTI_PR1_0_PR5       :1;
						uint32_t EXTI_PR1_0_PR6       :1;
						uint32_t EXTI_PR1_0_PR7       :1;
						uint32_t EXTI_PR1_0_PR8       :1;
						uint32_t EXTI_PR1_0_PR9       :1;
						uint32_t EXTI_PR1_0_PR10      :1;
						uint32_t EXTI_PR1_0_PR11      :1;
						uint32_t EXTI_PR1_0_PR12      :1;
						uint32_t EXTI_PR1_0_PR13      :1;
						uint32_t EXTI_PR1_0_PR14      :1;
						uint32_t EXTI_PR1_0_PR15      :1;
						uint32_t EXTI_PR1_0_PR16      :1;
						uint32_t EXTI_PR1_0_PR17      :1;
						uint32_t EXTI_PR1_0_PR18      :1;
						uint32_t EXTI_PR1_0_PR19      :1;
						uint32_t EXTI_PR1_0_PR20      :1;
						uint32_t EXTI_PR1_0_PR21      :1;
						uint32_t EXTI_PR1_0_PIF22     :1;
						uint32_t                      :9;
					};
					#endif
					struct
					{
						uint32_t PIF0                 :1;
						uint32_t PIF1                 :1;
						uint32_t PIF2                 :1;
						uint32_t PIF3                 :1;
						uint32_t PIF4                 :1;
						uint32_t PIF5                 :1;
						uint32_t PIF6                 :1;
						uint32_t PIF7                 :1;
						uint32_t PIF8                 :1;
						uint32_t PIF9                 :1;
						uint32_t PIF10                :1;
						uint32_t PIF11                :1;
						uint32_t PIF12                :1;
						uint32_t PIF13                :1;
						uint32_t PIF14                :1;
						uint32_t PIF15                :1;
						uint32_t PIF16                :1;
						uint32_t                      :1;
						uint32_t PIF18                :1;
						uint32_t PIF19                :1;
						uint32_t PIF20                :1;
						uint32_t PIF21                :1;
						uint32_t                      :10;
					};
				};
				//SOOL-EXTI_PR1-DECLARATION
			};
			#endif
			
			#ifdef EXTI_PR2
			struct PR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef EXTI_PR2_0
					struct
					{
						uint32_t EXTI_PR2_0_PR32      :1;
						uint32_t EXTI_PR2_0_PR33      :1;
						uint32_t                      :1;
						uint32_t EXTI_PR2_0_PIF35     :1;
						uint32_t EXTI_PR2_0_PIF36     :1;
						uint32_t EXTI_PR2_0_PIF37     :1;
						uint32_t EXTI_PR2_0_PIF38     :1;
						uint32_t                      :10;
						uint32_t EXTI_PR2_0_PR49      :1;
						uint32_t                      :1;
						uint32_t EXTI_PR2_0_PR51      :1;
						uint32_t                      :12;
					};
					#endif
					#ifdef EXTI_PR2_1
					struct
					{
						uint32_t PIF32                :1;
						uint32_t EXTI_PR2_1_PIF33     :1;
						uint32_t                      :30;
					};
					#endif
				};
				//SOOL-EXTI_PR2-DECLARATION
			};
			#endif
			
			#ifdef EXTI_RTSR
			struct RTSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef EXTI_RTSR_0
					struct
					{
						uint32_t TR0                  :1;
						uint32_t TR1                  :1;
						uint32_t TR2                  :1;
						uint32_t TR3                  :1;
						uint32_t TR4                  :1;
						uint32_t TR5                  :1;
						uint32_t TR6                  :1;
						uint32_t TR7                  :1;
						uint32_t TR8                  :1;
						uint32_t TR9                  :1;
						uint32_t TR10                 :1;
						uint32_t TR11                 :1;
						uint32_t TR12                 :1;
						uint32_t TR13                 :1;
						uint32_t TR14                 :1;
						uint32_t TR15                 :1;
						uint32_t TR16                 :1;
						uint32_t TR17                 :1;
						uint32_t EXTI_RTSR_0_TR18     :1;
						uint32_t EXTI_RTSR_0_TR19     :1;
						uint32_t EXTI_RTSR_0_TR20     :1;
						uint32_t EXTI_RTSR_0_TR21     :1;
						uint32_t EXTI_RTSR_0_TR22     :1;
						uint32_t EXTI_RTSR_0_TR23     :1;
						uint32_t EXTI_RTSR_0_TR24     :1;
						uint32_t                      :4;
						uint32_t EXTI_RTSR_0_TR29     :1;
						uint32_t EXTI_RTSR_0_TR30     :1;
						uint32_t EXTI_RTSR_0_TR31     :1;
					};
					#endif
					#ifdef EXTI_RTSR_1
					struct
					{
						uint32_t RT0                  :1;
						uint32_t RT1                  :1;
						uint32_t RT2                  :1;
						uint32_t RT3                  :1;
						uint32_t RT4                  :1;
						uint32_t RT5                  :1;
						uint32_t RT6                  :1;
						uint32_t RT7                  :1;
						uint32_t RT8                  :1;
						uint32_t RT9                  :1;
						uint32_t RT10                 :1;
						uint32_t RT11                 :1;
						uint32_t RT12                 :1;
						uint32_t RT13                 :1;
						uint32_t RT14                 :1;
						uint32_t RT15                 :1;
						uint32_t RT16                 :1;
						uint32_t RT17                 :1;
						uint32_t EXTI_RTSR_1_RT18     :1;
						uint32_t EXTI_RTSR_1_RT19     :1;
						uint32_t EXTI_RTSR_1_RT20     :1;
						uint32_t EXTI_RTSR_1_RT21     :1;
						uint32_t EXTI_RTSR_1_RT22     :1;
						uint32_t EXTI_RTSR_1_RT23     :1;
						uint32_t                      :5;
						uint32_t EXTI_RTSR_1_RT29     :1;
						uint32_t EXTI_RTSR_1_RT30     :1;
						uint32_t EXTI_RTSR_1_RT31     :1;
					};
					#endif
				};
				//SOOL-EXTI_RTSR-DECLARATION
			};
			#endif
			
			#ifdef EXTI_RTSR1
			struct RTSR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t EXTI_RTSR1_0_TR0     :1;
						uint32_t EXTI_RTSR1_0_TR1     :1;
						uint32_t EXTI_RTSR1_0_TR2     :1;
						uint32_t EXTI_RTSR1_0_TR3     :1;
						uint32_t EXTI_RTSR1_0_TR4     :1;
						uint32_t EXTI_RTSR1_0_TR5     :1;
						uint32_t EXTI_RTSR1_0_TR6     :1;
						uint32_t EXTI_RTSR1_0_TR7     :1;
						uint32_t EXTI_RTSR1_0_TR8     :1;
						uint32_t EXTI_RTSR1_0_TR9     :1;
						uint32_t EXTI_RTSR1_0_TR10    :1;
						uint32_t EXTI_RTSR1_0_TR11    :1;
						uint32_t EXTI_RTSR1_0_TR12    :1;
						uint32_t EXTI_RTSR1_0_TR13    :1;
						uint32_t EXTI_RTSR1_0_TR14    :1;
						uint32_t EXTI_RTSR1_0_TR15    :1;
						uint32_t EXTI_RTSR1_0_TR16    :1;
						uint32_t EXTI_RTSR1_0_TR17    :1;
						uint32_t EXTI_RTSR1_0_TR18    :1;
						uint32_t EXTI_RTSR1_0_TR19    :1;
						uint32_t EXTI_RTSR1_0_TR20    :1;
						uint32_t EXTI_RTSR1_0_TR21    :1;
						uint32_t EXTI_RTSR1_0_RT22    :1;
						uint32_t                      :9;
					};
					#ifdef EXTI_RTSR1_1
					struct
					{
						uint32_t RT0                  :1;
						uint32_t RT1                  :1;
						uint32_t RT2                  :1;
						uint32_t RT3                  :1;
						uint32_t RT4                  :1;
						uint32_t RT5                  :1;
						uint32_t RT6                  :1;
						uint32_t RT7                  :1;
						uint32_t RT8                  :1;
						uint32_t RT9                  :1;
						uint32_t RT10                 :1;
						uint32_t RT11                 :1;
						uint32_t RT12                 :1;
						uint32_t RT13                 :1;
						uint32_t RT14                 :1;
						uint32_t RT15                 :1;
						uint32_t RT16                 :1;
						uint32_t                      :1;
						uint32_t RT18                 :1;
						uint32_t RT19                 :1;
						uint32_t RT20                 :1;
						uint32_t RT21                 :1;
						uint32_t                      :10;
					};
					#endif
				};
				//SOOL-EXTI_RTSR1-DECLARATION
			};
			#endif
			
			#ifdef EXTI_RTSR2
			struct RTSR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t EXTI_RTSR2_0_TR32    :1;
						uint32_t EXTI_RTSR2_0_TR33    :1;
						uint32_t                      :1;
						uint32_t EXTI_RTSR2_0_RT35    :1;
						uint32_t EXTI_RTSR2_0_RT36    :1;
						uint32_t EXTI_RTSR2_0_RT37    :1;
						uint32_t EXTI_RTSR2_0_RT38    :1;
						uint32_t                      :10;
						uint32_t EXTI_RTSR2_0_TR49    :1;
						uint32_t                      :1;
						uint32_t EXTI_RTSR2_0_TR51    :1;
						uint32_t                      :12;
					};
					#ifdef EXTI_RTSR2_1
					struct
					{
						uint32_t RT32                 :1;
						uint32_t EXTI_RTSR2_1_RT33    :1;
						uint32_t                      :30;
					};
					#endif
				};
				//SOOL-EXTI_RTSR2-DECLARATION
			};
			#endif
			
			#ifdef EXTI_RTSR3
			struct RTSR3_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :18;
					uint32_t TR82                 :1;
					uint32_t                      :1;
					uint32_t TR84                 :1;
					uint32_t TR85                 :1;
					uint32_t TR86                 :1;
					uint32_t                      :9;
			
				//SOOL-EXTI_RTSR3-DECLARATION
			};
			#endif
			
			#ifdef EXTI_SWIER
			struct SWIER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef EXTI_SWIER_0
					struct
					{
						uint32_t SWIE0                :1;
						uint32_t SWIE1                :1;
						uint32_t SWIE2                :1;
						uint32_t SWIE3                :1;
						uint32_t SWIE4                :1;
						uint32_t SWIE5                :1;
						uint32_t SWIE6                :1;
						uint32_t SWIE7                :1;
						uint32_t SWIE8                :1;
						uint32_t SWIE9                :1;
						uint32_t SWIE10               :1;
						uint32_t SWIE11               :1;
						uint32_t SWIE12               :1;
						uint32_t SWIE13               :1;
						uint32_t SWIE14               :1;
						uint32_t SWIE15               :1;
						uint32_t SWIE16               :1;
						uint32_t SWIE17               :1;
						uint32_t EXTI_SWIER_0_SWIE18  :1;
						uint32_t EXTI_SWIER_0_SWIE19  :1;
						uint32_t EXTI_SWIER_0_SWIE20  :1;
						uint32_t EXTI_SWIER_0_SWIE21  :1;
						uint32_t EXTI_SWIER_0_SWIE22  :1;
						uint32_t EXTI_SWIER_0_SWIE23  :1;
						uint32_t EXTI_SWIER_0_SWIE24  :1;
						uint32_t                      :4;
						uint32_t EXTI_SWIER_0_SWIE29  :1;
						uint32_t EXTI_SWIER_0_SWIE30  :1;
						uint32_t EXTI_SWIER_0_SWIE31  :1;
					};
					#endif
					#ifdef EXTI_SWIER_1
					struct
					{
						uint32_t SWI0                 :1;
						uint32_t SWI1                 :1;
						uint32_t SWI2                 :1;
						uint32_t SWI3                 :1;
						uint32_t SWI4                 :1;
						uint32_t SWI5                 :1;
						uint32_t SWI6                 :1;
						uint32_t SWI7                 :1;
						uint32_t SWI8                 :1;
						uint32_t SWI9                 :1;
						uint32_t SWI10                :1;
						uint32_t SWI11                :1;
						uint32_t SWI12                :1;
						uint32_t SWI13                :1;
						uint32_t SWI14                :1;
						uint32_t SWI15                :1;
						uint32_t SWI16                :1;
						uint32_t SWI17                :1;
						uint32_t EXTI_SWIER_1_SWI18   :1;
						uint32_t EXTI_SWIER_1_SWI19   :1;
						uint32_t EXTI_SWIER_1_SWI20   :1;
						uint32_t EXTI_SWIER_1_SWI21   :1;
						uint32_t EXTI_SWIER_1_SWI22   :1;
						uint32_t EXTI_SWIER_1_SWI23   :1;
						uint32_t                      :5;
						uint32_t EXTI_SWIER_1_SWI29   :1;
						uint32_t EXTI_SWIER_1_SWI30   :1;
						uint32_t EXTI_SWIER_1_SWI31   :1;
					};
					#endif
				};
				//SOOL-EXTI_SWIER-DECLARATION
			};
			#endif
			
			#ifdef EXTI_SWIER1
			struct SWIER1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t EXTI_SWIER1_0_SWIER0 :1;
						uint32_t EXTI_SWIER1_0_SWIER1 :1;
						uint32_t EXTI_SWIER1_0_SWIER2 :1;
						uint32_t EXTI_SWIER1_0_SWIER3 :1;
						uint32_t EXTI_SWIER1_0_SWIER4 :1;
						uint32_t EXTI_SWIER1_0_SWIER5 :1;
						uint32_t EXTI_SWIER1_0_SWIER6 :1;
						uint32_t EXTI_SWIER1_0_SWIER7 :1;
						uint32_t EXTI_SWIER1_0_SWIER8 :1;
						uint32_t EXTI_SWIER1_0_SWIER9 :1;
						uint32_t EXTI_SWIER1_0_SWIER10 :1;
						uint32_t EXTI_SWIER1_0_SWIER11 :1;
						uint32_t EXTI_SWIER1_0_SWIER12 :1;
						uint32_t EXTI_SWIER1_0_SWIER13 :1;
						uint32_t EXTI_SWIER1_0_SWIER14 :1;
						uint32_t EXTI_SWIER1_0_SWIER15 :1;
						uint32_t EXTI_SWIER1_0_SWIER16 :1;
						uint32_t EXTI_SWIER1_0_SWIER17 :1;
						uint32_t EXTI_SWIER1_0_SWIER18 :1;
						uint32_t EXTI_SWIER1_0_SWIER19 :1;
						uint32_t EXTI_SWIER1_0_SWIER20 :1;
						uint32_t EXTI_SWIER1_0_SWIER21 :1;
						uint32_t EXTI_SWIER1_0_SWI22  :1;
						uint32_t                      :9;
					};
					#ifdef EXTI_SWIER1_1
					struct
					{
						uint32_t SWI0                 :1;
						uint32_t SWI1                 :1;
						uint32_t SWI2                 :1;
						uint32_t SWI3                 :1;
						uint32_t SWI4                 :1;
						uint32_t SWI5                 :1;
						uint32_t SWI6                 :1;
						uint32_t SWI7                 :1;
						uint32_t SWI8                 :1;
						uint32_t SWI9                 :1;
						uint32_t SWI10                :1;
						uint32_t SWI11                :1;
						uint32_t SWI12                :1;
						uint32_t SWI13                :1;
						uint32_t SWI14                :1;
						uint32_t SWI15                :1;
						uint32_t SWI16                :1;
						uint32_t                      :1;
						uint32_t SWI18                :1;
						uint32_t SWI19                :1;
						uint32_t SWI20                :1;
						uint32_t SWI21                :1;
						uint32_t                      :10;
					};
					#endif
				};
				//SOOL-EXTI_SWIER1-DECLARATION
			};
			#endif
			
			#ifdef EXTI_SWIER2
			struct SWIER2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t EXTI_SWIER2_0_SWIER32 :1;
						uint32_t EXTI_SWIER2_0_SWIER33 :1;
						uint32_t                      :1;
						uint32_t EXTI_SWIER2_0_SWI35  :1;
						uint32_t EXTI_SWIER2_0_SWI36  :1;
						uint32_t EXTI_SWIER2_0_SWI37  :1;
						uint32_t EXTI_SWIER2_0_SWI38  :1;
						uint32_t                      :10;
						uint32_t EXTI_SWIER2_0_SWIER49 :1;
						uint32_t                      :1;
						uint32_t EXTI_SWIER2_0_SWIER51 :1;
						uint32_t                      :12;
					};
					#ifdef EXTI_SWIER2_1
					struct
					{
						uint32_t SWI32                :1;
						uint32_t EXTI_SWIER2_1_SWI33  :1;
						uint32_t                      :30;
					};
					#endif
				};
				//SOOL-EXTI_SWIER2-DECLARATION
			};
			#endif
			
			#ifdef EXTI_SWIER3
			struct SWIER3_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :18;
					uint32_t SWIER82              :1;
					uint32_t                      :1;
					uint32_t SWIER84              :1;
					uint32_t SWIER85              :1;
					uint32_t SWIER86              :1;
					uint32_t                      :9;
			
				//SOOL-EXTI_SWIER3-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					EXTI_MAP0_IMR;       // @0x000
					EXTI_MAP0_EMR;       // @0x004
					EXTI_MAP0_RTSR;      // @0x008
					EXTI_MAP0_FTSR;      // @0x00c
					EXTI_MAP0_SWIER;     // @0x010
					EXTI_MAP0_PR;        // @0x014
					__SOOL_PERIPH_PADDING_8;
					EXTI_MAP0_IMR2;      // @0x020
					EXTI_MAP0_EMR2;      // @0x024
					EXTI_MAP0_RTSR2;     // @0x028
					EXTI_MAP0_FTSR2;     // @0x02c
					EXTI_MAP0_SWIER2;    // @0x030
					EXTI_MAP0_PR2;       // @0x034
					__SOOL_PERIPH_PADDING_8;
					EXTI_MAP0_RTSR3;     // @0x040
					EXTI_MAP0_FTSR3;     // @0x044
					EXTI_MAP0_SWIER3;    // @0x048
					EXTI_MAP0_D3PMR3;    // @0x04c
					EXTI_MAP0_D3PCR3L;   // @0x050
					EXTI_MAP0_D3PCR3H;   // @0x054
				};
				struct
				{
					EXTI_MAP1_RTSR1;     // @0x000
					EXTI_MAP1_FTSR1;     // @0x004
					EXTI_MAP1_SWIER1;    // @0x008
					EXTI_MAP1_D3PMR1;    // @0x00c
					EXTI_MAP1_D3PCR1L;   // @0x010
					EXTI_MAP1_D3PCR1H;   // @0x014
					__SOOL_PERIPH_PADDING_8;
					EXTI_MAP1_RTSR2;     // @0x020
					EXTI_MAP1_FTSR2;     // @0x024
					EXTI_MAP1_SWIER2;    // @0x028
					EXTI_MAP1_D3PMR2;    // @0x02c
					EXTI_MAP1_D3PCR2L;   // @0x030
					EXTI_MAP1_D3PCR2H;   // @0x034
					__SOOL_PERIPH_PADDING_32;
				};
				struct
				{
					EXTI_MAP2_IMR1;      // @0x000
					EXTI_MAP2_EMR1;      // @0x004
					EXTI_MAP2_RTSR1;     // @0x008
					EXTI_MAP2_FTSR1;     // @0x00c
					EXTI_MAP2_SWIER1;    // @0x010
					EXTI_MAP2_PR1;       // @0x014
					__SOOL_PERIPH_PADDING_64;
				};
			};
			private:
			EXTI() = delete;
			//SOOL-EXTI-DECLARATION
		};
		
		
		class EXTI_Core
		{
			//SOOL-EXTI_Core-ENUMS
			
			public :
			
			#ifdef EXTI_Core_EMR3
			struct EMR3_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EM64                 :1;
					uint32_t EM65                 :1;
					uint32_t EM66                 :1;
					uint32_t EM67                 :1;
					uint32_t EM68                 :1;
					uint32_t EM69                 :1;
					uint32_t EM70                 :1;
					uint32_t EM71                 :1;
					uint32_t EM72                 :1;
					uint32_t EM73                 :1;
					uint32_t EM74                 :1;
					uint32_t EM75                 :1;
					uint32_t EM76                 :1;
					uint32_t EM77                 :1;
					uint32_t EM78                 :1;
					uint32_t EM79                 :1;
					uint32_t EM80                 :1;
					uint32_t EM81                 :1;
					uint32_t EM82                 :1;
					uint32_t                      :1;
					uint32_t EM84                 :1;
					uint32_t EM85                 :1;
					uint32_t EM86                 :1;
					uint32_t EM87                 :1;
					uint32_t EM88                 :1;
					uint32_t                      :7;
			
				//SOOL-EXTI_Core_EMR3-DECLARATION
			};
			#endif
			
			#ifdef EXTI_Core_IMR3
			struct IMR3_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t IM64                 :1;
					uint32_t IM65                 :1;
					uint32_t IM66                 :1;
					uint32_t IM67                 :1;
					uint32_t IM68                 :1;
					uint32_t IM69                 :1;
					uint32_t IM70                 :1;
					uint32_t IM71                 :1;
					uint32_t IM72                 :1;
					uint32_t IM73                 :1;
					uint32_t IM74                 :1;
					uint32_t IM75                 :1;
					uint32_t IM76                 :1;
					uint32_t IM77                 :1;
					uint32_t IM78                 :1;
					uint32_t IM79                 :1;
					uint32_t IM80                 :1;
					uint32_t IM81                 :1;
					uint32_t IM82                 :1;
					uint32_t                      :1;
					uint32_t IM84                 :1;
					uint32_t IM85                 :1;
					uint32_t IM86                 :1;
					uint32_t IM87                 :1;
					uint32_t IM88                 :1;
					uint32_t                      :7;
			
				//SOOL-EXTI_Core_IMR3-DECLARATION
			};
			#endif
			
			#ifdef EXTI_Core_PR3
			struct PR3_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :18;
					uint32_t PR82                 :1;
					uint32_t                      :1;
					uint32_t PR84                 :1;
					uint32_t PR85                 :1;
					uint32_t PR86                 :1;
					uint32_t                      :9;
			
				//SOOL-EXTI_Core_PR3-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					uint32_t IMR1;       // @0x000
					uint32_t EMR1;       // @0x004
					uint32_t PR1;        // @0x008
					__SOOL_PERIPH_PADDING_4;
					uint32_t IMR2;       // @0x010
					uint32_t EMR2;       // @0x014
					uint32_t PR2;        // @0x018
					__SOOL_PERIPH_PADDING_4;
					IMR3_TypeDef IMR3;   // @0x020
					EMR3_TypeDef EMR3;   // @0x024
					PR3_TypeDef PR3;     // @0x028
				};
			};
			private:
			EXTI_Core() = delete;
			//SOOL-EXTI_Core-DECLARATION
		};
		
		//region instances
#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F3     ) || defined(STM32L0     ) ||\
    defined(STM32L1     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define EXTI_BASE_ADDR ((uint32_t)0x40010400U)
#endif

#if defined(STM32F2     ) || defined(STM32F4     ) || defined(STM32F7     ) 
#define EXTI_BASE_ADDR ((uint32_t)0x40013C00U)
#endif

#if defined(STM32H7     ) 
#define EXTI_BASE_ADDR ((uint32_t)0x58000000U)
#define EXTI_D1_BASE_ADDR ((uint32_t)0x58000080U)
#define EXTI_D2_BASE_ADDR ((uint32_t)0x580000C0U)
#endif

#ifdef EXTI_BASE_ADDR
volatile class EXTI * const EXTI = reinterpret_cast<class EXTI* const>(EXTI_BASE_ADDR);
#endif
#ifdef EXTI_D1_BASE_ADDR
volatile class EXTI_Core * const EXTI_D1 = reinterpret_cast<class EXTI_Core* const>(EXTI_D1_BASE_ADDR);
#endif
#ifdef EXTI_D2_BASE_ADDR
volatile class EXTI_Core * const EXTI_D2 = reinterpret_cast<class EXTI_Core* const>(EXTI_D2_BASE_ADDR);
#endif
//endregion

//SOOL-EXTI-DEFINES
//SOOL-EXTI-DEFINITION
	};
};//region undef
#undef EXTI_EMR2_0_EM41
#undef EXTI_EMR2_0_EM42
#undef EXTI_EMR2_0_EM43
#undef EXTI_EMR2_0_EM44
#undef EXTI_EMR2_0_EM45
#undef EXTI_EMR2_0_EM46
#undef EXTI_EMR2_0_EM47
#undef EXTI_EMR2_0_EM48
#undef EXTI_EMR2_0_EM49
#undef EXTI_EMR2_0_EM50
#undef EXTI_EMR2_0_EM51
#undef EXTI_EMR2_0_EM52
#undef EXTI_EMR2_0_EM53
#undef EXTI_EMR2_0_EM54
#undef EXTI_EMR2_0_EM55
#undef EXTI_EMR2_0_EM56
#undef EXTI_EMR2_0_EM57
#undef EXTI_EMR2_0_EM58
#undef EXTI_EMR2_0_EM59
#undef EXTI_EMR2_0_EM60
#undef EXTI_EMR2_0_EM61
#undef EXTI_EMR2_0_EM62
#undef EXTI_EMR2_0_EM63
#undef EXTI_FTSR1_0_TR0
#undef EXTI_FTSR1_0_TR1
#undef EXTI_FTSR1_0_TR2
#undef EXTI_FTSR1_0_TR3
#undef EXTI_FTSR1_0_TR4
#undef EXTI_FTSR1_0_TR5
#undef EXTI_FTSR1_0_TR6
#undef EXTI_FTSR1_0_TR7
#undef EXTI_FTSR1_0_TR8
#undef EXTI_FTSR1_0_TR9
#undef EXTI_FTSR1_0_TR10
#undef EXTI_FTSR1_0_TR11
#undef EXTI_FTSR1_0_TR12
#undef EXTI_FTSR1_0_TR13
#undef EXTI_FTSR1_0_TR14
#undef EXTI_FTSR1_0_TR15
#undef EXTI_FTSR1_0_TR16
#undef EXTI_FTSR1_0_TR17
#undef EXTI_FTSR1_0_TR18
#undef EXTI_FTSR1_0_TR19
#undef EXTI_FTSR1_0_TR20
#undef EXTI_FTSR1_0_TR21
#undef EXTI_FTSR2_0_TR49
#undef EXTI_FTSR2_0_TR51
#undef EXTI_IMR2_0_IM41
#undef EXTI_IMR2_0_IM42
#undef EXTI_IMR2_0_IM43
#undef EXTI_IMR2_0_IM44
#undef EXTI_IMR2_0_IM45
#undef EXTI_IMR2_0_IM46
#undef EXTI_IMR2_0_IM47
#undef EXTI_IMR2_0_IM48
#undef EXTI_IMR2_0_IM49
#undef EXTI_IMR2_0_IM50
#undef EXTI_IMR2_0_IM51
#undef EXTI_IMR2_0_IM52
#undef EXTI_IMR2_0_IM53
#undef EXTI_IMR2_0_IM54
#undef EXTI_IMR2_0_IM55
#undef EXTI_IMR2_0_IM56
#undef EXTI_IMR2_0_IM57
#undef EXTI_IMR2_0_IM58
#undef EXTI_IMR2_0_IM59
#undef EXTI_IMR2_0_IM60
#undef EXTI_IMR2_0_IM61
#undef EXTI_IMR2_0_IM62
#undef EXTI_IMR2_0_IM63
#undef EXTI_PR1_0_PR0
#undef EXTI_PR1_0_PR1
#undef EXTI_PR1_0_PR2
#undef EXTI_PR1_0_PR3
#undef EXTI_PR1_0_PR4
#undef EXTI_PR1_0_PR5
#undef EXTI_PR1_0_PR6
#undef EXTI_PR1_0_PR7
#undef EXTI_PR1_0_PR8
#undef EXTI_PR1_0_PR9
#undef EXTI_PR1_0_PR10
#undef EXTI_PR1_0_PR11
#undef EXTI_PR1_0_PR12
#undef EXTI_PR1_0_PR13
#undef EXTI_PR1_0_PR14
#undef EXTI_PR1_0_PR15
#undef EXTI_PR1_0_PR16
#undef EXTI_PR1_0_PR17
#undef EXTI_PR1_0_PR18
#undef EXTI_PR1_0_PR19
#undef EXTI_PR1_0_PR20
#undef EXTI_PR1_0_PR21
#undef EXTI_PR2_0_PR49
#undef EXTI_PR2_0_PR51
#undef EXTI_RTSR1_0_TR0
#undef EXTI_RTSR1_0_TR1
#undef EXTI_RTSR1_0_TR2
#undef EXTI_RTSR1_0_TR3
#undef EXTI_RTSR1_0_TR4
#undef EXTI_RTSR1_0_TR5
#undef EXTI_RTSR1_0_TR6
#undef EXTI_RTSR1_0_TR7
#undef EXTI_RTSR1_0_TR8
#undef EXTI_RTSR1_0_TR9
#undef EXTI_RTSR1_0_TR10
#undef EXTI_RTSR1_0_TR11
#undef EXTI_RTSR1_0_TR12
#undef EXTI_RTSR1_0_TR13
#undef EXTI_RTSR1_0_TR14
#undef EXTI_RTSR1_0_TR15
#undef EXTI_RTSR1_0_TR16
#undef EXTI_RTSR1_0_TR17
#undef EXTI_RTSR1_0_TR18
#undef EXTI_RTSR1_0_TR19
#undef EXTI_RTSR1_0_TR20
#undef EXTI_RTSR1_0_TR21
#undef EXTI_RTSR2_0_TR49
#undef EXTI_RTSR2_0_TR51
#undef EXTI_SWIER1_0_SWIER0
#undef EXTI_SWIER1_0_SWIER1
#undef EXTI_SWIER1_0_SWIER2
#undef EXTI_SWIER1_0_SWIER3
#undef EXTI_SWIER1_0_SWIER4
#undef EXTI_SWIER1_0_SWIER5
#undef EXTI_SWIER1_0_SWIER6
#undef EXTI_SWIER1_0_SWIER7
#undef EXTI_SWIER1_0_SWIER8
#undef EXTI_SWIER1_0_SWIER9
#undef EXTI_SWIER1_0_SWIER10
#undef EXTI_SWIER1_0_SWIER11
#undef EXTI_SWIER1_0_SWIER12
#undef EXTI_SWIER1_0_SWIER13
#undef EXTI_SWIER1_0_SWIER14
#undef EXTI_SWIER1_0_SWIER15
#undef EXTI_SWIER1_0_SWIER16
#undef EXTI_SWIER1_0_SWIER17
#undef EXTI_SWIER1_0_SWIER18
#undef EXTI_SWIER1_0_SWIER19
#undef EXTI_SWIER1_0_SWIER20
#undef EXTI_SWIER1_0_SWIER21
#undef EXTI_SWIER2_0_SWIER49
#undef EXTI_SWIER2_0_SWIER51
#undef EXTI_MAP1_RTSR1
#undef EXTI_MAP1_FTSR1
#undef EXTI_MAP1_SWIER1
#undef EXTI_MAP1_D3PMR1
#undef EXTI_MAP1_D3PCR1L
#undef EXTI_MAP1_D3PCR1H
#undef EXTI_MAP1_RTSR2
#undef EXTI_MAP1_FTSR2
#undef EXTI_MAP1_SWIER2
#undef EXTI_MAP1_D3PMR2
#undef EXTI_MAP1_D3PCR2L
#undef EXTI_MAP1_D3PCR2H
#undef EXTI_MAP0_RTSR3
#undef EXTI_MAP0_FTSR3
#undef EXTI_MAP0_SWIER3
#undef EXTI_MAP0_D3PMR3
#undef EXTI_MAP0_D3PCR3L
#undef EXTI_MAP0_D3PCR3H
#undef EXTI_MAP0_IMR
#undef EXTI_MAP0_EMR
#undef EXTI_MAP0_RTSR
#undef EXTI_MAP0_FTSR
#undef EXTI_MAP0_SWIER
#undef EXTI_MAP0_PR
#undef EXTI_EMR_0_MR16
#undef EXTI_IMR_0_MR16
#undef EXTI_EMR_0_MR18
#undef EXTI_IMR_0_MR18
#undef EXTI_EMR_0_MR19
#undef EXTI_IMR_0_MR19
#undef EXTI_EMR_0_MR20
#undef EXTI_IMR_0_MR20
#undef EXTI_EMR_0_MR21
#undef EXTI_IMR_0_MR21
#undef EXTI_EMR_0_MR22
#undef EXTI_IMR_0_MR22
#undef EXTI_EMR_0_MR23
#undef EXTI_IMR_0_MR23
#undef EXTI_EMR_0_MR24
#undef EXTI_IMR_0_MR24
#undef EXTI_EMR_0_MR25
#undef EXTI_EMR_1_EM27
#undef EXTI_IMR_0_MR25
#undef EXTI_IMR_1_IM27
#undef EXTI_EMR_0_MR26
#undef EXTI_IMR_0_MR26
#undef EXTI_EMR_0_MR27
#undef EXTI_IMR_0_MR27
#undef EXTI_EMR_0_MR28
#undef EXTI_IMR_0_MR28
#undef EXTI_EMR_0_MR29
#undef EXTI_EMR2_0_MR33
#undef EXTI_FTSR_0_TR29
#undef EXTI_FTSR2_0_TR33
#undef EXTI_IMR_0_MR29
#undef EXTI_IMR2_0_MR33
#undef EXTI_PR_0_P29
#undef EXTI_PR2_0_PR33
#undef EXTI_RTSR_0_TR29
#undef EXTI_RTSR2_0_TR33
#undef EXTI_SWIER_0_SWIE29
#undef EXTI_SWIER2_0_SWIER33
#undef EXTI_EMR_0_MR30
#undef EXTI_EMR2_0_MR32
#undef EXTI_FTSR_0_TR30
#undef EXTI_FTSR2_0_TR32
#undef EXTI_IMR_0_MR30
#undef EXTI_IMR2_0_MR32
#undef EXTI_PR_0_P30
#undef EXTI_PR2_0_PR32
#undef EXTI_RTSR_0_TR30
#undef EXTI_RTSR2_0_TR32
#undef EXTI_SWIER_0_SWIE30
#undef EXTI_SWIER2_0_SWIER32
#undef EXTI_EMR_0_MR31
#undef EXTI_FTSR_0_TR31
#undef EXTI_IMR_0_MR31
#undef EXTI_PR_0_P31
#undef EXTI_RTSR_0_TR31
#undef EXTI_SWIER_0_SWIE31
#undef EXTI_EMR_1_EM16
#undef EXTI_IMR_1_IM16
#undef EXTI_EMR_1_EM18
#undef EXTI_IMR_1_IM18
#undef EXTI_EMR_1_EM19
#undef EXTI_FTSR_0_TR19
#undef EXTI_IMR_1_IM19
#undef EXTI_PR_0_P19
#undef EXTI_RTSR_0_TR19
#undef EXTI_SWIER_0_SWIE19
#undef EXTI_EMR_1_EM20
#undef EXTI_FTSR_0_TR20
#undef EXTI_IMR_1_IM20
#undef EXTI_PR_0_P20
#undef EXTI_RTSR_0_TR20
#undef EXTI_SWIER_0_SWIE20
#undef EXTI_EMR_1_EM21
#undef EXTI_EMR_1_EM22
#undef EXTI_FTSR_0_TR22
#undef EXTI_IMR_1_IM21
#undef EXTI_IMR_1_IM22
#undef EXTI_PR_0_P22
#undef EXTI_RTSR_0_TR22
#undef EXTI_SWIER_0_SWIE22
#undef EXTI_EMR_1_EM23
#undef EXTI_IMR_1_IM23
#undef EXTI_EMR_1_EM24
#undef EXTI_IMR_1_IM24
#undef EXTI_EMR_1_EM25
#undef EXTI_IMR_1_IM25
#undef EXTI_EMR_1_EM26
#undef EXTI_IMR_1_IM26
#undef EXTI_EMR_1_EM28
#undef EXTI_IMR_1_IM28
#undef EXTI_EMR_1_EM29
#undef EXTI_IMR_1_IM29
#undef EXTI_EMR_1_EM30
#undef EXTI_FTSR_1_FT30
#undef EXTI_IMR_1_IM30
#undef EXTI_PR_1_PIF30
#undef EXTI_RTSR_1_RT30
#undef EXTI_SWIER_1_SWI30
#undef EXTI_EMR_1_EM31
#undef EXTI_FTSR_1_FT31
#undef EXTI_IMR_1_IM31
#undef EXTI_PR_1_PIF31
#undef EXTI_RTSR_1_RT31
#undef EXTI_SWIER_1_SWI31
#undef EXTI_EMR1_EM19
#undef EXTI_FTSR1_0_FT22
#undef EXTI_FTSR2_0_FT37
#undef EXTI_FTSR2_0_FT38
#undef EXTI_PR1_0_PIF22
#undef EXTI_PR2_0_PIF37
#undef EXTI_PR2_0_PIF38
#undef EXTI_RTSR1_0_RT22
#undef EXTI_RTSR2_0_RT37
#undef EXTI_RTSR2_0_RT38
#undef EXTI_SWIER1_0_SWI22
#undef EXTI_SWIER2_0_SWI37
#undef EXTI_SWIER2_0_SWI38
#undef EXTI_MAP2_IMR1
#undef EXTI_MAP2_EMR1
#undef EXTI_MAP2_RTSR1
#undef EXTI_MAP2_FTSR1
#undef EXTI_MAP2_SWIER1
#undef EXTI_MAP2_PR1
#undef EXTI_EMR1_EM29
#undef EXTI_IMR1_0_IM29
#undef EXTI_EMR1_EM30
#undef EXTI_EMR2_0_EM36
#undef EXTI_IMR1_0_IM30
#undef EXTI_IMR2_0_IM36
#undef EXTI_MAP0_IMR2
#undef EXTI_MAP0_EMR2
#undef EXTI_MAP0_RTSR2
#undef EXTI_MAP0_FTSR2
#undef EXTI_MAP0_SWIER2
#undef EXTI_MAP0_PR2
#undef EXTI_EMR2_0_MR34
#undef EXTI_EMR2_0_MR35
#undef EXTI_IMR2_0_MR34
#undef EXTI_IMR2_0_MR35
#undef EXTI_EMR2_0_EM37
#undef EXTI_EMR2_0_EM38
#undef EXTI_IMR2_0_IM37
#undef EXTI_IMR2_0_IM38
#undef EXTI_EMR2_0_EM39
#undef EXTI_IMR2_0_IM39
#undef EXTI_EMR2_0_EM40
#undef EXTI_IMR2_0_IM40
#undef EXTI_EMR2_1_EM33
#undef EXTI_IMR2_1_IM33
#undef EXTI_EMR2_1_EM34
#undef EXTI_IMR2_1_IM34
#undef EXTI_EMR2_1_EM35
#undef EXTI_IMR2_1_IM35
#undef EXTI_FTSR_0_TR18
#undef EXTI_PR_0_P18
#undef EXTI_RTSR_0_TR18
#undef EXTI_SWIER_0_SWIE18
#undef EXTI_FTSR_0_TR21
#undef EXTI_PR_0_P21
#undef EXTI_RTSR_0_TR21
#undef EXTI_SWIER_0_SWIE21
#undef EXTI_FTSR_0_TR23
#undef EXTI_PR_0_P23
#undef EXTI_RTSR_0_TR23
#undef EXTI_SWIER_0_SWIE23
#undef EXTI_FTSR_0_TR24
#undef EXTI_PR_0_P24
#undef EXTI_RTSR_0_TR24
#undef EXTI_SWIER_0_SWIE24
#undef EXTI_FTSR_1_FT18
#undef EXTI_PR_1_PIF18
#undef EXTI_RTSR_1_RT18
#undef EXTI_SWIER_1_SWI18
#undef EXTI_FTSR_1_FT19
#undef EXTI_PR_1_PIF19
#undef EXTI_RTSR_1_RT19
#undef EXTI_SWIER_1_SWI19
#undef EXTI_FTSR_1_FT20
#undef EXTI_PR_1_PIF20
#undef EXTI_RTSR_1_RT20
#undef EXTI_SWIER_1_SWI20
#undef EXTI_FTSR_1_FT21
#undef EXTI_FTSR_1_FT22
#undef EXTI_PR_1_PIF21
#undef EXTI_PR_1_PIF22
#undef EXTI_RTSR_1_RT21
#undef EXTI_RTSR_1_RT22
#undef EXTI_SWIER_1_SWI21
#undef EXTI_SWIER_1_SWI22
#undef EXTI_FTSR_1_FT23
#undef EXTI_PR_1_PIF23
#undef EXTI_RTSR_1_RT23
#undef EXTI_SWIER_1_SWI23
#undef EXTI_FTSR_1_FT29
#undef EXTI_PR_1_PIF29
#undef EXTI_RTSR_1_RT29
#undef EXTI_SWIER_1_SWI29
#undef EXTI_FTSR2_0_FT35
#undef EXTI_PR2_0_PIF35
#undef EXTI_RTSR2_0_RT35
#undef EXTI_SWIER2_0_SWI35
#undef EXTI_FTSR2_0_FT36
#undef EXTI_PR2_0_PIF36
#undef EXTI_RTSR2_0_RT36
#undef EXTI_SWIER2_0_SWI36
#undef EXTI_FTSR2_1_FT33
#undef EXTI_PR2_1_PIF33
#undef EXTI_RTSR2_1_RT33
#undef EXTI_SWIER2_1_SWI33
//endregion
#endif
#endif
