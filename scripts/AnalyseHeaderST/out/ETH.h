#ifndef __SOOL_ETH_H
#define __SOOL_ETH_H

#include "peripheral_include.h"
//SOOL-ETH-INCLUDES
#if defined(STM32F107xC ) || defined(STM32F207xx ) || defined(STM32F217xx ) || defined(STM32F407xx ) ||\
    defined(STM32F417xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) ||\
    defined(STM32F439xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F745xx ) ||\
    defined(STM32F746xx ) || defined(STM32F756xx ) || defined(STM32F765xx ) || defined(STM32F767xx ) ||\
    defined(STM32F769xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32H7     ) 
//region defines

#if defined(STM32F107xC ) || defined(STM32F207xx ) || defined(STM32F217xx ) || defined(STM32F407xx ) ||\
    defined(STM32F417xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) ||\
    defined(STM32F439xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F745xx ) ||\
    defined(STM32F746xx ) || defined(STM32F756xx ) || defined(STM32F765xx ) || defined(STM32F767xx ) ||\
    defined(STM32F769xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) 
#define ETH_DMABMR
#define ETH_DMACHRBAR
#define ETH_DMACHRDR
#define ETH_DMACHTBAR
#define ETH_DMACHTDR
#define ETH_DMAIER
#define ETH_DMAMFBOCR
#define ETH_DMAOMR
#define ETH_DMARDLAR
#define ETH_DMARPDR
#define ETH_DMASR
#define ETH_DMATDLAR
#define ETH_DMATPDR
#define ETH_MACCR_0_RE       RE                   // 1 bits @ 2
#define ETH_MACCR_0_TE       TE                   // 1 bits @ 3
#define ETH_MACCR_0_APCS     APCS                 // 1 bits @ 7
#define ETH_MACCR_0_RD       RD                   // 1 bits @ 9
#define ETH_MACCR_0_IPCO     IPCO                 // 1 bits @ 10
#define ETH_MACCR_0_DM       DM                   // 1 bits @ 11
#define ETH_MACCR_0_ROD      ROD                  // 1 bits @ 13
#define ETH_MACCR_0_CSD      CSD                  // 1 bits @ 16
#define ETH_MACCR_0_IFG      IFG                  // 3 bits @ 17
#define ETH_MACCR_0_JD       JD                   // 1 bits @ 22
#define ETH_MACCR_0_WD       WD                   // 1 bits @ 23
#define ETH_MACFCR
#define ETH_MACFFR
#define ETH_MACHTHR
#define ETH_MACHTLR
#define ETH_MACIMR
#define ETH_MACMIIAR
#define ETH_MACMIIDR
#define ETH_MACPMTCSR
#define ETH_MACRWUFFR
#define ETH_MACSR
#define ETH_MACVLANTR
#define ETH_MMCRFAECR
#define ETH_MMCRFCECR
#define ETH_MMCRGUFCR
#define ETH_MMCTGFCR
#define ETH_MMCTGFMSCCR
#define ETH_MMCTGFSCCR
#define ETH_PTPSSIR
#define ETH_PTPTSAR
#define ETH_PTPTSCR
#define ETH_PTPTSHR
#define ETH_PTPTSHUR
#define ETH_PTPTSLR
#define ETH_PTPTSLUR
#define ETH_PTPTTHR
#define ETH_PTPTTLR
#define ETH_MAP0_MACFFR      MACFFR_TypeDef MACFFR
#define ETH_MAP0_MACHTHR     MACHTHR_TypeDef MACHTHR
#define ETH_MAP0_MACHTLR     MACHTLR_TypeDef MACHTLR
#define ETH_MAP0_MACMIIAR    MACMIIAR_TypeDef MACMIIAR
#define ETH_MAP0_MACMIIDR    MACMIIDR_TypeDef MACMIIDR
#define ETH_MAP0_MACFCR      MACFCR_TypeDef MACFCR
#define ETH_MAP0_MACVLANTR   MACVLANTR_TypeDef MACVLANTR
#define ETH_MAP0_MACRWUFFR   MACRWUFFR_TypeDef MACRWUFFR
#define ETH_MAP0_MACPMTCSR   MACPMTCSR_TypeDef MACPMTCSR
#define ETH_MAP0_MACSR       MACSR_TypeDef MACSR
#define ETH_MAP0_MACIMR      MACIMR_TypeDef MACIMR
#define ETH_MAP0_MACA0HR     MACAHR_TypeDef MACA0HR
#define ETH_MAP0_MACA0LR     MACALR_TypeDef MACA0LR
#define ETH_MAP0_MACA1HR     MACAHR_TypeDef MACA1HR
#define ETH_MAP0_MACA1LR     MACALR_TypeDef MACA1LR
#define ETH_MAP0_MACA2HR     MACAHR_TypeDef MACA2HR
#define ETH_MAP0_MACA2LR     MACALR_TypeDef MACA2LR
#define ETH_MAP0_MACA3HR     MACAHR_TypeDef MACA3HR
#define ETH_MAP0_MACA3LR     MACALR_TypeDef MACA3LR
#define ETH_MAP0_MMCCR       MMCCR_TypeDef MMCCR
#define ETH_MAP0_MMCRIR      MMCRIR_TypeDef MMCRIR
#define ETH_MAP0_MMCTIR      MMCTIR_TypeDef MMCTIR
#define ETH_MAP0_MMCRIMR     MMCRIMR_TypeDef MMCRIMR
#define ETH_MAP0_MMCTIMR     MMCTIMR_TypeDef MMCTIMR
#define ETH_MAP0_MMCTGFSCCR  MMCTGFSCCR_TypeDef MMCTGFSCCR
#define ETH_MAP0_MMCTGFMSCCR MMCTGFMSCCR_TypeDef MMCTGFMSCCR
#define ETH_MAP0_MMCTGFCR    MMCTGFCR_TypeDef MMCTGFCR
#define ETH_MAP0_MMCRFCECR   MMCRFCECR_TypeDef MMCRFCECR
#define ETH_MAP0_MMCRFAECR   MMCRFAECR_TypeDef MMCRFAECR
#define ETH_MAP0_MMCRGUFCR   MMCRGUFCR_TypeDef MMCRGUFCR
#define ETH_MAP0_PTPTSCR     PTPTSCR_TypeDef PTPTSCR
#define ETH_MAP0_PTPSSIR     PTPSSIR_TypeDef PTPSSIR
#define ETH_MAP0_PTPTSHR     PTPTSHR_TypeDef PTPTSHR
#define ETH_MAP0_PTPTSLR     PTPTSLR_TypeDef PTPTSLR
#define ETH_MAP0_PTPTSHUR    PTPTSHUR_TypeDef PTPTSHUR
#define ETH_MAP0_PTPTSLUR    PTPTSLUR_TypeDef PTPTSLUR
#define ETH_MAP0_PTPTSAR     PTPTSAR_TypeDef PTPTSAR
#define ETH_MAP0_PTPTTHR     PTPTTHR_TypeDef PTPTTHR
#define ETH_MAP0_PTPTTLR     PTPTTLR_TypeDef PTPTTLR
#define ETH_MAP0_DMABMR      DMABMR_TypeDef DMABMR
#define ETH_MAP0_DMATPDR     DMATPDR_TypeDef DMATPDR
#define ETH_MAP0_DMARPDR     DMARPDR_TypeDef DMARPDR
#define ETH_MAP0_DMARDLAR    DMARDLAR_TypeDef DMARDLAR
#define ETH_MAP0_DMATDLAR    DMATDLAR_TypeDef DMATDLAR
#define ETH_MAP0_DMASR       DMASR_TypeDef DMASR
#define ETH_MAP0_DMAOMR      DMAOMR_TypeDef DMAOMR
#define ETH_MAP0_DMAIER      DMAIER_TypeDef DMAIER
#define ETH_MAP0_DMAMFBOCR   DMAMFBOCR_TypeDef DMAMFBOCR
#define ETH_MAP0_DMACHTDR    DMACHTDR_TypeDef DMACHTDR
#define ETH_MAP0_DMACHRDR    DMACHRDR_TypeDef DMACHRDR
#define ETH_MAP0_DMACHTBAR   DMACHTBAR_TypeDef DMACHTBAR
#define ETH_MAP0_DMACHRBAR   DMACHRBAR_TypeDef DMACHRBAR
#else
#define ETH_MACCR_0_RE
#define ETH_MACCR_0_TE
#define ETH_MACCR_0_APCS
#define ETH_MACCR_0_RD
#define ETH_MACCR_0_IPCO
#define ETH_MACCR_0_DM
#define ETH_MACCR_0_ROD
#define ETH_MACCR_0_CSD
#define ETH_MACCR_0_IFG
#define ETH_MACCR_0_JD
#define ETH_MACCR_0_WD
#define ETH_MAP0_MACFFR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACHTHR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACHTLR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACMIIAR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACMIIDR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACFCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACVLANTR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACRWUFFR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACPMTCSR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACSR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACIMR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACA0HR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACA0LR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACA1HR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACA1LR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACA2HR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACA2LR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACA3HR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACA3LR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCRIR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCTIR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCRIMR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCTIMR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCTGFSCCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCTGFMSCCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCTGFCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCRFCECR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCRFAECR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCRGUFCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_PTPTSCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_PTPSSIR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_PTPTSHR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_PTPTSLR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_PTPTSHUR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_PTPTSLUR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_PTPTSAR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_PTPTTHR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_PTPTTLR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMABMR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMATPDR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMARPDR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMARDLAR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMATDLAR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMASR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMAOMR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMAIER __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMAMFBOCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACHTDR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACHRDR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACHTBAR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACHRBAR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F207xx ) || defined(STM32F217xx ) || defined(STM32F407xx ) || defined(STM32F417xx ) ||\
    defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F745xx ) || defined(STM32F746xx ) ||\
    defined(STM32F756xx ) || defined(STM32F765xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) ||\
    defined(STM32F777xx ) || defined(STM32F779xx ) 
