/*									tab:8
 *
 * main.c - skeleton source file for ECE220 picture drawing program
 *
 * "Copyright (c) 2018 by Charles H. Zega, and Saransh Sinha."
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice and the following
 * two paragraphs appear in all copies of this software.
 * 
 * IN NO EVENT SHALL THE AUTHOR OR THE UNIVERSITY OF ILLINOIS BE LIABLE TO 
 * ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL 
 * DAMAGES ARISING OUT  OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, 
 * EVEN IF THE AUTHOR AND/OR THE UNIVERSITY OF ILLINOIS HAS BEEN ADVISED 
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * THE AUTHOR AND THE UNIVERSITY OF ILLINOIS SPECIFICALLY DISCLAIM ANY 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE 
 * PROVIDED HEREUNDER IS ON AN "AS IS" BASIS, AND NEITHER THE AUTHOR NOR
 * THE UNIVERSITY OF ILLINOIS HAS ANY OBLIGATION TO PROVIDE MAINTENANCE, 
 * SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 *
 * Author:	    Charles Zega, Saransh Sinha
 * Version:	    1
 * Creation Date:   12 February 2018
 * Filename:	    mp5.h
 * History:
 *	CZ	1	12 February 2018
 *		First written.
 */

 /* 思えば不思議だ。一生のなかで一番よくあるものなのに、よく見たことがない。
    ---MUJIません
  */

#include "mp5.h"

/*
	You must write all your code only in this file, for all the functions!
*/

/*  INTRODUCTORY PARAGRAPH
 *  This MP means to do some individual tasks and then make them all up to gain the final picture.
 *  Respectively,
 *  near_horizontal
 *      draws a pixel to all points in between the two given pixels including
 *      the end points
 *  near_vertical
 *      draws a pixel to all points in between the two given pixels including
 *      the end points
 *  draw_line
 *      draws a pixel to all points in between the two given pixels including
 *      the end points
 *  draw_rect
 *      draws a pixel to every point of the edges of the rectangle
 *  draw_triangle
 *      draws a pixel to every point of the edges of the triangle
 *  draw_parallelogram
 *      draws a pixel to every point of the edges of the parallelogram
 *  draw_circle
 *      draws a pixel to every point whose distance from the center is
 *      greater than or equal to inner_r and less than or equal to outer_r
 *  rect_gradient
 *      fills every pixel within the bounds of the rectangle with a color
 *      based on its position within the rectangle and the difference in
 *      color between start_color and end_color
 *  draw_picture
 *      alters the image by calling any of the other functions in the file
 *
 */






/* 
 *  near_horizontal
 *
 *	 
 *	
 *	
 * INPUTS: x_start,y_start -- the coordinates of the pixel at one end of the line
 * 	   x_end, y_end    -- the coordinates of the pixel at the other end
 * OUTPUTS: draws a pixel to all points in between the two given pixels including
 *          the end points
 * RETURN VALUE: 0 if any of the pixels drawn are out of bounds, otherwise 1
 * SIDE EFFECTS: none
 */

int32_t
near_horizontal(int32_t x_start, int32_t y_start, int32_t x_end, int32_t y_end){
	/* Your code goes here! */

    int32_t x,y,x1,x2,y1,y2,sgn;    // basic local variables set-up
    int32_t ret = 1;                // this is the flag
    
    if (x_start==x_end && y_start==y_end){ // when this is a dot, draw the dot immediately, with return value 1.
        draw_dot(x_start,y_start);
        return 1;
    }
    
    if (x_start<x_end) {            // time to set up x1 and x2.
        x1=x_start;
        x2=x_end;
        y1=y_start;
        y2=y_end;
    } else {
        x2=x_start;
        x1=x_end;
        y2=y_start;
        y1=y_end;
    }
    
    if(y2>y1) sgn = 1;              // time to set up sign(represented as "sgn")
    if(y2<y1) sgn = -1;
    if(y2==y1) sgn = 0;
    
    for (x=x1; x<=x2; x++) {        // main task for draw_horizontal
        y=y1+(2*(y2-y1)*(x-x1)+sgn*(x2-x1))/(2*(x2-x1));
        draw_dot(x,y);
        ret &= draw_dot(x,y);       ///notice that this ret HAVE to be ANDed.
    }
    return ret;
}


