#include <stdio.h>


int neg(int nb[] , int taille){ // renvoie 1 si le nombre est négatif et 0 si le nombre est positif
    int i;

    for ( i =  0 ; i < taille ; i++){
        if (nb[i] < 0){
            return 1;
            
        }
    }
    return 0;
}


int nb_a_conv(int nb_tab[],int tab_taille){
    int i;
    for (i = 0; i < tab_taille ; i++ ){
        if (nb_tab[i] != 0){
            return i;
        }
    }
}
void converte(int nb[], int taille){
    int nb_a = nb_a_conv(nb,1000);
    nb[nb_a] = nb[nb_a] * -1;
}

int comparer(int nb1[], int nb2[],int taille){
    int i;
    for (i = 0 ; i < taille ; i++){
        if (nb1[i] > nb2[i]){
            return 1 ;
        }
        else if (nb1[i] < nb2[i]){
            return 2;
        }
    }
    return 3 ;
}
char flush_space(){
    char c;
    scanf("%c", &c);
    while(c==' ')
        scanf("%c", &c);
    return c;
}
void shift(int tab[], int taille_tab, int taille_nb){
    int i;
    for(i=0; i<taille_nb; i++){
        tab[taille_tab-i-1]=tab[taille_nb-i-1];
        tab[taille_nb-i-1]=0;
    }
}
int is_num(char c){
    return c>='0' && c<='9';
}
int convert(char c){
    return c-'0';
}
char lire_nombre(int tab[], int taille){
    char cur=0; int minus=0; int i=0;
    cur=flush_space();
    if(cur=='-'){
        minus=1;
        cur=flush_space();
    }
    tab[0]=minus ?-convert(cur) : convert(cur);
    scanf("%c", &cur);
    for(i=1; is_num(cur);i++){
        tab[i]=convert(cur);
        scanf("%c", &cur);
    }
    shift(tab, taille, i);
    if(cur==' ')
        return flush_space();
    else
        return cur;
}
void display(int tab[], int taille){
    int i=0;
    for(i=0; i<taille && tab[i]==0; i++)
    ;
    for(;i<taille;i++)
        printf("%d", tab[i]);
    printf("\n");
}
void add_positive_num(int res[], int nb1[], int nb2[], int taille){
    int i=0;
    int ret=0;
    int cur=0;
    int dizaine;
    int unite;
    for(i=0; i<taille; i++){
        cur=nb1[taille-i-1]+nb2[taille-i-1]+ret;
        dizaine=cur/10;
        unite=cur%10;
        res[taille-i-1]=unite;
        ret=dizaine;
    }
}


void soustraction_normal(int res[], int nb1[], int nb2[], int taille){
    int i=0;
    int cur=0;
    for(i=0; i<taille; i++){

            if (nb1[taille-i-1] < nb2[taille-i-1]){
            nb1[taille-i-1]=nb1[taille-i-1]+10;
            nb2[taille-i-2]=nb2[taille-i-2]+1;
            cur=nb1[taille-i-1]-nb2[taille-i-1];
        }
        else {
            cur=nb1[taille-i-1]-nb2[taille-i-1];
        }
        res[taille-i-1]=cur;
    }
}

void soustraction_inverse(int res[], int nb1[], int nb2[], int taille){
    int i;
    int cur = 0 ;

    for (i = 0 ; i < taille ; i++ ){
        if (nb2[taille-i-1] < nb1[taille-i-1]){

            nb2[taille-i-1]=nb2[taille-i-1]+10;
            nb1[taille-i-2]=nb1[taille-i-2]+1;
            cur=nb2[taille-i-1] - nb1[taille-i-1];
        }
        else {
            cur=nb2[taille-i-1]-nb1[taille-i-1];
        }
        res[taille-i-1]=  cur;
    }
        converte(res,1000);
}

void soustraction(int res[], int nb1[], int nb2[], int taille){
    int comp = comparer(nb1,nb2,1000);
    int neg1 = neg(nb1,1000);
    int neg2 = neg(nb2,1000);
    if(neg1 == 0 && neg2 == 0){
        if (comp == 1){
        soustraction_normal(res, nb1, nb2, taille);
        }
        else if (comp == 2){
        soustraction_inverse(res, nb1, nb2, taille);
        }
    }
    else if (neg1 == 1 && neg2 == 1){
        converte(nb1, 1000);
        converte(nb2, 1000);
        soustraction_normal(res, nb2, nb1, taille);
    }
    else if (neg1 == 1 && neg2 == 0){
            converte(nb1,1000);
            add_positive_num(res, nb1, nb2, taille);
            converte(res,1000);
        }
    else if(neg1 == 0 && neg2 == 1){
            converte(nb2,1000);
            add_positive_num(res, nb1, nb2, taille);
        }
}

