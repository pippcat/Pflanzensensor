/* Funktion: String GeneriereAnalogsensorAdminString(int sensorNummer, const String& sensorName, const int minimum, const int maximum)
 * Generiert einen String für einen Analogsensor
 * Parameter:
 * int sensorNummer: Nummer des Sensors
 * String sensorName: Name des Sensors
 * int minimum: Minimalwert des Sensors
 * int maximum: Maximalwert des Sensors
 * Rückgabewert: formatierter String
 */
String GeneriereAnalogsensorAdminString(
int sensorNummer,
const String& sensorName,
const int minimum,
const int maximum,
const int gruenUnten,
const int gruenOben,
const int gelbUnten,
const int gelbOben) {
  String analogsensorAdminString;
  analogsensorAdminString += "<h2>Analogsensor " + String(sensorNummer) + "</h2>";
  analogsensorAdminString += "<p>Sensorname: ";
  analogsensorAdminString += "<input type=\"text\" size=\"20\" name=\"Name: \" placeholder=\"" + String(sensorName) + "\"></p>";
  analogsensorAdminString += "<p>Minimalwert: ";
  analogsensorAdminString += "<input type=\"text\" size=\"4\" name=\"Minimum: \" placeholder=\"" + String(minimum) + "\"></p>";
  analogsensorAdminString += "<p>Maximalwert: ";
  analogsensorAdminString += "<input type=\"text\" size=\"4\" name=\"Maximum: \" placeholder=\"" + String(maximum) + "\"></p>";
  analogsensorAdminString += "<p>unterer grüner Schwellwert: ";
  analogsensorAdminString += "<input type=\"text\" size=\"4\" name=\"unterer grüner Schwellwert: \" placeholder=\"" + String(gruenUnten) + "\"></p>";
  analogsensorAdminString += "<p>oberer grüner Schwellwert: ";
  analogsensorAdminString += "<input type=\"text\" size=\"4\" name=\"oberer grüner Schwellwert: \" placeholder=\"" + String(gruenOben) + "\"></p>";
  analogsensorAdminString += "<p>unterer gelber Schwellwert: ";
  analogsensorAdminString += "<input type=\"text\" size=\"4\" name=\"unterer gelber Schwellwert: \" placeholder=\"" + String(gelbUnten) + "\"></p>";
  analogsensorAdminString += "<p>oberer gelber Schwellwert: ";
  analogsensorAdminString += "<input type=\"text\" size=\"4\" name=\"oberer gelber Schwellwert: \" placeholder=\"" + String(gelbOben) + "\"></p>";
  return analogsensorAdminString;
}

/*
 * Funktion: Void WebseiteAdminAusgeben()
 * Gibt die Administrationsseite des Webservers aus.
 */
