#ifndef __SOOL_LTDC_H
#define __SOOL_LTDC_H

#include "peripheral_include.h"
//SOOL-LTDC-INCLUDES
#if defined(STM32F429xx ) || defined(STM32F439xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) ||\
    defined(STM32F746xx ) || defined(STM32F756xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) ||\
    defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32H7     ) || defined(STM32L4R7xx ) ||\
    defined(STM32L4R9xx ) || defined(STM32L4S7xx ) || defined(STM32L4S9xx ) 
//region defines

#define LTDC_AWCR
#define LTDC_BCCR
#define LTDC_BPCR
#define LTDC_CDSR
#define LTDC_CPSR
#define LTDC_GCR
#define LTDC_ICR
#define LTDC_IER
#define LTDC_ISR
#define LTDC_LIPCR
#define LTDC_SRCR
#define LTDC_SSCR
#define LTDC_TWCR
#define LTDC_Layer_BFCR
#define LTDC_Layer_CACR
#define LTDC_Layer_CFBAR
#define LTDC_Layer_CFBLNR
#define LTDC_Layer_CFBLR
#define LTDC_Layer_CKCR
#define LTDC_Layer_CLUTWR
#define LTDC_Layer_CR
#define LTDC_Layer_DCCR
#define LTDC_Layer_PFCR
#define LTDC_Layer_WHPCR
#define LTDC_Layer_WVPCR

#if defined(STM32F429xx ) || defined(STM32F439xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) ||\
    defined(STM32F746xx ) || defined(STM32F756xx ) 
#define LTDC_GCR_1
#endif

#if defined(STM32F429xx ) || defined(STM32F439xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) ||\
    defined(STM32F746xx ) || defined(STM32F756xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) ||\
    defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32H7     ) 
#define LTDC_Layer_WHPCR_0_WHSPPOS WHSPPOS              // 16 bits @ 16
#define LTDC_Layer_WVPCR_0_WVSPPOS WVSPPOS              // 16 bits @ 16
#else
#define LTDC_Layer_WHPCR_0_WHSPPOS
#define LTDC_Layer_WVPCR_0_WVSPPOS
#endif

#if defined(STM32L4R7xx ) || defined(STM32L4R9xx ) || defined(STM32L4S7xx ) || defined(STM32L4S9xx ) 
#define LTDC_Layer_WHPCR_1
#define LTDC_Layer_WVPCR_1
#endif

//endregion

namespace sool
{
	namespace core
	{
		class LTDC
		{
			//SOOL-LTDC-ENUMS
			
			public :
			
			#ifdef LTDC_AWCR
			struct AWCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t AAH                  :11;
					uint32_t                      :5;
					uint32_t AAW                  :12;
					uint32_t                      :4;
			
				//SOOL-LTDC_AWCR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_BCCR
			struct BCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t BCBLUE               :8;
					uint32_t BCGREEN              :8;
					uint32_t BCRED                :8;
					uint32_t                      :8;
			
				//SOOL-LTDC_BCCR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_BPCR
			struct BPCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t AVBP                 :11;
					uint32_t                      :5;
					uint32_t AHBP                 :12;
					uint32_t                      :4;
			
				//SOOL-LTDC_BPCR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_CDSR
			struct CDSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t VDES                 :1;
					uint32_t HDES                 :1;
					uint32_t VSYNCS               :1;
					uint32_t HSYNCS               :1;
					uint32_t                      :28;
			
				//SOOL-LTDC_CDSR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_CPSR
			struct CPSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CYPOS                :16;
					uint32_t CXPOS                :16;
			
				//SOOL-LTDC_CPSR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_GCR
			struct GCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t LTDCEN               :1;
						uint32_t                      :3;
						uint32_t DBW                  :3;
						uint32_t                      :1;
						uint32_t DGW                  :3;
						uint32_t                      :1;
						uint32_t DRW                  :3;
						uint32_t                      :1;
						uint32_t DEN                  :1;
						uint32_t                      :11;
						uint32_t PCPOL                :1;
						uint32_t DEPOL                :1;
						uint32_t VSPOL                :1;
						uint32_t HSPOL                :1;
					};
					#ifdef LTDC_GCR_1
					struct
					{
						uint32_t                      :16;
						uint32_t DTEN                 :1;
						uint32_t                      :15;
					};
					#endif
				};
				//SOOL-LTDC_GCR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_ICR
			struct ICR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CLIF                 :1;
					uint32_t CFUIF                :1;
					uint32_t CTERRIF              :1;
					uint32_t CRRIF                :1;
					uint32_t                      :28;
			
