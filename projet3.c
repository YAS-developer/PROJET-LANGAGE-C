#include <stdio.h>
// Fonction min et max
int max(int i1, int i2) {
	return (i1 > i2) ? i1 : i2;
}
int min(int i1, int i2) {
	return (i1 < i2) ? i1 : i2;
}
int max5(int i1, int i2, int i3, int i4, int i5) {
	return max(max(max(i1, i2), max(i3, i4)), i5);
}
int min5(int i1, int i2, int i3, int i4, int i5) {
	return min(min(min(i1, i2), min(i3, i4)), i5);
}
int first(int i1, int i2, int i3, int i4, int i5) {
	return max5(i1, i2, i3, i4, i5);
}
int second(int i1, int i2, int i3, int i4, int i5) {
	int rem = first(i1, i2, i3, i4, i5);
    if (rem == i1)
	   i1 = 0;
    else if (rem == i2)
	   i2 = 0;
    else if (rem == i3)
	   i3 = 0;
    else if (rem == i4)
	   i4 = 0;
    else if (rem == i5)
	   i5 = 0;
	return first(i1, i2, i3, i4, i5);
}
int third(int i1, int i2, int i3, int i4, int i5) {
	int rem1 = first(i1, i2, i3, i4, i5);
    if (rem1 == i1)
	   i1 = 0;
    else if (rem1 == i2)
	   i2 = 0;
    else if (rem1 == i3)
	   i3 = 0;	   
    else if (rem1 == i4)
	   i4 = 0;	   
    else if (rem1 == i5)
	   i5 = 0;
	return second(i1, i2, i3, i4, i5);
}
int fourth(int i1, int i2, int i3, int i4, int i5) {
	int rem1 = first(i1, i2, i3, i4, i5);
    if (rem1 == i1)
	   i1 = 0;
    else if (rem1 == i2)
	   i2 = 0;
    else if (rem1 == i3)
	   i3 = 0;	   
    else if (rem1 == i4)
	   i4 = 0;	   
    else if (rem1 == i5)
	   i5 = 0;
	return third(i1, i2, i3, i4, i5);
}
int fifth(int i1, int i2, int i3, int i4, int i5) {
	return min5(i1, i2, i3, i4, i5);
}
// Les valeurs du jeu
int valeurjeu(int i1, char c1, int i2, char c2, int i3, char c3, int i4, char c4, int i5, char c5){
    if ((i1==i2 && i3!=i4 && i4!=i5 && i3!=i1 ) || (i2==i3 && i1!=i2 && i3!=i4 && i4!=i5 ) || (i3==i4 && i1!=i2 && i2!=i3 && i5!=i3 ) || (i4==i5 && i2!=i1 && i3!=i4 && i2!=i3))
        return 2;
    else if ((i1==i2 && i3==i4 && !(i2==i3) && !(i5==i3)) || (i1==i2 && i4==i5 && !(i3==i1) && !(i3==i4)) || (i2==i3 && i4==i5 && !(i3==i4) && !(i1==i2)))
        return 3;
    else if ((i1==i2 && i2==i3 && i4!=i3 && i4!=i5) || (i3==i4 && i4==i5 && i2!=i3 && i2!=i1) || (i2==i3 && i3==i4 && i1!=i2 && i5!=i4))
        return 4;
    else if (i2==i1-1 && i3==i1-2 && i4==i1-3 && i5==i1-4 && c1==c2 && c2==c3 && c3==c4 && c4==c5)
        return 9;
    else if (i2==i1-1 && i3==i1-2 && i4==i1-3 && i5==i1-4)
        return 5;
    else if (c1==c2 && c2==c3 && c3==c4 && c4==c5)
        return 6;
    else if ((i1==i2 && i2==i3 && i4==i5) || (i3==i4 && i4==i5 && i1==i2))
        return 7; 
    else if ((i1==i2 && i2==i3 && i3==i4) || (i2==i3 && i3==i4 && i4==i5 && i1!=i2))
        return 8;
    else
        return 1;
}
int main(int argc, char* argv[]){
    int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;
    char c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;
    scanf("%d %c %d %c %d %c %d %c %d %c %d %c %d %c %d %c %d %c %d %c", &i1, &c1, &i2, &c2, &i3, &c3, &i4, &c4, &i5, &c5, &i6, &c6, &i7, &c7, &i8, &c8, &i9, &c9, &i10, &c10);
    // Affecter variable
    int in1 = first(i1, i2, i3, i4, i5);
    int in2 = second(i1, i2, i3, i4, i5);
    int in3 = third(i1, i2, i3, i4, i5); 
    int in4 = fourth(i1, i2, i3, i4, i5);
    int in5 = fifth(i1, i2, i3, i4, i5);
    int in6 = first(i6, i7, i8, i9, i10);
    int in7 = second(i6, i7, i8, i9, i10);
    int in8 = third(i6, i7, i8, i9, i10);
    int in9 = fourth(i6, i7, i8, i9, i10); 
    int in10 = fifth(i6, i7, i8, i9, i10);
    if ((in5==1 && in4!=1 && in3!=1 && in2!=1 && in1!=1) && (in1!=5 || in2!=4 || in3!=3 || in4!=2)){
        in5 = 14;
    }
    if (in5==1 && in4==1 && in3!=1 && in2!=1 && in1!=1){
        in5 = 14;
        in4 = 14;
    }
    if (in5==1 && in4==1 && in3==1 && in2!=1 && in1!=1){
        in5 = 14;
        in4 = 14;
        in3 = 14;
    }
    if (in5==1 && in4==1 && in3==1 && in2==1 && in1!=1){
        in5 = 14;
        in4 = 14;
        in3 = 14;
        in2 = 14;
    }
    if (in5==1 && in4==1 && in3==1 && in2==1 && in1==1){ 
        in5 = 14;
        in4 = 14;
        in3 = 14;
        in2 = 14;
        in1 = 14;
    }
    if ((in10==1 && in9!=1 && in8!=1 && in7!=1 && in6!=1) && (in6!=5 || in7!=4 || in8!=3 || in9!=2)){
        in10 = 14;
    }
    if (in10==1 && in9==1 && in8!=1 && in7!=1 && in6!=1){
        in10 = 14;
        in9 = 14;
    }
    if (in10==1 && in9==1 && in8==1 && in7!=1 && in6!=1){
        in10 = 14;
        in9 = 14;
        in8 = 14;
    }
    if (in10==1 && in9==1 && in8==1 && in7==1 && in6!=1){
        in10 = 14;
        in9 = 14;
        in8 = 14;
        in7 = 14;
    }
    if (in10==1 && in9==1 && in8==1 && in7==1 && in6==1){ 
        in10 = 14;
        in9 = 14;
        in8 = 14;
        in7 = 14;
        in6 = 14;
    }
    int inn1 = first(in1, in2, in3, in4, in5);
    int inn2 = second(in1, in2, in3, in4, in5);
    int inn3 = third(in1, in2, in3, in4, in5); 
    int inn4 = fourth(in1, in2, in3, in4, in5);
    int inn5 = fifth(in1, in2, in3, in4, in5);
    int inn6 = first(in6, in7, in8, in9, in10);
    int inn7 = second(in6, in7, in8, in9, in10);
    int inn8 = third(in6, in7, in8, in9, in10);
    int inn9 = fourth(in6, in7, in8, in9, in10); 
    int inn10 = fifth(in6, in7, in8, in9, in10);
    // Combinaisons différentes
    int vlj1=valeurjeu(inn1, c1, inn2, c2, inn3, c3, inn4, c4, inn5, c5);
    int vlj2=valeurjeu(inn6, c6, inn7, c7, inn8, c8, inn9, c9, inn10, c10);
    if (vlj1 > vlj2)
        printf("Player1 wins\n");
    else if (vlj1 < vlj2)
        printf("Player2 wins\n");
    // Egalité
    else if (inn1==inn6 && inn2==inn7 && inn3==inn8 && inn4==inn9 && inn5==inn10)
        printf("Draw\n");
    // Carte Haute
    else if (vlj1==1){
        if ((inn1>inn6) || (inn1==inn6 && inn2>inn7) || (inn1==inn6 && inn2==inn7 && inn3>inn8) || 
            (inn1==inn6 && inn2==inn7 && inn3==inn8 && inn4>inn9) || 
            (inn1==inn6 && inn2==inn7 && inn3==inn8 && inn4==inn9 && inn5>inn10))
            printf("Player1 wins\n" );
        else if ((inn1<inn6) || (inn1==inn6 && inn2<inn7) || (inn1==inn6 && inn2==inn7 && inn3<inn8) || 
                (inn1==inn6 && inn2==inn7 && inn3==inn8 && inn4<inn9) || 
                (inn1==inn6 && inn2==inn7 && inn3==inn8 && inn4==inn9 && inn5<inn10))
            printf("Player2 wins\n");
    }
    // Paire 
    else if (vlj1==2){
        if ((inn1==inn2 && inn6==inn7 && inn1>inn7) || (inn1==inn2 && inn7==inn8 && inn1>inn7) || (inn1==inn2 && inn8==inn9 && inn1>inn8) || (inn1==inn2 && inn9==inn10 && inn1>inn9) || 
            (inn2==inn3 && inn6==inn7 && inn2>inn6) || (inn2==inn3 && inn7==inn8 && inn2>inn7) || (inn2==inn3 && inn8==inn9 && inn2>inn8) || (inn2==inn3 && inn9==inn10 && inn2>inn9) ||
            (inn3==inn4 && inn6==inn7 && inn3>inn6) || (inn3==inn4 && inn7==inn8 && inn3>inn7) || (inn3==inn4 && inn8==inn9 && inn3>inn9) || (inn3==inn4 && inn9==inn10 && inn3>inn9) || 
            (inn4==inn5 && inn6==inn7 && inn4>inn7) || (inn4==inn5 && inn7==inn8 && inn4>inn7) || (inn4==inn5 && inn8==inn9 && inn4>inn8) || (inn4==inn5 && inn9==inn10 && inn4>inn9)) 
            printf("Player1 wins\n");
        else if ((inn1==inn2 && inn6==inn7 && inn1==inn7 && (inn3>inn8 || (inn3==inn8 && inn4>inn9) || (inn3==inn8 && inn4==inn9 && inn5>inn10))) || 
            (inn2==inn3 && inn6==inn7 && inn2==inn6) || 
            (inn2==inn3 && inn7==inn8 && inn2==inn7 && (inn1>inn6 || (inn1==inn6 && inn4>inn9) || (inn1==inn6 && inn4==inn9 && inn5>inn10))) || 
            (inn2==inn3 && inn9==inn10 && inn2==inn9 && inn1>inn6) ||
            (inn3==inn4 && inn6==inn7 && inn3==inn6) || 
            (inn3==inn4 && inn7==inn8 && inn3==inn7 && inn1>inn6) || 
            (inn3==inn4 && inn8==inn9 && inn3==inn9 && (inn1>inn6 || (inn1==inn6 && inn2>inn7) || (inn1==inn6 && inn2==inn7 && inn5>inn10))) || 
            (inn3==inn4 && inn9==inn10 && inn3==inn9 && (inn1>inn6 || (inn1==inn6 && inn2>inn7))) || 
            (inn4==inn5 && inn6==inn7 && inn4==inn7) || 
            (inn4==inn5 && inn7==inn8 && inn4==inn7 && inn1>inn6) || 
            (inn4==inn5 && inn8==inn9 && inn4==inn8 && (inn1>inn6 || (inn1==inn6 && inn2>inn7))) || 
            (inn4==inn5 && inn9==inn10 && inn4==inn9 && (inn1>inn6 || (inn1==inn6 && inn2>inn7) || (inn1==inn6 && inn2==inn7 && inn3>inn8)))) 
            printf("Player1 wins\n");
        else 
            printf("Player2 wins\n");
    }
    // Brelan
    else if (vlj1==4){
        if ((inn1==inn2 && inn2==inn3 && inn6==inn7 && inn7==inn8 && inn1>inn6) || (inn1==inn2 && inn2==inn3 && inn8==inn9 && inn9==inn10 && inn1>inn7) || 
            (inn1==inn2 && inn2==inn3 && inn7==inn8 && inn8==inn9 && inn1>inn7) || (inn3==inn4 && inn4==inn5 && inn6==inn7 && inn7==inn8 && inn3>inn7) || 
            (inn3==inn4 && inn4==inn5 && inn8==inn9 && inn9==inn10 && inn3>inn8) || (inn3==inn4 && inn4==inn5 && inn7==inn8 && inn8==inn9 && inn3>inn8) || 
            (inn2==inn3 && inn3==inn4 && inn6==inn7 && inn7==inn8 && inn3>inn8) || (inn2==inn3 && inn3==inn4 && inn8==inn9 && inn9==inn10 && inn3>inn8) || 
            (inn2==inn3 && inn3==inn4 && inn7==inn8 && inn8==inn9 && inn3>inn8))
            printf("Player1 wins\n");
        else 
            printf("Player2 wins\n");
    }
    // Carré
    else if (vlj1==8){
        if ((inn1==inn2 && inn2==inn3 && inn3==inn4 && inn6==inn7 && inn7==inn8 && inn8==inn9 && inn1>inn7) || (inn1==inn2 && inn2==inn3 && inn3==inn4 && inn7==inn8 && inn8==inn9 && inn9==inn10 && inn1>inn7) || 
            (inn2==inn3 && inn3==inn4 && inn4==inn5 && inn6==inn7 && inn7==inn8 && inn8==inn9 && inn2>inn7) || (inn2==inn3 && inn3==inn4 && inn4==inn5 && inn7==inn8 && inn8==inn9 && inn9==inn10 && inn2>inn7))
            printf("Player1 wins\n");
        else  
            printf("Player2 wins\n");
    }
    // Suite Quinte Flush
    else if (vlj1==5 || vlj1==9){
        if (inn1>inn6)
            printf("Player1 wins\n");
        else if (inn1<inn6)
            printf("Player2 wins\n");
        else 
            printf("Draw\n");
    }
    // Couleur
    else if (vlj1==6){
        if ((inn1>inn6) || (inn1==inn6 && inn2>inn7) || (inn1==inn6 && inn2==inn7 && inn3>inn8) || 
            (inn1==inn6 && inn2==inn7 && inn3==inn8 && inn4>inn9) || 
            (inn1==inn6 && inn2==inn7 && inn3==inn8 && inn4==inn9 && inn5>inn10))
            printf("Player1 wins\n" );
        else if ((inn1<inn6) || (inn1==inn6 && inn2<inn7) || (inn1==inn6 && inn2==inn7 && inn3<inn8) || 
                (inn1==inn6 && inn2==inn7 && inn3==inn8 && inn4<inn9) || 
                (inn1==inn6 && inn2==inn7 && inn3==inn8 && inn4==inn9 && inn5<inn10))
            printf("Player2 wins\n");
    }
    // Full
    else if (vlj1==7){
        if ((inn1==inn2 && inn2==inn3 && inn4==inn5 && inn6==inn7 && inn7==inn8 && inn9==inn10 && inn1>inn6) || 
            (inn1==inn2 && inn2==inn3 && inn4==inn5 && inn8==inn9 && inn9==inn10 && inn6==inn7 && inn1>inn8) || 
            (inn3==inn4 && inn4==inn5 && inn1==inn2 && inn6==inn7 && inn7==inn8 && inn9==inn10 && inn3>inn6) || 
            (inn3==inn4 && inn4==inn5 && inn1==inn2 && inn8==inn9 && inn9==inn10 && inn6==inn7 && inn3>inn8))
            printf("Player1 wins\n");
        else 
            printf("Player2 wins\n"); 
    }
    // Double Paire
    else if (vlj1==3){
        if ((inn1==inn2 && inn3==inn4 && inn6==inn7 && inn8==inn9 && inn1>inn6) || 
        (inn1==inn2 && inn3==inn4 && inn6==inn7 && inn9==inn10 && inn1>inn6) || 
        (inn1==inn2 && inn3==inn4 && inn7==inn8 && inn9==inn10 && inn1>inn7) || 
        (inn1==inn2 && inn4==inn5 && inn6==inn7 && inn8==inn9 && inn1>inn6) || 
        (inn1==inn2 && inn4==inn5 && inn6==inn7 && inn9==inn10 && inn1>inn6) || 
        (inn1==inn2 && inn4==inn5 && inn7==inn8 && inn9==inn10 && inn1>inn7) || 
        (inn2==inn3 && inn4==inn5 && inn6==inn7 && inn8==inn9 && inn2>inn6) || 
        (inn2==inn3 && inn4==inn5 && inn6==inn7 && inn9==inn10 && inn2>inn6) ||
        (inn2==inn3 && inn4==inn5 && inn7==inn8 && inn9==inn10 && inn2>inn7))
            printf("Player1 wins\n");
        else
            printf("Player2 wins\n");
    }
}

