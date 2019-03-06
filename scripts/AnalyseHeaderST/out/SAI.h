#ifndef __SOOL_SAI_H
#define __SOOL_SAI_H

#include "peripheral_include.h"
//SOOL-SAI-INCLUDES
#if defined(STM32F413xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L4     ) ||\
    defined(STM32L4P    ) 
//region defines

#define SAI_GCR
#define SAI_Block_CLRFR
#define SAI_Block_CR1
#define SAI_Block_CR2
#define SAI_Block_DR
#define SAI_Block_FRCR
#define SAI_Block_IMR
#define SAI_Block_SLOTR
#define SAI_Block_SR

#if defined(STM32H7     ) || defined(STM32L4P    ) 
#define SAI_PDMCR
#define SAI_PDMDLY
#define SAI_Block_CR1_0_OSR  OSR                  // 1 bits @ 26
#define SAI_Block_CR1_1
#define SAI_MAP0_PDMCR       PDMCR_TypeDef PDMCR
#define SAI_MAP0_PDMDLY      PDMDLY_TypeDef PDMDLY
#else
#define SAI_Block_CR1_0_OSR
#define SAI_MAP0_PDMCR __SOOL_PERIPH_PADDING_4
#define SAI_MAP0_PDMDLY __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F413xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32L4     ) 
#define SAI_Block_CR1_0_NODIV NODIV                // 1 bits @ 19
#define SAI_Block_CR1_0_MCKDIV MCKDIV               // 4 bits @ 20
#else
#define SAI_Block_CR1_0_NODIV
#define SAI_Block_CR1_0_MCKDIV
#endif

#if defined(STM32F413xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32H7     ) 
#define SAI_Block_FRCR_1
#endif

//endregion

namespace sool
{
	namespace core
	{
		class SAI
		{
			//SOOL-SAI-ENUMS
			
			public :
			
			#ifdef SAI_GCR
			struct GCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SYNCIN               :2;
					uint32_t                      :2;
					uint32_t SYNCOUT              :2;
					uint32_t                      :26;
			
				//SOOL-SAI_GCR-DECLARATION
			};
			#endif
			
			#ifdef SAI_PDMCR
			struct PDMCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PDMEN                :1;
					uint32_t                      :3;
					uint32_t MICNBR               :2;
					uint32_t                      :2;
					uint32_t CKEN1                :1;
					uint32_t CKEN2                :1;
					uint32_t CKEN3                :1;
					uint32_t CKEN4                :1;
					uint32_t                      :20;
			
				//SOOL-SAI_PDMCR-DECLARATION
			};
			#endif
			
			#ifdef SAI_PDMDLY
			struct PDMDLY_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DLYM1L               :3;
					uint32_t                      :1;
					uint32_t DLYM1R               :3;
					uint32_t                      :1;
					uint32_t DLYM2L               :3;
					uint32_t                      :1;
					uint32_t DLYM2R               :3;
					uint32_t                      :1;
					uint32_t DLYM3L               :3;
					uint32_t                      :1;
					uint32_t DLYM3R               :3;
					uint32_t                      :1;
					uint32_t DLYM4L               :3;
					uint32_t                      :1;
					uint32_t DLYM4R               :3;
					uint32_t                      :1;
			