/* 
 *  near_vertical
 *	 
 *	 
 *	
 *	
 * INPUTS: x_start,y_start -- the coordinates of the pixel at one end of the line
 * 	   x_end, y_end    -- the coordinates of the pixel at the other end
 * OUTPUTS: draws a pixel to all points in between the two given pixels including
 *          the end points
 * RETURN VALUE: 0 if any of the pixels drawn are out of bounds, otherwise 1
 * SIDE EFFECTS: none
 */

int32_t
near_vertical(int32_t x_start, int32_t y_start, int32_t x_end, int32_t y_end){
	/* Your code goes here! */
    int32_t x,y,x1,x2,y1,y2,sgn;
    int32_t ret = 1;
    
    if (x_start==x_end && y_start==y_end){          // special case, only 1 dot.
        draw_dot(x_start,y_start);
        return 1;
    }
   
    if (y_start<y_end) {                            // time to set up x1 and x2.
        x1=x_start;
        x2=x_end;
        y1=y_start;
        y2=y_end;
    } else {
        x2=x_start;
        x1=x_end;
        y2=y_start;
        y1=y_end;
    }
    
    if(x2>x1) sgn = 1;          // set up sign(represented as "sgn")
    if(x2<x1) sgn = -1;
    if(x2==x1) sgn = 0;
    
    for (y=y1; y<=y2; y++) {    // main task for draw_vertical
        x=x1+(2*(x2-x1)*(y-y1)+sgn*(y2-y1))/(2*(y2-y1));
        draw_dot(x,y);
        ret &= draw_dot(x,y);
    }
	return ret;
}

/* 
 *  draw_line
 *	 
 *	 
 *	
 *	
 * INPUTS: x_start,y_start -- the coordinates of the pixel at one end of the line
 * 	   x_end, y_end    -- the coordinates of the pixel at the other end
 * OUTPUTS: draws a pixel to all points in between the two given pixels including
 *          the end points
 * RETURN VALUE: 0 if any of the pixels drawn are out of bounds, otherwise 1
 * SIDE EFFECTS: none
 */

int32_t
draw_line(int32_t x_start, int32_t y_start, int32_t x_end, int32_t y_end){
	/* Your code goes here! */

    float slope,x1,x2,y1,y2;                //IMPORTANT: the type MUST be float to make the slope continuous.
    int32_t ret = 1;
    if (x_start==x_end && y_start==y_end){  // if the two points given are identical
        near_vertical(x_start,y_start,x_end,y_end);
        ret = near_vertical(x_start,y_start,x_end,y_end);
    }
    
    if (x_start != x_end){                  // if the line is not perfectly vertical
        if (y_start<y_end) {
            x1=x_start;
            x2=x_end;
            y1=y_start;
            y2=y_end;
        } else {
            x2=x_start;
            x1=x_end;
            y2=y_start;
            y1=y_end;
        }
        slope=(y2-y1)/(x2-x1);              // time to calculate the slope
        if (slope>=-1 && slope<=1) {        // if the line is shallow (more horizontal)
            near_horizontal(x_start,y_start,x_end,y_end);
            ret = near_horizontal(x_start,y_start,x_end,y_end);
        }else{                              // if the line is steep (more vertical)
            near_vertical(x_start,y_start,x_end,y_end);
            ret = near_vertical(x_start,y_start,x_end,y_end);
        }
    }else{                                  // if the line is perfectly vertical
        near_vertical(x_start,y_start,x_end,y_end);
        ret = near_vertical(x_start,y_start,x_end,y_end);
    }
    
	return ret;
}


/* 
 *  draw_rect
 *	 
 *	 
 *	
 *	
 * INPUTS: x,y -- the coordinates of the of the top-left pixel of the rectangle
 *         w,h -- the width and height, respectively, of the rectangle
 * OUTPUTS: draws a pixel to every point of the edges of the rectangle
 * RETURN VALUE: 0 if any of the pixels drawn are out of bounds, otherwise 1
 * SIDE EFFECTS: none
 */

