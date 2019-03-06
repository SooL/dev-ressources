#ifndef __SOOL_DMA2D_H
#define __SOOL_DMA2D_H

#include "peripheral_include.h"
//SOOL-DMA2D-INCLUDES
#if defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F745xx ) || defined(STM32F746xx ) ||\
    defined(STM32F756xx ) || defined(STM32F765xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) ||\
    defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32H7     ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) || defined(STM32L4P    ) 
//region defines

#define DMA2D_AMTCR
#define DMA2D_BGCLUT
#define DMA2D_BGCMAR
#define DMA2D_BGCOLR
#define DMA2D_BGMAR
#define DMA2D_BGOR
#define DMA2D_BGPFCCR
#define DMA2D_CR
#define DMA2D_FGCLUT
#define DMA2D_FGCMAR
#define DMA2D_FGCOLR
#define DMA2D_FGMAR
#define DMA2D_FGOR
#define DMA2D_FGPFCCR
#define DMA2D_IFCR
#define DMA2D_ISR
#define DMA2D_LWR
#define DMA2D_NLR
#define DMA2D_OCOLR
#define DMA2D_OMAR
#define DMA2D_OOR
#define DMA2D_OPFCCR

#if defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F745xx ) || defined(STM32F746xx ) ||\
    defined(STM32F756xx ) || defined(STM32F765xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) ||\
    defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32H7     ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) 
#define DMA2D_BGOR_0
#define DMA2D_CR_0_MODE      MODE                 // 2 bits @ 16
#define DMA2D_FGOR_0
#define DMA2D_OOR_0
#else
#define DMA2D_CR_0_MODE
#endif

#if defined(STM32L4P    ) 
#define DMA2D_BGOR_1
#define DMA2D_CR_0_LOM       LOM                  // 1 bits @ 6
#define DMA2D_CR_1
#define DMA2D_FGOR_1
#define DMA2D_OOR_1
#define DMA2D_OPFCCR_SB      SB                   // 1 bits @ 8
#define DMA2D_VERR
#define DMA2D_MAP0_VERR      VERR_TypeDef VERR
#else
#define DMA2D_CR_0_LOM
#define DMA2D_OPFCCR_SB
#define DMA2D_MAP0_VERR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F765xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) || defined(STM32F777xx ) ||\
    defined(STM32F779xx ) || defined(STM32H7     ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) ||\
    defined(STM32L4P    ) 
#define DMA2D_BGPFCCR_AI     AI                   // 1 bits @ 20
#define DMA2D_BGPFCCR_RBS    RBS                  // 1 bits @ 21
#define DMA2D_FGPFCCR_AI     AI                   // 1 bits @ 20
#define DMA2D_FGPFCCR_RBS    RBS                  // 1 bits @ 21
#define DMA2D_OPFCCR_AI      AI                   // 1 bits @ 20
#define DMA2D_OPFCCR_RBS     RBS                  // 1 bits @ 21
#else
#define DMA2D_BGPFCCR_AI
#define DMA2D_BGPFCCR_RBS
#define DMA2D_FGPFCCR_AI
#define DMA2D_FGPFCCR_RBS
#define DMA2D_OPFCCR_AI
#define DMA2D_OPFCCR_RBS
#endif

#if defined(STM32H7     ) 
#define DMA2D_FGPFCCR_CSS    CSS                  // 2 bits @ 18
#else
#define DMA2D_FGPFCCR_CSS
#endif

//endregion

namespace sool
{
	namespace core
	{
		class DMA2D
		{
			//SOOL-DMA2D-ENUMS
			
			public :
			
			#ifdef DMA2D_AMTCR
			struct AMTCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EN                   :1;
					uint32_t                      :7;
					uint32_t DT                   :8;
					uint32_t                      :16;
			
				//SOOL-DMA2D_AMTCR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_BGCMAR
			struct BGCMAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MA                   :32;
			
				//SOOL-DMA2D_BGCMAR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_BGCOLR
			struct BGCOLR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t BLUE                 :8;
					uint32_t GREEN                :8;
					uint32_t RED                  :8;
					uint32_t                      :8;
			
				//SOOL-DMA2D_BGCOLR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_BGMAR
			struct BGMAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MA                   :32;
			