				//SOOL-SAI_PDMDLY-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					GCR_TypeDef GCR;     // @0x000
					__SOOL_PERIPH_PADDING_64;
					SAI_MAP0_PDMCR;      // @0x044
					SAI_MAP0_PDMDLY;     // @0x048
				};
			};
			private:
			SAI() = delete;
			//SOOL-SAI-DECLARATION
		};
		
		
		class SAI_Block
		{
			//SOOL-SAI_Block-ENUMS
			
			public :
			
			#ifdef SAI_Block_CLRFR
			struct CLRFR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t COVRUDR              :1;
					uint32_t CMUTEDET             :1;
					uint32_t CWCKCFG              :1;
					uint32_t CFREQ                :1;
					uint32_t CCNRDY               :1;
					uint32_t CAFSDET              :1;
					uint32_t CLFSDET              :1;
					uint32_t                      :25;
			
				//SOOL-SAI_Block_CLRFR-DECLARATION
			};
			#endif
			
			#ifdef SAI_Block_CR1
			struct CR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t MODE                 :2;
						uint32_t PRTCFG               :2;
						uint32_t                      :1;
						uint32_t DS                   :3;
						uint32_t LSBFIRST             :1;
						uint32_t CKSTR                :1;
						uint32_t SYNCEN               :2;
						uint32_t MONO                 :1;
						uint32_t OUTDRIV              :1;
						uint32_t                      :2;
						uint32_t SAIEN                :1;
						uint32_t DMAEN                :1;
						uint32_t                      :1;
						uint32_t SAI_Block_CR1_0_NODIV :1;
						uint32_t SAI_Block_CR1_0_MCKDIV :4;
						uint32_t                      :2;
						uint32_t SAI_Block_CR1_0_OSR  :1;
						uint32_t                      :5;
					};
					#ifdef SAI_Block_CR1_1
					struct
					{
						uint32_t                      :19;
						uint32_t NOMCK                :1;
						uint32_t MCKDIV               :6;
						uint32_t                      :6;
					};
					#endif
				};
				//SOOL-SAI_Block_CR1-DECLARATION
			};
			#endif
			
			#ifdef SAI_Block_CR2
			struct CR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FTH                  :3;
					uint32_t FFLUSH               :1;
					uint32_t TRIS                 :1;
					uint32_t MUTE                 :1;
					uint32_t MUTEVAL              :1;
					uint32_t MUTECNT              :6;
					uint32_t CPL                  :1;
					uint32_t COMP                 :2;
					uint32_t                      :16;
			
				//SOOL-SAI_Block_CR2-DECLARATION
			};
			#endif
			
			#ifdef SAI_Block_DR
			struct DR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DATA                 :32;
			
				//SOOL-SAI_Block_DR-DECLARATION
			};
			#endif
			
			#ifdef SAI_Block_FRCR
			struct FRCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t FRL                  :8;
						uint32_t FSALL                :7;
						uint32_t                      :1;
						uint32_t FSDEF                :1;
						uint32_t FSPOL                :1;
						uint32_t FSOFF                :1;
						uint32_t                      :13;
					};
					#ifdef SAI_Block_FRCR_1
					struct
					{
						uint32_t                      :17;
						uint32_t FSPO                 :1;
						uint32_t                      :14;
					};
					#endif
				};
				//SOOL-SAI_Block_FRCR-DECLARATION
			};
			#endif
			
			#ifdef SAI_Block_IMR
			struct IMR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t OVRUDRIE             :1;
					uint32_t MUTEDETIE            :1;
					uint32_t WCKCFGIE             :1;
					uint32_t FREQIE               :1;
					uint32_t CNRDYIE              :1;
					uint32_t AFSDETIE             :1;
					uint32_t LFSDETIE             :1;
					uint32_t                      :25;
			
				//SOOL-SAI_Block_IMR-DECLARATION
			};
			#endif
			
			#ifdef SAI_Block_SLOTR
			struct SLOTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FBOFF                :5;
					uint32_t                      :1;
					uint32_t SLOTSZ               :2;
					uint32_t NBSLOT               :4;
					uint32_t                      :4;
					uint32_t SLOTEN               :16;
			
				//SOOL-SAI_Block_SLOTR-DECLARATION
			};
			#endif
			
			#ifdef SAI_Block_SR
			struct SR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t OVRUDR               :1;
					uint32_t MUTEDET              :1;
					uint32_t WCKCFG               :1;
					uint32_t FREQ                 :1;
					uint32_t CNRDY                :1;
					uint32_t AFSDET               :1;
					uint32_t LFSDET               :1;
					uint32_t                      :9;
					uint32_t FLVL                 :3;
					uint32_t                      :13;
			
				//SOOL-SAI_Block_SR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR1_TypeDef CR1;     // @0x000
					CR2_TypeDef CR2;     // @0x004
					FRCR_TypeDef FRCR;   // @0x008
					SLOTR_TypeDef SLOTR; // @0x00c
					IMR_TypeDef IMR;     // @0x010
					SR_TypeDef SR;       // @0x014
					CLRFR_TypeDef CLRFR; // @0x018
					DR_TypeDef DR;       // @0x01c
				};
			};
			private:
			SAI_Block() = delete;
			//SOOL-SAI_Block-DECLARATION
		};
		
		//region instances
#if defined(STM32F413xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32H7     ) 
#define SAI1_BASE_ADDR ((uint32_t)0x40015800U)
#define SAI1_Block_A_BASE_ADDR ((uint32_t)0x40015804U)
#define SAI1_Block_B_BASE_ADDR ((uint32_t)0x40015824U)
#endif

