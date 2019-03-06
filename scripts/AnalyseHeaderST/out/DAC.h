#ifndef __SOOL_DAC_H
#define __SOOL_DAC_H

#include "peripheral_include.h"
//SOOL-DAC-INCLUDES
#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F100xB ) ||\
    defined(STM32F100xE ) || defined(STM32F101xE ) || defined(STM32F101xG ) || defined(STM32F103xE ) ||\
    defined(STM32F103xG ) || defined(STM32F105xC ) || defined(STM32F107xC ) || defined(STM32F2     ) ||\
    defined(STM32F3     ) || defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F410Cx ) ||\
    defined(STM32F410Rx ) || defined(STM32F410Tx ) || defined(STM32F413xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L052xx ) ||\
    defined(STM32L053xx ) || defined(STM32L062xx ) || defined(STM32L063xx ) || defined(STM32L072xx ) ||\
    defined(STM32L073xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) || defined(STM32L1     ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
//region defines

#if defined(STM32H7     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define DAC_CCR
#define DAC_CR_0_CEN1        CEN1                 // 1 bits @ 14
#define DAC_MCR
#define DAC_SHHR
#define DAC_SHRR
#define DAC_SHSR1
#define DAC_SHSR2
#define DAC_SR_CAL_FLAG1     CAL_FLAG1            // 1 bits @ 14
#define DAC_MAP0_CCR         CCR_TypeDef CCR
#define DAC_MAP0_MCR         MCR_TypeDef MCR
#define DAC_MAP0_SHSR1       SHSR1_TypeDef SHSR1
#define DAC_MAP0_SHSR2       SHSR2_TypeDef SHSR2
#define DAC_MAP0_SHHR        SHHR_TypeDef SHHR
#define DAC_MAP0_SHRR        SHRR_TypeDef SHRR
#else
#define DAC_CR_0_CEN1
#define DAC_SR_CAL_FLAG1
#define DAC_MAP0_CCR __SOOL_PERIPH_PADDING_4
#define DAC_MAP0_MCR __SOOL_PERIPH_PADDING_4
#define DAC_MAP0_SHSR1 __SOOL_PERIPH_PADDING_4
#define DAC_MAP0_SHSR2 __SOOL_PERIPH_PADDING_4
#define DAC_MAP0_SHHR __SOOL_PERIPH_PADDING_4
#define DAC_MAP0_SHRR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32H7     ) || defined(STM32L431xx ) || defined(STM32L432xx ) || defined(STM32L433xx ) ||\
    defined(STM32L442xx ) || defined(STM32L443xx ) || defined(STM32L471xx ) || defined(STM32L475xx ) ||\
    defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define DAC_CCR_OTRIM2       OTRIM2               // 5 bits @ 16
#define DAC_CR_0_CEN2        CEN2                 // 1 bits @ 30
#define DAC_MCR_MODE2        MODE2                // 3 bits @ 16
#define DAC_SHHR_THOLD2      THOLD2               // 10 bits @ 16
#define DAC_SHRR_TREFRESH2   TREFRESH2            // 8 bits @ 16
#define DAC_SR_CAL_FLAG2     CAL_FLAG2            // 1 bits @ 30
#define DAC_SR_BWST2         BWST2                // 1 bits @ 31
#else
#define DAC_CCR_OTRIM2
#define DAC_CR_0_CEN2
#define DAC_MCR_MODE2
#define DAC_SHHR_THOLD2
#define DAC_SHRR_TREFRESH2
#define DAC_SR_CAL_FLAG2
#define DAC_SR_BWST2
#endif

#define DAC_CR
#define DAC_DHR12L1
#define DAC_DHR12R1
#define DAC_DHR8R1
#define DAC_DOR1
#define DAC_SWTRIGR

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F100xB ) ||\
    defined(STM32F100xE ) || defined(STM32F101xE ) || defined(STM32F101xG ) || defined(STM32F103xE ) ||\
    defined(STM32F103xG ) || defined(STM32F105xC ) || defined(STM32F107xC ) || defined(STM32F2     ) ||\
    defined(STM32F3     ) || defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F410Cx ) ||\
    defined(STM32F410Rx ) || defined(STM32F410Tx ) || defined(STM32F413xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32L052xx ) || defined(STM32L053xx ) ||\
    defined(STM32L062xx ) || defined(STM32L063xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) ||\
    defined(STM32L082xx ) || defined(STM32L083xx ) || defined(STM32L1     ) 
