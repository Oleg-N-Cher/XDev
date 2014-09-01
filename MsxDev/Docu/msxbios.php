<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<head>
  <title>MSX BIOS calls</title>
  <meta http-equiv="Content-type" content="text/html; charset=UTF-8" />
  <meta http-equiv="Content-Style-Type" content="text/css" />
  <link rel="stylesheet" href="/css/map.css" type="text/css" />
  <link rel="stylesheet" href="/css/print.css" type="text/css" media="print" />
  <link rel="stylesheet" href="/css/classic.css" type="text/css" title="MAP Classic" />
  <link rel="alternate stylesheet" href="/css/modern.css" type="text/css" title="MAP Modern" />
  <link rel="alternate stylesheet" href="/css/experimental.css" type="text/css" title="MAP Experimental" />
</head>
<body>
<h1 id="head">MSX Assembly Page</h1>

<div id="menu">
<ul>
<li><a href="/">Main</a></li>
<li><a href="/articles/">Articles</a>
  <ul>
  <li><a href="/articles/#tutorials">Tutorials</a></li>
  <li><a href="/articles/#articles">Articles</a></li>
  <li><a href="/articles/#extarticles">External articles</a></li>
  </ul>
</li>
<li><a href="/resources/">Resources</a>
  <ul>
  <li><a href="/resources/#osdocs">OS documentation</a></li>
  <li><a href="/resources/#devicedocs">Device documentation</a></li>
  <li><a href="/resources/#swdocs">Software documentation</a></li>
  </ul>
</li>
<li><a href="/sources/">Sources</a>
  <ul>
  <li><a href="/sources/#code">Code examples</a></li>
  <li><a href="/sources/#source">Source code</a></li>
  <li><a href="/sources/#extsources">External sources</a></li>
  </ul>
</li>
<li><a href="/links/">Links</a>
  <ul>
  <li><a href="/links/#communities">Development communities</a></li>
  <li><a href="/links/#resources">Documentation resources</a></li>
  <li><a href="/links/#tools">Programming tools</a></li>
  </ul>
</li>
<li><a href="/contributing/">Contributing</a></li>
</ul>
</div>
<div id="content">



<h1>MSX BIOS calls</h1>

<p>This is an overview of all official MSX BIOS calls.</p>

