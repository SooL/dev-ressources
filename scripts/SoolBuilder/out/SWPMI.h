#ifndef __SOOL_SWPMI_H
#define __SOOL_SWPMI_H

#include "peripheral_include.h"
//SOOL-SWPMI-INCLUDES
#if defined(STM32H7     ) || defined(STM32L431xx ) || defined(STM32L432xx ) || defined(STM32L433xx ) ||\
    defined(STM32L442xx ) || defined(STM32L443xx ) || defined(STM32L471xx ) || defined(STM32L475xx ) ||\
    defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) 
//region defines

#define SWPMI_BRR
#define SWPMI_CR
#define SWPMI_ICR
#define SWPMI_IER
#define SWPMI_ISR
#define SWPMI_OR
#define SWPMI_RDR
#define SWPMI_RFL
#define SWPMI_TDR

#if defined(STM32H7     ) 
#define SWPMI_CR_SWPEN       SWPEN                // 1 bits @ 11
#define SWPMI_ICR_CRDYF      CRDYF                // 1 bits @ 11
#define SWPMI_IER_RDYIE      RDYIE                // 1 bits @ 11
#define SWPMI_ISR_RDYF       RDYF                 // 1 bits @ 11
#else
#define SWPMI_CR_SWPEN
#define SWPMI_ICR_CRDYF
#define SWPMI_IER_RDYIE
#define SWPMI_ISR_RDYF
#endif

//endregion

namespace sool
{
	namespace core
	{
		class SWPMI
		{
			//SOOL-SWPMI-ENUMS
			
			public :
			
			#ifdef SWPMI_BRR
			struct BRR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t BR                   :6;
					uint32_t                      :26;
			
				//SOOL-SWPMI_BRR-DECLARATION
			};
			#endif
			
			#ifdef SWPMI_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RXDMA                :1;
					uint32_t TXDMA                :1;
					uint32_t RXMODE               :1;
					uint32_t TXMODE               :1;
					uint32_t LPBK                 :1;
					uint32_t SWPACT               :1;
					uint32_t                      :4;
					uint32_t DEACT                :1;
					uint32_t SWPMI_CR_SWPEN       :1;
					uint32_t                      :20;
			
				//SOOL-SWPMI_CR-DECLARATION
			};
			#endif
			
			#ifdef SWPMI_ICR
			struct ICR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CRXBFF               :1;
					uint32_t CTXBEF               :1;
					uint32_t CRXBERF              :1;
					uint32_t CRXOVRF              :1;
					uint32_t CTXUNRF              :1;
					uint32_t                      :2;
					uint32_t CTCF                 :1;
					uint32_t CSRF                 :1;
					uint32_t                      :2;
					uint32_t SWPMI_ICR_CRDYF      :1;
					uint32_t                      :20;
			
				//SOOL-SWPMI_ICR-DECLARATION
			};
			#endif
			
			#ifdef SWPMI_IER
			struct IER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RXBFIE               :1;
					uint32_t TXBEIE               :1;
					uint32_t RXBERIE              :1;
					uint32_t RXOVRIE              :1;
					uint32_t TXUNRIE              :1;
					uint32_t RIE                  :1;
					uint32_t TIE                  :1;
					uint32_t TCIE                 :1;
					uint32_t SRIE                 :1;
					uint32_t                      :2;
					uint32_t SWPMI_IER_RDYIE      :1;
					uint32_t                      :20;
			
				//SOOL-SWPMI_IER-DECLARATION
			};
			#endif
			
			#ifdef SWPMI_ISR
			struct ISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RXBFF                :1;
					uint32_t TXBEF                :1;
					uint32_t RXBERF               :1;
					uint32_t RXOVRF               :1;
					uint32_t TXUNRF               :1;
					uint32_t RXNE                 :1;
					uint32_t TXE                  :1;
					uint32_t TCF                  :1;
					uint32_t SRF                  :1;
					uint32_t SUSP                 :1;
					uint32_t DEACTF               :1;
					uint32_t SWPMI_ISR_RDYF       :1;
					uint32_t                      :20;
			
				//SOOL-SWPMI_ISR-DECLARATION
			};
			#endif
			
			#ifdef SWPMI_OR
			struct OR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TBYP                 :1;
					uint32_t CLASS                :1;
					uint32_t                      :30;
			
				//SOOL-SWPMI_OR-DECLARATION
			};
			#endif
			
			#ifdef SWPMI_RDR
			struct RDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RD                   :32;
			
				//SOOL-SWPMI_RDR-DECLARATION
			};
			#endif
			
			#ifdef SWPMI_RFL
			struct RFL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t RFL                  :5;
						uint32_t                      :27;
					};
					struct
					{
						uint32_t RFL01                :2;
						uint32_t                      :30;
					};
				};
				//SOOL-SWPMI_RFL-DECLARATION
			};
			#endif
			
			#ifdef SWPMI_TDR
			struct TDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TD                   :32;
			
				//SOOL-SWPMI_TDR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					BRR_TypeDef BRR;     // @0x004
					__SOOL_PERIPH_PADDING_4;
					ISR_TypeDef ISR;     // @0x00c
					ICR_TypeDef ICR;     // @0x010
					IER_TypeDef IER;     // @0x014
					RFL_TypeDef RFL;     // @0x018
					TDR_TypeDef TDR;     // @0x01c
					RDR_TypeDef RDR;     // @0x020
					OR_TypeDef OR;       // @0x024
				};
			};
			private:
			SWPMI() = delete;
			//SOOL-SWPMI-DECLARATION
		};
		
		//region instances
#define SWPMI1_BASE_ADDR ((uint32_t)0x40008800U)
#ifdef SWPMI1_BASE_ADDR
volatile class SWPMI * const SWPMI1 = reinterpret_cast<class SWPMI* const>(SWPMI1_BASE_ADDR);
#endif
//endregion

//SOOL-SWPMI-DEFINES
//SOOL-SWPMI-DEFINITION
	};
};//region undef
#undef SWPMI_CR_SWPEN
#undef SWPMI_ICR_CRDYF
#undef SWPMI_IER_RDYIE
#undef SWPMI_ISR_RDYF
//endregion
#endif
#endif
