MODULE GrConfig;

CONST
  AutoDetect = 0; (* It's treated as the current display bits per pixel. *)

  ActualWidth*  = 256 * 3; (* Width, Height in pixels. *)
  ActualHeight* = 192 * 3;
  ActualMaxX*   = ActualWidth  - 1;
  ActualMaxY*   = ActualHeight - 1;
  DepthBits*    = AutoDetect; (* Depth in bits per pixel (8, 16, or 32). *)

  AppTitle* = "XDev/SDL graphic";

END GrConfig.
