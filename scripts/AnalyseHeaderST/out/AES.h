#ifndef __SOOL_AES_H
#define __SOOL_AES_H

#include "peripheral_include.h"
//SOOL-AES-INCLUDES
#if defined(STM32F423xx ) || defined(STM32F732xx ) || defined(STM32F733xx ) || defined(STM32L021xx ) ||\
    defined(STM32L041xx ) || defined(STM32L061xx ) || defined(STM32L062xx ) || defined(STM32L063xx ) ||\
    defined(STM32L081xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) || defined(STM32L162xC ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) ||\
    defined(STM32L442xx ) || defined(STM32L443xx ) || defined(STM32L462xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L4A6xx ) || defined(STM32L4S5xx ) || defined(STM32L4S7xx ) ||\
    defined(STM32L4S9xx ) 
//region defines

#define AES_CR
#define AES_DINR
#define AES_DOUTR
#define AES_IVR0
#define AES_IVR1
#define AES_IVR2
#define AES_IVR3
#define AES_KEYR0
#define AES_KEYR1
#define AES_KEYR2
#define AES_KEYR3
#define AES_SR

#if defined(STM32F423xx ) 
#define AES_CR_0_CHMOD       CHMOD                // 12 bits @ 5
#else
#define AES_CR_0_CHMOD
#endif

#if defined(STM32F423xx ) || defined(STM32F732xx ) || defined(STM32F733xx ) || defined(STM32L442xx ) ||\
    defined(STM32L443xx ) || defined(STM32L462xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) ||\
    defined(STM32L4A6xx ) || defined(STM32L4S5xx ) || defined(STM32L4S7xx ) || defined(STM32L4S9xx ) 
#define AES_CR_0_KEYSIZE     KEYSIZE              // 1 bits @ 18
#define AES_CR_1_CCFIE       CCFIE                // 1 bits @ 9
#define AES_CR_1_GCMPH       GCMPH                // 2 bits @ 13
#define AES_KEYR4
#define AES_KEYR5
#define AES_KEYR6
#define AES_KEYR7
#define AES_SR_BUSY          BUSY                 // 1 bits @ 3
#define AES_SUSP0R
#define AES_SUSP1R
#define AES_SUSP2R
#define AES_SUSP3R
#define AES_SUSP4R
#define AES_SUSP5R
#define AES_SUSP6R
#define AES_SUSP7R
#define AES_MAP0_KEYR4       uint32_t KEYR4
#define AES_MAP0_KEYR5       uint32_t KEYR5
#define AES_MAP0_KEYR6       uint32_t KEYR6
#define AES_MAP0_KEYR7       uint32_t KEYR7
#define AES_MAP0_SUSP0R      uint32_t SUSP0R
#define AES_MAP0_SUSP1R      uint32_t SUSP1R
#define AES_MAP0_SUSP2R      uint32_t SUSP2R
#define AES_MAP0_SUSP3R      uint32_t SUSP3R
#define AES_MAP0_SUSP4R      uint32_t SUSP4R
#define AES_MAP0_SUSP5R      uint32_t SUSP5R
#define AES_MAP0_SUSP6R      uint32_t SUSP6R
#define AES_MAP0_SUSP7R      uint32_t SUSP7R
#else
#define AES_CR_0_KEYSIZE
#define AES_CR_1_CCFIE
#define AES_CR_1_GCMPH
#define AES_SR_BUSY
#define AES_MAP0_KEYR4 __SOOL_PERIPH_PADDING_4
#define AES_MAP0_KEYR5 __SOOL_PERIPH_PADDING_4
#define AES_MAP0_KEYR6 __SOOL_PERIPH_PADDING_4
#define AES_MAP0_KEYR7 __SOOL_PERIPH_PADDING_4
#define AES_MAP0_SUSP0R __SOOL_PERIPH_PADDING_4
#define AES_MAP0_SUSP1R __SOOL_PERIPH_PADDING_4
#define AES_MAP0_SUSP2R __SOOL_PERIPH_PADDING_4
#define AES_MAP0_SUSP3R __SOOL_PERIPH_PADDING_4
#define AES_MAP0_SUSP4R __SOOL_PERIPH_PADDING_4
#define AES_MAP0_SUSP5R __SOOL_PERIPH_PADDING_4
#define AES_MAP0_SUSP6R __SOOL_PERIPH_PADDING_4
#define AES_MAP0_SUSP7R __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32L4S5xx ) || defined(STM32L4S7xx ) || defined(STM32L4S9xx ) 
#define AES_CR_0_NPBLB       NPBLB                // 4 bits @ 20
#else
#define AES_CR_0_NPBLB
#endif

#if defined(STM32L021xx ) || defined(STM32L041xx ) || defined(STM32L061xx ) || defined(STM32L062xx ) ||\
    defined(STM32L063xx ) || defined(STM32L081xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) ||\
    defined(STM32L162xC ) || defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) ||\
    defined(STM32L162xE ) 
