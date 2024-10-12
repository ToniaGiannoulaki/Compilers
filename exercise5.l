%{
 #include <stdio.h>
 int flag = 0; //metraei ta shmeia
 int i = 0; //metrhths
 int j = 0; //metrhths
 int x1 = 0; //pairnei ton arithmo pou steilame sth sunarthsh Shape()
 int ret = 0; //pairnei auto pou epistrefei h Shape()
 char *s = " "; //pointer pou einai isos me " " (to xrhsimopoioume gia na doume an uparxoun kena sto input tou xrhsth)
%}
Alphabet [A-H]
Point "point"" "*{Alphabet}{1}
Straight_Line "straight line"" "*{Alphabet}{2}
Triangle "triangle"" "*{Alphabet}{3}
Square "square"" "*{Alphabet}{4}
Pentagon "pentagon"" "*{Alphabet}{5}
Hexagon "hexagon"" "*{Alphabet}{6} 
Heptagon "heptagon"" "*{Alphabet}{7}
Octagon "octagon"" "*{Alphabet}{8}
%%
{Point} {
  printf("This is a point");
}
{Straight_Line} {
  ret = Shape(2);
  if(ret == 2){
    printf("This is a straight line");
  }
  else{
    printf("Unrecognized expression");
  }
}
{Triangle} {
  ret = Shape(3);
  if(ret == 3){
    printf("This is a triangle");
  }
  else{
    printf("Unrecognized expression");
  }
}
{Square} {
  ret = Shape(4);
  if(ret == 4){
    printf("This is a square");
  }
  else{
    printf("Unrecognized expression");
  }
}
{Pentagon} {
  ret = Shape(5);
  if(ret == 5){
    printf("This is a pentagon");
  }
  else{
    printf("Unrecognized expression");
  }
}
{Hexagon} {
  ret = Shape(6);
  if(ret == 6){
    printf("This is a hexagon");
  }
  else{
    printf("Unrecognized expression");
  }
}
{Heptagon} {
  ret = Shape(7);
  if(ret == 7){
    printf("This is a heptagon");
  }
  else{
    printf("Unrecognized expression");
  }
}
{Octagon} {
    ret = Shape(8);
  if(ret == 8){
    printf("This is an octagon");
  }
  else{
    printf("Unrecognized expression");
  }
}
[^\n]+ printf("Unrecognized expression");
%%
main() {
  yylex();
}

int Shape(int x){
  flag = 0; 
  x1 = x;
  char *yycopy = strdup(yytext);
  for(i = yyleng - 1; i >= yyleng - x1; --i )
   {
     for(j = yyleng - 1; j >= yyleng - x1; --j )
     {
        if(yycopy[i] == yycopy[j] && yycopy[i] != *s)
       {
         flag++;
       }
     }
   }

   if(flag==x1)
   {
    return flag;
   }
   else
   {
     return 0;
   }
}
