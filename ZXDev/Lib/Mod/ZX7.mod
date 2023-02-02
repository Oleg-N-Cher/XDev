(*-----------------------------------------------------------------------------
' SDCC LIBRARY FOR ZX7 DECOMPRESSORS
'
' Original version and further information is available at
' http://www.worldofspectrum.org/infoseekid.cgi?id=0027996
' http://www.worldofspectrum.org/infoseekid.cgi?id=0028048
'
' Copyleft (k) Einar Saukas
' ---------------------------------------------------------------------------*)

MODULE ZX7;

TYPE
  UINTEGER = INT32;

(*-----------------------------------------------------------------------------
' Decompress (from source to destination address) data that was previously
' compressed using ZX7. This is the smallest version of the ZX7 decompressor.
'
' Parameters:
'     src: source address (compressed data)
'     dst: destination address (decompressing)
' ---------------------------------------------------------------------------*)
PROCEDURE Standard* (src, dst: UINTEGER); END Standard;

(*-----------------------------------------------------------------------------
' Decompress (from source to destination address) data that was previously
' compressed using ZX7. This is the intermediate version of the ZX7
' decompressor, providing the best balance between speed and size.
'
' Parameters:
'     src: source address (compressed data)
'     dst: destination address (decompressing)
' ---------------------------------------------------------------------------*)
PROCEDURE Turbo* (src, dst: UINTEGER); END Turbo;

(*-----------------------------------------------------------------------------
' Decompress (from source to destination address) data that was previously
' compressed using ZX7. This is the fastest version of the ZX7 decompressor.
'
' Parameters:
'     src: source address (compressed data)
'     dst: destination address (decompressing)
' ---------------------------------------------------------------------------*)
PROCEDURE Mega* (src, dst: UINTEGER); END Mega;

(*-----------------------------------------------------------------------------
' Decompress (from source to destination address) data that was previously
' compressed using ZX7. This is the smallest version of the integrated RCS+ZX7
' decompressor.
'
' IMPORTANT: Data decompressed directly to the ZX-Spectrum screen must be both
' RCS encoded and ZX7 compressed, everything else must be ZX7 compressed only.
'
' Parameters:
'     src: source address (compressed data)
'     dst: destination address (decompressing)
' ---------------------------------------------------------------------------*)
PROCEDURE SmartRCS* (src, dst: UINTEGER); END SmartRCS;

(*-----------------------------------------------------------------------------
' Decompress (from source to destination address) data that was previously
' compressed using ZX7. This is the fastest version of the integrated RCS+ZX7
' decompressor.
'
' IMPORTANT: Data decompressed directly to the ZX-Spectrum screen must be both
' RCS encoded and ZX7 compressed, everything else must be ZX7 compressed only.
'
' Parameters:
'     src: source address (compressed data)
'     dst: destination address (decompressing)
' ---------------------------------------------------------------------------*)
PROCEDURE AgileRCS* (src, dst: UINTEGER); END AgileRCS;

END ZX7.
