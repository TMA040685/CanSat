/*
 *  PROGRAM:
 *    Arduino CanSat_v01.ino
 *  PURPOSE:
 *    Software for recording data from the CanSat units of 
 *    Marselisbog Gymnasium - for physics teaching
 *  AUTHOR:
 *    Thomas Mellergaard Amby, May 2013
 *  USAGE:
 *    Simply upload the software on the Arduino (WITHOUT THE SHIELD)
 *    due to the fact that the OpenLogger and the On-board USB both 
 *    runs on the TX/RX Serial pins. Attach the shield and a power supply 
 */
 
 #define NRDATA 425
 int x,y,z,temp1,temp2,tryk;
 int data[NRDATA, index, tilstand, tastetryk;
 int logstop = NRDATA - 6;

 void setup() {
   Serial.begin(9600);
   tilstand = 0;
 }
 
 void measure_inp() {
   // CHECK IF INPUT NUMBER IS CORRECT! //
   temp1 = analogRead(0);
   tryk  = analogRead(1);
   x     = analogRead(2);
   y     = analogRead(3);
   z     = analogRead(4);
   temp2 = analogRead(5);
 }
 
 void print_measure() {
   Serial.print('Data , ');
   Serial.print(temp1);
   Serial.print(' , ');
   Serial.print(tryk);
   Serial.print(' , ');
   Serial.print(x);
   Serial.print(' , ');
   Serial.print(y);
   Serial.print(' , ');
   Serial.print(z);
   Serial.print(' , ');
   Serial.println(temp2);
 }
 
 void store_measure() {
   data[index] = temp1;
   index++;
   data[index] = tryk;
   index++;
   data[index] = x;
   index++;
   data[index] = y;
   index++;
   data[index] = z;
   index++;
   data[index] = temp2;
   /*
    * When is an array filled?
    * THere has to be space left for at least 5 more or die
    * If it is filled then go to transmit data
    * (logstop is defind previously)
    */
    if (logstop <= index)
    {
        tilstand = 1;
        index    = 0;
    }
 }
 
 void transmit_measure() {
   
 }
 
 
