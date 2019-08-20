#ifndef __SOOL_DBGMCU_H
#define __SOOL_DBGMCU_H

#include "peripheral_include.h"
//SOOL-DBGMCU-INCLUDES
//region defines

#if defined(STM32F0     ) || defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) ||\
    defined(STM32F7     ) || defined(STM32L0     ) || defined(STM32L1     ) 
#define DBGMCU_APB1FZ
#define DBGMCU_MAP0_APB1FZ   APB1FZ_TypeDef APB1FZ
#define DBGMCU_MAP0_APB2FZ   APB2FZ_TypeDef APB2FZ
#else
#define DBGMCU_MAP0_APB1FZ __SOOL_PERIPH_PADDING_4
#define DBGMCU_MAP0_APB2FZ __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F031x6 ) || defined(STM32F038xx ) || defined(STM32F042x6 ) || defined(STM32F048xx ) ||\
    defined(STM32F051x8 ) || defined(STM32F058xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F2     ) ||\
    defined(STM32F3     ) || defined(STM32F401xC ) || defined(STM32F401xE ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F411xE ) || defined(STM32F412Cx ) || defined(STM32F412Rx ) ||\
    defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32L0     ) || defined(STM32L1     ) 
#define DBGMCU_APB1FZ_0_DBG_TIM2_STOP DBG_TIM2_STOP        // 1 bits @ 0
#else
#define DBGMCU_APB1FZ_0_DBG_TIM2_STOP
#endif

#if defined(STM32F0     ) || defined(STM32F2     ) || defined(STM32F302xC ) || defined(STM32F302xE ) ||\
    defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F328xx ) ||\
    defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) ||\
    defined(STM32F398xx ) || defined(STM32F401xC ) || defined(STM32F401xE ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F411xE ) || defined(STM32F412Cx ) || defined(STM32F412Rx ) ||\
    defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32L071xx ) || defined(STM32L072xx ) ||\
    defined(STM32L073xx ) || defined(STM32L081xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) ||\
    defined(STM32L1     ) 
#define DBGMCU_APB1FZ_0_DBG_TIM3_STOP DBG_TIM3_STOP        // 1 bits @ 1
#else
#define DBGMCU_APB1FZ_0_DBG_TIM3_STOP
#endif

#if defined(STM32F2     ) || defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F358xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) ||\
    defined(STM32F398xx ) || defined(STM32F401xC ) || defined(STM32F401xE ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F411xE ) || defined(STM32F412Cx ) || defined(STM32F412Rx ) ||\
    defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32L1     ) 
#define DBGMCU_APB1FZ_0_DBG_TIM4_STOP DBG_TIM4_STOP        // 1 bits @ 2
#else
#define DBGMCU_APB1FZ_0_DBG_TIM4_STOP
#endif

#if defined(STM32F2     ) || defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F4     ) ||\
    defined(STM32F7     ) || defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) ||\
    defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) ||\
    defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define DBGMCU_APB1FZ_0_DBG_TIM5_STOP DBG_TIM5_STOP        // 1 bits @ 3
#else
#define DBGMCU_APB1FZ_0_DBG_TIM5_STOP
#endif

#if defined(STM32F030x8 ) || defined(STM32F030xC ) || defined(STM32F051x8 ) || defined(STM32F058xx ) ||\
    defined(STM32F070xB ) || defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) ||\
    defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F2     ) || defined(STM32F3     ) ||\
    defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F410Cx ) || defined(STM32F410Rx ) ||\
    defined(STM32F410Tx ) || defined(STM32F412Cx ) || defined(STM32F412Rx ) || defined(STM32F412Vx ) ||\
    defined(STM32F412Zx ) || defined(STM32F413xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) ||\
    defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) ||\
    defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) ||\
    defined(STM32F7     ) || defined(STM32L051xx ) || defined(STM32L052xx ) || defined(STM32L053xx ) ||\
    defined(STM32L061xx ) || defined(STM32L062xx ) || defined(STM32L063xx ) || defined(STM32L071xx ) ||\
    defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L081xx ) || defined(STM32L082xx ) ||\
    defined(STM32L083xx ) || defined(STM32L1     ) 
#define DBGMCU_APB1FZ_0_DBG_TIM6_STOP DBG_TIM6_STOP        // 1 bits @ 4
#else
#define DBGMCU_APB1FZ_0_DBG_TIM6_STOP
#endif

#if defined(STM32F030xC ) || defined(STM32F070xB ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F2     ) ||\
    defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F328xx ) ||\
    defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) ||\
    defined(STM32F398xx ) || defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F412Cx ) ||\
    defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) ||\
    defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) ||\
    defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) ||\
    defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32L071xx ) ||\
    defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L081xx ) || defined(STM32L082xx ) ||\
    defined(STM32L083xx ) || defined(STM32L1     ) 
#define DBGMCU_APB1FZ_0_DBG_TIM7_STOP DBG_TIM7_STOP        // 1 bits @ 5
#else
#define DBGMCU_APB1FZ_0_DBG_TIM7_STOP
#endif

#if defined(STM32F2     ) || defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F412Cx ) || defined(STM32F412Rx ) || defined(STM32F412Vx ) ||\
    defined(STM32F412Zx ) || defined(STM32F413xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) ||\
    defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) ||\
    defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) ||\
    defined(STM32F7     ) 
#define DBGMCU_APB1FZ_0_DBG_TIM12_STOP DBG_TIM12_STOP       // 1 bits @ 6
#define DBGMCU_APB1FZ_0_DBG_TIM13_STOP DBG_TIM13_STOP       // 1 bits @ 7
#else
#define DBGMCU_APB1FZ_0_DBG_TIM12_STOP
#define DBGMCU_APB1FZ_0_DBG_TIM13_STOP
#endif

#if defined(STM32F0     ) || defined(STM32F2     ) || defined(STM32F373xC ) || defined(STM32F378xx ) ||\
    defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F412Cx ) || defined(STM32F412Rx ) ||\
    defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) 
#define DBGMCU_APB1FZ_0_DBG_TIM14_STOP DBG_TIM14_STOP       // 1 bits @ 8
#else
#define DBGMCU_APB1FZ_0_DBG_TIM14_STOP
#endif

#if defined(STM32F373xC ) || defined(STM32F378xx ) 
#define DBGMCU_APB1FZ_0_DBG_TIM18_STOP DBG_TIM18_STOP       // 1 bits @ 9
#define DBGMCU_APB2FZ_1_DBG_TIM19_STOP DBG_TIM19_STOP       // 1 bits @ 5
#else
#define DBGMCU_APB1FZ_0_DBG_TIM18_STOP
#define DBGMCU_APB2FZ_1_DBG_TIM19_STOP
#endif

#if defined(STM32F0     ) || defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) ||\
    defined(STM32F7     ) || defined(STM32L0     ) || defined(STM32L100xBA) || defined(STM32L100xC ) ||\
    defined(STM32L151xBA) || defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) ||\
    defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xBA) || defined(STM32L152xC ) ||\
    defined(STM32L152xCA) || defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) ||\
    defined(STM32L162xC ) || defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) ||\
    defined(STM32L162xE ) 
