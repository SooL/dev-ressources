#ifndef __SOOL_TSC_H
#define __SOOL_TSC_H

#include "peripheral_include.h"
//SOOL-TSC-INCLUDES
#if defined(STM32F042x6 ) || defined(STM32F048xx ) || defined(STM32F051x8 ) || defined(STM32F058xx ) ||\
    defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) ||\
    defined(STM32F098xx ) || defined(STM32F3     ) || defined(STM32L052xx ) || defined(STM32L053xx ) ||\
    defined(STM32L062xx ) || defined(STM32L063xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) ||\
    defined(STM32L082xx ) || defined(STM32L083xx ) || defined(STM32L4     ) || defined(STM32L4P    ) 
//region defines

#define TSC_CR
#define TSC_ICR
#define TSC_IER
#define TSC_IOASCR
#define TSC_IOCCR
#define TSC_IOGCSR
#define TSC_IOGXCR
#define TSC_IOHCR
#define TSC_IOSCR
#define TSC_ISR

#if defined(STM32F042x6 ) || defined(STM32F048xx ) || defined(STM32F051x8 ) || defined(STM32F058xx ) ||\
    defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) ||\
    defined(STM32F098xx ) || defined(STM32F3     ) || defined(STM32L052xx ) || defined(STM32L053xx ) ||\
    defined(STM32L062xx ) || defined(STM32L063xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) ||\
    defined(STM32L082xx ) || defined(STM32L083xx ) || defined(STM32L471xx ) || defined(STM32L475xx ) ||\
    defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define TSC_IOASCR_G8_IO1    G8_IO1               // 1 bits @ 28
#define TSC_IOASCR_G8_IO2    G8_IO2               // 1 bits @ 29
#define TSC_IOASCR_G8_IO3    G8_IO3               // 1 bits @ 30
#define TSC_IOASCR_G8_IO4    G8_IO4               // 1 bits @ 31
#define TSC_IOCCR_G8_IO1     G8_IO1               // 1 bits @ 28
#define TSC_IOCCR_G8_IO2     G8_IO2               // 1 bits @ 29
#define TSC_IOCCR_G8_IO3     G8_IO3               // 1 bits @ 30
#define TSC_IOCCR_G8_IO4     G8_IO4               // 1 bits @ 31
#define TSC_IOGCSR_G8E       G8E                  // 1 bits @ 7
#define TSC_IOGCSR_G8S       G8S                  // 1 bits @ 23
#define TSC_IOHCR_G8_IO1     G8_IO1               // 1 bits @ 28
#define TSC_IOHCR_G8_IO2     G8_IO2               // 1 bits @ 29
#define TSC_IOHCR_G8_IO3     G8_IO3               // 1 bits @ 30
#define TSC_IOHCR_G8_IO4     G8_IO4               // 1 bits @ 31
#define TSC_IOSCR_G8_IO1     G8_IO1               // 1 bits @ 28
#define TSC_IOSCR_G8_IO2     G8_IO2               // 1 bits @ 29
#define TSC_IOSCR_G8_IO3     G8_IO3               // 1 bits @ 30
#define TSC_IOSCR_G8_IO4     G8_IO4               // 1 bits @ 31
#define TSC_MAP0_IOGXCR      IOGXCR_TypeDef IOGXCR[8]
#else
#define TSC_IOASCR_G8_IO1
#define TSC_IOASCR_G8_IO2
#define TSC_IOASCR_G8_IO3
#define TSC_IOASCR_G8_IO4
#define TSC_IOCCR_G8_IO1
#define TSC_IOCCR_G8_IO2
#define TSC_IOCCR_G8_IO3
#define TSC_IOCCR_G8_IO4
#define TSC_IOGCSR_G8E
#define TSC_IOGCSR_G8S
#define TSC_IOHCR_G8_IO1
#define TSC_IOHCR_G8_IO2
#define TSC_IOHCR_G8_IO3
#define TSC_IOHCR_G8_IO4
#define TSC_IOSCR_G8_IO1
#define TSC_IOSCR_G8_IO2
#define TSC_IOSCR_G8_IO3
#define TSC_IOSCR_G8_IO4
#define TSC_MAP0_IOGXCR __SOOL_PERIPH_PADDING_32
#endif

