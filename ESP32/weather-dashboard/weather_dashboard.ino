#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

const char* ssid = "TU_RED";
const char* password = "TU_CLAVE";

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
WebServer server(80);

void handleRoot() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  String tempText = isnan(temp) ? "--" : String(temp, 1);
  String humText  = isnan(hum)  ? "--" : String(hum, 1);

  String tempColor = "#22c55e";
  if (!isnan(temp)) {
    if (temp >= 30) tempColor = "#ef4444";
    else if (temp >= 25) tempColor = "#f59e0b";
  }

  String html = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="refresh" content="3">
  <title>ESP32 Weather Station</title>
  <style>
    * {
      box-sizing: border-box;
      margin: 0;
      padding: 0;
    }

    body {
      font-family: Arial, sans-serif;
      background: linear-gradient(135deg, #0f172a, #1e293b, #334155);
      color: white;
      min-height: 100vh;
      display: flex;
      justify-content: center;
      align-items: center;
      padding: 20px;
    }

    .container {
      width: 100%;
      max-width: 420px;
    }

    .header {
      text-align: center;
      margin-bottom: 20px;
    }

    .header h1 {
      font-size: 2rem;
      margin-bottom: 8px;
    }

    .header p {
      color: #cbd5e1;
      font-size: 0.95rem;
    }

    .card {
      background: rgba(15, 23, 42, 0.75);
      backdrop-filter: blur(8px);
      border: 1px solid rgba(255,255,255,0.08);
      border-radius: 22px;
      padding: 22px;
      box-shadow: 0 10px 30px rgba(0,0,0,0.30);
    }

    .grid {
      display: grid;
      grid-template-columns: 1fr;
      gap: 16px;
      margin-top: 18px;
    }

    .sensor-box {
      background: rgba(255,255,255,0.05);
      border-radius: 18px;
      padding: 18px;
      text-align: center;
    }

    .label {
      font-size: 1rem;
      color: #cbd5e1;
      margin-bottom: 10px;
    }

    .value {
      font-size: 2.4rem;
      font-weight: bold;
    }

    .footer {
      margin-top: 18px;
      text-align: center;
      color: #94a3b8;
      font-size: 0.85rem;
    }

    .badge {
      display: inline-block;
      margin-top: 10px;
      background: rgba(34, 197, 94, 0.15);
      color: #86efac;
      border: 1px solid rgba(34, 197, 94, 0.35);
      border-radius: 999px;
      padding: 6px 12px;
      font-size: 0.8rem;
    }

    @media (min-width: 480px) {
      .grid {
        grid-template-columns: 1fr 1fr;
      }
    }
  </style>
</head>
<body>
  <div class="container">
    <div class="header">
      <h1>Andres Weather Station</h1>
      <p>ESP32 + DHT11 live dashboard</p>
    </div>

    <div class="card">
      <div class="badge">Auto refresh every 3 seconds</div>

      <div class="grid">
        <div class="sensor-box">
          <div class="label">Temperature</div>
          <div class="value" style="color:)rawliteral";

  html += tempColor;

  html += R"rawliteral(;">)rawliteral";
  html += tempText;
  html += R"rawliteral( &deg;C</div>
        </div>

        <div class="sensor-box">
          <div class="label">Humidity</div>
          <div class="value" style="color:#38bdf8;">)rawliteral";
  html += humText;
  html += R"rawliteral( %</div>
        </div>
      </div>

      <div class="footer">
        Data served from ESP32 local web server
      </div>
    </div>
  </div>
</body>
</html>
)rawliteral";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
  Serial.println("Servidor web iniciado");
}

void loop() {
  server.handleClient();
}