#define ETH_DMABMR_EDE       EDE                  // 1 bits @ 7
#define ETH_DMARSWTR
#define ETH_MACDBGR
#define ETH_MMCCR_MCP        MCP                  // 1 bits @ 4
#define ETH_MMCCR_MCFHP      MCFHP                // 1 bits @ 5
#define ETH_PTPTSCR_TSCNT    TSCNT                // 2 bits @ 16
#define ETH_PTPTSSR
#define ETH_MAP0_MACDBGR     MACDBGR_TypeDef MACDBGR
#define ETH_MAP0_PTPTSSR     PTPTSSR_TypeDef PTPTSSR
#define ETH_MAP0_DMARSWTR    uint32_t DMARSWTR
#else
#define ETH_DMABMR_EDE
#define ETH_MMCCR_MCP
#define ETH_MMCCR_MCFHP
#define ETH_PTPTSCR_TSCNT
#define ETH_MAP0_MACDBGR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_PTPTSSR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMARSWTR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32H7     ) 
#define ETH_DMACCARBR
#define ETH_DMACCARDR
#define ETH_DMACCATBR
#define ETH_DMACCATDR
#define ETH_DMACCR
#define ETH_DMACIER
#define ETH_DMACMFCR
#define ETH_DMACRCR
#define ETH_DMACRDLAR
#define ETH_DMACRDRLR
#define ETH_DMACRDTPR
#define ETH_DMACRIWTR
#define ETH_DMACSFCSR
#define ETH_DMACSR
#define ETH_DMACTCR
#define ETH_DMACTDLAR
#define ETH_DMACTDRLR
#define ETH_DMACTDTPR
#define ETH_DMADSR
#define ETH_DMAISR
#define ETH_DMAMR
#define ETH_DMASBMR
#define ETH_MAC1USTCR
#define ETH_MACACR
#define ETH_MACARPAR
#define ETH_MACATSNR
#define ETH_MACATSSR
#define ETH_MACCR_0_DR       DR                   // 1 bits @ 8
#define ETH_MACCR_0_ACS      ACS                  // 1 bits @ 20
#define ETH_MACCR_0_CST      CST                  // 1 bits @ 21
#define ETH_MACCR_0_IPG      IPG                  // 3 bits @ 24
#define ETH_MACCR_0_IPC      IPC                  // 1 bits @ 27
#define ETH_MACCR_0_SARC     SARC                 // 3 bits @ 28
#define ETH_MACCR_0_ARP      ARP                  // 1 bits @ 31
#define ETH_MACCR_1
#define ETH_MACDR
#define ETH_MACECR
#define ETH_MACHT0R
#define ETH_MACHT1R
#define ETH_MACHWF0R
#define ETH_MACHWF1R
#define ETH_MACHWF2R
#define ETH_MACIER
#define ETH_MACISR
#define ETH_MACIVIR
#define ETH_MACL3A00R
#define ETH_MACL3A01R
#define ETH_MACL3A10R
#define ETH_MACL3A11R
#define ETH_MACL3A20R
#define ETH_MACL3A21R
#define ETH_MACL3A30R
#define ETH_MACL3A31R
#define ETH_MACL3L4CR
#define ETH_MACL4AR
#define ETH_MACLCSR
#define ETH_MACLETR
#define ETH_MACLMIR
#define ETH_MACLTCR
#define ETH_MACMDIOAR
#define ETH_MACMDIODR
#define ETH_MACPCSR
#define ETH_MACPFR
#define ETH_MACPOCR
#define ETH_MACPPSCR
#define ETH_MACPPSIR
#define ETH_MACPPSTTNR
#define ETH_MACPPSTTSR
#define ETH_MACPPSWR
#define ETH_MACRFCR
#define ETH_MACRWKPFR
#define ETH_MACRXTXSR
#define ETH_MACSPI0R
#define ETH_MACSPI1R
#define ETH_MACSPI2R
#define ETH_MACSSIR
#define ETH_MACSTNR
#define ETH_MACSTNUR
#define ETH_MACSTSR
#define ETH_MACSTSUR
#define ETH_MACTFCR
#define ETH_MACTSAR
#define ETH_MACTSCR
#define ETH_MACTSEACR
#define ETH_MACTSECNR
#define ETH_MACTSIACR
#define ETH_MACTSICNR
#define ETH_MACTSSR
#define ETH_MACTTSSNR
#define ETH_MACTTSSSR
#define ETH_MACVHTR
#define ETH_MACVIR
#define ETH_MACVR
#define ETH_MACVTR
#define ETH_MACWTR
#define ETH_MMCRAEPR
#define ETH_MMCRCRCEPR
#define ETH_MMCRLPIMSTR
#define ETH_MMCRLPITCR
#define ETH_MMCRUPGR
#define ETH_MMCTLPIMSTR
#define ETH_MMCTLPITCR
#define ETH_MMCTMCGPR
#define ETH_MMCTPCGR
#define ETH_MMCTSCGPR
#define ETH_MTLISR
#define ETH_MTLOMR
#define ETH_MTLQICSR
#define ETH_MTLRQDR
#define ETH_MTLRQMPOCR
#define ETH_MTLRQOMR
#define ETH_MTLTQDR
#define ETH_MTLTQOMR
#define ETH_MTLTQUR
#define ETH_MAP1_MACECR      MACECR_TypeDef MACECR
#define ETH_MAP1_MACPFR      MACPFR_TypeDef MACPFR
#define ETH_MAP1_MACWTR      MACWTR_TypeDef MACWTR
#define ETH_MAP1_MACHT0R     uint32_t MACHT0R
#define ETH_MAP1_MACHT1R     uint32_t MACHT1R
#define ETH_MAP1_MACVTR      MACVTR_TypeDef MACVTR
#define ETH_MAP1_MACVHTR     MACVHTR_TypeDef MACVHTR
#define ETH_MAP0_MACVIR      MACVIR_TypeDef MACVIR
#define ETH_MAP0_MACIVIR     MACIVIR_TypeDef MACIVIR
#define ETH_MAP0_MACTFCR     MACTFCR_TypeDef MACTFCR
#define ETH_MAP0_MACRFCR     MACRFCR_TypeDef MACRFCR
#define ETH_MAP0_MACISR      MACISR_TypeDef MACISR
#define ETH_MAP0_MACIER      MACIER_TypeDef MACIER
#define ETH_MAP0_MACRXTXSR   MACRXTXSR_TypeDef MACRXTXSR
#define ETH_MAP0_MACPCSR     MACPCSR_TypeDef MACPCSR
#define ETH_MAP0_MACRWKPFR   MACRWKPFR_TypeDef MACRWKPFR
#define ETH_MAP0_MACLCSR     MACLCSR_TypeDef MACLCSR
#define ETH_MAP0_MACLTCR     MACLTCR_TypeDef MACLTCR
#define ETH_MAP0_MACLETR     MACLETR_TypeDef MACLETR
#define ETH_MAP0_MAC1USTCR   MAC1USTCR_TypeDef MAC1USTCR
#define ETH_MAP1_MACVR       MACVR_TypeDef MACVR
#define ETH_MAP0_MACDR       MACDR_TypeDef MACDR
#define ETH_MAP0_MACHWF0R    MACHWF0R_TypeDef MACHWF0R
#define ETH_MAP0_MACHWF1R    MACHWF1R_TypeDef MACHWF1R
#define ETH_MAP0_MACHWF2R    MACHWF2R_TypeDef MACHWF2R
#define ETH_MAP0_MACMDIOAR   MACMDIOAR_TypeDef MACMDIOAR
#define ETH_MAP0_MACMDIODR   MACMDIODR_TypeDef MACMDIODR
#define ETH_MAP0_MACARPAR    uint32_t MACARPAR
#define ETH_MAP1_MACA0HR     MACAHR_TypeDef MACA0HR
#define ETH_MAP1_MACA0LR     MACALR_TypeDef MACA0LR
#define ETH_MAP1_MACA1HR     MACAHR_TypeDef MACA1HR
#define ETH_MAP1_MACA1LR     MACALR_TypeDef MACA1LR
#define ETH_MAP1_MACA2HR     MACAHR_TypeDef MACA2HR
#define ETH_MAP1_MACA2LR     MACALR_TypeDef MACA2LR
#define ETH_MAP1_MACA3HR     MACAHR_TypeDef MACA3HR
#define ETH_MAP1_MACA3LR     MACALR_TypeDef MACA3LR
#define ETH_MAP1_MMCCR       MMCCR_TypeDef MMCCR
#define ETH_MAP1_MMCRIR      MMCRIR_TypeDef MMCRIR
#define ETH_MAP1_MMCTIR      MMCTIR_TypeDef MMCTIR
#define ETH_MAP1_MMCRIMR     MMCRIMR_TypeDef MMCRIMR
#define ETH_MAP1_MMCTIMR     MMCTIMR_TypeDef MMCTIMR
#define ETH_MAP0_MMCTSCGPR   uint32_t MMCTSCGPR
#define ETH_MAP0_MMCTMCGPR   uint32_t MMCTMCGPR
#define ETH_MAP0_MMCTPCGR    uint32_t MMCTPCGR
#define ETH_MAP0_MMCRCRCEPR  uint32_t MMCRCRCEPR
#define ETH_MAP0_MMCRAEPR    uint32_t MMCRAEPR
#define ETH_MAP0_MMCRUPGR    uint32_t MMCRUPGR
#define ETH_MAP0_MMCTLPIMSTR uint32_t MMCTLPIMSTR
#define ETH_MAP0_MMCTLPITCR  uint32_t MMCTLPITCR
#define ETH_MAP0_MMCRLPIMSTR uint32_t MMCRLPIMSTR
#define ETH_MAP0_MMCRLPITCR  uint32_t MMCRLPITCR
#define ETH_MAP0_MACL3L4C0R  MACL3L4CR_TypeDef MACL3L4C0R
#define ETH_MAP0_MACL4A0R    MACL4AR_TypeDef MACL4A0R
#define ETH_MAP0_MACL3A00R   uint32_t MACL3A00R
#define ETH_MAP0_MACL3A10R   uint32_t MACL3A10R
#define ETH_MAP0_MACL3A20R   uint32_t MACL3A20R
#define ETH_MAP0_MACL3A30R   uint32_t MACL3A30R
#define ETH_MAP0_MACL3L4C1R  MACL3L4CR_TypeDef MACL3L4C1R
#define ETH_MAP0_MACL4A1R    MACL4AR_TypeDef MACL4A1R
#define ETH_MAP0_MACL3A01R   uint32_t MACL3A01R
#define ETH_MAP0_MACL3A11R   uint32_t MACL3A11R
#define ETH_MAP0_MACL3A21R   uint32_t MACL3A21R
#define ETH_MAP0_MACL3A31R   uint32_t MACL3A31R
#define ETH_MAP0_MACTSCR     uint32_t MACTSCR
#define ETH_MAP0_MACSSIR     uint32_t MACSSIR
#define ETH_MAP0_MACSTSR     uint32_t MACSTSR
#define ETH_MAP0_MACSTNR     uint32_t MACSTNR
#define ETH_MAP0_MACSTSUR    uint32_t MACSTSUR
#define ETH_MAP0_MACSTNUR    uint32_t MACSTNUR
#define ETH_MAP0_MACTSAR     uint32_t MACTSAR
#define ETH_MAP0_MACTSSR     uint32_t MACTSSR
#define ETH_MAP0_MACTTSSNR   uint32_t MACTTSSNR
#define ETH_MAP0_MACTTSSSR   uint32_t MACTTSSSR
#define ETH_MAP0_MACACR      uint32_t MACACR
#define ETH_MAP0_MACATSNR    uint32_t MACATSNR
#define ETH_MAP0_MACATSSR    uint32_t MACATSSR
#define ETH_MAP0_MACTSIACR   uint32_t MACTSIACR
#define ETH_MAP0_MACTSEACR   uint32_t MACTSEACR
#define ETH_MAP0_MACTSICNR   uint32_t MACTSICNR
#define ETH_MAP0_MACTSECNR   uint32_t MACTSECNR
#define ETH_MAP0_MACPPSCR    uint32_t MACPPSCR
#define ETH_MAP0_MACPPSTTSR  uint32_t MACPPSTTSR
#define ETH_MAP0_MACPPSTTNR  uint32_t MACPPSTTNR
#define ETH_MAP0_MACPPSIR    uint32_t MACPPSIR
#define ETH_MAP0_MACPPSWR    uint32_t MACPPSWR
#define ETH_MAP0_MACPOCR     uint32_t MACPOCR
#define ETH_MAP0_MACSPI0R    uint32_t MACSPI0R
#define ETH_MAP0_MACSPI1R    uint32_t MACSPI1R
#define ETH_MAP0_MACSPI2R    uint32_t MACSPI2R
#define ETH_MAP0_MACLMIR     uint32_t MACLMIR
#define ETH_MAP0_MTLOMR      MTLOMR_TypeDef MTLOMR
#define ETH_MAP0_MTLISR      MTLISR_TypeDef MTLISR
#define ETH_MAP0_MTLTQOMR    MTLTQOMR_TypeDef MTLTQOMR
#define ETH_MAP0_MTLTQUR     MTLTQUR_TypeDef MTLTQUR
#define ETH_MAP0_MTLTQDR     MTLTQDR_TypeDef MTLTQDR
#define ETH_MAP0_MTLQICSR    MTLQICSR_TypeDef MTLQICSR
#define ETH_MAP0_MTLRQOMR    MTLRQOMR_TypeDef MTLRQOMR
#define ETH_MAP0_MTLRQMPOCR  MTLRQMPOCR_TypeDef MTLRQMPOCR
#define ETH_MAP0_MTLRQDR     MTLRQDR_TypeDef MTLRQDR
#define ETH_MAP1_DMAMR       DMAMR_TypeDef DMAMR
#define ETH_MAP1_DMASBMR     DMASBMR_TypeDef DMASBMR
#define ETH_MAP1_DMAISR      DMAISR_TypeDef DMAISR
#define ETH_MAP1_DMADSR      DMADSR_TypeDef DMADSR
#define ETH_MAP0_DMACCR      DMACCR_TypeDef DMACCR
#define ETH_MAP0_DMACTCR     DMACTCR_TypeDef DMACTCR
#define ETH_MAP0_DMACRCR     DMACRCR_TypeDef DMACRCR
#define ETH_MAP0_DMACTDLAR   DMACTDLAR_TypeDef DMACTDLAR
#define ETH_MAP0_DMACRDLAR   DMACRDLAR_TypeDef DMACRDLAR
#define ETH_MAP0_DMACTDTPR   DMACTDTPR_TypeDef DMACTDTPR
#define ETH_MAP0_DMACRDTPR   DMACRDTPR_TypeDef DMACRDTPR
#define ETH_MAP0_DMACTDRLR   DMACTDRLR_TypeDef DMACTDRLR
#define ETH_MAP0_DMACRDRLR   DMACRDRLR_TypeDef DMACRDRLR
#define ETH_MAP0_DMACIER     DMACIER_TypeDef DMACIER
#define ETH_MAP0_DMACRIWTR   DMACRIWTR_TypeDef DMACRIWTR
#define ETH_MAP0_DMACSFCSR   uint32_t DMACSFCSR
#define ETH_MAP0_DMACCATDR   DMACCATDR_TypeDef DMACCATDR
#define ETH_MAP0_DMACCARDR   DMACCARDR_TypeDef DMACCARDR
#define ETH_MAP0_DMACCATBR   DMACCATBR_TypeDef DMACCATBR
#define ETH_MAP0_DMACCARBR   DMACCARBR_TypeDef DMACCARBR
#define ETH_MAP0_DMACSR      DMACSR_TypeDef DMACSR
#define ETH_MAP0_DMACMFCR    DMACMFCR_TypeDef DMACMFCR
#else
#define ETH_MACCR_0_DR
#define ETH_MACCR_0_ACS
#define ETH_MACCR_0_CST
#define ETH_MACCR_0_IPG
#define ETH_MACCR_0_IPC
#define ETH_MACCR_0_SARC
#define ETH_MACCR_0_ARP
#define ETH_MAP1_MACECR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MACPFR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MACWTR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MACHT0R __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MACHT1R __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MACVTR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MACVHTR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACVIR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACIVIR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACTFCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACRFCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACISR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACIER __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACRXTXSR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACPCSR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACRWKPFR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACLCSR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACLTCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACLETR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MAC1USTCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MACVR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACDR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACHWF0R __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACHWF1R __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACHWF2R __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACMDIOAR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACMDIODR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACARPAR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MACA0HR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MACA0LR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MACA1HR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MACA1LR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MACA2HR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MACA2LR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MACA3HR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MACA3LR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MMCCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MMCRIR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MMCTIR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MMCRIMR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_MMCTIMR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCTSCGPR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCTMCGPR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCTPCGR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCRCRCEPR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCRAEPR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCRUPGR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCTLPIMSTR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCTLPITCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCRLPIMSTR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MMCRLPITCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACL3L4C0R __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACL4A0R __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACL3A00R __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACL3A10R __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACL3A20R __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACL3A30R __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACL3L4C1R __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACL4A1R __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACL3A01R __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACL3A11R __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACL3A21R __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACL3A31R __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACTSCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACSSIR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACSTSR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACSTNR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACSTSUR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACSTNUR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACTSAR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACTSSR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACTTSSNR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACTTSSSR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACACR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACATSNR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACATSSR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACTSIACR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACTSEACR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACTSICNR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACTSECNR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACPPSCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACPPSTTSR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACPPSTTNR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACPPSIR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACPPSWR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACPOCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACSPI0R __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACSPI1R __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACSPI2R __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MACLMIR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MTLOMR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MTLISR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MTLTQOMR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MTLTQUR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MTLTQDR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MTLQICSR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MTLRQOMR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MTLRQMPOCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_MTLRQDR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_DMAMR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_DMASBMR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_DMAISR __SOOL_PERIPH_PADDING_4
#define ETH_MAP1_DMADSR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACTCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACRCR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACTDLAR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACRDLAR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACTDTPR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACRDTPR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACTDRLR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACRDRLR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACIER __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACRIWTR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACSFCSR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACCATDR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACCARDR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACCATBR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACCARBR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACSR __SOOL_PERIPH_PADDING_4
#define ETH_MAP0_DMACMFCR __SOOL_PERIPH_PADDING_4
#endif