int32_t
draw_rect(int32_t x, int32_t y, int32_t w, int32_t h){
	/* Your code goes here! */
    int32_t ret = 1;
    if (w<=0 || h<0){                       // according to the document, this MUST be done.
        return 0;
    }
    draw_line(x,y,x+w,y);                   // draw the lines one by one to form the rectangele.
    ret &= draw_line(x,y,x+w,y);
    draw_line(x,y,x,y+h);
    ret &= draw_line(x,y,x,y+h);
    draw_line(x+w,y,x+w,y+h);
    ret &= draw_line(x+w,y,x+w,y+h);
    draw_line(x,y+h,x+w,x+h);
    ret &= draw_line(x,y+h,x+w,x+h);
    
    return ret;
}


/* 
 *  draw_triangle
 *	 
 *	 
 *	
 *	
 * INPUTS: x_A,y_A -- the coordinates of one of the vertices of the triangle
 *         x_B,y_B -- the coordinates of another of the vertices of the triangle
 *         x_C,y_C -- the coordinates of the final of the vertices of the triangle
 * OUTPUTS: draws a pixel to every point of the edges of the triangle
 * RETURN VALUE: 0 if any of the pixels drawn are out of bounds, otherwise 1
 * SIDE EFFECTS: none
 */

int32_t
draw_triangle(int32_t x_A, int32_t y_A, int32_t x_B, int32_t y_B, int32_t x_C, int32_t y_C){
	/* Your code goes here! */
    int32_t ret = 1;
    draw_line(x_A,y_A,x_B,y_B);             // draw the 3 sides of the triangle.
    ret &= draw_line(x_A,y_A,x_B,y_B);
    draw_line(x_B,y_B,x_C,y_C);
    ret &= draw_line(x_B,y_B,x_C,y_C);
    draw_line(x_A,y_A,x_C,y_C);
    ret &= draw_line(x_A,y_A,x_C,y_C);
    return ret;
}

/* 
 *  draw_parallelogram
 *	 
 *	 
 *	
 *	
 * INPUTS: x_A,y_A -- the coordinates of one of the vertices of the parallelogram
 *         x_B,y_B -- the coordinates of another of the vertices of the parallelogram
 *         x_C,y_C -- the coordinates of another of the vertices of the parallelogram
 * OUTPUTS: draws a pixel to every point of the edges of the parallelogram
 * RETURN VALUE: 0 if any of the pixels drawn are out of bounds, otherwise 1
 * SIDE EFFECTS: none
 */

int32_t
draw_parallelogram(int32_t x_A, int32_t y_A, int32_t x_B, int32_t y_B, int32_t x_C, int32_t y_C){
	/* Your code goes here! */
    int32_t x_D,y_D;
    int32_t ret = 1;
    x_D=x_A+x_C-x_B;                        // time to calculate the left point: where is it?
    y_D=y_A+y_C-y_B;
    
    draw_line(x_A,y_A,x_B,y_B);             // time to draw all the lines (4 sides).
    ret &= draw_line(x_A,y_A,x_B,y_B);
    draw_line(x_B,y_B,x_C,y_C);
    ret &= draw_line(x_B,y_B,x_C,y_C);
    draw_line(x_A,y_A,x_D,y_D);
    ret &= draw_line(x_A,y_A,x_D,y_D);
    draw_line(x_C,y_C,x_D,y_D);
    ret &= draw_line(x_C,y_C,x_D,y_D);
	return ret;
}


/* 
 *  draw_circle
 *	 
 *	 
 *	
 *	
 * INPUTS: x,y -- the center of the circle
 *         inner_r,outer_r -- the inner and outer radius of the circle
 * OUTPUTS: draws a pixel to every point whose distance from the center is
 * 	    greater than or equal to inner_r and less than or equal to outer_r
 * RETURN VALUE: 0 if any of the pixels drawn are out of bounds, otherwise 1
 * SIDE EFFECTS: none
 */

int32_t
draw_circle(int32_t x, int32_t y, int32_t inner_r, int32_t outer_r){
	/* Your code goes here!*/
    int32_t yt,xt,dsqr;                             // NOTICE: dsqr means d square, i.e., d^2.
    int32_t ret = 1;
    if (inner_r < 0 || outer_r < inner_r){          // special case.
        return 0;
    }
    for (xt=x-outer_r; xt<=x+outer_r; xt++) {       // main task for draw_circle.
        for (yt=y-outer_r; yt<=y+outer_r; yt++) {
            dsqr=(xt-x)*(xt-x)+(yt-y)*(yt-y);
            if (dsqr <= outer_r*outer_r && dsqr >= inner_r*inner_r) {
                draw_dot(xt,yt);
                ret &= draw_dot(xt,yt);
            }
        }
    }

	return ret;
}


