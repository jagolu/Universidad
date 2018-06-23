#include "tarjeta.h"
#use delay (clock=48000000)
#include "srf02.h"

typedef enum {
   MOVING_AROUND= 0,
   PUSHING_FORWARD = 1,
   PUSHING_BACKWARDS = 2,
   FINISHED = 3
} GlobalState;

typedef enum {
   STOPPED = 0,
   MOVING_FORWARD = 1,
   MOVING_BACKWARDS = 2,
   TURNING_FORWARD_LEFT = 3,
   TURNING_FORWARD_RIGHT = 4,
   TURNING_BACKWARDS_LEFT = 5,
   TURNING_BACKWARDS_RIGHT = 6,
   ROTATING_LEFT = 7,
   ROTATING_RIGHT = 8,
} MovementMode;
   
struct MovementState {
   MovementMode mov_mode;
   int speed;
   int duration;
};

GlobalState global_state;
struct MovementState act_movement = {STOPPED, 255, 255};
struct MovementState next_movement  = {STOPPED, 255, 255};
struct MovementState last_movement  = {STOPPED, 255, 255};
int pwm = 0;
// 1 duration = 256 * 256 * T0_DIV * 4 / clock
// T0_DIV_1 --> 1 duration = 5.46 e-3 = 5.4613 ms --> 255 duration ? 1.39 s
// T0_DIV_2 --> 1 duration = 4.26 e-5 = 0.0426 ms

void stop_moving();
void move_forward();
void move_backwards();
void turn_forward_left();
void turn_forward_right();
void turn_backwards_left();
void turn_backwards_right();
void rotate_izq();
void rotate_der();

int inf_front_left();
int inf_front_right();
int inf_back_left();
int inf_back_right();

int bumper_front();
int bumper_back();

int is_rotating()
{
   return act_movement.mov_mode == ROTATING_LEFT || act_movement.mov_mode == ROTATING_RIGHT;
}

void prueba_sensores_ruedas();
void prueba_bumpers();

#INT_TIMER0
void isr_timer0() {
   
   if (++pwm == 0) {
      if (act_movement.duration != 255) {
         if(--act_movement.duration == 0) {
            act_movement = next_movement;
            next_movement = last_movement;
         }
      }
   }

   if(pwm <= act_movement.speed) {
      switch(act_movement.mov_mode) {
         case MOVING_FORWARD:
            move_forward();
            break;
         case MOVING_BACKWARDS:
            move_backwards();
            break;
         case TURNING_FORWARD_LEFT:
            turn_forward_left();
            break;
         case TURNING_FORWARD_RIGHT:
            turn_forward_right();
            break;
         case TURNING_BACKWARDS_LEFT:
            turn_backwards_left();
            break;
         case TURNING_BACKWARDS_RIGHT:
            turn_backwards_right();
            break;
         case ROTATING_LEFT:
            rotate_izq();
            break;
         case ROTATING_RIGHT:
            rotate_der();
            break;
         default:
            stop_moving();
            break;
      }
   }
   else {
      stop_moving();
   }
}

void move_around() {
   if(bumper_front()) {
      global_state = PUSHING_FORWARD;
      act_movement.mov_mode = MOVING_FORWARD;
      act_movement.duration = 20;
      act_movement.speed = 128;
      next_movement.mov_mode = MOVING_FORWARD;
      next_movement.duration = 255;
      next_movement.speed = 255;
   }
   else if(bumper_back()) {
      global_state = PUSHING_BACKWARDS;
      act_movement.mov_mode = MOVING_BACKWARDS;
      act_movement.duration = 20;
      act_movement.speed = 128;
      next_movement.mov_mode = MOVING_BACKWARDS;
      next_movement.duration = 255;
      next_movement.speed = 255;
   }
   else if(inf_front_left() && !is_rotating()) {
      act_movement.mov_mode = ROTATING_LEFT;
      act_movement.duration = 128;
      act_movement.speed = 128;
      next_movement.mov_mode = MOVING_BACKWARDS;
      next_movement.duration = 20;
      next_movement.speed = 128;
      last_movement.mov_mode = MOVING_BACKWARDS;
      last_movement.duration = 255;
      last_movement.speed = 255;
   }
   else if(inf_front_right() && !is_rotating()) {
      act_movement.mov_mode = ROTATING_RIGHT;
      act_movement.duration = 128;
      act_movement.speed = 128;
      next_movement.mov_mode = MOVING_BACKWARDS;
      next_movement.duration = 20;
      next_movement.speed = 128;
      last_movement.mov_mode = MOVING_BACKWARDS;
      last_movement.duration = 255;
      last_movement.speed = 255;
   }
   else if(inf_back_left() && !is_rotating()) {
      act_movement.mov_mode = ROTATING_RIGHT;
      act_movement.duration = 128;
      act_movement.speed = 128;
      next_movement.mov_mode = MOVING_FORWARD;
      next_movement.duration = 20;
      next_movement.speed = 128;
      last_movement.mov_mode = MOVING_FORWARD;
      last_movement.duration = 255;
      last_movement.speed = 255;
   }
   else if(inf_back_right() && !is_rotating()) {
      act_movement.mov_mode = ROTATING_LEFT;
      act_movement.duration = 128;
      act_movement.speed = 128;
      next_movement.mov_mode = MOVING_FORWARD;
      next_movement.duration = 20;
      next_movement.speed = 128;
      last_movement.mov_mode = MOVING_FORWARD;
      last_movement.duration = 255;
      last_movement.speed = 255;
   }
   else if (P2) {
      global_state = FINISHED;
      act_movement.mov_mode = STOPPED;
      act_movement.duration = 255;
   }

}

