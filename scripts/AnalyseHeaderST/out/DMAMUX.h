#ifndef __SOOL_DMAMUX_H
#define __SOOL_DMAMUX_H

#include "peripheral_include.h"
//SOOL-DMAMUX-INCLUDES
#if defined(STM32H7     ) || defined(STM32L4P    ) 
//region defines

#define DMAMUX_Channel_CCR
#define DMAMUX_ChannelStatus_CFR
#define DMAMUX_ChannelStatus_CSR
#define DMAMUX_RequestGen_RGCR
#define DMAMUX_RequestGenStatus_RGCFR
#define DMAMUX_RequestGenStatus_RGSR

#if defined(STM32H7     ) 
#define DMAMUX_ChannelStatus_CFR_CSOF14 CSOF14               // 1 bits @ 14
#define DMAMUX_ChannelStatus_CFR_CSOF15 CSOF15               // 1 bits @ 15
#define DMAMUX_ChannelStatus_CSR_SOF14 SOF14                // 1 bits @ 14
#define DMAMUX_ChannelStatus_CSR_SOF15 SOF15                // 1 bits @ 15
#define DMAMUX_RequestGen_RGCR_0_NBREQ NBREQ                // 5 bits @ 19
#define DMAMUX_RequestGenStatus_RGCFR_COF4 COF4                 // 1 bits @ 4
#define DMAMUX_RequestGenStatus_RGCFR_COF5 COF5                 // 1 bits @ 5
#define DMAMUX_RequestGenStatus_RGCFR_COF6 COF6                 // 1 bits @ 6
#define DMAMUX_RequestGenStatus_RGCFR_COF7 COF7                 // 1 bits @ 7
#define DMAMUX_RequestGenStatus_RGSR_OF4 OF4                  // 1 bits @ 4
#define DMAMUX_RequestGenStatus_RGSR_OF5 OF5                  // 1 bits @ 5
#define DMAMUX_RequestGenStatus_RGSR_OF6 OF6                  // 1 bits @ 6
#define DMAMUX_RequestGenStatus_RGSR_OF7 OF7                  // 1 bits @ 7
#else
#define DMAMUX_ChannelStatus_CFR_CSOF14
#define DMAMUX_ChannelStatus_CFR_CSOF15
#define DMAMUX_ChannelStatus_CSR_SOF14
#define DMAMUX_ChannelStatus_CSR_SOF15
#define DMAMUX_RequestGen_RGCR_0_NBREQ
#define DMAMUX_RequestGenStatus_RGCFR_COF4
#define DMAMUX_RequestGenStatus_RGCFR_COF5
#define DMAMUX_RequestGenStatus_RGCFR_COF6
#define DMAMUX_RequestGenStatus_RGCFR_COF7
#define DMAMUX_RequestGenStatus_RGSR_OF4
#define DMAMUX_RequestGenStatus_RGSR_OF5
#define DMAMUX_RequestGenStatus_RGSR_OF6
#define DMAMUX_RequestGenStatus_RGSR_OF7
#endif

#if defined(STM32L4P    ) 
#define DMAMUX_RequestGen_RGCR_1
#endif

//endregion

namespace sool
{
	namespace core
	{
		class DMAMUX_Channel
		{
			//SOOL-DMAMUX_Channel-ENUMS
			
			public :
			
			#ifdef DMAMUX_Channel_CCR
			struct CCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DMAREQ_ID            :8;
					uint32_t SOIE                 :1;
					uint32_t EGE                  :1;
					uint32_t                      :6;
					uint32_t SE                   :1;
					uint32_t SPOL                 :2;
					uint32_t NBREQ                :5;
					uint32_t SYNC_ID              :5;
					uint32_t                      :3;
			
