#ifndef __SOOL_RTC_H
#define __SOOL_RTC_H

#include "peripheral_include.h"
//SOOL-RTC-INCLUDES
//region defines

#if defined(STM32F1     ) 
#define RTC_ALRH
#define RTC_ALRL
#define RTC_CNTH
#define RTC_CNTL
#define RTC_CRH
#define RTC_CRL
#define RTC_DIVH
#define RTC_DIVL
#define RTC_PRLH
#define RTC_PRLL
#define RTC_MAP1_CRH         CRH_TypeDef CRH
#define RTC_MAP1_CRL         CRL_TypeDef CRL
#define RTC_MAP1_PRLH        PRLH_TypeDef PRLH
#define RTC_MAP1_PRLL        PRLL_TypeDef PRLL
#define RTC_MAP1_DIVH        DIVH_TypeDef DIVH
#define RTC_MAP1_DIVL        DIVL_TypeDef DIVL
#define RTC_MAP0_CNTH        CNTH_TypeDef CNTH
#define RTC_MAP1_CNTL        CNTL_TypeDef CNTL
#define RTC_MAP0_ALRH        ALRH_TypeDef ALRH
#define RTC_MAP1_ALRL        ALRL_TypeDef ALRL
#else
#define RTC_MAP1_CRH __SOOL_PERIPH_PADDING_4
#define RTC_MAP1_CRL __SOOL_PERIPH_PADDING_4
#define RTC_MAP1_PRLH __SOOL_PERIPH_PADDING_4
#define RTC_MAP1_PRLL __SOOL_PERIPH_PADDING_4
#define RTC_MAP1_DIVH __SOOL_PERIPH_PADDING_4
#define RTC_MAP1_DIVL __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_CNTH __SOOL_PERIPH_PADDING_4
#define RTC_MAP1_CNTL __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_ALRH __SOOL_PERIPH_PADDING_4
#define RTC_MAP1_ALRL __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F0     ) || defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) ||\
    defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L0     ) || defined(STM32L1     ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
#define RTC_ALRMAR
#define RTC_CR
#define RTC_DR
#define RTC_ISR
#define RTC_PRER
#define RTC_TR
#define RTC_TSDR
#define RTC_TSTR
#define RTC_WPR
#define RTC_MAP0_TR          TR_TypeDef TR
#define RTC_MAP0_DR          DR_TypeDef DR
#define RTC_MAP0_CR          CR_TypeDef CR
#define RTC_MAP0_ISR         ISR_TypeDef ISR
#define RTC_MAP0_PRER        PRER_TypeDef PRER
#define RTC_MAP0_ALRMAR      ALRMAR_TypeDef ALRMAR
#define RTC_MAP0_WPR         WPR_TypeDef WPR
#define RTC_MAP0_TSTR        TSTR_TypeDef TSTR
#define RTC_MAP0_TSDR        TSDR_TypeDef TSDR
#else
#define RTC_MAP0_TR __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_DR __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_CR __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_ISR __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_PRER __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_ALRMAR __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_WPR __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_TSTR __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_TSDR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F0     ) || defined(STM32F3     ) || defined(STM32F4     ) || defined(STM32F7     ) ||\
    defined(STM32H7     ) || defined(STM32L0     ) || defined(STM32L100xBA) || defined(STM32L100xC ) ||\
    defined(STM32L151xBA) || defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) ||\
    defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xBA) || defined(STM32L152xC ) ||\
    defined(STM32L152xCA) || defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) ||\
    defined(STM32L162xC ) || defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) ||\
    defined(STM32L162xE ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define RTC_ALRMASSR
#define RTC_CALR
#define RTC_CR_0_BYPSHAD     BYPSHAD              // 1 bits @ 5
#define RTC_CR_0_COSEL       COSEL                // 1 bits @ 19
#define RTC_ISR_SHPF         SHPF                 // 1 bits @ 3
#define RTC_ISR_TAMP2F       TAMP2F               // 1 bits @ 14
#define RTC_ISR_RECALPF      RECALPF              // 1 bits @ 16
#define RTC_PRER_0_PREDIV_S  PREDIV_S             // 15 bits @ 0
#define RTC_SHIFTR
#define RTC_SSR
#define RTC_TSSSR
#define RTC_MAP0_SSR         SSR_TypeDef SSR
#define RTC_MAP0_SHIFTR      SHIFTR_TypeDef SHIFTR
#define RTC_MAP0_TSSSR       TSSSR_TypeDef TSSSR
#define RTC_MAP0_CALR        CALR_TypeDef CALR
#define RTC_MAP0_ALRMASSR    ALRMASSR_TypeDef ALRMASSR
#else
#define RTC_CR_0_BYPSHAD
#define RTC_CR_0_COSEL
#define RTC_ISR_SHPF
#define RTC_ISR_TAMP2F
#define RTC_ISR_RECALPF
#define RTC_PRER_0_PREDIV_S
#define RTC_MAP0_SSR __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_SHIFTR __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_TSSSR __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_CALR __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_ALRMASSR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) || defined(STM32F7     ) ||\
    defined(STM32H7     ) || defined(STM32L0     ) || defined(STM32L1     ) || defined(STM32L4     ) ||\
    defined(STM32L4P    ) 
#define RTC_ALRMBR
#define RTC_CR_0_ALRBE       ALRBE                // 1 bits @ 9
#define RTC_CR_0_ALRBIE      ALRBIE               // 1 bits @ 13
#define RTC_ISR_ALRBWF       ALRBWF               // 1 bits @ 1
#define RTC_ISR_ALRBF        ALRBF                // 1 bits @ 9
#define RTC_MAP1_ALRMBR      ALRMBR_TypeDef ALRMBR
#else
#define RTC_CR_0_ALRBE
#define RTC_CR_0_ALRBIE
#define RTC_ISR_ALRBWF
#define RTC_ISR_ALRBF
#define RTC_MAP1_ALRMBR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F3     ) || defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32H7     ) ||\
    defined(STM32L0     ) || defined(STM32L100xBA) || defined(STM32L100xC ) || defined(STM32L151xBA) ||\
    defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) || defined(STM32L151xDx) ||\
    defined(STM32L151xE ) || defined(STM32L152xBA) || defined(STM32L152xC ) || defined(STM32L152xCA) ||\
    defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
