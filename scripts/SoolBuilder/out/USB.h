#ifndef __SOOL_USB_H
#define __SOOL_USB_H

#include "peripheral_include.h"
//SOOL-USB-INCLUDES
#if defined(STM32F042x6 ) || defined(STM32F048xx ) || defined(STM32F070x6 ) || defined(STM32F070xB ) ||\
    defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F102x6 ) || defined(STM32F102xB ) ||\
    defined(STM32F103x6 ) || defined(STM32F103xB ) || defined(STM32F103xE ) || defined(STM32F103xG ) ||\
    defined(STM32F105xC ) || defined(STM32F107xC ) || defined(STM32F2     ) || defined(STM32F302x8 ) ||\
    defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) || defined(STM32F303xE ) ||\
    defined(STM32F373xC ) || defined(STM32F401xC ) || defined(STM32F401xE ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F411xE ) || defined(STM32F412Cx ) || defined(STM32F412Rx ) ||\
    defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32H7     ) || defined(STM32L052xx ) || defined(STM32L053xx ) ||\
    defined(STM32L062xx ) || defined(STM32L063xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) ||\
    defined(STM32L082xx ) || defined(STM32L083xx ) || defined(STM32L1     ) || defined(STM32L432xx ) ||\
    defined(STM32L433xx ) || defined(STM32L442xx ) || defined(STM32L443xx ) || defined(STM32L452xx ) ||\
    defined(STM32L462xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
//region defines

#if defined(STM32F042x6 ) || defined(STM32F048xx ) || defined(STM32F070x6 ) || defined(STM32F070xB ) ||\
    defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32L052xx ) || defined(STM32L053xx ) ||\
    defined(STM32L062xx ) || defined(STM32L063xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) ||\
    defined(STM32L082xx ) || defined(STM32L083xx ) || defined(STM32L432xx ) || defined(STM32L433xx ) ||\
    defined(STM32L442xx ) || defined(STM32L443xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) 
#define USB_BCDR
#define USB_MAP0_BCDR        BCDR_TypeDef BCDR
#else
#define USB_MAP0_BCDR __SOOL_PERIPH_PADDING_2
#endif

#if defined(STM32F042x6 ) || defined(STM32F048xx ) || defined(STM32F070x6 ) || defined(STM32F070xB ) ||\
    defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F102x6 ) || defined(STM32F102xB ) ||\
    defined(STM32F103x6 ) || defined(STM32F103xB ) || defined(STM32F103xE ) || defined(STM32F103xG ) ||\
    defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F373xC ) || defined(STM32L052xx ) || defined(STM32L053xx ) ||\
    defined(STM32L062xx ) || defined(STM32L063xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) ||\
    defined(STM32L082xx ) || defined(STM32L083xx ) || defined(STM32L1     ) || defined(STM32L432xx ) ||\
    defined(STM32L433xx ) || defined(STM32L442xx ) || defined(STM32L443xx ) || defined(STM32L452xx ) ||\
    defined(STM32L462xx ) 
#define USB_BTABLE
#define USB_CNTR
#define USB_DADDR
#define USB_EP0R
#define USB_EP1R
#define USB_EP2R
#define USB_EP3R
#define USB_EP4R
#define USB_EP5R
#define USB_EP6R
#define USB_EP7R
#define USB_FNR
#define USB_ISTR
#define USB_MAP0_EP0R        EP0R_TypeDef EP0R
#define USB_MAP0_EP1R        EP1R_TypeDef EP1R
#define USB_MAP0_EP2R        EP2R_TypeDef EP2R
#define USB_MAP0_EP3R        EP3R_TypeDef EP3R
#define USB_MAP0_EP4R        EP4R_TypeDef EP4R
#define USB_MAP0_EP5R        EP5R_TypeDef EP5R
#define USB_MAP0_EP6R        EP6R_TypeDef EP6R
#define USB_MAP0_EP7R        EP7R_TypeDef EP7R
#define USB_MAP0_CNTR        CNTR_TypeDef CNTR
#define USB_MAP0_ISTR        ISTR_TypeDef ISTR
#define USB_MAP0_FNR         FNR_TypeDef FNR
#define USB_MAP0_DADDR       DADDR_TypeDef DADDR
#define USB_MAP0_BTABLE      BTABLE_TypeDef BTABLE
#else
#define USB_MAP0_EP0R __SOOL_PERIPH_PADDING_2
#define USB_MAP0_EP1R __SOOL_PERIPH_PADDING_2
#define USB_MAP0_EP2R __SOOL_PERIPH_PADDING_2
#define USB_MAP0_EP3R __SOOL_PERIPH_PADDING_2
#define USB_MAP0_EP4R __SOOL_PERIPH_PADDING_2
#define USB_MAP0_EP5R __SOOL_PERIPH_PADDING_2
#define USB_MAP0_EP6R __SOOL_PERIPH_PADDING_2
#define USB_MAP0_EP7R __SOOL_PERIPH_PADDING_2
#define USB_MAP0_CNTR __SOOL_PERIPH_PADDING_2
#define USB_MAP0_ISTR __SOOL_PERIPH_PADDING_2
#define USB_MAP0_FNR __SOOL_PERIPH_PADDING_2
#define USB_MAP0_DADDR __SOOL_PERIPH_PADDING_2
#define USB_MAP0_BTABLE __SOOL_PERIPH_PADDING_2
#endif

#if defined(STM32F042x6 ) || defined(STM32F048xx ) || defined(STM32F070x6 ) || defined(STM32F070xB ) ||\
    defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F302x8 ) || defined(STM32F302xC ) ||\
    defined(STM32F302xE ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F373xC ) ||\
    defined(STM32L052xx ) || defined(STM32L053xx ) || defined(STM32L062xx ) || defined(STM32L063xx ) ||\
    defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L082xx ) || defined(STM32L083xx ) ||\
    defined(STM32L1     ) || defined(STM32L432xx ) || defined(STM32L433xx ) || defined(STM32L442xx ) ||\
    defined(STM32L443xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) 
#define USB_CNTR_0_LPMODE    LPMODE               // 1 bits @ 2
#else
#define USB_CNTR_0_LPMODE
#endif

#if defined(STM32F042x6 ) || defined(STM32F048xx ) || defined(STM32F070x6 ) || defined(STM32F070xB ) ||\
    defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F302x8 ) || defined(STM32F302xE ) ||\
    defined(STM32F303xE ) || defined(STM32L052xx ) || defined(STM32L053xx ) || defined(STM32L062xx ) ||\
    defined(STM32L063xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L082xx ) ||\
    defined(STM32L083xx ) || defined(STM32L432xx ) || defined(STM32L433xx ) || defined(STM32L442xx ) ||\
    defined(STM32L443xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) 
#define USB_CNTR_0_L1RESUME  L1RESUME             // 1 bits @ 5
#define USB_CNTR_0_L1REQM    L1REQM               // 1 bits @ 7
#define USB_ISTR_0_L1REQ     L1REQ                // 1 bits @ 7
#define USB_LPMCSR
#define USB_MAP0_LPMCSR      LPMCSR_TypeDef LPMCSR
#else
#define USB_CNTR_0_L1RESUME
#define USB_CNTR_0_L1REQM
#define USB_ISTR_0_L1REQ
#define USB_MAP0_LPMCSR __SOOL_PERIPH_PADDING_2
#endif

#if defined(STM32F102x6 ) || defined(STM32F102xB ) || defined(STM32F103x6 ) || defined(STM32F103xB ) ||\
    defined(STM32F103xE ) || defined(STM32F103xG ) || defined(STM32F302x8 ) || defined(STM32F302xC ) ||\
    defined(STM32F302xE ) || defined(STM32F303xC ) || defined(STM32F303xE ) || defined(STM32F373xC ) 
#define USB_CNTR_1
#endif

#if defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F373xC ) 
#define USB_CNTR_1_PMAOVR    PMAOVR               // 1 bits @ 14
#define USB_ISTR_1
#else
#define USB_CNTR_1_PMAOVR
#endif

#if defined(STM32F102x6 ) || defined(STM32F102xB ) || defined(STM32F103x6 ) || defined(STM32F103xB ) ||\
    defined(STM32F103xE ) || defined(STM32F103xG ) || defined(STM32L1     ) || defined(STM32L432xx ) ||\
    defined(STM32L433xx ) || defined(STM32L442xx ) || defined(STM32L443xx ) || defined(STM32L452xx ) ||\
    defined(STM32L462xx ) 
#define USB_DADDR_1
#endif

