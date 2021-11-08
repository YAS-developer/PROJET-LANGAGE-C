#include <stdio.h>
 
/*int rectangle(){
    int N;
    scanf("%d",&N);
    int i;
    int j;
    for(i = 0 ;i < N; ++i){                
        printf("*");                     //N=4 1
        //printf ("\n"); 
            for ( j = 1; j < N ; ++j)     // 3
            {
            printf("*");  
            }  
            printf ("\n");    
    }
  
}*/
void AutreChoix (){
    printf ("Autre choix ?\n");
}

void sapindroit(){

                       
    int N;
    int i;
    int j;
    printf("Hauteur ?\n");
    scanf("%d", &N);
    while (N <= 0){ printf("Erreur de saisie. Hauteur ?\n");
    scanf("%d", & N);}
    for(i = 0 ;i < N; ++i){           
        
        
        for ( j = 0; j < i ; ++j)          
             { 
                printf ("*");

            }    
            printf("*\n");     
    }
    printf("\n");
}

void sapingauche(){ 
    int N;
    int i, j, c;
    printf("Hauteur ?\n");
    scanf("%d", &N);
    while (N <= 0){ printf("Erreur de saisie. Hauteur ?\n");
    scanf("%d", & N);}
    for (i = 0; i < N; i++){
        for (c=N-(i+1); c>0; c--){
        printf(" ");
        }
        for(j = 0; j < i+1; j++){
    printf("*");
    }
    printf("\n");
    }
    printf("\n");
} 

void sapin(){
    int N;
    int i;
    int j = 0;
    printf("Hauteur ?\n");
    scanf("%d", &N);
    while (N <= 0){ printf("Erreur de saisie. Hauteur ?\n");
    scanf("%d", & N);}
    for (;N>0; N--){
        j++;
        for (i=-N+1; i<0; i++){
            printf(" ");
            }
        for(i = 0; i < 2*j-1; i++){
            printf("*");
            }   
        printf("\n");
    }
    for ( i = 0; i < j-1; i++){
        printf(" ");
        }
    printf("*\n\n");
}

       

void carre(){
    int N;
    int i,j,c;
    printf("Cote ?\n");
    scanf ("%d",&N);
    while (N <= 0){ printf("Erreur de saisie. Cote ?\n");
    scanf("%d", & N);}
    for ( i = 0; i < N; i++){
        if (i == 0 || i == N-1){
            for (j = 0; j < N; j++){
                printf("*");
            }
        }
        else {
            for(c = 0; c < N; c++ ){
                if (c == 0 || c == N-1){
                    printf("*");
                }
                else{
                    printf (" ");        
                }
            }
        }
        printf ("\n");
        
    }
    printf("\n");
}

void losange(){
    int N;
    int i,j;
    printf("Cote ?\n");
    scanf ("%d",&N);
    while (N <= 0 ){ printf("Erreur de saisie. Cote ?\n");
    scanf("%d", & N);}
    for ( i = 0; i < N; i++){
        for ( j = i+1; j < N; j++){
            printf(" ");
        }
        printf("/");
        for (j = 1; j < 1+2*i; j++){
            printf(" ");
        }
        printf("\\\n");
    }
    for (i=0; i < N; i++){
        for ( j = 0; j < i; j++){
            printf(" ");
        }
        printf("\\");
        for (j = 1; j < 2*N - 2*i - 1; j++){
            printf(" ");
        }
        printf("/\n");
    }
    printf("\n");
}

void cinq(){
    int N; 
    int i,j;
    
    printf("Taille ?\n");
    scanf ("%d",&N);
    while (N < 3){ printf("Erreur de saisie. Taille ?\n");
    scanf("%d", & N);}
    for ( i = 1; i < N; i++){   
        printf("*");   
    }
    
    printf("*\n");

    for (i=(N-2); i > 0; i-- ){
        printf("*\n");
    }    
    
    for ( i = 1; i < N; i++){
        printf("*");
    }
    
    printf("*\n");    

    for ( i = (N-2) ; i > 0 ; i--){
        for (j= 1; j < N; j++){
            printf(" ");
        }
        printf("*\n");
    }
    
    for (i=0;i<N;i++){
        printf("*");
    }
    printf("\n\n");
    }





void instructions(){
    printf("Instructions:\n"
   "   Afficher sapin droite (a)\n"
   "   Afficher sapin gauche (b)\n"
   "   Afficher sapin complet (c)\n"
   "   Afficher carre (d)\n"
   "   Afficher losange (e)\n"
   "   Afficher cinq (f)\n"
   "   Afficher instructions (h)\n"   
   "   Quitter (q)\n\n"
   "Votre choix ?\n");
}


int main(){
    instructions();
    char choix;
    
    
    while (choix != 'q'){
    scanf(" %c",&choix);
    
    if(choix == 'a'){
        sapindroit();
        AutreChoix();
    }

    else if (choix == 'b'){
        sapingauche();
        AutreChoix();
    }

    else if(choix == 'c'){
        sapin();
        AutreChoix();
    }
    
    else if(choix == 'd'){
        carre();
        AutreChoix();
    }

    else if(choix == 'e'){
        losange();
        AutreChoix();
    }

    else if (choix == 'f'){
        cinq();
        AutreChoix();
    }

    else if(choix == 'h'){
        instructions();
    }
    else if (choix == 'q'){
        return 0;
    }
    else{ 
        printf("Erreur de saisie. Votre choix ?\n");
    }
    }
}

