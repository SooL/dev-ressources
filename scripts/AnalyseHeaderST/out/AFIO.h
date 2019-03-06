#ifndef __SOOL_AFIO_H
#define __SOOL_AFIO_H

#include "peripheral_include.h"
//SOOL-AFIO-INCLUDES
#if defined(STM32F1     ) 
//region defines

#define AFIO_EVCR
#define AFIO_EXTICR
#define AFIO_MAPR
#define AFIO_MAPR2

#if defined(STM32F100xB ) || defined(STM32F100xE ) || defined(STM32F101xB ) || defined(STM32F101xE ) ||\
    defined(STM32F101xG ) || defined(STM32F102xB ) || defined(STM32F103xB ) || defined(STM32F103xE ) ||\
    defined(STM32F103xG ) || defined(STM32F105xC ) || defined(STM32F107xC ) 
#define AFIO_MAPR_USART3_REMAP USART3_REMAP         // 2 bits @ 4
#define AFIO_MAPR_TIM4_REMAP TIM4_REMAP           // 1 bits @ 12
#else
#define AFIO_MAPR_USART3_REMAP
#define AFIO_MAPR_TIM4_REMAP
#endif

#if defined(STM32F103x6 ) || defined(STM32F103xB ) || defined(STM32F103xE ) || defined(STM32F103xG ) ||\
    defined(STM32F105xC ) || defined(STM32F107xC ) 
#define AFIO_MAPR_CAN_REMAP  CAN_REMAP            // 2 bits @ 13
#else
#define AFIO_MAPR_CAN_REMAP
#endif

#if defined(STM32F100xE ) || defined(STM32F101xE ) || defined(STM32F101xG ) || defined(STM32F103xE ) ||\
    defined(STM32F103xG ) || defined(STM32F105xC ) || defined(STM32F107xC ) 
#define AFIO_MAPR_TIM5CH4_IREMAP TIM5CH4_IREMAP       // 1 bits @ 16
#else
#define AFIO_MAPR_TIM5CH4_IREMAP
#endif

#if defined(STM32F103xE ) || defined(STM32F103xG ) 
#define AFIO_MAPR_ADC1_ETRGINJ_REMAP ADC1_ETRGINJ_REMAP   // 1 bits @ 17
#define AFIO_MAPR_ADC1_ETRGREG_REMAP ADC1_ETRGREG_REMAP   // 1 bits @ 18
#define AFIO_MAPR_ADC2_ETRGINJ_REMAP ADC2_ETRGINJ_REMAP   // 1 bits @ 19
#define AFIO_MAPR_ADC2_ETRGREG_REMAP ADC2_ETRGREG_REMAP   // 1 bits @ 20
#else
#define AFIO_MAPR_ADC1_ETRGINJ_REMAP
#define AFIO_MAPR_ADC1_ETRGREG_REMAP
#define AFIO_MAPR_ADC2_ETRGINJ_REMAP
#define AFIO_MAPR_ADC2_ETRGREG_REMAP
#endif

#if defined(STM32F105xC ) || defined(STM32F107xC ) 
#define AFIO_MAPR_ETH_REMAP  ETH_REMAP            // 1 bits @ 21
#define AFIO_MAPR_CAN2_REMAP CAN2_REMAP           // 1 bits @ 22
#define AFIO_MAPR_MII_RMII_SEL MII_RMII_SEL         // 1 bits @ 23
#define AFIO_MAPR_SPI3_REMAP SPI3_REMAP           // 1 bits @ 28
#define AFIO_MAPR_TIM2ITR1_IREMAP TIM2ITR1_IREMAP      // 1 bits @ 29
#define AFIO_MAPR_PTP_PPS_REMAP PTP_PPS_REMAP        // 1 bits @ 30
#else
#define AFIO_MAPR_ETH_REMAP
#define AFIO_MAPR_CAN2_REMAP
#define AFIO_MAPR_MII_RMII_SEL
#define AFIO_MAPR_SPI3_REMAP
#define AFIO_MAPR_TIM2ITR1_IREMAP
#define AFIO_MAPR_PTP_PPS_REMAP
#endif

#if defined(STM32F100xB ) || defined(STM32F100xE ) 
#define AFIO_MAPR2_TIM15_REMAP TIM15_REMAP          // 1 bits @ 0
#define AFIO_MAPR2_TIM16_REMAP TIM16_REMAP          // 1 bits @ 1
#define AFIO_MAPR2_TIM17_REMAP TIM17_REMAP          // 1 bits @ 2
#define AFIO_MAPR2_CEC_REMAP CEC_REMAP            // 1 bits @ 3
#define AFIO_MAPR2_TIM1_DMA_REMAP TIM1_DMA_REMAP       // 1 bits @ 4
#define AFIO_MAPR2_TIM67_DAC_DMA_REMAP TIM67_DAC_DMA_REMAP  // 1 bits @ 11
#else
#define AFIO_MAPR2_TIM15_REMAP
#define AFIO_MAPR2_TIM16_REMAP
#define AFIO_MAPR2_TIM17_REMAP
#define AFIO_MAPR2_CEC_REMAP
#define AFIO_MAPR2_TIM1_DMA_REMAP
#define AFIO_MAPR2_TIM67_DAC_DMA_REMAP
#endif