#define RTC_ALRMBSSR
#define RTC_MAP0_ALRMBSSR    ALRMBSSR_TypeDef ALRMBSSR
#else
#define RTC_MAP0_ALRMBSSR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F031x6 ) || defined(STM32F038xx ) || defined(STM32F042x6 ) || defined(STM32F048xx ) ||\
    defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F2     ) ||\
    defined(STM32F3     ) || defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32H7     ) ||\
    defined(STM32L0     ) || defined(STM32L1     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define RTC_BKP0R
#define RTC_BKP1R
#define RTC_BKP2R
#define RTC_BKP3R
#define RTC_BKP4R
#define RTC_MAP0_BKP0R       uint32_t BKP0R
#define RTC_MAP0_BKP1R       uint32_t BKP1R
#define RTC_MAP0_BKP2R       uint32_t BKP2R
#define RTC_MAP0_BKP3R       uint32_t BKP3R
#define RTC_MAP0_BKP4R       uint32_t BKP4R
#else
#define RTC_MAP0_BKP0R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP1R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP2R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP3R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP4R __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F2     ) || defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) ||\
    defined(STM32F302xE ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) ||\
    defined(STM32F358xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F398xx ) ||\
    defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L151xB ) ||\
    defined(STM32L151xBA) || defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) ||\
    defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xB ) || defined(STM32L152xC ) ||\
    defined(STM32L152xCA) || defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) ||\
    defined(STM32L162xC ) || defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) ||\
    defined(STM32L162xE ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define RTC_BKP10R
#define RTC_BKP11R
#define RTC_BKP12R
#define RTC_BKP13R
#define RTC_BKP14R
#define RTC_BKP15R
#define RTC_BKP5R
#define RTC_BKP6R
#define RTC_BKP7R
#define RTC_BKP8R
#define RTC_BKP9R
#define RTC_MAP0_BKP5R       uint32_t BKP5R
#define RTC_MAP0_BKP6R       uint32_t BKP6R
#define RTC_MAP0_BKP7R       uint32_t BKP7R
#define RTC_MAP0_BKP8R       uint32_t BKP8R
#define RTC_MAP0_BKP9R       uint32_t BKP9R
#define RTC_MAP0_BKP10R      uint32_t BKP10R
#define RTC_MAP0_BKP11R      uint32_t BKP11R
#define RTC_MAP0_BKP12R      uint32_t BKP12R
#define RTC_MAP0_BKP13R      uint32_t BKP13R
#define RTC_MAP0_BKP14R      uint32_t BKP14R
#define RTC_MAP0_BKP15R      uint32_t BKP15R
#else
#define RTC_MAP0_BKP5R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP6R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP7R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP8R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP9R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP10R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP11R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP12R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP13R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP14R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP15R __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F2     ) || defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F318xx ) ||\
    defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F4     ) || defined(STM32F7     ) ||\
    defined(STM32H7     ) || defined(STM32L151xB ) || defined(STM32L151xBA) || defined(STM32L151xC ) ||\
    defined(STM32L151xCA) || defined(STM32L151xD ) || defined(STM32L151xDx) || defined(STM32L151xE ) ||\
    defined(STM32L152xB ) || defined(STM32L152xC ) || defined(STM32L152xCA) || defined(STM32L152xD ) ||\
    defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) || defined(STM32L162xCA) ||\
    defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) || defined(STM32L4     ) ||\
    defined(STM32L4P    ) 
#define RTC_BKP16R
#define RTC_BKP17R
#define RTC_BKP18R
#define RTC_BKP19R
#define RTC_MAP0_BKP16R      uint32_t BKP16R
#define RTC_MAP0_BKP17R      uint32_t BKP17R
#define RTC_MAP0_BKP18R      uint32_t BKP18R
#define RTC_MAP0_BKP19R      uint32_t BKP19R
#else
#define RTC_MAP0_BKP16R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP17R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP18R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP19R __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F7     ) || defined(STM32H7     ) ||\
    defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) || defined(STM32L151xDx) ||\
    defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) || defined(STM32L152xD ) ||\
    defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) || defined(STM32L162xCA) ||\
    defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) || defined(STM32L4     ) ||\
    defined(STM32L4P    ) 