				//SOOL-DMAMUX_Channel_CCR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CCR_TypeDef CCR;     // @0x000
				};
			};
			private:
			DMAMUX_Channel() = delete;
			//SOOL-DMAMUX_Channel-DECLARATION
		};
		
		
		class DMAMUX_ChannelStatus
		{
			//SOOL-DMAMUX_ChannelStatus-ENUMS
			
			public :
			
			#ifdef DMAMUX_ChannelStatus_CFR
			struct CFR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CSOF0                :1;
					uint32_t CSOF1                :1;
					uint32_t CSOF2                :1;
					uint32_t CSOF3                :1;
					uint32_t CSOF4                :1;
					uint32_t CSOF5                :1;
					uint32_t CSOF6                :1;
					uint32_t CSOF7                :1;
					uint32_t CSOF8                :1;
					uint32_t CSOF9                :1;
					uint32_t CSOF10               :1;
					uint32_t CSOF11               :1;
					uint32_t CSOF12               :1;
					uint32_t CSOF13               :1;
					uint32_t DMAMUX_ChannelStatus_CFR_CSOF14 :1;
					uint32_t DMAMUX_ChannelStatus_CFR_CSOF15 :1;
					uint32_t                      :16;
			
				//SOOL-DMAMUX_ChannelStatus_CFR-DECLARATION
			};
			#endif
			
			#ifdef DMAMUX_ChannelStatus_CSR
			struct CSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SOF0                 :1;
					uint32_t SOF1                 :1;
					uint32_t SOF2                 :1;
					uint32_t SOF3                 :1;
					uint32_t SOF4                 :1;
					uint32_t SOF5                 :1;
					uint32_t SOF6                 :1;
					uint32_t SOF7                 :1;
					uint32_t SOF8                 :1;
					uint32_t SOF9                 :1;
					uint32_t SOF10                :1;
					uint32_t SOF11                :1;
					uint32_t SOF12                :1;
					uint32_t SOF13                :1;
					uint32_t DMAMUX_ChannelStatus_CSR_SOF14 :1;
					uint32_t DMAMUX_ChannelStatus_CSR_SOF15 :1;
					uint32_t                      :16;
			
				//SOOL-DMAMUX_ChannelStatus_CSR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CSR_TypeDef CSR;     // @0x000
					CFR_TypeDef CFR;     // @0x004
				};
			};
			private:
			DMAMUX_ChannelStatus() = delete;
			//SOOL-DMAMUX_ChannelStatus-DECLARATION
		};
		
		
		class DMAMUX_RequestGen
		{
			//SOOL-DMAMUX_RequestGen-ENUMS
			
			public :
			
			#ifdef DMAMUX_RequestGen_RGCR
			struct RGCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t SIG_ID               :5;
						uint32_t                      :3;
						uint32_t OIE                  :1;
						uint32_t                      :7;
						uint32_t GE                   :1;
						uint32_t GPOL                 :2;
						uint32_t DMAMUX_RequestGen_RGCR_0_NBREQ :5;
						uint32_t                      :8;
					};
					#ifdef DMAMUX_RequestGen_RGCR_1
					struct
					{
						uint32_t                      :19;
						uint32_t GNBREQ               :5;
						uint32_t                      :8;
					};
					#endif
				};
				//SOOL-DMAMUX_RequestGen_RGCR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					RGCR_TypeDef RGCR;   // @0x000
				};
			};
			private:
			DMAMUX_RequestGen() = delete;
			//SOOL-DMAMUX_RequestGen-DECLARATION
		};
		
		
		class DMAMUX_RequestGenStatus
		{
			//SOOL-DMAMUX_RequestGenStatus-ENUMS
			
			public :
			
			#ifdef DMAMUX_RequestGenStatus_RGCFR
			struct RGCFR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t COF0                 :1;
					uint32_t COF1                 :1;
					uint32_t COF2                 :1;
					uint32_t COF3                 :1;
					uint32_t DMAMUX_RequestGenStatus_RGCFR_COF4 :1;
					uint32_t DMAMUX_RequestGenStatus_RGCFR_COF5 :1;
					uint32_t DMAMUX_RequestGenStatus_RGCFR_COF6 :1;
					uint32_t DMAMUX_RequestGenStatus_RGCFR_COF7 :1;
					uint32_t                      :24;
			
				//SOOL-DMAMUX_RequestGenStatus_RGCFR-DECLARATION
			};
			#endif
			
			#ifdef DMAMUX_RequestGenStatus_RGSR
			struct RGSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t OF0                  :1;
					uint32_t OF1                  :1;
					uint32_t OF2                  :1;
					uint32_t OF3                  :1;
					uint32_t DMAMUX_RequestGenStatus_RGSR_OF4 :1;
					uint32_t DMAMUX_RequestGenStatus_RGSR_OF5 :1;
					uint32_t DMAMUX_RequestGenStatus_RGSR_OF6 :1;
					uint32_t DMAMUX_RequestGenStatus_RGSR_OF7 :1;
					uint32_t                      :24;
			
				//SOOL-DMAMUX_RequestGenStatus_RGSR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					RGSR_TypeDef RGSR;   // @0x000
					RGCFR_TypeDef RGCFR; // @0x004
				};
			};
			private:
			DMAMUX_RequestGenStatus() = delete;
			//SOOL-DMAMUX_RequestGenStatus-DECLARATION
		};
		
		//region instances
