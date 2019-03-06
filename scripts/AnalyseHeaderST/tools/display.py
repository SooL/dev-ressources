#!/usr/bin/python3
#-*-coding:utf-8 -*

def display(obj, order = True) :
	out = ""
	if type(obj) == type(list()) :
		if order :
			for e in sorted(obj) :
				out += e + "\n"
		else :
			for e in obj :
				out += e + "\n"
	
	if type(obj) == type(dict()) :
		if order :
			for k in sorted(obj.keys()) :
				if type(obj[k]) == type (list()) :
					for v in sorted(obj[k]) :
						out += k + " \t=" + v + "\n"
				else :
					out += str(k) + " \t= " + str(obj[k]) + "\n"
					
	print(out)

def toBin(val : int,  lenght = int(0)) :
	out = ""
	tempValue = val
	while tempValue > 0 :
		out += "1" if tempValue & 1 else "0"
		tempValue >>= 1
		
	while lenght > len(out) :
		out += "0"
	
	if lenght <= 0 : lenght = len(out)
	return out[::-1][0:lenght]

def lenAdj(txt,fullLen : int,fill = ' ') :
	txt = str(txt)
	if len(txt) > fullLen :
		raise RuntimeError("Length of " + txt + " (" + str(len(txt)) +") superior to fullLen (" + str(fullLen) + ")")

	txt += fill * (fullLen - len(txt))
	return txt
