#ifndef __SOOL_DMA_H
#define __SOOL_DMA_H

#include "peripheral_include.h"
//SOOL-DMA-INCLUDES
//region defines

#if defined(STM32F030xC ) || defined(STM32F091xC ) || defined(STM32F098xx ) 
#define DMA_CSELR
#define DMA_MAP0_CSELR       typename plugin::CSELR_TypeDef CSELR
#define DMA1_CSELR_4_CH4_TIM16_CH1 CH4_TIM16_CH1        // 3 bits @ 12
#else
#define DMA_MAP0_CSELR __SOOL_PERIPH_PADDING_4
#define DMA1_CSELR_4_CH4_TIM16_CH1
#endif

#if defined(STM32F030xC ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32L031xx ) ||\
    defined(STM32L041xx ) || defined(STM32L051xx ) || defined(STM32L052xx ) || defined(STM32L053xx ) ||\
    defined(STM32L061xx ) || defined(STM32L062xx ) || defined(STM32L063xx ) || defined(STM32L071xx ) ||\
    defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L081xx ) || defined(STM32L082xx ) ||\
    defined(STM32L083xx ) || defined(STM32L4     ) 
#define DMA_CSELR_C6S        C6S                  // 4 bits @ 20
#define DMA_CSELR_C7S        C7S                  // 4 bits @ 24
#define DMA1_CSELR_10
#define DMA1_CSELR_6_C7S     C7S                  // 4 bits @ 24
#define DMA2_CSELR_0
#else
#define DMA_CSELR_C6S
#define DMA_CSELR_C7S
#define DMA1_CSELR_6_C7S
#endif

#if defined(STM32F2     ) || defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32H7     ) 
#define DMA_HIFCR
#define DMA_HISR
#define DMA_LIFCR
#define DMA_LISR
#define DMA_MAP1_LISR        LISR_TypeDef LISR
#define DMA_MAP1_HISR        HISR_TypeDef HISR
#define DMA_MAP0_LIFCR       LIFCR_TypeDef LIFCR
#define DMA_MAP0_HIFCR       HIFCR_TypeDef HIFCR
#else
#define DMA_MAP1_LISR __SOOL_PERIPH_PADDING_4
#define DMA_MAP1_HISR __SOOL_PERIPH_PADDING_4
#define DMA_MAP0_LIFCR __SOOL_PERIPH_PADDING_4
#define DMA_MAP0_HIFCR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F3     ) || defined(STM32L0     ) ||\
    defined(STM32L1     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define DMA_IFCR
#define DMA_ISR
#define DMA_MAP0_ISR         ISR_TypeDef ISR
#define DMA_MAP0_IFCR        IFCR_TypeDef IFCR
#else
#define DMA_MAP0_ISR __SOOL_PERIPH_PADDING_4
#define DMA_MAP0_IFCR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F042x6 ) || defined(STM32F048xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F1     ) ||\
    defined(STM32F3     ) || defined(STM32L031xx ) || defined(STM32L041xx ) || defined(STM32L051xx ) ||\
    defined(STM32L052xx ) || defined(STM32L053xx ) || defined(STM32L061xx ) || defined(STM32L062xx ) ||\
    defined(STM32L063xx ) || defined(STM32L071xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) ||\
    defined(STM32L081xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) || defined(STM32L1     ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
#define DMA_IFCR_CGIF6       CGIF6                // 1 bits @ 20
#define DMA_IFCR_CTCIF6      CTCIF6               // 1 bits @ 21
#define DMA_IFCR_CHTIF6      CHTIF6               // 1 bits @ 22
#define DMA_IFCR_CTEIF6      CTEIF6               // 1 bits @ 23
#define DMA_IFCR_CGIF7       CGIF7                // 1 bits @ 24
#define DMA_IFCR_CTCIF7      CTCIF7               // 1 bits @ 25
#define DMA_IFCR_CHTIF7      CHTIF7               // 1 bits @ 26
#define DMA_IFCR_CTEIF7      CTEIF7               // 1 bits @ 27
#define DMA_ISR_GIF6         GIF6                 // 1 bits @ 20
#define DMA_ISR_TCIF6        TCIF6                // 1 bits @ 21
#define DMA_ISR_HTIF6        HTIF6                // 1 bits @ 22
#define DMA_ISR_TEIF6        TEIF6                // 1 bits @ 23
#define DMA_ISR_GIF7         GIF7                 // 1 bits @ 24
#define DMA_ISR_TCIF7        TCIF7                // 1 bits @ 25
#define DMA_ISR_HTIF7        HTIF7                // 1 bits @ 26
#define DMA_ISR_TEIF7        TEIF7                // 1 bits @ 27
#else
#define DMA_IFCR_CGIF6
#define DMA_IFCR_CTCIF6
#define DMA_IFCR_CHTIF6
#define DMA_IFCR_CTEIF6
#define DMA_IFCR_CGIF7
#define DMA_IFCR_CTCIF7
#define DMA_IFCR_CHTIF7
#define DMA_IFCR_CTEIF7
#define DMA_ISR_GIF6
#define DMA_ISR_TCIF6
#define DMA_ISR_HTIF6
#define DMA_ISR_TEIF6
#define DMA_ISR_GIF7
#define DMA_ISR_TCIF7
#define DMA_ISR_HTIF7
#define DMA_ISR_TEIF7
#endif

#define DMA_Request_CSELR
#define DMA_Stream_CR
#define DMA_Stream_FCR
#define DMA_Stream_M0AR
#define DMA_Stream_M1AR
#define DMA_Stream_NDTR
#define DMA_Stream_PAR
#define DMA_Channel_CCR
#define DMA_Channel_CMAR
#define DMA_Channel_CNDTR
#define DMA_Channel_CPAR

#if defined(STM32F2     ) || defined(STM32F4     ) 
#define DMA_Stream_CR_0_ACK  ACK                  // 1 bits @ 20
#else
#define DMA_Stream_CR_0_ACK
#endif

#if defined(STM32F2     ) || defined(STM32F401xC ) || defined(STM32F401xE ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F410Cx ) || defined(STM32F410Rx ) || defined(STM32F410Tx ) ||\
    defined(STM32F411xE ) || defined(STM32F412Cx ) || defined(STM32F412Rx ) || defined(STM32F412Vx ) ||\
    defined(STM32F412Zx ) || defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F427xx ) ||\
    defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) ||\
    defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F745xx ) || defined(STM32F746xx ) ||\
    defined(STM32F756xx ) 
#define DMA_Stream_CR_0_CHSEL CHSEL                // 3 bits @ 25
#else
#define DMA_Stream_CR_0_CHSEL
#endif

#if defined(STM32F413xx ) || defined(STM32F423xx ) || defined(STM32F722xx ) || defined(STM32F723xx ) ||\
    defined(STM32F732xx ) || defined(STM32F733xx ) || defined(STM32F765xx ) || defined(STM32F767xx ) ||\
    defined(STM32F769xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) 
#define DMA_Stream_CR_1
#endif