#define RTC_BKP20R
#define RTC_BKP21R
#define RTC_BKP22R
#define RTC_BKP23R
#define RTC_BKP24R
#define RTC_BKP25R
#define RTC_BKP26R
#define RTC_BKP27R
#define RTC_BKP28R
#define RTC_BKP29R
#define RTC_BKP30R
#define RTC_BKP31R
#define RTC_MAP0_BKP20R      uint32_t BKP20R
#define RTC_MAP0_BKP21R      uint32_t BKP21R
#define RTC_MAP0_BKP22R      uint32_t BKP22R
#define RTC_MAP0_BKP23R      uint32_t BKP23R
#define RTC_MAP0_BKP24R      uint32_t BKP24R
#define RTC_MAP0_BKP25R      uint32_t BKP25R
#define RTC_MAP0_BKP26R      uint32_t BKP26R
#define RTC_MAP0_BKP27R      uint32_t BKP27R
#define RTC_MAP0_BKP28R      uint32_t BKP28R
#define RTC_MAP0_BKP29R      uint32_t BKP29R
#define RTC_MAP0_BKP30R      uint32_t BKP30R
#define RTC_MAP0_BKP31R      uint32_t BKP31R
#else
#define RTC_MAP0_BKP20R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP21R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP22R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP23R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP24R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP25R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP26R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP27R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP28R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP29R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP30R __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_BKP31R __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F2     ) || defined(STM32F4     ) || defined(STM32L1     ) 
#define RTC_CALIBR
#define RTC_CR_0_DCE         DCE                  // 1 bits @ 7
#define RTC_MAP1_CALIBR      CALIBR_TypeDef CALIBR
#else
#define RTC_CR_0_DCE
#define RTC_MAP1_CALIBR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F030xC ) || defined(STM32F070xB ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F2     ) ||\
    defined(STM32F3     ) || defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32H7     ) ||\
    defined(STM32L0     ) || defined(STM32L1     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define RTC_CR_0_WUCKSEL     WUCKSEL              // 3 bits @ 0
#define RTC_CR_0_WUTE        WUTE                 // 1 bits @ 10
#define RTC_CR_0_WUTIE       WUTIE                // 1 bits @ 14
#define RTC_ISR_WUTWF        WUTWF                // 1 bits @ 2
#define RTC_ISR_WUTF         WUTF                 // 1 bits @ 10
#define RTC_WUTR
#define RTC_MAP0_WUTR        WUTR_TypeDef WUTR
#else
#define RTC_CR_0_WUCKSEL
#define RTC_CR_0_WUTE
#define RTC_CR_0_WUTIE
#define RTC_ISR_WUTWF
#define RTC_ISR_WUTF
#define RTC_MAP0_WUTR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F0     ) || defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) ||\
    defined(STM32F7     ) || defined(STM32L1     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define RTC_CR_0_BKP         BKP                  // 1 bits @ 18
#else
#define RTC_CR_0_BKP
#endif

#if defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define RTC_CR_0_ITSE        ITSE                 // 1 bits @ 24
#define RTC_ISR_ITSF         ITSF                 // 1 bits @ 17
#else
#define RTC_CR_0_ITSE
#define RTC_ISR_ITSF
#endif

#if defined(STM32F0     ) || defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) ||\
    defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L031xx ) || defined(STM32L041xx ) ||\
    defined(STM32L051xx ) || defined(STM32L052xx ) || defined(STM32L053xx ) || defined(STM32L061xx ) ||\
    defined(STM32L062xx ) || defined(STM32L063xx ) || defined(STM32L071xx ) || defined(STM32L072xx ) ||\
    defined(STM32L073xx ) || defined(STM32L081xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) ||\
    defined(STM32L1     ) || defined(STM32L431xx ) || defined(STM32L433xx ) || defined(STM32L443xx ) ||\
    defined(STM32L451xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L471xx ) ||\
    defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define RTC_ISR_TAMP1F       TAMP1F               // 1 bits @ 13
#else
#define RTC_ISR_TAMP1F
#endif

#if defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) ||\
    defined(STM32F098xx ) || defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F358xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) ||\
    defined(STM32F398xx ) || defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L011xx ) ||\
    defined(STM32L021xx ) || defined(STM32L031xx ) || defined(STM32L041xx ) || defined(STM32L071xx ) ||\
    defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L081xx ) || defined(STM32L082xx ) ||\
    defined(STM32L083xx ) || defined(STM32L100xBA) || defined(STM32L100xC ) || defined(STM32L151xBA) ||\
    defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) || defined(STM32L151xDx) ||\
    defined(STM32L151xE ) || defined(STM32L152xBA) || defined(STM32L152xC ) || defined(STM32L152xCA) ||\
    defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) ||\
    defined(STM32L431xx ) || defined(STM32L433xx ) || defined(STM32L443xx ) || defined(STM32L451xx ) ||\
    defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L471xx ) || defined(STM32L475xx ) ||\
    defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define RTC_ISR_TAMP3F       TAMP3F               // 1 bits @ 15
#else
#define RTC_ISR_TAMP3F
#endif

#if defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L0     ) || defined(STM32L4     ) ||\
    defined(STM32L4P    ) 
#define RTC_OR
#define RTC_TAMPCR
#define RTC_MAP1_TAMPCR      TAMPCR_TypeDef TAMPCR
#define RTC_MAP0_OR          OR_TypeDef OR
#else
#define RTC_MAP1_TAMPCR __SOOL_PERIPH_PADDING_4
#define RTC_MAP0_OR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F7     ) 
#define RTC_OR_0
#define RTC_OR_1_ALARMTYPE   ALARMTYPE            // 1 bits @ 3
#else
#define RTC_OR_1_ALARMTYPE
#endif

#if defined(STM32H7     ) || defined(STM32L0     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define RTC_OR_1_ALARMOUTTYPE ALARMOUTTYPE         // 1 bits @ 0
#define RTC_OR_1_OUT_RMP     OUT_RMP              // 1 bits @ 1
#else
#define RTC_OR_1_ALARMOUTTYPE
#define RTC_OR_1_OUT_RMP
#endif

#if defined(STM32F2     ) || defined(STM32L100xB ) || defined(STM32L151xB ) || defined(STM32L152xB ) 
#define RTC_PRER_1
#endif

#if defined(STM32F0     ) || defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) ||\
    defined(STM32L1     ) 
#define RTC_TAFCR
#define RTC_MAP0_TAFCR       TAFCR_TypeDef TAFCR
#else
#define RTC_MAP0_TAFCR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F0     ) || defined(STM32F3     ) || defined(STM32F4     ) || defined(STM32L100xBA) ||\
    defined(STM32L100xC ) || defined(STM32L151xBA) || defined(STM32L151xC ) || defined(STM32L151xCA) ||\
    defined(STM32L151xD ) || defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xBA) ||\
    defined(STM32L152xC ) || defined(STM32L152xCA) || defined(STM32L152xD ) || defined(STM32L152xDx) ||\
    defined(STM32L152xE ) || defined(STM32L162xC ) || defined(STM32L162xCA) || defined(STM32L162xD ) ||\
    defined(STM32L162xDx) || defined(STM32L162xE ) 
#define RTC_TAFCR_0_TAMP2E   TAMP2E               // 1 bits @ 3
#define RTC_TAFCR_0_TAMP2TRG TAMP2TRG             // 1 bits @ 4
#define RTC_TAFCR_0_TAMPTS   TAMPTS               // 1 bits @ 7
#define RTC_TAFCR_0_TAMPFREQ TAMPFREQ             // 3 bits @ 8
#define RTC_TAFCR_0_TAMPFLT  TAMPFLT              // 2 bits @ 11
#define RTC_TAFCR_0_TAMPPRCH TAMPPRCH             // 2 bits @ 13
#define RTC_TAFCR_0_TAMPPUDIS TAMPPUDIS            // 1 bits @ 15
#else
#define RTC_TAFCR_0_TAMP2E
#define RTC_TAFCR_0_TAMP2TRG
#define RTC_TAFCR_0_TAMPTS
#define RTC_TAFCR_0_TAMPFREQ
#define RTC_TAFCR_0_TAMPFLT
#define RTC_TAFCR_0_TAMPPRCH
#define RTC_TAFCR_0_TAMPPUDIS
#endif