				//SOOL-LTDC_ICR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_IER
			struct IER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t LIE                  :1;
					uint32_t FUIE                 :1;
					uint32_t TERRIE               :1;
					uint32_t RRIE                 :1;
					uint32_t                      :28;
			
				//SOOL-LTDC_IER-DECLARATION
			};
			#endif
			
			#ifdef LTDC_ISR
			struct ISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t LIF                  :1;
					uint32_t FUIF                 :1;
					uint32_t TERRIF               :1;
					uint32_t RRIF                 :1;
					uint32_t                      :28;
			
				//SOOL-LTDC_ISR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_LIPCR
			struct LIPCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t LIPOS                :11;
					uint32_t                      :21;
			
				//SOOL-LTDC_LIPCR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_SRCR
			struct SRCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t IMR                  :1;
					uint32_t VBR                  :1;
					uint32_t                      :30;
			
				//SOOL-LTDC_SRCR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_SSCR
			struct SSCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t VSH                  :11;
					uint32_t                      :5;
					uint32_t HSW                  :12;
					uint32_t                      :4;
			
				//SOOL-LTDC_SSCR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_TWCR
			struct TWCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TOTALH               :11;
					uint32_t                      :5;
					uint32_t TOTALW               :12;
					uint32_t                      :4;
			
				//SOOL-LTDC_TWCR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					__SOOL_PERIPH_PADDING_8;
					SSCR_TypeDef SSCR;   // @0x008
					BPCR_TypeDef BPCR;   // @0x00c
					AWCR_TypeDef AWCR;   // @0x010
					TWCR_TypeDef TWCR;   // @0x014
					GCR_TypeDef GCR;     // @0x018
					__SOOL_PERIPH_PADDING_8;
					SRCR_TypeDef SRCR;   // @0x024
					__SOOL_PERIPH_PADDING_4;
					BCCR_TypeDef BCCR;   // @0x02c
					__SOOL_PERIPH_PADDING_4;
					IER_TypeDef IER;     // @0x034
					ISR_TypeDef ISR;     // @0x038
					ICR_TypeDef ICR;     // @0x03c
					LIPCR_TypeDef LIPCR; // @0x040
					CPSR_TypeDef CPSR;   // @0x044
					CDSR_TypeDef CDSR;   // @0x048
				};
			};
			private:
			LTDC() = delete;
			//SOOL-LTDC-DECLARATION
		};
		
		
		class LTDC_Layer
		{
			//SOOL-LTDC_Layer-ENUMS
			
			public :
			
			#ifdef LTDC_Layer_BFCR
			struct BFCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t BF2                  :3;
					uint32_t                      :5;
					uint32_t BF1                  :3;
					uint32_t                      :21;
			
				//SOOL-LTDC_Layer_BFCR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_Layer_CACR
			struct CACR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CONSTA               :8;
					uint32_t                      :24;
			
				//SOOL-LTDC_Layer_CACR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_Layer_CFBAR
			struct CFBAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CFBADD               :32;
			
				//SOOL-LTDC_Layer_CFBAR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_Layer_CFBLNR
			struct CFBLNR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CFBLNBR              :11;
					uint32_t                      :21;
			
				//SOOL-LTDC_Layer_CFBLNR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_Layer_CFBLR
			struct CFBLR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CFBLL                :13;
					uint32_t                      :3;
					uint32_t CFBP                 :13;
					uint32_t                      :3;
			
				//SOOL-LTDC_Layer_CFBLR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_Layer_CKCR
			struct CKCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CKBLUE               :8;
					uint32_t CKGREEN              :8;
					uint32_t CKRED                :8;
					uint32_t                      :8;
			
				//SOOL-LTDC_Layer_CKCR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_Layer_CLUTWR
			struct CLUTWR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t BLUE                 :8;
					uint32_t GREEN                :8;
					uint32_t RED                  :8;
					uint32_t CLUTADD              :8;
			
				//SOOL-LTDC_Layer_CLUTWR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_Layer_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t LEN                  :1;
					uint32_t COLKEN               :1;
					uint32_t                      :2;
					uint32_t CLUTEN               :1;
					uint32_t                      :27;
			
				//SOOL-LTDC_Layer_CR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_Layer_DCCR
			struct DCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DCBLUE               :8;
					uint32_t DCGREEN              :8;
					uint32_t DCRED                :8;
					uint32_t DCALPHA              :8;
			
				//SOOL-LTDC_Layer_DCCR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_Layer_PFCR
			struct PFCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PF                   :3;
					uint32_t                      :29;
			
				//SOOL-LTDC_Layer_PFCR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_Layer_WHPCR
			struct WHPCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t WHSTPOS              :12;
						uint32_t                      :4;
						uint32_t LTDC_Layer_WHPCR_0_WHSPPOS :16;
					};
					#ifdef LTDC_Layer_WHPCR_1
					struct
					{
						uint32_t                      :16;
						uint32_t WHSPPOS              :12;
						uint32_t                      :4;
					};
					#endif
				};
				//SOOL-LTDC_Layer_WHPCR-DECLARATION
			};
			#endif
			
			#ifdef LTDC_Layer_WVPCR
			struct WVPCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t WVSTPOS              :12;
						uint32_t                      :4;
						uint32_t LTDC_Layer_WVPCR_0_WVSPPOS :16;
					};
					#ifdef LTDC_Layer_WVPCR_1
					struct
					{
						uint32_t                      :16;
						uint32_t WVSPPOS              :12;
						uint32_t                      :4;
					};
					#endif
				};
				//SOOL-LTDC_Layer_WVPCR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					WHPCR_TypeDef WHPCR; // @0x004
					WVPCR_TypeDef WVPCR; // @0x008
					CKCR_TypeDef CKCR;   // @0x00c
					PFCR_TypeDef PFCR;   // @0x010
					CACR_TypeDef CACR;   // @0x014
					DCCR_TypeDef DCCR;   // @0x018
					BFCR_TypeDef BFCR;   // @0x01c
					__SOOL_PERIPH_PADDING_8;
					CFBAR_TypeDef CFBAR; // @0x028
					CFBLR_TypeDef CFBLR; // @0x02c
					CFBLNR_TypeDef CFBLNR; // @0x030
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					CLUTWR_TypeDef CLUTWR; // @0x040
				};
			};
			private:
			LTDC_Layer() = delete;
			//SOOL-LTDC_Layer-DECLARATION
		};
		
		//region instances