				//SOOL-DMA2D_BGMAR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_BGOR
			struct BGOR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DMA2D_BGOR_0
					struct
					{
						uint32_t LO                   :14;
						uint32_t                      :18;
					};
					#endif
					#ifdef DMA2D_BGOR_1
					struct
					{
						uint32_t LO                   :16;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-DMA2D_BGOR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_BGPFCCR
			struct BGPFCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CM                   :4;
					uint32_t CCM                  :1;
					uint32_t START                :1;
					uint32_t                      :2;
					uint32_t CS                   :8;
					uint32_t AM                   :2;
					uint32_t                      :2;
					uint32_t DMA2D_BGPFCCR_AI     :1;
					uint32_t DMA2D_BGPFCCR_RBS    :1;
					uint32_t                      :2;
					uint32_t ALPHA                :8;
			
				//SOOL-DMA2D_BGPFCCR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t START                :1;
						uint32_t SUSP                 :1;
						uint32_t ABORT                :1;
						uint32_t                      :3;
						uint32_t DMA2D_CR_0_LOM       :1;
						uint32_t                      :1;
						uint32_t TEIE                 :1;
						uint32_t TCIE                 :1;
						uint32_t TWIE                 :1;
						uint32_t CAEIE                :1;
						uint32_t CTCIE                :1;
						uint32_t CEIE                 :1;
						uint32_t                      :2;
						uint32_t DMA2D_CR_0_MODE      :2;
						uint32_t                      :14;
					};
					#ifdef DMA2D_CR_1
					struct
					{
						uint32_t                      :16;
						uint32_t MODE                 :3;
						uint32_t                      :13;
					};
					#endif
				};
				//SOOL-DMA2D_CR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_FGCMAR
			struct FGCMAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MA                   :32;
			
				//SOOL-DMA2D_FGCMAR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_FGCOLR
			struct FGCOLR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t BLUE                 :8;
					uint32_t GREEN                :8;
					uint32_t RED                  :8;
					uint32_t                      :8;
			
				//SOOL-DMA2D_FGCOLR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_FGMAR
			struct FGMAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MA                   :32;
			
				//SOOL-DMA2D_FGMAR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_FGOR
			struct FGOR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DMA2D_FGOR_0
					struct
					{
						uint32_t LO                   :14;
						uint32_t                      :18;
					};
					#endif
					#ifdef DMA2D_FGOR_1
					struct
					{
						uint32_t LO                   :16;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-DMA2D_FGOR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_FGPFCCR
			struct FGPFCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CM                   :4;
					uint32_t CCM                  :1;
					uint32_t START                :1;
					uint32_t                      :2;
					uint32_t CS                   :8;
					uint32_t AM                   :2;
					uint32_t DMA2D_FGPFCCR_CSS    :2;
					uint32_t DMA2D_FGPFCCR_AI     :1;
					uint32_t DMA2D_FGPFCCR_RBS    :1;
					uint32_t                      :2;
					uint32_t ALPHA                :8;
			
				//SOOL-DMA2D_FGPFCCR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_IFCR
			struct IFCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CTEIF                :1;
					uint32_t CTCIF                :1;
					uint32_t CTWIF                :1;
					uint32_t CAECIF               :1;
					uint32_t CCTCIF               :1;
					uint32_t CCEIF                :1;
					uint32_t                      :26;
			
				//SOOL-DMA2D_IFCR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_ISR
			struct ISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TEIF                 :1;
					uint32_t TCIF                 :1;
					uint32_t TWIF                 :1;
					uint32_t CAEIF                :1;
					uint32_t CTCIF                :1;
					uint32_t CEIF                 :1;
					uint32_t                      :26;
			
				//SOOL-DMA2D_ISR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_LWR
			struct LWR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t LW                   :16;
					uint32_t                      :16;
			
				//SOOL-DMA2D_LWR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_NLR
			struct NLR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t NL                   :16;
					uint32_t PL                   :14;
					uint32_t                      :2;
			
				//SOOL-DMA2D_NLR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_OCOLR
			struct OCOLR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t BLUE1                :8;
						uint32_t GREEN1               :8;
						uint32_t RED1                 :8;
						uint32_t ALPHA1               :8;
					};
					struct
					{
						uint32_t BLUE2                :5;
						uint32_t GREEN2               :6;
						uint32_t RED2                 :5;
						uint32_t                      :16;
					};
					struct
					{
						uint32_t BLUE3                :5;
						uint32_t GREEN3               :5;
						uint32_t RED3                 :5;
						uint32_t ALPHA3               :1;
						uint32_t                      :16;
					};
					struct
					{
						uint32_t BLUE4                :4;
						uint32_t GREEN4               :4;
						uint32_t RED4                 :4;
						uint32_t ALPHA4               :4;
						uint32_t                      :16;
					};
				};
				//SOOL-DMA2D_OCOLR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_OMAR
			struct OMAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MA                   :32;
			