#define DAC_CR_0_BOFF1       BOFF1                // 1 bits @ 1
#else
#define DAC_CR_0_BOFF1
#endif

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F100xB ) ||\
    defined(STM32F100xE ) || defined(STM32F101xE ) || defined(STM32F101xG ) || defined(STM32F103xE ) ||\
    defined(STM32F103xG ) || defined(STM32F105xC ) || defined(STM32F107xC ) || defined(STM32F2     ) ||\
    defined(STM32F3     ) || defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F410Cx ) ||\
    defined(STM32F410Rx ) || defined(STM32F410Tx ) || defined(STM32F413xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32L052xx ) || defined(STM32L053xx ) ||\
    defined(STM32L062xx ) || defined(STM32L063xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) ||\
    defined(STM32L082xx ) || defined(STM32L083xx ) || defined(STM32L1     ) || defined(STM32L4     ) 
#define DAC_CR_0_TEN1        TEN1                 // 1 bits @ 2
#define DAC_CR_0_TSEL1       TSEL1                // 3 bits @ 3
#else
#define DAC_CR_0_TEN1
#define DAC_CR_0_TSEL1
#endif

#if defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) ||\
    defined(STM32F098xx ) || defined(STM32F100xB ) || defined(STM32F100xE ) || defined(STM32F101xE ) ||\
    defined(STM32F101xG ) || defined(STM32F103xE ) || defined(STM32F103xG ) || defined(STM32F105xC ) ||\
    defined(STM32F107xC ) || defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) ||\
    defined(STM32F413xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F423xx ) ||\
    defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) ||\
    defined(STM32H7     ) || defined(STM32L052xx ) || defined(STM32L053xx ) || defined(STM32L062xx ) ||\
    defined(STM32L063xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L082xx ) ||\
    defined(STM32L083xx ) || defined(STM32L1     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define DAC_CR_0_WAVE1       WAVE1                // 2 bits @ 6
#define DAC_CR_0_MAMP1       MAMP1                // 4 bits @ 8
#else
#define DAC_CR_0_WAVE1
#define DAC_CR_0_MAMP1
#endif

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F100xB ) ||\
    defined(STM32F100xE ) || defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) ||\
    defined(STM32F413xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F423xx ) ||\
    defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) ||\
    defined(STM32H7     ) || defined(STM32L052xx ) || defined(STM32L053xx ) || defined(STM32L062xx ) ||\
    defined(STM32L063xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L082xx ) ||\
    defined(STM32L083xx ) || defined(STM32L1     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define DAC_CR_0_DMAUDRIE1   DMAUDRIE1            // 1 bits @ 13
#define DAC_SR
#define DAC_MAP0_SR          SR_TypeDef SR
#else
#define DAC_CR_0_DMAUDRIE1
#define DAC_MAP0_SR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32L4P    ) 
#define DAC_CR_0_HFSEL       HFSEL                // 1 bits @ 15
#else
#define DAC_CR_0_HFSEL
#endif

#if defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) ||\
    defined(STM32F098xx ) || defined(STM32F100xB ) || defined(STM32F100xE ) || defined(STM32F101xE ) ||\
    defined(STM32F101xG ) || defined(STM32F103xE ) || defined(STM32F103xG ) || defined(STM32F105xC ) ||\
    defined(STM32F107xC ) || defined(STM32F2     ) || defined(STM32F303x8 ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) ||\
    defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F398xx ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) ||\
    defined(STM32F413xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F423xx ) ||\
    defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) ||\
    defined(STM32H7     ) || defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L082xx ) ||\
    defined(STM32L083xx ) || defined(STM32L1     ) || defined(STM32L431xx ) || defined(STM32L432xx ) ||\
    defined(STM32L433xx ) || defined(STM32L442xx ) || defined(STM32L443xx ) || defined(STM32L471xx ) ||\
    defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define DAC_CR_0_EN2         EN2                  // 1 bits @ 16
