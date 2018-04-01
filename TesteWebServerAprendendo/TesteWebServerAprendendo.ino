#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>
#include <ESP8266WebServerSecure.h>

const char* ssid = "UltraSecreto";
const char* password = "TCC22062018";

String site = "";

ESP8266WebServer server(80); // server: http://192.168.4.1

void handleRoot2(){
  site = "<html lang=\"pt\"><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1, user-scalable=no\"/>\r\n";
  site += "<head><title>Hello World TCC ETECZL</title>\n";
  site += "<style>button{border:0;border-radius:0.3rem;background-color:#1fa3ec;color:#fff;line-height:2.4rem;font-size:1.2rem;width:100%;}</style></head>\n";
  site += "<body style=\"color: blue\">\n";
  site += "<center><h1>Hello World TCC</h1></center>\n";
  site += "<center><p><font color=\"red\" size=\"90%\">TCC</p></center>\n";
  site += "<script>var target_date = new Date(\"june 22, 2018 19:00:00\");\n";
  site += "var dias, horas, minutos, segundos;\n";
  site += "var regressiva = document.getElementById(\"regressiva\");\n";
  site += "setInterval(function () {\n";
  site += "var current_date = new Date().getTime();\n";
  site += "var segundos_f = (target_date - current_date) / 1000;\n";
  site += "dias = parseInt(segundos_f / 86400);\n";
  site += "segundos_f = segundos_f % 86400; \n";
  site += "horas = parseInt(segundos_f / 3600);\n";
  site += "segundos_f = segundos_f % 3600;\n";
  site += "minutos = parseInt(segundos_f / 60);\n";
  site += "segundos = parseInt(segundos_f % 60);\n";
  site += "document.getElementById('dia').innerHTML = dias;\n";
  site += "document.getElementById('hora').innerHTML = horas;\n";
  site += "document.getElementById('minuto').innerHTML = minutos;\n";
  site += "document.getElementById('segundo').innerHTML = segundos;\n";
  site += "}, 1000);\n";
  site += "</script>\n";
  site += "<div class=\"contagem\">\n";
  site += "<table><tr><td><div class=\"numero\" id=\"dia\"></div></td></td><td><div class=\"numero\" id=\"hora\"></div></td><td><div class=\"numero\" id=\"minuto\"></div></td><td><div class=\"numero\" id=\"segundo\"></div></td></tr>\n";
  site += "<tr style=\"height:20px\"><td><p class=\"legenda\">Dias</p></td><td><p class=\"legenda\">Horas</p></td><td><p class=\"legenda\">Min</p></td><td><p class=\"legenda\">Seg</p></td></tr></table>\n";
  site += "</table>\n";
  site += "</div>\n";
  site += "<a href=\"inicio\"><button>Inicio</button></a>\n";
  site += "</body>\n";
  site += "</html>";

  server.send(200, "text/html", site);

  site = "";
}

void handleRoot(){
  site = "<html lang=\"pt\"><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1, user-scalable=no\"/>\r\n";
  site += "<head><title>Hello World</title>\n";
  site += "<style>button{border:0;border-radius:0.3rem;background-color:#1fa3ec;color:#fff;line-height:2.4rem;font-size:1.2rem;width:100%;}</style></head>\n";
  site += "<body style=\"color: blue\">\n";
  site += "<style>.c} button{border:0;border-radius:0.3rem;background-color:#1fa3ec;color:#fff;line-height:2.4rem;font-size:1.2rem;width:100%;}</style>";
  site += "<center><h1>Hello World do meu ESP8266</h1></center>\n";
  site += "<center><h1>Agora Falando serio, quer tomar um susto, clique no botao abaixo:</h1></center>\n";
  site += "<a href=\"TCC\"><button>Pagina TCC</button></a>\n";
  site += "</body>\n";
  site += "</html>";

  server.send(200, "text/html", site);

  site = "";
}

void setup() {
  WiFi.mode(WIFI_AP); //aceita WIFI_AP / WIFI_AP_STA / WIFI_STA
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  server.on("/", handleRoot);
  server.on("/inicio", handleRoot);
  server.on("/TCC", handleRoot2);
  server.begin();
}

void loop() {
  server.handleClient();

//  String req = client.readStringUntil('\r');
//  client.flush();
// 
//  if (req.indexOf("TCC") != -1){
//    handleRoot2();
//  }else if (req.indexOf("Inicio") != -1){
//    handleRoot();
//  }  

}