#if defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) ||\
    defined(STM32F098xx ) || defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F358xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) ||\
    defined(STM32F398xx ) || defined(STM32L100xBA) || defined(STM32L100xC ) || defined(STM32L151xBA) ||\
    defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) || defined(STM32L151xDx) ||\
    defined(STM32L151xE ) || defined(STM32L152xBA) || defined(STM32L152xC ) || defined(STM32L152xCA) ||\
    defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define RTC_TAFCR_0_TAMP3E   TAMP3E               // 1 bits @ 5
#define RTC_TAFCR_0_TAMP3TRG TAMP3TRG             // 1 bits @ 6
#else
#define RTC_TAFCR_0_TAMP3E
#define RTC_TAFCR_0_TAMP3TRG
#endif

#if defined(STM32F2     ) || defined(STM32F4     ) 
#define RTC_TAFCR_0_TAMP1INSEL TAMP1INSEL           // 1 bits @ 16
#define RTC_TAFCR_0_TSINSEL  TSINSEL              // 1 bits @ 17
#define RTC_TAFCR_1_TAMPINSEL TAMPINSEL            // 1 bits @ 16
#else
#define RTC_TAFCR_0_TAMP1INSEL
#define RTC_TAFCR_0_TSINSEL
#define RTC_TAFCR_1_TAMPINSEL
#endif

#if defined(STM32F0     ) || defined(STM32F3     ) 
#define RTC_TAFCR_0_PC13VALUE PC13VALUE            // 1 bits @ 18
#define RTC_TAFCR_0_PC13MODE PC13MODE             // 1 bits @ 19
#define RTC_TAFCR_0_PC14VALUE PC14VALUE            // 1 bits @ 20
#define RTC_TAFCR_0_PC14MODE PC14MODE             // 1 bits @ 21
#define RTC_TAFCR_0_PC15VALUE PC15VALUE            // 1 bits @ 22
#define RTC_TAFCR_0_PC15MODE PC15MODE             // 1 bits @ 23
#else
#define RTC_TAFCR_0_PC13VALUE
#define RTC_TAFCR_0_PC13MODE
#define RTC_TAFCR_0_PC14VALUE
#define RTC_TAFCR_0_PC14MODE
#define RTC_TAFCR_0_PC15VALUE
#define RTC_TAFCR_0_PC15MODE
#endif

#if defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L031xx ) || defined(STM32L041xx ) ||\
    defined(STM32L051xx ) || defined(STM32L052xx ) || defined(STM32L053xx ) || defined(STM32L061xx ) ||\
    defined(STM32L062xx ) || defined(STM32L063xx ) || defined(STM32L071xx ) || defined(STM32L072xx ) ||\
    defined(STM32L073xx ) || defined(STM32L081xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) ||\
    defined(STM32L431xx ) || defined(STM32L433xx ) || defined(STM32L443xx ) || defined(STM32L451xx ) ||\
    defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L471xx ) || defined(STM32L475xx ) ||\
    defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define RTC_TAMPCR_0_TAMP1E  TAMP1E               // 1 bits @ 0
#define RTC_TAMPCR_0_TAMP1IE TAMP1IE              // 1 bits @ 16
#define RTC_TAMPCR_0_TAMP1NOERASE TAMP1NOERASE         // 1 bits @ 17
#define RTC_TAMPCR_0_TAMP1MF TAMP1MF              // 1 bits @ 18
#else
#define RTC_TAMPCR_0_TAMP1E
#define RTC_TAMPCR_0_TAMP1IE
#define RTC_TAMPCR_0_TAMP1NOERASE
#define RTC_TAMPCR_0_TAMP1MF
#endif

#if defined(STM32F7     ) || defined(STM32L031xx ) || defined(STM32L041xx ) || defined(STM32L051xx ) ||\
    defined(STM32L052xx ) || defined(STM32L053xx ) || defined(STM32L061xx ) || defined(STM32L062xx ) ||\
    defined(STM32L063xx ) || defined(STM32L071xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) ||\
    defined(STM32L081xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) || defined(STM32L431xx ) ||\
    defined(STM32L433xx ) || defined(STM32L443xx ) || defined(STM32L451xx ) || defined(STM32L452xx ) ||\
    defined(STM32L462xx ) || defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) ||\
    defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) ||\
    defined(STM32L4P    ) 
#define RTC_TAMPCR_0_TAMP1TRG TAMP1TRG             // 1 bits @ 1
#else
#define RTC_TAMPCR_0_TAMP1TRG
#endif

#if defined(STM32F7     ) || defined(STM32L0     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define RTC_TAMPCR_0_TAMP2TRG TAMP2TRG             // 1 bits @ 4
#else
#define RTC_TAMPCR_0_TAMP2TRG
#endif

#if defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L011xx ) || defined(STM32L021xx ) ||\
    defined(STM32L031xx ) || defined(STM32L041xx ) || defined(STM32L071xx ) || defined(STM32L072xx ) ||\
    defined(STM32L073xx ) || defined(STM32L081xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) ||\
    defined(STM32L431xx ) || defined(STM32L433xx ) || defined(STM32L443xx ) || defined(STM32L451xx ) ||\
    defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L471xx ) || defined(STM32L475xx ) ||\
    defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define RTC_TAMPCR_0_TAMP3E  TAMP3E               // 1 bits @ 5
#define RTC_TAMPCR_0_TAMP3IE TAMP3IE              // 1 bits @ 22
#define RTC_TAMPCR_0_TAMP3NOERASE TAMP3NOERASE         // 1 bits @ 23
#define RTC_TAMPCR_0_TAMP3MF TAMP3MF              // 1 bits @ 24
#else
#define RTC_TAMPCR_0_TAMP3E
#define RTC_TAMPCR_0_TAMP3IE
#define RTC_TAMPCR_0_TAMP3NOERASE
#define RTC_TAMPCR_0_TAMP3MF
#endif

#if defined(STM32F7     ) || defined(STM32L011xx ) || defined(STM32L021xx ) || defined(STM32L031xx ) ||\
    defined(STM32L041xx ) || defined(STM32L071xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) ||\
    defined(STM32L081xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) || defined(STM32L431xx ) ||\
    defined(STM32L433xx ) || defined(STM32L443xx ) || defined(STM32L451xx ) || defined(STM32L452xx ) ||\
    defined(STM32L462xx ) || defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) ||\
    defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) ||\
    defined(STM32L4P    ) 