#if defined(STM32F429xx ) || defined(STM32F439xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) ||\
    defined(STM32F746xx ) || defined(STM32F756xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) ||\
    defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32L4R7xx ) || defined(STM32L4R9xx ) ||\
    defined(STM32L4S7xx ) || defined(STM32L4S9xx ) 
#define LTDC_BASE_ADDR ((uint32_t)0x40016800U)
#define LTDC_Layer1_BASE_ADDR ((uint32_t)0x40016884U)
#define LTDC_Layer2_BASE_ADDR ((uint32_t)0x40016904U)
#endif

#if defined(STM32H7     ) 
#define LTDC_BASE_ADDR ((uint32_t)0x50001000U)
#define LTDC_Layer1_BASE_ADDR ((uint32_t)0x50001084U)
#define LTDC_Layer2_BASE_ADDR ((uint32_t)0x50001104U)
#endif

#ifdef LTDC_BASE_ADDR
volatile class LTDC * const LTDC = reinterpret_cast<class LTDC* const>(LTDC_BASE_ADDR);
#endif
#ifdef LTDC_Layer1_BASE_ADDR
volatile class LTDC_Layer * const LTDC_Layer1 = reinterpret_cast<class LTDC_Layer* const>(LTDC_Layer1_BASE_ADDR);
#endif
#ifdef LTDC_Layer2_BASE_ADDR
volatile class LTDC_Layer * const LTDC_Layer2 = reinterpret_cast<class LTDC_Layer* const>(LTDC_Layer2_BASE_ADDR);
#endif
//endregion

//SOOL-LTDC-DEFINES
//SOOL-LTDC-DEFINITION
	};
};//region undef
#undef LTDC_Layer_WHPCR_0_WHSPPOS
#undef LTDC_Layer_WVPCR_0_WVSPPOS
//endregion
#endif
#endif
