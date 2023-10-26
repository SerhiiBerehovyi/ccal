
#include <stdio.h>
#include "../includes/ccal/datastructure.h"
#include "../includes/ccal/datetime.h"
#include "../includes/tools/tools.h"
#include "../includes/ccal/menu.h"
#include "../includes/ccal/calendar.h"

void inputDate();

int main()
{
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

    int answer;
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
                printf("Programm wird beendet!\n");
        }
        waitForEnter();
    } while (answer != '7');

    return 0;
}

/********************************************************************
 * Funktion void inputDate(void)
 *   - Benutzer soll ein Datum eingeben.
 *   - Eingabe wird mit Hilfe der Funktion getDateFromString geparst
 *     und geprueft. Bei gueltigem Datum steht dieses in der Datums-
 *     variable Date.
 *   - Ergebnis der Eingabe wird entsprechend angezeigt.
 * Paramater: keine
 * Funktionsergebnis: nichts
 *******************************************************************/
void inputDate()
{
    sDate Date;
    char Input[20];

    printf("Geben Sie bitte ein gueltiges Datum ein: ");
    *Input = '\0';
    scanf("%19[^\n]", Input);
    clearBuffer();

    if (getDateFromString(Input, &Date))
        printf("Das Datum %02i.%02i.%04i ist gueltig!\n", Date.Day, Date.Month, Date.Year);
    else
        printf("Das eingegebene Datum '%s' ist ungueltig!\n", Input);

    printf("\n");
}
