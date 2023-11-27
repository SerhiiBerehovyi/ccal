
#include <stdio.h>
#include "../includes/tools/tools.h"
#include "../includes/tools/escapesequenzen.h"
#include "../includes/ccal/datastructure.h"
#include "../includes/ccal/calendar.h"
#include "../includes/ccal/database.h"
#include "../includes/ccal/menu.h"


int main()
{
    char menuTitle[MENUITEM_MAXLENGTH] = "Kalenderverwaltung v0.2";

    while (1)
    {
        clearScreen(); HOME;

        if (errorCode == 1)
        {
            printf("Fehler bei Speicherreservierung.\n"); errorCode = 0;
        }

        char *menuItems[MENUITEM_MAXNUM];
        menuItems[1] = "Termin erstellen";
        menuItems[2] = "Termin bearbeiten";
        menuItems[3] = "Termin loeschen";
        menuItems[4] = "Termin suchen";
        menuItems[5] = "Kalender sortieren";
        menuItems[6] = "Termine auflisten";
        menuItems[7] = "Programm beenden";

        int menuChoice = getMenu(menuTitle, menuItems, 7);

        switch (menuChoice)
        {
            case 1:
                createAppointment(); break;
            case 2:
                editAppointment(); break;
            case 3:
                deleteAppointment(); break;
            case 4:
                searchAppointment(); break;
            case 5:
                sortCalendar(); break;
            case 6:
                listCalendar(); break;
            default:
                closeCalendar(); return 0;
        }
    }
}