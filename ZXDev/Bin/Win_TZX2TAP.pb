;/ TZX2TAP Converter
; (c) 2010 By LCD
; Written using PureBasic 4.41
; This Software is Open Source
; No WinAPI Calls used, so multiplatform-compatible
version$="0.21"
; Added: Column witdhs now saved in Preference file
directory$=GetCurrentDirectory()

Global *Buffer=AllocateMemory(65536)
Procedure.s GetFileName(Filename$); Without suffixes
  len=Len(Filename$):Pos=len
  For a=1 To len
    If Mid(Filename$,a,1)="."
      Pos=a
    EndIf
  Next a
  ProcedureReturn Left(Filename$,Pos-1)
EndProcedure
Procedure TZX2TAP(Filename$)
  Shared Report
  Out$=GetFileName(Filename$)+".tap"
  error=0
  fileIn=ReadFile(#PB_Any,Filename$)
  If fileIn And FileSize(Out$)<1
    fileout=CreateFile(#PB_Any,Out$)
    If fileout
      ReadData(fileIn,*Buffer,10)
      ID$=PeekS(*Buffer,7)
      If ID$="ZXTape!" And PeekB(*Buffer+7)&$FF=$1A
        Repeat
          id=ReadByte(fileIn)&255
          Select id
            Case $10
              pause=ReadWord(fileIn)&$FFFF
              length=ReadWord(fileIn)&$FFFF
              ReadData(fileIn,*Buffer,length)
              WriteWord(fileout,length)
              WriteData(fileout,*Buffer,length)
            Case $11
              Pilot=ReadWord(fileIn)&$FFFF
              Sync0=ReadWord(fileIn)&$FFFF
              Sync1=ReadWord(fileIn)&$FFFF
              Pulse0=ReadWord(fileIn)&$FFFF
              Pulse1=ReadWord(fileIn)&$FFFF
              Tone=ReadWord(fileIn)&$FFFF
              lastbits=ReadByte(fileIn)&255
              pause=ReadWord(fileIn)&$FFFF
              length=ReadWord(fileIn)&$FFFF+ReadByte(fileIn)<<16
              If length>65535
                length=65535
                AddGadgetItem(Report,-1,Out$+": size over 65535 bytes cannot be saved in TAP")
              EndIf
              ReadData(fileIn,*Buffer,length)
              WriteWord(fileout,length)
              WriteData(fileout,*Buffer,length)
            Case $12 To $13,$15 To $1F
              error=1
              error$="Unsupported!"
              AddGadgetItem(Report,-1,Out$+": Unsupported block found ($"+Hex(id)+")")
            Case $14
              Pulse0=ReadWord(fileIn)&$FFFF
              Pulse1=ReadWord(fileIn)&$FFFF
              lastbits=ReadByte(fileIn)&255
              pause=ReadWord(fileIn)&$FFFF
              length=ReadWord(fileIn)&$FFFF+ReadByte(fileIn)<<16
              If length>65535
                length=65535
                AddGadgetItem(Report,-1,Out$+": size over 65535 bytes cannot be saved in TAP")
              EndIf
              ReadData(fileIn,*Buffer,length)
              WriteWord(fileout,length)
              WriteData(fileout,*Buffer,length)
            Case $20
              ReadWord(fileIn)
            Case $21,$30
              length=ReadByte(fileIn)&255
              ReadData(fileIn,*Buffer,length)
              text$=PeekS(*Buffer,length)
            Case $22 To $29
            Case $2A
              ReadLong(fileIn)
            Case $31
              pause=ReadByte(fileIn)&255
              length=ReadByte(fileIn)&255
              ReadData(fileIn,*Buffer,length)
              text$=PeekS(*Buffer,length)
            Case $32
              length=ReadWord(fileIn)&$FFFF
              ReadData(fileIn,*Buffer,length)
              text$=PeekS(*Buffer,length)
            Case $33
              Infos=ReadByte(fileIn)&$FF
              ReadData(fileIn,*Buffer,Infos*3)
            Case $35
              ReadData(fileIn,*Buffer,10)
              length=ReadWord(fileIn)&$FFFF
              ReadData(fileIn,*Buffer,length)
            Case $5A
              ReadData(fileIn,*Buffer,9)
          EndSelect
        Until Eof(fileIn) Or error
        CloseFile(fileout)
      EndIf
    EndIf
    CloseFile(fileIn)
  EndIf
EndProcedure
CompilerSelect #PB_Compiler_OS ;{
  CompilerCase #PB_OS_Linux
    sys$="Tux_"
  CompilerCase #PB_OS_MacOS
    sys$="Mac_"
  CompilerCase #PB_OS_Windows
    sys$="Win_"
CompilerEndSelect ;}


a=OpenPreferences("tzx2tap.ini") ;{ Load Preferences from ini
ExaminePreferenceGroups()
PreferenceGroup("001") ;{
win_posx=ReadPreferenceLong("WinPosX",0)
win_posy=ReadPreferenceLong("WinPosY",0)
win_sizx=ReadPreferenceLong("WinSizX",1021)
win_sizy=ReadPreferenceLong("WinSizY",700)
splitterA=ReadPreferenceLong("Splitter1",200)
splitterB=ReadPreferenceLong("Splitter2",500)
directory$=ReadPreferenceString("Currentdir",directory$)
column0=ReadPreferenceLong("column0",300)
column1=ReadPreferenceLong("column1",100)
column2=ReadPreferenceLong("column2",100)
column3=ReadPreferenceLong("column3",100)
ClosePreferences() ;}
;}

window=OpenWindow(#PB_Any,win_posx,win_posy,win_sizx,win_sizy,sys$+"TZX2TAP v. "+version$+" Written in 2010 by LCD",#PB_Window_SystemMenu|#PB_Window_MinimizeGadget|#PB_Window_SizeGadget)
CompilerIf #PB_Compiler_OS=#PB_OS_Windows ;{
  SmartWindowRefresh(window,1)
CompilerEndIf ;}

TZXDirs=ExplorerTreeGadget(#PB_Any,0,0,200,500,directory$,#PB_Explorer_AlwaysShowSelection|#PB_Explorer_NoFiles|#PB_Explorer_NoDriveRequester|#PB_Explorer_AutoSort)
TZXFiles=ExplorerListGadget(#PB_Any,200,0,700,500,directory$+"*.tzx",#PB_Explorer_AlwaysShowSelection|#PB_Explorer_MultiSelect|#PB_Explorer_GridLines|#PB_Explorer_FullRowSelect|#PB_Explorer_NoFolders|#PB_Explorer_NoParentFolder|#PB_Explorer_NoDirectoryChange|#PB_Explorer_NoDriveRequester|#PB_Explorer_AutoSort)

SetGadgetItemAttribute(TZXFiles,0,#PB_Explorer_ColumnWidth,column0,0)
SetGadgetItemAttribute(TZXFiles,0,#PB_Explorer_ColumnWidth,column1,1)
SetGadgetItemAttribute(TZXFiles,0,#PB_Explorer_ColumnWidth,column2,2)
SetGadgetItemAttribute(TZXFiles,0,#PB_Explorer_ColumnWidth,column3,3)


Report=EditorGadget(#PB_Any,0,500,920,200,#PB_Editor_ReadOnly)
splitter1=SplitterGadget(#PB_Any,0,0,920,500,TZXDirs,TZXFiles,#PB_Splitter_Vertical|#PB_Splitter_Separator)
splitter2=SplitterGadget(#PB_Any,0,0,920,700,splitter1,Report,#PB_Splitter_Separator)
ConvertButton=ButtonGadget(#PB_Any,900,0,120,29,"Convert to TAP")
Gosub resizing
SetGadgetState(splitter1,splitterA)
SetGadgetState(splitter2,splitterB)
Repeat
wwe=WaitWindowEvent()
If wwe=#PB_Event_Gadget;{
  Select EventGadget()
    Case TZXDirs
      SetGadgetText(TZXFiles,GetGadgetText(TZXDirs))
    Case ConvertButton
      Gosub conversion
  EndSelect ;}
ElseIf wwe=#PB_Event_SizeWindow ;{
  Gosub resizing
EndIf ;}
Until wwe=#PB_Event_CloseWindow

a=CreatePreferences("tzx2tap.ini") ;{ Save Preferences
PreferenceGroup("001") ;{
WritePreferenceLong("WinPosX",WindowX(window))
WritePreferenceLong("WinPosY",WindowY(window))
WritePreferenceLong("WinSizX",WindowWidth(window))
WritePreferenceLong("WinSizY",WindowHeight(window))
WritePreferenceLong("Splitter1",GetGadgetState(splitter1))
WritePreferenceLong("Splitter2",GetGadgetState(splitter2))
WritePreferenceString("Currentdir",GetGadgetText(TZXDirs))
WritePreferenceLong("column0",GetGadgetItemAttribute(TZXFiles,0,#PB_Explorer_ColumnWidth,0))
WritePreferenceLong("column1",GetGadgetItemAttribute(TZXFiles,0,#PB_Explorer_ColumnWidth,1))
WritePreferenceLong("column2",GetGadgetItemAttribute(TZXFiles,0,#PB_Explorer_ColumnWidth,2))
WritePreferenceLong("column3",GetGadgetItemAttribute(TZXFiles,0,#PB_Explorer_ColumnWidth,3))

ClosePreferences() ;}
;}
CloseWindow(window)
End

resizing: ;{
sizex=WindowWidth(window)
sizey=WindowHeight(window)
ResizeGadget(splitter2,#PB_Ignore,#PB_Ignore,sizex-121,sizey)
ResizeGadget(ConvertButton,sizex-120,#PB_Ignore,#PB_Ignore,#PB_Ignore)
;}
conversion: ;{
ClearGadgetItems(Report)
HideGadget(TZXFiles,1)
For a=0 To CountGadgetItems(TZXFiles)-1
  dir$=GetGadgetText(TZXFiles)
  If GetGadgetItemState(TZXFiles,a)&#PB_Explorer_Selected
    Filename$=GetGadgetItemText(TZXFiles,a,0)
    ext$=LCase(GetExtensionPart(Filename$))
    If ext$="tzx"
      fullpath$=dir$+Filename$
      b=GetFileAttributes(fullpath$)
      TZX2TAP(fullpath$)
      AddGadgetItem(Report,-1,Filename$)
    EndIf
  EndIf
Next a
HideGadget(TZXFiles,0)
Return ;} 
; jaPBe Version=3.10.2.823
; FoldLines=000A00120013006B006C00730088008A009E00A400A500A700BD00C200C300D4
; Build=15
; Language=0x0000 Language Neutral
; FirstLine=0
; CursorPosition=6
; ExecutableFormat=Windows
; Executable=D:\Win_TZX2TAP v0.21.exe
; DontSaveDeclare
; EOF