#define ETH_MACAHR
#define ETH_MACALR
#define ETH_MACCR
#define ETH_MMCCR
#define ETH_MMCRIMR
#define ETH_MMCRIR
#define ETH_MMCTIMR
#define ETH_MMCTIR

#if defined(STM32F207xx ) || defined(STM32F217xx ) || defined(STM32F407xx ) || defined(STM32F417xx ) ||\
    defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F469xx ) || defined(STM32F479xx ) 
#define ETH_MACDBGR_0_TFWA   TFWA                 // 1 bits @ 22
#else
#define ETH_MACDBGR_0_TFWA
#endif

#if defined(STM32F745xx ) || defined(STM32F746xx ) || defined(STM32F756xx ) || defined(STM32F765xx ) ||\
    defined(STM32F767xx ) || defined(STM32F769xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) 
#define ETH_MACDBGR_1
#endif

//endregion

namespace sool
{
	namespace core
	{
		class ETH
		{
			//SOOL-ETH-ENUMS
			
			public :
			
			#ifdef ETH_DMABMR
			struct DMABMR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SR                   :1;
					uint32_t DA                   :1;
					uint32_t DSL                  :5;
					uint32_t ETH_DMABMR_EDE       :1;
					uint32_t PBL                  :6;
					uint32_t RTPR                 :2;
					uint32_t FB                   :1;
					uint32_t RDP                  :6;
					uint32_t USP                  :1;
					uint32_t FPM                  :1;
					uint32_t AAB                  :1;
					uint32_t                      :6;
			
				//SOOL-ETH_DMABMR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACCARBR
			struct DMACCARBR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CURRBUFAPTR          :32;
			
				//SOOL-ETH_DMACCARBR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACCARDR
			struct DMACCARDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CURRDESAPTR          :32;
			
				//SOOL-ETH_DMACCARDR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACCATBR
			struct DMACCATBR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CURTBUFAPTR          :32;
			
				//SOOL-ETH_DMACCATBR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACCATDR
			struct DMACCATDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CURTDESAPTR          :32;
			
				//SOOL-ETH_DMACCATDR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACCR
			struct DMACCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MSS                  :14;
					uint32_t                      :2;
					uint32_t DMACC8PBL            :1;
					uint32_t                      :1;
					uint32_t DSL                  :3;
					uint32_t                      :11;
			
				//SOOL-ETH_DMACCR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACHRBAR
			struct DMACHRBAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t HRBAP                :32;
			
				//SOOL-ETH_DMACHRBAR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACHRDR
			struct DMACHRDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t HRDAP                :32;
			
				//SOOL-ETH_DMACHRDR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACHTBAR
			struct DMACHTBAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t HTBAP                :32;
			
				//SOOL-ETH_DMACHTBAR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACHTDR
			struct DMACHTDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t HTDAP                :32;
			
				//SOOL-ETH_DMACHTDR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACIER
			struct DMACIER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TIE                  :1;
					uint32_t TXSE                 :1;
					uint32_t TBUE                 :1;
					uint32_t                      :3;
					uint32_t RIE                  :1;
					uint32_t RBUE                 :1;
					uint32_t RSE                  :1;
					uint32_t RWTE                 :1;
					uint32_t ETIE                 :1;
					uint32_t ERIE                 :1;
					uint32_t FBEE                 :1;
					uint32_t CDEE                 :1;
					uint32_t AIE                  :1;
					uint32_t NIE                  :1;
					uint32_t                      :16;
			
				//SOOL-ETH_DMACIER-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACMFCR
			struct DMACMFCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MFC                  :11;
					uint32_t                      :4;
					uint32_t MFCO                 :1;
					uint32_t                      :16;
			