void main() {

   set_tris_a(0x00);
   set_tris_b(0x13);
   set_tris_c(0x00);
   set_tris_d(0x1F);
   set_tris_e(0x00);
   set_timer0(0);
   setup_timer_0(RTCC_INTERNAL | T0_DIV_2 | RTCC_8_BIT);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   
   // Rutina de comienzo
   led_on();
   delay_ms(3000);
   led_off();
   
   // Inicialización movimiento
   global_state = MOVING_AROUND;
   act_movement.mov_mode = MOVING_FORWARD;
   act_movement.duration = 255;
   act_movement.speed = 255;
   next_movement.mov_mode = MOVING_FORWARD;
   next_movement.duration = 255;
   next_movement.speed = 255;
   
   while(1){
      
      switch(global_state) {
         case MOVING_AROUND:
            move_around();
            delay_ms(1);
            break;
         case PUSHING_FORWARD:
            if(!bumper_front()) {
               global_state = MOVING_AROUND;
               act_movement.speed = 255;
            }
            else if (P2) {
               global_state = FINISHED;
               act_movement.mov_mode = STOPPED;
               act_movement.duration = 255;
            }
            delay_ms(1);
            break;
         case PUSHING_BACKWARDS:
            if(!bumper_back()) {
               global_state = MOVING_AROUND;
               act_movement.speed = 255;
            }
            else if (P2) {
               global_state = FINISHED;
               act_movement.mov_mode = STOPPED;
               act_movement.duration = 255;
            }
            delay_ms(1);
            break;
         case FINISHED:
            delay_ms(1000);
            break;
      }
      
      srf_burst();
   }
   
   
}


void stop_moving() {
   M1_P();
   M2_P();
   M3_P();
   M4_P();
}
void move_forward() {
   M1_A();
   M2_A();
   M3_A();
   M4_A();
}
void move_backwards() {
   M1_H();
   M2_H();
   M3_H();
   M4_H();
}
void turn_forward_left() {
   M1_P();
   M2_P();
   M3_A();
   M4_A();
}
void turn_forward_right() { 
   M1_A();
   M2_A();
   M3_P();
   M4_P();
}
void turn_backwards_left() {
   M1_P();
   M2_P();
   M3_H();
   M4_H();
}
void turn_backwards_right() { 
   M1_H();
   M2_H();
   M3_P();
   M4_P();
}
void rotate_izq() {
   M1_H();
   M2_H();
   M3_A();
   M4_A();
}
void rotate_der() {
   M1_A();
   M2_A();
   M3_H();
   M4_H();
}

// Entradas infrarrojo. IN a 0 = negro, IN a 1 = blanco
int inf_front_left() {
   return !IN1;
}
int inf_front_right() {
   return !IN4;
}
int inf_back_left() {
   return !IN2;
}
int inf_back_right() {
   return !IN3;
}

int bumper_front() {
   return IN5;
}
int bumper_back() {
   return IN6;
}

void prueba_sensores_ruedas() {
   if(inf_front_left())
      M1_H();
   else
      M1_P();
   
   if(inf_back_left())
      M2_H();
   else
      M2_P();
      
   if(inf_back_right())
      M3_H();
   else
      M3_P();
      
   if(inf_front_right())
      M4_H();
   else
      M4_P();
}

void prueba_bumpers() {
   if(bumper_front() && bumper_back()) {
      led_off();
   }
   else if(bumper_front() || bumper_back()) {
      led_on();
   }
   else {
      led_off();
   }
}