#if defined(STM32L431xx ) || defined(STM32L432xx ) || defined(STM32L433xx ) || defined(STM32L442xx ) ||\
    defined(STM32L443xx ) || defined(STM32L451xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) 
#define TSC_MAP1_IOGXCR      IOGXCR_TypeDef IOGXCR[7]
#else
#define TSC_MAP1_IOGXCR __SOOL_PERIPH_PADDING_16;__SOOL_PERIPH_PADDING_8;__SOOL_PERIPH_PADDING_4
#endif

//endregion

namespace sool
{
	namespace core
	{
		class TSC
		{
			//SOOL-TSC-ENUMS
			
			public :
			
			#ifdef TSC_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TSCE                 :1;
					uint32_t START                :1;
					uint32_t AM                   :1;
					uint32_t SYNCPOL              :1;
					uint32_t IODEF                :1;
					uint32_t MCV                  :3;
					uint32_t                      :4;
					uint32_t PGPSC                :3;
					uint32_t SSPSC                :1;
					uint32_t SSE                  :1;
					uint32_t SSD                  :7;
					uint32_t CTPL                 :4;
					uint32_t CTPH                 :4;
			
				//SOOL-TSC_CR-DECLARATION
			};
			#endif
			
			#ifdef TSC_ICR
			struct ICR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EOAIC                :1;
					uint32_t MCEIC                :1;
					uint32_t                      :30;
			
				//SOOL-TSC_ICR-DECLARATION
			};
			#endif
			
			#ifdef TSC_IER
			struct IER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EOAIE                :1;
					uint32_t MCEIE                :1;
					uint32_t                      :30;
			