#if defined(STM32F091xC ) || defined(STM32F098xx ) 
#define DMA1_CSELR_0_CH6_I2C1_TX CH6_I2C1_TX          // 1 bits @ 21
#define DMA1_CSELR_0_CH6_TIM1_CH1 CH6_TIM1_CH1         // 1 bits @ 22
#define DMA1_CSELR_0_CH6_USART1_RX CH6_USART1_RX        // 1 bits @ 23
#define DMA1_CSELR_0_CH7_I2C1_RX CH7_I2C1_RX          // 1 bits @ 25
#define DMA1_CSELR_0_CH7_USART1_TX CH7_USART1_TX        // 1 bits @ 27
#define DMA1_CSELR_1_CH6_SPI2_RX CH6_SPI2_RX          // 2 bits @ 20
#define DMA1_CSELR_1_CH6_TIM1_CH2 CH6_TIM1_CH2         // 1 bits @ 22
#define DMA1_CSELR_1_CH7_SPI2_TX CH7_SPI2_TX          // 2 bits @ 24
#define DMA1_CSELR_1_CH7_USART5_TX CH7_USART5_TX        // 2 bits @ 26
#define DMA1_CSELR_2_CH4_DAC_CH2 CH4_DAC_CH2          // 1 bits @ 12
#define DMA1_CSELR_2_CH5_USART7_RX CH5_USART7_RX        // 3 bits @ 17
#define DMA1_CSELR_2_CH6_TIM1_CH3 CH6_TIM1_CH3         // 1 bits @ 22
#define DMA1_CSELR_2_CH7_TIM17_CH1 CH7_TIM17_CH1        // 3 bits @ 24
#define DMA1_CSELR_3_CH5_USART8_RX CH5_USART8_RX        // 4 bits @ 16
#define DMA1_CSELR_3_CH6_TIM3_CH1 CH6_TIM3_CH1         // 2 bits @ 21
#define DMA1_CSELR_3_CH7_TIM17_UP CH7_TIM17_UP         // 3 bits @ 24
#define DMA1_CSELR_4_CH1_USART7_RX CH1_USART7_RX        // 3 bits @ 1
#define DMA1_CSELR_4_CH2_USART7_TX CH2_USART7_TX        // 3 bits @ 5
#define DMA1_CSELR_4_CH3_DAC_CH1 CH3_DAC_CH1          // 1 bits @ 8
#define DMA1_CSELR_4_CH3_USART7_RX CH3_USART7_RX        // 3 bits @ 9
#define DMA1_CSELR_4_CH6_TIM3_TRIG CH6_TIM3_TRIG        // 2 bits @ 21
#define DMA1_CSELR_4_CH7_USART7_TX CH7_USART7_TX        // 3 bits @ 25
#define DMA1_CSELR_5_CH1_USART8_RX CH1_USART8_RX        // 4 bits @ 0
#define DMA1_CSELR_5_CH2_USART8_TX CH2_USART8_TX        // 4 bits @ 4
#define DMA1_CSELR_5_CH3_USART8_RX CH3_USART8_RX        // 4 bits @ 8
#define DMA1_CSELR_5_CH6_TIM16_CH1 CH6_TIM16_CH1        // 3 bits @ 20
#define DMA1_CSELR_5_CH7_USART8_TX CH7_USART8_TX        // 4 bits @ 24
#define DMA1_CSELR_6_CH4_USART7_TX CH4_USART7_TX        // 3 bits @ 13
#define DMA1_CSELR_6_CH6_TIM16_UP CH6_TIM16_UP         // 3 bits @ 20
#define DMA1_CSELR_7
#define DMA1_CSELR_8_CH6_USART7_RX CH6_USART7_RX        // 3 bits @ 21
#define DMA1_CSELR_9
#define DMA2_CSELR_0_DEFAULT DEFAULT              // 0 bits @ 0
#define DMA2_CSELR_0_CH1_I2C2_TX CH1_I2C2_TX          // 1 bits @ 1
#define DMA2_CSELR_0_CH1_USART1_TX CH1_USART1_TX        // 1 bits @ 3
#define DMA2_CSELR_0_CH2_I2C2_RX CH2_I2C2_RX          // 1 bits @ 5
#define DMA2_CSELR_0_CH2_USART1_RX CH2_USART1_RX        // 1 bits @ 7
#define DMA2_CSELR_0_CH3_TIM6_UP CH3_TIM6_UP          // 1 bits @ 8
#define DMA2_CSELR_0_CH3_USART1_RX CH3_USART1_RX        // 1 bits @ 11
#define DMA2_CSELR_0_CH4_TIM7_UP CH4_TIM7_UP          // 1 bits @ 12
#define DMA2_CSELR_0_CH4_USART1_TX CH4_USART1_TX        // 1 bits @ 15
#define DMA2_CSELR_0_CH5_ADC CH5_ADC              // 1 bits @ 16
#define DMA2_CSELR_0_CH5_USART1_TX CH5_USART1_TX        // 1 bits @ 19
#define DMA2_CSELR_1
#define DMA2_CSELR_2
#define DMA2_CSELR_3
#define DMA2_CSELR_4_CH3_USART8_RX CH3_USART8_RX        // 4 bits @ 8
#define DMA2_CSELR_4_CH4_USART8_TX CH4_USART8_TX        // 4 bits @ 12
#else
#define DMA1_CSELR_0_CH6_I2C1_TX
#define DMA1_CSELR_0_CH6_TIM1_CH1
#define DMA1_CSELR_0_CH6_USART1_RX
#define DMA1_CSELR_0_CH7_I2C1_RX
#define DMA1_CSELR_0_CH7_USART1_TX
#define DMA1_CSELR_1_CH6_SPI2_RX
#define DMA1_CSELR_1_CH6_TIM1_CH2
#define DMA1_CSELR_1_CH7_SPI2_TX
#define DMA1_CSELR_1_CH7_USART5_TX
#define DMA1_CSELR_2_CH4_DAC_CH2
#define DMA1_CSELR_2_CH5_USART7_RX
#define DMA1_CSELR_2_CH6_TIM1_CH3
#define DMA1_CSELR_2_CH7_TIM17_CH1
#define DMA1_CSELR_3_CH5_USART8_RX
#define DMA1_CSELR_3_CH6_TIM3_CH1
#define DMA1_CSELR_3_CH7_TIM17_UP
#define DMA1_CSELR_4_CH1_USART7_RX
#define DMA1_CSELR_4_CH2_USART7_TX
#define DMA1_CSELR_4_CH3_DAC_CH1
#define DMA1_CSELR_4_CH3_USART7_RX
#define DMA1_CSELR_4_CH6_TIM3_TRIG
#define DMA1_CSELR_4_CH7_USART7_TX
#define DMA1_CSELR_5_CH1_USART8_RX
#define DMA1_CSELR_5_CH2_USART8_TX
#define DMA1_CSELR_5_CH3_USART8_RX
#define DMA1_CSELR_5_CH6_TIM16_CH1
#define DMA1_CSELR_5_CH7_USART8_TX
#define DMA1_CSELR_6_CH4_USART7_TX
#define DMA1_CSELR_6_CH6_TIM16_UP
#define DMA1_CSELR_8_CH6_USART7_RX
#define DMA2_CSELR_0_DEFAULT
#define DMA2_CSELR_0_CH1_I2C2_TX
#define DMA2_CSELR_0_CH1_USART1_TX
#define DMA2_CSELR_0_CH2_I2C2_RX
#define DMA2_CSELR_0_CH2_USART1_RX
#define DMA2_CSELR_0_CH3_TIM6_UP
#define DMA2_CSELR_0_CH3_USART1_RX
#define DMA2_CSELR_0_CH4_TIM7_UP
#define DMA2_CSELR_0_CH4_USART1_TX
#define DMA2_CSELR_0_CH5_ADC
#define DMA2_CSELR_0_CH5_USART1_TX
#define DMA2_CSELR_4_CH3_USART8_RX
#define DMA2_CSELR_4_CH4_USART8_TX
#endif

#if defined(STM32F030xC ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32L0     ) ||\
    defined(STM32L4     ) 