#define DBGMCU_APB1FZ_0_DBG_RTC_STOP DBG_RTC_STOP         // 1 bits @ 10
#else
#define DBGMCU_APB1FZ_0_DBG_RTC_STOP
#endif

#if defined(STM32F0     ) || defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) ||\
    defined(STM32F7     ) || defined(STM32L1     ) 
#define DBGMCU_APB1FZ_0_DBG_I2C1_SMBUS_TIMEOUT DBG_I2C1_SMBUS_TIMEOUT // 1 bits @ 21
#else
#define DBGMCU_APB1FZ_0_DBG_I2C1_SMBUS_TIMEOUT
#endif

#if defined(STM32F2     ) || defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) ||\
    defined(STM32F302xE ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F318xx ) ||\
    defined(STM32F358xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F398xx ) ||\
    defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L1     ) 
#define DBGMCU_APB1FZ_0_DBG_I2C2_SMBUS_TIMEOUT DBG_I2C2_SMBUS_TIMEOUT // 1 bits @ 22
#else
#define DBGMCU_APB1FZ_0_DBG_I2C2_SMBUS_TIMEOUT
#endif

#if defined(STM32F2     ) || defined(STM32F401xC ) || defined(STM32F401xE ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F411xE ) || defined(STM32F412Cx ) || defined(STM32F412Rx ) ||\
    defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) 
#define DBGMCU_APB1FZ_0_DBG_I2C3_SMBUS_TIMEOUT DBG_I2C3_SMBUS_TIMEOUT // 1 bits @ 23
#define DBGMCU_APB2FZ_1_DBG_TIM10_STOP DBG_TIM10_STOP       // 1 bits @ 17
#else
#define DBGMCU_APB1FZ_0_DBG_I2C3_SMBUS_TIMEOUT
#define DBGMCU_APB2FZ_1_DBG_TIM10_STOP
#endif

#if defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) || defined(STM32F412Cx ) ||\
    defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) ||\
    defined(STM32F423xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) ||\
    defined(STM32F765xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) || defined(STM32F777xx ) ||\
    defined(STM32F779xx ) 
#define DBGMCU_APB1FZ_0_DBG_I2C4_SMBUS_TIMEOUT DBG_I2C4_SMBUS_TIMEOUT // 1 bits @ 24
#else
#define DBGMCU_APB1FZ_0_DBG_I2C4_SMBUS_TIMEOUT
#endif

#if defined(STM32F042x6 ) || defined(STM32F048xx ) || defined(STM32F072xB ) || defined(STM32F078xx ) ||\
    defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F302x8 ) || defined(STM32F302xC ) ||\
    defined(STM32F302xE ) || defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) ||\
    defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F373xC ) ||\
    defined(STM32F378xx ) || defined(STM32F398xx ) 
#define DBGMCU_APB1FZ_0_DBG_CAN_STOP DBG_CAN_STOP         // 1 bits @ 25
#else
#define DBGMCU_APB1FZ_0_DBG_CAN_STOP
#endif

#if defined(STM32F2     ) || defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F410Cx ) ||\
    defined(STM32F410Rx ) || defined(STM32F410Tx ) || defined(STM32F412Cx ) || defined(STM32F412Rx ) ||\
    defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F745xx ) || defined(STM32F746xx ) || defined(STM32F756xx ) ||\
    defined(STM32F765xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) || defined(STM32F777xx ) ||\
    defined(STM32F779xx ) 
#define DBGMCU_APB1FZ_0_DBG_CAN2_STOP DBG_CAN2_STOP        // 1 bits @ 26
#else
#define DBGMCU_APB1FZ_0_DBG_CAN2_STOP
#endif

#if defined(STM32F413xx ) || defined(STM32F423xx ) 
#define DBGMCU_APB1FZ_0_DBG_CAN3_STOP DBG_CAN3_STOP        // 1 bits @ 27
#define DBGMCU_APB1FZ_1_DBG_LPTIM_STOP DBG_LPTIM_STOP       // 1 bits @ 9
#else
#define DBGMCU_APB1FZ_0_DBG_CAN3_STOP
#define DBGMCU_APB1FZ_1_DBG_LPTIM_STOP
#endif

#if defined(STM32L0     ) 
#define DBGMCU_APB1FZ_0_DBG_LPTIMER_STOP DBG_LPTIMER_STOP     // 1 bits @ 31
#define DBGMCU_APB1FZ_1_DBG_I2C1_STOP DBG_I2C1_STOP        // 1 bits @ 21
#define DBGMCU_APB2FZ_0_DBG_TIM21_STOP DBG_TIM21_STOP       // 1 bits @ 2
#define DBGMCU_CR_2
#else
#define DBGMCU_APB1FZ_0_DBG_LPTIMER_STOP
#define DBGMCU_APB1FZ_1_DBG_I2C1_STOP
#define DBGMCU_APB2FZ_0_DBG_TIM21_STOP
#endif

#if defined(STM32F2     ) || defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xE ) ||\
    defined(STM32F303xE ) || defined(STM32F318xx ) || defined(STM32F398xx ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) ||\
    defined(STM32F412Cx ) || defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) ||\
    defined(STM32F413xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F423xx ) ||\
    defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) ||\
    defined(STM32L0     ) 
#define DBGMCU_APB1FZ_1
#endif

#if defined(STM32F765xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) || defined(STM32F777xx ) ||\
    defined(STM32F779xx ) 
#define DBGMCU_APB1FZ_1_DBG_CAN3_STOP DBG_CAN3_STOP        // 1 bits @ 13
#else
#define DBGMCU_APB1FZ_1_DBG_CAN3_STOP
#endif

#if defined(STM32L051xx ) || defined(STM32L052xx ) || defined(STM32L053xx ) || defined(STM32L061xx ) ||\
    defined(STM32L062xx ) || defined(STM32L063xx ) || defined(STM32L071xx ) || defined(STM32L072xx ) ||\
    defined(STM32L073xx ) || defined(STM32L081xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) 
#define DBGMCU_APB1FZ_1_DBG_I2C2_STOP DBG_I2C2_STOP        // 1 bits @ 22
#else
#define DBGMCU_APB1FZ_1_DBG_I2C2_STOP
#endif

#if defined(STM32L071xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L081xx ) ||\
    defined(STM32L082xx ) || defined(STM32L083xx ) 
#define DBGMCU_APB1FZ_1_DBG_I2C3_STOP DBG_I2C3_STOP        // 1 bits @ 23
#else
#define DBGMCU_APB1FZ_1_DBG_I2C3_STOP
#endif

#if defined(STM32F2     ) || defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F410Cx ) ||\
    defined(STM32F410Rx ) || defined(STM32F410Tx ) || defined(STM32F412Cx ) || defined(STM32F412Rx ) ||\
    defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) 
#define DBGMCU_APB1FZ_1_DBG_CAN1_STOP DBG_CAN1_STOP        // 1 bits @ 25
#else
#define DBGMCU_APB1FZ_1_DBG_CAN1_STOP
#endif

#if defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xE ) || defined(STM32F303xE ) ||\
    defined(STM32F318xx ) || defined(STM32F398xx ) 