#if defined(STM32L4     ) || defined(STM32L4P    ) 
#define SAI1_BASE_ADDR ((uint32_t)0x40015400U)
#define SAI1_Block_A_BASE_ADDR ((uint32_t)0x40015404U)
#define SAI1_Block_B_BASE_ADDR ((uint32_t)0x40015424U)
#endif

#if defined(STM32F446xx ) || defined(STM32F7     ) || defined(STM32H7     ) 
#define SAI2_BASE_ADDR ((uint32_t)0x40015C00U)
#define SAI2_Block_A_BASE_ADDR ((uint32_t)0x40015C04U)
#define SAI2_Block_B_BASE_ADDR ((uint32_t)0x40015C24U)
#endif

#if defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define SAI2_BASE_ADDR ((uint32_t)0x40015800U)
#define SAI2_Block_A_BASE_ADDR ((uint32_t)0x40015804U)
#define SAI2_Block_B_BASE_ADDR ((uint32_t)0x40015824U)
#endif

#if defined(STM32H7     ) 
#define SAI3_BASE_ADDR ((uint32_t)0x40016000U)
#define SAI4_BASE_ADDR ((uint32_t)0x58005400U)
#define SAI3_Block_A_BASE_ADDR ((uint32_t)0x40016004U)
#define SAI3_Block_B_BASE_ADDR ((uint32_t)0x40016024U)
#define SAI4_Block_A_BASE_ADDR ((uint32_t)0x58005404U)
#define SAI4_Block_B_BASE_ADDR ((uint32_t)0x58005424U)
#endif

#ifdef SAI1_BASE_ADDR
volatile class SAI * const SAI1 = reinterpret_cast<class SAI* const>(SAI1_BASE_ADDR);
#endif
#ifdef SAI1_Block_A_BASE_ADDR
volatile class SAI_Block * const SAI1_Block_A = reinterpret_cast<class SAI_Block* const>(SAI1_Block_A_BASE_ADDR);
#endif
#ifdef SAI1_Block_B_BASE_ADDR
volatile class SAI_Block * const SAI1_Block_B = reinterpret_cast<class SAI_Block* const>(SAI1_Block_B_BASE_ADDR);
#endif
#ifdef SAI2_BASE_ADDR
volatile class SAI * const SAI2 = reinterpret_cast<class SAI* const>(SAI2_BASE_ADDR);
#endif
#ifdef SAI2_Block_A_BASE_ADDR
volatile class SAI_Block * const SAI2_Block_A = reinterpret_cast<class SAI_Block* const>(SAI2_Block_A_BASE_ADDR);
#endif
#ifdef SAI2_Block_B_BASE_ADDR
volatile class SAI_Block * const SAI2_Block_B = reinterpret_cast<class SAI_Block* const>(SAI2_Block_B_BASE_ADDR);
#endif
#ifdef SAI3_BASE_ADDR
volatile class SAI * const SAI3 = reinterpret_cast<class SAI* const>(SAI3_BASE_ADDR);
#endif
#ifdef SAI4_BASE_ADDR
volatile class SAI * const SAI4 = reinterpret_cast<class SAI* const>(SAI4_BASE_ADDR);
#endif
#ifdef SAI3_Block_A_BASE_ADDR
volatile class SAI_Block * const SAI3_Block_A = reinterpret_cast<class SAI_Block* const>(SAI3_Block_A_BASE_ADDR);
#endif
#ifdef SAI3_Block_B_BASE_ADDR
volatile class SAI_Block * const SAI3_Block_B = reinterpret_cast<class SAI_Block* const>(SAI3_Block_B_BASE_ADDR);
#endif
#ifdef SAI4_Block_A_BASE_ADDR
volatile class SAI_Block * const SAI4_Block_A = reinterpret_cast<class SAI_Block* const>(SAI4_Block_A_BASE_ADDR);
#endif
#ifdef SAI4_Block_B_BASE_ADDR
volatile class SAI_Block * const SAI4_Block_B = reinterpret_cast<class SAI_Block* const>(SAI4_Block_B_BASE_ADDR);
#endif
//endregion

//SOOL-SAI-DEFINES
//SOOL-SAI-DEFINITION
	};
};//region undef
#undef SAI_Block_CR1_0_OSR
#undef SAI_MAP0_PDMCR
#undef SAI_MAP0_PDMDLY
#undef SAI_Block_CR1_0_NODIV
#undef SAI_Block_CR1_0_MCKDIV
//endregion
#endif
#endif