#define DMA1_CSELR_4
#define DMA1_CSELR_6
#define DMA1_CSELR_8
#define DMA2_CSELR_4
#define DMA2_CSELR_5
#endif

//endregion

namespace sool
{
	namespace core
	{struct DMA_base_plugin
		{
		
			#ifdef DMA_CSELR
			struct CSELR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t C1S                  :4;
					uint32_t C2S                  :4;
					uint32_t C3S                  :4;
					uint32_t C4S                  :4;
					uint32_t C5S                  :4;
					uint32_t DMA_CSELR_C6S        :4;
					uint32_t DMA_CSELR_C7S        :4;
					uint32_t                      :4;
			
				//SOOL-DMA_CSELR-DECLARATION
			};
			#endif
			};
		template<typename plugin=DMA_base_plugin>
		class DMA
		{
			//SOOL-DMA-ENUMS
			
			public :
			
			#ifdef DMA_HIFCR
			struct HIFCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CFEIF4               :1;
					uint32_t                      :1;
					uint32_t CDMEIF4              :1;
					uint32_t CTEIF4               :1;
					uint32_t CHTIF4               :1;
					uint32_t CTCIF4               :1;
					uint32_t CFEIF5               :1;
					uint32_t                      :1;
					uint32_t CDMEIF5              :1;
					uint32_t CTEIF5               :1;
					uint32_t CHTIF5               :1;
					uint32_t CTCIF5               :1;
					uint32_t                      :4;
					uint32_t CFEIF6               :1;
					uint32_t                      :1;
					uint32_t CDMEIF6              :1;
					uint32_t CTEIF6               :1;
					uint32_t CHTIF6               :1;
					uint32_t CTCIF6               :1;
					uint32_t CFEIF7               :1;
					uint32_t                      :1;
					uint32_t CDMEIF7              :1;
					uint32_t CTEIF7               :1;
					uint32_t CHTIF7               :1;
					uint32_t CTCIF7               :1;
					uint32_t                      :4;
			
				//SOOL-DMA_HIFCR-DECLARATION
			};
			#endif
			
			#ifdef DMA_HISR
			struct HISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FEIF4                :1;
					uint32_t                      :1;
					uint32_t DMEIF4               :1;
					uint32_t TEIF4                :1;
					uint32_t HTIF4                :1;
					uint32_t TCIF4                :1;
					uint32_t FEIF5                :1;
					uint32_t                      :1;
					uint32_t DMEIF5               :1;
					uint32_t TEIF5                :1;
					uint32_t HTIF5                :1;
					uint32_t TCIF5                :1;
					uint32_t                      :4;
					uint32_t FEIF6                :1;
					uint32_t                      :1;
					uint32_t DMEIF6               :1;
					uint32_t TEIF6                :1;
					uint32_t HTIF6                :1;
					uint32_t TCIF6                :1;
					uint32_t FEIF7                :1;
					uint32_t                      :1;
					uint32_t DMEIF7               :1;
					uint32_t TEIF7                :1;
					uint32_t HTIF7                :1;
					uint32_t TCIF7                :1;
					uint32_t                      :4;
			