				//SOOL-TSC_IER-DECLARATION
			};
			#endif
			
			#ifdef TSC_IOASCR
			struct IOASCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t G1_IO1               :1;
					uint32_t G1_IO2               :1;
					uint32_t G1_IO3               :1;
					uint32_t G1_IO4               :1;
					uint32_t G2_IO1               :1;
					uint32_t G2_IO2               :1;
					uint32_t G2_IO3               :1;
					uint32_t G2_IO4               :1;
					uint32_t G3_IO1               :1;
					uint32_t G3_IO2               :1;
					uint32_t G3_IO3               :1;
					uint32_t G3_IO4               :1;
					uint32_t G4_IO1               :1;
					uint32_t G4_IO2               :1;
					uint32_t G4_IO3               :1;
					uint32_t G4_IO4               :1;
					uint32_t G5_IO1               :1;
					uint32_t G5_IO2               :1;
					uint32_t G5_IO3               :1;
					uint32_t G5_IO4               :1;
					uint32_t G6_IO1               :1;
					uint32_t G6_IO2               :1;
					uint32_t G6_IO3               :1;
					uint32_t G6_IO4               :1;
					uint32_t G7_IO1               :1;
					uint32_t G7_IO2               :1;
					uint32_t G7_IO3               :1;
					uint32_t G7_IO4               :1;
					uint32_t TSC_IOASCR_G8_IO1    :1;
					uint32_t TSC_IOASCR_G8_IO2    :1;
					uint32_t TSC_IOASCR_G8_IO3    :1;
					uint32_t TSC_IOASCR_G8_IO4    :1;
			
				//SOOL-TSC_IOASCR-DECLARATION
			};
			#endif
			
			#ifdef TSC_IOCCR
			struct IOCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t G1_IO1               :1;
					uint32_t G1_IO2               :1;
					uint32_t G1_IO3               :1;
					uint32_t G1_IO4               :1;
					uint32_t G2_IO1               :1;
					uint32_t G2_IO2               :1;
					uint32_t G2_IO3               :1;
					uint32_t G2_IO4               :1;
					uint32_t G3_IO1               :1;
					uint32_t G3_IO2               :1;
					uint32_t G3_IO3               :1;
					uint32_t G3_IO4               :1;
					uint32_t G4_IO1               :1;
					uint32_t G4_IO2               :1;
					uint32_t G4_IO3               :1;
					uint32_t G4_IO4               :1;
					uint32_t G5_IO1               :1;
					uint32_t G5_IO2               :1;
					uint32_t G5_IO3               :1;
					uint32_t G5_IO4               :1;
					uint32_t G6_IO1               :1;
					uint32_t G6_IO2               :1;
					uint32_t G6_IO3               :1;
					uint32_t G6_IO4               :1;
					uint32_t G7_IO1               :1;
					uint32_t G7_IO2               :1;
					uint32_t G7_IO3               :1;
					uint32_t G7_IO4               :1;
					uint32_t TSC_IOCCR_G8_IO1     :1;
					uint32_t TSC_IOCCR_G8_IO2     :1;
					uint32_t TSC_IOCCR_G8_IO3     :1;
					uint32_t TSC_IOCCR_G8_IO4     :1;
			
				//SOOL-TSC_IOCCR-DECLARATION
			};
			#endif
			
			#ifdef TSC_IOGCSR
			struct IOGCSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t G1E                  :1;
					uint32_t G2E                  :1;
					uint32_t G3E                  :1;
					uint32_t G4E                  :1;
					uint32_t G5E                  :1;
					uint32_t G6E                  :1;
					uint32_t G7E                  :1;
					uint32_t TSC_IOGCSR_G8E       :1;
					uint32_t                      :8;
					uint32_t G1S                  :1;
					uint32_t G2S                  :1;
					uint32_t G3S                  :1;
					uint32_t G4S                  :1;
					uint32_t G5S                  :1;
					uint32_t G6S                  :1;
					uint32_t G7S                  :1;
					uint32_t TSC_IOGCSR_G8S       :1;
					uint32_t                      :8;
			
				//SOOL-TSC_IOGCSR-DECLARATION
			};
			#endif
			
			#ifdef TSC_IOGXCR
			struct IOGXCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CNT                  :14;
					uint32_t                      :18;
			
				//SOOL-TSC_IOGXCR-DECLARATION
			};
			#endif
			
			#ifdef TSC_IOHCR
			struct IOHCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t G1_IO1               :1;
					uint32_t G1_IO2               :1;
					uint32_t G1_IO3               :1;
					uint32_t G1_IO4               :1;
					uint32_t G2_IO1               :1;
					uint32_t G2_IO2               :1;
					uint32_t G2_IO3               :1;
					uint32_t G2_IO4               :1;
					uint32_t G3_IO1               :1;
					uint32_t G3_IO2               :1;
					uint32_t G3_IO3               :1;
					uint32_t G3_IO4               :1;
					uint32_t G4_IO1               :1;
					uint32_t G4_IO2               :1;
					uint32_t G4_IO3               :1;
					uint32_t G4_IO4               :1;
					uint32_t G5_IO1               :1;
					uint32_t G5_IO2               :1;
					uint32_t G5_IO3               :1;
					uint32_t G5_IO4               :1;
					uint32_t G6_IO1               :1;
					uint32_t G6_IO2               :1;
					uint32_t G6_IO3               :1;
					uint32_t G6_IO4               :1;
					uint32_t G7_IO1               :1;
					uint32_t G7_IO2               :1;
					uint32_t G7_IO3               :1;
					uint32_t G7_IO4               :1;
					uint32_t TSC_IOHCR_G8_IO1     :1;
					uint32_t TSC_IOHCR_G8_IO2     :1;
					uint32_t TSC_IOHCR_G8_IO3     :1;
					uint32_t TSC_IOHCR_G8_IO4     :1;
			
				//SOOL-TSC_IOHCR-DECLARATION
			};
			#endif
			
			#ifdef TSC_IOSCR
			struct IOSCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t G1_IO1               :1;
					uint32_t G1_IO2               :1;
					uint32_t G1_IO3               :1;
					uint32_t G1_IO4               :1;
					uint32_t G2_IO1               :1;
					uint32_t G2_IO2               :1;
					uint32_t G2_IO3               :1;
					uint32_t G2_IO4               :1;
					uint32_t G3_IO1               :1;
					uint32_t G3_IO2               :1;
					uint32_t G3_IO3               :1;
					uint32_t G3_IO4               :1;
					uint32_t G4_IO1               :1;
					uint32_t G4_IO2               :1;
					uint32_t G4_IO3               :1;
					uint32_t G4_IO4               :1;
					uint32_t G5_IO1               :1;
					uint32_t G5_IO2               :1;
					uint32_t G5_IO3               :1;
					uint32_t G5_IO4               :1;
					uint32_t G6_IO1               :1;
					uint32_t G6_IO2               :1;
					uint32_t G6_IO3               :1;
					uint32_t G6_IO4               :1;
					uint32_t G7_IO1               :1;
					uint32_t G7_IO2               :1;
					uint32_t G7_IO3               :1;
					uint32_t G7_IO4               :1;
					uint32_t TSC_IOSCR_G8_IO1     :1;
					uint32_t TSC_IOSCR_G8_IO2     :1;
					uint32_t TSC_IOSCR_G8_IO3     :1;
					uint32_t TSC_IOSCR_G8_IO4     :1;
			
				//SOOL-TSC_IOSCR-DECLARATION
			};
			#endif
			
			#ifdef TSC_ISR
			struct ISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EOAF                 :1;
					uint32_t MCEF                 :1;
					uint32_t                      :30;
			
				//SOOL-TSC_ISR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					IER_TypeDef IER;     // @0x004
					ICR_TypeDef ICR;     // @0x008
					ISR_TypeDef ISR;     // @0x00c
					IOHCR_TypeDef IOHCR; // @0x010
					__SOOL_PERIPH_PADDING_4;
					IOASCR_TypeDef IOASCR; // @0x018
					__SOOL_PERIPH_PADDING_4;
					IOSCR_TypeDef IOSCR; // @0x020
					__SOOL_PERIPH_PADDING_4;
					IOCCR_TypeDef IOCCR; // @0x028
					__SOOL_PERIPH_PADDING_4;
					IOGCSR_TypeDef IOGCSR; // @0x030
					TSC_MAP0_IOGXCR;     // @0x034
				};
				struct
				{
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_4;
					TSC_MAP1_IOGXCR;     // @0x034
					__SOOL_PERIPH_PADDING_4;
				};
			};
			private:
			TSC() = delete;
			//SOOL-TSC-DECLARATION
		};
		
		//region instances
