/*  7-Segment-Template
*   Setting each segment of the display can be achieved through the use of binary or hexidecimal values. For binary, 
*   each pin within the busout can be addressed individually remembering that the LSB of the write value refers to the
*   left hand most pin in the bus. Therefore, 0b0000001 sets the state of pin PA_11 thus the state of segment A. To set the status 
*   of each segment using hexidecimal, simply convert the binary value to hex, 0b0000001 -> 0x01 etc....
*
*   To be modified as detailed in the associated Activity
*
*   Author: Andrew Knowles & James Chandler 2021
*/

#include "mbed.h"

#define WAIT_TIME_MS 500ms 

// The following pins are declared based on the suggested wiring of the Activity.   
DigitalOut seg1(PA_12);
DigitalOut seg2(PA_11);
DigitalOut seg3(PB_12);
DigitalOut seg4(PB_11);
DigitalOut seg5(PB_2);
DigitalOut seg6(PB_1);
DigitalOut seg7(PB_15);
DigitalOut seg8(PB_14);

/*[Part 2-start]
//segment       A       B     C      D    E     F      G        
BusOut SegDis(PA_11, ); //Add remaining pins in correct order
DigitalOut decimal_point(); //Add pin for the Decimal Point 

//               0     1     2     3     4     5     6     7     8     9     A     B     C     D     E     F    
int hexDis[] = {0x3F, 0x06, }; // Add the rest of the hex values associated with the dispplay items 0-F
int dp_status = 0;

void SegDis_init();
[Part 2-end]*/

/*[Part 3-start]
void SegDis_endcycle();
[Part 3-end]*/

int main()
{
    /* [Part 2-start]
    SegDis_init(); //test segments
    printf("This is the bare metal blinky example running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
    [Part 2-end]*/
    
    while (true)
    {
        
        // Toggle each segment in turn based on the order of the declared pins. 
        // This sequence can be used to determine which pin relates to which segment letter. E.g. Pin PA_11 relates to segment A.
        // A logisim seven segment simulator has been created to help determine the correct pin order for the bus, 
        // and the correct bus values for each display value. E.g. 0x3F corresponds to 0 on the 7-seg display (based on the prescribed wiring).
        seg1 = !seg1;
        ThisThread::sleep_for(WAIT_TIME_MS);
        seg2 = !seg2;
        ThisThread::sleep_for(WAIT_TIME_MS);
        seg3 = !seg3;
        ThisThread::sleep_for(WAIT_TIME_MS);
        seg4 = !seg4;
        ThisThread::sleep_for(WAIT_TIME_MS);
        seg5 = !seg5;
        ThisThread::sleep_for(WAIT_TIME_MS);
        seg6 = !seg6;
        ThisThread::sleep_for(WAIT_TIME_MS);
        seg7 = !seg7;
        ThisThread::sleep_for(WAIT_TIME_MS);
        seg8 = !seg8;
        ThisThread::sleep_for(WAIT_TIME_MS);
        
        /*[Part 2-start]
        // Once you have defined the pin order for the BusOut object 'SegDis', you can uncomment this code and cycle the display items. 
        for(int i = 0; i < 16; i++){        //cycle through the array and display each number / letter
            SegDis.write(hexDis[i]);
            decimal_point.write(dp_status); //write value to decimal point
            dp_status = !dp_status;         //toggle decimal point on/off

            ThisThread::sleep_for(WAIT_TIME_MS);
        }
        [Part 2-end]*/
        
        /*[Part 3-start]
        SegDis_endcycle();
        [Part 3-end]*/
    }
}

 /*[Part 2-start]
void SegDis_init(){
    SegDis.write(0x00); //turn off the display by setting all segments to '0'
    ThisThread::sleep_for(200ms);
}
[Part 2-end]*/

/*[Part 3-start]
void SegDis_endcycle(){
    ThisThread::sleep_for(200ms);
    SegDis.write(0x00);
    ThisThread::sleep_for(200ms);
    SegDis.write(0x01); 
    ThisThread::sleep_for(200ms);
    SegDis.write(0x00);
}[Part 3-end]*/