				//SOOL-ETH_DMACMFCR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACRCR
			struct DMACRCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SR                   :1;
					uint32_t RBSZ                 :14;
					uint32_t                      :1;
					uint32_t RPBL                 :6;
					uint32_t                      :9;
					uint32_t RPF                  :1;
			
				//SOOL-ETH_DMACRCR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACRDLAR
			struct DMACRDLAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :2;
					uint32_t RDESLA               :30;
			
				//SOOL-ETH_DMACRDLAR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACRDRLR
			struct DMACRDRLR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RDRL                 :10;
					uint32_t                      :22;
			
				//SOOL-ETH_DMACRDRLR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACRDTPR
			struct DMACRDTPR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :2;
					uint32_t RDT                  :30;
			
				//SOOL-ETH_DMACRDTPR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACRIWTR
			struct DMACRIWTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RWT                  :8;
					uint32_t                      :24;
			
				//SOOL-ETH_DMACRIWTR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACSR
			struct DMACSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TI                   :1;
					uint32_t TPS                  :1;
					uint32_t TBU                  :1;
					uint32_t                      :3;
					uint32_t RI                   :1;
					uint32_t RBU                  :1;
					uint32_t RPS                  :1;
					uint32_t RWT                  :1;
					uint32_t ETI                  :1;
					uint32_t ERI                  :1;
					uint32_t FBE                  :1;
					uint32_t CDE                  :1;
					uint32_t AIS                  :1;
					uint32_t NIS                  :1;
					uint32_t TEB                  :3;
					uint32_t REB                  :3;
					uint32_t                      :10;
			
				//SOOL-ETH_DMACSR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACTCR
			struct DMACTCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ST                   :1;
					uint32_t                      :3;
					uint32_t OSP                  :1;
					uint32_t                      :7;
					uint32_t TSE                  :1;
					uint32_t                      :3;
					uint32_t TPBL                 :6;
					uint32_t                      :10;
			
				//SOOL-ETH_DMACTCR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACTDLAR
			struct DMACTDLAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :2;
					uint32_t TDESLA               :30;
			
				//SOOL-ETH_DMACTDLAR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACTDRLR
			struct DMACTDRLR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TDRL                 :10;
					uint32_t                      :22;
			
				//SOOL-ETH_DMACTDRLR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMACTDTPR
			struct DMACTDTPR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :2;
					uint32_t TDT                  :30;
			
				//SOOL-ETH_DMACTDTPR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMADSR
			struct DMADSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :8;
					uint32_t RPS                  :4;
					uint32_t TPS                  :4;
					uint32_t                      :16;
			
				//SOOL-ETH_DMADSR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMAIER
			struct DMAIER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TIE                  :1;
					uint32_t TPSIE                :1;
					uint32_t TBUIE                :1;
					uint32_t TJTIE                :1;
					uint32_t ROIE                 :1;
					uint32_t TUIE                 :1;
					uint32_t RIE                  :1;
					uint32_t RBUIE                :1;
					uint32_t RPSIE                :1;
					uint32_t RWTIE                :1;
					uint32_t ETIE                 :1;
					uint32_t                      :2;
					uint32_t FBEIE                :1;
					uint32_t ERIE                 :1;
					uint32_t AISE                 :1;
					uint32_t NISE                 :1;
					uint32_t                      :15;
			
				//SOOL-ETH_DMAIER-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMAISR
			struct DMAISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DMACIS               :1;
					uint32_t                      :15;
					uint32_t MTLIS                :1;
					uint32_t MACIS                :1;
					uint32_t                      :14;
			
				//SOOL-ETH_DMAISR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMAMFBOCR
			struct DMAMFBOCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MFC                  :16;
					uint32_t OMFC                 :1;
					uint32_t MFA                  :11;
					uint32_t OFOC                 :1;
					uint32_t                      :3;
			
				//SOOL-ETH_DMAMFBOCR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMAMR
			struct DMAMR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SWR                  :1;
					uint32_t DA                   :1;
					uint32_t                      :9;
					uint32_t TXPR                 :1;
					uint32_t PR                   :3;
					uint32_t                      :1;
					uint32_t INTM                 :2;
					uint32_t                      :14;
			
				//SOOL-ETH_DMAMR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMAOMR
			struct DMAOMR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :1;
					uint32_t SR                   :1;
					uint32_t OSF                  :1;
					uint32_t RTC                  :2;
					uint32_t                      :1;
					uint32_t FUGF                 :1;
					uint32_t FEF                  :1;
					uint32_t                      :5;
					uint32_t ST                   :1;
					uint32_t TTC                  :3;
					uint32_t                      :3;
					uint32_t FTF                  :1;
					uint32_t TSF                  :1;
					uint32_t                      :2;
					uint32_t DFRF                 :1;
					uint32_t RSF                  :1;
					uint32_t DTCEFD               :1;
					uint32_t                      :5;
			
				//SOOL-ETH_DMAOMR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMARDLAR
			struct DMARDLAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SRL                  :32;
			
				//SOOL-ETH_DMARDLAR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMARPDR
			struct DMARPDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RPD                  :32;
			
				//SOOL-ETH_DMARPDR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMASBMR
			struct DMASBMR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FB                   :1;
					uint32_t                      :11;
					uint32_t AAL                  :1;
					uint32_t                      :1;
					uint32_t MB                   :1;
					uint32_t RB                   :1;
					uint32_t                      :16;
			
				//SOOL-ETH_DMASBMR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMASR
			struct DMASR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TS                   :1;
					uint32_t TPSS                 :1;
					uint32_t TBUS                 :1;
					uint32_t TJTS                 :1;
					uint32_t ROS                  :1;
					uint32_t TUS                  :1;
					uint32_t RS                   :1;
					uint32_t RBUS                 :1;
					uint32_t RPSS                 :1;
					uint32_t RWTS                 :1;
					uint32_t ETS                  :1;
					uint32_t                      :2;
					uint32_t FBES                 :1;
					uint32_t ERS                  :1;
					uint32_t AIS                  :1;
					uint32_t NIS                  :1;
					uint32_t RPS                  :3;
					uint32_t TPS                  :3;
					uint32_t EBS                  :3;
					uint32_t                      :1;
					uint32_t MMCS                 :1;
					uint32_t PMTS                 :1;
					uint32_t TSTS                 :1;
					uint32_t                      :2;
			
				//SOOL-ETH_DMASR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMATDLAR
			struct DMATDLAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t STL                  :32;
			
				//SOOL-ETH_DMATDLAR-DECLARATION
			};
			#endif
			
			#ifdef ETH_DMATPDR
			struct DMATPDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TPD                  :32;
			
				//SOOL-ETH_DMATPDR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MAC1USTCR
			struct MAC1USTCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TIC1USCNTR           :12;
					uint32_t                      :20;
			
				//SOOL-ETH_MAC1USTCR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACAHR
			struct MACAHR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MACAH                :16;
					uint32_t                      :8;
					uint32_t MBC                  :6;
					uint32_t SA                   :1;
					uint32_t AE                   :1;
			
				//SOOL-ETH_MACAHR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACALR
			struct MACALR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MACAL                :32;
			