#if defined(STM32H7     ) 
#define DMAMUX2_Channel0_BASE_ADDR ((uint32_t)0x58025800U)
#define DMAMUX2_Channel1_BASE_ADDR ((uint32_t)0x58025804U)
#define DMAMUX2_Channel2_BASE_ADDR ((uint32_t)0x58025808U)
#define DMAMUX2_Channel3_BASE_ADDR ((uint32_t)0x5802580CU)
#define DMAMUX2_Channel4_BASE_ADDR ((uint32_t)0x58025810U)
#define DMAMUX2_Channel5_BASE_ADDR ((uint32_t)0x58025814U)
#define DMAMUX2_Channel6_BASE_ADDR ((uint32_t)0x58025818U)
#define DMAMUX2_Channel7_BASE_ADDR ((uint32_t)0x5802581CU)
#define DMAMUX1_Channel14_BASE_ADDR ((uint32_t)0x40020838U)
#define DMAMUX1_Channel15_BASE_ADDR ((uint32_t)0x4002083CU)
#define DMAMUX2_ChannelStatus_BASE_ADDR ((uint32_t)0x58025880U)
#define DMAMUX2_RequestGenerator0_BASE_ADDR ((uint32_t)0x58025900U)
#define DMAMUX2_RequestGenerator1_BASE_ADDR ((uint32_t)0x58025904U)
#define DMAMUX2_RequestGenerator2_BASE_ADDR ((uint32_t)0x58025908U)
#define DMAMUX2_RequestGenerator3_BASE_ADDR ((uint32_t)0x5802590CU)
#define DMAMUX2_RequestGenerator4_BASE_ADDR ((uint32_t)0x58025910U)
#define DMAMUX2_RequestGenerator5_BASE_ADDR ((uint32_t)0x58025914U)
#define DMAMUX2_RequestGenerator6_BASE_ADDR ((uint32_t)0x58025918U)
#define DMAMUX2_RequestGenerator7_BASE_ADDR ((uint32_t)0x5802591CU)
#define DMAMUX1_RequestGenerator4_BASE_ADDR ((uint32_t)0x40020910U)
#define DMAMUX1_RequestGenerator5_BASE_ADDR ((uint32_t)0x40020914U)
#define DMAMUX1_RequestGenerator6_BASE_ADDR ((uint32_t)0x40020918U)
#define DMAMUX1_RequestGenerator7_BASE_ADDR ((uint32_t)0x4002091CU)
#define DMAMUX2_RequestGenStatus_BASE_ADDR ((uint32_t)0x58025940U)
#endif

