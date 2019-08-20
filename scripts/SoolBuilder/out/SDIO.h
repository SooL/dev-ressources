#ifndef __SOOL_SDIO_H
#define __SOOL_SDIO_H

#include "peripheral_include.h"
//SOOL-SDIO-INCLUDES
#if defined(STM32F1     ) || defined(STM32F2     ) || defined(STM32F401xC ) || defined(STM32F401xE ) ||\
    defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F411xE ) || defined(STM32F412Cx ) ||\
    defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) ||\
    defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) ||\
    defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) ||\
    defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32L151xD ) || defined(STM32L152xD ) ||\
    defined(STM32L162xD ) 
//region defines

#define SDIO_ARG
#define SDIO_CLKCR
#define SDIO_CMD
#define SDIO_DCOUNT
#define SDIO_DCTRL
#define SDIO_DLEN
#define SDIO_DTIMER
#define SDIO_FIFO
#define SDIO_FIFOCNT
#define SDIO_ICR
#define SDIO_MASK
#define SDIO_POWER
#define SDIO_RESP
#define SDIO_RESPCMD
#define SDIO_STA

#if defined(STM32F1     ) || defined(STM32F2     ) || defined(STM32F401xC ) || defined(STM32F401xE ) ||\
    defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F411xE ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) ||\
    defined(STM32F439xx ) || defined(STM32L151xD ) || defined(STM32L152xD ) || defined(STM32L162xD ) 
#define SDIO_CMD_ENCMDCOMPL  ENCMDCOMPL           // 1 bits @ 12
#define SDIO_CMD_NIEN        NIEN                 // 1 bits @ 13
#define SDIO_CMD_CEATACMD    CEATACMD             // 1 bits @ 14
#define SDIO_ICR_STBITERRC   STBITERRC            // 1 bits @ 9
#define SDIO_ICR_CEATAENDC   CEATAENDC            // 1 bits @ 23
#define SDIO_MASK_STBITERRIE STBITERRIE           // 1 bits @ 9
#define SDIO_MASK_CEATAENDIE CEATAENDIE           // 1 bits @ 23
#define SDIO_STA_STBITERR    STBITERR             // 1 bits @ 9
#define SDIO_STA_CEATAEND    CEATAEND             // 1 bits @ 23
#else
#define SDIO_CMD_ENCMDCOMPL
#define SDIO_CMD_NIEN
#define SDIO_CMD_CEATACMD
#define SDIO_ICR_STBITERRC
#define SDIO_ICR_CEATAENDC
#define SDIO_MASK_STBITERRIE
#define SDIO_MASK_CEATAENDIE
#define SDIO_STA_STBITERR
#define SDIO_STA_CEATAEND
#endif

//endregion

namespace sool
{
	namespace core
	{
		class SDIO
		{
			//SOOL-SDIO-ENUMS
			
			public :
			
			#ifdef SDIO_ARG
			struct ARG_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CMDARG               :32;
			
				//SOOL-SDIO_ARG-DECLARATION
			};
			#endif
			
			#ifdef SDIO_CLKCR
			struct CLKCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CLKDIV               :8;
					uint32_t CLKEN                :1;
					uint32_t PWRSAV               :1;
					uint32_t BYPASS               :1;
					uint32_t WIDBUS               :2;
					uint32_t NEGEDGE              :1;
					uint32_t HWFC_EN              :1;
					uint32_t                      :17;
			
				//SOOL-SDIO_CLKCR-DECLARATION
			};
			#endif
			
			#ifdef SDIO_CMD
			struct CMD_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CMDINDEX             :6;
					uint32_t WAITRESP             :2;
					uint32_t WAITINT              :1;
					uint32_t WAITPEND             :1;
					uint32_t CPSMEN               :1;
					uint32_t SDIOSUSPEND          :1;
					uint32_t SDIO_CMD_ENCMDCOMPL  :1;
					uint32_t SDIO_CMD_NIEN        :1;
					uint32_t SDIO_CMD_CEATACMD    :1;
					uint32_t                      :17;
			