#define DBGMCU_APB1FZ_1_DBG_I2C3_SMBUS_TIMEOUT DBG_I2C3_SMBUS_TIMEOUT // 1 bits @ 30
#else
#define DBGMCU_APB1FZ_1_DBG_I2C3_SMBUS_TIMEOUT
#endif

#if defined(STM32F7     ) 
#define DBGMCU_APB1FZ_2
#endif

#if defined(STM32L4     ) || defined(STM32L4P    ) 
#define DBGMCU_APB1FZR1
#define DBGMCU_APB1FZR2
#define DBGMCU_MAP1_APB1FZR1 APB1FZR1_TypeDef APB1FZR1
#define DBGMCU_MAP1_APB1FZR2 APB1FZR2_TypeDef APB1FZR2
#define DBGMCU_MAP1_APB2FZ   APB2FZ_TypeDef APB2FZ
#else
#define DBGMCU_MAP1_APB1FZR1 __SOOL_PERIPH_PADDING_4
#define DBGMCU_MAP1_APB1FZR2 __SOOL_PERIPH_PADDING_4
#define DBGMCU_MAP1_APB2FZ __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32L451xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L471xx ) ||\
    defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define DBGMCU_APB1FZR1_DBG_TIM3_STOP DBG_TIM3_STOP        // 1 bits @ 1
#else
#define DBGMCU_APB1FZR1_DBG_TIM3_STOP
#endif

#if defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define DBGMCU_APB1FZR1_DBG_TIM4_STOP DBG_TIM4_STOP        // 1 bits @ 2
#define DBGMCU_APB1FZR1_DBG_TIM5_STOP DBG_TIM5_STOP        // 1 bits @ 3
#define DBGMCU_APB2FZ_1_DBG_TIM8_STOP DBG_TIM8_STOP        // 1 bits @ 13
#else
#define DBGMCU_APB1FZR1_DBG_TIM4_STOP
#define DBGMCU_APB1FZR1_DBG_TIM5_STOP
#define DBGMCU_APB2FZ_1_DBG_TIM8_STOP
#endif

#if defined(STM32L431xx ) || defined(STM32L432xx ) || defined(STM32L433xx ) || defined(STM32L442xx ) ||\
    defined(STM32L443xx ) || defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) ||\
    defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) ||\
    defined(STM32L4P    ) 
#define DBGMCU_APB1FZR1_DBG_TIM7_STOP DBG_TIM7_STOP        // 1 bits @ 5
#else
#define DBGMCU_APB1FZR1_DBG_TIM7_STOP
#endif

#if defined(STM32L431xx ) || defined(STM32L433xx ) || defined(STM32L443xx ) || defined(STM32L451xx ) ||\
    defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L471xx ) || defined(STM32L475xx ) ||\
    defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define DBGMCU_APB1FZR1_DBG_I2C2_STOP DBG_I2C2_STOP        // 1 bits @ 22
#else
#define DBGMCU_APB1FZR1_DBG_I2C2_STOP
#endif

#if defined(STM32L496xx ) || defined(STM32L4A6xx ) 
#define DBGMCU_APB1FZR1_DBG_CAN2_STOP DBG_CAN2_STOP        // 1 bits @ 26
#else
#define DBGMCU_APB1FZR1_DBG_CAN2_STOP
#endif

#if defined(STM32L451xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define DBGMCU_APB1FZR2_DBG_I2C4_STOP DBG_I2C4_STOP        // 1 bits @ 1
#else
#define DBGMCU_APB1FZR2_DBG_I2C4_STOP
#endif

#if defined(STM32H7     ) 
#define DBGMCU_APB1HFZ1
#define DBGMCU_APB1LFZ1
#define DBGMCU_APB2FZ1
#define DBGMCU_APB3FZ1
#define DBGMCU_APB4FZ1
#define DBGMCU_CR_1
#define DBGMCU_MAP0_APB3FZ1  APB3FZ1_TypeDef APB3FZ1
#define DBGMCU_MAP0_APB1LFZ1 APB1LFZ1_TypeDef APB1LFZ1
#define DBGMCU_MAP0_APB1HFZ1 APB1HFZ1_TypeDef APB1HFZ1
#define DBGMCU_MAP0_APB2FZ1  APB2FZ1_TypeDef APB2FZ1
#define DBGMCU_MAP0_APB4FZ1  APB4FZ1_TypeDef APB4FZ1
#else
#define DBGMCU_MAP0_APB3FZ1 __SOOL_PERIPH_PADDING_4
#define DBGMCU_MAP0_APB1LFZ1 __SOOL_PERIPH_PADDING_4
#define DBGMCU_MAP0_APB1HFZ1 __SOOL_PERIPH_PADDING_4
#define DBGMCU_MAP0_APB2FZ1 __SOOL_PERIPH_PADDING_4
#define DBGMCU_MAP0_APB4FZ1 __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F0     ) || defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) ||\
    defined(STM32F7     ) || defined(STM32L0     ) || defined(STM32L1     ) || defined(STM32L4     ) ||\
    defined(STM32L4P    ) 
#define DBGMCU_APB2FZ
#endif

#if defined(STM32F0     ) || defined(STM32F2     ) || defined(STM32F303xC ) || defined(STM32F303xE ) ||\
    defined(STM32F334x8 ) || defined(STM32F358xx ) || defined(STM32F398xx ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F412Cx ) || defined(STM32F412Rx ) || defined(STM32F412Vx ) ||\
    defined(STM32F412Zx ) || defined(STM32F413xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) ||\
    defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) ||\
    defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) ||\
    defined(STM32F7     ) || defined(STM32L0     ) || defined(STM32L1     ) || defined(STM32L4     ) ||\
    defined(STM32L4P    ) 
#define DBGMCU_APB2FZ_0
#endif

#if defined(STM32F2     ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F358xx ) ||\
    defined(STM32F398xx ) || defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F412Cx ) ||\
    defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) ||\
    defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) ||\
    defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) ||\
    defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) 
#define DBGMCU_APB2FZ_0_DBG_TIM8_STOP DBG_TIM8_STOP        // 1 bits @ 1
#else
#define DBGMCU_APB2FZ_0_DBG_TIM8_STOP
#endif

#if defined(STM32L1     ) 
#define DBGMCU_APB2FZ_0_DBG_TIM10_STOP DBG_TIM10_STOP       // 1 bits @ 3
#define DBGMCU_APB2FZ_0_DBG_TIM11_STOP DBG_TIM11_STOP       // 1 bits @ 4
#define DBGMCU_APB2FZ_2_DBG_TIM9_STOP DBG_TIM9_STOP        // 1 bits @ 2
#else
#define DBGMCU_APB2FZ_0_DBG_TIM10_STOP
#define DBGMCU_APB2FZ_0_DBG_TIM11_STOP
#define DBGMCU_APB2FZ_2_DBG_TIM9_STOP
#endif

#if defined(STM32F303xE ) || defined(STM32F398xx ) 
#define DBGMCU_APB2FZ_0_DBG_TIM20_STOP DBG_TIM20_STOP       // 1 bits @ 5
#else
#define DBGMCU_APB2FZ_0_DBG_TIM20_STOP
#endif

