#!/usr/bin/python
# autogenerate C++ file information
# A Jeff Rubillo Product
import sys
if len(sys.argv) < 2:
    print "python cGenerator [classname]"
    exit(0)

# Header File
F = open (sys.argv[1]+".h", "w")
F.write("#ifndef __"+ sys.argv[1] + "_H__\n#define __"+ sys.argv[1] +"_H__\n\n")
F.write("#include <iostream>\n\n")
F.write("class "+ sys.argv[1] + " {\npublic:\n\t"+ sys.argv[1]+"();\n\t") # default
F.write(sys.argv[1] + "(const " + sys.argv[1] + "&);\n\t");
F.write("~" + sys.argv[1]+"();\n")
F.write("\nprivate:\n\n};\n\n#endif // __" + sys.argv[1] + "_H__")

F.close()

# .cpp File
F = open (sys.argv[1]+".cpp", "w")
F.write("#include " + '"' + sys.argv[1]+".h" + '"' +"\n\n")
F.write("\n"+sys.argv[1]+ "::" + sys.argv[1] + "() {\n\n}\n")
F.write("\n"+sys.argv[1]+ "::" + sys.argv[1] + "(const " + sys.argv[1] +" &other) {\n\n}\n")
F.write("\n"+sys.argv[1]+ "::~" + sys.argv[1] + "() {\n\n}\n")

F.close()