				//SOOL-SDIO_CMD-DECLARATION
			};
			#endif
			
			#ifdef SDIO_DCOUNT
			struct DCOUNT_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DATACOUNT            :25;
					uint32_t                      :7;
			
				//SOOL-SDIO_DCOUNT-DECLARATION
			};
			#endif
			
			#ifdef SDIO_DCTRL
			struct DCTRL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DTEN                 :1;
					uint32_t DTDIR                :1;
					uint32_t DTMODE               :1;
					uint32_t DMAEN                :1;
					uint32_t DBLOCKSIZE           :4;
					uint32_t RWSTART              :1;
					uint32_t RWSTOP               :1;
					uint32_t RWMOD                :1;
					uint32_t SDIOEN               :1;
					uint32_t                      :20;
			
				//SOOL-SDIO_DCTRL-DECLARATION
			};
			#endif
			
			#ifdef SDIO_DLEN
			struct DLEN_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DATALENGTH           :25;
					uint32_t                      :7;
			
				//SOOL-SDIO_DLEN-DECLARATION
			};
			#endif
			
			#ifdef SDIO_DTIMER
			struct DTIMER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DATATIME             :32;
			
				//SOOL-SDIO_DTIMER-DECLARATION
			};
			#endif
			
			#ifdef SDIO_FIFO
			struct FIFO_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FIFODATA             :32;
			
				//SOOL-SDIO_FIFO-DECLARATION
			};
			#endif
			
			#ifdef SDIO_FIFOCNT
			struct FIFOCNT_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FIFOCOUNT            :24;
					uint32_t                      :8;
			
				//SOOL-SDIO_FIFOCNT-DECLARATION
			};
			#endif
			
			#ifdef SDIO_ICR
			struct ICR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CCRCFAILC            :1;
					uint32_t DCRCFAILC            :1;
					uint32_t CTIMEOUTC            :1;
					uint32_t DTIMEOUTC            :1;
					uint32_t TXUNDERRC            :1;
					uint32_t RXOVERRC             :1;
					uint32_t CMDRENDC             :1;
					uint32_t CMDSENTC             :1;
					uint32_t DATAENDC             :1;
					uint32_t SDIO_ICR_STBITERRC   :1;
					uint32_t DBCKENDC             :1;
					uint32_t                      :11;
					uint32_t SDIOITC              :1;
					uint32_t SDIO_ICR_CEATAENDC   :1;
					uint32_t                      :8;
			
				//SOOL-SDIO_ICR-DECLARATION
			};
			#endif
			
			#ifdef SDIO_MASK
			struct MASK_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CCRCFAILIE           :1;
					uint32_t DCRCFAILIE           :1;
					uint32_t CTIMEOUTIE           :1;
					uint32_t DTIMEOUTIE           :1;
					uint32_t TXUNDERRIE           :1;
					uint32_t RXOVERRIE            :1;
					uint32_t CMDRENDIE            :1;
					uint32_t CMDSENTIE            :1;
					uint32_t DATAENDIE            :1;
					uint32_t SDIO_MASK_STBITERRIE :1;
					uint32_t DBCKENDIE            :1;
					uint32_t CMDACTIE             :1;
					uint32_t TXACTIE              :1;
					uint32_t RXACTIE              :1;
					uint32_t TXFIFOHEIE           :1;
					uint32_t RXFIFOHFIE           :1;
					uint32_t TXFIFOFIE            :1;
					uint32_t RXFIFOFIE            :1;
					uint32_t TXFIFOEIE            :1;
					uint32_t RXFIFOEIE            :1;
					uint32_t TXDAVLIE             :1;
					uint32_t RXDAVLIE             :1;
					uint32_t SDIOITIE             :1;
					uint32_t SDIO_MASK_CEATAENDIE :1;
					uint32_t                      :8;
			
				//SOOL-SDIO_MASK-DECLARATION
			};
			#endif
			
			#ifdef SDIO_POWER
			struct POWER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PWRCTRL              :2;
					uint32_t                      :30;
			
				//SOOL-SDIO_POWER-DECLARATION
			};
			#endif
			
			#ifdef SDIO_RESP
			struct RESP_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CARDSTATUS           :32;
			
				//SOOL-SDIO_RESP-DECLARATION
			};
			#endif
			
			#ifdef SDIO_RESPCMD
			struct RESPCMD_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t RESPCMD              :6;
						uint32_t                      :26;
					};
					struct
					{
						uint32_t CARDSTATUS0          :32;
					};
				};
				//SOOL-SDIO_RESPCMD-DECLARATION
			};
			#endif
			
			#ifdef SDIO_STA
			struct STA_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CCRCFAIL             :1;
					uint32_t DCRCFAIL             :1;
					uint32_t CTIMEOUT             :1;
					uint32_t DTIMEOUT             :1;
					uint32_t TXUNDERR             :1;
					uint32_t RXOVERR              :1;
					uint32_t CMDREND              :1;
					uint32_t CMDSENT              :1;
					uint32_t DATAEND              :1;
					uint32_t SDIO_STA_STBITERR    :1;
					uint32_t DBCKEND              :1;
					uint32_t CMDACT               :1;
					uint32_t TXACT                :1;
					uint32_t RXACT                :1;
					uint32_t TXFIFOHE             :1;
					uint32_t RXFIFOHF             :1;
					uint32_t TXFIFOF              :1;
					uint32_t RXFIFOF              :1;
					uint32_t TXFIFOE              :1;
					uint32_t RXFIFOE              :1;
					uint32_t TXDAVL               :1;
					uint32_t RXDAVL               :1;
					uint32_t SDIOIT               :1;
					uint32_t SDIO_STA_CEATAEND    :1;
					uint32_t                      :8;
			
				//SOOL-SDIO_STA-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					POWER_TypeDef POWER; // @0x000
					CLKCR_TypeDef CLKCR; // @0x004
					ARG_TypeDef ARG;     // @0x008
					CMD_TypeDef CMD;     // @0x00c
					RESPCMD_TypeDef RESPCMD; // @0x010
					RESP_TypeDef RESP1;  // @0x014
					RESP_TypeDef RESP2;  // @0x018
					RESP_TypeDef RESP3;  // @0x01c
					RESP_TypeDef RESP4;  // @0x020
					DTIMER_TypeDef DTIMER; // @0x024
					DLEN_TypeDef DLEN;   // @0x028
					DCTRL_TypeDef DCTRL; // @0x02c
					DCOUNT_TypeDef DCOUNT; // @0x030
					STA_TypeDef STA;     // @0x034
					ICR_TypeDef ICR;     // @0x038
					MASK_TypeDef MASK;   // @0x03c
					__SOOL_PERIPH_PADDING_8;
					FIFOCNT_TypeDef FIFOCNT; // @0x048
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_4;
					FIFO_TypeDef FIFO;   // @0x080
				};
			};
			private:
			SDIO() = delete;
			//SOOL-SDIO-DECLARATION
		};
		
		//region instances
#if defined(STM32F1     ) 
#define SDIO_BASE_ADDR ((uint32_t)0x40018000U)
#endif

#if defined(STM32F2     ) || defined(STM32F401xC ) || defined(STM32F401xE ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F411xE ) || defined(STM32F412Cx ) || defined(STM32F412Rx ) ||\
    defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32L151xD ) || defined(STM32L152xD ) || defined(STM32L162xD ) 
#define SDIO_BASE_ADDR ((uint32_t)0x40012C00U)
#endif

#ifdef SDIO_BASE_ADDR
volatile class SDIO * const SDIO = reinterpret_cast<class SDIO* const>(SDIO_BASE_ADDR);
#endif
//endregion

//SOOL-SDIO-DEFINES
//SOOL-SDIO-DEFINITION
	};
};//region undef
#undef SDIO_CMD_ENCMDCOMPL
#undef SDIO_CMD_NIEN
#undef SDIO_CMD_CEATACMD
#undef SDIO_ICR_STBITERRC
#undef SDIO_ICR_CEATAENDC
#undef SDIO_MASK_STBITERRIE
#undef SDIO_MASK_CEATAENDIE
#undef SDIO_STA_STBITERR
#undef SDIO_STA_CEATAEND
//endregion
#endif
#endif
