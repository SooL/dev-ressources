#ifndef __SOOL_SDADC_H
#define __SOOL_SDADC_H

#include "peripheral_include.h"
//SOOL-SDADC-INCLUDES
#if defined(STM32F373xC ) || defined(STM32F378xx ) 
//region defines

#define SDADC_CLRISR
#define SDADC_CONF0R
#define SDADC_CONF1R
#define SDADC_CONF2R
#define SDADC_CONFCHR1
#define SDADC_CONFCHR2
#define SDADC_CR1
#define SDADC_CR2
#define SDADC_ISR
#define SDADC_JCHGR
#define SDADC_JDATA12R
#define SDADC_JDATA13R
#define SDADC_JDATAR
#define SDADC_RDATA12R
#define SDADC_RDATA13R
#define SDADC_RDATAR

//endregion

namespace sool
{
	namespace core
	{
		class SDADC
		{
			//SOOL-SDADC-ENUMS
			
			public :
			
			#ifdef SDADC_CONF0R
			struct CONF0R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t OFFSET0              :12;
					uint32_t                      :8;
					uint32_t GAIN0                :3;
					uint32_t                      :3;
					uint32_t SE0                  :2;
					uint32_t                      :2;
					uint32_t COMMON0              :2;
			
				//SOOL-SDADC_CONF0R-DECLARATION
			};
			#endif
			
			#ifdef SDADC_CONF1R
			struct CONF1R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t OFFSET1              :12;
					uint32_t                      :8;
					uint32_t GAIN1                :3;
					uint32_t                      :3;
					uint32_t SE1                  :2;
					uint32_t                      :2;
					uint32_t COMMON1              :2;
			
				//SOOL-SDADC_CONF1R-DECLARATION
			};
			#endif
			
			#ifdef SDADC_CONF2R
			struct CONF2R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t OFFSET2              :12;
					uint32_t                      :8;
					uint32_t GAIN2                :3;
					uint32_t                      :3;
					uint32_t SE2                  :2;
					uint32_t                      :2;
					uint32_t COMMON2              :2;
			