				//SOOL-DMA2D_OMAR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_OOR
			struct OOR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DMA2D_OOR_0
					struct
					{
						uint32_t LO                   :14;
						uint32_t                      :18;
					};
					#endif
					#ifdef DMA2D_OOR_1
					struct
					{
						uint32_t LO                   :16;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-DMA2D_OOR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_OPFCCR
			struct OPFCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CM                   :3;
					uint32_t                      :5;
					uint32_t DMA2D_OPFCCR_SB      :1;
					uint32_t                      :11;
					uint32_t DMA2D_OPFCCR_AI      :1;
					uint32_t DMA2D_OPFCCR_RBS     :1;
					uint32_t                      :10;
			
				//SOOL-DMA2D_OPFCCR-DECLARATION
			};
			#endif
			
			#ifdef DMA2D_VERR
			struct VERR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MINREV               :4;
					uint32_t MAJREV               :4;
					uint32_t                      :24;
			
				//SOOL-DMA2D_VERR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					ISR_TypeDef ISR;     // @0x004
					IFCR_TypeDef IFCR;   // @0x008
					FGMAR_TypeDef FGMAR; // @0x00c
					FGOR_TypeDef FGOR;   // @0x010
					BGMAR_TypeDef BGMAR; // @0x014
					BGOR_TypeDef BGOR;   // @0x018
					FGPFCCR_TypeDef FGPFCCR; // @0x01c
					FGCOLR_TypeDef FGCOLR; // @0x020
					BGPFCCR_TypeDef BGPFCCR; // @0x024
					BGCOLR_TypeDef BGCOLR; // @0x028
					FGCMAR_TypeDef FGCMAR; // @0x02c
					BGCMAR_TypeDef BGCMAR; // @0x030
					OPFCCR_TypeDef OPFCCR; // @0x034
					OCOLR_TypeDef OCOLR; // @0x038
					OMAR_TypeDef OMAR;   // @0x03c
					OOR_TypeDef OOR;     // @0x040
					NLR_TypeDef NLR;     // @0x044
					LWR_TypeDef LWR;     // @0x048
					AMTCR_TypeDef AMTCR; // @0x04c
					__SOOL_PERIPH_PADDING_512;
					__SOOL_PERIPH_PADDING_256;
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_4;
					DMA2D_MAP0_VERR;     // @0x3f4
					__SOOL_PERIPH_PADDING_8;
					uint32_t FGCLUT[256]; // @0x400
					uint32_t BGCLUT[256]; // @0x800
				};
			};
			private:
			DMA2D() = delete;
			//SOOL-DMA2D-DECLARATION
		};
		
		//region instances
#if defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F745xx ) || defined(STM32F746xx ) ||\
    defined(STM32F756xx ) || defined(STM32F765xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) ||\
    defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) ||\
    defined(STM32L4P    ) 
#define DMA2D_BASE_ADDR ((uint32_t)0x4002B000U)
#endif

#if defined(STM32H7     ) 
#define DMA2D_BASE_ADDR ((uint32_t)0x52001000U)
#endif

#ifdef DMA2D_BASE_ADDR
volatile class DMA2D * const DMA2D = reinterpret_cast<class DMA2D* const>(DMA2D_BASE_ADDR);
#endif
//endregion

//SOOL-DMA2D-DEFINES
//SOOL-DMA2D-DEFINITION
	};
};//region undef
#undef DMA2D_CR_0_MODE
#undef DMA2D_CR_0_LOM
#undef DMA2D_OPFCCR_SB
#undef DMA2D_MAP0_VERR
#undef DMA2D_BGPFCCR_AI
#undef DMA2D_BGPFCCR_RBS
#undef DMA2D_FGPFCCR_AI
#undef DMA2D_FGPFCCR_RBS
#undef DMA2D_OPFCCR_AI
#undef DMA2D_OPFCCR_RBS
#undef DMA2D_FGPFCCR_CSS
//endregion
#endif
#endif
