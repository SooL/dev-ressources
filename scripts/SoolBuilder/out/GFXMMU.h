#ifndef __SOOL_GFXMMU_H
#define __SOOL_GFXMMU_H

#include "peripheral_include.h"
//SOOL-GFXMMU-INCLUDES
#if defined(STM32L4R7xx ) || defined(STM32L4R9xx ) || defined(STM32L4S7xx ) || defined(STM32L4S9xx ) 
//region defines

#define GFXMMU_B0CR
#define GFXMMU_B1CR
#define GFXMMU_B2CR
#define GFXMMU_B3CR
#define GFXMMU_CR
#define GFXMMU_DVR
#define GFXMMU_FCR
#define GFXMMU_LUT
#define GFXMMU_LUTH
#define GFXMMU_LUTL
#define GFXMMU_SR
#define GFXMMU_VERR

//endregion

namespace sool
{
	namespace core
	{
		class GFXMMU
		{
			//SOOL-GFXMMU-ENUMS
			
			public :
			
			#ifdef GFXMMU_B0CR
			struct B0CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :4;
					uint32_t PBO                  :19;
					uint32_t PBBA                 :9;
			
				//SOOL-GFXMMU_B0CR-DECLARATION
			};
			#endif
			
			#ifdef GFXMMU_B1CR
			struct B1CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :4;
					uint32_t PBO                  :19;
					uint32_t PBBA                 :9;
			
				//SOOL-GFXMMU_B1CR-DECLARATION
			};
			#endif
			
			#ifdef GFXMMU_B2CR
			struct B2CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :4;
					uint32_t PBO                  :19;
					uint32_t PBBA                 :9;
			
				//SOOL-GFXMMU_B2CR-DECLARATION
			};
			#endif
			
			#ifdef GFXMMU_B3CR
			struct B3CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :4;
					uint32_t PBO                  :19;
					uint32_t PBBA                 :9;
			
				//SOOL-GFXMMU_B3CR-DECLARATION
			};
			#endif
			
			#ifdef GFXMMU_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t B0OIE                :1;
					uint32_t B1OIE                :1;
					uint32_t B2OIE                :1;
					uint32_t B3OIE                :1;
					uint32_t AMEIE                :1;
					uint32_t                      :1;
					uint32_t C192BM               :1;
					uint32_t                      :25;
			
				//SOOL-GFXMMU_CR-DECLARATION
			};
			#endif
			
			#ifdef GFXMMU_DVR
			struct DVR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DV                   :32;
			
				//SOOL-GFXMMU_DVR-DECLARATION
			};
			#endif
			
			#ifdef GFXMMU_FCR
			struct FCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CB0OF                :1;
					uint32_t CB1OF                :1;
					uint32_t CB2OF                :1;
					uint32_t CB3OF                :1;
					uint32_t CAMEF                :1;
					uint32_t                      :27;
			
				//SOOL-GFXMMU_FCR-DECLARATION
			};
			#endif
			
			#ifdef GFXMMU_LUT
			struct LUT_TypeDef : public Reg64_t
			{
				using Reg64_t::operator=;
				
					uint32_t EN                   :1;
					uint32_t                      :7;
					uint32_t FVB                  :8;
					uint32_t LVB                  :8;
					uint32_t                      :12;
					uint32_t LO                   :18;
					uint32_t                      :10;
			
				//SOOL-GFXMMU_LUT-DECLARATION
			};
			#endif
			
			#ifdef GFXMMU_LUTH
			struct LUTH_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :4;
					uint32_t LO                   :18;
					uint32_t                      :10;
			
				//SOOL-GFXMMU_LUTH-DECLARATION
			};
			#endif
			
			#ifdef GFXMMU_LUTL
			struct LUTL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EN                   :1;
					uint32_t                      :7;
					uint32_t FVB                  :8;
					uint32_t LVB                  :8;
					uint32_t                      :8;
			
				//SOOL-GFXMMU_LUTL-DECLARATION
			};
			#endif
			
			#ifdef GFXMMU_SR
			struct SR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t B0OF                 :1;
					uint32_t B1OF                 :1;
					uint32_t B2OF                 :1;
					uint32_t B3OF                 :1;
					uint32_t AMEF                 :1;
					uint32_t                      :27;
			
				//SOOL-GFXMMU_SR-DECLARATION
			};
			#endif
			
			#ifdef GFXMMU_VERR
			struct VERR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MINREV               :4;
					uint32_t MAJREV               :4;
					uint32_t                      :24;
			
				//SOOL-GFXMMU_VERR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					SR_TypeDef SR;       // @0x004
					FCR_TypeDef FCR;     // @0x008
					__SOOL_PERIPH_PADDING_4;
					DVR_TypeDef DVR;     // @0x010
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					B0CR_TypeDef B0CR;   // @0x020
					B1CR_TypeDef B1CR;   // @0x024
					B2CR_TypeDef B2CR;   // @0x028
					B3CR_TypeDef B3CR;   // @0x02c
					__SOOL_PERIPH_PADDING_2048;
					__SOOL_PERIPH_PADDING_1024;
					__SOOL_PERIPH_PADDING_512;
					__SOOL_PERIPH_PADDING_256;
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_4;
					VERR_TypeDef VERR;   // @0xff4
					__SOOL_PERIPH_PADDING_8;
					LUT_TypeDef LUT[1024]; // @0x1000
				};
				struct
				{
					__SOOL_PERIPH_PADDING_4096;
					BigArrayReg_t<LUTL_TypeDef, 0, 8, 1024> LUTL; // @0x1000
					__SOOL_PERIPH_PADDING_4096;
				};
				struct
				{
					__SOOL_PERIPH_PADDING_4096;
					BigArrayReg_t<LUTH_TypeDef, 4, 8, 1024> LUTH; // @0x1000
					__SOOL_PERIPH_PADDING_4096;
				};
			};
			private:
			GFXMMU() = delete;
			//SOOL-GFXMMU-DECLARATION
		};
		
		//region instances
#define GFXMMU_BASE_ADDR ((uint32_t)0x4002C000U)
#ifdef GFXMMU_BASE_ADDR
volatile class GFXMMU * const GFXMMU = reinterpret_cast<class GFXMMU* const>(GFXMMU_BASE_ADDR);
#endif
//endregion

//SOOL-GFXMMU-DEFINES
//SOOL-GFXMMU-DEFINITION
	};
};//region undef
//endregion
#endif
#endif