#define RTC_TAMPCR_0_TAMP3TRG TAMP3TRG             // 1 bits @ 6
#else
#define RTC_TAMPCR_0_TAMP3TRG
#endif

#if defined(STM32F745xx ) || defined(STM32F746xx ) || defined(STM32F756xx ) || defined(STM32H7     ) 
#define RTC_TAMPCR_1
#endif

//endregion

namespace sool
{
	namespace core
	{
		class RTC
		{
			//SOOL-RTC-ENUMS
			
			public :
			
			#ifdef RTC_ALRH
			struct ALRH_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RTC_ALR              :16;
					uint32_t                      :16;
			
				//SOOL-RTC_ALRH-DECLARATION
			};
			#endif
			
			#ifdef RTC_ALRL
			struct ALRL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RTC_ALR              :16;
					uint32_t                      :16;
			
				//SOOL-RTC_ALRL-DECLARATION
			};
			#endif
			
			#ifdef RTC_ALRMAR
			struct ALRMAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SU                   :4;
					uint32_t ST                   :3;
					uint32_t MSK1                 :1;
					uint32_t MNU                  :4;
					uint32_t MNT                  :3;
					uint32_t MSK2                 :1;
					uint32_t HU                   :4;
					uint32_t HT                   :2;
					uint32_t PM                   :1;
					uint32_t MSK3                 :1;
					uint32_t DU                   :4;
					uint32_t DT                   :2;
					uint32_t WDSEL                :1;
					uint32_t MSK4                 :1;
			