#define DAC_CR_0_WAVE2       WAVE2                // 2 bits @ 22
#define DAC_CR_0_MAMP2       MAMP2                // 4 bits @ 24
#define DAC_CR_0_DMAEN2      DMAEN2               // 1 bits @ 28
#define DAC_DHR12LD_DACC2DHR DACC2DHR             // 12 bits @ 20
#define DAC_DHR12RD_DACC2DHR DACC2DHR             // 12 bits @ 16
#define DAC_DHR8RD_DACC2DHR  DACC2DHR             // 8 bits @ 8
#define DAC_SWTRIGR_SWTRIG2  SWTRIG2              // 1 bits @ 1
#else
#define DAC_CR_0_EN2
#define DAC_CR_0_WAVE2
#define DAC_CR_0_MAMP2
#define DAC_CR_0_DMAEN2
#define DAC_DHR12LD_DACC2DHR
#define DAC_DHR12RD_DACC2DHR
#define DAC_DHR8RD_DACC2DHR
#define DAC_SWTRIGR_SWTRIG2
#endif

#if defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) ||\
    defined(STM32F098xx ) || defined(STM32F100xB ) || defined(STM32F100xE ) || defined(STM32F101xE ) ||\
    defined(STM32F101xG ) || defined(STM32F103xE ) || defined(STM32F103xG ) || defined(STM32F105xC ) ||\
    defined(STM32F107xC ) || defined(STM32F2     ) || defined(STM32F303x8 ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) ||\
    defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F398xx ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) ||\
    defined(STM32F413xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F423xx ) ||\
    defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) ||\
    defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) ||\
    defined(STM32L1     ) 
#define DAC_CR_0_BOFF2       BOFF2                // 1 bits @ 17
#else
#define DAC_CR_0_BOFF2
#endif

#if defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) ||\
    defined(STM32F098xx ) || defined(STM32F100xB ) || defined(STM32F100xE ) || defined(STM32F101xE ) ||\
    defined(STM32F101xG ) || defined(STM32F103xE ) || defined(STM32F103xG ) || defined(STM32F105xC ) ||\
    defined(STM32F107xC ) || defined(STM32F2     ) || defined(STM32F303x8 ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) ||\
    defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F398xx ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) ||\
    defined(STM32F413xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F423xx ) ||\
    defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) ||\
    defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) ||\
    defined(STM32L1     ) || defined(STM32L431xx ) || defined(STM32L432xx ) || defined(STM32L433xx ) ||\
    defined(STM32L442xx ) || defined(STM32L443xx ) || defined(STM32L471xx ) || defined(STM32L475xx ) ||\
    defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) 
#define DAC_CR_0_TEN2        TEN2                 // 1 bits @ 18
#define DAC_CR_0_TSEL2       TSEL2                // 3 bits @ 19
#else
#define DAC_CR_0_TEN2
#define DAC_CR_0_TSEL2
#endif

#if defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) ||\
    defined(STM32F098xx ) || defined(STM32F100xB ) || defined(STM32F100xE ) || defined(STM32F2     ) ||\
    defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F328xx ) ||\
    defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) ||\
    defined(STM32F398xx ) || defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F410Cx ) ||\
    defined(STM32F410Rx ) || defined(STM32F410Tx ) || defined(STM32F413xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L072xx ) ||\
    defined(STM32L073xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) || defined(STM32L1     ) ||\
    defined(STM32L431xx ) || defined(STM32L432xx ) || defined(STM32L433xx ) || defined(STM32L442xx ) ||\
    defined(STM32L443xx ) || defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) ||\
    defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) ||\
    defined(STM32L4P    ) 
#define DAC_CR_0_DMAUDRIE2   DMAUDRIE2            // 1 bits @ 29
#else
#define DAC_CR_0_DMAUDRIE2
#endif

#if defined(STM32F303x8 ) || defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32H7     ) ||\
    defined(STM32L4P    ) 
#define DAC_CR_1
#endif

#if defined(STM32F303x8 ) || defined(STM32F328xx ) || defined(STM32F334x8 ) 
#define DAC_CR_1_OUTEN1      OUTEN1               // 1 bits @ 1
#define DAC_CR_1_OUTEN2      OUTEN2               // 1 bits @ 17
#else
#define DAC_CR_1_OUTEN1
#define DAC_CR_1_OUTEN2
#endif