				//SOOL-ETH_MACALR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACCR
			struct MACCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t                      :2;
						uint32_t ETH_MACCR_0_RE       :1;
						uint32_t ETH_MACCR_0_TE       :1;
						uint32_t DC                   :1;
						uint32_t BL                   :2;
						uint32_t ETH_MACCR_0_APCS     :1;
						uint32_t ETH_MACCR_0_DR       :1;
						uint32_t ETH_MACCR_0_RD       :1;
						uint32_t ETH_MACCR_0_IPCO     :1;
						uint32_t ETH_MACCR_0_DM       :1;
						uint32_t LM                   :1;
						uint32_t ETH_MACCR_0_ROD      :1;
						uint32_t FES                  :1;
						uint32_t                      :1;
						uint32_t ETH_MACCR_0_CSD      :1;
						uint32_t ETH_MACCR_0_IFG      :3;
						uint32_t ETH_MACCR_0_ACS      :1;
						uint32_t ETH_MACCR_0_CST      :1;
						uint32_t ETH_MACCR_0_JD       :1;
						uint32_t ETH_MACCR_0_WD       :1;
						uint32_t ETH_MACCR_0_IPG      :3;
						uint32_t ETH_MACCR_0_IPC      :1;
						uint32_t ETH_MACCR_0_SARC     :3;
						uint32_t ETH_MACCR_0_ARP      :1;
					};
					#ifdef ETH_MACCR_1
					struct
					{
						uint32_t RE                   :1;
						uint32_t TE                   :1;
						uint32_t PRELEN               :2;
						uint32_t                      :5;
						uint32_t DCRS                 :1;
						uint32_t DO                   :1;
						uint32_t ECRSFD               :1;
						uint32_t                      :1;
						uint32_t DM                   :1;
						uint32_t                      :2;
						uint32_t JE                   :1;
						uint32_t JD                   :1;
						uint32_t                      :1;
						uint32_t WD                   :1;
						uint32_t                      :2;
						uint32_t S2KP                 :1;
						uint32_t GPSLCE               :1;
						uint32_t                      :8;
					};
					#endif
				};
				//SOOL-ETH_MACCR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACDBGR
			struct MACDBGR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t MMRPEA               :1;
						uint32_t MSFRWCS              :2;
						uint32_t                      :1;
						uint32_t RFWRA                :1;
						uint32_t RFRCS                :2;
						uint32_t                      :1;
						uint32_t RFFL                 :2;
						uint32_t                      :6;
						uint32_t MMTEA                :1;
						uint32_t MTFCS                :2;
						uint32_t MTP                  :1;
						uint32_t TFRS                 :2;
						uint32_t ETH_MACDBGR_0_TFWA   :1;
						uint32_t                      :1;
						uint32_t TFNE                 :1;
						uint32_t TFF                  :1;
						uint32_t                      :6;
					};
					#ifdef ETH_MACDBGR_1
					struct
					{
						uint32_t                      :22;
						uint32_t TPWA                 :1;
						uint32_t                      :9;
					};
					#endif
				};
				//SOOL-ETH_MACDBGR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACDR
			struct MACDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RPESTS               :1;
					uint32_t RFCFCSTS             :2;
					uint32_t                      :13;
					uint32_t TPESTS               :1;
					uint32_t TFCSTS               :2;
					uint32_t                      :13;
			
				//SOOL-ETH_MACDR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACECR
			struct MACECR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t GPSL                 :14;
					uint32_t                      :2;
					uint32_t DCRCC                :1;
					uint32_t SPEN                 :1;
					uint32_t USP                  :1;
					uint32_t                      :5;
					uint32_t EIPGEN               :1;
					uint32_t EIPG                 :5;
					uint32_t                      :2;
			
				//SOOL-ETH_MACECR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACFCR
			struct MACFCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FCBBPA               :1;
					uint32_t TFCE                 :1;
					uint32_t RFCE                 :1;
					uint32_t UPFD                 :1;
					uint32_t PLT                  :2;
					uint32_t                      :1;
					uint32_t ZQPD                 :1;
					uint32_t                      :8;
					uint32_t PT                   :16;
			
				//SOOL-ETH_MACFCR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACFFR
			struct MACFFR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PM                   :1;
					uint32_t HU                   :1;
					uint32_t HM                   :1;
					uint32_t DAIF                 :1;
					uint32_t PAM                  :1;
					uint32_t BFD                  :1;
					uint32_t PCF                  :2;
					uint32_t SAIF                 :1;
					uint32_t SAF                  :1;
					uint32_t HPF                  :1;
					uint32_t                      :20;
					uint32_t RA                   :1;
			
				//SOOL-ETH_MACFFR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACHTHR
			struct MACHTHR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t HTH                  :32;
			
				//SOOL-ETH_MACHTHR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACHTLR
			struct MACHTLR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t HTL                  :32;
			
				//SOOL-ETH_MACHTLR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACHWF0R
			struct MACHWF0R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MIISEL               :1;
					uint32_t GMIISEL              :1;
					uint32_t HDSEL                :1;
					uint32_t PCSSEL               :1;
					uint32_t VLHASH               :1;
					uint32_t SMASEL               :1;
					uint32_t RWKSEL               :1;
					uint32_t MGKSEL               :1;
					uint32_t MMCSEL               :1;
					uint32_t ARPOFFSEL            :1;
					uint32_t                      :2;
					uint32_t TSSEL                :1;
					uint32_t EEESEL               :1;
					uint32_t TXCOESEL             :1;
					uint32_t                      :1;
					uint32_t RXCOESEL             :1;
					uint32_t                      :1;
					uint32_t ADDMACADRSEL         :5;
					uint32_t MACADR32SEL          :1;
					uint32_t MACADR64SEL          :1;
					uint32_t TSSTSSEL             :2;
					uint32_t SAVLANINS            :1;
					uint32_t ACTPHYSEL            :3;
					uint32_t                      :1;
			
				//SOOL-ETH_MACHWF0R-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACHWF1R
			struct MACHWF1R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RXFIFOSIZE           :5;
					uint32_t                      :1;
					uint32_t TXFIFOSIZE           :5;
					uint32_t OSTEN                :1;
					uint32_t PTOEN                :1;
					uint32_t ADVTHWORD            :1;
					uint32_t ADDR64               :2;
					uint32_t DCBEN                :1;
					uint32_t SPHEN                :1;
					uint32_t TSOEN                :1;
					uint32_t DBGMEMA              :1;
					uint32_t AVSEL                :1;
					uint32_t                      :3;
					uint32_t HASHTBLSZ            :2;
					uint32_t                      :1;
					uint32_t L3L4FNUM             :4;
					uint32_t                      :1;
			
				//SOOL-ETH_MACHWF1R-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACHWF2R
			struct MACHWF2R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RXQCNT               :4;
					uint32_t                      :2;
					uint32_t TXQCNT               :4;
					uint32_t                      :3;
					uint32_t RXCHCNT              :3;
					uint32_t                      :2;
					uint32_t TXCHCNT              :4;
					uint32_t                      :2;
					uint32_t PPSOUTNUM            :3;
					uint32_t                      :1;
					uint32_t AUXSNAPNUM           :3;
					uint32_t                      :1;
			
				//SOOL-ETH_MACHWF2R-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACIER
			struct MACIER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :3;
					uint32_t PHYIE                :1;
					uint32_t PMTIE                :1;
					uint32_t LPIIE                :1;
					uint32_t                      :6;
					uint32_t TSIE                 :1;
					uint32_t TXSTSIE              :1;
					uint32_t RXSTSIE              :1;
					uint32_t                      :17;
			
				//SOOL-ETH_MACIER-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACIMR
			struct MACIMR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :3;
					uint32_t PMTIM                :1;
					uint32_t                      :5;
					uint32_t TSTIM                :1;
					uint32_t                      :22;
			
				//SOOL-ETH_MACIMR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACISR
			struct MACISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :3;
					uint32_t PHYIS                :1;
					uint32_t PMTIS                :1;
					uint32_t LPIIS                :1;
					uint32_t                      :2;
					uint32_t MMCIS                :1;
					uint32_t MMCRXIS              :1;
					uint32_t MMCTXIS              :1;
					uint32_t                      :1;
					uint32_t TSIS                 :1;
					uint32_t TXSTSIS              :1;
					uint32_t RXSTSIS              :1;
					uint32_t                      :17;
			
				//SOOL-ETH_MACISR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACIVIR
			struct MACIVIR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t VLT                  :16;
					uint32_t VLC                  :2;
					uint32_t VLP                  :1;
					uint32_t CSVL                 :1;
					uint32_t VLTI                 :1;
					uint32_t                      :11;
			
				//SOOL-ETH_MACIVIR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACL3L4CR
			struct MACL3L4CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t L3PEN                :1;
					uint32_t                      :1;
					uint32_t L3SAM                :1;
					uint32_t L3SAIM               :1;
					uint32_t L3DAM                :1;
					uint32_t L3DAIM               :1;
					uint32_t L3HSBM               :5;
					uint32_t L3HDBM               :5;
					uint32_t L4PEN                :1;
					uint32_t                      :1;
					uint32_t L4SPM                :1;
					uint32_t L4SPIM               :1;
					uint32_t L4DPM                :1;
					uint32_t L4DPIM               :1;
					uint32_t                      :10;
			
				//SOOL-ETH_MACL3L4CR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACL4AR
			struct MACL4AR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t L4SP                 :16;
					uint32_t L4DP                 :16;
			
				//SOOL-ETH_MACL4AR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACLCSR
			struct MACLCSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TLPIEN               :1;
					uint32_t TLPIEX               :1;
					uint32_t RLPIEN               :1;
					uint32_t RLPIEX               :1;
					uint32_t                      :4;
					uint32_t TLPIST               :1;
					uint32_t RLPIST               :1;
					uint32_t                      :6;
					uint32_t LPIEN                :1;
					uint32_t PLS                  :1;
					uint32_t                      :1;
					uint32_t LPITXA               :1;
					uint32_t LPITE                :1;
					uint32_t LPITCSE              :1;
					uint32_t                      :10;
			
				//SOOL-ETH_MACLCSR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACLETR
			struct MACLETR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t LPIET                :20;
					uint32_t                      :12;
			
				//SOOL-ETH_MACLETR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACLTCR
			struct MACLTCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TWT                  :16;
					uint32_t LST                  :10;
					uint32_t                      :6;
			
				//SOOL-ETH_MACLTCR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACMDIOAR
			struct MACMDIOAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MB                   :1;
					uint32_t C45E                 :1;
					uint32_t MOC                  :2;
					uint32_t SKAP                 :1;
					uint32_t                      :3;
					uint32_t CR                   :4;
					uint32_t NTC                  :3;
					uint32_t                      :1;
					uint32_t RDA                  :5;
					uint32_t PA                   :5;
					uint32_t BTB                  :1;
					uint32_t PSE                  :1;
					uint32_t                      :4;
			
				//SOOL-ETH_MACMDIOAR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACMDIODR
			struct MACMDIODR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MD                   :16;
					uint32_t RA                   :16;
			
				//SOOL-ETH_MACMDIODR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACMIIAR
			struct MACMIIAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MB                   :1;
					uint32_t MW                   :1;
					uint32_t CR                   :3;
					uint32_t                      :1;
					uint32_t MR                   :5;
					uint32_t PA                   :5;
					uint32_t                      :16;
			
				//SOOL-ETH_MACMIIAR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACMIIDR
			struct MACMIIDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MD                   :16;
					uint32_t                      :16;
			
				//SOOL-ETH_MACMIIDR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACPCSR
			struct MACPCSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PWRDWN               :1;
					uint32_t MGKPKTEN             :1;
					uint32_t RWKPKTEN             :1;
					uint32_t                      :2;
					uint32_t MGKPRCVD             :1;
					uint32_t RWKPRCVD             :1;
					uint32_t                      :2;
					uint32_t GLBLUCAST            :1;
					uint32_t RWKPFE               :1;
					uint32_t                      :13;
					uint32_t RWKPTR               :5;
					uint32_t                      :2;
					uint32_t RWKFILTRST           :1;
			
				//SOOL-ETH_MACPCSR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACPFR
			struct MACPFR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PR                   :1;
					uint32_t HUC                  :1;
					uint32_t HMC                  :1;
					uint32_t DAIF                 :1;
					uint32_t PM                   :1;
					uint32_t DBF                  :1;
					uint32_t PCF                  :2;
					uint32_t SAIF                 :1;
					uint32_t SAF                  :1;
					uint32_t HPF                  :1;
					uint32_t                      :5;
					uint32_t VTFE                 :1;
					uint32_t                      :3;
					uint32_t IPFE                 :1;
					uint32_t DNTU                 :1;
					uint32_t                      :9;
					uint32_t RA                   :1;
			
				//SOOL-ETH_MACPFR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACPMTCSR
			struct MACPMTCSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PD                   :1;
					uint32_t MPE                  :1;
					uint32_t WFE                  :1;
					uint32_t                      :2;
					uint32_t MPR                  :1;
					uint32_t WFR                  :1;
					uint32_t                      :2;
					uint32_t GU                   :1;
					uint32_t                      :21;
					uint32_t WFFRPR               :1;
			
				//SOOL-ETH_MACPMTCSR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACRFCR
			struct MACRFCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RFE                  :1;
					uint32_t UP                   :1;
					uint32_t                      :30;
			
				//SOOL-ETH_MACRFCR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACRWKPFR
			struct MACRWKPFR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :32;
			
				//SOOL-ETH_MACRWKPFR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACRWUFFR
			struct MACRWUFFR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t D                    :32;
			
				//SOOL-ETH_MACRWUFFR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACRXTXSR
			struct MACRXTXSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TJT                  :1;
					uint32_t NCARR                :1;
					uint32_t LCARR                :1;
					uint32_t EXDEF                :1;
					uint32_t LCOL                 :1;
					uint32_t EXCOL                :1;
					uint32_t                      :2;
					uint32_t RWT                  :1;
					uint32_t                      :23;
			
				//SOOL-ETH_MACRXTXSR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACSR
			struct MACSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :3;
					uint32_t PMTS                 :1;
					uint32_t MMCS                 :1;
					uint32_t MMMCRS               :1;
					uint32_t MMCTS                :1;
					uint32_t                      :2;
					uint32_t TSTS                 :1;
					uint32_t                      :22;
			
				//SOOL-ETH_MACSR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACTFCR
			struct MACTFCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FCB                  :1;
					uint32_t TFE                  :1;
					uint32_t                      :2;
					uint32_t PLT                  :3;
					uint32_t DZPQ                 :1;
					uint32_t                      :8;
					uint32_t PT                   :16;
			
				//SOOL-ETH_MACTFCR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACVHTR
			struct MACVHTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t VLHT                 :16;
					uint32_t                      :16;
			
				//SOOL-ETH_MACVHTR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACVIR
			struct MACVIR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t VLT                  :16;
					uint32_t VLC                  :2;
					uint32_t VLP                  :1;
					uint32_t CSVL                 :1;
					uint32_t VLTI                 :1;
					uint32_t                      :11;
			
				//SOOL-ETH_MACVIR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACVLANTR
			struct MACVLANTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t VLANTI               :16;
					uint32_t VLANTC               :1;
					uint32_t                      :15;
			
				//SOOL-ETH_MACVLANTR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACVR
			struct MACVR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SNPSVER              :8;
					uint32_t USERVER              :8;
					uint32_t                      :16;
			
				//SOOL-ETH_MACVR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACVTR
			struct MACVTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t VL                   :16;
					uint32_t ETV                  :1;
					uint32_t VTIM                 :1;
					uint32_t ESVL                 :1;
					uint32_t ERSVLM               :1;
					uint32_t DOVLTC               :1;
					uint32_t EVLS                 :2;
					uint32_t                      :1;
					uint32_t EVLRXS               :1;
					uint32_t VTHM                 :1;
					uint32_t EDVLP                :1;
					uint32_t ERIVLT               :1;
					uint32_t EIVLS                :2;
					uint32_t                      :1;
					uint32_t EIVLRXS              :1;
			
				//SOOL-ETH_MACVTR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MACWTR
			struct MACWTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t WTO                  :4;
					uint32_t                      :4;
					uint32_t PWE                  :1;
					uint32_t                      :23;
			
				//SOOL-ETH_MACWTR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MMCCR
			struct MMCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CR                   :1;
					uint32_t CSR                  :1;
					uint32_t ROR                  :1;
					uint32_t MCF                  :1;
					uint32_t ETH_MMCCR_MCP        :1;
					uint32_t ETH_MMCCR_MCFHP      :1;
					uint32_t                      :26;
			
				//SOOL-ETH_MMCCR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MMCRFAECR
			struct MMCRFAECR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RFAEC                :32;
			
				//SOOL-ETH_MMCRFAECR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MMCRFCECR
			struct MMCRFCECR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RFCEC                :32;
			
				//SOOL-ETH_MMCRFCECR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MMCRGUFCR
			struct MMCRGUFCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RGUFC                :32;
			
				//SOOL-ETH_MMCRGUFCR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MMCRIMR
			struct MMCRIMR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :5;
					uint32_t RFCEM                :1;
					uint32_t RFAEM                :1;
					uint32_t                      :10;
					uint32_t RGUFM                :1;
					uint32_t                      :14;
			
				//SOOL-ETH_MMCRIMR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MMCRIR
			struct MMCRIR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :5;
					uint32_t RFCES                :1;
					uint32_t RFAES                :1;
					uint32_t                      :10;
					uint32_t RGUFS                :1;
					uint32_t                      :14;
			
				//SOOL-ETH_MMCRIR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MMCTGFCR
			struct MMCTGFCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TGFC                 :32;
			
				//SOOL-ETH_MMCTGFCR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MMCTGFMSCCR
			struct MMCTGFMSCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TGFMSCC              :32;
			
				//SOOL-ETH_MMCTGFMSCCR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MMCTGFSCCR
			struct MMCTGFSCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TGFSCC               :32;
			
				//SOOL-ETH_MMCTGFSCCR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MMCTIMR
			struct MMCTIMR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :14;
					uint32_t TGFSCM               :1;
					uint32_t TGFMSCM              :1;
					uint32_t                      :5;
					uint32_t TGFM                 :1;
					uint32_t                      :10;
			
				//SOOL-ETH_MMCTIMR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MMCTIR
			struct MMCTIR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :14;
					uint32_t TGFSCS               :1;
					uint32_t TGFMSCS              :1;
					uint32_t                      :5;
					uint32_t TGFS                 :1;
					uint32_t                      :10;
			
				//SOOL-ETH_MMCTIR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MTLISR
			struct MTLISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t QIS                  :1;
					uint32_t                      :15;
					uint32_t MACIS                :1;
					uint32_t                      :15;
			
				//SOOL-ETH_MTLISR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MTLOMR
			struct MTLOMR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :8;
					uint32_t CNTPRST              :1;
					uint32_t CNTCLR               :1;
					uint32_t                      :22;
			
				//SOOL-ETH_MTLOMR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MTLQICSR
			struct MTLQICSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TXUNFIS              :1;
					uint32_t                      :7;
					uint32_t TXUIE                :1;
					uint32_t                      :7;
					uint32_t RXOVFIS              :1;
					uint32_t                      :7;
					uint32_t RXOIE                :1;
					uint32_t                      :7;
			
				//SOOL-ETH_MTLQICSR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MTLRQDR
			struct MTLRQDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RWCSTS               :1;
					uint32_t RRCSTS               :2;
					uint32_t                      :1;
					uint32_t RXQSTS               :2;
					uint32_t                      :10;
					uint32_t PRXQ                 :14;
					uint32_t                      :2;
			
				//SOOL-ETH_MTLRQDR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MTLRQMPOCR
			struct MTLRQMPOCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t OVFPKTCNT            :11;
					uint32_t OVFCNTOVF            :1;
					uint32_t                      :4;
					uint32_t MISPKTCNT            :11;
					uint32_t MISCNTOVF            :1;
					uint32_t                      :4;
			
				//SOOL-ETH_MTLRQMPOCR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MTLRQOMR
			struct MTLRQOMR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RTC                  :2;
					uint32_t                      :1;
					uint32_t FUP                  :1;
					uint32_t FEP                  :1;
					uint32_t RSF                  :1;
					uint32_t DISTCPEF             :1;
					uint32_t                      :25;
			
				//SOOL-ETH_MTLRQOMR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MTLTQDR
			struct MTLTQDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TXQPAUSED            :1;
					uint32_t TRCSTS               :2;
					uint32_t TWCSTS               :1;
					uint32_t TXQSTS               :1;
					uint32_t TXSTSFSTS            :1;
					uint32_t                      :10;
					uint32_t PTXQ                 :3;
					uint32_t                      :1;
					uint32_t STXSTSF              :3;
					uint32_t                      :9;
			
				//SOOL-ETH_MTLTQDR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MTLTQOMR
			struct MTLTQOMR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FTQ                  :1;
					uint32_t TSF                  :1;
					uint32_t                      :2;
					uint32_t TTC                  :3;
					uint32_t                      :25;
			
				//SOOL-ETH_MTLTQOMR-DECLARATION
			};
			#endif
			
			#ifdef ETH_MTLTQUR
			struct MTLTQUR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t UFPKTCNT             :11;
					uint32_t UFCNTOVF             :1;
					uint32_t                      :20;
			
				//SOOL-ETH_MTLTQUR-DECLARATION
			};
			#endif
			
			#ifdef ETH_PTPSSIR
			struct PTPSSIR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t STSSI                :8;
					uint32_t                      :24;
			
				//SOOL-ETH_PTPSSIR-DECLARATION
			};
			#endif
			
			#ifdef ETH_PTPTSAR
			struct PTPTSAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TSA                  :32;
			
				//SOOL-ETH_PTPTSAR-DECLARATION
			};
			#endif
			
			#ifdef ETH_PTPTSCR
			struct PTPTSCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TSE                  :1;
					uint32_t TSFCU                :1;
					uint32_t TSSTI                :1;
					uint32_t TSSTU                :1;
					uint32_t TSITE                :1;
					uint32_t TSARU                :1;
					uint32_t                      :10;
					uint32_t ETH_PTPTSCR_TSCNT    :2;
					uint32_t                      :14;
			
				//SOOL-ETH_PTPTSCR-DECLARATION
			};
			#endif
			
			#ifdef ETH_PTPTSHR
			struct PTPTSHR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t STS                  :32;
			
				//SOOL-ETH_PTPTSHR-DECLARATION
			};
			#endif
			
			#ifdef ETH_PTPTSHUR
			struct PTPTSHUR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TSUS                 :32;
			
				//SOOL-ETH_PTPTSHUR-DECLARATION
			};
			#endif
			
			#ifdef ETH_PTPTSLR
			struct PTPTSLR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t STSS                 :31;
					uint32_t STPNS                :1;
			
				//SOOL-ETH_PTPTSLR-DECLARATION
			};
			#endif
			
			#ifdef ETH_PTPTSLUR
			struct PTPTSLUR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TSUSS                :31;
					uint32_t TSUPNS               :1;
			
				//SOOL-ETH_PTPTSLUR-DECLARATION
			};
			#endif
			
			#ifdef ETH_PTPTSSR
			struct PTPTSSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :4;
					uint32_t TSSO                 :1;
					uint32_t TSTTR                :1;
					uint32_t                      :2;
					uint32_t TSSARFE              :1;
					uint32_t TSSSR                :1;
					uint32_t TSPTPPSV2E           :1;
					uint32_t TSSPTPOEFE           :1;
					uint32_t TSSIPV6FE            :1;
					uint32_t TSSIPV4FE            :1;
					uint32_t TSSEME               :1;
					uint32_t TSSMRME              :1;
					uint32_t                      :16;
			
				//SOOL-ETH_PTPTSSR-DECLARATION
			};
			#endif
			
			#ifdef ETH_PTPTTHR
			struct PTPTTHR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TTSH                 :32;
			
				//SOOL-ETH_PTPTTHR-DECLARATION
			};
			#endif
			
			#ifdef ETH_PTPTTLR
			struct PTPTTLR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TTSL                 :32;
			
				//SOOL-ETH_PTPTTLR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					MACCR_TypeDef MACCR; // @0x000
					ETH_MAP0_MACFFR;     // @0x004
					ETH_MAP0_MACHTHR;    // @0x008
					ETH_MAP0_MACHTLR;    // @0x00c
					ETH_MAP0_MACMIIAR;   // @0x010
					ETH_MAP0_MACMIIDR;   // @0x014
					ETH_MAP0_MACFCR;     // @0x018
					ETH_MAP0_MACVLANTR;  // @0x01c
					__SOOL_PERIPH_PADDING_8;
					ETH_MAP0_MACRWUFFR;  // @0x028
					ETH_MAP0_MACPMTCSR;  // @0x02c
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_MACDBGR;    // @0x034
					ETH_MAP0_MACSR;      // @0x038
					ETH_MAP0_MACIMR;     // @0x03c
					ETH_MAP0_MACA0HR;    // @0x040
					ETH_MAP0_MACA0LR;    // @0x044
					ETH_MAP0_MACA1HR;    // @0x048
					ETH_MAP0_MACA1LR;    // @0x04c
					ETH_MAP0_MACA2HR;    // @0x050
					ETH_MAP0_MACA2LR;    // @0x054
					ETH_MAP0_MACA3HR;    // @0x058
					ETH_MAP0_MACA3LR;    // @0x05c
					ETH_MAP0_MACVIR;     // @0x060
					ETH_MAP0_MACIVIR;    // @0x064
					__SOOL_PERIPH_PADDING_8;
					ETH_MAP0_MACTFCR;    // @0x070
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_MACRFCR;    // @0x090
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_MACISR;     // @0x0b0
					ETH_MAP0_MACIER;     // @0x0b4
					ETH_MAP0_MACRXTXSR;  // @0x0b8
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_MACPCSR;    // @0x0c0
					ETH_MAP0_MACRWKPFR;  // @0x0c4
					__SOOL_PERIPH_PADDING_8;
					ETH_MAP0_MACLCSR;    // @0x0d0
					ETH_MAP0_MACLTCR;    // @0x0d4
					ETH_MAP0_MACLETR;    // @0x0d8
					ETH_MAP0_MAC1USTCR;  // @0x0dc
					__SOOL_PERIPH_PADDING_32;
					ETH_MAP0_MMCCR;      // @0x100
					ETH_MAP0_MMCRIR;     // @0x104
					ETH_MAP0_MMCTIR;     // @0x108
					ETH_MAP0_MMCRIMR;    // @0x10c
					ETH_MAP0_MMCTIMR;    // @0x110
					ETH_MAP0_MACDR;      // @0x114
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_MACHWF0R;   // @0x11c
					ETH_MAP0_MACHWF1R;   // @0x120
					ETH_MAP0_MACHWF2R;   // @0x124
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_MMCTGFSCCR; // @0x14c
					ETH_MAP0_MMCTGFMSCCR; // @0x150
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_MMCTGFCR;   // @0x168
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_8;
					ETH_MAP0_MMCRFCECR;  // @0x194
					ETH_MAP0_MMCRFAECR;  // @0x198
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_8;
					ETH_MAP0_MMCRGUFCR;  // @0x1c4
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					ETH_MAP0_MACMDIOAR;  // @0x200
					ETH_MAP0_MACMDIODR;  // @0x204
					__SOOL_PERIPH_PADDING_8;
					ETH_MAP0_MACARPAR;   // @0x210
					__SOOL_PERIPH_PADDING_1024;
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_PTPTSCR;    // @0x700
					ETH_MAP0_PTPSSIR;    // @0x704
					ETH_MAP0_PTPTSHR;    // @0x708
					ETH_MAP0_PTPTSLR;    // @0x70c
					ETH_MAP0_PTPTSHUR;   // @0x710
					ETH_MAP0_PTPTSLUR;   // @0x714
					ETH_MAP0_PTPTSAR;    // @0x718
					ETH_MAP0_PTPTTHR;    // @0x71c
					ETH_MAP0_PTPTTLR;    // @0x720
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_PTPTSSR;    // @0x728
					__SOOL_PERIPH_PADDING_32;
					ETH_MAP0_MMCTSCGPR;  // @0x74c
					ETH_MAP0_MMCTMCGPR;  // @0x750
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_MMCTPCGR;   // @0x768
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_8;
					ETH_MAP0_MMCRCRCEPR; // @0x794
					ETH_MAP0_MMCRAEPR;   // @0x798
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_8;
					ETH_MAP0_MMCRUPGR;   // @0x7c4
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_MMCTLPIMSTR; // @0x7ec
					ETH_MAP0_MMCTLPITCR; // @0x7f0
					ETH_MAP0_MMCRLPIMSTR; // @0x7f4
					ETH_MAP0_MMCRLPITCR; // @0x7f8
					__SOOL_PERIPH_PADDING_256;
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_MACL3L4C0R; // @0x900
					ETH_MAP0_MACL4A0R;   // @0x904
					__SOOL_PERIPH_PADDING_8;
					ETH_MAP0_MACL3A00R;  // @0x910
					ETH_MAP0_MACL3A10R;  // @0x914
					ETH_MAP0_MACL3A20R;  // @0x918
					ETH_MAP0_MACL3A30R;  // @0x91c
					__SOOL_PERIPH_PADDING_16;
					ETH_MAP0_MACL3L4C1R; // @0x930
					ETH_MAP0_MACL4A1R;   // @0x934
					__SOOL_PERIPH_PADDING_8;
					ETH_MAP0_MACL3A01R;  // @0x940
					ETH_MAP0_MACL3A11R;  // @0x944
					ETH_MAP0_MACL3A21R;  // @0x948
					ETH_MAP0_MACL3A31R;  // @0x94c
					__SOOL_PERIPH_PADDING_256;
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_16;
					ETH_MAP0_MACTSCR;    // @0xb00
					ETH_MAP0_MACSSIR;    // @0xb04
					ETH_MAP0_MACSTSR;    // @0xb08
					ETH_MAP0_MACSTNR;    // @0xb0c
					ETH_MAP0_MACSTSUR;   // @0xb10
					ETH_MAP0_MACSTNUR;   // @0xb14
					ETH_MAP0_MACTSAR;    // @0xb18
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_MACTSSR;    // @0xb20
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_MACTTSSNR;  // @0xb30
					ETH_MAP0_MACTTSSSR;  // @0xb34
					__SOOL_PERIPH_PADDING_8;
					ETH_MAP0_MACACR;     // @0xb40
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_MACATSNR;   // @0xb48
					ETH_MAP0_MACATSSR;   // @0xb4c
					ETH_MAP0_MACTSIACR;  // @0xb50
					ETH_MAP0_MACTSEACR;  // @0xb54
					ETH_MAP0_MACTSICNR;  // @0xb58
					ETH_MAP0_MACTSECNR;  // @0xb5c
					__SOOL_PERIPH_PADDING_16;
					ETH_MAP0_MACPPSCR;   // @0xb70
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_MACPPSTTSR; // @0xb80
					ETH_MAP0_MACPPSTTNR; // @0xb84
					ETH_MAP0_MACPPSIR;   // @0xb88
					ETH_MAP0_MACPPSWR;   // @0xb8c
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_16;
					ETH_MAP0_MACPOCR;    // @0xbc0
					ETH_MAP0_MACSPI0R;   // @0xbc4
					ETH_MAP0_MACSPI1R;   // @0xbc8
					ETH_MAP0_MACSPI2R;   // @0xbcc
					ETH_MAP0_MACLMIR;    // @0xbd0
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_MTLOMR;     // @0xc00
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_MTLISR;     // @0xc20
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_MTLTQOMR;   // @0xd00
					ETH_MAP0_MTLTQUR;    // @0xd04
					ETH_MAP0_MTLTQDR;    // @0xd08
					__SOOL_PERIPH_PADDING_32;
					ETH_MAP0_MTLQICSR;   // @0xd2c
					ETH_MAP0_MTLRQOMR;   // @0xd30
					ETH_MAP0_MTLRQMPOCR; // @0xd34
					ETH_MAP0_MTLRQDR;    // @0xd38
					__SOOL_PERIPH_PADDING_512;
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_DMABMR;     // @0x1000
					ETH_MAP0_DMATPDR;    // @0x1004
					ETH_MAP0_DMARPDR;    // @0x1008
					ETH_MAP0_DMARDLAR;   // @0x100c
					ETH_MAP0_DMATDLAR;   // @0x1010
					ETH_MAP0_DMASR;      // @0x1014
					ETH_MAP0_DMAOMR;     // @0x1018
					ETH_MAP0_DMAIER;     // @0x101c
					ETH_MAP0_DMAMFBOCR;  // @0x1020
					ETH_MAP0_DMARSWTR;   // @0x1024
					__SOOL_PERIPH_PADDING_32;
					ETH_MAP0_DMACHTDR;   // @0x1048
					ETH_MAP0_DMACHRDR;   // @0x104c
					ETH_MAP0_DMACHTBAR;  // @0x1050
					ETH_MAP0_DMACHRBAR;  // @0x1054
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_8;
					ETH_MAP0_DMACCR;     // @0x1100
					ETH_MAP0_DMACTCR;    // @0x1104
					ETH_MAP0_DMACRCR;    // @0x1108
					__SOOL_PERIPH_PADDING_8;
					ETH_MAP0_DMACTDLAR;  // @0x1114
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_DMACRDLAR;  // @0x111c
					ETH_MAP0_DMACTDTPR;  // @0x1120
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_DMACRDTPR;  // @0x1128
					ETH_MAP0_DMACTDRLR;  // @0x112c
					ETH_MAP0_DMACRDRLR;  // @0x1130
					ETH_MAP0_DMACIER;    // @0x1134
					ETH_MAP0_DMACRIWTR;  // @0x1138
					ETH_MAP0_DMACSFCSR;  // @0x113c
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_DMACCATDR;  // @0x1144
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_DMACCARDR;  // @0x114c
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_DMACCATBR;  // @0x1154
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP0_DMACCARBR;  // @0x115c
					ETH_MAP0_DMACSR;     // @0x1160
					__SOOL_PERIPH_PADDING_8;
					ETH_MAP0_DMACMFCR;   // @0x116c
				};
				struct
				{
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP1_MACECR;     // @0x004
					ETH_MAP1_MACPFR;     // @0x008
					ETH_MAP1_MACWTR;     // @0x00c
					ETH_MAP1_MACHT0R;    // @0x010
					ETH_MAP1_MACHT1R;    // @0x014
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					ETH_MAP1_MACVTR;     // @0x050
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP1_MACVHTR;    // @0x058
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP1_MACVR;      // @0x110
					__SOOL_PERIPH_PADDING_256;
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP1_MACA0HR;    // @0x300
					ETH_MAP1_MACA0LR;    // @0x304
					ETH_MAP1_MACA1HR;    // @0x308
					ETH_MAP1_MACA1LR;    // @0x30c
					ETH_MAP1_MACA2HR;    // @0x310
					ETH_MAP1_MACA2LR;    // @0x314
					ETH_MAP1_MACA3HR;    // @0x318
					ETH_MAP1_MACA3LR;    // @0x31c
					__SOOL_PERIPH_PADDING_512;
					__SOOL_PERIPH_PADDING_256;
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_32;
					ETH_MAP1_MMCCR;      // @0x700
					ETH_MAP1_MMCRIR;     // @0x704
					ETH_MAP1_MMCTIR;     // @0x708
					ETH_MAP1_MMCRIMR;    // @0x70c
					ETH_MAP1_MMCTIMR;    // @0x710
					__SOOL_PERIPH_PADDING_2048;
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					ETH_MAP1_DMAMR;      // @0x1000
					ETH_MAP1_DMASBMR;    // @0x1004
					ETH_MAP1_DMAISR;     // @0x1008
					ETH_MAP1_DMADSR;     // @0x100c
					__SOOL_PERIPH_PADDING_256;
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_32;
				};
			};
			private:
			ETH() = delete;
			//SOOL-ETH-DECLARATION
		};
		
		//region instances
