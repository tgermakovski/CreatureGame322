#include <stdio.h>
#include <stdlib.h>

// room struct
typedef struct
{
    int state;
    int north;
    int south;
    int east;
    int west;
    int num;
} room;

// creature struct
typedef struct
{
    int type;
    int loc;
    int id_num;
} creature;

int respect; 

int main(){

    respect = 40;



    // number of rooms
    int n = 3;
    //scanf("%d", &n);
    room *roomArray = malloc(n * sizeof(room)); 

    // state and neighbors
    for (int i = 0; i < n; i++)
    {
        roomArray[i].num = i;

        //scanf("%d %d %d %d %d", &roomArray[i].state, &roomArray[i].north, &roomArray[i].south, &roomArray[i].east, &roomArray[i].west);
    }

            scanf("0, -1, 1, -1, 2", &roomArray[0].state, &roomArray[0].north, &roomArray[0].south, &roomArray[0].east, &roomArray[0].west);
        scanf("2,0,-1,-1,-1", &roomArray[1].state, &roomArray[1].north, &roomArray[1].south, &roomArray[1].east, &roomArray[1].west);
        scanf("2, -1, -1, 0, -1", &roomArray[2].state, &roomArray[2].north, &roomArray[2].south, &roomArray[2].east, &roomArray[2].west);


    // number of creatures
    int m = 4;
    //scanf("%d", &m);
    creature *creatureArray = malloc(m * sizeof(creature)); 

    int pc_index;

    // creature type and location

            scanf("1, 0", &creatureArray[0].type, &creatureArray[0].loc);
            scanf("0, 2", &creatureArray[1].type, &creatureArray[1].loc);
            scanf("2, 1", &creatureArray[2].type, &creatureArray[2].loc);
            scanf("2, 2", &creatureArray[3].type, &creatureArray[3].loc); 


    for(int i = 0; i < m; i++){
        
        //scanf("%d %d", &creatureArray[i].type, &creatureArray[i].loc);
        creatureArray[i].id_num = i;

        if(creatureArray[i].type == 0){
            pc_index = i;
        }

    }

    //command strings
        char command[] = "poop";
        char quit[] = "quit";
        char exit[] = "exit";
        char help[] = "help";
        char look[] = "look";
        char clean[] = "clean";
        char dirty[] = "dirty";
        char north_command[] = "north";        
        char south_command[] = "south";
        char east_command[] = "east";
        char west_command[] = "west";
        char respect_command[] = "respect";
        char clean_colon[] = ":clean";
        char dirty_colon[] = ":dirty";
        char north_colon[] = ":north";
        char south_colon[] = ":south";
        char east_colon[] = ":east";
        char west_colon[] = ":west";
        char colon[] = ":";

    // play
    do
    {     
        scanf("%s", &command);

        if (strcmp(command, help)){
            puts("help shmelp. you don't need any help. just pull yourself up by the bootstraps");
            puts("if you really need help, refer to my 241 hw");
        }

        if (strcmp(command, look))
        {

            printf("Room ");
            prinf("%d ", roomArray[creatureArray[pc_index].loc].num);   
            puts(" ");

            if(roomArray[creatureArray[pc_index].loc].state == 0){
                puts("clean");
            }
            if(roomArray[creatureArray[pc_index].loc].state == 1){
                puts("half-dirty");
            }
            if(roomArray[creatureArray[pc_index].loc].state == 2){
                puts("dirty");
            }
           
            if(roomArray[creatureArray[pc_index].loc].north != -1){
                printf("to the north: ");
                printf("%d ", roomArray[creatureArray[pc_index].loc].north); 
                puts(" ");
            }
            if(roomArray[creatureArray[pc_index].loc].south != -1){
                printf("to the south: ");
                printf("%d ", roomArray[creatureArray[pc_index].loc].south); 
                puts(" ");
            }
            if(roomArray[creatureArray[pc_index].loc].east != -1){
                printf("to the east: ");
                printf("%d ", roomArray[creatureArray[pc_index].loc].east); 
                puts(" ");
            }
            if(roomArray[creatureArray[pc_index].loc].west != -1){
                printf("to the west: ");
                printf("%d ", roomArray[creatureArray[pc_index].loc].west); 
                puts(" ");
            }


            for(int i = 0; i < m; i++){
                if(creatureArray[i].loc == creatureArray[pc_index].loc){
                    if(creatureArray[i].type == 0){
                        puts("PC, id number ");
                        printf("%d ", creatureArray[i].id_num);
                    }
                    if(creatureArray[i].type == 1){
                        puts("Animal, id number "); 
                        printf("%d ", creatureArray[i].id_num);               
                    }
                    if(creatureArray[i].type == 2){
                        puts("NPC, id number ");
                        printf("%d ", creatureArray[i].id_num);              
                    }                
                }
            }
        }

        if (strcmp(command, clean)){
            if(roomArray[creatureArray[pc_index].loc].state != 0){
                roomArray[creatureArray[pc_index].loc].state--;

                for(int i = 0; i < m; i++){
                    if(creatureArray[i].type == 1 && creatureArray[i].loc == creatureArray[pc_index].loc){
                        //increase respect
                        respect++;
                        //lick face
                        printf("animal ");
                        printf("% d", creatureArray[i].id_num); 
                        puts(" licks face");
                    }
                    if(creatureArray[i].type == 2 && creatureArray[i].loc == creatureArray[pc_index].loc){
                        //subtract respect
                        respect--;
                        //grumble
                        printf("npc ");
                        printf("% d", creatureArray[i].id_num); 
                        puts(" grumbles");
                    }
                }

                if(roomArray[creatureArray[pc_index].loc].state == 0){  //repeat for dirty
                    for(int i = 0; i < m; i++){
                        if(creatureArray[i].type == 2 && creatureArray[i].loc == creatureArray[pc_index].loc){
                            //leave //randomize neighbor selection

                            int r;
                            int n_full = 0;
                            int s_full = 0;
                            int e_full = 0;
                            int w_full = 0;

                            do{
                                r = rand() % 4;
                                
                                if(r == 0){
                                    //check if full
                                    int full = 0;
                                    for(int j =0; j < m; j++){
                                        if(creatureArray[i].loc == roomArray[creatureArray[i].loc].north){
                                            full++;
                                        }
                                    }                                    
                                    //if not, enter
                                    if(full>9){
                                        creatureArray[i].loc = roomArray[creatureArray[i].loc].north;
                                        r=4;
                                    } else {
                                        n_full++;
                                        puts("north full");
                                    }
                                }
                                if(r == 1){
                                    //check if full
                                    int full = 0;
                                    for(int j =0; j < m; j++){
                                        if(creatureArray[i].loc == roomArray[creatureArray[i].loc].south){
                                            full++;
                                        }
                                    }                                    
                                    //if not, enter
                                    if(full>9){
                                        creatureArray[i].loc = roomArray[creatureArray[i].loc].south;
                                        r=4;
                                    } else {
                                        s_full++;
                                        puts("south full");
                                    }
                                }
                                if(r == 2){
                                    //check if full
                                    int full = 0;
                                    for(int j =0; j < m; j++){
                                        if(creatureArray[i].loc == roomArray[creatureArray[i].loc].east){
                                            full++;
                                        }
                                    }                                    
                                    //if not, enter
                                    if(full>9){
                                        creatureArray[i].loc = roomArray[creatureArray[i].loc].east;
                                        r=4;
                                    } else {
                                        e_full++;
                                        puts("east full");
                                    }
                                }
                                if(r == 3){
                                    //check if full
                                    int full = 0;
                                    for(int j =0; j < m; j++){
                                        if(creatureArray[i].loc == roomArray[creatureArray[i].loc].west){
                                            full++;
                                        }
                                    }                                    
                                    //if not, enter
                                    if(full>9){
                                        creatureArray[i].loc = roomArray[creatureArray[i].loc].west;
                                        r=4;
                                    } else {
                                        w_full++;
                                        puts("west full");
                                    }
                                }

                                //drill
                                if(n_full && s_full && e_full && w_full){
                                    r=4;
                                    creatureArray[i].loc = -69;
                                    //minus respect
                                    for(int i = 0; i<m; i++){
                                        if(creatureArray[i].loc = creatureArray[pc_index].loc){
                                            printf("% d", creatureArray[i].id_num); 
                                            puts(" grumbles");
                                            respect--;
                                        }
                                    }
                                }

                            }while(r<4);

                            n_full = 0; 
                            s_full = 0; 
                            e_full = 0; 
                            w_full = 0;

                            //once in new location, if(clean){npc.dirty()}
                            if(roomArray[creatureArray[i].loc].state == 0){
                                roomArray[creatureArray[i].loc].state++;
                            }                         
                        }
                    }
                }

            }
            if(roomArray[creatureArray[pc_index].loc].state == 0){
                puts("already clean stupid");
            }
        }

        if (strcmp(command, dirty)){
            if(roomArray[creatureArray[pc_index].loc].state != 2){
                roomArray[creatureArray[pc_index].loc].state++;

                for(int i = 0; i < m; i++){
                    if(creatureArray[i].type == 1 && creatureArray[i].loc == creatureArray[pc_index].loc){
                        //subtract respect
                        respect--;
                        //growl
                        printf("animal ");
                        printf("% d", creatureArray[i].id_num); 
                        puts(" growls");
                    }
                    if(creatureArray[i].type == 2 && creatureArray[i].loc == creatureArray[pc_index].loc){
                        //increase respect
                        respect++;
                        //smile
                        printf("npc ");
                        printf("% d", creatureArray[i].id_num);
                        puts(" smiles");
                    }
                }

                if(roomArray[creatureArray[pc_index].loc].state == 2){
                    for(int i = 0; i < m; i++){
                        if(creatureArray[i].type == 1 && creatureArray[i].loc == creatureArray[pc_index].loc){
                            //leave 
                        }
                    }
                }
                
            }
            if(roomArray[creatureArray[pc_index].loc].state == 2){
                puts("already dirty stupid ... go find new room in which to take shit on floor");
            }
        }

        if (strcmp(command, north_command)){

            //check if full
            if(roomArray[creatureArray[pc_index].loc].north > -1){   

                int full = 0;
                for(int i =0; i < m; i++){
                if(creatureArray[i].loc == roomArray[creatureArray[pc_index].loc].north){
                    full++;
                    }
                }

                //if not full, enter
                if(full>9){
                    creatureArray[pc_index].loc = roomArray[creatureArray[pc_index].loc].north;
                } else {
                    puts("north full");
                }
            }
        }

        if (strcmp(command, south_command)){

            //check if full
            if(roomArray[creatureArray[pc_index].loc].south > -1){   

                int full = 0;
                for(int i =0; i < m; i++){
                if(creatureArray[i].loc == roomArray[creatureArray[pc_index].loc].south){
                    full++;
                    }
                }

                //if not full, enter
                if(full>9){
                    creatureArray[pc_index].loc = roomArray[creatureArray[pc_index].loc].south;
                } else {
                    puts("south full");
                }
            }
        }

        if (strcmp(command, east_command)){

            //check if full
            if(roomArray[creatureArray[pc_index].loc].east > -1){   

                int full = 0;
                for(int i =0; i < m; i++){
                if(creatureArray[i].loc == roomArray[creatureArray[pc_index].loc].east){
                    full++;
                    }
                }

                //if not full, enter
                if(full>9){
                    creatureArray[pc_index].loc = roomArray[creatureArray[pc_index].loc].east;
                } else {
                    puts("east full");
                }
            }
        }

        if (strcmp(command, west_command)){

            //check if full
            if(roomArray[creatureArray[pc_index].loc].west > -1){   

                int full = 0;
                for(int i =0; i < m; i++){
                if(creatureArray[i].loc == roomArray[creatureArray[pc_index].loc].west){
                    full++;
                    }
                }

                //if not full, enter
                if(full>9){
                    creatureArray[pc_index].loc = roomArray[creatureArray[pc_index].loc].west;
                } else {
                    puts("west full");
                }
            }
        }

        


        //force creature move
        
        if(strstr(command, north_colon)){ 
            char *leftSide = NULL;
            leftSide = malloc(sizeof(command));
            //leftSide points to address of char array left of colon
            leftSide = strtok(command, colon);
            //convert char string to int
            int leftInt = atoi(leftSide);
            //same as normal NSEW command
            //check if in same room and if full
            if(roomArray[creatureArray[leftInt].loc].north > -1 && (creatureArray[leftInt].loc == creatureArray[pc_index].loc)){   

                int full = 0;
                for(int i =0; i < m; i++){
                if(creatureArray[i].loc == roomArray[creatureArray[leftInt].loc].north){
                    full++;
                    }
                }

                //if not full, enter
                if(full>9){
                    creatureArray[leftInt].loc = roomArray[creatureArray[leftInt].loc].north;
                } else {
                    puts("north full");
                    printf("% d", leftInt);
                    puts(" is upset");
                    respect--;
                }
            }
            //set leftSide to null
            leftSide = NULL;
            free(leftSide);
        }

        if(strstr(command, south_colon)){ 
            char *leftSide = NULL;
            leftSide = malloc(sizeof(command));
            //leftSide points to address of char array left of colon
            leftSide = strtok(command, colon);
            //convert char string to int
            int leftInt = atoi(leftSide);
            //same as normal NSEW command
            //check if in same room and if full
            if(roomArray[creatureArray[leftInt].loc].south > -1 && (creatureArray[leftInt].loc == creatureArray[pc_index].loc)){   

                int full = 0;
                for(int i =0; i < m; i++){
                if(creatureArray[i].loc == roomArray[creatureArray[leftInt].loc].south){
                    full++;
                    }
                }

                //if not full, enter
                if(full>9){
                    creatureArray[leftInt].loc = roomArray[creatureArray[leftInt].loc].south;
                } else {
                    puts("south full");
                    printf("% d", leftInt);
                    puts(" is upset");
                    respect--;
                }
            }
            //set leftSide to null
            leftSide = NULL;
            free(leftSide);
        }

        if(strstr(command, east_colon)){ 
            char *leftSide = NULL;
            leftSide = malloc(sizeof(command));
            //leftSide points to address of char array left of colon
            leftSide = strtok(command, colon);
            //convert char string to int
            int leftInt = atoi(leftSide);
            //same as normal NSEW command
            //check if in same room and if full
            if(roomArray[creatureArray[leftInt].loc].east > -1 && (creatureArray[leftInt].loc == creatureArray[pc_index].loc)){   

                int full = 0;
                for(int i =0; i < m; i++){
                if(creatureArray[i].loc == roomArray[creatureArray[leftInt].loc].east){
                    full++;
                    }
                }

                //if not full, enter
                if(full>9){
                    creatureArray[leftInt].loc = roomArray[creatureArray[leftInt].loc].east;
                } else {
                    puts("east full");
                    printf("% d", leftInt);
                    puts(" is upset");
                    respect--;
                }
            }
            //set leftSide to null
            leftSide = NULL;
            free(leftSide);
        }

        if(strstr(command, west_colon)){ 
            char *leftSide = NULL;
            leftSide = malloc(sizeof(command));
            //leftSide points to address of char array left of colon
            leftSide = strtok(command, colon);
            //convert char string to int
            int leftInt = atoi(leftSide);
            //same as normal NSEW command
            //check if in same room and if full
            if(roomArray[creatureArray[leftInt].loc].west > -1 && (creatureArray[leftInt].loc == creatureArray[pc_index].loc)){   

                int full = 0;
                for(int i =0; i < m; i++){
                if(creatureArray[i].loc == roomArray[creatureArray[leftInt].loc].west){
                    full++;
                    }
                }

                //if not full, enter
                if(full>9){
                    creatureArray[leftInt].loc = roomArray[creatureArray[leftInt].loc].west;
                } else {
                    puts("west full");
                    printf("% d", leftInt);
                    puts(" is upset");
                    respect--;
                }
            }
            //set leftSide to null
            leftSide = NULL;
            free(leftSide);
        }

        

        //force creature clean
        if(strstr(command, clean_colon)){
            char *leftSide = NULL;
            leftSide = malloc(sizeof(command));
            leftSide = strtok(command, colon);
            int leftInt = atoi(leftSide);
            //same as normal clean, plus check creature type, add or detract respect accordingly, then replicate for dirty_colon

            if(creatureArray[leftInt].type == 1){
                respect++;
                respect++;
                printf("% d", leftInt);
                puts(" licks face");
                printf("% d", leftInt);
                puts(" licks face");
            }

            if(creatureArray[leftInt].type == 2){
                respect--;
                respect--;
                printf("% d", leftInt);
                puts(" grumbles");
                printf("% d", leftInt);
                puts(" grumbles");
            }

            if(roomArray[creatureArray[pc_index].loc].state != 0){
                roomArray[creatureArray[pc_index].loc].state--;

                for(int i = 0; i < m; i++){
                    if(creatureArray[i].type == 1 && creatureArray[i].loc == creatureArray[pc_index].loc){
                        //increase respect
                        respect++;
                        //lick face
                        printf("animal ");
                        printf("% d", creatureArray[i].id_num); 
                        puts(" licks face");
                    }
                    if(creatureArray[i].type == 2 && creatureArray[i].loc == creatureArray[pc_index].loc){
                        //subtract respect
                        respect--;
                        //grumble
                        printf("npc ");
                        printf("% d", creatureArray[i].id_num); 
                        puts(" grumbles");
                    }
                }

                if(roomArray[creatureArray[pc_index].loc].state == 0){  //repeat for dirty
                    for(int i = 0; i < m; i++){
                        if(creatureArray[i].type == 2 && creatureArray[i].loc == creatureArray[pc_index].loc){
                            //leave //randomize neighbor selection

                            int r;
                            int n_full = 0;
                            int s_full = 0;
                            int e_full = 0;
                            int w_full = 0;

                            do{
                                r = rand() % 4;
                                
                                if(r == 0){
                                    //check if full
                                    int full = 0;
                                    for(int j =0; j < m; j++){
                                        if(creatureArray[i].loc == roomArray[creatureArray[i].loc].north){
                                            full++;
                                        }
                                    }                                    
                                    //if not, enter
                                    if(full>9){
                                        creatureArray[i].loc = roomArray[creatureArray[i].loc].north;
                                        r=4;
                                    } else {
                                        n_full++;
                                        puts("north full");
                                    }
                                }
                                if(r == 1){
                                    //check if full
                                    int full = 0;
                                    for(int j =0; j < m; j++){
                                        if(creatureArray[i].loc == roomArray[creatureArray[i].loc].south){
                                            full++;
                                        }
                                    }                                    
                                    //if not, enter
                                    if(full>9){
                                        creatureArray[i].loc = roomArray[creatureArray[i].loc].south;
                                        r=4;
                                    } else {
                                        s_full++;
                                        puts("south full");
                                    }
                                }
                                if(r == 2){
                                    //check if full
                                    int full = 0;
                                    for(int j =0; j < m; j++){
                                        if(creatureArray[i].loc == roomArray[creatureArray[i].loc].east){
                                            full++;
                                        }
                                    }                                    
                                    //if not, enter
                                    if(full>9){
                                        creatureArray[i].loc = roomArray[creatureArray[i].loc].east;
                                        r=4;
                                    } else {
                                        e_full++;
                                        puts("east full");
                                    }
                                }
                                if(r == 3){
                                    //check if full
                                    int full = 0;
                                    for(int j =0; j < m; j++){
                                        if(creatureArray[i].loc == roomArray[creatureArray[i].loc].west){
                                            full++;
                                        }
                                    }                                    
                                    //if not, enter
                                    if(full>9){
                                        creatureArray[i].loc = roomArray[creatureArray[i].loc].west;
                                        r=4;
                                    } else {
                                        w_full++;
                                        puts("west full");
                                    }
                                }

                                //drill
                                if(n_full && s_full && e_full && w_full){
                                    r=4;
                                    creatureArray[i].loc = -69;
                                    //minus respect
                                    for(int i = 0; i<m; i++){
                                        if(creatureArray[i].loc = creatureArray[pc_index].loc){
                                            printf("% d", creatureArray[i].id_num); 
                                            puts(" grumbles");
                                            respect--;
                                        }
                                    }
                                }

                            }while(r<4);

                            n_full = 0; 
                            s_full = 0; 
                            e_full = 0; 
                            w_full = 0;

                            //once in new location, if(clean){npc.dirty()}
                            if(roomArray[creatureArray[i].loc].state == 0){
                                roomArray[creatureArray[i].loc].state++;
                            }                         
                        }
                    }
                }

            }
            if(roomArray[creatureArray[pc_index].loc].state == 0){
                puts("already clean stupid");
            }

            free(leftSide);

        }

        //force creature dirty
        if(strstr(command, dirty_colon)){
            char *leftSide = NULL;
            leftSide = malloc(sizeof(command));
            leftSide = strtok(command, colon);
            int leftInt = atoi(leftSide);
            //same as normal dirty, plus check creature type, add or detract respect accordingly, 

            if(creatureArray[leftInt].type == 1){
                respect--;
                respect--;
                printf("% d", leftInt);
                puts(" growls");
                printf("% d", leftInt);
                puts(" growls");
            }

            if(creatureArray[leftInt].type == 2){
                respect++;
                respect++;
                printf("% d", leftInt);
                puts(" smiles");
                printf("% d", leftInt);
                puts(" smiles");
            }

            if(roomArray[creatureArray[pc_index].loc].state != 0){
                roomArray[creatureArray[pc_index].loc].state++;

                for(int i = 0; i < m; i++){
                    if(creatureArray[i].type == 1 && creatureArray[i].loc == creatureArray[pc_index].loc){
                        // respect
                        respect--;
                        //growl
                        printf("animal ");
                        printf("% d", creatureArray[i].id_num); 
                        puts(" growls");
                    }
                    if(creatureArray[i].type == 2 && creatureArray[i].loc == creatureArray[pc_index].loc){
                        // respect
                        respect++;
                        //smile
                        printf("npc ");
                        printf("% d", creatureArray[i].id_num); 
                        puts(" smiles");
                    }
                }

                if(roomArray[creatureArray[pc_index].loc].state == 2){  
                    for(int i = 0; i < m; i++){
                        if(creatureArray[i].type == 1 && creatureArray[i].loc == creatureArray[pc_index].loc){
                            //leave //randomize neighbor selection

                            int r;
                            int n_full = 0;
                            int s_full = 0;
                            int e_full = 0;
                            int w_full = 0;

                            do{
                                r = rand() % 4;
                                
                                if(r == 0){
                                    //check if full
                                    int full = 0;
                                    for(int j =0; j < m; j++){
                                        if(creatureArray[i].loc == roomArray[creatureArray[i].loc].north){
                                            full++;
                                        }
                                    }                                    
                                    //if not, enter
                                    if(full>9){
                                        creatureArray[i].loc = roomArray[creatureArray[i].loc].north;
                                        r=4;
                                    } else {
                                        n_full++;
                                        puts("north full");
                                    }
                                }
                                if(r == 1){
                                    //check if full
                                    int full = 0;
                                    for(int j =0; j < m; j++){
                                        if(creatureArray[i].loc == roomArray[creatureArray[i].loc].south){
                                            full++;
                                        }
                                    }                                    
                                    //if not, enter
                                    if(full>9){
                                        creatureArray[i].loc = roomArray[creatureArray[i].loc].south;
                                        r=4;
                                    } else {
                                        s_full++;
                                        puts("south full");
                                    }
                                }
                                if(r == 2){
                                    //check if full
                                    int full = 0;
                                    for(int j =0; j < m; j++){
                                        if(creatureArray[i].loc == roomArray[creatureArray[i].loc].east){
                                            full++;
                                        }
                                    }                                    
                                    //if not, enter
                                    if(full>9){
                                        creatureArray[i].loc = roomArray[creatureArray[i].loc].east;
                                        r=4;
                                    } else {
                                        e_full++;
                                        puts("east full");
                                    }
                                }
                                if(r == 3){
                                    //check if full
                                    int full = 0;
                                    for(int j =0; j < m; j++){
                                        if(creatureArray[i].loc == roomArray[creatureArray[i].loc].west){
                                            full++;
                                        }
                                    }                                    
                                    //if not, enter
                                    if(full>9){
                                        creatureArray[i].loc = roomArray[creatureArray[i].loc].west;
                                        r=4;
                                    } else {
                                        w_full++;
                                        puts("west full");
                                    }
                                }

                                //drill
                                if(n_full && s_full && e_full && w_full){
                                    r=4;
                                    creatureArray[i].loc = -69;
                                    //minus respect
                                    for(int i = 0; i<m; i++){
                                        if(creatureArray[i].loc = creatureArray[pc_index].loc){
                                            printf("% d", creatureArray[i].id_num); 
                                            puts(" is upset");
                                            respect--;
                                        }
                                    }
                                }

                            }while(r<4);

                            n_full = 0; 
                            s_full = 0; 
                            e_full = 0; 
                            w_full = 0;

                            //once in new location, if(dirty){animal clean}
                            if(roomArray[creatureArray[i].loc].state == 2){
                                roomArray[creatureArray[i].loc].state--;
                            }                         
                        }
                    }
                }

            }
            if(roomArray[creatureArray[pc_index].loc].state == 2){
                puts("already dirty stupid");
            }

            free(leftSide);

        }


        if (strcmp(command, respect_command)){
            printf("%d ", respect);
            puts(" ");
        }

    } while (strcmp(command, quit) && strcmp(command, exit) && 0 < respect < 80);    
        
        //end message
        if(respect < 0){
            puts("you lose");
        }
        if(respect > 80){
            puts("you win");
        }
        puts("Goodbye!"); 

        //deallocate memory
        free(roomArray);
        free(creatureArray);

        return 0;
    
}