#if defined(STM32H7     ) || defined(STM32L4P    ) 
#define DAC_CR_1_TSEL1       TSEL1                // 4 bits @ 2
#define DAC_CR_1_TSEL2       TSEL2                // 4 bits @ 18
#define DAC_CR_2
#else
#define DAC_CR_1_TSEL1
#define DAC_CR_1_TSEL2
#endif

#if defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) ||\
    defined(STM32F098xx ) || defined(STM32F100xB ) || defined(STM32F100xE ) || defined(STM32F101xE ) ||\
    defined(STM32F101xG ) || defined(STM32F103xE ) || defined(STM32F103xG ) || defined(STM32F105xC ) ||\
    defined(STM32F107xC ) || defined(STM32F2     ) || defined(STM32F303x8 ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) ||\
    defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F398xx ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) ||\
    defined(STM32F413xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F423xx ) ||\
    defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) ||\
    defined(STM32H7     ) || defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L082xx ) ||\
    defined(STM32L083xx ) || defined(STM32L1     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define DAC_DHR12L2
#define DAC_DHR12R2
#define DAC_DHR8R2
#define DAC_DOR2
#define DAC_MAP0_DHR12R2     DHR12R2_TypeDef DHR12R2
#define DAC_MAP0_DHR12L2     DHR12L2_TypeDef DHR12L2
#define DAC_MAP0_DHR8R2      DHR8R2_TypeDef DHR8R2
#define DAC_MAP0_DOR2        DOR2_TypeDef DOR2
#else
#define DAC_MAP0_DHR12R2 __SOOL_PERIPH_PADDING_4
#define DAC_MAP0_DHR12L2 __SOOL_PERIPH_PADDING_4
#define DAC_MAP0_DHR8R2 __SOOL_PERIPH_PADDING_4
#define DAC_MAP0_DOR2 __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) ||\
    defined(STM32F098xx ) || defined(STM32F100xB ) || defined(STM32F100xE ) || defined(STM32F101xE ) ||\
    defined(STM32F101xG ) || defined(STM32F103xE ) || defined(STM32F103xG ) || defined(STM32F105xC ) ||\
    defined(STM32F107xC ) || defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) ||\
    defined(STM32F413xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F423xx ) ||\
    defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) ||\
    defined(STM32H7     ) || defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L082xx ) ||\
    defined(STM32L083xx ) || defined(STM32L1     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define DAC_DHR12LD
#define DAC_DHR12RD
#define DAC_DHR8RD
#define DAC_MAP0_DHR12RD     DHR12RD_TypeDef DHR12RD
#define DAC_MAP0_DHR12LD     DHR12LD_TypeDef DHR12LD
#define DAC_MAP0_DHR8RD      DHR8RD_TypeDef DHR8RD
#else
#define DAC_MAP0_DHR12RD __SOOL_PERIPH_PADDING_4
#define DAC_MAP0_DHR12LD __SOOL_PERIPH_PADDING_4
#define DAC_MAP0_DHR8RD __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32H7     ) 
#define DAC_SHSR1_1
#endif

#if defined(STM32L4     ) || defined(STM32L4P    ) 
#define DAC_SR_BWST1         BWST1                // 1 bits @ 15
#else
#define DAC_SR_BWST1
#endif

#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F100xB ) ||\
    defined(STM32F100xE ) || defined(STM32F2     ) || defined(STM32F303x8 ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) ||\
    defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F398xx ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) ||\
    defined(STM32F413xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F423xx ) ||\
    defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) ||\
    defined(STM32H7     ) || defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L082xx ) ||\
    defined(STM32L083xx ) || defined(STM32L1     ) || defined(STM32L431xx ) || defined(STM32L432xx ) ||\
    defined(STM32L433xx ) || defined(STM32L442xx ) || defined(STM32L443xx ) || defined(STM32L471xx ) ||\
    defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define DAC_SR_DMAUDR2       DMAUDR2              // 1 bits @ 29
#else
#define DAC_SR_DMAUDR2
#endif

//endregion