#define TSC_BASE_ADDR ((uint32_t)0x40024000U)
#ifdef TSC_BASE_ADDR
volatile class TSC * const TSC = reinterpret_cast<class TSC* const>(TSC_BASE_ADDR);
#endif
//endregion

//SOOL-TSC-DEFINES
//SOOL-TSC-DEFINITION
	};
};//region undef
#undef TSC_IOASCR_G8_IO1
#undef TSC_IOASCR_G8_IO2
#undef TSC_IOASCR_G8_IO3
#undef TSC_IOASCR_G8_IO4
#undef TSC_IOCCR_G8_IO1
#undef TSC_IOCCR_G8_IO2
#undef TSC_IOCCR_G8_IO3
#undef TSC_IOCCR_G8_IO4
#undef TSC_IOGCSR_G8E
#undef TSC_IOGCSR_G8S
#undef TSC_IOHCR_G8_IO1
#undef TSC_IOHCR_G8_IO2
#undef TSC_IOHCR_G8_IO3
#undef TSC_IOHCR_G8_IO4
#undef TSC_IOSCR_G8_IO1
#undef TSC_IOSCR_G8_IO2
#undef TSC_IOSCR_G8_IO3
#undef TSC_IOSCR_G8_IO4
#undef TSC_MAP0_IOGXCR
#undef TSC_MAP1_IOGXCR
//endregion
#endif
#endif