#define USB_Device_DAINT
#define USB_Device_DAINTMSK
#define USB_Device_DCFG
#define USB_Device_DCTL
#define USB_Device_DEACHINT
#define USB_Device_DEACHMSK
#define USB_Device_DIEPEMPMSK
#define USB_Device_DIEPMSK
#define USB_Device_DINEP1MSK
#define USB_Device_DOEPMSK
#define USB_Device_DOUTEP1MSK
#define USB_Device_DSTS
#define USB_Device_DTHRCTL
#define USB_Device_DVBUSDIS
#define USB_Device_DVBUSPULSE
#define USB_Global_CID
#define USB_Global_DIEPTXF
#define USB_Global_DIEPTXF0_HNPTXFSIZ
#define USB_Global_GAHBCFG
#define USB_Global_GCCFG
#define USB_Global_GINTMSK
#define USB_Global_GINTSTS
#define USB_Global_GOTGCTL
#define USB_Global_GOTGINT
#define USB_Global_GRSTCTL
#define USB_Global_GRXFSIZ
#define USB_Global_GRXSTSP
#define USB_Global_GRXSTSR
#define USB_Global_GUSBCFG
#define USB_Global_HNPTXSTS
#define USB_Global_HPTXFSIZ
#define USB_Host_HAINT
#define USB_Host_HAINTMSK
#define USB_Host_HCFG
#define USB_Host_HFIR
#define USB_Host_HFNUM
#define USB_Host_HPTXSTS
#define USB_HostChannel_HCCHAR
#define USB_HostChannel_HCDMA
#define USB_HostChannel_HCINT
#define USB_HostChannel_HCINTMSK
#define USB_HostChannel_HCSPLT
#define USB_HostChannel_HCTSIZ
#define USB_INEndpoint_DIEPCTL
#define USB_INEndpoint_DIEPDMA
#define USB_INEndpoint_DIEPINT
#define USB_INEndpoint_DIEPTSIZ
#define USB_INEndpoint_DTXFSTS
#define USB_OUTEndpoint_DOEPCTL
#define USB_OUTEndpoint_DOEPDMA
#define USB_OUTEndpoint_DOEPINT
#define USB_OUTEndpoint_DOEPTSIZ

#if defined(STM32F412Cx ) || defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) ||\
    defined(STM32F413xx ) || defined(STM32F423xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) 
#define USB_Device_DOEPMSK_OTEPSPRM OTEPSPRM             // 1 bits @ 5
#define USB_Global_GOTGINT_IDCHNG IDCHNG               // 1 bits @ 20
#else
#define USB_Device_DOEPMSK_OTEPSPRM
#define USB_Global_GOTGINT_IDCHNG
#endif

#if defined(STM32H7     ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define USB_Global_GADPCTL
#define USB_Global_GHWCFG1
#define USB_Global_GHWCFG2
#define USB_Global_GPWRDN
#define USB_Global_GSNPSID
#define USB_Global_MAP0_GSNPSID uint32_t GSNPSID
#define USB_Global_MAP0_GHWCFG1 uint32_t GHWCFG1
#define USB_Global_MAP0_GHWCFG2 uint32_t GHWCFG2
#define USB_Global_MAP0_GPWRDN GPWRDN_TypeDef GPWRDN
#define USB_Global_MAP0_GADPCTL uint32_t GADPCTL
#else
#define USB_Global_MAP0_GSNPSID __SOOL_PERIPH_PADDING_4
#define USB_Global_MAP0_GHWCFG1 __SOOL_PERIPH_PADDING_4
#define USB_Global_MAP0_GHWCFG2 __SOOL_PERIPH_PADDING_4
#define USB_Global_MAP0_GPWRDN __SOOL_PERIPH_PADDING_4
#define USB_Global_MAP0_GADPCTL __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F105xC ) || defined(STM32F107xC ) || defined(STM32F2     ) || defined(STM32F401xC ) ||\
    defined(STM32F401xE ) || defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F411xE ) ||\
    defined(STM32F412Cx ) || defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) ||\
    defined(STM32F413xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F423xx ) ||\
    defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) ||\
    defined(STM32H7     ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define USB_Global_GCCFG_0
#define USB_Global_GINTMSK_0
#define USB_Global_GOTGCTL_0
#define USB_Global_GRXSTSR_0
#define USB_Global_GRXSTSR_1
#endif

#if defined(STM32F412Cx ) || defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) ||\
    defined(STM32F413xx ) || defined(STM32F423xx ) || defined(STM32F723xx ) || defined(STM32F733xx ) ||\
    defined(STM32H7     ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define USB_Global_GCCFG_0_DCDET DCDET                // 1 bits @ 0
#define USB_Global_GCCFG_0_PDET PDET                 // 1 bits @ 1
#define USB_Global_GCCFG_0_SDET SDET                 // 1 bits @ 2
#define USB_Global_GCCFG_0_PS2DET PS2DET               // 1 bits @ 3
#define USB_Global_GCCFG_1_BCDEN BCDEN                // 1 bits @ 17
#define USB_Global_GCCFG_1_DCDEN DCDEN                // 1 bits @ 18
#define USB_Global_GCCFG_1_PDEN PDEN                 // 1 bits @ 19
#define USB_Global_GCCFG_1_SDEN SDEN                 // 1 bits @ 20
#else
#define USB_Global_GCCFG_0_DCDET
#define USB_Global_GCCFG_0_PDET
#define USB_Global_GCCFG_0_SDET
#define USB_Global_GCCFG_0_PS2DET
#define USB_Global_GCCFG_1_BCDEN
#define USB_Global_GCCFG_1_DCDEN
#define USB_Global_GCCFG_1_PDEN
#define USB_Global_GCCFG_1_SDEN
#endif

#if defined(STM32F2     ) || defined(STM32F401xC ) || defined(STM32F401xE ) || defined(STM32F405xx ) ||\
    defined(STM32F407xx ) || defined(STM32F411xE ) || defined(STM32F415xx ) || defined(STM32F417xx ) ||\
    defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) 
#define USB_Global_GCCFG_0_I2CPADEN I2CPADEN             // 1 bits @ 17
#define USB_Global_GCCFG_0_NOVBUSSENS NOVBUSSENS           // 1 bits @ 21
#else
#define USB_Global_GCCFG_0_I2CPADEN
#define USB_Global_GCCFG_0_NOVBUSSENS
#endif

#if defined(STM32F105xC ) || defined(STM32F107xC ) || defined(STM32F2     ) || defined(STM32F401xC ) ||\
    defined(STM32F401xE ) || defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F411xE ) ||\
    defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F427xx ) || defined(STM32F429xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) 
#define USB_Global_GCCFG_0_VBUSASEN VBUSASEN             // 1 bits @ 18
#define USB_Global_GCCFG_0_VBUSBSEN VBUSBSEN             // 1 bits @ 19
#define USB_Global_GCCFG_0_SOFOUTEN SOFOUTEN             // 1 bits @ 20
#define USB_Global_GOTGCTL_0_BSVLD BSVLD                // 1 bits @ 19
#else
#define USB_Global_GCCFG_0_VBUSASEN
#define USB_Global_GCCFG_0_VBUSBSEN
#define USB_Global_GCCFG_0_SOFOUTEN
#define USB_Global_GOTGCTL_0_BSVLD
#endif

#if defined(STM32F723xx ) || defined(STM32F733xx ) 
#define USB_Global_GCCFG_0_OTGIDEN OTGIDEN              // 1 bits @ 22
#define USB_Global_GCCFG_0_PHYHSEN PHYHSEN              // 1 bits @ 23
#define USB_Global_GUSBCFG_PHYIF PHYIF                // 1 bits @ 3
#define USB_Global_GUSBCFG_ULPI_UTMI_SEL ULPI_UTMI_SEL        // 1 bits @ 4
#else
#define USB_Global_GCCFG_0_OTGIDEN
#define USB_Global_GCCFG_0_PHYHSEN
#define USB_Global_GUSBCFG_PHYIF
#define USB_Global_GUSBCFG_ULPI_UTMI_SEL
#endif

#if defined(STM32F412Cx ) || defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) ||\
    defined(STM32F413xx ) || defined(STM32F423xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L475xx ) ||\
    defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define USB_Global_GCCFG_1
#define USB_Global_GINTMSK_0_LPMINTM LPMINTM              // 1 bits @ 27
#define USB_Global_GINTSTS_LPMINT LPMINT               // 1 bits @ 27
#define USB_Global_GLPMCFG_0
#define USB_Global_GOTGCTL_0_VBVALOEN VBVALOEN             // 1 bits @ 2
#define USB_Global_GOTGCTL_0_VBVALOVAL VBVALOVAL            // 1 bits @ 3
#define USB_Global_GOTGCTL_0_AVALOEN AVALOEN              // 1 bits @ 4
#define USB_Global_GOTGCTL_0_AVALOVAL AVALOVAL             // 1 bits @ 5
#define USB_Global_GOTGCTL_0_BVALOEN BVALOEN              // 1 bits @ 6
#define USB_Global_GOTGCTL_0_BVALOVAL BVALOVAL             // 1 bits @ 7
#define USB_Global_GOTGCTL_1
#else
#define USB_Global_GINTMSK_0_LPMINTM
#define USB_Global_GINTSTS_LPMINT
#define USB_Global_GOTGCTL_0_VBVALOEN
#define USB_Global_GOTGCTL_0_VBVALOVAL
#define USB_Global_GOTGCTL_0_AVALOEN
#define USB_Global_GOTGCTL_0_AVALOVAL
#define USB_Global_GOTGCTL_0_BVALOEN
#define USB_Global_GOTGCTL_0_BVALOVAL
#endif

