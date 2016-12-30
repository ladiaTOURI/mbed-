
#include "mbed.h"
#include "m3pi.h"
DigitalOut myled(LED1);
Serial pc(USBTX, USBRX);
 m3pi pi;
float bat;
char buffer [4];
AnalogIn position(A0);
PwmOut servo(D3);
int main() {
    //communication usb
pc.printf("recption usb.\n\r");
//myled = 1;
//servo.period(0.020f);
pi.locate(0,1);
    while(1)
    {
// servo position determined by a pulse width between 1-2ms
//servo.pulsewidth(0.001f + 0.001f * position);
//pc.printf("recption usb.\n\r");
//myled = 1;
bat=pi.battery();
myled = 1;
bat=bat*1000;
sprintf (buffer, "%f", bat);
pi.cls();
//afficher la tempuratutre  sur  LCD du robot  su r le LCD
pi.printf(buffer);
//pc.printf(buffer);
//pc.printf("%f",bat );
//pi.line_position();
wait(0.5);
}
}
