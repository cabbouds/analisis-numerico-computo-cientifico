/*
 * ejercicio2.c
 *
 *  Created on: Mar 2, 2017
 *      Author: Javier Quiroz
 */
#include<stdio.h>

#define MAXLINEA 1000 /*máximo tamaño de una línea*/


/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/
int obtenlinea(void);
void copia(void);



/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
    int c;
    int i;
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++)
        linea[i] = c;
    if(c == '\n'){
        linea[i] = c;
        i++;
    }
    linea[i]='\0'; //este caracter es necesario para almacenar strings
    return i;
}

/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void){
    int i;
    extern char linea[], linea_max[];
    i=0;
    while(1){
        linea_max[i] = linea[i];
        if( linea_max[i] == '\0' ) break;
        if( linea_max[i] == " " ) i--;
        i++;
    }
}

/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia_con_i(void){
    int i;
    extern char linea[], linea_max[];
    i=0;
    while(linea_max[i]){
        linea_max[i] = linea[i] ;
        if( linea_max[i] == " " ) i--; // ignora los espacions
        i++;
    }
    linea_max[i] = '\0'; //asegura que la cadena tenga un terminador
}

void copia_con_apuntadores(void){
    extern char linea[], linea_max[];

    char* plinea = linea;
    char* plinea_max = linea_max;
    while(*plinea ){
    	*plinea_max = *plinea;
        if( *plinea_max == " " ) plinea_max --; // ignorar los blancos
    	plinea++;
        plinea_max++;
     }
    *plinea_max = '\0';  // asegura que la cadena tenga un terminador
}


void voltea(char *cadena){
    int len;
    extern char linea[], linea_max[];


    char * inicio =  cadena;
    len = strlen(cadena);
    char *p = inicio +len-1;
    while(inicio <= p ){
    	putchar(*p);
    	p--;
     }
}




/*
 * Respuesta al a pregunta f)
 * Qué efecto tiene escribir extern para la declaración de variables dentro de main(), getline() y copia()?
 *
 * Respuesta:
 * Declara a las variable como definidas fuera del cuerpo de la funciones. En este caso estas variables son
 * globales y se definen al principio del programa (lineas 14 y 15)
 *
 *
 *
 */
/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0)
        if( longitud > max){
            max = longitud;
            copia();
        }
    if(strlen(linea_max) > 80)
        printf("%s", linea_max);
return 0;
}
/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    char* mi_cadena= "esta es una cadena";
    char mi_cadena2[] = "esta es otra";
    voltea(mi_cadena);
    voltea(mi_cadena2);

return 0;
}

