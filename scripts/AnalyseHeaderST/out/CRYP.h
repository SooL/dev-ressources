#ifndef __SOOL_CRYP_H
#define __SOOL_CRYP_H

#include "peripheral_include.h"
//SOOL-CRYP-INCLUDES
#if defined(STM32F215xx ) || defined(STM32F217xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F479xx ) || defined(STM32F756xx ) ||\
    defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32H750xx ) || defined(STM32H753xx ) 
//region defines

#define CRYP_CR
#define CRYP_DMACR
#define CRYP_DOUT
#define CRYP_IMSCR
#define CRYP_IV0LR
#define CRYP_IV0RR
#define CRYP_IV1LR
#define CRYP_IV1RR
#define CRYP_K0LR
#define CRYP_K0RR
#define CRYP_K1LR
#define CRYP_K1RR
#define CRYP_K2LR
#define CRYP_K2RR
#define CRYP_K3LR
#define CRYP_K3RR
#define CRYP_MISR
#define CRYP_RISR
#define CRYP_SR

#if defined(STM32F215xx ) || defined(STM32F217xx ) 
#define CRYP_CR_ALGOMODE     ALGOMODE             // 3 bits @ 3
#else
#define CRYP_CR_ALGOMODE
#endif

#if defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F479xx ) || defined(STM32F756xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) ||\
    defined(STM32H750xx ) || defined(STM32H753xx ) 
#define CRYP_CR_GCM_CCMPH    GCM_CCMPH            // 2 bits @ 16
#define CRYP_CSGCM0R
#define CRYP_CSGCM1R
#define CRYP_CSGCM2R
#define CRYP_CSGCM3R
#define CRYP_CSGCM4R
#define CRYP_CSGCM5R
#define CRYP_CSGCM6R
#define CRYP_CSGCM7R
#define CRYP_CSGCMCCM0R
#define CRYP_CSGCMCCM1R
#define CRYP_CSGCMCCM2R
#define CRYP_CSGCMCCM3R
#define CRYP_CSGCMCCM4R
#define CRYP_CSGCMCCM5R
#define CRYP_CSGCMCCM6R
#define CRYP_CSGCMCCM7R
#define CRYP_MAP0_CSGCMCCM0R uint32_t CSGCMCCM0R
#define CRYP_MAP0_CSGCMCCM1R uint32_t CSGCMCCM1R
#define CRYP_MAP0_CSGCMCCM2R uint32_t CSGCMCCM2R
#define CRYP_MAP0_CSGCMCCM3R uint32_t CSGCMCCM3R
#define CRYP_MAP0_CSGCMCCM4R uint32_t CSGCMCCM4R
#define CRYP_MAP0_CSGCMCCM5R uint32_t CSGCMCCM5R
#define CRYP_MAP0_CSGCMCCM6R uint32_t CSGCMCCM6R
#define CRYP_MAP0_CSGCMCCM7R uint32_t CSGCMCCM7R
#define CRYP_MAP0_CSGCM0R    uint32_t CSGCM0R
#define CRYP_MAP0_CSGCM1R    uint32_t CSGCM1R
#define CRYP_MAP0_CSGCM2R    uint32_t CSGCM2R
#define CRYP_MAP0_CSGCM3R    uint32_t CSGCM3R
#define CRYP_MAP0_CSGCM4R    uint32_t CSGCM4R
#define CRYP_MAP0_CSGCM5R    uint32_t CSGCM5R
#define CRYP_MAP0_CSGCM6R    uint32_t CSGCM6R
#define CRYP_MAP0_CSGCM7R    uint32_t CSGCM7R
#else
#define CRYP_CR_GCM_CCMPH
#define CRYP_MAP0_CSGCMCCM0R __SOOL_PERIPH_PADDING_4
#define CRYP_MAP0_CSGCMCCM1R __SOOL_PERIPH_PADDING_4
#define CRYP_MAP0_CSGCMCCM2R __SOOL_PERIPH_PADDING_4
#define CRYP_MAP0_CSGCMCCM3R __SOOL_PERIPH_PADDING_4
#define CRYP_MAP0_CSGCMCCM4R __SOOL_PERIPH_PADDING_4
#define CRYP_MAP0_CSGCMCCM5R __SOOL_PERIPH_PADDING_4
#define CRYP_MAP0_CSGCMCCM6R __SOOL_PERIPH_PADDING_4
#define CRYP_MAP0_CSGCMCCM7R __SOOL_PERIPH_PADDING_4
#define CRYP_MAP0_CSGCM0R __SOOL_PERIPH_PADDING_4
#define CRYP_MAP0_CSGCM1R __SOOL_PERIPH_PADDING_4
#define CRYP_MAP0_CSGCM2R __SOOL_PERIPH_PADDING_4
#define CRYP_MAP0_CSGCM3R __SOOL_PERIPH_PADDING_4
#define CRYP_MAP0_CSGCM4R __SOOL_PERIPH_PADDING_4
#define CRYP_MAP0_CSGCM5R __SOOL_PERIPH_PADDING_4
#define CRYP_MAP0_CSGCM6R __SOOL_PERIPH_PADDING_4
#define CRYP_MAP0_CSGCM7R __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32H750xx ) || defined(STM32H753xx ) 
#define CRYP_DIN
#define CRYP_RISR_1
#define CRYP_MAP1_DIN        uint32_t DIN
#else
#define CRYP_MAP1_DIN __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F215xx ) || defined(STM32F217xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F479xx ) || defined(STM32F756xx ) ||\
    defined(STM32F777xx ) || defined(STM32F779xx ) 