#if defined(STM32F412Cx ) || defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) ||\
    defined(STM32F413xx ) || defined(STM32F423xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32H7     ) || defined(STM32L475xx ) || defined(STM32L476xx ) ||\
    defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) ||\
    defined(STM32L4P    ) 
#define USB_Global_GDFIFOCFG
#define USB_Global_GHWCFG3
#define USB_Global_GLPMCFG
#define USB_Global_MAP0_GHWCFG3 GHWCFG3_TypeDef GHWCFG3
#define USB_Global_MAP0_GLPMCFG GLPMCFG_TypeDef GLPMCFG
#define USB_Global_MAP0_GDFIFOCFG uint32_t GDFIFOCFG
#else
#define USB_Global_MAP0_GHWCFG3 __SOOL_PERIPH_PADDING_4
#define USB_Global_MAP0_GLPMCFG __SOOL_PERIPH_PADDING_4
#define USB_Global_MAP0_GDFIFOCFG __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F412Cx ) || defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) ||\
    defined(STM32F413xx ) || defined(STM32F423xx ) 
#define USB_Global_GINTMSK_0_RSTDETM RSTDETM              // 1 bits @ 23
#else
#define USB_Global_GINTMSK_0_RSTDETM
#endif

#if defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) ||\
    defined(STM32H7     ) 
#define USB_Global_GINTMSK_1
#endif

#if defined(STM32F412Cx ) || defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) ||\
    defined(STM32F413xx ) || defined(STM32F423xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) ||\
    defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32H7     ) 
#define USB_Global_GINTSTS_RSTDET RSTDET               // 1 bits @ 23
#define USB_Global_GLPMCFG_0_L1RSMOK L1RSMOK              // 1 bits @ 16
#define USB_Global_GOTGCTL_0_EHEN EHEN                 // 1 bits @ 12
#define USB_Global_GOTGCTL_0_OTGVER OTGVER               // 1 bits @ 20
#define USB_OUTEndpoint_DOEPINT_OTEPSPR OTEPSPR              // 1 bits @ 5
#else
#define USB_Global_GINTSTS_RSTDET
#define USB_Global_GLPMCFG_0_L1RSMOK
#define USB_Global_GOTGCTL_0_EHEN
#define USB_Global_GOTGCTL_0_OTGVER
#define USB_OUTEndpoint_DOEPINT_OTEPSPR
#endif

#if defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define USB_Global_GLPMCFG_1
#define USB_Global_GPWRDN_DISABLEVBUS DISABLEVBUS          // 1 bits @ 6
#else
#define USB_Global_GPWRDN_DISABLEVBUS
#endif

#if defined(STM32F105xC ) || defined(STM32F107xC ) || defined(STM32F2     ) || defined(STM32F401xC ) ||\
    defined(STM32F401xE ) || defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F411xE ) ||\
    defined(STM32F412Cx ) || defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) ||\
    defined(STM32F413xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F423xx ) ||\
    defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) ||\
    defined(STM32H7     ) 
#define USB_Global_GOTGCTL_0_HNGSCS HNGSCS               // 1 bits @ 8
#define USB_Global_GOTGCTL_0_HNPRQ HNPRQ                // 1 bits @ 9
#define USB_Global_GOTGCTL_0_HSHNPEN HSHNPEN              // 1 bits @ 10
#define USB_Global_GOTGCTL_0_DHNPEN DHNPEN               // 1 bits @ 11
#define USB_Global_GOTGCTL_0_CIDSTS CIDSTS               // 1 bits @ 16
#define USB_Global_GOTGCTL_0_DBCT DBCT                 // 1 bits @ 17
#define USB_Global_GOTGCTL_0_ASVLD ASVLD                // 1 bits @ 18
#else
#define USB_Global_GOTGCTL_0_HNGSCS
#define USB_Global_GOTGCTL_0_HNPRQ
#define USB_Global_GOTGCTL_0_HSHNPEN
#define USB_Global_GOTGCTL_0_DHNPEN
#define USB_Global_GOTGCTL_0_CIDSTS
#define USB_Global_GOTGCTL_0_DBCT
#define USB_Global_GOTGCTL_0_ASVLD
#endif

#if defined(STM32F7     ) || defined(STM32H7     ) 
#define USB_Global_GPWRDN_ADPMEN ADPMEN               // 1 bits @ 0
#define USB_Global_GPWRDN_ADPIF ADPIF                // 1 bits @ 23
#else
#define USB_Global_GPWRDN_ADPMEN
#define USB_Global_GPWRDN_ADPIF
#endif

//endregion

namespace sool
{
	namespace core
	{
		class USB
		{
			//SOOL-USB-ENUMS
			
			public :
			
			#ifdef USB_BCDR
			struct BCDR_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t BCDEN                :1;
					uint16_t DCDEN                :1;
					uint16_t PDEN                 :1;
					uint16_t SDEN                 :1;
					uint16_t DCDET                :1;
					uint16_t PDET                 :1;
					uint16_t SDET                 :1;
					uint16_t PS2DET               :1;
					uint16_t                      :7;
					uint16_t DPPU                 :1;
			
				//SOOL-USB_BCDR-DECLARATION
			};
			#endif
			
			#ifdef USB_BTABLE
			struct BTABLE_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t                      :3;
					uint16_t BTABLE               :13;
			
				//SOOL-USB_BTABLE-DECLARATION
			};
			#endif
			
			#ifdef USB_CNTR
			struct CNTR_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
			
