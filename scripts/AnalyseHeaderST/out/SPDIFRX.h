#ifndef __SOOL_SPDIFRX_H
#define __SOOL_SPDIFRX_H

#include "peripheral_include.h"
//SOOL-SPDIFRX-INCLUDES
#if defined(STM32F446xx ) || defined(STM32F745xx ) || defined(STM32F746xx ) || defined(STM32F756xx ) ||\
    defined(STM32F765xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) || defined(STM32F777xx ) ||\
    defined(STM32F779xx ) || defined(STM32H7     ) 
//region defines

#define SPDIFRX_CR
#define SPDIFRX_CSR
#define SPDIFRX_DIR
#define SPDIFRX_DR
#define SPDIFRX_DR0
#define SPDIFRX_DR1
#define SPDIFRX_DR2
#define SPDIFRX_IFCR
#define SPDIFRX_IMR
#define SPDIFRX_SR

#if defined(STM32H7     ) 
#define SPDIFRX_CR_CKSEN     CKSEN                // 1 bits @ 20
#define SPDIFRX_CR_CKSBKPEN  CKSBKPEN             // 1 bits @ 21
#define SPDIFRX_DIR_THI      THI                  // 13 bits @ 0
#define SPDIFRX_IDR
#define SPDIFRX_SIDR
#define SPDIFRX_VERR
#define SPDIFRX_MAP0_VERR    VERR_TypeDef VERR
#define SPDIFRX_MAP0_IDR     IDR_TypeDef IDR
#define SPDIFRX_MAP0_SIDR    SIDR_TypeDef SIDR
#else
#define SPDIFRX_CR_CKSEN
#define SPDIFRX_CR_CKSBKPEN
#define SPDIFRX_DIR_THI
#define SPDIFRX_MAP0_VERR __SOOL_PERIPH_PADDING_4
#define SPDIFRX_MAP0_IDR __SOOL_PERIPH_PADDING_4
#define SPDIFRX_MAP0_SIDR __SOOL_PERIPH_PADDING_4
#endif

//endregion

namespace sool
{
	namespace core
	{
		class SPDIFRX
		{
			//SOOL-SPDIFRX-ENUMS
			
			public :
			
			#ifdef SPDIFRX_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SPDIFEN              :2;
					uint32_t RXDMAEN              :1;
					uint32_t RXSTEO               :1;
					uint32_t DRFMT                :2;
					uint32_t PMSK                 :1;
					uint32_t VMSK                 :1;
					uint32_t CUMSK                :1;
					uint32_t PTMSK                :1;
					uint32_t CBDMAEN              :1;
					uint32_t CHSEL                :1;
					uint32_t NBTR                 :2;
					uint32_t WFA                  :1;
					uint32_t                      :1;
					uint32_t INSEL                :3;
					uint32_t                      :1;
					uint32_t SPDIFRX_CR_CKSEN     :1;
					uint32_t SPDIFRX_CR_CKSBKPEN  :1;
					uint32_t                      :10;
			
				//SOOL-SPDIFRX_CR-DECLARATION
			};
			#endif
			
			#ifdef SPDIFRX_CSR
			struct CSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t USR                  :16;
					uint32_t CS                   :8;
					uint32_t SOB                  :1;
					uint32_t                      :7;
			
				//SOOL-SPDIFRX_CSR-DECLARATION
			};
			#endif
			
			#ifdef SPDIFRX_DIR
			struct DIR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SPDIFRX_DIR_THI      :13;
					uint32_t                      :3;
					uint32_t TLO                  :13;
					uint32_t                      :3;
			
