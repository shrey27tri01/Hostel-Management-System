#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/function.h"

#include "headers/add.h"
#include "headers/ListSort.h"
#include "headers/ListSearch.h"
#include "headers/update.h"
#include "headers/inout.h"

#include "headers/info.h"
#include "headers/display.h"


int main(void){
    system("clear");
    security_check();
    while(1){
        main_menu();
        int what_to_do;
        scanf("%d",&what_to_do);
        switch (what_to_do){
        case 1:
            system("clear");        
            add();
            Fullsort();
            break;
        
        case 2:
            system("clear");        
            interact();
            break;

        case 3:
            system("clear");        
            search();
            break;
    	
      	 case 4:
            system("clear");        
            status();
            break;
    
        case 5:
            system("clear");        
            update();
            Fullsort();
            break;

        case 6:
            system("clear");
            display();
            break; 

        case 7:
            system("clear");        
            info();
            break;   
        case 0:
            exit(0);
            break;
       
        default:
            printf("PLEASE SELECT FROM GIVEN MENU\n");
            break;
        }
    }
    return 0;    
}
