#ifndef __SOOL_CEC_H
#define __SOOL_CEC_H

#include "peripheral_include.h"
//SOOL-CEC-INCLUDES
#if defined(STM32F042x6 ) || defined(STM32F048xx ) || defined(STM32F051x8 ) || defined(STM32F058xx ) ||\
    defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) ||\
    defined(STM32F098xx ) || defined(STM32F100xB ) || defined(STM32F100xE ) || defined(STM32F373xC ) ||\
    defined(STM32F378xx ) || defined(STM32F446xx ) || defined(STM32F745xx ) || defined(STM32F746xx ) ||\
    defined(STM32F756xx ) || defined(STM32F765xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) ||\
    defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32H7     ) 
//region defines

#define CEC_CFGR

#if defined(STM32F042x6 ) || defined(STM32F048xx ) || defined(STM32F051x8 ) || defined(STM32F058xx ) ||\
    defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) ||\
    defined(STM32F098xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F446xx ) ||\
    defined(STM32F745xx ) || defined(STM32F746xx ) || defined(STM32F756xx ) || defined(STM32F765xx ) ||\
    defined(STM32F767xx ) || defined(STM32F769xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) ||\
    defined(STM32H7     ) 
#define CEC_CFGR_0
#define CEC_CR
#define CEC_IER
#define CEC_ISR
#define CEC_RXDR
#define CEC_TXDR
#define CEC_MAP0_CR          CR_TypeDef CR
#define CEC_MAP0_CFGR        CFGR_TypeDef CFGR
#define CEC_MAP0_TXDR        TXDR_TypeDef TXDR
#define CEC_MAP0_RXDR        RXDR_TypeDef RXDR
#define CEC_MAP0_ISR         ISR_TypeDef ISR
#define CEC_MAP0_IER         IER_TypeDef IER
#else
#define CEC_MAP0_CR __SOOL_PERIPH_PADDING_4
#define CEC_MAP0_CFGR __SOOL_PERIPH_PADDING_4
#define CEC_MAP0_TXDR __SOOL_PERIPH_PADDING_4
#define CEC_MAP0_RXDR __SOOL_PERIPH_PADDING_4
#define CEC_MAP0_ISR __SOOL_PERIPH_PADDING_4
#define CEC_MAP0_IER __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F100xB ) || defined(STM32F100xE ) 
#define CEC_CFGR_1
#define CEC_CSR
#define CEC_ESR
#define CEC_OAR
#define CEC_PRES
#define CEC_RXD
#define CEC_TXD
#define CEC_MAP1_CFGR        CFGR_TypeDef CFGR
#define CEC_MAP1_OAR         OAR_TypeDef OAR
#define CEC_MAP1_PRES        PRES_TypeDef PRES
#define CEC_MAP1_ESR         ESR_TypeDef ESR
#define CEC_MAP1_CSR         CSR_TypeDef CSR
#define CEC_MAP1_TXD         TXD_TypeDef TXD
#define CEC_MAP0_RXD         RXD_TypeDef RXD
#else
#define CEC_MAP1_CFGR __SOOL_PERIPH_PADDING_4
#define CEC_MAP1_OAR __SOOL_PERIPH_PADDING_4
#define CEC_MAP1_PRES __SOOL_PERIPH_PADDING_4
#define CEC_MAP1_ESR __SOOL_PERIPH_PADDING_4
#define CEC_MAP1_CSR __SOOL_PERIPH_PADDING_4
#define CEC_MAP1_TXD __SOOL_PERIPH_PADDING_4
#define CEC_MAP0_RXD __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F042x6 ) || defined(STM32F048xx ) || defined(STM32F051x8 ) || defined(STM32F058xx ) ||\
    defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) ||\
    defined(STM32F098xx ) || defined(STM32F373xC ) || defined(STM32F378xx ) || defined(STM32F745xx ) ||\
    defined(STM32F746xx ) || defined(STM32F756xx ) || defined(STM32F765xx ) || defined(STM32F767xx ) ||\
    defined(STM32F769xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32H7     ) 
#define CEC_TXDR_1
#endif

//endregion

namespace sool
{
	namespace core
	{
		class CEC
		{
			//SOOL-CEC-ENUMS
			
			public :
			
			#ifdef CEC_CFGR
			struct CFGR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef CEC_CFGR_0
					struct
					{
						uint32_t SFT                  :3;
						uint32_t RXTOL                :1;
						uint32_t BRESTP               :1;
						uint32_t BREGEN               :1;
						uint32_t LBPEGEN              :1;
						uint32_t BRDNOGEN             :1;
						uint32_t SFTOPT               :1;
						uint32_t                      :7;
						uint32_t OAR                  :15;
						uint32_t LSTN                 :1;
					};
					#endif
					#ifdef CEC_CFGR_1
					struct
					{
						uint32_t PE                   :1;
						uint32_t IE                   :1;
						uint32_t BTEM                 :1;
						uint32_t BPEM                 :1;
						uint32_t                      :28;
					};
					#endif
				};
				//SOOL-CEC_CFGR-DECLARATION
			};
			#endif
			
			#ifdef CEC_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CECEN                :1;
					uint32_t TXSOM                :1;
					uint32_t TXEOM                :1;
					uint32_t                      :29;
			