namespace sool
{
	namespace core
	{
		class DAC
		{
			//SOOL-DAC-ENUMS
			
			public :
			
			#ifdef DAC_CCR
			struct CCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t OTRIM1               :5;
					uint32_t                      :11;
					uint32_t DAC_CCR_OTRIM2       :5;
					uint32_t                      :11;
			
				//SOOL-DAC_CCR-DECLARATION
			};
			#endif
			
			#ifdef DAC_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t EN1                  :1;
						uint32_t DAC_CR_0_BOFF1       :1;
						uint32_t DAC_CR_0_TEN1        :1;
						uint32_t DAC_CR_0_TSEL1       :3;
						uint32_t DAC_CR_0_WAVE1       :2;
						uint32_t DAC_CR_0_MAMP1       :4;
						uint32_t DMAEN1               :1;
						uint32_t DAC_CR_0_DMAUDRIE1   :1;
						uint32_t DAC_CR_0_CEN1        :1;
						uint32_t DAC_CR_0_HFSEL       :1;
						uint32_t DAC_CR_0_EN2         :1;
						uint32_t DAC_CR_0_BOFF2       :1;
						uint32_t DAC_CR_0_TEN2        :1;
						uint32_t DAC_CR_0_TSEL2       :3;
						uint32_t DAC_CR_0_WAVE2       :2;
						uint32_t DAC_CR_0_MAMP2       :4;
						uint32_t DAC_CR_0_DMAEN2      :1;
						uint32_t DAC_CR_0_DMAUDRIE2   :1;
						uint32_t DAC_CR_0_CEN2        :1;
						uint32_t                      :1;
					};
					#ifdef DAC_CR_1
					struct
					{
						uint32_t                      :1;
						uint32_t DAC_CR_1_OUTEN1      :1;
						uint32_t DAC_CR_1_TSEL1       :4;
						uint32_t                      :11;
						uint32_t DAC_CR_1_OUTEN2      :1;
						uint32_t DAC_CR_1_TSEL2       :4;
						uint32_t                      :10;
					};
					#endif
					#ifdef DAC_CR_2
					struct
					{
						uint32_t                      :1;
						uint32_t TEN1                 :1;
						uint32_t                      :15;
						uint32_t TEN2                 :1;
						uint32_t                      :14;
					};
					#endif
				};
				//SOOL-DAC_CR-DECLARATION
			};
			#endif
			
			#ifdef DAC_DHR12L1
			struct DHR12L1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :4;
					uint32_t DACC1DHR             :12;
					uint32_t                      :16;
			
				//SOOL-DAC_DHR12L1-DECLARATION
			};
			#endif
			
			#ifdef DAC_DHR12L2
			struct DHR12L2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :4;
					uint32_t DACC2DHR             :12;
					uint32_t                      :16;
			
				//SOOL-DAC_DHR12L2-DECLARATION
			};
			#endif
			
			#ifdef DAC_DHR12LD
			struct DHR12LD_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :4;
					uint32_t DACC1DHR             :12;
					uint32_t                      :4;
					uint32_t DAC_DHR12LD_DACC2DHR :12;
			
				//SOOL-DAC_DHR12LD-DECLARATION
			};
			#endif
			
			#ifdef DAC_DHR12R1
			struct DHR12R1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DACC1DHR             :12;
					uint32_t                      :20;
			
				//SOOL-DAC_DHR12R1-DECLARATION
			};
			#endif
			
			#ifdef DAC_DHR12R2
			struct DHR12R2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DACC2DHR             :12;
					uint32_t                      :20;
			
				//SOOL-DAC_DHR12R2-DECLARATION
			};
			#endif
			
			#ifdef DAC_DHR12RD
			struct DHR12RD_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DACC1DHR             :12;
					uint32_t                      :4;
					uint32_t DAC_DHR12RD_DACC2DHR :12;
					uint32_t                      :4;
			
				//SOOL-DAC_DHR12RD-DECLARATION
			};
			#endif
			
			#ifdef DAC_DHR8R1
			struct DHR8R1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DACC1DHR             :8;
					uint32_t                      :24;
			
				//SOOL-DAC_DHR8R1-DECLARATION
			};
			#endif
			
			#ifdef DAC_DHR8R2
			struct DHR8R2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DACC2DHR             :8;
					uint32_t                      :24;
			
				//SOOL-DAC_DHR8R2-DECLARATION
			};
			#endif
			
			#ifdef DAC_DHR8RD
			struct DHR8RD_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DACC1DHR             :8;
					uint32_t DAC_DHR8RD_DACC2DHR  :8;
					uint32_t                      :16;
			
				//SOOL-DAC_DHR8RD-DECLARATION
			};
			#endif
			
			#ifdef DAC_DOR1
			struct DOR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DACC1DOR             :12;
					uint32_t                      :20;
			
				//SOOL-DAC_DOR1-DECLARATION
			};
			#endif
			
			#ifdef DAC_DOR2
			struct DOR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DACC2DOR             :12;
					uint32_t                      :20;
			
				//SOOL-DAC_DOR2-DECLARATION
			};
			#endif
			
			#ifdef DAC_MCR
			struct MCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MODE1                :3;
					uint32_t                      :13;
					uint32_t DAC_MCR_MODE2        :3;
					uint32_t                      :13;
			
				//SOOL-DAC_MCR-DECLARATION
			};
			#endif
			
			#ifdef DAC_SHHR
			struct SHHR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t THOLD1               :10;
					uint32_t                      :6;
					uint32_t DAC_SHHR_THOLD2      :10;
					uint32_t                      :6;
			
				//SOOL-DAC_SHHR-DECLARATION
			};
			#endif
			
			#ifdef DAC_SHRR
			struct SHRR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TREFRESH1            :8;
					uint32_t                      :8;
					uint32_t DAC_SHRR_TREFRESH2   :8;
					uint32_t                      :8;
			
				//SOOL-DAC_SHRR-DECLARATION
			};
			#endif
			
			#ifdef DAC_SHSR1
			struct SHSR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t TSAMPLE1             :10;
						uint32_t                      :22;
					};
					#ifdef DAC_SHSR1_1
					struct
					{
						uint32_t TSAMPLE2             :10;
						uint32_t                      :22;
					};
					#endif
				};
				//SOOL-DAC_SHSR1-DECLARATION
			};
			#endif
			
			#ifdef DAC_SHSR2
			struct SHSR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TSAMPLE2             :10;
					uint32_t                      :22;
			
				//SOOL-DAC_SHSR2-DECLARATION
			};
			#endif
			
			#ifdef DAC_SR
			struct SR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :13;
					uint32_t DMAUDR1              :1;
					uint32_t DAC_SR_CAL_FLAG1     :1;
					uint32_t DAC_SR_BWST1         :1;
					uint32_t                      :13;
					uint32_t DAC_SR_DMAUDR2       :1;
					uint32_t DAC_SR_CAL_FLAG2     :1;
					uint32_t DAC_SR_BWST2         :1;
			
				//SOOL-DAC_SR-DECLARATION
			};
			#endif
			
			#ifdef DAC_SWTRIGR
			struct SWTRIGR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SWTRIG1              :1;
					uint32_t DAC_SWTRIGR_SWTRIG2  :1;
					uint32_t                      :30;
			
				//SOOL-DAC_SWTRIGR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					SWTRIGR_TypeDef SWTRIGR; // @0x004
					DHR12R1_TypeDef DHR12R1; // @0x008
					DHR12L1_TypeDef DHR12L1; // @0x00c
					DHR8R1_TypeDef DHR8R1; // @0x010
					DAC_MAP0_DHR12R2;    // @0x014
					DAC_MAP0_DHR12L2;    // @0x018
					DAC_MAP0_DHR8R2;     // @0x01c
					DAC_MAP0_DHR12RD;    // @0x020
					DAC_MAP0_DHR12LD;    // @0x024
					DAC_MAP0_DHR8RD;     // @0x028
					DOR1_TypeDef DOR1;   // @0x02c
					DAC_MAP0_DOR2;       // @0x030
					DAC_MAP0_SR;         // @0x034
					DAC_MAP0_CCR;        // @0x038
					DAC_MAP0_MCR;        // @0x03c
					DAC_MAP0_SHSR1;      // @0x040
					DAC_MAP0_SHSR2;      // @0x044
					DAC_MAP0_SHHR;       // @0x048
					DAC_MAP0_SHRR;       // @0x04c
				};
			};
			private:
			DAC() = delete;
			//SOOL-DAC-DECLARATION
		};
		
		//region instances
