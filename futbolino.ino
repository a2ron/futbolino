#include <LiquidCrystal.h>
#include <TrueRandom.h>
int ball_value, last_gol_value, last_gol_i;
int count[2];

int getBallValue(){
    int r = TrueRandom.random(1,10);
    if (r == 1){
        return 2; // Doblinha
    }else if(r == 2){
       return -1; // Discontinha
    }else{
       return 1; // Normalinha
    }
}

void setup(){
   init();
}

void init()
{
   ball_value = getBallValue();
   count[0] = 0;
   count[1] = 0;
}

void gol(int i){
    count[i] += ball_value;
    last_gol_value = ball_value;
    ball_value = getBallValue();
    last_gol_i = i;
}

void discount(){
    int i_discount = (last_gol_i+1)%2;
    count[i_discount] -= abs(last_gol_value);
    count[last_gol_i] -= last_gol_value;
    last_gol_i = i_discount;
}

void loop() {
    if(r){
       init();
    }
    else if(a){//gol for A team
        gol(0);
    }
    else if(b){ //gol for B team
        gol(1);
    }
    else if(d){ //discount
        discount();
    }
    else if(v){ //vomitona
        if(ball_value>0)
		ball_value++;

        else ball_value--;
    }    
}
