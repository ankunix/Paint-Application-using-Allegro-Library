/*
  Name:Paint Application using Allegro Library
  Author:Ankush Chauhan
  Date: 11/08/12 2:42
*/

#include <allegro.h>

void init();
void deinit();
void gen_frames();
void gen_pallete();
void gen_toolbox();
void check_color();
void check_toolbox();
void init_screen();
BITMAP *bmp;
int tool,draw_color,draw_color_sec,frame_color;
void draw_fx();
int main() {
    
  init();
	tool=3;
	bmp=create_bitmap(640,480);
	show_mouse(screen);
init_screen();


	while (!key[KEY_ESC])
    {
    acquire_screen();
    blit(bmp, screen, 0, 0, 0, 0, 640, 480);
    release_screen();
	
    
     if((mouse_x>103)&&(mouse_y<399))
      draw_fx();
     else if(mouse_x>30 && mouse_x<300 && mouse_y>430 && mouse_y<455)
        check_color();
     else if(mouse_x<101 && mouse_y<401)
          check_toolbox();
    
    }

	deinit();
	return 0;
}

END_OF_MAIN()

void init_screen()
{
          clear_to_color(bmp,makecol(255,0,0));
     draw_color=makecol(0,0,0);
     draw_color_sec=makecol(255,255,255);
     gen_frames();
     gen_pallete();
     gen_toolbox();
     rectfill(bmp,102,0,640,400,draw_color_sec);//Fill color in the frame Draw space
        
}
void gen_frames()
{


     hline(bmp,0,401,640,makecol(0,0,0));//Pallete Frame
     vline(bmp,101,0,401,makecol(0,0,0));//Toolbox Frame
     

}
void gen_pallete()
{

     rectfill(bmp, 0, 402, 640, 480, makecol(200,200,200));//Fill color in the frame pallete
     rectfill(bmp, 30, 430, 55, 455, makecol(255,255,255)); //WHITE COLOR PICK
     rectfill(bmp, 60, 430, 85, 455, makecol(255,0,0)); //RED COLOR PICK
     rectfill(bmp, 90, 430, 115, 455, makecol(0,255,0)); //GREEN COLOR PICK
     rectfill(bmp, 120, 430, 145, 455, makecol(0,0,255)); //BLUE COLOR PICK
     rectfill(bmp, 150, 430, 175, 455, makecol(240,240,0)); //Other Mixes
     rectfill(bmp, 180, 430, 205, 455, makecol(255,0,255));
     rectfill(bmp, 210, 430, 235, 455, makecol(0,0,0)); 
     rectfill(bmp, 240, 430, 265, 455, makecol(25,150,200)); 
     rectfill(bmp, 270, 430, 295, 455, makecol(205,25,160)); 

      
     
     
}
void gen_toolbox()
{
     rectfill(bmp, 0, 0, 100, 400,makecol(200,200,200));//Fill color in the frame toolbox
    hline(bmp,0,20,100,makecol(0,0,0)); 
    textprintf_centre_ex(bmp, font, 50, 7, makecol(20, 24, 100),-1,"NEW");//new drawing
    hline(bmp,0,40,100,makecol(0,0,0)); 
    textprintf_centre_ex(bmp, font, 50, 27, makecol(20, 24, 100),-1,"EXIT");//exit app
    hline(bmp,0,60,100,makecol(0,0,0)); 
    textprintf_centre_ex(bmp, font, 50, 47, makecol(20, 24, 100),-1,"Pencil");//Pencil tool selection
    hline(bmp,0,80,100,makecol(0,0,0)); 
    line(bmp,10,68,90,72,makecol(0,0,0));//line tool selection
    hline(bmp,0,100,100,makecol(0,0,0)); 
    rect(bmp,20,85,80,97,makecol(0,0,0));//rect tool selection
    hline(bmp,0,120,100,makecol(0,0,0)); 
    rectfill(bmp,20,105,80,117,makecol(0,0,0));//rectfill tool selection
    hline(bmp,0,170,100,makecol(0,0,0)); 
    circle(bmp,50,145,15,makecol(0,0,0));//circle tool selectionh
    hline(bmp,0,220,100,makecol(0,0,0)); 
    circlefill(bmp,50,195,15,makecol(0,0,0));//circle tool selection    
    hline(bmp,0,270,100,makecol(0,0,0)); 
    textprintf_centre_ex(bmp, font, 50, 240, makecol(20, 24, 100),-1,"Ereaser");//circle tool selection 
    rectfill(bmp,15,300,65,350,draw_color_sec);    
    rectfill(bmp,40,320,90,370,draw_color);
}
void check_color()
{
     if(getpixel(screen,mouse_x,mouse_y)!=frame_color)
     if(mouse_b==1)
     draw_color=getpixel(screen,mouse_x,mouse_y);     
     else if(mouse_b==2)
     draw_color_sec=getpixel(screen,mouse_x,mouse_y);    
     rectfill(bmp,15,300,65,350,draw_color_sec);    
    rectfill(bmp,40,320,90,370,draw_color);
}
void draw_fx()
{
    textprintf_centre_ex(bmp, font,600, 400, makecol(20, 24, 100),-1,"%d",tool);
     if (mouse_b==1)
     {
                    if(tool==3)
                    putpixel(bmp,mouse_x,mouse_y,draw_color);
                    else if(tool==4)
                    line(bmp,mouse_x,mouse_y,mouse_x+30,mouse_y,draw_color);
                    else if(tool==5)
                    rect(bmp,mouse_x,mouse_y,mouse_x+40,mouse_y+30,draw_color);
                    else if(tool==6)
                    rectfill(bmp,mouse_x,mouse_y,mouse_x+40,mouse_y+30,draw_color);
                    else if(tool==7)
                    circle(bmp,mouse_x,mouse_y,20,draw_color);
                    else if(tool==8)
                    circlefill(bmp,mouse_x,mouse_y,20,draw_color);
                    else if(tool==9)
                    rectfill(bmp,mouse_x,mouse_y,mouse_x+40,mouse_y+40,draw_color_sec);
                    

                    
          gen_frames();
     gen_pallete();
     gen_toolbox();
     }
} 
void check_toolbox()
{
          if(mouse_b==1)
          {
          if(mouse_y<20 && mouse_y>0)
          rectfill(bmp,102,0,640,400,draw_color_sec);
          else if(mouse_y<40 && mouse_y>20)
          exit(-1);
          else if(mouse_y<60 && mouse_y>40)
          tool=3;
          else if(mouse_y<80 && mouse_y>60)
          tool=4;
          else if(mouse_y<100 && mouse_y>80)
          tool=5;
          else if(mouse_y<120 && mouse_y>100)
          tool=6;
          else if(mouse_y<170 && mouse_y>120)
          tool=7;
          else if(mouse_y<220 && mouse_y>170)
          tool=8;
          else if(mouse_y<270 && mouse_y>220)
          tool=9;
          }

}
void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	set_window_title("PAINT APP Using Allegro By Ankush Chauhan");
}
void deinit() {
	clear_keybuf();
}