void WebseiteAdminAusgeben() {
   #if MODUL_DEBUG
    Serial.println(F("# Beginn von WebsiteAdminAusgeben()"));
  #endif
  #include "wifi_bilder.h"
  #include "wifi_header.h"
  #include "wifi_footer.h"
  String formatierterCode = htmlHeader;
  formatierterCode += "<h1>Adminseite</h1>";
  formatierterCode += "<p>Auf dieser Seite können die Variablen verändert werden.</p>";
  formatierterCode += "<p>Die Felder zeigen in grau die derzeit gesetzten Werte an. Falls kein neuer Wert eingegeben wird, bleibt der alte Wert erhalten.</p>";
  formatierterCode += "<form action=\"/setzeVariablen\" method=\"POST\">";
  #if MODUL_BODENFEUCHTE
    formatierterCode += "<h2>Bodenfeuchte</h2>";
    formatierterCode += "<p>Sensorname: ";
    formatierterCode += "<input type=\"text\" size=\"20\" name=\"bodenfeuchteName\" placeholder=\"";
    formatierterCode += bodenfeuchteName;
    formatierterCode += "\"></p>";
    formatierterCode += "<p>Minimalwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"bodenfeuchteMinimum\" placeholder=\"";
    formatierterCode += bodenfeuchteMinimum;
    formatierterCode += "\"></p>";
    formatierterCode += "<p>Maximalwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"bodenfeuchteMaximum\" placeholder=\"";
    formatierterCode += bodenfeuchteMaximum;
    formatierterCode += "\"></p>";
    formatierterCode += "<p>unterer grüner Schwellwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"bodenfeuchteGruenUnten\" placeholder=\"";
    formatierterCode += bodenfeuchteGruenUnten;
    formatierterCode += "\"></p>";
    formatierterCode += "<p>oberer grüner Schwellwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"bodenfeuchteGruenOben\" placeholder=\"";
    formatierterCode += bodenfeuchteGruenOben;
    formatierterCode += "\"></p>";
    formatierterCode += "<p>unterer gelber Schwellwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"bodenfeuchteGelbUnten\" placeholder=\"";
    formatierterCode += bodenfeuchteGelbUnten;
    formatierterCode += "\"></p>";
    formatierterCode += "<p>oberer gelber Schwellwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"bodenfeuchteGelbOben\" placeholder=\"";
    formatierterCode += bodenfeuchteGelbOben;
    formatierterCode += "\"></p>";
  #endif
  #if MODUL_DHT
    formatierterCode += "<h2>DHT Modul</h2>";
    formatierterCode += "<h3>Lufttemperatur</h3>";
    formatierterCode += "<p>unterer grüner Schwellwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"lufttemperaturGruenUnten\" placeholder=\"";
    formatierterCode += lufttemperaturGruenUnten;
    formatierterCode += "\"></p>";
    formatierterCode += "<p>oberer grüner Schwellwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"lufttemperaturGruenOben\" placeholder=\"";
    formatierterCode += lufttemperaturGruenOben;
    formatierterCode += "\"></p>";
    formatierterCode += "<p>unterer gelber Schwellwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"lufttemperaturGelbUnten\" placeholder=\"";
    formatierterCode += lufttemperaturGelbUnten;
    formatierterCode += "\"></p>";
    formatierterCode += "<p>oberer gelber Schwellwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"lufttemperaturGelbOben\" placeholder=\"";
    formatierterCode += lufttemperaturGelbOben;
    formatierterCode += "\"></p>";
    formatierterCode += "<h3>Luftfeuchte</h3>";
    formatierterCode += "<p>unterer grüner Schwellwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"luftfeuchteGruenUnten\" placeholder=\"";
    formatierterCode += luftfeuchteGruenUnten;
    formatierterCode += "\"></p>";
    formatierterCode += "<p>oberer grüner Schwellwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"luftfeuchteGruenOben\" placeholder=\"";
    formatierterCode += luftfeuchteGruenOben;
    formatierterCode += "\"></p>";
    formatierterCode += "<p>unterer gelber Schwellwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"luftfeuchteGelbUnten\" placeholder=\"";
    formatierterCode += luftfeuchteGelbUnten;
    formatierterCode += "\"></p>";
    formatierterCode += "<p>oberer gelber Schwellwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"luftfeuchteGelbOben\" placeholder=\"";
    formatierterCode += luftfeuchteGelbOben;
    formatierterCode += "\"></p>";
  #endif

  #if MODUL_HELLIGKEIT
    formatierterCode += "<h2>Helligkeitssensor</h2>";
    formatierterCode += "<p>Sensorname: ";
    formatierterCode += "<input type=\"text\" size=\"20\" name=\"helligkeitName\" placeholder=\"";
    formatierterCode += helligkeitName;
    formatierterCode += "\"></p>";
    formatierterCode += "<p>Minimalwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"helligkeitMinimum\" placeholder=\"";
    formatierterCode += helligkeitMinimum;
    formatierterCode += "\"></p>";
    formatierterCode += "<p>Maximalwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"helligkeitMaximum\" placeholder=\"";
    formatierterCode += helligkeitMaximum;
    formatierterCode += "\"></p>";
    formatierterCode += "<p>unterer grüner Schwellwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"helligkeitGruenUnten\" placeholder=\"";
    formatierterCode += helligkeitGruenUnten;
    formatierterCode += "\"></p>";
    formatierterCode += "<p>oberer grüner Schwellwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"helligkeitGruenOben\" placeholder=\"";
    formatierterCode += helligkeitGruenOben;
    formatierterCode += "\"></p>";
    formatierterCode += "<p>unterer gelber Schwellwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"helligkeitGelbUnten\" placeholder=\"";
    formatierterCode += helligkeitGelbUnten;
    formatierterCode += "\"></p>";
    formatierterCode += "<p>oberer gelber Schwellwert: ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"helligkeitGelbOben\" placeholder=\"";
    formatierterCode += helligkeitGelbOben;
    formatierterCode += "\"></p>";
  #endif
  #if MODUL_LEDAMPEL
    formatierterCode += "<h2>LED Ampel</h2>";
    formatierterCode += "<h3>Anzeigemodus</h3>";
    formatierterCode += "<p>Modus: (0: Helligkeit und Bodenfeuchte; 1: Helligkeit; 2: Bodenfeuchte): ";
    formatierterCode += "<input type=\"text\" size=\"4\" name=\"ampelModus\" placeholder=\"";
    formatierterCode += ampelModus;
    formatierterCode += "\"></p>";
  #endif
  #if MODUL_ANALOG3
    formatierterCode += GeneriereAnalogsensorAdminString(3, analog3Name, analog3Minimum, analog3Maximum, analog3GruenUnten, analog3GruenOben, analog3GelbUnten, analog3GelbOben);
  #endif
  #if MODUL_ANALOG4
    formatierterCode += GeneriereAnalogsensorAdminString(4, analog4Name, analog4Minimum, analog4Maximum, analog4GruenUnten, analog4GruenOben, analog4GelbUnten, analog4GelbOben);
  #endif
  #if MODUL_ANALOG5
    formatierterCode += GeneriereAnalogsensorAdminString(5, analog5Name, analog5Minimum, analog5Maximum, analog5GruenUnten, analog5GruenOben, analog5GelbUnten, analog5GelbOben);
  #endif
  #if MODUL_ANALOG6
    formatierterCode += GeneriereAnalogsensorAdminString(6, analog6Name, analog6Minimum, analog6Maximum, analog6GruenUnten, analog6GruenOben, analog6GelbUnten, analog6GelbOben);
  #endif
  #if MODUL_ANALOG7
    formatierterCode += GeneriereAnalogsensorAdminString(7, analog7Name, analog7Minimum, analog7Maximum, analog7GruenUnten, analog7GruenOben, analog7GelbUnten, analog7GelbOben);
  #endif
  #if MODUL_ANALOG8
    formatierterCode += GeneriereAnalogsensorAdminString(8, analog8Name, analog8Minimum, analog8Maximum, analog8GruenUnten, analog8GruenOben, analog8GelbUnten, analog8GelbOben);
  #endif

  formatierterCode += "<h2>Passwort</h2>";
  formatierterCode += "<p><input type=\"password\" name=\"Passwort\" placeholder=\"Passwort\"><br>";
  formatierterCode += "<input type=\"submit\" value=\"Absenden\"></p></form>";

  formatierterCode += "<h2>Links</h2>";
  formatierterCode += "<ul>";
  formatierterCode += "<li><a href=\"/\">zur Startseite</a></li>";
  #if MODUL_DEBUG
  formatierterCode += "<li><a href=\"/debug.html\">zur Anzeige der Debuginformationen</a></li>";
  #endif
  formatierterCode += "<li><a href=\"https://www.github.com/pippcat/Pflanzensensor\" target=\"_blank\"><img src=\"";
  formatierterCode += logoGithub;
  formatierterCode += "\">&nbspRepository mit dem Quellcode und der Dokumentation</a></li>";
  formatierterCode += "<li><a href=\"https://www.fabmobil.org\" target=\"_blank\"><img src=\"";
  formatierterCode += logoFabmobil;
  formatierterCode += "\">&nbspHomepage</a></li>";
  formatierterCode += "</ul>";

  formatierterCode += htmlFooter;
  Webserver.send(200, "text/html", formatierterCode);
}