/* 
 *  rect_gradient
 *	 
 *	 
 *	
 *	
 * INPUTS: x,y -- the coordinates of the of the top-left pixel of the rectangle
 *         w,h -- the width and height, respectively, of the rectangle
 *         start_color -- the color of the far left side of the rectangle
 *         end_color -- the color of the far right side of the rectangle
 * OUTPUTS: fills every pixel within the bounds of the rectangle with a color
 *	    based on its position within the rectangle and the difference in
 *          color between start_color and end_color
 * RETURN VALUE: 0 if any of the pixels drawn are out of bounds, otherwise 1
 * SIDE EFFECTS: none
 */

int32_t
rect_gradient(int32_t x, int32_t y, int32_t w, int32_t h, int32_t start_color, int32_t end_color){
	/* Your code goes here! */
    int32_t ret = 1; // the same as draw_rect
    int32_t level1,level2,level,xt,yt,sgn;
    int32_t R3,G3,B3,maskR,maskG,maskB;
    if (w<=0 || h<0){                   // special case (or we call it "edge case").
        return 0;
    }
    
    maskR = 0x00FF0000;                 // INNOVATIVE METHOD: use the mask to gain the right answer!
    maskG = 0x0000FF00;
    maskB = 0x000000FF;
    
    
    for (xt=x; xt<=x+w; xt++) {         // for every vertial line:
        for (yt=y; yt<=y+h; yt++){          // for every horizontal line:
            level1 = start_color & maskB;       // block for xxxx | RRRR | GGGG | BBBB
            level1 = level1 >> 0;               // BBBB
            level2 = end_color & maskB;
            level2 = level2 >> 0;
            
            if(level2>level1) sgn = 1;          // calculation
            if(level2<level1) sgn = -1;
            if(level2==level1) sgn = 0;
            
            B3 = level1+(2*(xt-x)*(level2-level1)+sgn*w)/(2*w);
            B3 = B3 << 0;
            //
            //
            level1 = start_color & maskG;       // GGGG
            level1 = level1 >> 8;
            level2 = end_color & maskG;
            level2 = level2 >> 8;
            
            if(level2>level1) sgn = 1;          // calculation
            if(level2<level1) sgn = -1;
            if(level2==level1) sgn = 0;
            
            G3 = level1+(2*(xt-x)*(level2-level1)+sgn*w)/(2*w);
            G3 = G3 << 8;
            //
            //
            level1 = start_color & maskR;       // RRRR
            level1 = level1 >> 16;
            level2 = end_color & maskR;
            level2 = level2 >> 16;
            
            if(level2>level1) sgn = 1;          // calculation
            if(level2<level1) sgn = -1;
            if(level2==level1) sgn = 0;
            
            R3 = level1+(2*(xt-x)*(level2-level1)+sgn*w)/(2*w);
            R3 = R3 << 16;
            //
            //
            level = R3 + G3 + B3;
            
            set_color(level);                   // time to draw the lines!
            ret &= draw_dot(xt,yt);             // INNOVATIVE METHOD: DO NOT NEED TO USE DRAW_DOT INDEPENDENTLY!
        }
    }
    
    return ret;
}


/* 
 *  draw_picture
 *	 
 *	 
 *	
 *	
 * INPUTS: none
 * OUTPUTS: alters the image by calling any of the other functions in the file
 * RETURN VALUE: 0 if any of the pixels drawn are out of bounds, otherwise 1
 * SIDE EFFECTS: none
 */