#if defined(STM32H7     ) || defined(STM32L4P    ) 
#define DMAMUX1_Channel0_BASE_ADDR ((uint32_t)0x40020800U)
#define DMAMUX1_Channel1_BASE_ADDR ((uint32_t)0x40020804U)
#define DMAMUX1_Channel2_BASE_ADDR ((uint32_t)0x40020808U)
#define DMAMUX1_Channel3_BASE_ADDR ((uint32_t)0x4002080CU)
#define DMAMUX1_Channel4_BASE_ADDR ((uint32_t)0x40020810U)
#define DMAMUX1_Channel5_BASE_ADDR ((uint32_t)0x40020814U)
#define DMAMUX1_Channel6_BASE_ADDR ((uint32_t)0x40020818U)
#define DMAMUX1_Channel7_BASE_ADDR ((uint32_t)0x4002081CU)
#define DMAMUX1_Channel8_BASE_ADDR ((uint32_t)0x40020820U)
#define DMAMUX1_Channel9_BASE_ADDR ((uint32_t)0x40020824U)
#define DMAMUX1_Channel10_BASE_ADDR ((uint32_t)0x40020828U)
#define DMAMUX1_Channel11_BASE_ADDR ((uint32_t)0x4002082CU)
#define DMAMUX1_Channel12_BASE_ADDR ((uint32_t)0x40020830U)
#define DMAMUX1_Channel13_BASE_ADDR ((uint32_t)0x40020834U)
#define DMAMUX1_ChannelStatus_BASE_ADDR ((uint32_t)0x40020880U)
#define DMAMUX1_RequestGenerator0_BASE_ADDR ((uint32_t)0x40020900U)
#define DMAMUX1_RequestGenerator1_BASE_ADDR ((uint32_t)0x40020904U)
#define DMAMUX1_RequestGenerator2_BASE_ADDR ((uint32_t)0x40020908U)
#define DMAMUX1_RequestGenerator3_BASE_ADDR ((uint32_t)0x4002090CU)
#define DMAMUX1_RequestGenStatus_BASE_ADDR ((uint32_t)0x40020940U)
#endif

#if defined(STM32L4P    ) 
#define DMAMUX1_BASE_ADDR ((uint32_t)0x40020800U)
#endif

