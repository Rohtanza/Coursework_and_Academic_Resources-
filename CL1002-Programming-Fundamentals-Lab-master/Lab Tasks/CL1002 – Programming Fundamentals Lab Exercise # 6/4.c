#include<stdio.h>
int main()
    {
        int coffe=0,tea=0,coke=0,jucie=0,x,i=1;
        printf("\nFor Coffe press \"1\"\nFor Tea press \"2\"\nFor Coke press \"3\"\nFor Orange Juice \"4\"\n");
        while(1)
        { printf("\nPlease input the favorite beverage person #%dChose form 1,2,3 and 4 form menu and enter -1 to exit:",i);
          scanf("%d",&x);
          if(x==-1)
          break;
          i++;
          switch (x)
          {
          case 1:
            coffe++;
            break;
            case 2:
            tea++;
            break;
            case 3:
            coke++;
            break;
            case 4:
            jucie++;
            break;            
          }}
          printf("Beravge\tNumber of Votes\n***********************\n  Coffe\t\t%d\n  Tea\t\t%d\n  Coke\t\t%d\n  Juice\t\t%d\n***********************\n",coffe,tea,coke,jucie);
          return 0;}