				//SOOL-DMA_HISR-DECLARATION
			};
			#endif
			
			#ifdef DMA_IFCR
			struct IFCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CGIF1                :1;
					uint32_t CTCIF1               :1;
					uint32_t CHTIF1               :1;
					uint32_t CTEIF1               :1;
					uint32_t CGIF2                :1;
					uint32_t CTCIF2               :1;
					uint32_t CHTIF2               :1;
					uint32_t CTEIF2               :1;
					uint32_t CGIF3                :1;
					uint32_t CTCIF3               :1;
					uint32_t CHTIF3               :1;
					uint32_t CTEIF3               :1;
					uint32_t CGIF4                :1;
					uint32_t CTCIF4               :1;
					uint32_t CHTIF4               :1;
					uint32_t CTEIF4               :1;
					uint32_t CGIF5                :1;
					uint32_t CTCIF5               :1;
					uint32_t CHTIF5               :1;
					uint32_t CTEIF5               :1;
					uint32_t DMA_IFCR_CGIF6       :1;
					uint32_t DMA_IFCR_CTCIF6      :1;
					uint32_t DMA_IFCR_CHTIF6      :1;
					uint32_t DMA_IFCR_CTEIF6      :1;
					uint32_t DMA_IFCR_CGIF7       :1;
					uint32_t DMA_IFCR_CTCIF7      :1;
					uint32_t DMA_IFCR_CHTIF7      :1;
					uint32_t DMA_IFCR_CTEIF7      :1;
					uint32_t                      :4;
			
				//SOOL-DMA_IFCR-DECLARATION
			};
			#endif
			
			#ifdef DMA_ISR
			struct ISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t GIF1                 :1;
					uint32_t TCIF1                :1;
					uint32_t HTIF1                :1;
					uint32_t TEIF1                :1;
					uint32_t GIF2                 :1;
					uint32_t TCIF2                :1;
					uint32_t HTIF2                :1;
					uint32_t TEIF2                :1;
					uint32_t GIF3                 :1;
					uint32_t TCIF3                :1;
					uint32_t HTIF3                :1;
					uint32_t TEIF3                :1;
					uint32_t GIF4                 :1;
					uint32_t TCIF4                :1;
					uint32_t HTIF4                :1;
					uint32_t TEIF4                :1;
					uint32_t GIF5                 :1;
					uint32_t TCIF5                :1;
					uint32_t HTIF5                :1;
					uint32_t TEIF5                :1;
					uint32_t DMA_ISR_GIF6         :1;
					uint32_t DMA_ISR_TCIF6        :1;
					uint32_t DMA_ISR_HTIF6        :1;
					uint32_t DMA_ISR_TEIF6        :1;
					uint32_t DMA_ISR_GIF7         :1;
					uint32_t DMA_ISR_TCIF7        :1;
					uint32_t DMA_ISR_HTIF7        :1;
					uint32_t DMA_ISR_TEIF7        :1;
					uint32_t                      :4;
			
				//SOOL-DMA_ISR-DECLARATION
			};
			#endif
			
			#ifdef DMA_LIFCR
			struct LIFCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CFEIF0               :1;
					uint32_t                      :1;
					uint32_t CDMEIF0              :1;
					uint32_t CTEIF0               :1;
					uint32_t CHTIF0               :1;
					uint32_t CTCIF0               :1;
					uint32_t CFEIF1               :1;
					uint32_t                      :1;
					uint32_t CDMEIF1              :1;
					uint32_t CTEIF1               :1;
					uint32_t CHTIF1               :1;
					uint32_t CTCIF1               :1;
					uint32_t                      :4;
					uint32_t CFEIF2               :1;
					uint32_t                      :1;
					uint32_t CDMEIF2              :1;
					uint32_t CTEIF2               :1;
					uint32_t CHTIF2               :1;
					uint32_t CTCIF2               :1;
					uint32_t CFEIF3               :1;
					uint32_t                      :1;
					uint32_t CDMEIF3              :1;
					uint32_t CTEIF3               :1;
					uint32_t CHTIF3               :1;
					uint32_t CTCIF3               :1;
					uint32_t                      :4;
			
				//SOOL-DMA_LIFCR-DECLARATION
			};
			#endif
			
			#ifdef DMA_LISR
			struct LISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FEIF0                :1;
					uint32_t                      :1;
					uint32_t DMEIF0               :1;
					uint32_t TEIF0                :1;
					uint32_t HTIF0                :1;
					uint32_t TCIF0                :1;
					uint32_t FEIF1                :1;
					uint32_t                      :1;
					uint32_t DMEIF1               :1;
					uint32_t TEIF1                :1;
					uint32_t HTIF1                :1;
					uint32_t TCIF1                :1;
					uint32_t                      :4;
					uint32_t FEIF2                :1;
					uint32_t                      :1;
					uint32_t DMEIF2               :1;
					uint32_t TEIF2                :1;
					uint32_t HTIF2                :1;
					uint32_t TCIF2                :1;
					uint32_t FEIF3                :1;
					uint32_t                      :1;
					uint32_t DMEIF3               :1;
					uint32_t TEIF3                :1;
					uint32_t HTIF3                :1;
					uint32_t TCIF3                :1;
					uint32_t                      :4;
			
				//SOOL-DMA_LISR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					DMA_MAP0_ISR;        // @0x000
					DMA_MAP0_IFCR;       // @0x004
					DMA_MAP0_LIFCR;      // @0x008
					DMA_MAP0_HIFCR;      // @0x00c
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					DMA_MAP0_CSELR;      // @0x0a8
				};
				struct
				{
					DMA_MAP1_LISR;       // @0x000
					DMA_MAP1_HISR;       // @0x004
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_4;
				};
			};
			private:
			DMA() = delete;
			//SOOL-DMA-DECLARATION
		};
		
		
		class DMA_Request
		{
			//SOOL-DMA_Request-ENUMS
			
			public :
			
			union
			{
				
				struct
				{
					uint32_t CSELR;      // @0x000
				};
			};
			private:
			DMA_Request() = delete;
			//SOOL-DMA_Request-DECLARATION
		};
		
		
		class DMA_Stream
		{
			//SOOL-DMA_Stream-ENUMS
			
			public :
			
			#ifdef DMA_Stream_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t EN                   :1;
						uint32_t DMEIE                :1;
						uint32_t TEIE                 :1;
						uint32_t HTIE                 :1;
						uint32_t TCIE                 :1;
						uint32_t PFCTRL               :1;
						uint32_t DIR                  :2;
						uint32_t CIRC                 :1;
						uint32_t PINC                 :1;
						uint32_t MINC                 :1;
						uint32_t PSIZE                :2;
						uint32_t MSIZE                :2;
						uint32_t PINCOS               :1;
						uint32_t PL                   :2;
						uint32_t DBM                  :1;
						uint32_t CT                   :1;
						uint32_t DMA_Stream_CR_0_ACK  :1;
						uint32_t PBURST               :2;
						uint32_t MBURST               :2;
						uint32_t DMA_Stream_CR_0_CHSEL :3;
						uint32_t                      :4;
					};
					#ifdef DMA_Stream_CR_1
					struct
					{
						uint32_t                      :25;
						uint32_t CHSEL                :4;
						uint32_t                      :3;
					};
					#endif
				};
				//SOOL-DMA_Stream_CR-DECLARATION
			};
			#endif
			
			#ifdef DMA_Stream_FCR
			struct FCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FTH                  :2;
					uint32_t DMDIS                :1;
					uint32_t FS                   :3;
					uint32_t                      :1;
					uint32_t FEIE                 :1;
					uint32_t                      :24;
			
				//SOOL-DMA_Stream_FCR-DECLARATION
			};
			#endif
			
			#ifdef DMA_Stream_M0AR
			struct M0AR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t M0A                  :32;
			
				//SOOL-DMA_Stream_M0AR-DECLARATION
			};
			#endif
			
			#ifdef DMA_Stream_M1AR
			struct M1AR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t M1A                  :32;
			
				//SOOL-DMA_Stream_M1AR-DECLARATION
			};
			#endif
			
			#ifdef DMA_Stream_NDTR
			struct NDTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t NDT0                 :1;
					uint32_t NDT1                 :1;
					uint32_t NDT2                 :1;
					uint32_t NDT3                 :1;
					uint32_t NDT4                 :1;
					uint32_t NDT5                 :1;
					uint32_t NDT6                 :1;
					uint32_t NDT7                 :1;
					uint32_t NDT8                 :1;
					uint32_t NDT9                 :1;
					uint32_t NDT10                :1;
					uint32_t NDT11                :1;
					uint32_t NDT12                :1;
					uint32_t NDT13                :1;
					uint32_t NDT14                :1;
					uint32_t NDT15                :1;
					uint32_t                      :16;
			
				//SOOL-DMA_Stream_NDTR-DECLARATION
			};
			#endif
			
			#ifdef DMA_Stream_PAR
			struct PAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PA                   :32;
			
				//SOOL-DMA_Stream_PAR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					NDTR_TypeDef NDTR;   // @0x004
					PAR_TypeDef PAR;     // @0x008
					M0AR_TypeDef M0AR;   // @0x00c
					M1AR_TypeDef M1AR;   // @0x010
					FCR_TypeDef FCR;     // @0x014
				};
			};
			private:
			DMA_Stream() = delete;
			//SOOL-DMA_Stream-DECLARATION
		};
		
		
		class DMA_Channel
		{
			//SOOL-DMA_Channel-ENUMS
			
			public :
			
			#ifdef DMA_Channel_CCR
			struct CCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EN                   :1;
					uint32_t TCIE                 :1;
					uint32_t HTIE                 :1;
					uint32_t TEIE                 :1;
					uint32_t DIR                  :1;
					uint32_t CIRC                 :1;
					uint32_t PINC                 :1;
					uint32_t MINC                 :1;
					uint32_t PSIZE                :2;
					uint32_t MSIZE                :2;
					uint32_t PL                   :2;
					uint32_t MEM2MEM              :1;
					uint32_t                      :17;
			
				//SOOL-DMA_Channel_CCR-DECLARATION
			};
			#endif
			
			#ifdef DMA_Channel_CMAR
			struct CMAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MA                   :32;
			
				//SOOL-DMA_Channel_CMAR-DECLARATION
			};
			#endif
			
			#ifdef DMA_Channel_CNDTR
			struct CNDTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t NDT                  :16;
					uint32_t                      :16;
			
				//SOOL-DMA_Channel_CNDTR-DECLARATION
			};
			#endif
			
			#ifdef DMA_Channel_CPAR
			struct CPAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PA                   :32;
			
				//SOOL-DMA_Channel_CPAR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CCR_TypeDef CCR;     // @0x000
					CNDTR_TypeDef CNDTR; // @0x004
					CPAR_TypeDef CPAR;   // @0x008
					CMAR_TypeDef CMAR;   // @0x00c
				};
			};
			private:
			DMA_Channel() = delete;
			//SOOL-DMA_Channel-DECLARATION
		};
		
		//region instances
#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F3     ) || defined(STM32H7     ) ||\
    defined(STM32L0     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define DMA1_BASE_ADDR ((uint32_t)0x40020000U)
#endif

#if defined(STM32F2     ) || defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L1     ) 
#define DMA1_BASE_ADDR ((uint32_t)0x40026000U)
#endif

#if defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F100xE ) || defined(STM32F101xE ) ||\
    defined(STM32F101xG ) || defined(STM32F103xE ) || defined(STM32F103xG ) || defined(STM32F105xC ) ||\
    defined(STM32F107xC ) || defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F358xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) ||\
    defined(STM32F398xx ) || defined(STM32H7     ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define DMA2_BASE_ADDR ((uint32_t)0x40020400U)
#endif

#if defined(STM32F2     ) || defined(STM32F4     ) || defined(STM32F7     ) || defined(STM32L100xC ) ||\
    defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) || defined(STM32L151xDx) ||\
    defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) || defined(STM32L152xD ) ||\
    defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) || defined(STM32L162xCA) ||\
    defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define DMA2_BASE_ADDR ((uint32_t)0x40026400U)
