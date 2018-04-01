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
