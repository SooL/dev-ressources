import argparse
import typing as T
import re
parser = argparse.ArgumentParser(description="Pin aliasing generation tool for SooL")

parser.add_argument("cube_report",
					help="File to read")
parser.add_argument("-n","--namespace",
					default=None,
					required=False,
					help="Specify a namespace name to encapsulate the pin mapping")
parser.add_argument("output_name",
					help="Output files path, without extension")

def extract_data(data_in : str) -> str :
	start = "Pin Nb\tPINs\tFUNCTIONs\tLABELs"
	start_position = data_in.rfind(start) + len(start)
	end_position = data_in.find("\n\n",start_position)
	
	return data_in[start_position:end_position]

def parse_report(report : str) -> T.Dict[str,str] :
	regex = re.compile(r"(P\w\d\d?)")
	out = dict()
	print("Report parsing")
	for line in report.split("\n") :
		if len(line) == 0 :
			continue
		fields = line.strip().split("\t")
		match = regex.match(fields[1])
		if not match :
			print("\tInvalid field", fields[1])
			continue
		
		
		fields[1] = match.group(1)
		
		print("\tFound",fields[1], "mapped to",fields[-1])
		out[fields[1]] = fields[-1]
	return out
		
def cpp_generation(data : T.Dict[str,str],namespace : str, filename : str) :
	generic_template = "volatile StandAlone_Pin< {pin_number:2s}>& {alias:20s}= {pin};"

	out = "#include \"" + filename + ".h\"\n"
	out += "#include \"GPIO.h\"\n"
	if namespace is not None :
		out += "namespace " + namespace + "\n{\n"
	last_port = None
	for pin in sorted(data.keys(),key=lambda x : ord(x[1])*100 + int(x[2:])) :
		if namespace is not None :
			out += "\t"
		if last_port is not None and pin[1] != last_port :
			out += "\n"
		last_port = pin[1]
		out += generic_template.format(pin=pin,pin_number=pin[2:],alias=data[pin]) + "\n"
	
	if namespace is not None :
		out += "}"
	
	return out

def h_generation(data : T.Dict[str,str],namespace : str, filename : str) :
	generic_template = "extern volatile sool::ll::StandAlone_Pin < {pin_number:2s}>& {alias};"
	
	out = "#ifndef H_" + filename.capitalize() + "\n"
	out += "#define H_" + filename.capitalize() + "\n"
	out += "#include \"GPIO.h\"\n"
	
	if namespace is not None :
		out += "namespace " + namespace + "\n{\n"
	last_port = None
	for pin in sorted(data.keys(),key=lambda x : ord(x[1]) * 100 + int(x[2 :])) :
		if namespace is not None :
			out += "\t"
		if last_port is not None and pin[1] != last_port :
			out += "\n"
		last_port = pin[1]
		out += generic_template.format(pin=pin,pin_number=pin[2 :],alias=data[pin]) + "\n"
	
	if namespace is not None :
		out += "}"
	
	out += "\n#endif"
	return out

if __name__ == "__main__" :
	
	args = parser.parse_args()
	
	with open(args.cube_report,"r") as report :
		data = report.read()
	
		data = parse_report(extract_data(data))
		#print(cpp_generation(data,args.namespace))
	
		with open(args.output_name + ".h","w") as header :
			header.write(h_generation(data,args.namespace,args.output_name))
			
		with open(args.output_name + ".cpp","w") as cpp :
			cpp.write(cpp_generation(data,args.namespace,args.output_name))