<ul>
  <li><a href="#msx1bios">MSX 1 BIOS</a> (up till function call #159)</li>
  <li><a href="#msx2bios">MSX 2 BIOS</a> (up till function call #177)</li>
  <li><a href="#msx2pbios">MSX 2+ BIOS</a> (up till function call #17D)</li>
  <li><a href="#msxtrbios">MSX turbo R BIOS</a> (up till function call #189)</li>
</ul>


<h1 id="msx1bios">MSX 1 BIOS Entries</h1>

<h2>RST-and other routines</h2>

<h3 id="CHKRAM">CHKRAM (also called STARTUP, RESET or BOOT)</h3>
<pre>
Address  : #0000
Function : Tests RAM and sets RAM slot for the system
Registers: All
Remark   : After this, a jump must be made to INIT, for further initialisation.
</pre> 


<h3 id="SYNCHR">SYNCHR</h3>
<pre>
Address  : #0008
Function : tests whether the character of [HL] is the specified character
           if not, it generates SYNTAX ERROR, otherwise it goes to CHRGTR (#0010)
Input    : set the character to be tested in [HL] and the character to be
           compared next to RST instruction which calls this routine (inline parameter)
Output   : HL is increased by one and A receives [HL], When the tested character is
           numerical, the CY flag is set the end of the statement (00h or 3Ah) causes
           the Z flag to be set
Registers: AF, HL
</pre>

 
<h3 id="RDSLT">RDSLT</h3>
<pre>
Address  : #000C
Function : Reads the value of an address in another slot
Input    : A  - ExxxSSPP
           |        || Primary  slotnumber  (00-11)
           |        - Secundary slotnumber (00-11)
           +----------- Expanded slot (0 = no, 1 = yes)
           HL - Address to read
Output   : A  - Contains the vaule of the read address
Registers: AF, C, DE
Remark   : This routine turns off the interupt, but won't turn it on again
</pre>


<h3 id="CHRGTR">CHRGTR</h3>
<pre>
Address  : #0010
Function : Gets the next character (or token) of the Basic-text
Input    : HL - Address last character
Output   : HL - points to the next character
           A  - contains the character
           C  - flag set if it's a number
           Z  - flag set if it's the end of the statement
Registers: AF, HL
</pre>


<h3 id="WRSLT">WRSLT</h3>
<pre>
Address  : #0014
Function : Writes a value to an address in another slot.
Input    : A  - Slot in which the value will be written
           see RDSLT for input
           HL - Address of value to write
           E  - value to write
Registers: AF, BC, D
Remark   : See RDSLT
</pre>


<h3 id="OUTDO">OUTDO</h3>
<pre>
Address  : #0018
Function : Output to current outputchannel (printer, diskfile, etc.)
Input    : A  - PRTFIL, PRTFLG
Remark   : Used in basic, in ML it's pretty difficult
</pre>


<h3 id="CALSLT">CALSLT</h3>
<pre>
Address  : #001C
Function : Executes inter-slot call.
Input    : IY - High byte with input for A in RDSLT
           IX - The address that will be called
Remark   : Variables can never be given in alternative registers
           of the Z-80 or IX and IY
</pre>


<h3 id="DCOMPR">DCOMPR</h3>
<pre>
Address  : #0020
Function : Compares HL with DE
Input    : HL, DE
Output   : Z-flag set if HL and DE are the same.
Registers: AF
</pre>


<h3 id="ENASLT">ENASLT</h3>
<pre>
Address  : #0024
Function : Switches indicated slot at indicated page on perpetual
Input    : A  - ExxxSSPP
                +-?------ see RDSLT
           H - Bit 6 and 7 must contain the page number (00-11)
</pre>


<h3 id="GETYPR">GETYPR</h3>
<pre>
Address  : #0028
Function : Returns Type of DAC
Input    : DAC
Output   : S,Z,P/V, CY
Registers: AF
Remark   : Not a very clear routine to me, please mail us if you know more about it.
</pre>


<h3 id="CALLF">CALLF</h3>
<pre>
Address  : #0030
Function : Executes an interslot call
Output   : depends on the calling routine
Registers: AF, and the other registers depending on the calling routine
Remark   : The following is the calling sequence:
           RST #30
           DB destination slot (see RDSLT accu)
           DW destination address
</pre>


<h3 id="KEYINT">KEYINT</h3>
<pre>
Address  : #0038
Function : Executes the timer interrupt process routine
</pre>


<h2>Initialization-routines</h2>

<h3 id="INITIO">INITIO</h3>
<pre>
Address  : #003B
Function : Initialises the device
Registers: All
</pre>


<h3 id="INIFNK">INIFNK</h3>
<pre>
Address  : #003E
Function : Initialises the contents of the function keys
Registers: All
</pre>


<h2>VDP routines</h2>

<h3 id="DISSCR">DISSCR</h3>
<pre>
Address  : #0041
Function : inhibits the screen display
Registers: AF, BC
</pre>


<h3 id="ENASCR">ENASCR</h3>
<pre>
Address  : #0044
Function : displays the screen
Registers: AF, BC
</pre>


<h3 id="WRTVDP">WRTVDP</h3>
<pre>
Address  : #0047
Function : write data in the VDP-register
Input    : B  - data to write
           C  - number of the register
Registers: AF, BC
</pre>


<h3 id="RDVRM">RDVRM</h3>
<pre>
Address  : #004A
Function : Reads the content of VRAM
Input    : HL - address read
Output   : A  - value which was read
Registers: AF
</pre>


<h3 id="WRTVRM">WRTVRM</h3>
<pre>
Address  : #004D
Function : Writes data in VRAM
Input    : HL - address write
           A  - value write
Registers: AF
</pre>


<h3 id="SETRD">SETRD</h3>
<pre>
Address  : #0050
Function : Enable VDP to read
Input    : HL - for VRAM-address
Registers: AF
</pre>


<h3 id="SETWRT">SETWRT</h3>
<pre>
Address  : #0053
Function : Enable VDP to write
Input    : HL - Address
Registers: AF
</pre>


<h3 id="FILVRM">FILVRM</h3>
<pre>
Address  : #0056
Function : fill VRAM with value
Input    : A  - data byte
           BC - length of the area to be written
           HL - start address
Registers: AF, BC
</pre>


<h3 id="LDIRMV">LDIRMV</h3>
<pre>
Address  : #0059
Function : Block transfer to memory from VRAM
Input    : BC - blocklength
           DE - Start address of memory
           HL - Start address of VRAM
Registers: All
</pre>


<h3 id="LDIRVM">LDIRVM</h3>
<pre>
Address  : #005C
Function : Block transfer to VRAM from memory
Input    : BC - blocklength
           DE - Start address of VRAM
           HL - Start address of memory
Registers: All
</pre>


<h3 id="CHGMOD">CHGMOD</h3>
<pre>
Address  : #005F
Function : Switches to given screenmode
Input    : A  - screen mode
Registers: All
</pre>


<h3 id="CHGCLR">CHGCLR</h3>
<pre>
Address  : #0062
Function : Changes the screencolors
Input    : Foregroundcolor in FORCLR
           Backgroundcolor in BAKCLR
           Bordercolor in BDRCLR
Registers: All
</pre>


<h3 id="NMI">NMI</h3>
<pre>
Address  : #0066
Function : Executes (non-maskable interupt) handling routine
</pre>


<h3 id="CLRSPR">CLRSPR</h3>
<pre>
Address  : #0069
Function : Initialises all sprites
Input    : SCRMOD
Registers: Alles
</pre>


<h3 id="INITXT">INITXT</h3>
<pre>
Address  : #006C
Function : Schakelt naar SCREEN 0 (tekst-scherm met 40*24 tekens)
Input    : TXTNAM, TXTCGP
Registers: All
</pre>


<h3 id="INIT32">INIT32</h3>
<pre>
Address  : #006F
Function : Switches to SCREEN 1 (text screen with 32*24 characters)
Input    : T32NAM, T32CGP, T32COL, T32ATR, T32PAT
Registers: All
</pre>


<h3 id="INIGRP">INIGRP</h3>
<pre>
Address  : #0072
Function : Switches to SCREEN 2 (high resolution screen with 256*192 pixels)
Input    : GRPNAM, GRPCGP, GRPCOL, GRPATR, GRPPAT
Registers: All
</pre>


<h3 id="INIMLT">INIMLT</h3>
<pre>
Address  : #0075
Function : Switches to SCREEN 3 (multi-color screen 64*48 pixels)
Input    : MLTNAM, MLTCGP, MLTCOL, MLTATR, MLTPAT
Registers: All
</pre>


<h3 id="SETTXT">SETTXT</h3>
<pre>
Address  : #0078
Function : Switches to VDP in SCREEN 0 mode
Input    : See INITXT
Registers: All
</pre>


<h3 id="SETT32">SETT32</h3>
<pre>
Address  : #007B
Function : Schakelt VDP in SCREEN 1 modus
Input    : See INIT32
Registers: All
</pre>


<h3 id="SETGRP">SETGRP</h3>
<pre>
Address  : #007E
Function : Switches VDP to SCREEN 2 mode
Input    : See INIGRP
Registers: All
</pre>


<h3 id="SETMLT">SETMLT</h3>
<pre>
Address  : #0081
Function : Switches VDP to SCREEN 3 mode
Input    : See INIMLT
Registers: All
</pre>


<h3 id="CALPAT">CALPAT</h3>
<pre>
Address  : #0084
Function : Returns the address of the sprite pattern table
Input    : A  - Sprite ID
Output   : HL - For the address
Registers: AF, DE, HL
</pre>


<h3 id="CALATR">CALATR</h3>
<pre>
Address  : #0087
Function : Returns the address of the sprite attribute table
Input    : A  - Sprite number
Output   : HL - For the address
Registers: AF, DE, HL
</pre>


<h3 id="GSPSIZ">GSPSIZ</h3>
<pre>
Address  : #008A
Function : Returns current sprite size
Output   : A  - Sprite-size in bytes
           C-flag set when size is 16*16 sprites otherwise C-flag is reset
Registers: AF
</pre>


<h3 id="GRPPRT">GRPPRT</h3>
<pre>
Address  : #008D
Function : Displays a character on the graphic screen
Input    : A  - ASCII value of the character to print
</pre>


<h2>PSG routines</h2>


<h3 id="GICINI">GICINI</h3>
<pre>
Address  : #0090
Function : Initialises PSG and sets initial value for the PLAY statement
Registers: All
</pre>


<h3 id="WRTPSG">WRTPSG</h3>
<pre>
Address  : #0093
Function : Writes data to PSG-register
Input    : A  - PSG register number
           E  - data write
</pre>


<h3 id="RDPSG">RDPSG</h3>
<pre>
Address  : #0096
Function : Reads value from PSG-register
Input    : A  - PSG-register read
Output   : A  - value read
</pre>


<h3 id="STRTMS">STRTMS</h3>
<pre>
Address  : #0099
Function : Tests whether the PLAY statement is being executed as a background
           task. If not, begins to execute the PLAY statement
Registers: All
</pre>


<h2>Console routines</h2>

<h3 id="CHSNS">CHSNS</h3>
<pre>
Address  : #009C
Function : Tests the status of the keyboard buffer
Output   : Z-flag set if buffer is empty, otherwise not set
Registers: AF
</pre>


<h3 id="CHGET">CHGET</h3>
<pre>
Address  : #009F
Function : One character input (waiting)
Output   : A  - ASCII-code of the input character
Registers: AF
</pre>


<h3 id="CHPUT">CHPUT</h3>
<pre>
Address  : #00A2
Function : Displays one character
Input    : A  - ASCII-code of character to display
</pre>


<h3 id="LPTOUT">LPTOUT</h3>
<pre>
Address  : #00A5
Function : Sends one character to printer
Input    : A  - ASCII-code of character to send
Output   : C-flag set if failed
Registers: F
</pre>


<h3 id="LPTSTT">LPTSTT</h3>
<pre>
Address  : #00A8
Function : Tests printer status
Output   : A  - #FF and Z-flag reset if printer is ready
                #00 and Z-flag set if not ready
Registers: AF
</pre>


<h3 id="CNVCHR">CNVCHR</h3>
<pre>
Address  : #00AB
Function : tests for the graphic header and transforms the code
Input    : A  - charactercode
Output   : the C-flag is reset to not the graphic reader
           the C-flag and Z-flag are set to the transformed code is set in A
           the C-flag is set and Z-flag is reset to the untransformed code is set in A
Registers: AF
</pre>


<h3 id="PINLIN">PINLIN</h3>
<pre>
Address  : #00AE
Function : Stores in the specified buffer the character codes input until the return
           key or STOP key is pressed
Output   : HL - for the starting address of the buffer -1
           C-flag set when it ends with the STOP key
Registers: All
</pre>


<h3 id="INLIN">INLIN</h3>
<pre>
Address  : #00B1
Function : Same as PINLIN except that AUGFLG (#F6AA) is set
Output   : HL - for the starting address of the buffer -1
           C-flag set when it ends with the STOP key
Registers: All
</pre>


<h3 id="QINLIN">QINLIN</h3>
<pre>
Address  : #00B4
Function : Prints a questionmark andone space
Output   : HL - for the starting address of the buffer -1
           C-flag set when it ends with the STOP key
Registers: All
</pre>


<h3 id="BREAKX">BREAKX</h3>
<pre>
Address  : #00B7
Function : Tests status of CTRL-STOP
Output   : C-flag set when pressed
Registers: AF
Remark   : In this routine, interrupts are inhibited
</pre>


<h3 id="ISCNTC">ISCNTC</h3>
<pre>
Address  : #00BA
Function : Tests status of SHIFT-STOP
</pre>


<h3 id="CKCNTC">CKCNTC</h3>
<pre>
Address  : #00BD
Function : Same as ISCNTC. used in Basic
</pre>


<h3 id="BEEP">BEEP</h3>
<pre>
Address  : #00C0
Function : generates beep
Registers: All
</pre>


<h3 id="CLS">CLS</h3>
<pre>
Address  : #00C3
Function : Clears the screen
Registers: AF, BC, DE
Remark   : Z-flag must be set to be able to run this routine
           XOR A will do fine most of the time
</pre>


<h3 id="POSIT">POSIT</h3>
<pre>
Address  : #00C6
Function : Plaatst cursor op aangegeven positie
Input    : H  - Y coordinate of cursor
           L  - X coordinate of cursor
Registers: AF
</pre>


<h3 id="FNKSB">FNKSB</h3>
<pre>
Address  : #00C9
Function : Tests whether the function key display is active (FNKFLG)
           If so, displays them, otherwise erase them
Input    : FNKFLG (#FBCE)
Registers: All
</pre>


<h3 id="ERAFNK">ERAFNK</h3>
<pre>
Address  : #00CC
Function : Erase functionkey display
Registers: All
</pre>


<h3 id="DSPFNK">DSPFNK</h3>
<pre>
Address  : #00CF
Function : Displays the function keys
Registers: All
</pre>


<h3 id="TOTEXT">TOTEXT</h3>
<pre>
Address  : #00D2
Function : Forces the screen to be in the text mode
Registers: All
</pre>


<h2>Controller routines</h2>

<h3 id="GTSTCK">GTSTCK</h3>
<pre>
Address  : #00D5
Function : Returns the joystick status
Input    : A  - Joystick number to test (0 = cursors, 1 = port 1, 2 = port 2)
Output   : A  - Direction
Registers: All
</pre>


<h3 id="GTTRIG">GTTRIG</h3>
<pre>
Address  : #00D8
Function : Returns current trigger status
Input    : A  - trigger button to test
           0 = spacebar
           1 = port 1, button A
           2 = port 2, button A
           3 = port 1, button B
           4 = port 2, button B
Output   : A  - #00 trigger button not pressed
                #FF trigger button pressed
Registers: AF
</pre>


<h3 id="GTPAD">GTPAD</h3>
<pre>
Address  : #00DB
Function : Returns current touch pad status
Input    : A  - Touchpad number to test
Output   : A  - Value
Registers: All
</pre>


<h3 id="GTPDL">GTPDL</h3>
<pre>
Address  : #00DE
Function : Returns currenct value of paddle
Input    : A  - Paddle number
Output   : A  - Value
Registers: All
</pre>


<h2>Tape device routines</h2>

<h3 id="TAPION">TAPION</h3>
<pre>
Address  : #00E1
Function : Reads the header block after turning the cassette motor on
Output   : C-flag set if failed
Registers: All
</pre>


<h3 id="TAPIN">TAPIN</h3>
<pre>
Address  : #00E4
Function : Read data from the tape
Output   : A  - read value
           C-flag set if failed
Registers: All
</pre>


<h3 id="TAPIOF">TAPIOF</h3>
<pre>
Address  : #00E7
Function : Stops reading from the tape
</pre>


<h3 id="TAPOON">TAPOON</h3>
<pre>
Address  : #00EA
Function : Turns on the cassette motor and writes the header
Input    : A  - #00 short header
            not #00 long header
Output   : C-flag set if failed
Registers: All
</pre>


<h3 id="TAPOUT">TAPOUT</h3>
<pre>
Address  : #00ED
Function : Writes data on the tape
Input    : A  - data to write
Output   : C-flag set if failed
Registers: All
</pre>


<h3 id="TAPOOF">TAPOOF</h3>
<pre>
Address  : #00F0
Function : Stops writing on the tape
</pre>


<h3 id="STMOTR">STMOTR</h3>
<pre>
Address  : #00F3
Function : Sets the cassette motor action
Input    : A  - #00 stop motor
                #01 start motor
                #FF reverse the current action
Registers: AF
</pre>


<h2>Queue routines</h2>

<h3 id="LFTQ">LFTQ</h3>
<pre>
Address  : #00F6
Function : Gives number of bytes in queue
Output   : A  - length of queue in bytes
Remark   : Internal use
</pre>


<h3 id="PUTQ">PUTQ</h3>
<pre>
Address  : #00F9
Function : Put byte in queue
Remark   : Internal use
</pre>


<h2>Graphic routines</h2>

<h3 id="RIGHTC">RIGHTC</h3>
<pre>
Address  : #00FC
Function : Shifts screenpixel to the right
Registers: AF
</pre>


<h3 id="LEFTC">LEFTC</h3>
<pre>
Address  : #00FF
Function : Shifts screenpixel to the left
Registers: AF
</pre>


<h3 id="UPC">UPC</h3>
<pre>
Address  : #0102
Function : Shifts screenpixel up
Registers: AF
</pre>


<h3 id="TUPC">TUPC</h3>
<pre>
Address  : #0105
Function : Tests whether UPC is possible, if possible, execute UPC
Output   : C-flag set if operation would end outside the screen
Registers: AF
</pre>


<h3 id="DOWNC">DOWNC</h3>
<pre>
Address  : #0108
Function : Shifts screenpixel down
Registers: AF
</pre>


<h3 id="TDOWNC">TDOWNC</h3>
<pre>
Address  : #010B
Function : Tests whether DOWNC is possible, if possible, execute DOWNC
Output   : C-flag set if operation would end outside the screen
Registers: AF
</pre>


<h3 id="SCALXY">SCALXY</h3>
<pre>
Address  : #010E
Function : Scales X and Y coordinates
</pre>


<h3 id="MAPXY">MAPXY</h3>
<pre>
Address  : #0111
Function : Places cursor at current cursor address
</pre>


<h3 id="FETCHC">FETCHC</h3>
<pre>
Address  : #0114
Function : Gets current cursor addresses mask pattern
Output   : HL - Cursor address
           A  - Mask pattern
</pre>


<h3 id="STOREC">STOREC</h3>
<pre>
Address  : #0117
Function : Record current cursor addresses mask pattern
Input    : HL - Cursor address
           A  - Mask pattern
</pre>


<h3 id="SETATR">SETATR</h3>
<pre>
Address  : #011A
Function : Set attribute byte
</pre>


<h3 id="READC">READC</h3>
<pre>
Address  : #011D
Function : Reads attribute byte of current screenpixel
</pre>


<h3 id="SETC">SETC</h3>
<pre>
Address  : #0120
Function : Returns currenct screenpixel of specificed attribute byte
</pre>


<h3 id="NSETCX">NSETCX</h3>
<pre>
Address  : #0123
Function : Set horizontal screenpixels
</pre>


<h3 id="GTASPC">GTASPC</h3>
<pre>
Address  : #0126
Function : Gets screen relations
Output   : DE, HL
Registers: DE, HL
</pre>


<h3 id="PNTINI">PNTINI</h3>
<pre>
Address  : #0129
Function : Initalises the PAINT instruction
</pre>


<h3 id="SCANR">SCANR</h3>
<pre>
Address  : #012C
Function : Scans screenpixels to the right
</pre>


<h3 id="SCANL">SCANL</h3>
<pre>
Address  : #012F
Function : Scans screenpixels to the left
</pre>


<h2>Misc routines</h2>

<h3 id="CHGCAP">CHGCAP</h3>
<pre>
Address  : #0132
Function : Alternates the CAP lamp status
Input    : A  - #00 is lamp on
            not #00 is lamp off
Registers: AF
</pre>


<h3 id="CHGSND">CHGSND</h3>
<pre>
Address  : #0135
Function : Alternates the 1-bit sound port status
Input    : A  - #00 to turn off
            not #00 to turn on
Registers: AF
</pre>


<h3 id="RSLREG">RSLREG</h3>
<pre>
Address  : #0138
Function : Reads the primary slot register
Output   : A  - for the value which was read
           33221100
           ||||||- Pagina 0 (#0000-#3FFF)
           ||||--- Pagina 1 (#4000-#7FFF)
           ||----- Pagina 2 (#8000-#BFFF)
           ------- Pagina 3 (#C000-#FFFF)
Registers: A
</pre>


<h3 id="WSLREG">WSLREG</h3>
<pre>
Address  : #013B
Function : Writes value to the primary slot register
Input    : A  - value value to (see RSLREG)
</pre>


<h3 id="RDVDP">RDVDP</h3>
<pre>
Address  : #013E
Function : Reads VDP status register
Output   : A  - Value which was read
Registers: A
</pre>


<h3 id="SNSMAT">SNSMAT</h3>
<pre>
Address  : #0141
Function : Returns the value of the specified line from the keyboard matrix
Input    : A  - for the specified line
Output   : A  - for data (the bit corresponding to the pressed key will be 0)
Registers: AF
</pre>


<h3 id="PHYDIO">PHYDIO</h3>
<pre>
Address  : #0144
Function : Executes I/O for mass-storage media like diskettes
Input    : B  - Number of sectors
           C  - Media ID of the disk
           DE - Begin sector
           HL - Begin address in memory
Registers: All
Remark   : Before the call is called, the Z-flag must be reset, and the execution
           address which was in HL must be at the last stack address
           By the way: In minimum configuration only a HOOK is available
</pre>


<h3 id="FORMAT">FORMAT</h3>
<pre>
Address  : #0147
Function : Initialises mass-storage media like formatting of diskettes
Registers: All
Remark   : In minimum configuration only a HOOK is available
</pre>


<h3 id="ISFLIO">ISFLIO</h3>
<pre>
Address  : #014A
Function : Tests if I/O to device is taking place
Output   : A  - #00 if not taking place
            not #00 if taking place
Registers: AF
</pre>


<h3 id="OUTDLP">OUTDLP</h3>
<pre>
Address  : #014D
Function : Printer output
Input    : A  - code to print
Registers: F
Remark   : Differences with LPTOUT:
           1. TAB is expanded to spaces
           2. For non-MSX printers, Hiragana is transformed to katakana
              and graphic characters are transformed to 1-byte characters
           3. If failed, device I/O error occurs
</pre>


<h3 id="GETVCP">GETVCP</h3>
<pre>
Address  : #0150
Function : Returns pointer to play queue
Input    : A  - Channel number
Output   : HL - Pointer
Registers: AF
Remark   : Only used to play music in background
</pre>


<h3 id="GETVC2">GETVC2</h3>
<pre>
Address  : #0153
Function : Returns pointer to variable in queue number VOICEN (byte op #FB38)
Input    : L  - Pointer in play buffer
Output   : HL - Pointer
Registers: AF
</pre>


<h3 id="KILBUF">KILBUF</h3>
<pre>
Address  : #0156
Function : Clear keyboard buffer
Registers: HL
</pre>


<h3 id="CALBAS">CALBAS</h3>
<pre>
Address  : #0159
Function : Executes inter-slot call to the routine in BASIC interpreter
Input    : IX - for the calling address
Output   : Depends on the called routine
Registers: Depends on the called routine
</pre>


<h1 id="msx2bios">MSX 2 BIOS Entries</h1>

<h3 id="SUBROM">SUBROM</h3>
<pre>
Address  : #015C
Function : Calls a routine in SUB-ROM
Input    : IX - Address of routine in SUB-ROM
Output   : Depends on the routine
Registers: Alternative registers, IY
Remark   : Use of EXTROM or CALSLT is more convenient.
           In IX a extra value to the routine can be given by first
           PUSH'ing it to the stack.
</pre>


<h3 id="EXTROM">EXTROM</h3>
<pre>
Address  : #015F
Function : Calls a routine in SUB-ROM. Most common way
Input    : IX - Address of routine in SUB-ROM
Output   : Depends on the routine
Registers: Alternative registers, IY
Remark   : Use: LD IX,address
                CALL EXTROM
</pre>


<h3 id="CHKSLZ">CHKSLZ</h3>
<pre>
Address  : #0162
Function : Search slots for SUB-ROM
Registers: Alles
</pre>


<h3 id="CHKNEW">CHKNEW</h3>
<pre>
Address  : #0165
Function : Tests screen mode
Output   : C-flag set if screenmode = 5, 6, 7 or 8 
Registers: AF
</pre>


<h3 id="EOL">EOL</h3>
<pre>
Address  : #0168
Function : Deletes to the end of the line
Input    : H  - x-coordinate of cursor
           L  - y-coordinate of cursor
Registers: All
</pre>


<h3 id="BIGFIL">BIGFIL</h3>
<pre>
Address  : #016B
Function : Same function as FILVRM (total VRAM can be reached).
Input    : HL - address
           BC - length
           A  - data
Registers: AF,BC
</pre>


<h3 id="NSETRD">NSETRD</h3>
<pre>
Address  : #016E
Function : Same function as SETRD.(with full 16 bits VRAM-address)
Input    : HL - VRAM address
Registers: AF
</pre>


<h3 id="NSTWRT">NSTWRT</h3>
<pre>
Address  : #0171
Function : Same function as SETWRT.(with full 16 bits VRAM-address)
Input    : HL - VRAM address
Registers: AF
</pre>


<h3 id="NRDVRM">NRDVRM</h3>
<pre>
Address  : #0174
Function : Reads VRAM like in RDVRM.(with full 16 bits VRAM-address)
Input    : HL - VRAM address
Output   : A  - Read value
Registers: F
</pre>


<h3 id="NWRVRM">NWRVRM</h3>
<pre>
Address  : #0177
Function : Writes to VRAM like in WRTVRM.(with full 16 bits VRAM-address)
Input    : HL - VRAM address
           A  - Value to write
Registers: AF
</pre>



<h1 id="msx2pbios">MSX 2+ BIOS Entries</h1>

<h3 id="RDBTST">RDBTST</h3>
<pre>
Address  : #017A
Function : Read value of I/O poort #F4
Input    : none
Output   : A = value read
Registers: AF
</pre>


<h3 id="WRBTST">WRBTST</h3>
<pre>
Address  : #017D
Function : Write value to I/O poort #F4
Input    : A = value to write
           Bit 7 shows the MSX 2+ startup screen when reset, otherwise it's skipped.
Output   : none
Registers: none
</pre>



<h1 id="msxtrbios">MSX turbo R BIOS Entries</h1>

<h3 id="CHGCPU">CHGCPU</h3>
<pre>
Address  : #0180
Function : Changes CPU mode
Input    : A = LED 0 0 0 0 0 x x
                |            0 0 = Z80 (ROM) mode
                |            0 1 = R800 ROM  mode
                |            1 0 = R800 DRAM mode
               LED indicates whether the Turbo LED is switched with the CPU
Output   : none
Registers: none
</pre>


<h3 id="GETCPU">GETCPU</h3>
<pre>
Address  : #0183
Function : Returns current CPU mode
Input    : none
Output   : A = 0 0 0 0 0 0 x x
                           0 0 = Z80 (ROM) mode
                           0 1 = R800 ROM  mode
                           1 0 = R800 DRAM mode
Registers: AF
</pre>


<h3 id="PCMPLY">PCMPLY</h3>
<pre>
Address  : #0186
Function : Plays specified memory area through the PCM chip
Input    : A = v 0 0 0 0 0 x x
               |           | |
               |           +-+-- Quality parameter (Speed: 0 = Fast)
               +---------------- VRAM usage flag
           HL= Start address in RAM or VRAM
           BC= Length of area to play
           D = Bit 0 = Bit 17 of area length when using VRAM
           E = Bit 0 = Bit 17 os start address when using VRAM
Output   : C-flag set when aborted with CTRL-STOP
Registers: all
</pre>


<h3 id="PCMREC">PCMREC</h3>
<pre>
Address  : #0189
Function : Records audio using the PCM chip into the specified memory area
Input    : A = v t t t t c x x
               | | | | | | | |
               | | | | | | +-+-- Quality parameter (Speed: 0 = Fast)
               | | | | | +------ Zero-data compression
               | +-+-+-+-------- Treshold
               +---------------- VRAM usage flag
           HL= Start address in RAM or VRAM
           BC= Length of area to play
           D = Bit 0 = Bit 17 of area length when using VRAM
           E = Bit 0 = Bit 17 os start address when using VRAM
Output   : C-flag set when aborted with CTRL-STOP
Registers: all
</pre>

<p class="signed">BiFi</p>




</div>

<div id="foot">© 2014 MSX Assembly Page</div>
</body>
</html>