#define CRYP_DR
#define CRYP_RISR_0
#define CRYP_MAP0_DR         uint32_t DR
#else
#define CRYP_MAP0_DR __SOOL_PERIPH_PADDING_4
#endif

//endregion

namespace sool
{
	namespace core
	{
		class CRYP
		{
			//SOOL-CRYP-ENUMS
			
			public :
			
			#ifdef CRYP_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :2;
					uint32_t ALGODIR              :1;
					uint32_t CRYP_CR_ALGOMODE     :3;
					uint32_t DATATYPE             :2;
					uint32_t KEYSIZE              :2;
					uint32_t                      :4;
					uint32_t FFLUSH               :1;
					uint32_t CRYPEN               :1;
					uint32_t CRYP_CR_GCM_CCMPH    :2;
					uint32_t                      :14;
			
				//SOOL-CRYP_CR-DECLARATION
			};
			#endif
			
			#ifdef CRYP_DMACR
			struct DMACR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DIEN                 :1;
					uint32_t DOEN                 :1;
					uint32_t                      :30;
			
				//SOOL-CRYP_DMACR-DECLARATION
			};
			#endif
			
			#ifdef CRYP_IMSCR
			struct IMSCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t INIM                 :1;
					uint32_t OUTIM                :1;
					uint32_t                      :30;
			