				//SOOL-SPDIFRX_DIR-DECLARATION
			};
			#endif
			
			#ifdef SPDIFRX_DR
			struct DR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t DR0_DR               :24;
						uint32_t DR0_PE               :1;
						uint32_t DR0_V                :1;
						uint32_t DR0_U                :1;
						uint32_t DR0_C                :1;
						uint32_t DR0_PT               :2;
						uint32_t                      :2;
					};
					struct
					{
						uint32_t DR1_PE               :1;
						uint32_t DR1_V                :1;
						uint32_t DR1_U                :1;
						uint32_t DR1_C                :1;
						uint32_t DR1_PT               :2;
						uint32_t                      :2;
						uint32_t DR1_DR               :24;
					};
					struct
					{
						uint32_t DR2_DRNL2            :16;
						uint32_t DR2_DRNL1            :16;
					};
				};
				//SOOL-SPDIFRX_DR-DECLARATION
			};
			#endif
			
			#ifdef SPDIFRX_DR0
			struct DR0_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DR                   :24;
					uint32_t PE                   :1;
					uint32_t V                    :1;
					uint32_t U                    :1;
					uint32_t C                    :1;
					uint32_t PT                   :2;
					uint32_t                      :2;
			
				//SOOL-SPDIFRX_DR0-DECLARATION
			};
			#endif
			
			#ifdef SPDIFRX_DR1
			struct DR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PE                   :1;
					uint32_t V                    :1;
					uint32_t U                    :1;
					uint32_t C                    :1;
					uint32_t PT                   :2;
					uint32_t                      :2;
					uint32_t DR                   :24;
			
				//SOOL-SPDIFRX_DR1-DECLARATION
			};
			#endif
			
			#ifdef SPDIFRX_DR2
			struct DR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DRNL2                :16;
					uint32_t DRNL1                :16;
			
				//SOOL-SPDIFRX_DR2-DECLARATION
			};
			#endif
			
			#ifdef SPDIFRX_IDR
			struct IDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ID                   :32;
			
				//SOOL-SPDIFRX_IDR-DECLARATION
			};
			#endif
			
			#ifdef SPDIFRX_IFCR
			struct IFCR_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint32_t                      :2;
					uint32_t PERRCF               :1;
					uint32_t OVRCF                :1;
					uint32_t SBDCF                :1;
					uint32_t SYNCDCF              :1;
					uint32_t                      :26;
			
				//SOOL-SPDIFRX_IFCR-DECLARATION
			};
			#endif
			
			#ifdef SPDIFRX_IMR
			struct IMR_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint32_t RXNEIE               :1;
					uint32_t CSRNEIE              :1;
					uint32_t PERRIE               :1;
					uint32_t OVRIE                :1;
					uint32_t SBLKIE               :1;
					uint32_t SYNCDIE              :1;
					uint32_t IFEIE                :1;
					uint32_t                      :25;
			
				//SOOL-SPDIFRX_IMR-DECLARATION
			};
			#endif
			
			#ifdef SPDIFRX_SIDR
			struct SIDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SID                  :32;
			
				//SOOL-SPDIFRX_SIDR-DECLARATION
			};
			#endif
			
			#ifdef SPDIFRX_SR
			struct SR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RXNE                 :1;
					uint32_t CSRNE                :1;
					uint32_t PERR                 :1;
					uint32_t OVR                  :1;
					uint32_t SBD                  :1;
					uint32_t SYNCD                :1;
					uint32_t FERR                 :1;
					uint32_t SERR                 :1;
					uint32_t TERR                 :1;
					uint32_t                      :7;
					uint32_t WIDTH5               :15;
					uint32_t                      :1;
			
				//SOOL-SPDIFRX_SR-DECLARATION
			};
			#endif
			
			#ifdef SPDIFRX_VERR
			struct VERR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MINREV               :4;
					uint32_t MAJREV               :4;
					uint32_t                      :24;
			
				//SOOL-SPDIFRX_VERR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					IMR_TypeDef IMR;     // @0x004
					SR_TypeDef SR;       // @0x008
					IFCR_TypeDef IFCR;   // @0x00c
					DR_TypeDef DR;       // @0x010
					CSR_TypeDef CSR;     // @0x014
					DIR_TypeDef DIR;     // @0x018
					__SOOL_PERIPH_PADDING_512;
					__SOOL_PERIPH_PADDING_256;
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					SPDIFRX_MAP0_VERR;   // @0x3f4
					SPDIFRX_MAP0_IDR;    // @0x3f8
					SPDIFRX_MAP0_SIDR;   // @0x3fc
				};
				struct
				{
					__SOOL_PERIPH_PADDING_16;
					DR0_TypeDef DR0;     // @0x010
					__SOOL_PERIPH_PADDING_512;
					__SOOL_PERIPH_PADDING_256;
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
				};
				struct
				{
					__SOOL_PERIPH_PADDING_16;
					DR1_TypeDef DR1;     // @0x010
					__SOOL_PERIPH_PADDING_512;
					__SOOL_PERIPH_PADDING_256;
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
				};
				struct
				{
					__SOOL_PERIPH_PADDING_16;
					DR2_TypeDef DR2;     // @0x010
					__SOOL_PERIPH_PADDING_512;
					__SOOL_PERIPH_PADDING_256;
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
				};
			};
			private:
			SPDIFRX() = delete;
			//SOOL-SPDIFRX-DECLARATION
		};
		
		//region instances
#define SPDIFRX_BASE_ADDR ((uint32_t)0x40004000U)
#ifdef SPDIFRX_BASE_ADDR
volatile class SPDIFRX * const SPDIFRX = reinterpret_cast<class SPDIFRX* const>(SPDIFRX_BASE_ADDR);
#endif
//endregion

//SOOL-SPDIFRX-DEFINES
//SOOL-SPDIFRX-DEFINITION
	};
};//region undef
#undef SPDIFRX_CR_CKSEN
#undef SPDIFRX_CR_CKSBKPEN
#undef SPDIFRX_DIR_THI
#undef SPDIFRX_MAP0_VERR
#undef SPDIFRX_MAP0_IDR
#undef SPDIFRX_MAP0_SIDR
//endregion
#endif
#endif
