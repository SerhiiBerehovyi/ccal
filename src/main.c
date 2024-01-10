
#include <stdio.h>
#include "../includes/ccal/database.h"
#include "../includes/ccal/datetime.h"
#include "../includes/tools/tools.h"
#include "../includes/ccal/menu.h"
#include "../includes/ccal/calendar.h"

int main()
{

    int calendarLoaded;
    calendarLoaded = loadCalendar();
    if(!calendarLoaded)
    {
        printf("Fehler beim Leser der Daten\n");
        return 1;
    }

    printf("%s", "Der Datenbank wurde erfolgreich abgelesen.\n\n");

    char *menuName = "Terminverwaltung V 0.2";
    char *menuItems[] = {
            "Neuen Termin anlegen",
            "Termin Bearbeiten",
            "Termin loechen",
            "Termin suchen",
            "Termine sortieren",
            "Termine Auflisten",
            "Program beenden"
    };

    int answer, calendarSaved;

    do {
        answer = getMenu(menuName, menuItems, 7);
        switch (answer) {
            case '1':
                createAppointment();
                break;
            case '2':
                editAppointment();
                break;
            case '3':
                deleteAppointment();
                break;
            case '4':
                searchAppointment();
                break;
            case '5':
                sortCalendar();
                break;
            case '6':
                listCalendar();
                break;
            default:
                calendarSaved = saveCalendar();
                if(!calendarSaved)
                {
                    printf("Kalender kann nicht gespeichert werden.\n");
                }
                else
                {
                    printf("Kalender wurde erfolgreich gespeichert.\n");
                }

                freeCalendar();
                printf("Programm wird beendet!\n");
        }
        waitForEnter();
    } while (answer != '7');

    return 0;
}