				//SOOL-RTC_ALRMAR-DECLARATION
			};
			#endif
			
			#ifdef RTC_ALRMASSR
			struct ALRMASSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SS                   :15;
					uint32_t                      :9;
					uint32_t MASKSS               :4;
					uint32_t                      :4;
			
				//SOOL-RTC_ALRMASSR-DECLARATION
			};
			#endif
			
			#ifdef RTC_ALRMBR
			struct ALRMBR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SU                   :4;
					uint32_t ST                   :3;
					uint32_t MSK1                 :1;
					uint32_t MNU                  :4;
					uint32_t MNT                  :3;
					uint32_t MSK2                 :1;
					uint32_t HU                   :4;
					uint32_t HT                   :2;
					uint32_t PM                   :1;
					uint32_t MSK3                 :1;
					uint32_t DU                   :4;
					uint32_t DT                   :2;
					uint32_t WDSEL                :1;
					uint32_t MSK4                 :1;
			
				//SOOL-RTC_ALRMBR-DECLARATION
			};
			#endif
			
			#ifdef RTC_ALRMBSSR
			struct ALRMBSSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SS                   :15;
					uint32_t                      :9;
					uint32_t MASKSS               :4;
					uint32_t                      :4;
			
				//SOOL-RTC_ALRMBSSR-DECLARATION
			};
			#endif
			
			#ifdef RTC_CALIBR
			struct CALIBR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DC                   :5;
					uint32_t                      :2;
					uint32_t DCS                  :1;
					uint32_t                      :24;
			
				//SOOL-RTC_CALIBR-DECLARATION
			};
			#endif
			
			#ifdef RTC_CALR
			struct CALR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CALM                 :9;
					uint32_t                      :4;
					uint32_t CALW16               :1;
					uint32_t CALW8                :1;
					uint32_t CALP                 :1;
					uint32_t                      :16;
			
				//SOOL-RTC_CALR-DECLARATION
			};
			#endif
			
			#ifdef RTC_CNTH
			struct CNTH_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RTC_CNT              :16;
					uint32_t                      :16;
			
				//SOOL-RTC_CNTH-DECLARATION
			};
			#endif
			
			#ifdef RTC_CNTL
			struct CNTL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RTC_CNT              :16;
					uint32_t                      :16;
			
				//SOOL-RTC_CNTL-DECLARATION
			};
			#endif
			
			#ifdef RTC_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t RTC_CR_0_WUCKSEL     :3;
						uint32_t TSEDGE               :1;
						uint32_t REFCKON              :1;
						uint32_t RTC_CR_0_BYPSHAD     :1;
						uint32_t FMT                  :1;
						uint32_t RTC_CR_0_DCE         :1;
						uint32_t ALRAE                :1;
						uint32_t RTC_CR_0_ALRBE       :1;
						uint32_t RTC_CR_0_WUTE        :1;
						uint32_t TSE                  :1;
						uint32_t ALRAIE               :1;
						uint32_t RTC_CR_0_ALRBIE      :1;
						uint32_t RTC_CR_0_WUTIE       :1;
						uint32_t TSIE                 :1;
						uint32_t ADD1H                :1;
						uint32_t SUB1H                :1;
						uint32_t RTC_CR_0_BKP         :1;
						uint32_t RTC_CR_0_COSEL       :1;
						uint32_t POL                  :1;
						uint32_t OSEL                 :2;
						uint32_t COE                  :1;
						uint32_t RTC_CR_0_ITSE        :1;
						uint32_t                      :7;
					};
					struct
					{
						uint32_t                      :18;
						uint32_t BCK                  :1;
						uint32_t                      :13;
					};
				};
				//SOOL-RTC_CR-DECLARATION
			};
			#endif
			
			#ifdef RTC_CRH
			struct CRH_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SECIE                :1;
					uint32_t ALRIE                :1;
					uint32_t OWIE                 :1;
					uint32_t                      :29;
			
				//SOOL-RTC_CRH-DECLARATION
			};
			#endif
			
			#ifdef RTC_CRL
			struct CRL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SECF                 :1;
					uint32_t ALRF                 :1;
					uint32_t OWF                  :1;
					uint32_t RSF                  :1;
					uint32_t CNF                  :1;
					uint32_t RTOFF                :1;
					uint32_t                      :26;
			
				//SOOL-RTC_CRL-DECLARATION
			};
			#endif
			
			#ifdef RTC_DIVH
			struct DIVH_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RTC_DIV              :4;
					uint32_t                      :28;
			
				//SOOL-RTC_DIVH-DECLARATION
			};
			#endif
			
			#ifdef RTC_DIVL
			struct DIVL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RTC_DIV              :16;
					uint32_t                      :16;
			
				//SOOL-RTC_DIVL-DECLARATION
			};
			#endif
			
			#ifdef RTC_DR
			struct DR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DU                   :4;
					uint32_t DT                   :2;
					uint32_t                      :2;
					uint32_t MU                   :4;
					uint32_t MT                   :1;
					uint32_t WDU                  :3;
					uint32_t YU                   :4;
					uint32_t YT                   :4;
					uint32_t                      :8;
			
				//SOOL-RTC_DR-DECLARATION
			};
			#endif
			
			#ifdef RTC_ISR
			struct ISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ALRAWF               :1;
					uint32_t RTC_ISR_ALRBWF       :1;
					uint32_t RTC_ISR_WUTWF        :1;
					uint32_t RTC_ISR_SHPF         :1;
					uint32_t INITS                :1;
					uint32_t RSF                  :1;
					uint32_t INITF                :1;
					uint32_t INIT                 :1;
					uint32_t ALRAF                :1;
					uint32_t RTC_ISR_ALRBF        :1;
					uint32_t RTC_ISR_WUTF         :1;
					uint32_t TSF                  :1;
					uint32_t TSOVF                :1;
					uint32_t RTC_ISR_TAMP1F       :1;
					uint32_t RTC_ISR_TAMP2F       :1;
					uint32_t RTC_ISR_TAMP3F       :1;
					uint32_t RTC_ISR_RECALPF      :1;
					uint32_t RTC_ISR_ITSF         :1;
					uint32_t                      :14;
			
				//SOOL-RTC_ISR-DECLARATION
			};
			#endif
			
			#ifdef RTC_OR
			struct OR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef RTC_OR_0
					struct
					{
						uint32_t                      :1;
						uint32_t TSINSEL              :2;
						uint32_t ALARMOUTTYPE         :1;
						uint32_t                      :28;
					};
					#endif
					struct
					{
						uint32_t RTC_OR_1_ALARMOUTTYPE :1;
						uint32_t RTC_OR_1_OUT_RMP     :1;
						uint32_t                      :1;
						uint32_t RTC_OR_1_ALARMTYPE   :1;
						uint32_t                      :28;
					};
				};
				//SOOL-RTC_OR-DECLARATION
			};
			#endif
			
			#ifdef RTC_PRER
			struct PRER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t RTC_PRER_0_PREDIV_S  :15;
						uint32_t                      :1;
						uint32_t PREDIV_A             :7;
						uint32_t                      :9;
					};
					#ifdef RTC_PRER_1
					struct
					{
						uint32_t PREDIV_S             :13;
						uint32_t                      :19;
					};
					#endif
				};
				//SOOL-RTC_PRER-DECLARATION
			};
			#endif
			
			#ifdef RTC_PRLH
			struct PRLH_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PRL                  :4;
					uint32_t                      :28;
			
				//SOOL-RTC_PRLH-DECLARATION
			};
			#endif
			
			#ifdef RTC_PRLL
			struct PRLL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PRL                  :16;
					uint32_t                      :16;
			
				//SOOL-RTC_PRLL-DECLARATION
			};
			#endif
			
			#ifdef RTC_SHIFTR
			struct SHIFTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SUBFS                :15;
					uint32_t                      :16;
					uint32_t ADD1S                :1;
			
				//SOOL-RTC_SHIFTR-DECLARATION
			};
			#endif
			
			#ifdef RTC_SSR
			struct SSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SS                   :16;
					uint32_t                      :16;
			
				//SOOL-RTC_SSR-DECLARATION
			};
			#endif
			
			#ifdef RTC_TAFCR
			struct TAFCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t TAMP1E               :1;
						uint32_t TAMP1TRG             :1;
						uint32_t TAMPIE               :1;
						uint32_t RTC_TAFCR_0_TAMP2E   :1;
						uint32_t RTC_TAFCR_0_TAMP2TRG :1;
						uint32_t RTC_TAFCR_0_TAMP3E   :1;
						uint32_t RTC_TAFCR_0_TAMP3TRG :1;
						uint32_t RTC_TAFCR_0_TAMPTS   :1;
						uint32_t RTC_TAFCR_0_TAMPFREQ :3;
						uint32_t RTC_TAFCR_0_TAMPFLT  :2;
						uint32_t RTC_TAFCR_0_TAMPPRCH :2;
						uint32_t RTC_TAFCR_0_TAMPPUDIS :1;
						uint32_t RTC_TAFCR_0_TAMP1INSEL :1;
						uint32_t RTC_TAFCR_0_TSINSEL  :1;
						uint32_t RTC_TAFCR_0_PC13VALUE :1;
						uint32_t RTC_TAFCR_0_PC13MODE :1;
						uint32_t RTC_TAFCR_0_PC14VALUE :1;
						uint32_t RTC_TAFCR_0_PC14MODE :1;
						uint32_t RTC_TAFCR_0_PC15VALUE :1;
						uint32_t RTC_TAFCR_0_PC15MODE :1;
						uint32_t                      :8;
					};
					struct
					{
						uint32_t                      :16;
						uint32_t RTC_TAFCR_1_TAMPINSEL :1;
						uint32_t                      :1;
						uint32_t ALARMOUTTYPE         :1;
						uint32_t                      :13;
					};
				};
				//SOOL-RTC_TAFCR-DECLARATION
			};
			#endif
			
			#ifdef RTC_TAMPCR
			struct TAMPCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t RTC_TAMPCR_0_TAMP1E  :1;
						uint32_t RTC_TAMPCR_0_TAMP1TRG :1;
						uint32_t TAMPIE               :1;
						uint32_t TAMP2E               :1;
						uint32_t RTC_TAMPCR_0_TAMP2TRG :1;
						uint32_t RTC_TAMPCR_0_TAMP3E  :1;
						uint32_t RTC_TAMPCR_0_TAMP3TRG :1;
						uint32_t TAMPTS               :1;
						uint32_t TAMPFREQ             :3;
						uint32_t TAMPFLT              :2;
						uint32_t TAMPPRCH             :2;
						uint32_t TAMPPUDIS            :1;
						uint32_t RTC_TAMPCR_0_TAMP1IE :1;
						uint32_t RTC_TAMPCR_0_TAMP1NOERASE :1;
						uint32_t RTC_TAMPCR_0_TAMP1MF :1;
						uint32_t TAMP2IE              :1;
						uint32_t TAMP2NOERASE         :1;
						uint32_t TAMP2MF              :1;
						uint32_t RTC_TAMPCR_0_TAMP3IE :1;
						uint32_t RTC_TAMPCR_0_TAMP3NOERASE :1;
						uint32_t RTC_TAMPCR_0_TAMP3MF :1;
						uint32_t                      :7;
					};
					#ifdef RTC_TAMPCR_1
					struct
					{
						uint32_t                      :1;
						uint32_t TAMP1_TRG            :1;
						uint32_t                      :2;
						uint32_t TAMP2_TRG            :1;
						uint32_t                      :1;
						uint32_t TAMP3_TRG            :1;
						uint32_t                      :25;
					};
					#endif
				};
				//SOOL-RTC_TAMPCR-DECLARATION
			};
			#endif
			
			#ifdef RTC_TR
			struct TR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SU                   :4;
					uint32_t ST                   :3;
					uint32_t                      :1;
					uint32_t MNU                  :4;
					uint32_t MNT                  :3;
					uint32_t                      :1;
					uint32_t HU                   :4;
					uint32_t HT                   :2;
					uint32_t PM                   :1;
					uint32_t                      :9;
			
				//SOOL-RTC_TR-DECLARATION
			};
			#endif
			
			#ifdef RTC_TSDR
			struct TSDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DU                   :4;
					uint32_t DT                   :2;
					uint32_t                      :2;
					uint32_t MU                   :4;
					uint32_t MT                   :1;
					uint32_t WDU                  :3;
					uint32_t                      :16;
			
				//SOOL-RTC_TSDR-DECLARATION
			};
			#endif
			
			#ifdef RTC_TSSSR
			struct TSSSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SS                   :16;
					uint32_t                      :16;
			
				//SOOL-RTC_TSSSR-DECLARATION
			};
			#endif
			
			#ifdef RTC_TSTR
			struct TSTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SU                   :4;
					uint32_t ST                   :3;
					uint32_t                      :1;
					uint32_t MNU                  :4;
					uint32_t MNT                  :3;
					uint32_t                      :1;
					uint32_t HU                   :4;
					uint32_t HT                   :2;
					uint32_t PM                   :1;
					uint32_t                      :9;
			
				//SOOL-RTC_TSTR-DECLARATION
			};
			#endif
			
			#ifdef RTC_WPR
			struct WPR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t KEY                  :8;
					uint32_t                      :24;
			
				//SOOL-RTC_WPR-DECLARATION
			};
			#endif
			
			#ifdef RTC_WUTR
			struct WUTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t WUT                  :16;
					uint32_t                      :16;
			
				//SOOL-RTC_WUTR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					RTC_MAP0_TR;         // @0x000
					RTC_MAP0_DR;         // @0x004
					RTC_MAP0_CR;         // @0x008
					RTC_MAP0_ISR;        // @0x00c
					RTC_MAP0_PRER;       // @0x010
					RTC_MAP0_WUTR;       // @0x014
					RTC_MAP0_CNTH;       // @0x018
					RTC_MAP0_ALRMAR;     // @0x01c
					RTC_MAP0_ALRH;       // @0x020
					RTC_MAP0_WPR;        // @0x024
					RTC_MAP0_SSR;        // @0x028
					RTC_MAP0_SHIFTR;     // @0x02c
					RTC_MAP0_TSTR;       // @0x030
					RTC_MAP0_TSDR;       // @0x034
					RTC_MAP0_TSSSR;      // @0x038
					RTC_MAP0_CALR;       // @0x03c
					RTC_MAP0_TAFCR;      // @0x040
					RTC_MAP0_ALRMASSR;   // @0x044
					RTC_MAP0_ALRMBSSR;   // @0x048
					RTC_MAP0_OR;         // @0x04c
					RTC_MAP0_BKP0R;      // @0x050
					RTC_MAP0_BKP1R;      // @0x054
					RTC_MAP0_BKP2R;      // @0x058
					RTC_MAP0_BKP3R;      // @0x05c
					RTC_MAP0_BKP4R;      // @0x060
					RTC_MAP0_BKP5R;      // @0x064
					RTC_MAP0_BKP6R;      // @0x068
					RTC_MAP0_BKP7R;      // @0x06c
					RTC_MAP0_BKP8R;      // @0x070
					RTC_MAP0_BKP9R;      // @0x074
					RTC_MAP0_BKP10R;     // @0x078
					RTC_MAP0_BKP11R;     // @0x07c
					RTC_MAP0_BKP12R;     // @0x080
					RTC_MAP0_BKP13R;     // @0x084
					RTC_MAP0_BKP14R;     // @0x088
					RTC_MAP0_BKP15R;     // @0x08c
					RTC_MAP0_BKP16R;     // @0x090
					RTC_MAP0_BKP17R;     // @0x094
					RTC_MAP0_BKP18R;     // @0x098
					RTC_MAP0_BKP19R;     // @0x09c
					RTC_MAP0_BKP20R;     // @0x0a0
					RTC_MAP0_BKP21R;     // @0x0a4
					RTC_MAP0_BKP22R;     // @0x0a8
					RTC_MAP0_BKP23R;     // @0x0ac
					RTC_MAP0_BKP24R;     // @0x0b0
					RTC_MAP0_BKP25R;     // @0x0b4
					RTC_MAP0_BKP26R;     // @0x0b8
					RTC_MAP0_BKP27R;     // @0x0bc
					RTC_MAP0_BKP28R;     // @0x0c0
					RTC_MAP0_BKP29R;     // @0x0c4
					RTC_MAP0_BKP30R;     // @0x0c8
					RTC_MAP0_BKP31R;     // @0x0cc
				};
				struct
				{
					RTC_MAP1_CRH;        // @0x000
					RTC_MAP1_CRL;        // @0x004
					RTC_MAP1_PRLH;       // @0x008
					RTC_MAP1_PRLL;       // @0x00c
					RTC_MAP1_DIVH;       // @0x010
					RTC_MAP1_DIVL;       // @0x014
					RTC_MAP1_CALIBR;     // @0x018
					RTC_MAP1_CNTL;       // @0x01c
					RTC_MAP1_ALRMBR;     // @0x020
					RTC_MAP1_ALRL;       // @0x024
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					RTC_MAP1_TAMPCR;     // @0x040
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
				};
			};
			private:
			RTC() = delete;
			//SOOL-RTC-DECLARATION
		};
		
		//region instances
