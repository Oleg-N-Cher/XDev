MODULE RoseRedir;
IMPORT Rose;

TYPE
  Address = ARRAY OF CHAR;
  Redirector* = RECORD
    listener: Rose.Listener;
    error-  : BOOLEAN; (** Was there an error during the work? *)
    errcode-: INTEGER; (** A code of the first occurred error. *)
    host-   : ARRAY 255 + 1 OF CHAR; (* RFC 1034, RFC 1035 *)
    ip-     : ARRAY 16 OF CHAR; (* "XXX.XXX.XXX.XXX" *)
    port-   : INTEGER; (* 16-bit protocol port *)
  END;

PROCEDURE (VAR self: Redirector) Redirect* (
  IN localAdr, remoteAdr: Address);
BEGIN
  self.listener.Listen(localAdr);
  self.error := self.listener.error;
  self.errcode := self.listener.errcode;
  COPY(self.listener.host, self.host);
  COPY(self.listener.ip, self.ip);
  self.port := self.listener.port;
END Redirect;

PROCEDURE (VAR self: Redirector) Stop* ;
BEGIN
END Stop;

END RoseRedir.
