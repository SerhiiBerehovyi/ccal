
#include <stdio.h>
#include "../includes/ccal/calendar.h"
#include "../includes/ccal/datastructure.h"
#include "../includes/ccal/datetime.h"
#include "../includes/tools/tools.h"
#include "../includes/ccal/menu.h"

void inputDate();

int main()
{
    char menuTitle[MENUITEM_MAXLENGTH] = "Kalenderverwaltung v0.2";

    while (1) {
        clearScreen();

        char *menuitems[MENUITEM_MAXNUM];
        menuitems[1] = "Termin erstellen";
        menuitems[2] = "Termin bearbeiten";
        menuitems[3] = "Termin loeschen";
        menuitems[4] = "Termin suchen";
        menuitems[5] = "Kalender sortieren";
        menuitems[6] = "Termine auflisten";
        menuitems[7] = "Programm beenden";

        int menuChoice = getMenu(menuTitle, menuitems, 7);

        switch (menuChoice) {
            case 1:
                createAppointment();
                break;
            case 2:
                editAppointment();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                searchAppointment();
                break;
            case 5:
                sortCalendar();
                break;
            case 6:
                listCalendar();
                break;
            default:
                return 0;
        }
    }
    return 0;
}