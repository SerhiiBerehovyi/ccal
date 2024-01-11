
#include <stdio.h>
#include "../includes/tools/tools.h"
#include "../includes/tools/escapesequenzen.h"
#include "../includes/ccal/datastructure.h"
#include "../includes/ccal/calendar.h"
#include "../includes/ccal/database.h"
#include "../includes/ccal/menu.h"


int main()
{
    clearScreen();
    HOME;

    loadCalendar();

    char menuTitle[50] = PRINTED_TITLE;

    while (1)
    {
        clearScreen();
        HOME;

        if (errorCode)
        {
            switch (errorCode)
            {
                case 1:
                {
                    printf("Ein undefinierter Fehler ist aufgetreten :(\n");
                    break;
                }
                case 2:
                {
                    printf("Kalender konnte nicht geladen werden. %s pruefen.\n", DATABASE_FILENAME);
                    return 2;
                }
                case 3:
                {
                    printf("Kalender konnte nicht gespeichert werden.\n");
                    break;
                }
                case 4:
                {
                    printf("Text konnte nicht eingelesen werden.\n");
                    break;
                }
                case 5:
                {
                    printf("%s nicht vorhanden. Programm startet mit leerem Kalender.\n", DATABASE_FILENAME);
                    break;
                }
                case 6:
                {
                    printf("Mindestens ein Termin konnte nicht geladen werden. Kalender und %s pruefen.\n", DATABASE_FILENAME);
                }
                case 66:
                {
                    printf("Nicht mal ein einziges Byte war mehr frei :(\n");
                }
                default:
                {
                    break;
                }
            }
            errorCode = 0;
            waitForEnter();
        }

        char *menuItems[MENUITEM_MAXNUM];
        menuItems[1] = "Termin erstellen";
        menuItems[2] = "Termin bearbeiten";
        menuItems[3] = "Termin loeschen";
        menuItems[4] = "Termin suchen";
        menuItems[5] = "Termine auflisten";
        menuItems[6] = "Programm beenden";

        int menuChoice = getMenu(menuTitle, menuItems, 6);

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
                listCalendar(); break;
            default:
                closeCalendar(); return 0;
        }
    }
}