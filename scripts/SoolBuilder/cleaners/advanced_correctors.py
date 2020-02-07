import re

def CAN_periph_advanced_cleaner(periph: "Peripheral") :
	from structure import Peripheral, MappingElement
	for m in periph.mappings :
		if "F0R1" in m and not "sFilterRegister" in periph :
			F0R1 = m["F0R1"]; F0R2 = m["F0R2"]
			FRx = F0R1.component
			FRx.name = "FRx"

			array_size = len(list(filter(lambda elmt : re.match("^F\d+R1", elmt.name), m.elements)))
			if len(list(filter(lambda elmt : elmt.component is FRx, m.elements))) != (array_size * 2) :
				raise AssertionError("different registers for CAN filters")

			address = F0R1.address
			filter_register_sub_periph = Peripheral(FRx.chips, "FilterRegister", "CAN Filter Register")
			filter_register_sub_periph.add_register(FRx)
			filter_register_sub_periph.place_component(FRx, 0, "FR1")
			filter_register_sub_periph.place_component(FRx, F0R2.address - F0R1.address, "FR2")
			periph.add_register(filter_register_sub_periph)
			periph.place_array(component=filter_register_sub_periph, address=address, name="sFilterRegister",
			                   array_size=array_size)
			m.remove_elements_for(FRx)

		if "TI0R" in m and not "TxMailBox" in periph :
			TI0R, TDT0R, TDL0R, TDH0R = m["TI0R"], m["TDT0R"], m["TDL0R"], m["TDH0R"]
			TIR, TDTR, TDLR, TDHR = TI0R.component, TDT0R.component, TDL0R.component, TDH0R.component
			TIR.name, TDTR.name, TDLR.name, TDHR.name = "TIR", "TDTR", "TDLR", "TDHR"
			array_size = len(list(filter(lambda elmt : re.match("^TI\d*R", elmt.name), m.elements)))
			address = TI0R.address
			mailbox_sub_periph = Peripheral(TIR.chips, "TxMailBox", "CAN Tx MailBox")
			mailbox_sub_periph.add_register(TIR)
			mailbox_sub_periph.add_register(TDTR)
			mailbox_sub_periph.add_register(TDLR)
			mailbox_sub_periph.add_register(TDHR)
			mailbox_sub_periph.place_component(TIR, 0)
			mailbox_sub_periph.place_component(TDTR, TDT0R.address-TI0R.address)
			mailbox_sub_periph.place_component(TDLR, TDL0R.address-TI0R.address)
			mailbox_sub_periph.place_component(TDHR, TDH0R.address-TI0R.address)
			periph.add_register(mailbox_sub_periph)
			periph.place_array(component=mailbox_sub_periph, address=TI0R.address, name="sTxMailBox",
			                   array_size=array_size)
			i = 0
			while i < len(m.elements) :
				if re.match("^T(I|D[TLH])\d*R", m.elements[i].name) :
					m.remove_element(m.elements[i])
				else : i += 1

		if "RI0R" in m and not "RxMailBox" in periph :
			RI0R, RDT0R, RDL0R, RDH0R = m["RI0R"], m["RDT0R"], m["RDL0R"], m["RDH0R"]
			RIR, RDTR, RDLR, RDHR = RI0R.component, RDT0R.component, RDL0R.component, RDH0R.component
			RIR.name, RDTR.name, RDLR.name, RDHR.name = "RIR", "RDTR", "RDLR", "RDHR"

			array_size = len(list(filter(lambda elmt : re.match("^RI\d*R", elmt.name), m.elements)))
			address = RI0R.address
			mailbox_sub_periph = Peripheral(RIR.chips, "FIFOMailBox", "CAN Rx MailBox")
			mailbox_sub_periph.add_register(RIR)
			mailbox_sub_periph.add_register(RDTR)
			mailbox_sub_periph.add_register(RDLR)
			mailbox_sub_periph.add_register(RDHR)
			mailbox_sub_periph.place_component(RIR, 0)
			mailbox_sub_periph.place_component(RDTR, RDT0R.address-RI0R.address)
			mailbox_sub_periph.place_component(RDLR, RDL0R.address-RI0R.address)
			mailbox_sub_periph.place_component(RDHR, RDH0R.address-RI0R.address)
			periph.add_register(mailbox_sub_periph)
			periph.place_array(component=mailbox_sub_periph, address=RI0R.address, name="sFIFOMailBox",
			                   array_size=array_size)

			i = 0
			while i < len(m.elements) :
				if re.match("^R(I|D[TLH])\d*R", m.elements[i].name) :
					m.remove_element(m.elements[i])
				else : i += 1
