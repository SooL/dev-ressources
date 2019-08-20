#ifndef __SOOL_FIREWALL_H
#define __SOOL_FIREWALL_H

#include "peripheral_include.h"
//SOOL-FIREWALL-INCLUDES
#if defined(STM32L051xx ) || defined(STM32L052xx ) || defined(STM32L053xx ) || defined(STM32L061xx ) ||\
    defined(STM32L062xx ) || defined(STM32L063xx ) || defined(STM32L071xx ) || defined(STM32L072xx ) ||\
    defined(STM32L073xx ) || defined(STM32L081xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) ||\
    defined(STM32L4     ) || defined(STM32L4P    ) 
//region defines

#define FIREWALL_CR
#define FIREWALL_CSL
#define FIREWALL_CSSA
#define FIREWALL_NVDSL
#define FIREWALL_NVDSSA
#define FIREWALL_VDSL
#define FIREWALL_VDSSA

#if defined(STM32L051xx ) || defined(STM32L052xx ) || defined(STM32L053xx ) || defined(STM32L061xx ) ||\
    defined(STM32L062xx ) || defined(STM32L063xx ) || defined(STM32L071xx ) || defined(STM32L072xx ) ||\
    defined(STM32L073xx ) || defined(STM32L081xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) 
#define FIREWALL_LSL
#define FIREWALL_LSSA
#define FIREWALL_VDSL_0
#define FIREWALL_VDSSA_0
#define FIREWALL_MAP0_LSSA   uint32_t LSSA
#define FIREWALL_MAP0_LSL    uint32_t LSL
#else
#define FIREWALL_MAP0_LSSA __SOOL_PERIPH_PADDING_4
#define FIREWALL_MAP0_LSL __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32L431xx ) || defined(STM32L432xx ) || defined(STM32L433xx ) || defined(STM32L442xx ) ||\
    defined(STM32L443xx ) || defined(STM32L451xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) ||\
    defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) 
#define FIREWALL_VDSL_1
#define FIREWALL_VDSSA_1
#endif

#if defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define FIREWALL_VDSL_2
#define FIREWALL_VDSSA_2
#endif

//endregion

namespace sool
{
	namespace core
	{
		class FIREWALL
		{
			//SOOL-FIREWALL-ENUMS
			
			public :
			
			#ifdef FIREWALL_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FPA                  :1;
					uint32_t VDS                  :1;
					uint32_t VDE                  :1;
					uint32_t                      :29;
			
				//SOOL-FIREWALL_CR-DECLARATION
			};
			#endif
			
			#ifdef FIREWALL_CSL
			struct CSL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :8;
					uint32_t LENG                 :14;
					uint32_t                      :10;
			
				//SOOL-FIREWALL_CSL-DECLARATION
			};
			#endif
			
			#ifdef FIREWALL_CSSA
			struct CSSA_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :8;
					uint32_t ADD                  :16;
					uint32_t                      :8;
			
				//SOOL-FIREWALL_CSSA-DECLARATION
			};
			#endif
			
			#ifdef FIREWALL_NVDSL
			struct NVDSL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :8;
					uint32_t LENG                 :14;
					uint32_t                      :10;
			
				//SOOL-FIREWALL_NVDSL-DECLARATION
			};
			#endif
			
			#ifdef FIREWALL_NVDSSA
			struct NVDSSA_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :8;
					uint32_t ADD                  :16;
					uint32_t                      :8;
			
				//SOOL-FIREWALL_NVDSSA-DECLARATION
			};
			#endif
			
			#ifdef FIREWALL_VDSL
			struct VDSL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef FIREWALL_VDSL_0
					struct
					{
						uint32_t                      :6;
						uint32_t LENG                 :10;
						uint32_t                      :16;
					};
					#endif
					#ifdef FIREWALL_VDSL_1
					struct
					{
						uint32_t                      :6;
						uint32_t LENG                 :11;
						uint32_t                      :15;
					};
					#endif
					#ifdef FIREWALL_VDSL_2
					struct
					{
						uint32_t                      :6;
						uint32_t LENG                 :12;
						uint32_t                      :14;
					};
					#endif
				};
				//SOOL-FIREWALL_VDSL-DECLARATION
			};
			#endif
			
			#ifdef FIREWALL_VDSSA
			struct VDSSA_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef FIREWALL_VDSSA_0
					struct
					{
						uint32_t                      :6;
						uint32_t ADD                  :10;
						uint32_t                      :16;
					};
					#endif
					#ifdef FIREWALL_VDSSA_1
					struct
					{
						uint32_t                      :6;
						uint32_t ADD                  :11;
						uint32_t                      :15;
					};
					#endif
					#ifdef FIREWALL_VDSSA_2
					struct
					{
						uint32_t                      :6;
						uint32_t ADD                  :12;
						uint32_t                      :14;
					};
					#endif
				};
				//SOOL-FIREWALL_VDSSA-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CSSA_TypeDef CSSA;   // @0x000
					CSL_TypeDef CSL;     // @0x004
					NVDSSA_TypeDef NVDSSA; // @0x008
					NVDSL_TypeDef NVDSL; // @0x00c
					VDSSA_TypeDef VDSSA; // @0x010
					VDSL_TypeDef VDSL;   // @0x014
					FIREWALL_MAP0_LSSA;  // @0x018
					FIREWALL_MAP0_LSL;   // @0x01c
					CR_TypeDef CR;       // @0x020
				};
			};
			private:
			FIREWALL() = delete;
			//SOOL-FIREWALL-DECLARATION
		};
		
		//region instances
#define FIREWALL_BASE_ADDR ((uint32_t)0x40011C00U)
#ifdef FIREWALL_BASE_ADDR
volatile class FIREWALL * const FIREWALL = reinterpret_cast<class FIREWALL* const>(FIREWALL_BASE_ADDR);
#endif
//endregion

//SOOL-FIREWALL-DEFINES
//SOOL-FIREWALL-DEFINITION
	};
};//region undef
#undef FIREWALL_MAP0_LSSA
#undef FIREWALL_MAP0_LSL
//endregion
#endif
#endif