				union
				{
					struct
					{
						uint16_t FRES                 :1;
						uint16_t PDWN                 :1;
						uint16_t USB_CNTR_0_LPMODE    :1;
						uint16_t FSUSP                :1;
						uint16_t RESUME               :1;
						uint16_t USB_CNTR_0_L1RESUME  :1;
						uint16_t                      :1;
						uint16_t USB_CNTR_0_L1REQM    :1;
						uint16_t ESOFM                :1;
						uint16_t SOFM                 :1;
						uint16_t RESETM               :1;
						uint16_t SUSPM                :1;
						uint16_t WKUPM                :1;
						uint16_t ERRM                 :1;
						uint16_t PMAOVRM              :1;
						uint16_t CTRM                 :1;
					};
					#ifdef USB_CNTR_1
					struct
					{
						uint16_t                      :2;
						uint16_t LP_MODE              :1;
						uint16_t                      :11;
						uint16_t USB_CNTR_1_PMAOVR    :1;
						uint16_t                      :1;
					};
					#endif
				};
				//SOOL-USB_CNTR-DECLARATION
			};
			#endif
			
			#ifdef USB_DADDR
			struct DADDR_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
			
				union
				{
					struct
					{
						uint16_t ADD                  :7;
						uint16_t EF                   :1;
						uint16_t                      :8;
					};
					#ifdef USB_DADDR_1
					struct
					{
						uint16_t ADD0                 :1;
						uint16_t ADD1                 :1;
						uint16_t ADD2                 :1;
						uint16_t ADD3                 :1;
						uint16_t ADD4                 :1;
						uint16_t ADD5                 :1;
						uint16_t ADD6                 :1;
						uint16_t                      :9;
					};
					#endif
				};
				//SOOL-USB_DADDR-DECLARATION
			};
			#endif
			
			#ifdef USB_EP0R
			struct EP0R_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t EA                   :4;
					uint16_t STAT_TX              :2;
					uint16_t DTOG_TX              :1;
					uint16_t CTR_TX               :1;
					uint16_t EP_KIND              :1;
					uint16_t EP_TYPE              :2;
					uint16_t SETUP                :1;
					uint16_t STAT_RX              :2;
					uint16_t DTOG_RX              :1;
					uint16_t CTR_RX               :1;
			
				//SOOL-USB_EP0R-DECLARATION
			};
			#endif
			
			#ifdef USB_EP1R
			struct EP1R_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t EA                   :4;
					uint16_t STAT_TX              :2;
					uint16_t DTOG_TX              :1;
					uint16_t CTR_TX               :1;
					uint16_t EP_KIND              :1;
					uint16_t EP_TYPE              :2;
					uint16_t SETUP                :1;
					uint16_t STAT_RX              :2;
					uint16_t DTOG_RX              :1;
					uint16_t CTR_RX               :1;
			
				//SOOL-USB_EP1R-DECLARATION
			};
			#endif
			
			#ifdef USB_EP2R
			struct EP2R_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t EA                   :4;
					uint16_t STAT_TX              :2;
					uint16_t DTOG_TX              :1;
					uint16_t CTR_TX               :1;
					uint16_t EP_KIND              :1;
					uint16_t EP_TYPE              :2;
					uint16_t SETUP                :1;
					uint16_t STAT_RX              :2;
					uint16_t DTOG_RX              :1;
					uint16_t CTR_RX               :1;
			
				//SOOL-USB_EP2R-DECLARATION
			};
			#endif
			
			#ifdef USB_EP3R
			struct EP3R_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t EA                   :4;
					uint16_t STAT_TX              :2;
					uint16_t DTOG_TX              :1;
					uint16_t CTR_TX               :1;
					uint16_t EP_KIND              :1;
					uint16_t EP_TYPE              :2;
					uint16_t SETUP                :1;
					uint16_t STAT_RX              :2;
					uint16_t DTOG_RX              :1;
					uint16_t CTR_RX               :1;
			
				//SOOL-USB_EP3R-DECLARATION
			};
			#endif
			
			#ifdef USB_EP4R
			struct EP4R_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t EA                   :4;
					uint16_t STAT_TX              :2;
					uint16_t DTOG_TX              :1;
					uint16_t CTR_TX               :1;
					uint16_t EP_KIND              :1;
					uint16_t EP_TYPE              :2;
					uint16_t SETUP                :1;
					uint16_t STAT_RX              :2;
					uint16_t DTOG_RX              :1;
					uint16_t CTR_RX               :1;
			
				//SOOL-USB_EP4R-DECLARATION
			};
			#endif
			
			#ifdef USB_EP5R
			struct EP5R_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t EA                   :4;
					uint16_t STAT_TX              :2;
					uint16_t DTOG_TX              :1;
					uint16_t CTR_TX               :1;
					uint16_t EP_KIND              :1;
					uint16_t EP_TYPE              :2;
					uint16_t SETUP                :1;
					uint16_t STAT_RX              :2;
					uint16_t DTOG_RX              :1;
					uint16_t CTR_RX               :1;
			
				//SOOL-USB_EP5R-DECLARATION
			};
			#endif
			
			#ifdef USB_EP6R
			struct EP6R_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t EA                   :4;
					uint16_t STAT_TX              :2;
					uint16_t DTOG_TX              :1;
					uint16_t CTR_TX               :1;
					uint16_t EP_KIND              :1;
					uint16_t EP_TYPE              :2;
					uint16_t SETUP                :1;
					uint16_t STAT_RX              :2;
					uint16_t DTOG_RX              :1;
					uint16_t CTR_RX               :1;
			
				//SOOL-USB_EP6R-DECLARATION
			};
			#endif
			
			#ifdef USB_EP7R
			struct EP7R_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t EA                   :4;
					uint16_t STAT_TX              :2;
					uint16_t DTOG_TX              :1;
					uint16_t CTR_TX               :1;
					uint16_t EP_KIND              :1;
					uint16_t EP_TYPE              :2;
					uint16_t SETUP                :1;
					uint16_t STAT_RX              :2;
					uint16_t DTOG_RX              :1;
					uint16_t CTR_RX               :1;
			
				//SOOL-USB_EP7R-DECLARATION
			};
			#endif
			
			#ifdef USB_FNR
			struct FNR_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t FN                   :11;
					uint16_t LSOF                 :2;
					uint16_t LCK                  :1;
					uint16_t RXDM                 :1;
					uint16_t RXDP                 :1;
			
				//SOOL-USB_FNR-DECLARATION
			};
			#endif
			
			#ifdef USB_ISTR
			struct ISTR_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
			
				union
				{
					struct
					{
						uint16_t EP_ID                :4;
						uint16_t DIR                  :1;
						uint16_t                      :2;
						uint16_t USB_ISTR_0_L1REQ     :1;
						uint16_t ESOF                 :1;
						uint16_t SOF                  :1;
						uint16_t RESET                :1;
						uint16_t SUSP                 :1;
						uint16_t WKUP                 :1;
						uint16_t ERR                  :1;
						uint16_t PMAOVR               :1;
						uint16_t CTR                  :1;
					};
					#ifdef USB_ISTR_1
					struct
					{
						uint16_t                      :14;
						uint16_t PMAOVRM              :1;
						uint16_t                      :1;
					};
					#endif
				};
				//SOOL-USB_ISTR-DECLARATION
			};
			#endif
			
			#ifdef USB_LPMCSR
			struct LPMCSR_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t LMPEN                :1;
					uint16_t LPMACK               :1;
					uint16_t                      :1;
					uint16_t REMWAKE              :1;
					uint16_t BESL                 :4;
					uint16_t                      :8;
			
				//SOOL-USB_LPMCSR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					USB_MAP0_EP0R;       // @0x000
					__SOOL_PERIPH_PADDING_2;
					USB_MAP0_EP1R;       // @0x004
					__SOOL_PERIPH_PADDING_2;
					USB_MAP0_EP2R;       // @0x008
					__SOOL_PERIPH_PADDING_2;
					USB_MAP0_EP3R;       // @0x00c
					__SOOL_PERIPH_PADDING_2;
					USB_MAP0_EP4R;       // @0x010
					__SOOL_PERIPH_PADDING_2;
					USB_MAP0_EP5R;       // @0x014
					__SOOL_PERIPH_PADDING_2;
					USB_MAP0_EP6R;       // @0x018
					__SOOL_PERIPH_PADDING_2;
					USB_MAP0_EP7R;       // @0x01c
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_2;
					USB_MAP0_CNTR;       // @0x040
					__SOOL_PERIPH_PADDING_2;
					USB_MAP0_ISTR;       // @0x044
					__SOOL_PERIPH_PADDING_2;
					USB_MAP0_FNR;        // @0x048
					__SOOL_PERIPH_PADDING_2;
					USB_MAP0_DADDR;      // @0x04c
					__SOOL_PERIPH_PADDING_2;
					USB_MAP0_BTABLE;     // @0x050
					__SOOL_PERIPH_PADDING_2;
					USB_MAP0_LPMCSR;     // @0x054
					__SOOL_PERIPH_PADDING_2;
					USB_MAP0_BCDR;       // @0x058
				};
			};
			private:
			USB() = delete;
			//SOOL-USB-DECLARATION
		};
		
		
		class USB_Device
		{
			//SOOL-USB_Device-ENUMS
			
			public :
			
			#ifdef USB_Device_DAINT
			struct DAINT_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t IEPINT               :16;
					uint32_t OEPINT               :16;
			
				//SOOL-USB_Device_DAINT-DECLARATION
			};
			#endif
			
			#ifdef USB_Device_DAINTMSK
			struct DAINTMSK_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t IEPM                 :16;
					uint32_t OEPM                 :16;
			
				//SOOL-USB_Device_DAINTMSK-DECLARATION
			};
			#endif
			
			#ifdef USB_Device_DCFG
			struct DCFG_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DSPD                 :2;
					uint32_t NZLSOHSK             :1;
					uint32_t                      :1;
					uint32_t DAD                  :7;
					uint32_t PFIVL                :2;
					uint32_t                      :11;
					uint32_t PERSCHIVL            :2;
					uint32_t                      :6;
			
				//SOOL-USB_Device_DCFG-DECLARATION
			};
			#endif
			
			#ifdef USB_Device_DCTL
			struct DCTL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RWUSIG               :1;
					uint32_t SDIS                 :1;
					uint32_t GINSTS               :1;
					uint32_t GONSTS               :1;
					uint32_t TCTL                 :3;
					uint32_t SGINAK               :1;
					uint32_t CGINAK               :1;
					uint32_t SGONAK               :1;
					uint32_t CGONAK               :1;
					uint32_t POPRGDNE             :1;
					uint32_t                      :20;
			
				//SOOL-USB_Device_DCTL-DECLARATION
			};
			#endif
			
			#ifdef USB_Device_DEACHINT
			struct DEACHINT_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :1;
					uint32_t IEP1INT              :1;
					uint32_t                      :15;
					uint32_t OEP1INT              :1;
					uint32_t                      :14;
			
				//SOOL-USB_Device_DEACHINT-DECLARATION
			};
			#endif
			
			#ifdef USB_Device_DIEPEMPMSK
			struct DIEPEMPMSK_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t INEPTXFEM            :16;
					uint32_t                      :16;
			
				//SOOL-USB_Device_DIEPEMPMSK-DECLARATION
			};
			#endif
			
			#ifdef USB_Device_DIEPMSK
			struct DIEPMSK_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t XFRCM                :1;
					uint32_t EPDM                 :1;
					uint32_t                      :1;
					uint32_t TOM                  :1;
					uint32_t ITTXFEMSK            :1;
					uint32_t INEPNMM              :1;
					uint32_t INEPNEM              :1;
					uint32_t                      :1;
					uint32_t TXFURM               :1;
					uint32_t BIM                  :1;
					uint32_t                      :22;
			
				//SOOL-USB_Device_DIEPMSK-DECLARATION
			};
			#endif
			
			#ifdef USB_Device_DOEPMSK
			struct DOEPMSK_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t XFRCM                :1;
					uint32_t EPDM                 :1;
					uint32_t                      :1;
					uint32_t STUPM                :1;
					uint32_t OTEPDM               :1;
					uint32_t USB_Device_DOEPMSK_OTEPSPRM :1;
					uint32_t B2BSTUP              :1;
					uint32_t                      :1;
					uint32_t OPEM                 :1;
					uint32_t BOIM                 :1;
					uint32_t                      :22;
			
				//SOOL-USB_Device_DOEPMSK-DECLARATION
			};
			#endif
			
			#ifdef USB_Device_DSTS
			struct DSTS_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SUSPSTS              :1;
					uint32_t ENUMSPD              :2;
					uint32_t EERR                 :1;
					uint32_t                      :4;
					uint32_t FNSOF                :14;
					uint32_t                      :10;
			
				//SOOL-USB_Device_DSTS-DECLARATION
			};
			#endif
			
			#ifdef USB_Device_DTHRCTL
			struct DTHRCTL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t NONISOTHREN          :1;
					uint32_t ISOTHREN             :1;
					uint32_t TXTHRLEN             :9;
					uint32_t                      :5;
					uint32_t RXTHREN              :1;
					uint32_t RXTHRLEN             :9;
					uint32_t                      :1;
					uint32_t ARPEN                :1;
					uint32_t                      :4;
			
				//SOOL-USB_Device_DTHRCTL-DECLARATION
			};
			#endif
			
			#ifdef USB_Device_DVBUSDIS
			struct DVBUSDIS_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t VBUSDT               :16;
					uint32_t                      :16;
			
				//SOOL-USB_Device_DVBUSDIS-DECLARATION
			};
			#endif
			
			#ifdef USB_Device_DVBUSPULSE
			struct DVBUSPULSE_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DVBUSP               :12;
					uint32_t                      :20;
			
				//SOOL-USB_Device_DVBUSPULSE-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					DCFG_TypeDef DCFG;   // @0x000
					DCTL_TypeDef DCTL;   // @0x004
					DSTS_TypeDef DSTS;   // @0x008
					__SOOL_PERIPH_PADDING_4;
					DIEPMSK_TypeDef DIEPMSK; // @0x010
					DOEPMSK_TypeDef DOEPMSK; // @0x014
					DAINT_TypeDef DAINT; // @0x018
					DAINTMSK_TypeDef DAINTMSK; // @0x01c
					__SOOL_PERIPH_PADDING_8;
					DVBUSDIS_TypeDef DVBUSDIS; // @0x028
					DVBUSPULSE_TypeDef DVBUSPULSE; // @0x02c
					DTHRCTL_TypeDef DTHRCTL; // @0x030
					DIEPEMPMSK_TypeDef DIEPEMPMSK; // @0x034
					DEACHINT_TypeDef DEACHINT; // @0x038
					uint32_t DEACHMSK;   // @0x03c
					__SOOL_PERIPH_PADDING_4;
					uint32_t DINEP1MSK;  // @0x044
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					uint32_t DOUTEP1MSK; // @0x084
				};
			};
			private:
			USB_Device() = delete;
			//SOOL-USB_Device-DECLARATION
		};
		
		
		class USB_Global
		{
			//SOOL-USB_Global-ENUMS
			
			public :
			
			#ifdef USB_Global_CID
			struct CID_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PRODUCT_ID           :32;
			
				//SOOL-USB_Global_CID-DECLARATION
			};
			#endif
			
			#ifdef USB_Global_DIEPTXF
			struct DIEPTXF_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t INEPTXSA             :16;
					uint32_t INEPTXFD             :16;
			
				//SOOL-USB_Global_DIEPTXF-DECLARATION
			};
			#endif
			
			#ifdef USB_Global_GAHBCFG
			struct GAHBCFG_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t GINT                 :1;
					uint32_t HBSTLEN              :4;
					uint32_t DMAEN                :1;
					uint32_t                      :1;
					uint32_t TXFELVL              :1;
					uint32_t PTXFELVL             :1;
					uint32_t                      :23;
			
				//SOOL-USB_Global_GAHBCFG-DECLARATION
			};
			#endif
			
			#ifdef USB_Global_GCCFG
			struct GCCFG_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef USB_Global_GCCFG_0
					struct
					{
						uint32_t USB_Global_GCCFG_0_DCDET :1;
						uint32_t USB_Global_GCCFG_0_PDET :1;
						uint32_t USB_Global_GCCFG_0_SDET :1;
						uint32_t USB_Global_GCCFG_0_PS2DET :1;
						uint32_t                      :12;
						uint32_t PWRDWN               :1;
						uint32_t USB_Global_GCCFG_0_I2CPADEN :1;
						uint32_t USB_Global_GCCFG_0_VBUSASEN :1;
						uint32_t USB_Global_GCCFG_0_VBUSBSEN :1;
						uint32_t USB_Global_GCCFG_0_SOFOUTEN :1;
						uint32_t USB_Global_GCCFG_0_NOVBUSSENS :1;
						uint32_t USB_Global_GCCFG_0_OTGIDEN :1;
						uint32_t USB_Global_GCCFG_0_PHYHSEN :1;
						uint32_t                      :8;
					};
					#endif
					#ifdef USB_Global_GCCFG_1
					struct
					{
						uint32_t                      :17;
						uint32_t USB_Global_GCCFG_1_BCDEN :1;
						uint32_t USB_Global_GCCFG_1_DCDEN :1;
						uint32_t USB_Global_GCCFG_1_PDEN :1;
						uint32_t USB_Global_GCCFG_1_SDEN :1;
						uint32_t VBDEN                :1;
						uint32_t                      :10;
					};
					#endif
				};
				//SOOL-USB_Global_GCCFG-DECLARATION
			};
			#endif
			
			#ifdef USB_Global_GHWCFG3
			struct GHWCFG3_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :14;
					uint32_t LPMMode              :1;
					uint32_t                      :17;
			
				//SOOL-USB_Global_GHWCFG3-DECLARATION
			};
			#endif
			
			#ifdef USB_Global_GINTMSK
			struct GINTMSK_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef USB_Global_GINTMSK_0
					struct
					{
						uint32_t                      :1;
						uint32_t MMISM                :1;
						uint32_t OTGINT               :1;
						uint32_t SOFM                 :1;
						uint32_t RXFLVLM              :1;
						uint32_t NPTXFEM              :1;
						uint32_t GINAKEFFM            :1;
						uint32_t GONAKEFFM            :1;
						uint32_t                      :2;
						uint32_t ESUSPM               :1;
						uint32_t USBSUSPM             :1;
						uint32_t USBRST               :1;
						uint32_t ENUMDNEM             :1;
						uint32_t ISOODRPM             :1;
						uint32_t EOPFM                :1;
						uint32_t                      :1;
						uint32_t EPMISM               :1;
						uint32_t IEPINT               :1;
						uint32_t OEPINT               :1;
						uint32_t IISOIXFRM            :1;
						uint32_t PXFRM_IISOOXFRM      :1;
						uint32_t FSUSPM               :1;
						uint32_t USB_Global_GINTMSK_0_RSTDETM :1;
						uint32_t PRTIM                :1;
						uint32_t HCIM                 :1;
						uint32_t PTXFEM               :1;
						uint32_t USB_Global_GINTMSK_0_LPMINTM :1;
						uint32_t CIDSCHGM             :1;
						uint32_t DISCINT              :1;
						uint32_t SRQIM                :1;
						uint32_t WUIM                 :1;
					};
					#endif
					#ifdef USB_Global_GINTMSK_1
					struct
					{
						uint32_t                      :23;
						uint32_t RSTDEM               :1;
						uint32_t                      :8;
					};
					#endif
				};
				//SOOL-USB_Global_GINTMSK-DECLARATION
			};
			#endif
			
			#ifdef USB_Global_GINTSTS
			struct GINTSTS_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CMOD                 :1;
					uint32_t MMIS                 :1;
					uint32_t OTGINT               :1;
					uint32_t SOF                  :1;
					uint32_t RXFLVL               :1;
					uint32_t NPTXFE               :1;
					uint32_t GINAKEFF             :1;
					uint32_t BOUTNAKEFF           :1;
					uint32_t                      :2;
					uint32_t ESUSP                :1;
					uint32_t USBSUSP              :1;
					uint32_t USBRST               :1;
					uint32_t ENUMDNE              :1;
					uint32_t ISOODRP              :1;
					uint32_t EOPF                 :1;
					uint32_t                      :2;
					uint32_t IEPINT               :1;
					uint32_t OEPINT               :1;
					uint32_t IISOIXFR             :1;
					uint32_t PXFR_INCOMPISOOUT    :1;
					uint32_t DATAFSUSP            :1;
					uint32_t USB_Global_GINTSTS_RSTDET :1;
					uint32_t HPRTINT              :1;
					uint32_t HCINT                :1;
					uint32_t PTXFE                :1;
					uint32_t USB_Global_GINTSTS_LPMINT :1;
					uint32_t CIDSCHG              :1;
					uint32_t DISCINT              :1;
					uint32_t SRQINT               :1;
					uint32_t WKUINT               :1;
			
				//SOOL-USB_Global_GINTSTS-DECLARATION
			};
			#endif
			
			#ifdef USB_Global_GLPMCFG
			struct GLPMCFG_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef USB_Global_GLPMCFG_0
					struct
					{
						uint32_t LPMEN                :1;
						uint32_t LPMACK               :1;
						uint32_t BESL                 :4;
						uint32_t REMWAKE              :1;
						uint32_t L1SSEN               :1;
						uint32_t BESLTHRS             :4;
						uint32_t L1DSEN               :1;
						uint32_t LPMRSP               :2;
						uint32_t SLPSTS               :1;
						uint32_t USB_Global_GLPMCFG_0_L1RSMOK :1;
						uint32_t LPMCHIDX             :4;
						uint32_t LPMRCNT              :3;
						uint32_t SNDLPM               :1;
						uint32_t LPMRCNTSTS           :3;
						uint32_t ENBESL               :1;
						uint32_t                      :3;
					};
					#endif
					#ifdef USB_Global_GLPMCFG_1
					struct
					{
						uint32_t                      :16;
						uint32_t L1ResumeOK           :1;
						uint32_t                      :15;
					};
					#endif
				};
				//SOOL-USB_Global_GLPMCFG-DECLARATION
			};
			#endif
			
			#ifdef USB_Global_GOTGCTL
			struct GOTGCTL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef USB_Global_GOTGCTL_0
					struct
					{
						uint32_t SRQSCS               :1;
						uint32_t SRQ                  :1;
						uint32_t USB_Global_GOTGCTL_0_VBVALOEN :1;
						uint32_t USB_Global_GOTGCTL_0_VBVALOVAL :1;
						uint32_t USB_Global_GOTGCTL_0_AVALOEN :1;
						uint32_t USB_Global_GOTGCTL_0_AVALOVAL :1;
						uint32_t USB_Global_GOTGCTL_0_BVALOEN :1;
						uint32_t USB_Global_GOTGCTL_0_BVALOVAL :1;
						uint32_t USB_Global_GOTGCTL_0_HNGSCS :1;
						uint32_t USB_Global_GOTGCTL_0_HNPRQ :1;
						uint32_t USB_Global_GOTGCTL_0_HSHNPEN :1;
						uint32_t USB_Global_GOTGCTL_0_DHNPEN :1;
						uint32_t USB_Global_GOTGCTL_0_EHEN :1;
						uint32_t                      :3;
						uint32_t USB_Global_GOTGCTL_0_CIDSTS :1;
						uint32_t USB_Global_GOTGCTL_0_DBCT :1;
						uint32_t USB_Global_GOTGCTL_0_ASVLD :1;
						uint32_t USB_Global_GOTGCTL_0_BSVLD :1;
						uint32_t USB_Global_GOTGCTL_0_OTGVER :1;
						uint32_t                      :11;
					};
					#endif
					#ifdef USB_Global_GOTGCTL_1
					struct
					{
						uint32_t                      :19;
						uint32_t BSESVLD              :1;
						uint32_t                      :12;
					};
					#endif
				};
				//SOOL-USB_Global_GOTGCTL-DECLARATION
			};
			#endif
			
			#ifdef USB_Global_GOTGINT
			struct GOTGINT_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :2;
					uint32_t SEDET                :1;
					uint32_t                      :5;
					uint32_t SRSSCHG              :1;
					uint32_t HNSSCHG              :1;
					uint32_t                      :7;
					uint32_t HNGDET               :1;
					uint32_t ADTOCHG              :1;
					uint32_t DBCDNE               :1;
					uint32_t USB_Global_GOTGINT_IDCHNG :1;
					uint32_t                      :11;
			
				//SOOL-USB_Global_GOTGINT-DECLARATION
			};
			#endif
			
			#ifdef USB_Global_GPWRDN
			struct GPWRDN_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t USB_Global_GPWRDN_ADPMEN :1;
					uint32_t                      :5;
					uint32_t USB_Global_GPWRDN_DISABLEVBUS :1;
					uint32_t                      :16;
					uint32_t USB_Global_GPWRDN_ADPIF :1;
					uint32_t                      :8;
			
				//SOOL-USB_Global_GPWRDN-DECLARATION
			};
			#endif
			
			#ifdef USB_Global_GRSTCTL
			struct GRSTCTL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CSRST                :1;
					uint32_t HSRST                :1;
					uint32_t FCRST                :1;
					uint32_t                      :1;
					uint32_t RXFFLSH              :1;
					uint32_t TXFFLSH              :1;
					uint32_t TXFNUM               :5;
					uint32_t                      :19;
					uint32_t DMAREQ               :1;
					uint32_t AHBIDL               :1;
			
				//SOOL-USB_Global_GRSTCTL-DECLARATION
			};
			#endif
			
			#ifdef USB_Global_GRXFSIZ
			struct GRXFSIZ_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RXFD                 :16;
					uint32_t                      :16;
			
				//SOOL-USB_Global_GRXFSIZ-DECLARATION
			};
			#endif
			
			#ifdef USB_Global_GRXSTSP
			struct GRXSTSP_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EPNUM                :4;
					uint32_t BCNT                 :11;
					uint32_t DPID                 :2;
					uint32_t PKTSTS               :4;
					uint32_t                      :11;
			
				//SOOL-USB_Global_GRXSTSP-DECLARATION
			};
			#endif
			
			#ifdef USB_Global_GRXSTSR
			struct GRXSTSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef USB_Global_GRXSTSR_0
					struct
					{
						uint32_t CHNUM                :4;
						uint32_t BCNT                 :11;
						uint32_t DPID                 :2;
						uint32_t PKTSTS               :4;
						uint32_t FRMNUM               :4;
						uint32_t                      :7;
					};
					#endif
					#ifdef USB_Global_GRXSTSR_1
					struct
					{
						uint32_t EPNUM                :4;
						uint32_t                      :28;
					};
					#endif
				};
				//SOOL-USB_Global_GRXSTSR-DECLARATION
			};
			#endif
			
			#ifdef USB_Global_GUSBCFG
			struct GUSBCFG_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TOCAL                :3;
					uint32_t USB_Global_GUSBCFG_PHYIF :1;
					uint32_t USB_Global_GUSBCFG_ULPI_UTMI_SEL :1;
					uint32_t                      :1;
					uint32_t PHYSEL               :1;
					uint32_t                      :1;
					uint32_t SRPCAP               :1;
					uint32_t HNPCAP               :1;
					uint32_t TRDT                 :4;
					uint32_t                      :1;
					uint32_t PHYLPCS              :1;
					uint32_t                      :1;
					uint32_t ULPIFSLS             :1;
					uint32_t ULPIAR               :1;
					uint32_t ULPICSM              :1;
					uint32_t ULPIEVBUSD           :1;
					uint32_t ULPIEVBUSI           :1;
					uint32_t TSDPS                :1;
					uint32_t PCCI                 :1;
					uint32_t PTCI                 :1;
					uint32_t ULPIIPD              :1;
					uint32_t                      :3;
					uint32_t FHMOD                :1;
					uint32_t FDMOD                :1;
					uint32_t CTXPKT               :1;
			
				//SOOL-USB_Global_GUSBCFG-DECLARATION
			};
			#endif
			
			#ifdef USB_Global_HPTXFSIZ
			struct HPTXFSIZ_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PTXSA                :16;
					uint32_t PTXFD                :16;
			
				//SOOL-USB_Global_HPTXFSIZ-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					GOTGCTL_TypeDef GOTGCTL; // @0x000
					GOTGINT_TypeDef GOTGINT; // @0x004
					GAHBCFG_TypeDef GAHBCFG; // @0x008
					GUSBCFG_TypeDef GUSBCFG; // @0x00c
					GRSTCTL_TypeDef GRSTCTL; // @0x010
					GINTSTS_TypeDef GINTSTS; // @0x014
					GINTMSK_TypeDef GINTMSK; // @0x018
					GRXSTSR_TypeDef GRXSTSR; // @0x01c
					GRXSTSP_TypeDef GRXSTSP; // @0x020
					GRXFSIZ_TypeDef GRXFSIZ; // @0x024
					uint32_t DIEPTXF0_HNPTXFSIZ; // @0x028
					uint32_t HNPTXSTS;   // @0x02c
					__SOOL_PERIPH_PADDING_8;
					GCCFG_TypeDef GCCFG; // @0x038
					CID_TypeDef CID;     // @0x03c
					USB_Global_MAP0_GSNPSID; // @0x040
					USB_Global_MAP0_GHWCFG1; // @0x044
					USB_Global_MAP0_GHWCFG2; // @0x048
					USB_Global_MAP0_GHWCFG3; // @0x04c
					__SOOL_PERIPH_PADDING_4;
					USB_Global_MAP0_GLPMCFG; // @0x054
					USB_Global_MAP0_GPWRDN; // @0x058
					USB_Global_MAP0_GDFIFOCFG; // @0x05c
					USB_Global_MAP0_GADPCTL; // @0x060
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					HPTXFSIZ_TypeDef HPTXFSIZ; // @0x100
					DIEPTXF_TypeDef DIEPTXF[15]; // @0x104
				};
			};
			private:
			USB_Global() = delete;
			//SOOL-USB_Global-DECLARATION
		};
		
		
		class USB_Host
		{
			//SOOL-USB_Host-ENUMS
			
			public :
			
			#ifdef USB_Host_HAINT
			struct HAINT_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t HAINT                :16;
					uint32_t                      :16;
			
				//SOOL-USB_Host_HAINT-DECLARATION
			};
			#endif
			
			#ifdef USB_Host_HAINTMSK
			struct HAINTMSK_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t HAINTM               :16;
					uint32_t                      :16;
			
				//SOOL-USB_Host_HAINTMSK-DECLARATION
			};
			#endif
			
			#ifdef USB_Host_HCFG
			struct HCFG_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FSLSPCS              :2;
					uint32_t FSLSS                :1;
					uint32_t                      :29;
			
				//SOOL-USB_Host_HCFG-DECLARATION
			};
			#endif
			
			#ifdef USB_Host_HFIR
			struct HFIR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FRIVL                :16;
					uint32_t                      :16;
			
				//SOOL-USB_Host_HFIR-DECLARATION
			};
			#endif
			
			#ifdef USB_Host_HFNUM
			struct HFNUM_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FRNUM                :16;
					uint32_t FTREM                :16;
			
				//SOOL-USB_Host_HFNUM-DECLARATION
			};
			#endif
			
			#ifdef USB_Host_HPTXSTS
			struct HPTXSTS_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PTXFSAVL             :16;
					uint32_t PTXQSAV              :8;
					uint32_t PTXQTOP              :8;
			
				//SOOL-USB_Host_HPTXSTS-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					HCFG_TypeDef HCFG;   // @0x000
					HFIR_TypeDef HFIR;   // @0x004
					HFNUM_TypeDef HFNUM; // @0x008
					__SOOL_PERIPH_PADDING_4;
					HPTXSTS_TypeDef HPTXSTS; // @0x010
					HAINT_TypeDef HAINT; // @0x014
					HAINTMSK_TypeDef HAINTMSK; // @0x018
				};
			};
			private:
			USB_Host() = delete;
			//SOOL-USB_Host-DECLARATION
		};
		
		
		class USB_HostChannel
		{
			//SOOL-USB_HostChannel-ENUMS
			
			public :
			
			#ifdef USB_HostChannel_HCCHAR
			struct HCCHAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MPSIZ                :11;
					uint32_t EPNUM                :4;
					uint32_t EPDIR                :1;
					uint32_t                      :1;
					uint32_t LSDEV                :1;
					uint32_t EPTYP                :2;
					uint32_t MC                   :2;
					uint32_t DAD                  :7;
					uint32_t ODDFRM               :1;
					uint32_t CHDIS                :1;
					uint32_t CHENA                :1;
			
				//SOOL-USB_HostChannel_HCCHAR-DECLARATION
			};
			#endif
			
			#ifdef USB_HostChannel_HCDMA
			struct HCDMA_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DMAADDR              :32;
			
				//SOOL-USB_HostChannel_HCDMA-DECLARATION
			};
			#endif
			
			#ifdef USB_HostChannel_HCINT
			struct HCINT_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t XFRC                 :1;
					uint32_t CHH                  :1;
					uint32_t AHBERR               :1;
					uint32_t STALL                :1;
					uint32_t NAK                  :1;
					uint32_t ACK                  :1;
					uint32_t NYET                 :1;
					uint32_t TXERR                :1;
					uint32_t BBERR                :1;
					uint32_t FRMOR                :1;
					uint32_t DTERR                :1;
					uint32_t                      :21;
			
				//SOOL-USB_HostChannel_HCINT-DECLARATION
			};
			#endif
			
			#ifdef USB_HostChannel_HCINTMSK
			struct HCINTMSK_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t XFRCM                :1;
					uint32_t CHHM                 :1;
					uint32_t AHBERR               :1;
					uint32_t STALLM               :1;
					uint32_t NAKM                 :1;
					uint32_t ACKM                 :1;
					uint32_t NYET                 :1;
					uint32_t TXERRM               :1;
					uint32_t BBERRM               :1;
					uint32_t FRMORM               :1;
					uint32_t DTERRM               :1;
					uint32_t                      :21;
			
				//SOOL-USB_HostChannel_HCINTMSK-DECLARATION
			};
			#endif
			
			#ifdef USB_HostChannel_HCSPLT
			struct HCSPLT_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PRTADDR              :7;
					uint32_t HUBADDR              :7;
					uint32_t XACTPOS              :2;
					uint32_t COMPLSPLT            :1;
					uint32_t                      :14;
					uint32_t SPLITEN              :1;
			
				//SOOL-USB_HostChannel_HCSPLT-DECLARATION
			};
			#endif
			
			#ifdef USB_HostChannel_HCTSIZ
			struct HCTSIZ_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t XFRSIZ               :19;
					uint32_t PKTCNT               :10;
					uint32_t DPID                 :2;
					uint32_t DOPING               :1;
			
				//SOOL-USB_HostChannel_HCTSIZ-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					HCCHAR_TypeDef HCCHAR; // @0x000
					HCSPLT_TypeDef HCSPLT; // @0x004
					HCINT_TypeDef HCINT; // @0x008
					HCINTMSK_TypeDef HCINTMSK; // @0x00c
					HCTSIZ_TypeDef HCTSIZ; // @0x010
					HCDMA_TypeDef HCDMA; // @0x014
				};
			};
			private:
			USB_HostChannel() = delete;
			//SOOL-USB_HostChannel-DECLARATION
		};
		
		
		class USB_INEndpoint
		{
			//SOOL-USB_INEndpoint-ENUMS
			
			public :
			
			#ifdef USB_INEndpoint_DIEPCTL
			struct DIEPCTL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MPSIZ                :11;
					uint32_t                      :4;
					uint32_t USBAEP               :1;
					uint32_t EONUM_DPID           :1;
					uint32_t NAKSTS               :1;
					uint32_t EPTYP                :2;
					uint32_t                      :1;
					uint32_t STALL                :1;
					uint32_t TXFNUM               :4;
					uint32_t CNAK                 :1;
					uint32_t SNAK                 :1;
					uint32_t SD0PID_SEVNFRM       :1;
					uint32_t SODDFRM              :1;
					uint32_t EPDIS                :1;
					uint32_t EPENA                :1;
			
				//SOOL-USB_INEndpoint_DIEPCTL-DECLARATION
			};
			#endif
			
			#ifdef USB_INEndpoint_DIEPDMA
			struct DIEPDMA_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DMAADDR              :32;
			
				//SOOL-USB_INEndpoint_DIEPDMA-DECLARATION
			};
			#endif
			
			#ifdef USB_INEndpoint_DIEPINT
			struct DIEPINT_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t XFRC                 :1;
					uint32_t EPDISD               :1;
					uint32_t                      :1;
					uint32_t TOC                  :1;
					uint32_t ITTXFE               :1;
					uint32_t                      :1;
					uint32_t INEPNE               :1;
					uint32_t TXFE                 :1;
					uint32_t TXFIFOUDRN           :1;
					uint32_t BNA                  :1;
					uint32_t                      :1;
					uint32_t PKTDRPSTS            :1;
					uint32_t BERR                 :1;
					uint32_t NAK                  :1;
					uint32_t                      :18;
			
				//SOOL-USB_INEndpoint_DIEPINT-DECLARATION
			};
			#endif
			
			#ifdef USB_INEndpoint_DIEPTSIZ
			struct DIEPTSIZ_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t XFRSIZ               :19;
					uint32_t PKTCNT               :10;
					uint32_t MULCNT               :2;
					uint32_t                      :1;
			
				//SOOL-USB_INEndpoint_DIEPTSIZ-DECLARATION
			};
			#endif
			
			#ifdef USB_INEndpoint_DTXFSTS
			struct DTXFSTS_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t INEPTFSAV            :16;
					uint32_t                      :16;
			
				//SOOL-USB_INEndpoint_DTXFSTS-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					DIEPCTL_TypeDef DIEPCTL; // @0x000
					__SOOL_PERIPH_PADDING_4;
					DIEPINT_TypeDef DIEPINT; // @0x008
					__SOOL_PERIPH_PADDING_4;
					DIEPTSIZ_TypeDef DIEPTSIZ; // @0x010
					DIEPDMA_TypeDef DIEPDMA; // @0x014
					DTXFSTS_TypeDef DTXFSTS; // @0x018
				};
			};
			private:
			USB_INEndpoint() = delete;
			//SOOL-USB_INEndpoint-DECLARATION
		};
		
		
		class USB_OUTEndpoint
		{
			//SOOL-USB_OUTEndpoint-ENUMS
			
			public :
			
			#ifdef USB_OUTEndpoint_DOEPCTL
			struct DOEPCTL_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MPSIZ                :11;
					uint32_t                      :4;
					uint32_t USBAEP               :1;
					uint32_t                      :1;
					uint32_t NAKSTS               :1;
					uint32_t EPTYP                :2;
					uint32_t SNPM                 :1;
					uint32_t STALL                :1;
					uint32_t                      :4;
					uint32_t CNAK                 :1;
					uint32_t SNAK                 :1;
					uint32_t SD0PID_SEVNFRM       :1;
					uint32_t SODDFRM              :1;
					uint32_t EPDIS                :1;
					uint32_t EPENA                :1;
			
				//SOOL-USB_OUTEndpoint_DOEPCTL-DECLARATION
			};
			#endif
			
			#ifdef USB_OUTEndpoint_DOEPINT
			struct DOEPINT_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t XFRC                 :1;
					uint32_t EPDISD               :1;
					uint32_t                      :1;
					uint32_t STUP                 :1;
					uint32_t OTEPDIS              :1;
					uint32_t USB_OUTEndpoint_DOEPINT_OTEPSPR :1;
					uint32_t B2BSTUP              :1;
					uint32_t                      :7;
					uint32_t NYET                 :1;
					uint32_t                      :17;
			
				//SOOL-USB_OUTEndpoint_DOEPINT-DECLARATION
			};
			#endif
			
			#ifdef USB_OUTEndpoint_DOEPTSIZ
			struct DOEPTSIZ_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t XFRSIZ               :19;
					uint32_t PKTCNT               :10;
					uint32_t STUPCNT              :2;
					uint32_t                      :1;
			
				//SOOL-USB_OUTEndpoint_DOEPTSIZ-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					DOEPCTL_TypeDef DOEPCTL; // @0x000
					__SOOL_PERIPH_PADDING_4;
					DOEPINT_TypeDef DOEPINT; // @0x008
					__SOOL_PERIPH_PADDING_4;
					DOEPTSIZ_TypeDef DOEPTSIZ; // @0x010
					uint32_t DOEPDMA;    // @0x014
				};
			};
			private:
			USB_OUTEndpoint() = delete;
			//SOOL-USB_OUTEndpoint-DECLARATION
		};
		
		//region instances