				//SOOL-CRYP_IMSCR-DECLARATION
			};
			#endif
			
			#ifdef CRYP_MISR
			struct MISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t INMIS                :1;
					uint32_t OUTMIS               :1;
					uint32_t                      :30;
			
				//SOOL-CRYP_MISR-DECLARATION
			};
			#endif
			
			#ifdef CRYP_RISR
			struct RISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef CRYP_RISR_0
					struct
					{
						uint32_t OUTRIS               :1;
						uint32_t INRIS                :1;
						uint32_t                      :30;
					};
					#endif
					#ifdef CRYP_RISR_1
					struct
					{
						uint32_t INRIS                :1;
						uint32_t OUTRIS               :1;
						uint32_t                      :30;
					};
					#endif
				};
				//SOOL-CRYP_RISR-DECLARATION
			};
			#endif
			
			#ifdef CRYP_SR
			struct SR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t IFEM                 :1;
					uint32_t IFNF                 :1;
					uint32_t OFNE                 :1;
					uint32_t OFFU                 :1;
					uint32_t BUSY                 :1;
					uint32_t                      :27;
			
				//SOOL-CRYP_SR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					SR_TypeDef SR;       // @0x004
					CRYP_MAP0_DR;        // @0x008
					uint32_t DOUT;       // @0x00c
					DMACR_TypeDef DMACR; // @0x010
					IMSCR_TypeDef IMSCR; // @0x014
					RISR_TypeDef RISR;   // @0x018
					MISR_TypeDef MISR;   // @0x01c
					uint32_t K0LR;       // @0x020
					uint32_t K0RR;       // @0x024
					uint32_t K1LR;       // @0x028
					uint32_t K1RR;       // @0x02c
					uint32_t K2LR;       // @0x030
					uint32_t K2RR;       // @0x034
					uint32_t K3LR;       // @0x038
					uint32_t K3RR;       // @0x03c
					uint32_t IV0LR;      // @0x040
					uint32_t IV0RR;      // @0x044
					uint32_t IV1LR;      // @0x048
					uint32_t IV1RR;      // @0x04c
					CRYP_MAP0_CSGCMCCM0R; // @0x050
					CRYP_MAP0_CSGCMCCM1R; // @0x054
					CRYP_MAP0_CSGCMCCM2R; // @0x058
					CRYP_MAP0_CSGCMCCM3R; // @0x05c
					CRYP_MAP0_CSGCMCCM4R; // @0x060
					CRYP_MAP0_CSGCMCCM5R; // @0x064
					CRYP_MAP0_CSGCMCCM6R; // @0x068
					CRYP_MAP0_CSGCMCCM7R; // @0x06c
					CRYP_MAP0_CSGCM0R;   // @0x070
					CRYP_MAP0_CSGCM1R;   // @0x074
					CRYP_MAP0_CSGCM2R;   // @0x078
					CRYP_MAP0_CSGCM3R;   // @0x07c
					CRYP_MAP0_CSGCM4R;   // @0x080
					CRYP_MAP0_CSGCM5R;   // @0x084
					CRYP_MAP0_CSGCM6R;   // @0x088
					CRYP_MAP0_CSGCM7R;   // @0x08c
				};
				struct
				{
					__SOOL_PERIPH_PADDING_8;
					CRYP_MAP1_DIN;       // @0x008
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_4;
				};
			};
			private:
			CRYP() = delete;
			//SOOL-CRYP-DECLARATION
		};
		
		//region instances
#if defined(STM32F215xx ) || defined(STM32F217xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F479xx ) || defined(STM32F756xx ) ||\
    defined(STM32F777xx ) || defined(STM32F779xx ) 
#define CRYP_BASE_ADDR ((uint32_t)0x50060000U)
#endif

#if defined(STM32H750xx ) || defined(STM32H753xx ) 
#define CRYP_BASE_ADDR ((uint32_t)0x48021000U)
#endif

#ifdef CRYP_BASE_ADDR
volatile class CRYP * const CRYP = reinterpret_cast<class CRYP* const>(CRYP_BASE_ADDR);
#endif
//endregion

//SOOL-CRYP-DEFINES
//SOOL-CRYP-DEFINITION
	};
};//region undef
#undef CRYP_CR_ALGOMODE
#undef CRYP_CR_GCM_CCMPH
#undef CRYP_MAP0_CSGCMCCM0R
#undef CRYP_MAP0_CSGCMCCM1R
#undef CRYP_MAP0_CSGCMCCM2R
#undef CRYP_MAP0_CSGCMCCM3R
#undef CRYP_MAP0_CSGCMCCM4R
#undef CRYP_MAP0_CSGCMCCM5R
#undef CRYP_MAP0_CSGCMCCM6R
#undef CRYP_MAP0_CSGCMCCM7R
#undef CRYP_MAP0_CSGCM0R
#undef CRYP_MAP0_CSGCM1R
#undef CRYP_MAP0_CSGCM2R
#undef CRYP_MAP0_CSGCM3R
#undef CRYP_MAP0_CSGCM4R
#undef CRYP_MAP0_CSGCM5R
#undef CRYP_MAP0_CSGCM6R
#undef CRYP_MAP0_CSGCM7R
#undef CRYP_MAP1_DIN
#undef CRYP_MAP0_DR
//endregion
#endif
#endif