#define DAC1_BASE_ADDR ((uint32_t)0x40007400U)
#if defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F100xB ) ||\
    defined(STM32F100xE ) || defined(STM32F101xE ) || defined(STM32F101xG ) || defined(STM32F103xE ) ||\
    defined(STM32F103xG ) || defined(STM32F105xC ) || defined(STM32F107xC ) || defined(STM32F2     ) ||\
    defined(STM32F3     ) || defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F410Cx ) ||\
    defined(STM32F410Rx ) || defined(STM32F410Tx ) || defined(STM32F413xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32L052xx ) || defined(STM32L053xx ) ||\
    defined(STM32L062xx ) || defined(STM32L063xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) ||\
    defined(STM32L082xx ) || defined(STM32L083xx ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define DAC_BASE_ADDR ((uint32_t)0x40007400U)
#endif

#if defined(STM32F303x8 ) || defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F373xC ) ||\
    defined(STM32F378xx ) 
#define DAC2_BASE_ADDR ((uint32_t)0x40009800U)
#endif

#ifdef DAC1_BASE_ADDR
volatile class DAC * const DAC1 = reinterpret_cast<class DAC* const>(DAC1_BASE_ADDR);
#endif
#ifdef DAC_BASE_ADDR
volatile class DAC * const DAC = reinterpret_cast<class DAC* const>(DAC_BASE_ADDR);
#endif
#ifdef DAC2_BASE_ADDR
volatile class DAC * const DAC2 = reinterpret_cast<class DAC* const>(DAC2_BASE_ADDR);
#endif
//endregion

//SOOL-DAC-DEFINES
//SOOL-DAC-DEFINITION
	};
};//region undef
#undef DAC_CR_0_CEN1
#undef DAC_SR_CAL_FLAG1
#undef DAC_MAP0_CCR
#undef DAC_MAP0_MCR
#undef DAC_MAP0_SHSR1
#undef DAC_MAP0_SHSR2
#undef DAC_MAP0_SHHR
#undef DAC_MAP0_SHRR
#undef DAC_CCR_OTRIM2
#undef DAC_CR_0_CEN2
#undef DAC_MCR_MODE2
#undef DAC_SHHR_THOLD2
#undef DAC_SHRR_TREFRESH2
#undef DAC_SR_CAL_FLAG2
#undef DAC_SR_BWST2
#undef DAC_CR_0_BOFF1
#undef DAC_CR_0_TEN1
#undef DAC_CR_0_TSEL1
#undef DAC_CR_0_WAVE1
#undef DAC_CR_0_MAMP1
#undef DAC_CR_0_DMAUDRIE1
#undef DAC_MAP0_SR
#undef DAC_CR_0_HFSEL
#undef DAC_CR_0_EN2
#undef DAC_CR_0_WAVE2
#undef DAC_CR_0_MAMP2
#undef DAC_CR_0_DMAEN2
#undef DAC_DHR12LD_DACC2DHR
#undef DAC_DHR12RD_DACC2DHR
#undef DAC_DHR8RD_DACC2DHR
#undef DAC_SWTRIGR_SWTRIG2
#undef DAC_CR_0_BOFF2
#undef DAC_CR_0_TEN2
#undef DAC_CR_0_TSEL2
#undef DAC_CR_0_DMAUDRIE2
#undef DAC_CR_1_OUTEN1
#undef DAC_CR_1_OUTEN2
#undef DAC_CR_1_TSEL1
#undef DAC_CR_1_TSEL2
#undef DAC_MAP0_DHR12R2
#undef DAC_MAP0_DHR12L2
#undef DAC_MAP0_DHR8R2
#undef DAC_MAP0_DOR2
#undef DAC_MAP0_DHR12RD
#undef DAC_MAP0_DHR12LD
#undef DAC_MAP0_DHR8RD
#undef DAC_SR_BWST1
#undef DAC_SR_DMAUDR2
//endregion
#endif
#endif
