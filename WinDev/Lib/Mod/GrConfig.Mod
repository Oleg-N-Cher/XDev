MODULE GrConfig;

CONST
  AutoDetect = 0; (* It's treated as the current display bits per pixel. *)

  VirtualWidth*  = 256; (* Virtual Width, Height in pixels. *)
  VirtualHeight* = 192;
  VirtualMaxX*   = VirtualWidth  - 1;
  VirtualMaxY*   = VirtualHeight - 1;
  ActualWidth*   = VirtualWidth  * 3; (* Actual Width, Height in pixels. *)
  ActualHeight*  = VirtualHeight * 3;
  ActualMaxX*    = ActualWidth   - 1;
  ActualMaxY*    = ActualHeight  - 1;
  DepthBits*     = AutoDetect; (* Depth in bits per pixel (8, 16, or 32). *)

  AppTitle* = "XDev/SDL graphic";

  ChkOutOfScreen* = TRUE;

END GrConfig.
