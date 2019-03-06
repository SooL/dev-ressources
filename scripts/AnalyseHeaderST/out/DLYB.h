#ifndef __SOOL_DLYB_H
#define __SOOL_DLYB_H

#include "peripheral_include.h"
//SOOL-DLYB-INCLUDES
#if defined(STM32H7     ) 
//region defines

#define DLYB_CFGR
#define DLYB_CR

//endregion

namespace sool
{
	namespace core
	{
		class DLYB
		{
			//SOOL-DLYB-ENUMS
			
			public :
			
			#ifdef DLYB_CFGR
			struct CFGR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SEL                  :4;
					uint32_t                      :4;
					uint32_t UNIT                 :7;
					uint32_t                      :1;
					uint32_t LNG                  :12;
					uint32_t                      :3;
					uint32_t LNGF                 :1;
			
				//SOOL-DLYB_CFGR-DECLARATION
			};
			#endif
			
			#ifdef DLYB_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DEN                  :1;
					uint32_t SEN                  :1;
					uint32_t                      :30;
			
				//SOOL-DLYB_CR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					CFGR_TypeDef CFGR;   // @0x004
				};
			};
			private:
			DLYB() = delete;
			//SOOL-DLYB-DECLARATION
		};
		
		//region instances
#define DLYB_SDMMC2_BASE_ADDR ((uint32_t)0x48022800U)
#define DLYB_QUADSPI_BASE_ADDR ((uint32_t)0x52006000U)
#define DLYB_SDMMC1_BASE_ADDR ((uint32_t)0x52008000U)
#ifdef DLYB_SDMMC2_BASE_ADDR
volatile class DLYB * const DLYB_SDMMC2 = reinterpret_cast<class DLYB* const>(DLYB_SDMMC2_BASE_ADDR);
#endif
#ifdef DLYB_QUADSPI_BASE_ADDR
volatile class DLYB * const DLYB_QUADSPI = reinterpret_cast<class DLYB* const>(DLYB_QUADSPI_BASE_ADDR);
#endif
#ifdef DLYB_SDMMC1_BASE_ADDR
volatile class DLYB * const DLYB_SDMMC1 = reinterpret_cast<class DLYB* const>(DLYB_SDMMC1_BASE_ADDR);
#endif
//endregion

//SOOL-DLYB-DEFINES
//SOOL-DLYB-DEFINITION
	};
};//region undef
//endregion
#endif
#endif
