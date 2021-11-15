#include <stdio.h>
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
int display(int tab[], int taille){
    int i=0;
    for(i=0; i<taille && tab[i]==0; i++)
    ;
    for(;i<taille;i++)
        printf("%d", tab[i]);
    printf("\n");
}
int negat(int tab[], int tailletab){
    int i;
    for(i=0; i<tailletab; i++){
        if (tab[i]!=0){
            return i;
        }
    }
}
void converte(int nb[], int taille){
    int degres = negat(nb, 1000);
    nb[degres]=nb[degres]*-1;
}
int detect(int nb[], int taille){
    int i;
    int negativite = 0;
    for (i=0; i<taille; i++){
        if (nb[i]<0){
            return 2;
        }
    }
    return 1;
}
int comparer(int nb1[], int nb2[], int taille){
    int i;
    int res=0;
    int detecter1 = detect(nb1, 1000);
    int detecter2 = detect(nb2, 1000);
    if (detecter1==2 && detecter2==1){
        return 2;
    }
    else if (detecter1==1 && detecter2==2){
        return 1;
    }
    else if ((detecter1==1 && detecter2==1) || (detecter1==2 && detecter2==2)){
        for (i=0; i<taille; i++){
            if (nb1[i]>nb2[i]){
                return 1;
            }
            else if (nb1[i]<nb2[i]){
                return 2;
            }
        }
    }
    return 3;
}
void soustraction_normale(int res[], int nb1[], int nb2[], int taille){
    int i=0;
    int cur=0;
    for(i=0; i<taille; i++){
        if (nb1[taille-i-1]<nb2[taille-i-1]){
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
void soustraction_contraire(int res[], int nb1[], int nb2[], int taille){
    int i=0;
    int cur=0;
    for(i=0; i<taille; i++){
        if (nb2[taille-i-1]<nb1[taille-i-1]){
            nb2[taille-i-1]=nb2[taille-i-1]+10;
            nb1[taille-i-2]=nb1[taille-i-2]+1;
            cur=nb2[taille-i-1]-nb1[taille-i-1];
        }
        else {
            cur=nb2[taille-i-1]-nb1[taille-i-1];
        }
        res[taille-i-1]=cur;
    }
    int degnb = negat(res, 1000);
    res[degnb]=-res[degnb];
}
void addition(int res[], int nb1[], int nb2[], int taille){
    int i=0;
    int ret=0;
    int cur=0;
    int dizaine;
    int unite;
    int detecter1 = detect(nb1, 1000);
    int detecter2 = detect(nb2, 1000);
    int comparaisontch = comparer(nb1, nb2, 1000);
    if (detecter1==1 && detecter2==2){
        converte(nb2, 1000);
        comparaisontch = comparer(nb1, nb2, 1000);
        if (comparaisontch==2){
            soustraction_contraire(res, nb1, nb2, 1000);
        }
        else if (comparaisontch==1){
            soustraction_normale(res, nb1, nb2, 1000);
        }
    }
    else if (detecter1==2 && detecter2==1){
        converte(nb1, 1000);
        comparaisontch = comparer(nb1, nb2, 1000);
        if (comparaisontch==2){
            soustraction_normale(res, nb2, nb1, 1000);
        }
        else if (comparaisontch==1){
            soustraction_contraire(res, nb2, nb1, 1000);
        }
    }
    else if (detecter1==2 && detecter2==2){
        converte(nb1, 1000);
        converte(nb2, 1000);
        comparaisontch = comparer(nb1, nb2, 1000);
        for(i=0; i<taille; i++){
        cur=nb1[taille-i-1]+nb2[taille-i-1]+ret;
        dizaine=cur/10;
        unite=cur%10;
        res[taille-i-1]=unite;
        ret=dizaine;
    }
    converte(res, 1000);
    }
    else {
    for(i=0; i<taille; i++){
        cur=nb1[taille-i-1]+nb2[taille-i-1]+ret;
        dizaine=cur/10;
        unite=cur%10;
        res[taille-i-1]=unite;
        ret=dizaine;
    }
    }
}
int chiffre(int tab[], int tailletab){
    int i;
    for(i=0; i<tailletab && tab[i]==0; i++);
    
    return tailletab-i;
}
void decale(int nb[1000], int leftmove){
    int i, pass;
    int degresnb = chiffre(nb, 1000);
    for (i=0; i<=degresnb; i++){
        nb[1000-degresnb-leftmove+i]=nb[1000-degresnb+i];
    }
    for (i=0; i<leftmove; i++){
        nb[1000-i-1]=0;
    }
}
void soustraction(int res[], int nb1[], int nb2[], int taille){
    int i=0;
    int cur=0;
    int detecter1 = detect(nb1, 1000);
    int detecter2 = detect(nb2, 1000);
    int comparaisontch = comparer(nb1, nb2, 1000);
    if (detecter1==1 && detecter2==1){
        if (comparaisontch==1){
            soustraction_normale(res, nb1, nb2, 1000);
        }
        else if (comparaisontch==2){
            soustraction_contraire(res, nb1, nb2, 1000);
        }
    }
    else if (detecter1==2 && detecter2==1){
        converte(nb1, 1000);
        addition(res, nb1, nb2, 1000);
        converte(res, 1000);
    }
    else if (detecter1==1 && detecter2==2){
        converte(nb2, 1000);
        addition(res, nb1, nb2, 1000);
    }
    else if (detecter1==2 && detecter2==2){
        converte(nb2, 1000);
        addition(res, nb1, nb2, 1000);
    }
}
void soustraction_division(int res[], int nb1[], int nb2[], int taille){
    int i=0;
    int cur=0, C1=0, C2=0, ret=0;
    for(i=0; i<taille; i++){
        C1=nb1[taille-i-1];
        C2=nb2[taille-i-1]+ret;
        if (C1<C2){
            ret=1;
            cur=10+C1-C2;
        }
        else {
            ret=0;
            cur=C1-C2;
        }
        res[taille-i-1]=cur;
    }
}
void division(int res[], int nb1[], int nb2[], int taille){
    int i, y;
    int comparaisontch = 0;
    int uniteun[1000] = {0}; 
    int tabalt[1000]= {0}; 
    int resf[1000]= {0};
    uniteun[999] = 1;
    int degnb1 = chiffre(nb1, 1000);
    int degnb2 = chiffre(nb2, 1000);
    int ecartDeg = degnb1 - degnb2 ;
    int detecter1 = detect(nb1, 1000);
    int detecter2 = detect(nb2, 1000);
    if (detecter1==2 && detecter2==1){
    converte(nb1, 1000);
    for (i=0; i<taille; i++){
        tabalt[i]=nb2[i];
    }
    for(i=ecartDeg; i >= 0; i--){
      decale(nb2,i);
      comparaisontch = comparer(nb1, nb2, 1000);
      for (y=0; y<taille; y++) resf[y]=0;

      while (comparaisontch == 1 || comparaisontch==3){
            soustraction_division(nb1, nb1, nb2, 1000);
            addition(resf, resf, uniteun, 1000);
            comparaisontch = comparer(nb1, nb2, 1000);
       }
        decale(resf,i);
        addition(res, res, resf, 1000);
        for (y=0; y<taille; y++){
             nb2[y]=tabalt[y];
    }
    }
    converte(res, 1000);
    }
    else if (detecter1==1 && detecter2==2){
        converte(nb2, 1000);
        for (i=0; i<taille; i++)tabalt[i]=nb2[i];

    for(i=ecartDeg; i >= 0; i--){
      decale(nb2,i);
      comparaisontch = comparer(nb1, nb2, 1000);
      for (y=0; y<taille; y++) resf[y]=0;

      while (comparaisontch == 1 || comparaisontch==3){
            soustraction_division(nb1, nb1, nb2, 1000);
            addition(resf, resf, uniteun, 1000);
            comparaisontch = comparer(nb1, nb2, 1000);
       }
        decale(resf,i);
        addition(res, res, resf, 1000);
        for (y=0; y<taille; y++) nb2[y]=tabalt[y];
    }
    converte(res, 1000);
    }
    else if (detecter1==2 && detecter2==2){
        converte(nb1, 1000);
        converte(nb2, 1000);
        for (i=0; i<taille; i++)tabalt[i]=nb2[i];

    for(i=ecartDeg; i >= 0; i--){
      decale(nb2,i);
      comparaisontch = comparer(nb1, nb2, 1000);
      for (y=0; y<taille; y++) resf[y]=0;

      while (comparaisontch == 1 || comparaisontch==3){
            soustraction_division(nb1, nb1, nb2, 1000);
            addition(resf, resf, uniteun, 1000);
            comparaisontch = comparer(nb1, nb2, 1000);
       }
        decale(resf,i);
        addition(res, res, resf, 1000);
        for (y=0; y<taille; y++) nb2[y]=tabalt[y];
    }
    }
    else {
        for (i=0; i<taille; i++)tabalt[i]=nb2[i];

    for(i=ecartDeg; i >= 0; i--){
      decale(nb2,i);
      comparaisontch = comparer(nb1, nb2, 1000);
      for (y=0; y<taille; y++) resf[y]=0;

      while (comparaisontch == 1 || comparaisontch==3){
            soustraction_division(nb1, nb1, nb2, 1000);
            addition(resf, resf, uniteun, 1000);
            comparaisontch = comparer(nb1, nb2, 1000);
       }
        decale(resf,i);
        addition(res, res, resf, 1000);
        for (y=0; y<taille; y++) nb2[y]=tabalt[y];
    }
    }
}
void multiplication(int resf[], int nb1[], int nb2[], int taille){
    int i;
    int j;
    int detecter1 = detect(nb1, 1000);
    int detecter2 = detect(nb2, 1000);
    int degresnb = chiffre(nb2, taille);
    if (detecter1==2 && detecter2==1){
    converte(nb1, 1000);
    for (i=0; i<degresnb; i++){
        int rest[1000] = {0};
        for (j=1; j<=nb2[taille-i-1]; j++){
            addition(rest, rest, nb1, 1000);
        }
        decale(rest, i);
        addition(resf, resf, rest, 1000);
    }
    converte(resf, 1000);
    }
    else if (detecter1==1 && detecter2==2){
    converte(nb2, 1000);
    for (i=0; i<degresnb; i++){
        int rest[1000] = {0};
        for (j=1; j<=nb2[taille-i-1]; j++){
            addition(rest, rest, nb1, 1000);
        }
        decale(rest, i);
        addition(resf, resf, rest, 1000);
    }
    converte(resf, 1000);
    }
    else if (detecter1==2 && detecter2==2){
    converte(nb1, 1000);
    converte(nb2, 1000);
    for (i=0; i<degresnb; i++){
        int rest[1000] = {0};
        for (j=1; j<=nb2[taille-i-1]; j++){
            addition(rest, rest, nb1, 1000);
        }
        decale(rest, i);
        addition(resf, resf, rest, 1000);
    }
    }
    else {
        for (i=0; i<degresnb; i++){
        int rest[1000] = {0};
        for (j=1; j<=nb2[taille-i-1]; j++){
            addition(rest, rest, nb1, 1000);
        }
        decale(rest, i);
        addition(resf, resf, rest, 1000);
    }
    }
}
void modulo(int res[], int nb1[], int nb2[], int taille){
    int i, y;
    int res1[1000]={0};
    int res2[1000]={0};
    int nb1vrai[1000]={0};
    int detecter1 = detect(nb1, 1000);
    int detecter2 = detect(nb2, 1000);
    if (detecter1==2 && detecter2==1){
    converte(nb1, 1000);
    for (i=0; i<taille; i++){
        nb1vrai[i]=nb1[i];
    }
    division(res1, nb1, nb2, taille);
    multiplication(res2, res1, nb2, taille);
    for (y=0; y<taille; y++){
        nb1[y]=nb1vrai[y];
    }
    soustraction(res, nb1, res2, taille);
    converte(res, 1000);
    }
    else if (detecter1==1 && detecter2==2){
    converte(nb2, 1000);
    for (i=0; i<taille; i++){
        nb1vrai[i]=nb1[i];
    }
    division(res1, nb1, nb2, taille);
    multiplication(res2, res1, nb2, taille);
    for (y=0; y<taille; y++){
        nb1[y]=nb1vrai[y];
    }
    soustraction(res, nb1, res2, taille);
    }
    else if (detecter1==2 && detecter2==2){
        converte(nb1, 1000);
        converte(nb2, 1000);
        for (i=0; i<taille; i++){
        nb1vrai[i]=nb1[i];
    }
    division(res1, nb1, nb2, taille);
    multiplication(res2, res1, nb2, taille);
    for (y=0; y<taille; y++){
        nb1[y]=nb1vrai[y];
    }
    soustraction(res, nb1, res2, taille);
    converte(res, 1000);
    }
    else {
        for (i=0; i<taille; i++){
        nb1vrai[i]=nb1[i];
    }
    division(res1, nb1, nb2, taille);
    multiplication(res2, res1, nb2, taille);
    for (y=0; y<taille; y++){
        nb1[y]=nb1vrai[y];
    }
    soustraction(res, nb1, res2, taille);
    }
}
int poubelle(int res[], int taille){
    int i;
    int vide[1000]={0};
    int comparaisontch=comparer(vide, res, 1000);
    for (i=0; i<taille; i++){
        if (comparaisontch==3){
            printf("0");
            return 0;
        }
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
    if(op2 =='\n'){
    if(op1 == '+')
    {
        addition(res1, nb1, nb2, 1000);
        poubelle(res1, 1000);
        display(res1, 1000);
    }
    else if (op1 == '-')
    {
        soustraction(res1, nb1, nb2, 1000);
        poubelle(res1, 1000);
        display(res1, 1000);
    }

    else if ( op1 == '*')
    {
        multiplication(res1, nb1, nb2, 1000);
        poubelle(res1, 1000);
        display(res1, 1000);
    }

    else if ( op1 == '/')
    {
        division(res1, nb1, nb2, 1000);
        poubelle(res1, 1000);
        display(res1, 1000);
    }

    else if ( op1 == '%')
    {
        modulo(res1, nb1, nb2, 1000);
        poubelle(res1, 1000);
        display(res1, 1000);
    }
    }
    
    if(op2!='\n'){
        lire_nombre(nb3, 1000);
    }
    
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

     else if ( op1 == '-' && op2 == '/')
    {
        division(res1, nb2, nb3, 1000);
        soustraction(res2, nb1, res1, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '-' && op2 == '%')
    {
        modulo(res1, nb2, nb3, 1000);
        soustraction(res2, nb1, res1, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '*' && op2 == '*')
    {
        multiplication(res1, nb1, nb2, 1000);
        multiplication(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '*' && op2 == '+')
    {
        multiplication(res1, nb1, nb2, 1000);
        addition(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '*' && op2 == '-')
    {
        multiplication(res1, nb1, nb2, 1000);
        soustraction(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '*' && op2 == '/')
    {
        multiplication(res1, nb1, nb2, 1000);
        division(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '*' && op2 == '%')
    {
        multiplication(res1, nb1, nb2, 1000);
        modulo(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '/' && op2 == '/')
    {
        division(res1, nb1, nb2, 1000);
        division(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '/' && op2 == '*')
    {
        division(res1, nb1, nb2, 1000);
        multiplication(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '/' && op2 == '-')
    {
        division(res1, nb1, nb2, 1000);
        soustraction(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '/' && op2 == '+')
    {
        division(res1, nb1, nb2, 1000);
        addition(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '/' && op2 == '%')
    {
        division(res1, nb1, nb2, 1000);
        multiplication(res2, res1, nb3, 1000); 
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '%' && op2 == '%')
    {
        modulo(res1, nb1, nb2, 1000);
        modulo(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '%' && op2 == '*')
    {
        modulo(res1, nb1, nb2, 1000);
        multiplication(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '%' && op2 == '/')
    {
        modulo(res1, nb1, nb2, 1000);
        division(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '%' && op2 == '+')
    {   
        modulo(res1, nb1, nb2, 1000);
        addition(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '%' && op2 == '-')
    {
        modulo(res1, nb1, nb2, 1000);
        soustraction(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '-' && op2 == '-')
    {
        soustraction(res1, nb1, nb2, 1000);
        soustraction(res2,res1,nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '*' && op2 == '*')
    {
        multiplication(res1, nb1, nb2, 1000);
        multiplication(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '*' && op2 == '+')
    {
        multiplication(res1, nb1, nb2, 1000);
        addition(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '*' && op2 == '-')
    {
        multiplication(res1, nb1, nb2, 1000);
        soustraction (res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '+' && op2 == '*')
    {
        multiplication(res1, nb2, nb3, 1000);
        addition(res2,nb1, res1, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    
    else if ( op1 == '-' && op2 == '*')
    {
        multiplication(res1, nb2, nb3, 1000);
        soustraction (res2, nb1, res1, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
}
    