#if defined(STM32F101xG ) || defined(STM32F103xG ) 
#define AFIO_MAPR2_TIM9_REMAP TIM9_REMAP           // 1 bits @ 5
#define AFIO_MAPR2_TIM10_REMAP TIM10_REMAP          // 1 bits @ 6
#define AFIO_MAPR2_TIM11_REMAP TIM11_REMAP          // 1 bits @ 7
#else
#define AFIO_MAPR2_TIM9_REMAP
#define AFIO_MAPR2_TIM10_REMAP
#define AFIO_MAPR2_TIM11_REMAP
#endif

#if defined(STM32F100xE ) || defined(STM32F101xG ) || defined(STM32F103xG ) 
#define AFIO_MAPR2_TIM13_REMAP TIM13_REMAP          // 1 bits @ 8
#define AFIO_MAPR2_TIM14_REMAP TIM14_REMAP          // 1 bits @ 9
#else
#define AFIO_MAPR2_TIM13_REMAP
#define AFIO_MAPR2_TIM14_REMAP
#endif

#if defined(STM32F100xE ) || defined(STM32F101xE ) || defined(STM32F101xG ) || defined(STM32F103xE ) ||\
    defined(STM32F103xG ) 
#define AFIO_MAPR2_FSMC_NADV_REMAP FSMC_NADV_REMAP      // 1 bits @ 10
#else
#define AFIO_MAPR2_FSMC_NADV_REMAP
#endif

#if defined(STM32F100xE ) 
#define AFIO_MAPR2_TIM12_REMAP TIM12_REMAP          // 1 bits @ 12
#define AFIO_MAPR2_MISC_REMAP MISC_REMAP           // 1 bits @ 13
#else
#define AFIO_MAPR2_TIM12_REMAP
#define AFIO_MAPR2_MISC_REMAP
#endif

//endregion

namespace sool
{
	namespace core
	{
		class AFIO
		{
			//SOOL-AFIO-ENUMS
			
			public :
			
			#ifdef AFIO_EVCR
			struct EVCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PIN                  :4;
					uint32_t PORT                 :3;
					uint32_t EVOE                 :1;
					uint32_t                      :24;
			
				//SOOL-AFIO_EVCR-DECLARATION
			};
			#endif
			
			#ifdef AFIO_EXTICR
			struct EXTICR_TypeDef : public BigArrayReg_t<uint32_t, 0, 4, 4>
			{
				using BigArrayReg_t<uint32_t, 0, 4, 4>::operator=;
				
					uint32_t EXTI0                :4;
					uint32_t EXTI1                :4;
					uint32_t EXTI2                :4;
					uint32_t EXTI3                :4;
					uint32_t                      :16;
					uint32_t EXTI4                :4;
					uint32_t EXTI5                :4;
					uint32_t EXTI6                :4;
					uint32_t EXTI7                :4;
					uint32_t                      :16;
					uint32_t EXTI8                :4;
					uint32_t EXTI9                :4;
					uint32_t EXTI10               :4;
					uint32_t EXTI11               :4;
					uint32_t                      :16;
					uint32_t EXTI12               :4;
					uint32_t EXTI13               :4;
					uint32_t EXTI14               :4;
					uint32_t EXTI15               :4;
					uint32_t                      :16;
			
				//SOOL-AFIO_EXTICR-DECLARATION
			};
			#endif
			
			#ifdef AFIO_MAPR
			struct MAPR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SPI1_REMAP           :1;
					uint32_t I2C1_REMAP           :1;
					uint32_t USART1_REMAP         :1;
					uint32_t USART2_REMAP         :1;
					uint32_t AFIO_MAPR_USART3_REMAP :2;
					uint32_t TIM1_REMAP           :2;
					uint32_t TIM2_REMAP           :2;
					uint32_t TIM3_REMAP           :2;
					uint32_t AFIO_MAPR_TIM4_REMAP :1;
					uint32_t AFIO_MAPR_CAN_REMAP  :2;
					uint32_t PD01_REMAP           :1;
					uint32_t AFIO_MAPR_TIM5CH4_IREMAP :1;
					uint32_t AFIO_MAPR_ADC1_ETRGINJ_REMAP :1;
					uint32_t AFIO_MAPR_ADC1_ETRGREG_REMAP :1;
					uint32_t AFIO_MAPR_ADC2_ETRGINJ_REMAP :1;
					uint32_t AFIO_MAPR_ADC2_ETRGREG_REMAP :1;
					uint32_t AFIO_MAPR_ETH_REMAP  :1;
					uint32_t AFIO_MAPR_CAN2_REMAP :1;
					uint32_t AFIO_MAPR_MII_RMII_SEL :1;
					uint32_t SWJ_CFG              :3;
					uint32_t                      :1;
					uint32_t AFIO_MAPR_SPI3_REMAP :1;
					uint32_t AFIO_MAPR_TIM2ITR1_IREMAP :1;
					uint32_t AFIO_MAPR_PTP_PPS_REMAP :1;
					uint32_t                      :1;
			