#if defined(STM32F042x6 ) || defined(STM32F048xx ) || defined(STM32F070x6 ) || defined(STM32F070xB ) ||\
    defined(STM32F072xB ) || defined(STM32F078xx ) || defined(STM32F102x6 ) || defined(STM32F102xB ) ||\
    defined(STM32F103x6 ) || defined(STM32F103xB ) || defined(STM32F103xE ) || defined(STM32F103xG ) ||\
    defined(STM32F302x8 ) || defined(STM32F302xC ) || defined(STM32F302xE ) || defined(STM32F303xC ) ||\
    defined(STM32F303xE ) || defined(STM32F373xC ) || defined(STM32L1     ) 
#define USB_BASE_ADDR ((uint32_t)0x40005C00U)
#endif

#if defined(STM32L432xx ) || defined(STM32L433xx ) || defined(STM32L442xx ) || defined(STM32L443xx ) ||\
    defined(STM32L452xx ) || defined(STM32L462xx ) 
#define USB_BASE_ADDR ((uint32_t)0x40006800U)
#endif

#ifdef USB_BASE_ADDR
volatile class USB * const USB = reinterpret_cast<class USB* const>(USB_BASE_ADDR);
#endif
//endregion

//SOOL-USB-DEFINES
//SOOL-USB-DEFINITION
	};
};//region undef
#undef USB_MAP0_BCDR
#undef USB_MAP0_EP0R
#undef USB_MAP0_EP1R
#undef USB_MAP0_EP2R
#undef USB_MAP0_EP3R
#undef USB_MAP0_EP4R
#undef USB_MAP0_EP5R
#undef USB_MAP0_EP6R
#undef USB_MAP0_EP7R
#undef USB_MAP0_CNTR
#undef USB_MAP0_ISTR
#undef USB_MAP0_FNR
#undef USB_MAP0_DADDR
#undef USB_MAP0_BTABLE
#undef USB_CNTR_0_LPMODE
#undef USB_CNTR_0_L1RESUME
#undef USB_CNTR_0_L1REQM
#undef USB_ISTR_0_L1REQ
#undef USB_MAP0_LPMCSR
#undef USB_CNTR_1_PMAOVR
#undef USB_Device_DOEPMSK_OTEPSPRM
#undef USB_Global_GOTGINT_IDCHNG
#undef USB_Global_MAP0_GSNPSID
#undef USB_Global_MAP0_GHWCFG1
#undef USB_Global_MAP0_GHWCFG2
#undef USB_Global_MAP0_GPWRDN
#undef USB_Global_MAP0_GADPCTL
#undef USB_Global_GCCFG_0_DCDET
#undef USB_Global_GCCFG_0_PDET
#undef USB_Global_GCCFG_0_SDET
#undef USB_Global_GCCFG_0_PS2DET
#undef USB_Global_GCCFG_1_BCDEN
#undef USB_Global_GCCFG_1_DCDEN
#undef USB_Global_GCCFG_1_PDEN
#undef USB_Global_GCCFG_1_SDEN
#undef USB_Global_GCCFG_0_I2CPADEN
#undef USB_Global_GCCFG_0_NOVBUSSENS
#undef USB_Global_GCCFG_0_VBUSASEN
#undef USB_Global_GCCFG_0_VBUSBSEN
#undef USB_Global_GCCFG_0_SOFOUTEN
#undef USB_Global_GOTGCTL_0_BSVLD
#undef USB_Global_GCCFG_0_OTGIDEN
#undef USB_Global_GCCFG_0_PHYHSEN
#undef USB_Global_GUSBCFG_PHYIF
#undef USB_Global_GUSBCFG_ULPI_UTMI_SEL
#undef USB_Global_GINTMSK_0_LPMINTM
#undef USB_Global_GINTSTS_LPMINT
#undef USB_Global_GOTGCTL_0_VBVALOEN
#undef USB_Global_GOTGCTL_0_VBVALOVAL
#undef USB_Global_GOTGCTL_0_AVALOEN
#undef USB_Global_GOTGCTL_0_AVALOVAL
#undef USB_Global_GOTGCTL_0_BVALOEN
#undef USB_Global_GOTGCTL_0_BVALOVAL
#undef USB_Global_MAP0_GHWCFG3
#undef USB_Global_MAP0_GLPMCFG
#undef USB_Global_MAP0_GDFIFOCFG
#undef USB_Global_GINTMSK_0_RSTDETM
#undef USB_Global_GINTSTS_RSTDET
#undef USB_Global_GLPMCFG_0_L1RSMOK
#undef USB_Global_GOTGCTL_0_EHEN
#undef USB_Global_GOTGCTL_0_OTGVER
#undef USB_OUTEndpoint_DOEPINT_OTEPSPR
#undef USB_Global_GPWRDN_DISABLEVBUS
#undef USB_Global_GOTGCTL_0_HNGSCS
#undef USB_Global_GOTGCTL_0_HNPRQ
#undef USB_Global_GOTGCTL_0_HSHNPEN
#undef USB_Global_GOTGCTL_0_DHNPEN
#undef USB_Global_GOTGCTL_0_CIDSTS
#undef USB_Global_GOTGCTL_0_DBCT
#undef USB_Global_GOTGCTL_0_ASVLD
#undef USB_Global_GPWRDN_ADPMEN
#undef USB_Global_GPWRDN_ADPIF
//endregion
#endif
#endif
