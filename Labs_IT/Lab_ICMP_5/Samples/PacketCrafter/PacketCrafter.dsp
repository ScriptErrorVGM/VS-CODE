# Microsoft Developer Studio Project File - Name="PacketCrafter" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=PacketCrafter - Win32 MFC
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "PacketCrafter.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PacketCrafter.mak" CFG="PacketCrafter - Win32 MFC"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PacketCrafter - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "PacketCrafter - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "PacketCrafter - Win32 MFC Release" (based on "Win32 (x86) Application")
!MESSAGE "PacketCrafter - Win32 MFC" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PacketCrafter - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\\" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 ws2_32.lib KomodiaInfraLib.lib KomodiaTCPIPLib.lib /nologo /subsystem:windows /machine:I386 /nodefaultlib:"winsock.lib" /libpath:"..\..\KomodiaInfraLib\Release" /libpath:"..\..\KomodiaTCPIPLib\Release"

!ELSEIF  "$(CFG)" == "PacketCrafter - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\\" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 ws2_32.lib KomodiaInfraLib.lib KomodiaTCPIPLib.lib /nologo /subsystem:windows /debug /machine:I386 /nodefaultlib:"winsock2.lib" /pdbtype:sept /libpath:"..\..\KomodiaInfraLib\debug" /libpath:"..\..\KomodiaTCPIPLib\debug"

!ELSEIF  "$(CFG)" == "PacketCrafter - Win32 MFC Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "PacketCrafter___Win32_MFC_Release"
# PROP BASE Intermediate_Dir "PacketCrafter___Win32_MFC_Release"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "MFCRelease"
# PROP Intermediate_Dir "MFCRelease"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "..\..\\" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\\" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 ws2_32.lib KomodiaInfraLib.lib KomodiaTCPIPLib.lib /nologo /subsystem:windows /machine:I386 /nodefaultlib:"winsock.lib" /libpath:"..\..\KomodiaInfraLib\Release" /libpath:"..\..\KomodiaTCPIPLib\Release"
# ADD LINK32 ws2_32.lib KomodiaInfraLib.lib KomodiaTCPIPLib.lib /nologo /subsystem:windows /machine:I386 /nodefaultlib:"winsock.lib" /libpath:"..\..\KomodiaInfraLib\MFCRelease" /libpath:"..\..\KomodiaTCPIPLib\MFCRelease"

!ELSEIF  "$(CFG)" == "PacketCrafter - Win32 MFC"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "PacketCrafter___Win32_MFC"
# PROP BASE Intermediate_Dir "PacketCrafter___Win32_MFC"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "MFC"
# PROP Intermediate_Dir "MFC"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\\" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\\" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 ws2_32.lib KomodiaInfraLib.lib KomodiaTCPIPLib.lib /nologo /subsystem:windows /debug /machine:I386 /nodefaultlib:"winsock2.lib" /pdbtype:sept /libpath:"..\..\KomodiaInfraLib\debug" /libpath:"..\..\KomodiaTCPIPLib\debug"
# ADD LINK32 ws2_32.lib KomodiaInfraLib.lib KomodiaTCPIPLib.lib /nologo /subsystem:windows /debug /machine:I386 /nodefaultlib:"winsock2.lib" /pdbtype:sept /libpath:"..\..\KomodiaInfraLib\MFC" /libpath:"..\..\KomodiaTCPIPLib\MFC"

!ENDIF 

# Begin Target

# Name "PacketCrafter - Win32 Release"
# Name "PacketCrafter - Win32 Debug"
# Name "PacketCrafter - Win32 MFC Release"
# Name "PacketCrafter - Win32 MFC"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\HyperLink\HyperLink.cpp
# End Source File
# Begin Source File

SOURCE=.\ICMPDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\PacketCrafter.cpp
# End Source File
# Begin Source File

SOURCE=.\PacketCrafter.rc
# End Source File
# Begin Source File

SOURCE=.\PacketCrafterDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TCPDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\UDPDialog.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\HyperLink\hyperlink.h
# End Source File
# Begin Source File

SOURCE=.\ICMPDialog.h
# End Source File
# Begin Source File

SOURCE=.\PacketCrafter.h
# End Source File
# Begin Source File

SOURCE=.\PacketCrafterDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TCPDialog.h
# End Source File
# Begin Source File

SOURCE=.\UDPDialog.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\PacketCrafter.ico
# End Source File
# Begin Source File

SOURCE=.\res\PacketCrafter.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