#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F2     ) || defined(STM32F3     ) ||\
    defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L0     ) || defined(STM32L1     ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
#define RTC_BASE_ADDR ((uint32_t)0x40002800U)
#endif

#if defined(STM32H7     ) 
#define RTC_BASE_ADDR ((uint32_t)0x58004000U)
#endif

#ifdef RTC_BASE_ADDR
volatile class RTC * const RTC = reinterpret_cast<class RTC* const>(RTC_BASE_ADDR);
#endif
//endregion

//SOOL-RTC-DEFINES
//SOOL-RTC-DEFINITION
	};
};//region undef
#undef RTC_MAP1_CRH
#undef RTC_MAP1_CRL
#undef RTC_MAP1_PRLH
#undef RTC_MAP1_PRLL
#undef RTC_MAP1_DIVH
#undef RTC_MAP1_DIVL
#undef RTC_MAP0_CNTH
#undef RTC_MAP1_CNTL
#undef RTC_MAP0_ALRH
#undef RTC_MAP1_ALRL
#undef RTC_MAP0_TR
#undef RTC_MAP0_DR
#undef RTC_MAP0_CR
#undef RTC_MAP0_ISR
#undef RTC_MAP0_PRER
#undef RTC_MAP0_ALRMAR
#undef RTC_MAP0_WPR
#undef RTC_MAP0_TSTR
#undef RTC_MAP0_TSDR
#undef RTC_CR_0_BYPSHAD
#undef RTC_CR_0_COSEL
#undef RTC_ISR_SHPF
#undef RTC_ISR_TAMP2F
#undef RTC_ISR_RECALPF
#undef RTC_PRER_0_PREDIV_S
#undef RTC_MAP0_SSR
#undef RTC_MAP0_SHIFTR
#undef RTC_MAP0_TSSSR
#undef RTC_MAP0_CALR
#undef RTC_MAP0_ALRMASSR
#undef RTC_CR_0_ALRBE
#undef RTC_CR_0_ALRBIE
#undef RTC_ISR_ALRBWF
#undef RTC_ISR_ALRBF
#undef RTC_MAP1_ALRMBR
#undef RTC_MAP0_ALRMBSSR
#undef RTC_MAP0_BKP0R
#undef RTC_MAP0_BKP1R
#undef RTC_MAP0_BKP2R
#undef RTC_MAP0_BKP3R
#undef RTC_MAP0_BKP4R
#undef RTC_MAP0_BKP5R
#undef RTC_MAP0_BKP6R
#undef RTC_MAP0_BKP7R
#undef RTC_MAP0_BKP8R
#undef RTC_MAP0_BKP9R
#undef RTC_MAP0_BKP10R
#undef RTC_MAP0_BKP11R
#undef RTC_MAP0_BKP12R
#undef RTC_MAP0_BKP13R
#undef RTC_MAP0_BKP14R
#undef RTC_MAP0_BKP15R
#undef RTC_MAP0_BKP16R
#undef RTC_MAP0_BKP17R
#undef RTC_MAP0_BKP18R
#undef RTC_MAP0_BKP19R
#undef RTC_MAP0_BKP20R
#undef RTC_MAP0_BKP21R
#undef RTC_MAP0_BKP22R
#undef RTC_MAP0_BKP23R
#undef RTC_MAP0_BKP24R
#undef RTC_MAP0_BKP25R
#undef RTC_MAP0_BKP26R
#undef RTC_MAP0_BKP27R
#undef RTC_MAP0_BKP28R
#undef RTC_MAP0_BKP29R
#undef RTC_MAP0_BKP30R
#undef RTC_MAP0_BKP31R
#undef RTC_CR_0_DCE
#undef RTC_MAP1_CALIBR
#undef RTC_CR_0_WUCKSEL
#undef RTC_CR_0_WUTE
#undef RTC_CR_0_WUTIE
#undef RTC_ISR_WUTWF
#undef RTC_ISR_WUTF
#undef RTC_MAP0_WUTR
#undef RTC_CR_0_BKP
#undef RTC_CR_0_ITSE
#undef RTC_ISR_ITSF
#undef RTC_ISR_TAMP1F
#undef RTC_ISR_TAMP3F
#undef RTC_MAP1_TAMPCR
#undef RTC_MAP0_OR
#undef RTC_OR_1_ALARMTYPE
#undef RTC_OR_1_ALARMOUTTYPE
#undef RTC_OR_1_OUT_RMP
#undef RTC_MAP0_TAFCR
#undef RTC_TAFCR_0_TAMP2E
#undef RTC_TAFCR_0_TAMP2TRG
#undef RTC_TAFCR_0_TAMPTS
#undef RTC_TAFCR_0_TAMPFREQ
#undef RTC_TAFCR_0_TAMPFLT
#undef RTC_TAFCR_0_TAMPPRCH
#undef RTC_TAFCR_0_TAMPPUDIS
#undef RTC_TAFCR_0_TAMP3E
#undef RTC_TAFCR_0_TAMP3TRG
#undef RTC_TAFCR_0_TAMP1INSEL
#undef RTC_TAFCR_0_TSINSEL
#undef RTC_TAFCR_1_TAMPINSEL
#undef RTC_TAFCR_0_PC13VALUE
#undef RTC_TAFCR_0_PC13MODE
#undef RTC_TAFCR_0_PC14VALUE
#undef RTC_TAFCR_0_PC14MODE
#undef RTC_TAFCR_0_PC15VALUE
#undef RTC_TAFCR_0_PC15MODE
#undef RTC_TAMPCR_0_TAMP1E
#undef RTC_TAMPCR_0_TAMP1IE
#undef RTC_TAMPCR_0_TAMP1NOERASE
#undef RTC_TAMPCR_0_TAMP1MF
#undef RTC_TAMPCR_0_TAMP1TRG
#undef RTC_TAMPCR_0_TAMP2TRG
#undef RTC_TAMPCR_0_TAMP3E
#undef RTC_TAMPCR_0_TAMP3IE
#undef RTC_TAMPCR_0_TAMP3NOERASE
#undef RTC_TAMPCR_0_TAMP3MF
#undef RTC_TAMPCR_0_TAMP3TRG
//endregion
#endif