				//SOOL-CEC_CR-DECLARATION
			};
			#endif
			
			#ifdef CEC_CSR
			struct CSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TSOM                 :1;
					uint32_t TEOM                 :1;
					uint32_t TERR                 :1;
					uint32_t TBTRF                :1;
					uint32_t RSOM                 :1;
					uint32_t REOM                 :1;
					uint32_t RERR                 :1;
					uint32_t RBTF                 :1;
					uint32_t                      :24;
			
				//SOOL-CEC_CSR-DECLARATION
			};
			#endif
			
			#ifdef CEC_ESR
			struct ESR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t BTE                  :1;
					uint32_t BPE                  :1;
					uint32_t RBTFE                :1;
					uint32_t SBE                  :1;
					uint32_t ACKE                 :1;
					uint32_t LINE                 :1;
					uint32_t TBTFE                :1;
					uint32_t                      :25;
			
				//SOOL-CEC_ESR-DECLARATION
			};
			#endif
			
			#ifdef CEC_IER
			struct IER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RXBRIE               :1;
					uint32_t RXENDIE              :1;
					uint32_t RXOVRIE              :1;
					uint32_t BREIE                :1;
					uint32_t SBPEIE               :1;
					uint32_t LBPEIE               :1;
					uint32_t RXACKEIE             :1;
					uint32_t ARBLSTIE             :1;
					uint32_t TXBRIE               :1;
					uint32_t TXENDIE              :1;
					uint32_t TXUDRIE              :1;
					uint32_t TXERRIE              :1;
					uint32_t TXACKEIE             :1;
					uint32_t                      :19;
			
				//SOOL-CEC_IER-DECLARATION
			};
			#endif
			
			#ifdef CEC_ISR
			struct ISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RXBR                 :1;
					uint32_t RXEND                :1;
					uint32_t RXOVR                :1;
					uint32_t BRE                  :1;
					uint32_t SBPE                 :1;
					uint32_t LBPE                 :1;
					uint32_t RXACKE               :1;
					uint32_t ARBLST               :1;
					uint32_t TXBR                 :1;
					uint32_t TXEND                :1;
					uint32_t TXUDR                :1;
					uint32_t TXERR                :1;
					uint32_t TXACKE               :1;
					uint32_t                      :19;
			
				//SOOL-CEC_ISR-DECLARATION
			};
			#endif
			
			#ifdef CEC_OAR
			struct OAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t OA                   :4;
					uint32_t                      :28;
			
				//SOOL-CEC_OAR-DECLARATION
			};
			#endif
			
			#ifdef CEC_PRES
			struct PRES_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PRES                 :14;
					uint32_t                      :18;
			
				//SOOL-CEC_PRES-DECLARATION
			};
			#endif
			
			#ifdef CEC_RXD
			struct RXD_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RXD                  :8;
					uint32_t                      :24;
			
				//SOOL-CEC_RXD-DECLARATION
			};
			#endif
			
			#ifdef CEC_RXDR
			struct RXDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RXD                  :8;
					uint32_t                      :24;
			
				//SOOL-CEC_RXDR-DECLARATION
			};
			#endif
			
			#ifdef CEC_TXD
			struct TXD_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TXD                  :8;
					uint32_t                      :24;
			
				//SOOL-CEC_TXD-DECLARATION
			};
			#endif
			
			#ifdef CEC_TXDR
			struct TXDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t TXD                  :8;
						uint32_t                      :24;
					};
					#ifdef CEC_TXDR_1
					struct
					{
						uint32_t RXD                  :8;
						uint32_t                      :24;
					};
					#endif
				};
				//SOOL-CEC_TXDR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CEC_MAP0_CR;         // @0x000
					CEC_MAP0_CFGR;       // @0x004
					CEC_MAP0_TXDR;       // @0x008
					CEC_MAP0_RXDR;       // @0x00c
					CEC_MAP0_ISR;        // @0x010
					CEC_MAP0_IER;        // @0x014
					CEC_MAP0_RXD;        // @0x018
				};
				struct
				{
					CEC_MAP1_CFGR;       // @0x000
					CEC_MAP1_OAR;        // @0x004
					CEC_MAP1_PRES;       // @0x008
					CEC_MAP1_ESR;        // @0x00c
					CEC_MAP1_CSR;        // @0x010
					CEC_MAP1_TXD;        // @0x014
					__SOOL_PERIPH_PADDING_4;
				};
			};
			private:
			CEC() = delete;
			//SOOL-CEC-DECLARATION
		};
		
		//region instances
#if defined(STM32F042x6 ) || defined(STM32F048xx ) || defined(STM32F051x8 ) || defined(STM32F058xx ) ||\
    defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F091xC ) ||\
    defined(STM32F098xx ) || defined(STM32F100xB ) || defined(STM32F100xE ) || defined(STM32F373xC ) ||\
    defined(STM32F378xx ) 
#define CEC_BASE_ADDR ((uint32_t)0x40007800U)
#endif

#if defined(STM32F446xx ) || defined(STM32F745xx ) || defined(STM32F746xx ) || defined(STM32F756xx ) ||\
    defined(STM32F765xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) || defined(STM32F777xx ) ||\
    defined(STM32F779xx ) || defined(STM32H7     ) 
#define CEC_BASE_ADDR ((uint32_t)0x40006C00U)
#endif

#ifdef CEC_BASE_ADDR
volatile class CEC * const CEC = reinterpret_cast<class CEC* const>(CEC_BASE_ADDR);
#endif
//endregion

//SOOL-CEC-DEFINES
//SOOL-CEC-DEFINITION
	};
};//region undef
#undef CEC_MAP0_CR
#undef CEC_MAP0_CFGR
#undef CEC_MAP0_TXDR
#undef CEC_MAP0_RXDR
#undef CEC_MAP0_ISR
#undef CEC_MAP0_IER
#undef CEC_MAP1_CFGR
#undef CEC_MAP1_OAR
#undef CEC_MAP1_PRES
#undef CEC_MAP1_ESR
#undef CEC_MAP1_CSR
#undef CEC_MAP1_TXD
#undef CEC_MAP0_RXD
//endregion
#endif
#endif