				//SOOL-SDADC_CONF2R-DECLARATION
			};
			#endif
			
			#ifdef SDADC_CONFCHR1
			struct CONFCHR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CONFCH0              :2;
					uint32_t                      :2;
					uint32_t CONFCH1              :2;
					uint32_t                      :2;
					uint32_t CONFCH2              :2;
					uint32_t                      :2;
					uint32_t CONFCH3              :2;
					uint32_t                      :2;
					uint32_t CONFCH4              :2;
					uint32_t                      :2;
					uint32_t CONFCH5              :2;
					uint32_t                      :2;
					uint32_t CONFCH6              :2;
					uint32_t                      :2;
					uint32_t CONFCH7              :2;
					uint32_t                      :2;
			
				//SOOL-SDADC_CONFCHR1-DECLARATION
			};
			#endif
			
			#ifdef SDADC_CONFCHR2
			struct CONFCHR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CONFCH8              :2;
					uint32_t                      :30;
			
				//SOOL-SDADC_CONFCHR2-DECLARATION
			};
			#endif
			
			#ifdef SDADC_CR1
			struct CR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EOCALIE              :1;
					uint32_t JEOCIE               :1;
					uint32_t JOVRIE               :1;
					uint32_t REOCIE               :1;
					uint32_t ROVRIE               :1;
					uint32_t                      :3;
					uint32_t REFV                 :2;
					uint32_t SLOWCK               :1;
					uint32_t SBI                  :1;
					uint32_t PDI                  :1;
					uint32_t                      :1;
					uint32_t JSYNC                :1;
					uint32_t RSYNC                :1;
					uint32_t JDMAEN               :1;
					uint32_t RDMAEN               :1;
					uint32_t                      :13;
					uint32_t INIT                 :1;
			
				//SOOL-SDADC_CR1-DECLARATION
			};
			#endif
			
			#ifdef SDADC_CR2
			struct CR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ADON                 :1;
					uint32_t CALIBCNT             :2;
					uint32_t                      :1;
					uint32_t STARTCALIB           :1;
					uint32_t JCONT                :1;
					uint32_t JDS                  :1;
					uint32_t                      :1;
					uint32_t JEXTSEL              :4;
					uint32_t                      :1;
					uint32_t JEXTEN               :2;
					uint32_t JSWSTART             :1;
					uint32_t RCH                  :4;
					uint32_t                      :2;
					uint32_t RCONT                :1;
					uint32_t RSWSTART             :1;
					uint32_t FAST                 :1;
					uint32_t                      :7;
			
				//SOOL-SDADC_CR2-DECLARATION
			};
			#endif
			
			#ifdef SDADC_ISR
			struct ISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t EOCALF               :1;
						uint32_t JEOCF                :1;
						uint32_t JOVRF                :1;
						uint32_t REOCF                :1;
						uint32_t ROVRF                :1;
						uint32_t                      :7;
						uint32_t CALIBIP              :1;
						uint32_t JCIP                 :1;
						uint32_t RCIP                 :1;
						uint32_t STABIP               :1;
						uint32_t                      :15;
						uint32_t INITRDY              :1;
					};
					struct
					{
						uint32_t CLREOCALF            :1;
						uint32_t                      :1;
						uint32_t CLRJOVRF             :1;
						uint32_t                      :1;
						uint32_t CLRROVRF             :1;
						uint32_t                      :27;
					};
				};
				//SOOL-SDADC_ISR-DECLARATION
			};
			#endif
			
			#ifdef SDADC_JCHGR
			struct JCHGR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t JCHG                 :9;
					uint32_t                      :23;
			
				//SOOL-SDADC_JCHGR-DECLARATION
			};
			#endif
			
			#ifdef SDADC_JDATA12R
			struct JDATA12R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t JDATA1               :16;
					uint32_t JDATA2               :16;
			
				//SOOL-SDADC_JDATA12R-DECLARATION
			};
			#endif
			
			#ifdef SDADC_JDATA13R
			struct JDATA13R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t JDATA1               :16;
					uint32_t JDATA3               :16;
			
				//SOOL-SDADC_JDATA13R-DECLARATION
			};
			#endif
			
			#ifdef SDADC_JDATAR
			struct JDATAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t JDATA                :16;
					uint32_t                      :8;
					uint32_t JDATACH              :4;
					uint32_t                      :4;
			
				//SOOL-SDADC_JDATAR-DECLARATION
			};
			#endif
			
			#ifdef SDADC_RDATA12R
			struct RDATA12R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RDATA1               :16;
					uint32_t RDATA2               :16;
			
				//SOOL-SDADC_RDATA12R-DECLARATION
			};
			#endif
			
			#ifdef SDADC_RDATA13R
			struct RDATA13R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RDATA1               :16;
					uint32_t RDATA3               :16;
			
				//SOOL-SDADC_RDATA13R-DECLARATION
			};
			#endif
			
			#ifdef SDADC_RDATAR
			struct RDATAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RDATA                :16;
					uint32_t                      :16;
			
				//SOOL-SDADC_RDATAR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR1_TypeDef CR1;     // @0x000
					CR2_TypeDef CR2;     // @0x004
					ISR_TypeDef ISR;     // @0x008
					uint32_t CLRISR;     // @0x00c
					__SOOL_PERIPH_PADDING_4;
					JCHGR_TypeDef JCHGR; // @0x014
					__SOOL_PERIPH_PADDING_8;
					CONF0R_TypeDef CONF0R; // @0x020
					CONF1R_TypeDef CONF1R; // @0x024
					CONF2R_TypeDef CONF2R; // @0x028
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_4;
					CONFCHR1_TypeDef CONFCHR1; // @0x040
					CONFCHR2_TypeDef CONFCHR2; // @0x044
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					JDATAR_TypeDef JDATAR; // @0x060
					RDATAR_TypeDef RDATAR; // @0x064
					__SOOL_PERIPH_PADDING_8;
					JDATA12R_TypeDef JDATA12R; // @0x070
					RDATA12R_TypeDef RDATA12R; // @0x074
					JDATA13R_TypeDef JDATA13R; // @0x078
					RDATA13R_TypeDef RDATA13R; // @0x07c
				};
			};
			private:
			SDADC() = delete;
			//SOOL-SDADC-DECLARATION
		};
		
		//region instances
#define SDADC1_BASE_ADDR ((uint32_t)0x40016000U)
#define SDADC2_BASE_ADDR ((uint32_t)0x40016400U)
#define SDADC3_BASE_ADDR ((uint32_t)0x40016800U)
#ifdef SDADC1_BASE_ADDR
volatile class SDADC * const SDADC1 = reinterpret_cast<class SDADC* const>(SDADC1_BASE_ADDR);
#endif
#ifdef SDADC2_BASE_ADDR
volatile class SDADC * const SDADC2 = reinterpret_cast<class SDADC* const>(SDADC2_BASE_ADDR);
#endif
#ifdef SDADC3_BASE_ADDR
volatile class SDADC * const SDADC3 = reinterpret_cast<class SDADC* const>(SDADC3_BASE_ADDR);
#endif
//endregion

//SOOL-SDADC-DEFINES
//SOOL-SDADC-DEFINITION
	};
};//region undef
//endregion
#endif
#endif