#if defined(STM32F334x8 ) 
#define DBGMCU_APB2FZ_0_DBG_HRTIM1_STOP DBG_HRTIM1_STOP      // 1 bits @ 8
#else
#define DBGMCU_APB2FZ_0_DBG_HRTIM1_STOP
#endif

#if defined(STM32F0     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define DBGMCU_APB2FZ_0_DBG_TIM1_STOP DBG_TIM1_STOP        // 1 bits @ 11
#define DBGMCU_APB2FZ_0_DBG_TIM16_STOP DBG_TIM16_STOP       // 1 bits @ 17
#else
#define DBGMCU_APB2FZ_0_DBG_TIM1_STOP
#define DBGMCU_APB2FZ_0_DBG_TIM16_STOP
#endif

#if defined(STM32F030x8 ) || defined(STM32F030xC ) || defined(STM32F051x8 ) || defined(STM32F058xx ) ||\
    defined(STM32F070xB ) || defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) ||\
    defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define DBGMCU_APB2FZ_0_DBG_TIM15_STOP DBG_TIM15_STOP       // 1 bits @ 16
#else
#define DBGMCU_APB2FZ_0_DBG_TIM15_STOP
#endif

#if defined(STM32F0     ) || defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) ||\
    defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) ||\
    defined(STM32L4P    ) 
#define DBGMCU_APB2FZ_0_DBG_TIM17_STOP DBG_TIM17_STOP       // 1 bits @ 18
#else
#define DBGMCU_APB2FZ_0_DBG_TIM17_STOP
#endif

#if defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) || defined(STM32F7     ) ||\
    defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define DBGMCU_APB2FZ_1
#endif

#if defined(STM32F2     ) || defined(STM32F301x8 ) || defined(STM32F302x8 ) || defined(STM32F302xC ) ||\
    defined(STM32F302xE ) || defined(STM32F303x8 ) || defined(STM32F303xC ) || defined(STM32F303xE ) ||\
    defined(STM32F318xx ) || defined(STM32F328xx ) || defined(STM32F334x8 ) || defined(STM32F358xx ) ||\
    defined(STM32F398xx ) || defined(STM32F4     ) || defined(STM32F7     ) 
#define DBGMCU_APB2FZ_1_DBG_TIM1_STOP DBG_TIM1_STOP        // 1 bits @ 0
#else
#define DBGMCU_APB2FZ_1_DBG_TIM1_STOP
#endif

#if defined(STM32F3     ) 
#define DBGMCU_APB2FZ_1_DBG_TIM15_STOP DBG_TIM15_STOP       // 1 bits @ 2
#define DBGMCU_APB2FZ_1_DBG_TIM16_STOP DBG_TIM16_STOP       // 1 bits @ 3
#define DBGMCU_APB2FZ_1_DBG_TIM17_STOP DBG_TIM17_STOP       // 1 bits @ 4
#else
#define DBGMCU_APB2FZ_1_DBG_TIM15_STOP
#define DBGMCU_APB2FZ_1_DBG_TIM16_STOP
#define DBGMCU_APB2FZ_1_DBG_TIM17_STOP
#endif

#if defined(STM32F2     ) || defined(STM32F4     ) || defined(STM32F7     ) 
#define DBGMCU_APB2FZ_1_DBG_TIM9_STOP DBG_TIM9_STOP        // 1 bits @ 16
#define DBGMCU_APB2FZ_1_DBG_TIM11_STOP DBG_TIM11_STOP       // 1 bits @ 18
#else
#define DBGMCU_APB2FZ_1_DBG_TIM9_STOP
#define DBGMCU_APB2FZ_1_DBG_TIM11_STOP
#endif

#if defined(STM32L031xx ) || defined(STM32L041xx ) || defined(STM32L051xx ) || defined(STM32L052xx ) ||\
    defined(STM32L053xx ) || defined(STM32L061xx ) || defined(STM32L062xx ) || defined(STM32L063xx ) ||\
    defined(STM32L071xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L081xx ) ||\
    defined(STM32L082xx ) || defined(STM32L083xx ) || defined(STM32L1     ) 
#define DBGMCU_APB2FZ_2
#endif

#if defined(STM32L031xx ) || defined(STM32L041xx ) || defined(STM32L051xx ) || defined(STM32L052xx ) ||\
    defined(STM32L053xx ) || defined(STM32L061xx ) || defined(STM32L062xx ) || defined(STM32L063xx ) ||\
    defined(STM32L071xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L081xx ) ||\
    defined(STM32L082xx ) || defined(STM32L083xx ) 
#define DBGMCU_APB2FZ_2_DBG_TIM22_STOP DBG_TIM22_STOP       // 1 bits @ 5
#else
#define DBGMCU_APB2FZ_2_DBG_TIM22_STOP
#endif

#define DBGMCU_CR
#define DBGMCU_IDCODE

#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F2     ) || defined(STM32F3     ) ||\
    defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L1     ) || defined(STM32L4     ) ||\
    defined(STM32L4P    ) 
#define DBGMCU_CR_0
#endif

#if defined(STM32F1     ) || defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) ||\
    defined(STM32F7     ) 
#define DBGMCU_CR_0_DBG_SLEEP DBG_SLEEP            // 1 bits @ 0
#else
#define DBGMCU_CR_0_DBG_SLEEP
#endif

#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F2     ) || defined(STM32F3     ) ||\
    defined(STM32F4     ) || defined(STM32F7     ) 
#define DBGMCU_CR_0_DBG_STOP DBG_STOP             // 1 bits @ 1
#define DBGMCU_CR_0_DBG_STANDBY DBG_STANDBY          // 1 bits @ 2
#else
#define DBGMCU_CR_0_DBG_STOP
#define DBGMCU_CR_0_DBG_STANDBY
#endif