#endif

#if defined(STM32L0     ) || defined(STM32L4     ) 
#define DMA1_CSELR_BASE_ADDR ((uint32_t)0x400200A8U)
#endif

#if defined(STM32L4     ) 
#define DMA2_CSELR_BASE_ADDR ((uint32_t)0x400204A8U)
#endif

#if defined(STM32F2     ) || defined(STM32F4     ) || defined(STM32F7     ) 
#define DMA1_Stream0_BASE_ADDR ((uint32_t)0x40026010U)
#define DMA1_Stream1_BASE_ADDR ((uint32_t)0x40026028U)
#define DMA1_Stream2_BASE_ADDR ((uint32_t)0x40026040U)
#define DMA1_Stream3_BASE_ADDR ((uint32_t)0x40026058U)
#define DMA1_Stream4_BASE_ADDR ((uint32_t)0x40026070U)
#define DMA1_Stream5_BASE_ADDR ((uint32_t)0x40026088U)
#define DMA1_Stream6_BASE_ADDR ((uint32_t)0x400260A0U)
#define DMA1_Stream7_BASE_ADDR ((uint32_t)0x400260B8U)
#define DMA2_Stream0_BASE_ADDR ((uint32_t)0x40026410U)
#define DMA2_Stream1_BASE_ADDR ((uint32_t)0x40026428U)
#define DMA2_Stream2_BASE_ADDR ((uint32_t)0x40026440U)
#define DMA2_Stream3_BASE_ADDR ((uint32_t)0x40026458U)
#define DMA2_Stream4_BASE_ADDR ((uint32_t)0x40026470U)
#define DMA2_Stream5_BASE_ADDR ((uint32_t)0x40026488U)
#define DMA2_Stream6_BASE_ADDR ((uint32_t)0x400264A0U)
#define DMA2_Stream7_BASE_ADDR ((uint32_t)0x400264B8U)
#endif

#if defined(STM32H7     ) 
#define DMA1_Stream0_BASE_ADDR ((uint32_t)0x40020010U)
#define DMA1_Stream1_BASE_ADDR ((uint32_t)0x40020028U)
#define DMA1_Stream2_BASE_ADDR ((uint32_t)0x40020040U)
#define DMA1_Stream3_BASE_ADDR ((uint32_t)0x40020058U)
#define DMA1_Stream4_BASE_ADDR ((uint32_t)0x40020070U)
#define DMA1_Stream5_BASE_ADDR ((uint32_t)0x40020088U)
#define DMA1_Stream6_BASE_ADDR ((uint32_t)0x400200A0U)
#define DMA1_Stream7_BASE_ADDR ((uint32_t)0x400200B8U)
#define DMA2_Stream0_BASE_ADDR ((uint32_t)0x40020410U)
#define DMA2_Stream1_BASE_ADDR ((uint32_t)0x40020428U)
#define DMA2_Stream2_BASE_ADDR ((uint32_t)0x40020440U)
#define DMA2_Stream3_BASE_ADDR ((uint32_t)0x40020458U)
#define DMA2_Stream4_BASE_ADDR ((uint32_t)0x40020470U)
#define DMA2_Stream5_BASE_ADDR ((uint32_t)0x40020488U)
#define DMA2_Stream6_BASE_ADDR ((uint32_t)0x400204A0U)
#define DMA2_Stream7_BASE_ADDR ((uint32_t)0x400204B8U)
#endif

#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F3     ) || defined(STM32L0     ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
#define DMA1_Channel1_BASE_ADDR ((uint32_t)0x40020008U)
#define DMA1_Channel2_BASE_ADDR ((uint32_t)0x4002001CU)
#define DMA1_Channel3_BASE_ADDR ((uint32_t)0x40020030U)
#define DMA1_Channel4_BASE_ADDR ((uint32_t)0x40020044U)
#define DMA1_Channel5_BASE_ADDR ((uint32_t)0x40020058U)
#endif

#if defined(STM32L1     ) 
#define DMA1_Channel1_BASE_ADDR ((uint32_t)0x40026008U)
#define DMA1_Channel2_BASE_ADDR ((uint32_t)0x4002601CU)
#define DMA1_Channel3_BASE_ADDR ((uint32_t)0x40026030U)
#define DMA1_Channel4_BASE_ADDR ((uint32_t)0x40026044U)
#define DMA1_Channel5_BASE_ADDR ((uint32_t)0x40026058U)
#define DMA1_Channel6_BASE_ADDR ((uint32_t)0x4002606CU)
#define DMA1_Channel7_BASE_ADDR ((uint32_t)0x40026080U)
#endif

#if defined(STM32F042x6 ) || defined(STM32F048xx ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F1     ) ||\
    defined(STM32F3     ) || defined(STM32L031xx ) || defined(STM32L041xx ) || defined(STM32L051xx ) ||\
    defined(STM32L052xx ) || defined(STM32L053xx ) || defined(STM32L061xx ) || defined(STM32L062xx ) ||\
    defined(STM32L063xx ) || defined(STM32L071xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) ||\
    defined(STM32L081xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) || defined(STM32L4     ) ||\
    defined(STM32L4P    ) 
#define DMA1_Channel6_BASE_ADDR ((uint32_t)0x4002006CU)
#define DMA1_Channel7_BASE_ADDR ((uint32_t)0x40020080U)
#endif

#if defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F100xE ) || defined(STM32F101xE ) ||\
    defined(STM32F101xG ) || defined(STM32F103xE ) || defined(STM32F103xG ) || defined(STM32F105xC ) ||\
    defined(STM32F107xC ) || defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F358xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) ||\
    defined(STM32F398xx ) || defined(STM32L4     ) || defined(STM32L4P    ) 
#define DMA2_Channel1_BASE_ADDR ((uint32_t)0x40020408U)
#define DMA2_Channel2_BASE_ADDR ((uint32_t)0x4002041CU)
#define DMA2_Channel3_BASE_ADDR ((uint32_t)0x40020430U)
#define DMA2_Channel4_BASE_ADDR ((uint32_t)0x40020444U)
#define DMA2_Channel5_BASE_ADDR ((uint32_t)0x40020458U)
#endif

#if defined(STM32L100xC ) || defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) ||\
    defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) ||\
    defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define DMA2_Channel1_BASE_ADDR ((uint32_t)0x40026408U)
#define DMA2_Channel2_BASE_ADDR ((uint32_t)0x4002641CU)
#define DMA2_Channel3_BASE_ADDR ((uint32_t)0x40026430U)
#define DMA2_Channel4_BASE_ADDR ((uint32_t)0x40026444U)
#define DMA2_Channel5_BASE_ADDR ((uint32_t)0x40026458U)
#endif

#if defined(STM32L4     ) || defined(STM32L4P    ) 
#define DMA2_Channel6_BASE_ADDR ((uint32_t)0x4002046CU)
#define DMA2_Channel7_BASE_ADDR ((uint32_t)0x40020480U)
#endif

#ifdef DMA1_BASE_ADDR
struct DMA1_plugin: DMA_base_plugin {
	
	#ifdef DMA_CSELR
	struct CSELR_TypeDef : public Reg32_t
	{
		using Reg32_t::operator=;
	
