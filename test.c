
#include <conio.h>

int menu(void);
void setcolor(unsigned short color);


main()
{
while(1)
{
/*get selection and execute the relevant statement*/
switch(menu())
{
case 1:
{
setcolor(8);
puts("You selected menu item 1\n");
puts("Finished item 1 task\n");
break;
}
case 2:
{
setcolor(11);
puts("You selected menu item 2\n");
puts("Finished item 2 task\n");
break;
}
case 3:
{
setcolor(12);
puts("You are quitting\n");
exit(0);
break;
}
default:
{
puts("Invalid menu choice\n");
break;
}
}
}
return 0;
}

return reply;
}