#define ETH_BASE_ADDR ((uint32_t)0x40028000U)
#ifdef ETH_BASE_ADDR
volatile class ETH * const ETH = reinterpret_cast<class ETH* const>(ETH_BASE_ADDR);
#endif
//endregion

//SOOL-ETH-DEFINES
//SOOL-ETH-DEFINITION
	};
};//region undef
#undef ETH_MACCR_0_RE
#undef ETH_MACCR_0_TE
#undef ETH_MACCR_0_APCS
#undef ETH_MACCR_0_RD
#undef ETH_MACCR_0_IPCO
#undef ETH_MACCR_0_DM
#undef ETH_MACCR_0_ROD
#undef ETH_MACCR_0_CSD
#undef ETH_MACCR_0_IFG
#undef ETH_MACCR_0_JD
#undef ETH_MACCR_0_WD
#undef ETH_MAP0_MACFFR
#undef ETH_MAP0_MACHTHR
#undef ETH_MAP0_MACHTLR
#undef ETH_MAP0_MACMIIAR
#undef ETH_MAP0_MACMIIDR
#undef ETH_MAP0_MACFCR
#undef ETH_MAP0_MACVLANTR
#undef ETH_MAP0_MACRWUFFR
#undef ETH_MAP0_MACPMTCSR
#undef ETH_MAP0_MACSR
#undef ETH_MAP0_MACIMR
#undef ETH_MAP0_MACA0HR
#undef ETH_MAP0_MACA0LR
#undef ETH_MAP0_MACA1HR
#undef ETH_MAP0_MACA1LR
#undef ETH_MAP0_MACA2HR
#undef ETH_MAP0_MACA2LR
#undef ETH_MAP0_MACA3HR
#undef ETH_MAP0_MACA3LR
#undef ETH_MAP0_MMCCR
#undef ETH_MAP0_MMCRIR
#undef ETH_MAP0_MMCTIR
#undef ETH_MAP0_MMCRIMR
#undef ETH_MAP0_MMCTIMR
#undef ETH_MAP0_MMCTGFSCCR
#undef ETH_MAP0_MMCTGFMSCCR
#undef ETH_MAP0_MMCTGFCR
#undef ETH_MAP0_MMCRFCECR
#undef ETH_MAP0_MMCRFAECR
#undef ETH_MAP0_MMCRGUFCR
#undef ETH_MAP0_PTPTSCR
#undef ETH_MAP0_PTPSSIR
#undef ETH_MAP0_PTPTSHR
#undef ETH_MAP0_PTPTSLR
#undef ETH_MAP0_PTPTSHUR
#undef ETH_MAP0_PTPTSLUR
#undef ETH_MAP0_PTPTSAR
#undef ETH_MAP0_PTPTTHR
#undef ETH_MAP0_PTPTTLR
#undef ETH_MAP0_DMABMR
#undef ETH_MAP0_DMATPDR
#undef ETH_MAP0_DMARPDR
#undef ETH_MAP0_DMARDLAR
#undef ETH_MAP0_DMATDLAR
#undef ETH_MAP0_DMASR
#undef ETH_MAP0_DMAOMR
#undef ETH_MAP0_DMAIER
#undef ETH_MAP0_DMAMFBOCR
#undef ETH_MAP0_DMACHTDR
#undef ETH_MAP0_DMACHRDR
#undef ETH_MAP0_DMACHTBAR
#undef ETH_MAP0_DMACHRBAR
#undef ETH_DMABMR_EDE
#undef ETH_MMCCR_MCP
#undef ETH_MMCCR_MCFHP
#undef ETH_PTPTSCR_TSCNT
#undef ETH_MAP0_MACDBGR
#undef ETH_MAP0_PTPTSSR
#undef ETH_MAP0_DMARSWTR
#undef ETH_MACCR_0_DR
#undef ETH_MACCR_0_ACS
#undef ETH_MACCR_0_CST
#undef ETH_MACCR_0_IPG
#undef ETH_MACCR_0_IPC
#undef ETH_MACCR_0_SARC
#undef ETH_MACCR_0_ARP
#undef ETH_MAP1_MACECR
#undef ETH_MAP1_MACPFR
#undef ETH_MAP1_MACWTR
#undef ETH_MAP1_MACHT0R
#undef ETH_MAP1_MACHT1R
#undef ETH_MAP1_MACVTR
#undef ETH_MAP1_MACVHTR
#undef ETH_MAP0_MACVIR
#undef ETH_MAP0_MACIVIR
#undef ETH_MAP0_MACTFCR
#undef ETH_MAP0_MACRFCR
#undef ETH_MAP0_MACISR
#undef ETH_MAP0_MACIER
#undef ETH_MAP0_MACRXTXSR
#undef ETH_MAP0_MACPCSR
#undef ETH_MAP0_MACRWKPFR
#undef ETH_MAP0_MACLCSR
#undef ETH_MAP0_MACLTCR
#undef ETH_MAP0_MACLETR
#undef ETH_MAP0_MAC1USTCR
#undef ETH_MAP1_MACVR
#undef ETH_MAP0_MACDR
#undef ETH_MAP0_MACHWF0R
#undef ETH_MAP0_MACHWF1R
#undef ETH_MAP0_MACHWF2R
#undef ETH_MAP0_MACMDIOAR
#undef ETH_MAP0_MACMDIODR
#undef ETH_MAP0_MACARPAR
#undef ETH_MAP1_MACA0HR
#undef ETH_MAP1_MACA0LR
#undef ETH_MAP1_MACA1HR
#undef ETH_MAP1_MACA1LR
#undef ETH_MAP1_MACA2HR
#undef ETH_MAP1_MACA2LR
#undef ETH_MAP1_MACA3HR
#undef ETH_MAP1_MACA3LR
#undef ETH_MAP1_MMCCR
#undef ETH_MAP1_MMCRIR
#undef ETH_MAP1_MMCTIR
#undef ETH_MAP1_MMCRIMR
#undef ETH_MAP1_MMCTIMR
#undef ETH_MAP0_MMCTSCGPR
#undef ETH_MAP0_MMCTMCGPR
#undef ETH_MAP0_MMCTPCGR
#undef ETH_MAP0_MMCRCRCEPR
#undef ETH_MAP0_MMCRAEPR
#undef ETH_MAP0_MMCRUPGR
#undef ETH_MAP0_MMCTLPIMSTR
#undef ETH_MAP0_MMCTLPITCR
#undef ETH_MAP0_MMCRLPIMSTR
#undef ETH_MAP0_MMCRLPITCR
#undef ETH_MAP0_MACL3L4C0R
#undef ETH_MAP0_MACL4A0R
#undef ETH_MAP0_MACL3A00R
#undef ETH_MAP0_MACL3A10R
#undef ETH_MAP0_MACL3A20R
#undef ETH_MAP0_MACL3A30R
#undef ETH_MAP0_MACL3L4C1R
#undef ETH_MAP0_MACL4A1R
#undef ETH_MAP0_MACL3A01R
#undef ETH_MAP0_MACL3A11R
#undef ETH_MAP0_MACL3A21R
#undef ETH_MAP0_MACL3A31R
#undef ETH_MAP0_MACTSCR
#undef ETH_MAP0_MACSSIR
#undef ETH_MAP0_MACSTSR
#undef ETH_MAP0_MACSTNR
#undef ETH_MAP0_MACSTSUR
#undef ETH_MAP0_MACSTNUR
#undef ETH_MAP0_MACTSAR
#undef ETH_MAP0_MACTSSR
#undef ETH_MAP0_MACTTSSNR
#undef ETH_MAP0_MACTTSSSR
#undef ETH_MAP0_MACACR
#undef ETH_MAP0_MACATSNR
#undef ETH_MAP0_MACATSSR
#undef ETH_MAP0_MACTSIACR
#undef ETH_MAP0_MACTSEACR
#undef ETH_MAP0_MACTSICNR
#undef ETH_MAP0_MACTSECNR
#undef ETH_MAP0_MACPPSCR
#undef ETH_MAP0_MACPPSTTSR
#undef ETH_MAP0_MACPPSTTNR
#undef ETH_MAP0_MACPPSIR
#undef ETH_MAP0_MACPPSWR
#undef ETH_MAP0_MACPOCR
#undef ETH_MAP0_MACSPI0R
#undef ETH_MAP0_MACSPI1R
#undef ETH_MAP0_MACSPI2R
#undef ETH_MAP0_MACLMIR
#undef ETH_MAP0_MTLOMR
#undef ETH_MAP0_MTLISR
#undef ETH_MAP0_MTLTQOMR
#undef ETH_MAP0_MTLTQUR
#undef ETH_MAP0_MTLTQDR
#undef ETH_MAP0_MTLQICSR
#undef ETH_MAP0_MTLRQOMR
#undef ETH_MAP0_MTLRQMPOCR
#undef ETH_MAP0_MTLRQDR
#undef ETH_MAP1_DMAMR
#undef ETH_MAP1_DMASBMR
#undef ETH_MAP1_DMAISR
#undef ETH_MAP1_DMADSR
#undef ETH_MAP0_DMACCR
#undef ETH_MAP0_DMACTCR
#undef ETH_MAP0_DMACRCR
#undef ETH_MAP0_DMACTDLAR
#undef ETH_MAP0_DMACRDLAR
#undef ETH_MAP0_DMACTDTPR
#undef ETH_MAP0_DMACRDTPR
#undef ETH_MAP0_DMACTDRLR
#undef ETH_MAP0_DMACRDRLR
#undef ETH_MAP0_DMACIER
#undef ETH_MAP0_DMACRIWTR
#undef ETH_MAP0_DMACSFCSR
#undef ETH_MAP0_DMACCATDR
#undef ETH_MAP0_DMACCARDR
#undef ETH_MAP0_DMACCATBR
#undef ETH_MAP0_DMACCARBR
#undef ETH_MAP0_DMACSR
#undef ETH_MAP0_DMACMFCR
#undef ETH_MACDBGR_0_TFWA
//endregion
#endif
#endif
