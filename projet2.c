#include <stdio.h>
int main(int argc, char* argv[]){

    int var1, var2, var3, var4, var5, var6, d1, d2, d3, d4, d5, d6;

    scanf ("%d%d%d%d%d%d", &var1, &var2, &var3, &var4, &var5, &var6);

    if (var1 > var2){
        if (var2 > var3){
             d3 = var1;
             d2 = var2;
             d1 = var3;
        }
        else{
            if (var1 > var3){
                 d3 = var1;
                 d2 = var3;
                 d1 = var2;
            }
            else{
                 d3 = var3;
                 d2 = var1;
                 d1 = var2;
            }
        }
    }
    
    else{
        if(var3 > var2){
             d3 = var3;
             d2 = var2;
             d1 = var1;
        }
        else{
            if (var3 > var1){
                 d3 = var2;
                 d2 = var3;
                 d1 = var1;
            }
            else{
                 d3 = var2;
                 d2 = var1;
                 d1 = var3;
            }
        }
    }
        
        
    if (var4 > var5){
        if (var5 > var6){
             d6 = var4;
             d5 = var5;
             d4 = var6;
        }
        else{
            if (var4 > var6){
                 d6 = var4;
                 d5 = var6;
                 d4 = var5;
            }
            else{
                 d6 = var6;
                 d5 = var4;
                 d4 = var5;
            }
        }
    }
    
    else{
        if(var6 > var5){
             d6 = var6;
             d5 = var5;
             d4 = var4;
        }
        else{
            if (var6 > var4){
                 d6 = var5;
                 d5 = var6;
                 d4 = var4;
            }
            else{
                 d6 = var5;
                 d5 = var4;
                 d4 = var6;
            }
        }
    }
        
    if (d3 == 4 && d2 == 2 && d1 == 1 && (d6 != 4 || d5 != 2 || d4 != 1)){
        printf("Player1 wins\n");
    }
    else{
        if (d6 == 4 && d5 == 2 && d4 == 1 && (d3 != 4 || d2 != 2 || d1 != 1)){
            printf("Player2 wins\n");
        }
        else{
            if (d6 == d3 && d5 == d2 && d4 == d1){
                printf("Draw\n");
            }
            else{
                if (d1 == d2 && d2 == d3 && (d6 != d5 || d6 != d4 || d5 != d4)){
                    printf("Player1 wins\n");
                }
                else{
                    if (d4 == d5 && d5 == d6 && (d3 != d2 || d3 != d1 || d2 != d1)){
                        printf("Player2 wins\n");
                    }
                    else{
                        if (d1 == 1 && d2 == 1 && d3 != 1 && (d4 != 1 || d5 != 1)){
                            printf("Player1 wins\n");
                        }
                        else{
                            if (d4 == 1 && d5 == 1 && d6 != 1 && (d1 != 1 || d2 != 1)){
                                printf("Player2 wins\n");
                            }
                            else{
                                if (d3 == d2+1 && d2 == d1+1 && (d6 != d5+1 || d5 != d4+1)){
                                    printf("Player1 wins\n");
                                }
                                else{
                                    if (d6 == d5+1 && d5 == d4+1 && (d3 != d2+1 || d2 != d1+1)){
                                        printf("Player2 wins\n");
                                    }
                                    else{
                                        if (d6 == d5+1 && d5 == d4+1 && d3 == d2+1 && d2 == d1+1 && d6 > d3){
                                            printf("Player2 wins\n");
                                        }
                                        else{
                                            if (d6 == d5+1 && d5 == d4+1 && d3 == d2+1 && d2 == d1+1 && d6 < d3){
                                                printf("Player1 wins\n");
                                            }
                                            else{
                                                if (d1 == d2 && d2 == d3 && d6 == d5 && d5 == d4 && d1 > d4){
                                                    printf("Player1 wins\n");
                                                }
                                                else{
                                                    if (d1 == d2 && d2 == d3 && d6 == d5 && d5 == d4 && d1 < d4){
                                                        printf("Player2 wins\n");
                                                    }
                                                    else{
                                                        if (d1 == 1 && d2 == 1 && d3 != 1 && d4 == 1 && d5 == 1 && d6 != 1 && d6 > d3){
                                                            printf("Player2 wins\n");
                                                        }
                                                        else{
                                                            if (d1 == 1 && d2 == 1 && d3 != 1 && d4 == 1 && d5 == 1 && d6 != 1 && d6 < d3){
                                                                printf("Player1 wins\n");
                                                            }
                                                            else{
                                                                if ((d3 > d6) || (d3 == d6 && d2 > d5) || (d3 == d6 && d2 == d5 && d1 > d4)){
                                                                    printf("Player1 wins\n");
                                                                }
                                                                else{
                                                                    printf("Player2 wins\n");
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
