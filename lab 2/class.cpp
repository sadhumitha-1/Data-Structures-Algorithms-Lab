#include<cstdio>
#include<cstdlib>
#include<cmath>

class area
{
    private:
        int length;
        int breadth;
        int height;

    public:
    
        int square(int side)
        {
            return side*side;
        }
        int cube(int side)
        {
            return 6*side*side;
        }
        int rectangle(int length,int breadth)
        {
            return length*breadth;
        }
        int cuboid(int length,int breadth,int heigth)
        {
            return 2*((length*breadth)+(breadth*heigth)+(heigth*length));
        }
    
};

int main()
{
    area Area;
    char choice;
    do
    {
        printf("\nPlease choose any of the options from below to calculate area of:");
        printf("\na)Square");
        printf("\nb)Cube");
        printf("\nc)Rectangle");
        printf("\nd)Cuboid");
        printf("\ne)Exit");
        printf("\nEnter your choice: ");
        scanf(" %c",&choice);
            switch(choice)
            {
                case 'a':
                {
                    int length;
                    int result;
                    printf("enter the length(side) of the square:");
                    scanf("%d",&length);
                    result=Area.square(length);
                    printf("the area of square with side %d is %d\n",length,result);
                    break;
                }
                case 'b':
                {
                    int length;
                    int result;
                    printf("enter the length(side) of the cube:");
                    scanf("%d",&length);
                    result=Area.cube(length);
                    printf("the area of cube with side %d is %d\n",length,result);
                    break;
                }
                case 'c':
                {
                    int length;
                    int breadth;
                    int result;
                    printf("enter the length of the rectangle:");
                    scanf("%d",&length);
                    printf("enter the breadth of the rectangle:");
                    scanf("%d",&breadth);

                    result=Area.rectangle(length,breadth);
                    printf("the area of rectangle with length %d and breadth %d is %d\n",length,breadth,result);
                    break;
                }
                case 'd':
                {
                    int length;
                    int breadth;
                    int heigth;
                    int result;
                    printf("enter the length of the cuboid:");
                    scanf("%d",&length);
                    printf("enter the breadth of the cuboid:");
                    scanf("%d",&breadth);
                    printf("enter the heigth of the cuboid:");
                    scanf("%d",&heigth);
                    result=Area.cuboid(length,breadth,heigth);
                    printf("the area of cuboid with length %d, breadth %d and heigth %d is %d\n",length,breadth,heigth,result);
                    break;
                }
                case 'e':
                {
                    printf("Exiting the program...\n");
                    break;
                }
                default:
                {
                    printf("Invalid Choice.Please enter valid choice\n");
                    break;
                }


            }
    }while(choice!='e');
    
}