		union
		{
			struct
			{
				uint32_t DEFAULT              :0;
				uint32_t CH1_ADC              :1;
				uint32_t                      :2;
				uint32_t CH1_USART1_RX        :1;
				uint32_t CH2_ADC              :1;
				uint32_t CH2_I2C1_TX          :1;
				uint32_t CH2_TIM1_CH1         :1;
				uint32_t CH2_USART1_TX        :1;
				uint32_t CH3_TIM6_UP          :1;
				uint32_t CH3_I2C1_RX          :1;
				uint32_t CH3_TIM1_CH2         :1;
				uint32_t CH3_USART1_RX        :1;
				uint32_t CH4_TIM7_UP          :1;
				uint32_t CH4_I2C2_TX          :1;
				uint32_t                      :1;
				uint32_t CH4_USART1_TX        :1;
				uint32_t                      :1;
				uint32_t CH5_I2C2_RX          :1;
				uint32_t CH5_TIM1_CH3         :1;
				uint32_t CH5_USART1_RX        :1;
				uint32_t                      :1;
				uint32_t DMA1_CSELR_0_CH6_I2C1_TX :1;
				uint32_t DMA1_CSELR_0_CH6_TIM1_CH1 :1;
				uint32_t DMA1_CSELR_0_CH6_USART1_RX :1;
				uint32_t                      :1;
				uint32_t DMA1_CSELR_0_CH7_I2C1_RX :1;
				uint32_t                      :1;
				uint32_t DMA1_CSELR_0_CH7_USART1_TX :1;
				uint32_t                      :4;
			};
			struct
			{
				uint32_t CH1_TIM17_CH1        :3;
				uint32_t                      :1;
				uint32_t CH2_SPI1_RX          :2;
				uint32_t CH2_USART5_TX        :2;
				uint32_t CH3_SPI1_TX          :2;
				uint32_t CH3_USART5_RX        :2;
				uint32_t CH4_SPI2_RX          :2;
				uint32_t CH4_USART5_TX        :2;
				uint32_t CH5_SPI2_TX          :2;
				uint32_t CH5_USART5_RX        :2;
				uint32_t DMA1_CSELR_1_CH6_SPI2_RX :2;
				uint32_t DMA1_CSELR_1_CH6_TIM1_CH2 :1;
				uint32_t                      :1;
				uint32_t DMA1_CSELR_1_CH7_SPI2_TX :2;
				uint32_t DMA1_CSELR_1_CH7_USART5_TX :2;
				uint32_t                      :4;
			};
			#ifdef DMA1_CSELR_10
			struct
			{
				uint32_t                      :20;
				uint32_t C6S                  :4;
				uint32_t                      :8;
			};
			#endif
			struct
			{
				uint32_t CH1_TIM17_UP         :3;
				uint32_t                      :1;
				uint32_t CH2_TIM17_CH1        :3;
				uint32_t                      :1;
				uint32_t CH3_TIM16_CH1        :3;
				uint32_t                      :1;
				uint32_t DMA1_CSELR_2_CH4_DAC_CH2 :1;
				uint32_t CH4_TIM3_CH1         :2;
				uint32_t                      :2;
				uint32_t DMA1_CSELR_2_CH5_USART7_RX :3;
				uint32_t                      :2;
				uint32_t DMA1_CSELR_2_CH6_TIM1_CH3 :1;
				uint32_t                      :1;
				uint32_t DMA1_CSELR_2_CH7_TIM17_CH1 :3;
				uint32_t                      :5;
			};
			struct
			{
				uint32_t                      :2;
				uint32_t CH1_USART5_RX        :2;
				uint32_t CH2_TIM17_UP         :3;
				uint32_t                      :1;
				uint32_t CH3_TIM16_UP         :3;
				uint32_t                      :2;
				uint32_t CH4_TIM3_TRIG        :2;
				uint32_t                      :1;
				uint32_t DMA1_CSELR_3_CH5_USART8_RX :4;
				uint32_t                      :1;
				uint32_t DMA1_CSELR_3_CH6_TIM3_CH1 :2;
				uint32_t                      :1;
				uint32_t DMA1_CSELR_3_CH7_TIM17_UP :3;
				uint32_t                      :5;
			};
			#ifdef DMA1_CSELR_4
			struct
			{
				uint32_t                      :1;
				uint32_t DMA1_CSELR_4_CH1_USART7_RX :3;
				uint32_t                      :1;
				uint32_t DMA1_CSELR_4_CH2_USART7_TX :3;
				uint32_t DMA1_CSELR_4_CH3_DAC_CH1 :1;
				uint32_t DMA1_CSELR_4_CH3_USART7_RX :3;
				uint32_t DMA1_CSELR_4_CH4_TIM16_CH1 :3;
				uint32_t                      :1;
				uint32_t C5S                  :4;
				uint32_t                      :1;
				uint32_t DMA1_CSELR_4_CH6_TIM3_TRIG :2;
				uint32_t                      :2;
				uint32_t DMA1_CSELR_4_CH7_USART7_TX :3;
				uint32_t                      :4;
			};
			#endif
			struct
			{
				uint32_t DMA1_CSELR_5_CH1_USART8_RX :4;
				uint32_t DMA1_CSELR_5_CH2_USART8_TX :4;
				uint32_t DMA1_CSELR_5_CH3_USART8_RX :4;
				uint32_t CH4_TIM16_UP         :3;
				uint32_t                      :5;
				uint32_t DMA1_CSELR_5_CH6_TIM16_CH1 :3;
				uint32_t                      :1;
				uint32_t DMA1_CSELR_5_CH7_USART8_TX :4;
				uint32_t                      :4;
			};
			#ifdef DMA1_CSELR_6
			struct
			{
				uint32_t C1S                  :4;
				uint32_t C2S                  :4;
				uint32_t C3S                  :4;
				uint32_t                      :1;
				uint32_t DMA1_CSELR_6_CH4_USART7_TX :3;
				uint32_t                      :4;
				uint32_t DMA1_CSELR_6_CH6_TIM16_UP :3;
				uint32_t                      :1;
				uint32_t DMA1_CSELR_6_C7S     :4;
				uint32_t                      :4;
			};
			#endif
			#ifdef DMA1_CSELR_7
			struct
			{
				uint32_t                      :12;
				uint32_t CH4_USART8_TX        :4;
				uint32_t                      :6;
				uint32_t CH6_USART5_RX        :2;
				uint32_t                      :8;
			};
			#endif
			#ifdef DMA1_CSELR_8
			struct
			{
				uint32_t                      :12;
				uint32_t C4S                  :4;
				uint32_t                      :5;
				uint32_t DMA1_CSELR_8_CH6_USART7_RX :3;
				uint32_t                      :8;
			};
			#endif
			#ifdef DMA1_CSELR_9
			struct
			{
				uint32_t                      :20;
				uint32_t CH6_USART8_RX        :4;
				uint32_t                      :8;
			};
			#endif
		};
		//SOOL-DMA_CSELR-DECLARATION
	};
	#endif
	
};
volatile class DMA<DMA1_plugin>* const DMA1 =reinterpret_cast<class DMA<DMA1_plugin>* const>(DMA1_BASE_ADDR);
#endif
#ifdef DMA2_BASE_ADDR
struct DMA2_plugin: DMA_base_plugin {
	
	#ifdef DMA_CSELR
	struct CSELR_TypeDef : public Reg32_t
	{
		using Reg32_t::operator=;
	