#if defined(STM32F1     ) || defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) ||\
    defined(STM32F7     ) || defined(STM32L1     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define DBGMCU_CR_0_TRACE_IOEN TRACE_IOEN           // 1 bits @ 5
#define DBGMCU_CR_0_TRACE_MODE TRACE_MODE           // 2 bits @ 6
#else
#define DBGMCU_CR_0_TRACE_IOEN
#define DBGMCU_CR_0_TRACE_MODE
#endif

#if defined(STM32F1     ) 
#define DBGMCU_CR_0_DBG_IWDG_STOP DBG_IWDG_STOP        // 1 bits @ 8
#define DBGMCU_CR_0_DBG_WWDG_STOP DBG_WWDG_STOP        // 1 bits @ 9
#define DBGMCU_CR_0_DBG_TIM2_STOP DBG_TIM2_STOP        // 1 bits @ 11
#define DBGMCU_CR_0_DBG_TIM3_STOP DBG_TIM3_STOP        // 1 bits @ 12
#define DBGMCU_CR_0_DBG_I2C1_SMBUS_TIMEOUT DBG_I2C1_SMBUS_TIMEOUT // 1 bits @ 15
#else
#define DBGMCU_CR_0_DBG_IWDG_STOP
#define DBGMCU_CR_0_DBG_WWDG_STOP
#define DBGMCU_CR_0_DBG_TIM2_STOP
#define DBGMCU_CR_0_DBG_TIM3_STOP
#define DBGMCU_CR_0_DBG_I2C1_SMBUS_TIMEOUT
#endif

#if defined(STM32F100xB ) || defined(STM32F100xE ) || defined(STM32F101xE ) || defined(STM32F101xG ) ||\
    defined(STM32F103x6 ) || defined(STM32F103xB ) || defined(STM32F103xE ) || defined(STM32F103xG ) ||\
    defined(STM32F105xC ) || defined(STM32F107xC ) 
#define DBGMCU_CR_0_DBG_TIM1_STOP DBG_TIM1_STOP        // 1 bits @ 10
#else
#define DBGMCU_CR_0_DBG_TIM1_STOP
#endif

#if defined(STM32F100xB ) || defined(STM32F100xE ) || defined(STM32F101xB ) || defined(STM32F101xE ) ||\
    defined(STM32F101xG ) || defined(STM32F102xB ) || defined(STM32F103xB ) || defined(STM32F103xE ) ||\
    defined(STM32F103xG ) || defined(STM32F105xC ) || defined(STM32F107xC ) 
#define DBGMCU_CR_0_DBG_TIM4_STOP DBG_TIM4_STOP        // 1 bits @ 13
#define DBGMCU_CR_0_DBG_I2C2_SMBUS_TIMEOUT DBG_I2C2_SMBUS_TIMEOUT // 1 bits @ 16
#else
#define DBGMCU_CR_0_DBG_TIM4_STOP
#define DBGMCU_CR_0_DBG_I2C2_SMBUS_TIMEOUT
#endif

#if defined(STM32F103x6 ) || defined(STM32F103xB ) || defined(STM32F103xE ) || defined(STM32F103xG ) ||\
    defined(STM32F105xC ) || defined(STM32F107xC ) 
#define DBGMCU_CR_0_DBG_CAN1_STOP DBG_CAN1_STOP        // 1 bits @ 14
#else
#define DBGMCU_CR_0_DBG_CAN1_STOP
#endif

#if defined(STM32F103xE ) || defined(STM32F103xG ) 
#define DBGMCU_CR_0_DBG_TIM8_STOP DBG_TIM8_STOP        // 1 bits @ 17
#else
#define DBGMCU_CR_0_DBG_TIM8_STOP
#endif

#if defined(STM32F100xE ) || defined(STM32F101xE ) || defined(STM32F101xG ) || defined(STM32F103xE ) ||\
    defined(STM32F103xG ) || defined(STM32F105xC ) || defined(STM32F107xC ) 
#define DBGMCU_CR_0_DBG_TIM5_STOP DBG_TIM5_STOP        // 1 bits @ 18
#define DBGMCU_CR_0_DBG_TIM6_STOP DBG_TIM6_STOP        // 1 bits @ 19
#define DBGMCU_CR_0_DBG_TIM7_STOP DBG_TIM7_STOP        // 1 bits @ 20
#else
#define DBGMCU_CR_0_DBG_TIM5_STOP
#define DBGMCU_CR_0_DBG_TIM6_STOP
#define DBGMCU_CR_0_DBG_TIM7_STOP
#endif

#if defined(STM32F105xC ) || defined(STM32F107xC ) 
#define DBGMCU_CR_0_DBG_CAN2_STOP DBG_CAN2_STOP        // 1 bits @ 21
#else
#define DBGMCU_CR_0_DBG_CAN2_STOP
#endif

#if defined(STM32F100xB ) || defined(STM32F100xE ) 
#define DBGMCU_CR_0_DBG_TIM15_STOP DBG_TIM15_STOP       // 1 bits @ 22
#define DBGMCU_CR_0_DBG_TIM16_STOP DBG_TIM16_STOP       // 1 bits @ 23
#define DBGMCU_CR_0_DBG_TIM17_STOP DBG_TIM17_STOP       // 1 bits @ 24
#else
#define DBGMCU_CR_0_DBG_TIM15_STOP
#define DBGMCU_CR_0_DBG_TIM16_STOP
#define DBGMCU_CR_0_DBG_TIM17_STOP
#endif

#if defined(STM32F100xE ) || defined(STM32F101xG ) || defined(STM32F103xG ) 
#define DBGMCU_CR_0_DBG_TIM12_STOP DBG_TIM12_STOP       // 1 bits @ 25
#define DBGMCU_CR_0_DBG_TIM13_STOP DBG_TIM13_STOP       // 1 bits @ 26
#define DBGMCU_CR_0_DBG_TIM14_STOP DBG_TIM14_STOP       // 1 bits @ 27
#else
#define DBGMCU_CR_0_DBG_TIM12_STOP
#define DBGMCU_CR_0_DBG_TIM13_STOP
#define DBGMCU_CR_0_DBG_TIM14_STOP
#endif

#if defined(STM32F101xE ) || defined(STM32F101xG ) || defined(STM32F103xG ) || defined(STM32F105xC ) ||\
    defined(STM32F107xC ) 
#define DBGMCU_CR_0_DBG_TIM9_STOP DBG_TIM9_STOP        // 1 bits @ 28
#define DBGMCU_CR_0_DBG_TIM10_STOP DBG_TIM10_STOP       // 1 bits @ 29
#define DBGMCU_CR_0_DBG_TIM11_STOP DBG_TIM11_STOP       // 1 bits @ 30
#else
#define DBGMCU_CR_0_DBG_TIM9_STOP
#define DBGMCU_CR_0_DBG_TIM10_STOP
#define DBGMCU_CR_0_DBG_TIM11_STOP
#endif

#if defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) 
#define DBGMCU_IDCODE_0_DIV_ID DIV_ID               // 4 bits @ 12
#define DBGMCU_IDCODE_1
#else
#define DBGMCU_IDCODE_0_DIV_ID
#endif

//endregion

namespace sool
{
	namespace core
	{
		class DBGMCU
		{
			//SOOL-DBGMCU-ENUMS
			
			public :
			
			#ifdef DBGMCU_APB1FZ
			struct APB1FZ_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t DBGMCU_APB1FZ_0_DBG_TIM2_STOP :1;
						uint32_t DBGMCU_APB1FZ_0_DBG_TIM3_STOP :1;
						uint32_t DBGMCU_APB1FZ_0_DBG_TIM4_STOP :1;
						uint32_t DBGMCU_APB1FZ_0_DBG_TIM5_STOP :1;
						uint32_t DBGMCU_APB1FZ_0_DBG_TIM6_STOP :1;
						uint32_t DBGMCU_APB1FZ_0_DBG_TIM7_STOP :1;
						uint32_t DBGMCU_APB1FZ_0_DBG_TIM12_STOP :1;
						uint32_t DBGMCU_APB1FZ_0_DBG_TIM13_STOP :1;
						uint32_t DBGMCU_APB1FZ_0_DBG_TIM14_STOP :1;
						uint32_t DBGMCU_APB1FZ_0_DBG_TIM18_STOP :1;
						uint32_t DBGMCU_APB1FZ_0_DBG_RTC_STOP :1;
						uint32_t DBG_WWDG_STOP        :1;
						uint32_t DBG_IWDG_STOP        :1;
						uint32_t                      :8;
						uint32_t DBGMCU_APB1FZ_0_DBG_I2C1_SMBUS_TIMEOUT :1;
						uint32_t DBGMCU_APB1FZ_0_DBG_I2C2_SMBUS_TIMEOUT :1;
						uint32_t DBGMCU_APB1FZ_0_DBG_I2C3_SMBUS_TIMEOUT :1;
						uint32_t DBGMCU_APB1FZ_0_DBG_I2C4_SMBUS_TIMEOUT :1;
						uint32_t DBGMCU_APB1FZ_0_DBG_CAN_STOP :1;
						uint32_t DBGMCU_APB1FZ_0_DBG_CAN2_STOP :1;
						uint32_t DBGMCU_APB1FZ_0_DBG_CAN3_STOP :1;
						uint32_t                      :3;
						uint32_t DBGMCU_APB1FZ_0_DBG_LPTIMER_STOP :1;
					};
					#ifdef DBGMCU_APB1FZ_1
					struct
					{
						uint32_t                      :9;
						uint32_t DBGMCU_APB1FZ_1_DBG_LPTIM_STOP :1;
						uint32_t                      :3;
						uint32_t DBGMCU_APB1FZ_1_DBG_CAN3_STOP :1;
						uint32_t                      :7;
						uint32_t DBGMCU_APB1FZ_1_DBG_I2C1_STOP :1;
						uint32_t DBGMCU_APB1FZ_1_DBG_I2C2_STOP :1;
						uint32_t DBGMCU_APB1FZ_1_DBG_I2C3_STOP :1;
						uint32_t                      :1;
						uint32_t DBGMCU_APB1FZ_1_DBG_CAN1_STOP :1;
						uint32_t                      :4;
						uint32_t DBGMCU_APB1FZ_1_DBG_I2C3_SMBUS_TIMEOUT :1;
						uint32_t                      :1;
					};
					#endif
					#ifdef DBGMCU_APB1FZ_2
					struct
					{
						uint32_t                      :9;
						uint32_t DBG_LPTIM1_STOP      :1;
						uint32_t                      :22;
					};
					#endif
				};
				//SOOL-DBGMCU_APB1FZ-DECLARATION
			};
			#endif
			
			#ifdef DBGMCU_APB1FZR1
			struct APB1FZR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DBG_TIM2_STOP        :1;
					uint32_t DBGMCU_APB1FZR1_DBG_TIM3_STOP :1;
					uint32_t DBGMCU_APB1FZR1_DBG_TIM4_STOP :1;
					uint32_t DBGMCU_APB1FZR1_DBG_TIM5_STOP :1;
					uint32_t DBG_TIM6_STOP        :1;
					uint32_t DBGMCU_APB1FZR1_DBG_TIM7_STOP :1;
					uint32_t                      :4;
					uint32_t DBG_RTC_STOP         :1;
					uint32_t DBG_WWDG_STOP        :1;
					uint32_t DBG_IWDG_STOP        :1;
					uint32_t                      :8;
					uint32_t DBG_I2C1_STOP        :1;
					uint32_t DBGMCU_APB1FZR1_DBG_I2C2_STOP :1;
					uint32_t DBG_I2C3_STOP        :1;
					uint32_t                      :1;
					uint32_t DBG_CAN_STOP         :1;
					uint32_t DBGMCU_APB1FZR1_DBG_CAN2_STOP :1;
					uint32_t                      :4;
					uint32_t DBG_LPTIM1_STOP      :1;
			
				//SOOL-DBGMCU_APB1FZR1-DECLARATION
			};
			#endif
			
			#ifdef DBGMCU_APB1FZR2
			struct APB1FZR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :1;
					uint32_t DBGMCU_APB1FZR2_DBG_I2C4_STOP :1;
					uint32_t                      :3;
					uint32_t DBG_LPTIM2_STOP      :1;
					uint32_t                      :26;
			
				//SOOL-DBGMCU_APB1FZR2-DECLARATION
			};
			#endif
			
			#ifdef DBGMCU_APB1HFZ1
			struct APB1HFZ1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :8;
					uint32_t DBG_FDCAN            :1;
					uint32_t                      :23;
			
				//SOOL-DBGMCU_APB1HFZ1-DECLARATION
			};
			#endif
			
			#ifdef DBGMCU_APB1LFZ1
			struct APB1LFZ1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DBG_TIM2             :1;
					uint32_t DBG_TIM3             :1;
					uint32_t DBG_TIM4             :1;
					uint32_t DBG_TIM5             :1;
					uint32_t DBG_TIM6             :1;
					uint32_t DBG_TIM7             :1;
					uint32_t DBG_TIM12            :1;
					uint32_t DBG_TIM13            :1;
					uint32_t DBG_TIM14            :1;
					uint32_t DBG_LPTIM1           :1;
					uint32_t                      :11;
					uint32_t DBG_I2C1             :1;
					uint32_t DBG_I2C2             :1;
					uint32_t DBG_I2C3             :1;
					uint32_t                      :8;
			
				//SOOL-DBGMCU_APB1LFZ1-DECLARATION
			};
			#endif
			
			#ifdef DBGMCU_APB2FZ
			struct APB2FZ_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DBGMCU_APB2FZ_0
					struct
					{
						uint32_t                      :1;
						uint32_t DBGMCU_APB2FZ_0_DBG_TIM8_STOP :1;
						uint32_t DBGMCU_APB2FZ_0_DBG_TIM21_STOP :1;
						uint32_t DBGMCU_APB2FZ_0_DBG_TIM10_STOP :1;
						uint32_t DBGMCU_APB2FZ_0_DBG_TIM11_STOP :1;
						uint32_t DBGMCU_APB2FZ_0_DBG_TIM20_STOP :1;
						uint32_t                      :2;
						uint32_t DBGMCU_APB2FZ_0_DBG_HRTIM1_STOP :1;
						uint32_t                      :2;
						uint32_t DBGMCU_APB2FZ_0_DBG_TIM1_STOP :1;
						uint32_t                      :4;
						uint32_t DBGMCU_APB2FZ_0_DBG_TIM15_STOP :1;
						uint32_t DBGMCU_APB2FZ_0_DBG_TIM16_STOP :1;
						uint32_t DBGMCU_APB2FZ_0_DBG_TIM17_STOP :1;
						uint32_t                      :13;
					};
					#endif
					#ifdef DBGMCU_APB2FZ_1
					struct
					{
						uint32_t DBGMCU_APB2FZ_1_DBG_TIM1_STOP :1;
						uint32_t                      :1;
						uint32_t DBGMCU_APB2FZ_1_DBG_TIM15_STOP :1;
						uint32_t DBGMCU_APB2FZ_1_DBG_TIM16_STOP :1;
						uint32_t DBGMCU_APB2FZ_1_DBG_TIM17_STOP :1;
						uint32_t DBGMCU_APB2FZ_1_DBG_TIM19_STOP :1;
						uint32_t                      :7;
						uint32_t DBGMCU_APB2FZ_1_DBG_TIM8_STOP :1;
						uint32_t                      :2;
						uint32_t DBGMCU_APB2FZ_1_DBG_TIM9_STOP :1;
						uint32_t DBGMCU_APB2FZ_1_DBG_TIM10_STOP :1;
						uint32_t DBGMCU_APB2FZ_1_DBG_TIM11_STOP :1;
						uint32_t                      :13;
					};
					#endif
					#ifdef DBGMCU_APB2FZ_2
					struct
					{
						uint32_t                      :2;
						uint32_t DBGMCU_APB2FZ_2_DBG_TIM9_STOP :1;
						uint32_t                      :2;
						uint32_t DBGMCU_APB2FZ_2_DBG_TIM22_STOP :1;
						uint32_t                      :26;
					};
					#endif
				};
				//SOOL-DBGMCU_APB2FZ-DECLARATION
			};
			#endif
			
			#ifdef DBGMCU_APB2FZ1
			struct APB2FZ1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DBG_TIM1             :1;
					uint32_t DBG_TIM8             :1;
					uint32_t                      :14;
					uint32_t DBG_TIM15            :1;
					uint32_t DBG_TIM16            :1;
					uint32_t DBG_TIM17            :1;
					uint32_t                      :10;
					uint32_t DBG_HRTIM            :1;
					uint32_t                      :2;
			
				//SOOL-DBGMCU_APB2FZ1-DECLARATION
			};
			#endif
			
			#ifdef DBGMCU_APB3FZ1
			struct APB3FZ1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :6;
					uint32_t DBG_WWDG1            :1;
					uint32_t                      :25;
			
				//SOOL-DBGMCU_APB3FZ1-DECLARATION
			};
			#endif
			
			#ifdef DBGMCU_APB4FZ1
			struct APB4FZ1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :7;
					uint32_t DBG_I2C4             :1;
					uint32_t                      :1;
					uint32_t DBG_LPTIM2           :1;
					uint32_t DBG_LPTIM3           :1;
					uint32_t DBG_LPTIM4           :1;
					uint32_t DBG_LPTIM5           :1;
					uint32_t                      :3;
					uint32_t DBG_RTC              :1;
					uint32_t                      :1;
					uint32_t DBG_IWDG1            :1;
					uint32_t                      :13;
			
				//SOOL-DBGMCU_APB4FZ1-DECLARATION
			};
			#endif
			
			#ifdef DBGMCU_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DBGMCU_CR_0
					struct
					{
						uint32_t DBGMCU_CR_0_DBG_SLEEP :1;
						uint32_t DBGMCU_CR_0_DBG_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_STANDBY :1;
						uint32_t                      :2;
						uint32_t DBGMCU_CR_0_TRACE_IOEN :1;
						uint32_t DBGMCU_CR_0_TRACE_MODE :2;
						uint32_t DBGMCU_CR_0_DBG_IWDG_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_WWDG_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_TIM1_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_TIM2_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_TIM3_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_TIM4_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_CAN1_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_I2C1_SMBUS_TIMEOUT :1;
						uint32_t DBGMCU_CR_0_DBG_I2C2_SMBUS_TIMEOUT :1;
						uint32_t DBGMCU_CR_0_DBG_TIM8_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_TIM5_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_TIM6_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_TIM7_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_CAN2_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_TIM15_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_TIM16_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_TIM17_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_TIM12_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_TIM13_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_TIM14_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_TIM9_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_TIM10_STOP :1;
						uint32_t DBGMCU_CR_0_DBG_TIM11_STOP :1;
						uint32_t                      :1;
					};
					#endif
					#ifdef DBGMCU_CR_1
					struct
					{
						uint32_t DBG_SLEEPD1          :1;
						uint32_t DBG_STOPD1           :1;
						uint32_t DBG_STANDBYD1        :1;
						uint32_t                      :4;
						uint32_t DBG_STOPD3           :1;
						uint32_t DBG_STANDBYD3        :1;
						uint32_t                      :11;
						uint32_t DBG_TRACECKEN        :1;
						uint32_t DBG_CKD1EN           :1;
						uint32_t DBG_CKD3EN           :1;
						uint32_t                      :5;
						uint32_t DBG_TRGOEN           :1;
						uint32_t                      :3;
					};
					#endif
					#ifdef DBGMCU_CR_2
					struct
					{
						uint32_t DBG                  :3;
						uint32_t                      :29;
					};
					#endif
				};
				//SOOL-DBGMCU_CR-DECLARATION
			};
			#endif
			
			#ifdef DBGMCU_IDCODE
			struct IDCODE_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t DEV_ID               :12;
						uint32_t DBGMCU_IDCODE_0_DIV_ID :4;
						uint32_t REV_ID               :16;
					};
					#ifdef DBGMCU_IDCODE_1
					struct
					{
						uint32_t                      :13;
						uint32_t MCD_DIV_ID           :2;
						uint32_t                      :17;
					};
					#endif
				};
				//SOOL-DBGMCU_IDCODE-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					IDCODE_TypeDef IDCODE; // @0x000
					CR_TypeDef CR;       // @0x004
					DBGMCU_MAP0_APB1FZ;  // @0x008
					DBGMCU_MAP0_APB2FZ;  // @0x00c
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_4;
					DBGMCU_MAP0_APB3FZ1; // @0x034
					__SOOL_PERIPH_PADDING_4;
					DBGMCU_MAP0_APB1LFZ1; // @0x03c
					__SOOL_PERIPH_PADDING_4;
					DBGMCU_MAP0_APB1HFZ1; // @0x044
					__SOOL_PERIPH_PADDING_4;
					DBGMCU_MAP0_APB2FZ1; // @0x04c
					__SOOL_PERIPH_PADDING_4;
					DBGMCU_MAP0_APB4FZ1; // @0x054
				};
				struct
				{
					__SOOL_PERIPH_PADDING_8;
					DBGMCU_MAP1_APB1FZR1; // @0x008
					DBGMCU_MAP1_APB1FZR2; // @0x00c
					DBGMCU_MAP1_APB2FZ;  // @0x010
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_4;
				};
			};
			private:
			DBGMCU() = delete;
			//SOOL-DBGMCU-DECLARATION
		};
		
		//region instances