void addition(int res[], int nb1[], int nb2[], int taille){
    int comp = comparer(nb1,nb2,1000);
    int neg1 = neg(nb1,1000);
    int neg2 = neg(nb2,1000);

    if(neg1 == 0 && neg2 == 0){
        add_positive_num(res, nb1, nb2, taille);
    }
    else if (neg1 == 0 && neg2 == 1){
        converte(nb2,1000);
        soustraction(res, nb1, nb2, taille);
        }
    else if (neg1 == 1 && neg2 == 0){
        converte(nb1,1000);
        soustraction(res, nb1, nb2, taille);
        converte(res,1000);
    }
    else if (neg1 == 1 && neg2 == 1){
        converte(nb2,1000); converte(nb1,1000);
        addition(res, nb1, nb2, taille);
        converte(res,1000);
    }
}

int chiffre(int tab[], int tailletab){
    int i;
    for(i=0; i<tailletab && tab[i]==0; i++);
    return tailletab-i;
}



void decaler(int nb[1000], int decal){
    int i;
    int nc = chiffre(nb, 1000);
    for (i=0; i<=nc; i++){
        nb[1000-nc-decal+i]=nb[1000-nc+i];
    }
    for (i=0; i<decal; i++){
        nb[1000-i-1]=0;
    }
}
void multiply(int resf[], int nb1[], int nb2[], int taille){
    int i;
    int j;
    int nc = chiffre(nb2, taille);
    for (i=0; i<nc; i++){
        int rest[1000] = {0};
        for (j=1; j<=nb2[taille-i-1]; j++){
            addition(rest, rest, nb1, 1000);
        }
        decaler(rest, i);
        addition(resf, resf, rest, 1000);
    }
}

void multiplication(int res[], int nb1[], int nb2[], int taille){

    int neg1 = neg(nb1,1000);
    int neg2 = neg(nb2,1000);

    if (neg1 == 0 && neg2 == 0){
        multiply(res,nb1,nb2,1000);
    }
    else if (neg1 == 0 && neg2 == 1){
        converte(nb2, 1000);
        multiply(res,nb1,nb2,1000);
        converte(res,1000);
    }
    else if (neg1 == 1 && neg2 == 1){
        converte(nb2, 1000); converte(nb1, 1000);
        multiply(res,nb1,nb2,1000);
    }
    else if (neg1 == 1 && neg2 == 0){
        converte(nb1, 1000);
        multiply(res,nb1,nb2,1000);
        converte(res,1000);
    }

}


   

int main(){
    int nb1[1000]={0};
    int nb2[1000]={0};
    int nb3[1000]={0};
    int res1[1000]={0};
    int res2[1000]={0};
    char op1, op2;
    op1=lire_nombre(nb1, 1000);
    op2=lire_nombre(nb2, 1000);
    if(op2!='\n'){
        lire_nombre(nb3, 1000);
    }
    /*display(nb1, 1000);
    printf("%c\n", op1);
    display(nb2, 1000);
    printf("%c\n", op2);
    display(nb3, 1000);// 
        addition(res1, nb1, nb2, 1000);
        display(res1, 1000);*/
    if (op1 == '+' && op2 == '\n'){
        addition(res1,nb1,nb2,1000);
        display(res1, 1000);
    }
    else if (op1 == '+' && op2 == '+'){
        addition(res1,nb1,nb2,1000);
        addition(res2,res1,nb3,1000);
        display(res2,1000);
    }     
    else if (op1 == '+' && op2 == '-'){
        addition(res1,nb1,nb2,1000);
        soustraction(res2,res1,nb3,1000);
        display(res2,1000);
    }  
    else if (op1 == '-' && op2 == '\n'){
        soustraction(res1,nb1,nb2,1000);
        display(res1, 1000);
    }
   else if (op1 == '-' && op2 == '-'){
        soustraction(res1,nb1,nb2,1000);
        soustraction(res2,res1,nb3,1000);
        display(res2,1000);
    }
   else if (op1 == '-' && op2 == '+'){
        soustraction(res1,nb1,nb2,1000);
        addition(res2,res1,nb3,1000);
        display(res2,1000);
    }

   else if ( op1 == '*' && op2 == '*'){
        multiplication(res1, nb1, nb2, 1000);
        multiplication(res2, res1, nb3, 1000);
        display(res2,1000);
    }
    else if ( op1 == '*' && op2 == '\n'){
        multiplication(res1, nb1, nb2, 1000);
        display(res1,1000);
    }
   else if ( op1 == '*' && op2 == '+'){
        multiplication(res1, nb1, nb2, 1000);
        addition(res2, res1, nb3, 1000);
        display(res2,1000);
    }
   else if ( op1 == '*' && op2 == '-'){
        multiplication(res1, nb1, nb2, 1000);
        soustraction (res2, res1, nb3, 1000);
        display(res2,1000);
    }
   else if ( op1 == '+' && op2 == '*'){
        multiplication(res1, nb2, nb3, 1000);
        addition(res2,nb1, res1, 1000);
        display(res2,1000);
    }
   else if ( op1 == '-' && op2 == '*'){
        multiplication(res1, nb2, nb3, 1000);
        soustraction (res2, nb1, res1, 1000);
        display(res2,1000);
    }





}