		union
		{
			#ifdef DMA2_CSELR_0
			struct
			{
				uint32_t DMA2_CSELR_0_DEFAULT :0;
				uint32_t                      :1;
				uint32_t DMA2_CSELR_0_CH1_I2C2_TX :1;
				uint32_t                      :1;
				uint32_t DMA2_CSELR_0_CH1_USART1_TX :1;
				uint32_t                      :1;
				uint32_t DMA2_CSELR_0_CH2_I2C2_RX :1;
				uint32_t                      :1;
				uint32_t DMA2_CSELR_0_CH2_USART1_RX :1;
				uint32_t DMA2_CSELR_0_CH3_TIM6_UP :1;
				uint32_t                      :2;
				uint32_t DMA2_CSELR_0_CH3_USART1_RX :1;
				uint32_t DMA2_CSELR_0_CH4_TIM7_UP :1;
				uint32_t                      :2;
				uint32_t DMA2_CSELR_0_CH4_USART1_TX :1;
				uint32_t DMA2_CSELR_0_CH5_ADC :1;
				uint32_t                      :2;
				uint32_t DMA2_CSELR_0_CH5_USART1_TX :1;
				uint32_t C6S                  :4;
				uint32_t C7S                  :4;
				uint32_t                      :4;
			};
			#endif
			#ifdef DMA2_CSELR_1
			struct
			{
				uint32_t                      :2;
				uint32_t CH1_USART5_TX        :2;
				uint32_t                      :2;
				uint32_t CH2_USART5_RX        :2;
				uint32_t CH3_DAC_CH1          :1;
				uint32_t                      :1;
				uint32_t CH3_USART5_RX        :2;
				uint32_t CH4_DAC_CH2          :1;
				uint32_t                      :1;
				uint32_t CH4_USART5_TX        :2;
				uint32_t                      :2;
				uint32_t CH5_USART5_TX        :2;
				uint32_t                      :12;
			};
			#endif
			#ifdef DMA2_CSELR_2
			struct
			{
				uint32_t                      :1;
				uint32_t CH1_USART7_TX        :3;
				uint32_t                      :1;
				uint32_t CH2_USART7_RX        :3;
				uint32_t CH3_SPI1_RX          :2;
				uint32_t                      :2;
				uint32_t CH4_SPI1_TX          :2;
				uint32_t                      :3;
				uint32_t CH5_USART7_TX        :3;
				uint32_t                      :12;
			};
			#endif
			#ifdef DMA2_CSELR_3
			struct
			{
				uint32_t CH1_USART8_TX        :4;
				uint32_t CH2_USART8_RX        :4;
				uint32_t                      :1;
				uint32_t CH3_USART7_RX        :3;
				uint32_t                      :1;
				uint32_t CH4_USART7_TX        :3;
				uint32_t CH5_USART8_TX        :4;
				uint32_t                      :12;
			};
			#endif
			#ifdef DMA2_CSELR_4
			struct
			{
				uint32_t C1S                  :4;
				uint32_t C2S                  :4;
				uint32_t DMA2_CSELR_4_CH3_USART8_RX :4;
				uint32_t DMA2_CSELR_4_CH4_USART8_TX :4;
				uint32_t C5S                  :4;
				uint32_t                      :12;
			};
			#endif
			#ifdef DMA2_CSELR_5
			struct
			{
				uint32_t                      :8;
				uint32_t C3S                  :4;
				uint32_t C4S                  :4;
				uint32_t                      :16;
			};
			#endif
		};
		//SOOL-DMA_CSELR-DECLARATION
	};
	#endif
	
};
volatile class DMA<DMA2_plugin>* const DMA2 =reinterpret_cast<class DMA<DMA2_plugin>* const>(DMA2_BASE_ADDR);
#endif
#ifdef DMA1_CSELR_BASE_ADDR
volatile class DMA_Request * const DMA1_CSELR = reinterpret_cast<class DMA_Request* const>(DMA1_CSELR_BASE_ADDR);
#endif
#ifdef DMA2_CSELR_BASE_ADDR
volatile class DMA_Request * const DMA2_CSELR = reinterpret_cast<class DMA_Request* const>(DMA2_CSELR_BASE_ADDR);
#endif
#ifdef DMA1_Stream0_BASE_ADDR
volatile class DMA_Stream * const DMA1_Stream0 = reinterpret_cast<class DMA_Stream* const>(DMA1_Stream0_BASE_ADDR);
#endif
#ifdef DMA1_Stream1_BASE_ADDR
volatile class DMA_Stream * const DMA1_Stream1 = reinterpret_cast<class DMA_Stream* const>(DMA1_Stream1_BASE_ADDR);
#endif
#ifdef DMA1_Stream2_BASE_ADDR
volatile class DMA_Stream * const DMA1_Stream2 = reinterpret_cast<class DMA_Stream* const>(DMA1_Stream2_BASE_ADDR);
#endif
#ifdef DMA1_Stream3_BASE_ADDR
volatile class DMA_Stream * const DMA1_Stream3 = reinterpret_cast<class DMA_Stream* const>(DMA1_Stream3_BASE_ADDR);
#endif
#ifdef DMA1_Stream4_BASE_ADDR
volatile class DMA_Stream * const DMA1_Stream4 = reinterpret_cast<class DMA_Stream* const>(DMA1_Stream4_BASE_ADDR);
#endif
#ifdef DMA1_Stream5_BASE_ADDR
volatile class DMA_Stream * const DMA1_Stream5 = reinterpret_cast<class DMA_Stream* const>(DMA1_Stream5_BASE_ADDR);
#endif
#ifdef DMA1_Stream6_BASE_ADDR
volatile class DMA_Stream * const DMA1_Stream6 = reinterpret_cast<class DMA_Stream* const>(DMA1_Stream6_BASE_ADDR);
#endif
#ifdef DMA1_Stream7_BASE_ADDR
volatile class DMA_Stream * const DMA1_Stream7 = reinterpret_cast<class DMA_Stream* const>(DMA1_Stream7_BASE_ADDR);
#endif
#ifdef DMA2_Stream0_BASE_ADDR
volatile class DMA_Stream * const DMA2_Stream0 = reinterpret_cast<class DMA_Stream* const>(DMA2_Stream0_BASE_ADDR);
#endif
#ifdef DMA2_Stream1_BASE_ADDR
volatile class DMA_Stream * const DMA2_Stream1 = reinterpret_cast<class DMA_Stream* const>(DMA2_Stream1_BASE_ADDR);
#endif
#ifdef DMA2_Stream2_BASE_ADDR
volatile class DMA_Stream * const DMA2_Stream2 = reinterpret_cast<class DMA_Stream* const>(DMA2_Stream2_BASE_ADDR);
#endif
#ifdef DMA2_Stream3_BASE_ADDR
volatile class DMA_Stream * const DMA2_Stream3 = reinterpret_cast<class DMA_Stream* const>(DMA2_Stream3_BASE_ADDR);
#endif
#ifdef DMA2_Stream4_BASE_ADDR
volatile class DMA_Stream * const DMA2_Stream4 = reinterpret_cast<class DMA_Stream* const>(DMA2_Stream4_BASE_ADDR);
#endif
#ifdef DMA2_Stream5_BASE_ADDR
volatile class DMA_Stream * const DMA2_Stream5 = reinterpret_cast<class DMA_Stream* const>(DMA2_Stream5_BASE_ADDR);
#endif
#ifdef DMA2_Stream6_BASE_ADDR
volatile class DMA_Stream * const DMA2_Stream6 = reinterpret_cast<class DMA_Stream* const>(DMA2_Stream6_BASE_ADDR);
#endif
#ifdef DMA2_Stream7_BASE_ADDR
volatile class DMA_Stream * const DMA2_Stream7 = reinterpret_cast<class DMA_Stream* const>(DMA2_Stream7_BASE_ADDR);
#endif
#ifdef DMA1_Channel1_BASE_ADDR
volatile class DMA_Channel * const DMA1_Channel1 = reinterpret_cast<class DMA_Channel* const>(DMA1_Channel1_BASE_ADDR);
#endif
#ifdef DMA1_Channel2_BASE_ADDR
volatile class DMA_Channel * const DMA1_Channel2 = reinterpret_cast<class DMA_Channel* const>(DMA1_Channel2_BASE_ADDR);
#endif
#ifdef DMA1_Channel3_BASE_ADDR
volatile class DMA_Channel * const DMA1_Channel3 = reinterpret_cast<class DMA_Channel* const>(DMA1_Channel3_BASE_ADDR);
#endif
#ifdef DMA1_Channel4_BASE_ADDR
volatile class DMA_Channel * const DMA1_Channel4 = reinterpret_cast<class DMA_Channel* const>(DMA1_Channel4_BASE_ADDR);
#endif
#ifdef DMA1_Channel5_BASE_ADDR
volatile class DMA_Channel * const DMA1_Channel5 = reinterpret_cast<class DMA_Channel* const>(DMA1_Channel5_BASE_ADDR);
#endif
#ifdef DMA1_Channel6_BASE_ADDR
volatile class DMA_Channel * const DMA1_Channel6 = reinterpret_cast<class DMA_Channel* const>(DMA1_Channel6_BASE_ADDR);
#endif
#ifdef DMA1_Channel7_BASE_ADDR
volatile class DMA_Channel * const DMA1_Channel7 = reinterpret_cast<class DMA_Channel* const>(DMA1_Channel7_BASE_ADDR);
#endif
#ifdef DMA2_Channel1_BASE_ADDR
volatile class DMA_Channel * const DMA2_Channel1 = reinterpret_cast<class DMA_Channel* const>(DMA2_Channel1_BASE_ADDR);
#endif
#ifdef DMA2_Channel2_BASE_ADDR
volatile class DMA_Channel * const DMA2_Channel2 = reinterpret_cast<class DMA_Channel* const>(DMA2_Channel2_BASE_ADDR);
#endif
#ifdef DMA2_Channel3_BASE_ADDR
volatile class DMA_Channel * const DMA2_Channel3 = reinterpret_cast<class DMA_Channel* const>(DMA2_Channel3_BASE_ADDR);
#endif
#ifdef DMA2_Channel4_BASE_ADDR
volatile class DMA_Channel * const DMA2_Channel4 = reinterpret_cast<class DMA_Channel* const>(DMA2_Channel4_BASE_ADDR);
#endif
#ifdef DMA2_Channel5_BASE_ADDR
volatile class DMA_Channel * const DMA2_Channel5 = reinterpret_cast<class DMA_Channel* const>(DMA2_Channel5_BASE_ADDR);
#endif
#ifdef DMA2_Channel6_BASE_ADDR
volatile class DMA_Channel * const DMA2_Channel6 = reinterpret_cast<class DMA_Channel* const>(DMA2_Channel6_BASE_ADDR);
#endif
#ifdef DMA2_Channel7_BASE_ADDR
volatile class DMA_Channel * const DMA2_Channel7 = reinterpret_cast<class DMA_Channel* const>(DMA2_Channel7_BASE_ADDR);
#endif
//endregion

