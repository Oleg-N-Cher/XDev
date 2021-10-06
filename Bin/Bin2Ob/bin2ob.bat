@ECHO OFF
ECHO MODULE Rsrc;           > Rsrc.ob3
bin2ob.exe Test\ball.png   >> Rsrc.ob3
bin2ob.exe Test\bat.png    >> Rsrc.ob3
bin2ob.exe Test\bricks.png >> Rsrc.ob3
ECHO END Rsrc.             >> Rsrc.ob3