				//SOOL-AFIO_MAPR-DECLARATION
			};
			#endif
			
			#ifdef AFIO_MAPR2
			struct MAPR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t AFIO_MAPR2_TIM15_REMAP :1;
					uint32_t AFIO_MAPR2_TIM16_REMAP :1;
					uint32_t AFIO_MAPR2_TIM17_REMAP :1;
					uint32_t AFIO_MAPR2_CEC_REMAP :1;
					uint32_t AFIO_MAPR2_TIM1_DMA_REMAP :1;
					uint32_t AFIO_MAPR2_TIM9_REMAP :1;
					uint32_t AFIO_MAPR2_TIM10_REMAP :1;
					uint32_t AFIO_MAPR2_TIM11_REMAP :1;
					uint32_t AFIO_MAPR2_TIM13_REMAP :1;
					uint32_t AFIO_MAPR2_TIM14_REMAP :1;
					uint32_t AFIO_MAPR2_FSMC_NADV_REMAP :1;
					uint32_t AFIO_MAPR2_TIM67_DAC_DMA_REMAP :1;
					uint32_t AFIO_MAPR2_TIM12_REMAP :1;
					uint32_t AFIO_MAPR2_MISC_REMAP :1;
					uint32_t                      :18;
			
				//SOOL-AFIO_MAPR2-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					EVCR_TypeDef EVCR;   // @0x000
					MAPR_TypeDef MAPR;   // @0x004
					EXTICR_TypeDef EXTICR; // @0x008
					__SOOL_PERIPH_PADDING_4;
					MAPR2_TypeDef MAPR2; // @0x01c
				};
			};
			private:
			AFIO() = delete;
			//SOOL-AFIO-DECLARATION
		};
		
		//region instances
#define AFIO_BASE_ADDR ((uint32_t)0x40010000U)
#ifdef AFIO_BASE_ADDR
volatile class AFIO * const AFIO = reinterpret_cast<class AFIO* const>(AFIO_BASE_ADDR);
#endif
//endregion

//SOOL-AFIO-DEFINES
//SOOL-AFIO-DEFINITION
	};
};//region undef
#undef AFIO_MAPR_USART3_REMAP
#undef AFIO_MAPR_TIM4_REMAP
#undef AFIO_MAPR_CAN_REMAP
#undef AFIO_MAPR_TIM5CH4_IREMAP
#undef AFIO_MAPR_ADC1_ETRGINJ_REMAP
#undef AFIO_MAPR_ADC1_ETRGREG_REMAP
#undef AFIO_MAPR_ADC2_ETRGINJ_REMAP
#undef AFIO_MAPR_ADC2_ETRGREG_REMAP
#undef AFIO_MAPR_ETH_REMAP
#undef AFIO_MAPR_CAN2_REMAP
#undef AFIO_MAPR_MII_RMII_SEL
#undef AFIO_MAPR_SPI3_REMAP
#undef AFIO_MAPR_TIM2ITR1_IREMAP
#undef AFIO_MAPR_PTP_PPS_REMAP
#undef AFIO_MAPR2_TIM15_REMAP
#undef AFIO_MAPR2_TIM16_REMAP
#undef AFIO_MAPR2_TIM17_REMAP
#undef AFIO_MAPR2_CEC_REMAP
#undef AFIO_MAPR2_TIM1_DMA_REMAP
#undef AFIO_MAPR2_TIM67_DAC_DMA_REMAP
#undef AFIO_MAPR2_TIM9_REMAP
#undef AFIO_MAPR2_TIM10_REMAP
#undef AFIO_MAPR2_TIM11_REMAP
#undef AFIO_MAPR2_TIM13_REMAP
#undef AFIO_MAPR2_TIM14_REMAP
#undef AFIO_MAPR2_FSMC_NADV_REMAP
#undef AFIO_MAPR2_TIM12_REMAP
#undef AFIO_MAPR2_MISC_REMAP
//endregion
#endif
#endif