#define AES_CR_1_CHMOD       CHMOD                // 2 bits @ 5
#define AES_CR_2
#else
#define AES_CR_1_CHMOD
#endif

//endregion

namespace sool
{
	namespace core
	{
		class AES
		{
			//SOOL-AES-ENUMS
			
			public :
			
			#ifdef AES_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t EN                   :1;
						uint32_t DATATYPE             :2;
						uint32_t MODE                 :2;
						uint32_t AES_CR_0_CHMOD       :12;
						uint32_t                      :1;
						uint32_t AES_CR_0_KEYSIZE     :1;
						uint32_t                      :1;
						uint32_t AES_CR_0_NPBLB       :4;
						uint32_t                      :8;
					};
					struct
					{
						uint32_t                      :5;
						uint32_t AES_CR_1_CHMOD       :2;
						uint32_t CCFC                 :1;
						uint32_t ERRC                 :1;
						uint32_t AES_CR_1_CCFIE       :1;
						uint32_t ERRIE                :1;
						uint32_t DMAINEN              :1;
						uint32_t DMAOUTEN             :1;
						uint32_t AES_CR_1_GCMPH       :2;
						uint32_t                      :17;
					};
					#ifdef AES_CR_2
					struct
					{
						uint32_t                      :9;
						uint32_t CCIE                 :1;
						uint32_t                      :22;
					};
					#endif
				};
				//SOOL-AES_CR-DECLARATION
			};
			#endif
			
			#ifdef AES_SR
			struct SR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CCF                  :1;
					uint32_t RDERR                :1;
					uint32_t WRERR                :1;
					uint32_t AES_SR_BUSY          :1;
					uint32_t                      :28;
			
				//SOOL-AES_SR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					SR_TypeDef SR;       // @0x004
					uint32_t DINR;       // @0x008
					uint32_t DOUTR;      // @0x00c
					uint32_t KEYR0;      // @0x010
					uint32_t KEYR1;      // @0x014
					uint32_t KEYR2;      // @0x018
					uint32_t KEYR3;      // @0x01c
					uint32_t IVR0;       // @0x020
					uint32_t IVR1;       // @0x024
					uint32_t IVR2;       // @0x028
					uint32_t IVR3;       // @0x02c
					AES_MAP0_KEYR4;      // @0x030
					AES_MAP0_KEYR5;      // @0x034
					AES_MAP0_KEYR6;      // @0x038
					AES_MAP0_KEYR7;      // @0x03c
					AES_MAP0_SUSP0R;     // @0x040
					AES_MAP0_SUSP1R;     // @0x044
					AES_MAP0_SUSP2R;     // @0x048
					AES_MAP0_SUSP3R;     // @0x04c
					AES_MAP0_SUSP4R;     // @0x050
					AES_MAP0_SUSP5R;     // @0x054
					AES_MAP0_SUSP6R;     // @0x058
					AES_MAP0_SUSP7R;     // @0x05c
				};
			};
			private:
			AES() = delete;
			//SOOL-AES-DECLARATION
		};
		
		//region instances
#if defined(STM32F423xx ) || defined(STM32F732xx ) || defined(STM32F733xx ) || defined(STM32L162xC ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) ||\
    defined(STM32L442xx ) || defined(STM32L443xx ) || defined(STM32L462xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L4A6xx ) || defined(STM32L4S5xx ) || defined(STM32L4S7xx ) ||\
    defined(STM32L4S9xx ) 
#define AES_BASE_ADDR ((uint32_t)0x50060000U)
#endif

#if defined(STM32L021xx ) || defined(STM32L041xx ) || defined(STM32L061xx ) || defined(STM32L062xx ) ||\
    defined(STM32L063xx ) || defined(STM32L081xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) 
#define AES_BASE_ADDR ((uint32_t)0x40026000U)
#endif

#ifdef AES_BASE_ADDR
volatile class AES * const AES = reinterpret_cast<class AES* const>(AES_BASE_ADDR);
#endif
//endregion

//SOOL-AES-DEFINES
//SOOL-AES-DEFINITION
	};
};//region undef
#undef AES_CR_0_CHMOD
#undef AES_CR_0_KEYSIZE
#undef AES_CR_1_CCFIE
#undef AES_CR_1_GCMPH
#undef AES_SR_BUSY
#undef AES_MAP0_KEYR4
#undef AES_MAP0_KEYR5
#undef AES_MAP0_KEYR6
#undef AES_MAP0_KEYR7
#undef AES_MAP0_SUSP0R
#undef AES_MAP0_SUSP1R
#undef AES_MAP0_SUSP2R
#undef AES_MAP0_SUSP3R
#undef AES_MAP0_SUSP4R
#undef AES_MAP0_SUSP5R
#undef AES_MAP0_SUSP6R
#undef AES_MAP0_SUSP7R
#undef AES_CR_0_NPBLB
#undef AES_CR_1_CHMOD
//endregion
#endif
#endif