#if defined(STM32F0     ) || defined(STM32L0     ) 
#define DBGMCU_BASE_ADDR ((uint32_t)0x40015800U)
#endif

#if defined(STM32F1     ) || defined(STM32F2     ) || defined(STM32F3     ) || defined(STM32F4     ) ||\
    defined(STM32F7     ) || defined(STM32L1     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define DBGMCU_BASE_ADDR ((uint32_t)0xE0042000U)
#endif

#if defined(STM32H7     ) 
#define DBGMCU_BASE_ADDR ((uint32_t)0x00000000U)
#endif

#ifdef DBGMCU_BASE_ADDR
volatile class DBGMCU * const DBGMCU = reinterpret_cast<class DBGMCU* const>(DBGMCU_BASE_ADDR);
#endif
//endregion

//SOOL-DBGMCU-DEFINES
//SOOL-DBGMCU-DEFINITION
	};
};//region undef
#undef DBGMCU_MAP0_APB1FZ
#undef DBGMCU_MAP0_APB2FZ
#undef DBGMCU_APB1FZ_0_DBG_TIM2_STOP
#undef DBGMCU_APB1FZ_0_DBG_TIM3_STOP
#undef DBGMCU_APB1FZ_0_DBG_TIM4_STOP
#undef DBGMCU_APB1FZ_0_DBG_TIM5_STOP
#undef DBGMCU_APB1FZ_0_DBG_TIM6_STOP
#undef DBGMCU_APB1FZ_0_DBG_TIM7_STOP
#undef DBGMCU_APB1FZ_0_DBG_TIM12_STOP
#undef DBGMCU_APB1FZ_0_DBG_TIM13_STOP
#undef DBGMCU_APB1FZ_0_DBG_TIM14_STOP
#undef DBGMCU_APB1FZ_0_DBG_TIM18_STOP
#undef DBGMCU_APB2FZ_1_DBG_TIM19_STOP
#undef DBGMCU_APB1FZ_0_DBG_RTC_STOP
#undef DBGMCU_APB1FZ_0_DBG_I2C1_SMBUS_TIMEOUT
#undef DBGMCU_APB1FZ_0_DBG_I2C2_SMBUS_TIMEOUT
#undef DBGMCU_APB1FZ_0_DBG_I2C3_SMBUS_TIMEOUT
#undef DBGMCU_APB2FZ_1_DBG_TIM10_STOP
#undef DBGMCU_APB1FZ_0_DBG_I2C4_SMBUS_TIMEOUT
#undef DBGMCU_APB1FZ_0_DBG_CAN_STOP
#undef DBGMCU_APB1FZ_0_DBG_CAN2_STOP
#undef DBGMCU_APB1FZ_0_DBG_CAN3_STOP
#undef DBGMCU_APB1FZ_1_DBG_LPTIM_STOP
#undef DBGMCU_APB1FZ_0_DBG_LPTIMER_STOP
#undef DBGMCU_APB1FZ_1_DBG_I2C1_STOP
#undef DBGMCU_APB2FZ_0_DBG_TIM21_STOP
#undef DBGMCU_APB1FZ_1_DBG_CAN3_STOP
#undef DBGMCU_APB1FZ_1_DBG_I2C2_STOP
#undef DBGMCU_APB1FZ_1_DBG_I2C3_STOP
#undef DBGMCU_APB1FZ_1_DBG_CAN1_STOP
#undef DBGMCU_APB1FZ_1_DBG_I2C3_SMBUS_TIMEOUT
#undef DBGMCU_MAP1_APB1FZR1
#undef DBGMCU_MAP1_APB1FZR2
#undef DBGMCU_MAP1_APB2FZ
#undef DBGMCU_APB1FZR1_DBG_TIM3_STOP
#undef DBGMCU_APB1FZR1_DBG_TIM4_STOP
#undef DBGMCU_APB1FZR1_DBG_TIM5_STOP
#undef DBGMCU_APB2FZ_1_DBG_TIM8_STOP
#undef DBGMCU_APB1FZR1_DBG_TIM7_STOP
#undef DBGMCU_APB1FZR1_DBG_I2C2_STOP
#undef DBGMCU_APB1FZR1_DBG_CAN2_STOP
#undef DBGMCU_APB1FZR2_DBG_I2C4_STOP
#undef DBGMCU_MAP0_APB3FZ1
#undef DBGMCU_MAP0_APB1LFZ1
#undef DBGMCU_MAP0_APB1HFZ1
#undef DBGMCU_MAP0_APB2FZ1
#undef DBGMCU_MAP0_APB4FZ1
#undef DBGMCU_APB2FZ_0_DBG_TIM8_STOP
#undef DBGMCU_APB2FZ_0_DBG_TIM10_STOP
#undef DBGMCU_APB2FZ_0_DBG_TIM11_STOP
#undef DBGMCU_APB2FZ_2_DBG_TIM9_STOP
#undef DBGMCU_APB2FZ_0_DBG_TIM20_STOP
#undef DBGMCU_APB2FZ_0_DBG_HRTIM1_STOP
#undef DBGMCU_APB2FZ_0_DBG_TIM1_STOP
#undef DBGMCU_APB2FZ_0_DBG_TIM16_STOP
#undef DBGMCU_APB2FZ_0_DBG_TIM15_STOP
#undef DBGMCU_APB2FZ_0_DBG_TIM17_STOP
#undef DBGMCU_APB2FZ_1_DBG_TIM1_STOP
#undef DBGMCU_APB2FZ_1_DBG_TIM15_STOP
#undef DBGMCU_APB2FZ_1_DBG_TIM16_STOP
#undef DBGMCU_APB2FZ_1_DBG_TIM17_STOP
#undef DBGMCU_APB2FZ_1_DBG_TIM9_STOP
#undef DBGMCU_APB2FZ_1_DBG_TIM11_STOP
#undef DBGMCU_APB2FZ_2_DBG_TIM22_STOP
#undef DBGMCU_CR_0_DBG_SLEEP
#undef DBGMCU_CR_0_DBG_STOP
#undef DBGMCU_CR_0_DBG_STANDBY
#undef DBGMCU_CR_0_TRACE_IOEN
#undef DBGMCU_CR_0_TRACE_MODE
#undef DBGMCU_CR_0_DBG_IWDG_STOP
#undef DBGMCU_CR_0_DBG_WWDG_STOP
#undef DBGMCU_CR_0_DBG_TIM2_STOP
#undef DBGMCU_CR_0_DBG_TIM3_STOP
#undef DBGMCU_CR_0_DBG_I2C1_SMBUS_TIMEOUT
#undef DBGMCU_CR_0_DBG_TIM1_STOP
#undef DBGMCU_CR_0_DBG_TIM4_STOP
#undef DBGMCU_CR_0_DBG_I2C2_SMBUS_TIMEOUT
#undef DBGMCU_CR_0_DBG_CAN1_STOP
#undef DBGMCU_CR_0_DBG_TIM8_STOP
#undef DBGMCU_CR_0_DBG_TIM5_STOP
#undef DBGMCU_CR_0_DBG_TIM6_STOP
#undef DBGMCU_CR_0_DBG_TIM7_STOP
#undef DBGMCU_CR_0_DBG_CAN2_STOP
#undef DBGMCU_CR_0_DBG_TIM15_STOP
#undef DBGMCU_CR_0_DBG_TIM16_STOP
#undef DBGMCU_CR_0_DBG_TIM17_STOP
#undef DBGMCU_CR_0_DBG_TIM12_STOP
#undef DBGMCU_CR_0_DBG_TIM13_STOP
#undef DBGMCU_CR_0_DBG_TIM14_STOP
#undef DBGMCU_CR_0_DBG_TIM9_STOP
#undef DBGMCU_CR_0_DBG_TIM10_STOP
#undef DBGMCU_CR_0_DBG_TIM11_STOP
#undef DBGMCU_IDCODE_0_DIV_ID
//endregion
#endif