int32_t
draw_picture(){
	/* Your code goes here! */
    
    int32_t ret = 1;                            // I LOVE THIS PART!!!
    int32_t i;
    
    /* background color set-up.
     */
    
    rect_gradient(0,0,624,320,0xcc0000,0xffff99);
    
    /* iphone frame set-up.
     */
    
    
    for (i=0; i<=15; i++) {
        switch (i<=3) {
            case 1:
                set_color(0x007A99);
                break;
                
            default:
                set_color(0x000000);
                break;
        }
        
        
        ret &= draw_line(50+i,50,50+i,270);                         // left side verticle line.
        
        {
            int32_t x = 75, y = 50, inner_r = 25-i, outer_r = 26-i; // left up ciecle.
            int32_t yt,xt,dsqr;
            for (xt=x-outer_r; xt<=x; xt++) {
                for (yt=y-outer_r; yt<=y; yt++) {
                    dsqr=(xt-x)*(xt-x)+(yt-y)*(yt-y);
                    if (dsqr <= outer_r*outer_r && dsqr >= inner_r*inner_r) {
                        ret &= draw_dot(xt,yt);
                    }
                }
            }
        }
            
        ret &= draw_line(75,25+i,549,25+i);                             // up horizontal line.
        
        {
            int32_t x = 549, y = 50, inner_r = 25-i, outer_r = 26-i;    // right up ciecle.
            int32_t yt,xt,dsqr;
            for (xt=x; xt<=x+outer_r; xt++) {
                for (yt=y-outer_r; yt<=y; yt++) {
                    dsqr=(xt-x)*(xt-x)+(yt-y)*(yt-y);
                    if (dsqr <= outer_r*outer_r && dsqr >= inner_r*inner_r) {
                        ret &= draw_dot(xt,yt);
                    }
                }
            }
        }
        
        ret &= draw_line(574-i,50,574-i,270);                              // right verticle line.
        
        {
            int32_t x = 549, y = 270, inner_r = 25-i, outer_r = 26-i;      // right down ciecle.
            int32_t yt,xt,dsqr;
            for (xt=x; xt<=x+outer_r; xt++) {
                for (yt=y; yt<=y+outer_r; yt++) {
                    dsqr=(xt-x)*(xt-x)+(yt-y)*(yt-y);
                    if (dsqr <= outer_r*outer_r && dsqr >= inner_r*inner_r) {
                        ret &= draw_dot(xt,yt);
                    }
                }
            }
        }
        
        ret &= draw_line(75,295-i,549,295-i);                               // down horizontal line.
        
        {
            int32_t x = 75, y = 270, inner_r = 25-i, outer_r = 26-i;        // left down circle.
            int32_t yt,xt,dsqr;
            for (xt=x-outer_r; xt<=x; xt++) {
                for (yt=y; yt<=y+outer_r; yt++) {
                    dsqr=(xt-x)*(xt-x)+(yt-y)*(yt-y);
                    if (dsqr <= outer_r*outer_r && dsqr >= inner_r*inner_r) {
                        ret &= draw_dot(xt,yt);
                    }
                }
            }
        }
        
        
    }
    
    /* buttons drawing
     */
    
    set_color(0x000000);
    
    for (i=0; i<=1; i++) {                                                  // up big button.
        ret &= draw_line(170,23+i,250,23+i);
    }
   
    for (i=0; i<=1; i++) {                                                  // down small button 1.
        ret &= draw_line(130,296+i,150,296+i);
    }
    
    for (i=0; i<=1; i++) {                                                  // down small button 2.
        ret &= draw_line(170,296+i,210,296+i);
    }
 
    for (i=0; i<=1; i++) {                                                  // down small button 3.
        ret &= draw_line(230,296+i,270,296+i);
    }
    
    
    /* iphone bang set-up.
     */
    
    for (i=0; i<=20; i++) {
                set_color(0x000000);
        
        ret &= draw_line(84-i,100,84-i,220);                              // right vertical line.
        
        ret &= draw_line(74,90+i,55,90+i);                                // up horizontal line.
        ret &= draw_line(74,230-i,55,230-i);                              // down horizontal line.
        
        {
            int32_t x = 74, y = 100, inner_r = 10-i, outer_r = 11-i;  // right up ciecle.
            int32_t yt,xt,dsqr;
            for (xt=x; xt<=x+outer_r; xt++) {
                for (yt=y-outer_r; yt<=y; yt++) {
                    dsqr=(xt-x)*(xt-x)+(yt-y)*(yt-y);
                    if (dsqr <= outer_r*outer_r && dsqr >= inner_r*inner_r) {
                        ret &= draw_dot(xt,yt);
                    }
                }
            }
        }
            
        {
            int32_t x = 74, y = 220, inner_r = 10-i, outer_r = 11-i;  // right down ciecle.
            int32_t yt,xt,dsqr;
            for (xt=x; xt<=x+outer_r; xt++) {
                for (yt=y; yt<=y+outer_r; yt++) {
                    dsqr=(xt-x)*(xt-x)+(yt-y)*(yt-y);
                    if (dsqr <= outer_r*outer_r && dsqr >= inner_r*inner_r) {
                        ret &= draw_dot(xt,yt);
                    }
                }
            }
        }
        
        
    }
    
    
    for (i=0; i<=6; i++) {
        
        set_color(0xffffff);
        {
            int32_t x = 73, y = 120, inner_r = 3-i, outer_r = 4-i;  // camera place.
            int32_t yt,xt,dsqr;
            for (xt=x-outer_r; xt<=x+outer_r; xt++) {
                for (yt=y-outer_r; yt<=y+outer_r; yt++) {
                    dsqr=(xt-x)*(xt-x)+(yt-y)*(yt-y);
                    if (dsqr <= outer_r*outer_r && dsqr >= inner_r*inner_r) {
                        ret &= draw_dot(xt,yt);
                    }
                }
            }
        }
        
        {
            int32_t x = 73, y = 140, inner_r = 2-i, outer_r = 3-i;  // microphone place up circle.
            int32_t yt,xt,dsqr;
            for (xt=x-outer_r; xt<=x+outer_r; xt++) {
                for (yt=y-outer_r; yt<=y; yt++) {
                    dsqr=(xt-x)*(xt-x)+(yt-y)*(yt-y);
                    if (dsqr <= outer_r*outer_r && dsqr >= inner_r*inner_r) {
                        ret &= draw_dot(xt,yt);
                    }
                }
            }
        }
        
        {
            int32_t x = 73, y = 180, inner_r = 2-i, outer_r = 3-i;  // microphone place down circle.
            int32_t yt,xt,dsqr;
            for (xt=x-outer_r; xt<=x+outer_r; xt++) {
                for (yt=y; yt<=y+outer_r; yt++) {
                    dsqr=(xt-x)*(xt-x)+(yt-y)*(yt-y);
                    if (dsqr <= outer_r*outer_r && dsqr >= inner_r*inner_r) {
                        ret &= draw_dot(xt,yt);
                    }
                }
            }
        }
        
        draw_line(70+i,140,70+i,180);                               // microphone place lines inside.
        
    }
        
    /* screen contents set-up.
     */
    
    set_color(0x000000);
    
    // left person
    draw_circle(176,140,10,11); // left person head
    draw_line(182,152,196,172); // left person neck
    draw_line(196,172,186,186); // left person left arm
    draw_line(196,172,220,142); // left person right arm
    draw_line(196,172,212,188); // left person body
    draw_line(212,188,198,212); // left person left leg
    draw_line(212,188,242,202); // left person right leg
    
    // sword of left person
    draw_parallelogram(212,132,214,152,218,150); // sword handle
    draw_parallelogram(220,128,208,130,206,126); // sword PPQ
    draw_triangle(212,126,216,124,202,40);       // sword edge
    
    // right person
    draw_circle(420,130,10,11); // right person head
    draw_line(400,162,388,182); // right person neck
    draw_line(388,182,368,152); // right person left arm
    draw_line(388,182,358,162); // right person right arm
    draw_line(388,182,368,202); // right person body
    draw_line(368,202,328,212); // right person left leg
    draw_line(368,202,338,222); // right person right leg
    
    
    // blood
    set_color(0xff0000);
    draw_line(396,162,394,160); // blood, center at (400,162,388,182)
    draw_line(398,156,397,153);
    draw_line(402,156,404,150);
    draw_line(404,158,404,150);
    draw_line(402,160,412,154);
    draw_line(403,162,411,160);
    
    // ghost of blade
    {
        int32_t x = 50, y = 518, inner_r = 500, outer_r = 502; // left part
        int32_t yt,xt,dsqr;
        i = 0xffff00;
        
        for (xt=x+153; xt<=x+outer_r-64; xt++) {
            for (yt=y-outer_r; yt<=y-20; yt++) {
                dsqr=(xt-x)*(xt-x)+(yt-y)*(yt-y);
                if (dsqr <= outer_r*outer_r && dsqr >= inner_r*inner_r) {
                    i = i - 80;
                    set_color(i);
                    ret &= draw_dot(xt,yt);
                }
            }
        }
    }

    
    return ret;
}
