#ifndef __SOOL_OCTOSPIM_H
#define __SOOL_OCTOSPIM_H

#include "peripheral_include.h"
//SOOL-OCTOSPIM-INCLUDES
#if defined(STM32L4P    ) 
//region defines

#define OCTOSPIM_PCR

//endregion

namespace sool
{
	namespace core
	{
		class OCTOSPIM
		{
			//SOOL-OCTOSPIM-ENUMS
			
			public :
			
			#ifdef OCTOSPIM_PCR
			struct PCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CLKEN                :1;
					uint32_t CLKSRC               :1;
					uint32_t                      :2;
					uint32_t DQSEN                :1;
					uint32_t DQSSRC               :1;
					uint32_t                      :2;
					uint32_t NCSEN                :1;
					uint32_t NCSSRC               :1;
					uint32_t                      :6;
					uint32_t IOLEN                :1;
					uint32_t IOLSRC               :2;
					uint32_t                      :5;
					uint32_t IOHEN                :1;
					uint32_t IOHSRC               :2;
					uint32_t                      :5;
			
				//SOOL-OCTOSPIM_PCR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					__SOOL_PERIPH_PADDING_4;
					PCR_TypeDef PCR[2];  // @0x004
				};
			};
			private:
			OCTOSPIM() = delete;
			//SOOL-OCTOSPIM-DECLARATION
		};
		
		//region instances
#define OCTOSPIM_BASE_ADDR ((uint32_t)0x50061C00U)
#ifdef OCTOSPIM_BASE_ADDR
volatile class OCTOSPIM * const OCTOSPIM = reinterpret_cast<class OCTOSPIM* const>(OCTOSPIM_BASE_ADDR);
#endif
//endregion

//SOOL-OCTOSPIM-DEFINES
//SOOL-OCTOSPIM-DEFINITION
	};
};//region undef
//endregion
#endif
#endif
