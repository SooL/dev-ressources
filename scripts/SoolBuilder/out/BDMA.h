#ifndef __SOOL_BDMA_H
#define __SOOL_BDMA_H

#include "peripheral_include.h"
//SOOL-BDMA-INCLUDES
#if defined(STM32H7     ) 
//region defines

#define BDMA_IFCR
#define BDMA_ISR
#define BDMA_Channel_CCR
#define BDMA_Channel_CMAR
#define BDMA_Channel_CNDTR
#define BDMA_Channel_CPAR

//endregion

namespace sool
{
	namespace core
	{
		class BDMA
		{
			//SOOL-BDMA-ENUMS
			
			public :
			
			#ifdef BDMA_IFCR
			struct IFCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CGIF0                :1;
					uint32_t CTCIF0               :1;
					uint32_t CHTIF0               :1;
					uint32_t CTEIF0               :1;
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
					uint32_t CGIF6                :1;
					uint32_t CTCIF6               :1;
					uint32_t CHTIF6               :1;
					uint32_t CTEIF6               :1;
					uint32_t CGIF7                :1;
					uint32_t CTCIF7               :1;
					uint32_t CHTIF7               :1;
					uint32_t CTEIF7               :1;
			
				//SOOL-BDMA_IFCR-DECLARATION
			};
			#endif
			
			#ifdef BDMA_ISR
			struct ISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t GIF0                 :1;
					uint32_t TCIF0                :1;
					uint32_t HTIF0                :1;
					uint32_t TEIF0                :1;
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
					uint32_t GIF6                 :1;
					uint32_t TCIF6                :1;
					uint32_t HTIF6                :1;
					uint32_t TEIF6                :1;
					uint32_t GIF7                 :1;
					uint32_t TCIF7                :1;
					uint32_t HTIF7                :1;
					uint32_t TEIF7                :1;
			
				//SOOL-BDMA_ISR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					ISR_TypeDef ISR;     // @0x000
					IFCR_TypeDef IFCR;   // @0x004
				};
			};
			private:
			BDMA() = delete;
			//SOOL-BDMA-DECLARATION
		};
		
		
		class BDMA_Channel
		{
			//SOOL-BDMA_Channel-ENUMS
			
			public :
			
			#ifdef BDMA_Channel_CCR
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
			
				//SOOL-BDMA_Channel_CCR-DECLARATION
			};
			#endif
			
			#ifdef BDMA_Channel_CMAR
			struct CMAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MA                   :32;
			
				//SOOL-BDMA_Channel_CMAR-DECLARATION
			};
			#endif
			
			#ifdef BDMA_Channel_CNDTR
			struct CNDTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t NDT                  :16;
					uint32_t                      :16;
			
				//SOOL-BDMA_Channel_CNDTR-DECLARATION
			};
			#endif
			
			#ifdef BDMA_Channel_CPAR
			struct CPAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PA                   :32;
			
				//SOOL-BDMA_Channel_CPAR-DECLARATION
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
			BDMA_Channel() = delete;
			//SOOL-BDMA_Channel-DECLARATION
		};
		
		//region instances
#define BDMA_BASE_ADDR ((uint32_t)0x58025400U)
#if defined(STM32H7     ) 
#define BDMA_Channel0_BASE_ADDR ((uint32_t)0x58025408U)
#define BDMA_Channel1_BASE_ADDR ((uint32_t)0x5802541CU)
#define BDMA_Channel2_BASE_ADDR ((uint32_t)0x58025430U)
#define BDMA_Channel3_BASE_ADDR ((uint32_t)0x58025444U)
#define BDMA_Channel4_BASE_ADDR ((uint32_t)0x58025458U)
#define BDMA_Channel5_BASE_ADDR ((uint32_t)0x5802546CU)
#define BDMA_Channel6_BASE_ADDR ((uint32_t)0x58025480U)
#define BDMA_Channel7_BASE_ADDR ((uint32_t)0x58025494U)
#endif

#ifdef BDMA_BASE_ADDR
volatile class BDMA * const BDMA = reinterpret_cast<class BDMA* const>(BDMA_BASE_ADDR);
#endif
#ifdef BDMA_Channel0_BASE_ADDR
volatile class BDMA_Channel * const BDMA_Channel0 = reinterpret_cast<class BDMA_Channel* const>(BDMA_Channel0_BASE_ADDR);
#endif
#ifdef BDMA_Channel1_BASE_ADDR
volatile class BDMA_Channel * const BDMA_Channel1 = reinterpret_cast<class BDMA_Channel* const>(BDMA_Channel1_BASE_ADDR);
#endif
#ifdef BDMA_Channel2_BASE_ADDR
volatile class BDMA_Channel * const BDMA_Channel2 = reinterpret_cast<class BDMA_Channel* const>(BDMA_Channel2_BASE_ADDR);
#endif
#ifdef BDMA_Channel3_BASE_ADDR
volatile class BDMA_Channel * const BDMA_Channel3 = reinterpret_cast<class BDMA_Channel* const>(BDMA_Channel3_BASE_ADDR);
#endif
#ifdef BDMA_Channel4_BASE_ADDR
volatile class BDMA_Channel * const BDMA_Channel4 = reinterpret_cast<class BDMA_Channel* const>(BDMA_Channel4_BASE_ADDR);
#endif
#ifdef BDMA_Channel5_BASE_ADDR
volatile class BDMA_Channel * const BDMA_Channel5 = reinterpret_cast<class BDMA_Channel* const>(BDMA_Channel5_BASE_ADDR);
#endif
#ifdef BDMA_Channel6_BASE_ADDR
volatile class BDMA_Channel * const BDMA_Channel6 = reinterpret_cast<class BDMA_Channel* const>(BDMA_Channel6_BASE_ADDR);
#endif
#ifdef BDMA_Channel7_BASE_ADDR
volatile class BDMA_Channel * const BDMA_Channel7 = reinterpret_cast<class BDMA_Channel* const>(BDMA_Channel7_BASE_ADDR);
#endif
//endregion

//SOOL-BDMA-DEFINES
//SOOL-BDMA-DEFINITION
	};
};//region undef
//endregion
#endif
#endif