//SOOL-DMA-DEFINES
//SOOL-DMA-DEFINITION
	};
};//region undef
#undef DMA_MAP0_CSELR
#undef DMA1_CSELR_4_CH4_TIM16_CH1
#undef DMA_CSELR_C6S
#undef DMA_CSELR_C7S
#undef DMA1_CSELR_6_C7S
#undef DMA_MAP1_LISR
#undef DMA_MAP1_HISR
#undef DMA_MAP0_LIFCR
#undef DMA_MAP0_HIFCR
#undef DMA_MAP0_ISR
#undef DMA_MAP0_IFCR
#undef DMA_IFCR_CGIF6
#undef DMA_IFCR_CTCIF6
#undef DMA_IFCR_CHTIF6
#undef DMA_IFCR_CTEIF6
#undef DMA_IFCR_CGIF7
#undef DMA_IFCR_CTCIF7
#undef DMA_IFCR_CHTIF7
#undef DMA_IFCR_CTEIF7
#undef DMA_ISR_GIF6
#undef DMA_ISR_TCIF6
#undef DMA_ISR_HTIF6
#undef DMA_ISR_TEIF6
#undef DMA_ISR_GIF7
#undef DMA_ISR_TCIF7
#undef DMA_ISR_HTIF7
#undef DMA_ISR_TEIF7
#undef DMA_Stream_CR_0_ACK
#undef DMA_Stream_CR_0_CHSEL
#undef DMA1_CSELR_0_CH6_I2C1_TX
#undef DMA1_CSELR_0_CH6_TIM1_CH1
#undef DMA1_CSELR_0_CH6_USART1_RX
#undef DMA1_CSELR_0_CH7_I2C1_RX
#undef DMA1_CSELR_0_CH7_USART1_TX
#undef DMA1_CSELR_1_CH6_SPI2_RX
#undef DMA1_CSELR_1_CH6_TIM1_CH2
#undef DMA1_CSELR_1_CH7_SPI2_TX
#undef DMA1_CSELR_1_CH7_USART5_TX
#undef DMA1_CSELR_2_CH4_DAC_CH2
#undef DMA1_CSELR_2_CH5_USART7_RX
#undef DMA1_CSELR_2_CH6_TIM1_CH3
#undef DMA1_CSELR_2_CH7_TIM17_CH1
#undef DMA1_CSELR_3_CH5_USART8_RX
#undef DMA1_CSELR_3_CH6_TIM3_CH1
#undef DMA1_CSELR_3_CH7_TIM17_UP
#undef DMA1_CSELR_4_CH1_USART7_RX
#undef DMA1_CSELR_4_CH2_USART7_TX
#undef DMA1_CSELR_4_CH3_DAC_CH1
#undef DMA1_CSELR_4_CH3_USART7_RX
#undef DMA1_CSELR_4_CH6_TIM3_TRIG
#undef DMA1_CSELR_4_CH7_USART7_TX
#undef DMA1_CSELR_5_CH1_USART8_RX
#undef DMA1_CSELR_5_CH2_USART8_TX
#undef DMA1_CSELR_5_CH3_USART8_RX
#undef DMA1_CSELR_5_CH6_TIM16_CH1
#undef DMA1_CSELR_5_CH7_USART8_TX
#undef DMA1_CSELR_6_CH4_USART7_TX
#undef DMA1_CSELR_6_CH6_TIM16_UP
#undef DMA1_CSELR_8_CH6_USART7_RX
#undef DMA2_CSELR_0_DEFAULT
#undef DMA2_CSELR_0_CH1_I2C2_TX
#undef DMA2_CSELR_0_CH1_USART1_TX
#undef DMA2_CSELR_0_CH2_I2C2_RX
#undef DMA2_CSELR_0_CH2_USART1_RX
#undef DMA2_CSELR_0_CH3_TIM6_UP
#undef DMA2_CSELR_0_CH3_USART1_RX
#undef DMA2_CSELR_0_CH4_TIM7_UP
#undef DMA2_CSELR_0_CH4_USART1_TX
#undef DMA2_CSELR_0_CH5_ADC
#undef DMA2_CSELR_0_CH5_USART1_TX
#undef DMA2_CSELR_4_CH3_USART8_RX
#undef DMA2_CSELR_4_CH4_USART8_TX
//endregion
#endif
