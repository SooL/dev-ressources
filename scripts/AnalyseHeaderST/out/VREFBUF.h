#ifndef __SOOL_VREFBUF_H
#define __SOOL_VREFBUF_H

#include "peripheral_include.h"
//SOOL-VREFBUF-INCLUDES
#if defined(STM32H7     ) || defined(STM32L431xx ) || defined(STM32L433xx ) || defined(STM32L443xx ) ||\
    defined(STM32L451xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L471xx ) ||\
    defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
//region defines

#define VREFBUF_CCR
#define VREFBUF_CSR

#if defined(STM32H7     ) 
#define VREFBUF_CSR_0_VRS    VRS                  // 3 bits @ 4
#else
#define VREFBUF_CSR_0_VRS
#endif

#if defined(STM32L431xx ) || defined(STM32L433xx ) || defined(STM32L443xx ) || defined(STM32L451xx ) ||\
    defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L471xx ) || defined(STM32L475xx ) ||\
    defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define VREFBUF_CSR_1
#endif

//endregion

namespace sool
{
	namespace core
	{
		class VREFBUF
		{
			//SOOL-VREFBUF-ENUMS
			
			public :
			
			#ifdef VREFBUF_CCR
			struct CCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TRIM                 :6;
					uint32_t                      :26;
			
				//SOOL-VREFBUF_CCR-DECLARATION
			};
			#endif
			
			#ifdef VREFBUF_CSR
			struct CSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t ENVR                 :1;
						uint32_t HIZ                  :1;
						uint32_t                      :1;
						uint32_t VRR                  :1;
						uint32_t VREFBUF_CSR_0_VRS    :3;
						uint32_t                      :25;
					};
					#ifdef VREFBUF_CSR_1
					struct
					{
						uint32_t                      :2;
						uint32_t VRS                  :1;
						uint32_t                      :29;
					};
					#endif
				};
				//SOOL-VREFBUF_CSR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CSR_TypeDef CSR;     // @0x000
					CCR_TypeDef CCR;     // @0x004
				};
			};
			private:
			VREFBUF() = delete;
			//SOOL-VREFBUF-DECLARATION
		};
		
		//region instances
#if defined(STM32H7     ) 
#define VREFBUF_BASE_ADDR ((uint32_t)0x58003C00U)
#endif

#if defined(STM32L431xx ) || defined(STM32L433xx ) || defined(STM32L443xx ) || defined(STM32L451xx ) ||\
    defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L471xx ) || defined(STM32L475xx ) ||\
    defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define VREFBUF_BASE_ADDR ((uint32_t)0x40010030U)
#endif

#ifdef VREFBUF_BASE_ADDR
volatile class VREFBUF * const VREFBUF = reinterpret_cast<class VREFBUF* const>(VREFBUF_BASE_ADDR);
#endif
//endregion

//SOOL-VREFBUF-DEFINES
//SOOL-VREFBUF-DEFINITION
	};
};//region undef
#undef VREFBUF_CSR_0_VRS
//endregion
#endif
#endif
