#include <stdio.h>

int main (int argc, char* argv[]){
    char color;
    int diode1;
    int diode2;
    int nums;
    int nombatterie;
    int port; 
    
    scanf("%c %d %d %d %d %d" ,&color,&diode1,&diode2,&nums,&nombatterie,&port);
    
    int c = (diode1 == 1 && diode2 == 0 && (color == 'b'|| color =='r')) ||
            (color == 'b' && diode1 == 0 && diode2 == 0) ||
            
            (port == 1 && color == 'd' && diode1 == 1 && diode2 == 0) ||
            (port == 1 && color == 'n' && diode1 == 0 && diode2 == 1) ||
            (port == 1 && color == 'n' && diode1 == 1 && diode2 == 1) ||

            (nombatterie >= 2 && color == 'r'&& diode1 == 0 && diode2 == 1 )||
            (nombatterie >= 2 && color == 'r' && diode2 == 1 && diode1 == 1)||
            (nombatterie >= 2 && color == 'b' && diode1 == 1 && diode2 == 1)||

            (nums%2 == 0 && color == 'r' && diode1 == 0 && diode2 == 0 ) ||
            (nums%2 == 0 && color == 'd' && diode1 == 0 && diode2 == 0) ||
            (nums%2 == 0 && color == 'n' && diode1 == 0 && diode2 == 0) ||
            (nums%2 == 0 && color == 'd' && diode1 == 0 && diode2 == 1 );

    printf ("%d\n", c);
    return 0;
}
    
    
    
    
