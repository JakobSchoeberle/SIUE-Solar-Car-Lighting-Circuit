#include <project.h>
#include <stdbool.h>

volatile bool UpdateFlag = 0;
volatile bool HeadlightFlag = 0;
volatile bool BrakeFlag = 0;
volatile bool LeftBlinkerFlag = 0;
volatile bool RightBlinkerFlag = 0;
volatile bool HazardFlag = 0;
int Debounce = 50;

int main(){
    CyGlobalIntEnable;
    
    CAN_Init(); /* initialize CAN node */
    CAN_Start(); /* start CAN node */
    Clock_Start();
    
    Brakes_Write(0);
    RightBlinkers_Write(0);
    LeftBlinkers_Write(0);

    CyDelay(400);
    int count = 0;
    while (1)
    {    
        /* ------- UserInput ------- */
        
        if(HeadLights_BTN_Read() == 0){ //Headlight BTN
            CyDelay(Debounce);
            if(HeadLights_BTN_Read() == 0){
                UpdateFlag = 1;
                if(HeadlightFlag == 0){
                    HeadlightFlag = 1;
                }
                else{
                    HeadlightFlag = 0;
                }
                while(HeadLights_BTN_Read() == 0);
            }
        }
        if(LeftBlinker_BTN_Read() == 0){ //Left Blinker BTN
            CyDelay(Debounce);
            if(LeftBlinker_BTN_Read() == 0){
                UpdateFlag = 1;
                if(LeftBlinkerFlag == 0){
                    LeftBlinkerFlag = 1;
                    RightBlinkerFlag = 0;
                }
                else{
                    LeftBlinkerFlag = 0;
                }
                while(LeftBlinker_BTN_Read() == 0);
            }
        }
        if(RightBlinker_BTN_Read() == 0){ //Right Blinker BTN
            CyDelay(Debounce);
            if(RightBlinker_BTN_Read() == 0){
                UpdateFlag = 1;
                if(RightBlinkerFlag == 0){
                    RightBlinkerFlag = 1;
                    LeftBlinkerFlag = 0;
                }
                else{
                    RightBlinkerFlag = 0;
                }
                while(RightBlinker_BTN_Read() == 0);
            }
        }
        if(Hazard_BTN_Read() == 0){ //Hazard BTN
            CyDelay(Debounce);
            if(Hazard_BTN_Read() == 0){
                UpdateFlag = 1;
                if(HazardFlag == 0){
                    HazardFlag = 1;
                    RightBlinkerFlag = 0;
                    LeftBlinkerFlag = 0;
                }
                else{
                    HazardFlag = 0;
                }
                while(Hazard_BTN_Read() == 0);
            }
        }
        if(Brake_SW_Read() == 0){ //Brake SW
            UpdateFlag = 1;
            BrakeFlag = 1;
        }
        else{
            BrakeFlag = 0;
        }
        
        /* ------- Lights ------- */
        if(HeadlightFlag == 1){
            HeadLights_Write(1);
        }
        else{
            HeadLights_Write(0);
        }
        
        if(LeftBlinkerFlag == 1){
            LeftBlinkers_Write(1);
        }
        else{
            LeftBlinkers_Write(0);
        }
        if(RightBlinkerFlag == 1){
            RightBlinkers_Write(1);
        }
        else{
            RightBlinkers_Write(0);
        }
        if(HazardFlag == 1){
            RightBlinkers_Write(1);
            LeftBlinkers_Write(1);
        }
        else{
            RightBlinkers_Write(0);
            LeftBlinkers_Write(0);
        }
        if(BrakeFlag == 1){
            Brakes_Write(1);
        }
        else{
            Brakes_Write(0);
        }
        
        /* ------ Com ------- */
        
        if(UpdateFlag == 1){
            CAN_SendMsg0();
            UpdateFlag = 0;
        }

    }
}