#ifdef DMAMUX2_Channel0_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX2_Channel0 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX2_Channel0_BASE_ADDR);
#endif
#ifdef DMAMUX2_Channel1_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX2_Channel1 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX2_Channel1_BASE_ADDR);
#endif
#ifdef DMAMUX2_Channel2_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX2_Channel2 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX2_Channel2_BASE_ADDR);
#endif
#ifdef DMAMUX2_Channel3_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX2_Channel3 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX2_Channel3_BASE_ADDR);
#endif
#ifdef DMAMUX2_Channel4_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX2_Channel4 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX2_Channel4_BASE_ADDR);
#endif
#ifdef DMAMUX2_Channel5_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX2_Channel5 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX2_Channel5_BASE_ADDR);
#endif
#ifdef DMAMUX2_Channel6_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX2_Channel6 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX2_Channel6_BASE_ADDR);
#endif
#ifdef DMAMUX2_Channel7_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX2_Channel7 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX2_Channel7_BASE_ADDR);
#endif
#ifdef DMAMUX1_Channel14_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX1_Channel14 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX1_Channel14_BASE_ADDR);
#endif
#ifdef DMAMUX1_Channel15_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX1_Channel15 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX1_Channel15_BASE_ADDR);
#endif
#ifdef DMAMUX2_ChannelStatus_BASE_ADDR
volatile class DMAMUX_ChannelStatus * const DMAMUX2_ChannelStatus = reinterpret_cast<class DMAMUX_ChannelStatus* const>(DMAMUX2_ChannelStatus_BASE_ADDR);
#endif
#ifdef DMAMUX2_RequestGenerator0_BASE_ADDR
volatile class DMAMUX_RequestGen * const DMAMUX2_RequestGenerator0 = reinterpret_cast<class DMAMUX_RequestGen* const>(DMAMUX2_RequestGenerator0_BASE_ADDR);
#endif
#ifdef DMAMUX2_RequestGenerator1_BASE_ADDR
volatile class DMAMUX_RequestGen * const DMAMUX2_RequestGenerator1 = reinterpret_cast<class DMAMUX_RequestGen* const>(DMAMUX2_RequestGenerator1_BASE_ADDR);
#endif
#ifdef DMAMUX2_RequestGenerator2_BASE_ADDR
volatile class DMAMUX_RequestGen * const DMAMUX2_RequestGenerator2 = reinterpret_cast<class DMAMUX_RequestGen* const>(DMAMUX2_RequestGenerator2_BASE_ADDR);
#endif
#ifdef DMAMUX2_RequestGenerator3_BASE_ADDR
volatile class DMAMUX_RequestGen * const DMAMUX2_RequestGenerator3 = reinterpret_cast<class DMAMUX_RequestGen* const>(DMAMUX2_RequestGenerator3_BASE_ADDR);
#endif
#ifdef DMAMUX2_RequestGenerator4_BASE_ADDR
volatile class DMAMUX_RequestGen * const DMAMUX2_RequestGenerator4 = reinterpret_cast<class DMAMUX_RequestGen* const>(DMAMUX2_RequestGenerator4_BASE_ADDR);
#endif
#ifdef DMAMUX2_RequestGenerator5_BASE_ADDR
volatile class DMAMUX_RequestGen * const DMAMUX2_RequestGenerator5 = reinterpret_cast<class DMAMUX_RequestGen* const>(DMAMUX2_RequestGenerator5_BASE_ADDR);
#endif
#ifdef DMAMUX2_RequestGenerator6_BASE_ADDR
volatile class DMAMUX_RequestGen * const DMAMUX2_RequestGenerator6 = reinterpret_cast<class DMAMUX_RequestGen* const>(DMAMUX2_RequestGenerator6_BASE_ADDR);
#endif
#ifdef DMAMUX2_RequestGenerator7_BASE_ADDR
volatile class DMAMUX_RequestGen * const DMAMUX2_RequestGenerator7 = reinterpret_cast<class DMAMUX_RequestGen* const>(DMAMUX2_RequestGenerator7_BASE_ADDR);
#endif
#ifdef DMAMUX1_RequestGenerator4_BASE_ADDR
volatile class DMAMUX_RequestGen * const DMAMUX1_RequestGenerator4 = reinterpret_cast<class DMAMUX_RequestGen* const>(DMAMUX1_RequestGenerator4_BASE_ADDR);
#endif
#ifdef DMAMUX1_RequestGenerator5_BASE_ADDR
volatile class DMAMUX_RequestGen * const DMAMUX1_RequestGenerator5 = reinterpret_cast<class DMAMUX_RequestGen* const>(DMAMUX1_RequestGenerator5_BASE_ADDR);
#endif
#ifdef DMAMUX1_RequestGenerator6_BASE_ADDR
volatile class DMAMUX_RequestGen * const DMAMUX1_RequestGenerator6 = reinterpret_cast<class DMAMUX_RequestGen* const>(DMAMUX1_RequestGenerator6_BASE_ADDR);
#endif
#ifdef DMAMUX1_RequestGenerator7_BASE_ADDR
volatile class DMAMUX_RequestGen * const DMAMUX1_RequestGenerator7 = reinterpret_cast<class DMAMUX_RequestGen* const>(DMAMUX1_RequestGenerator7_BASE_ADDR);
#endif
#ifdef DMAMUX2_RequestGenStatus_BASE_ADDR
volatile class DMAMUX_RequestGenStatus * const DMAMUX2_RequestGenStatus = reinterpret_cast<class DMAMUX_RequestGenStatus* const>(DMAMUX2_RequestGenStatus_BASE_ADDR);
#endif
#ifdef DMAMUX1_Channel0_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX1_Channel0 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX1_Channel0_BASE_ADDR);
#endif
#ifdef DMAMUX1_Channel1_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX1_Channel1 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX1_Channel1_BASE_ADDR);
#endif
#ifdef DMAMUX1_Channel2_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX1_Channel2 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX1_Channel2_BASE_ADDR);
#endif
#ifdef DMAMUX1_Channel3_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX1_Channel3 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX1_Channel3_BASE_ADDR);
#endif
#ifdef DMAMUX1_Channel4_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX1_Channel4 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX1_Channel4_BASE_ADDR);
#endif
#ifdef DMAMUX1_Channel5_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX1_Channel5 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX1_Channel5_BASE_ADDR);
#endif
#ifdef DMAMUX1_Channel6_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX1_Channel6 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX1_Channel6_BASE_ADDR);
#endif
#ifdef DMAMUX1_Channel7_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX1_Channel7 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX1_Channel7_BASE_ADDR);
#endif
#ifdef DMAMUX1_Channel8_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX1_Channel8 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX1_Channel8_BASE_ADDR);
#endif
#ifdef DMAMUX1_Channel9_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX1_Channel9 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX1_Channel9_BASE_ADDR);
#endif
#ifdef DMAMUX1_Channel10_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX1_Channel10 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX1_Channel10_BASE_ADDR);
#endif
#ifdef DMAMUX1_Channel11_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX1_Channel11 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX1_Channel11_BASE_ADDR);
#endif
#ifdef DMAMUX1_Channel12_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX1_Channel12 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX1_Channel12_BASE_ADDR);
#endif
#ifdef DMAMUX1_Channel13_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX1_Channel13 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX1_Channel13_BASE_ADDR);
#endif
#ifdef DMAMUX1_ChannelStatus_BASE_ADDR
volatile class DMAMUX_ChannelStatus * const DMAMUX1_ChannelStatus = reinterpret_cast<class DMAMUX_ChannelStatus* const>(DMAMUX1_ChannelStatus_BASE_ADDR);
#endif
#ifdef DMAMUX1_RequestGenerator0_BASE_ADDR
volatile class DMAMUX_RequestGen * const DMAMUX1_RequestGenerator0 = reinterpret_cast<class DMAMUX_RequestGen* const>(DMAMUX1_RequestGenerator0_BASE_ADDR);
#endif
#ifdef DMAMUX1_RequestGenerator1_BASE_ADDR
volatile class DMAMUX_RequestGen * const DMAMUX1_RequestGenerator1 = reinterpret_cast<class DMAMUX_RequestGen* const>(DMAMUX1_RequestGenerator1_BASE_ADDR);
#endif
#ifdef DMAMUX1_RequestGenerator2_BASE_ADDR
volatile class DMAMUX_RequestGen * const DMAMUX1_RequestGenerator2 = reinterpret_cast<class DMAMUX_RequestGen* const>(DMAMUX1_RequestGenerator2_BASE_ADDR);
#endif
#ifdef DMAMUX1_RequestGenerator3_BASE_ADDR
volatile class DMAMUX_RequestGen * const DMAMUX1_RequestGenerator3 = reinterpret_cast<class DMAMUX_RequestGen* const>(DMAMUX1_RequestGenerator3_BASE_ADDR);
#endif
#ifdef DMAMUX1_RequestGenStatus_BASE_ADDR
volatile class DMAMUX_RequestGenStatus * const DMAMUX1_RequestGenStatus = reinterpret_cast<class DMAMUX_RequestGenStatus* const>(DMAMUX1_RequestGenStatus_BASE_ADDR);
#endif
#ifdef DMAMUX1_BASE_ADDR
volatile class DMAMUX_Channel * const DMAMUX1 = reinterpret_cast<class DMAMUX_Channel* const>(DMAMUX1_BASE_ADDR);
#endif
//endregion

//SOOL-DMAMUX-DEFINES
//SOOL-DMAMUX-DEFINITION
	};
};//region undef
#undef DMAMUX_ChannelStatus_CFR_CSOF14
#undef DMAMUX_ChannelStatus_CFR_CSOF15
#undef DMAMUX_ChannelStatus_CSR_SOF14
#undef DMAMUX_ChannelStatus_CSR_SOF15
#undef DMAMUX_RequestGen_RGCR_0_NBREQ
#undef DMAMUX_RequestGenStatus_RGCFR_COF4
#undef DMAMUX_RequestGenStatus_RGCFR_COF5
#undef DMAMUX_RequestGenStatus_RGCFR_COF6
#undef DMAMUX_RequestGenStatus_RGCFR_COF7
#undef DMAMUX_RequestGenStatus_RGSR_OF4
#undef DMAMUX_RequestGenStatus_RGSR_OF5
#undef DMAMUX_RequestGenStatus_RGSR_OF6
#undef DMAMUX_RequestGenStatus_RGSR_OF7
//endregion
#endif
#endif
